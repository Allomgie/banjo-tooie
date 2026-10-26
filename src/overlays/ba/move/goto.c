#include "common.h"

#define GD (*(GotoData **)((u8 *)param_0 + 0xC8))
extern void baphysics_set_target_horizontal_velocity(Actor *, f32);
extern void func_8009C0F8(Actor*, s32);
struct bamovegoto_unkC8 { u8 pad7C[0x7C]; s32 unk7C; s32 unk80; };
struct bamovegoto { u8 padC8[0xC8]; struct bamovegoto_unkC8 *unkC8; };
extern void baphysics_set_type();
typedef struct { u8 pad0[4]; f32 pos[3]; f32 vel[3]; u8 pad1C[0xC]; f32 unk28[3]; f32 unk34; f32 unk38; u8 pad3C[0x18]; u8 state; u8 pad55; u8 unk56; u8 pad57; f32 target[3]; f32 start[3]; f32 duration; f32 time; f32 speed; void (*unk7C)(Actor *, f32 *, f32); f32 (*unk80)(Actor *, f32); } GotoData;
extern void func_8009C128(Actor *, f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern f32 func_800EEFFC(f32 *);
extern void func_8009BA9C(Actor *, s32);
extern f32 func_800D8FF8(void);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800EE7F8();
extern f32 func_800F1214(f32, f32, f32);
extern void func_800EF334(f32 *, f32);
extern f32 func_800EEF94(f32 *);
extern void func_800EF368(f32 *, f32);
extern void func_800EFA20(f32 *, f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);

void func_80800000_bamovegoto(Actor *param_0, s32 param_1)
{
    if ((param_1 == 0) || (param_1 == 6))
    {
        baphysics_set_target_horizontal_velocity(param_0, 0);
        func_8009BA9C(param_0, 0);
    }
    *(s8 *)((char *)(*(u8 **)((char *)param_0 + 0xC8)) + 0x54) = (s8)param_1;
}

void bamovegoto_entrypoint_0(u8 *param_0)
{
  int new_var;
  *((s32 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0xC8)))) + 0x80)) = 0;
  *((s32 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0xC8)))) + 0x7C)) = 0;
  *((f32 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0xC8)))) + 0x78)) = 0.0f;
  new_var = 0x70;
  *((s8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0xC8)))) + 0x55)) = 1;
  *((s8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0xC8)))) + 0x56)) = 0;
  *((s8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0xC8)))) + 0x54)) = 0;
  *((f32 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0xC8)))) + new_var)) = 1.0f;
  *((f32 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0xC8)))) + 0x74)) = 0;
  func_800EFD24((*((u8 **) (((s8 *) param_0) + 0xC8))) + 0x58, param_0);
  func_800EFD24((*((u8 **) (((s8 *) param_0) + 0xC8))) + 0x64, param_0);
}

void bamovegoto_entrypoint_1(Actor *param_0)
{
    s32 local_0;
    s32 *ptr = (s32*)((char*)param_0 + 0xC8);
    local_0 = ptr[0] + 4;
    func_800EE7F8(local_0, ptr[0] + 0x64);
    func_8009C0F8(param_0, ptr[0] + 0x64);
    func_80800000_bamovegoto(param_0, 6);
}

f32 bamovegoto_entrypoint_2(u8 *param_0) {
    return (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xC8)))) + (0x74)));
}

void bamovegoto_entrypoint_3(u8 *param_0) {
    s32 local_0;

    local_0 = (*(s32 *)((s8 *)(param_0) + (0xC8)));
    func_800EEAD4(local_0 + 0x58, local_0 + 0x64);
}

s32 bamovegoto_entrypoint_4(u8 *param_0) {
    return (*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xC8)))) + (0x54))) == 6;
}

void bamovegoto_entrypoint_5(s32 arg0)
{
    func_80800000_bamovegoto(arg0,0);
}

void bamovegoto_entrypoint_6(void *param_0)
{
    s32 *t6;
    *((s8 *) ((*((s32 **) (((char *) param_0) + 0xC8))) + (0x54 / 4))) = 0;
}

int bamovegoto_entrypoint_7(s32 param_0, f32 param_1)
{
  int new_var;
  new_var = new_var + 0x50;
  new_var = param_0;
  *((f32 *) ((*((s32 *)((char *)(new_var) + 200))) + 112)) = param_1;
}

int bamovegoto_entrypoint_8(s32 param_0, f32 param_1)
{
  int new_var;
 new_var = 0x50; *((f32 *) ((*((s32 *) (param_0 + 0xC8))) + 0x78)) = param_1;
}

void bamovegoto_entrypoint_9(void *arg, s32 v)
{
    ((s8 *)(*(void **)((char *)arg + 0xC8)))[85] = v;
}

void bamovegoto_entrypoint_10(void *arg, s32 v)
{
    ((s8 *)(*(void **)((char *)arg + 0xC8)))[86] = v;
}

void bamovegoto_entrypoint_11(struct bamovegoto *param_0, s32 param_1, s32 param_2)
{
  struct bamovegoto *new_var;
  param_0->unkC8->unk80 = param_1;
  new_var++;
  new_var = param_0;
  param_0;
  param_0->unkC8->unk7C = param_2;
}

void bamovegoto_entrypoint_12(Actor *param_0)
{
  char *new_var4;
  char *new_var5;
  char *new_var;
  char *new_var3;
  char *new_var2;
  new_var5 = (new_var2 = new_var3);
  new_var3 = (new_var2 = (char *) param_0) + 0x58;
  new_var = new_var5;
  new_var4 = new_var2;
  func_800EE7F8((*((s32 *)((char *)(new_var4) + 200))) + 100);
}

void bamovegoto_entrypoint_13(u8 *param_0) {
    baphysics_set_type(param_0, 0xC);
    if ((*(u8 **)(param_0 + 0xC8))[0x55] == 1) {
        func_80800000_bamovegoto(param_0, 2);
    } else {
        func_80800000_bamovegoto(param_0, 4);
    }
}

void bamovegoto_entrypoint_14(Actor *param_0)
{
    f32 local_0;
    f32 local_1;
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4;
    f32 local_5[3];

    switch (GD->state) {
    case 2:
        func_8009C128(param_0, GD->target);
        if (GD->speed != 0) {
            func_800EFB24(local_2, GD->start, GD->target);
            GD->duration = func_800EEFFC(local_2) / GD->speed;
        }
        GD->time = 0.0f;
        func_8009BA9C(param_0, 0);
        baphysics_set_target_horizontal_velocity(param_0, 0);
        func_80800000_bamovegoto(param_0, 3);
        break;
    case 3:
        GD->time += func_800D8FF8();
        local_0 = func_800F10B4(GD->time, 0.0f, GD->duration, 0.0f, 1.0f);
        if (GD->unk80 != NULL) {
            local_1 = GD->unk80(param_0, local_0);
        } else {
            local_1 = local_0;
        }
        func_800EE7F8(local_3, GD->pos);
        GD->pos[0] = func_800F1214(local_1, GD->target[0], GD->start[0]);
        GD->pos[1] = func_800F1214(local_1, GD->target[1], GD->start[1]);
        GD->pos[2] = func_800F1214(local_1, GD->target[2], GD->start[2]);
        if (GD->unk7C != NULL) {
            GD->unk7C(param_0, GD->pos, local_0);
        }
        func_800EFB24(GD->vel, GD->pos, local_3);
        func_800EF334(GD->vel, 1.0f / func_800D8FF8());
        baphysics_set_target_horizontal_velocity(param_0, func_800EEF94(GD->vel));
        if (local_0 == 1.0f) {
            func_80800000_bamovegoto(param_0, 6);
        }
        break;
    case 4:
        func_8009C128(param_0, GD->target);
        func_80800000_bamovegoto(param_0, 5);
        break;
    case 5:
        local_4 = func_800D8FF8();
        func_800EFB24(local_5, GD->start, GD->pos);
        local_5[1] = 0;
        if (func_800EEFFC(local_5) <= GD->speed * local_4) {
            func_80800000_bamovegoto(param_0, 6);
        } else {
            func_800EF368(local_5, GD->speed);
        }
        GD->vel[0] = local_5[0];
        GD->vel[2] = local_5[2];
        if (GD->unk56) {
            GD->vel[1] += GD->unk34 * local_4;
            if (GD->vel[1] < GD->unk38) {
                GD->vel[1] = GD->unk38;
            }
        }
        func_800EFA20(GD->unk28, GD->vel, local_4);
        baphysics_set_target_horizontal_velocity(param_0, func_800EEF94(GD->vel));
        func_800EF04C(GD->pos, GD->unk28);
        break;
    case 0:
    case 1:
    case 6:
        break;
    }
}
