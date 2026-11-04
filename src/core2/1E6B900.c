// Player model component (model, bones, tint, variants, draw) and egg ammo selection
// (per-mode egg lists, cycling, HUD display, unlimited-egg timer).
#include "core2/1E6B900.h"

// PlayerState+0x50 is the player model component (size 0x118, see func_80092010).
// QQ and PP use the parameter name param_0 directly.
#define MODEL(p) (*(LocalModel **) ((u8 *) (p) + 0x50))
#define QQ (*(S_931AC **) ((u8 *) param_0 + 0x50))
#define PP ((S93230 *) *(u32 *) ((u8 *) param_0 + 0x50))
#define LOCAL_INDEX (*(u8 **) ((u8 *) param_0 + 0x64))[1]
typedef struct ActorLocal_CC_0 ActorLocal_CC_0;
typedef struct Actor_80092018 Actor_80092018;
extern void func_80019750();
extern void func_80019CD4();
extern void func_800EE780();
extern void mlMtxGet();
extern void mlMtxRotPitch(f32);
extern f32 func_800136E4(f32);
extern f32 baroll_get();
extern f32 func_8009BFCC();
extern void func_8009C128();
typedef struct Actor_80092258 Actor_80092258;
extern s32 func_8009AD78(Actor_80092258 *param_0, int arg1);
extern s32 func_800A89F8(void);
extern f32 _bainvisible_entrypoint_2(Actor_80092258 *param_0, int arg1);
extern void func_800DF464(f32 param);
extern void func_800DF830(s32 param);
typedef struct {
    s16 field_0;
    u8 pad_2[2];
    void *field_4;
    f32 field_8;
    s16 field_C, field_E;
    u8 field_10, field_11, field_12, field_13, field_14, field_15;
    s16 field_16[3];
} LocalSub;
typedef struct {
    s32 field_0;
    u8 field_4;
    u8 pad_5[3];
    u8 field_8, field_9;
    u8 pad_A[2];
    void *field_C;
} LocalAction;
typedef struct {
    s16 field_0;
    u8 pad_2[6];
    void *field_8;
    s16 field_C;
    u8 pad_E[2];
    u8 field_10, field_11, field_12, field_13;
    u8 pad_14[3];
    u8 field_17, field_18, field_19;
    u8 pad_1A[2];
    f32 field_1C;
    u8 pad_20[12];
    f32 field_2C[3];
    u8 pad_38[12];
    f32 field_44[3];
    u8 pad_50[20];
    f32 field_64[3];
    u8 pad_70[4];
    f32 field_74;
    LocalAction field_78;
    u8 pad_88[8];
    LocalSub field_90;
    f32 field_AC[3], field_B8[3];
    u8 field_C4;
    u8 pad_C5[3];
    f32 field_C8;
} LocalModel;
extern int func_80100E18(s16);
extern void func_800ADFE0();
extern void func_800D70F8();
extern void func_800D6CEC();
extern void *func_800AE080(s16);
extern s32 func_800B26F0(void *);
extern s32 func_800A25D0(PlayerState *);
extern s32 func_80100D24();
extern s32 func_800AE020(void);
extern s32 func_800E09B8(s32);
extern void func_800AE6FC(void *, s16);
extern void func_800EE7F8();
extern void func_800EF04C(f32 *, f32 *);
extern void *func_80100AC4(s16);
extern void *func_80100A74(s16, s32);
extern void func_800DF720(void *);
extern void func_800DF818(void *);
extern void func_800DF714(void *);
extern void func_800DF72C(void *);
extern void func_800A06E8(PlayerState *);
extern void func_800DF47C(void (*)(void), PlayerState *);
extern void func_800DF440(s32);
extern void func_800DF574(s32);
extern void func_800DF3E0(void);
extern s32 func_800A946C(void);
extern void func_800A0714(PlayerState *, s32);
extern void func_800DE448(f32 *, f32 *, f32, f32 *, void *);
extern s32 func_800A4C68(PlayerState *);
extern s32 func_800E3E8C(f32 *, f32);
extern void func_800A7108(s32, s32);
extern void func_800A7130(void *, s32);
extern void func_8008CA98(PlayerState *);
extern void func_8008D058(PlayerState *);
extern void *func_8008AEDC(void *);
extern void *baanim_getAnimCtrlPtr(PlayerState *);
extern void func_8008C200();
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800DF4CC(f32 *);
extern void _babackpack_entrypoint_3(PlayerState *, f32 *, f32 *, f32, f32 *);
extern s32 func_800A3274(void);
extern void _bapreload_entrypoint_0();
typedef struct Actor_800927C4 Actor_800927C4;
extern s32 func_800F6BE4(Actor_800927C4 *);
extern Actor_800927C4 *func_800F53D0(Actor_800927C4 *);
extern void *func_80108474(s32, f32 *, s32);
extern void func_800A70D0(s32, s32);
typedef struct {
    char pad[0x78];
    s32 unk78;
    char pad2[0x8];
    s32 unk84;
} Actor_unk50;
extern void func_800EFD24(void *);
typedef struct {
    u8 pad_0[0x20];
    f32 local_0;
    f32 local_1;
    f32 local_2;
} local_0;
typedef struct {
    u8 pad_0[0x50];
    local_0 *local_0;
} local_1;
extern Unkfunc_800E0960_1 *func_800AE6BC(s32);
extern f32 func_800B2354(s32);
typedef struct ActorLocal_CC_50 {
    u8 pad[12];
    s16 unkC;
    s16 unkE;
    u8 unk12[2];
} ActorLocal_CC_50;
typedef struct Actor_8009312C {
    ActorLocal_CC_50 local;
} Actor_8009312C;
typedef struct {
    u8 pad0[0x15];
    u8 unk15;
} S_931AC;
extern f32 yaw_get(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
extern void yaw_applyIdeal(PlayerState *);
typedef struct {
    u8 pad0[0x1C];
    f32 unk1C;
    u8 pad20[0x3C];
    f32 unk5C;
    f32 unk60;
    f32 unk64;
    u8 pad68[8];
    f32 unk70;
    f32 unk74;
} S93230;
extern void func_800EF334(f32 *, f32);
extern f32 mlAbsF(f32);
extern void _chbaddiesetup_entrypoint_5();
extern s32 func_800BEC1C(void);
extern void *func_800BEC28(s32);
extern s32 _dbzone_entrypoint_4();
extern s32 _glzone_entrypoint_6();
extern void _bsfirstp_entrypoint_1(PlayerState *, s32);
extern int D_80117DDC[];
extern int D_80117DD8[];
extern u8 D_80117DF0[];
typedef struct {
    u8 pad[0x10C];
    s32 local_0;
    s32 local_1;
    s32 local_2;
} State94070;
typedef struct {
    u8 pad[0x50];
    State94070 *local_0;
} Actor94070;
typedef struct {
    f32 local_0;
    u8 pad[12];
} Entry94070;
extern Entry94070 D_80117DD0[];
extern s32 func_800D90A4(void *);
extern void func_800E3980(f32 *);
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_800E4BB8(s32);
extern s32 func_800E488C(s32);
extern s32 D_80117DD4;
extern s32 func_800C954C(void);
extern int func_800F6774(s32 param_0);
extern float func_8009E9F0(float param_0);
extern void func_80101180(int param_0, int param_1, int param_2);
extern float _batimer_get();
extern void func_800D2498(int param_0, s32 param_1, int param_2);
extern int func_800C0638(void);
extern int _batimer_decrement();
extern void _batimer_set(s32, s32, f32);
extern char D_80117E3C[];
extern char D_80117E3D[];
extern u32 D_80117E30[];
extern s32 _gcegg_entrypoint_6(s32);
typedef struct {
    u8 pad0[2];
    u8 unk2;
    u8 unk3;
} S_94644;
extern s32 func_8009E964(void);
extern f32 func_8009E970(void);
typedef struct {
    u8 pad0;
    u8 unk1;
} S0_94AB4;
typedef struct {
    u8 pad0[0x64];
    S0_94AB4 *unk64;
} S_94AB4;
s32 _gcegg_entrypoint_5(s32 param_0);
s32 func_800D1A04(s32 param_0);
void func_80092EC8();
void func_8009312C();
int func_8009332C(s32 param_0, f32 param_1);
void func_80093370();
void func_8009337C();
void func_80093504();
void func_8009359C();
void func_800936E8();
void func_80093700();
int func_80093738();
void func_80093AB8();
s32 func_80093DF4();
s32 func_80093F7C();
int func_80093FD4();
void func_80094070();
void func_800941C8(u8 *param_0, s32 param_1);
s32 func_800942D0();
void func_80094430(s32 param_0, f32 param_1);
void func_800946C4();
s32 func_80094A10();
u8 func_80094C64();
int func_80094C88();
void func_80094D04();
int func_80094DA8();
int func_80094E40();

// Player model component: model and anim slots, bones, transform/tint, variants, companion, draw.
s32 func_80092010(void)
{
    return 0x118;
}

struct ActorLocal_CC_0 {
    s32 pad[7];
    s32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    s32 pad2[5];
    f32 unk44;
};

struct Actor_80092018 {
    u8 pad[0x50];
    ActorLocal_CC_0 *local;
};

void func_80092018(Actor_80092018 *player)
{
    f32 rotation[3];
    f32 unk_0[3];
    ActorLocal_CC_0 *local_1;
    f32 yaw;
    local_1 = player->local;
    if (*(u8 *) ((char *) local_1 + 196) != 0) {
        yaw = *(f32 *) ((char *) local_1 + 200);
    } else {
        yaw = *(f32 *) ((char *) local_1 + 40);
    }
    func_800EFA4C(rotation, local_1->unk20, yaw, local_1->unk24);
    local_1 = player->local;
    func_800EE780(unk_0, &local_1->unk2C, &local_1->unk44);
    func_80019CD4();
    local_1 = player->local;
    func_80019750(&local_1->unk44, rotation, local_1->unk1C, unk_0);
    local_1 = player->local;
    if (*(u8 *) ((char *) local_1 + 196) != 0) {
        mlMtxRotPitch(local_1->unk28);
    }
    local_1 = player->local;
    mlMtxGet((f32 *) ((char *) local_1 + 0xCC));
}

int func_800920C8(long player)
{
    s32 local_0;
    local_0 = *(s32 *) (player + 0x50);
    func_80093504(player, local_0 + 0x64, local_0 + 0x50);
}

void func_800920F0(player) u8 *player;
{
    u8 mode;

    mode = (*(u8 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x50)))) + (0x15)));

switch (mode) {
    case 2:
        *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x50) + 0x28) =
            func_800136E4(yaw_get(player) + 180.0f);
        return;
    default:
        *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x50) + 0x28) = yaw_get(player);

    case 3:
        return;
}

}

void func_8009216C(u8 *player, s32 pos, s32 rotation)
{
    u8 *model;

    func_800920F0();
    (*(f32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x50)))) + (0x24))) = baroll_get(player);
    (*(f32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x50)))) + (0x20))) = func_8009BFCC(player);
    model = (*(u8 **) ((s8 *) (player) + (0x50)));
    func_800EFA4C(rotation, (*(f32 *) ((s8 *) (model) + (0x20))),
                  (*(f32 *) ((s8 *) (model) + (0x28))), (*(f32 *) ((s8 *) (model) + (0x24))));
    func_8009C128(player, pos);
}

// Writes the position of bone 1..0xA to out.
void func_800921E0(u8 *player, s32 bone, s32 out)
{
    func_8009C2A0(*((s32 *) (*((u8 **) (player + 0x50)) + 4)), bone);

if (func_800EEEA8(out) != 0) {
    func_8009C128(player, out);
}

}

void func_80092224(void *player)
{
    s32 val;
    // Matching: the temporary is needed for the match.
    ((u8 *) ((s32 *) player)[0x14])[0x1A] = (val = 1);
}

void func_80092234(u8 *player)
{
    (*(s8 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x50)))) + (0x1A))) = 1;
    (*(s8 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x50)))) + (0x16))) = 1;
}

s32 func_8009224C(s32 player)
{
    int base;
    // Matching: the copy is needed for the match.
    base = player;
    return ((u8 **) base)[20][0x1A];
}

// Returns the model alpha (0-255), including the invisibility fade.
s32 func_80092258(player)
u8 *player;
{
    u8 *model;
    u8 unk_0;
    s32 unk_1;
    f32 alpha;

    model = (*(u8 **) ((s8 *) player + 0x50));

if (*(u8 *) ((s8 *) model + 0x88) != 0) {
    alpha = (f32) (s32) *(u8 *) ((s8 *) model + 0x8C);
} else {

alpha = (f32) (s32) (*(u8 *) ((s8 *) model + 0x14));
}
if (func_8009AD78(player, 0xC) != 0) {
    unk_0 = 0;

if (func_80093DF4(player, 2) != 0) {
    unk_1 = func_800A89F8();
    if (func_800A4C68(player) == unk_1) {
        unk_0 = 1;
    }
}

alpha *= _bainvisible_entrypoint_2(player, unk_0);
}
return (u32) alpha & 0xFF;
}

s32 func_8009239C(int player)
{
    unsigned int index;
    // Matching: the index variable is needed for the match.
    index = 0;
    return ((u8 **) (player + 0x50))[index][0x19];
}

void func_800923A8(u8 *player, s32 param_1)
{
    u8 alpha;
    int alpha_result;
    u8 *model;
    u8 *model_2;

    alpha_result = func_80092258();
    alpha = alpha_result;
    func_800A2540(player, alpha_result);
    func_800DF464(2.0);
    if (param_1 != 0) {
        model = *(u8 **) (player + 0x50);

if (*(u8 *) (model + 0x16) == 0) {
    func_800DF738(*(s32 *) (model + 4));
}

}
func_800DF830(1);
model_2 = *(u8 **) (player + 0x50);
if (*(u8 *) (model_2 + 0x88) != 0) {
    func_800DF5D8(*(u8 *) (model_2 + 0x89), *(u8 *) (model_2 + 0x8A),
                  *(u8 *) (model_2 + 0x8B), alpha);
}
}

// Draws the player model.
void func_80092444(PlayerState *player, s32 param_1)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 unk_0[3];
    f32 scale;
    f32 yaw_vec[3];
    s32 local_6;
    union {
        void *model;
        LocalAction *action;
    } local_5;

if (MODEL(player)->field_90.field_12) {
    func_80093AB8(player, param_1);
    return;
}

if (func_800A89F8() != func_800A4C68(player) || MODEL(player)->field_18) {
    if (MODEL(player)->field_17) {
        local_5.action = &MODEL(player)->field_78;
        if (MODEL(player)->field_78.field_C) {
            if (local_5.action->field_4) {
                local_5.action->field_4 = 0;
                func_800A7108(local_5.action->field_C, local_5.action->field_0);
            } else if (local_5.action->field_9) {
                local_5.action->field_9 = 0;
                func_800A7130(local_5.action->field_C, local_5.action->field_8);
            }
        }
        scale = MODEL(player)->field_1C;
        func_8009216C(player, local_1, local_0);
        func_80094070(player, local_1);
        func_800EE7F8(unk_0, MODEL(player)->field_2C);
        func_800EF04C(local_1, MODEL(player)->field_44);
        func_800EF04C(unk_0, MODEL(player)->field_44);
        if (func_800E3E8C(local_1, MODEL(player)->field_1C * MODEL(player)->field_74) &&
            MODEL(player)->field_C) {
            local_5.model = func_80092B04(player, 1);
            if (!MODEL(player)->field_10) {
                func_8008CA98(player);
                func_8008C200(MODEL(player)->field_0, func_800B27E0(local_5.model),
                              func_8008AEDC(baanim_getAnimCtrlPtr(player)));
                MODEL(player)->field_13 ^= 1;
            }
            MODEL(player)->field_10 = 1;
            func_800A06E8(player);
            if (MODEL(player)->field_C4) {
                func_800EFA4C(yaw_vec, 0, local_0[1], 0);
                local_0[1] = MODEL(player)->field_C8;
                func_800DF4CC(yaw_vec);
            }
            if (MODEL(player)->field_12)
                func_800DF818(func_80100A74(MODEL(player)->field_12, 0));
            func_800DF72C(func_800AE080(MODEL(player)->field_0));
            func_800DF47C(func_80092234, player);
            func_800923A8(player, 1);
            func_800DF720(func_80100AC4(MODEL(player)->field_12));
            func_800DF440(0);
            func_800DE448(local_1, local_0, scale, unk_0, local_5.model);
            if (MODEL(player)->field_11) {
                func_800923A8(player, 0);
                _babackpack_entrypoint_3(player, local_1, local_0, scale, unk_0);
            }
        }
    }
}

}

int func_8009272C(s32 player, long value)
{
    s32 local_0;
    long value_copy;
    // Matching: the extra copies are needed for the match.
    value_copy = value;
    local_0 = player;
    *((*((u8 **) (local_0 + 0x50))) + 0x11) = value_copy;
}

s32 func_80092738(s32 player)
{
    return ((u8 *) (*(u8 **) (player + 0x50)))[0x11];
}

// Enables the colour tint (RGBA from func_80092750).
void func_80092744(void *player, s32 enabled)
{
    ((s8 *) (*(void **) ((char *) player + 0x50)))[136] = enabled;
}

void func_80092750(u8 *player, s32 red, s32 green, s32 blue, s32 alpha)
{
    *(s8 *) (*(u8 **) (player + 0x50) + 0x89) = red;
    *(s8 *) (*(u8 **) (player + 0x50) + 0x8A) = green;
    *(s8 *) (*(u8 **) (player + 0x50) + 0x8B) = blue;
    *(s8 *) (*(u8 **) (player + 0x50) + 0x8C) = alpha;
}

void func_80092778(PlayerState *player)
{
    s16 local_0;
    s16 local_1;
    _bapreload_entrypoint_0(player, func_800A3274(), &local_0, &local_1);
    func_80092EC8(player, local_0);
    func_8009312C(player, local_1);
}

struct Actor_800927C4 {
    char pad[0x50];
    Actor_unk50 *unk50;
    char pad2[0x130];
    s32 unk184;
};

void func_800927C4(s32 param_0, f32 x, f32 y, f32 z, Actor_800927C4 *actor)
{
    f32 local_0[4];
    void *handle;

if (func_800F6BE4(actor) != 0) {
    actor = func_800F53D0(actor);
    func_800EFA4C(local_0, x, y, z);
    handle = func_80108474(param_0, local_0, 0);
    actor->unk50->unk84 = *(s32 *) handle;
    func_800A70D0(actor->unk50->unk84, actor->unk184);

    // Matching: the comma expression is needed for the match.
    func_800A7108((0, actor->unk50)->unk84, actor->unk50->unk78);
}

}

void func_80092864(PlayerState *player, f32 param_1)
{
    char *base;
    // Matching: the pointer copy and the extra block are needed for the match.
    base = (char *) player;
    *((f32 *) (((char *) (*((PlayerState **) (base + 0x50)))) + 0x78)) = param_1;
    {
        base = (char *) player + 0x50;
        *(s8 *) ((char *) *(PlayerState **) base + 0x7C) = 1;
    }
}

void func_80092880(PlayerState *player, s32 param_1)
{
    *(u8 *) ((char *) (*(struct ba_flag_s **) ((char *) player + 80)) + 0x80) = param_1;
    *(u8 *) ((char *) (*(struct ba_flag_s **) ((char *) player + 80)) + 0x81) = 1;
}

void func_80092898(u8 *player)
{
    s32 unk_0[2];
    f32 zero;
    _babackpack_entrypoint_9();
    *((s8 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0x50)))) + 0x11)) = 0;
    *((u8 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0x50)))) + 0x14)) = 0xFF;
    *((s8 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0x50)))) + 0x10)) = 0;
    *((s8 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0x50)))) + 0x16)) = 0;
    *((s8 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0x50)))) + 0x12)) = 0;
    *((s8 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0x50)))) + 0x13)) = 0;
    *((s16 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0x50)))) + 0xC)) = 0;
    *((s8 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0x50)))) + 0xA2)) = 0;
    *((s16 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0x50)))) + 0x9C)) = 0;
    func_800936E8(player, 0);
    func_80093700(player, 1);
    *((s16 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0x50)))) + 0)) = func_800AE020();
    unk_0[0] = func_800AE080(*((s16 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0x50)))) + 0)));
    func_800AE6FC(unk_0[0], (s16) func_800E09B8(0xA));
    *((s8 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0x50)))) + 0x88)) = 0;
    *((s32 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0x50)))) + 4)) = func_800DBFF8();
    *((s32 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0x50)))) + 0x84)) = 0;
    *((s8 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0x50)))) + 0x7C)) = 0;
    *((s8 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0x50)))) + 0x81)) = 0;
    func_800EFD24((*((u8 **) (((s8 *) player) + 0x50))) + 0x2C);
    func_800EFD24((*((u8 **) (((s8 *) player) + 0x50))) + 0x38);
    func_800EFD24((*((u8 **) (((s8 *) player) + 0x50))) + 0x44);
    *((f32 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0x50)))) + 0x20)) = 0.0f;
    zero = ((local_1 *) player)->local_0->local_0;
    ((local_1 *) player)->local_0->local_1 = zero;
    ((local_1 *) player)->local_0->local_2 = zero;
    func_80093370(player, 1);
    func_8009337C(player, 1);
    func_80093230(player, 1.0f);
    *((s8 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0x50)))) + 0x15)) = 0;
    func_800931AC(player, 1);
    func_80092778(player);
    func_80092864(player, 1.0f);
}

void func_80092A1C(u8 *player)
{
    s32 local_0;

    func_80092EC8(player, 0);
    func_8009359C(player, 0);
    func_800ADFE0((*(s16 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x50)))) + (0))));
    (*(s16 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x50)))) + (0))) = 0;
    func_800DBFD8((*(s32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x50)))) + (4))));
    (*(s32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x50)))) + (4))) = 0;
    local_0 = (*(s32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x50)))) + (0x84)));

if (local_0 != 0) {
    func_800A70B0(local_0);
}

(*(s32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x50)))) + (0x84))) = 0;
_babackpack_entrypoint_8(player);
}

void func_80092AA4(player) void *player;
{
    void *player_copy = player;
    // Matching: the copy and the comma expression are needed for the match.
    *((s32 *) (0x84 + ((char *) (*((void **) (((char *) ((0, player_copy))) + 0x50)))))) = 0;
}

void func_80092AB0(PlayerState *player)
{
    func_800E0ACC(func_80092AD8(player));
}

Unkfunc_800E0960_1 *func_80092AD8(PlayerState *player)
{
    return func_800AE6BC(func_800AE080(*(s16 *) (*(u8 **) ((u8 *) player + 0x50))));
}

PlayerState *func_80092B04(player, param_1)
PlayerState *player;
s32 param_1;
{
    s32 local_0;

if (*(s16 *) (*(s32 *) ((u8 *) player + 0x50) + 0x0C) == 0x607) {
    return (PlayerState *) func_80093F7C(player);
}

local_0 = func_800D674C(*(s16 *) (*(s32 *) ((u8 *) player + 0x50) + 0x0C));

if (param_1 == 0) {
    func_800D62E4(*(s16 *) (*(s32 *) ((u8 *) player + 0x50) + 0x0C), param_1);
}

return (PlayerState *) local_0;
}

short func_80092B80(s16 *player)
{
    return ((s16 *) *((int *) player + 0x14))[6];
}

f32 func_80092B8C(PlayerState *player, f32 *out)
{
    func_800EE7F8(out, (*(u8 **) ((u8 *) player + 0x50)) + 0x64);
    return *(f32 *) ((*(u8 **) ((u8 *) player + 0x50)) + 0x70);
}

s32 func_80092BC4(s32 player)
{
    u8 **model_ptr;
    int addr;
    // Matching: the two temporaries are needed for the match.
    addr = player + 0x54;
    model_ptr = (u8 **) addr;
    return model_ptr[0xFFFFFFFF][0xC4];
}

f32 func_80092BD0(u8 *player)
{
    return (*(f32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x50)))) + (0xC8)));
}

f32 func_80092BDC(void *player)
{
    return ((f32 *) (*(void **) ((char *) player + 0x50)))[7];
}

f32 func_80092BE8(PlayerState *player)
{
    return *(f32 *) (*(s32 *) ((char *) player + 0x50) + 0x28);
}

f32 func_80092BF4(PlayerState *player)
{
    return *(f32 *) ((char *) (*(struct ba_alarm_s **) ((char *) player + 0x50)) + 0x30);
}

void func_80092C00(PlayerState *player, f32 *out)
{
    func_800921E0(player, 0x1, out);
}

void func_80092C24(PlayerState *player, f32 *out)
{
    func_800921E0(player, 0x2, out);
}

void func_80092C48(PlayerState *player, f32 *out)
{
    func_800921E0(player, 0x7, out);
}

void func_80092C6C(s32 player, s32 out)
{
    func_800921E0(player, 0x6, out);
}

void func_80092C90(void *player, s32 out, u32 param_2)
{
    func_800DBEFC(*((s32 *) (((char *) (*((s32 **) (((char *) player) + 0x50)))) + 0x4)), param_2,
                  out);

if (func_800EEEA8(out) != 0) {
    func_8009C128(player, out);
}

}

void func_80092CDC(u8 *player, s32 out, s32 param_2)
{
    func_800DBEFC((*(s32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x50)))) + (4))), param_2,
                  out);
    func_800EEF24(out);
}

int func_80092D18(s32 player, s32 out)
{
    func_800EE7F8(out, *(s32 *) (player + 0x50) + 0x44);
}

int func_80092D44(s32 player, s32 out)
{
    f32 local_1[3];
    f32 local_0[3];
    func_800921E0(player, 4, local_0);
    func_800921E0(player, 3, local_1);
    func_800EE780(out, local_0, local_1);
    func_800EF334(out, 0.5f);
}

void func_80092D9C(s32 player, s32 out)
{
    func_800921E0(player, 0x3, out);
}

void func_80092DC0(s32 player, s32 out)
{
    func_800921E0(player, 0x4, out);
}

void func_80092DE4(s32 player, s32 out)
{
    func_800921E0(player, 0x8, out);
}

void func_80092E08(s32 player, s32 out)
{
    func_800921E0(player, 0x9, out);
}

void func_80092E2C(s32 player, s32 out)
{
    func_800921E0(player, 0xA, out);
}

u8 func_80092E50(void *player)
{
    return (*((u8 **) (((u8 *) player) + 0x50)))[0x15];
}

void func_80092E5C(s32 player, s32 out)
{
    func_800921E0(player, 0x5, out);
}

void func_80092E80(s32 player)
{
    func_800AE080(**(s16 **) (player + 0x50));
}

s32 func_80092EA4(s32 player)
{
    return ((u8 *) (*(u8 **) (player + 0x50)))[0x17];
}

s32 func_80092EB0(s32 player)
{
    return ((u8 *) (*(u8 **) (player + 0x50)))[0x18];
}

void func_80092EBC(void *player, s32 alpha)
{
    ((s8 *) (*(void **) ((char *) player + 0x50)))[20] = alpha;
}

// Switches the model asset (model_id) of the player model component.
void func_80092EC8(player, model_id) u8 *player;
s32 model_id;
{
    s32 model_asset;
    s32 unk_0;
    u8 local_1;

if (model_id != *(s16 *) (*(u8 **) (player + 0x50) + 0xC)) {
    if (*(s16 *) (*(u8 **) (player + 0x50) + 0xC) != 0) {
        func_800D70F8(*(s16 *) (*(u8 **) (player + 0x50) + 0xC), 0);
        func_800D6CEC(*(s16 *) (*(u8 **) (player + 0x50) + 0xC));
        *(s16 *) (*(u8 **) (player + 0x50) + 0xE) = 0;
    }

    local_1 = (*(u8 **) (player + 0x50))[0x12];
    if (local_1 != 0) {
        func_80100E18((s16) local_1);
        (*(u8 **) (player + 0x50))[0x12] = 0;
    }

    *(s16 *) (*(u8 **) (player + 0x50) + 0xC) = (s16) model_id;
    func_80093FD4(player, model_id);

    if (model_id != 0) {
        model_asset = func_80092B04(player, 0);
        func_800D70F8(*(s16 *) (*(u8 **) (player + 0x50) + 0xC), 1);
        func_800ADD80(*(s16 *) (*(u8 **) (player + 0x50) + 0), func_800B27E0(model_asset));

        if ((*(u8 **) (player + 0x50))[0x12] == 0) {
            if (func_800B26F0(model_asset) != 0) {
                unk_0 = 1;
            } else {
                unk_0 = 0;
            }
            (*(u8 **) (player + 0x50))[0x12] =
                func_80100D24(model_asset, *(s16 *) (*(u8 **) (player + 0x50) + 0xC), unk_0,
                              func_800A25D0(player), 0, 0);
        }

        func_800B237C(func_800B2840(model_asset), *(u8 **) (player + 0x50) + 0x50,
                      *(u8 **) (player + 0x50) + 0x5C);
        *(f32 *) (*(u8 **) (player + 0x50) + 0x58) = 0.0f;
        *(f32 *) (*(u8 **) (player + 0x50) + 0x50) = *(f32 *) (*(u8 **) (player + 0x50) + 0x58);
        func_800EE7F8(*(u8 **) (player + 0x50) + 0x64, *(u8 **) (player + 0x50) + 0x50);
        *(f32 *) (*(u8 **) (player + 0x50) + 0x70) = *(f32 *) (*(u8 **) (player + 0x50) + 0x5C);
        *(f32 *) (*(u8 **) (player + 0x50) + 0x60) = *(f32 *) (*(u8 **) (player + 0x50) + 0x74) =
            func_800B2354(func_800B2840(model_asset));
    }
}

}

void func_80093070(s32 player, s32 param_1, s32 param_2, u8 *param_3)
{
    s32 unk_0;
    s32 unk_1;
    s32 unk_2;
    s32 unk_3;
    s32 unk_4;
    s32 unk_5;
    u8 old_handle;
    unk_0 = func_800D674C(param_2);
    unk_1 = func_800D674C(param_1);
    unk_4 = func_800A25D0(player);
    unk_5 = unk_4;
    old_handle = *param_3;

if (old_handle != 0) {
    unk_3 = func_80100E18((s16) old_handle);
}

*param_3 = func_80100D24(unk_0, param_2, 1, unk_5, 0, 0);
unk_2 = func_800B2840(unk_0);
func_800B25D8(func_80100A74(*param_3, 0), unk_2, unk_1);
}

void func_8009312C(player, model_id) Actor_8009312C *player;
unsigned int model_id;
{
    ActorLocal_CC_50 *local_0;

if (model_id != 0) {
    local_0 = *(ActorLocal_CC_50 **) ((char *) player + 0x50);
    if (model_id != local_0->unkE) {
        local_0->unkE = model_id;
        local_0 = *(ActorLocal_CC_50 **) ((char *) player + 0x50);
        func_80093070(player, model_id, local_0->unkC, (u8 *) local_0 + 0x12);
    }
}

}

void func_8009316C(u8 *player, int model_id)
{
    u8 *model;
    u8 *model_2;

if (model_id != 0) {
    model = *(u8 **) ((char *) player + 0x50);
    if (model_id != *(s16 *) ((char *) model + 0x9E)) {
        *(s16 *) ((char *) model + 0x9E) = model_id;
        // Matching: the empty block is needed for the match.
        if (0 && 0) {
        }
        model_2 = *(u8 **) ((char *) player + 0x50);
        func_80093070(player, model_id, *(s16 *) ((char *) model_2 + 0x9C), model_2 + 0xA0);
    }
}

}

void func_800931AC(param_0, param_1) PlayerState *param_0;
s32 param_1;
{
    if ((param_1 != QQ->unk15) && ((param_1 == 2) || (QQ->unk15 == 2))) {
        yaw_setIdeal(param_0, func_800136E4(yaw_get(param_0) + 180.0f));
        yaw_applyIdeal(param_0);
    }

QQ->unk15 = param_1;
}

void func_80093230(PlayerState *param_0, f32 param_1)
{
    PP->unk1C = param_1;
    PP->unk70 = PP->unk1C * PP->unk5C;
    PP->unk74 = PP->unk1C * PP->unk60;
    func_800EF334(&PP->unk64, PP->unk1C);
}

void func_8009328C(PlayerState *player, f32 yaw)
{
    *(f32 *) (*(s32 *) ((char *) player + 0x50) + 0x28) = func_800136E4(yaw);
}

func_800932BC(s32 player, f32 param_1)
{
    *(f32 *) (*(s32 *) (player + 0x50) + 0xC8) = param_1;
}

void func_800932CC(u8 *player, int enabled)
{
    u8 *model;
    model = *((u8 **) (((s8 *) player) + 0x50));

if (enabled != *(u8 *) ((s8 *) model + 0xC4)) {
    if (enabled != 0) {
        *(f32 *) ((s8 *) model + 0xC8) = 0.0f;
    }
    model = *(u8 **) ((s8 *) player + 0x50);
    *(s8 *) ((s8 *) model + 0xC4) = enabled;
}

}

void func_80093300(PlayerState *player, f32 param_1)
{
    *(f32 *) ((*(u8 **) ((u8 *) player + 0x50)) + 0x30) = param_1;
    func_8009332C(player, param_1);
}

func_8009332C(s32 player, f32 param_1)
{
    *(f32 *) (*(s32 *) (player + 0x50) + 0x3c) = param_1;
}

void func_8009333C(void *player)
{
    func_800EE7F8(*(s32 *) ((char *) player + 80) + 68);
}

void func_80093360(PlayerState *player, f32 param_1)
{
    *(f32 *) ((u8 *) *(s32 **) ((u8 *) player + 0x50) + 0x48) = param_1;
}

void func_80093370(player, value) void *player;
s32 value;
{
    ((s8 *) (*(void **) ((char *) player + 0x50)))[23] = value;
}

void func_8009337C(player, value) void *player;
s32 value;
{
    ((s8 *) (*(void **) ((char *) player + 0x50)))[24] = value;
}

// Moves the value at +0x30 toward its target at +0x3C.
void func_80093388(u8 *player)
{
    f32 delta;
    f32 local_1;
    f32 step;
    u8 *model;
    u8 *model_2;

    model = *(u8 **) ((s8 *) player + 0x50);
    delta = *(f32 *) ((s8 *) model + 0x3C) - *(f32 *) ((s8 *) model + 0x30);
    local_1 = mlAbsF(delta);
    step = local_1;

if (local_1 < 0.01f) {
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x50) + 0x30) =
        *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x50) + 0x3C);
    return;
}

if (local_1 > 5.0f) {
    step = 1.0f;
}

if (delta > 0.0f) {
    model_2 = *(u8 **) ((s8 *) player + 0x50);
    *(f32 *) ((s8 *) model_2 + 0x30) = *(f32 *) ((s8 *) model_2 + 0x30) + step;
    return;
}

*(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x50) +
          0x30) = *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x50) + 0x30) - step;
}

void func_80093448(s32 *player)
{
    s32 local_2;
    s32 local_1;
    s32 local_0;

if (!*(s32 *) ((char *) *(s32 **) ((char *) player + 0x50) + 0x84)) {
    {
        func_8009C128(player, &local_0);
    }
    _chbaddiesetup_entrypoint_5(&func_800927C4, 0x215, local_0, local_1, local_2,
                                *(s32 *) ((char *) player + 0x184));
}

func_80093388(player);
func_80092018(player);
func_800920C8(player);
}

void func_800934C4(void *player)
{
    s32 handle;
    handle = *((s32 *) (((char *) (*((u8 **) (((char *) player) + 0x50)))) + 4));

if (handle != 0) {
    *(s32 *) ((char *) *(u8 **) ((char *) player + 0x50) + 4) =
        func_800DC060(handle, *(s32 *) ((char *) *(u8 **) ((char *) player + 0x50) + 4), player);
}

}

void func_80093504(player) u8 *player;
{
    func_800F23D0((*(s32 *) ((s8 *) (player) + (0x50))) + 0xCC);
}

void func_80093528(u8 *player)
{
    u8 local_0;
    u8 *local_1;

    (*(s8 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x50)))) + (0x1A))) = 0;
    func_800DBEB0((*(s32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x50)))) + (4))), player);
    (*(s8 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x50)))) + (0x16))) = 0;
    (*(u8 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x50)))) + (0xA5))) = 0U;
    local_1 = (*(u8 **) ((s8 *) (player) + (0x50)));
    local_0 = (*(u8 *) ((s8 *) (local_1) + (0xA5)));
    (*(u8 *) ((s8 *) (local_1) + (0xA1))) = local_0;
    (*(u8 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x50)))) + (0x10))) = local_0;
}

void func_80093584(u8 *player)
{
    u8 *model;

    (*(s32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x50)))) + (0x94))) = 0;
    model = (*(u8 **) ((s8 *) (player) + (0x50)));
    (*(s32 *) ((s8 *) (model) + (8))) = (s32) (*(s32 *) ((s8 *) (model) + (0x94)));
}

// Switches the model asset of the secondary model slot.
void func_8009359C(player, model_id) PlayerState *player;
s32 model_id;
{
    void *local_0;
    LocalSub *local_1;
    s32 unk_0;
    s32 unk_1;
    local_1 = &MODEL(player)->field_90;

if (model_id != local_1->field_C) {
    if (local_1->field_C) {
        if (local_1->field_10) {
            func_80100E18(local_1->field_10);
            local_1->field_10 = 0;
        }
        func_800ADFE0(local_1->field_0);
        local_1->field_0 = 0;
        func_800D70F8(local_1->field_C, 0);
        func_800D6CEC(local_1->field_C);
        local_1->field_C = 0;
        local_1->field_E = 0;
    }
    if (!model_id) {
        local_1->field_12 = 0;
        return;
    }
    local_1->field_C = model_id;
    local_0 = func_80093738(player);
    func_800D70F8(local_1->field_C, 1);
    if (func_800B26F0(local_0))
        unk_0 = 1;
    else
        unk_0 = 0;
    unk_1 = func_800A25D0(player);
    local_1->field_10 = func_80100D24(local_0, local_1->field_C, unk_0, unk_1, 0, 0);
    local_1->field_0 = func_800AE020();
    func_800AE6FC(func_800AE080(local_1->field_0), func_800E09B8(0xC));
}

}

void func_800936CC(void *player, s32 value)
{
    ((s8 *) (*(void **) ((char *) player + 0x50)))[162] = value;
}

func_800936D8(s32 player, f32 param_1)
{
    *(f32 *) (*(s32 *) (player + 0x50) + 0x98) = param_1;
}

void func_800936E8(player, value) void *player;
s32 value;
{
    ((s8 *) (*(void **) ((char *) player + 0x50)))[163] = value;
}

s32 func_800936F4(s32 player)
{
    // Matching: the index expression is needed for the match.
    return ((u8 **) (player + 0x54))[0xFFFFFFFF ^ 0][0xA3];
}

void func_80093700(player, value) void *player;
s32 value;
{
    ((s8 *) (*(void **) ((char *) player + 0x50)))[25] = value;
}

void func_8009370C(u8 *player)
{
    func_800AE6BC(
        func_800AE080((*(s16 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x50)))) + (0x90)))));
}

int func_80093738(player) void *player;
{
    u32 model;
    s16 model_id;
    // Matching: the mask is needed for the match.
    model = (*((u32 *) (((u8 *) player) + 0x50))) & 0xFFFFFFFFFFFFFFFF;
    model_id = *((s16 *) (((u8 *) model) + 0x9C));
    func_800D674C(model_id);
}

// slot 0: main model, slot 1: secondary model.
void func_8009375C(u8 *player, u8 *param_1, s32 slot)
{
    s32 local_0;
    s16 local_1;
    s32 model_asset;
    s32 unk_0;
    s32 unk_1;

    unk_0 = (*(s32 *) ((s8 *) (param_1) + (4))) + 0x40;

switch (slot) {
    case 0:
        model_asset = func_80092B04(player, 0);
        local_1 = *(s16 *) ((s8 *) *(u8 **) ((s8 *) player + 0x50) + 0);
        local_0 = baanim_getAnimCtrlPtr(player);
        *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x50) + 0x10) = 1;
        *(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x50) + 8) = unk_0;
        break;
    case 1:
        model_asset = func_80093738(player);
        local_1 = *(s16 *) ((s8 *) *(u8 **) ((s8 *) player + 0x50) + 0x90);
        local_0 = func_8008D04C(player);
        *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x50) + 0xA1) = 1;
        *(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x50) + 0x94) = unk_0;
}

unk_1 = func_800B27E0(model_asset);
func_8008C200(local_1, unk_1, func_8008AEDC(local_0));
func_800AE598(func_800AE080(local_1), param_1 + 4);
}

// Draws one model slot of the player: 0 = main model, 1 = secondary model.
void func_80093864(PlayerState *player, s32 ctx, s32 slot)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 unk_0[3];
    f32 scale;
    void *model;
    void *unk_1;

switch (slot) {
    case 0:
        func_8009216C(player, local_1, local_0);
        scale = MODEL(player)->field_1C;
        model = func_80092B04(player, 1);
        unk_1 = func_800AE080(MODEL(player)->field_0);
        if (model) {
            if (MODEL(player)->field_12) {
                func_800DF720(func_80100AC4(MODEL(player)->field_12));
                func_800DF818(func_80100A74(MODEL(player)->field_12, 0));
            }
            func_800DF714(MODEL(player)->field_8);
            func_800DF72C(unk_1);
            func_800A06E8(player);
            func_800DF47C(func_80092234, player);
            func_800DF440(0);
            if (func_800A946C() == 1)
                func_800DF574(1);
        }
        break;
    case 1:
        scale = MODEL(player)->field_90.field_8;
        model = func_80093738(player);
        unk_1 = func_800AE080(MODEL(player)->field_90.field_0);
        func_800EE7F8(local_1, MODEL(player)->field_AC);
        func_800EE7F8(local_0, MODEL(player)->field_B8);
        if (model) {
            if (MODEL(player)->field_90.field_10) {
                func_800DF720(func_80100AC4(MODEL(player)->field_90.field_10));
                func_800DF818(func_80100A74(MODEL(player)->field_90.field_10, 0));
            }
            func_800DF714(MODEL(player)->field_90.field_4);
            func_800DF72C(unk_1);
            func_800DF3E0();
            func_800DF47C(func_80092224, player);
            func_800A0714(player, MODEL(player)->field_90.field_C);
        }
}

func_800EE7F8(unk_0, MODEL(player)->field_2C);
func_800EF04C(local_1, MODEL(player)->field_44);
func_800EF04C(unk_0, MODEL(player)->field_44);

if (model) {
    func_800923A8(player, slot == 0);
    func_800DE448(local_1, local_0, scale, unk_0, model);
}

}

void func_80093AB8(player, ctx) PlayerState *player;
s32 ctx;
{
    s32 local_0;
    s32 local_1;
    f32 pos[3];
    LocalModel *model;
    s32 unk_1;

if (MODEL(player)->field_17) {
    local_0 = func_800A89F8();
    model = MODEL(player);
    switch (model->field_90.field_12) {
        case 1:
            local_1 = 3;
            break;
        case 2:
        case 3:
            switch (model->field_19) {
                case 0:
                    local_1 = 3;
                    break;
                case 1:
                    local_1 = 3;
                    if (func_800A4C68(player) == local_0) {
                        if (MODEL(player)->field_90.field_13)
                            local_1 = 1;
                        else if (!MODEL(player)->field_18)
                            local_1 = 0;
                    }
                    break;
            }
            break;
    }
    switch (local_1) {
        case 0:
            return;
        case 1:
            break;
        case 3:
            func_8009C128(player, pos);
            if (!func_800E3E8C(pos, MODEL(player)->field_1C * MODEL(player)->field_74))
                return;
            unk_1 = func_800BEC1C();
            if (unk_1) {
                if (!MODEL(player)->field_90.field_15) {
                    MODEL(player)->field_90.field_15 = 1;
                    func_800EF04C(pos, MODEL(player)->field_64);
                    MODEL(player)->field_90.field_14 = _dbzone_entrypoint_4(
                        func_800BEC28(0), pos, MODEL(player)->field_90.field_16);
                }
                if (MODEL(player)->field_90.field_14 &&
                    !_glzone_entrypoint_6(unk_1, MODEL(player)->field_90.field_16,
                                          MODEL(player)->field_90.field_14))
                    return;
            }
    }
    switch (MODEL(player)->field_90.field_12) {
        case 1:
            if (MODEL(player)->field_18 || func_800A4C68(player) != local_0) {
                if (!MODEL(player)->field_10) {
                    func_8008CA98(player);
                    func_8009375C(player, ctx, 0);
                }
                func_80093864(player, ctx, 0);
                if (MODEL(player)->field_90.field_13) {
                    func_8009216C(player, MODEL(player)->field_AC, MODEL(player)->field_B8);
                    if (!MODEL(player)->field_90.field_11) {
                        func_8008D058(player);
                        func_8009375C(player, ctx, 1);
                    }
                    func_80093864(player, ctx, 1);
                }
            }
            break;
        case 2:
            if (local_1 == 3) {
                if (!MODEL(player)->field_10) {
                    _bsfirstp_entrypoint_1(player, 0);
                    func_8009375C(player, ctx, 0);
                }
                func_80093864(player, ctx, 0);
            }
            break;
        case 3:
            if (local_1 == 3) {
                if (!MODEL(player)->field_10) {
                    _bsfirstp_entrypoint_1(player, 0);
                    func_8009375C(player, ctx, 0);
                }
                func_80093864(player, ctx, 0);
            }
    }
}

}

s32 func_80093DF4(player, value)
u8 *player;
s32 value;
{
    return (value == (*(u8 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x50)))) + (0xA2)))) ? 1
                                                                                             : 0;
}

void func_80093E18(u8 *player, s32 ctx)
{
    s8 pad[4];
    s32 unk_1;
    s32 unk_0;
    u8 *model;
    unk_0 = func_800A89F8();
    unk_1 = func_800A88C4(unk_0, func_800A5090(player));
    func_800E44FC(ctx);

if (*(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x50) + 0xA1) == 0) {
    _bsfirstp_entrypoint_1(player, 1);
    {
        model = *(u8 **) ((s8 *) player + 0x50);
        _bsfirstp_entrypoint_0(player, model + 0xAC, model + 0xB8);
        func_8009375C(player, ctx, 1);
    }
}

func_80093864(player, ctx, 1);
func_800A88C4(unk_0, unk_1);
func_800E44FC(ctx);
}

f32 func_80093ECC(s32 player, s32 *pos, s32 rot, f32 *vec)
{
    func_8009216C(player, pos, rot);
    func_800EE7F8(vec, (s32 *) ((u8 *) (((s32 *) player)[0x14]) + 0x2C));
    func_800EF04C(pos, (s32 *) ((u8 *) (((s32 *) player)[0x14]) + 0x44));
    func_800EF04C(vec, (s32 *) ((u8 *) (((s32 *) player)[0x14]) + 0x44));
    return *(f32 *) ((u8 *) (((s32 *) player)[0x14]) + 0x1C);
}

s32 func_80093F30(s32 index)
{
    int offset_32;
    long long offset;
    int offset_masked;
    offset = index * 4;
    offset_32 = offset;
    offset_masked = offset_32 & 0xFFFFFFFFFFFFFFFF;
    if (func_8009EA2C()) {
        offset = offset_masked;
        return D_80117DDC[offset];
    }
    {
        return D_80117DD8[offset & 0xFFFFFFFFFFFFFFFF];
    }
}

s32 func_80093F7C(player, flag)
s32 player;
s32 flag;
{
    s32 local_0;

    local_0 = func_800D674C(*(s32 **) (*(s32 **) (player + 0x50) + 67));

if (flag == 0) {
    func_800D62E4(*(s32 **) (*(s32 **) (player + 0x50) + 67));
}

return local_0;
}

// For model 0x607, picks the model variant from the per-map table; otherwise clears it.
int func_80093FD4(player, model_id)
s32 player;
u32 model_id;
{
    s32 local_0;
    s32 local_1;
    s32 offset;

if (model_id == 0x607) {
    local_0 = func_800EA05C();
    local_1 = 0;
    if (*(s16 *) D_80117DF0 != -1) {
        do {
            if (*(s16 *) (D_80117DF0 + local_1 * 4) == local_0)
                break;
            local_1++;
        } while (*(s16 *) (D_80117DF0 + local_1 * 4) != -1);
    }
    offset = local_1 << 2;
    local_0 = func_80093F30(*(s16 *) (D_80117DF0 + offset + 2));
    func_800941C8(player, local_0);
    return;
}
{
    func_800941C8(player, 0);
}

}

// Chooses the model variant from the camera distance to pos.
void func_80094070(actor, pos) Actor94070 *actor;
f32 *pos;
{
    f32 dist;
    f32 local_0[3];
    s32 local_1;
    s32 variant;

if (actor->local_0->local_0 && func_800D90A4(&actor->local_0->local_2)) {
    func_800E3980(local_0);
    dist = func_800EEAD4(pos, local_0);
    for (local_1 = 0; local_1 < 2; local_1++) {
        if (dist < D_80117DD0[local_1].local_0)
            break;
    }
    local_1--;
    variant = func_80093F30(local_1);
    if (variant != actor->local_0->local_0) {
        if (func_800942D0(actor, local_1)) {
            if (actor->local_0->local_1 && variant != actor->local_0->local_1) {
                func_800E4BB8(actor->local_0->local_1);
            }
            actor->local_0->local_1 = variant;
            if (func_800E488C(actor->local_0->local_1)) {
                func_800941C8(actor, actor->local_0->local_1);
            }
        } else if (actor->local_0->local_1) {
            func_800E4BB8(actor->local_0->local_1);
            actor->local_0->local_1 = 0;
        }
    } else if (actor->local_0->local_1) {
        func_800E4BB8(actor->local_0->local_1);
        actor->local_0->local_1 = 0;
    }
}

}

void func_800941C8(u8 *player, s32 variant)
{
    s32 unk_0;
    s32 old_variant;
    s32 local_1;
    u8 unk_1;
    u8 *model;

    model = (*(u8 **) ((s8 *) (player) + (0x50)));
    old_variant = (*(s32 *) ((s8 *) (model) + (0x10C)));

if (old_variant != 0) {
    func_800D70F8(old_variant, 0);
    func_800D6CEC(*(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x50) + 0x10C));
    model = *(u8 **) ((s8 *) player + 0x50);
}

unk_1 = (*(u8 *) ((s8 *) (model) + (0x12)));

if (unk_1 != 0) {
    func_80100E18((s16) unk_1);
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x50) + 0x12) = 0;
    model = *(u8 **) ((s8 *) player + 0x50);
}

(*(s32 *) ((s8 *) (model) + (0x10C))) = variant;
(*(s32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x50)))) + (0x110))) = 0;

if (variant != 0) {
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x50) + 0x114) = 0.0f;
    local_1 = func_80093F7C(player, 0);
    func_800D70F8(*(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x50) + 0x10C), 1);
    if (func_800B26F0(local_1) != 0) {
        unk_0 = 1;
    } else {
        unk_0 = 0;
    }
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x50) + 0x12) =
        func_80100D24(local_1, *(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x50) + 0x10C), unk_0,
                      func_800A25D0(player), 0, 0);
}

}

// Whether enough heap is free (threshold 0x32000) for the given variant.
s32 func_800942D0(player, index)
u8 *player;
s32 index;
{
    s32 local_0;

    func_8001BDAC(&local_0, 1);

if (*(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x50) + 0x110) != 0) {
    local_0 += *(s32 *) ((u8 *) &D_80117DD4 + (index * 0x10));
}

return local_0 >= 0x32001;
}

// Egg ammo selection: egg list per mode, cycling on R, HUD egg item, unlimited-egg timer.
s32 func_80094340(void)
{
    return 0x4;
}

// Tests mask against the egg flag byte (egg state + 2).
s32 func_80094348(u8 *player, s32 mask)
{
    return ((*(u8 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x64)))) + (2))) & mask) ? 1 : 0;
}

void func_80094370(s32 player)
{
    func_800946C4(player, 0);

}

// Ticks the unlimited-egg timer and shows it on the HUD.
void func_80094390(u8 *player)
{
    if ((func_800C954C() == 0) && (func_800F6774(*(s32 *) (player + 0x184)) != 0) &&
        (_batimer_decrement(player, 0xD) != 0)) {
        func_8009E9F0(0.0f);
        func_80094430(player, 0);
        func_80101180(0x1CD, 0x76, 0);
    }

if (func_800C0638() == 0) {
    func_800D2498(0x105, (s32) _batimer_get(player, 0xD), 0);
}

}

// Starts (duration > 0) or ends the unlimited-egg timer.
void func_80094430(s32 player, f32 duration)
{
    if (duration != 0.0f) {
        func_800946C4(player, 2);
    } else {

func_80094370(player);
}
if (duration > 0.0f) {
    func_800947EC(player, 0x10, 1);
    _batimer_set(player, 0xD, duration);
    return;
}
func_800947EC(player, 0x10, 0);
_batimer_set(player, 0xD, 0);
}

s32 func_800944E0(PlayerState *player, s32 index)
{
    return D_80117E3C[index << 1];
}

u8 func_800944F8(s32 player, s32 index)
{
    return D_80117E3D[index << 1];
}

// Returns the currently selected egg type.
s32 func_80094510(PlayerState *player)
{
    u8 *local_0 = *((u8 **) (((u8 *) player) + 0x64));
    u8 *state_copy;
    state_copy = local_0;
    return *((u8 *) (state_copy[1] + ((u32 *) D_80117E30)[local_0[0]]));
}

void func_80094538(s32 player)
{
    func_8009E9E4(func_80094510(player));
    func_8009E9F0(_batimer_get(player, 13));
}

// Selects wanted_egg if available, else the first available egg, else index 0.
void func_80094574(PlayerState *param_0, s32 wanted_egg)
{
    s32 local_0;
    LOCAL_INDEX = 0;
    while ((local_0 = func_80094510(param_0)) != 0) {
        if (_gcegg_entrypoint_6(local_0) && local_0 == wanted_egg)
            return;
        LOCAL_INDEX++;
    }
    LOCAL_INDEX = 0;
    while ((local_0 = func_80094510(param_0)) != 0) {
        if (_gcegg_entrypoint_6(local_0))
            return;
        LOCAL_INDEX++;
    }
    LOCAL_INDEX = 0;
}

void func_80094644(void *player)
{
    s32 timer;
    (*(S_94644 **) ((u8 *) player + 0x64))->unk2 = 0;
    func_80094370(player);
    func_80094574(player, func_8009E964());
    timer = (s32) func_8009E970();
    if (timer != 0) {
        func_80094430(player, (f32) timer);
    }
    (*(S_94644 **) ((u8 *) player + 0x64))->unk3 = 0;

}

void func_800946C4(player, mode) PlayerState *player;
s32 mode;
{
    switch (mode) {
        case 0:
            func_800947EC(player, 1, 0);
            func_800947EC(player, 2, 0);
            func_800947EC(player, 4, 0);
            func_800947EC(player, 8, 0);
            break;

        case 1:
            func_800947EC(player, 1, 1);
            func_800947EC(player, 2, 1);
            func_800947EC(player, 4, 1);
            func_800947EC(player, 8, 0);
            break;

        case 2:
            func_800947EC(player, 1, 1);
            func_800947EC(player, 2, 1);
            func_800947EC(player, 4, 1);
            func_800947EC(player, 8, 0);
    }

(*(s8 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x64)))) + (0))) = (s8) mode;
(*(s8 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x64)))) + (1))) = 0;

}

void func_800947EC(player, mask, set) PlayerState *player;
s32 mask;
s32 set;
{
    if (set != 0) {
        (*(u8 **) ((u8 *) player + 0x64))[2] |= mask;
    } else {

(*(u8 **) ((u8 *) player + 0x64))[2] &= ~mask;
}
}

int func_80094824(s32 player)
{
    if (bainput_func_80097C7C()) {
        func_80094A10(player);
        func_80094C88(player);

}
func_80094D04(player);
}

void func_80094864(PlayerState *player)
{
    s32 local_0;
    u8 local_1;
    if (func_800F6774(*(s32 *) ((char *) player + 0x184))) {
        if (func_80094348(player, 0x10)) {
            func_80094390(player);
        }

if (func_80094348(player, 8)) {
    local_0 = _gcegg_entrypoint_5(func_80094510(player));
    if (func_80094348(player, 4) == 0) {
        func_800D1824(local_0);
    }
}

if (func_80094348(player, 1) == 0) {
    local_1 = *(u8 *) ((char *) *(u8 **) ((char *) player + 0x64) + 3);
    switch (local_1) {
        case 0:
            if (bainput_func_80097C7C(player) != 0) {
                *(u8 *) ((char *) *(u8 **) ((char *) player + 0x64) + 3) = 1U;
                func_80094E40(func_80094510(player));
                func_80094C88(player);
            }
            break;

        case 1:
            func_80094824(player);
            if (func_80094DA8(player) != 0) {
                *(u8 *) ((char *) *(u8 **) ((char *) player + 0x64) + 3) = 2U;
                func_80094C88(player);
            }
            break;

        case 2:
            func_80094824(player);
            if (func_80094DA8(player) == 0) {
                *(u8 *) ((char *) *(u8 **) ((char *) player + 0x64) + 3) = 0U;
            }
    }
}

}
}

int func_800949BC(s32 player)
{
    return func_8009E674(player, 0x80000) != 0 ||
           (_bafpctrl_entrypoint_5(player) != 0 && _baeggfire_entrypoint_8(player) != 0);
}

// Cycles to the next available egg in the current list and returns it.
s32 func_80094A10(player)
PlayerState *player;
{
    s32 new_egg;
    s32 old_egg;
    s32 egg;
    u8 *egg_state;

    old_egg = func_80094510(player);
    if (func_800949BC(player) != 0) {
        return old_egg;
    }
    do {
        egg_state = *(u8 **) ((u8 *) player + 0x64);
        egg_state[1] = egg_state[1] + 1;
        new_egg = func_80094510(player);
        egg = new_egg;

if (new_egg == 0) {
    *(*(u8 **) ((u8 *) player + 0x64) + 1) = 0;
    egg = func_80094510(player);
}

}
while (_gcegg_entrypoint_6(egg) == 0)
    ;
if (egg != old_egg) {
    func_80094E40(egg);
}
return egg;
}

void func_80094AB4(S_94AB4 *player)
{
    s32 egg;
    if (func_80094348(player, 2) != 0) {
        return;
    }
    egg = func_80094C64(player, player->unk64->unk1);
    if (egg == 0) {
        return;
    }
    if (_gcegg_entrypoint_6(egg) == 0) {
        return;
    }
    func_800D1824(_gcegg_entrypoint_5(egg));
}

s32 func_80094B14(PlayerState *player)
{
    s32 local_0;
    local_0 = _gcegg_entrypoint_5(func_80094510(player));
    if (baflag_isTrue(player, 0x34) || (!func_80094348(player, 4) && func_800D1C38(local_0))) {
        func_800D1824(local_0);
        func_800FC660(0xF);
        return 0;
    }
    if (func_80094510(player) == 5 && _plsu_entrypoint_1(0x11) != -1)
        return 0;
    return 1;
}

s32 func_80094BC0(PlayerState *player)
{
    if (func_80094348(player, 4)) {
        return 1;
    }
    return func_800D1A04(_gcegg_entrypoint_5(func_80094510(player)));
}

int func_80094C0C(s32 player, s32 egg)
{
    if (func_80094348(player, 4)) {
        return;
    }
    if (egg != 2 || func_8009EA2C() == 0) {
        func_800D1804(_gcegg_entrypoint_5(egg));

}
}

// Egg type at index in the current mode's egg list.
u8 func_80094C64(player, index)
PlayerState *player;
s32 index;
{
    return ((u8 **) D_80117E30)[*(u8 *) *(u8 **) ((u8 *) player + 0x64)][index];
}

int func_80094C88(player)
s32 player;
{
    s32 local_0;
    s32 local_1;
    s32 egg;
    local_1 = 0;
    egg = func_80094C64(player, 0);
    while (egg != 0) {
        if (_gcegg_entrypoint_6(egg)) {
            local_0 = _gcegg_entrypoint_5(egg);
            func_800D1824(local_0);
        }

local_1++;
egg = func_80094C64(player, local_1);

}
}

void func_80094D04(player) u8 *player;
{
    s32 local_0;
    s32 local_1;
    s32 unk_0;
    s32 egg;
    s32 i;

    i = 0;
    local_0 = func_80094C64(player, 0);
    egg = local_0;
    if (local_0 != 0) {
        do {
            if ((i != *(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x64) + 1)) &&
                (_gcegg_entrypoint_6(egg) != 0)) {
                unk_0 = func_800D27C8(func_800D1C5C(_gcegg_entrypoint_5(egg)));
                if (unk_0 >= 0) {
                    func_800FAA34(unk_0);
                }
            }
            i += 1;
            local_1 = func_80094C64(player, i);
            egg = local_1;
        } while (local_1 != 0);

}
}

int func_80094DA8(player)
s32 player;
{
    s32 local_1;
    s32 player_copy;
    s32 egg;
    local_1 = 0;
    // Matching: no-op OR needed for the match.
    player_copy = player | 0;
    while ((egg = func_80094C64(player_copy, local_1)) != 0) {
        if (_gcegg_entrypoint_6(egg) != 0) {
            if (func_800D27F4(func_800D1C5C(_gcegg_entrypoint_5(egg))) == 0) {
                return 0;
            }
        }

local_1++;
}

return 1;
}

int func_80094E40()
{
    s32 local_0;
    local_0 = _gcegg_entrypoint_2();
    // Matching: no-op OR needed for the match.
    func_800FC660(local_0 | 0);
}

// TU-NOTE: the .data of this file is defined here in C, values taken from the ROM.
// D_80117E3D = D_80117E3C + 0x1, D_80117DD4 = D_80117DD0 + 0x4, D_80117DD8 = D_80117DD0 + 0x8,
// D_80117DDC = D_80117DD0 + 0xC are linker symbols (undefined_syms.us.txt) inside these objects.
// The extern declarations above match the objects (same addresses): D_80117E30 is u32.
Entry94070 D_80117DD0[2] = {0.0f,   0x0, 0x1, 0x38, 0x80, 0x0, 0x0, 0x6, 0x2A, 0x0, 0x0, 0x8, 0x38,
                            8e+02f, 0x0, 0x1, 0x11, 0x70, 0x0, 0x0, 0x6, 0x2B, 0x0, 0x0, 0x8, 0x39};
u8 D_80117DF0[48] = {0x0,  0xB8, 0x0, 0x1, 0x0, 0xD6, 0x0, 0x1, 0x1, 0xA7, 0x0, 0x1,
                     0x1,  0xA8, 0x0, 0x1, 0x1, 0xA9, 0x0, 0x1, 0x1, 0x12, 0x0, 0x1,
                     0x1,  0x27, 0x0, 0x1, 0x1, 0x28, 0x0, 0x1, 0x1, 0x36, 0x0, 0x1,
                     0xFF, 0xFF, 0x0, 0x0, 0x0, 0x0,  0x0, 0x0, 0x0, 0x0,  0x0, 0x0};
u32 D_80117E20[2] = {0x1020403, 0x5000000};
u32 D_80117E28[1] = {0x1000000};
u32 D_80117E2C[1] = {0x7000000};
u32 D_80117E30[3] = {(u32) &D_80117E20, (u32) &D_80117E28, (u32) &D_80117E2C};
char D_80117E3C[36] = {0x0, 0x0,  0x3,  0x0,  0x2, 0x0,  0x2, 0x0,  0x1, 0x0,  0x1, 0x0,
                       0x1, 0x0,  0x0,  0x1,  0x0, 0x40, 0x0, 0x41, 0x0, 0x42, 0x0, 0x43,
                       0x0, 0x44, -0x1, -0x1, 0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0};
