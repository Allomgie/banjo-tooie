// Mumbo's wand-glow helper: spawns the glow actor while he charges, keeps it at the wand tip
// each frame, and releases it when the attack ends.
#include "overlays/ba/wandglow.h"
#include "wandglow.h"

extern void func_8008EEC4(PlayerState *, f32 *, s32, s32);

s32 bawandglow_entrypoint_0(void)
{
    return sizeof(BaWandGlow);
}

// Free callback of the glow actor: clears the handle.
void bawandglow_entrypoint_1(s32 unk_0, s32 player_idx)
{
    PlayerState *self = func_800F53E4(player_idx);
    if (self != NULL) {
        self->wandglow->unkC = NULL;
    }
}

// Deferred spawn of the glow actor.
void bawandglow_entrypoint_2(s32 player_idx)
{
    PlayerState *self = func_800F53D0(player_idx);
    if (self->wandglow->unk10) {
        self->wandglow->unkC = _chwandglow_entrypoint_0(player_idx, _bawandglow_entrypoint_1);
    }
}

#ifndef NONMATCHING

// Moves the glow to the wand tip bone (0x27D).
void bawandglow_entrypoint_3(PlayerState *self, s32 unk_0)
{
    void *glow = self->wandglow->unkC;
    if (glow != NULL) {
        func_8008F880(glow);
    }
    // Matching: the float argument is passed as raw bits.
    func_8008EEC4(self, self->wandglow->unk0, *(s32 *) &unk_0, 0x27D);
}

#else
void bawandglow_entrypoint_3(0, s32 arg1)
{
#endif

    // Schedules the deferred glow spawn.
    void bawandglow_entrypoint_4(PlayerState * self)
    {
        self->wandglow->unk10 = 1;
        _chbaddiesetup_entrypoint_1(_bawandglow_entrypoint_2, self->unk184);
    }

    // Releases the glow actor.
    void bawandglow_entrypoint_5(PlayerState * self)
    {
        if (self->wandglow->unkC != NULL) {
            _chwandglow_entrypoint_1(self->wandglow->unkC, self);
        }
        self->wandglow->unk10 = 0;
        self->wandglow->unkC = NULL;
    }

    // Resets the glow state.
    void bawandglow_entrypoint_6(PlayerState * self)
    {
        self->wandglow->unk10 = 0;
        self->wandglow->unkC = NULL;
        func_800EFD24(self->wandglow->unk0);
    }

    // Starts the glow fade-out.
    void bawandglow_entrypoint_7(PlayerState * self)
    {
        if (self->wandglow->unkC != NULL) {
            _chwandglow_entrypoint_2(self->wandglow->unkC);
        }
    }
