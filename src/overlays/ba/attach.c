// Probably the player's link to an external controller (PlayerState+0x08): one id plus a
// callback that player states forward events to, e.g. Stony kicks to the stone-ball controller.
#include "common.h"
#include "overlays/ba/attach.h"

s32 baattach_entrypoint_0(void)
{
    return sizeof(BaAttach);
}

s32 baattach_entrypoint_1(PlayerState *self)
{
    if (self->attach->unk0) {
        return 1;
    } else {
        return 0;
    }
}

// Links an external controller id and its event callback to the player.
s32 baattach_entrypoint_2(PlayerState *self, s32 id, void (*callback)(s32, s32, s32, s32))
{
    self->attach->unk0 = id;
    self->attach->unk4 = callback;
    return 1;
}

// Sends event 3 (reset) to the linked callback.
void baattach_entrypoint_3(PlayerState *self)
{
    baattach_entrypoint_6(self, 3, 0, 0);
}

void baattach_entrypoint_4(PlayerState *self)
{
    self->attach->unk0 = 0;
}

void baattach_entrypoint_5(PlayerState *self, s32 unk_0)
{
    if (self->attach->unk0) {
        self->attach->unk0 = 0;
    }
}

// Forwards an event to the linked callback, if any.
void baattach_entrypoint_6(PlayerState *self, s32 event, s32 arg_a, s32 arg_b)
{
    s32 pad;
    s32 id = self->attach->unk0;
    if (id) {
        self->attach->unk4(id, event, arg_a, arg_b);
    }
}
