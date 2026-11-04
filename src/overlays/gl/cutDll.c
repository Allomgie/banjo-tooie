// Cutscene director: a 6-state machine that warps to the cutscene map, puts players under cutscene
// control and warps back. Many actor overlays start cutscenes and query whether one is running.
#include "gl/cutDll.h"
#include "common.h"

// Global cutscene record. state: 1 idle, 2 start, 3 playing, 4 end in place,
// 5 return to previous map, 6 cleanup.
typedef struct {
    s16 cutscene_map;
    s16 return_map;
    s16 cutscene_id;
    u8 unk_6;
    u8 unk_7;
    u8 state;
    u8 unk_9;
    u8 theme_music;
    u8 unk_B;
    u8 unk_C;
    u8 unk_D;
    u8 unk_E;
    u8 zone_music_suspended;
    u8 unk_10;
} CutsceneInformation;

extern CutsceneInformation D_801275E8;
extern u8 D_8012762C;
void glcutDll_entrypoint_16(void);
void glcutDll_entrypoint_11(u32 arg0);
void glcutDll_entrypoint_10(u32 arg0);
void glcutDll_entrypoint_7(u32 arg0);

void func_80800000_glcutDll(u32 value)
{
    D_801275E8.unk_6 = value;
}

void func_8080000C_glcutDll(u32 value)
{
    D_801275E8.unk_9 = value;
}

// Cutscene state machine; see CutsceneInformation for the states.
void func_80800018_glcutDll(u32 new_state)
{
    switch (new_state) {
        case 1:
            func_8080000C_glcutDll(0U);
            func_80800000_glcutDll(0U);
            D_801275E8.unk_C = 0;
            func_800FE734(0);
            break;
        case 2:
            if ((D_801275E8.cutscene_map != D_801275E8.return_map) || (func_800DA298(FLAG3_A52_UNK) != 0)) {
                if (D_801275E8.theme_music != 0) {
                    func_800FE844(2);
                    func_800FE734(1);
                }
                if (_gcsectionDll_entrypoint_4(D_801275E8.cutscene_map) != D_8012762C) {
                    func_800A8230();
                }
                func_800A7990(D_801275E8.cutscene_map, 0, D_801275E8.unk_10);
            }
            func_800DA544(FLAG2_641_CUTSCENE_STORAGE_ACTIVE);
            if ((D_801275E8.unk_B == 0) && (D_801275E8.zone_music_suspended == 0)) {
                func_800C78CC(1);
                D_801275E8.zone_music_suspended = 1U;
            }
            D_801275E8.unk_C = 1;
            break;
        case 3:
            if ((D_801275E8.state == 2) &&
                ((D_801275E8.cutscene_map != D_801275E8.return_map) || (func_800DA298(FLAG3_A52_UNK) != 0)) &&
                (D_801275E8.unk_7 != 0)) {
                func_80800000_glcutDll(1U);
                func_8080000C_glcutDll(0U);
                func_800D9290();
                func_800D9330(1);
            }
            break;
        case 4:
            if (D_801275E8.unk_6 != 0) {
                func_800D92F4();
            }
            func_800DA524(FLAG2_641_CUTSCENE_STORAGE_ACTIVE);
            if ((D_801275E8.unk_B == 0) && (D_801275E8.zone_music_suspended != 0)) {
                func_800C78CC(0);
                D_801275E8.zone_music_suspended = 0U;
            }
            if (D_801275E8.unk_E != 0) {
                func_80090708(0);
            }
            func_8080000C_glcutDll(0U);
            D_801275E8.cutscene_id = 0;
            func_800DA524(FLAG3_A52_UNK);
            break;
        case 5:
            if (D_801275E8.theme_music != 0) {
                func_800FE844(2);
                func_800FE734(1);
            }
            if (_gcsectionDll_entrypoint_4(D_801275E8.return_map) != D_8012762C) {
                func_800A8230();
            }
            func_800A7990(D_801275E8.return_map, 0, D_801275E8.unk_10);
            func_800DA524(FLAG2_641_CUTSCENE_STORAGE_ACTIVE);
            if ((D_801275E8.unk_B == 0) && (D_801275E8.zone_music_suspended != 0)) {
                func_800C78CC(0);
                D_801275E8.zone_music_suspended = 0U;
            }
            if (D_801275E8.unk_6 != 0) {
                func_8080000C_glcutDll(1U);
            }
            D_801275E8.cutscene_id = 0;
            D_801275E8.unk_D = 1;
            func_800DA524(FLAG3_A52_UNK);
            break;
        case 6:
            if (D_801275E8.unk_9 != 0) {
                func_800D92F4();
                func_80800000_glcutDll(0U);
                func_8080000C_glcutDll(0U);
                func_800FE734(0);
            }
            if (D_801275E8.unk_C != 0) {
                D_801275E8.unk_C = 0U;
            }
            if (D_801275E8.unk_D != 0) {
                D_801275E8.unk_D = 0U;
            }
    }
    D_801275E8.state = (s8) new_state;
}

void glcutDll_entrypoint_0(void)
{
    func_80800018_glcutDll(1U);
    glcutDll_entrypoint_10(func_800EA05C());
    glcutDll_entrypoint_11(1U);
    func_80800000_glcutDll(0U);
    D_801275E8.theme_music = 1;
    D_801275E8.unk_B = 0;
    D_801275E8.zone_music_suspended = 0;
    D_801275E8.unk_10 = 0;
    D_801275E8.cutscene_id = 0;
    D_801275E8.unk_E = 0;
}

u8 glcutDll_entrypoint_1(void)
{
    return D_801275E8.unk_9;
}

void glcutDll_entrypoint_2(void)
{
}

void glcutDll_entrypoint_3(void)
{
    func_800D92EC();
    func_8080000C_glcutDll(0U);
    func_80800000_glcutDll(0U);
    D_801275E8.theme_music = 1;
    D_801275E8.unk_B = 0;
    D_801275E8.zone_music_suspended = 0;
    D_801275E8.unk_10 = 0;
    D_801275E8.unk_C = 0;
    D_801275E8.unk_D = 0;
    D_801275E8.cutscene_id = 0;
    D_801275E8.unk_E = 0;
    D_801275E8.state = 0;
    func_80800018_glcutDll(1U);
}

void glcutDll_entrypoint_4(void)
{
    if (D_801275E8.state != 1) {
        func_80800018_glcutDll(6);
    }
}

void glcutDll_entrypoint_5(void)
{
    if (D_801275E8.state != 1) {
        func_80800018_glcutDll(3);
    }
}

// Starts a cutscene with the given cutscene map and cutscene id.
void glcutDll_entrypoint_6(u32 cutscene_map, u32 cutscene_id)
{
    glcutDll_entrypoint_0();
    glcutDll_entrypoint_7(cutscene_map);
    glcutDll_entrypoint_22(cutscene_id);
    glcutDll_entrypoint_16();
}

// Set the cutscene map.
void glcutDll_entrypoint_7(u32 map)
{
    D_801275E8.cutscene_map = map;
}

// Return the cutscene map.
s16 glcutDll_entrypoint_8(void)
{
    return D_801275E8.cutscene_map;
}

// Get the map to return to after the cutscene ends.
s16 glcutDll_entrypoint_9(void)
{
    return D_801275E8.return_map;
}

// Set the cutscene return map.
void glcutDll_entrypoint_10(u32 map)
{
    D_801275E8.return_map = map;
}

void glcutDll_entrypoint_11(u32 value)
{
    D_801275E8.unk_7 = value;
}

void glcutDll_entrypoint_12(s32 disable)
{
    if (disable != 0) {
        D_801275E8.theme_music = 0;
        return;
    }
    D_801275E8.theme_music = 1;
}

void glcutDll_entrypoint_13(s32 value)
{
    if (value != 0) {
        D_801275E8.unk_B = 0;
        return;
    }
    D_801275E8.unk_B = 1;
}

void glcutDll_entrypoint_14(u32 value)
{
    D_801275E8.unk_10 = value;
}

void glcutDll_entrypoint_15(u32 value)
{
    D_801275E8.unk_E = value;
}

void glcutDll_entrypoint_16(void)
{
    func_80800018_glcutDll(2);
}

void glcutDll_entrypoint_17(void)
{
    if (func_800EA05C() == D_801275E8.return_map) {
        func_80800018_glcutDll(4U);
        func_80800018_glcutDll(1U);
        return;
    }
    func_80800018_glcutDll(5U);
}

s16 glcutDll_entrypoint_18(void)
{
    return D_801275E8.cutscene_id;
}

// Is cutscene cutscene_id running?
u32 glcutDll_entrypoint_19(s32 cutscene_id)
{
    u32 is_current;

    is_current = cutscene_id == D_801275E8.cutscene_id;
    if (is_current) {
        return func_800DB9B0() != 0;
    }
}

// Is cutscene 0x8A or 0x8C running?
s32 glcutDll_entrypoint_20(void)
{
    s16 cutscene_id;

    if (func_800DB9B0() == 0) {
        return 0;
    }
    cutscene_id = D_801275E8.cutscene_id;
    if (cutscene_id == 0x8C) {
        return 1;
    }
    if (cutscene_id == 0x8A) {
        return 1;
    }
    return 0;
}

void glcutDll_entrypoint_21(void)
{
    func_800DA544(FLAG3_A52_UNK);
}

void glcutDll_entrypoint_22(u32 cutscene_id)
{
    D_801275E8.cutscene_id = cutscene_id;
}

s32 glcutDll_entrypoint_23(void)
{
    if ((D_801275E8.cutscene_map != D_801275E8.return_map) && (func_800EA05C() == D_801275E8.cutscene_map)) {
        return 1;
    }
    return 0;
}

// Starts a cutscene keeping the current music settings; -1 keeps the current
// return map / cutscene id.
void glcutDll_entrypoint_24(u32 cutscene_map, u32 return_map, u32 cutscene_id)
{
    u32 saved_return_map;
    u32 saved_cutscene_id;
    s32 saved_theme_music;
    s32 saved_unk_b;
    s32 saved_unk_10;
    s32 saved_zone_music_suspended;

    saved_return_map = (u32) D_801275E8.return_map;
    saved_cutscene_id = (u32) D_801275E8.cutscene_id;
    saved_theme_music = (s32) D_801275E8.theme_music;
    saved_unk_b = (s32) D_801275E8.unk_B;
    saved_unk_10 = (s32) D_801275E8.unk_10;
    saved_zone_music_suspended = (s32) D_801275E8.zone_music_suspended;
    glcutDll_entrypoint_0();
    glcutDll_entrypoint_11(0U);
    D_801275E8.theme_music = (u8) saved_theme_music;
    D_801275E8.unk_B = (u8) saved_unk_b;
    D_801275E8.unk_10 = (u8) saved_unk_10;
    D_801275E8.zone_music_suspended = (u8) saved_zone_music_suspended;
    if (cutscene_id == -1U) {
        glcutDll_entrypoint_22(saved_cutscene_id);
    } else {
        glcutDll_entrypoint_22(cutscene_id);
    }
    glcutDll_entrypoint_7(cutscene_map);
    if (return_map == -1U) {
        glcutDll_entrypoint_10(saved_return_map);
    } else {
        glcutDll_entrypoint_10(return_map);
    }
    glcutDll_entrypoint_16();
    func_80800000_glcutDll(1U);
}
