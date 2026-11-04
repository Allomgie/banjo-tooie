#include "common.h"

extern s32 D_8007DA60;

// Anti-tamper value; the top byte is 0x10 when untouched.
s32 gleeprom_entrypoint_0(void)
{
    return *(s32 *) ((s8 *) &D_8007DA60 + 0xF0) ^ 0xBD1F0416;
}

// Writes one 8-byte EEPROM block; the address is offset / 8.
int gleeprom_entrypoint_1(s32 offset, s32 data, u32 *length)
{
    s32 unk_0;
    s32 result;

    func_80016934(3);
    result = osEepromLongWrite(func_80016928(), (offset / 8) & 0xFF, data, length);
    func_80016934(0);
    return result;
}

// Reads one 8-byte EEPROM block; the address is offset / 8.
int gleeprom_entrypoint_2(s32 offset, s32 data, s32 length)
{
    s32 pad0;
    u32 result;
    func_80016934(3);
    result = osEepromLongRead(func_80016928(), (offset / 8) & 0xFF, data, length);
    func_80016934(0);
    return result;
}
