#!/usr/bin/env python3
"""Writes this fork's progress badges from the linker map.

    python3 tools/progress_badges.py --version us

Reads build/<version>/banjotooie_decompressed.map, the same source the
upstream progress script uses, and writes into progress/<version>/:

  all.json, boot.json, core1.json, core2.json, overlays.json
      shields.io endpoint documents. The badges in README.md point straight
      at these files in this repository, so committing them updates the
      badges. Nothing else is involved: no external service, no API key.

  progress.json
      the plain numbers, so the history stays readable in a diff.

  README.md
      a table of the same numbers.

Run it after a successful build and commit the result. The badge URLs use
the ref HEAD, which GitHub resolves to this repository's default branch, so
they follow whichever branch is set as default.
"""

from __future__ import annotations

import argparse
import json
from pathlib import Path

import progress

# label -> folder in the map file; None means the whole ROM
BADGES = [
    ("All", None),
    ("Boot", "boot"),
    ("Core1", "core1"),
    ("Core2", "core2"),
    ("Overlays", "overlays"),
]


def colour(percent: float) -> str:
    if percent >= 100.0:
        return "brightgreen"
    if percent >= 75.0:
        return "green"
    if percent >= 50.0:
        return "yellowgreen"
    if percent >= 25.0:
        return "yellow"
    if percent >= 10.0:
        return "orange"
    return "red"


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("-v", "--version", default="us")
    args = parser.parse_args()

    map_path = Path("build") / args.version / "banjotooie_decompressed.map"
    if not map_path.exists():
        raise SystemExit(
            "no map file at %s — build first (make -j8 check)" % map_path)

    total, per_folder = progress.getProgress(map_path, args.version)

    out_dir = Path("progress") / args.version
    out_dir.mkdir(parents=True, exist_ok=True)

    numbers: dict[str, dict[str, float]] = {}
    rows = []

    for label, folder in BADGES:
        stats = total if folder is None else per_folder.get(folder)
        if stats is None:
            continue
        done, size = stats.decompedSize, stats.total
        pct = 100.0 * done / size if size else 0.0

        key = "all" if folder is None else folder
        (out_dir / (key + ".json")).write_text(
            json.dumps({
                "schemaVersion": 1,
                "label": label,
                "message": "%.2f%%" % pct,
                "color": colour(pct),
            }) + "\n", encoding="utf-8")

        numbers[key] = {"decompiled": done, "total": size,
                        "percent": round(pct, 4)}
        rows.append((label, done, size, pct))

    (out_dir / "progress.json").write_text(
        json.dumps(numbers, indent=2, sort_keys=True) + "\n", encoding="utf-8")

    table = ["# Progress (%s)" % args.version, "",
             "Regenerate with `python3 tools/progress_badges.py`"
             " after a successful build.", "",
             "| Segment | Decompiled | Total | |",
             "|---|---:|---:|---:|"]
    for label, done, size, pct in rows:
        table.append("| %s | %s | %s | %.2f%% |"
                     % (label, f"{done:,}", f"{size:,}", pct))
    (out_dir / "README.md").write_text("\n".join(table) + "\n",
                                       encoding="utf-8")

    for label, done, size, pct in rows:
        print("%-10s %10s / %-10s %7.2f%%"
              % (label, f"{done:,}", f"{size:,}", pct))
    print("\nwritten to %s/" % out_dir)


if __name__ == "__main__":
    main()
