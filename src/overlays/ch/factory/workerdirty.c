#include "ch/factory/workerdirty.h"

extern int D_80800EF8_chfactoryworkerdirty[];
extern s32 D_80800F90_chfactoryworkerdirty[];
extern void _subaddieaudioquick_entrypoint_2(s32, s32, void *);
extern s32 D_80800FD0_chfactoryworkerdirty;
extern u16 D_80800FD4_chfactoryworkerdirty[];
extern u16 D_80800FD6_chfactoryworkerdirty;
extern s32 D_80800FEC_chfactoryworkerdirty[];
extern s16 D_8080100C_chfactoryworkerdirty[];
extern u8 D_80801008_chfactoryworkerdirty[];
extern void *func_80100094(Actor *, u32);
extern Actor *func_801084B0(s32, Actor **);
extern void func_80101010(s32);
extern void func_8010105C(f32);
extern u8 D_80800F80_chfactoryworkerdirty[];
extern u8 D_80800FA0_chfactoryworkerdirty[];
extern u8 D_80800FB0_chfactoryworkerdirty[];
extern u8 D_80800FC0_chfactoryworkerdirty[];
extern u8 D_80800F40_chfactoryworkerdirty[];
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void _sudeflect_entrypoint_1(u8 *, f32, f32, f32, s32);
extern void _subaddieaudioquick_entrypoint_3();
extern s32 func_80101E14(Actor *, f32);
extern void func_800BBCB8(u8 *, u8 *, f32, s32, u8 *);
typedef union DirtyWorkerEvent { u32 local_0; s16 local_1[2]; } DirtyWorkerEvent;
extern f32 D_80801024_chfactoryworkerdirty[];
extern f32 D_80801034_chfactoryworkerdirty[];
extern void _gcdialogcamera_entrypoint_3(f32 *, f32);
s32 func_808009C0_chfactoryworkerdirty();
int func_80800A14_chfactoryworkerdirty();
s32 func_80800A54_chfactoryworkerdirty();
int func_80800AB4_chfactoryworkerdirty();
s32 func_80800B40_chfactoryworkerdirty();
void func_808000AC_chfactoryworkerdirty();
s32 func_808008A4_chfactoryworkerdirty(Actor *param_0, s32 param_1, DirtyWorkerEvent param_2);
extern void func_80101870(), func_80105834(), func_80107C2C(), func_8080025C_chfactoryworkerdirty(), func_80800340_chfactoryworkerdirty();
extern u8 D_80800ED0_chfactoryworkerdirty[];

int chfactoryworkerdirty_entrypoint_0()
{
    return &D_80800EF8_chfactoryworkerdirty;
}

void func_8080000C_chfactoryworkerdirty(Actor* arg0)
{
    func_80108B04(arg0,1);
}

void func_8080002C_chfactoryworkerdirty(Actor *param_0)
{
    void *local_0 = func_80100094(param_0, 0);
    func_8010114C(*(s32 **)((char *)local_0 + 0x0), 0x2C, 0);
    *(s32 **)((char *)local_0 + 0x0) = 0;
}

void func_80800068_chfactoryworkerdirty(s32 *param_0, s32 param_1, s32 param_2) {
    s16 sp1E;
    s16 sp1C;

    if (*param_0 != 0) {
        sp1C = param_1;
        sp1E = param_2;
        func_8010114C(*param_0, 0x21, *(s32 *)&sp1C);
    }
}

void func_808000AC_chfactoryworkerdirty(param_0, param_1) Actor *param_0; s32 param_1;
{
    u8 *local_0;
    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
    case 3:
        func_8080000C_chfactoryworkerdirty(param_0);
        func_801032B0(param_0, 0x83B, param_0->unk0->unk16);
        func_80102424(param_0, 2);
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800F80_chfactoryworkerdirty);
        break;
    case 4: func_80800068_chfactoryworkerdirty(local_0, 1, 1); break;
    case 5: func_80800068_chfactoryworkerdirty(local_0, 1, 2); break;
    case 6: func_80800068_chfactoryworkerdirty(local_0, 1, 3); break;
    case 7:
    case 8:
        func_80102424(param_0, 4);
        func_801032B0(param_0, 0x803, param_0->unk0->unk16);
        switch (local_0[0x10]) {
        case 6:
            func_8080002C_chfactoryworkerdirty(param_0);
            *(f32 *)(local_0 + 8) = 8.0f;
            *(f32 *)(local_0 + 0xC) = 0.0f;
            func_80800AF8_chfactoryworkerdirty(param_0);
            param_0->unk74_30 = 0;
            break;
        case 1:
            if (_glcutDll_entrypoint_20()) {
                *(f32 *)(local_0 + 8) = 8.0f;
                *(f32 *)(local_0 + 0xC) = 0.0f;
            } else { *(f32 *)(local_0 + 8) = 0.0f; }
            param_0->unk74_30 = 1;
            func_801032B0(param_0, 0x803, param_0->unk0->unk16);
            break;
        }
        break;
    }
    local_0[0x10] = param_1;
}

s32 func_808009E4_chfactoryworkerdirty();

void func_8080025C_chfactoryworkerdirty(param_0) Actor *param_0;
{
    void *local_0;
    f32 local_1[3];
    local_0 = func_80100094(param_0, 0);
    *(u8 *)((char *)local_0 + 0x10) = 1;
    *(s32 *)local_0 = 0;
    if (func_808009E4_chfactoryworkerdirty() && func_80800A14_chfactoryworkerdirty(param_0) && _glcutDll_entrypoint_20() == 0 && func_800D0B68(0x36, 1) == 0) {
        func_800EEB9C(&local_1, *(f32 **)((char *)param_0 + 0x48), 0x42C80000);
        func_800EF04C(&local_1, (f32 *)((char *)param_0 + 4));
        func_800D1000(0x36, 1, &local_1, 3, 0);
    }
    if (_glcutDll_entrypoint_20()) {
        func_808000AC_chfactoryworkerdirty(param_0, 8);
    } else {
        if (func_80800AB4_chfactoryworkerdirty(param_0)) {
            func_808000AC_chfactoryworkerdirty(param_0, 7);
        }
    }
    *(f32 *)((char *)param_0 + 0x54) = *(f32 *)((char *)param_0 + 0x48);
}

void func_80800340_chfactoryworkerdirty(Actor* arg0)
{
    func_80100094(arg0,0);
    func_80800DB4_chfactoryworkerdirty(arg0);
}

void func_8080036C_chfactoryworkerdirty(s32 param_0)
{
    _subaddieaudioquick_entrypoint_2(param_0, param_0 + 4, &D_80800F90_chfactoryworkerdirty);
}

void func_80800C98_chfactoryworkerdirty();

void func_80800700_chfactoryworkerdirty();

void func_8080061C_chfactoryworkerdirty();

void func_80800394_chfactoryworkerdirty(Actor *param_0)
{
    u8 *local_0;
    s32 local_4;
    u8 **new_var;
    u8 *local_2;

    local_0 = func_80100094(param_0, 0);
    func_80800C98_chfactoryworkerdirty(param_0);
    if ((u32) (*((u16 *) (((u8 *) param_0) + 0x72))) >> 10 == 2)
    {
        _subaddieaudioquick_entrypoint_3(param_0, ((u8 *) param_0) + 4, D_80800FA0_chfactoryworkerdirty, 0x3F000000);
        if (func_80101DDC(param_0) != 0)
        {
            func_80102424(param_0, 3);
        }
    }
    switch ((local_0[0x10]))
    {
        case 1:
            local_2 = ((u8 *) param_0) + 4;
            if (func_800C0638() == 0)
            {
                if (func_80101E14(param_0, 0.13f) != 0 || func_80101E14(param_0, 0.215f) != 0 ||
                    func_80101E14(param_0, 0.27f) != 0 || func_80101E14(param_0, 0.34f) != 0)
                {
                    func_8080036C_chfactoryworkerdirty(param_0);
                }
                _subaddieaudioquick_entrypoint_3(param_0, local_2, D_80800FB0_chfactoryworkerdirty, 0x3ECCCCCD);
            }
            _sudeflect_entrypoint_1(local_2, 120.0f, 0.0f, 70.0f, 0xA);
            func_8080061C_chfactoryworkerdirty(param_0);
            return;

        case 2:
            _sudeflect_entrypoint_1(((u8 *) param_0) + 4, 120.0f, 0.0f, 70.0f, 0xA);
            return;

        case 3:
            func_808000AC_chfactoryworkerdirty(param_0, 4);
            return;

        case 7:
        case 8:
            local_2 = ((u8 *) param_0) + 4;
            new_var = &local_2;
            if (func_800C0638() == 0 && func_80101E14(param_0, 0.46f) != 0)
            {
                _subaddieaudioquick_entrypoint_2(param_0, *new_var, D_80800FC0_chfactoryworkerdirty);
            }
            if (*((f32 *) (local_0 + 8)) > 0)
            {
                *((f32 *) (local_0 + 0xC)) += func_800F10B4(*((f32 *) (local_0 + 8)), 0, 8.0f, 0, 5.0f);
                local_4 = (s32) (*((f32 *) (local_0 + 0xC)));
                func_800BBCB8(*new_var, 0, 1.0f, local_4, D_80800F40_chfactoryworkerdirty);
                *((f32 *) (local_0 + 0xC)) = *((f32 *) (local_0 + 0xC)) - ((f32) local_4);
                func_800D9078(local_0 + 8);
            }
            _sudeflect_entrypoint_1(*new_var, 120.0f, 0.0f, 70.0f, 0xA);
            func_80800994_chfactoryworkerdirty(param_0);
            func_80800700_chfactoryworkerdirty(param_0);
            return;

        default:
            return;
    }
}

void func_8080061C_chfactoryworkerdirty(u8 *param_0) {
    s32 *local_2;

    if (func_80090178(0x40) != 0) {
        local_2 = &D_80800FD0_chfactoryworkerdirty;
        if (func_808009C0_chfactoryworkerdirty() != 0) {
            D_80800FD4_chfactoryworkerdirty[0] = D_80800FD6_chfactoryworkerdirty;
        }
        (*(u8 *)((s8 *)(param_0) + (0x74))) = (u8) ((*(u8 *)((s8 *)(param_0) + (0x74))) & 0xFFBF);
    } else {
        local_2 = &D_80800FEC_chfactoryworkerdirty;
    }
    switch (_subaddiedialog_entrypoint_7(param_0, param_0 + 4, local_2)) {
    case 0x134C:
        func_80090734(1, param_0 + 4);
        func_808000AC_chfactoryworkerdirty(param_0, 2);
        return;
    case 0x134D:
        func_80090734(1, param_0 + 4);
        func_808000AC_chfactoryworkerdirty(param_0, 2);
        return;
    default:
        func_80090734(1, param_0 + 4);
    case 0x0:
        return;
    }
}

void func_80800700_chfactoryworkerdirty(Actor *param_0)
{
    if (func_808009E4_chfactoryworkerdirty()) D_8080100C_chfactoryworkerdirty[0] = 0x1350;
    else if (func_80800A54_chfactoryworkerdirty() == 1) D_8080100C_chfactoryworkerdirty[0] = 0x134F;
    else D_8080100C_chfactoryworkerdirty[0] = 0x134E;
    if (_subaddiedialog_entrypoint_7(param_0, param_0->position, D_80801008_chfactoryworkerdirty)) {
        func_80090734(1, param_0->position);
    }
}

void func_80800788_chfactoryworkerdirty(s32 *param_0, s32 param_1, s32 param_2) {
    switch (param_1) {                                 
    case 0x134C: ;
    case 0x134D:
        func_80090708(0);
        func_800904F4(0x65, *param_0);
        return;
    case 0x1350:
        func_80800B40_chfactoryworkerdirty(param_0);
        func_80090708(0);
        func_800D1000(0x36, 1, param_0 + 1, 0, 0);
        return;
    default:
        func_80090708(0);
        return;
    }
}

int func_80800828_chfactoryworkerdirty(s32 param_0, s32 param_1, s32 param_2)
{
  if (param_1 == 0x134E)
  {
    return func_80800A54_chfactoryworkerdirty();
  }
  return 0;
}

void func_80800864_chfactoryworkerdirty(Actor *param_0)
{
    void *local_0;
    local_0 = func_80100094(param_0, 0);
    _subaddielink_entrypoint_1(local_0, func_801084B0(0x239, &param_0)->unk0);
}

s32 func_80800D48_chfactoryworkerdirty();

s32 func_808008A4_chfactoryworkerdirty(Actor *param_0, s32 param_1, DirtyWorkerEvent param_2)
{
    switch (param_1) {
        case 0x3D:
            func_80800864_chfactoryworkerdirty(param_0);
            return 0;
        case 0x52:
            if (func_801022E4(param_0) == 0x35E) {
                _gcdialogcamera_entrypoint_3(D_80801024_chfactoryworkerdirty, param_0->scale);
            } else {
                _gcdialogcamera_entrypoint_3(D_80801034_chfactoryworkerdirty, param_0->scale);
            }
            return 1;
        case 0x2E:
            func_80800788_chfactoryworkerdirty(param_0, param_2.local_1[0], param_2.local_1[1]);
            return 1;
        case 0x30:
            return func_80800828_chfactoryworkerdirty(param_0, param_2.local_1[0], param_2.local_1[1]);
        case 0x29:
            func_80800D48_chfactoryworkerdirty(param_0);
            return 1;
        case 0x2A:
            func_80800DB4_chfactoryworkerdirty(param_0);
            return 1;
    }
    return 0;
}

int func_80800994_chfactoryworkerdirty(int param_0)
{
  unsigned int new_var2;
  int new_var;
  func_80102BF8(param_0, 0x3E99999A, 0x40400000, 0x43960000);
  new_var2 = (new_var = 0);
}

s32 func_808009C0_chfactoryworkerdirty(void){
    func_800DA564(0x42D, 6);
}

s32 func_808009E4_chfactoryworkerdirty()
{
    return func_800DA298(FLAG_433_UNK);
}

s32 func_80800A04_chfactoryworkerdirty(param_0) Actor *param_0;
{
  return ((((u16) (*((u16 *) (((char *) param_0) + 0x76)))) & 0xFFFFFFFF) >> 7) - 0x32;
}

int func_80800A14_chfactoryworkerdirty(param_0) Actor *param_0;
{
  s32 local_0;
  s32 local_1;
  local_0 = func_800DA564(0x42D, 6);
  local_1 = func_80800A04_chfactoryworkerdirty(param_0) + 1 == local_0;
  return local_1;
}

s32 func_80800A54_chfactoryworkerdirty(void) {
    s32 local_0;
    s32 local_1;
    s32 local_2;

    local_1 = 0;
    local_0 = 0;
    do {
        if (func_800DA298(local_0 + 0x42D) == 0) {
            local_2 = 1;
        } else {
            local_2 = 0;
        }
        local_1 += local_2;
        local_0++;
    } while (local_0 != 6);
    return local_1;
}

int func_80800AB4_chfactoryworkerdirty(param_0) s32 param_0; {
    return func_808009E4_chfactoryworkerdirty() != 0 || func_800DA298(func_80800A04_chfactoryworkerdirty(param_0) + 0x42D) != 0;
}

int func_80800AF8_chfactoryworkerdirty()
{
  s32 local_0;
  local_0 = func_80800A04_chfactoryworkerdirty();
  func_800DA544(local_0 + 0x42D);
  if (func_800DA564(0x42D, 6) == 0x3F)
  {
    func_800DA544(0x433);
  }
}

s32 func_80800B40_chfactoryworkerdirty(void){
    s32 temp = func_80800A04_chfactoryworkerdirty();
    func_800DA7A8(0x42D, temp + 1, 6);
}

void chfactoryworkerdirty_entrypoint_1(s32 param_0, s32 param_1) {
    s32 temp_a0;

    temp_a0 = func_80106790(param_0);
    switch (param_1) {
    case 1:
        func_808000AC_chfactoryworkerdirty(temp_a0, 3);
        return;
    case 2:
        func_808000AC_chfactoryworkerdirty(temp_a0, 5);
        return;
    case 3:
        func_808000AC_chfactoryworkerdirty(temp_a0, 6);
        return;
    case 4:
        func_808000AC_chfactoryworkerdirty(temp_a0, 7);
        return;
    }
}

void chfactoryworkerdirty_entrypoint_2(Unk80132ED0 *param_0, s32 param_1, f32 param_2) {
    Actor *local_1 = func_80106790(param_0);
    void *local_0 = func_80100094(local_1, 0);
    func_80101010(param_1);
    func_8010105C(param_2);
    func_80800068_chfactoryworkerdirty(local_0, 3, 0);
}

void chfactoryworkerdirty_entrypoint_3(Unk80132ED0 *param_0, f32 param_1) {
    Actor *local_1 = func_80106790(param_0);
    void *local_0 = func_80100094(local_1, 0);
    func_8010105C(param_1);
    func_80800068_chfactoryworkerdirty(local_0, 2, 0);
}

void func_80800C98_chfactoryworkerdirty(s32 *param_0) {
    if (func_80100094(param_0, 1) != 0) {
        if (func_801022E4(param_0) == 0x35D) {
            if (func_80102320(param_0, 0x3ECCCCCD, 0x3F400000) != 0) {
                _suexpression_entrypoint_18(func_80100094(param_0, 1), 1);
            }
        } else {
            _suexpression_entrypoint_18(func_80100094(param_0, 1), 1);
        }
        _suexpression_entrypoint_10(func_80100094(param_0, 1), *param_0, 0);
    }
}

s32 func_80800D48_chfactoryworkerdirty(Actor *this){
    if(!func_80100094(this, 1)){
        _suexpression_entrypoint_7(this, 1, 0x8F);
        _suexpression_entrypoint_12(func_80100094(this, 1), 0x42700000, 0x41700000);
        _suexpression_entrypoint_17(func_80100094(this, 1), 0x4B0);
    }
}

void func_80800DB4_chfactoryworkerdirty(Actor *this) {
    if (func_80100094(this, 1)) {
        _suexpression_entrypoint_8(this, 1);
    }
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/factory/workerdirty.data.s) is defined here in C --
 * tables holding function pointers must be in the same unit, otherwise IDO's assembler schedules those functions differently.
 * D_80800FD6_chfactoryworkerdirty is a label inside D_80800FD4_chfactoryworkerdirty, defined in undefined_syms.us.txt.
 * extern views adjusted to the object (address-neutral): D_80800EF8_chfactoryworkerdirty -> int[], D_80800F90_chfactoryworkerdirty -> s32[], D_80800FD4_chfactoryworkerdirty -> u16[] (used as NAME[0]), D_80800FEC_chfactoryworkerdirty -> s32[], D_8080100C_chfactoryworkerdirty -> s16[] (used as NAME[0]) */
u8 D_80800ED0_chfactoryworkerdirty[40] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40, 0xBC, 0xCC, 0xCD, 0x3, 0x5D, 0x0, 0x1, 0x3F, 0xF3, 0x33, 0x33, 0x1, 0x23, 0x0, 0xA, 0x3D, 0xF5, 0xC2, 0x8F, 0x1, 0x4B, 0x0, 0x1, 0x40, 0x2C, 0xCC, 0xCD, 0x3, 0x5E, 0x0, 0x1 };
int D_80800EF8_chfactoryworkerdirty[18] = { 0x27E0170, 0x8020001, (u32)&D_80800ED0_chfactoryworkerdirty, (u32)func_80800394_chfactoryworkerdirty, (u32)func_80105834, (u32)func_80101870, 0x7D00000, 0x3F800000, 0x0, 0x40000120, (u32)func_80800340_chfactoryworkerdirty, 0x0, 0x140000, (u32)func_8080025C_chfactoryworkerdirty, (u32)func_80107C2C, -0x7FFFDBEE, (u32)func_808008A4_chfactoryworkerdirty, 0x0 };
u8 D_80800F40_chfactoryworkerdirty[64] = { 0x0, 0x1D, 0x9, 0xEA, 0x0, 0x15, 0x0, 0x33, 0x0, 0x80, 0x0, 0xB, 0x0, 0x32, 0x0, 0x3C, 0x0, 0x78, 0x0, 0x0, 0x0, 0x2C, 0xFF, 0xD8, 0x0, 0x50, 0xFF, 0xD8, 0x0, 0x28, 0x0, 0x78, 0x0, 0x28, 0x0, 0x27, 0x0, 0x0, 0x0, 0xC8, 0x0, 0x0, 0x0, 0xFA, 0x0, 0x24, 0x0, 0x23, 0x0, 0x23, 0x0, 0x25, 0x0, 0xA, 0x0, 0xA, 0x0, 0x2B, 0x0, 0x4C, 0x0, 0x4C, 0x0, 0x0 };
u8 D_80800F80_chfactoryworkerdirty[16] = { 0x0, 0x13, 0x4, 0xA2, 0x0, 0x16, 0x6D, 0x60, 0x0, 0xA, 0x1, 0x80, 0x0, 0x0, 0x0, 0x0 };
s32 D_80800F90_chfactoryworkerdirty[4] = { 0x1305CA, 0x1655F0, 0xD00D9, 0xF30000 };
u8 D_80800FA0_chfactoryworkerdirty[16] = { 0x0, 0x13, 0x5, 0x5E, 0x0, 0xD, 0x1, 0x4C, 0x1, 0x4C, 0x0, 0x16, 0x46, 0x50, 0x0, 0x0 };
u8 D_80800FB0_chfactoryworkerdirty[16] = { 0x0, 0x13, 0x4, 0xE4, 0x0, 0x16, 0x55, 0xF0, 0x0, 0xD, 0x1, 0x59, 0x1, 0x66, 0x0, 0x0 };
u8 D_80800FC0_chfactoryworkerdirty[16] = { 0x0, 0x13, 0x4, 0xE5, 0x0, 0x16, 0x55, 0xF0, 0x0, 0xD, 0x1, 0x59, 0x1, 0x66, 0x0, 0x0 };
s32 D_80800FD0_chfactoryworkerdirty = 0xE6;
u16 D_80800FD4_chfactoryworkerdirty[12] = { 0x134C, 0x134D, 0x0, 0x40, 0x0, 0x0, 0x8F, 0x0, 0x6, 0x4732, 0x0, 0x0 };
s32 D_80800FEC_chfactoryworkerdirty[7] = { 0x42C00E6, 0x134A134B, -0x1, 0x0, 0x8F0000, 0x60732, 0x0 };
u8 D_80801008_chfactoryworkerdirty[4] = { 0x0, 0x0, 0x0, 0xE6 };
s16 D_8080100C_chfactoryworkerdirty[12] = { 0x0, 0x1351, 0x0, 0x40, 0x1351, 0x0, 0x8E, 0x0, 0x6, 0x4732, 0x0, 0x0 };
f32 D_80801024_chfactoryworkerdirty[4] = { 1.8e+02f, 1e+02f, 1e+02f, 3e+01f };
f32 D_80801034_chfactoryworkerdirty[7] = { 1.5e+02f, 1e+02f, 1e+02f, 3e+01f, 0.0f, 0.0f, 0.0f };
