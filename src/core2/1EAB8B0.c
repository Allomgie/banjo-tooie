#include "common.h"

// Minigame records (best times or scores), indexed by id - 0x80.
s16 D_8012B260[23];
extern s32 func_800D395C();
extern s32 D_8012B290;

// Address of record (id - 0x80); uses the alternate table (D_8012B290) in game mode 2.
u8 *func_800D1FC0(index)
s32 index;
{
    u8 *entry;

    index -= 0x80;
    if (func_800D395C(index) != 0) {
        entry = (index * 2) + (u8 *) &D_8012B290;
    } else {
        entry = (index * 2) + (u8 *) D_8012B260;
    }
    return entry;
}

void func_800D2014(void)
{
    s32 i;
    for (i = 0; i < 23; i++) {
        D_8012B260[i] = 0;
    }
}

// Stores value if it beats the record; mode selects the compare direction.
// Returns 1 for a new record, 0 for a tie, -1 otherwise.
s32 func_800D2054(s32 mode, s32 id, s32 value)
{
    s32 result;
    s16 *record;
    s32 diff;
    record = func_800D1FC0(id);
    if (*record == 0)
        result = 1;
    else {
        switch (mode) {
            case 0:
                diff = value - *record;
                break;
            case 1:
                diff = *record - value;
                break;
        }
        result = diff <= 0 ? (diff != 0 ? -1 : 0) : 1;
    }
    if (result == 1) {
        if (func_800D395C())
            func_800DA544(0xD54);
        *record = value;
    }
    return result;
}

int func_800D211C()
{
    s16 *record;
    record = func_800D1FC0();
    return *record;
}

s32 func_800D2140()
{
    return 0x2E;
}

// Loads records from save data (at most 23 entries).
int func_800D2148(u8 *src, u32 size)
{
    u32 src_addr;
    int count = size >> 1;
    if (0x18 <= count) {
        count = 0x17;
    }
    src_addr = (u32) src;
    rare_memcpy((s32 *) D_8012B260, src_addr, count << 1);
}

// Saves records (0x2E bytes).
s32 func_800D2188(void *dest)
{
    rare_memcpy(dest, (s32 *) D_8012B260, 0x2E);
}

int func_800D21B0(s32 *size_out, s32 **data_out)
{
    *size_out = 0x2E;
    *data_out = &D_8012B290;
}
