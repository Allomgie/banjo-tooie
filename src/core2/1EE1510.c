#include "common.h"

#define reinterpret_cast(type, var) (*((type *) &var))
extern s32 D_80124580[];
extern void func_8010A3E8(void *, f32);
typedef struct {
    u32 top : 30;
    u32 flag : 1;
    u32 tail : 1;
} CtorTailSource;
typedef struct {
    u32 top : 15;
    u32 flag : 1;
    u32 tail : 16;
} CtorDestFlag;
typedef struct {
    u32 top : 11;
    u32 flag : 1;
    u32 tail : 20;
} CtorCopyFlag;
typedef struct {
    u32 node : 11;
    u32 id : 12;
    u32 rest : 9;
} ActorIdBits;
typedef struct {
    u8 state : 6;
    u8 rest : 2;
} ActorStateBits;
typedef struct {
    u8 rest : 4;
    u8 mode : 4;
} ActorModeBits;
typedef struct {
    u8 mode : 2;
    u8 rest : 6;
} ActorDrawBits;
typedef union {
    u8 raw;
    struct {
        u8 bit_7 : 1, bit_6 : 1, bit_5 : 1, bit_4 : 1, bit_3 : 1, bit_2 : 1, bit_1 : 1, bit_0 : 1;
    } bits;
} CtorFlagByte;
typedef union {
    u32 raw;
    u16 half[2];
    CtorFlagByte byte[4];
    ActorIdBits id;
} CtorFlagWord;
typedef struct {
    u8 *marker;
    f32 position[3];
    s32 entry;
    s32 render;
    u8 data18[0x1C];
    f32 value34;
    f32 scale;
    u8 data3C[0xC];
    f32 yaw;
    u8 data4C[8];
    f32 ideal_yaw;
    u32 data58;
    s8 color[3];
    u8 data5F[5];
    CtorFlagByte flags64[8];
    CtorFlagWord flags6C;
    CtorFlagByte flags70[4];
    CtorFlagWord flags74;
    CtorFlagByte flags78[4];
    u16 value7C;
    CtorFlagByte flags7E[2];
    u8 data80[0x14];
    CtorFlagWord flags94;
    u8 color98[4];
} CtorActor;
typedef struct {
    s16 marker_id, actor_id;
    u16 model_id;
    s16 state;
    u8 data08[0x10];
    u16 value18;
    u8 data1A[2];
    f32 scale;
    u8 data20[2];
    u16 value22;
    s32 flags;
    u8 data28[4];
    s32 *draw;
    u16 value30, value32;
    u8 data34[8];
    s32 flags3C;
    s32 value40;
} CtorInfo;
void func_800EE904(f32 *param_0, s32 param_1);
s32 func_80106790(s32);
typedef struct {
    u8 b70_a : 7;
    u8 f70_01 : 1;
    u8 b71_a : 2;
    u8 f71_20 : 1;
    u8 b71_b : 5;
    u8 b72;
    u8 b73_a : 4;
    u8 f73_08 : 1;
    u8 b73_b : 3;
} Bytes70;
typedef struct {
    u32 w70_a : 7;
    u32 f70_01 : 1;
    u32 w70_b : 2;
    u32 f71_20 : 1;
    u32 w70_c : 17;
    u32 f73_08 : 1;
    u32 w70_d : 3;
} Word70;
typedef struct {
    u8 b74_a : 6;
    u8 f74 : 1;
    u8 b74_b : 1;
    u8 b75;
    u8 b76;
    u8 b77_a : 1;
    u8 f77 : 1;
    u8 b77_b : 6;
} Bytes74;
typedef struct {
    u32 w74_a : 6;
    u32 f74 : 1;
    u32 w74_b : 1;
    u32 w75 : 16;
    u32 w77_a : 1;
    u32 f77 : 1;
    u32 w77_b : 6;
} Word74;
typedef struct {
    u8 b78[3];
    u8 f7B : 2;
    u8 b7B_a : 4;
    u8 g7B : 1;
    u8 b7B_b : 1;
} Bytes78;
typedef struct {
    u32 w78 : 24;
    u32 f7B : 2;
    u32 w7B_a : 4;
    u32 g7B : 1;
    u32 w7B_b : 1;
} Word78;
typedef struct {
    u8 pad00[0x70];
    union {
        Word70 w;
        Bytes70 b;
    } u70;
    union {
        Word74 w;
        Bytes74 b;
    } u74;
    union {
        Word78 w;
        Bytes78 b;
    } u78;
    u8 pad7C[0x1A];
    u16 f96 : 1;
    u16 u96_b : 15;
} ObjE1510;
typedef struct {
    u8 pad00[0x10];
    u32 unk10_a : 11;
    u32 unk10_19 : 11;
    u32 unk10_b : 5;
    u32 unk10_4 : 1;
    u32 unk10_3 : 2;
    u32 unk10_c : 2;
} NodeE1510;
extern void func_8010381C(void);
extern s32 func_800BF8E4(ObjE1510 *);
extern void _subaddiefade_entrypoint_9(ObjE1510 *, f32 *);
extern void _subaddiefade_entrypoint_11(ObjE1510 *, f32 *);
typedef struct {
    u8 pad00[0x48];
    f32 unk48;
    u8 pad4C[0x2A];
    u16 unk76 : 9;
    u16 unk76b : 7;
} ActorA8C;
typedef struct {
    u8 pad00[4];
    u32 unk04 : 31;
    u32 bit0 : 1;
    u8 pad08[8];
    u32 unk10_a : 11;
    u32 unk10_19 : 11;
    u32 unk10_b : 10;
} NodePropE1510;
extern NodePropE1510 *_gccubesearch_entrypoint_17(s32, s32);
typedef struct {
    u8 pad00[0x77];
    u8 unk77_a : 3;
    u8 unk77_4 : 1;
    u8 unk77_b : 4;
} ActorE1510;
typedef struct {
    u8 pad00[2];
    s16 unk2_a : 5;
    s16 index : 10;
    s16 unk2_b : 1;
    u8 pad04[8];
    f32 unk0C;
} PropE1510;
extern void _gspropctrl_entrypoint_9(void *, s32 *);
extern s32 _glsplinefind_entrypoint_4(s32 *, s32 *);
extern s32 _glsplinefind_entrypoint_2(s32 *);
extern PropE1510 *func_8010556C(ActorE1510 *);
extern s32 func_800D7520(s32);
extern f32 func_800C82CC(s32, f32 *);
void func_80108658(ObjE1510 *p, s32 flags, s32 flags2, NodeE1510 *np);
void func_80108A8C();
int func_80108B44(u16 *param_0, u32 param_1, int param_2);
int func_80108C90(s32 param_0, s32 param_1, s32 param_2, void *param_3);
ActorE1510 *func_80108DC0(s32 arg0, s32 *position, s32 yaw, s32 arg3, s32 arg4, s32 arg5);

int func_80107C20()
{
    return (int) D_80124580;
}

// Generic actor constructor: allocates an actor slot, creates its marker and fills it from an ActorInfo.
u8 *func_80107C2C(u8 *pos, s32 yaw, u8 *info, s32 entry, u8 *node)
{
    u8 *actor;
    s32 actor_index;
    s32 i;
    actor = func_80106668(&actor_index);
    ((CtorActor *) actor)->entry = entry;
    ((ActorStateBits *) (actor + 0x72))->state = *(s16 *) (info + 6);
    ((CtorActor *) actor)->position[0] = (f32) ((s32 *) pos)[0];
    ((CtorActor *) actor)->position[1] = (f32) ((s32 *) pos)[1];
    ((CtorActor *) actor)->position[2] = (f32) ((s32 *) pos)[2];
    ((CtorActor *) actor)->yaw = (f32) yaw;
    ((CtorActor *) actor)->ideal_yaw = (f32) yaw;
    ((CtorActor *) actor)->flags64[1].bits.bit_0 = 1;
    ((CtorActor *) actor)->scale = 1.0f;
    ((ActorIdBits *) (actor + 0x6C))->id = *(s16 *) (info + 2);
    ((CtorActor *) actor)->value34 = 0.f;
    ((ActorModeBits *) (actor + 0x77))->mode = 0;
    ((ActorDrawBits *) (actor + 0x7A))->mode = 1;
    ((CtorActor *) actor)->flags64[1].bits.bit_2 = 1;
    ((CtorActor *) actor)->value7C = (u16) ((CtorInfo *) info)->value18;
    if (((CtorInfo *) info)->scale != 0.0f) {
        ((CtorFlagByte *) (actor + 0x75))->bits.bit_4 = 1;
    } else {
        ((CtorFlagByte *) (actor + 0x75))->bits.bit_4 = 0;
    }
    ((CtorDestFlag *) (actor + 0x94))->flag = ((CtorCopyFlag *) (actor + 0x74))->flag;
    func_80100074(actor, 0, ((CtorInfo *) info)->value30);
    func_80100074(actor, 1, ((CtorInfo *) info)->value32);
    // Select the marker representation from the model asset type.
    if (((CtorInfo *) info)->model_id == 0xFFFF) {
        *(u8 **) ((s8 *) actor + 0) =
            func_800EBED4(pos, 1, ((CtorInfo *) info)->marker_id,
                          (((CtorInfo *) info)->flags & 0x400) ? 1 : 0);
    } else {
        *(u8 **) ((s8 *) actor + 0) = func_800EBED4(
            pos, (func_800D738C(((CtorInfo *) info)->model_id) == 7) ? 0 : 1,
            ((CtorInfo *) info)->marker_id, (((CtorInfo *) info)->flags & 0x400) ? 1 : 0);
    }
    ((CtorDestFlag *) (*(u8 **) actor + 0x18))->flag = 1;
    if (*(s32 **) ((s8 *) info + 0x2C) != 0) {
        *(s32 **) ((s8 *) *(u8 **) ((s8 *) actor + 0) + 8) = *(s32 **) ((s8 *) info + 0x2C);
    } else {
        *(s32 **) ((s8 *) *(u8 **) ((s8 *) actor + 0) + 8) = &func_80107C20;
    }
    func_800EC340(*(u8 **) ((s8 *) actor + 0), actor_index);
    func_800EC360(*(u8 **) ((s8 *) actor + 0), ((CtorInfo *) info)->model_id);
    func_800EC368(*(u8 **) ((s8 *) actor + 0), ((CtorInfo *) info)->value22);
    ((CtorFlagByte *) (actor + 0x75))->bits.bit_0 = 1;
    ((CtorFlagByte *) (actor + 0x75))->bits.bit_3 = *(u16 *) (actor + 0x74);
    // Transfer ActorInfo options into actor and marker bitfields; high-bit selectors are
    // passed to func_80102FA0 unchanged.
    if (func_80102FA0(info, 1) != 0) {
        _subaddieDll_entrypoint_1(actor);
    }
    if (func_80102FA0(info, 0x800000) != 0) {
        ((CtorFlagByte *) (actor + 0x71))->bits.bit_5 = 1;
    }
    if (func_80102FA0(info, 8) != 0) {
        ((CtorFlagByte *) (actor + 0x70))->bits.bit_0 = 1;
    }
    if (func_80102FA0(info, 0x100) != 0) {
        ((ActorModeBits *) (actor + 0x77))->mode = 1;
    }
    if (func_80102FA0(info, 0x200000) != 0) {
        ((CtorFlagByte *) (actor + 0x64))->bits.bit_1 = 1;
    }
    if (func_80102FA0(info, 0x04000000) != 0) {
        ((CtorFlagByte *) (actor + 0x71))->bits.bit_6 = 1;
    }
    if (func_80102FA0(info, 4) == 0) {
        ((CtorFlagByte *) (actor + 0x75))->bits.bit_1 = 1;
    }
    if (func_80102FA0(info, 0x100000) == 0) {
        ((CtorFlagByte *) (actor + 0x71))->bits.bit_4 = 1;
    }
    if (func_80102FA0(info, 0x08000000) != 0) {
        ((CtorFlagByte *) (actor + 0x71))->bits.bit_2 = 1;
    }
    if (func_80102FA0(info, 0x80000002) != 0) {
        *(u8 *) ((s8 *) *(u8 **) ((s8 *) actor + 0) + 0x2A) =
            (u8) (*(u8 *) ((s8 *) *(u8 **) ((s8 *) actor + 0) + 0x2A) & 0xFFFD);
    }
    if (func_80102FA0(info, 0x80000004) != 0) {
        ((CtorFlagByte *) (actor + 0x64))->bits.bit_7 = 1;
    }
    if (func_80102FA0(info, 0x80000008) != 0) {
        ((CtorFlagByte *) (actor + 0x64))->bits.bit_6 = 1;
    }
    if (func_80102FA0(info, 0x80000400) != 0) {
        ((CtorFlagByte *) (actor + 0x71))->bits.bit_1 = 1;
    }
    if (func_80102FA0(info, 0x80001000) != 0) {
        ((CtorFlagByte *) (actor + 0x71))->bits.bit_0 = 1;
    }
    if (func_80102FA0(info, 0x80002000) != 0) {
        ((CtorFlagByte *) (actor + 0x77))->bits.bit_5 = 1;
    }
    if (func_80102FA0(info, 0x80004000) != 0) {
        ((CtorFlagByte *) (actor + 0x7E))->bits.bit_5 = 1;
    }
    if (func_80102FA0(info, 0x80000100) != 0) {
        ((CtorFlagByte *) (actor + 0x74))->bits.bit_2 = 1;
    }
    if (func_80102FA0(info, 0x80100000) != 0) {
        ((CtorFlagByte *) (actor + 0x75))->bits.bit_7 = 1;
    }
    if (func_80102FA0(info, 0x80000001) != 0) {
        ((CtorFlagByte *) (actor + 0x64))->bits.bit_0 = 1;
    }
    if (func_80102FA0(info, 0x80000010) != 0) {
        ((CtorFlagByte *) (actor + 0x7B))->bits.bit_1 = 1;
    }
    if (func_80102FA0(info, 0x80400000) != 0) {
        ((CtorFlagByte *) (actor + 0x94))->bits.bit_7 = 1;
    }
    if (func_80102FA0(info, 0x80800000) != 0) {
        ((CtorFlagByte *) (actor + 0x94))->bits.bit_6 = 1;
    }
    if (func_80102FA0(info, 0x80000040) != 0) {
        ((CtorFlagByte *) (actor + 0x73))->bits.bit_2 = 1;
    }
    if (func_80102FA0(info, 0x80040000) != 0) {
        ((CtorFlagByte *) (actor + 0x79))->bits.bit_3 = 1;
    }
    if (func_80102FA0(info, 0x80200000) != 0) {
        ((CtorFlagByte *) (actor + 0x95))->bits.bit_1 = 1;
    }
    if (func_80102FA0(info, 0x84000000) != 0) {
        ((CtorFlagByte *) (actor + 0x96))->bits.bit_6 = 1;
    }
    if (func_80102FA0(info, 0x80000080) != 0) {
        ((CtorFlagByte *) (actor + 0x71))->bits.bit_3 = 1;
    }
    if (func_80102FA0(info, 0x82000000) != 0) {
        ((CtorDestFlag *) (actor + 0x94))->flag = 0;
    }
    func_8010A800(actor, 0);
    if (func_80102FA0(info, 0x800) != 0) {
        func_8010A800(actor, 1);
        func_8010A63C(actor);
    }
    if (func_80102FA0(info, 0x20000) != 0) {
        func_8010A800(actor, 2);
    } else if (func_80102FA0(info, 0x400000) != 0) {
        func_8010A800(actor, 3);
    } else if (func_80102FA0(info, 0x80008000) != 0) {
        func_8010A800(actor, 4);
    }
    if (func_80102FA0(info, 0x80000800) != 0) {
        ((CtorFlagByte *) (actor + 0x7E))->bits.bit_6 = 0;
    } else {
        ((CtorFlagByte *) (actor + 0x7E))->bits.bit_6 = 1;
    }
    if (func_80102FA0(info, 0x80000200) != 0) {
        ((CtorFlagByte *) (actor + 0x65))->bits.bit_0 = 0;
    } else {
        ((CtorFlagByte *) (actor + 0x65))->bits.bit_0 = 1;
    }
    // Placement node supplies an 11-bit node index and an extra flag.
    if (node != 0) {
        ((ActorIdBits *) (actor + 0x6C))->node = ((ActorIdBits *) (node + 0x10))->node;
        ((CtorFlagByte *) (actor + 0x73))->bits.bit_0 =
            ((CtorTailSource *) (node + 0x10))->flag;
    }
    func_80108658(actor, ((CtorInfo *) info)->flags, ((CtorInfo *) info)->flags3C,
                  node);
    // Install render and color defaults.
    ((CtorActor *) actor)->render = 0x4A0021;
    for (i = 0; i < 3; i++) {
        ((CtorActor *) actor)->color[i] = 0x63;
    }
    func_800F31FC(actor + 0x98, 0xFF, 0xFF, 0xFF, 0xFF);
    if (((CtorInfo *) info)->value40 != 0) {
        ((CtorFlagByte *) (actor + 0x74))->bits.bit_4 = 1;
    } else {
        ((CtorFlagByte *) (actor + 0x74))->bits.bit_4 = 0;
    }
    ((CtorFlagByte *) (actor + 0x74))->bits.bit_3 = 1;
    func_80102424(actor, (u32) *(u16 *) ((s8 *) actor + 0x72) >> 0xA);
    func_80103930(actor);
    func_8010A3E8(actor, 1.0f);
    func_80106E88(actor);
    func_80104F2C(actor, func_80102FA0(info, 0x40000000), func_80102FA0(info, 0x10));
    if (func_800BEC1C() != 0) {
        _subaddiezone_entrypoint_0(actor);
    }
    return actor;
}

s32 func_80108454(s32 actor_id, s32 pos, s32 yaw)
{
    func_80108C90(actor_id, pos, yaw, 0);
}

int func_80108474(s32 actor_id, s32 src_pos, s32 yaw)
{
    f32 pos[3];
    func_800EE904(pos, src_pos);
    func_80108C90(actor_id, pos, yaw, 0);
}

s32 func_801084B0(s32 actor_id, s32 **ref)
{
    s32 result;
    s32 saved;
    f32 pos[3];
    s32 *p;

    p = *ref;
    saved = *p;
    func_800EE904(pos, p + 1);
    result = func_80108C90(actor_id, pos, (s32) *(f32 *) ((s8 *) *ref + 0x48), 0);
    *ref = (s32 *) func_80106790(saved);
    return result;
}

s32 func_80108528(s32 actor_id, s32 src_pos, s32 yaw, s32 **ref)
{
    s32 saved;
    s32 result;

    saved = **ref;
    result = func_80108474(actor_id, src_pos, yaw);
    *ref = (s32 *) func_80106790(saved);
    return result;
}

void func_8010856C(s32 actor_id, u8 *src_pos, u8 *params)
{
    s8 unk_0[8];
    s32 unk_1;

    func_800EE904((s32 *) ((u8 *) &unk_1 - 4), src_pos);
    *(f32 *) ((u8 *) func_80108DC0(actor_id, (s32 *) ((u8 *) &unk_1 - 4),
                                   (s32) *(f32 *) (params + 4), 0, 0, 0) +
              0x44) = *(f32 *) params;
}

int func_801085CC(enum actor_e actor_id, s16 src_pos[3], s32 yaw)
{
    s32 pos[3];
    int i;
    for (i = 0; i < 3; i++) {
        pos[i] = src_pos[i];
    }

    return func_80108C90(actor_id, &pos, yaw, 0);
}

int func_80108618(s32 actor, s32 game_flag)
{
    // Matching: "| 0" needed for the match.
    if (func_800DA298(game_flag | 0)) {
        func_800FFAB0(actor);
        return 1;
    }
    return 0;
}

// Sets the f7B bits from the spawn flags and the placement node.
// Matching: the line breaks in this function are needed for the match.
void func_80108658(ObjE1510 *p, s32 flags, s32 flags2, NodeE1510 *np)
{
    p->f96 = 0;
    p->u74.b.f74 = p->f96; p->u74.b.f77 = p->f96; p->u78.b.f7B = p->f96;
    if (flags & 0x10000000) {
        p->u78.b.f7B = p->u78.b.f7B + 1;
        if (!p->u70.w.f71_20 && !p->u70.b.f70_01) {
            p->u70.b.f71_20 = 1;
        }
    }
    if (flags & 0x20000000) {
        p->u78.b.f7B = p->u78.b.f7B + 2;
        if (!p->u70.w.f71_20 && !p->u70.b.f70_01) {
            p->u70.b.f71_20 = 1;
        }
    }
    if (flags & 0x2000) {
        if (p->u78.b.f7B == 0) {
            p->u78.b.f7B = 1;
        }
        p->u74.b.f77 = 1;
    }
    if ((flags2 & 0x80010000) == 0x80010000) {
        p->u74.b.f74 = 1;
    }
    if ((flags2 & 0x80080000) == 0x80080000) {
        p->f96 = 1;
    }
    if (np != NULL) {
        if ((flags & 0x30002000) != 0) {
            if (np->unk10_3 != 0) {}  // Matching: empty block needed for the match.
        } else {
            p->u78.b.f7B = np->unk10_3;
            p->u74.b.f77 = np->unk10_4;
            if (p->u78.b.f7B != 0 || p->u74.w.f77 != 0) {
                if (!p->u70.w.f71_20 && !p->u70.b.f70_01) {
                    p->u70.b.f71_20 = 1;
                }
            }
        }
    }
    if (p->u78.b.f7B != 0 && p->u70.w.f73_08) {
        func_8010381C();
    }
}

// Matching: the line breaks in this function are needed for the match.
void func_801088A8(ObjE1510 *actor, s32 flags, s32 flags2, s32 node)
{
    actor->f96 = 0;
    actor->u74.b.f74 = actor->f96; actor->u74.b.f77 = actor->f96; actor->u78.b.f7B = actor->f96;
    if (func_800BF8E4(actor) != 0) {
        func_80108658(actor, flags, flags2, node);
    }
}

void func_80108944(ObjE1510 *dst, ObjE1510 *src)
{
    s32 mode;
    s32 extra;
    f32 tmp[3];

    extra = 0;
    mode = 0;
    switch (src->u78.b.f7B) {
        case 1:
            mode = 0x10000000;
            break;
        case 2:
            mode = 0x20000000;
            break;
        case 3:
            mode = 0x30000000;
    }
    if (src->u74.w.f77) {
        mode |= 0x2000;
    }
    if (src->u78.w.g7B) {
        dst->u78.b.g7B = 1;
        _subaddiefade_entrypoint_9(src, tmp);
        _subaddiefade_entrypoint_11(dst, tmp);
    }
    if (src->f96) {
        extra = 0x80080000;
    }
    func_80108658(dst, mode, extra, 0);
}

int func_80108A30(s32 actor_id, s32 *pos, s32 yaw, s32 unk_0)
{
    // Matching: "| 0" needed for the match.
    _chbaddiesetup_entrypoint_6(&func_80108A8C, actor_id | 0, pos[0], pos[1], pos[2],
                                yaw, unk_0);
}

void func_80108A8C(actor_id, x, y, z, yaw, unk_0) s32 actor_id;
s32 x;
s32 y;
s32 z;
s32 yaw;
s32 unk_0;
{
    f32 pos[3];
    f32 yaw_f;
    ActorA8C *actor;
    pos[0] = reinterpret_cast(f32, x);
    pos[1] = reinterpret_cast(f32, y);
    pos[2] = reinterpret_cast(f32, z);
    yaw_f = reinterpret_cast(f32, yaw);
    actor = func_80108474(actor_id, pos, (s32) yaw_f);
    if (actor != NULL) {
        actor->unk48 = yaw_f;
        actor->unk76 = unk_0;
    }
}

void func_80108B04(u8 **setup, s32 arg)
{
    u8 **setup_copy;
    setup_copy = setup;
    // Matching: if (1) wrapper needed for the match.
    if (1) {
        _chbaddiesetup_entrypoint_3(&func_80108B44, *setup_copy, arg,
                                    (u32) *(u16 *) (*setup + 0x12) >> 1);
    }
}

int func_80108B44(u16 *actor, u32 arg, int id)
{
    if (((u32) actor[9] >> 1) == id && func_801069A4(actor)) {
        func_8010114C(actor, 0x3D, arg);
    }
}

int func_80108B8C(u16 *actor, u32 arg, int id)
{
    if (((u32) actor[9] >> 1) == id && func_801069A4(actor)) {
        func_8010114C(actor, 0x59, arg);
    }
}

void func_80108BD4(u8 **setup, s32 arg)
{
    u8 **setup_copy;
    setup_copy = setup;
    // Matching: if (1) wrapper needed for the match.
    if (1) {
        _chbaddiesetup_entrypoint_3(&func_80108B8C, *setup_copy, arg,
                                    (u32) *(u16 *) (*setup + 0x12) >> 1);
    }
}

// Despawns every actor whose ActorInfo game flag is set.
void func_80108C14(void)
{
    s32 iter;
    u16 flag_id;
    s32 *actor;
    actor = func_801067C4(&iter);
    if (actor != 0) {
        do {
            // Matching: ^ 0 needed for the match.
            flag_id = *(u16 *) ((char *) func_80100368(actor) + 0x20) ^ 0;
            if ((flag_id != 0) && (func_800DA298(flag_id & 0xFFFF) != 0)) {
                func_800FFAB0(actor);
                func_800819B4(*(s32 *) ((char *) actor + 0x10));
            }
            actor = func_8010682C(&iter);
        } while (actor != 0);
    }
}

// Spawns an actor by id through the spawn callback (+0x38) of its descriptor.
int func_80108C90(s32 actor_id, s32 pos, s32 yaw, void *arg)
{
    s32 info_getter;
    s32 info;
    info_getter = _gemarkersDll_entrypoint_0(actor_id);
    if (!info_getter)
        return 0;
    info = ((s32(*)(void)) info_getter)();
    return ((s32(*)(s32, s32, s32, s32, void *)) *
            (s32 **) ((char *) info + 0x38))(pos, yaw, info, info_getter, arg);
}

NodePropE1510 *func_80108CF4(s32 node_id)
{
    NodePropE1510 *node;
    u32 first;
    u32 next_id;

    node = _gccubesearch_entrypoint_17(node_id, 0);
    first = 1;
    while ((node != NULL) && ((first == 1) || (node->bit0 == 1)) && (node->unk10_19 != 0)) {
        next_id = node->unk10_19;
        node = _gccubesearch_entrypoint_17(next_id, 0);
        first = 0;
    }
    return ((first == 1) || (node == NULL) || (node->bit0 == 1)) ? NULL : node;
}

// Spawns an actor by id and attaches it to a spline.
ActorE1510 *func_80108DC0(s32 actor_id, s32 *position, s32 yaw, s32 node_id, s32 unk_0, s32 arg)
{
    ActorE1510 *actor;
    s32 index;
    void *node;
    s32 node_pos[3];
    f32 pos_f[3];
    PropE1510 *prop;

    actor = func_80108C90(actor_id, position, yaw, arg);
    if (actor != NULL) {
        node = func_80108CF4(node_id);
        if (node != NULL) {
            _gspropctrl_entrypoint_9(node, node_pos);
            index = _glsplinefind_entrypoint_4(position, node_pos);
        } else {
            index = _glsplinefind_entrypoint_2(position);
        }
        if (index >= 0) {
            prop = func_8010556C(actor);
            prop->index = index;
            pos_f[0] = (f32) position[0];
            pos_f[1] = (f32) position[1];
            pos_f[2] = (f32) position[2];
            prop->unk0C = func_800C82CC(func_800D7520(index), pos_f);
            actor->unk77_4 = 1;
        }
    }
    return actor;
}

// TU-NOTE: the .data of this file is defined here in C (formerly asm/data/core2/1EE1510.data.s).
// Its tables point to functions of this file; IDO schedules some of them differently unless the
// tables are defined in the same unit. Values are taken from the ROM. D_80124580 is declared as
// s32[] to match the object (same address).
extern void func_80108F08();
s32 D_80124580[8] = {0x0, 0x0, 0x0, (u32) func_80108F08, 0x0, 0x0, 0x0, 0x0};
