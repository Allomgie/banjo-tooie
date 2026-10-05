# Banjo Tooie Decomp

![code Progress]
![boot Progress]
![core1 Progress]
![core2 Progress]
![overlays Progress]

[code Progress]: https://img.shields.io/endpoint?url=https%3A%2F%2Fraw.githubusercontent.com%2FAllomgie%2Fbanjo-tooie%2FHEAD%2Fprogress%2Fus%2Fall.json
[boot Progress]: https://img.shields.io/endpoint?url=https%3A%2F%2Fraw.githubusercontent.com%2FAllomgie%2Fbanjo-tooie%2FHEAD%2Fprogress%2Fus%2Fboot.json
[core1 Progress]: https://img.shields.io/endpoint?url=https%3A%2F%2Fraw.githubusercontent.com%2FAllomgie%2Fbanjo-tooie%2FHEAD%2Fprogress%2Fus%2Fcore1.json
[core2 Progress]: https://img.shields.io/endpoint?url=https%3A%2F%2Fraw.githubusercontent.com%2FAllomgie%2Fbanjo-tooie%2FHEAD%2Fprogress%2Fus%2Fcore2.json
[overlays Progress]: https://img.shields.io/endpoint?url=https%3A%2F%2Fraw.githubusercontent.com%2FAllomgie%2Fbanjo-tooie%2FHEAD%2Fprogress%2Fus%2Foverlays.json

The badges read [`progress/us/`](progress/us/) in this repository rather than
the shared upstream dataset, so they can be kept current from here. After a
successful build:

```sh
python3 tools/progress_badges.py --version us
```

Then commit what it wrote **on this branch**. The badge URLs use the ref
`HEAD`, which GitHub resolves to the repository's default branch, so setting
the default branch to this one is all they need.

## Branches in this fork

The decompilation work and this fork's own presentation are kept apart, so
that the work can still be offered upstream unchanged if the project becomes
active again.

- **Work branches** (`core1-stage1-ido53`, `core1-stage2-hasm`,
  `core1-stage3-ido71`, `core2-ready-batch1`, `overlays-ready-batch1`, and
  whatever follows) contain nothing but decompilation. They touch no README,
  no badge, no progress file, and each one builds byte-identically on its own.
  Any of them can be opened as a pull request against upstream as it stands.
- **`fork-main`** is this branch: the work branches merged together, plus the
  badge tooling above. It is the default branch, so it is what visitors see
  and what the badges read.

Two consequences worth remembering. A new batch of work branches off the
latest *work* branch, never off `fork-main`, or the fork-specific commit would
travel into a pull request. And refreshing the progress figures only ever
touches `fork-main`, so it can never collide with a work branch or with a
merge of one.

## Setup

- Clone this repo recursively with git.
  - If you've already cloned, then init submodules recursively instead.
  - `git submodule update --init --recursive`
- Install packages for the C++ libraries fmtlib and toml11.
  - Ubuntu: `sudo apt install libfmt-dev libtoml11-dev gcc-mips-linux-gnu`
- Install pip requirements for splat.
  - `python3 -m pip install -r tools/splat/requirements.txt`
- Install pip requirements for this project.
  - `python3 -m pip install -r tools/requirements.txt`
- Place a copy of Banjo Tooie NTSC-U (SHA1 = af1a89e12b638b8d82cc4c085c8e01d4cba03fb3) in this folder and name it `baserom.us.z64`.
- Run `make setup` to decompress the rom and split it.
- Run `make` (with an optional job count) to build the rom.

## Use of AI tools

Every function in this repository is verified the same way, whatever its origin: the build must reproduce the original ROM byte for byte (`make check`). An unverified function is never treated as matched.

This is a hybrid project. I developed AI tools and built pipelines around them, and I matched functions by hand. Large and complex functions were mostly matched by hand, small and repetitive ones mostly by the pipelines, with exceptions in both directions.

The tooling grew with the project. Two examples: an "idiom witch hunt" compiles C code generated with Csmith through IDO and searches the output for specific codegen idioms, and a "Frankenstein" algorithm assembles candidates from already solved functions and scores them. Other tools read and query the whole function database, organize and categorize the progress automatically, and use several metrics to find systematic errors and fix them across many functions at once.

For functions where m2c gives no usable starting point, I fine-tuned a model as part of the research around this project: [Allomgie/Qwen32B-N64-Decomp-16bit](https://huggingface.co/Allomgie/Qwen32B-N64-Decomp-16bit). For individual cases and benchmark tests I also used Qwen3-Coder-Next, Qwen3.6-35B-A3B, Qwen3.6-27B, Qwen3.8-27B, Anthropic Claude Opus 4.6, 4.7, 4.8, 5 and 5.5, and ChatGPT Astra 6 and Sol 6.1.

Claude Code (Claude Opus) was used as an agentic assistant for assembling translation units, repairing their context and splitting units at object boundaries. I reviewed and committed every change.

On Mr-Wiseguy's repository I only pushed functions I matched by hand. Progress that was developed with AI assistance lives in this fork.

The project is still in its byte-matching phase, so the sources still contain artifacts of that process, such as probes left over from the decomp permuter. Once everything is matched, a separate fork will provide clean, equivalent functions that no longer aim for byte accuracy.
