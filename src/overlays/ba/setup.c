#include "common.h"
#include "playerstate.h"

extern void func_800EE7F8(void *, void *);
extern void func_800C6A7C(void *, void *, void *, int);
extern f32 func_8009E97C(void);
extern f32 func_8009E988(void);
extern void bastatetimer_set(PlayerState *, s32, f32);
extern f32 func_800F8A50(void);
extern void _plcamera_entrypoint_13(int *param_0, f32 param_1);
extern void yaw_setIdeal(int param_0, f32 param_1);
extern u8 D_8012762C;
extern void func_8009EB0C(f32);
extern int _gspropctrl_entrypoint_13(s32);
extern void _basetup_entrypoint_1(void);
extern s32 func_800F4A8C(s32, f32 *, f32);

s32 basetup_entrypoint_0()
{
    return 0x4;
}

// CCL map-specific fix, applied only when flag 0x327 is set.
int func_80800008_basetup(s32 state)
{
    s32 map;
    s32 entrance;
    map = func_800EA05C();
    entrance = func_800EA090();
    if (!func_800DB9B0()) {
        if (map == 0x13A && entrance == 0xE || map == 0x136 && entrance == 0x1B) {
            if (func_800DA298(0x327)) {
                func_800A0FF0(state);
            }
        }
    }
}

void func_80800080_basetup(s32 state)
{
    s32 shoe;
    s32 unk_0;
    shoe = _bashoes_entrypoint_1();
    unk_0 = func_800F40EC(state);
    if (unk_0) {
        switch (func_800A3274(state)) {
            case 1:
                switch (shoe) {
                    case 2:
                    case 3:
                    case 4:
                    case 5:
                        _bashoes_entrypoint_6(state, 1);
                }
                break;
            case 0xb:
                switch (shoe) {
                    case 3:
                    case 4:
                    case 5:
                        _bashoes_entrypoint_6(state, 2);
                }
        }
    }
}

void func_80800140_basetup(s32 pos)
{
    f32 unk_0[3];
    f32 probe_pos[3];
    func_800EE7F8(probe_pos, pos);
    *(f32 *) ((char *) pos + 4) -= 1000.0f;
    func_800C6A7C(probe_pos, pos, unk_0, 0x420025);
}

// TDL small T-rex height probe for both positions.
int func_80800194_basetup(s32 state, s32 pos_a, s32 pos_b)
{
    s32 bs_state;
    s32 map;
    s32 entrance;
    bs_state = func_800A3274(state);
    map = func_800EA05C();
    entrance = func_800EA090();
    if (!func_800DB9B0()) {
        if (map == 0x112 && entrance == 0xF || map == 0x116 && entrance == 2) {
            if (bs_state == 0x12) {
                func_80800140_basetup(pos_a);
                func_80800140_basetup(pos_b);
            }
        }
    }
}

void basetup_entrypoint_1(s32 unk_0, s32 unk_1)
{
    s32 state;
    s32 next_state;
    s32 flag;

    state = func_800F53D0(unk_1);
    next_state = _badata_entrypoint_35(state);
    flag = func_800EA068(8);
    switch (func_8009E958()) {
        case 1:
            if (flag && func_800C6E38(0x15))
                next_state = 0xC8;
            break;
        case 9:
            if (flag)
                next_state = 0xCB;
            else
                next_state = 0xC9;
    }
    func_800A3544(state, 0);
    bs_setState(state, next_state);
}

// Restore state timers and set the initial bs state.
void func_808002D4_basetup(PlayerState *state)
{
    bastatetimer_set(state, 2, func_8009E97C());
    bastatetimer_set(state, 3, func_8009E988());
    if (func_8009EA64()) {
        bs_setState(state, _badata_entrypoint_33(state));
    } else if (func_8009EA20()) {
        bs_setState(state, 0x11E);
    } else {
        func_80800008_basetup(state);
        bs_setState(state, _badata_entrypoint_35(state));
    }
    func_80800080_basetup(state);
}

void func_80800394_basetup(u8 *state)
{
    s32 unk_0;
    s32 unk_1;
    s32 state_id;
    s32 unk_2;
    s32 cur_state;
    s32 unk_3;
    unk_0 = func_800F8B88() == 3;
    unk_1 = func_8008DAA8(state);
    state_id = func_800A3274(state);
    cur_state = bs_getCurrentState(state);
    unk_2 = cur_state == 0;
    if (unk_1 != 0) {
        if (unk_2) {
            func_808002D4_basetup(state);
        }
    } else if (unk_2) {
        func_808002D4_basetup(state);
    }
    if (unk_1 == 0) {
        cur_state = func_800A3274(state);
        if (func_800F64A4(func_800F54E4(), 0x10000) != 0) {
            if (func_8008E23C(state) != 0 && cur_state == 0xA) {
                func_800F457C(state, 2);
            } else {
                bs_setState(state, _badrone_entrypoint_29(state));
            }
        } else {
            if (unk_0 != 0) {
                bs_setState(state, 0xED);
            } else {
                func_800F457C(state, 2);
            }
        }
        if (func_800F8DA8(cur_state) != 0) {
            func_800F8D50(*(s32 *) (state + 0x184), cur_state);
        }
    } else {
        unk_3 = 0;
        switch (state_id) {
            case 11:
                if (unk_0 != 0) {
                    unk_3 = 1;
                }
                break;
            case 14:
            case 17:
                unk_3 = 1;
        }
        if (unk_3 != 0) {
            func_800F8128(*(s32 *) (state + 0x184));
        }
    }
}

s32 func_80800534_basetup(int state_in)
{
    int buf;
    s32 pad0;
    int state;
    state = state_in;
    if (func_800DB9B0() != 0 || _glcutDll_entrypoint_1() != 0) {
        func_80800394_basetup(state);
        return 1;
    }
    if (func_8008DAA8(state) == 0) {
        func_80800394_basetup(state);
        if (func_800F99FC() == 0 && func_800F99E8() == 0 && func_800F8B7C() != 0 &&
            func_8008E23C(state) != 0) {
            _plcamera_entrypoint_13(*(int **) (state + 0x184), func_800F8A50());
        }
        return 1;
    }
    if (func_800F99FC() != 0) {
        if (func_800A3274(state) == 0xA) {
            func_808002D4_basetup(state);
        }
        return 1;
    }
    if (func_800F99E8() != 0) {
        func_80800394_basetup(state);
        return 1;
    }
    if (func_800F8B7C() != 0 && func_8008E23C(state) != 0) {
        func_800F89E4(func_800A3274(state), (int *) ((s8 *) &buf - 8));
        func_800F452C(state, (int *) ((s8 *) &buf - 8));
        yaw_setIdeal(state, func_800F8A50());
        yaw_applyIdeal(state);
        _plcamera_entrypoint_13(*(int **) (state + 0x184), func_800F8A50());
        func_80800394_basetup(state);
        return 1;
    }
    if (func_8009EA64() != 0) {
        func_80800394_basetup(state);
        return 1;
    }
    return 0;
}

// Cube search for the entrance marker.
int func_808006F0_basetup()
{
    s32 marker;
    marker = _gemarkersDll_entrypoint_1();
    _gccubesearch_entrypoint_14(marker | 0, 0);
}

// Cube search for entrance prop 0x52 + index.
int func_8080071C_basetup(s32 index)
{
    s32 prop_id;
    prop_id = 0x52;
    if (func_800A9C98(index) != 0) {
        return 0;
    }
    if ((index > 0) && (index < 0x29)) {
        prop_id += index;
    }
    return _gccubesearch_entrypoint_14(prop_id | 0, 0);
}

// Choose the transformation for this map; forced forms on multiplayer maps.
s32 func_80800778_basetup(PlayerState *state)
{
    s32 form;

    form = func_8009E958();
    switch (form) {
        case 9:
            if (func_800EA05C() == 0x116) {
                form = 1;
                func_8009EB18(0);
            }
            break;
        case 1:
            if (func_800EA068(8) && func_800C6E38(0x15))
                form = 9;
    }
    if (func_800EA068(0x40)) {
        switch (func_800EA05C()) {
            case 0x182:
                form = 12;
                break;
            case 0x188:
                form = 6;
                break;
            default:
                form = 9;
                break;
        }
        func_8009E9D8(form);
    }
    return form;
}

// Player spawn on map entry.
void basetup_entrypoint_2(PlayerState *state)
{
    s32 marker;
    s32 entrance_prop;
    s32 entrance;
    f32 pos[3];
    f32 yaw;
    f32 spawn_rot[3];
    s32 form;
    s32 unk_0;
    Vec3f prop_pos;
    f32 unk_1;

    if (func_800A3274() == 4 || _gclevel_entrypoint_4(1)) {
        func_800F44DC(state, 0);
        return;
    }
    if (!func_80800534_basetup(state)) {
        entrance = func_800EA090();
        marker = func_808006F0_basetup(entrance);
        if (marker) {
            entrance_prop = func_8080071C_basetup(entrance);
        } else {
            if (_sudeathmatch_entrypoint_0(*(s32 *) ((u8 *) state + 0x184), pos, spawn_rot)) {
                yaw = spawn_rot[1];
            } else if (!marker) {
                func_800F44DC(state, 0);
                return;
            }
            entrance_prop = 0;
        }
        form = func_80800778_basetup(state);
        if (form == 9) {
            _bashoes_entrypoint_6(state, 1);
            func_8009EB0C(0.0f);
            if (entrance_prop && !func_8009E994()) {
                form = func_8009E958();
            } else {
                func_800A3544(state, D_8012762C == 0x1B ? 1 : 0);
            }
        }
        func_800A3410(state, form);
        func_80092778(state);
        func_800F44DC(state, 0);
        if (marker) {
            _gspropctrl_entrypoint_11(marker, pos);
            yaw = _gspropctrl_entrypoint_12(marker);
        }
        func_800F44DC(state, 1);
        **(s32 **) ((u8 *) state + 0x100) = -1;
        if (func_8009EA4C() == 2) {
            if (func_800EA068(8) && func_800C6E38(0x15)) {
                func_8009EAD0(1);
            } else {
                yaw += 180.0f;
            }
        }
        yaw_setIdeal(state, yaw);
        yaw_applyIdeal(state);
        if (entrance_prop) {
            unk_1 = 1.0f;
            if (func_800EA068(4)) {
                unk_0 = _gspropctrl_entrypoint_13(entrance_prop);
                unk_1 = unk_0 * 0.1f;
            }
            _gspropctrl_entrypoint_11(entrance_prop, prop_pos.f);
            func_80800194_basetup(state, prop_pos.f, pos);
            func_800F452C(state, prop_pos.f);
            func_808002D4_basetup(state);
            func_800F497C(*(s32 *) ((u8 *) state + 0x184));
            func_800F49D4(*(s32 *) ((u8 *) state + 0x184), _basetup_entrypoint_1,
                          *(s32 *) ((u8 *) state + 0x184));
            func_800F4A8C(*(s32 *) ((u8 *) state + 0x184), pos, unk_1);
        } else {
            func_800F452C(state, pos);
            func_808002D4_basetup(state);
        }
    }
}

void basetup_entrypoint_3(s32 arg0)
{
}

void basetup_entrypoint_4(s32 arg0)
{
}
