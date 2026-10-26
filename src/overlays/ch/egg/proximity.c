#include "common.h"

extern int D_80800CE0_cheggproximity;
extern Actor *_suegg_entrypoint_11(s32, void *, s32);
extern f32 func_80013B7C(f32, f32);
extern void _sueggmove_entrypoint_5(Actor *, s32);
extern void _sueggmove_entrypoint_6(Actor *, f32, f32);
extern void _suegg_entrypoint_1(Actor *, f32);
typedef struct { u8 pad_0[0x38]; u32 pad_1 : 8; u32 local_0 : 1; u32 pad_2 : 23; } EggProximityState;
typedef struct { u8 pad_0[0xA4]; s32 local_0; } EggProximityExplosion;
extern void *func_80100094(Actor *, s32);
typedef struct { u8 unused[0x78]; u16 unusedMode : 14; u16 mode : 2; } ProximityRenderMode;
extern u8 func_800D9078();
typedef struct { u8 pad_0[0x40]; s32 local_0[8]; s32 local_1[8]; f32 local_2[8]; u8 pad_1[4]; s32 local_3; } EggPlayerTimers1559;
extern int func_800F5898(void);
extern void *func_800F53D0(s32);
extern void _bamotor_entrypoint_0(void *, f32, f32);
typedef struct { u8 pad[0x40]; s32 states[24]; s32 player; s32 pad_A4; s32 dialog; } ProximityEggState;
extern f32 func_800D8FF8(void);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void _fxegg_entrypoint_5(f32 *, f32 *, f32);
typedef struct { u8 pad_0[0x38]; u32 pad_1 : 8; u32 local_0 : 1; u32 local_1 : 1; u32 pad_2 : 22; } ProximityFlags1834;
extern void _cheggproximity_entrypoint_2(void);
extern void _suegg_entrypoint_23();
extern void func_80101FDC();
extern s32 D_80800D28_cheggproximity;
typedef struct { u8 pad_0[0x40]; s32 local_0[8]; s32 local_1[8]; u8 pad_1[0x28]; s32 local_2; } ProximityEggPayload921;
extern s32 func_800F6438(s32);
extern s32 func_800F6CC8(s32);
extern void func_800F5A00(s32, f32 *);
extern f32 func_800EFC7C(f32 *, f32 *);
typedef struct { f32 dy[8]; f32 dist[8]; s32 state[8]; s32 prev[8]; u8 pad80[0x20]; s32 best; s32 flag; } EggProx;
typedef struct { u8 pad[0x3A]; s16 h3A; } EggProxLocal;
void func_80800AFC_cheggproximity();
s32 func_80800BF4_cheggproximity();
void func_808001CC_cheggproximity();
int func_8080048C_cheggproximity();
void func_80800718_cheggproximity();
void func_80800874_cheggproximity();

int *cheggproximity_entrypoint_0()
{
    return &D_80800CE0_cheggproximity;
}

Actor *cheggproximity_entrypoint_1(s32 param_0, void *param_1, f32 *param_2, s32 param_3)
{
    Actor *local_0;
    _sueggmove_entrypoint_10(param_0, param_1);
    local_0 = _suegg_entrypoint_11(0x160, param_1, param_3);
    local_0->scale = 0.25f;
    local_0->rotation[1] = func_80013B7C(param_2[0], param_2[2]);
    _sueggmove_entrypoint_5(local_0, 0);
    _sueggmove_entrypoint_6(local_0, 0.0f, -22000.0f);
    _sueggmove_entrypoint_7(local_0, param_2);
    _suegg_entrypoint_1(local_0, 30.0f);
    return local_0;
}

s32 func_808000A8_cheggproximity(Actor *param_0, s32 param_1, s32 param_2)
{
    EggProximityState *local_0;
    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
    case 0x4F: func_800FFAB0(param_0); return 1;
    case 0x45:
    case 0x78:
        ((EggProximityExplosion *)func_80100094(param_0, 1))->local_0 = 1;
        break;
    case 0x40:
        func_80800718_cheggproximity(param_0, 6);
        local_0->local_0 = 1;
        break;
    default: return 0;
    }
    return 1;
}

void func_80800164_cheggproximity(Actor *param_0)
{
    u32 local_0 = ((ProximityRenderMode *)param_0)->mode;

    if (*(u8 *)((u8 *)param_0 + 0x9B) != 0xFF) {
        ((ProximityRenderMode *)param_0)->mode = 1;
    }
    _subaddiedraw25d_entrypoint_1(param_0);
    ((ProximityRenderMode *)param_0)->mode = local_0;
}

void func_808001CC_cheggproximity(param_0) Actor *param_0;
{
    u8 *local_2;
    f32 local_3;
    f32 local_0[3];
    f32 local_1[3];

    local_2 = func_80100094(param_0, 0);
    *(f32 *)(local_2 + 0x28) -= func_800D8FF8();
    local_3 = func_800F10B4(*(f32 *)(local_2 + 0x30), 0, 2.0f, 0.0333f, 0.1f);
    _suegg_entrypoint_20(param_0, local_1);
    while (0.0f >= *(f32 *)(local_2 + 0x28)) {
        *(f32 *)(local_2 + 0x28) += local_3;
        func_800EE7F8(local_0, param_0->position);
        _fxegg_entrypoint_5(param_0->position, local_1, param_0->scale);
    }
}

void cheggproximity_entrypoint_2(u8 *param_0) {
    s32 local_0;
    s32 local_2;
    s32 local_1;

    local_2 = func_80106790();
    local_0 = local_2;
    local_1 = (s32) (*(s16 *)((s8 *)(func_80100094(local_2, 0)) + (0x3A)));
    _cheggsplode_entrypoint_1(&local_0, local_1, _gcegg_entrypoint_0((u32) (*(u32 *)((s8 *)(param_0) + (0x24))) >> 0x16));
    _suegg_entrypoint_4(local_0, 0);
}




































void func_808006A4_cheggproximity();

void func_80800650_cheggproximity();

void func_808005EC_cheggproximity();

void func_80800588_cheggproximity();

void func_80800510_cheggproximity();

void func_80800330_cheggproximity(Actor *param_0)
{
    u8 *local_0 = func_80100094(param_0, 0);
    u8 *local_1;

    switch (param_0->unk70_10) {
        case 1:
            if (!_suegg_entrypoint_8(param_0)) func_8080048C_cheggproximity(param_0, local_0);
            break;
        case 2:
            if (!_suegg_entrypoint_8(param_0)) func_80800510_cheggproximity(param_0, local_0);
            break;
        case 3: func_80800588_cheggproximity(param_0, (Actor *)local_0); break;
        case 4: func_808005EC_cheggproximity(param_0, (Actor *)local_0); break;
        case 5: func_80800650_cheggproximity(param_0, local_0); break;
        case 6: func_808006A4_cheggproximity(param_0, local_0); break;
    }
    if (((ProximityFlags1834 *)local_0)->local_0 && !((ProximityFlags1834 *)local_0)->local_1) {
        local_1 = func_80100094(param_0, 1);
        if (*(s32 *)(local_1 + 0xA8)) func_80101180(0x2C4, 0x74, param_0->unk0);
        if (param_0->unk70_10 == 6) _chbaddiesetup_entrypoint_1(_cheggproximity_entrypoint_2, param_0->unk0);
        else func_800FFAB0(param_0);
    }
}

int func_8080048C_cheggproximity(param_0, param_1) s32 param_0; f32 param_1[3];
{
  if (func_800EEEA8(param_0 + 0x28) != 0)
  {
    func_80800718_cheggproximity(param_0, 3);
    return;
  }
  func_808001CC_cheggproximity(param_0);
  _suegg_entrypoint_16(param_0);
  if (param_1[12] > 0.19999695f)
  {
    func_80800718_cheggproximity(param_0, 2);
  }
}

void func_80800510_cheggproximity(f32 param_0[3], u8 *var_arg1)
{
  int new_var;
  if (func_800EEEA8((void *) (((char *) param_0) + 0x28)) != 0)
  {
    func_80800718_cheggproximity(param_0, 3);
    return;
  }
  func_808001CC_cheggproximity(param_0);
  new_var = !param_0;
  _suegg_entrypoint_16(param_0);
  if ((new_var && (!param_0)) && (!param_0))
  {
  }
  if (_suegg_entrypoint_14(param_0) != 0)
  {
    var_arg1[0x39] |= 0x80 & 0xFFFF;
  }
}

void func_80800588_cheggproximity(Actor *param_0, Actor *param_1)
{
    if (*(s32 *)((u8 *)func_80100094(param_0, 1) + 0xA4) == 0) {
        func_80800874_cheggproximity(param_0);
        if (!func_80800BF4_cheggproximity(param_0) &&
            func_800D9078((f32 *)((u8 *)param_1 + 0x30))) {
            func_80800718_cheggproximity(param_0, 4);
        }
    }
}

void func_808005EC_cheggproximity(Actor *param_0, Actor *param_1)
{
    if (*(s32 *)((u8 *)func_80100094(param_0, 1) + 0xA4) == 0) {
        func_80800874_cheggproximity(param_0);
        if (!func_80800BF4_cheggproximity(param_0) &&
            func_800D9078((f32 *)((u8 *)param_1 + 0x30))) {
            func_80800718_cheggproximity(param_0, 5);
        }
    }
}

void func_80800650_cheggproximity(param_0, param_1) void *param_0; u8 param_1;
{
  u8 local_0;
  void *new_var;
  char *new_var2;
  new_var = param_0;
  func_80800874_cheggproximity();
  func_80800AFC_cheggproximity(new_var);
  new_var2 = (char *) param_0;
  ;
  if (((s32) (*((u8 *) (new_var2 + 0x9B)))) < 0x79)
  {
    func_80800718_cheggproximity(new_var, 6);
    return;
  }
  *((u8 *) (((char *) new_var) + 0x9B)) = (u8) ((*((u8 *) (new_var2 + 0x9B))) - 8);
}

void func_808006A4_cheggproximity(Actor *param_0, EggProximityState *param_1)
{
    u8 *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 1);
    local_1 = *(s32 *)(local_0 + 0xA0);
    func_80800874_cheggproximity(param_0);
    func_80800AFC_cheggproximity(param_0);
    if (((s32 *)(local_0 + 0x40))[local_1] == 1) {
        param_1->local_0 = 1;
    }
}

void func_80800718_cheggproximity(param_0, param_1) Actor *param_0; s32 param_1;
{
    u8 *local_0 = func_80100094(param_0, 0);
    ProximityEggPayload921 *local_1 = func_80100094(param_0, 1);
    s32 local_2;

    func_80101FDC(param_0, param_1);
    switch (param_1) {
        case 1: local_1->local_2 = 0; break;
        case 2: _sueggmove_entrypoint_6(param_0, -3000.0f, -22000.0f); break;
        case 3:
            func_8010A590(param_0);
            local_1->local_2 = 1;
            _suegg_entrypoint_23(param_0);
            *(f32 *)(local_0 + 0x30) = 1.0f;
            func_80101180(0x2C4, 0x73, param_0->unk0);
            break;
        case 4: *(f32 *)(local_0 + 0x30) = 3.5f; break;
        case 5:
            for (local_2 = 0; local_2 < 8; local_2++) {
                local_1->local_1[local_2] = -1;
                local_1->local_0[local_2] = -1;
            }
            func_8010D930(4, *(u32 *)((u8 *)param_0 + 0x70) & 1, param_0->position, &D_80800D28_cheggproximity);
            break;
        case 6: break;
    }
}

void func_80800874_cheggproximity(param_0) Actor *param_0;
{
    EggProxLocal *local;
    EggProx *d;
    s32 best;
    s32 i;
    s32 state;
    f32 vec[3];
    f32 dist;
    f32 dy;

    local = func_80100094(param_0, 0);
    d = func_80100094(param_0, 1);
    best = -1;
    for (i = 0; i < func_800F5898(); i++) {
        state = -1;
        if ((param_0->unk70_10 != 3 || i != local->h3A) && d->flag == 0) {
            if (func_800F6438(i) && !func_800F6CC8(i)) {
                func_800F5A00(i, vec);
                dist = func_800EFC7C(vec, param_0->position);
                dy = vec[1] - param_0->position[1];
                d->dist[i] = dist;
                d->dy[i] = dy;
                if (!(160000.0f < dist)) {
                    if (90000.0f < dist) {
                        state = 0;
                    } else {
                        state = (3600.0f < dist) ? 1 : 2;
                    }
                }
                switch (state) {
                case 2:
                    if (-dy < 175.0f && dy < 100.0f) {
                        break;
                    }
                    state = 1;
                case 1:
                    if (-dy < 300.0f && dy < 300.0f) {
                        break;
                    }
                    state = 0;
                case 0:
                    if (-dy < 400.0f && dy < 400.0f) {
                        break;
                    }
                    state = -1;
                    break;
                }
                if (state != -1) {
                    if (best < 0) {
                        best = i;
                    } else if (d->dist[i] < d->dist[best]) {
                        best = i;
                    }
                }
            }
            d->prev[i] = d->state[i];
            d->state[i] = state;
        }
    }
    d->best = best;
}

void func_80800AFC_cheggproximity(param_0) Actor *param_0;
{
    EggPlayerTimers1559 *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 1);
    if (local_0->local_3 == 0) {
        for (local_1 = 0; local_1 < func_800F5898(); local_1++) {
            if (local_0->local_0[local_1] != -1) {
                if (local_0->local_1[local_1] == -1) {
                    local_0->local_2[local_1] = 1.0f;
                    _bamotor_entrypoint_0(func_800F53D0(local_1), 1.0f, 0.25f);
                } else if (func_800D9078(&local_0->local_2[local_1])) {
                    local_0->local_2[local_1] = 1.0f;
                    _bamotor_entrypoint_0(func_800F53D0(local_1), 1.0f, 0.25f);
                }
            }
        }
    }
}

s32 func_80800BF4_cheggproximity(param_0) Actor *param_0;
{
    ProximityEggState *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 1);
    local_1 = local_0->player;
    if (local_1 >= 0 && local_0->states[local_1] == 2) {
        if (((ProximityEggState *)func_80100094(param_0, 1))->dialog) {
            func_80101180(0x2C4, 0x74, param_0->unk0, local_1);
        }
        func_800F7664(local_1, 0x45, 1);
        _sueggmisc_entrypoint_2(param_0->position, 6);
        func_800FFAB0(param_0);
        return 1;
    }
    return 0;
}
