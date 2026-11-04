// Most likely two player subsystems: bone pose overrides for the Banjo-Kazooie models, and
// the climb target (pole or tree) with its re-grab cooldown and climb interrupt.
#include "common.h"

#define STATE(p) (*(LocalState **) ((u8 *) (p) + 0xAC))
#define QQ (*(S_987CC **) ((u8 *) param_0 + 0xE0))
extern void func_800DFFA0(s32, s32, f32 *);
extern void func_800DFF64(s32, s32, f32 *);
extern void func_800DFFDC(s32, s32, f32 *);
typedef struct {
    f32 angles[4], scale[3], rotation[3];
    u8 angle_active, scale_active, rotation_active, pad_2B;
    f32 scale_factor;
} LocalState;
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern u8 D_80117E9C[];
extern u8 D_80117E90[];
extern int D_80117EB0[];
typedef struct {
    u8 pad_0[0x28];
    f32 cooldown;
    u8 offered;
} S_987CC;
extern f32 func_800D8FF8(void *);
extern f32 func_800F0E00(f32, f32);
extern s32 func_800C6E38(s32);
extern void func_8009E7C8();
void func_80098480();
void func_80098494(u8 *player, f32 angle_0, f32 angle_1, f32 angle_2, f32 angle_3);
void func_800984CC();
void func_800984F0();
int func_80098520(s32 player, f32 scale_factor);

// Bone pose override hook for the player models (called from baanim).
// Returns the size of the PlayerState+0xAC block.
s32 func_80098210()
{
    return 0x30;
}

// Applies the bone pose overrides to the Banjo-Kazooie player models (0x607/0x608).
void func_80098218(void *player, s32 model)
{
    f32 vec[3];
    f32 factor;
    switch (func_80092B80(player)) {
        case 0x607:
        case 0x608:
            if (STATE(player)->angle_active) {
                func_800EFD24(vec);
                vec[0] = STATE(player)->angles[0];
                func_800DFFDC(model, 0x2C, vec);
                vec[0] = STATE(player)->angles[1];
                func_800DFFDC(model, 0x2D, vec);
                vec[0] = STATE(player)->angles[2];
                func_800DFFDC(model, 0x2E, vec);
                vec[0] = STATE(player)->angles[3];
                func_800DFFDC(model, 0x3D, vec);
            }
            if (STATE(player)->rotation_active)
                func_800DFFA0(model, 0x3C, STATE(player)->rotation);
            if (STATE(player)->scale_active) {
                func_800DFF64(model, 0x3C, STATE(player)->scale);
                if (STATE(player)->scale[0] == STATE(player)->scale[1] &&
                    STATE(player)->scale[1] == STATE(player)->scale[2] &&
                    STATE(player)->scale[2] == 1.0f)
                    STATE(player)->scale_active = 0;
            }
            if (STATE(player)->scale_factor != 1.0f) {
                func_800DFC20(model, 0x6C, vec);
                factor = STATE(player)->scale_factor;
                func_800EFA4C(vec, vec[0] * factor, vec[1] * factor,
                              vec[2] * factor);
                func_800DFFA0(model, 0x6C, vec);
            }
        case 0x61C:
        case 0x623:
            break;
    }
}

void func_80098408(void *player)
{
    func_80098480(player, 0, 0);
    func_80098494(player, 0.0f, 0.0f, 0.0f, 0.0f);
    func_800984F0(player, D_80117E9C);
    func_800984CC(player, D_80117E90);
    func_80098520(player, 1.0f);
}

void func_80098480(param_0, param_1, param_2) u8 *param_0;
int param_1;
int param_2;
{
    *(s8 *) (*(u8 **) (param_0 + 0xAC) + 0x28) = param_1;
    *(s8 *) (*(u8 **) (param_0 + 0xAC) + 0x2A) = param_2;
}

void func_80098494(u8 *player, f32 angle_0, f32 angle_1, f32 angle_2, f32 angle_3)
{
    (*(f32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0xAC)))) + (0))) = angle_0;
    (*(f32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0xAC)))) + (4))) = angle_1;
    (*(f32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0xAC)))) + (8))) = angle_2;
    (*(f32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0xAC)))) + (0xC))) = angle_3;
}

// Matching: the extra pointer temporaries are needed for the match.
void func_800984CC(player) Actor *player;
{
    s32 *state_addr;
    s32 *base;
    state_addr = (s32 *) ((base = (char *) player) + 43);
    base = state_addr;
    func_800EE7F8((*base) + 28);
}

// Matching: the extra pointer temporaries are needed for the match.
void func_800984F0(player) Actor *player;
{
    char *state_addr;
    s8 **state;
    char *base;
    base = (char *) player;
    state_addr = base + 0xAC;
    state = (s8 **) state_addr;
    (*state)[0x29] = 1;
    func_800EE7F8((*(state = &(*((s32 **) state_addr)))) + 0x10);
}

func_80098520(s32 player, f32 scale_factor)
{
    *(f32 *) (*(s32 *) (player + 172) + 44) = scale_factor;
}

// Climb target: pole or tree bottom, top, radius, type, cooldown and climb interrupt.
// Returns the size of the PlayerState+0xE0 block.
s32 func_80098530()
{
    return 0x34;
}

void func_80098538(u8 *player)
{
    func_800EFD24((*(u8 **) ((s8 *) (player) + (0xE0))), player);
    func_800EFD24((*(u8 **) ((s8 *) (player) + (0xE0))) + 0xC, player);
    (*(s8 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0xE0)))) + (0x2C))) = 0;
    (*(f32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0xE0)))) + (0x28))) = 0.0f;
    (*(s8 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0xE0)))) + (0x2F))) = 0;
}

s32 func_80098590(s32 player, s32 out)
{
    func_800EE7F8(out, *(s32 *) (player + 224));
}

// Returns the bottom y of the climb target.
f32 func_800985B8(void *player)
{
    return ((f32 *) (*(void **) ((char *) player + 0xE0)))[1];
}

// Searches the cube around the player for a climbable prop.
s32 func_800985C4(s32 player, s32 param_1)
{
    s32 prop;
    func_8009C128(player);
    prop = _gccubesearch_entrypoint_6(D_80117EB0, param_1);

if (prop == 0) {
    return 0;
}

_gspropctrl_entrypoint_11(prop, param_1);
return 1;
}

f32 func_80098610(struct Func80098610Arg *player)
{
    return *(f32 *) ((char *) (*(s32 **) ((char *) player + 0xE0)) + 0x30);
}

s32 func_8009861C(void *player)
{
    return ((u8 *) (*((void **) (((u8 *) player) + 0xE0))))[0x2E];
}

// Returns the radius of the climb target.
f32 func_80098628(void *player)
{
    return ((f32 *) (*(void **) ((char *) player + 0xE0)))[6];
}

s32 func_80098634(s32 player)
{
    return ((u8 *) (*(s32 **) (player + 0xE0)))[0x2F];
}

s32 func_80098640(s32 player)
{
    return ((u8 *) (*(u8 **) (player + 0xe0)))[0x2D];
}

// Returns the top y of the climb target.
f32 func_8009864C(void *player)
{
    return ((f32 *) (*(void **) ((char *) player + 0xE0)))[4];
}

// Offers a climb target, except the one just released while the cooldown runs.
void func_80098658(u8 *player, u8 *bottom, u8 *top, f32 radius, s32 param_4, s32 param_5)
{
    u8 *target;

    target = (*(u8 **) ((s8 *) (player) + (0xE0)));

if (!(*(f32 *) ((s8 *) target + 0x28) > 0.0f) ||
    (*(f32 *) ((s8 *) target + 0x1C) != *(f32 *) ((s8 *) bottom + 0)) ||
    (*(f32 *) ((s8 *) target + 0x20) != *(f32 *) ((s8 *) bottom + 4)) ||
    (*(f32 *) ((s8 *) target + 0x24) != *(f32 *) ((s8 *) bottom + 8))) {
    func_800EE7F8(target, bottom);
    func_800EE7F8(*(u8 **) ((s8 *) player + 0xE0) + 0xC, top);
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0xE0) + 0x18) = radius;
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0xE0) + 0x2D) = (s8) param_4;
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0xE0) + 0x2F) = (s8) param_5;
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0xE0) + 0x2C) = 1;
}

}

void func_80098730(s32 *player, s32 bottom, s32 top, f32 radius, s32 param_4, s32 param_5)
{
    func_80098658(player, bottom, top, radius, param_4, param_5);
    *(s8 *) (player[0x38] + 0x2E) = 1;
}

void func_80098778(void *player, s32 bottom, s32 top, f32 radius, s32 p4, s32 p5, f32 unk_30)
{
    func_80098658(player, bottom, top, radius, p4, p5);
    (*(u8 **) ((u8 *) player + 0xE0))[0x2E] = 2;
    *(f32 *) ((*(u8 **) ((u8 *) player + 0xE0)) + 0x30) = unk_30;
}

// Ticks the re-grab cooldown; interrupts into the climb state if a climb was offered and the ability is known.
void func_800987CC(void *param_0)
{
    QQ->cooldown = func_800F0E00(QQ->cooldown - func_800D8FF8(param_0), 0.0f);

if (QQ->offered != 0) {
    if (func_800C6E38(5) != 0) {
        func_8009E7C8(param_0, 0xC);
    }
}

QQ->offered = 0;
}

// Matching: the (f32) cast on the constant is needed for the match.
void func_80098840(u8 *player)
{
    u8 *target;

    (*(s8 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0xE0)))) + (0x2C))) = 0;
    target = (*(u8 **) ((s8 *) (player) + (0xE0)));
    func_800EE7F8(target + 0x1C, target, player);
    (*(f32 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0xE0)))) + (0x28))) = (f32) 0.6f;
}

// TU-NOTE: the .data of this file is defined here in C; values are from the ROM.
// D_80117EB0 is declared int[] above (uses written as NAME[0]).
u8 D_80117E90[12] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
u8 D_80117E9C[20] = {0x3F, 0x80, 0x0, 0x0, 0x3F, 0x80, 0x0, 0x0, 0x3F, 0x80,
                     0x0,  0x0,  0x0, 0x0, 0x0,  0x0,  0x0, 0x0, 0x0,  0x0};
int D_80117EB0[4] = {0x161, -0x1, 0x0, 0x0};
