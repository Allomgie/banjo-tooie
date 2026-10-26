#include "common.h"

extern u8 unk20[];
typedef struct { u8 pad_0[0x18]; u8 local_0; u8 pad_1[3]; } RainElement1517;
typedef struct { u8 pad_0[0x20]; void *local_0; } RainState1517;
extern void *func_800D674C(s32);
extern void *vector_begin(void *);
extern void *vector_end(void *);
extern void func_800DF830(s32);
extern void func_800DE448(void *, s32, f32, s32, void *);
extern s32 func_800DF350(void);
extern void func_800C3A40(u8, f32, f32, f32);
typedef struct { f32 unk0[3]; f32 unkC[3]; } RainDrop;
typedef struct { u8 pad0[0x10]; f32 unk10[3]; u8 pad1C[4]; void *unk20; s32 unk24; } RainSystem;
extern s32 vector_size(void *);
extern void *vector_push_back(void **);
extern void func_800E3980(f32 *);
extern void func_800E3958(f32 *);
extern void func_800E3A58(f32 *);
extern f32 func_800DC178(f32, f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern f32 func_800EEFD4(f32 *);
extern void func_800EF934(f32 *, f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);
extern s32 func_800E3F8C(f32, f32, f32);
extern void func_800EE7F8(f32 *, f32 *);
typedef struct { u8 pad_0[0x28]; s32 local_0; u8 pad_1[4]; u8 local_1; u8 pad_2[3]; f32 local_2; u8 pad_3[0xC]; f32 local_3; } RainState61;
extern void *heap_alloc(int);
extern void *vector_new(int, int);
extern void func_800EFD24(void *);
typedef struct { int unk0; int unk4; int unk8; int unkC; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; float unk2C; int unk30; } FxRain;
extern f32 func_800D8FF8(void);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800C37E0(u8, f32, f32, f32);
extern void func_800C316C();
extern f32 func_800EEB40();
extern s32 func_800F1574(f32 *, f32);
extern u8 *vector_at(s32, s32);

void func_80800000_fxrain(RainSystem *this)
{
    f32 plyrPos[3];
    f32 camNorm[3];
    f32 camRot[3];
    f32 dist;
    s32 i;
    RainDrop *drop;
    f32 pos[3];

    if (vector_size(this->unk20) >= this->unk24) {
        return;
    }
    func_800E3980(plyrPos);
    func_800E3958(camNorm);
    func_800E3A58(camRot);
    drop = vector_push_back(&this->unk20);
    dist = func_800DC178(50.0f, 2000.0f);
    func_800EFA4C(pos, 0.0f, func_800DC178(200.0f, 300.0f), -dist);
    if (func_800EEFD4(this->unk10) < 25.0f) {
        func_800EF934(pos, pos, func_800DC178(0.0f, 360.0f));
    } else {
        func_800EF934(pos, pos, camRot[1] + func_800DC178(-70.0f, 70.0f));
    }
    func_800EF04C(pos, plyrPos);
    if (dist < 1000.0f) {
        for (i = 0; i < 10 && func_800E3F8C(pos[0], pos[1] - 10.0f, pos[2]); i++) {
            pos[1] += 100.0f;
        }
    }
    func_800EE7F8(drop->unk0, pos);
    func_800EFA4C(drop->unkC, 0.0f, func_800DC178(-1600.0f, -1500.0f), 0.0f);
}

void func_808001E8_fxrain(s32 param_0, s32 param_1){
    s32 *local_0;
    local_0 = (s32 *)(param_0 + 0x28);
    *local_0 = param_1;
}

int fxrain_entrypoint_0(Actor *param_0)
{
  vector_clear((*(s32 *)((char *)(param_0) + 0x20)));
}

void fxrain_entrypoint_1(void *param_0)
{
    RainElement1517 *local_0;
    RainElement1517 *local_1;
    void *local_2;

    local_2 = func_800D674C(0x9EC);
    local_0 = vector_begin(((RainState1517 *)param_0)->local_0);
    local_1 = vector_end(((RainState1517 *)param_0)->local_0);
    for (param_0 = local_0; (RainElement1517 *)param_0 < local_1; param_0 = (u8 *)param_0 + 0x1C) {
        func_800DF830(2);
        func_800DE448(param_0, 0, 1.0f, 0, local_2);
        ((RainElement1517 *)param_0)->local_0 = func_800DF350();
    }
}

int fxrain_entrypoint_2(u8 *param_0) {
    return *(s32 *)(param_0 + 0x28) != 1 && vector_size(*(s32 *)(param_0 + 0x20)) == 0;
}

int fxrain_entrypoint_3(RainState61 *param_0)
{
    if (param_0->local_0 != 1) {
        return 0;
    }
    switch (param_0->local_1) {
    case 1:
    case 2:
        return 1;
    case 3:
        return param_0->local_2 < param_0->local_3 * 0.9f;
    }
    return 0;
}

void fxrain_entrypoint_4(u8 *param_0)
{
  u8 local_0;
  int new_var;
  new_var = ((((((*param_0) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu;
  if ((local_0 = new_var) != 0)
  {
    func_800C2FDC(local_0 & 0xFF, param_0, local_0);
    *param_0 = 0;
  }
  vector_free(*((void **) (((char *) param_0) + 0x20)));
  heap_free(param_0);
}

int fxrain_entrypoint_5(s32 param_0)
{
  FxRain *local_0;
  local_0 = heap_alloc(0x4C);
  func_800EFD24((u8 *)local_0 + 4);
  func_800EFD24(&local_0->unk10);
  *(u8 *)((char *)local_0 + 0x0) = 0;
  *(u8 *)((char *)local_0 + 0x1C) = 0;
  *(u8 *)((char *)local_0 + 0x30) = 0;
  local_0->unk20 = vector_new(0x1C, param_0);
  local_0->unk24 = param_0;
  local_0->unk28 = 0;
  local_0->unk2C = 0.1f;
  return local_0;
}

void fxrain_entrypoint_6(void *param_0, f32 param_1, f32 param_2, f32 param_3, f32 param_4)
{
    u8 *local_0 = (u8 *) ((char *) param_0 + 0x30);
    f32 local_1[3];
    *local_0 = 1;
    *(f32 *) ((char *) param_0 + 0x34) = 0.0f;
    *(f32 *) ((char *) param_0 + 0x38) = 0.1f;
    *(f32 *) ((char *) param_0 + 0x3C) = param_1;
    *(f32 *) ((char *) param_0 + 0x40) = param_2;
    *(f32 *) ((char *) param_0 + 0x44) = param_3;
    *(f32 *) ((char *) param_0 + 0x48) = param_4;
}

void fxrain_entrypoint_7(s32 arg0)
{
    func_808001E8_fxrain(arg0,1);
}

void fxrain_entrypoint_8(u8 *param_0) {
    func_808001E8_fxrain(param_0, 2);
    if (*param_0) {
        func_800C3A40(*param_0, 0.0f, 0.0f, 3.0f);
        *param_0 = 0;
    }
}

void fxrain_entrypoint_9(u8 *param_0)
{
    f32 sp44[3];
    f32 temp_f20;
    s32 i;
    u8 *e;
    s32 st;
    f32 rr;

    temp_f20 = func_800D8FF8();
    func_800E3980(sp44);
    func_800EFB24((f32 *)(param_0 + 0x10), sp44, (f32 *)(param_0 + 4));
    func_800EE7F8((f32 *)(param_0 + 4), sp44);
    if (func_800A5490() != 0) {
        vector_clear(*(s32 *)(param_0 + 0x20));
    }
    if (vector_size(*(s32 *)(param_0 + 0x20)) > 0) {
        if (param_0[0] == 0) {
            param_0[0] = func_800C2E04();
            func_800C330C(param_0[0], 3);
            func_800C301C(param_0[0], 0x465);
            func_800C37E0(param_0[0], 0.95f, 1.05f, 0.01f);
            func_800C3A40(param_0[0], 3.0f, 12960000.0f, 0);
            func_800C3418(param_0[0], 2);
            func_800C316C(param_0[0], 0x1388, 0x1770, 0x40A00000);
            func_800C3BDC(param_0[0]);
        }
    } else if (param_0[0] != 0) {
        func_800C2FDC(param_0[0]);
        param_0[0] = 0;
    }
    i = 0;
    if (vector_size(*(s32 *)(param_0 + 0x20)) > 0) {
        do {
            e = vector_at(*(s32 *)(param_0 + 0x20), i);
            *(f32 *)(e + 0) = *(f32 *)(e + 0xC) * temp_f20 + *(f32 *)(e + 0);
            *(f32 *)(e + 4) = *(f32 *)(e + 0x10) * temp_f20 + *(f32 *)(e + 4);
            *(f32 *)(e + 8) = *(f32 *)(e + 0x14) * temp_f20 + *(f32 *)(e + 8);
            if (*(f32 *)(e + 4) < sp44[1] - 500.0f && e[0x18] == 0) {
                vector_erase(*(s32 *)(param_0 + 0x20), i);
                i--;
            }
            i++;
        } while (i < vector_size(*(s32 *)(param_0 + 0x20)));
    }
    param_0[0x1C] = param_0[0x1C] + 1;
    if (param_0[0x1C] < vector_size(*(s32 *)(param_0 + 0x20))) {
        rr = 2200.0f;
        if (rr * rr < func_800EEB40(vector_at(*(s32 *)(param_0 + 0x20), param_0[0x1C]), sp44)) {
            vector_erase(*(s32 *)(param_0 + 0x20), param_0[0x1C]);
        }
    } else {
        param_0[0x1C] = 0;
    }
    st = param_0[0x30];
    if (param_0[0x30] != 0) {
        *(f32 *)(param_0 + 0x34) = *(f32 *)(param_0 + 0x34) + temp_f20;
        if (*(f32 *)(param_0 + st * 4 + 0x38) <= *(f32 *)(param_0 + 0x34)) {
            *(f32 *)(param_0 + 0x34) = 0.0f;
            param_0[0x30] = st + 1;
            st = param_0[0x30];
            if (st >= 5) {
                param_0[0x30] = 1;
                st = param_0[0x30];
            }
        }
        if (st == 1) {
            *(f32 *)(param_0 + 0x38) = (1.0f - *(f32 *)(param_0 + 0x34) / *(f32 *)(param_0 + 0x3C)) * 0.1f;
        } else if (st == 2) {
            *(f32 *)(param_0 + 0x38) = 0.01f;
        } else if (st == 3) {
            *(f32 *)(param_0 + 0x38) = *(f32 *)(param_0 + 0x34) / *(f32 *)(param_0 + 0x44) * 0.1f;
        } else {
            *(f32 *)(param_0 + 0x38) = 0.01f;
        }
        if (*(f32 *)(param_0 + 0x38) <= 0.01f) {
            *(f32 *)(param_0 + 0x38) = 0.01f;
        }
    }
    if (func_800F1574((f32 *)(param_0 + 0x2C), temp_f20) != 0) {
        if (*(s32 *)(param_0 + 0x28) == 1 && func_800A5490() == 0 && param_0[0x30] != 4) {
            func_80800000_fxrain(param_0);
        }
        if (param_0[0x30] != 0) {
            *(f32 *)(param_0 + 0x2C) = *(f32 *)(param_0 + 0x38);
        } else {
            *(f32 *)(param_0 + 0x2C) = 0.01f;
        }
    }
}
