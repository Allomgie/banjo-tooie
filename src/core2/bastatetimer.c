#include "common.h"
#include "overlays/ba/statetimer.h"
#include "core2/1EB2840.h"

typedef struct {
    f32 now;
    f32 prev;
    s8 pause;
} BaStateTimerX;

s32 bastatetimerList_getSize(void)
{
    return sizeof(BaStateTimerList);
}

f32 bastatetimer_get(PlayerState *self, BaStateTimerId id)
{
    return self->state_timer->timer[id].now;
}

f32 bastatetimer_getPrevious(PlayerState *self, BaStateTimerId id)
{
    return self->state_timer->timer[id].prev;
}

int bastatetimer_isActive(PlayerState *self, BaStateTimerId id)
{
    return (self->state_timer->timer[id].now != 0.0f);
}

int bastatetimer_isDone(PlayerState *self, BaStateTimerId id)
{
    return (self->state_timer->timer[id].now == 0.0f);
}

// True on the frame the timer crosses time.
int bastatetimer_isAt(PlayerState *self, BaStateTimerId id, f32 time)
{
    BaStateTimer *timer = &self->state_timer->timer[id];
    return ((timer->now < time) && (time <= timer->prev));
}

void bastatetimerlist_free(PlayerState *self)
{
}

#ifndef NONMATCHING

// Timers 2 and 3 start with the pause flag set.
void bastatetimerlist_init(PlayerState *player)
{
    s32 i;
    for (i = 0; i < 10; i++) {
        (*(BaStateTimerX **) ((u8 *) player + 0x3C))[i].now = 0.0f;
        (*(BaStateTimerX **) ((u8 *) player + 0x3C))[i].prev = 0.0f;
        (*(BaStateTimerX **) ((u8 *) player + 0x3C))[i].pause = (i == 2) || (i == 3);
    }
}

#else
void bastatetimerlist_init(0)
{
#endif

    void bastatetimer_clear(PlayerState * self, BaStateTimerId id)
    {
        bastatetimer_set(self, id, 0.0f);
    }

    void bastatetimer_set(PlayerState * self, BaStateTimerId id, f32 time)
    {
        self->state_timer->timer[id].now = time;
        self->state_timer->timer[id].prev = time;
    }

    // Counts all timers down by the frame delta, clamped at 0. Timers with the pause flag
    // hold while the player is not controllable.
    void bastatetimerlist_update(PlayerState * self)
    {
        int i;
        f32 pad0;
        s32 controllable;
        f32 delta;

        controllable = !func_800F424C(self);
        delta = func_800D8FF8();
        for (i = 0; i < BA_STATE_TIMER_COUNT; i++) {
            self->state_timer->timer[i].prev = self->state_timer->timer[i].now;
            if (0.0f != self->state_timer->timer[i].now &&
                !(self->state_timer->timer[i].unk8 && controllable)) {
                self->state_timer->timer[i].now -= delta;
                if (self->state_timer->timer[i].now < 0.0f) {
                    self->state_timer->timer[i].now = 0.0f;
                }
            }
        }
    }
