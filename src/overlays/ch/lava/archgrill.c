#include "common.h"

extern int func_800D9078(void *);
extern int D_808006A4_chlavaarchgrill[];
typedef struct {
    u8 unk0;
    u8 pad1;
    u16 unk2;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 unk9;
} GrillEvent;
extern GrillEvent D_80800610_chlavaarchgrill[12];
extern s32 func_800DA564(s32, s32);
extern void func_80101FDC(Actor *, s32);
extern void _capod_entrypoint_14(void);
extern void _capod_entrypoint_13(Unk80132ED0 *, s32, s32, s32);
extern void func_800DA7A8();
extern void func_80101180(s32, s32, s32);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void func_80101870(), func_80105834(), func_80107C2C(), func_80800000_chlavaarchgrill(),
    func_808002D0_chlavaarchgrill();

void func_80800000_chlavaarchgrill(actor) f32 *actor;
{
    actor[11] = actor[2];
    func_800DA7A8(0xA1A, 0, 3, actor);
    func_8010A800(actor, 2);
}

// Message handler: table lookup (D_80800610) for stage transitions; stage counter is FLAG3_A1A (3 bits).
s32 func_80800044_chlavaarchgrill(Actor *this, s32 arg1, s32 arg2)
{
    s32 stage;
    s32 count;
    s32 result;
    s32 i;

    stage = func_800DA564(0xA1A, 3);
    count = 12;
    for (i = 0; i < count; i++) {
        if (D_80800610_chlavaarchgrill[i].unk0 != this->unk74_7) {
            continue;
        }
        if (arg1 != D_80800610_chlavaarchgrill[i].unk2) {
            continue;
        }
        if (D_80800610_chlavaarchgrill[i].unk5 == this->unk70_10 &&
            arg2 == D_80800610_chlavaarchgrill[i].unk4 && stage == D_80800610_chlavaarchgrill[i].unk9) {
            result = 1;
            func_80101FDC(this, D_80800610_chlavaarchgrill[i].unk6);
            if (D_80800610_chlavaarchgrill[i].unk7) {
                if (D_80800610_chlavaarchgrill[i].unk4) {
                    _capod_entrypoint_14();
                    _capod_entrypoint_13(this->unk0, 0, D_80800610_chlavaarchgrill[i].unk7, 0x2010);
                    result = 4;
                } else {
                    _capod_entrypoint_13(this->unk0, 0, D_80800610_chlavaarchgrill[i].unk7, 0x10);
                }
            }
            switch (D_80800610_chlavaarchgrill[i].unk8) {
                case 1:
                    *(f32 *) &this->actorData[0] = 0.75f;
                    break;
                case 2:
                    func_800DA7A8(0xA1A, 1, 3);
                    func_80101180(0x288, 0x61, 0);
                    break;
                case 3:
                    *(f32 *) &this->actorData[0] = 0.75f;
                    func_800DA7A8(0xA1A, 2, 3);
                    break;
                case 4:
                    func_800DA7A8(0xA1A, 3, 3);
                    func_80101180(0x288, 0x5D, 0);
                    break;
                case 5:
                    *(f32 *) &this->actorData[0] = 0.75f;
                    func_800DA7A8(0xA1A, 4, 3);
            }
            return result;
        }
    }
    return 0;
}

// When the timer runs out, go to next_state and start the 2 s slide timer.
void func_80800288_chlavaarchgrill(s32 *actor, s32 next_state)
{
    if (func_800D9078(actor + 6)) {
        func_80101FDC(actor, next_state);
        *(float *) ((char *) actor + 0x58) = 2.0f;
    }
}

// Update: each slide moves the grill by half its height (190 * scale / 2).
void func_808002D0_chlavaarchgrill(actor) Actor *actor;
{
    extern u8 D_80800688_chlavaarchgrill[];
    extern u8 D_80800698_chlavaarchgrill[];

    switch ((u32) *(u16 *) ((char *) actor + 0x72) >> 10) {
        case 2:
            func_80800288_chlavaarchgrill(actor, 3);
            break;

        case 3: {
            s32 done;
            done = func_800D9078((char *) actor + 0x58);

            *(f32 *) ((char *) actor + 8) =
                func_800F12D4(*(f32 *) ((char *) actor + 0x58), 0, 2.0f,
                              (190.0f * *(f32 *) ((char *) actor + 0x38)) / 2 +
                                  *(f32 *) ((char *) actor + 0x2C),
                              *(f32 *) ((char *) actor + 0x2C));

            _subaddieaudioloop_entrypoint_4(actor, (char *) actor + 4, 1,
                                            D_80800688_chlavaarchgrill);

            if (done != 0) {
                func_80101FDC(actor, 4);
            }
            break;
        }

        case 5:
            func_80800288_chlavaarchgrill(actor, 6);
            break;

        case 6: {
            s32 done;
            done = func_800D9078((char *) actor + 0x58);

            *(f32 *) ((char *) actor + 8) = func_800F12D4(
                *(f32 *) ((char *) actor + 0x58), 0.0f, 2.0f,
                (190.0f * *(f32 *) ((char *) actor + 0x38)) + *(f32 *) ((char *) actor + 0x2C),
                (190.0f * *(f32 *) ((char *) actor + 0x38)) / 2 +
                    *(f32 *) ((char *) actor + 0x2C));

            _subaddieaudioloop_entrypoint_4(actor, (char *) actor + 4, 1,
                                            D_80800688_chlavaarchgrill);

            if (done != 0) {
                func_80101FDC(actor, 7);

                _subaddieaudioquick_entrypoint_2(actor, (char *) actor + 4,
                                                 D_80800698_chlavaarchgrill);
            }
            break;
        }

        case 8:
            func_80800288_chlavaarchgrill(actor, 9);
            break;

        case 9: {
            s32 done;
            done = func_800D9078((char *) actor + 0x58);

            *(f32 *) ((char *) actor + 8) =
                func_800F12D4(*(f32 *) ((char *) actor + 0x58), 2.0f, 0,
                              (190.0f * *(f32 *) ((char *) actor + 0x38)) / 2 +
                                  *(f32 *) ((char *) actor + 0x2C),
                              *(f32 *) ((char *) actor + 0x2C));

            _subaddieaudioloop_entrypoint_4(actor, (char *) actor + 4, 1,
                                            D_80800688_chlavaarchgrill);

            if (done != 0) {
                func_80101FDC(actor, 1);

                _subaddieaudioquick_entrypoint_2(actor, (char *) actor + 4,
                                                 D_80800698_chlavaarchgrill);
            }
            break;
        }

        case 10:
            if (func_800D9078((char *) actor + 0x18)) {
                func_80101FDC(actor, 0xB);
                *(f32 *) ((char *) actor + 0x58) = 4.0f;
            }
            break;

        case 11: {
            s32 done;
            done = func_800D9078((char *) actor + 0x58);

            *(f32 *) ((char *) actor + 8) = func_800F12D4(
                *(f32 *) ((char *) actor + 0x58), 0, 4.0f,
                (190.0f * *(f32 *) ((char *) actor + 0x38)) + *(f32 *) ((char *) actor + 0x2C),
                *(f32 *) ((char *) actor + 0x2C));

            _subaddieaudioloop_entrypoint_4(actor, (char *) actor + 4, 1,
                                            D_80800688_chlavaarchgrill);

            if (done != 0) {
                func_80101FDC(actor, 0xC);
            }
        }
    }
}

int chlavaarchgrill_entrypoint_0()
{
    return &D_808006A4_chlavaarchgrill;
}

GrillEvent D_80800610_chlavaarchgrill[12] = {
    0x32, 0x0,  0xB,  0x20, 0x7,  0x7,  0x1E, 0x2,  0x0,  0x32, 0x0,  0xB,  0x3F, 0x7,  0x7,  0x1E,
    0x2,  0x0,  0x33, 0x0,  0xB,  0x1E, 0x7,  0x7,  0x1C, 0x4,  0x2,  0x32, 0x0,  0x63, 0x0,  0x1,
    0x2,  0x20, 0x1,  0x0,  0x32, 0x0,  0x64, 0x0,  0x4,  0x8,  0x3F, 0x1,  0x0,  0x32, 0x0,  0x61,
    0x0,  0x4,  0x5,  0x3F, 0x1,  0x0,  0x33, 0x0,  0x61, 0x0,  0x1,  0x2,  0x0,  0x3,  0x1,  0x33,
    0x0,  0x61, 0x0,  0x1,  0x2,  0x1E, 0x1,  0x2,  0x33, 0x0,  0x62, 0x0,  0x4,  0x8,  0x40, 0x1,
    0x2,  0x33, 0x0,  0x5D, 0x0,  0x4,  0x5,  0x40, 0x1,  0x2,  0x33, 0x0,  0xB,  0x40, 0x7,  0x7,
    0x1C, 0x4,  0x2,  0x34, 0x0,  0x5D, 0x0,  0x1,  0xA,  0x0,  0x5,  0x3};
u8 D_80800688_chlavaarchgrill[16] = {0x0, 0x13, 0x5, 0x7,  0x0, 0x18, 0x0, 0x2,
                                     0x0, 0xA,  0x0, 0x8C, 0x0, 0x0,  0x0, 0x0};
u8 D_80800698_chlavaarchgrill[12] = {0x0, 0x13, 0x4, 0xC7, 0x0, 0x18, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0};
int D_808006A4_chlavaarchgrill[19] = {0xAC0288,
                                      0x8D80001,
                                      0x0,
                                      (u32) func_808002D0_chlavaarchgrill,
                                      (u32) func_80105834,
                                      (u32) func_80101870,
                                      0x0,
                                      0x0,
                                      0x0,
                                      0x800,
                                      0x0,
                                      0x0,
                                      0x0,
                                      (u32) func_80800000_chlavaarchgrill,
                                      (u32) func_80107C2C,
                                      -0x7FFFFFFE,
                                      (u32) func_80800044_chlavaarchgrill,
                                      0x0,
                                      0x0};
