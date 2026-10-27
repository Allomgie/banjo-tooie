#include "common.h"

typedef struct { u32 local_0:8; u32 local_1:13; s32 local_2:10; u32 local_3:1; f32 local_4; f32 local_5; f32 local_6; f32 local_7; f32 local_8; f32 local_9; f32 local_10; f32 local_11; u32 local_12:15; u32 pad_0:1; u32 local_13:1; u32 local_14:1; u32 local_15:1; u32 local_16:4; u32 local_17:3; u32 pad_1:6; u16 local_18:3; u16 local_24:1; u16 local_25:2; u16 local_19:8; u16 pad_3:2; u32 local_20:9; u32 local_21:1; u32 local_22:6; f32 local_23; f32 local_26; f32 local_27; f32 local_28; f32 local_29; u32 local_30:9; u32 local_31:9; u32 local_32:9; u32 pad_4:5; u32 local_33:1; u32 local_34:2; u32 local_35:9; u32 pad_5:20; } SplineNodeState;
typedef struct { f32 local_0; union { struct { u16 local_0:11; u16 pad_0:1; u16 local_1:2; u16 local_2:2; u32 local_3:9; u32 local_4:3; u32 local_5:3; u32 pad_1:1; } local_0; struct { u32 local_0:1; u32 local_1:15; u32 local_2:8; u32 local_3:4; u32 pad_0:4; } local_1; u16 local_2[2]; } local_1; u32 local_2:10; u32 local_3:11; u32 local_4:1; u32 local_5:1; u32 local_6:1; u32 pad_0:8; union { struct { u32 local_0:9; u32 local_1:11; u32 local_2:11; u32 local_3:1; } local_0; struct { u32 local_0:8; u32 pad_0:2; u32 local_1:1; u32 local_2:8; u32 pad_1:13; } local_1; } local_7; union { struct { u32 local_0:11; u32 pad_0:12; u32 local_1:1; u32 local_2:1; u32 pad_1:3; u32 local_3:1; u32 pad_2:3; } local_0; struct { u32 pad_0:22; u32 local_0:6; u32 pad_1:4; } local_1; } local_8; } SplineNode;
typedef struct { s32 local_0; SplineNode local_1[1]; } SplineNodeList;
typedef struct { u8 pad_0[0x190]; f32 local_0; } SplineNodeContext;
typedef struct { u8 pad_0[0x78]; u16 pad_1:14; u16 local_0:2; u32 pad_2:16; } SplineNodeActorFlags;
typedef struct { f32 local_0; f32 local_1; } SplineNodeActorMotionData;
extern void *func_80105494(Actor *);
extern s32 _glsplinefuncs_entrypoint_0(s32, s32 *, f32 *, f32 *, s32, f32 *, f32 *);
extern void _glsplinenode_entrypoint_0();
extern s16 D_808009B0_glsplinenode[];
extern void *func_80104248(Actor *);
extern void *func_801042B8(Actor *);
extern void anctrl_reset(void *);
extern void anctrl_setIndex(void *, s32);
extern void anctrl_setDuration(void *, f32);
extern void anctrl_start(void *);
extern void func_8008B188(void *, s32);
extern void func_800D7754(Actor *, s32);
extern void func_80101D4C(Actor *);
extern void func_80101D7C(Actor *);
extern void func_800DA3B8(s32, s32);
extern void func_800C04C8(s32, s32, s32, s32, void (*)());
extern void func_800EE7F8(f32 *, f32 *);
extern f32 func_800D7708(s32, f32, s32);
extern f32 func_800C7AE4(s32, f32, f32);
typedef union { Actor *a; s32 w; } SplineActorArg;

s32 glsplinenode_entrypoint_0(s32 param_0, s32 param_1, s32 param_2) {
    func_800D035C(1);
}

s32 glsplinenode_entrypoint_1(SplineNodeContext *param_0, SplineActorArg param_1, SplineNode *param_2, SplineNodeList *param_3)
{
    SplineNodeState *local_0;
    s32 local_1;
    s32 local_2;
    s32 local_11;
    s32 local_12 = 1;
    f32 local_3;
    f32 local_4[3];
    f32 local_5;
    f32 local_6;
    void *local_7;
    SplineNode *local_8;
    SplineNode *local_9;

    local_0 = func_80105494(param_1.a);
    local_1 = 0;
    if (param_2->local_7.local_0.local_3) {
        switch (param_2->local_1.local_0.local_5) {
        case 0:
            if (param_2->local_7.local_1.local_0) {
                local_0->local_0 = param_2->local_7.local_1.local_0;
                local_0->local_4 = param_0->local_0;
                local_0->local_1 = 0;
                local_0->local_5 = 0.0f;
            }
            break;
        case 7:
            if (param_2->local_8.local_0.local_3 == 1) {
                ((SplineNodeActorFlags *)param_1.a)->local_0 = param_2->local_1.local_1.local_0 == 0 ? 2 : (local_12 == param_2->local_1.local_1.local_0 ? 1 : 0);
                if (param_2->local_1.local_1.local_1) {
                    ((SplineNodeActorMotionData *)param_1.a->actorData)->local_0 = param_2->local_1.local_1.local_1 * 0.25f;
                } else {
                    ((SplineNodeActorMotionData *)param_1.a->actorData)->local_0 = 0.0f;
                }
                ((SplineNodeActorMotionData *)param_1.a->actorData)->local_1 = 0.0f;
            }
            if (param_2->local_7.local_1.local_1 == 1) {
                func_800C04C8(param_2->local_7.local_1.local_2, param_2->local_8.local_1.local_0,
                    param_2->local_1.local_1.local_2, param_2->local_1.local_1.local_3,
                    _glsplinenode_entrypoint_0);
            }
            break;
        case 6:
            func_800DA3B8(param_2->local_1.local_2[0], 1);
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            break;
        }
        if (param_2->local_7.local_0.local_2) {
            local_11 = _glsplinefuncs_entrypoint_0(param_2->local_7.local_0.local_2,
                &local_2, &local_3, local_4, local_0->local_2, &local_5, &local_6);
            local_1 = 2;
            local_0->local_2 = local_2;
            local_0->local_6 = local_3;
            func_800EE7F8(param_1.a->position, local_4);
            if (local_11) {
                if (local_5 != -9999.0f) {
                    param_1.a->rotation[1] = local_5;
                    param_1.a->unk54 = param_1.a->rotation[1];
                }
                if (local_6 != -9999.0f) {
                    param_1.a->rotation[0] = local_6;
                    param_1.a->unk50 = param_1.a->rotation[0];
                }
            }
        }
    } else {
        if (param_2->local_6) {
            if (param_2->local_8.local_0.local_2) {
                local_0->local_16 = param_2->local_7.local_0.local_2 - 0x69;
            } else {
                local_0->local_11 = (f32)param_2->local_7.local_0.local_2 / 4;
            }
        }
        if (param_2->local_4) {
            local_7 = func_80104248(param_1.a);
            local_0->local_10 = (f32)param_2->local_3 / 4;
            local_0->local_12 = _seqdat_entrypoint_0(param_2->local_2, 0);
            if (!local_7) {
                local_7 = func_801042B8(param_1.a);
                anctrl_reset(local_7);
            }
            anctrl_setIndex(local_7, local_0->local_12);
            anctrl_setDuration(local_7, local_0->local_10);
            func_8008B188(local_7, 1);
            if (local_7) {
                anctrl_start(local_7);
            }
        }
        func_800D7754(param_1.a, param_2->local_1.local_0.local_4);
        switch (param_2->local_1.local_0.local_5) {
        case 2:
            local_0->local_25 = 0;
            if (local_0->local_8 < 0.0f) {
                local_0->local_8 = -local_0->local_8;
            } else {
                local_0->local_8 = local_0->local_8;
            }
            func_80101D4C(param_1.a);
            break;
        case 3:
            local_0->local_25 = 0;
            if (local_0->local_8 < 0.0f) {
                local_0->local_8 = local_0->local_8;
            } else {
                local_0->local_8 = -local_0->local_8;
            }
            func_80101D4C(param_1.a);
            break;
        case 4:
            local_0->local_25 = 1;
            if (local_0->local_8 < 0.0f) {
                local_0->local_8 = -local_0->local_8;
            } else {
                local_0->local_8 = local_0->local_8;
            }
            func_80101D7C(param_1.a);
            break;
        case 5:
            local_0->local_25 = 1;
            if (local_0->local_8 < 0.0f) {
                local_0->local_8 = local_0->local_8;
            } else {
                local_0->local_8 = -local_0->local_8;
            }
            func_80101D7C(param_1.a);
            break;
        case 6:
            local_0->local_25 = 2;
            break;
        }
        if (param_2->local_1.local_0.local_1) {
            local_0->local_18 = D_808009B0_glsplinenode[param_2->local_1.local_0.local_1];
        }
        if (local_0->local_24 != param_2->local_8.local_0.local_1) {
            local_0->local_24 = param_2->local_8.local_0.local_1;
        }
        if (param_2->local_5) {
            local_0->local_8 = func_800D7708(local_0->local_2, local_0->local_6, param_2->local_7.local_0.local_1);
        }
        if (param_2->local_1.local_0.local_0) {
            local_9 = param_3->local_0 + &param_3->local_1[0];
            for (local_8 = &param_3->local_1[0];
                 local_8->local_8.local_0.local_0 != param_2->local_1.local_0.local_0 && local_8 < local_9;
                 local_8++) {
            }
            local_0->local_34 = param_2->local_1.local_0.local_2;
            local_0->local_33 = 0;
            local_0->local_28 = param_2->local_0;
            local_0->local_29 = local_8->local_0;
            if (param_2->local_1.local_0.local_2 & 1) {
                local_0->local_31 = param_2->local_7.local_0.local_0;
                local_0->local_30 = local_8->local_7.local_0.local_0;
                local_0->local_32 = param_2->local_1.local_0.local_3;
                local_0->local_35 = local_8->local_1.local_0.local_3;
                param_1.a->rotation[1] = param_1.a->unk54 = local_0->local_31;
                param_1.a->rotation[0] = param_1.a->unk50 = local_0->local_32;
            }
            if (param_2->local_1.local_0.local_2 & 2) {
                local_0->local_26 = local_0->local_8;
                local_0->local_27 = func_800C7AE4(func_800D7520(local_0->local_2), local_8->local_0, 1.0f) / ((f32)local_8->local_7.local_0.local_1 / 4);
            }
        }
        if (!local_0->local_15 && !local_0->local_22 && !local_0->local_17) {
            if (local_0->local_13) {
                param_1.a->unk54 = param_2->local_7.local_0.local_0;
            }
            if (local_0->local_14) {
                param_1.a->unk50 = param_2->local_1.local_0.local_3;
            }
        }
    }
    return local_1;
}
