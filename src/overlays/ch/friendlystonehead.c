#include "common.h"

typedef struct { s16 local_0; s16 local_1; } FriendlyStoneEvent;
extern u8 D_80800968_chfriendlystonehead[];
extern void _gcdialogcamera_entrypoint_3(void *, f32);
extern f32 func_8010CD28();
extern void func_80102BF8(u8 *, f32, f32, f32);
extern s32 D_80800978_chfriendlystonehead[];
extern s32 D_808008C0_chfriendlystonehead[];
extern s32 func_800DA298(s32);
extern s32 func_800D0A9C(s32, s32);
extern s32 func_800DA9E4(s32, s32);
extern void _capod_entrypoint_13(void *, s32, s32, s32);
extern void _subaddiedialog_entrypoint_8(Actor *, f32 *, s32 *, s32 *, s32);
extern int D_80800988_chfriendlystonehead[];
extern int D_808008E0_chfriendlystonehead[];
extern u16 D_80800908_chfriendlystonehead[];
extern u8 D_80800998_chfriendlystonehead[];
extern u16 D_8080099C_chfriendlystonehead;
extern u16 D_8080099E_chfriendlystonehead;
extern u16 D_808009A4_chfriendlystonehead;
extern void _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
typedef struct { u8 pad_0[0x28]; u32 pad_1 : 18; u32 flag : 1; u32 pad_2 : 13; } StoneheadMarker;
extern int D_808009B4_chfriendlystonehead[];
extern u8 D_80800950_chfriendlystonehead[];
extern u8 D_8080095C_chfriendlystonehead[];
extern void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
extern void func_80102424();
extern void func_8010C820();
int func_808006C4_chfriendlystonehead();
void func_80800830_chfriendlystonehead();

void func_80800000_chfriendlystonehead(s32 arg0)
{
    func_80102424(arg0,1);
}

s32 func_80800540_chfriendlystonehead();

void func_808002BC_chfriendlystonehead();

s32 func_80800284_chfriendlystonehead();

void func_80800238_chfriendlystonehead();

void func_80800020_chfriendlystonehead(Actor *param_0)
{
    func_8010C820(param_0, 0xA0, 0x50);
    switch (param_0->unk70_10) {
        case 1: func_80800238_chfriendlystonehead(param_0); break;
        case 2:
            _subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_80800950_chfriendlystonehead, 0.2f);
            func_80800284_chfriendlystonehead(param_0);
            func_808002BC_chfriendlystonehead(param_0);
            if (func_80101DDC(param_0)) func_80102424(param_0, 3);
            break;
        case 3:
            func_80800284_chfriendlystonehead(param_0);
            func_808002BC_chfriendlystonehead(param_0);
            func_80800540_chfriendlystonehead(param_0);
            break;
        case 4: func_808002BC_chfriendlystonehead(param_0); break;
        case 5:
            _subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_8080095C_chfriendlystonehead, 0.15f);
            func_80800238_chfriendlystonehead(param_0);
            if (func_80101DDC(param_0)) {
                func_80102424(param_0, 1);
                ((u8 *)param_0->unk0)[0x2A] &= ~0x20;
            }
            break;
        case 6: func_808002BC_chfriendlystonehead(param_0); break;
    }
}

void func_80800160_chfriendlystonehead(u8 **param_0, s32 param_1) {
    func_800DF744(3, (u32) ((*(s32 *)((s8 *)(*param_0) + (0x28))) << 0x12) >> 0x1F);
    func_80101870(param_0, param_1);
}

s32 func_808001A8_chfriendlystonehead(Actor *param_0, s32 param_1, FriendlyStoneEvent param_2)
{
    switch (param_1) {
    case 0x2E:
        func_80102424(param_0, 3);
        break;
    case 0x2F:
        func_808006C4_chfriendlystonehead(param_0, param_2.local_0, param_2.local_1);
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3(D_80800968_chfriendlystonehead, param_0->scale);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800238_chfriendlystonehead(void *param_0)
{
  u8 **arg0 = (u8 **) param_0;
  u8 *temp_v0;
  u8 **new_var3;
  u8 new_var;
  char *new_var2;
  if (func_8010C9B0(((u8 *) arg0) + 4, 0x1F4) != 0)
  {
    func_80102424(arg0, 2);
    if (((((((((((1 & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu)
    {
      new_var3 = &(*arg0);
      temp_v0 = *new_var3;
      new_var2 = (char *) temp_v0;
      *((u8 *) (((char *) temp_v0) + 0x2A)) = (new_var = (u8) (((((((((((((*((u8 *) (new_var2 + 0x2A))) & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF) | 0x20));
    }
  }
}

s32 func_80800284_chfriendlystonehead(Actor *this) {
    if (func_8010C9B0(this->position, 0x1F4) == 0) {
        func_80102424(this, 5);
    }
}

void func_808002BC_chfriendlystonehead(u8 *param_0) {
    *(f32 *)(param_0 + 0x54) = func_8010CD28(param_0);
    func_80102BF8(param_0, 0.1f, 4.0f, 120.0f);
}

int func_808002F8_chfriendlystonehead()
{
  func_800DA524(0x425);
  func_800DA524(0x426);
  func_800DA524(0x427);
}

void func_80800328_chfriendlystonehead(Actor *param_0)
{
    s32 local_0;

    local_0 = func_800DA298(0x9CB) && func_800DA298(0x5F);
    if (local_0 && !func_800D0A9C(3, 1)) {
        func_80800830_chfriendlystonehead((*(Actor **)&param_0), 0xF20);
        _capod_entrypoint_13((*(Actor **)&param_0)->unk0, 0, 1, 0x2010);
    } else if (func_800DA9E4(0x9CA, 0)) {
        func_80800830_chfriendlystonehead((*(Actor **)&param_0), 0xF22);
    } else if (func_800DA9E4(0x9CB, 0)) {
        func_808002F8_chfriendlystonehead();
        if (!func_800DA298(0x5E)) {
            func_80800830_chfriendlystonehead((*(Actor **)&param_0), 0xF1E);
        } else if (!func_800DA298(0x5F)) {
            func_80800830_chfriendlystonehead((*(Actor **)&param_0), 0xF1F);
        }
    } else {
        _subaddiedialog_entrypoint_8((*(Actor **)&param_0), (*(Actor **)&param_0)->position, &D_80800978_chfriendlystonehead, &D_808008C0_chfriendlystonehead, 4);
    }
}

void func_80800444_chfriendlystonehead(s32 param_0)
{
    s32 local_0;

    local_0 = func_800DA298(0xA17) != 0;
    if (local_0 != 0) {
        local_0 = func_800DA298(0x369) != 0;
    }
    if ((local_0 != 0) && (func_800D0A9C(0x44, 1) == 0)) {
        func_80800830_chfriendlystonehead(param_0, 0x127E);
        return;
    }
    if (func_800DA9E4(0xA16, 0) != 0) {
        func_80800830_chfriendlystonehead(param_0, 0x1280);
        return;
    }
    if (func_800DA9E4(0xA17, 0) != 0) {
        if (func_800DA298(0x368) == 0) {
            func_80800830_chfriendlystonehead(param_0, 0x127C);
            return;
        }
        if (func_800DA298(0x369) == 0) {
            func_80800830_chfriendlystonehead(param_0, 0x127D);
        }
    } else {
        _subaddiedialog_entrypoint_8(param_0, param_0 + 4, &D_80800988_chfriendlystonehead, &D_808008E0_chfriendlystonehead, 5);
    }
}

s32 func_80800540_chfriendlystonehead(Actor *param_0)
{
    u16 local_0;
    u16 local_1;
    s32 local_3;

    switch (func_800EA05C()) {
        case 0xBB:
            func_80800328_chfriendlystonehead(param_0);
            return 1;
        case 0x12D:
            func_80800444_chfriendlystonehead(param_0);
            return 1;
        default:
            local_3 = (s32)param_0->unk74_7 - 1;
            local_0 = ((u16 (*)[2])D_80800908_chfriendlystonehead)[local_3][1];
            if (func_800F64A4(func_800F54E4(), 0x1000)) local_1 = 0xF5A;
            else local_1 = ((u16 (*)[2])D_80800908_chfriendlystonehead)[local_3][0];
            if (local_0 == 0xF30) {
                if (func_800DA564(0x32B, 2) == 0) {
                    func_800DA7A8(0x32B, func_800DC128(0, 3) + 1, 2);
                }
                local_0 += func_800DA564(0x32B, 2) - 1;
            }
            D_8080099C_chfriendlystonehead = local_0;
            D_808009A4_chfriendlystonehead = local_1;
            D_8080099E_chfriendlystonehead = local_0;
            return _subaddiedialog_entrypoint_7(param_0, param_0->position, D_80800998_chfriendlystonehead);
    }
}

int func_80800680_chfriendlystonehead(s32 *param_0, s32 param_1)
{
  func_800C01A8(0x6B, 0);
  _capod_entrypoint_13(*param_0, 0, param_1, 0x2010);
}

int func_808006C4_chfriendlystonehead(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
  switch (param_1) {
    case 0xF1E:
        func_800DA544(0x5E);
        func_80800680_chfriendlystonehead(param_0, 8);
        return;
    case 0xF1F:
        func_800DA544(0x5F);
        func_80800680_chfriendlystonehead(param_0, 10);
        return;
    case 0xF19:
        func_800DA544(0x576);
        func_80800680_chfriendlystonehead(param_0, 6);
        return;
    case 0xF20:
        func_800D1000(3, 1, 0, 1, 0);
        return;
    case 0x127C:
        func_800DA544(0x368);
        func_80800680_chfriendlystonehead(param_0, 2);
        return;
    case 0x127D:
        func_800DA544(0x369);
        func_80800680_chfriendlystonehead(param_0, 4);
        return;
    case 0x1277:
        func_800DA544(0x577);
        func_80800680_chfriendlystonehead(param_0, 0);
        return;
    case 0x127E:
        func_800D1000(0x44, 1, 0, 1, 0);
        func_800C01A8(0x64, 0);
        _capod_entrypoint_13(*(s32 **)param_0, 0, 6, 0x2010);
        return;
  }
}

void func_80800830_chfriendlystonehead(param_0, param_1) Actor *param_0; s16 param_1;
{
    _subaddiedialog_entrypoint_11(param_0->unk0, param_1, 0xE, param_0->position, 0x35);
    func_80102424(param_0, 6);
    ((StoneheadMarker *)param_0->unk0)->flag = 1;
}

int chfriendlystonehead_entrypoint_0()
{
    return (int)&D_808009B4_chfriendlystonehead;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/friendlystonehead.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * Labels inside an object are linker symbols in undefined_syms.us.txt: D_8080099E_chfriendlystonehead = D_8080099C_chfriendlystonehead + 0x2
 * extern declarations adjusted to the object (same addresses): D_808008C0_chfriendlystonehead -> s32[], D_808008E0_chfriendlystonehead -> int[], D_80800978_chfriendlystonehead -> s32[], D_80800988_chfriendlystonehead -> int[], D_808009B4_chfriendlystonehead -> int[] */
extern void func_80105834();
extern void func_80107C2C();
s32 D_808008C0_chfriendlystonehead[8] = { 0x80, 0xF190100, 0x80, 0xF1A0200, 0x1, 0xF1B0300, 0x1000, 0xF5A0300 };
int D_808008E0_chfriendlystonehead[10] = { 0x201, 0x12790200, 0x400, 0x12DF0200, 0x1000, 0x12E00200, 0x80, 0x12770100, 0x80, 0x12780200 };
u16 D_80800908_chfriendlystonehead[8] = { 0xF0F, 0xF30, 0xF11, 0xF10, 0xF13, 0xF12, 0xF15, 0xF14 };
u32 D_80800918_chfriendlystonehead[14] = { 0x0, 0x0, 0x3FC00000, 0x7A0044, 0x3FC00000, 0x7A0002, 0x40800000, 0x7B0001, 0x40800000, 0x7B0001, 0x3FA66666, 0x7C0002, 0x40800000, 0x7B0001 };
u8 D_80800950_chfriendlystonehead[12] = { 0x0, 0x13, 0x6, 0x42, 0x0, 0xD, 0x0, 0xC0, 0x0, 0xD9, 0x0, 0x0 };
u8 D_8080095C_chfriendlystonehead[12] = { 0x0, 0x13, 0x6, 0x42, 0x0, 0xD, 0x0, 0xA6, 0x0, 0xC0, 0x0, 0x0 };
u8 D_80800968_chfriendlystonehead[16] = { 0x43, 0x20, 0x0, 0x0, 0x42, 0xC8, 0x0, 0x0, 0x42, 0xC8, 0x0, 0x0, 0x42, 0x20, 0x0, 0x0 };
s32 D_80800978_chfriendlystonehead[4] = { 0x640000, 0x12C0035, 0xE, 0x400 };
int D_80800988_chfriendlystonehead[4] = { 0x36E0000, 0x12C0035, 0xE, 0x400 };
u8 D_80800998_chfriendlystonehead[4] = { 0x0, 0x0, 0x1, 0x2C };
u16 D_8080099C_chfriendlystonehead = 0x0;
static u32 D_8080099C_chfriendlystonehead_rest[1] = { 0x80 };
u16 D_808009A4_chfriendlystonehead = 0x0;
static u32 D_808009A4_chfriendlystonehead_rest[3] = { 0x350000, 0xE4000, 0x4000000 };
int D_808009B4_chfriendlystonehead[19] = { 0x15C0114, 0x6760001, (u32)&D_80800918_chfriendlystonehead, (u32)func_80800020_chfriendlystonehead, (u32)func_80105834, (u32)func_80800160_chfriendlystonehead, 0x3E80000, 0x3F99999A, 0x0, 0x40000000, 0x0, 0x0, 0x0, (u32)func_80800000_chfriendlystonehead, (u32)func_80107C2C, -0x7DFFDBAA, (u32)func_808001A8_chfriendlystonehead, 0x0, 0x0 };
