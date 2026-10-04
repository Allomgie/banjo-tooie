#include "common.h"
#include "core2/1EC8070.h"
#include "core2/1ECB9F0.h"

typedef struct { s16 local_0[3]; u8 pad[6]; u8 local_1[4]; } VertexAA3B4;
typedef struct { f32 local_0[3][3]; f32 local_1[3][4]; } BufferAA3B4;
extern void func_800EE88C();
typedef struct { s16 local_0[3], local_1[3]; u16 local_2, local_3; s16 pad10, local_4; s32 pad14; u32 local_5[1]; } GridAA;
typedef struct { u32 *local_0[100]; u32 **local_1; } ListAA;
extern ListAA D_801277A0;
extern u32 *D_80127930[];
typedef struct { u8 pad[0x24]; f32 local_0[3][4]; } ColorAAAE0;
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EE97C(f32 *, f32 *, f32 *);
extern f32 func_800EEFD4(f32 *);
extern f32 func_800EEB40(f32 *, f32 *);
extern f32 sqrtf(f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
typedef struct { u16 start, count; } ABGeo;
typedef struct { u16 vertex[3]; u16 pad; u32 flags; } ABTri;
typedef struct { s16 pos[3]; u8 pad[10]; } ABVertex;
extern void *D_8012798C;
extern void *heap_alloc();
extern void heap_free(void *ptr);
typedef struct NodeABA20 { struct NodeABA20 *local_0; struct NodeABA20 *local_1; } NodeABA20;
extern NodeABA20 *defrag(NodeABA20 *);
typedef struct { u16 start,count; } LocalGeo;
typedef struct { u16 vertex[3],pad; u32 flags; } LocalTri_800ABCE0;
typedef struct { f32 edge0[3],edge1[3],normal[3]; LocalTri_800ABCE0 *tri; f32 points[3][3]; } LocalEntry;
typedef struct { u8 pad[0x10]; LocalEntry entries[1]; } LocalBlock;
extern void func_800EF2A0(f32 *);
typedef struct { f32 edgeAB[3]; f32 edgeAC[3]; f32 normal[3]; void *triangle; f32 vertices[3][3]; } LocalTriangle;
typedef struct LocalTriangleBlock { s32 first; struct LocalTriangleBlock *next; s32 capacity; s32 count; LocalTriangle triangles[1]; } LocalTriangleBlock;
extern void func_800EFD24(f32 *);
extern f32 func_800EEAA4(f32 *, f32 *);
extern f32 mlAbsF(f32);
extern void func_800EF04C(f32 *, f32 *);
typedef struct { u8 pad[0x24]; void *local_0; } HitAC638;
extern void func_800EE7F8(f32 *, f32 *);
extern f32 D_80127938[][3];
extern f32 D_8012795C[];
extern void func_80019CD4(void);
extern void func_8001980C(f32 *, f32 *, f32, f32 *);
extern void func_80019750(f32 *, f32 *, f32, f32 *);
extern void func_80019224(f32 *, f32 *);
extern void func_800EF410(f32 *, f32 *);
typedef struct { u8 pad00[0x10]; u16 groupCount; } LocalModel;
typedef struct { u16 first, count; } LocalGroup;
typedef struct { u16 index[3]; u16 pad06; u32 flags; } LocalTri_800AD2C8;
typedef struct { s16 position[3]; u8 pad06[10]; } LocalVertex;
typedef struct { s16 position[3][3]; s16 pad12; } LocalCachedTri;
typedef struct { s16 position[3][3]; } LocalOutput;
extern struct { LocalCachedTri triangles[64]; LocalCachedTri *end; } D_80127990;
extern LocalVertex *func_800B2190(void *);
extern void func_800EE8CC();
extern void func_800EFB58(s32 *, s32 *, s32 *);
extern void func_800EE9EC(f32 *, s32 *, s32 *);
typedef struct { u8 pad[0x10]; u16 local_0; } ModelAD894;
typedef struct { u16 local_0, local_1; } GroupAD894;
typedef struct { u16 local_0[3]; u8 pad[6]; } TriAD894;
typedef struct { s16 local_0[3]; u8 pad[10]; } VertexAD894;
extern s32 func_800EED58(s32 *, s32 *);

void func_800AA2A0(s16 *param_0, s32 *param_1, f32 *param_2)
{
  s32 local_0;
  f32 local_4;
  s16 *new_var;
  s32 local_8;
  if (!param_0[9])
  {
    param_1[2] = 0;
    param_1[1] = 0;
    param_1[0] = 0;
    return;
  }
  for (local_0 = 0; local_0 < 3; local_0++)
  {
    local_4 = param_2[local_0];
    if (local_4 >= 0.0f)
    {
      local_8 = (s32) local_4;
      param_1[local_0] = local_8 / param_0[9];
    }
    else
    {
      local_8 = (s32) local_4;
      param_1[local_0] = (local_8 / param_0[9]) - 1;
    }
    new_var = param_0;
    if (param_1[local_0] < new_var[local_0])
    {
      param_1[local_0] = new_var[local_0];
    }
    if (param_1[local_0] > new_var[local_0 + 3])
    {
      param_1[local_0] = new_var[local_0 + 3];
    }
  }

  return;
}

void func_800AA3B4(u16 *param_0, u8 *param_1) {
    s32 local_0;
    s32 local_2;
    VertexAA3B4 *local_1;
    VertexAA3B4 *local_3;
    if (param_0 != 0) {
        local_3 = (VertexAA3B4 *)(param_1 + 0x18);
        for (local_0 = 0; local_0 < 3; local_0++) {
            local_1 = local_3 + param_0[local_0];
            func_800EE88C((*((BufferAA3B4 *) D_80127938)).local_0[local_0], local_1->local_0);
            for (local_2 = 0; local_2 < 4; local_2++) {
                (*((BufferAA3B4 *) D_80127938)).local_1[local_0][local_2] = (u32)local_1->local_1[local_2];
            }
        }
    }
}

void func_800AA4D4(GridAA *param_0, f32 *param_1, f32 *param_2, u32 ***param_3, u32 ***param_4)
{
    s32 local_0[3];
    s32 local_1[3];
    s32 local_2;
    s32 local_3;
    s32 local_4;
    s32 local_5;
    s32 local_6;
    s32 local_7;
    if (!param_0->local_4) {
        D_801277A0.local_1 = D_801277A0.local_0;
        *D_801277A0.local_1++ = param_0->local_5;
        *param_3 = D_801277A0.local_0;
        *param_4 = D_801277A0.local_1;
        return;
    }
    for (local_2 = 0; local_2 < 3; local_2++) {
        if (param_1[local_2] >= 0.0f) local_0[local_2] = (s32)param_1[local_2] / param_0->local_4;
        else local_0[local_2] = (s32)param_1[local_2] / param_0->local_4 - 1;
        if (param_2[local_2] >= 0.0f) local_1[local_2] = (s32)param_2[local_2] / param_0->local_4;
        else local_1[local_2] = (s32)param_2[local_2] / param_0->local_4 - 1;
        if (local_0[local_2] < param_0->local_0[local_2]) local_0[local_2] = param_0->local_0[local_2];
        if (local_0[local_2] > param_0->local_1[local_2]) local_0[local_2] = param_0->local_1[local_2];
        if (local_1[local_2] < param_0->local_0[local_2]) local_1[local_2] = param_0->local_0[local_2];
        if (local_1[local_2] > param_0->local_1[local_2]) local_1[local_2] = param_0->local_1[local_2];
        local_0[local_2] -= param_0->local_0[local_2];
        local_1[local_2] -= param_0->local_0[local_2];
    }
    D_801277A0.local_1 = D_801277A0.local_0;
    for (local_3 = local_0[2]; local_3 <= local_1[2]; local_3++) {
        for (local_4 = local_0[1]; local_4 <= local_1[1]; local_4++) {
            for (local_5 = local_0[0]; local_5 <= local_1[0]; local_5++) {
                if (D_801277A0.local_1 < D_80127930) {
                    *D_801277A0.local_1 = (param_0->local_3 * local_3 + param_0->local_5) + local_5 + local_4 * param_0->local_2;
                    D_801277A0.local_1++;
                }
            }
        }
    }
    *param_3 = D_801277A0.local_0;
    *param_4 = D_801277A0.local_1;
}

void func_800AA7FC(GridAA *param_0, s32 *param_1, s32 *param_2, u32 ***param_3, u32 ***param_4)
{
    s32 local_0[3];
    s32 local_1[3];
    s32 local_2;
    s32 local_3;
    s32 local_4;
    s32 local_5;
    s32 local_6;
    s32 local_7;
    if (!param_0->local_4) {
        D_801277A0.local_1 = D_801277A0.local_0;
        *D_801277A0.local_1++ = param_0->local_5;
        *param_3 = D_801277A0.local_0;
        *param_4 = D_801277A0.local_1;
        return;
    }
    for (local_2 = 0; local_2 < 3; local_2++) {
        if (param_1[local_2] >= 0) local_0[local_2] = (s32)param_1[local_2] / param_0->local_4;
        else local_0[local_2] = (s32)param_1[local_2] / param_0->local_4 - 1;
        if (param_2[local_2] >= 0) local_1[local_2] = (s32)param_2[local_2] / param_0->local_4;
        else local_1[local_2] = (s32)param_2[local_2] / param_0->local_4 - 1;
        if (local_0[local_2] < param_0->local_0[local_2]) local_0[local_2] = param_0->local_0[local_2];
        if (local_0[local_2] > param_0->local_1[local_2]) local_0[local_2] = param_0->local_1[local_2];
        if (local_1[local_2] < param_0->local_0[local_2]) local_1[local_2] = param_0->local_0[local_2];
        if (local_1[local_2] > param_0->local_1[local_2]) local_1[local_2] = param_0->local_1[local_2];
        local_0[local_2] -= param_0->local_0[local_2];
        local_1[local_2] -= param_0->local_0[local_2];
    }
    D_801277A0.local_1 = D_801277A0.local_0;
    for (local_3 = local_0[2]; local_3 <= local_1[2]; local_3++) {
        for (local_4 = local_0[1]; local_4 <= local_1[1]; local_4++) {
            for (local_5 = local_0[0]; local_5 <= local_1[0]; local_5++) {
                if (D_801277A0.local_1 < D_80127930) {
                    *D_801277A0.local_1 = (param_0->local_3 * local_3 + param_0->local_5) + local_5 + local_4 * param_0->local_2;
                    D_801277A0.local_1++;
                }
            }
        }
    }
    *param_3 = D_801277A0.local_0;
    *param_4 = D_801277A0.local_1;
}

void func_800AAAE0(u8 param_0[3][4])
{
    s32 local_0;
    s32 local_1;
    for (local_0 = 0; local_0 < 3; local_0++) {
        for (local_1 = 0; local_1 < 4; local_1++) {
            param_0[local_0][local_1] = (u32)(*((ColorAAAE0 *) D_80127938)).local_0[local_0][local_1];
        }
    }
}

void func_800AAD28(s32 param_0)
{
  u8 *var_s0;
  u8 *new_var;
  s32 var_s1;
 var_s0 = ((u8 *) D_80127938); new_var = ((u8 *) D_8012795C);
  var_s1 = param_0;
  do
  {
    func_800EE7F8(var_s1, var_s0);
    var_s0 += 0xC;
    var_s1 += 0xC;
  }
  while (var_s0 != new_var);
}

int func_800AAD80(u16 *param_0)
{
  s32 local_0;
  u32 local_1;
  u32 local_2;
  u32 *local_3;
  local_0 = 0;
  local_1 = (((u32) param_0) + (param_0[8] * 4)) + 0x18;
  local_2 = local_1 + (param_0[10] * 0xC);
  local_3 = (u32 *) local_1;
  while (local_3 < ((u32 *) local_2))
  {
    if (local_3[2] & 0x20020)
    {
      local_0++;
    }
    local_3 = (u32 *) (((u32) local_3) + 12);
  }
  return local_0;
}

u16 func_800AADE4(u16 *arg0)
{
    return arg0[10];
}

int func_800AADEC(f32 *param_0, f32 *param_1, f32 *param_2, f32 param_3) {
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3;
    f32 local_4;
    func_800EFB24(local_0, param_1, param_0);
    local_3 = func_800EEFD4(local_0);
    if (local_3 < 0.01f) return func_800EEB40(param_0, param_2) < param_3;
    local_4 = 1.0f / sqrtf(local_3);
    local_0[0] *= local_4;
    local_0[1] *= local_4;
    local_0[2] *= local_4;
    func_800EFB24(local_1, param_2, param_0);
    func_800EE97C(local_2, local_1, local_0);
    return func_800EEFD4(local_2) < param_3;
}

int func_800AAEF4(f32 *param_0, f32 param_1, f32 *param_2, f32 *param_3) {
    f32 local_0[3];
    f32 local_2;
    f32 local_1;
    f32 local_3;
    local_3 = param_1 * param_1;
    if (!func_800AADEC(param_2, param_3, param_0, local_3)) return 0;
    func_800EFA4C(local_0, (param_2[0] + param_3[0]) * 0.5f, (param_2[1] + param_3[1]) * 0.5f, (param_2[2] + param_3[2]) * 0.5f);
    local_1 = func_800EEB40(local_0, param_0);
    local_2 = func_800EEB40(local_0, param_2);
    if (local_2 + local_3 + (2.0f * local_3) * local_2 <= local_1) return 0;
    return 1;
}

int func_800AAFEC(f32 param_0[3], f32 param_1[3], s32 *param_2, s32 *param_3, f32 *param_4)
{
  s32 local_0;
  for (local_0 = 0; local_0 < 3; local_0++)
  {
    if (param_0[local_0] < param_1[local_0])
    {
      param_2[local_0] = param_0[local_0];
      param_3[local_0] = param_1[local_0];
    }
    else
    {
      param_2[local_0] = param_1[local_0];
      param_3[local_0] = param_0[local_0];
    }
    param_2[local_0]--;
    param_3[local_0]++;
  }

  func_800EFB24(param_4, param_1, param_0);
}

ABTri *func_800AB0BC(u8 *param_0, u8 *param_1, f32 *param_2, f32 *param_3, f32 *param_4, u32 param_5)
{
    s32 local_0;
    ABGeo **local_2;
    ABGeo **local_3;
    ABGeo **local_4;
    s32 local_33;
    s32 local_5[3];
    s32 local_6[3];
    f32 local_7[3];
    s32 local_34;
    ABTri *local_8;
    ABTri *local_9;
    ABTri *local_11;
    ABTri *local_10;
    f32 local_12[3];
    f32 local_13[3];
    f32 local_14[3];
    f32 local_15[3];
    s32 local_35;
    f32 local_16[3];
    f32 local_17[3];
    f32 local_18[3];
    f32 local_19;
    f32 local_20;
    f32 local_21;
    f32 local_22;
    f32 local_23;
    s32 local_36;
    s32 local_37;
    f32 local_24[3];
    s32 local_38;
    s32 local_39;
    f32 local_25[3][3];
    ABVertex *local_26;
    ABVertex *local_27;
    ABVertex *local_28;
    ABVertex *local_29;
    s32 local_30;
    s32 local_31;
    s32 local_32;

    /* Reject segments outside the vertex-list extent before visiting cells. */
    local_8 = 0;
    local_19 = (f32)(u32)*(u16 *)(param_1 + 0x14);
    func_800AAFEC(param_2, param_3, local_5, local_6, local_7);
    for (local_0 = 0; local_0 < 3; local_0++) {
        if (local_6[local_0] <= -local_19 || local_19 <= local_5[local_0]) return 0;
    }
    func_800AA7FC(param_0, local_5, local_6, &local_2, &local_4);
    for (local_3 = local_2; local_3 < local_4; local_3++) {
        local_9 = (ABTri *)(param_0 + 0x18 + *(u16 *)(param_0 + 0x10) * 4) + (*local_3)->start;
        local_10 = local_9 + (*local_3)->count;
        for (local_11 = local_9; local_11 < local_10; local_11++) {
            local_26 = (ABVertex *)(param_1 + 0x18);
            if (local_11->flags & param_5) continue;
            local_27 = &local_26[local_11->vertex[0]];
            local_28 = &local_26[local_11->vertex[1]];
            local_29 = &local_26[local_11->vertex[2]];
            /* Reject on each axis before converting that axis to float. */
            local_30 = local_27->pos[0]; 
            local_31 = local_28->pos[0]; 
            local_32 = local_29->pos[0]; 
            if (local_30 < local_5[0] && local_31 < local_5[0] && local_32 < local_5[0]) continue; 
            if (local_6[0] < local_30 && local_6[0] < local_31 && local_6[0] < local_32) continue; 
            local_25[0][0] = local_30; 
            local_25[1][0] = local_31; 
            local_25[2][0] = local_32;
            local_30 = local_27->pos[1]; 
            local_31 = local_28->pos[1]; 
            local_32 = local_29->pos[1]; 
            if (local_30 < local_5[1] && local_31 < local_5[1] && local_32 < local_5[1]) continue; 
            if (local_6[1] < local_30 && local_6[1] < local_31 && local_6[1] < local_32) continue; 
            local_25[0][1] = local_30; 
            local_25[1][1] = local_31; 
            local_25[2][1] = local_32;
            local_30 = local_27->pos[2]; 
            local_31 = local_28->pos[2]; 
            local_32 = local_29->pos[2]; 
            if (local_30 < local_5[2] && local_31 < local_5[2] && local_32 < local_5[2]) continue; 
            if (local_6[2] < local_30 && local_6[2] < local_31 && local_6[2] < local_32) continue; 
            local_25[0][2] = local_30; 
            local_25[1][2] = local_31; 
            local_25[2][2] = local_32;
            /* Form the plane normal; rescaling limits intermediate magnitude. */
            func_800EFB24(local_12, local_25[1], local_25[0]);
            func_800EFB24(local_13, local_25[2], local_25[0]);
            func_800EE97C(local_24, local_12, local_13);
            if (mlAbsF(local_24[0]) > 100000.0f || mlAbsF(local_24[1]) > 100000.0f || mlAbsF(local_24[2]) > 100000.0f) {
                local_24[0] *= 0.00001f;
                local_24[1] *= 0.00001f;
                local_24[2] *= 0.00001f;
            }
            func_800EFB24(local_14, param_2, local_25[0]);
            func_800EFB24(local_15, param_3, local_25[0]);
            local_19 = func_800EEAA4(local_14, local_24);
            local_20 = func_800EEAA4(local_15, local_24);
            if (local_19 >= 0.0f && local_20 >= 0.0f) continue;
            if (local_19 <= 0.0f && local_20 <= 0.0f) continue;
            /* Flag 0x10000 permits reversing the normal for a back-side hit. */
            if ((local_11->flags & 0x10000) && local_19 < 0.0f) {
                local_24[0] = -local_24[0];
                local_24[1] = -local_24[1];
                local_24[2] = -local_24[2];
            }
            local_20 = -func_800EEAA4(local_25[0], local_24);
            local_19 = func_800EEAA4(local_24, local_7);
            if (local_19 >= 0.0f) continue;
            local_19 = -(func_800EEAA4(local_24, param_2) + local_20) / local_19;
            if (local_19 <= 0.0f || 1.0f <= local_19) continue;
            func_800EFA4C(local_16, param_2[0] + local_7[0] * local_19, param_2[1] + local_7[1] * local_19, param_2[2] + local_7[2] * local_19);
            /* Drop the dominant normal axis and solve the 2D barycentric test. */
            local_33 = mlAbsF(local_24[0]) > mlAbsF(local_24[1]) ? 0 : 1;
            if (mlAbsF(local_24[2]) > mlAbsF(local_24[local_33])) local_33 = 2;
            local_0 = (local_33 + 1) % 3;
            func_800EFA4C(local_17, local_16[local_0] - local_25[0][local_0], local_12[local_0], local_13[local_0]);
            local_0 = (local_33 + 2) % 3;
            func_800EFA4C(local_18, local_16[local_0] - local_25[0][local_0], local_12[local_0], local_13[local_0]);
            local_21 = 1.0f / (local_17[1] * local_18[2] - local_18[1] * local_17[2]);
            local_22 = (local_17[0] * local_18[2] - local_18[0] * local_17[2]) * local_21;
            if (local_22 < 0.0f || 1.0f < local_22) continue;
            local_23 = (local_17[1] * local_18[0] - local_18[1] * local_17[0]) * local_21;
            if (local_23 < 0.0f || 1.0f < local_23 || 1.0f < local_22 + local_23) continue;
            /* Shortening the segment makes subsequent accepted hits nearer. */
            local_8 = local_11;
            func_800EE7F8(param_3, local_16);
            func_800EE7F8(param_4, local_24);
            func_800AAFEC(param_2, param_3, local_5, local_6, local_7);
        }
    }
    if (local_8) func_800EF2A0(param_4);
    func_800AA3B4(local_8, param_1);
    return local_8;
}

s32 func_800AB868(s32 param_0, s32 param_1, f32 *param_2, f32 *param_3, f32 param_4, s32 *param_5, s32 *param_6, s32 *param_7, s32 param_8)
{
  f32 local_0[3];
  f32 local_1[3];
  s32 local_2;
  s32 pad[2];
  s32 *local_3;

  func_80019CD4();
  func_8001980C(param_2, param_3, param_4, 0);
  func_800193C4(local_0, param_5);
  func_800193C4(local_1, param_6);
  local_2 = func_800AB0BC(param_0, param_1, local_0, local_1, param_7, param_8);
  if (local_2 == 0) {
    return 0;
  }
  func_80019CD4();
  func_80019750(param_2, param_3, param_4, 0);
  func_800193C4(param_6, local_1);
  local_3 = (s32 *) D_80127938; do {
    func_80019224(local_3, local_3);
    local_3 += 3;
  } while (local_3 != (s32 *) D_8012795C);
  func_80019CD4();
  func_80019750(0, param_3, 1.0f, 0);
  func_80019224(param_7, param_7);
  return local_2;
}

void func_800AB980()
{
  D_8012798C = heap_alloc(0x484);
  ((struct { int unk0; int unk1; int unk3; int unk2; } *)D_8012798C)->unk0 = 0;
  ((struct { int unk0; int unk1; int unk3; int unk2; } *)D_8012798C)->unk1 = 0;
  ((struct { int unk0; int unk1; int unk3; int unk2; } *)D_8012798C)->unk2 = 0xf;
  ((struct { int unk0; int unk1; int unk3; int unk2; } *)D_8012798C)->unk3 = 0x40000000;
}

void func_800AB9D0()
{
    void *s0 = D_8012798C;
    while (s0)
    {
        void *s1 = *((void **)s0 + 1);
        heap_free(s0);
        s0 = s1;
    }
    D_8012798C = 0;
}

void func_800ABA20(void) {
    NodeABA20 *local_0;
    NodeABA20 *local_1;
    local_0 = ((NodeABA20 *) D_8012798C);
    while (local_0 != 0) {
        local_1 = local_0;
        local_0 = defrag(local_0);
        if (local_0 != local_1) {
            if (local_0->local_0 != 0) local_0->local_0->local_1 = local_0;
            else D_8012798C = local_0;
            if (local_0->local_1 != 0) local_0->local_1->local_0 = local_0;
        }
        local_0 = local_0->local_1;
    }
}

void func_800ABA9C()
{
  void *local_0;
  void *next;
  s32 local_1;
  s32 local_2;
  void *temp_t9;
  next = func_8001211C();
  local_1 = ((s32) next) - 0x28;
  local_2 = local_1;
  local_0 = *((void **) (((char *) D_8012798C) + 4));
  if ((local_0 != 0) && (local_1 < (*((s32 *) (((char *) local_0) + 8)))))
  {
    do
    {
      local_0 = *((void **) (((char *) local_0) + 4));
      if (local_0 == 0)
      {
        break;
      }
    }
    while (local_2 < (*((s32 *) (((char *) local_0) + 8))));
  }
  if (local_0 != 0)
  {
    ;
    *((s32 *) (((char *) (*((void **) (((char *) local_0) + 0)))) + 4)) = 0;
    if (local_0 != 0)
    {
      do
      {
        next = *((void **) (((char *) local_0) + 4));
        heap_free(local_0);
        local_0 = next;
      }
      while (next != 0);
    }
  }
}

void func_800ABB34(s32 **param_0, s32 **param_1) {
    s32 *var_a0;

    *param_0 = (s32 *)((s8 *)*param_0 + 0x4C);
    if (((s32)*param_0 - (s32)*param_1 - 0x10) / 0x4C >= *(s32 *)((s8 *)*param_1 + 0xC)) {
        var_a0 = *(s32 **)((s8 *)*param_1 + 4);
        if (var_a0 == NULL) {
            *(s32 **)((s8 *)*param_1 + 4) = heap_alloc(0xEE8, param_1);
            *(s32 **)((s8 *)*(s32 **)((s8 *)*param_1 + 4)) = *param_1;
            *(s32 *)((s8 *)*(s32 **)((s8 *)*param_1 + 4) + 4) = 0;
            *(s32 *)((s8 *)*(s32 **)((s8 *)*param_1 + 4) + 0xC) = 0x32;
            var_a0 = *(s32 **)((s8 *)*param_1 + 4);
        }
        *param_1 = var_a0;
        *(s32 *)((s8 *)*param_1 + 8) = func_8001211C(var_a0, param_1, param_0);
        *param_0 = *param_1 + 4;
    }
}

void func_800ABC0C(s32 *param_0, s32 **param_1)
{
  s32 local_0;
  local_0 = (*param_0) + 0x4C;
  *param_0 = (*param_0) + 0x4C;
  if (((((*param_0) - ((s32)*param_1)) - 0x10) / 0x4C) >= (*param_1)[3])
  {
    *param_1 = (*param_1)[1];
    *param_0 = (s32)(*param_1) + 0x10;
  }
}

func_800ABC58(f32 *param_0, f32 *param_1, f32 param_2, f32 *param_3, f32 *param_4) {
    s32 local_0;
    for(local_0 = 0; local_0 < 3; local_0++){
        if(param_0[local_0] < param_1[local_0]){
            param_3[local_0] = param_0[local_0];
            param_4[local_0] = param_1[local_0];
        } else {
            param_3[local_0] = param_1[local_0];
            param_4[local_0] = param_0[local_0];
        }
        param_3[local_0] -= param_2;
        param_4[local_0] += param_2;
    }
}

s32 func_800ABCE0(u8 *param_0,u8 *param_1,f32 *param_2,f32 *param_3,f32 *param_4,f32 param_5,u32 param_6,LocalEntry **param_7)
{
    LocalGeo **local_0;
    LocalGeo **local_1;
    LocalGeo **local_2;
    f32 local_3[3];
    s32 local_4;
    s16 *local_17;
    f32 local_5[3];
    f32 local_6[3];
    s32 local_7;
    LocalTri_800ABCE0 *local_8;
    LocalTri_800ABCE0 *local_9;
    LocalTri_800ABCE0 *local_10;
    u8 *local_11;
    f32 local_12[3];
    f32 local_13[3];
    f32 local_14;
    LocalBlock *local_15;
    LocalEntry *local_16;
    func_800ABC58(param_2,param_3,param_5,local_5,local_6);
    local_14=*(u16 *)(param_1+0x14);
    for (local_4=0;local_4<3;local_4++) {
        if (local_6[local_4]<=-local_14 || local_14<=local_5[local_4]) return 0;
    }
    func_800AA4D4(param_0,local_5,local_6,&local_0,&local_2);
    local_15=((LocalBlock *) D_8012798C);
    local_16=local_15->entries;
    for (local_1=local_0;local_1<local_2;local_1++) {
        local_8=(LocalTri_800ABCE0 *)(param_0+*(u16 *)(param_0+0x10)*4+0x18)+(*local_1)->start;
        local_9=local_8+(*local_1)->count;
        for (local_10=local_8;local_10<local_9;local_10++) {
            local_11=param_1+0x18;
            if (local_10->flags & param_6) continue;
            for (local_4=0;local_4<3;local_4++) {
                local_17=(s16 *)(local_11+local_10->vertex[local_4]*0x10);
                func_800EE88C(local_16->points[local_4],local_17);
            }
            func_800EE7F8(local_12,local_16->points[0]);
            func_800EE7F8(local_13,local_16->points[0]);
            for (local_4=1;local_4<3;local_4++) {
                for (local_7=0;local_7<3;local_7++) {
                    if (local_16->points[local_4][local_7]<local_12[local_7]) local_12[local_7]=local_16->points[local_4][local_7];
                    if (local_13[local_7]<local_16->points[local_4][local_7]) local_13[local_7]=local_16->points[local_4][local_7];
                }
            }
            if (local_6[0]<local_12[0] || local_13[0]<local_5[0]) continue;
            if (local_6[1]<local_12[1] || local_13[1]<local_5[1]) continue;
            if (local_6[2]<local_12[2] || local_13[2]<local_5[2]) continue;
            func_800EFB24(local_16->edge0,local_16->points[1],local_16->points[0]);
            func_800EFB24(local_16->edge1,local_16->points[2],local_16->points[0]);
            func_800EE97C(local_16->normal,local_16->edge0,local_16->edge1);
            func_800EF2A0(local_16->normal);
            if (local_10->flags & 0x10000) {
                func_800EFB24(local_3,param_2,local_16->points[0]);
                if (func_800EEAA4(local_3,local_16->normal)<0.0f) {
                    local_16->normal[0]=-local_16->normal[0];
                    local_16->normal[1]=-local_16->normal[1];
                    local_16->normal[2]=-local_16->normal[2];
                }
            }
            if (func_800EEAA4(local_16->normal,param_4)>0.0f) continue;
            local_16->tri=local_10;
            func_800ABB34(&local_16,&local_15);
        }
    }
    *param_7=local_16;
    return local_16!=((LocalBlock *) D_8012798C)->entries;
}

LocalTriangle *func_800AC100(LocalTriangle *param_0, f32 *param_1, f32 param_2, f32 *param_3)
{
    s32 local_0;
    LocalTriangleBlock *local_1;
    LocalTriangle *local_2;
    f32 local_3[3][3];
    f32 local_4[3][3];
    f32 local_5;
    f32 local_6;
    f32 local_7;
    f32 local_8;
    f32 local_9;
    f32 local_10;
    f32 local_11[3];
    f32 local_12[3];
    u32 local_13;
    s32 local_14;
    s32 local_15;
    f32 local_16[3];
    LocalTriangle *local_17;
    f32 local_18;

    local_17 = NULL;
    local_5 = param_2 * param_2;
    func_800EFD24(param_3);
    local_1 = ((LocalTriangleBlock *) D_8012798C);
    for (local_2 = local_1->triangles; local_2 != param_0; func_800ABC0C(&local_2, &local_1)) {
        func_800EFB24(local_4[0], param_1, local_2->vertices[0]);
        local_9 = func_800EEAA4(local_4[0], local_2->normal);
        if (param_2 - 0.5f <= mlAbsF(local_9)) continue;

        local_16[0] = param_1[0] - local_2->normal[0] * local_9;
        local_16[1] = param_1[1] - local_2->normal[1] * local_9;
        local_16[2] = param_1[2] - local_2->normal[2] * local_9;
        local_15 = mlAbsF(local_2->normal[0]) > mlAbsF(local_2->normal[1]) ? 0 : 1;
        if (mlAbsF(local_2->normal[2]) > mlAbsF(local_2->normal[local_15])) local_15 = 2;

        func_800EFA4C(local_11, local_16[(local_15 + 1) % 3] - local_2->vertices[0][(local_15 + 1) % 3], local_2->edgeAB[(local_15 + 1) % 3], local_2->edgeAC[(local_15 + 1) % 3]);
        func_800EFA4C(local_12, local_16[(local_15 + 2) % 3] - local_2->vertices[0][(local_15 + 2) % 3], local_2->edgeAB[(local_15 + 2) % 3], local_2->edgeAC[(local_15 + 2) % 3]);
        local_18 = local_11[1] * local_12[2] - local_12[1] * local_11[2];
        if (local_18 == 0.0f) continue;
        local_18 = 1.0f / local_18;
        local_8 = (local_11[0] * local_12[2] - local_12[0] * local_11[2]) * local_18;
        local_7 = (local_11[1] * local_12[0] - local_12[1] * local_11[0]) * local_18;
        if (0.0f <= local_8 && local_8 <= 1.0f && 0.0f <= local_7 && local_7 <= 1.0f)
        if (local_8 + local_7 <= 1.0f) {
            local_17 = local_2;
            func_800EF04C(param_3, local_2->normal);
            continue;
        }
        for (local_0 = 0; local_0 < 3; local_0++) {
            func_800EFB24(local_4[local_0], param_1, local_2->vertices[local_0]);
            if (func_800EEFD4(local_4[local_0]) < local_5) {
                local_17 = local_2;
                func_800EF04C(param_3, local_2->normal);
                break;
            }
        }
        if (local_0 < 3) continue;
        for (local_0 = 0; local_0 < 3; local_0++) {
            func_800EFB24(local_3[local_0], local_2->vertices[(local_0 + 1) % 3], local_2->vertices[local_0]);
            local_10 = func_800EEFD4(local_3[local_0]);
            func_800EF2A0(local_3[local_0]);
            local_6 = func_800EEAA4(local_3[local_0], local_4[local_0]);
            if (0 <= local_6 && local_6 * local_6 <= local_10) {
                local_16[0] = local_4[local_0][0] - local_3[local_0][0] * local_6;
                local_16[1] = local_4[local_0][1] - local_3[local_0][1] * local_6;
                local_16[2] = local_4[local_0][2] - local_3[local_0][2] * local_6;
                if (func_800EEFD4(local_16) < local_5) {
                    local_17 = local_2;
                    func_800EF04C(param_3, local_2->normal);
                    break;
                }
            }
        }
    }
    return local_17;
}

void *func_800AC638(void *param_0, void *param_1, f32 *param_2, f32 *param_3, f32 param_4, f32 *param_5, s32 param_6, u32 param_7) {
    void *local_0;
    f32 local_1[3];
    f32 local_2, local_3, local_4;
    s32 local_5;
    f32 local_6[3];
    f32 local_7[3];
    HitAC638 *local_8;
    HitAC638 *local_9;
    f32 local_10[3];
    func_800EFB24(local_10, param_3, param_2);
    if (!func_800ABCE0(param_0, param_1, param_2, param_3, local_10, param_4 + 0.5f, param_7, &local_0)) return 0;
    local_8 = func_800AC100(local_0, param_3, param_4, local_7);
    if (!local_8) return 0;
    func_800EE7F8(param_5, local_7);
    func_800EFB24(local_1, param_3, param_2);
    func_800EE7F8(param_3, param_2);
    local_2 = 0.0f;
    local_3 = 1.0f;
    for (local_5 = 0; local_5 < param_6; local_5++) {
        local_4 = (local_2 + local_3) * 0.5f;
        local_6[0] = param_2[0] + local_1[0] * local_4;
        local_6[1] = param_2[1] + local_1[1] * local_4;
        local_6[2] = param_2[2] + local_1[2] * local_4;
        local_9 = func_800AC100(local_0, local_6, param_4, local_7);
        if (local_9) {
            local_3 = local_4;
            local_8 = local_9;
            func_800EE7F8(param_5, local_7);
        } else {
            local_2 = local_4;
            func_800EE7F8(param_3, local_6);
        }
    }
    if (!local_8) return 0;
    func_800EF2A0(param_5);
    func_800AA3B4(local_8->local_0, param_1);
    return local_8->local_0;
}

s32 func_800AC848(s32 param_0, s32 param_1, f32 *param_2, f32 *param_3, f32 param_4, f32 *param_5, f32 *param_6, f32 param_7, f32 *param_8, s32 param_9, s32 param_10) {
    f32 local_5[3];
    f32 local_0[3];
    s32 local_3;
    s32 local_1;
    func_80019CD4();
    func_8001980C(param_2, param_3, param_4, 0);
    func_80019224(local_5, param_5);
    func_80019224(local_0, param_6);
    local_1 = func_800AC638(param_0, param_1, local_5, local_0, param_7 / param_4, param_8, param_9, param_10);
    if (!local_1) return 0;
    func_80019CD4();
    func_80019750(param_2, param_3, param_4, 0);
    func_80019224(param_6, local_0);
    for (local_3 = 0; local_3 < 3; local_3++) func_80019224(D_80127938[local_3], D_80127938[local_3]);
    func_80019CD4();
    func_80019750(0, param_3, 1.0f, 0);
    func_80019224(param_8, param_8);
    return local_1;
}

ABTri *func_800AC978(u8 *param_0, u8 *param_1, f32 *param_2, f32 param_3, f32 *param_4, s32 param_5)
{
    ABGeo **local_0; /* start_geo in the BK twin */
    ABGeo **local_1;
    ABGeo **local_2;
    s32 local_3;
    f32 local_4[3];
    f32 local_5[3];
    s32 local_6;
    f32 local_7[3]; /* Accumulated contact normals. */
    ABTri *local_8;
    ABTri *local_32;
    u8 *local_29;
    u16 *local_30;
    ABTri *local_9;
    ABTri *local_10;
    f32 (*local_31)[3];
    f32 local_20;
    f32 local_21;
    f32 local_11[3][3]; /* Triangle edges; normalized during edge tests. */
    f32 local_12[3][3];
    f32 local_22;
    f32 local_23;
    f32 local_24;
    f32 local_13[3]; /* tri_normal */
    f32 local_14[3];
    f32 local_15[3];
    f32 local_25;
    f32 local_26;
    s32 local_27;
    f32 local_17[3];
    f32 local_18[3];
    f32 local_16[3];
    f32 local_19[3][3]; /* tri_vtx_coord */
    f32 local_28;
    ABGeo *local_33;

    /* Broad phase: expand the sphere bounds, then reject the entire model. */
    for (local_3 = 0; local_3 < 3; local_3++) {
        local_4[local_3] = param_2[local_3] - (param_3 + 0.5f);
        local_5[local_3] = param_2[local_3] + (param_3 + 0.5f);
    }
    local_20 = *(u16 *)(param_1 + 0x14);
    for (local_3 = 0; local_3 < 3; local_3++) {
        if (local_5[local_3] <= -local_20 || local_20 <= local_4[local_3]) return 0;
    }
    local_8 = 0;
    func_800EFD24(local_7);
    func_800AA4D4(param_0, local_4, local_5, &local_0, &local_2);
    for (local_1 = local_0; local_1 < local_2; local_1++) {
        local_32 = (ABTri *)(param_0 + 0x18 + *(u16 *)(param_0 + 0x10) * 4) + (*local_1)->start;
        local_10 = local_32 + (*local_1)->count;
        for (local_9 = local_32; local_9 < local_10; local_9++) {
            if (local_9->flags & param_5) continue;
            local_29 = param_1 + 0x18;
            for (local_3 = 0; local_3 < 3; local_3++) {
                local_30 = (u16 *)(local_29 + local_9->vertex[local_3] * 0x10);
                func_800EE88C(local_19[local_3], (s16 *)local_30);
            }
            func_800EE7F8(local_17, local_19[0]);
            func_800EE7F8(local_18, local_19[0]);
            for (local_3 = 1; local_3 < 3; local_3++) {
                for (local_6 = 0; local_6 < 3; local_6++) {
                    if (local_19[local_3][local_6] < local_17[local_6]) local_17[local_6] = local_19[local_3][local_6];
                    if (local_18[local_6] < local_19[local_3][local_6]) local_18[local_6] = local_19[local_3][local_6];
                }
            }
            if (local_5[0] < local_17[0] || local_18[0] < local_4[0]) continue;
            if (local_5[1] < local_17[1] || local_18[1] < local_4[1]) continue;
            if (local_5[2] < local_17[2] || local_18[2] < local_4[2]) continue;
            /* Reject degenerate triangles; orient two-sided faces toward us. */
            func_800EFB24(local_11[0], local_19[1], local_19[0]);
            func_800EFB24(local_11[1], local_19[2], local_19[0]);
            func_800EE97C(local_13, local_11[0], local_11[1]);
            func_800EF2A0(local_13);
            if (local_13[0] == 0.0f && local_13[1] == 0.0f && local_13[2] == 0.0f) continue;
            func_800EFB24(local_12[0], param_2, local_19[0]);
            if ((local_9->flags & 0x10000) && func_800EEAA4(local_12[0], local_13) < 0) {
                local_13[0] = -local_13[0];
                local_13[1] = -local_13[1];
                local_13[2] = -local_13[2];
            }
            local_21 = func_800EEAA4(local_12[0], local_13);
            if (param_3 - 0.5f <= mlAbsF(local_21)) continue;
            local_16[0] = param_2[0] - local_13[0] * local_21;
            local_16[1] = param_2[1] - local_13[1] * local_21;
            local_16[2] = param_2[2] - local_13[2] * local_21;
            /* Drop the dominant normal axis for the 2D barycentric test. */
            local_27 = mlAbsF(local_13[0]) > mlAbsF(local_13[1]) ? 0 : 1;
            if (mlAbsF(local_13[2]) > mlAbsF(local_13[local_27])) local_27 = 2;
            local_3 = (local_27 + 1) % 3;
            func_800EFA4C(local_14, local_16[local_3] - local_19[0][local_3], local_11[0][local_3], local_11[1][local_3]);
            local_3 = (local_27 + 2) % 3;
            func_800EFA4C(local_15, local_16[local_3] - local_19[0][local_3], local_11[0][local_3], local_11[1][local_3]);
            local_22 = 1.0f / (local_14[1] * local_15[2] - local_15[1] * local_14[2]);
            local_23 = (local_14[0] * local_15[2] - local_15[0] * local_14[2]) * local_22;
            if (local_23 >= 0 && local_23 <= 1.0f) {
                local_20 = local_15[0];
                local_20 = (local_14[1] * local_20 - local_15[1] * local_14[0]) * local_22;
                if (local_20 >= 0 && local_20 <= 1.0f && local_23 + local_20 <= 1.0f) {
                local_8 = local_9;
                func_800EF04C(local_7, local_13);
                continue;
            }
            }
            /* Outside the face: test the three vertices, then edge segments. */
            local_28 = param_3 * param_3;
            for (local_3 = 0; local_3 < 3; local_3++) {
                func_800EFB24(local_12[local_3], param_2, local_19[local_3]);
                if (func_800EEFD4(local_12[local_3]) < local_28) {
                    local_8 = local_9;
                    func_800EF04C(local_7, local_13);
                    break;
                }
            }
            if (local_3 < 3) continue;
            for (local_3 = 0; local_3 < 3; local_3++) {
                func_800EFB24(local_11[local_3], local_19[(local_3 + 1) % 3], local_19[local_3]);
                local_25 = func_800EEFD4(local_11[local_3]);
                func_800EF2A0(local_11[local_3]);
                local_26 = func_800EEAA4(local_11[local_3], local_12[local_3]);
                if (local_26 >= 0.0f && local_26 * local_26 <= local_25) {
                    local_16[0] = local_12[local_3][0] - local_11[local_3][0] * local_26;
                    local_16[1] = local_12[local_3][1] - local_11[local_3][1] * local_26;
                    local_16[2] = local_12[local_3][2] - local_11[local_3][2] * local_26;
                    if (func_800EEFD4(local_16) < local_28) {
                        local_8 = local_9;
                        func_800EF04C(local_7, local_13);
                        break;
                    }
                }
            }
        }
    }
    if (local_8 != 0) func_800EF410(param_4, local_7);
    func_800AA3B4(local_8, param_1);
    return local_8;
}

s32 func_800AD1AC(s32 param_0, s32 param_1, f32 *param_2, f32 *param_3, f32 param_4, f32 *param_5, f32 param_6, f32 *param_7, s32 param_8) {
    f32 local_0[3];
    s32 local_3;
    s32 local_1;
    s32 local_4;
    f32 (*local_2)[3];
    func_80019CD4();
    func_8001980C(param_2, param_3, param_4, 0);
    func_80019224(local_0, param_5);
    local_1 = func_800AC978(param_0, param_1, local_0, param_6 / param_4, param_7, param_8);
    if (!local_1) return 0;
    func_80019CD4();
    func_80019750(param_2, param_3, param_4, 0);
    func_80019224(param_5, local_0);
    for (local_3 = 0; local_3 < 3; local_3++) func_80019224(D_80127938[local_3], D_80127938[local_3]);
    func_80019CD4();
    func_80019750(0, param_3, 1.0f, 0);
    func_80019224(param_7, param_7);
    return local_1;
}

s32 func_800AD2C8(LocalModel *param_0, void *param_1, f32 *param_2, f32 *param_3, f32 *param_4, LocalOutput **param_5, s32 param_6, f32 param_7)
{
    s32 local_0;
    s32 local_1;
    s32 local_2 = 0;
    LocalGroup **local_3;
    LocalGroup **local_4;
    LocalGroup **local_5;
    LocalVertex *local_6;
    LocalTri_800AD2C8 *local_7;
    LocalTri_800AD2C8 *local_8;
    s32 local_9[3];
    s32 local_10[3];
    s32 local_11[3];
    s32 local_12[3];
    s32 local_13[3];
    s32 local_14[3][3];
    s32 local_15[3];
    s32 local_16[3];
    LocalCachedTri *local_17;
    LocalVertex *local_18;
    LocalTri_800AD2C8 *local_20;
    f32 local_19[3];

    for (local_0 = 0; local_0 < 3; local_0++) {
        local_9[local_0] = param_2[local_0] - param_4[local_0];
        local_10[local_0] = param_3[local_0] - param_4[local_0];
        local_11[local_0] = param_4[local_0];
    }
    func_800AA7FC(param_0, local_9, local_10, &local_3, &local_4);
    local_6 = func_800B2190(param_1);
    D_80127990.end = D_80127990.triangles;
    for (local_5 = local_3; local_5 < local_4; local_5++) {
        local_20 = (LocalTri_800AD2C8 *)((u8 *)param_0 + param_0->groupCount * 4 + 0x18) + (*local_5)->first;
        local_7 = local_20 + (*local_5)->count;
        for (local_8 = local_20; local_2 < param_6 && local_8 < local_7; local_8++) {
            if (local_8->flags & 0x20020) continue;
            local_18 = local_6 + local_8->index[0];
            local_12[0] = local_13[0] = local_18->position[0];
            local_12[1] = local_13[1] = local_18->position[1];
            local_12[2] = local_13[2] = local_18->position[2];
            func_800EE8CC(local_14[0], local_18->position);
            for (local_0 = 1; local_0 < 3; local_0++) {
                local_18 = local_6 + local_8->index[local_0];
                for (local_1 = 0; local_1 < 3; local_1++) {
                    if (local_18->position[local_1] < local_12[local_1]) local_12[local_1] = local_18->position[local_1];
                    if (local_13[local_1] < local_18->position[local_1]) local_13[local_1] = local_18->position[local_1];
                }
                func_800EE8CC(local_14[local_0], local_18->position);
            }
            if (local_13[0] < local_9[0] || local_10[0] < local_12[0]) continue;
            if (local_13[1] < local_9[1] || local_10[1] < local_12[1]) continue;
            if (local_13[2] < local_9[2] || local_10[2] < local_12[2]) continue;
            for (local_17 = D_80127990.triangles; local_17 < D_80127990.end; local_17++) {
                if (local_14[0][0] == local_17->position[0][0] &&
                    local_14[0][1] == local_17->position[0][1] &&
                    local_14[0][2] == local_17->position[0][2] &&
                    local_14[1][0] == local_17->position[1][0] &&
                    local_14[1][1] == local_17->position[1][1] &&
                    local_14[1][2] == local_17->position[1][2] &&
                    local_14[2][0] == local_17->position[2][0] &&
                    local_14[2][1] == local_17->position[2][1] &&
                    local_14[2][2] == local_17->position[2][2]) break;
            }
            if (local_17 != D_80127990.end) continue;
            func_800EFB58(local_15, local_14[1], local_14[0]);
            func_800EFB58(local_16, local_14[2], local_14[0]);
            func_800EE9EC(local_19, local_15, local_16);
            if (local_19[1] <= 0.0f) continue;
            func_800EF2A0(local_19);
            if (local_19[1] < param_7) continue;
            if (D_80127990.end - D_80127990.triangles < 64) {
                D_80127990.end->position[0][0] = local_14[0][0];
                D_80127990.end->position[0][1] = local_14[0][1];
                D_80127990.end->position[0][2] = local_14[0][2];
                D_80127990.end->position[1][0] = local_14[1][0];
                D_80127990.end->position[1][1] = local_14[1][1];
                D_80127990.end->position[1][2] = local_14[1][2];
                D_80127990.end->position[2][0] = local_14[2][0];
                D_80127990.end->position[2][1] = local_14[2][1];
                D_80127990.end->position[2][2] = local_14[2][2];
                D_80127990.end++;
            }
            if (local_2 < param_6) {
                for (local_0 = 0; local_0 < 3; local_0++) {
                    for (local_1 = 0; local_1 < 3; local_1++) {
                        (*param_5)->position[local_0][local_1] = local_14[local_0][local_1] + local_11[local_1];
                    }
                }
                (*param_5)++;
                local_2++;
            }
        }
    }
    return local_2;
}

s32 func_800AD894(ModelAD894 *param_0, void *param_1, f32 *param_2, f32 *param_3, f32 *param_4, f32 *param_5, f32 param_6)
{
    s32 local_18;
    s32 local_19;
    GroupAD894 **local_0;
    GroupAD894 **local_1;
    GroupAD894 **local_2;
    VertexAD894 *local_3;
    TriAD894 *local_4;
    TriAD894 *local_5;
    s32 local_6[3];
    s32 local_7[3];
    s32 local_8[3];
    s32 local_9[3];
    s32 local_10[3];
    s32 local_11[3];
    s32 local_12[3][3];
    s32 local_13[3];
    s32 local_14[3];
    TriAD894 *local_21;
    VertexAD894 *local_20;
    f32 local_17[3];
    for (local_18 = 0; local_18 < 3; local_18++) {
        local_6[local_18] = param_2[local_18] - param_5[local_18];
        local_7[local_18] = param_3[local_18] - param_5[local_18];
    }
    for (local_18 = 0; local_18 < 3; local_18++) local_8[local_18] = local_6[local_18] < local_7[local_18] ? local_6[local_18] : local_7[local_18];
    for (local_18 = 0; local_18 < 3; local_18++) local_9[local_18] = local_7[local_18] < local_6[local_18] ? local_6[local_18] : local_7[local_18];
    func_800AA7FC(param_0, local_8, local_9, &local_0, &local_1);
    local_3 = func_800B2190(param_1);
    for (local_2 = local_0; local_2 < local_1; local_2++) {
        local_21 = (TriAD894 *)((u8 *)param_0 + param_0->local_0 * 4 + 0x18) + (*local_2)->local_0;
        local_4 = local_21 + (*local_2)->local_1;
        for (local_5 = local_21; local_5 < local_4; local_5++) {
            local_20 = local_5->local_0[0] + local_3;
            local_10[0] = local_11[0] = local_20->local_0[0];
            local_10[1] = local_11[1] = local_20->local_0[1];
            local_10[2] = local_11[2] = local_20->local_0[2];
            func_800EE8CC(local_12[0], local_20->local_0);
            for (local_18 = 1; local_18 < 3; local_18++) {
                local_20 = local_5->local_0[local_18] + local_3;
                for (local_19 = 0; local_19 < 3; local_19++) {
                    if (local_20->local_0[local_19] < local_10[local_19]) local_10[local_19] = local_20->local_0[local_19];
                    if (local_11[local_19] < local_20->local_0[local_19]) local_11[local_19] = local_20->local_0[local_19];
                }
                func_800EE8CC(local_12[local_18], local_20->local_0);
            }
            if (local_11[0] < local_8[0] || local_9[0] < local_10[0] || local_11[1] < local_8[1] || local_9[1] < local_10[1] || local_11[2] < local_8[2] || local_9[2] < local_10[2]) continue;
            func_800EFB58(local_13, local_12[1], local_12[0]);
            func_800EFB58(local_14, local_12[2], local_12[0]);
            func_800EE9EC(local_17, local_13, local_14);
            func_800EF2A0(local_17);
            if (local_17[1] <= param_6 && func_800EEAA4(local_17, param_4) > 0.0f) continue;
            if (func_800EED58(local_7, local_12[0]) && func_800EED58(local_6, local_12[1])) return 0;
            if (func_800EED58(local_7, local_12[1]) && func_800EED58(local_6, local_12[2])) return 0;
            if (func_800EED58(local_7, local_12[2]) && func_800EED58(local_6, local_12[0])) return 0;
        }
    }
    return 1;
}
