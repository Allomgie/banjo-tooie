#include "core2/1EDA900.h"

extern s32 D_80135A70;
extern float D_80135A7C;
typedef struct { u8 pad[0x74]; u32 unk74_0:3; u32 flag:1; u32 rest:28; } Actor108C;
extern s32 *func_80081D34(s32 *);
extern s32 func_80081D80(s32 *);
extern s32 *func_80100368(Actor *);
extern s32 func_800819B4(s32 *, s32);
extern Actor *func_80106790(Unk80132ED0 *);
extern Actor *func_801067C4();
extern f32 func_800EEB40(f32 *, f32 *);
typedef struct { Unk80132ED0 *local_0; s32 local_1; u32 local_2; } Entry1013;
extern void **func_800BE3F8(void);
extern void *func_800BDC44(void);
extern s32 func_800BDC5C(void);
extern Entry1013 *func_800E9E88();
extern Unk80132ED0* D_80135A80;

int func_80101010(s32 param_0)
{
  s32 local_0;
  local_0 = param_0 | 0;
  func_800EE7F8(&D_80135A70, local_0);
}

void func_80101038(s32 param_0) {
    func_800EE7F8(param_0, &D_80135A70);
}

void func_8010105C(f32 param_0)
{
  D_80135A7C = param_0;
}

float func_80101068()
{
  return D_80135A7C;
}

void func_80101074(s32 param_0)
{
  D_80135A80 = param_0;
}

Unk80132ED0* func_80101080()
{
    return D_80135A80;
}

s32 func_8010108C(Actor *param_0, s32 param_1, s32 param_2) {
    s32 *local_2;
    s32 local_0;
    s32 local_1;
    s32 *local_3;

    if (((Actor108C *)param_0)->flag) {
        local_3 = func_80081D34(*(s32 **)((char *)param_0 + 0x10));
        if (local_3 != 0) {
            local_1 = func_80081D80(local_3);
        } else {
            local_1 = 0;
        }
        local_2 = func_80100368(param_0);
        local_0 = (*(s32 (**)(Actor *, s32, s32))((char *)local_2 + 0x40))(param_0, param_1, param_2);
        if (local_3 != 0 && local_1 == 0 && local_0 <= 0) {
            func_800819B4(*(s32 **)((char *)param_0 + 0x10), local_0);
        }
        return local_0;
    }
    return -1;
}

s32 func_8010114C(s32 param_0, s32 param_1, s32 param_2) {
    extern s32 func_8010108C();
    return func_8010108C(func_80106790((Unk80132ED0 *)param_0), param_1, param_2);
}

s32 func_80101180(s32 param_0, s32 param_1, s32 param_2) {
    extern s32 func_8010108C();
    Actor *local_1;
    s32 local_0;
    s32 local_2 = 0;
    s32 local_3;
    for (local_1 = func_801067C4(&local_0); local_1; local_1 = func_8010682C(&local_0)) {
        if (!local_1->unk64_17 && ((*(u32 *)((u8 *)local_1 + 0x6C) << 11) >> 20) == param_0) {
            local_3 = func_8010108C(local_1, param_1, param_2);
            if (local_3 > 0 && !local_2) local_2 = local_3;
        }
    }
    return local_2;
}

s32 func_80101238(s32 param_0, s32 param_1) {
    extern s32 func_8010108C();
    Actor *local_1;
    s32 local_0;
    s32 local_2 = 0;
    s32 local_3;
    for (local_1 = func_801067C4(&local_0); local_1; local_1 = func_8010682C(&local_0)) {
        if (!local_1->unk64_17) {
            local_3 = func_8010108C(local_1, param_0, param_1);
            if (local_3 > 0 && !local_2) local_2 = local_3;
        }
    }
    return local_2;
}

s32 func_801012D0(f32 *param_0, f32 param_1, s32 param_2, s32 param_3) {
    extern s32 func_8010108C();
    Actor *local_1;
    s32 local_0;
    s32 local_2 = 0;
    s32 local_3;
    param_1 *= param_1;
    for (local_1 = func_801067C4(&local_0); local_1; local_1 = func_8010682C(&local_0)) {
        if (!local_1->unk64_17 && func_800EEB40(local_1->position, param_0) < param_1) {
            local_3 = func_8010108C(local_1, param_2, param_3);
            if (local_3 > 0 && !local_2) local_2 = local_3;
        }
    }
    return local_2;
}

s32 func_801013A8(f32 *param_0, s32 param_1, s32 param_2) {
    extern s32 func_8010108C();
    Entry1013 *local_0;
    Entry1013 *local_1;
    s32 local_2;
    s32 local_3;
    void **local_4;
    void *local_5;
    Actor *local_6;
    f32 local_7;
    Entry1013 *local_8;
    Unk80132ED0 *local_9;
    local_4 = func_800BE3F8();
    local_2 = 0;
    for (; *local_4; local_4++) {
        local_0 = func_800E9E88(*local_4);
        local_1 = func_800E9EB4(*local_4);
        for (; local_0 < local_1; local_0++) {
            if ((local_0->local_2 & 1) && (local_9 = local_0->local_0, *(u16 *)((u8 *)local_9 + 0x18) & 1)) {
                local_3 = func_8010114C((s32)local_9, param_1, param_2);
                if (local_3 > 0 && !local_2) local_2 = local_3;
            }
        }
    }
    local_5 = func_800BDC44();
    local_0 = func_800E9E88(local_5);
    local_8 = func_800E9EB4(local_5);
    for (; local_0 < local_8; local_0++) {
        if ((local_0->local_2 & 1) && (local_9 = local_0->local_0, *(u16 *)((u8 *)local_9 + 0x18) & 1)) {
            local_6 = func_80106790(local_9);
            local_7 = func_800EEB40(local_6->position, param_0);
            if (local_7 < (1.5f * func_800BDC5C()) * (func_800BDC5C() * 1.5f)) {
                func_8010108C(local_6, param_1, param_2);
                if (local_3 > 0 && !local_2) local_2 = local_3;
            }
        }
    }
    return local_2;
}
