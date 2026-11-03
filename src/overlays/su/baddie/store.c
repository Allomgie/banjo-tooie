#include "common.h"

extern Actor *func_801067C4(int *);
extern Actor *func_8010682C(int *);
extern u8 *func_80108474();
void typedef struct {
    u8 pad[0x70];
    u32 pad_a : 14;
    u32 f17 : 1;
    u32 pad_b : 17;
} Bit70;
extern s32 func_800DB9B0();
extern s32 func_80102F74();
extern s32 func_800EA05C();
extern s32 _glcutDll_entrypoint_8();
extern s32 func_8001B7B8();
typedef struct {
    u8 pad_0[0x75];
    u8 p0 : 5;
    u8 b2 : 1;
    u8 p1 : 2;
} SSB75;
typedef struct {
    u8 pad_0[0x64];
    u8 p0 : 5;
    u8 b2 : 1;
    u8 p1 : 2;
} SSB64;
typedef struct {
    u8 pad_0[0x73];
    u8 p0 : 4;
    u8 b3 : 1;
    u8 p1 : 3;
} SSB73;
typedef struct {
    u8 pad_0[0x74];
    u8 b7 : 1;
    u8 p0 : 7;
} SSB74;
typedef struct {
    u8 pad_0[0xAC];
    u16 b15 : 1;
    u16 v : 15;
} SSHAC;
typedef struct {
    u8 pad_0[0x9C];
    u8 b7 : 1;
    u8 b6 : 1;
    u8 b5 : 1;
    u8 p0 : 5;
} SSB9C;
typedef struct {
    u8 pad_0[0x9F];
    u8 p0 : 6;
    u8 b1 : 1;
    u8 p1 : 1;
} SSB9F;
typedef struct {
    u8 pad_0[0xAE];
    u8 b7 : 1;
    u8 f : 6;
    u8 b0 : 1;
} SSBAE;
typedef struct {
    u8 pad_0[0xAF];
    u8 b7 : 1;
    u8 p0 : 7;
} SSBAF;
typedef struct {
    u8 pad_0[0x9E];
    u16 idx : 14;
    u16 p0 : 2;
} SSH9E;
typedef struct {
    u8 pad_0[0x9D];
    u8 p0 : 5;
    u8 t : 3;
} SSB9D;
typedef struct {
    u8 pad_0[0xAC];
    u8 b7 : 1;
    u8 p0 : 7;
} SSBAC;
typedef struct {
    u8 pad_0[0x28];
    u32 p0 : 21;
    u32 b10 : 1;
    u32 b9 : 1;
    u32 f : 8;
    u32 b0 : 1;
} SSU28;
typedef struct {
    u8 pad_0[0x12];
    u16 v : 15;
    u16 b0 : 1;
} SSH12;
typedef struct {
    u8 pad_0[0x9C];
    u32 p0 : 3;
    u32 f : 10;
    u32 p1 : 19;
} SSW9C;
typedef struct {
    u8 pad_0[0x94];
    u32 p0 : 2;
    u32 f : 10;
    u32 p1 : 20;
} SSA94;
extern f32 func_8008B2AC();
extern f32 func_8008B2D4();
extern f32 anctrl_getAnimTimer();
extern void func_80105634();
extern void func_80106EE0();
extern u8 *func_8010556C();
extern u8 *func_80106E88();
extern void rare_memcpy(void *, void *, s32);
extern void func_8001B754();
extern s32 func_8001B668(s32, s32);
extern u8 *func_8001B798();
extern u8 *func_80104248();
extern u8 *func_801042B8();
extern void anctrl_setPlaybackType();
extern void anctrl_setIndex();
extern void func_8008B188();
extern void anctrl_setSmoothTransition();
extern void anctrl_setDuration(u8 *, f32);
extern f32 func_800F0D50(f32, f32, f32);
extern void func_8008B10C(u8 *, f32);
extern void anctrl_setSubrange(u8 *, f32, f32);
extern void anctrl_start();
extern void func_8008B2DC(u8 *, f32);
extern void func_80104328();
extern void func_8010A654();
extern void func_80103014();
typedef struct {
    u8 p[0x12];
    u16 hi : 15;
    u16 lo : 1;
} SB12;
typedef struct {
    u8 p[0x13];
    u8 pad : 7;
    u8 b : 1;
} SB13;
typedef struct {
    u8 p[0x1B];
    u8 pad : 7;
    u8 b : 1;
} SB1B;
typedef struct {
    u8 p[0x28];
    u32 q : 16;
    u32 pad : 5;
    u32 b2 : 1;
    u32 b1 : 1;
    u32 b0 : 1;
    u32 r : 8;
} SB2A;
typedef struct {
    u8 p[0x28];
    u32 q : 16;
    u32 pad : 7;
    u32 f : 8;
    u32 lo : 1;
} SB2AH;
typedef struct {
    u8 p[0x7E];
    u8 b7 : 1;
    u8 b6 : 1;
    u8 b5 : 1;
    u8 b4 : 1;
    u8 rest : 4;
} SB7E;
typedef struct {
    u8 p[0xAE];
    u16 neg : 1;
    u16 rest : 15;
} SBAE;
typedef struct {
    u8 p[0x9C];
    u16 hi : 13;
    u16 pb : 3;
} SB9C;
typedef struct {
    u8 p[0xAE];
    u8 r : 7;
    u8 b0 : 1;
    u8 b7 : 1;
    u8 r2 : 7;
} SRAEB;
int func_80800330_subaddiestore();
s32 func_808003AC_subaddiestore();
s32 *func_808004FC_subaddiestore();
int func_80800AD8_subaddiestore();
void func_80800B24_subaddiestore();
s32 func_80800F98_subaddiestore();
u8 *func_80800FD0_subaddiestore();
int func_80801054_subaddiestore();

u8 *subaddiestore_entrypoint_0(u8 *param_0, u8 *param_1)
{
    s32 local_3;
    s32 local_4;
    u8 *local_5;
    u8 *local_6;
    Actor *local_7;
    s32 pad;
    s32 local_0;
    s32 local_1;
    int local_2;

    local_3 = func_808003AC_subaddiestore(&local_0, &local_1);
    local_4 = param_1 - param_0;
    param_0 = heap_realloc(param_0, local_4 + local_3);
    local_5 = param_0 + local_4;
    *(s16 *) (local_5 + 0) = local_0;
    *(s16 *) (local_5 + 2) = local_1;
    local_5 += 4;
    for (local_7 = func_801067C4(&local_2); local_7; local_7 = func_8010682C(&local_2)) {
        local_5 = func_808004FC_subaddiestore(local_7, local_5);
    }
    local_6 = local_5;
    for (local_7 = func_801067C4(&local_2); local_7; local_7 = func_8010682C(&local_2)) {
        local_6 = func_80800AD8_subaddiestore(local_7, local_6);
    }
    return param_0;
}

subaddiestore_entrypoint_1(s32 param_0, s16 *param_1)
{
    u8 *local_0;
    u8 *local_1;
    s32 local_3;
    s32 local_2;
    s32 local_4;
    s16 *local_5 = param_1;

    for (local_0 = func_801067C4(&local_2); local_0 != 0; local_0 = func_8010682C(&local_2)) {
        if (1)
            if ((*(u32 *) (local_0 + 0x6C) >> 21) != 0) {
                local_3 = func_80801054_subaddiestore(param_1, local_0, &local_1);
                if (local_3 != 0) {
                    if (local_3 == 1 && (!((Bit70 *) local_1)->f17 || _glcutDll_entrypoint_1())) {
                        func_80800B24_subaddiestore(local_1, local_0);
                    }
                } else if (!((Bit70 *) local_0)->f17 && func_80102F74(local_0, 0x80000) == 0) {
                    func_800FFAB0(local_0);
                }
            }
    }
    local_1 = (u8 *) param_1 + 4;
    for (local_4 = 0; local_4 < *local_5; local_4++) {
        if (func_80800330_subaddiestore(local_1)) {
            func_80800B24_subaddiestore(
                local_1, func_80108474((*(u32 *) (local_1 + 0x6C) << 11) >> 20, local_1 + 4,
                                       (s32) *(f32 *) (local_1 + 0x48)));
        }
        local_1 = func_80800FD0_subaddiestore(local_1);
    }
}

s32 func_80800260_subaddiestore(param_0)
Actor *param_0;
{
    s32 local_1;
    if (param_0->unk0 == 0) {
        return 0;
    }
    if (!param_0->unk74_17 || param_0->unk64_17) {
        return 0;
    }
    if (((Bit70 *) param_0)->f17) {
        local_1 = func_800DB9B0() && _glcutDll_entrypoint_8() != func_800EA05C();
        return local_1 ? 1 : 0;
    }
    if (func_80102F74(param_0, 0x80) != 0) {
        return 2;
    }
    if (param_0) {
    }
    return 1;
}

int func_80800330_subaddiestore(param_0)
Actor *param_0;
{
    u32 local_0;
    int local_2;
    Actor *local_1;

    local_0 = param_0->pad6C_21;
    if (local_0 == 0) {
        return 1;
    }
    for (local_1 = func_801067C4(&local_2); local_1; local_1 = func_8010682C(&local_2)) {
        if (local_0 == local_1->pad6C_21) {
            return 0;
        }
    }
    return 1;
}

s32 func_808003AC_subaddiestore(param_0, param_1)
s32 *param_0;
s32 *param_1;
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    Actor *local_4;
    s32 local_5;
    int local_3;
    s32 j;

    local_0 = 0;
    local_1 = 0;
    local_2 = 4;
    for (local_4 = func_801067C4(&local_3); local_4; local_4 = func_8010682C(&local_3)) {
        local_5 = 0;
        switch (func_80800260_subaddiestore(local_4)) {
            case 0:
                break;
            case 1:
                local_2 += 0xB0;
                if (local_4->unk7C_0) {
                    local_2 += 0x48;
                }
                if ((*(u32 *) ((u8 *) local_4 + 0x94) << 2) >> 22) {
                    local_2 += 0x18;
                }
                for (j = 0; j < 3; j++) {
                    if (((s16 *) ((u8 *) local_4 + 0x82))[j]) {
                        local_5 = 1;
                        local_2 += func_8001B7B8(((s16 *) ((u8 *) local_4 + 0x82))[j]);
                    }
                }
                if (local_5) {
                    local_2 += 0xC;
                }
                local_0++;
                break;
            case 2:
                local_2 += 4;
                local_1++;
        }
    }
    *param_0 = local_0;
    *param_1 = local_1;
    return local_2;
}

s32 *func_808004FC_subaddiestore(param_0, param_1)
Actor *param_0;
u8 *param_1;
{
    s32 u0;
    s32 n;
    f32 sp5C;
    f32 sp58;
    s32 w0;
    s32 *var_s4;
    s32 *var_s2;
    s32 var_s3;
    s32 h;

    if (func_80800260_subaddiestore() != 1) {
        return (s32 *) param_1;
    }
    rare_memcpy(param_1, param_0, 0x9C);
    *(s16 *) (param_1 + 0x60) = 0;
    ((SSB75 *) param_1)->b2 = 0;
    ((SSB64 *) param_1)->b2 = 0;
    *(u8 *) (param_1 + 0x5F) = 0;
    *(s32 *) (param_1 + 0x40) = 0;
    *(s32 *) (param_1 + 0x3C) = 0;
    *(s16 *) (param_1 + 0x90) = 0;
    *(s16 *) (param_1 + 0x80) = 0;
    *(s16 *) (param_1 + 0x8E) = 0;
    ((SSB73 *) param_1)->b3 = 0;
    ((SSB74 *) param_1)->b7 = 0;
    ((SSW9C *) param_1)->f = param_0->unk0->unk24 >> 22;
    ((SSHAC *) param_1)->v = ((SSH12 *) param_0->unk0)->v;
    ((SSB9C *) param_1)->b6 = ((SSU28 *) param_0->unk0)->b10;
    ((SSB9C *) param_1)->b5 = ((SSU28 *) param_0->unk0)->b9;
    h = func_8010A698(param_0);
    ((SSB9F *) param_1)->b1 = h;
    ((SSBAE *) param_1)->f = ((SSU28 *) param_0->unk0)->f;
    h = param_0->unk0->unk10 & 1;
    ((SSBAE *) param_1)->b0 = h;
    ((SSBAF *) param_1)->b7 = param_0->unk0->unk18;
    if (*(s16 *) ((u8 *) param_0 + 0x8C) != 0) {
        h = func_80104248(param_0);
        ((SSH9E *) param_1)->idx = anctrl_getIndex(h);
        ((SSB9D *) param_1)->t = anctrl_getPlaybackType(h);
        ((SSBAC *) param_1)->b7 = func_8008B28C(h);
        ((SSB9C *) param_1)->b7 = func_8008B29C(h);
        *(f32 *) (param_1 + 0xA0) = func_8008B2AC(h);
        func_8008B238(h, &sp5C, &sp58);
        *(s16 *) (param_1 + 0xA8) = (u32) (sp5C * 32768);
        *(s16 *) (param_1 + 0xAA) = (u32) (sp58 * 32768);
        *(s16 *) (param_1 + 0xA4) = (u32) (anctrl_getAnimTimer(h) * 32768);
        *(s16 *) (param_1 + 0xA6) = (u32) (func_8008B2D4(h) * 32768);
    }
    if (*(s16 *) ((u8 *) param_0 + 0x8C) != 0) {
        ((SSBAE *) param_1)->b7 = 1;
    } else {
        ((SSBAE *) param_1)->b7 = 0;
    }
    *(s16 *) (param_1 + 0x8C) = 0;
    *(s32 *) param_1 = 0;
    var_s4 = (s32 *) (param_1 + 0xB0);
    if (param_0->unk7C_0) {
        w0 = (s32) var_s4;
        rare_memcpy(var_s4, func_80105494(param_0), 0x48);
        var_s4 = (s32 *) (w0 + 0x48);
    }
    w0 = (s32) var_s4;
    if (((SSA94 *) param_0)->f != 0) {
        rare_memcpy(var_s4, func_80106F30(param_0), 0x18);
        var_s4 = (s32 *) (w0 + 0x18);
    }
    if (func_80800F98_subaddiestore(param_0) != 0) {
        var_s2 = var_s4;
        var_s4 = (s32 *) ((u8 *) var_s4 + 0xC);
        for (var_s3 = 0; var_s3 < 3; var_s3++) {
            if (((s16 *) ((u8 *) param_0 + 0x82))[var_s3] != 0) {
                n = func_8001B7B8(((s16 *) ((u8 *) param_0 + 0x82))[var_s3]);
                var_s2[var_s3] = n;
                rare_memcpy(var_s4, func_8001B798(((s16 *) ((u8 *) param_0 + 0x82))[var_s3]), n);
                var_s4 = (s32 *) ((u8 *) var_s4 + n);
            } else {
                var_s2[var_s3] = 0;
            }
        }
    }
    return var_s4;
}

int func_80800AD8_subaddiestore(param_0, param_1)
Actor *param_0;
u32 *param_1;
{
    if (func_80800260_subaddiestore() != 2) {
        return param_1;
    }
    param_1[0] = *(u32 *) ((char *) param_0 + 0x6C) >> 21;
    return param_1 + 1;
}

void func_80800B24_subaddiestore(param_0, param_1) u8 *param_0;
u8 *param_1;
{
    u8 *s0;
    u8 *s5;
    u8 *s1;
    u8 *s2;
    u8 *ptr;
    s32 s3;
    s32 s4;
    s32 size;
    s32 value;
    f32 f12;
    f32 f1;
    f32 f14;
    f32 f0;
    f32 scale;

    s0 = param_0 + 0xB0;
    s5 = s0;

    *(s32 *) (param_0 + 0) = *(s32 *) (param_1 + 0);
    *(s16 *) (param_0 + 0x8C) = *(s16 *) (param_1 + 0x8C);

    if ((*(u32 *) (param_1 + 0x7C) & 0xFFF) != 0) {
        func_80105634(param_1);
    }

    if ((*(u32 *) (param_1 + 0x94) << 2) >> 22 != 0) {
        func_80106EE0(param_1);
    }

    if ((*(u32 *) (param_0 + 0x7C) & 0xFFF) != 0) {
        s2 = s5;
        *(u16 *) (param_0 + 0x7E) &= 0xF000;
        ptr = func_8010556C(param_0);
        rare_memcpy(ptr, s5, 0x48);
        s5 = s2 + 0x48;
    }

    if ((*(u32 *) (param_0 + 0x94) << 2) >> 22 != 0) {
        s0 = s5;
        *(u16 *) (param_0 + 0x94) &= 0xC00F;
        ptr = func_80106E88(param_0);
        rare_memcpy(ptr, s5, 0x18);
        s5 = s0 + 0x18;
    }

    if (func_80800F98_subaddiestore(param_0)) {
        s1 = s5;
        s5 += 0xC;
        for (s3 = 0; s3 < 3; s3++) {
            if (((s16 *) (param_1 + 0x82))[s3] != 0) {
                func_8001B754(((s16 *) (param_1 + 0x82))[s3]);
                ((s16 *) (param_1 + 0x82))[s3] = 0;
            }
            if (((s32 *) s1)[s3] > 0) {
                ((s16 *) (param_0 + 0x82))[s3] = func_8001B668(0, ((s32 *) s1)[s3]);
                rare_memcpy(func_8001B798(((s16 *) (param_0 + 0x82))[s3]), s5, ((s32 *) s1)[s3]);
                s5 = ((s32 *) s1)[s3] + s5;
            }
        }
    }

    rare_memcpy(param_1, param_0, 0x9C);

    if ((*(s16 *) (param_1 + 0x8C) != 0) || ((SBAE *) param_0)->neg) {
        s0 = func_80104248(param_1);

        if (((SBAE *) param_0)->neg) {
            if (s0 == 0) {
                s0 = func_801042B8(param_1);
            }

            if (((SB9C *) param_0)->pb) {
                anctrl_setPlaybackType(s0, ((SB9C *) param_0)->pb);
            }

            anctrl_setIndex(s0, (u32) *(u16 *) (param_0 + 0x9E) >> 2);
            func_8008B188(s0, *(u32 *) (param_0 + 0xAC) >> 31);
            anctrl_setSmoothTransition(s0, *(u32 *) (param_0 + 0x9C) >> 31);
            anctrl_setDuration(s0, *(f32 *) (param_0 + 0xA0));

            scale = 0.000030517578125f;
            f14 = (f32) *(u16 *) (param_0 + 0xA8) * scale;
            f0 = (f32) *(u16 *) (param_0 + 0xAA) * scale;
            f12 = (f32) *(u16 *) (param_0 + 0xA4) * scale;
            f12 = func_800F0D50(f12, f14, f0);
            f1 = (f32) *(u16 *) (param_0 + 0xA6) * scale;
            f1 = func_800F0D50(f1, f14, f0);

            func_8008B10C(s0, f12);
            anctrl_setSubrange(s0, f14, f0);
            anctrl_start(s0);
            func_8008B2DC(s0, f1);
            func_8008B10C(s0, f12);
        } else {
            func_80104328(param_1);
        }
    }

    s0 = *(u8 **) param_1;
    ((SB12 *) s0)->hi = *(u16 *) (param_0 + 0xAC);

    func_8010A654(param_1, (*(u32 *) (param_0 + 0x9C) << 30) >> 31);

    s0 = *(u8 **) param_1;
    ((SB2A *) s0)->b2 = (*(u32 *) (param_0 + 0x9C) << 1) >> 31;

    s0 = *(u8 **) param_1;
    ((SB2A *) s0)->b1 = (*(u32 *) (param_0 + 0x9C) << 2) >> 31;

    ((SB7E *) param_1)->b7 = 0;
    ((SB7E *) param_1)->b4 = 0;

    s0 = *(u8 **) param_1;
    ((SB2AH *) s0)->f = (*(u32 *) (param_0 + 0xAC) << 17) >> 26;

    s0 = *(u8 **) param_1;
    ((SB13 *) s0)->b = ((SRAEB *) param_0)->b0;

    s0 = *(u8 **) param_1;
    ((SB1B *) s0)->b = ((SRAEB *) param_0)->b7;

    func_80103014(param_1);
}

s32 func_80800F98_subaddiestore(param_0)
u8 *param_0;
{
    s32 local_0;

    for (local_0 = 0; local_0 < 3; local_0++) {

if (((s16 *) (param_0 + 0x82))[local_0] != 0) {
    return 1;
}

}
return 0;
}

u8 *func_80800FD0_subaddiestore(param_0)
Actor *param_0;
{
    u8 *local_0;
    s32 local_2;
    s32 *local_1;

    local_0 = (u8 *) param_0 + 0xB0;
    if (param_0->unk7C_0) {
        local_0 += 0x48;
    }
    if ((param_0->pad94 << 2) >> 22) {
        local_0 += 0x18;
    }
    if (func_80800F98_subaddiestore(param_0, local_0)) {
        local_1 = (s32 *) local_0;
        local_0 += 0xC;
        for (local_2 = 0; local_2 < 3; local_2++) {
            local_0 = local_1[local_2] + local_0;
        }
    }
    return local_0;
}

int func_80801054_subaddiestore(param_0, param_1, param_2)
OSIoMesgHdr *param_0;
void *param_1;
OSMesg **param_2;
{
    s16 local_0;
    void *local_1;
    OSMesg *local_2;
    s32 local_3;
    u32 local_4;

    local_4 = (*(u32 *) ((char *) param_1 + 0x6C)) >> 0x15;
    local_1 = (void *) ((char *) param_0 + 4);
    local_3 = 0;
    if (*(s16 *) param_0 > 0) {
    loop_1:
        if (local_4 == ((*(u32 *) ((char *) local_1 + 0x6C)) >> 0x15)) {
            *param_2 = (OSMesg *) local_1;
            return 1;
        }
        local_1 = func_80800FD0_subaddiestore(local_1);
        local_3 += 1;
        if (local_3 >= *(s16 *) param_0) {
            local_3 = 0;
            goto block_5;
        }
        goto loop_1;
    }
block_5:
    local_0 = *(s16 *) ((char *) param_0 + 2);
    local_2 = (OSMesg *) local_1;
    if (local_0 > 0) {
    loop_6:
        local_3 += 1;
        if (local_4 == *(u32 *) local_2) {
            *param_2 = NULL;
            return 2;
        }
        local_2 = (OSMesg *) ((char *) local_2 + 4);
        if (local_3 >= local_0) {
            goto block_9;
        }
        goto loop_6;
    }
block_9:
    return 0;
}
