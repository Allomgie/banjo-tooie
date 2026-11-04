// Player alarm (PlayerState+0x00): plays countdown beeps from one positional sfx source,
// faster as a timed footwear item (turbo trainers, wading boots, stilts) runs out.
#include "common.h"
#include "overlays/ba/alarm.h"
#include "overlays/ba/playerstate.h"
#include "core2/1E75920.h"
#include "core2/1E9A960.h"
#include "core2/1ECA640.h"

s32 baalarm_get_size(void)
{
    return sizeof(BaAlarm);
}

void baalarm_free(PlayerState *self)
{
    if (self->alarm->id) {
        func_800C2FDC(self->alarm->id);
    }
    self->alarm->id = 0;
}

void baalarm_new(PlayerState *self)
{
    self->alarm->id = func_800C2E04();
    func_800C3418(self->alarm->id, 0);
    func_800C330C(self->alarm->id, 2);
    func_800C431C(self->alarm->id, 0);
    self->alarm->active = 1;
}

// Countdown beeps: plays one when a beep time falls between the previous and current remaining time.
void baalarm_entrypoint_3(PlayerState *self, f32 prev_time, f32 time)
{
    f32 beep_time;
    f32 unused;
    f32 pos[3];
    s32 alt;

    if (self->alarm->active == 0) {
        return;
    }

    func_8009C128(self, pos);
    if (time < 1.0f) {
        if (prev_time != time) {
            func_80800294_baalarm(self->alarm->id, 2);
            func_800C35E8(self->alarm->id, pos);
            func_800C301C(self->alarm->id, 0x414);
            func_800C3058(self->alarm->id, 0x7FFF);
            func_800C3BDC(self->alarm->id);
        }
    } else {
        beep_time = 5.0f;
        alt = 0;
        while (0.0f < beep_time) {
            if (beep_time <= prev_time && time < beep_time) {
                func_800C35E8(self->alarm->id, pos);
                func_800C301C(self->alarm->id, alt ? 0x41C : 0x438);
                func_800C3058(self->alarm->id, 0x7FFF);
                func_80800294_baalarm(self->alarm->id, 3);
                func_800C3BDC(self->alarm->id);
                break;
            }
            alt ^= 1;
            beep_time -= func_800F10B4(beep_time, 0.0f, 5.0f, 0.1f, 0.25f);
        }
    }
}

void func_80800294_baalarm(u8 id, s32 unk_0)
{
    if (func_800C39A0(id) != unk_0) {
        func_800C3CE8(id);
        func_800C330C(id, unk_0);
    }
}
