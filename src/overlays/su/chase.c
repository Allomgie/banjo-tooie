#include "common.h"

typedef struct { s32 frame; s32 count; } ChaseCache;
extern ChaseCache D_808001D0_suchase;
extern void func_8010D254(f32 *);
typedef struct { u8 pad_0[0x64]; u32 pad_1 : 1; u32 local_0 : 1; u32 local_1 : 1; u32 pad_2 : 29; } ChaseActorFlags;
typedef struct { Unk80132ED0 *local_0; u32 pad_0; u32 local_1; } ChaseActorEntry;
extern s32 *func_800BE444(f32 *);
extern ChaseActorEntry *func_800E9E88(s32);
extern ChaseActorEntry *func_800E9EB4(s32);
extern Actor *func_80106790(Unk80132ED0 *);
extern f32 func_800EEB40(f32 *, f32 *);
void func_808000A8_suchase();

s32 suchase_entrypoint_0(void)
{
    s32 local_1;
    f32 local_0[3];

    local_1 = func_8001211C();
    if (local_1 != D_808001D0_suchase.frame) {
        func_8010D254(local_0);
        D_808001D0_suchase.frame = local_1;
        D_808001D0_suchase.count = 0;
        func_808000A8_suchase(&D_808001D0_suchase, local_0);
    }
    return D_808001D0_suchase.count;
}

int suchase_entrypoint_1(s32 *param_0) {
    s32 local_0 = suchase_entrypoint_0();
    return local_0 == 0 || local_0 == *param_0;
}

void func_808000A8_suchase(param_0, param_1) ChaseCache *param_0; f32 *param_1;
{
    f32 local_0;
    s32 *local_1;
    ChaseActorEntry *local_2;
    ChaseActorEntry *local_3;
    Unk80132ED0 *local_4;
    Actor *local_5;
    f32 local_6;

    local_0 = 1e10f;
    local_1 = func_800BE444(param_1);
    while (*local_1) {
        local_2 = func_800E9E88(*local_1);
        local_3 = func_800E9EB4(*local_1);
        for (; local_2 < local_3; local_2++) {
            if (local_2->local_1 & 1) {
                local_4 = local_2->local_0;
                if (*(u16 *)((u8 *)local_4 + 0x18) & 1) {
                    local_5 = func_80106790(local_4);
                    if (!((ChaseActorFlags *)local_5)->local_1 &&
                        ((ChaseActorFlags *)local_5)->local_0) {
                        local_6 = func_800EEB40(local_5->position, param_1);
                        if (local_6 < local_0) {
                            param_0->count = (s32)local_4;
                            local_0 = local_6;
                        }
                    }
                }
            }
        }
        local_1++;
    }
}
