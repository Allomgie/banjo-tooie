#include "common.h"

// Load and pin a text asset; returns a pointer past its first byte.
s32 gldbstring_entrypoint_0(s32 unk_0, s32 asset_id)
{
    unk_0 = func_800D674C(asset_id);
    func_800D70D0(1);
    func_800D71F4(1);
    return unk_0 + 1;
}

// Find string `id` in the current language: entries are {id + 0x80, len, data}.
u8 *gldbstring_entrypoint_1(u8 *text, s16 id)
{
    u8 *table;
    u8 *entry;
    s32 count;
    s32 i;
    u8 entry_id;
    u8 len;
    s32 offset;

    offset = _gldialog_entrypoint_0() * 2;
    table = text + offset;
    offset = table[0];
    offset += table[1] << 8;
    entry = text + offset;
    count = entry[-1];
    for (i = 0; i < count; i++) {
        entry_id = entry[0];
        len = entry[1];
        entry += 2;
        if (id + 0x80 == entry_id) {
            return entry;
        }
        entry += len;
    }
    return NULL;
}

// Unpin and release the text asset.
s32 gldbstring_entrypoint_2(Actor *asset)
{
    func_800D721C(asset, 0);
    func_800D70F8(asset, 0);
    func_800D6CEC(asset);
}
