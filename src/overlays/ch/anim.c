#include "common.h"

extern void _chanim_entrypoint_0(Unk80132ED0 *, s32);
typedef union {
    s32 value;
    Unk80132ED0 *ptr;
    f32 fvalue;
} ChAnimCallbackWord;
extern void _anseq_entrypoint_2(Actor *, f32, void (*)(Unk80132ED0 *, s32), s32, s32);
extern void _chanim_entrypoint_1(Unk80132ED0 *, s32, s32);
extern void _anseq_entrypoint_3(void *, f32, void (*)(Unk80132ED0 *, s32, s32), s32, s32, s32);
extern void _chanim_entrypoint_2(Unk80132ED0 *, s32, s32);
extern void _anseq_entrypoint_5(s32);
typedef struct {
    s16 seq_handle;
    s16 pad_2;
    s32 slots[60];
    s32 unk_F4;
    s32 unk_F8;
} AnimSeqData;
extern void func_80100074(Actor *, s32, s32);
extern s16 *func_80100094(s32, s32);
extern s16 _anseq_entrypoint_6();
extern void func_800DF758(void *);
extern void *func_80104248(Actor *);

typedef struct {
    s16 seq_handle;
    u8 pad_2[0xF2];
    s32 antab;
    s32 anim_id;
} CodexActorAnimation;

void chanim_entrypoint_0(s32 unused, s32 slot)
{
    *(s32 *) ((char *) func_80100094(func_80106790(), 0) + (slot * 4) + 4) = 0;
}

void chanim_entrypoint_1(s32 unused, s32 slot, s32 value)
{
    *(s32 *) ((s8 *) func_80100094(func_80106790(), 0) + (slot * 4) + 4) = value;
}

void chanim_entrypoint_2(s32 unused, s32 slot, s32 anim_id)
{
    s32 actor;
    s32 *data;

    actor = func_80106790();
    data = func_80100094(actor, 0);
    data[slot + 1] = func_800DC128(0, anim_id + 1);
}

void chanim_entrypoint_3(Actor *actor, f32 anim_time, ChAnimCallbackWord word, s32 arg)
{
    _anseq_entrypoint_2(actor, anim_time, _chanim_entrypoint_0, word.value, arg);
}

void chanim_entrypoint_4(void *seq, f32 anim_time, ChAnimCallbackWord word, s32 arg0,
                         s32 arg1)
{
    _anseq_entrypoint_3(seq, anim_time, _chanim_entrypoint_1, word.value, arg0, arg1);
}

void chanim_entrypoint_5(void *seq, f32 anim_time, ChAnimCallbackWord word, s32 arg0,
                         s32 arg1)
{
    _anseq_entrypoint_3(seq, anim_time, _chanim_entrypoint_2, word.value, arg0, arg1);
}

void chanim_entrypoint_6(s32 actor)
{
    s16 *data = func_80100094(actor, 0);
    if (*data != 0) {
        _anseq_entrypoint_5(*data);
    }
    *data = 0;
}

void chanim_entrypoint_7(Actor *actor, s32 use_seq)
{
    s32 i;
    AnimSeqData *data;

    func_80100074(actor, 0, sizeof(AnimSeqData));
    data = func_80100094(actor, 0);
    data->seq_handle = 0;
    data->unk_F8 = 0;
    data->unk_F4 = use_seq;
    for (i = 0; i < 60; i++) {
        data->slots[i] = 0;
    }
    if (data->unk_F4) {
        data->seq_handle = _anseq_entrypoint_6();
    }
}

void chanim_entrypoint_8(Actor *actor)
{
    void *data;
    if (func_80104248(actor) != 0) {
        data = func_80100094(actor, 0);
        if (*(short *) data != 0) {
            func_800DF758((char *) data + 4);
        }
    }
}

// Plays the sequence and re-triggers the antab hook when the anim id changes.
void chanim_entrypoint_9(Actor *actor)
{
    int anim_id;
    CodexActorAnimation *data;
    int seq;

    data = func_80100094(actor, 0);
    if (func_80104248(actor)) {
        if (data->seq_handle) {
            seq = _anseq_entrypoint_9(data->seq_handle);
            anim_id = func_801022E4(actor);
            if (anim_id != data->anim_id) {
                data->anim_id = anim_id;
                _anseq_entrypoint_0(seq);
                if (data->antab) {
                    _inantab_entrypoint_4(data->antab, actor->unk0, seq, (s16) anim_id);
                }
            }
            _anseq_entrypoint_8(seq, func_80104248(actor));
        }
    }
}
