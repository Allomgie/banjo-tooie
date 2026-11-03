#include "core2/1EA78C0.h"

typedef struct {
    u8 pad_0[0x24];
    u32 unk_24;
} ActorCDFD0;
typedef struct {
    u8 pad_0[19];
    u8 is_diamond : 1;
    u8 pad_13 : 7;
} PropCDFD0;
extern s32 D_8012B020[];
extern s32 func_800DAB54(s32 *, s32);
extern void func_800EC370();
extern void **func_800BDD24(s32 *);
extern PropCDFD0 *func_800E9D68(void *);
extern s32 func_800E9DD4(void *);
extern s32 _gspropctrl_entrypoint_0(PropCDFD0 *);
extern s32 _gspropctrl_entrypoint_1(PropCDFD0 *, s32 *);
extern void func_800D5318(PropCDFD0 *, ActorCDFD0 *);
extern u16 D_8011AA10[7][2];
extern void func_800DAA8C(void *, s32, s32);
extern void func_800BE52C(s32 *, s32 *);
extern void func_800DAAF8();
extern void func_800DAB8C();
extern s32 func_800E9D90(s32);
typedef struct {
    u8 unk_4;
    u8 unk_A;
} Struct_800CE308;
typedef struct {
    s16 hud_id;
    s16 unk_2;
    s16 unk_4;
} E_CE3F4;
extern void func_800D2498();
typedef struct {
    f32 time;
    u8 pad_4[6];
    s16 display;
    f32 max_time;
    s16 max_display;
} S_CE438;
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern s32 D_8011AA34;
typedef struct {
    f32 time, prev_time;
    s16 prev_display, display;
    u8 pad_C[6];
    s8 enable_count;
    u8 paused, hold, pad_15[3];
    void (*callback)(s32, s32);
    s32 callback_arg;
} LocalTimer;
typedef struct {
    s16 hud_id, has_tick_sfx, gate_flags;
} LocalConfig_800CE628;
extern LocalConfig_800CE628 D_8011AA30[];
extern s32 func_800EA09C(void);
extern s32 func_800DB9B0(void);
extern f32 func_800D9004(void);
extern s32 func_800F6D24(s32);
extern s32 func_800F8004(s32);
extern s32 func_800F68B8(s32);
extern u8 D_8012B030[];
typedef struct {
    f32 time;
    f32 prev_time;
    s16 prev_display;
    s16 display;
    f32 max_time;
    s16 max_display;
    u8 pad_12[3];
    u8 unk_15;
    u8 pad_16[2];
    s32 callback;
} S_CE8D8;
typedef struct {
    f32 time;
    u8 pad_4[0xE];
    s8 enable_count;
    u8 paused, hold, unk_15, sfx_active;
} ControlCEC94;
typedef struct {
    u8 pad_0[0x120];
    u8 sfx_handle, tick_sfx_on;
} AudioCEC94;
extern s16 D_8011AA68[];
extern void func_800FC6B0(u32);
extern void func_800FC74C(u32);
extern void func_800FCD14(s32, s32);
extern void func_800C3BDC(s32);
extern void func_800C2FDC(s32);
extern s32 func_800C4350();
typedef struct {
    f32 unk_0;
    u8 pad_4[0x10];
} E_CEF00;
typedef struct {
    s16 unk_0;
    u8 pad_2[18];
} E20_CEF48;
extern E20_CEF48 D_8011AA8E[];
extern f32 D_8012B170;
typedef struct {
    s16 water_stack[4];
    s16 unk_8;
    s16 last_display;
    u8 drowning;
    u8 pad_D[3];
    f32 saved_air;
} StateCEF7C;
StateCEF7C D_8012B160;
typedef struct {
    s32 pad_0;
    s16 unk_4, unk_6;
    f32 unk_8;
    s32 pad_C[2];
} EntryCF01C;
extern s16 D_8012B168;
extern s16 D_8012B16A;
extern f32 func_800D8FF8(void);
extern void func_800C3FF0(s32, f32, s32);
extern void func_800FC63C(s32, s32);
extern u8 D_8012B16C;
extern void func_8008FBC0(void);
extern void func_8008FBE0(u32);
extern u32 func_8008FC00(void);
extern void func_800D9078(void *);
extern void func_800F7B9C(u32, void *);
extern f32 D_8012B178;
extern f32 D_8012B174;
extern u32 D_8012B17C;
extern s32 func_800D3E40(s32);
extern void *func_800F54E4(void);
extern s32 func_800F6604(void *);
extern short D_8012B15E[];
typedef struct {
    u8 pad_0[0xC];
    s16 unk_C;
    u8 pad_E[2];
    f32 unk_10;
} LocalConfig_800CF734;
extern LocalConfig_800CF734 D_8011AA80[];
int func_800CE1A8();
int func_800CE21C();
void func_800CEC94();
// Returns 1 when the player-state conditions for the air meter hold.
s32 func_800CF580();
// Water type on top of the air stack, 0 if none.
s32 func_800CF640();
f32 func_800CF67C();
// Air capacity: 10 with flag 0x1BF (upgraded air), else 6.
// Matching: the "| 0" in the return is needed for the match.
int func_800CF6D0();
void func_800CF734();

// TU-NOTE: .rodata starts with these 16-byte constants (formerly asm/data/core2/1EA78C0.rodata.s);
// the zero words belong to the object, as the ROM alignment shows.
const struct {
    f32 x;
    f32 pad[3];
} D_801259B0 = {1.4142135f};

// Dispatches to func_800D5318 for each trigger prop whose area contains the actor.
void func_800CDFD0(ActorCDFD0 *actor)
{
    s32 unused;
    s32 actor_pos[3];
    s32 prop_pos[3];
    s32 trigger_type;
    s32 radius;
    s16 pos_s16[3];
    PropCDFD0 *prop;
    PropCDFD0 *props_end;
    void **cube;
    trigger_type = func_800CE21C(actor->unk_24 >> 22);
    if (trigger_type == -1)
        return;
    if (func_800DAB54(D_8012B020, trigger_type) != 1)
        return;
    func_800EC370(actor, pos_s16);
    actor_pos[0] = pos_s16[0];
    actor_pos[1] = pos_s16[1];
    actor_pos[2] = pos_s16[2];
    for (cube = func_800BDD24(actor_pos); *cube; cube++) {
        prop = func_800E9D68(*cube);
        props_end = func_800E9DD4(*cube) + prop;
        for (; prop < props_end; prop++) {
            if (_gspropctrl_entrypoint_0(prop) == trigger_type) {
                radius = _gspropctrl_entrypoint_1(prop, prop_pos);
                if (prop_pos[1] - radius < actor_pos[1] && actor_pos[1] < prop_pos[1] + radius) {
                    if (prop->is_diamond) {
                        if (func_800CE1A8(actor_pos, prop_pos, radius)) {
                            func_800D5318(prop, actor);
                        }
                    } else {
                        if (prop_pos[0] - radius < actor_pos[0] &&
                            actor_pos[0] < prop_pos[0] + radius &&
                            prop_pos[2] - radius < actor_pos[2] &&
                            actor_pos[2] < prop_pos[2] + radius) {
                            func_800D5318(prop, actor);
                        }
                    }
                }
            }
        }
    }
}

// Diamond-shaped (45 degree rotated square) area test.
int func_800CE1A8(actor_pos, prop_pos, radius)
int *actor_pos;
int *prop_pos;
int radius;
{
    int diag;
    int rot_u;
    int dz;
    int size;
    int rot_v;
    diag = radius * D_801259B0.x;
    rot_u = actor_pos[0] - prop_pos[0] + diag;
    dz = actor_pos[2] - prop_pos[2];
    rot_v = rot_u - dz;
    size = diag * 2;
    if (rot_u + dz < 0 || size < rot_u + dz)
        return 0;
    return rot_v > 0 && rot_v < size;
}

// Maps a marker id to a trigger type, -1 if none.
int func_800CE21C(marker_id)
s32 marker_id;
{
    s32 i;
    for (i = 0; i < 7; i++) {
        if (marker_id == D_8011AA10[i][0])
            return D_8011AA10[i][1];

}
return -1;
}

void func_800CE2DC(void)
{
    func_800DAA8C((u8 *) D_8012B020, 7, 2);
}

// Rebuilds the bitset of trigger types present in the current map.
void func_800CE308()
{
    u32 cube;
    u32 cubes_end;
    u32 props_end;
    Struct_800CE308 *prop;

    func_800DAB8C((u8 *) D_8012B020, 0);
    func_800BE52C(&cube, &cubes_end);
    if (cube < cubes_end) {
        do {
            if (func_800E9DD4(cube) != 0) {
                prop = (Struct_800CE308 *) func_800E9D68(cube);
                props_end = func_800E9D90(cube);
                if (prop < (Struct_800CE308 *) props_end) {
                    do {
                        if (!(*(s32 *) ((char *) prop + 4) & 1)) {
                            func_800DAAF8((u8 *) D_8012B020, *(u8 *) ((char *) prop + 10), 1);
                        }
                        prop = (Struct_800CE308 *) ((u32) prop + 0x14);
                    } while (prop < (Struct_800CE308 *) props_end);
                }
            }
            cube += 8;
        } while (cube < cubes_end);

}
}

// Timer table D_8012B030: 9 slots of 0x20 bytes. Slot 1 is the underwater air meter.
u8 *func_800CE3E0(slot)
s32 slot;
{
    return (u8 *) ((slot << 5) + (s32) ((struct struct_func_8012B030 *) D_8012B030));
}

void func_800CE3F4(void *timer, s32 slot)
{
    func_800D2498(((E_CE3F4 *) D_8011AA30)[slot].hud_id, *(s16 *) ((u8 *) timer + 0xA), 0);
}

void func_800CE438(timer, slot) S_CE438 *timer;
s32 slot;
{
    timer->time =
        func_800F10B4((f32) timer->display, 0.0f, (f32) timer->max_display, 0.0f, timer->max_time);
    func_800CE3F4(timer, slot);
}

void func_800CE49C(u8 *timer, s32 slot, s32 update_hud)
{
    *(s16 *) (timer + 0xA) =
        (s32) (func_800F10B4(*(f32 *) timer, 0.0f, *(f32 *) (timer + 0xC), 1.0f,
                             (f32) *(s16 *) (timer + 0x10) + 1.0f) -
               0.0001f);
    if (update_hud)
        func_800CE3F4(timer, slot);
}

// Clears all timer slots.
void func_800CE524(void)
{
    s32 i;
    void *timer;
    for (i = 0; i < 9; i++) {
        timer = func_800CE3E0(i);
        *(s16 *) ((char *) timer + 0x8) = 0;
        *(s16 *) ((char *) timer + 0xA) = *(s16 *) ((char *) timer + 0x8);
        *(f32 *) ((char *) timer + 0x0) = 0.0f;
        *(f32 *) ((char *) timer + 0x4) = 0.0f;
        *(u8 *) ((char *) timer + 0x16) = 0;
        *(u8 *) ((char *) timer + 0x15) = 0;
        *(u8 *) ((char *) timer + 0x14) = 0;
        *(u8 *) ((char *) timer + 0x12) = 0;
        *(u8 *) ((char *) timer + 0x13) = 0;
        *(s32 *) ((char *) timer + 0x18) = 0;
        *(s32 *) ((char *) timer + 0x1C) = 0;
    }
}

// Returns 0 if a gating flag of the slot matches an active condition.
s32 func_800CE59C(s32 slot, s32 cond_4, s32 cond_1, s32 cond_2, s32 cond_8)
{
    u16 gate_flags;
    gate_flags = *(u16 *) ((u8 *) &D_8011AA34 + slot * 6);
    if ((cond_4 != 0) && (gate_flags & 4)) {
        return 0;
    }
    if ((cond_1 != 0) && (gate_flags & 1)) {
        return 0;
    }
    if ((cond_2 != 0) && (gate_flags & 2)) {
        return 0;
    }
    if ((cond_8 != 0) && (gate_flags & 8)) {
        return 0;
    }
    return 1;
}

// Per-frame update of all timer slots: countdown, expiry callback, HUD and sfx.
void func_800CE628(void)
{
    LocalTimer *timer;
    f32 delta;
    s32 player;
    s32 cond_4;
    s32 cond_1;
    s32 cond_2;
    s32 cond_8;
    s32 slot;
    s32 allowed;
    void (*callback)(s32, s32);
    s32 callback_arg;
    if (func_800EA09C() == 2) {
        player = func_800F54E4();
        delta = func_800D9004();
        cond_4 = func_800DB9B0();
        cond_1 = func_800F6D24(player);
        cond_2 = func_800F8004(player);
        cond_8 = func_800F68B8(player);
        for (slot = 0; slot != 9; slot++) {
            timer = func_800CE3E0(slot);
            allowed = func_800CE59C(slot, cond_4, cond_1, cond_2, cond_8);

if (timer->enable_count > 0 && !timer->paused && !timer->hold && allowed) {
    timer->prev_time = timer->time;
    timer->prev_display = timer->display;
    timer->time -= delta;
    if (timer->time < 0.0f) {
        timer->time = 0.0f;
        if (timer->callback) {
            callback = timer->callback;
            callback_arg = timer->callback_arg;
            timer->callback = 0;
            timer->callback_arg = 0;
            callback(slot, callback_arg);
        }
        timer->enable_count = 0;
    }
    func_800CE49C(timer, slot, 1);
}

if (D_8011AA30[slot].has_tick_sfx)
    func_800CEC94(timer, slot, allowed);
timer->hold = 0;

}
}
}

// Stops the timer sounds.
void func_800CE7DC(void)
{
    if (D_8012B030[0x120] != 0) {
        func_800C2FDC(D_8012B030[0x120]);
        D_8012B030[0x120] = 0;
    }
    if (D_8012B030[0x121]) {
        func_800FC74C(0x92);
        D_8012B030[0x121] = 0;
    }
}

void func_800CE83C(s32 slot, s32 paused)
{
    *(u8 *) (func_800CE3E0(slot) + 0x13) = paused;
}

void func_800CE864()
{
    s8 *timer = func_800CE3E0();
    timer[0x14] = 1;
}

void func_800CE88C(void *slot, s32 enable)
{
    s8 *timer;

    timer = func_800CE3E0(slot);
    if (enable != 0) {
        timer[0x12]++;
        return;
    }
    if (timer[0x12] != 0) {
        timer[0x12]--;
    }
}

void func_800CE8D8(void *slot, f32 time, s32 display)
{
    S_CE8D8 *timer = func_800CE3E0(slot);
    timer->unk_15 = 0;
    timer->callback = 0;
    timer->max_display = timer->display = timer->prev_display = display;
    timer->time = timer->prev_time = timer->max_time = time;
}

int func_800CE928(s32 slot, s32 callback, s32 callback_arg)
{
    typedef struct {
        char pad_0[0x18];
        s32 callback;
        s32 callback_arg;
    } Actor;
    Actor *timer;
    timer = (Actor *) func_800CE3E0(slot);
    timer->callback = callback;
    timer->callback_arg = callback_arg;
}

s32 func_800CE95C(void)
{
    return *(s32 *) ((s8 *) func_800CE3E0() + 0x18);
}

int func_800CE980(s32 slot, f32 time, s32 skip_hud)
{
    f32 value;
    f32 *timer;
    timer = func_800CE3E0();
    value = time;
    if (timer[3] < value) {
        timer[3] = value;
    }
    timer[1] = value;
    timer[0] = value;
    func_800CE49C(timer, slot, !skip_hud);
}

int func_800CE9E8(s32 slot, s32 display)
{
    // Matching: the casts to the same type below are needed for the match.
    s32 timer;
    timer = func_800CE3E0(slot);
    if ((s16) *(s16 *) ((char *) timer + 0x10) < display) {
        *(s16 *) ((char *) timer + 0x10) = (s16) display;
    }
    *(s16 *) ((char *) timer + 0x8) = (s16) display;
    *(s16 *) ((char *) timer + 0xA) = (s16) display;
    func_800CE438(timer, slot, display);
}

void func_800CEA38(s32 slot, int flag)
{
    s32 timer;
    timer = func_800CE3E0(slot);
    *(u8 *) (timer + 0x15) = flag;
}

f32 func_800CEA60()
{
    f32 *timer = func_800CE3E0();
    return *timer;
}

int func_800CEA84()
{
    s16 *timer;
    timer = func_800CE3E0();
    return *(s16 *) ((s8 *) timer + 0xA);
}

s32 func_800CEAA8()
{
    return *(s8 *) ((s8 *) func_800CE3E0() + 0x12) > 0;
}

s32 func_800CEAD0(void)
{
    f32 time;
    time = func_800CEA60();
    return time == 0.0f;
}

// True when the time dropped past threshold this frame.
s32 func_800CEB08(f32 *timer, f32 threshold)
{
    if (((s8 *) timer)[0x12] != 0) {
        if (threshold <= timer[1]) {
            if (timer[0] < threshold) {
                return 1;
            }

}
}
return 0;
}

int func_800CEB54(s32 slot, f32 threshold)
{
    func_800CEB08(func_800CE3E0(slot), threshold);
}

// True when the displayed value dropped past value this frame.
int func_800CEB80(s32 slot, s32 value)
{
    Actor *timer;
    timer = func_800CE3E0(slot);
    if ((*(s8 *) ((char *) (timer) + 0x12)) != 0 &&
        value < (*(s16 *) ((char *) (timer) + 0x8)) &&
        value >= (*(s16 *) ((char *) (timer) + 0xA))) {
        return 1;
    }
    return 0;
}

// Shows the slot's HUD item, or hides it when gated off.
void func_800CEBD8(s32 slot, s32 show)
{
    s32 player;
    short hud_id;
    s32 cond_2;
    s32 cond_1;
    s32 cond_4;
    player = func_800F54E4();
    if (show != 0) {
        cond_4 = func_800DB9B0();
        cond_1 = func_800F6D24(player);
        cond_2 = func_800F8004(player);
        if (func_800CE59C(slot, cond_4, cond_1, cond_2, func_800F68B8(player)) != 0) {
            func_800CE3F4(func_800CE3E0(slot), slot);
            return;

}
}
hud_id = *(short *) ((char *) (short *) D_8011AA30 + (slot * 3) * 2);
func_800D284C(hud_id);
}

// Low-timer sounds: sfx 0x92 while time is between 1 and 5, a looping sound below 1.
void func_800CEC94(timer, slot, allowed) ControlCEC94 *timer;
s32 slot;
s32 allowed;
{
    s32 tick_sfx;
    s32 alarm_sfx;
    s32 tmp;
    tick_sfx = (timer->time > 1.0f) && (timer->time < 5.0f);
    alarm_sfx = (timer->time > 0.0f) && (timer->time < 1.0f);
    tmp =
        (timer->enable_count > 0) && !timer->paused && !timer->hold && (!allowed || timer->unk_15);
    if (!tmp) {
        alarm_sfx = 0;
        tick_sfx = 0;
    }
    if (tick_sfx || alarm_sfx || timer->sfx_active) {
        if (tick_sfx) {
            if (!(*(AudioCEC94 *) D_8012B030).tick_sfx_on) {
                func_800FC6B0(0x92);
                (*(AudioCEC94 *) D_8012B030).tick_sfx_on = 1;
            }

func_800FCD14(0x92, (s32) (((timer->time - 1.0f) * (200000.0f) / 4) + (200000.0f)));
}
else if ((*((AudioCEC94 *) D_8012B030)).tick_sfx_on)
{
    func_800FC74C(0x92);
    (*((AudioCEC94 *) D_8012B030)).tick_sfx_on = 0;
}
if (alarm_sfx) {
    tmp = (*((AudioCEC94 *) D_8012B030)).sfx_handle;

if (!tmp) {
    (*(AudioCEC94 *) D_8012B030).sfx_handle = func_800C4350(0, 0, D_8011AA68);
}

tmp = (*((AudioCEC94 *) D_8012B030)).sfx_handle;
func_800C3BDC(tmp);
}
else
{
    tmp = (*((AudioCEC94 *) D_8012B030)).sfx_handle;

if (tmp) {
    func_800C2FDC(tmp);
    (*(AudioCEC94 *) D_8012B030).sfx_handle = 0;
}

}
timer->sfx_active = tick_sfx || alarm_sfx;
}
}

// Full air value for a water type.
f32 func_800CEF00(s32 water_type)
{
    return ((E_CEF00 *) D_8011AA80)[water_type].unk_0 * (f32) func_800CF6D0(water_type);
}

f32 func_800CEF48(s32 water_type)
{
    return (f32) D_8011AA8E[water_type].unk_0;
}

void func_800CEF6C()
{
    D_8012B170 = 0.0f;
}

// Initializes the air meter on timer slot 1.
s32 func_800CEF7C(void)
{
    s32 capacity;
    s32 display;
    f32 full_air;
    s32 i;
    full_air = func_800CEF00(0);
    capacity = func_800CF6D0();
    func_800CE8D8(1, full_air, capacity);
    if (D_8012B160.saved_air != 0.0f)
        func_800CE980(1, D_8012B160.saved_air, 1);
    for (i = 0; i < 4; i++) {
        D_8012B160.water_stack[i] = 9;
    }
    D_8012B160.unk_8 = 0;
    display = func_800CEA84(1);
    D_8012B160.last_display = display;
    D_8012B160.drowning = 0;
}

// Per-frame air update: refills the air while it is not draining.
void func_800CF01C(void)
{
    s32 draining;
    s32 display;
    f32 air;
    f32 max_air;
    EntryCF01C *entry;
    f32 unk_0;
    s32 unk_1, unk_2;
    draining = func_800CEAA8(1) + D_8012B168;
    air = func_800CEA60(1);
    max_air = func_800CEF00(0);
    if (!func_800CF580()) {
        func_800CE864(1);
        return;
    }
    if (draining == 0 && air < max_air) {
        air += func_800D8FF8();
        if (max_air < air)
            air = max_air;
        func_800CE980(1, air, 0);
    }
    display = func_800CEA84(1);
    if (display != D_8012B16A) {
        entry = &((EntryCF01C *) D_8011AA80)[func_800CF640()];
        unk_0 = entry->unk_8;
        unk_1 = entry->unk_4;
        unk_2 = entry->unk_6;
        if (unk_0 >= 0.0f)
            func_800C3FF0(unk_1, unk_0, unk_2);
        else
            func_800FC63C(unk_1, unk_2);
        D_8012B16A = display;
    }
}

void func_800CF160(f32 interval, s32 damage_arg)
{
    ((u8 *) &D_8012B160)[0xC] = 1;
    *(f32 *) &((u8 *) &D_8012B160)[0x14] = interval;
    *(f32 *) &((u8 *) &D_8012B160)[0x18] = 0.0f;
    *(s32 *) &((u8 *) &D_8012B160)[0x1C] = damage_arg;
}

void func_800CF184()
{
    D_8012B16C = 0;
}

// Periodic drowning damage once the air has run out.
void func_800CF190(void)
{
    f32 *interval;
    if (func_800CF67C() != 0.0f) {
        func_800CF184();
        return;
    }
    interval = &D_8012B174;
    if (func_800CF580() != 0) {
        func_800CF7F4(1);
        func_8008FBE0(1);
        func_800D9078(&D_8012B178);
        if (D_8012B178 <= 0.0f) {
            // Matching: the extra block is needed for the match.
            {
                D_8012B178 = *interval;
            }

func_8008FBC0();

if (func_8008FC00() == 0) {
    func_800F7B9C(func_800F54E4(), D_8012B17C);
    func_800CF184();
}

}
}
}

void func_800CF264(void)
{
    if (func_800EA09C() == 2) {
        func_800CF01C();
        if (D_8012B16C != 0) {
            func_800CF190();

}
}
}

void func_800CF2B0()
{
    D_8012B170 = func_800CEA60(1);
}

// Pushes a water type onto the air stack (entering water).
void func_800CF2D4(s32 water_type)
{
    s32 _pad;
    f32 fraction;
    f32 max_air;

    if (func_800D3E40(9) == 0) {
        ((s16 *) (s32 *) &D_8012B160)[func_800CEAA8(1)] = water_type;
        fraction = func_800CF67C();
        max_air = func_800CEF00(water_type);
        func_800CE8D8(1, max_air, func_800CF6D0());
        func_800CE980(1, fraction * max_air, 0);
        func_800CE928(1, &func_800CF734, 0);
        func_800CE88C(1, 1);
        if (func_800F6604(func_800F54E4()) != 0) {
            if (func_800CEF48(water_type) == 0.0f) {
                func_800F7B9C(func_800F54E4(), 0x57);
            }

}
else if (func_800CEF48(water_type) != 0.0f)
{
    func_800F7B9C(func_800F54E4(), 0x56);
}
}
}

void func_800CF40C(s32 amount)
{
    f32 air;
    f32 max_air;
    air = func_800CEA60(1);
    max_air = func_800CEF00(func_800CF640());
    air += (f32) amount * max_air / (f32) func_800CF6D0();
    if (max_air < air)
        air = max_air;
    func_800CE980(1, air, 0);
}

// Pops a water type from the air stack (leaving water).
void func_800CF494(void)
{
    s32 unused;
    f32 fraction;
    f32 max_air;
    s32 depth;
    s16 pending;

    if (func_800D3E40(9) == 0) {
        depth = func_800CEAA8(1);
        pending = *(s16 *) ((s8 *) (((u16 *) &D_8012B160)) + 8);
        if (pending != 0) {
            *(s16 *) ((s8 *) (((u16 *) &D_8012B160)) + 8) = pending - 1;
            return;
        }
        if (depth > 0) {
            *(s16 *) ((s8 *) (((u16 *) &D_8012B160)) + depth * 2) = 9;
            fraction = func_800CF67C(depth, ((u16 *) &D_8012B160));
            func_800CE88C(1, 0);
            max_air = func_800CEF00(func_800CF640());
            func_800CE8D8(1, max_air, func_800CF6D0());

            func_800CE980(1, fraction * max_air, 0);

if (func_800F6604(func_800F54E4()) != 0) {
    func_800F7B9C(func_800F54E4(), 0x57);
}

}
}
}

s32 func_800CF580()
{
    s32 player;
    if (func_800A9C98()) {
        return 0;
    }
    if (func_800D3E40(9)) {
        return 0;
    }
    player = func_800F54E4();
    // Matching: "| 0" below is needed for the match.
    if (!func_800F6BE4(player | 0)) {
        return 0;
    }
    if (func_800F6D24(player) != 0) {
        return 0;
    }
    if (func_800F64A4(player, 0x1A000) != 0) {
        return 0;
    }
    if (func_800F8B88() == 3) {
        return 0;
    }
    return 1;
}

s32 func_800CF640()
{
    int water_type;
    int depth;
    depth = func_800CEAA8(1);
    if (depth) {
        water_type = D_8012B15E[depth];
    } else {
        water_type = 0;
    }
    return water_type;
}

// Air left as a fraction of the current maximum.
f32 func_800CF67C(void)
{
    return func_800CEA60(1) / func_800CEF00(func_800CF640());
}

void func_800CF6B0()
{
    func_800CEA84(0x1);
}

int func_800CF6D0()
{
    s32 capacity;
    capacity = func_800DA298(0x1BF) ? 0xA : 0x6;
    return capacity | 0;
}

int func_800CF700()
{
    s32 capacity;
    func_800DA544(0x1BF);
    capacity = func_800CF6D0();
    // Matching: "| 0" is needed for the match.
    func_800CE9E8(1, capacity | 0);
}

// Air expiry callback: starts drowning damage, pops all water types and re-arms itself.
void func_800CF734(slot, arg) s32 slot;
s32 arg;
{
    s32 water_type;
    s32 count;
    s32 i;
    water_type = func_800CF640();
    if (D_8011AA80[water_type].unk_10 > 0.0f)
        func_800CF160(D_8011AA80[water_type].unk_10, D_8011AA80[water_type].unk_C);
    count = func_800CEAA8(1);
    for (i = 0; i < count; i++)
        func_800CF494();
    D_8012B168 = count;
    func_800CE928(1, func_800CF734, 0);
}

void func_800CF7F4(show) u32 show;
{
    if (((func_800CF580() != 0) && (func_800A16A4() == 0)) || (show == 0)) {
        func_800CEBD8(1, show);
    }
}

int func_800CF840(s32 paused)
{
    // Matching: "| 0" is needed for the match.
    func_800CE83C(1, paused | 0);
}

// TU-NOTE: .data is defined here in C, values taken from the ROM (formerly asm/data/core2/1EA78C0.data.s).
// Linker symbols inside these objects (undefined_syms.us.txt): D_8011AA12 = D_8011AA10 + 0x2,
// D_8011AA14 = +0x4, D_8011AA16 = +0x6, D_8011AA18 = +0x8, D_8011AA1A = +0xA,
// D_8011AA34 = D_8011AA30 + 0x4, D_8011AA8E = D_8011AA80 + 0xE.
u16 D_8011AA10[7][2] = {0x0, 0x0,   0x15D, 0x1,   0x26C, 0x2,   0x26D,
                        0x3, 0x26E, 0x4,   0x26F, 0x5,   0x270, 0x6};
static u32 D_8011AA10_rest[1] = {0x0};
LocalConfig_800CE628 D_8011AA30[9] = {0xCC,  0x0, 0xF, 0xCD,  0x0, 0xC, 0xCE, 0x0, 0xC,
                                      0xC9,  0x0, 0xC, 0xF4,  0x0, 0x4, 0xF6, 0x0, 0x4,
                                      0x104, 0x0, 0x4, 0x117, 0x0, 0x0, 0xCC, 0x0, 0x0};
s16 D_8011AA68[12] = {0x206, 0x13, 0x414, 0x1B, 0x2, 0x16, 0x7FFF, 0x0, 0x0, 0x0, 0x0, 0x0};
LocalConfig_800CF734 D_8011AA80[8] = {
    0x3D, 0xCC, 0xCC, 0xCD, 0x3, 0xE9, 0x46, 0x50, 0x3F, 0x99, 0x99, 0x9A, 0x0,  0x0, 0x0, 0.0f,
    0x41, 0x20, 0x0,  0x0,  0x0, 0x46, 0x6D, 0x60, 0xBF, 0x80, 0x0,  0x0,  0x11, 0x0, 0x0, 2.0f,
    0x40, 0xC0, 0x0,  0x0,  0x0, 0x46, 0x6D, 0x60, 0xBF, 0x80, 0x0,  0x0,  0x45, 0x0, 0x1, 2.0f,
    0x40, 0x40, 0x0,  0x0,  0x0, 0x46, 0x6D, 0x60, 0xBF, 0x80, 0x0,  0x0,  0x45, 0x0, 0x1, 2.0f,
    0x3F, 0x0,  0x0,  0x0,  0x0, 0x46, 0x6D, 0x60, 0xBF, 0x80, 0x0,  0x0,  0x45, 0x0, 0x1, 1.0f,
    0x41, 0x70, 0x0,  0x0,  0x0, 0x46, 0x6D, 0x60, 0xBF, 0x80, 0x0,  0x0,  0x45, 0x0, 0x1, 3.0f,
    0x41, 0x40, 0x0,  0x0,  0x0, 0x46, 0x6D, 0x60, 0xBF, 0x80, 0x0,  0x0,  0x45, 0x0, 0x1, 3.0f,
    0x40, 0x0,  0x0,  0x0,  0x0, 0x46, 0x6D, 0x60, 0xBF, 0x80, 0x0,  0x0,  0x45, 0x0, 0x1, 2.0f};
static u32 D_8011AA80_rest[4] = {0x40C00000, 0x466D60, 0xBF800000, 0x450001};
