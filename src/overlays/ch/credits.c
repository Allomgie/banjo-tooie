// End-credits and character-parade director: steps through a table of shots, warps between maps,
// fades name/role text in and out, draws a rotating logo and allows skipping.
#include "common.h"

extern u8 D_80127611;
extern s16 D_808012C0_chcredits[][4];
extern s16 D_80801208_chcredits[][4];
extern s16 D_808012BA_chcredits[][4];
extern s16 D_80801202_chcredits[][4];
extern u8 D_80127610[];
// TU-NOTE: D_80127610 holds {shot index, mode, start arg}; mode 2 selects the parade tables.
typedef struct {
    u8 shot;
    u8 mode;
    u8 start_arg;
} CreditsState_808000E8_chcredits;
extern void func_808000C8_chcredits(void);
extern void _gcfrontend_entrypoint_9(s32);
extern u8 D_8012760D[];
extern void _capod_entrypoint_14(void);
typedef struct {
    u8 shot;
    u8 mode;
    u8 start_arg;
} CreditsState_80800464_chcredits;
typedef struct {
    s8 unk_0;
    s8 unk_1;
    s8 unk_2;
    s8 pad_3[5];
} CreditsLines;
extern CreditsLines D_808012BC_chcredits[];
extern CreditsLines D_80801204_chcredits[];
extern void *func_80100094(Actor *, s32);
extern void *_gldbstring_entrypoint_0(s32, s32);
extern char *_gldbstring_entrypoint_1(void *, s16);
extern void _gldbstring_entrypoint_2(s32);
extern void func_800E715C(char *, char *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern f32 D_80801578_chcredits[][3];
extern f32 D_80801560_chcredits[][3];
extern f32 D_8080155C_chcredits;
extern f32 D_80801548_chcredits[3];
extern f32 D_80801554_chcredits[3];
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800E3C8C(f32, f32);
extern void func_800E7CF4(void *);
extern void func_800DE498(void *, f32 *, f32 *, f32, s32, void *);
extern u8 *func_800B8C50(void);
extern void func_800B7F14(void *);
extern void func_800B8CB0(s32);
extern s32 func_800E7188();
extern void func_800B811C(void *);
extern u8 D_80801590_chcredits[];
extern void *D_8080159C_chcredits[];
typedef struct {
    u8 pad_0[0x72];
    u16 st : 6;
    u16 rest : 10;
} CreditsState_80800800_chcredits;
extern f32 func_800D8FF8(void);
extern void func_80015ECC(s32, s32 *);
extern s32 func_800DA9E4(s32, s32);
extern void func_800B8CF0(f32);

void func_80800710_chcredits();

void func_808003E8_chcredits();
s16 func_80800000_chcredits(shot)
s32 shot;
{

if (D_80127611 == 2) {
    return D_808012C0_chcredits[shot][0];
}

return D_80801208_chcredits[shot][0];

}

s16 func_8080003C_chcredits(s32 shot)
{
    if (D_80127611 == 2) {
        return D_808012BA_chcredits[shot][0];
    }

return D_80801202_chcredits[shot][0];

}

// True when the last shot is done.
s32 func_80800078_chcredits(void)
{
    if (D_80127610[1] == 2) {
        return D_80127610[0] >= 0x51U;
    }

return D_80127610[0] >= 0x16U;
}

int func_808000B4_chcredits(s32 mode)
{
    s8 *state = ((int *) D_80127610);
    state[1] = mode;
    state[0] = 0;
}

void func_808000C8_chcredits()
{
    _glcutDll_entrypoint_17();

}

void func_808000E8_chcredits(void)
{
    switch ((*(CreditsState_808000E8_chcredits *) D_80127610).start_arg) {
        case 0:
            switch ((*(CreditsState_808000E8_chcredits *) D_80127610).mode) {
                case 0:
                    func_808000B4_chcredits(1);
                    break;
                case 1:
                    func_808000C8_chcredits();
            }
            break;
        case 1:
            _gcfrontend_entrypoint_9(0x85);
            switch ((*(CreditsState_808000E8_chcredits *) D_80127610).mode) {
                case 0:
                    func_808000B4_chcredits(2);
                    break;
                case 2:
                    func_808000C8_chcredits();
            }
            break;
        case 2:
            switch ((*(CreditsState_808000E8_chcredits *) D_80127610).mode) {
                case 0:
                    func_808000B4_chcredits(1);
                    break;
                case 1:
                    func_808000B4_chcredits(2);
                    break;
                case 2:
                    func_808000C8_chcredits();
            }
    }

}

void chcredits_entrypoint_0(u32 start_arg)
{
    u8 *state;

    state = D_80127610;
    state[1] = 0;
    state[2] = start_arg;
    func_808000E8_chcredits();
    func_800DA544(0x650);
    _glcutDll_entrypoint_0();
    _glcutDll_entrypoint_7(func_80800000_chcredits(-1));
    _glcutDll_entrypoint_22(0x8C);
    _glcutDll_entrypoint_16();

}

s32 chcredits_entrypoint_1(void)
{
    if (*(u8 *) ((char *) &D_80127610 + 0 + 1) == 2) {
        return func_8080003C_chcredits(*(u8 *) ((char *) &D_80127610 + 0));
    }

return -1;

}

void func_808002A4_chcredits(s32 actor)
{
    if (D_8012760D[3] == 0) {
        func_80800710_chcredits(actor, 2);
    } else {

func_80800710_chcredits(actor, 3);
}
func_808003E8_chcredits(actor, func_8080003C_chcredits(D_8012760D[3]));
}

void func_80800300_chcredits(Actor *actor)
{
    s32 map_id;
    u8 *state;
    if (func_80800078_chcredits())
        func_808000E8_chcredits();
    else {
        map_id = func_80800000_chcredits((*((u8 *) D_80127610)));
        state = ((u8 *) D_80127610);
        (*state)++;
        if (func_800EA05C() != map_id)
            _glcutDll_entrypoint_24(map_id, -1, -1);

else
{
    _capod_entrypoint_14();
    func_808002A4_chcredits(actor);
}
}
}

void func_8080038C_chcredits(void)
{
    s32 map_id;

    map_id = func_800EA05C();
    if (map_id == 0x19C || map_id == 0x19D) {
        if (func_800D395C()) {
            _gcfrontend_entrypoint_10();
        } else {

_gcgoto_entrypoint_1(0x194, 0);
}
}
}

void func_808003E8_chcredits(owner, node) s32 *owner;
s32 node;
{
    s32 node_kind;

    node_kind = func_800A5854(node);
    if (node_kind != 2) {
        if ((node_kind == 5) || (node_kind == 6) || (node_kind == 8)) {
            _capod_entrypoint_13(*owner, 0, node, 0x834);
        }
    } else {
        _capod_entrypoint_21(*owner, 0, node, 0x814);
    }
}

// Loads the name/role strings of the current shot into the actor buffer.
void func_80800464_chcredits(Actor *this)
{
    char *buf;
    s32 pad;
    s32 id;
    void *db;
    char *s;
    s32 i;

    buf = func_80100094(this, 0);
    if ((*((CreditsState_80800464_chcredits *) D_80127610)).mode == 2) {
        if (D_808012BC_chcredits[(*((CreditsState_80800464_chcredits *) D_80127610)).shot].unk_0 >=
            0) {
            id = D_808012BC_chcredits[(*((CreditsState_80800464_chcredits *) D_80127610)).shot]
                     .unk_0 +
                 0x1B86;
            db = _gldbstring_entrypoint_0(0, id);
            for (i = 0; i != 2; i++) {
                s = _gldbstring_entrypoint_1(db, i);

if (s) {
    func_800E715C(buf + i * 0x80, s);
} else {

func_800E715C(buf + i * 0x80, "");
}
}
_gldbstring_entrypoint_2(id);
}
else
{
    for (i = 0; i != 2; i++) {
        func_800E715C(buf + i * 0x80, "");
    }
}
id = D_808012BC_chcredits[(*((CreditsState_80800464_chcredits *) D_80127610)).shot].unk_1 + 0x1B88;
db = _gldbstring_entrypoint_0(0, id);
func_800E715C(
    buf + 0x100,
    _gldbstring_entrypoint_1(
        db, D_808012BC_chcredits[(*((CreditsState_80800464_chcredits *) D_80127610)).shot].unk_2));
_gldbstring_entrypoint_2(id);
}
else
{
    if (D_80801204_chcredits[(*((CreditsState_80800464_chcredits *) D_80127610)).shot].unk_0 >= 0) {
        id = D_80801204_chcredits[(*((CreditsState_80800464_chcredits *) D_80127610)).shot].unk_0 +
             0x1B68;
        db = _gldbstring_entrypoint_0(0, id);
        for (i = 0; i != 2; i++) {
            s = _gldbstring_entrypoint_1(db, i);
            if (s) {
                func_800E715C(buf + i * 0x80, s);
            } else {
                func_800E715C(buf + i * 0x80, "");
            }
        }
        _gldbstring_entrypoint_2(id);
    } else {
        for (i = 0; i != 2; i++) {
            func_800E715C(buf + i * 0x80, "");
        }
    }
    id = (*((CreditsState_80800464_chcredits *) D_80127610)).shot + 0x1B6F;
    db = _gldbstring_entrypoint_0(0, id);
    for (i = 0; i != 3; i++) {
        s = _gldbstring_entrypoint_1(db, i);
        if (s) {
            func_800E715C(buf + 0x100 + i * 0x80, s);
        } else {
            func_800E715C(buf + 0x100 + i * 0x80, "");
        }
    }
    _gldbstring_entrypoint_2(id);
}
}

void func_80800710_chcredits(actor, phase) Actor *actor;
s32 phase;
{
    func_80102424(actor, phase);
    switch (actor->unk70_10) {
        case 2:
            actor->unk64_19 = 1;
            *(f32 *) ((u8 *) actor + 0x34) = 1.0f;
            break;
        case 3:
            func_80800464_chcredits(actor);
            actor->unk58 = 0.75f;
            break;
        case 4:
            actor->unk64_19 = 0;
            if (func_800EA05C() == 0x116) {
                actor->unk58 = 10.0f;
            } else {
                actor->unk58 = 7.0f;
            }
            break;
        case 5:
            actor->unk58 = 0.75f;
            break;
        case 8:
            func_8080038C_chcredits();
            break;
        case 6:
            *(f32 *) ((u8 *) actor + 0x34) = 1.0f;
    }
}

void func_80800800_chcredits(Actor *actor)
{
    f32 dt;
    s32 input[6];

    dt = func_800D8FF8();
    if (((CreditsState_80800800_chcredits *) actor)->st >= 3 &&
        ((CreditsState_80800800_chcredits *) actor)->st < 6) {
        func_80015ECC(0, input);
        if (input[1] == 1) {
            func_808000C8_chcredits();
        }
    }
    switch (((CreditsState_80800800_chcredits *) actor)->st) {
        case 2:
            if (*(f32 *) &actor->actorData[7] <= 0) {
                func_80800710_chcredits(actor, 3);
                return;
            }
            *(f32 *) &actor->actorData[7] = *(f32 *) &actor->actorData[7] - dt;
            break;
        case 3:
            if (actor->unk58 <= 0) {
                func_80800710_chcredits(actor, 4);
                actor->unk6C_0 = 0xFF;
                break;
            }
            actor->unk58 = actor->unk58 - dt;
            actor->unk6C_0 = (u32) func_800F10B4(actor->unk58, 0.75f, 0.0f, 0.0f, 255.0f);
            break;
        case 4:
            if (actor->unk58 <= 0) {
                func_80800710_chcredits(actor, 5);
                return;
            }
            actor->unk58 = actor->unk58 - dt;
            break;
        case 5:
            if (actor->unk58 <= 0) {
                func_80800300_chcredits(actor);
                actor->unk6C_0 = 0;
                break;
            }
            actor->unk58 = actor->unk58 - dt;
            actor->unk6C_0 = (u32) func_800F10B4(actor->unk58, 0.75f, 0.0f, 255.0f, 0.0f);
            break;
        case 7:
            if (func_800C954C()) {
                return;
            }
            switch (func_800EA05C()) {
                case 0x19C:
                    if (func_800DA9E4(0x650, 0)) {
                        func_8080038C_chcredits();
                    } else {
                        chcredits_entrypoint_0(0);
                    }
                    return;
                case 0x19D:
                    if (func_800DA9E4(0x650, 0)) {
                        func_8080038C_chcredits();
                    } else {
                        chcredits_entrypoint_0(1);
                    }
            }
            return;
        case 6:
            if (*(f32 *) &actor->actorData[7] <= 0) {
                func_80800710_chcredits(actor, 8);
                return;
            }
            *(f32 *) &actor->actorData[7] = *(f32 *) &actor->actorData[7] - dt;
        case 8:
            break;
    }
}

void func_80800BCC_chcredits(s32 arg0)
{
}

void func_80800BD4_chcredits(actor) Actor *actor;
{
    s32 map_id;

    ((u8 *) actor)[0x7A] &= ~0xC0;
    func_800EFA4C(actor->position, 0.0f, 0.0f, 0.0f);
    map_id = func_800EA05C();
    if (map_id == 0x19C || map_id == 0x19D) {
        if (func_800DA9E4(0x650, 0))
            func_80800710_chcredits(actor, 6);
        else
            func_80800710_chcredits(actor, 7);
        func_808003E8_chcredits(actor, 0);
        return;
    }
    func_808002A4_chcredits(actor);
}

// Draws the rotating logo model.
void func_80800C84_chcredits(Actor *actor, void *dl)
{
    f32 logo_scale;
    s32 setting;
    logo_scale = 0.0f;
    setting = _glglobalsettings_entrypoint_3();
    func_800E41CC();
    func_800E3C8C(50.0f, 2000.0f);
    func_800E39D8(D_80801578_chcredits[setting], D_80801560_chcredits[setting]);
    func_800E3CE8();
    func_800E44FC(dl);
    func_800E7C28(dl);
    func_800E7CF4(dl);
    switch (actor->unk70_10) {
        case 2:
            logo_scale = func_800F10B4(((f32 *) actor->actorData)[7], 1.0f, 0.0f, 1.0f, 0.0f);
            D_8080155C_chcredits = logo_scale * 360.0f;
            break;
        case 6:
            logo_scale = func_800F10B4(((f32 *) actor->actorData)[7], 1.0f, 0.0f, 0.0f, 1.0f);
            D_8080155C_chcredits = logo_scale * 360.0f;
            break;
        case 7:
        case 8:
            logo_scale = 1.0f;
            break;
    }
    if (logo_scale > 0.0f) {
        func_800DF830(1);
        func_800DE498(dl, D_80801548_chcredits, D_80801554_chcredits, logo_scale, 0,
                      (void *) func_800D674C(0x9A1));
    }
    func_80101870(actor, dl);
    func_800E4208();
    func_800E44FC(dl);
}

// Draws centred text with a drop shadow.
void func_80800E4C_chcredits(text, y, dl, alpha) void *text;
s32 y;
void *dl;
s32 alpha;
{
    f32 scale;
    s32 x;
    s32 shadow_y;
    f32 two = 2.0f;

    scale = _glglobalsettings_entrypoint_3() ? 0.95f : 1.0f;
    x = (304.0f - func_800B8CFC(text) * scale) / two;
    func_800B8C8C(alpha);
    func_800B8CBC(0, 0, 0);
    func_800B8CF0(scale);
    func_800B80D0(dl);
    shadow_y = y + 1;
    func_800B8E28(dl, x + 1, shadow_y, text);
    func_800B8CBC(255, 255, 255);
    func_800B8CF0(scale);
    func_800B80D0(dl);
    func_800B8E28(dl, x, shadow_y, text);
}

// Draws the name and role lines with fade alpha.
void func_80800F50_chcredits(u8 *actor, u8 *dl)
{
    u8 *lines;
    s32 name_y;
    s32 role_y;
    s32 k;

    lines = func_80100094(actor, 0);
    func_800B8C50();
    func_800B7F14(dl);
    func_800B8CB0(1);
    if (D_8012760D[4] == 2) {
        name_y = 0xA0;
        role_y = 0xAF;
        if (func_800E7188(lines + 0x80)) {
            name_y = 0x91;
        }
    } else {
        name_y = 0x55;
        role_y = 0x78;
    }
    if (func_800E7188(lines)) {
        if (func_800E7188((lines + 0x80))) {
            func_80800E4C_chcredits(lines, (s32) ((f32) name_y - 7.5f), dl,
                                    *(s32 *) (actor + 0x6C) & 0x1FF);
            func_80800E4C_chcredits((lines + 0x80), (s32) ((f32) name_y + 7.5f), dl,
                                    *(s32 *) (actor + 0x6C) & 0x1FF);
        } else {
            func_80800E4C_chcredits(lines, name_y, dl, *(s32 *) (actor + 0x6C) & 0x1FF);
        }
    }
    for (k = 0; k != 3; k++) {
        if (func_800E7188(lines + 0x100 + k * 0x80)) {
            func_80800E4C_chcredits(lines + 0x100 + k * 0x80, k * 15 + role_y, dl,
                                    *(s32 *) (actor + 0x6C) & 0x1FF);
        }
    }
    func_800B811C(dl);
}

void func_80801108_chcredits(actor, dl) Actor *actor;
s32 dl;
{
    s32 alpha;
    if (!actor->unk64_19) {
        alpha = 0xFF - actor->unk6C_0;
        if (alpha >= 0xF6)
            alpha = 0xFF;
        else if (alpha < 10)
            alpha = 0;
        func_800B99CC(dl, alpha, D_80801590_chcredits);
    }
    func_80800F50_chcredits(actor, dl);
    func_80800C84_chcredits(actor, dl);
}

int *chcredits_entrypoint_2()
{
    return (int *) D_8080159C_chcredits;
}

extern void func_80105834(), func_80107C2C(), func_80800BCC_chcredits(), func_80800BD4_chcredits(),
    func_80801108_chcredits();

u32 D_80801200_chcredits[1] = {0xAF001F};
CreditsLines D_80801204_chcredits[23] = {
    0x5, 0x0, 0x0, 0x0, 0x1, 0x42,  0x0, 0x55, 0x0, 0x0, 0x0, 0x0, 0x1, 0x4F,  0x0, 0x18,
    0x0, 0x0, 0x0, 0x0, 0x1, 0x55,  0x0, 0x2A, 0x0, 0x0, 0x0, 0x0, 0x1, 0x5A,  0x0, 0x12,
    0x0, 0x0, 0x0, 0x0, 0x1, 0x5C,  0x0, 0x17, 0x0, 0x0, 0x0, 0x0, 0x0, -0x48, 0x0, 0x29,
    0x1, 0x0, 0x0, 0x0, 0x0, -0x39, 0x0, 0xC,  0x1, 0x0, 0x0, 0x0, 0x0, -0x2A, 0x0, 0x4A,
    0x1, 0x0, 0x0, 0x0, 0x1, -0x59, 0x0, 0x41, 0x1, 0x0, 0x0, 0x0, 0x1, 0x12,  0x0, 0x5A,
    0x1, 0x0, 0x0, 0x0, 0x1, 0x0,   0x0, 0x1A, 0x2, 0x0, 0x0, 0x0, 0x1, 0x27,  0x0, 0x2E,
    0x2, 0x0, 0x0, 0x0, 0x1, 0x36,  0x0, 0x63, 0x2, 0x0, 0x0, 0x0, 0x0, -0x48, 0x0, 0x2A,
    0x3, 0x0, 0x0, 0x0, 0x0, -0x39, 0x0, 0xE,  0x3, 0x0, 0x0, 0x0, 0x0, -0x1A, 0x0, 0x10,
    0x3, 0x0, 0x0, 0x0, 0x1, -0x58, 0x0, 0x41, 0x3, 0x0, 0x0, 0x0, 0x1, 0x12,  0x0, 0x5B,
    0x4, 0x0, 0x0, 0x0, 0x1, 0x0,   0x0, 0x1B, 0x4, 0x0, 0x0, 0x0, 0x1, 0x28,  0x0, 0x4C,
    0x4, 0x0, 0x0, 0x0, 0x1, 0x36,  0x0, 0x6D, 0x5, 0x0, 0x0, 0x0, 0x1, 0x5D,  0x0, 0x53,
    0x6, 0x0, 0x0, 0x0, 0x0, -0x48, 0x0, 0x28};
CreditsLines D_808012BC_chcredits[81] = {
    0x0,  0x0, 0x1,  0x0, 0x0, -0x48, 0x0, 0x23,  -0x1, 0x0, 0x0,  0x0, 0x0, -0x3C, 0x0, 0x9,
    -0x1, 0x0, 0x2,  0x0, 0x0, -0x48, 0x0, 0x30,  -0x1, 0x0, 0x3,  0x0, 0x0, -0x3B, 0x0, 0x0,
    -0x1, 0x0, 0x4,  0x0, 0x1, 0x7A,  0x0, 0x28,  -0x1, 0x0, 0x5,  0x0, 0x0, -0x28, 0x0, 0x6,
    -0x1, 0x1, 0x0,  0x0, 0x0, -0x28, 0x0, 0xC,   -0x1, 0x1, 0x1,  0x0, 0x0, -0x39, 0x0, 0x1A,
    -0x1, 0x1, 0x2,  0x0, 0x0, -0x2F, 0x0, 0x25,  -0x1, 0x1, 0x3,  0x0, 0x0, -0x7,  0x0, 0x37,
    -0x1, 0x2, 0x1,  0x0, 0x0, -0x2A, 0x0, 0x4E,  -0x1, 0x2, 0x0,  0x0, 0x0, -0x2A, 0x0, 0x4F,
    -0x1, 0x2, 0x2,  0x0, 0x0, -0x2A, 0x0, 0x4C,  -0x1, 0x2, 0x3,  0x0, 0x0, -0x7,  0x0, 0x36,
    -0x1, 0x2, 0x4,  0x0, 0x0, -0x13, 0x0, 0xE,   -0x1, 0x3, 0x0,  0x0, 0x0, -0x13, 0x0, 0xF,
    -0x1, 0x3, 0x1,  0x0, 0x0, -0x12, 0x0, 0xC,   -0x1, 0x3, 0x4,  0x0, 0x1, -0x59, 0x0, 0x2B,
    -0x1, 0x3, 0x7,  0x0, 0x1, -0x59, 0x0, 0x43,  -0x1, 0x3, 0x2,  0x0, 0x0, -0x13, 0x0, 0x10,
    -0x1, 0x3, 0x6,  0x0, 0x1, -0x59, 0x0, 0x44,  -0x1, 0x3, 0x3,  0x0, 0x0, -0x1,  0x0, 0x6,
    -0x1, 0x3, 0x5,  0x0, 0x0, -0xF,  0x0, 0x12,  -0x1, 0x3, 0x8,  0x0, 0x0, -0xF,  0x0, 0x13,
    -0x1, 0x3, 0x9,  0x0, 0x0, -0xF,  0x0, 0x14,  -0x1, 0x3, 0xA,  0x0, 0x0, -0x6,  0x0, 0xA,
    -0x1, 0x3, 0xB,  0x0, 0x0, -0x4,  0x0, 0x37,  -0x1, 0x3, 0xC,  0x0, 0x1, 0x12,  0x0, 0x61,
    -0x1, 0x4, 0x0,  0x0, 0x1, 0x14,  0x0, 0x13,  -0x1, 0x4, 0x1,  0x0, 0x1, 0x12,  0x0, 0x62,
    -0x1, 0x4, 0x2,  0x0, 0x1, 0x15,  0x0, 0x1E,  -0x1, 0x4, 0x3,  0x0, 0x1, 0x18,  0x0, 0x20,
    -0x1, 0x4, 0x7,  0x0, 0x1, 0x18,  0x0, 0x21,  -0x1, 0x4, 0x8,  0x0, 0x1, 0x18,  0x0, 0x22,
    -0x1, 0x4, 0x9,  0x0, 0x1, 0x18,  0x0, 0x23,  -0x1, 0x4, 0xA,  0x0, 0x1, 0x1A,  0x0, 0x14,
    -0x1, 0x4, 0x4,  0x0, 0x1, 0x16,  0x0, 0x3C,  -0x1, 0x4, 0x5,  0x0, 0x1, 0x13,  0x0, 0x3E,
    -0x1, 0x4, 0x6,  0x0, 0x1, 0x3,   0x0, 0x9,   -0x1, 0x5, 0x0,  0x0, 0x1, 0x3,   0x0, 0xA,
    -0x1, 0x5, 0x1,  0x0, 0x1, 0x10,  0x0, 0x4A,  -0x1, 0x5, 0x2,  0x0, 0x1, 0x31,  0x0, 0x4,
    -0x1, 0x6, 0x1,  0x0, 0x1, 0x31,  0x0, 0x8,   -0x1, 0x6, 0x2,  0x0, 0x1, 0x31,  0x0, 0x5,
    -0x1, 0x6, 0x3,  0x0, 0x1, 0x31,  0x0, 0x7,   -0x1, 0x6, 0x4,  0x0, 0x1, 0x31,  0x0, 0x6,
    -0x1, 0x6, 0x5,  0x0, 0x1, 0x28,  0x0, -0x7A, -0x1, 0x6, 0x9,  0x0, 0x1, 0x28,  0x0, 0x7C,
    -0x1, 0x6, 0x6,  0x0, 0x1, 0x28,  0x0, -0x79, -0x1, 0x6, 0x7,  0x0, 0x1, 0x28,  0x0, -0x78,
    -0x1, 0x6, 0x8,  0x0, 0x1, 0x29,  0x0, 0x1C,  -0x1, 0x6, 0x0,  0x0, 0x1, 0x28,  0x0, -0x7B,
    -0x1, 0x6, 0xA,  0x0, 0x1, 0x28,  0x0, -0x7C, -0x1, 0x6, 0xB,  0x0, 0x1, 0x2B,  0x0, 0x31,
    -0x1, 0x6, 0xC,  0x0, 0x1, 0x2C,  0x0, 0x31,  -0x1, 0x6, 0xD,  0x0, 0x1, 0x36,  0x0, 0x70,
    -0x1, 0x7, 0x0,  0x0, 0x1, 0x3A,  0x0, 0x9,   -0x1, 0x7, 0x1,  0x0, 0x1, 0x37,  0x0, 0xF,
    -0x1, 0x7, 0x2,  0x0, 0x1, 0x36,  0x0, 0x72,  -0x1, 0x7, 0x3,  0x0, 0x1, 0x3F,  0x0, 0x19,
    -0x1, 0x7, 0x4,  0x0, 0x1, 0x51,  0x0, 0x16,  -0x1, 0x8, 0x5,  0x0, 0x1, 0x4F,  0x0, 0x19,
    -0x1, 0x8, 0x6,  0x0, 0x1, 0x50,  0x0, 0x9,   -0x1, 0x8, 0x7,  0x0, 0x1, 0x53,  0x0, 0x5,
    -0x1, 0x8, 0x8,  0x0, 0x0, -0x53, 0x0, 0x8,   -0x1, 0x8, 0x9,  0x0, 0x1, 0x60,  0x0, 0x6,
    -0x1, 0x8, 0x14, 0x0, 0x1, 0x55,  0x0, 0x2B,  -0x1, 0x8, 0xA,  0x0, 0x1, 0x43,  0x0, 0x8,
    -0x1, 0x8, 0xB,  0x0, 0x1, 0x43,  0x0, 0x9,   -0x1, 0x8, 0xC,  0x0, 0x1, 0x43,  0x0, 0xA,
    -0x1, 0x8, 0xD,  0x0, 0x1, 0x69,  0x0, 0x0,   -0x1, 0x8, 0xE,  0x0, 0x1, 0x5E,  0x0, 0x1C,
    -0x1, 0x8, 0x4,  0x0, 0x1, 0x44,  0x0, 0x15,  -0x1, 0x8, 0x2,  0x0, 0x1, 0x44,  0x0, 0x16,
    -0x1, 0x8, 0x3,  0x0, 0x0, -0x4A, 0x0, 0x10,  -0x1, 0x8, 0x1,  0x0, 0x1, 0x6A,  0x0, 0x0,
    -0x1, 0x8, 0xF,  0x0, 0x1, 0x6A,  0x0, 0x1,   -0x1, 0x8, 0x10, 0x0, 0x1, 0x6A,  0x0, 0x2,
    -0x1, 0x8, 0x11, 0x0, 0x0, -0x49, 0x0, 0x1,   -0x1, 0x8, 0x0,  0x0, 0x1, 0x67,  0x0, 0x0,
    0x1,  0x8, 0x12, 0x0, 0x1, 0x68,  0x0, 0x0};
static u32 D_808012BC_chcredits_rest[1] = {0xFF081300};
f32 D_80801548_chcredits[3] = {0.0f, 562.5f, -1125.0f};
f32 D_80801554_chcredits[3] = {0.0f, 0.0f, 0.0f};
f32 D_80801560_chcredits[2][3] = {357.9f, 0.16f, 0.0f, 0.15f, 0.16f, 0.0f};
f32 D_80801578_chcredits[2][3] = {-9.29f, 635.68f, 224.39f, -3.29f, 568.34f, -99.52f};
u8 D_80801590_chcredits[12] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
void *D_8080159C_chcredits[21] = {(void *) 0x01580174,
                                  (void *) 0x09A00001,
                                  0,
                                  (void *) func_80800800_chcredits,
                                  (void *) func_80105834,
                                  (void *) func_80801108_chcredits,
                                  0,
                                  0,
                                  0,
                                  (void *) 0x00400404,
                                  (void *) func_80800BCC_chcredits,
                                  0,
                                  (void *) 0x02800000,
                                  (void *) func_80800BD4_chcredits,
                                  (void *) func_80107C2C,
                                  (void *) 0x80000002,
                                  0,
                                  0,
                                  0,
                                  0,
                                  0};
