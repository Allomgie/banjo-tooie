#include "common.h"
#include "overlays/ba/boost.h"
#include "playerstate.h"
#include "boost.h"

s32 baboost_entrypoint_0(void)
{
    return sizeof(BaBoost);
}

// Number of running boosts.
s32 baboost_entrypoint_1(PlayerState *state)
{
    s32 i;
    s32 count = 0;
    for (i = 0; i < 5; i++) {
        if (state->boost->unk8[i] != 0.0f)
            count++;
    }
    return count;
}

s32 baboost_entrypoint_2(PlayerState *state, f32 boost_time);

// Try to start a boost. Returns 1 if accepted, 0 if it is left pending.
s32 baboost_entrypoint_2(PlayerState *state, f32 boost_time)
{
    s32 i;

    for (i = 0; i < 5; i++) {
        // A running boost started less than 0.25 s ago blocks the new one.
        if (boost_time - 0.25f < state->boost->unk8[i]) {
            state->boost->unk4 = boost_time;
            return 0;
        }
    }
    for (i = 0; i < 5; i++) {
        if (state->boost->unk8[i] == 0.0f) {
            state->boost->unk8[i] = boost_time;
            return 1;
        }
    }
    state->boost->unk4 = boost_time;
    return 0;
}

// Clear all boosts and disable the queue.
void baboost_entrypoint_3(PlayerState *state)
{
    s32 i;

    for (i = 0; i < 5; i++) {
        // Matching: double assignment needed for the match.
        state->boost->unk8[i] = state->boost->unk8[i] = 0.0f;
    }
    state->boost->unk4 = 0;
    state->boost->unk0 = (u32) state->boost->unk4;
}

// Enable or disable the queue; disabling clears it.
void baboost_entrypoint_4(PlayerState *state, s32 enable)
{
    state->boost->unk0 = enable;
    if (state->boost->unk0 == 0) {
        _baboost_entrypoint_3(state);
    }
}

// Tick running boosts and retry the pending request.
void baboost_entrypoint_5(PlayerState *state)
{
    s32 i;
    f32 pending;
    if (state->boost->unk0) {
        for (i = 0; i < 5; i++) {
            func_800D9078(&state->boost->unk8[i]);
        }
        if (state->boost->unk4 != 0.0f) {
            pending = state->boost->unk4;
            state->boost->unk4 = 0.0f;
            baboost_entrypoint_2(state, pending);
        }
    }
}
