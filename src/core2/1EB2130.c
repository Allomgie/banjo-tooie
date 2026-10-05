#include "common.h"

extern float D_8011B964[];
extern u8 D_8011B961[3];
extern s32 D_8012C020;
extern void freelist_next();
typedef struct { s16 x; s16 y; } pair16;
typedef union { s32 val; pair16 pair; } local_1_type;
typedef struct { f32 local_0, local_1, local_2[3]; s16 local_3[3]; u8 local_4; } StateD89C8;
typedef struct { s16 local_0[3]; u8 pad[10]; } VertexD89C8;
typedef struct { u8 pad[24]; VertexD89C8 local_0[1]; } MeshD89C8;
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_80019CD4(void);
extern void func_80019750(f32 *, f32 *, f32, f32 *);
extern void func_80019224(f32 *, f32 *);
typedef struct { f32 weights[2],point[3]; s16 indices[3]; u8 active,pad; } LocalAttachment;
typedef struct { s16 xyz[3]; u8 pad6[10]; } LocalVertex;
typedef struct { u8 pad0[0x18]; LocalVertex vertices[1]; } LocalVertexList;
extern void func_8001980C(f32 *,f32 *,f32,f32 *);
extern void func_800EE97C(f32 *,f32 *,f32 *);
extern void func_800EE7F8(f32 *,f32 *);
extern f32 mlAbsF(f32);
extern f32 func_800EEF94(f32 *);
extern s32 D_8012C030;
s32 func_800D8988();

float func_800D8840(s32 param_0){
    return *(f32 *)((char *)D_8011B964 + param_0 * 8);
}

int func_800D8854(s32 param_0)
{
  return D_8011B961[param_0 * 8] & 1;
}

void func_800D8870()
{
  D_8012C020 = freelist_new(0x70, 0);
}

s32 func_800D8898(void){
    freelist_free(D_8012C020);
    D_8012C020 = 0;
}

int func_800D88C0()
{
  if (D_8012C020 != 0)
  {
    D_8012C020 = freelist_defrag(D_8012C020);
  }
  return;
}

int func_800D88F8()
{
  local_1_type local_1;
  s32 local_0;
  local_1.val = 0;
  freelist_next(((u8 *) &D_8012C020), &local_1);
  for (local_0 = 0; local_0 < 4; local_0++)
  {
    u8 *local_2 = func_800D8988(local_1.pair.y, local_0);
    local_2[0x1a] = 0;
  }
  return local_1.pair.y;
}

s32 func_800D8954(indx) s16 indx;{
    s32 local_0 = indx;
    freelist_erase(D_8012C020, local_0);
}

s32 func_800D8988(param_0, param_1) s16 param_0; s32 param_1;
{
  return freelist_at(((u8 *) D_8012C020), param_0) + (param_1 * 0x1C);
}

s32 func_800D89C8(s16 param_0, s32 param_1, f32 *param_2, f32 *param_3, f32 param_4, f32 *param_5, MeshD89C8 *param_6, f32 *param_7, f32 *param_8) {
    f32 local_0[3];
    f32 local_1[3];
    s32 local_2;
    s32 local_3;
    f32 local_4[3][3];
    VertexD89C8 *local_6;
    StateD89C8 *local_5;
    local_5 = func_800D8988(param_0, param_1);
    if (!local_5->local_4) return 0;
    local_5->local_4 = 0;
    if (func_800EEAD4(param_7, local_5->local_2) > 0.1f) return 0;
    for (local_2 = 0; local_2 < 3; local_2++) {
        local_6 = local_5->local_3[local_2] + param_6->local_0;
        for (local_3 = 0; local_3 < 3; local_3++) {
            local_4[local_2][local_3] = local_6->local_0[local_3];
        }
    }
    func_800EFB24(local_0, local_4[1], local_4[0]);
    func_800EFB24(local_1, local_4[2], local_4[0]);
    func_800EFA4C(param_8,
        local_4[0][0] + local_5->local_0 * local_0[0] + local_1[0] * local_5->local_1,
        local_4[0][1] + local_5->local_0 * local_0[1] + local_1[1] * local_5->local_1,
        local_4[0][2] + local_5->local_0 * local_0[2] + local_1[2] * local_5->local_1);
    func_80019CD4();
    func_80019750(param_2, param_3, param_4, param_5);
    func_80019224(param_8, param_8);
    return 1;
}

void func_800D8B80(s16 param_0,s32 param_1,f32 *param_2,f32 *param_3,f32 param_4,f32 *param_5,u16 *param_6,LocalVertexList *param_7,f32 *param_8)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4[3];
    s32 local_5;
    s32 local_6;
    LocalVertex *local_7;
    s32 local_10;
    s32 local_8;
    s32 local_9;
    f32 local_11[3];
    f32 local_12[3][3];
    f32 local_14;
    LocalAttachment *local_13;
    f32 local_16;
    local_13=func_800D8988(param_0,param_1);
    func_800EE7F8(local_13->point,param_8);
    func_80019CD4();
    func_8001980C(param_2,param_3,param_4,param_5);
    func_80019224(local_2,param_8);
    for (local_5=0;local_5<3;local_5++) local_13->indices[local_5]=param_6[local_5];
    for (local_5=0;local_5<3;local_5++) {
        local_7=param_7->vertices+local_13->indices[local_5];
        for (local_6=0;local_6<3;local_6++) local_12[local_5][local_6]=local_7->xyz[local_6];
    }
    func_800EFB24(local_0,local_12[1],local_12[0]);
    func_800EFB24(local_1,local_12[2],local_12[0]);
    func_800EE97C(local_11,local_0,local_1);
    if (100000.0f<local_11[0] || 100000.0f<local_11[1] || 100000.0f<local_11[2] || local_11[0]<(-100000.0f) || local_11[1]<(-100000.0f) || local_11[2]<(-100000.0f)) {
        local_11[0]*=0.00001f;
        local_11[1]*=0.00001f;
        local_11[2]*=0.00001f;
    }
    if (func_800EEF94(local_11)<0.001f) { local_13->active=0; return; }
    local_16=mlAbsF(local_11[0]);
    local_14=mlAbsF(local_11[1]);
    local_10=local_14<local_16 ? 0 : 1;
    local_16=mlAbsF(local_11[2]);
    local_14=mlAbsF(local_11[local_10]);
    if (local_14<local_16) local_10=2;
    local_8=(local_10+1)%3;
    func_800EFA4C(local_3,local_2[local_8]-local_12[0][local_8],local_0[local_8],local_1[local_8]);
    local_9=(local_10+2)%3;
    func_800EFA4C(local_4,local_2[local_9]-local_12[0][local_9],local_0[local_9],local_1[local_9]);
    local_14=local_3[1]*local_4[2]-local_4[1]*local_3[2];
    local_13->weights[0]=(local_3[0]*local_4[2]-local_4[0]*local_3[2])/local_14;
    local_13->weights[1]=(local_3[1]*local_4[0]-local_4[1]*local_3[0])/local_14;
    local_13->active=1;
}

int func_800D8F40()
{
    return (int)&D_8012C030;
}
