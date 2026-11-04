#include "common.h"

#define AF(p, i) (*(f32 *) &(p)->actorData[i])
extern int D_80800C00_chbeanstalkseed[];
extern Vec3f D_80800C48_chbeanstalkseed;
extern void func_800DE498(s32, f32 *, void *, f32, s32, s32);
extern int D_80800C54_chbeanstalkseed[];
typedef struct {
    f32 window[5];
} SeedAnimationWindows;
extern SeedAnimationWindows D_80800BE0_chbeanstalkseed;
extern Vec3f D_80800BF4_chbeanstalkseed;
extern f32 func_800DC178(f32, f32);
typedef struct {
    u8 pad_0[0x72];
    u16 st : 6;
    u16 rest : 10;
} SeedState;
extern f32 func_800F13C4(f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_80013970(f32);
extern void func_800F7F50(s32, f32 *, u32 *, f32, s32, s32);
extern s32 func_800F0064(f32 *, f32, f32 *);
extern s32 func_800D91EC(f32 *, f32);
extern void func_800C3F48(u32);
typedef union {
    u32 word;
    s16 halves[2];
} BeanstalkSeedMessage37;
extern void func_800EE7F8();
extern void func_80101180();
void func_80800804_chbeanstalkseed();
extern void func_80105834(), func_80107C2C(), func_80108ED0(), func_80800950_chbeanstalkseed();

// Kind 1 (seed): despawn if this seed's flag (0x33D + index) is already set.
void func_80800000_chbeanstalkseed(void *param_0)
{
    u16 *data;
    data = (u16 *) param_0;
    if (func_800DA298(((u32) data[0x3B] >> 7) + 0x33D) != 0) {
        func_800FFA88(*(s32 *) param_0);
    }
}

// Footstep sounds at animation windows.
void func_8080003C_chbeanstalkseed(Actor *param_0)
{
    SeedAnimationWindows windows_a = D_80800BE0_chbeanstalkseed;
    Vec3f windows_b = D_80800BF4_chbeanstalkseed;

    if (func_80101E4C(param_0, &windows_a)) {
        func_800C4140(((u16) (u32) (func_800DC178(0.95f, 1.05f) * 1023.0f) << 21) + 0xDABF0,
                      param_0->position, 0x03E800FA);
    } else if (func_80101E4C(param_0, &windows_b)) {
        func_800C4140(((u16) (u32) (func_800DC178(0.95f, 1.05f) * 1023.0f) << 21) + 0xDACD5,
                      param_0->position, 0x03E800FA);
    }
}

// Seed message handler: on collect (0x3E) set flag, give bean item 0x50, first-time dialog.
s32 func_8080026C_chbeanstalkseed(u8 *param_0, s32 param_1, s32 param_2)
{
    if (param_1 == 0x3E) {
        func_800DA544(((u32) *(u16 *) ((u8 *) param_0 + 0x76) >> 7) + 0x33D);
        func_800FC6B0(0);
        func_800D1844(0x50);
        if ((func_800DA298(0x6BE) == 0) && (func_800F5410(func_800F54E4()) == 1)) {
            _subaddiedialog_entrypoint_11(*(s32 *) ((u8 *) param_0 + 0), 0x1430, 6, param_0 + 4,
                                          0xC);
            func_800DA544(0x6BE);
        }
        func_800FFA88(*(s32 *) ((u8 *) param_0 + 0));
        return 1;
    }
    return 0;
}

int chbeanstalkseed_entrypoint_0()
{
    return (int) &D_80800C00_chbeanstalkseed;
}

// Can the player plant a seed here (has item 0x50, right form).
s32 func_80800328_chbeanstalkseed()
{
    if (func_8010C500() == 0) {
        return 0;
    }
    if (func_800D1A04(0x50) == 0) {
        return 0;
    }
    if (func_800F64A4(func_800F54E4(), 0x201) == 0) {
        return 0;
    }
    if (func_800F6720(func_800F54E4()) != 0) {
        return 0;
    }
    if (func_800F66F0(func_800F54E4()) != 0) {
        return 0;
    }
    return 1;
}

// Kind 2 (planting spot) update, by state.
void func_808003D8_chbeanstalkseed(Actor *param_0)
{
    s32 unk_0;
    f32 growth;
    s32 i;
    s32 item;
    s32 found;
    f32 push;
    f32 hit_pos[3];

    switch (((SeedState *) param_0)->st) {
        case 1:
            if (func_80800328_chbeanstalkseed(param_0)) {
                item = func_801000D8(param_0, 1, 0x14);
                _subaddieitem_entrypoint_0(item, 0x481, 0x3E8, 0);
                _subaddieitem_entrypoint_2(item);
                func_80101FDC(param_0, 2);
            }
            break;
        case 2:
            found = func_80100094(param_0, 1);
            if (_subaddieitem_entrypoint_3(param_0, param_0->position, found)) {
                found = _subaddiefind_entrypoint_2(0x481, 0);
                if (found != 0) {
                    param_0->rotation[1] = *(f32 *) (found + 0x48);
                    func_800FFA88(*(s32 *) found);
                }
                func_80800804_chbeanstalkseed(param_0, 3);
                func_80100074(param_0, 1, 0);
            }
            break;
        case 3:
            func_8010C964(param_0);
            break;
        case 4:
            if (func_800D91EC(&param_0->unk58, 6.0f)) {
                func_80800804_chbeanstalkseed(param_0, 5);
                break;
            }
            growth = 0.00001f;
            for (i = 0; i < 8; i++) {
                if (param_0->unk58 < 0.75f * i) {
                    continue;
                }
                if (0.75f * (i + 1) < param_0[0].unk58) {
                    growth += 0.125f;
                } else {
                    growth += func_80013970(func_800F10B4(func_800F13C4(param_0->unk58, 0.75f),
                                                           0.0f, 0.75f, 0.0f, 90.0f)) *
                               0.125f;
                }
            }
            AF(param_0, 3) = param_0->unk54;
            param_0->unk54 = growth;
            param_0->scale = func_800F10B4(param_0->unk58, 0.0f, 6.0f, 0.0f, 1.0f) * growth;
            if (func_800F13C4(AF(param_0, 3), 0.125f) > func_800F13C4(param_0->unk54, 0.125f)) {
                if (param_0->unk58 < 5.8f) {
                    func_800C3F48(
                        ((u16) (u32) (func_800F10B4(param_0->unk58, 0.0f, 6.0f, 0.5f, 1.0f) *
                                      1023.0f)
                         << 21) +
                        0x1B5C1D);
                }
            }
            break;
        case 5:
            func_8010D254(hit_pos);
            if (func_800F0064(hit_pos, param_0->scale * 150.0f, param_0->position)) {
                if (param_0->position[1] < hit_pos[1] && hit_pos[1] <= AF(param_0, 5)) {
                    _subaddieDll_entrypoint_4(param_0, 1);
                    push = func_800F10B4(hit_pos[1], param_0->position[1], AF(param_0, 5),
                                            100.0f, 75.0f) *
                              param_0->scale;
                    i = func_800F54E4();
                    func_800F7F50(i, param_0->position, &param_0->actorData[4], push, 1,
                                  1);
                    break;
                }
            }
            _subaddieDll_entrypoint_4(param_0, 0);
    }
}

// Enter planting spot state; 3 = planted, 4 = growing, 5 = fully grown.
void func_80800804_chbeanstalkseed(param_0, param_1) Actor *param_0;
s32 param_1;
{
    switch (param_1) {
        case 1:
            param_0->unk64_16 = 0;
            break;
        case 3:
            param_0->unk64_16 = 1;
            func_80103140(param_0, 0x8CF, param_0->unk0->unk16);
            func_800DA544(param_0->unk74_7 + 0x323);
            break;
        case 4:
            _subaddieDll_entrypoint_4(param_0, 1);
            func_80103140(param_0, 0x8DD, param_0->unk0->unk16);
            *(f32 *) ((u8 *) param_0 + 0x58) = 0.0f;
            param_0->scale = 0.01f;
            _capod_entrypoint_13(param_0->unk0, 0, param_0->unk74_7 * 2 - 0x58, 0x6810);
            *(f32 *) ((u8 *) param_0 + 0x54) = 1.0f;
            func_800C3F48(0x3FFB5C1D);
            break;
        case 5:
            func_800DA544(param_0->unk74_7 + 0x325);
            _subaddieDll_entrypoint_4(param_0, 0);
            param_0->scale = 1.0f;
            func_8010A63C(param_0);
            break;
    }
    func_80102424(param_0, param_1);
}

void func_80800950_chbeanstalkseed(param_0, param_1) Actor *param_0;
s32 param_1;
{
    Vec3f offset;
    switch (param_0->unk70_10) {
        case 1:
        case 2:
            break;
        case 4:
            func_80101870(param_0, param_1);
            if (param_0->unk7C_12) {
                offset = D_80800C48_chbeanstalkseed;
                func_800DF830(1);
                func_800DE498(param_1, param_0->position, offset.f, 1.0f, 0, func_800D674C(0x8CF));
            }
            break;
        default:
            func_80101870(param_0, param_1);
    }
}

s32 func_80800A0C_chbeanstalkseed(Actor *param_0, s32 param_1, BeanstalkSeedMessage37 param_2)
{
    s32 index;

    switch (param_1) {
        case 11:
            _capod_entrypoint_14();
            func_80101180(0x40E, 0x4C, 0);
            return 4;
        case 0x4B:
            if (param_0->unk70_10 == 3) {
                func_80800804_chbeanstalkseed(param_0, 4);
                return 1;
            }
            return 0;
        case 0x95:
            func_800EE7F8((f32 *) &param_0->actorData[4], param_0->position);
            *(f32 *) &param_0->actorData[5] += 2412.0f * param_0->scale * 0.8f;
            index = param_0->unk74_7;
            if (index >= 51 || index < 53) {
                if (func_800DA298(index + 0x325))
                    func_80800804_chbeanstalkseed(param_0, 5);
                else if (func_800DA298(param_0->unk74_7 + 0x323))
                    func_80800804_chbeanstalkseed(param_0, 3);
                else
                    func_80800804_chbeanstalkseed(param_0, 1);
            }
            return 1;
        default:
            return 0;
    }
}

int chbeanstalkseed_entrypoint_1()
{
    return (int) &D_80800C54_chbeanstalkseed;
}

extern int func_80101870();
u32 D_80800BD0_chbeanstalkseed[4] = {0x0, 0x0, 0x407B851F, 0x1FC0001};
SeedAnimationWindows D_80800BE0_chbeanstalkseed = {0.07f, 0.2f, 0.57f, 0.7f, -1.0f};
Vec3f D_80800BF4_chbeanstalkseed = {0.37f, 0.87f, -1.0f};
int D_80800C00_chbeanstalkseed[18] = {0x127040D,
                                      0x8CF0001,
                                      (u32) &D_80800BD0_chbeanstalkseed,
                                      (u32) func_8080003C_chbeanstalkseed,
                                      (u32) func_80105834,
                                      (u32) func_80101870,
                                      0x3E80000,
                                      0x0,
                                      0x0,
                                      0x800000,
                                      0x0,
                                      (u32) func_80108ED0,
                                      0x0,
                                      (u32) func_80800000_chbeanstalkseed,
                                      (u32) func_80107C2C,
                                      -0x7FFFDC00,
                                      (u32) func_8080026C_chbeanstalkseed,
                                      0x0};
Vec3f D_80800C48_chbeanstalkseed = {0.0f, 0.0f, 0.0f};
int D_80800C54_chbeanstalkseed[19] = {0x1580480,
                                      0x8DD0001,
                                      0x0,
                                      (u32) func_808003D8_chbeanstalkseed,
                                      (u32) func_80105834,
                                      (u32) func_80800950_chbeanstalkseed,
                                      0x7D00000,
                                      0x0,
                                      0x0,
                                      0x20421,
                                      0x0,
                                      (u32) func_80108ED0,
                                      0x0,
                                      0x0,
                                      (u32) func_80107C2C,
                                      -0x7FDFDBFE,
                                      (u32) func_80800A0C_chbeanstalkseed,
                                      0x0,
                                      0x0};
