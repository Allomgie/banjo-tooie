#include "core2/1EDB4D0.h"
#include "core2/anctrl.h"
#include "core2/1EBA250.h"
void func_8008B2DC(AnimCtrl *, f32);

extern s32 anctrl_getPlaybackType(s32);
typedef struct {
    f32 duration;
    u16 anim_index;
    u16 flags;
} local_entry_80101BE0;
typedef struct {
    u8 entry_index : 6;
    u8 pad_0_6 : 2;
} bits_80101BE0;
extern f32 func_8008B2AC(s32);
typedef struct _AnCtrl AnCtrl;
typedef struct {
    f32 duration;
    u16 anim_index;
    u16 flags;
} local_entry_80101F64;
typedef struct {
    f32 duration;
    u16 anim_index;
    u16 flags;
} local_entry_801021BC;
extern void *func_80104248();
typedef struct {
    u8 pad0[0x78];
    u32 pad78_0 : 12;
    u32 uses_message : 1;
    u32 pad78_13 : 19;
} S_102394;
typedef struct {
    u8 pad0[8];
    void *anim_table;
} R_102394;
extern s32 func_8010108C(S_102394 *, s32, s32);
extern void *func_80101080(void);
extern R_102394 *func_80100368(S_102394 *);
typedef struct {
    s16 unk_0, unk_2, unk_4;
    u16 flags;
} LocalConfig;
extern void func_8008B4A8(AnimCtrl *, s32);
extern s32 func_800DC298(f32);
extern f32 func_800DC0C0(void);
extern void *func_800AE080(s16);
extern Unkfunc_800E0960_1 *func_800AE6BC(void *);
extern s32 func_800E09B8(s32);
extern void func_800AE6FC();
extern s32 func_800D3E40(u32);
void *func_80102394();

int func_80101BE0(void *actor, u32 index)
{
    local_entry_80101BE0 *table;
    s32 anim_ctrl;
    table = (local_entry_80101BE0 *) func_80102394(actor);

    ((bits_80101BE0 *) ((u8 *) actor + 0x72))->entry_index = index;
    if (table == 0) {
        return 0;
    }
    if (table[index].anim_index != 0) {
        anim_ctrl = func_80104248(actor);
        if (anim_ctrl == 0) {
            anim_ctrl = func_801042B8(actor);
            anctrl_reset(anim_ctrl);
        }
        if (anctrl_getPlaybackType(anim_ctrl) == 3) {
            anctrl_setPlaybackType(anim_ctrl, 2);
        }
        anctrl_setIndex(anim_ctrl, table[index].anim_index);
        anctrl_setDuration(anim_ctrl, table[index].duration);
        func_8008B188(anim_ctrl, 1);
    } else {
        func_80104328(actor);
    }
    return 1;
}

void func_80101CDC(Actor *actor, f32 duration)
{
    Actor *anim_ctrl = func_80104248(actor);
    if (anim_ctrl)
        anctrl_setDuration(anim_ctrl, duration);
}

f32 func_80101D0C()
{
    s32 anim_ctrl;
    anim_ctrl = func_80104248();
    if (anim_ctrl) {
        return func_8008B2AC(anim_ctrl);
    }
    return 0.0f;
}

int func_80101D4C()
{
    AnCtrl *anim_ctrl;
    anim_ctrl = func_80104248();
    if (anim_ctrl != 0) {
        anctrl_setPlaybackType(anim_ctrl, 1);
    }
}

void func_80101D7C()
{
    void *anim_ctrl = func_80104248();
    if (anim_ctrl != NULL) {
        anctrl_setPlaybackType(anim_ctrl, 2);
    }
}

int func_80101DAC(s32 actor, s32 value)
{
    s32 anim_ctrl;
    anim_ctrl = func_80104248(actor);
    if (anim_ctrl != 0) {
        func_8008B4A8(anim_ctrl, value);
    }
}

s32 func_80101DDC(Actor *actor)
{
    s32 anim_ctrl = func_80104248(actor);
    if (anim_ctrl == 0) {
        return 0;
    }
    return anctrl_isStopped(anim_ctrl);
}

s32 func_80101E14(Actor *actor, f32 frame)
{
    void *anim_ctrl;
    anim_ctrl = func_80104248(actor);
    if (!anim_ctrl) {
        return 0;
    }
    // Matching: the extra block is needed for the match.
    {
        return anctrl_isAt(anim_ctrl, frame);
    }
}

s32 func_80101E4C(Actor *actor, f32 *frames)
{
    f32 *cursor;
    s32 i;
    cursor = frames;
    i = 0;
    if (*frames != -1.0f) {
        while (1) {
            if (func_80101E14(actor, *cursor) != 0) {
                return i + 1;
            }
            i++;
            cursor++;
            if (*cursor == -1.0f) {
                break;
            }
        }
    }
    return 0;
}

void func_80101EE4(s32 actor, f32 timer)
{
    Actor *anim_ctrl;
    anim_ctrl = func_80104248(actor);
    if (anim_ctrl != 0) {
        func_8008B10C(anim_ctrl, timer);
        func_8008B2DC(anim_ctrl, timer);
    }
}

f32 func_80101F24(Actor *actor)
{
    void *anim_ctrl = func_80104248(actor);
    if (anim_ctrl != 0) {
        return anctrl_getAnimTimer(anim_ctrl);
    }
    return 0.0f;
}

int func_80101F64(actor, index)
s32 actor;
s32 index;
{
    local_entry_80101F64 *table;
    s32 anim_ctrl;
    table = func_80102394(actor);
    anim_ctrl = func_80104248(actor);
    if (anim_ctrl == 0)
        return 1;
    if (table != 0)
        return anctrl_getIndex(anim_ctrl) != table[index].anim_index;
    return 1;
}

void func_80101FDC(Actor *actor, u32 index)
{
    void *unk_0;
    s32 anim_ctrl;

    unk_0 = func_80101F64();

if (func_80101BE0(actor, index) != 0) {
    anim_ctrl = func_80104248(actor);
    if ((anim_ctrl != 0) && (unk_0 != 0)) {
        anctrl_start(anim_ctrl);
    }
}

}

f32 func_8010203C(s32 actor, s32 index)
{
    void *table;

    table = func_80102394(actor);

if (table == 0) {
    return 0.0f;
}

return *((f32 *) ((double *) table + index));
}

int func_80102078(s32 actor, f32 value)
{
    s32 anim_ctrl;
    anim_ctrl = func_80104248(actor);

if (anim_ctrl != 0) {
    func_8008B1C8(anim_ctrl, value);
}

}

int func_801020A8()
{
    s32 anim_ctrl;
    anim_ctrl = func_80104248();

if (anim_ctrl != 0) {
    func_8008B1C8(anim_ctrl, 0.2f);
}

}

int func_801020DC(s32 actor, s32 smooth)
{
    Actor *anim_ctrl;
    anim_ctrl = func_80104248(actor);

if (anim_ctrl != NULL) {
    anctrl_setSmoothTransition(anim_ctrl, smooth == 1 ? 1 : 0);
}

}

s32 func_80102128(s32 actor, s32 param_1, s32 param_2, f32 chance, s32 index)
{
    if ((func_8001210C(param_1) == param_2) && (func_800DC298(chance) != 0)) {
        if (index != -1) {
            func_80102424(actor, index);
        }
        return 1;
    }

return 0;
}

int func_80102190(u8 *actor, s32 clear)
{
    short mask;
    mask = 0xFFFFFFFFFFFFFFFFu;

if (clear != 0) {
    actor[0x74] &=
        ((((((((((((~0x8 & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) &
                 0xFFFFFFFFFFFFFFFFu) &
                0xFFFFFFFFFFFFFFFFu) &
               0xFFFFFFFFFFFFFFFFu) &
              0xFFFFFFFFFFFFFFFFu) &
             mask) &
            0xFFFFFFFFFFFFFFFFu) &
           0xFFFFFFFFFFFFFFFFu) &
          0xFFFF) &
         0xFFFF) &
        0xFFFF;
}

else
{
    actor[0x74] |= 0x8;
}
}

int func_801021BC(s32 actor, u32 index)
{
    local_entry_801021BC *table = func_80102394(actor);
    return table != 0 && table[index].anim_index != 0;
}

void func_80102204(u8 *actor)
{
    s32 unk_0;
    s32 unk_1;
    s32 unk_2;
    s32 *unk_3;
    s32 unk_4;
    s32 anim_ctrl_copy;
    s32 anim_ctrl;

    anim_ctrl = func_80104248();
    anim_ctrl_copy = anim_ctrl;

if (anim_ctrl != 0) {
    unk_0 = func_801039E4(*(s32 *) ((s8 *) actor + 0));
    func_8008B304(anim_ctrl_copy);
    unk_2 = func_8008B4D4(anim_ctrl_copy);
    unk_3 = func_800DF330();
    unk_4 = func_80103CDC(actor, unk_0);
    unk_1 = func_800B26F0(unk_0);
    func_800AE160(unk_3, func_800B27E0(unk_0), unk_2);
    _dbanim_entrypoint_0(unk_1, unk_4, *unk_3);
    if (*(u8 *) ((s8 *) actor + 0x70) & 1) {
        _dbanim_entrypoint_0(unk_1, func_80103D00(actor, unk_0), *unk_3);
    }
    func_800DF41C(0);
    func_800DF72C(0);
}

}

s32 func_801022E4(Actor *actor)
{
    s32 anim_ctrl;
    anim_ctrl = func_80104248(actor);

if (anim_ctrl != 0) {
    return anctrl_getIndex(anim_ctrl);
}

return 0;
}

s32 func_80102320(void *actor, f32 start, f32 end)
{
    void *anim_ctrl;
    f32 timer;
    // Matching: extra temporary needed for the match.
    s32 result = 0;
    anim_ctrl = func_80104248(actor);

if (anim_ctrl != 0) {
    timer = anctrl_getAnimTimer(anim_ctrl);
    return ((start <= timer) && (timer <= end)) ? 1 : result;
}

return 0;

}

void *func_80102394(actor)
S_102394 *actor;
{
    if (actor->uses_message) {
        func_8010108C(actor, 0x99, 0);
        return func_80101080();
    }

return func_80100368(actor)->anim_table;
}

int func_801023E4(s32 actor, s32 index)
{
    u16 *table;
    table = func_80102394(actor);

if (!table) {
    return 0;
}

return ((u16 *) ((u8 *) table + index * 8 + 6))[0];
}

void func_80102424(actor, index) Actor *actor;
s32 index;
{
    LocalConfig *table;
    AnimCtrl *anim_ctrl;
    s32 pre_flags;
    s32 flags;
    table = func_80102394();
    anim_ctrl = func_80104248(actor);

if (anim_ctrl && table) {
    pre_flags = table[index].flags;
    anctrl_setSmoothTransition(anim_ctrl, pre_flags & 0x200 ? 0 : 1);
}

func_80101FDC(actor, index);
anim_ctrl = func_80104248(actor);

if (anim_ctrl) {
    flags = table[index].flags;
    if (flags & 1) {
        anctrl_setPlaybackType(anim_ctrl, 2);
        func_8008B4A8(anim_ctrl, flags & 0x100 ? 0 : 1);
    }
    if (flags & 2)
        anctrl_setPlaybackType(anim_ctrl, 1);
    if (flags & 4)
        anctrl_setPlaybackType(anim_ctrl, 3);
    if (flags & 8)
        func_8008B188(anim_ctrl, 1);
    if (flags & 0x10)
        func_8008B188(anim_ctrl, 0);
    if (flags & 0x800)
        func_8008B188(anim_ctrl, func_800DC298(0.5f) ? 1 : 0);
    if (flags & 0x40)
        func_8008B10C(anim_ctrl, 0);
    if (flags & 0x80)
        func_8008B10C(anim_ctrl, 0.999f);
    if (flags & 0x400)
        func_8008B10C(anim_ctrl, func_800DC0C0());
    func_80102190(actor, flags & 0x20 ? 1 : 0);
}

}

s32 func_8010262C(Unk80132ED0 *desc, u32 param_1)
{
    Unkfunc_800E0960_1 *result;
    void *unk_0;
    s16 unk_1;
    s16 id;
    id = *(s16 *) ((u8 *) desc + 0x10);
    result = NULL;

if (id && param_1) {
    unk_0 = func_800AE080(id);
    result = func_800AE6BC(unk_0);
    if (!result) {
        unk_1 = func_800E09B8(param_1);
        func_800AE6FC(unk_0, unk_1);
        result = func_800E0A28(unk_1);
    }
    func_800E0ACC(result);
    func_800E0AF0(result, 1.0f);
}

return (s32) result;
}

void func_801026CC(Actor *actor, Vec3f params, f32 value)
{
    f32 duration;
    if (func_800D3E40(8))
        value *= 1.5f;
    if (value < 100.0f)
        duration = params.pos.x;
    else
        duration = (value - 100.0f) * params.pos.y + params.pos.x;
    if (duration < params.pos.z)
        duration = params.pos.z;
    func_80101CDC(actor, duration);
}
