// EEPROM save layout: two 0x80-byte settings copies, then four 0x1C0-byte game slots.
// Reads blocks with checksum check, writes them (EEPROM type 2 only) and erases them.
#include "common.h"

extern s32 _glglobaldata_entrypoint_1(s32);
extern int D_80079D70[];
extern s32 _gleeprom_entrypoint_1();

// Verifies the block checksum; 3 = bad CRC.
s32 func_80800000_glgamestore()
{
    s32 ret;

    ret = _glcrc_entrypoint_1();
    if (ret) {
        ret = 3;
    }
    return ret;
}

// EEPROM offset of global settings copy n (0x80 bytes each).
s32 func_80800030_glgamestore(copy)
s32 copy;
{
    return copy << 7;
}

// EEPROM offset of game slot n: two settings copies, then 0x1C0 bytes per slot.
int func_80800038_glgamestore(slot)
s32 slot;
{
    s32 size;
    int offset;
    // Matching: the temporary for the slot size is needed for the match.
    offset = slot * (size = 448);
    return func_80800030_glgamestore(2) + offset;
}

// Reads a block and verifies its checksum; 2 = read error, 3 = bad CRC.
s32 func_8080006C_glgamestore(s32 offset, s32 buf, s32 size)
{
    s32 status = 0;

if (_gleeprom_entrypoint_2(offset, buf, size)) {
    status = 2;
}

if (status == 0) {
    status = func_80800000_glgamestore(buf, size);
}

return status;
}

// Reads a game slot.
s32 glgamestore_entrypoint_0(s32 slot, s32 buf)
{
    s32 offset = func_80800038_glgamestore(slot);
    func_8080006C_glgamestore(offset, buf, 0x1C0);
}

// Reads a global settings copy.
s32 glgamestore_entrypoint_1(s32 copy, s32 buf)
{
    s32 status = func_8080006C_glgamestore(func_80800030_glgamestore(copy), buf, 0x80);

if (status == 0 && _glglobaldata_entrypoint_1(buf) == 0) {
    status = 2;
}

return status;
}

// Writes a block; only done when the EEPROM type flag is 2.
int func_8080013C_glgamestore()
{
    s32 error;

    error = 0;

if (D_80079D70[0x7B] == 2) {
    if (_gleeprom_entrypoint_1() != 0) {
        error = 1;
    }
}

return error;
}

// Writes a game slot.
s32 glgamestore_entrypoint_2(s32 slot, s32 buf)
{
    func_8080013C_glgamestore(func_80800038_glgamestore(slot), buf, 0x1C0);
}

// Writes a global settings copy.
s32 glgamestore_entrypoint_3(s32 copy, s32 buf)
{
    func_8080013C_glgamestore(func_80800030_glgamestore(copy), buf, 0x80);
}

// TU-NOTE: this .bss object is defined here ahead of its first use: IDO places
// .bss objects used before their definition first, the rest in definition order.
s32 B_80800270_glgamestore;

// Erases a block by writing 8 zero bytes.
s32 func_808001E0_glgamestore(s32 offset)
{
    s32 error = 0;

if (_gleeprom_entrypoint_1(offset, &B_80800270_glgamestore, 8) != 0) {
    error = 1;
}

return error;
}

// Erases a game slot.
void glgamestore_entrypoint_4()
{
    func_808001E0_glgamestore(func_80800038_glgamestore());
}

// Erases a global settings copy.
s32 glgamestore_entrypoint_5(void)
{
    s32 offset;
    offset = func_80800030_glgamestore();
    func_808001E0_glgamestore(offset);
}
