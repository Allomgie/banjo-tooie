// Global (cross-save) options: widescreen, screen position, sound mode, and loading/saving them
// to the two redundant EEPROM copies.
#include "gl/globalsettings.h"

extern s16 D_80800560_glglobalsettings[][2];
s32 glglobalsettings_entrypoint_4();
int glglobalsettings_entrypoint_5();
void glglobalsettings_entrypoint_6();
s32 glglobalsettings_entrypoint_7();
void glglobalsettings_entrypoint_8();

// Defaults: widescreen off, screen position 0/0, sound mode 1.
s32 glglobalsettings_entrypoint_0(void)
{
    glglobalsettings_entrypoint_4(0);
    glglobalsettings_entrypoint_6(0, 0);
    glglobalsettings_entrypoint_8(1);
}

s32 glglobalsettings_entrypoint_3();

// Applies the stored settings: widescreen, sound mode, screen position.
void func_80800034_glglobalsettings(void)
{
    s32 pos_x;
    s32 pos_y;

    glglobalsettings_entrypoint_4(glglobalsettings_entrypoint_3());
    glglobalsettings_entrypoint_8(glglobalsettings_entrypoint_7());
    glglobalsettings_entrypoint_5(&pos_x, &pos_y);
    glglobalsettings_entrypoint_6(pos_x, pos_y);
}

// Allocates a settings block.
int func_80800084_glglobalsettings()
{
    heap_alloc(0x80);
}

// Reads one settings copy, up to 3 tries.
s32 func_808000A4_glglobalsettings(s32 slot, s32 buf)
{
    s32 i;
    s32 ret;

    for (i = 3; i != 0; i--) {
        ret = _glgamestore_entrypoint_1(slot, buf);
        if (ret == 0) {
            break;
        }
    }

    if (ret != 0) {
        _glglobaldata_entrypoint_4(buf);
    }

    return ret;
}

// Erases every copy except valid_slot.
s32 func_80800114_glglobalsettings(void *valid_slot)
{
    s32 i;
    s32 keep;
    // Matching: the extra copy of the parameter is needed for the match.
    keep = (s32) valid_slot;
    for (i = 0; i < 2; i++) {
        if (i != keep) {
            _glgamestore_entrypoint_5(i);
        }
    }
}

// Reads both copies. The last valid one is returned (-1 if none) and its data
// ends up in *best_buf. If both are valid, the other copy is erased.
s32 func_80800168_glglobalsettings(s32 *best_buf)
{
    s32 tmp;
    s32 slot;
    s32 buf;
    s32 valid_count;
    s32 valid_slot;

    buf = func_80800084_glglobalsettings();
    valid_slot = -1;
    slot = 0;
    valid_count = 0;
    do {
        if (func_808000A4_glglobalsettings(slot, buf) != 0) {
            goto skip_block;
        }
        tmp = buf;
        buf = *best_buf;
        valid_count += 1;
        valid_slot = slot;
        *best_buf = tmp;
    skip_block:
        slot += 1;
    } while (slot != 2);
    if (valid_count >= 2) {
        func_80800114_glglobalsettings(valid_slot);
    }
    heap_free(buf);
    return valid_slot;
}

// Loads the settings; falls back to the defaults if no copy is valid.
s32 glglobalsettings_entrypoint_1(void)
{
    s32 slot;
    void *buf;

    buf = func_80800084_glglobalsettings();
    slot = func_80800168_glglobalsettings(&buf);
    if (slot == -1) {
        glglobalsettings_entrypoint_0();
    } else {
        _glglobaldata_entrypoint_2(buf);
        func_80800034_glglobalsettings();
    }
    heap_free(buf);
}

// Writes buf to a slot (up to 3 tries) and reads it back.
s32 func_80800278_glglobalsettings(s32 slot, s32 buf)
{
    s32 scratch;
    s32 tries;
    s32 ret;

    tries = 3;
    scratch = func_80800084_glglobalsettings();
loop_1:
    ret = _glgamestore_entrypoint_3(slot, buf);
    if (ret == 0) {
        func_808000A4_glglobalsettings(slot, scratch);
    }
    tries -= 1;
    if ((ret != 0) && (tries != 0)) {
        goto loop_1;
    }
    heap_free(scratch);
    return ret;
}

// Saves the settings to the copy that is not the valid one, then erases the
// stale copy. Does nothing unless the 'global flags changed' flag is set.
s32 glglobalsettings_entrypoint_2(void)
{
    s32 ret;
    s32 valid_slot;
    s32 slot;
    s32 buf;

    if (func_800DA298(0xD54) == 0) {
        return 0;
    }
    buf = func_80800084_glglobalsettings();
    valid_slot = func_80800168_glglobalsettings(&buf);
    _glglobaldata_entrypoint_3(buf);
    slot = 0;
loop_3:
    if (slot == valid_slot) {
        slot += 1;
        if (slot != 2) {
            goto loop_3;
        }
    }
    ret = func_80800278_glglobalsettings(slot, buf);
    if (ret == 0) {
        func_80800114_glglobalsettings(slot);
        func_800DA524(0xD54);
    }
    heap_free(buf);
    return ret;
}

// Widescreen flag.
s32 glglobalsettings_entrypoint_3()
{
    return func_800DA298(GFLAG_BB9_WIDESCREEN_ENABLED);
}

// Sets widescreen on/off.
s32 glglobalsettings_entrypoint_4(enabled)
int enabled;
{
    set_widescreen(enabled);
    func_800DA3B8(0xBB9, enabled ? 1 : 0);
}

// Reads the screen position; flags hold it with a bias of 0x20 (x) and 0x28 (y).
int glglobalsettings_entrypoint_5(out_x, out_y)
s32 *out_x;
s32 *out_y;
{
    s32 raw_x;
    raw_x = func_800DA564(0xBBA, 6);
    out_x[0] = raw_x - 0x20;
    out_y[0] = func_800DA564(0xBC0, 6) - 0x28;
}

// Sets the screen position, clamped to the 6-bit flag range.
void glglobalsettings_entrypoint_6(pos_x, pos_y) s32 pos_x;
s32 pos_y;
{
    func_80015670();
    pos_x += 0x20;
    pos_y += 0x28;

if (pos_x >= 0x40) {
    pos_x = 0x3F;
}

if (pos_y >= 0x40) {
    pos_y = 0x3F;
}

func_800DA7A8(0xBBA, pos_x, 6);
func_800DA7A8(0xBC0, pos_y, 6);
}

// Sound mode (0..3).
s32 glglobalsettings_entrypoint_7(void)
{
    func_800DA564(0xBC6, 2);
}

// Sets the sound mode.
void glglobalsettings_entrypoint_8(mode) s32 mode;
{
    func_80012F0C(D_80800560_glglobalsettings[mode][0]);
    func_80012F34(0, D_80800560_glglobalsettings[mode][1]);
    func_80012F34(1, D_80800560_glglobalsettings[mode][1]);
    func_800DA7A8(0xBC6, mode, 2);
}

// TU-NOTE: the .data of this overlay is defined here in C; values are taken from the ROM.
// Audio output params per sound mode.
s16 D_80800560_glglobalsettings[4][2] = {0x1, 0x4, 0x2, 0x4, 0x3, 0x4, 0x4, 0x4};
