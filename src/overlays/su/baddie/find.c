#include "common.h"

extern Actor *func_801067C4(s32 *);
extern Actor *func_8010682C(s32 *);
extern f32 func_800EEB40(f32 *, f32 *);
typedef struct ActorSearchProp { Unk80132ED0 *local_0; u32 pad_0; u32 local_1; } ActorSearchProp;
extern Actor **func_8010413C(void);
extern void **func_800BE3F8(f32 *);
extern void *func_800E9E88(void *);
extern void *func_800E9EB4(void *);
extern Actor *func_80106790(Unk80132ED0 *);
extern f32 func_800EEAD4(f32 *, f32 *);
Actor *subaddiefind_entrypoint_11();

Actor *subaddiefind_entrypoint_0(f32 *param_0, s32 param_1, s32 param_2, f32 *param_3)
{
    f32 local_1;
    f32 local_2;
    s32 local_3;
    Actor *local_4;
    s32 local_0;
    Actor *local_5;

    local_2 = 0.0f;
    local_4 = NULL;
    local_3 = 0;
    local_5 = func_801067C4(&local_0);
    while (local_5) {
        if ((param_1 == local_5->unk6C_9 || param_1 < 0) &&
            param_2 != local_5->unk70_10 && local_5->unk6C_9 != 0x215 &&
            local_5->unk6C_9 != 0x243 && !local_5->unk64_17) {
            local_1 = func_800EEB40(param_0, local_5->position);
            if (local_1 < local_2 || !local_3) {
                local_2 = local_1;
                local_4 = local_5;
                local_3 = 1;
            }
        }
        local_5 = func_8010682C(&local_0);
    }
    if (param_3) {
        *param_3 = sqrtf(local_2);
    }
    return local_4;
}

Actor *subaddiefind_entrypoint_1(Actor *param_0, s32 param_1, s32 param_2, f32 *param_3)
{
    f32 local_1;
    Actor *local_2;
    Actor *local_3;
    s32 local_0;

    local_2 = 0;
    local_1 = 1e10f;
    local_3 = func_801067C4(&local_0);
    while (local_3) {
        if ((param_1 == local_3->unk6C_9 || param_1 < 0) &&
            param_2 != local_3->unk70_10 && local_3->unk6C_9 != 0x215 &&
            local_3->unk6C_9 != 0x243 && !local_3->unk64_17 &&
            local_3->unk0 != param_0->unk0) {
            f32 local_4 = func_800EEAD4(param_0->position, local_3->position);
            if (local_4 < local_1) {
                local_1 = local_4;
                local_2 = local_3;
            }
        }
        local_3 = func_8010682C(&local_0);
    }
    if (param_3) {
        *param_3 = local_1;
    }
    return local_2;
}

Actor *subaddiefind_entrypoint_2(s32 param_0, s32 *param_1)
{
    Actor *local_1;
    s32 local_0;

    for (local_1 = func_801067C4(&local_0); local_1 != NULL;
         local_1 = func_8010682C(&local_0)) {
        if (param_0 == local_1->unk6C_9 && !local_1->unk64_17) {
            if (param_1 != NULL) {
                *param_1 = local_0;
            }
            return local_1;
        }
    }
    return NULL;
}

u8 *subaddiefind_entrypoint_3(s32 param_0, s32 param_1)
{
  Actor *var_v0;
  Actor *var_v1;
  var_v0 = func_8010682C(param_1);
  var_v1 = var_v0;
  if (var_v0 != NULL) {
loop_1:
    if ((param_0 == ((u32)(*(s32 *)((u8 *)var_v0 + 0x6C) << 11) >> 20)) && !var_v0->unk64_17) {
      return (u8 *)var_v1;
    }
    var_v0 = func_8010682C(param_1);
    var_v1 = var_v0;
    if (var_v0 == NULL) goto block_5;
    goto loop_1;
  }
block_5:
  return NULL;
}

s32 subaddiefind_entrypoint_4(s32 param_0, Actor **param_1, s32 param_2)
{
    Actor *local_1;
    s32 local_0;
    s32 local_2;

    local_2 = 0;

    for (local_1 = func_801067C4(&local_0); local_1 != NULL;
         local_1 = func_8010682C(&local_0)) {
        if (param_0 == local_1->unk6C_9 && !local_1->unk64_17) {
            local_2++;
            *param_1++ = local_1;
            if (local_2 == param_2) {
                return local_2;
            }
        }
    }
    return local_2;
}

s32 subaddiefind_entrypoint_5(s32 param_0, Actor **param_1, s32 param_2, f32 *param_3, f32 param_4, f32 (*param_5)(f32 *, f32 *))
{
    Actor *local_1;
    s32 local_0;
    s32 local_2 = 0;

    param_4 *= param_4;
    for (local_1 = func_801067C4(&local_0); local_1 != NULL; local_1 = func_8010682C(&local_0)) {
        if (local_1->unk6C_9 == param_0 && !local_1->unk64_17 && param_5(param_3, local_1->position) < param_4) {
            *param_1++ = local_1;
            local_2++;
            if (local_2 == param_2) {
                return local_2;
            }
        }
    }
    return local_2;
}

s32 subaddiefind_entrypoint_6(s16 *param_0, Actor **param_1, s32 param_2)
{
    s32 local_1;
    Actor *local_2;
    s32 local_0;
    s16 *local_3;

    local_1 = 0;
    for (local_2 = func_801067C4(&local_0); local_2; local_2 = func_8010682C(&local_0)) {
        if (!local_2->unk64_17) {
            for (local_3 = param_0; *local_3 != -1; local_3++) {
                if (local_2->unk6C_9 == *local_3) {
                    local_1++;
                    *param_1++ = local_2;
                    if (local_1 == param_2) return local_1;
                }
            }
        }
    }
    return local_1;
}

s32 subaddiefind_entrypoint_7(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 local_1;
    Actor *local_0;
    local_0 = subaddiefind_entrypoint_0(param_0->position, param_1, -1, &local_1);
    if (local_0 && local_1 < param_2) param_0->unk3C = local_0->unk0;
    else param_0->unk3C = NULL;
    return param_0->unk3C ? local_1 : -1.0f;
}

Actor *subaddiefind_entrypoint_8(s32 param_0)
{
    Actor *local_1;
    s32 local_0;

    for (local_1 = func_801067C4(&local_0); local_1 != NULL;
         local_1 = func_8010682C(&local_0)) {
        if (param_0 == ((u32)*(u16 *)((u8 *)local_1->unk0 + 0x12) >> 1) && !local_1->unk64_17) {
            return local_1;
        }
    }
    return NULL;
}

s32 subaddiefind_entrypoint_9(s32 param_0)
{
    Actor *local_1;
    s32 local_2 = 0;
    s32 local_0;

    for (local_1 = func_801067C4(&local_0); local_1 != NULL;
         local_1 = func_8010682C(&local_0)) {
        if (param_0 == local_1->unk6C_9 && !local_1->unk64_17) {
            local_2++;
        }
    }
    return local_2;
}

s32 subaddiefind_entrypoint_10(u8 *param_0, s32 param_1, s32 param_2) {
    s32 *local_0 = subaddiefind_entrypoint_11(param_1, param_2);
    if (local_0 != NULL) {
        *(s32 *)(param_0 + 0x3C) = *local_0;
    } else {
        *(s32 *)(param_0 + 0x3C) = 0;
    }
    return (*(s32 *)(param_0 + 0x3C) != 0) ? 1 : 0;
}

Actor *subaddiefind_entrypoint_11(param_0, param_1) s32 param_0; s32 param_1;
{
    Actor *local_0[20];
    s32 local_1;
    s32 local_2;

    local_1 = subaddiefind_entrypoint_4(param_0, local_0, 20);
    for (local_2 = 0; local_2 < local_1; local_2++) {
        if (local_0[local_2]->unk74_7 == param_1) {
            return local_0[local_2];
        }
    }
    return NULL;
}

Actor *subaddiefind_entrypoint_12(s32 param_0)
{
    Actor *local_1;
    s32 local_0;

    for (local_1 = func_801067C4(&local_0); local_1 != NULL;
         local_1 = func_8010682C(&local_0)) {
        if (!local_1->unk64_17 && param_0 == (*(u32 *)((u8 *)local_1 + 0x6C) >> 21)) {
            return local_1;
        }
    }
    return NULL;
}

Actor **subaddiefind_entrypoint_13(f32 *param_0)
{
    ActorSearchProp *local_0;
    s32 local_1;
    ActorSearchProp *local_2;
    Actor **local_3;
    void **local_4;
    Actor *local_5;

    local_3 = func_8010413C();
    local_1 = 0;
    for (local_4 = func_800BE3F8(param_0); *local_4; local_4++) {
        local_0 = func_800E9E88(*local_4);
        local_2 = func_800E9EB4(*local_4);
        for (; local_0 < local_2; local_0++) {
            if ((local_0->local_1 & 1) && (*(u16 *)((u8 *)local_0->local_0 + 0x18) & 1)) {
                local_5 = func_80106790(local_0->local_0);
                if (!local_5->unk64_17) {
                    local_3[local_1++] = local_5;
                }
            }
        }
    }
    local_3[local_1] = NULL;
    return local_3;
}
