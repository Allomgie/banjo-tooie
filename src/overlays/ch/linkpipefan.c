// Possibly spinning fan blades (variants 0x33..0x39, one save flag each) that hurt on contact.
// Projectiles slow or stop them; an egg breaks a stopped fan. Speed drives sound and alpha.
#include "common.h"

extern s32 D_8080091C_chlinkpipefan[];
extern s32 D_80800960_chlinkpipefan[];
extern s32 D_80800994_chlinkpipefan[];
extern s32 D_808009A0_chlinkpipefan[];
extern f32 func_800F13C4(f32, f32);
extern void func_800DA544(s32);
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
extern void _chskeletonexplode_entrypoint_7(Actor *, f32 *);
extern Actor *func_80106790(Unk80132ED0 *);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern s32 D_808009AC_chlinkpipefan[];
extern s32 D_808009B8_chlinkpipefan[];
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
typedef union {
    Unk80132ED0 *marker;
    s32 word;
} Mass63FanEvent;
extern int D_808009C8_chlinkpipefan[];
extern u8 D_80800910_chlinkpipefan[];
extern void _chlinkpipefan_entrypoint_0(void);
extern f32 func_800F1FF0(f32, f32, f32, f32, f32);
extern f32 func_800D8FF8(void);
extern f32 func_800136E4(f32);
extern f32 func_800DC178(f32, f32);
extern s32 func_800D91EC(f32 *, f32);
extern s32 func_800D90F8(f32 *, f32);
extern void func_800C4208(s32, f32, s32, f32 *, f32, f32);
extern void _subaddieaudioloop_entrypoint_0(Actor *, f32);

// Init: loads the variant (0x33..0x39) and removes the fan if its flag is already set.
void func_80800000_chlinkpipefan(u8 *actor)
{
    u32 variant;
    u32 variant_idx;
    int shift;
    variant = (variant_idx = (u32) *(u16 *) ((u8 *) actor + 0x76) >> 7);
    if (((s32) variant < 0x33) || ((s32) variant >= 0x3A)) {
        func_800FFA88(*(s32 *) ((u8 *) actor + 0));
        // Matching: separate shift variable and empty block needed for the match.
        shift = 7;
        if (0) {
        }
        variant_idx = (u32) *(u16 *) ((u8 *) actor + 0x76) >> shift;
    }
    if (func_800DA298(variant_idx + 0x15C) != 0) {
        func_800FFA88(*(s32 *) ((u8 *) actor + 0));
    }
    *(f32 *) ((u8 *) actor + 0x34) = 1.5f;
}

void func_808003B4_chlinkpipefan();

// Matching: the line breaks in this function are needed for the match.
// Per-frame update: spin speed by state, whoosh and loop sounds, blade alpha.
void func_80800080_chlinkpipefan(Actor *fan)
{
    s32 state;
    f32 prev_phase;
    f32 pitch;

    state = fan->unk70_10;
    switch (state) {
        case 1:
        fan->rotation[2] = func_800F1FF0(fan->rotation[2], 0.0f, 0.1f, 0.1f, 3.0f);
        break;
        case 2:
        if (func_800D91EC((f32 *)&fan->actorData[7], 1.5f)) {
            fan->unk54 = 450.0f;
        } else {
            fan->unk54 = func_800F10B4(*(f32 *)&fan->actorData[7], 1.5f, 0, 450.0f, 0);
        }
        break;
        case 3:
        if (func_800D90F8((f32 *)&fan->actorData[7], 0.75f)) {
            if (func_800D90A4(&fan->unk58)) {
                func_808003B4_chlinkpipefan(fan, 2);
            }
        } else {
            fan->unk54 = func_800F10B4(*(f32 *)&fan->actorData[7], 1.5f, 0, 450.0f, 0);
        }
        break;
        case 4:
        if (func_800D90A4((f32 *)&fan->actorData[7])) {
            fan->unk54 = 0.0f;
            if (func_800D90A4(&fan->unk58)) {
                func_808003B4_chlinkpipefan(fan, 2);
            }
        } else {
            fan->unk54 = func_800F10B4(*(f32 *)&fan->actorData[7], 1.5f, 0, 450.0f, 0);
        }
    }
    ((f32 *)fan->actorData)[3] = fan->rotation[2];
    fan->rotation[2] = func_800136E4(fan->rotation[2] + func_800D8FF8() * fan->unk54);
    prev_phase = func_800F13C4(((f32 *)fan->actorData)[3], 90.0f); if (func_800F13C4(fan->rotation[2], 90.0f) < prev_phase && fan->unk54 > 225.0f) {
        pitch = func_800F10B4(fan->unk54, 225.0f, 450.0f, 0.3f, 0.6f); func_800C4208(0x3FF, func_800DC178(-0.05f, 0.05f) + pitch, 0x4A38, fan->position, 200.0f, 1500.0f);
    }
    if (fan->unk54 != 0.0f) {
        _subaddieaudioloop_entrypoint_4(fan, fan->position, 1, D_80800910_chlinkpipefan);
        _subaddieaudioloop_entrypoint_0(fan, func_800F10B4(fan->unk54, 225.0f, 450.0f, 0.4f, 0.8f));
    }
    if (fan->unk6C_0) {
        fan->unk6C_0--;
    }
    if (func_801065A4(fan)) {
        _glid_entrypoint_0(func_801065A4(fan), 1, _chlinkpipefan_entrypoint_0, fan->unk0);
    }
    func_8010A654(fan, fan->unk70_10 == 4);
}

// State change: 1 break and set flag, 2 spin, 3 slowed, 4 stopped.
void func_808003B4_chlinkpipefan(Actor *fan, u32 state)
{
    f32 *pos;

    switch (state) {
        case 1:
            fan->rotation[2] = func_800F13C4(fan->rotation[2], 90.0f);
            if (fan->rotation[2] > 45.0f)
                fan->rotation[2] = 90.0f - fan->rotation[2];
            func_800DA544(fan->unk74_7 + 0x15C);
            pos = fan->position;
            func_800BBCB8(pos, pos, 1.0f, 4, &D_8080091C_chlinkpipefan);
            func_800BBCB8(pos, pos, 1.0f, 10, &D_80800960_chlinkpipefan);
            _subaddieaudioquick_entrypoint_2(fan, pos, &D_80800994_chlinkpipefan);
            _chskeletonexplode_entrypoint_7(fan, pos);
            return;
        case 2:
            func_80101FDC(fan, state);
            return;
        case 3:
            func_80101FDC(fan, state);
            fan->unk58 = 5.0f;
            return;
        case 4:
            fan->unk58 = 5.0f;
            if (fan->unk70_10 != 4) {
                _subaddieaudioquick_entrypoint_2(fan, fan->position,
                                                 &D_808009A0_chlinkpipefan);
                func_80101FDC(fan, state);
            }
    }
}

// Vertex callback: sets the blades' vertex alpha from the spin speed.
void chlinkpipefan_entrypoint_0(void *unk_0, void *unk_1, u8 (*verts)[16], s32 count,
                                Unk80132ED0 *marker)
{
    f32 alpha_f;
    u8(*end)[16];
    u8 alpha;

    alpha_f = func_800F12D4(func_80106790(marker)->unk54, 225.0f, 450.0f, 0.0f, 255.0f);
    end = verts + count;
    if (verts < end) {
        alpha = (u8) (u32) alpha_f;
        do {
            (*verts)[15] = alpha;
            verts++;
        } while (verts < end);
    }
}

s32 func_80800638_chlinkpipefan(Actor *fan, s32 msg_id, Mass63FanEvent msg)
{
    Actor *target;
    s32 contact_type;
    // Matching: constant held in a variable for the match.
    s32 k = 15;

    switch (msg_id) {
        case 0x3E:
            if (fan->unk70_10 != 4) {
                contact_type = (*(u32 *) ((u8 *) fan->unk0 + 0x18) << 11) >> 28;
                if (k == contact_type) {
                    func_800F79DC(func_800F54E4(), 6, fan->unk0);
                } else if (contact_type == 1) {
                    func_800F79DC(func_800F54E4(), 3, fan->unk0);
                }
            }
            return 1;
        case 0x3F:
            if (func_80106790(msg.marker)->unk6C_9 == 0x15C) {
                func_808003B4_chlinkpipefan(fan, 4);
            } else if (((*(u32 *) ((u8 *) fan->unk0 + 0x18) << 11) >> 28) == 1 &&
                       fan->unk70_10 != 4) {
                func_808003B4_chlinkpipefan(fan, 3);
            }
            if (!fan->unk6C_0) {
                if (fan->unk70_10 == 4) {
                    _subaddieaudioquick_entrypoint_2(fan, fan->position,
                                                     &D_808009B8_chlinkpipefan);
                } else {
                    _subaddieaudioquick_entrypoint_2(fan, fan->position,
                                                     &D_808009AC_chlinkpipefan);
                }
            }
            fan->unk6C_0 = 8;
            return 1;
        case 0x40:
            if (fan->unk70_10 == 4 && fan->unk54 <= 45.0f) {
                func_808003B4_chlinkpipefan(fan, 1);
            }
            return 1;
        case 0x1F:
            func_801015D0(fan);
            func_800DF6BC((s32) func_800F10B4(fan->unk54, 0.0f, 225.0f, 255.0f, 0.0f), 255);
            func_800DF744(1, 1);
            return 1;
        case 0xF:
            target = func_80106790(func_80101080());
            _chskeletonexplode_entrypoint_3(target, 1, 0);
            _chskeletonexplode_entrypoint_4(target, 7);
            _chskeletonexplode_entrypoint_5(
                target, (s32) func_800F10B4(fan->unk54, 0.0f, 225.0f, 255.0f, 0.0f));
            func_800FFA88(fan->unk0);
            return 1;
        default:
            return 0;
    }
}

int chlinkpipefan_entrypoint_1()
{
    return (int) &D_808009C8_chlinkpipefan;
}

extern void func_80105834();
extern void func_801018A4();
extern void func_80108ED0();
extern void func_80107C2C();
u8 D_80800910_chlinkpipefan[12] = {0x0,  0x13, 0x4, 0xA9, 0x0, 0x16,
                                   0x5D, 0xC0, 0x0, 0x1B, 0x0, 0x0};
s32 D_8080091C_chlinkpipefan[17] = {0x1D09DD,   0x2B0400, 0x6000022, 0x2000280, 0x6000800, 0x150000,
                                    0x260019,   0x7,      0x2CFFEC,  0x14FFEC,  0x140028,  0x140020,
                                    0x60606080, 0xAFFEC,  -0x310014, 0x140032,  0x140000};
s32 D_80800960_chlinkpipefan[13] = {0x1D09D9, 0x1B00C8,  0x190000E, 0x320096,  0x150000,
                                    0xFD002B, 0x4000600, 0x20DEDE,  -0x21FFDE, 0xC0019,
                                    0x190026, 0x2D00C8,  0x1900000};
s32 D_80800994_chlinkpipefan[3] = {0x1304C8, 0x166D60, 0x1B0000};
s32 D_808009A0_chlinkpipefan[3] = {0x13052B, 0x164E20, 0x1B0000};
s32 D_808009AC_chlinkpipefan[3] = {0x1304A0, 0x166D60, 0x1B0000};
s32 D_808009B8_chlinkpipefan[4] = {0x130546, 0xA0080, 0x166D60, 0x1B0000};
int D_808009C8_chlinkpipefan[18] = {0x133029C,
                                    0x6F10002,
                                    0x0,
                                    (u32) func_80800080_chlinkpipefan,
                                    (u32) func_80105834,
                                    (u32) func_801018A4,
                                    0x17700000,
                                    0x0,
                                    0x0,
                                    0x821000,
                                    0x0,
                                    (u32) func_80108ED0,
                                    0x0,
                                    (u32) func_80800000_chlinkpipefan,
                                    (u32) func_80107C2C,
                                    -0x7FFFFC00,
                                    (u32) func_80800638_chlinkpipefan,
                                    0x0};
