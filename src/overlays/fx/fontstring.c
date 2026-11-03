#include "common.h"


s32 func_80800000_fxfontstring(char *str){
    while(*str){
        str++;
    }
    return str;
}

void fxfontstring_entrypoint_0(s32 param_0, s32 param_1)
{
  u8 *local_0;
 do { do { local_0 = func_80800000_fxfontstring(param_0); *local_0 = 0xFD; local_0++; if (param_1 != 0) { *local_0 = 0x68; } else { *local_0 = 0x6C; } local_0++; *local_0 = 0; } while (0); } while (0);
}

void fxfontstring_entrypoint_1(u8 *param_0, s32 param_1)
{
    u8 *local_0;
    u8 *local_1;
    s32 local_2;

    local_0 = func_80800000_fxfontstring(param_0);
    local_0[0] = 0xFD;
    local_0[1] = 0x61;
    local_1 = local_0 + 2;
    if (param_1 <= 0) {
        *local_1 = 1;
    } else {
        local_2 = param_1 >= 256 ? 255 : param_1;
        *local_1 = local_2;
    }
    local_1++;
    *local_1 = 0;
}

u8 *fxfontstring_entrypoint_2(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
    u8 *p;
    s32 v;

    p = func_80800000_fxfontstring(param_0);
    *p++ = 0xFD;
    *p++ = 0x63;
    if (param_1 <= 0) {
        *p = 1;
    } else {
        if (param_1 >= 0x100) {
            v = 0xFF;
        } else {
            v = param_1;
        }
        *p = v;
    }
    p++;
    if (param_2 <= 0) {
        *p = 1;
    } else {
        if (param_2 >= 0x100) {
            v = 0xFF;
        } else {
            v = param_2;
        }
        *p = v;
    }
    p++;
    if (param_3 <= 0) {
        *p = 1;
    } else {
        if (param_3 >= 0x100) {
            v = 0xFF;
        } else {
            v = param_3;
        }
        *p = v;
    }
    *++p = 0;
}

int fxfontstring_entrypoint_3(s32 param_0, u32 param_1, s32 param_2)
{
  u8 *local_0;
  unsigned short new_var;
  local_0 = func_80800000_fxfontstring(param_0);
  new_var = param_1;
  *(local_0++) = 0xFD;
  *(local_0++) = 0x69;
  *(local_0++) = param_1 & 0xFF;
 *(local_0++) = new_var >> 8; *(local_0++) = param_2 + 1; *(local_0++) = 0;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/fx/fontstring.data.s) is defined here in C.
 * Values are taken from the ROM. */
