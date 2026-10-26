#include "common.h"

#define AF(p, i) (*(f32 *)&(p)->actorData[i])
extern s32 D_80800D3C_chgoldfish;
extern void _gcdialogcamera_entrypoint_3(void *, f32);
extern u8 D_80800D4C_chgoldfish[];
extern f32 func_800BED50(void);
extern s32 _fxsplash_entrypoint_2(f32 *, f32);
extern s32 _fxairbub_entrypoint_1(f32 *, f32, f32, f32);
extern void func_800BA930(s32, s32, s32, s32, s32, s32, s32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern f32 func_80013970(f32);
extern f32 func_800F1FF0(f32, f32, f32, f32, f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern int D_80800D94_chgoldfish;
typedef struct { u8 pad_0[0x72]; u16 st : 6; u16 rest : 10; } GoldfishState;
typedef struct { u32 top : 7; u32 rest : 25; } GoldfishTop;
extern u8 D_80800D20_chgoldfish[];
extern f32 func_800F1214(f32, f32, f32);
extern f32 func_800DC178(f32, f32);
extern void func_800CD08C(s32, u32 *);
extern f32 func_80090010(void);
extern f32 func_80103EF4(Actor *);
extern f32 func_8010CD28(Actor *);
extern void func_800EFCD8(f32 *, f32, f32);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF04C();
extern void *func_800BEF00(f32 *, f32 *, f32 *, s32);
s32 func_80800BA8_chgoldfish();
void func_808005F0_chgoldfish();
extern void func_80101870(), func_80105834(), func_80107C2C(), func_80108ED0(), func_80800000_chgoldfish();
extern u8 D_80800CC0_chgoldfish[];

void func_80800000_chgoldfish(param_0) ALCSPlayer *param_0; {
    if (func_800DA298(0x1BF) != 0) {
        func_800FFA88(*(void **)((char *)param_0 + 0x0));
        return;
    }
    if (func_800DA298(0x1DA) != 0) {
        func_808005F0_chgoldfish(param_0, 6);
    } else if (func_800DA298(0x51E) != 0) {
        func_808005F0_chgoldfish(param_0, 3);
    }
    *(f32 *)((char *)param_0 + 0x24) = *(f32 *)((char *)param_0 + 0x38);
    *(f32 *)((char *)param_0 + 0x4C) = 90.0f;
    func_80800BA8_chgoldfish(param_0, (char *)param_0 + 4);
}




































f32 func_80800AB4_chgoldfish(Actor *param_0, f32 *param_1, f32 *param_2, f32 *param_3, f32 param_4, f32 param_5);

void func_80800964_chgoldfish();

void func_80800924_chgoldfish();

void func_8080009C_chgoldfish(Actor *param_0)
{
    f32 local_0[1];
    f32 local_2;
    f32 local_1;

    switch (((GoldfishState *)param_0)->st) {
    case 2:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        func_8010C964(param_0);
        if (1) {}
        break;
    }
    switch (((GoldfishState *)param_0)->st) {
    case 1:
        if (func_800DA298(0x51E)) {
            func_808005F0_chgoldfish(param_0, 2);
            return;
        }
        _subaddiedialog_entrypoint_7(param_0, param_0->position, D_80800D20_chgoldfish);
        return;
    case 2:
        if (!func_800DA298(0x1DA)) {
            func_800DA544(0x1DA);
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x15BF, 0xE, param_0->position, 0x67);
        }
        return;
    case 3:
        if (func_800D90A4(&param_0->unk58)) {
            param_0->unk54 = func_800DC178(0.0f, 360.0f);
            param_0->unk50 = param_0->rotation[2] == 90.0f ? 270.0f : 90.0f;
            func_800EE7F8((f32 *)&param_0->actorData[4], param_0->position);
            func_800CD08C((*(u32 *)((u8 *)param_0 + 0x70) >> 25) - 1, param_0->actorData);
            if (func_80800BA8_chgoldfish(param_0, param_0->actorData)) {
                func_808005F0_chgoldfish(param_0, 4);
                return;
            }
        }
        break;
    case 4:
        if (func_80800AB4_chgoldfish(param_0, &param_0->actorData[4], param_0->actorData, param_0->position, 0.5f, 50.0f) == 1.0f) {
            func_808005F0_chgoldfish(param_0, 3);
        }
        return;
    case 5:
        func_8008FE94(1, param_0->actorData);
        local_0[0] = func_80800AB4_chgoldfish(param_0, &param_0->actorData[4], param_0->actorData, param_0->position, 1.0f, 150.0f);
        if (1.0f - local_0[0] == 0.0f) {
            func_80090708(0);
            func_808005F0_chgoldfish(param_0, 6);
        }
        param_0->scale = AF(param_0, 3) * (1.0f - local_0[0] * 0.5f);
        func_80800924_chgoldfish(param_0);
        return;
    case 6:
        func_8008FE68(param_0->position);
        param_0->position[1] += 200.0f;
        if (func_800D90A4(&param_0->unk58)) {
            param_0->unk58 = 40.0f;
            _subaddiedialog_entrypoint_11(param_0->unk0, func_800DC128(0x15C2, 0x15C5), 0xE, param_0->position, 0x67);
        }
        if (func_800F71D4(func_800F54E4())) {
            func_808005F0_chgoldfish(param_0, 7);
            return;
        }
        break;
    case 7:
        local_1 = param_0->position[1];
        local_2 = func_80800AB4_chgoldfish(param_0, &param_0->actorData[4], param_0->actorData, param_0->position, 1.0f, 200.0f);
        param_0->rotation[0] = func_80013970(func_800F1214(local_2, 270.0f, 540.0f)) * 70.0f;
        if (func_800D90A4(&param_0->unk58)) {
            func_808005F0_chgoldfish(param_0, 8);
        }
        if (param_0->position[1] <= AF(param_0, 7)) {
            if (AF(param_0, 7) < local_1) {
                func_80800964_chgoldfish(param_0->position);
            }
        }
        param_0->scale = AF(param_0, 3) * local_2;
        break;
    case 8:
        if (func_8010CE70(param_0, 6, -1)) {
            func_808005F0_chgoldfish(param_0, 9);
        }
        break;
    case 9:
    case 10:
        break;
    }
}

s32 func_808004AC_chgoldfish(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    switch (param_1) {
        case 0x2E:
            switch (*(s16 *)&param_2) {
                case 0x15BF:
                    func_808005F0_chgoldfish(param_0, 3);
                    break;
                case 0x15C0:
                    func_800C7074(0x30, !func_800DA298(0x648));
                    func_808005F0_chgoldfish(param_0, 10);
                    break;
            }
            return 1;
        case 0x2F:
            if (*(s16 *)&param_2 == 0x15C0 && ((s16 *)&param_2)[1] == 1 && func_800DA298(0x649)) func_800CF700();
            return 1;
        case 0x52:
            _gcdialogcamera_entrypoint_3(&D_80800D3C_chgoldfish, param_0->scale);
            return 1;
        case 0x3E:
            if ((param_0->unk70_10 == 3 || param_0->unk70_10 == 4) && func_800F64A4(func_800F54E4(), 1)) func_808005F0_chgoldfish(param_0, 5);
            return 1;
        default:
            return 0;
    }
}

void func_808005F0_chgoldfish(param_0, param_1) Actor *param_0; s32 param_1;
{
    Vec3f local_0;
    Vec3f local_1;
    s32 local_2;
    u8 *local_7;

    switch (param_1) {
    case 3:
        param_0->unk58 = 1.0f;
        func_80102424(param_0, 3);
        return;
    case 4:
        param_0->unk58 = 0.5f;
        func_80102424(param_0, 4);
        return;
    case 5:
        func_800FC6B0(0xE);
        func_8008FE94(1, param_0->actorData);
        func_800EE7F8((f32 *)&param_0->actorData[4], param_0->position);
        param_0->unk58 = 1.0f;
        param_0->unk54 = func_80090010();
        param_0->unk50 = 0;
        func_80090708(1);
        func_80102424(param_0, 5);
        return;
    case 6:
        param_0->unk64_16 = 0;
        param_0->unk58 = 40.0f;
        func_80102424(param_0, 6);
        return;
    case 7:
        param_0->unk58 = 1.0f;
        func_8008FE94(1, ((f32 *)&param_0->actorData[4]));
        param_0->unk54 = func_80090010();
        for (local_2 = 0; local_2 != 4; local_2++) {
            func_800EFCD8(((f32 *)param_0->actorData), param_0->unk54, 300.0f);
            func_800EF04C(((f32 *)param_0->actorData), ((f32 *)&param_0->actorData[4]));
            func_800EE7F8(local_0.f, ((f32 *)param_0->actorData));
            local_0.pos.y = ((f32 *)param_0->actorData)[5] + 500.0f;
            param_0->rotation[2] = 0.0f;
            param_0->unk50 = 0.0f;
            ((f32 *)param_0->actorData)[1] = ((f32 *)param_0->actorData)[5] - 500.0f;
            local_7 = func_800BEF00(local_0.f, ((f32 *)param_0->actorData), local_1.f, 0);
            if (local_7) {
                if (func_800C84B0(*(s32 *)(local_7 + 8)) == 4) {
                    ((f32 *)param_0->actorData)[7] = ((f32 *)param_0->actorData)[1];
                    func_800EE7F8(local_0.f, ((f32 *)param_0->actorData));
                    ((f32 *)param_0->actorData)[1] -= 3.0f * func_80103EF4(param_0);
                    if (func_800BEF00(local_0.f, ((f32 *)param_0->actorData), local_1.f, 0) == NULL) {
                        param_0->unk64_16 = 1;
                        func_80102424(param_0, 7);
                        return;
                    }
                }
                param_0->unk54 += 90.0f;
            }
        }
        return;
    case 8:
        func_800FC6B0(0xE);
        param_0->unk54 = func_8010CD28(param_0);
        func_800F8300(func_800F54E4(), 1, param_0->position);
        func_80102424(param_0, 8);
        return;
    case 9:
        _subaddiedialog_entrypoint_11(param_0->unk0, 0x15C0, 0x4E, param_0->position, 0x67);
        func_80102424(param_0, 9);
        return;
    case 10:
        func_800F82D4(func_800F54E4(), 0);
        _subaddiefade_entrypoint_3(param_0);
        func_80102424(param_0, 10);
        return;
    default:
        func_80102424(param_0, param_1);
        return;
    }
}

void func_80800924_chgoldfish(u8 *param_0)
{
    func_800BBCB8(param_0 + 4, 0, *(s32 *)(param_0 + 0x38), 1, &D_80800D4C_chgoldfish);
}

void func_80800964_chgoldfish(f32 *param_0)
{
    f32 local_0[3];
    f32 local_1;
    s32 local_2;
    local_1 = func_800BED50();
    local_0[0] = param_0[0];
    local_0[1] = local_1;
    local_0[2] = param_0[2];
    func_800C4140(0x7FFB5C09, param_0, 0x4B000FA);
    local_2 = _fxsplash_entrypoint_2(local_0, 35.0f); _fxripple_entrypoint_0(3, local_0);
    func_800BA930(local_2, -350, 300, -350, 350, 500, 350); func_800BA22C(local_2, 10);
    func_800BA930(local_2, -150, 500, -150, 150, 800, 150); func_800BA22C(local_2, 10);
    _fxsplash25d_entrypoint_0(local_0); local_0[1] -= 30.0f;
    local_2 = _fxairbub_entrypoint_1(local_0, 20.0f, local_1, 1.0f);
    func_800BA930(local_2, -60, -250, -60, 60, -150, 60); func_800BA22C(local_2, 8);
}

f32 func_80800AB4_chgoldfish(Actor *param_0, f32 *param_1, f32 *param_2, f32 *param_3, f32 param_4, f32 param_5)
{
    f32 local_0;

    func_800D90A4(&param_0->unk58);
    local_0 = func_800F10B4(param_0->unk58, param_4, 0.0f, 0.0f, 1.0f);
    func_800EFE50(param_3, param_1, param_2, local_0);
    param_3[1] += func_80013970(local_0 * 180.0f) * param_5;
    param_0->rotation[1] = func_800F1FF0(param_0->rotation[1], param_0->unk54, 0.5f, 0.1f, 10.0f);
    param_0->rotation[2] = func_800F1FF0(param_0->rotation[2], param_0->unk50, 0.5f, 0.1f, 10.0f);
    return local_0;
}

s32 func_80800BA8_chgoldfish(param_0, param_1) Actor *param_0; f32 *param_1;
{
    f32 local_0[3];
    f32 local_1[3];
    func_800EFA4C(local_0, param_1[0], param_1[1] + 300.0f, param_1[2]);
    param_1[1] -= 300.0f;
    if (func_800BEF00(local_0, param_1, local_1, 0)) {
        param_1[1] += 20.0f;
        return 1;
    }
    return 0;
}

int chgoldfish_entrypoint_0()
{
    return (int)&D_80800D94_chgoldfish;
}
