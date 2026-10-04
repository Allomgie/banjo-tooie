#include "common.h"

typedef struct { s32 local_0; f32 local_1; /* Vertical offset used for the raised collision sweep. */ f32 local_2; /* Collision radius. */ u8 local_3[8]; s32 local_4; /* Collision filter, combined with 0x20020 by this routine. */ u8 local_5[4]; u8 *local_6; /* Last contact triangle. */ u8 local_7[0x24]; f32 local_8[3]; /* Last contact normal. */ u8 local_9[4]; s8 local_10; u8 local_11; u8 local_12; u8 local_13; } CollisionStateD4584;
extern f32 func_800C6784(s32);
extern void func_800C675C(s32, f32 *);
extern f32 mlAbsF(f32);
typedef struct { f32 local_0[3]; /* 0x00: corrected destination */ f32 local_1[3]; /* 0x0C: sweep start */ u8 *local_2; /* 0x18: contact triangle */ f32 local_3[3]; /* 0x1C: contact normal */ f32 local_4[3]; /* 0x28: vertically offset destination */ f32 local_5[3]; /* 0x34: vertically offset start */ s32 local_6; /* 0x40: preliminary sweep hit */ f32 local_7[3][3]; /* 0x44: preliminary collision data; row 0 is normal */ f32 local_9[3][3]; /* 0x68: contact triangle vertices */ s32 local_10; /* 0x8C: snapshot of the instance's contact-state flag */ } CollisionRecordD4584;
extern void func_800FAE44(void *, void *, f32, f32, s32, s32);
extern s32 func_800FABF4(void *, void *, void *, s32, f32, f32);
extern void *func_800C6B78(void *, void *, f32, void *, s32, s32);
extern void *func_800FB434(void *, void *, f32, f32, void *, s32, s32);
extern void func_800FAF78(void *, void *, void *, void *, void *);
extern void func_800F0524(void *, void *, void *);
extern void func_800F0410(void *, void *, void *);
extern s32 func_800F0CB4(void *, void *, void *, void *);
extern void func_800EE7F8(void *, void *);
extern void func_800EE780(void *, void *, void *);
extern void func_800EFB24(void *, void *, void *);
extern void func_800EF2A0(void *);
extern void func_800EF368(void *, f32);
extern void func_800EFA20(void *, void *, f32);
extern void func_800EFA4C(void *, f32, f32, f32);
extern s32 func_800EEF24(void *);
extern void func_800EF04C(void *, void *);
extern f32 func_800C673C(s32);
extern void func_800EA600();
extern void func_800C68AC(s32 param_0, s32 param_1);
extern void func_800C68CC();
extern void func_800C65E0();
extern void func_800EA614(void);
void func_800D4D5C();

void func_800D4400(CollisionStateD4584 *param_0, f32 *param_1, f32 *param_2)
{
    f32 pos[3];
    f32 ground;
    s32 wasOn;

    func_800D4D5C(param_1, param_0);
    ground = func_800C6784(param_0->local_0);
    func_800C675C(param_0->local_0, pos);
    wasOn = param_0->local_12;
    param_0->local_12 = 0;
    if (pos[1] < 0.432f) {
        return;
    }
    if (param_1[1] <= ground) {
        param_1[1] = ground;
        param_0->local_12 = 1;
        return;
    }
    if (wasOn == 0) {
        return;
    }
    if (!(param_2[1] < 0.0f)) {
        return;
    }
    if (pos[1] < 0.9f) {
        if (param_1[1] < ground + 30.0f) {
            param_1[1] = ground;
            param_0->local_12 = 1;
        }
    } else {
        if (param_1[1] < ground + 5.0f) {
            param_1[1] = ground;
            param_0->local_12 = 1;
        }
    }
}

int func_800D4534(s32 param_0, u8 *param_1)
{
  if (!param_1)
  {
    return 0;
  }
  func_800AAD28(param_0);
  return 1;
}

void func_800D4564()
{
    func_800AAD28();
}

void func_800D4584(CollisionStateD4584 *param_0, f32 *param_1, f32 *param_2, f32 *param_3) {
    f32 local_2[3];
    s32 local_3;
    f32 local_4[3];
    CollisionRecordD4584 *local_5;
    f32 local_6[3];
    f32 local_7[3];
    u8 *local_8;
    f32 local_9[3];
    s32 local_10;
    CollisionRecordD4584 local_0[5];
    f32 *local_11;
    CollisionRecordD4584 *local_12;
    f32 local_13;
    f32 local_14;
    f32 local_15[3];
    f32 local_16[3];
    s32 local_17;
    f32 local_18;
    s32 local_19;
    f32 local_20[3];
    f32 local_21[3];
    f32 local_22[3];
    s32 local_1; /* Retained stack home: removing it shifts IDO spill slots. */
    if (func_800DA298(0x664) == 0) {
        local_19 = param_0->local_4;
        func_800FAE44(param_1, local_4, (param_0->local_2), (param_0->local_1), 1, local_19 | 0x20020);
        for (local_10 = 0; local_10 < 5; local_10++) {
        local_12 = &local_0[local_10];
        if (local_10 != 0) {
            local_5 = local_12 - 1;
        } else {
            local_5 = NULL;
        }
        if (local_10 != 0) {
            func_800EE7F8(local_12, local_5);
            func_800EE7F8(local_12->local_1, local_5->local_1);
        } else {
            func_800EE7F8(local_12, param_2);
            func_800EE7F8(local_12->local_1, param_1);
        }
        func_800EE7F8(local_9, local_12);
        func_800EFB24(local_6, local_12, local_12->local_1);
        /* Long motion gets a preliminary sweep; reject outward-facing hits. */
        if ((local_6[0] * local_6[0] + local_6[1] * local_6[1] + local_6[2] * local_6[2]) > 100.0f) {
            local_14 = (local_12->local_0[1]);
            local_11 = local_12->local_7[0];
            local_3 = func_800FABF4(local_12->local_1, local_12, local_11, (local_19 | 0x20020), (param_0->local_2) - 1.0f, (param_0->local_1));
            (local_12->local_6) = local_3;
            if (local_3 != 0) {
                func_800EF2A0(local_6);
                local_18 = local_6[0] * local_12->local_7[0][0] + local_6[1] * local_12->local_7[0][1] + local_6[2] * local_12->local_7[0][2];
                if (local_18 > 0) {
                    (local_12->local_6) = 0;
                    func_800EE7F8(local_12, local_9);
                }
            }
            if ((local_12->local_6) != 0) {
                if ((local_12->local_7[0][1] >= 0) && (local_12->local_7[0][1] < 0.02f)) {
                    if (param_0->local_0 != 0) {
                        local_13 = func_800C673C(param_0->local_0) - 1.0f;
                        if (local_13 <= mlAbsF(local_14 - (local_12->local_0[1]))) {
                            (local_12->local_6) = func_800FABF4(local_12->local_1, local_12, local_11, (local_19 | 0x20020), ((param_0->local_2) - 1.0f), (param_0->local_1));
                            local_14 = (local_12->local_0[1]);
                        }
                    }
                    (local_12->local_0[1]) = local_14;
                }
            }
        } else {
            (local_12->local_6) = 0;
        }
        if ((param_0->local_0) != 0) {
            func_800D4400(param_0, local_12, param_3);
        }
        (local_12->local_10) = (s32) (param_0->local_12);
        local_12->local_5[0] = local_12->local_1[0];
        local_12->local_5[1] = local_12->local_1[1] + param_0->local_1;
        local_12->local_5[2] = local_12->local_1[2];
        local_12->local_4[0] = local_12->local_0[0];
        local_12->local_4[1] = local_12->local_0[1] + param_0->local_1;
        local_12->local_4[2] = local_12->local_0[2];
        local_8 = func_800C6B78(local_12->local_5, local_12->local_4, (param_0->local_2), local_12->local_3, 3, (local_19 | 0x20020));
        (local_12->local_2) = local_8;
        if (local_8 != NULL) {
            func_800D4564(param_0->local_7);
            (param_0->local_11) = (u8) ((param_0->local_11) + 1);
            (param_0->local_6) = (u8 *) (local_12->local_2);
            func_800EE7F8(param_0->local_8, local_12->local_3);
            /* Third-pass repeated contacts need a combined normal to avoid
             * oscillating between the same pair of surfaces. */
            if (local_10 == 2) {

                if (((local_12->local_2) == local_0[0].local_2) && ((local_12->local_2) != (local_5->local_2))) {
                    func_800EE780(local_6, local_12->local_3, local_5->local_3);
                    func_800EF2A0(local_6);
                    func_800EE7F8(local_12->local_3, local_6);
                }
            }
            if (local_10 == 2) {

                if ((local_12->local_2) == local_0[0].local_2) {
                    local_11 = local_12->local_9[0];
                    if (((local_12->local_2) == (local_5->local_2)) && (func_800D4534(local_11, (local_12->local_2)) != 0)) {
                        func_800F0524(local_6, local_11, local_12);
                        func_800EFB24(local_2, local_12, local_6);
                        func_800EF368(local_2, (param_0->local_2) + 1);
                        local_6[0] += local_2[0];
                        local_6[1] += local_2[1];
                        local_6[2] += local_2[2];
                        if (!((*(s32 *)((char *)((local_12->local_2)) + (8))) & 0x10000)) {
                            (local_12->local_2) = func_800FB434(local_6, local_12, (param_0->local_1), (param_0->local_2), local_12->local_3, 3, (local_19 | 0x20020));
                        } else {
                            func_800EE7F8(local_12, local_6);
                        }
                    }
                }
            }
            if (((local_12->local_10) == 0) && ((local_12->local_2) != NULL) && ((*(f32 *)((char *)(param_3) + (4))) < 0.0f)) {
                local_11 = local_12->local_9[0];
                if ((mlAbsF((local_12->local_3[1])) < 0.01f) && (func_800D4534(local_11, (local_12->local_2)) != 0)) {
                    func_800F0524(local_6, local_11, local_12);
                    func_800EFA20(local_2, local_12->local_3, (param_0->local_2) + 1);
                    func_800EE780(local_7, local_6, local_2);
                    (local_12->local_2) = func_800FB434(local_7, local_6, (param_0->local_1), (param_0->local_2), local_12->local_3, 3, (local_19 | 0x20020));
                    (local_12->local_0[0]) = local_6[0];
                    (local_12->local_0[2]) = local_6[2];
                }
            }
            /* Tooie-specific slope correction: test the vertical projection,
             * then push horizontally away from the contact if necessary. */
            if (0.6f < (local_12->local_3[1])) {
                local_11 = local_12->local_9[0];
                if ((param_0->local_2) != (param_0->local_1)) {
                    if (func_800D4534(local_11, (local_12->local_2)) != 0) {
                        local_17 = 1;
                        func_800EE7F8(local_15, local_12);
                        func_800EFA4C(local_16, 0.0f, 1.0f, 0.0f);
                        if ((func_800F0CB4(local_15, local_16, local_11, local_12->local_3) != 0) && (mlAbsF((local_12->local_0[1]) - local_15[1]) < 0.01f)) {
                            local_17 = 0;
                        }
                        if (local_17 != 0) {
                            func_800EE7F8(local_20, local_12->local_1);
                            func_800F0410(local_21, local_11, local_12->local_4);
                            func_800EFB24(local_22, local_20, local_21);
                            local_22[1] = 0.0f;
                            func_800EF2A0(local_22);
                            if (func_800EEF24(local_22) != 0) {
                                func_800EE7F8(local_12->local_3, local_22);
                                func_800EE7F8(local_12->local_1, param_1);
                                local_18 = (f32) (local_10 + 1);
                                func_800EF368(local_22, local_18 * local_18 * 2);
                                func_800EF04C(local_12, local_22);
                                func_800EF04C(local_12->local_4, local_22);
                            }
                        }
                    }
                }
            }
            if (func_800EEF24(local_12->local_3) != 0) {
                func_800FAF78(local_12->local_1, local_12, local_12->local_5, local_12->local_4, local_12->local_3);
            }
        } else {
            break;
        }
        }
        if ((local_10 == 5) && ((param_0->local_12) == 0) && ((param_0->local_6) != NULL) && ((*(f32 *)((char *)(param_2) + (4))) < (*(f32 *)((char *)(param_1) + (4))))) {
            (param_0->local_10) = 1;
        }
        if (local_10 == 5) {
            func_800EE7F8(param_2, local_4);
            return;
        }
        func_800EE7F8(param_2, local_12);
    }
    return;
}

void func_800D4D5C(param_0, param_1) s32 param_0; u8 * param_1;
{
    func_800EA600((*(s32 *)((s8 *)(param_1) + (0xC))));
    (*(s32 (**)(u8 *))((s8 *)(param_1) + (0x10)))(param_1);
    func_800C68AC((*(s32 *)((s8 *)(param_1) + (0))), param_0);
    func_800C68CC((*(s32 *)((s8 *)(param_1) + (0))), (*(s32 *)((s8 *)(param_1) + (0x14))));
    func_800C65E0((*(s32 *)((s8 *)(param_1) + (0))));
    func_800EA614();
}
