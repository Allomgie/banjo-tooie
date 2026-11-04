#include "common.h"

typedef struct {
    u8 unk0;
    u8 pad1[3];
    f32 unk4;
    f32 unk8[3];
    f32 unk14[3];
} RainbowSeg;
extern RainbowSeg *func_80100074(Actor *, s32, s32);
extern void func_800EFD24(f32 *);
extern f32 func_80103EAC(Actor *);
extern void func_800EEC70(f32 *, f32, f32, f32);
extern f32 func_80103EF4(Actor *);
extern void func_800EE780(f32 *, f32 *, f32 *);
extern u8 D_80800FD0_chrainbow[];
extern f32 func_800DC0C0(void);
extern f32 func_800F1214(f32, f32, f32);
extern f32 func_800138D0(f32);
extern void func_800EF04C(f32 *, f32 *);
extern Actor *func_80106790(Unk80132ED0 *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern s32 _capod_entrypoint_14(void);
extern Actor *_subaddiefind_entrypoint_2(s32, s32);
typedef struct {
    f32 v[3];
} RainbowVector;
extern RainbowVector D_80801004_chrainbow;
extern u32 D_80801010_chrainbow[];
extern void _chrainbow_entrypoint_0();
extern s32 func_800D91EC(f32 *, f32);
typedef struct {
    u8 pad0[8];
    f32 pos[3];
    u8 pad14[0xC];
} RbEnt;
extern int func_800EEB9C(f32[3], f32, f32);
extern int func_800EE7F8(f32[3], f32[3]);
void func_80800270_chrainbow();
void func_80800838_chrainbow();

// Starts in state 13 if the rainbow is already spawned (flag 0x1E1), else state 1.
int func_80800000_chrainbow(Actor *actor)
{
    s32 state;
    state = func_800DA298(0x1e1);
    if (state != 0) {
        state = 13;
    } else {
        state = 1;
    }
    func_80800270_chrainbow(actor, state);
}

void func_8080003C_chrainbow(Actor *actor)
{
    switch (actor->unk70_10) {
        case 1:
            if (func_801065A4(actor))
                func_80103110(actor, 0);
            break;
        case 2:
            if (func_800DA298(0x9DE))
                func_80800270_chrainbow(actor, 3);
            break;
        case 3:
            if (func_800D91EC(&actor->unk58, 5.0f))
                func_80800270_chrainbow(actor, 4);
            break;
        case 4:
            if (func_800D91EC(&actor->unk58, 6.5f))
                func_80800270_chrainbow(actor, 5);
            *(f32 *) &actor->actorData[7] = func_800F10B4(actor->unk58, 5.0f, 6.5f, 0.0f, 1.0f);
            break;
        case 5:
            if (func_800D91EC(&actor->unk58, 10.5f))
                func_80800270_chrainbow(actor, 6);
            break;
        case 6:
            if (func_800D91EC(&actor->unk58, 13.5f))
                func_80800270_chrainbow(actor, 7);
            break;
        case 8:
            if (func_800D91EC(&actor->unk58, 18.5f))
                func_80800270_chrainbow(actor, 9);
            break;
        case 12:
            if (func_800D91EC(&actor->unk58, 20.5f))
                func_80800270_chrainbow(actor, 13);
            *(f32 *) &actor->actorData[7] =
                func_800F10B4(actor->unk58, 18.5f, 20.5f, 1.0f, 0.0f);
            break;
        case 13:
            if (func_801065A4(actor) && !actor->unk64_20) {
                actor->unk64_20 = 1;
                _glid_entrypoint_0(func_801065A4(actor), 1, &_chrainbow_entrypoint_0,
                                   actor->unk0);
            }
    }
    func_80800838_chrainbow(actor);
    if (func_801065A4(actor)) {
        _glid_entrypoint_0(func_801065A4(actor), 1, &_chrainbow_entrypoint_0, actor->unk0);
    }
}

void func_80800440_chrainbow();

// Rainbow state change: 3 starts the rain, 13 stops it and sets flag 0x1E1.
void func_80800270_chrainbow(actor, state) Actor *actor;
s32 state;
{
    switch (state) {
        case 1:
            func_80103110(actor, 0);
            actor->unk64_20 = 0;
            actor->unk64_16 = 0;
            actor->unk58 = 0.0f;
            ((f32 *) actor->actorData)[7] = 0.0f;
            break;
        case 2:
            func_80800440_chrainbow(actor);
            func_800DA524(0x9DF);
            break;
        case 3:
            func_80101180(0x2B0, 0xBB, 12);
            _capod_entrypoint_13(actor->unk0, actor->unk0, 9, 0x810);
            actor->unk58 = 0.0f;
            break;
        case 4:
            _fxrain_entrypoint_7(func_800B7C54());
            _chglowbo_entrypoint_6();
            func_800DA544(0x580);
            break;
        case 8:
            actor->unk64_16 = 1;
            ((f32 *) actor->actorData)[7] = 1.0f;
            _capod_entrypoint_13(actor->unk0, actor->unk0, 12, 0x4810);
            _subaddieDll_entrypoint_0(actor);
            break;
        case 12:
            actor->unk58 = 18.5f;
            _capod_entrypoint_13(actor->unk0, actor->unk0, 90, 0x2810);
            break;
        case 13:
            _fxrain_entrypoint_8(func_800B7C54());
            func_800DA524(0x9DE);
            func_800DA544(0x9DF);
            func_800DA544(0x1E1);
            func_80100074(actor, 0, 0);
            _subaddieDll_entrypoint_0(actor);
            func_8010A63C(actor);
            actor->unk64_20 = 0;
            ((f32 *) actor->actorData)[7] = 0.0f;
            actor->unk58 = 20.5f;
            func_80103110(actor, 0);
    }
    func_80101FDC(actor, state);
}

// Creates the 6 rainbow segments.
void func_80800440_chrainbow(Actor *actor)
{
    RainbowSeg *segs;
    s32 i;
    f32 offset[3];
    f32 origin[3];

    segs = func_80100074(actor, 0, 0xC0);
    for (i = 0; i < 6; i++) {
        segs[i].unk0 = 1;
        func_800EFD24(segs[i].unk8);
        segs[i].unk4 = 0.0f;
        func_800EEC70(offset, actor->rotation[0], actor->rotation[1] - 90.0f,
                      func_80103EAC(actor));
        origin[0] = actor->position[0] + offset[0];
        origin[1] = actor->position[1] - func_80103EF4(actor);
        origin[2] = actor->position[2] + offset[2];
        func_800EEC70(offset, actor->rotation[0], actor->rotation[1] - 180.0f,
                      actor->scale * 800.0f * ((f32) i / 5.0f));
        func_800EE780(segs[i].unk14, origin, offset);
    }
}

// Emits a particle burst for one segment at pos.
void func_808005E0_chrainbow(f32 *pos, s32 seg_index)
{
    Actor *emitter;
    emitter = func_800B53A4(1);
    func_800BA3FC((int) emitter, seg_index + 0x9DF);
    func_800BABB8(emitter, pos, 0, 0x3F800000, &D_80800FD0_chrainbow);
}

// Spawns count particle bursts along the rainbow.
void func_8080063C_chrainbow(Actor *actor, f32 spread, s32 count)
{
    Vec3f offset;
    Vec3f spawn_pos;
    Vec3f seg_pos;
    f32 blend;
    s32 seg;
    s32 i;

    for (i = 0; i < count; i++) {
        blend = func_800F1214(func_800DC0C0(), 1.0f, spread);
        seg = func_800DC128(0, 6);
        func_800EEC70(offset.f, actor->rotation[0], actor->rotation[1] - 90.0f,
                      func_80103EAC(actor));
        spawn_pos.f[0] = actor->position[0] + func_800F1214(blend, -offset.f[0], offset.f[0]);
        spawn_pos.f[1] =
            (actor->position[1] - func_80103EF4(actor)) +
            func_800138D0(func_800F1214(blend, 90.0f, 270.0f)) * -func_80103EF4(actor);
        spawn_pos.f[2] = actor->position[2] + func_800F1214(blend, -offset.f[2], offset.f[2]);
        func_800EEC70(seg_pos.f, actor->rotation[0], actor->rotation[1] - 180.0f,
                      (actor->scale * 800.0f) * ((f32) seg / 5.0f));
        func_800EF04C(seg_pos.f, spawn_pos.f);
        func_808005E0_chrainbow(seg_pos.f, seg);
    }
}

void func_80800838_chrainbow(actor) Actor *actor;
{
    RbEnt *ents;
    f32 spin;
    f32 ring_pos[3];
    f32 full_spin;
    f32 unk_0[2];
    f32 ring_pos_b[3];
    f32 progress;
    f32 height;
    f32 unk_1;
    f32 unk_2;
    s32 i;

    full_spin = 720.0f;
    ents = func_80100094(actor, 0);
    switch (actor->unk70_10) {
        case 3:
        case 4:
        case 5:
            progress = func_800F10B4(actor->unk58, 0.0f, 10.5f, 0.0f, 1.0f);
            // Matching: the dead assignment to height is needed for the match.
            height = progress * 1000.0f;
            height = func_800F10B4(actor->unk58, 0.0f, 5.0f, 0.0f, 200.0f);
            unk_2 = func_800F10B4(actor->unk58, 0.0f, 10.5f, 360.0f, 720.0f);
            spin = progress * unk_2;
            progress = 0.0f;
            for (i = 0, unk_1 = 2.0f * spin, spin = 0.0f; i != 6; i++) {
                func_800EE7F8(ents[i].pos, func_80106790(actor->unk3C)->position);
                unk_2 = (f32) i * 60.0f;
                func_800EEB9C(ring_pos, unk_1 + unk_2, 100.0f);
                func_800EF04C(ents[i].pos, ring_pos);
                ents[i].pos[1] += height;
                func_808005E0_chrainbow(ents[i].pos, i);
            }
            break;
        case 6:
            progress = func_800F10B4(actor->unk58, 10.5f, 13.5f, 0.0f, 1.0f);
            height = progress * 1000.0f + 200.0f;
            unk_1 = progress * 1000.0f + 100.0f;
            spin = progress * full_spin;
                // Matching: needed for the match.
            full_spin = 0.0f;
            unk_2 = 2.0f * spin;
            spin = 0.0f;
            for (i = 0; i != 6; i++) {
                func_800EE7F8(ents[i].pos, func_80106790(actor->unk3C)->position);
                progress = (f32) i * 60.0f;
                func_800EEB9C(ring_pos_b, unk_2 + progress, unk_1);
                func_800EF04C(ents[i].pos, ring_pos_b);
                ents[i].pos[1] += height;
                func_808005E0_chrainbow(ents[i].pos, i);
            }
            break;
        case 8:
            func_8080063C_chrainbow(actor, 0.0f, 4);
    }
}

// Vertex callback: fades the rainbow mesh out by vertex alpha.
void chrainbow_entrypoint_0(s32 unk_0, Vtx_tn *src_vtx, Vtx_tn *dst_vtx, s32 count,
                            Unk80132ED0 *handle)
{
    Actor *rainbow;
    Vtx_tn *end;
    f32 fade_end;
    f32 fade_start;
    f32 x;

    rainbow = func_80106790(handle);
    fade_end = func_800F10B4(rainbow->unk58, 13.5f, 18.0f, -3200.0f, 3200.0f);
    fade_start = func_800F10B4(rainbow->unk58, 14.0f, 18.5f, -3200.0f, 3200.0f);
    end = dst_vtx + count;
    for (; dst_vtx < end; dst_vtx++, src_vtx++) {
        x = src_vtx->ob[0];
        if (x < fade_start) {
            *((u8 *) dst_vtx + 0xF) = *((u8 *) src_vtx + 0xF);
        } else if (x < fade_end) {
            *((u8 *) dst_vtx + 0xF) = (u32) func_800F10B4(
                x, fade_start, fade_end, (f32) (u32) *((u8 *) src_vtx + 0xF), 0.0f);
        } else {
            *((u8 *) dst_vtx + 0xF) = 0;
        }
    }
}

// Picks state 0xB if an actor 0x480 handles message 0x4B, else 0xC.
void func_80800CD4_chrainbow(Actor *actor)
{
    Actor *targets[3];
    s32 found;
    s32 i;

    i = _subaddiefind_entrypoint_4(0x480, targets, 3) - 1;
    found = 0;
    for (; i >= 0; i--) {
        if (func_8010114C(targets[i]->unk0, 0x4B, 0)) {
            found = 1;
            break;
        }
    }
    if (found) {
        func_80800270_chrainbow(actor, 0xB);
    } else {
        func_80800270_chrainbow(actor, 0xC);
    }
}

s32 func_80800D88_chrainbow(Actor *actor, s32 message, s32 arg)
{
    Actor *target;

    switch (message) {
        case 11:
            _capod_entrypoint_14();
            if (arg == 9) {
                if (func_800DA298(0x1E1)) {
                    func_80800CD4_chrainbow(actor);
                } else {
                    func_80800270_chrainbow(actor, 8);
                }
                return 4;
            }
            if (arg == 12) {
                func_80800CD4_chrainbow(actor);
            }
            return 4;
        case 0x4B:
            if (arg == 12) {
                func_80800270_chrainbow(actor, 2);
                _subaddieDll_entrypoint_4(actor, 1);
                func_80103110(actor, 1);
                return 1;
            }
            return 0;
        case 0x4C:
            func_80800CD4_chrainbow(actor);
            return 1;
        case 0x95:
            target = _subaddiefind_entrypoint_2(0x2B0, 0);
            if (target) {
                actor->unk3C = target->unk0;
            }
            return 1;
        default:
            return 0;
    }
}

void func_80800EB4_chrainbow(Actor *actor, s32 unk_1)
{
    RainbowVector value;
    func_80101870(actor);
    switch (actor->unk70_10) {
        case 1:
        case 13:
            break;
        default:
            value = D_80801004_chrainbow;
            func_800B99CC(unk_1,
                          (s32) func_800F1214(((f32 *) actor->actorData)[7], 0.0f, 100.0f),
                          value.v);
    }
}

char *chrainbow_entrypoint_1()
{
    return &D_80801010_chrainbow;
}

extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
u8 D_80800FD0_chrainbow[52] = {0x0,  0x16, 0x12, 0x4,  0x0,  0x1B, 0xFE, 0x70, 0xFD, 0xA8, 0x0,
                               0x22, 0x0,  0x33, 0x0,  0x4C, 0x0,  0x0,  0x0,  0x0,  0x0,  0x15,
                               0x0,  0x0,  0x0,  0x99, 0x0,  0x2B, 0x0,  0x4C, 0x0,  0x99, 0x0,
                               0x2F, 0x0,  0x80, 0x0,  0x80, 0x0,  0x0,  0x0,  0x33, 0x0,  0x33,
                               0x0,  0x0,  0x0,  0xC0, 0x1,  0x1A, 0x0,  0x0};
RainbowVector D_80801004_chrainbow = {0.0f, 0.0f, 0.0f};
u32 D_80801010_chrainbow[20] = {0x165040E,
                                0x8CE0001,
                                0x0,
                                (u32) func_8080003C_chrainbow,
                                (u32) func_80105834,
                                (u32) func_80800EB4_chrainbow,
                                0x4E20,
                                0x0,
                                0x0,
                                0x21000,
                                0x0,
                                (u32) func_80108ED0,
                                0x0,
                                (u32) func_80800000_chrainbow,
                                (u32) func_80107C2C,
                                0x80000402,
                                (u32) func_80800D88_chrainbow,
                                0x0,
                                0x0,
                                0x0};
