#include "common.h"

extern Actor *func_80106790();
extern s32 D_80800920_chfantasylakebits[];
extern s32 D_80800928_chfantasylakebits[];
extern s32 D_80800934_chfantasylakebits[];
extern s32 D_80800940_chfantasylakebits[];
extern s32 D_80800980_chfantasylakebits[];
extern s32 D_808009B8_chfantasylakebits[];
extern s32 D_808009C4_chfantasylakebits[];
extern s32 D_808009D0_chfantasylakebits[];
extern s32 D_808009DC_chfantasylakebits[];
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800EFE50(f32 *, void *, void *, f32);
extern s32 func_800BBCB8(f32 *, s32, f32, s32, s32 *);
extern void func_800D91EC(f32 *, f32);
extern void func_800D90A4();
extern void _subaddieaudioloop_entrypoint_0(Actor *, f32);
extern void _subaddieaudioloop_entrypoint_4(Actor *, void *, s32, void *);
extern f32 func_800F1DF4(f32 *, f32 *);
extern void func_800DF500(f32, f32, f32);
extern int D_80800A30_chfantasylakebits[];
extern s32 D_80800A78_chfantasylakebits[];
extern s32 D_80800AB4_chfantasylakebits[];
extern s32 D_80800ADC_chfantasylakebits[];
extern s32 _fxairbub_entrypoint_1(f32 *, f32, f32, f32);
extern int D_80800AF0_chfantasylakebits[];
extern f32 func_800F5628(void *);
extern void _chfantasylakebits_entrypoint_0(void);
void func_80800300_chfantasylakebits();

// Vertex callback: tints the lake mesh yellow and offsets its height.
void chfantasylakebits_entrypoint_0(void *unk_0, Vtx *src_vtx, Vtx *dst_vtx, s32 count,
                                    Unk80132ED0 *handle)
{
    Actor *lake;
    Vtx *end;
    lake = func_80106790(handle);
    end = dst_vtx + count;
    for (; dst_vtx < end; dst_vtx++, src_vtx++) {
        dst_vtx->v.cn[0] = 0xFF;
        dst_vtx->v.cn[1] = 0xFF;
        dst_vtx->v.cn[2] = 0;
        dst_vtx->v.ob[1] = src_vtx->v.ob[1] + lake->actorData[3];
    }
}

// Update: lowers the lake by up to 3200 units while draining (cases 2 and 3).
void func_8080007C_chfantasylakebits(Actor *actor)
{
    s16 height;

    switch ((u32) *(u16 *) ((u8 *) actor + 0x72) >> 10) {
        case 2:
            if (!func_800DB9B0()) {
                _capod_entrypoint_13(actor->unk0, 0, 0x23, 0x30);
            }
            func_800D91EC(&actor->unk58, 12.0f);
            func_80800300_chfantasylakebits(
                actor, (s16) func_800F10B4(actor->unk58, 0.0f, 12.0f, 0, -3200.0f));
            _subaddieaudioloop_entrypoint_4(actor, &D_80800934_chfantasylakebits, 1,
                                            &D_80800920_chfantasylakebits);
            break;
        case 3:
            if (actor->unk58 < 6.0f) {
                func_800BBCB8(&D_80800934_chfantasylakebits, &D_80800934_chfantasylakebits, 1.0f, 2,
                              &D_80800940_chfantasylakebits);
            }
            func_800D91EC(&actor->unk58, 12.0f);
            height = func_800F10B4(actor->unk58, 0.0f, 12.0f, 0, -3200.0f);
            _subaddieaudioloop_entrypoint_4(actor, &D_80800934_chfantasylakebits, 1,
                                            &D_80800920_chfantasylakebits);
            func_80800300_chfantasylakebits(actor, height);
            break;
        case 4:
            func_800BBCB8(&D_808009B8_chfantasylakebits, 0, 1.0f, 2, &D_80800980_chfantasylakebits);
            func_800D90A4((f32 *) ((u8 *) actor + 0x34));
            func_800EFE50(actor->position, &D_808009C4_chfantasylakebits,
                          &D_808009D0_chfantasylakebits,
                          func_800F10B4(*(f32 *) ((u8 *) actor + 0x34), 5.0f, 0.0f, 0.0f, 1.0f));
            actor->unk54 =
                func_800F10B4(*(f32 *) ((u8 *) actor + 0x34), 5.0f, 0.0f, 1.0f, 2.0f);
            _subaddieaudioloop_entrypoint_4(actor, &D_80800934_chfantasylakebits, 1,
                                            &D_80800928_chfantasylakebits);
            _subaddieaudioloop_entrypoint_0(actor, 1.0f);
            if (*(f32 *) ((u8 *) actor + 0x34) > 2.0f) {
                func_800BBCB8(&D_808009B8_chfantasylakebits, 0, 1.0f, 1,
                              &D_808009DC_chfantasylakebits);
            }
            func_800F8418(func_800F54E4(), (f32 *) ((u8 *) actor + 0x28));
    }
}

// Sets the lake surface height offset through the map-mesh wibble effect.
void func_80800300_chfantasylakebits(unk_0, height) s32 unk_0;
s16 height;
{
    s32 mesh;
    mesh = func_800BEA88(1);
    mesh = _idworld_entrypoint_4(mesh, 1);
    if (mesh != 0) {
        _idwibble_entrypoint_5(mesh, height);
    }
}

// Lake controller state change; state 5 is the already-drained lake (flag 0x327).
void func_80800344_chfantasylakebits(actor, state) Actor *actor;
s32 state;
{
    s32 mesh;
    s32 second_mesh;
    s32 drained_mesh;

    switch (state) {
        case 1:
            mesh = func_800BEA88(1);
            actor->unk58 = 0.0f;
            func_800BF744(1, 1);
            *(s32 *) ((u8 *) actor + 0x24) = 0;
            _idworldmake_entrypoint_1(mesh, 0x654, 1, 1);
            _glid_entrypoint_0(mesh, 1, _chfantasylakebits_entrypoint_0, actor->unk0);
            if (func_800EA05C() == 0x13A) {
                second_mesh = func_800BEA88(0);
                *(s32 *) ((u8 *) actor + 0x24) = 0;
                _idworldmake_entrypoint_1(second_mesh, 0x59B, 2, 1);
            }
            actor->unk64_16 = 0;
            func_80103110(actor, 0);
            break;
        case 2:
            func_800F9C38();
            func_80103110(actor, 1);
            actor->unk58 = 0.0f;
            _subaddieDll_entrypoint_0(actor);
            actor->unk54 = 1.0f;
            func_80103140(actor, 0x8DE, actor->unk0->unk16);
            break;
        case 3:
            func_8010A800(actor, 2);
            func_800F5A00(func_800F54E4(), (f32 *) ((u8 *) actor + 0x28));
            *(f32 *) ((u8 *) actor + 0x2C) = func_800F5628(func_800F54E4());
            break;
        case 4:
            func_800BF744(1, 0);
            actor->unk64_16 = 1;
            *(f32 *) ((u8 *) actor + 0x34) = 5.0f;
            _subaddieaudioloop_entrypoint_2(actor);
            break;
        case 5:
            drained_mesh = func_800BEA88(1);
            func_800BF744(1, 0);
            *(s32 *) ((u8 *) actor + 0x24) = -3200;
            _glid_entrypoint_0(drained_mesh, 1, _chfantasylakebits_entrypoint_0, actor->unk0);
            _idworldmake_entrypoint_1(drained_mesh, 0x654, 1, 1);
            func_800DA544(0x327);
            func_800DA524(0x9FC);
            actor->unk64_16 = 0;
            _subaddieaudioloop_entrypoint_2(actor);
            func_800FFAB0(actor);
    }
    func_80101FDC(actor, state);
}

int func_80800570_chfantasylakebits(Actor *actor, s32 message, s32 arg)
{
    f32 target_pos[3];
    switch (message) {
        case 0xB:
            if (arg == 0x23) {
                _capod_entrypoint_14();
                func_80800344_chfantasylakebits(actor, 5);
                _glcutDll_entrypoint_6(0x112, 0x36);
                return 4;
            }
            return 3;
        case 0xC:
            if (actor->unk70_10 == 2)
                func_80800344_chfantasylakebits(actor, 3);
            else if (actor->unk70_10 == 3)
                func_80800344_chfantasylakebits(actor, 4);
            return 3;
        case 0x36:
            func_80800344_chfantasylakebits(actor, 2);
            return 1;
        case 0x1F:
            if (*(u16 *) ((u8 *) actor + 0x64) & 1) {
                func_801015D0(actor);
                func_800E3980(target_pos);
                actor->rotation[1] = func_800F1DF4(actor->position, target_pos);
                func_800DF500(*(f32 *) ((u8 *) actor + 0x54), 4.0f,
                              *(f32 *) ((u8 *) actor + 0x54));
            }
            return 1;
        case 0x95:
            if (func_800DA298(0x327))
                func_80800344_chfantasylakebits(actor, 5);
            else
                func_80800344_chfantasylakebits(actor, 1);
            return 1;
        default:
            return 0;
    }
}

int chfantasylakebits_entrypoint_1()
{
    return (int) &D_80800A30_chfantasylakebits;
}

int func_808006F4_chfantasylakebits(s32 marker[3])
{
    if (!func_800DA298(0x327) && !func_800DA298(0x9FC)) {
        return;
    }
    func_800FFA88(marker[0]);
}

// Stopper: when hit by the right attack it explodes, releases bubbles and starts the draining.
s32 func_8080073C_chfantasylakebits(Actor *actor, s32 message, s32 arg)
{
    s32 bubbles;
    Actor *stopper;

    switch (message) {
        case 0x40:
            if (func_8008FCC8(actor->unk0) == 20) {
                bubbles = _fxairbub_entrypoint_1(actor->position, 200.0f,
                                                 actor->position[1] + 500.0f, 3.0f);
                func_800BA930(bubbles, -60, -250, -60, 60, 0, 60);
                func_800BA22C(bubbles, 10);
                func_800BBCB8(actor->position, actor->position, actor->scale, 3,
                              &D_80800A78_chfantasylakebits);
                func_800BBCB8(actor->position, actor->position, actor->scale, 8,
                              &D_80800AB4_chfantasylakebits);
                func_800C4AF0(actor->position, &D_80800ADC_chfantasylakebits);
                func_80101180(0x415, 0x36, 0);
                _chskeletonexplode_entrypoint_7(actor, actor->position);
                func_800DA544(0x9FC);
                return 1;
            } else {
            }
            return 0;
        case 0x1F:
            func_801015D0(actor);
            func_800DF744(1, 1);
            func_800DF744(2, 1);
            return 1;
        case 0xF:
            stopper = (Actor *) func_80106790(func_80101080());
            _chskeletonexplode_entrypoint_3(stopper, 1, 2);
            _chskeletonexplode_entrypoint_3(stopper, 2, 1);
            _chskeletonexplode_entrypoint_4(stopper, 1);
            func_800FFA88(actor->unk0);
            return 1;
        default:
            return 0;
    }
}

int chfantasylakebits_entrypoint_2()
{
    return (int) &D_80800AF0_chfantasylakebits;
}

extern void func_80105834();
extern void func_801018A4();
extern void func_80108ED0();
extern void func_80107C2C();
s32 D_80800920_chfantasylakebits[2] = {0x20013, 0x56A0000};
s32 D_80800928_chfantasylakebits[3] = {0x20013, 0x3EC0016, 0x7D000000};
s32 D_80800934_chfantasylakebits[3] = {-0x39BCB000, -0x3A860000, 0x45BB8000};
s32 D_80800940_chfantasylakebits[16] = {
    0x1D09CB, 0x161210, 0x1B012C, 0x258002C, -0x960000, -0x95FF6A, 0x96,    0xE0064,
    0x640022, 0x190033, 0x26004C, 0x1500B3,  0xE6002B,  0x330066,  0x70001, 0x0};
s32 D_80800980_chfantasylakebits[14] = {0x1D09F3, 0x20FFFF,   -0x14BFFDE, 0x660080,  0x33004C,
                                        0x1BF254, -0xDABFFF9, 0x1002B,    0xA000A00, 0x160200,
                                        0xE004B,  0x4B001E,   0xC800C8,   0x0};
s32 D_808009B8_chfantasylakebits[3] = {-0x39BC6000, -0x3A736000, 0x45BE0000};
s32 D_808009C4_chfantasylakebits[3] = {-0x39BC6000, -0x3AC48000, 0x45BE0000};
s32 D_808009D0_chfantasylakebits[3] = {-0x39BC6000, -0x3A63C000, 0x45BE0000};
s32 D_808009DC_chfantasylakebits[21] = {
    0x1D09DD, 0x161210, 0x180000,  0x70F00,  0x1E00001B, -0x2570190, 0x2CFF6A,
    0xFF6A,   0x960000, 0x96000E,  0x640064, 0x220080,   0x800180,   0x3000015,
    0x330080, 0x2B00CC, 0x133002F, 0x350066, 0x350000,   0x0,        0xCC0000};
int D_80800A30_chfantasylakebits[18] = {0x1580415,
                                        0x1,
                                        0x0,
                                        (u32) func_8080007C_chfantasylakebits,
                                        (u32) func_80105834,
                                        (u32) func_801018A4,
                                        0x3A98,
                                        0x0,
                                        0x0,
                                        0x1000,
                                        0x0,
                                        (u32) func_80108ED0,
                                        0x0,
                                        0x0,
                                        (u32) func_80107C2C,
                                        -0x7FFFDBFE,
                                        (u32) func_80800570_chfantasylakebits,
                                        0x0};
s32 D_80800A78_chfantasylakebits[15] = {0x1D09DD,    0x2B0800, 0xA000022, 0x1800200, 0x4800600,
                                        0x150000,    0x260019, 0x7,       0x2D0032,  0x640020,
                                        -0x21588E40, 0xAFF9C,  0x19FF9C,  0x64004B,  0x640000};
s32 D_80800AB4_chfantasylakebits[10] = {0x1D092F, 0x14002D, 0x1900258, 0x1BFCE0, -0x257FFDE,
                                        0xB300CC, 0xB300B3, 0x1E0032,  0x32000D, 0x4B0000};
s32 D_80800ADC_chfantasylakebits[5] = {0x130413, 0xA00E6, 0x166D60, 0x2001B, 0x0};
int D_80800AF0_chfantasylakebits[20] = {0x10B0414,
                                        0x92A0001,
                                        0x0,
                                        0x0,
                                        (u32) func_80105834,
                                        (u32) func_801018A4,
                                        0x0,
                                        0x0,
                                        0x0,
                                        0x800,
                                        0x0,
                                        (u32) func_80108ED0,
                                        0x0,
                                        (u32) func_808006F4_chfantasylakebits,
                                        (u32) func_80107C2C,
                                        -0x7FFFD400,
                                        (u32) func_8080073C_chfantasylakebits,
                                        0x0,
                                        0x0,
                                        0x0};
