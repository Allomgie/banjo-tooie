#include "common.h"
#include "vector.h"

extern f32 func_800DC178(f32, f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern f32 func_800EEFD4();
extern void func_800EF934(f32 *, f32 *, f32);
extern s32 func_800E3F8C(f32, f32, f32);
extern void func_800EE780(f32 *, f32 *, f32 *);
typedef struct { u8 pad_0[0x24]; s32 local_0[4]; } Broad51LeafTextures;
typedef struct { s32 model; f32 position[3]; u8 pad_0[0xC]; f32 rotation[3]; u8 pad_1[0xC]; u8 state; u8 pad_2[3]; } LeafParticle;
typedef struct { u8 pad_0[0x1C]; Vector *particles; } LeafParticles;
extern s32 func_800DF350(void);
extern void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
typedef struct { f32 local_0[3]; f32 local_1[3]; s32 local_2; Vector *local_3; s16 local_4; u8 local_5; u8 pad_0; s32 local_6[4]; u8 local_7; u8 pad_1[3]; f32 local_8; } LeafEmitter61;
extern void *heap_alloc(s32);
extern f32 func_800D8FF8(void);
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern s32 func_800F1574(f32 *, f32);
typedef struct { s32 local_0; f32 position[3]; f32 velocity[3]; f32 rotation[3]; f32 angular_velocity[3]; u8 local_1; u8 pad_0[3]; } Mass63Leaf;

void func_80800000_fxleaves(u8 *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_6;
    f32 local_7;
    u8 *local_3;
    f32 local_4[3];
    f32 local_5;
    s32 local_8;

    if (vector_size(*(Vector **)(param_0 + 0x1C)) < *(s16 *)(param_0 + 0x20)) {
        func_8008FE68(local_0);
        func_800E3958(local_1);
        func_800E3A58(local_2);
        local_3 = vector_push_back((Vector **)(param_0 + 0x1C));
        local_5 = func_800DC178(50.0f, 1200.0f);
        func_800EFA4C(local_4, 0.0f, func_800DC178(200.0f, 500.0f), -local_5);
        if (func_800EEFD4((f32 *)(param_0 + 0xC)) < 25.0f) {
            func_800EF934(local_4, local_4, func_800DC178(0.0f, 360.0f));
        } else {
            func_800EF934(local_4, local_4, local_2[1] + func_800DC178(-70.0f, 70.0f));
        }
        func_800EE780(local_4, local_0, local_4);
        if (local_5 < 600.0f) {
            for (local_8 = 0; local_8 < 10 && func_800E3F8C(local_4[0], local_4[1] - 10.0f, local_4[2]); local_8++) {
                local_4[1] += 100.0f;
            }
        }
        func_800EE7F8((f32 *)(local_3 + 4), local_4);
        func_800EFA4C((f32 *)(local_3 + 0x10), 0.0f, -100.0f, 0.0f);
        func_800EFD24((f32 *)(local_3 + 0x1C));
        local_6 = func_800DC178(-300.0f, 300.0f);
        local_7 = func_800DC178(-300.0f, 300.0f);
        func_800EFA4C((f32 *)(local_3 + 0x28), local_6, local_7, func_800DC178(-300.0f, 300.0f));
        param_0[0x34]++;
        if (param_0[0x34] >= 4) {
            param_0[0x34] = 0;
        }
        *(s32 *)local_3 = ((Broad51LeafTextures *)param_0)->local_0[param_0[0x34]];
    }
}

int func_80800288_fxleaves(u8 *param_0, int param_1)
{
  param_0[0x22] = param_1;
}

void fxleaves_entrypoint_0(void *param_0)
{
    vector_clear(*(void **)((char *)param_0 + 0x1C));
}

void fxleaves_entrypoint_1(LeafParticles *param_0)
{
    LeafParticle *local_0;
    LeafParticle *local_1;
    LeafParticle *local_2;
    local_0 = vector_begin(param_0->particles);
    local_1 = vector_end(param_0->particles);
    for (local_2 = local_0; local_2 < local_1; local_2++) {
        func_800DF830(2);
        func_800DE448(local_2->position, local_2->rotation, 1.0f, NULL, (s32)func_800D674C(local_2->model));
        local_2->state = func_800DF350();
    }
}

s32 fxleaves_entrypoint_2(u8 *param_0)
{
  char *new_var2;
  int new_var;
  s32 local_0;
  s32 local_1;
  s32 local_2;
  u8 *new_var3;
  local_0 = (*((u8 *) (((char *) param_0) - -0x22))) != 1;
  if (local_0 != 0)
  {
    new_var = 0x1C;
    new_var3 = param_0;
    local_0 = vector_size(*((s32 *) ((new_var2 = (char *) new_var3) + new_var))) == 0;
    return local_0;
  }
  local_1 = local_0 < 1;
  local_2 = local_1;
  local_0 = local_1;
}

int fxleaves_entrypoint_3(s32 param_0)
{
  vector_free(*(s32 *)((char *)param_0 + 0x1C));
  heap_free(param_0);
}

LeafEmitter61 *fxleaves_entrypoint_4(s32 param_0)
{
    LeafEmitter61 *local_0;

    local_0 = heap_alloc(sizeof(LeafEmitter61));
    local_0->local_2 = 0;
    local_0->local_0[0] = local_0->local_0[1] = local_0->local_0[2] = 0.0f;
    local_0->local_1[0] = local_0->local_1[1] = local_0->local_1[2] = 0.0f;
    local_0->local_3 = vector_new(0x38, param_0);
    local_0->local_4 = param_0;
    local_0->local_5 = 0;
    local_0->local_6[0] = 0x9ED;
    local_0->local_6[1] = 0x9EE;
    local_0->local_6[2] = 0x9EF;
    local_0->local_6[3] = 0x9F0;
    local_0->local_7 = 0;
    local_0->local_8 = 0.1f;
    return local_0;
}

void fxleaves_entrypoint_5(s32 arg0)
{
    func_80800288_fxleaves(arg0,1);
}

void fxleaves_entrypoint_6(s32 arg0)
{
    func_80800288_fxleaves(arg0,0x2);
}

void fxleaves_entrypoint_7(u8 *param_0)
{
    f32 local_0[3];
    f32 local_1;
    s32 local_2;
    Mass63Leaf *local_3;

    local_1 = func_800D8FF8();
    func_8008FE68(local_0);
    func_800EFB24((f32 *)(param_0 + 0xC), local_0, (f32 *)param_0);
    func_800EE7F8((f32 *)param_0, local_0);
    if (func_800A5490()) {
        vector_clear(*(Vector **)(param_0 + 0x1C));
    }
    for (local_2 = 0; local_2 < vector_size(*(Vector **)(param_0 + 0x1C)); local_2++) {
        local_3 = vector_at(*(Vector **)(param_0 + 0x1C), local_2);
        local_3->position[0] += local_3->velocity[0] * local_1;
        local_3->position[1] += local_3->velocity[1] * local_1;
        local_3->position[2] += local_3->velocity[2] * local_1;
        local_3->velocity[0] += func_800DC178(-400.0f, 400.0f) * local_1;
        local_3->velocity[2] += func_800DC178(-400.0f, 400.0f) * local_1;
        local_3->rotation[0] += local_3->angular_velocity[0] * local_1;
        local_3->rotation[1] += local_3->angular_velocity[1] * local_1;
        local_3->rotation[2] += local_3->angular_velocity[2] * local_1;
        local_3->angular_velocity[0] += func_800DC178(-300.0f, 300.0f) * local_1;
        local_3->angular_velocity[1] += func_800DC178(-300.0f, 300.0f) * local_1;
        local_3->angular_velocity[2] += func_800DC178(-300.0f, 300.0f) * local_1;
        if (local_3->position[1] < local_0[1] - 500.0f && !local_3->local_1) {
            vector_erase(*(Vector **)(param_0 + 0x1C), local_2);
            local_2--;
        }
    }
    (*(s32 *)(param_0 + 0x18))++;
    if (*(s32 *)(param_0 + 0x18) < vector_size(*(Vector **)(param_0 + 0x1C))) {
        local_3 = vector_at(*(Vector **)(param_0 + 0x1C), *(s32 *)(param_0 + 0x18));
        if (func_800EEAD4(local_3->position, local_0) > 1320.0f) {
            vector_erase(*(Vector **)(param_0 + 0x1C), *(s32 *)(param_0 + 0x18));
        }
    } else {
        *(s32 *)(param_0 + 0x18) = 0;
    }
    if (func_800F1574((f32 *)(param_0 + 0x38), local_1)) {
        if (param_0[0x22] == 1 && !func_800A5490()) {
            func_80800000_fxleaves(param_0);
        }
        *(f32 *)(param_0 + 0x38) = 0.1f;
    }
}
