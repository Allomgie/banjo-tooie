#include "common.h"

#define CH_ANIM_CALLBACK_WORD_DEFINED
extern void _chanim_entrypoint_0(Unk80132ED0 *, s32);
typedef union { s32 local_0; Unk80132ED0 *local_1; f32 local_2; } ChAnimCallbackWord;
extern void _anseq_entrypoint_2(Actor *, f32, void (*)(Unk80132ED0 *, s32), s32, s32);
extern void _chanim_entrypoint_1(Unk80132ED0 *, s32, s32);
extern void _anseq_entrypoint_3(void *, f32, void (*)(Unk80132ED0 *, s32, s32), s32, s32, s32);
extern void _chanim_entrypoint_2(Unk80132ED0 *, s32, s32);
extern void _anseq_entrypoint_5(s32);
typedef struct { s16 unk0; s16 pad2; s32 slots[60]; s32 unkF4; s32 unkF8; } AnimSeqData;
extern void func_80100074(Actor *, s32, s32);
extern s16 *func_80100094(s32, s32);
extern s16 _anseq_entrypoint_6();
extern void func_800DF758(void *);
extern void *func_80104248(Actor *);
typedef struct { s16 local_0; u8 pad_0[0xF2]; s32 local_1; s32 local_2; } CodexActorAnimation;

void chanim_entrypoint_0(s32 param_0, s32 param_1) {
    (*(s32 *)((char *)func_80100094(func_80106790(), 0) + (param_1 * 4) + 4)) = 0;
}

void chanim_entrypoint_1(s32 param_0, s32 param_1, s32 param_2) {
    (*(s32 *)((s8 *)func_80100094(func_80106790(), 0) + (param_1 * 4) + (4))) = param_2;
}

void chanim_entrypoint_2(s32 param_0, s32 param_1, s32 param_2) {
    s32 local_1;
    s32 *local_0;

    local_1 = func_80106790();
    local_0 = func_80100094(local_1, 0);
    local_0[param_1 + 1] = func_800DC128(0, param_2 + 1);
}

void chanim_entrypoint_3(Actor *param_0, f32 param_1, ChAnimCallbackWord param_2, s32 param_3)
{
    _anseq_entrypoint_2(param_0, param_1, _chanim_entrypoint_0, param_2.local_0, param_3);
}

void chanim_entrypoint_4(void *param_0, f32 param_1, ChAnimCallbackWord param_2, s32 param_3, s32 param_4)
{
    _anseq_entrypoint_3(param_0, param_1, _chanim_entrypoint_1, param_2.local_0, param_3, param_4);
}

void chanim_entrypoint_5(void *param_0, f32 param_1, ChAnimCallbackWord param_2, s32 param_3, s32 param_4)
{
    _anseq_entrypoint_3(param_0, param_1, _chanim_entrypoint_2, param_2.local_0, param_3, param_4);
}

void chanim_entrypoint_6(s32 param_0) {
    s16 *local_0 = func_80100094(param_0, 0);
    if (*local_0 != 0) {
        _anseq_entrypoint_5(*local_0);
    }
    *local_0 = 0;
}

void chanim_entrypoint_7(Actor *param_0, s32 param_1)
{
    s32 local_1;
    AnimSeqData *local_0;

    func_80100074(param_0, 0, sizeof(AnimSeqData));
    local_0 = func_80100094(param_0, 0);
    local_0->unk0 = 0;
    local_0->unkF8 = 0;
    local_0->unkF4 = param_1;
    for (local_1 = 0; local_1 < 60; local_1++) {
        local_0->slots[local_1] = 0;
    }
    if (local_0->unkF4) {
        local_0->unk0 = _anseq_entrypoint_6();
    }
}

void chanim_entrypoint_8(Actor *param_0)
{
  void *local_0;
  if (func_80104248(param_0) != 0)
  {
    local_0 = func_80100094(param_0, 0);
    if ((*((short *) local_0)) != 0)
    {
      func_800DF758(((char *) local_0) + 4);
    }
  }
}

void chanim_entrypoint_9(Actor *param_0)
{
    int local_1;
    CodexActorAnimation *local_2;
    int local_0;

    local_2 = func_80100094(param_0, 0);
    if (func_80104248(param_0)) {
        if (local_2->local_0) {
            local_0 = _anseq_entrypoint_9(local_2->local_0);
            local_1 = func_801022E4(param_0);
            if (local_1 != local_2->local_2) {
                local_2->local_2 = local_1;
                _anseq_entrypoint_0(local_0);
                if (local_2->local_1) {
                    _inantab_entrypoint_4(local_2->local_1, param_0->unk0, local_0, (s16)local_1);
                }
            }
            _anseq_entrypoint_8(local_0, func_80104248(param_0));
        }
    }
}
