// Save-slot manager: caches the three visible save files and maps them onto the EEPROM slots.
// Loads (with retry), saves crash-safely via a spare slot, copies, erases and frees files.
#include "common.h"

extern s8 D_80127618[];
extern void aligned4_memcpy(s32, s32, s32);
extern void heap_free(void *);
// D_80127614 layout: cached slot images, logical file -> physical slot map
// (3 files plus the spare slot), cache-enabled flag.
typedef struct {
    s32 pad_0;
    void *buffers[3];
    s32 slot_map;
    u8 enabled;
} SaveGameBuffers_glsavegame_entrypoint_1;
extern u8 D_80127614[];
extern void _glgamedata_entrypoint_2(s32);
typedef struct {
    void *buffers[3];
    s32 slot_map;
    u8 enabled;
} SaveGameBuffers_glsavegame_entrypoint_9;
extern void _glgamedata_entrypoint_6();

// Allocates a slot buffer.
int func_80800000_glsavegame()
{
    heap_alloc(0x1C0);
}

// Reads and validates a physical slot (up to 3 tries). The buffer is cleared on
// failure; ret 3 means bad structure or version.
s32 func_80800020_glsavegame(s32 slot, s32 buf)
{
    s32 i;
    s32 ret;

    for (i = 3; i != 0; i--) {
        ret = _glgamestore_entrypoint_0(slot, buf);
        if (ret == 0) {
            break;
        }
    }
    if (ret == 0) {
        if (_glgamedata_entrypoint_5(buf) == 2) {
            ret = 3;
        }
    }
    if (ret == 0) {
        if (_glgamedata_entrypoint_4(buf) == 0) {
            ret = 3;
        }
    }
    if (ret != 0) {
        _glgamedata_entrypoint_6(buf);
    }
    return ret;
}

// File number stored in the image (section 2), or -1.
int func_808000CC_glsavegame(s32 image)
{
    s32 offset;
    s32 len;
    if (_glgamedata_entrypoint_3(image, 2, &offset, &len)) {
        return *(u8 *) (image + offset) - 1;
    }
    return -1;
}

// Scans the four physical slots, caches each valid image under its file and
// builds the file -> slot map. The slot that fails to load becomes the spare.
s32 glsavegame_entrypoint_0(void)
{
    s32 slot;
    s32 file;
    u32 used[4];
    s32 ret;
    s32 buf;
    D_80127618[0x12] = -1;
    D_80127618[0xF] = -1;
    used[3] = 0;
    for (slot = 0; slot < 3; slot++) {
        D_80127618[slot + 0xC] = -1;
        used[slot] = 0;
        ((s32 *) D_80127618)[slot] = func_80800000_glsavegame();
        _glgamedata_entrypoint_6(((s32 *) D_80127618)[slot]);
    }
    buf = func_80800000_glsavegame();
    for (slot = 0; slot != 4; slot++) {
        ret = func_80800020_glsavegame(slot, buf);
        if (!ret) {
            file = func_808000CC_glsavegame(buf);
            if (D_80127618[file + 0xC] == -1) {
                D_80127618[file + 0xC] = slot;
                used[slot] = 1;
                aligned4_memcpy(((s32 *) D_80127618)[file], buf, 0x1C0);
            } else {
                ret = 2;
            }
        }
        if (ret) {
            D_80127618[0xF] = slot;
        }
    }
    heap_free(buf);
    used[D_80127618[0xF]] = 1;
    for (file = 0; file < 3; file++) {
        for (slot = 0; slot < 4 && D_80127618[file + 0xC] == -1; slot++) {
            if (!used[slot]) {
                used[slot] = 1;
                D_80127618[file + 0xC] = slot;
            }
        }
    }
    D_80127618[0x10] = 1;
    D_80127618[0x11] = 1;
}

// Writes buf to a physical slot (up to 3 tries) and reads it back.
s32 func_808002E0_glsavegame(s32 slot, s32 buf)
{
    s32 verify_buf;
    s32 slot_copy;
    s32 ret;
    s32 slot_copy2;
    s32 tries;
    tries = 3;
    verify_buf = func_80800000_glsavegame(slot, buf);
    // Matching: the extra copies of slot are needed for the match.
    slot_copy = slot;
    slot_copy2 = slot_copy;
loop_1:
    ret = _glgamestore_entrypoint_2(slot_copy2, buf);

    if (ret == 0) {
        func_80800020_glsavegame(slot_copy2, verify_buf);
    }
    tries -= 1;
    if ((ret != 0) && (tries != 0)) {
        // Matching: empty loop needed for the match.
        do {
        } while (0);
        goto loop_1;
    }
    heap_free(verify_buf);
    return ret;
}

// Erases a physical slot (up to 3 tries).
int func_8080036C_glsavegame(s32 slot)
{
    s32 ret;
    s32 i;
    for (i = 3; i != 0; i--) {
        ret = _glgamestore_entrypoint_4(slot);
        if (ret == 0) {
            break;
        }
    }
    return ret;
}

// Frees the cached slot images.
void glsavegame_entrypoint_1(void)
{
    void **p;
    void **end;

    for (p = (*(SaveGameBuffers_glsavegame_entrypoint_1 *) D_80127614).buffers,
        end = (*(SaveGameBuffers_glsavegame_entrypoint_1 *) D_80127614).buffers + 3;
         p != end; p++) {
        if (*p != NULL) {
            heap_free(*p);
            *p = NULL;
        }
    }
    (*(SaveGameBuffers_glsavegame_entrypoint_1 *) D_80127614).enabled = 0;
}

// Whether the file is non-empty.
s32 glsavegame_entrypoint_2(s32 file)
{
    return **(u8 **) (D_80127614 + 4 + file * 4) != 0;
}

// Whether any file is non-empty.
s32 glsavegame_entrypoint_3(void)
{
    s32 i;
    for (i = 0; i < 3; i++) {
        if (glsavegame_entrypoint_2(i)) {
            return TRUE;
        }
    }
    return FALSE;
}

// Cached slot image of a file.
int glsavegame_entrypoint_4(s32 file)
{
    return ((s32 *) D_80127614)[file + 1];
}

s32 glsavegame_entrypoint_5()
{
    return 0x1;
}

// Section 2 writer: file number + 1.
void glsavegame_entrypoint_6(s8 *out)
{
    *out = ((s8 *) D_80127614)[0x16] + 1;
}

void func_808004B8_glsavegame(int file)
{
    D_80127614[0x16] = file;
}

int func_808004C4_glsavegame()
{
    s8 *base = (s8 *) D_80127614;
    base[0x16] = -1;
}

// Saves the current game to a file: writes the spare slot, erases the old slot,
// then swaps them in the map so a crash never loses the old copy.
s32 glsavegame_entrypoint_7(s32 file)
{
    s32 ret;
    s32 old_slot;
    s32 spare;
    void *buf;
    buf = func_80800000_glsavegame();

    old_slot = ((s8 *) D_80127618 + file)[0xC];
    spare = ((s8 *) D_80127618)[0xF];
    func_808004B8_glsavegame(file);
    _glgamedata_entrypoint_1(buf);
    func_808004C4_glsavegame();
    ret = func_808002E0_glsavegame(spare, buf);
    if (!ret)
        ret = func_8080036C_glsavegame(old_slot);
    if (!ret) {
        ((s8 *) D_80127618 + file)[0xC] = spare;
        ((s8 *) D_80127614)[0x13] = old_slot;
    }
    heap_free(buf);
    return ret;
}

// Loads a file into the game.
s32 glsavegame_entrypoint_8(s32 file)
{
    s32 ret;
    s32 slot;
    s32 buf = func_80800000_glsavegame(file);
    slot = ((s8 *) D_80127614)[file + 0x10];
    ret = func_80800020_glsavegame(slot, buf);
    if (ret == 0) {
        _glgamedata_entrypoint_2(buf);
    }
    heap_free(buf);
    return ret;
}

// Erases a file: erases its slot, which becomes the spare, and clears the cache.
int glsavegame_entrypoint_9(s32 file)
{
    int ret;
    s32 old_slot;
    s32 spare;

    old_slot =
        ((s8 *) (*(SaveGameBuffers_glsavegame_entrypoint_9 *) D_80127618).buffers)[file + 12];
    spare = ((s8 *) (*(SaveGameBuffers_glsavegame_entrypoint_9 *) D_80127618).buffers)[15];
    ret = func_8080036C_glsavegame(old_slot);
    if (ret == 0) {
        ((s8 *) (*(SaveGameBuffers_glsavegame_entrypoint_9 *) D_80127618).buffers)[file + 12] =
            spare;
        ((s8 *) (*(SaveGameBuffers_glsavegame_entrypoint_9 *) D_80127618).buffers)[15] = old_slot;
        if ((*(SaveGameBuffers_glsavegame_entrypoint_9 *) D_80127618).enabled)
            _glgamedata_entrypoint_6(
                (*(SaveGameBuffers_glsavegame_entrypoint_9 *) D_80127618).buffers[file]);
    }
    return ret;
}

// Copies file src over file dst via the spare slot.
s32 glsavegame_entrypoint_10(s32 dst, s32 src)
{
    s32 buf;
    s32 ret;
    s32 dst_old;
    s32 spare;
    s8 *dst_base;
    buf = func_80800000_glsavegame();
    ret = D_80127618[src + 0xC];
    dst_base = D_80127618 + dst;
    dst_old = dst_base[0xC];
    spare = D_80127618[0xF];
    ret = func_80800020_glsavegame(ret, buf);
    _glgamedata_entrypoint_2(buf);
    func_808004B8_glsavegame(dst);
    _glgamedata_entrypoint_1(buf);
    func_808004C4_glsavegame();
    if (ret == 0) {
        ret = func_808002E0_glsavegame(spare, buf);
    }
    if (ret == 0) {
        ret = func_8080036C_glsavegame(dst_old);
    }
    if (ret == 0) {
        dst_base[0xC] = spare;
        D_80127618[0xF] = dst_old;
        if (*(u8 *) &D_80127618[0x10] != 0) {
            aligned4_memcpy(((s32 *) D_80127618)[dst], ((s32 *) D_80127618)[src], 0x1C0);
        }
    }
    heap_free(buf);
    return ret;
}
