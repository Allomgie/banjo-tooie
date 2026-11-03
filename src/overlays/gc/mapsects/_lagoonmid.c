#include "common.h"

typedef struct { f32 local_0[3]; f32 local_1[3]; f32 local_2[3]; s16 local_3; s16 local_4; s16 local_5; s16 pad_0; } LagoonSector1180;
extern LagoonSector1180 D_80800230_gcmapsects_lagoonmid[4];
extern s16 D_808002E0_gcmapsects_lagoonmid[3][2];
extern s16 D_808002EC_gcmapsects_lagoonmid[4];
extern s16 D_808002F4_gcmapsects_lagoonmid[];
extern void _gcmapsects_lagoonmid_entrypoint_1();
extern void _gcmapsects_entrypoint_0(s32, s32, f32 *, f32 *, void *, f32);
extern void func_800E39A8(f32 *, f32 *);
extern f32 func_80013728(f32);
extern f32 func_800136E4(f32);
extern s32 func_800E3E8C(void *, f32);

void gcmapsects_lagoonmid_entrypoint_0(void)
{
    u32 local_0;
    s16 (*local_1)[2];

    _gcmapsects_entrypoint_10(4);
    for (local_0 = 0; local_0 < 4; local_0++) {
        _gcmapsects_entrypoint_0(D_80800230_gcmapsects_lagoonmid[local_0].local_4,
            D_80800230_gcmapsects_lagoonmid[local_0].local_5,
            D_80800230_gcmapsects_lagoonmid[local_0].local_0,
            D_80800230_gcmapsects_lagoonmid[local_0].local_1,
            D_80800230_gcmapsects_lagoonmid[local_0].local_2,
            D_80800230_gcmapsects_lagoonmid[local_0].local_3);
    }
    local_1 = D_808002E0_gcmapsects_lagoonmid;
    local_0 = 0;
    do {
        _gcmapsects_entrypoint_3((*local_1)[0], (*local_1)[1]);
        local_1++;
    } while (++local_0 < 3);
    for (local_0 = 0; local_0 < 4; local_0++) {
        _gcmapsects_entrypoint_1(D_808002EC_gcmapsects_lagoonmid[local_0], 0);
        _gcmapsects_entrypoint_2(D_808002EC_gcmapsects_lagoonmid[local_0], 0);
    }
    _gcmapsects_entrypoint_12(_gcmapsects_lagoonmid_entrypoint_1);
    _gcmapsects_entrypoint_14(2);
}

void gcmapsects_lagoonmid_entrypoint_1(u8 *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    u8 local_2;
    func_800E39A8(local_0, local_1);
    local_1[0] = func_80013728(local_1[0]);
    local_1[1] = func_800136E4(local_1[1]);
    local_2 = param_0[0x7E];
    if (local_2 && ((local_0[1] < 8000.0f && local_1[0] < -20.0f) || (local_0[1] < 6000.0f && local_1[0] < 0.0f))) {
        local_2 = param_0[0x7E] = 0;
    }
    if (local_2 && local_0[1] < 4000.0f && local_1[0] >= 0.0f) param_0[0x7E] = func_800E3E8C(D_808002F4_gcmapsects_lagoonmid, 982.0f);
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/gc/mapsects/_lagoonmid.data.s) is defined here in C.
 * Values are taken from the ROM.
 * Labels inside an object are linker symbols in undefined_syms.us.txt: D_8080023C_gcmapsects_lagoonmid = D_80800230_gcmapsects_lagoonmid + 0xC, D_80800248_gcmapsects_lagoonmid = D_80800230_gcmapsects_lagoonmid + 0x18 */
LagoonSector1180 D_80800230_gcmapsects_lagoonmid[4] = { -4.4e+03f, -3.5e+03f, 8.2e+03f, -13567.0f, -5.91e+03f, 3.7e+03f, 2.2e+03f, -1e+02f, 14731.0f, 0x1D4C, 0x72A, 0x0, 0x0, 3.5e+03f, -5.6e+03f, 2.6e+03f, -397.0f, -7843.0f, -2428.0f, 6558.0f, -3053.0f, 7587.0f, 0x1D4C, 0x730, 0x0, 0x0, 3.5e+03f, -6e+03f, 1.02e+04f, 1806.0f, -6485.0f, 7554.0f, 4588.0f, -4579.0f, 12675.0f, 0x1D4C, 0x72D, 0x0, 0x0, -1.69e+04f, -8e+02f, 9.4e+03f, -19355.0f, -3666.0f, 7359.0f, -11455.0f, 1631.0f, 11719.0f, -0xA0, 0x733, 0x737, 0x0 };
s16 D_808002E0_gcmapsects_lagoonmid[3][2] = { 0x0, 0x2, 0x0, 0x3, 0x2, 0x1 };
s16 D_808002EC_gcmapsects_lagoonmid[4] = { 0x0, 0x3, 0x1, 0x2 };
s16 D_808002F4_gcmapsects_lagoonmid[2] = { -0x39F3, 0x5000 };
u32 D_808002F8_gcmapsects_lagoonmid[2] = { 0x45BAF000, 0xC54C9000 };
