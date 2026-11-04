// Most likely the honeycomb energy pickups: placed honeycomb and level-dependent drops. Collecting
// shows first-time tutorials and the HUD health refill, and the number of live drops is capped.
#include "common.h"

#define AF(p, i) (*(f32 *) &(p)->actorData[i])
extern void _sudialog_entrypoint_0(void);
extern void func_800C9E20(f32, void *, s32, s32);
typedef struct Mass44HoneyFlags {
    u8 pad_0[0x78];
    u32 pad_1 : 26;
    u32 disabled : 1;
    u32 pad_2 : 1;
    u32 unk_78_3 : 1;
    u32 pad_3 : 3;
} Mass44HoneyFlags;
extern s32 D_80127194;
extern void func_80109EEC(Actor *, s32);
typedef struct {
    u8 pad_0[0x64];
    u32 pad_64 : 11;
    u32 unk_64_11 : 1;
    u32 unk_64_12 : 1;
    u32 unk_64_13 : 19;
} HoneyS;
extern void func_8010DCB4(s32);
extern s32 *D_80801020_chhoney[];
extern f32 func_800D8FF8(void);
typedef struct {
    u8 pad_0[0x78];
    u32 pad_1 : 26;
    u32 disabled : 1;
    u32 pad_2 : 5;
} HoneyFlags;
extern s32 func_800D9078(f32 *);
extern int D_80801048_chhoney[];
extern void *D_80801090_chhoney;
extern int D_808010D8_chhoney[];
extern u8 D_8012762C;
extern void func_800CE8D8(s32, f32, s32);
extern s32 func_800DC298(f32);
extern f32 func_800DC178(f32, f32);
extern void func_800EF214(f32 *, f32, f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800C4B64(f32);
extern u8 D_80801028_chhoney[];
typedef struct {
    u8 pad_0[0x72];
    u16 state : 6;
    u16 unk_72_6 : 10;
} HoneyState;
typedef struct {
    u8 pad_0[0x78];
    u32 pad_1 : 28;
    u32 unk_78_3 : 1;
    u32 pad_2 : 3;
} Honey78;
extern u8 D_80801038_chhoney[];
extern s32 func_8008FC28(void);
extern s32 func_8008FC00(void);
extern void func_8008FBE0(s32);
extern void func_800FA9F4(s32, s32);
extern void func_800C3FC0(s32, f32, s32);
extern void func_8008FC70(s32);
extern void func_80090708(s32);
extern void func_800FFAB0(Actor *);
extern void _subaddieaudioloop_entrypoint_4();
void func_80800688_chhoney();

// Value of a drop for the current level (D_8012762C).
f32 func_80800000_chhoney(void)
{
    switch (D_8012762C) {
        case 19:
            return 1.0f;
        case 16:
            return 0.7999878f;
        case 15:
            return 0.59999084f;
        case 18:
            return 0.3999939f;
        case 20:
            return 0.2999878f;
        case 21:
            return 0.19999695f;
        case 22:
            return 0.099990845f;
        case 23:
            return 0.07499695f;
        case 24:
            return 0.049987793f;
        case 25:
            return 0.049987793f;
        case 26:
            return 0.7999878f;
        default:
            return 0.0f;
    }
}

// Enters a pickup state and runs its entry actions (tutorial text, HUD refill).
void func_808000C4_chhoney(actor, state) Actor *actor;
s32 state;
{
    if (actor->unk70_10 == 2 || actor->unk70_10 == 3)
        *(f32 *) ((u8 *) actor + 0x24) = 0.0f;
    func_80101FDC(actor, state);
    switch (actor->unk70_10) {
        case 7:
            _subaddiedialog_entrypoint_11(actor->unk0, 0xCE6, 12, actor->position, 0);
            return;
        case 8:
            _subaddiedialog_entrypoint_11(actor->unk0, 0xCE7, 12, actor->position, 0);
            return;
        case 3:
            func_80090708(2);
            func_800CE8D8(6, 10.0f, 10);
            func_800CE88C(6, 1);
            func_800FA9F4(0, 1);
            *(f32 *) ((u8 *) actor + 0x58) = *(f32 *) ((u8 *) actor + 0x2C);
            break;
        case 2:
            func_80090708(2);
            func_800CE8D8(6, 10.0f, 10);
            func_800CE88C(6, 1);
            func_800FA9F4(0, 1);
            *(f32 *) ((u8 *) actor + 0x58) = *(f32 *) ((u8 *) actor + 0x2C);
            break;
        case 5:
        case 6:
            *(f32 *) ((u8 *) actor + 0x58) = 0.0f;
            break;
        case 4:
            func_800FA9F4(0, 0);
            actor->unk6C_0 = func_8008FC00();
            func_8008FC70(0);
            *(f32 *) ((u8 *) actor + 0x58) = 0.2f;
    }
}

// Init: picks the kind from the model (0x55 placed, 0x22B/0x22C drops).
void func_80800244_chhoney(Actor *actor)
{
    *(s32 *) ((u8 *) actor + 0x54) = func_8001211C();
    *(f32 *) ((u8 *) actor + 0x28) = 20.0f;
    _subaddieDll_entrypoint_4(actor, !((*(u32 *) ((u8 *) actor + 0x78) << 26) >> 31));
    actor->scale = 0.5f;
    switch (actor->unk0->unk24 >> 22) {
        case 0x55:
            actor->unk79_4 = 0;
            break;
        case 0x22C:
            actor->unk79_4 = 2;
            *(f32 *) ((u8 *) actor + 0x2C) = func_80800000_chhoney();
            break;
        case 0x22B:
            actor->unk79_4 = 1;
            *(f32 *) ((u8 *) actor + 0x2C) = func_80800000_chhoney();
    }
    func_8010A5B0(actor, func_800DA298(0x64C));
}

// Collection: plays the jingle and starts the matching pickup state.
void func_80800328_chhoney(Actor *actor, Unk80132ED0 *msg)
{
    if (func_800F4B4C((u32) *(u16 *) ((u8 *) msg + 0x1A) >> 5)) {
        switch (actor->unk79_4) {
            case 0:
                func_800C9E20(0.75f, &_sudialog_entrypoint_0, 0x2F, 0);
                func_8008FC50();
                func_800FC660(8);
                func_800FFAB0(actor);
                break;
            case 2:
                func_800FC660(0x81);
                if (!func_800DA9E4(0x40E, 1))
                    func_808000C4_chhoney(actor, 8);
                else
                    func_808000C4_chhoney(actor, 3);
                break;
            case 1:
                func_800FC660(0x80);
                if (!func_800DA9E4(0x40D, 1))
                    func_808000C4_chhoney(actor, 7);
                else
                    func_808000C4_chhoney(actor, 2);
        }
        _fxsparkle_entrypoint_1(actor->position, 1);
        func_8010A570(actor);
        actor->unk64_16 = 0;
        ((u8 *) actor)[0x75] &= ~0x10;
    }
}

int func_8080046C_chhoney(Actor *actor, s32 msg_id, s32 data)
{
    switch (msg_id) {
        case 0x3E:
            *((u8 *) actor + 0x79) &= 0xFFFC;
            func_80800328_chhoney(actor, (Unk80132ED0 *) data);
            break;
        case 0x2E:
            switch (((s16 *) &data)[0]) {
                case 0xCE6:
                    func_808000C4_chhoney(actor, 2);
                    break;
                case 0xCE7:
                    func_808000C4_chhoney(actor, 3);
                    break;
            }
            break;
        case 0x1F:
            func_8010DD20(actor, ((Mass44HoneyFlags *) actor)->unk_78_3 ? 2 : 3, data);
            if ((actor->unk0->unk24 >> 22) != 0x55)
                func_800DF744(3, actor->unk79_4);
            break;
        case 0x95:
            actor->unk64_19 = 0;
            actor->unk64_20 = 1 - ((Mass44HoneyFlags *) actor)->unk_78_3;
            func_80109EEC(actor, 0x44);
            switch (actor->unk0->unk24 >> 22) {
                case 0x55:
                case 0x22B:
                case 0x22C:
                    if (!((Mass44HoneyFlags *) actor)->disabled) {
                        if (++D_80127194 >= 11)
                            func_80800688_chhoney(actor);
                    }
            }
            break;
        default:
            return 0;
    }
    return 1;
}

// Destructor: one live drop less.
void func_80800634_chhoney(HoneyS *honey)
{
    D_80127194--;
    if (honey->unk_64_12) {
        func_8010DCB4(honey->unk_64_11 ? 2 : 3);
    }
}

// Too many live drops: sparkles and removes the oldest one.
void func_80800688_chhoney(current) s32 *current;
{
    s32 *found[14];
    s32 *target_ptr[2];
    s32 target;
    s32 oldest_time;
    s32 count;
    s32 i;
    s32 *other;
    s32 spawn_time;

    target = 0;
    // Matching: empty block steers IDO's register allocation.
    if (1) {
    }
    oldest_time = func_8001211C();
    count = _subaddiefind_entrypoint_6(D_80801020_chhoney, found, 14);
    for (i = 0; i < count; i++) {
        other = found[i];
        if (current != other) {
            spawn_time = *(s32 *) ((u8 *) other + 0x54);
            if (spawn_time <= oldest_time && (*(u16 *) ((u8 *) other + 0x64) & 1)) {
                target = *other;
                oldest_time = spawn_time;
                target_ptr[0] = other;
            }
        }
    }
    if (target == 0) {
        target = *found[0];
        target_ptr[0] = found[0];
    }
    _fxsparkle_entrypoint_1(target_ptr[0] + 1, 0);
    func_800FFA88(target);
}

// Twinkles around drops.
void func_80800754_chhoney(Actor *actor)
{
    s32 i;
    f32 twinkle_pos[3];
    switch (actor->unk0->unk24 >> 22) {
        case 0x55:
            break;
        case 0x22B:
        case 0x22C:
            if (actor->unk7C_12) {
                for (i = 0; i < 4; i++) {
                    if (func_800DC298(0.03f)) {
                        _subaddieskeleton_entrypoint_0(actor, 1, twinkle_pos);
                        func_800EF214(twinkle_pos, func_800DC178(0.0f, 360.0f),
                                      func_800DC178(0.0f, 360.0f), 50.0f);
                        _fxtwinkle_entrypoint_0(twinkle_pos);
                    }
                }
            }
    }
}

// Health tick sound, pitch rises with health.
void func_80800870_chhoney(actor, health) Actor *actor;
s32 health;
{
    if (*(f32 *) &actor->actorData[6] <= 0.0f) {
        func_800C4B64(func_800F10B4(health, 1.0f, 10.0f, 0.8f, 1.5f));
        _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80801028_chhoney);
        *(f32 *) &actor->actorData[6] = 0.1f;
    }
}

// Rolls the HUD health counter to random values.
void func_808008F8_chhoney(Actor *actor, f32 unk_1)
{
    f32 delta_time;
    s32 max_health;
    s32 health;
    s32 new_health;

    delta_time = func_800D8FF8();
    actor->unk58 -= delta_time;
    *(f32 *) &actor->actorData[6] -= delta_time;
    if (actor->unk58 <= 0.0f) {
        max_health = func_8008FC28() + 1;
        health = func_8008FC00();
        new_health = func_800DC128(1, max_health);
        while (new_health == health)
            new_health = func_800DC128(1, max_health);
        func_8008FC70(new_health);
        func_80800870_chhoney(actor, new_health);
        actor->unk58 = *(f32 *) &actor->actorData[5];
    }
}

// Counts the HUD health counter up one step at a time.
void func_808009BC_chhoney(Actor *actor)
{
    f32 delta_time;
    s32 health;
    delta_time = func_800D8FF8();
    actor->unk58 -= delta_time;
    *(f32 *) &actor->actorData[6] -= delta_time;
    if (actor->unk58 <= 0.0f) {
        health = func_8008FC00() + 1;
        if (func_8008FC28() < health)
            health = 1;
        func_8008FC70(health);
        func_80800870_chhoney(actor, health);
        actor->unk58 = *(f32 *) &actor->actorData[5];
    }
}

s32 func_80800EB0_chhoney();

// Update: runs the state machine of the pickup.
void func_80800A5C_chhoney(Actor *actor)
{
    f32 delta_time;
    s32 max_health;
    s32 health;

    func_80800EB0_chhoney(actor);
    if (actor->unk64_20 != ((Honey78 *) actor)->unk_78_3) {
        if (((Honey78 *) actor)->unk_78_3) {
            if (actor->unk64_19) {
                func_8010DCB4(3);
            }
            func_8010DC50(2);
        } else {
            if (actor->unk64_19) {
                func_8010DCB4(2);
            }
            func_8010DC50(3);
        }
        actor->unk64_20 = ((Honey78 *) actor)->unk_78_3;
        actor->unk64_19 = 1;
    }
    delta_time = func_800D8FF8();
    max_health = func_8008FC28();
    switch (((HoneyState *) actor)->state) {
        case 1:
            if (!max_health) {
                func_8010A570(actor);
            } else {
                func_8010A590(actor);
            }
            if (actor->unk0->unk24 >> 22 == 0x22B || actor->unk0->unk24 >> 22 == 0x22C) {
                if (func_8010CAC0(actor->position, 0x1F4) && max_health) {
                    func_8008FBE0(1);
                }
            }
            func_80800754_chhoney(actor);
            return;
        case 7:
            func_8008FBE0(1);
            return;
        case 2:
            func_8008FBE0(1);
            func_808008F8_chhoney(actor, 1e-45f);
            if (func_80090080()) {
                if (func_80016B30(0, 1)) {
                    func_800CE88C(6, 0);
                    func_808000C4_chhoney(actor, 5);
                    return;
                }
            }
            if (func_800CEAD0(6)) {
                func_808000C4_chhoney(actor, 5);
            }
            break;
        case 8:
            func_8008FBE0(1);
            return;
        case 3:
            func_8008FBE0(1);
            func_808009BC_chhoney(actor);
            if (func_80090080()) {
                if (func_80016B30(0, 1)) {
                    func_800CE88C(6, 0);
                    func_808000C4_chhoney(actor, 5);
                    return;
                }
            }
            if (func_800CEAD0(6)) {
                func_808000C4_chhoney(actor, 5);
            }
            break;
        case 5:
            func_8008FBE0(1);
            func_800FA9F4(0, 1);
            actor->unk58 += delta_time * 4.0f;
            if (0.2f < actor->unk58) {
                AF(actor, 3) += 1.0f;
                if (10.0f < AF(actor, 3)) {
                    func_808000C4_chhoney(actor, 4);
                } else {
                    func_808000C4_chhoney(actor, 6);
                }
            }
            _subaddieaudioloop_entrypoint_4(actor, actor->position, 1, D_80801038_chhoney);
            return;
        case 6:
            func_8008FBE0(1);
            func_800FA9F4(0, 2);
            actor->unk58 += delta_time * 4.0f;
            if (0.2f < actor->unk58) {
                func_808000C4_chhoney(actor, 5);
            }
            _subaddieaudioloop_entrypoint_4(actor, actor->position, 1, D_80801038_chhoney);
            return;
        case 4:
            func_8008FBE0(1);
            actor->unk58 -= func_800D8FF8();
            if (actor->unk58 <= 0.0f) {
                health = func_8008FC00();
                actor->unk58 = 0.2f;
                health = health + 1;
                func_800C3FC0(0x66C, func_800F10B4((f32) health, 1.0f, 10.0f, 0.8f, 1.5f), 0x3E80);
                func_8008FC70(health);
                if (health == actor->unk6C_0) {
                    func_80090708(0);
                    func_800FFAB0(actor);
                }
            }
    }
}

s32 func_80800EB0_chhoney(Actor *actor)
{
    if (((HoneyFlags *) actor)->disabled || actor->unk64_17)
        return 0;
    if (func_800EA068(2))
        return 0;
    if (func_800D9078((f32 *) &actor->actorData[4])) {
        if (actor->unk64_16) {
            _subaddiefade_entrypoint_3(actor);
            return 1;
        }
    }
    return 0;
}

int chhoney_entrypoint_0()
{
    return &D_80801048_chhoney;
}

int chhoney_entrypoint_1()
{
    return &D_80801090_chhoney;
}

int chhoney_entrypoint_2()
{
    return (int) &D_808010D8_chhoney;
}

// TU-NOTE: this overlay's .data is defined here in C. Its tables point to functions of this file,
// and IDO's assembler schedules some of them differently unless they share the unit.
// D_80801048_chhoney and D_808010D8_chhoney are declared as int[].
extern void func_80105834();
extern void func_801018A4();
extern void func_80108ED0();
extern void func_80107C2C();
s32 *D_80801020_chhoney[2] = {(void *) 0x02290196, (void *) 0x0197FFFF};
u8 D_80801028_chhoney[16] = {0x0, 0x13, 0x6, 0x57, 0x0, 0x16, 0x27, 0x10,
                             0x1, 0x22, 0x0, 0x2,  0x0, 0x1D, 0x0,  0x0};
u8 D_80801038_chhoney[16] = {0x0, 0x13, 0x6, 0x79, 0x0, 0x16, 0x46, 0x50,
                             0x0, 0x1,  0x5, 0xDC, 0x9, 0xC4, 0x0,  0x0};
int D_80801048_chhoney[18] = {0x550229,
                              0x7040001,
                              0x0,
                              (u32) func_80800A5C_chhoney,
                              (u32) func_80105834,
                              (u32) func_801018A4,
                              0xBB80000,
                              0x3FE66666,
                              0x0,
                              0x40000000,
                              (u32) func_80800634_chhoney,
                              (u32) func_80108ED0,
                              0x0,
                              (u32) func_80800244_chhoney,
                              (u32) func_80107C2C,
                              -0x7DFF8FB0,
                              (u32) func_8080046C_chhoney,
                              0x0};
void *D_80801090_chhoney = (void *) 0x022B0196;
static u32 D_80801090_chhoney_rest[17] = {0x7050001,
                                          0x0,
                                          (u32) func_80800A5C_chhoney,
                                          (u32) func_80105834,
                                          (u32) func_801018A4,
                                          0xBB80000,
                                          0x3FE66666,
                                          0x0,
                                          0x40A00000,
                                          (u32) func_80800634_chhoney,
                                          (u32) func_80108ED0,
                                          0x0,
                                          (u32) func_80800244_chhoney,
                                          (u32) func_80107C2C,
                                          0x82007050,
                                          (u32) func_8080046C_chhoney,
                                          0x0};
int D_808010D8_chhoney[18] = {0x22C0197,
                              0x7050001,
                              0x0,
                              (u32) func_80800A5C_chhoney,
                              (u32) func_80105834,
                              (u32) func_801018A4,
                              0xBB80000,
                              0x3FE66666,
                              0x0,
                              0x40A00000,
                              (u32) func_80800634_chhoney,
                              (u32) func_80108ED0,
                              0x0,
                              (u32) func_80800244_chhoney,
                              (u32) func_80107C2C,
                              -0x7DFF8FB0,
                              (u32) func_8080046C_chhoney,
                              0x0};
