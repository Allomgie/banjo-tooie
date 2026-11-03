/*
 * ch/credits (overlays) -- IDO 5.3, -O2 -mips2 -G 0 (project default).
 */

#include "common.h"

extern u8 D_80127611;
extern s16 D_808012C0_chcredits[][4];
extern s16 D_80801208_chcredits[][4];
extern s16 D_808012BA_chcredits[][4];
extern s16 D_80801202_chcredits[][4];
extern u8 D_80127610[];
typedef struct { u8 unk0; u8 unk1; u8 unk2; } CreditsState_808000E8_chcredits;
extern void func_808000C8_chcredits(void);
extern void _gcfrontend_entrypoint_9(s32);
extern u8 D_8012760D[];
extern void _capod_entrypoint_14(void);
typedef struct { u8 unk0; u8 unk1; u8 unk2; } CreditsState_80800464_chcredits;
typedef struct { s8 unk0; s8 unk1; s8 unk2; s8 pad3[5]; } CreditsLines;
extern CreditsLines D_808012BC_chcredits[];
extern CreditsLines D_80801204_chcredits[];
extern void *func_80100094(Actor *, s32);
extern void *_gldbstring_entrypoint_0(s32, s32);
extern char *_gldbstring_entrypoint_1(void *, s16);
extern void _gldbstring_entrypoint_2(s32);
extern void func_800E715C(char *, char *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern f32 D_80801578_chcredits[][3];
extern f32 D_80801560_chcredits[][3];
extern f32 D_8080155C_chcredits;
extern f32 D_80801548_chcredits[3];
extern f32 D_80801554_chcredits[3];
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800E3C8C(f32, f32);
extern void func_800E7CF4(void *);
extern void func_800DE498(void *, f32 *, f32 *, f32, s32, void *);
extern u8 *func_800B8C50(void);
extern void func_800B7F14(void *);
extern void func_800B8CB0(s32);
extern s32 func_800E7188();
extern void func_800B811C(void *);
extern u8 D_80801590_chcredits[];
extern void *D_8080159C_chcredits[];
typedef struct { u8 pad_0[0x72]; u16 st : 6; u16 rest : 10; } CreditsState_80800800_chcredits;
extern f32 func_800D8FF8(void);
extern void func_80015ECC(s32, s32 *);
extern s32 func_800DA9E4(s32, s32);
extern void func_800B8CF0(f32);

/* Forward declarations of the functions in this file. */
void func_80800710_chcredits();
void func_80800E4C_chcredits();

s16 func_80800000_chcredits();
s16 func_8080003C_chcredits(s32 param_0);
s32 func_80800078_chcredits(void);
int func_808000B4_chcredits(s32 param_0);
void func_808000E8_chcredits(void);
void chcredits_entrypoint_0(u32 param_0);
s32 chcredits_entrypoint_1(void);
void func_808002A4_chcredits(s32 param_0);
void func_80800300_chcredits(Actor *param_0);
void func_8080038C_chcredits(void);
void func_808003E8_chcredits();
void func_80800464_chcredits(Actor *this);
void func_80800C84_chcredits(Actor *param_0, void *param_1);
void func_80800F50_chcredits(u8 *param_0, u8 *param_1);
int * chcredits_entrypoint_2();
void func_80800800_chcredits(Actor *param_0);
s16 func_80800000_chcredits(param_0) s32 param_0; {
    if (D_80127611 == 2) {
        return D_808012C0_chcredits[param_0][0];
    }
    return D_80801208_chcredits[param_0][0];
}

s16 func_8080003C_chcredits(s32 param_0) {
    if (D_80127611 == 2) {
        return D_808012BA_chcredits[param_0][0];
    }
    return D_80801202_chcredits[param_0][0];
}

s32 func_80800078_chcredits(void) {
    if (D_80127610[1] == 2) {
        return D_80127610[0] >= 0x51U;
    }
    return D_80127610[0] >= 0x16U;
}

int func_808000B4_chcredits(s32 param_0)
{
  s8 *local_0 = ((int *) D_80127610);
  local_0[1] = param_0;
  local_0[0] = 0;
}

void func_808000C8_chcredits()
{
    _glcutDll_entrypoint_17();
}

void func_808000E8_chcredits(void)
{
    switch ((*((CreditsState_808000E8_chcredits *) D_80127610)).unk2) {
    case 0:
        switch ((*((CreditsState_808000E8_chcredits *) D_80127610)).unk1) {
        case 0:
            func_808000B4_chcredits(1);
            break;
        case 1:
            func_808000C8_chcredits();
            break;
        }
        break;
    case 1:
        _gcfrontend_entrypoint_9(0x85);
        switch ((*((CreditsState_808000E8_chcredits *) D_80127610)).unk1) {
        case 0:
            func_808000B4_chcredits(2);
            break;
        case 2:
            func_808000C8_chcredits();
            break;
        }
        break;
    case 2:
        switch ((*((CreditsState_808000E8_chcredits *) D_80127610)).unk1) {
        case 0:
            func_808000B4_chcredits(1);
            break;
        case 1:
            func_808000B4_chcredits(2);
            break;
        case 2:
            func_808000C8_chcredits();
            break;
        }
        break;
    }
}

void chcredits_entrypoint_0(u32 param_0)
{
    u8 *local_0;

    local_0 = D_80127610;
    local_0[1] = 0;
    local_0[2] = param_0;
    func_808000E8_chcredits();
    func_800DA544(0x650);
    _glcutDll_entrypoint_0();
    _glcutDll_entrypoint_7(func_80800000_chcredits(-1));
    _glcutDll_entrypoint_22(0x8C);
    _glcutDll_entrypoint_16();
}

s32 chcredits_entrypoint_1(void) {
    if (*(u8 *)((char *)&D_80127610 + 0 + 1) == 2) {
        return func_8080003C_chcredits(*(u8 *)((char *)&D_80127610 + 0));
    }
    return -1;
}

void func_808002A4_chcredits(s32 param_0) {
    if (D_8012760D[3] == 0) {
        func_80800710_chcredits(param_0, 2);
    } else {
        func_80800710_chcredits(param_0, 3);
    }
    func_808003E8_chcredits(param_0, func_8080003C_chcredits(D_8012760D[3]));
}

void func_80800300_chcredits(Actor *param_0)
{
    s32 local_0;
    u8 *local_1;
    if (func_80800078_chcredits()) func_808000E8_chcredits();
    else {
        local_0 = func_80800000_chcredits((*((u8 *) D_80127610)));
        local_1 = ((u8 *) D_80127610);
        (*local_1)++;
        if (func_800EA05C() != local_0) _glcutDll_entrypoint_24(local_0, -1, -1);
        else {
            _capod_entrypoint_14();
            func_808002A4_chcredits(param_0);
        }
    }
}

void func_8080038C_chcredits(void)
{
    s32 local_0;

    local_0 = func_800EA05C();
    if (local_0 == 0x19C || local_0 == 0x19D) {
        if (func_800D395C()) {
            _gcfrontend_entrypoint_10();
        } else {
            _gcgoto_entrypoint_1(0x194, 0);
        }
    }
}

void func_808003E8_chcredits(param_0, param_1) s32 *param_0; s32 param_1; {
    s32 temp_v0;

    temp_v0 = func_800A5854(param_1);
    if (temp_v0 != 2) {
        if ((temp_v0 == 5) || (temp_v0 == 6) || (temp_v0 == 8)) {
            _capod_entrypoint_13(*param_0, 0, param_1, 0x834);
        }
    } else {
        _capod_entrypoint_21(*param_0, 0, param_1, 0x814);
    }
}

void func_80800464_chcredits(Actor *this)
{
    char *buf;
    s32 pad;
    s32 id;
    void *db;
    char *s;
    s32 i;

    buf = func_80100094(this, 0);
    if ((*((CreditsState_80800464_chcredits *) D_80127610)).unk1 == 2) {
        if (D_808012BC_chcredits[(*((CreditsState_80800464_chcredits *) D_80127610)).unk0].unk0 >= 0) {
            id = D_808012BC_chcredits[(*((CreditsState_80800464_chcredits *) D_80127610)).unk0].unk0 + 0x1B86;
            db = _gldbstring_entrypoint_0(0, id);
            for (i = 0; i != 2; i++) {
                s = _gldbstring_entrypoint_1(db, i);
                if (s) {
                    func_800E715C(buf + i * 0x80, s);
                } else {
                    func_800E715C(buf + i * 0x80, "");
                }
            }
            _gldbstring_entrypoint_2(id);
        } else {
            for (i = 0; i != 2; i++) {
                func_800E715C(buf + i * 0x80, "");
            }
        }
        id = D_808012BC_chcredits[(*((CreditsState_80800464_chcredits *) D_80127610)).unk0].unk1 + 0x1B88;
        db = _gldbstring_entrypoint_0(0, id);
        func_800E715C(buf + 0x100, _gldbstring_entrypoint_1(db, D_808012BC_chcredits[(*((CreditsState_80800464_chcredits *) D_80127610)).unk0].unk2));
        _gldbstring_entrypoint_2(id);
    } else {
        if (D_80801204_chcredits[(*((CreditsState_80800464_chcredits *) D_80127610)).unk0].unk0 >= 0) {
            id = D_80801204_chcredits[(*((CreditsState_80800464_chcredits *) D_80127610)).unk0].unk0 + 0x1B68;
            db = _gldbstring_entrypoint_0(0, id);
            for (i = 0; i != 2; i++) {
                s = _gldbstring_entrypoint_1(db, i);
                if (s) {
                    func_800E715C(buf + i * 0x80, s);
                } else {
                    func_800E715C(buf + i * 0x80, "");
                }
            }
            _gldbstring_entrypoint_2(id);
        } else {
            for (i = 0; i != 2; i++) {
                func_800E715C(buf + i * 0x80, "");
            }
        }
        id = (*((CreditsState_80800464_chcredits *) D_80127610)).unk0 + 0x1B6F;
        db = _gldbstring_entrypoint_0(0, id);
        for (i = 0; i != 3; i++) {
            s = _gldbstring_entrypoint_1(db, i);
            if (s) {
                func_800E715C(buf + 0x100 + i * 0x80, s);
            } else {
                func_800E715C(buf + 0x100 + i * 0x80, "");
            }
        }
        _gldbstring_entrypoint_2(id);
    }
}

void func_80800710_chcredits(param_0, param_1) Actor *param_0; s32 param_1;
{
    func_80102424(param_0, param_1);
    switch (param_0->unk70_10) {
        case 2:
            param_0->unk64_19 = 1;
            *(f32 *)((u8 *)param_0 + 0x34) = 1.0f;
            break;
        case 3:
            func_80800464_chcredits(param_0);
            param_0->unk58 = 0.75f;
            break;
        case 4:
            param_0->unk64_19 = 0;
            if (func_800EA05C() == 0x116) {
                param_0->unk58 = 10.0f;
            } else {
                param_0->unk58 = 7.0f;
            }
            break;
        case 5:
            param_0->unk58 = 0.75f;
            break;
        case 8:
            func_8080038C_chcredits();
            break;
        case 6:
            *(f32 *)((u8 *)param_0 + 0x34) = 1.0f;
            break;
    }
}

void func_80800800_chcredits(Actor *param_0)
{
    f32 local_0;
    s32 local_1[6];

    local_0 = func_800D8FF8();
    if (((CreditsState_80800800_chcredits *)param_0)->st >= 3 && ((CreditsState_80800800_chcredits *)param_0)->st < 6) {
        func_80015ECC(0, local_1);
        if (local_1[1] == 1) {
            func_808000C8_chcredits();
        }
    }
    switch (((CreditsState_80800800_chcredits *)param_0)->st) {
    case 2:
        if (*(f32 *)&param_0->actorData[7] <= 0) {
            func_80800710_chcredits(param_0, 3);
            return;
        }
        *(f32 *)&param_0->actorData[7] = *(f32 *)&param_0->actorData[7] - local_0;
        break;
    case 3:
        if (param_0->unk58 <= 0) {
            func_80800710_chcredits(param_0, 4);
            param_0->unk6C_0 = 0xFF;
            break;
        }
        param_0->unk58 = param_0->unk58 - local_0;
        param_0->unk6C_0 = (u32)func_800F10B4(param_0->unk58, 0.75f, 0.0f, 0.0f, 255.0f);
        break;
    case 4:
        if (param_0->unk58 <= 0) {
            func_80800710_chcredits(param_0, 5);
            return;
        }
        param_0->unk58 = param_0->unk58 - local_0;
        break;
    case 5:
        if (param_0->unk58 <= 0) {
            func_80800300_chcredits(param_0);
            param_0->unk6C_0 = 0;
            break;
        }
        param_0->unk58 = param_0->unk58 - local_0;
        param_0->unk6C_0 = (u32)func_800F10B4(param_0->unk58, 0.75f, 0.0f, 255.0f, 0.0f);
        break;
    case 7:
        if (func_800C954C()) {
            return;
        }
        switch (func_800EA05C()) {
        case 0x19C:
            if (func_800DA9E4(0x650, 0)) {
                func_8080038C_chcredits();
            } else {
                chcredits_entrypoint_0(0);
            }
            return;
        case 0x19D:
            if (func_800DA9E4(0x650, 0)) {
                func_8080038C_chcredits();
            } else {
                chcredits_entrypoint_0(1);
            }
            return;
        }
        return;
    case 6:
        if (*(f32 *)&param_0->actorData[7] <= 0) {
            func_80800710_chcredits(param_0, 8);
            return;
        }
        *(f32 *)&param_0->actorData[7] = *(f32 *)&param_0->actorData[7] - local_0;
        break;
    case 8:
        break;
    }
}

void func_80800BCC_chcredits(s32 arg0)
{
}

void func_80800BD4_chcredits(param_0) Actor *param_0;
{
    s32 local_0;

    ((u8 *)param_0)[0x7A] &= ~0xC0;
    func_800EFA4C(param_0->position, 0.0f, 0.0f, 0.0f);
    local_0 = func_800EA05C();
    if (local_0 == 0x19C || local_0 == 0x19D) {
        if (func_800DA9E4(0x650, 0)) func_80800710_chcredits(param_0, 6);
        else func_80800710_chcredits(param_0, 7);
        func_808003E8_chcredits(param_0, 0);
        return;
    }
    func_808002A4_chcredits(param_0);
}

void func_80800C84_chcredits(Actor *param_0, void *param_1)
{
    f32 local_0;
    s32 local_1;
    local_0 = 0.0f;
    local_1 = _glglobalsettings_entrypoint_3();
    func_800E41CC();
    func_800E3C8C(50.0f, 2000.0f);
    func_800E39D8(D_80801578_chcredits[local_1], D_80801560_chcredits[local_1]);
    func_800E3CE8();
    func_800E44FC(param_1);
    func_800E7C28(param_1);
    func_800E7CF4(param_1);
    switch (param_0->unk70_10) {
    case 2:
        local_0 = func_800F10B4(((f32 *)param_0->actorData)[7], 1.0f, 0.0f, 1.0f, 0.0f);
        D_8080155C_chcredits = local_0 * 360.0f;
        break;
    case 6:
        local_0 = func_800F10B4(((f32 *)param_0->actorData)[7], 1.0f, 0.0f, 0.0f, 1.0f);
        D_8080155C_chcredits = local_0 * 360.0f;
        break;
    case 7:
    case 8: local_0 = 1.0f; break;
    }
    if (local_0 > 0.0f) {
        func_800DF830(1);
        func_800DE498(param_1, D_80801548_chcredits, D_80801554_chcredits, local_0, 0, (void *)func_800D674C(0x9A1));
    }
    func_80101870(param_0, param_1);
    func_800E4208();
    func_800E44FC(param_1);
}

void func_80800E4C_chcredits(param_0, param_1, param_2, param_3) void *param_0; s32 param_1; void *param_2; s32 param_3;
{
    f32 local_1;
    s32 local_0;
    s32 local_3;
    f32 local_2 = 2.0f;

    local_1 = _glglobalsettings_entrypoint_3() ? 0.95f : 1.0f;
    local_0 = (304.0f - func_800B8CFC(param_0) * local_1) / local_2;
    func_800B8C8C(param_3);
    func_800B8CBC(0, 0, 0);
    func_800B8CF0(local_1);
    func_800B80D0(param_2);
    local_3 = param_1 + 1;
    func_800B8E28(param_2, local_0 + 1, local_3, param_0);
    func_800B8CBC(255, 255, 255);
    func_800B8CF0(local_1);
    func_800B80D0(param_2);
    func_800B8E28(param_2, local_0, local_3, param_0);
}

void func_80800F50_chcredits(u8 *param_0, u8 *param_1)
{
    u8 *s2;
    s32 yA;
    s32 s5;
    s32 k;

    s2 = func_80100094(param_0, 0);
    func_800B8C50();
    func_800B7F14(param_1);
    func_800B8CB0(1);
    if (D_8012760D[4] == 2) {
        yA = 0xA0;
        s5 = 0xAF;
        if (func_800E7188(s2 + 0x80)) {
            yA = 0x91;
        }
    } else {
        yA = 0x55;
        s5 = 0x78;
    }
    if (func_800E7188(s2)) {
        if (func_800E7188((s2 + 0x80))) {
            func_80800E4C_chcredits(s2, (s32)((f32)yA - 7.5f), param_1, *(s32 *)(param_0 + 0x6C) & 0x1FF);
            func_80800E4C_chcredits((s2 + 0x80), (s32)((f32)yA + 7.5f), param_1, *(s32 *)(param_0 + 0x6C) & 0x1FF);
        } else {
            func_80800E4C_chcredits(s2, yA, param_1, *(s32 *)(param_0 + 0x6C) & 0x1FF);
        }
    }
    for (k = 0; k != 3; k++) {
        if (func_800E7188(s2 + 0x100 + k * 0x80)) {
            func_80800E4C_chcredits(s2 + 0x100 + k * 0x80, k * 15 + s5, param_1, *(s32 *)(param_0 + 0x6C) & 0x1FF);
        }
    }
    func_800B811C(param_1);
}

void func_80801108_chcredits(param_0, param_1) Actor *param_0; s32 param_1;
{
    s32 local_0;
    if (!param_0->unk64_19) {
        local_0 = 0xFF - param_0->unk6C_0;
        if (local_0 >= 0xF6) local_0 = 0xFF;
        else if (local_0 < 10) local_0 = 0;
        func_800B99CC(param_1, local_0, D_80801590_chcredits);
    }
    func_80800F50_chcredits(param_0, param_1);
    func_80800C84_chcredits(param_0, param_1);
}

int *chcredits_entrypoint_2()
{
    return (int *)D_8080159C_chcredits;
}

extern void func_80105834(), func_80107C2C(), func_80800BCC_chcredits(), func_80800BD4_chcredits(), func_80801108_chcredits();

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/credits.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * Labels inside an object are linker symbols in undefined_syms.us.txt: D_80801202_chcredits = D_80801200_chcredits + 0x2, D_808012BA_chcredits = D_80801204_chcredits + 0xB6, D_808012BD_chcredits = D_808012BC_chcredits + 0x1, D_808012BE_chcredits = D_808012BC_chcredits + 0x2, D_80801208_chcredits = D_80801204_chcredits + 0x4, D_808012C0_chcredits = D_808012BC_chcredits + 0x4, D_8080155C_chcredits = D_80801554_chcredits + 0x8 */
u32 D_80801200_chcredits[1] = { 0xAF001F };
CreditsLines D_80801204_chcredits[23] = { 0x5, 0x0, 0x0, 0x0, 0x1, 0x42, 0x0, 0x55, 0x0, 0x0, 0x0, 0x0, 0x1, 0x4F, 0x0, 0x18, 0x0, 0x0, 0x0, 0x0, 0x1, 0x55, 0x0, 0x2A, 0x0, 0x0, 0x0, 0x0, 0x1, 0x5A, 0x0, 0x12, 0x0, 0x0, 0x0, 0x0, 0x1, 0x5C, 0x0, 0x17, 0x0, 0x0, 0x0, 0x0, 0x0, -0x48, 0x0, 0x29, 0x1, 0x0, 0x0, 0x0, 0x0, -0x39, 0x0, 0xC, 0x1, 0x0, 0x0, 0x0, 0x0, -0x2A, 0x0, 0x4A, 0x1, 0x0, 0x0, 0x0, 0x1, -0x59, 0x0, 0x41, 0x1, 0x0, 0x0, 0x0, 0x1, 0x12, 0x0, 0x5A, 0x1, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x1A, 0x2, 0x0, 0x0, 0x0, 0x1, 0x27, 0x0, 0x2E, 0x2, 0x0, 0x0, 0x0, 0x1, 0x36, 0x0, 0x63, 0x2, 0x0, 0x0, 0x0, 0x0, -0x48, 0x0, 0x2A, 0x3, 0x0, 0x0, 0x0, 0x0, -0x39, 0x0, 0xE, 0x3, 0x0, 0x0, 0x0, 0x0, -0x1A, 0x0, 0x10, 0x3, 0x0, 0x0, 0x0, 0x1, -0x58, 0x0, 0x41, 0x3, 0x0, 0x0, 0x0, 0x1, 0x12, 0x0, 0x5B, 0x4, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x1B, 0x4, 0x0, 0x0, 0x0, 0x1, 0x28, 0x0, 0x4C, 0x4, 0x0, 0x0, 0x0, 0x1, 0x36, 0x0, 0x6D, 0x5, 0x0, 0x0, 0x0, 0x1, 0x5D, 0x0, 0x53, 0x6, 0x0, 0x0, 0x0, 0x0, -0x48, 0x0, 0x28 };
CreditsLines D_808012BC_chcredits[81] = { 0x0, 0x0, 0x1, 0x0, 0x0, -0x48, 0x0, 0x23, -0x1, 0x0, 0x0, 0x0, 0x0, -0x3C, 0x0, 0x9, -0x1, 0x0, 0x2, 0x0, 0x0, -0x48, 0x0, 0x30, -0x1, 0x0, 0x3, 0x0, 0x0, -0x3B, 0x0, 0x0, -0x1, 0x0, 0x4, 0x0, 0x1, 0x7A, 0x0, 0x28, -0x1, 0x0, 0x5, 0x0, 0x0, -0x28, 0x0, 0x6, -0x1, 0x1, 0x0, 0x0, 0x0, -0x28, 0x0, 0xC, -0x1, 0x1, 0x1, 0x0, 0x0, -0x39, 0x0, 0x1A, -0x1, 0x1, 0x2, 0x0, 0x0, -0x2F, 0x0, 0x25, -0x1, 0x1, 0x3, 0x0, 0x0, -0x7, 0x0, 0x37, -0x1, 0x2, 0x1, 0x0, 0x0, -0x2A, 0x0, 0x4E, -0x1, 0x2, 0x0, 0x0, 0x0, -0x2A, 0x0, 0x4F, -0x1, 0x2, 0x2, 0x0, 0x0, -0x2A, 0x0, 0x4C, -0x1, 0x2, 0x3, 0x0, 0x0, -0x7, 0x0, 0x36, -0x1, 0x2, 0x4, 0x0, 0x0, -0x13, 0x0, 0xE, -0x1, 0x3, 0x0, 0x0, 0x0, -0x13, 0x0, 0xF, -0x1, 0x3, 0x1, 0x0, 0x0, -0x12, 0x0, 0xC, -0x1, 0x3, 0x4, 0x0, 0x1, -0x59, 0x0, 0x2B, -0x1, 0x3, 0x7, 0x0, 0x1, -0x59, 0x0, 0x43, -0x1, 0x3, 0x2, 0x0, 0x0, -0x13, 0x0, 0x10, -0x1, 0x3, 0x6, 0x0, 0x1, -0x59, 0x0, 0x44, -0x1, 0x3, 0x3, 0x0, 0x0, -0x1, 0x0, 0x6, -0x1, 0x3, 0x5, 0x0, 0x0, -0xF, 0x0, 0x12, -0x1, 0x3, 0x8, 0x0, 0x0, -0xF, 0x0, 0x13, -0x1, 0x3, 0x9, 0x0, 0x0, -0xF, 0x0, 0x14, -0x1, 0x3, 0xA, 0x0, 0x0, -0x6, 0x0, 0xA, -0x1, 0x3, 0xB, 0x0, 0x0, -0x4, 0x0, 0x37, -0x1, 0x3, 0xC, 0x0, 0x1, 0x12, 0x0, 0x61, -0x1, 0x4, 0x0, 0x0, 0x1, 0x14, 0x0, 0x13, -0x1, 0x4, 0x1, 0x0, 0x1, 0x12, 0x0, 0x62, -0x1, 0x4, 0x2, 0x0, 0x1, 0x15, 0x0, 0x1E, -0x1, 0x4, 0x3, 0x0, 0x1, 0x18, 0x0, 0x20, -0x1, 0x4, 0x7, 0x0, 0x1, 0x18, 0x0, 0x21, -0x1, 0x4, 0x8, 0x0, 0x1, 0x18, 0x0, 0x22, -0x1, 0x4, 0x9, 0x0, 0x1, 0x18, 0x0, 0x23, -0x1, 0x4, 0xA, 0x0, 0x1, 0x1A, 0x0, 0x14, -0x1, 0x4, 0x4, 0x0, 0x1, 0x16, 0x0, 0x3C, -0x1, 0x4, 0x5, 0x0, 0x1, 0x13, 0x0, 0x3E, -0x1, 0x4, 0x6, 0x0, 0x1, 0x3, 0x0, 0x9, -0x1, 0x5, 0x0, 0x0, 0x1, 0x3, 0x0, 0xA, -0x1, 0x5, 0x1, 0x0, 0x1, 0x10, 0x0, 0x4A, -0x1, 0x5, 0x2, 0x0, 0x1, 0x31, 0x0, 0x4, -0x1, 0x6, 0x1, 0x0, 0x1, 0x31, 0x0, 0x8, -0x1, 0x6, 0x2, 0x0, 0x1, 0x31, 0x0, 0x5, -0x1, 0x6, 0x3, 0x0, 0x1, 0x31, 0x0, 0x7, -0x1, 0x6, 0x4, 0x0, 0x1, 0x31, 0x0, 0x6, -0x1, 0x6, 0x5, 0x0, 0x1, 0x28, 0x0, -0x7A, -0x1, 0x6, 0x9, 0x0, 0x1, 0x28, 0x0, 0x7C, -0x1, 0x6, 0x6, 0x0, 0x1, 0x28, 0x0, -0x79, -0x1, 0x6, 0x7, 0x0, 0x1, 0x28, 0x0, -0x78, -0x1, 0x6, 0x8, 0x0, 0x1, 0x29, 0x0, 0x1C, -0x1, 0x6, 0x0, 0x0, 0x1, 0x28, 0x0, -0x7B, -0x1, 0x6, 0xA, 0x0, 0x1, 0x28, 0x0, -0x7C, -0x1, 0x6, 0xB, 0x0, 0x1, 0x2B, 0x0, 0x31, -0x1, 0x6, 0xC, 0x0, 0x1, 0x2C, 0x0, 0x31, -0x1, 0x6, 0xD, 0x0, 0x1, 0x36, 0x0, 0x70, -0x1, 0x7, 0x0, 0x0, 0x1, 0x3A, 0x0, 0x9, -0x1, 0x7, 0x1, 0x0, 0x1, 0x37, 0x0, 0xF, -0x1, 0x7, 0x2, 0x0, 0x1, 0x36, 0x0, 0x72, -0x1, 0x7, 0x3, 0x0, 0x1, 0x3F, 0x0, 0x19, -0x1, 0x7, 0x4, 0x0, 0x1, 0x51, 0x0, 0x16, -0x1, 0x8, 0x5, 0x0, 0x1, 0x4F, 0x0, 0x19, -0x1, 0x8, 0x6, 0x0, 0x1, 0x50, 0x0, 0x9, -0x1, 0x8, 0x7, 0x0, 0x1, 0x53, 0x0, 0x5, -0x1, 0x8, 0x8, 0x0, 0x0, -0x53, 0x0, 0x8, -0x1, 0x8, 0x9, 0x0, 0x1, 0x60, 0x0, 0x6, -0x1, 0x8, 0x14, 0x0, 0x1, 0x55, 0x0, 0x2B, -0x1, 0x8, 0xA, 0x0, 0x1, 0x43, 0x0, 0x8, -0x1, 0x8, 0xB, 0x0, 0x1, 0x43, 0x0, 0x9, -0x1, 0x8, 0xC, 0x0, 0x1, 0x43, 0x0, 0xA, -0x1, 0x8, 0xD, 0x0, 0x1, 0x69, 0x0, 0x0, -0x1, 0x8, 0xE, 0x0, 0x1, 0x5E, 0x0, 0x1C, -0x1, 0x8, 0x4, 0x0, 0x1, 0x44, 0x0, 0x15, -0x1, 0x8, 0x2, 0x0, 0x1, 0x44, 0x0, 0x16, -0x1, 0x8, 0x3, 0x0, 0x0, -0x4A, 0x0, 0x10, -0x1, 0x8, 0x1, 0x0, 0x1, 0x6A, 0x0, 0x0, -0x1, 0x8, 0xF, 0x0, 0x1, 0x6A, 0x0, 0x1, -0x1, 0x8, 0x10, 0x0, 0x1, 0x6A, 0x0, 0x2, -0x1, 0x8, 0x11, 0x0, 0x0, -0x49, 0x0, 0x1, -0x1, 0x8, 0x0, 0x0, 0x1, 0x67, 0x0, 0x0, 0x1, 0x8, 0x12, 0x0, 0x1, 0x68, 0x0, 0x0 };
static u32 D_808012BC_chcredits_rest[1] = { 0xFF081300 };
f32 D_80801548_chcredits[3] = { 0.0f, 562.5f, -1125.0f };
f32 D_80801554_chcredits[3] = { 0.0f, 0.0f, 0.0f };
f32 D_80801560_chcredits[2][3] = { 357.9f, 0.16f, 0.0f, 0.15f, 0.16f, 0.0f };
f32 D_80801578_chcredits[2][3] = { -9.29f, 635.68f, 224.39f, -3.29f, 568.34f, -99.52f };
u8 D_80801590_chcredits[12] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
void *D_8080159C_chcredits[21] = { (void *)0x01580174, (void *)0x09A00001, 0, (void *)func_80800800_chcredits, (void *)func_80105834, (void *)func_80801108_chcredits, 0, 0, 0, (void *)0x00400404, (void *)func_80800BCC_chcredits, 0, (void *)0x02800000, (void *)func_80800BD4_chcredits, (void *)func_80107C2C, (void *)0x80000002, 0, 0, 0, 0, 0 };
