#include "common.h"
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);

typedef struct {
    s16 kind, sprite, slot;
} EggEffectRecord;
extern EggEffectRecord D_80800550_fxegg[];
extern void func_800BA75C(s32, s32);
extern void func_800BA22C(s32, s32);
extern s32 D_80800574_fxegg[];
extern u8 D_808005B0_fxegg[];
extern u8 D_808005D8_fxegg[];
extern u8 D_80800614_fxegg[];
extern void func_800EFA20(f32 *, f32 *, f32);
extern void func_800BA930(s32, s32, s32, s32, s32, s32, s32);
extern s32 D_80800630_fxegg[];
extern s32 D_80800658_fxegg[];
extern s32 func_800B5BE4(s32);
int func_8080009C_fxegg(s32, s32, s32, f32);

// Returns the record for the effect kind; unknown kinds fall back to kind 1.
EggEffectRecord *func_80800000_fxegg(s32 kind)
{
    s32 i;

    while (1) {
        for (i = 0; D_80800550_fxegg[i].kind != 0; i++) {
            if (D_80800550_fxegg[i].kind == kind) {
                return &D_80800550_fxegg[i];
            }
        }
        kind = 1;
    }
}

void fxegg_entrypoint_0(s32 kind, s32 pos, f32 unk_2)
{
    s16 *record = func_80800000_fxegg(kind);
    s32 emitter = func_8080009C_fxegg(record[1], record[2], pos, unk_2);
    func_800BA75C(emitter, pos);
    func_800BA22C(emitter, 5);
}

// Matching: no return statement in this function; needed for the match.
int func_8080009C_fxegg(s32 sprite, s32 slot, s32 pos, f32 unk_3)
{
    s32 emitter;
    // Matching: `| 0` is needed for the match.
    emitter = func_800B5BE4(slot | 0);
    func_800BA670(emitter, sprite);
    func_800BABB8(emitter, pos, pos, unk_3, &D_80800574_fxegg);
}

void func_808000F8_fxegg(s32 emitter, s32 pos, s32 sprite, f32 unk_3)
{
    // Matching: `| 0` is needed for the match.
    func_800BA3FC(emitter, sprite | 0);
    func_800BABB8(emitter, pos, 0, unk_3, &D_808005B0_fxegg);
}

s32 fxegg_entrypoint_1(s32 pos, f32 unk_1)
{
    s32 emitter;

    emitter = func_800B5BE4(0xC);
    // Matching: `| 0` is needed for the match.
    func_808000F8_fxegg(emitter | 0, pos, 0x9E5, unk_1);
    return emitter;
}

s32 fxegg_entrypoint_2(s32 pos, f32 unk_1)
{
    s32 emitter;

    emitter = func_800B5BE4(0xB);
    // Matching: `| 0` is needed for the match.
    func_808000F8_fxegg(emitter | 0, pos, 0x9E0, unk_1);
    return emitter;
}

void func_808001CC_fxegg(s32 emitter, s32 pos, f32 unk_2)
{
    func_800BABB8(emitter, pos, 0, unk_2, D_808005D8_fxegg);
}

s32 fxegg_entrypoint_3(s32 pos, f32 unk_1)
{
    s32 emitter;

    emitter = func_800B5BE4(0x13);
    // Matching: `| 0` is needed for the match.
    func_808001CC_fxegg(emitter | 0, pos, unk_1);
    return emitter;
}

int fxegg_entrypoint_4(s32 pos, f32 unk_1)
{
    s32 emitter;
    emitter = func_800B5BE4(0x21);
    // Matching: `| 0` is needed for the match.
    func_808000F8_fxegg(emitter | 0, pos, 0x9E4, unk_1);
    return emitter;
}

s32 fxegg_entrypoint_5(f32 *pos, f32 *velocity, f32 unk_2)
{
    s32 emitter;
    f32 vel[3];
    emitter = _fxdlsmoke_entrypoint_0();
    if (velocity) {
        func_800EFA20(vel, velocity, 0.15f);
        func_800BA930(emitter, (s16) vel[0], (s16) (vel[1] + 60.0f), (s16) vel[2],
                      (s16) vel[0], (s32) (vel[1] + 100.0f), (s16) vel[2]);
    }
    func_800BABB8(emitter, pos, pos, unk_2, D_80800614_fxegg);
    return emitter;
}

s32 fxegg_entrypoint_6(f32 *pos, f32 unk_1, f32 *velocity)
{
    s32 emitter;

    emitter = func_800B5BE4(0x17);
    func_800BA930(emitter, (s16) velocity[0], (s16) velocity[1], (s16) velocity[2], (s16) velocity[0],
                  (s16) velocity[1], (s16) velocity[2]);
    func_800BA3FC(emitter, 0x9E2);
    func_800BABB8(emitter, pos, 0, unk_1, &D_80800630_fxegg);
    return emitter;
}

void func_80800410_fxegg(s32 emitter, f32 *pos, f32 *velocity, s32 sprite, f32 unk_4)
{
    func_800BA930(emitter, (s16) velocity[0], (s16) velocity[1], (s16) velocity[2], (s16) velocity[0],
                  (s16) velocity[1], (s16) velocity[2]);
    func_800BA3FC(emitter, sprite);
    func_800BABB8(emitter, pos, NULL, unk_4, D_80800658_fxegg);
}

void fxegg_entrypoint_7(s32 pos, s32 velocity, f32 unk_2)
{
    func_80800410_fxegg(func_800B5BE4(0xB), pos, velocity, 0x9E0, unk_2);
}

void fxegg_entrypoint_8(s32 pos, s32 velocity, f32 unk_2)
{
    func_80800410_fxegg(func_800B5BE4(0xC), pos, velocity, 0x9E5, unk_2);
}

// TU-NOTE: The overlay .data is defined here in C. Values are taken from the ROM.
// The externs of D_80800574_fxegg and D_80800630_fxegg are declared as s32[] to match the objects.

EggEffectRecord D_80800550_fxegg[6] = {0x1, 0x611, 0x5,  0x2, 0x71B, 0x26, 0x3, 0x71E, 0x28,
                                       0x5, 0x71A, 0x25, 0x7, 0x71C, 0x27, 0x0, 0x0,   0x0};
s32 D_80800574_fxegg[15] = {0x160400,  0x220333,  0x4000033, 0x330027,  0x1900190,
                            0x3200320, 0x2A0000,  0x20180,   0x180002C, -0xC7FF38,
                            -0xC7FF38, 0x19000C8, 0xC0028,   0x1BFCE0,  -0x3200000};
u8 D_808005B0_fxegg[40] = {0x0, 0xC,  0x0, 0x20, 0x0, 0x15, 0x0, 0x19, 0x0, 0x33,
                           0x0, 0x22, 0x1, 0x0,  0x1, 0x0,  0x0, 0x66, 0x0, 0x66,
                           0x0, 0x27, 0x1, 0x90, 0x1, 0x90, 0x3, 0x20, 0x3, 0x20,
                           0x0, 0x2B, 0x0, 0x28, 0x0, 0x28, 0x1, 0x1A, 0x0, 0x0};
u8 D_808005D8_fxegg[60] = {0x0,  0x1D, 0x9, 0xCE, 0x0, 0x16, 0x12, 0x0,  0x0, 0x32, 0x0,  0x2,
                           0x0,  0x15, 0x0, 0x0,  0x0, 0x99, 0x0,  0x22, 0x1, 0x99, 0x2,  0x0,
                           0x1,  0x33, 0x1, 0x99, 0x0, 0x2B, 0x0,  0xA6, 0x0, 0xA6, 0x0,  0x1B,
                           0x1,  0x2C, 0x1, 0x2C, 0x0, 0x18, 0x0,  0x0,  0x0, 0x0,  0x19, 0x0,
                           0x19, 0x0,  0x0, 0x17, 0x0, 0x80, 0x1,  0x1A, 0x0, 0x0,  0x0,  0x0};
u8 D_80800614_fxegg[28] = {0x0, 0x15, 0x0, 0x0,  0x0, 0x33, 0x0, 0x22, 0x1, 0x99,
                           0x2, 0x0,  0x2, 0xCC, 0x3, 0x99, 0x0, 0x2B, 0x0, 0x99,
                           0x0, 0xB3, 0x1, 0x1A, 0x0, 0x0,  0x0, 0x0};
s32 D_80800630_fxegg[10] = {0xC000C,  0x150019,  0x330022,  0x1000100, 0x660066,
                            0x270190, 0x1900320, 0x320002B, 0x4C004C,  0x11A0000};
s32 D_80800658_fxegg[10] = {0xC0001,  0x150019,  0x330022,  0x1000100, 0x660066,
                            0x270190, 0x1900320, 0x320002B, 0x280028,  0x11A0000};
