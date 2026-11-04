// Ability (learned move) flags on top of game flags: has/used checks, set and unlock helpers,
// plus a 4-channel frame-count throttle.
#include "core2/1EA0690.h"
#include "core2/1EB3750.h"

// TU-NOTE: D_8012AAD0 holds the last frame each of 4 channels fired; D_8012AAE0 is the frame counter.
extern s32 D_8012AAE0;
s32 D_8012AAD0[4];

extern void debug_call();

// Learned/used ability flags and the first-use jingle.
// First use of an ability: marks it used and plays music track 0xE.
void func_800C6DA0(s32 ability_id)
{
    // Matching: always-zero flag guards an 8-arg call that IDO removes but whose
    // outgoing-arg frame area stays. debug_call is a stand-in callee.
    s32 debug = 0;
    s32 play_music;
    play_music = 1;
    if (func_800C6E18(ability_id)) {
        return;
    }
    switch (ability_id - 0x3C) {
        case 0:
        case 1:
            break;

        case 6:
            play_music = 0;

        case 7:
        case 9:
            break;
    }
    if (play_music) {
        func_800FC6B0(0xE);
    }
    func_800C70D0(ability_id, 1);
    if (debug)
        debug_call(1, 2, 3, 4, 5, 6, 7, 8);
}

// Has the ability been used/seen.
s32 func_800C6E18(ability_id)
s32 ability_id;
{
    func_800DA298(ability_id + 0xEE);
}

// Has the ability been learned.
s32 func_800C6E38(s32 ability_id)
{
    return func_800DA298(ability_id + FLAG_0ED_ABILITY_BK_BEAK_BARGE);
}

void func_800C6E58(void)
{
}

void func_800C6E60(void)
{
    func_800C70B0(0, 1);
    func_800C70B0(1, 1);
    func_800C70B0(2, 1);
    func_800C70B0(3, 1);
    func_800C70B0(4, 1);
    func_800C70B0(5, 1);
    func_800C70B0(6, 1);
    func_800C70B0(7, 1);
    func_800C70B0(8, 1);
    func_800C70B0(9, 1);
    func_800C70B0(0xA, 1);
    func_800C70B0(0xB, 1);
    func_800C70B0(0xC, 1);
    func_800C70B0(0xD, 1);
    func_800C70B0(0xE, 1);
    func_800C70B0(0xF, 1);
    func_800C70B0(0x10, 1);
    func_800C70B0(0x11, 1);
    func_800C70B0(0x12, 1);
    func_800C70B0(0x13, 1);
    func_800C70B0(0x31, 1);
    func_800C70D0(0x3C, 1);
    func_800C70D0(0x3D, 1);
    func_800C70D0(0x3E, 1);
    func_800C70D0(0x3F, 1);
    func_800C70D0(0x40, 1);
    func_800C70D0(0x41, 1);
    func_800C70D0(0x42, 1);
    func_800C70D0(0x43, 1);
    func_800C70D0(0x44, 1);
    func_800C70D0(0x45, 1);
    func_800C70D0(0x46, 1);
    func_800C70D0(0x47, 1);
    func_800C70D0(0x48, 1);
}

// Give all abilities.
void func_800C7010(void)
{
    s32 id = 0;

while (id < 0x3C) {
    func_800C70B0(id, 1);
    id++;
}

id = 0x3C;

while (id < 0x50) {
    func_800C70D0(id, 1);
    id += 1;
}

}

void func_800C7074(s32 ability_id, s32 set)
{
    func_800C70B0(ability_id, set);

if (set != 0) {
    func_80101238(0x1A, ability_id);
}

}

// Set the ability-learned flag.
void func_800C70B0(s32 ability_id, s32 set)
{
    func_800DA3B8(ability_id + FLAG_0ED_ABILITY_BK_BEAK_BARGE, set);
}

// Set the ability-used flag.
void func_800C70D0(s32 ability_id, s32 set)
{
    func_800DA3B8(ability_id + FLAG_0EE_ABILITY_BK_BEAK_BOMB, set);
}

// 4-slot frame-count throttle.
int func_800C70F0(s32 channel)
{
    ((s32 *) D_8012AAD0)[channel] = D_8012AAE0;
}

// Returns 1 at most once every 5 frames per channel.
int func_800C710C(s32 channel)
{
    s32 *last_frame = (s32 *) (((char *) (((s32 *) D_8012AAD0))) + (channel << 2));

if (((*last_frame + 5) & 0xFFFFFFFFu) < D_8012AAE0) {
    *last_frame = D_8012AAE0;
    return 1;
}

return 0;
}

// defrag() passthrough used by another file.
// Passthrough to defrag.
void *func_800C7150(void *ptr)
{
    return defrag(ptr);
}
void func_800C7170(void)
{
    s32 i;
    for (i = 0; i < 4; i++) {
        D_8012AAD0[i] = 0;
    }
}

void func_800C718C()
{
    D_8012AAE0++;
}
