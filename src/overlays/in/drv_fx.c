#include "common.h"

extern Actor *func_80106790(Unk80132ED0 *);
extern void func_800DBEFC(void *, s32, f32 *);
extern void func_800EE88C(f32 *, void *);
extern s32 func_800BBCB8(f32 *, s32, f32, s32, s32 *);
extern s32 D_808005B0_indrv_fx[];
extern s32 D_80800608_indrv_fx[];
extern s32 D_80800648_indrv_fx[];
extern s32 D_80800684_indrv_fx[];
extern s32 D_808006E4_indrv_fx[];
extern s32 D_80800720_indrv_fx[];
extern s32 D_80800780_indrv_fx[];
extern s32 D_808007E0_indrv_fx[];
extern s32 D_80800818_indrv_fx[];
extern s32 D_80800870_indrv_fx[];
extern s32 D_808008C0_indrv_fx[];
extern s32 D_80800920_indrv_fx[];
extern s32 D_80800964_indrv_fx[];
extern s32 D_808009A8_indrv_fx[];
extern s32 D_808009F4_indrv_fx[];
extern s32 D_80800A4C_indrv_fx[];
extern s32 D_80800AA4_indrv_fx[];
extern s32 D_80800AFC_indrv_fx[];
extern s32 D_80800B2C_indrv_fx[];
extern s32 D_80800B5C_indrv_fx[];
extern s32 D_80800BA0_indrv_fx[];
extern s32 D_80800BE8_indrv_fx[];
extern s32 D_80800C3C_indrv_fx[];
extern s32 D_80800CA4_indrv_fx[];
extern s32 D_80800CF0_indrv_fx[];
extern s32 D_80800D30_indrv_fx[];
extern s32 D_80800D6C_indrv_fx[];
extern s32 D_80800DBC_indrv_fx[];
extern s32 D_80800E0C_indrv_fx[];
extern s32 D_80800E5C_indrv_fx[];
extern s32 D_80800EAC_indrv_fx[];

void func_80800000_indrv_fx(Unk80132ED0 *param_0, s32 param_1, f32 param_2, s32 param_3, s32 *param_4)
{
    f32 local_0[3];
    Actor *local_1;

    local_1 = func_80106790(param_0);
    if (local_1->unk7C_12 || param_1 == -1) {
        if (param_1 == -1) {} // empty test (no code): counts as an extra use of -1 for uopt coloring
        if (param_1 != -1) {
            func_800DBEFC(param_0->unk4, param_1, local_0);
        } else {
            func_800EE88C(local_0, (u8 *)param_0->unk0 + 4);
        }
        func_800BBCB8(local_0, (s32)local_0, param_2, param_3, param_4);
    }
}

int indrv_fx_entrypoint_0(s32 param_0, u32 param_1, s32 param_2)
{
    switch (param_1)
    {
        case 0:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 2, &D_808005B0_indrv_fx);
            break;
        case 1:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 5, &D_80800608_indrv_fx);
            break;
        case 2:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 5, &D_80800648_indrv_fx);
            break;
        case 3:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 1, &D_80800684_indrv_fx);
            break;
        case 4:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 4, &D_808006E4_indrv_fx);
            break;
        case 5:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 1, &D_80800720_indrv_fx);
            break;
        case 10:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 1, &D_80800780_indrv_fx);
            break;
        case 6:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 3, &D_808007E0_indrv_fx);
            break;
        case 7:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 6, &D_80800818_indrv_fx);
            break;
        case 8:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 32, &D_80800870_indrv_fx);
            break;
        case 9:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 1, &D_808008C0_indrv_fx);
            break;
        case 11:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 1, &D_80800920_indrv_fx);
            break;
        case 12:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 1, &D_80800964_indrv_fx);
            break;
        case 13:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 1, &D_808009A8_indrv_fx);
            break;
        case 14:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 2, &D_808009F4_indrv_fx);
            break;
        case 15:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 2, &D_80800A4C_indrv_fx);
            break;
        case 16:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 3, &D_80800AA4_indrv_fx);
            break;
        case 17:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 1, &D_80800AFC_indrv_fx);
            break;
        case 18:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 1, &D_80800B2C_indrv_fx);
            break;
        case 19:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 1, &D_80800B5C_indrv_fx);
            break;
        case 20:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 30, &D_80800BA0_indrv_fx);
            break;
        case 21:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 6, &D_80800BE8_indrv_fx);
            break;
        case 22:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 1, &D_80800C3C_indrv_fx);
            break;
        case 23:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 1, &D_80800CA4_indrv_fx);
            break;
        case 24:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 32, &D_80800CF0_indrv_fx);
            break;
        case 25:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 1, &D_80800D30_indrv_fx);
            break;
        case 26:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 32, &D_80800D6C_indrv_fx);
            break;
        case 27:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 32, &D_80800DBC_indrv_fx);
            break;
        case 28:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 32, &D_80800E0C_indrv_fx);
            break;
        case 29:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 32, &D_80800E5C_indrv_fx);
            break;
        case 30:
            func_80800000_indrv_fx(param_0, param_2, 1.0f, 32, &D_80800EAC_indrv_fx);
            break;
    }
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/in/drv_fx.data.s) is defined here in C.
 * Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_808005B0_indrv_fx -> s32[], D_80800608_indrv_fx -> s32[], D_80800648_indrv_fx -> s32[], D_80800684_indrv_fx -> s32[], D_808006E4_indrv_fx -> s32[], D_80800720_indrv_fx -> s32[], D_80800780_indrv_fx -> s32[], D_808007E0_indrv_fx -> s32[], D_80800818_indrv_fx -> s32[], D_80800870_indrv_fx -> s32[], D_808008C0_indrv_fx -> s32[], D_80800920_indrv_fx -> s32[], D_80800964_indrv_fx -> s32[], D_808009A8_indrv_fx -> s32[], D_808009F4_indrv_fx -> s32[], D_80800A4C_indrv_fx -> s32[], D_80800AA4_indrv_fx -> s32[], D_80800AFC_indrv_fx -> s32[], D_80800B2C_indrv_fx -> s32[], D_80800B5C_indrv_fx -> s32[], D_80800BA0_indrv_fx -> s32[], D_80800BE8_indrv_fx -> s32[], D_80800C3C_indrv_fx -> s32[], D_80800CA4_indrv_fx -> s32[], D_80800CF0_indrv_fx -> s32[], D_80800D30_indrv_fx -> s32[], D_80800D6C_indrv_fx -> s32[], D_80800DBC_indrv_fx -> s32[], D_80800E0C_indrv_fx -> s32[], D_80800E5C_indrv_fx -> s32[], D_80800EAC_indrv_fx -> s32[] */
s32 D_808005B0_indrv_fx[22] = { 0x1D09B8, 0x190004, 0x9001B, -0x40005, 0x2D0013, 0x21000E, 0xA, 0x160410, 0x26FDC8, -0x1A101A1, 0x1AB0195, 0x15B0022, 0x0, 0x3540354, 0x150028, 0x2E002B, 0xD100DE, 0x2F0017, 0x190019, 0x0, 0xEE, 0x0 };
s32 D_80800608_indrv_fx[16] = { 0x1D09CA, 0x190005, 0x8001B, -0x2BBFFE5, 0x2D0035, 0x7C000E, 0x90013, 0x20595C, 0x466A0024, 0xCA00FD, 0x2A0000, 0x1020117, 0x1D90016, 0x2000015, 0xB3, 0x0 };
s32 D_80800648_indrv_fx[15] = { 0x1D09CA, 0x190005, 0x8001B, -0x13FFEC, 0x2D0049, 0xAE000E, 0x8, 0x20595C, 0x466A0024, 0xCA00FD, 0x2A0000, 0x3500B3, 0xE60015, 0xB3, 0x0 };
s32 D_80800684_indrv_fx[24] = { 0x1D09C9, 0x190003, 0xD001B, 0x200078, 0x2C0000, 0x590000, 0x53, 0xE, 0x13007E, 0x2009FF, 0x13D0026, -0x20002D, -0x170000, 0x33, 0x240135, 0x1FD0015, 0xAE, 0x2A0000, 0x540163, 0x1B0002F, 0xA0014, 0x2E, 0x400000, 0xEE0000 };
s32 D_808006E4_indrv_fx[15] = { 0x1D09CA, 0x190005, 0x8001B, -0x12BFF95, 0x2D0035, 0x7C000E, 0x90013, 0x20595C, 0x466A0024, 0x17D01FD, 0x2A0000, 0x1020217, 0x2590015, 0xB3, 0x0 };
s32 D_80800720_indrv_fx[24] = { 0x1D09C9, 0x190003, 0xD001B, 0x3200B4, 0x2C0000, 0x590000, 0x53, 0xE, 0x13007E, 0x2009FF, 0x13D0026, -0x20002D, -0x170000, 0x33, 0x2402B3, 0x3B30015, 0xAE, 0x2A0000, 0x540363, 0x3B0002F, 0xA0014, 0x2E, 0x400000, 0xEE0000 };
s32 D_80800780_indrv_fx[24] = { 0x1D09C9, 0x190003, 0xD001B, 0x5001E, 0x2C0000, 0xA0000, 0x14, 0xE, 0x13007E, 0x208275, 0x67500026, -0x20002D, -0x170000, 0x33, 0x2402B3, 0x3B30015, 0xAE, 0x2A0000, 0x540363, 0x3B0002F, 0xA0014, 0x2E, 0x400000, 0xEE0000 };
s32 D_808007E0_indrv_fx[14] = { 0x1D09BC, 0x190006, 0x9000E, 0x9E00CC, 0x24045C, 0x47D0015, 0x33003A, 0x2A0000, 0x190180, 0x233002F, 0x4F0045, 0x45008C, 0x61006E, 0xB00000 };
s32 D_80800818_indrv_fx[22] = { 0x1D09BC, 0x190001, 0x5001B, 0x690116, 0x2D0063, 0x8F000E, 0xA, 0x160410, 0x26FDC8, -0x1A101A1, 0x1AB0195, 0x15B0022, 0x0, 0x13541354, 0x150028, 0x2E002B, 0xD100DE, 0x2F0017, 0x190019, 0x0, 0xEE, 0x0 };
s32 D_80800870_indrv_fx[20] = { 0x1D09BB, 0x180001, 0xA1B07, 0x1C57001B, -0xC80063, 0x2D00F7, 0x171000E, 0x7000A, 0x1FFFFF, -0xFFFFEA, -0x7BFFFFDA, -0x13B0111, -0x118FF1A, 0xDC00B4, 0x240011, 0x140015, 0xC2, 0x2A0000, 0xCA059C, 0x6300000 };
s32 D_808008C0_indrv_fx[24] = { 0x1D09C9, 0x190003, 0xD001B, 0x1E0096, 0x2C0000, 0x590000, 0x53, 0xE, 0x13007E, 0x20FF09, -0x9AFFDA, -0x20002D, -0x170000, 0x33, 0x2402B3, 0x3B30015, 0x3300AE, 0x2A0000, 0x540363, 0x3B0002F, 0xA0014, 0x2E, 0x400000, 0xEE0000 };
s32 D_80800920_indrv_fx[17] = { 0x1D09DC, 0x190003, 0xB002C, 0x74, 0x0, 0x870000, 0x20FFFF, -0xCDFFD9, -0x6A0050, 0x38, 0x22006E, 0x87017A, 0x18F0015, 0x3A00C2, 0x2B0238, 0x2C20016, 0x2000000 };
s32 D_80800964_indrv_fx[17] = { 0x1D09DC, 0x190003, 0xB002C, 0x6A, 0x0, 0x7D0000, 0x20F0F0, -0xFCDFFD9, -0x6A0050, 0x38, 0x22026E, 0x2D4047A, 0x48F0015, 0x3A00C2, 0x2B0338, 0x4C20016, 0x2000000 };
s32 D_808009A8_indrv_fx[19] = { 0x1D09DC, 0x190003, 0xB000E, 0x13007E, 0x2C0000, 0x6A0000, 0x7D, 0x20, 0x32323250, 0x27FF95, -0x500000, 0x380022, 0xA100A1, 0x12E0142, 0x15003A, 0xC2002B, 0x9E00C2, 0x160200, 0x0 };
s32 D_808009F4_indrv_fx[22] = { 0x1D09B9, 0x190001, 0x5001B, 0x1310242, 0x2D0009, 0xF000E, 0x2, 0x160400, 0x26FEF4, -0xD900D9, 0xE300CD, 0xF70022, 0x0, 0x3540354, 0x150028, 0x2E002B, 0xB800C5, 0x2F0017, 0x190019, 0x0, 0xEE, 0x0 };
s32 D_80800A4C_indrv_fx[22] = { 0x1D09B9, 0x190001, 0x5001B, 0x1310242, 0x2D0009, 0xF000E, 0x2, 0x160400, 0x26FEF4, -0xD900D9, 0xE300CD, 0xF70022, 0x1540154, 0x0, 0x150019, 0x61002B, 0x9E00AB, 0x2F0017, 0x190019, 0x0, 0xEE, 0x0 };
s32 D_80800AA4_indrv_fx[22] = { 0x1D09B9, 0x190001, 0x5001B, 0x690116, 0x2D0063, 0x8F000E, 0xA, 0x160410, 0x26FDC8, -0x1A101A1, 0x1AB0195, 0x15B0022, 0x0, 0x13541354, 0x150028, 0x2E002B, 0xD100DE, 0x2F0017, 0x190019, 0x0, 0xEE, 0x0 };
s32 D_80800AFC_indrv_fx[12] = { 0x1D08CB, 0x26FFE3, 0x0, 0x15F0177, 0x1A10022, 0xA0011, 0x41E141E3, 0x150000, 0x73002B, 0x820087, 0x160010, 0x0 };
s32 D_80800B2C_indrv_fx[12] = { 0x1D0938, 0x26FFE3, 0x0, 0x15F0177, 0x1A10022, 0xA0011, 0x41E141E3, 0x150000, 0x73002B, 0x820087, 0x160010, 0x0 };
s32 D_80800B5C_indrv_fx[17] = { 0x1D09DC, 0x190003, 0xB002C, 0x91, 0x0, 0xB90000, 0x20FFFF, -0xE4FFD9, -0x6A0050, 0x38, 0x2200EE, 0x13A037A, 0x38F0015, 0x3A00C2, 0x2B0238, 0x2990016, 0x2000000 };
s32 D_80800BA0_indrv_fx[18] = { 0x1D09E3, 0x1FFFB, -0x51D0000, 0x6FC30, 0x2C, -0x17B0100, -0x12BFE82, 0x1EF012C, 0x1FFFE6, 0x6D000016, -0x7FFFFFDC, 0x17001C, 0x150000, 0x8C002B, 0xF0011E, 0x400F5, 0x160200, 0x0 };
s32 D_80800BE8_indrv_fx[21] = { 0x1D09DE, 0x2CFF7D, -0x980084, 0x880099, 0x860001, 0x12C, 0x0, 0x1900000, 0x27FE80, -0x12BFEF9, 0x27C0022, 0x28002C7, 0x433045C, 0x150021, 0xD9002B, 0xDE011E, 0x2F005E, 0x6B007A, 0x6B0070, 0x820068, 0x0 };
s32 D_80800C3C_indrv_fx[26] = { 0x1D09C9, 0x190000, 0x8001B, 0x50005, 0x2C0000, 0x220000, 0x29, 0x20, 0x64656551, 0x160400, 0x210000, 0x0, 0x270000, -0xC0000, 0xC0022, 0x420051, 0x630073, 0x150033, 0xB3002B, 0x18001E3, 0x2F0000, 0x2E002B, 0x33, 0x4000FA, 0x160200, 0x0 };
s32 D_80800CA4_indrv_fx[19] = { 0x1D09E5, 0x190002, 0x6002C, -0x310032, 0x32, 0x320000, 0x270000, -0x460000, 0x460022, 0x4C00A8, 0x12601A6, 0x150054, 0x61002B, 0x730091, 0x2F0040, 0x3D0033, 0x0, 0x61, 0x0 };
s32 D_80800CF0_indrv_fx[16] = { 0x1D09B2, 0x190000, 0x9001B, -0x1F7027E, 0x2D0113, 0x235000E, 0x7000A, 0x160010, 0x270000, -0x3890000, 0x3460024, 0x1E0045, 0x15000A, 0xE8002B, 0x18001B5, 0x0 };
s32 D_80800D30_indrv_fx[15] = { 0x1D09B0, 0x2C0030, 0x5A0000, 0x2A0064, 0x9602, 0x220035, 0x3D004C, 0x660015, 0x8200BD, 0x2B0421, 0x421002F, 0x230021, 0x260023, 0x14, 0x7A0000 };
s32 D_80800D6C_indrv_fx[20] = { 0x1D09E4, 0x1BFCE6, -0x360FFD3, 0x28502AF, 0xE0005, 0x60016, -0x7FFFFFDA, -0x850194, -0xF4FF35, 0x14F00EF, 0x240028, 0x280015, 0x200F3, 0x2B01D7, 0x1D9002F, 0x6E0047, 0x730000, 0x0, 0x16, 0x2000000 };
s32 D_80800DBC_indrv_fx[20] = { 0x1D09E8, 0x1BFCE6, -0x360FFD3, 0x28502AF, 0xE0005, 0x60016, -0x7FFFFFDA, -0x850194, -0xF4FF35, 0x14F00EF, 0x240028, 0x280015, 0x200F3, 0x2B01D7, 0x1D9002F, 0x6E0047, 0x730000, 0x0, 0x16, 0x2000000 };
s32 D_80800E0C_indrv_fx[20] = { 0x1D09E9, 0x1BFCE6, -0x360FFD3, 0x28502AF, 0xE0005, 0x60016, -0x7FFFFFDA, -0x850194, -0xF4FF35, 0x14F00EF, 0x240028, 0x280015, 0x200F3, 0x2B01D7, 0x1D9002F, 0x6E0047, 0x730000, 0x0, 0x16, 0x2000000 };
s32 D_80800E5C_indrv_fx[20] = { 0x1D09EB, 0x1BFCE6, -0x360FFD3, 0x28502AF, 0xE0005, 0x60016, -0x7FFFFFDA, -0x850194, -0xF4FF35, 0x14F00EF, 0x240028, 0x280015, 0x200F3, 0x2B01D7, 0x1D9002F, 0x6E0047, 0x730000, 0x0, 0x16, 0x2000000 };
s32 D_80800EAC_indrv_fx[21] = { 0x1D09E0, 0x1BFCE6, -0x360FFD3, 0x28502AF, 0xE0005, 0x60016, -0x7FFFFFDA, -0x850194, -0xF4FF35, 0x14F00EF, 0x240028, 0x280015, 0x200F3, 0x2B01D7, 0x1D9002F, 0x6E0047, 0x730000, 0x0, 0x16, 0x2000000, 0x0 };
