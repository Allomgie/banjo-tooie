#include "gc/introtext.h"

typedef struct { u32 pad_0 : 10; u32 local_0 : 16; u32 local_1 : 6; } IntroTextRecord;
extern IntroTextRecord D_80800250_gcintrotext[];
extern u16 D_8080056C_gcintrotext[];
extern u16 D_8080056E_gcintrotext;
extern u16 D_80800570_gcintrotext[24];
IntroTextRecord *func_808000C8_gcintrotext();
int func_808001AC_gcintrotext();

void gcintrotext_entrypoint_0()
{
    func_800DA544(FLAG2_6CB_UNK);
}

s32 gcintrotext_entrypoint_1(void)
{
  s32 out;
  unsigned long long new_var;
  out = (new_var = (func_800DA9E4(0x6CB, 0)) ? (1) : (0));
  if (!out)
  {
  }
  return out;
}

s32 gcintrotext_entrypoint_2(s32 param_0, s32 *param_1, s32 *param_2)
{
    IntroTextRecord *local_0;
    if (param_0 == -1) param_0 = func_800EA05C();
    local_0 = func_808000C8_gcintrotext(param_0);
    if (local_0 == NULL) return -1;
    *param_1 = local_0->local_0;
    *param_2 = local_0->local_1;
    return func_808001AC_gcintrotext(param_0);
}

IntroTextRecord *func_808000C8_gcintrotext(param_0) s32 param_0;
{
    s32 local_0;

    for (local_0 = 0; local_0 < 199; local_0++) {
        if (param_0 == D_80800250_gcintrotext[local_0].pad_0) {
            return &D_80800250_gcintrotext[local_0];
        }
    }
    return NULL;
}

int func_808001AC_gcintrotext(param_0) s32 param_0;
{
    s32 local_0;
    if (param_0 == D_8080056C_gcintrotext[0]) return 0;
    if (param_0 == D_8080056E_gcintrotext) return 0;
    for (local_0 = 0; local_0 < 24; local_0++) {
        if (param_0 == D_80800570_gcintrotext[local_0]) return 0;
    }
    return 1;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/gc/introtext.data.s) is defined here in C.
 * Values are taken from the ROM.
 * Labels inside an object are linker symbols in undefined_syms.us.txt: D_8080056E_gcintrotext = D_8080056C_gcintrotext + 0x2
 * extern declarations adjusted to the object (same addresses): D_8080056C_gcintrotext -> u16[] (uses written as NAME[0]) */
IntroTextRecord D_80800250_gcintrotext[1] = { 0xA1, 0x18AD, 0x0 };
u32 D_80800254_gcintrotext[1] = { 0x28862B40 };
u32 D_80800258_gcintrotext[1] = { 0x28C62B40 };
u32 D_8080025C_gcintrotext[196] = { 0x29062B40, 0x29462B40, 0x29862B40, 0x29C62B40, 0x62C62B40, 0x2A062B41, 0x2A462B41, 0x2A862B41, 0x2AC62B41, 0x2B062B41, 0x2BC62B40, 0x5CC62B41, 0x2B862B80, 0x2B462B81, 0x50462B42, 0x2D862B01, 0x2DC62B00, 0x2E062BC0, 0x2E462BC5, 0x2E862BC1, 0x2EC62BC3, 0x2F062BC4, 0x31062BCE, 0x31462BC2, 0x31862BC6, 0x32062BC7, 0x32462BC8, 0x5DC62BC9, 0x5E862BCA, 0x5E062BCC, 0x5E462BCB, 0x31C62C00, 0x32862C0E, 0x32C62C01, 0x33062C02, 0x33462C03, 0x33862C04, 0x33C62C05, 0x34062C0C, 0x34462C0B, 0x34862C07, 0x34C62C08, 0x35062C09, 0x35C62C0A, 0x36062C06, 0x36862C0F, 0x36C62C10, 0x36462B00, 0x37062C11, 0x3A462B01, 0x48462C0D, 0x58C62C12, 0x35862C40, 0x49062C55, 0x35462B01, 0x37462C41, 0x37862C4D, 0x37C62C4E, 0x38062C4F, 0x38462C42, 0x4EC62C56, 0x38862C43, 0x38C62C44, 0x39062C4A, 0x39462C4B, 0x39862C45, 0x4F062C57, 0x39C62C46, 0x3A862C47, 0x3AC62C48, 0x3B062C49, 0x3E462C4C, 0x5D862B00, 0x69C62C80, 0x69862C90, 0x6A062C8E, 0x6A462C8F, 0x3BC62B00, 0x3B462C81, 0x3B862C82, 0x3C462C83, 0x3D062C8B, 0x3D862C8C, 0x3DC62C84, 0x3E062C85, 0x3E862C86, 0x3F062C8D, 0x3FC62C87, 0x48062B01, 0x49862C88, 0x49462C89, 0x60462C8A, 0x44862CC0, 0x44C62CC1, 0x45062CC2, 0x45462CC3, 0x45862CC4, 0x45C62CC5, 0x46062CC6, 0x46462CC7, 0x46862CCB, 0x46C62CC8, 0x47862B01, 0x48862B01, 0x48C62CCA, 0x5C462B00, 0x40062D00, 0x40462D01, 0x40862D02, 0x40C62D03, 0x41062D04, 0x41462D05, 0x41862D06, 0x41C62D07, 0x42062D08, 0x42462D09, 0x42862D10, 0x42C62D0A, 0x43062D0B, 0x43462D0C, 0x43862D0D, 0x43C62D0E, 0x44062D11, 0x44462D0F, 0x47C62B01, 0x5C862B00, 0x58862D13, 0x61C62D14, 0x49C62D40, 0x4A062D41, 0x4A462D42, 0x4A862D43, 0x4AC62D44, 0x4B062D45, 0x4B462D46, 0x4B862D4A, 0x4BC62D4B, 0x4C062D4C, 0x4C462D47, 0x4C862D48, 0x4CC62D49, 0x4D062B00, 0x4D462B01, 0x4D862D80, 0x4DC62D81, 0x4E062D82, 0x4E462D83, 0x4E862D84, 0x4F462D86, 0x4F862B00, 0x4FC62B00, 0x50062B01, 0x57462DC0, 0x57862DC1, 0x57C62DC2, 0x58062DC3, 0x62862DC4, 0x50862E00, 0x50C62E01, 0x51062E02, 0x66C62E17, 0x51462E03, 0x51862E04, 0x51C62E05, 0x52062E06, 0x52462E07, 0x52862E08, 0x52C62E09, 0x53062E0A, 0x53462E0B, 0x53862E0C, 0x53C62E11, 0x54062E0D, 0x54462E0E, 0x54862E12, 0x54C62E0F, 0x55062E13, 0x55C62B01, 0x55462E14, 0x55862B00, 0x56862E15, 0x56C62E10, 0x57062E16, 0x5FC62E80, 0x59862E81, 0x59462E82, 0x61862E83, 0x5EC62E84, 0x5F062E85, 0x60862E86, 0x60C62E87, 0x5F462E88, 0x59062E89, 0x60062E8A, 0x61462E8B, 0x62062E8C };
u16 D_8080056C_gcintrotext[2] = { 0xE5, 0xE4 };
u16 D_80800570_gcintrotext[24] = { 0x123, 0x10A, 0xF9, 0xD1, 0xFC, 0x110, 0x141, 0x15B, 0x15E, 0x17A, 0x113, 0xC6, 0xC8, 0xC9, 0xDE, 0xDF, 0xE0, 0x12E, 0x12F, 0x130, 0x19A, 0x12B, 0x12C, 0x13F };
