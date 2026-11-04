// Jukebox in Jolly's bar (needs the JUKEBOX cheat): a two-level menu of music categories and
// unlocked tracks, plus a listener actor that reacts to its dance message with a random dance.
#include "common.h"

typedef struct {
    void *items;
    u8 count;
    u8 id;
    u8 pad[2];
} MusicCat76;
extern int func_800DC298(f32);
extern void _gcnewoption_entrypoint_31(s32, s32, s32);
extern void _gcnewoption_entrypoint_32(s32, s32);
extern void _gcnewoption_entrypoint_33(s32);
typedef struct {
    s16 local_0;
    s16 local_2;
    s16 local_1;
} MusicStyle62;
typedef struct {
    s16 local_0;
    s16 local_1;
} MusicItem62;
typedef struct {
    MusicItem62 *local_0;
    u8 local_1;
    u8 pad_0[3];
} MusicCategory62;
extern MusicStyle62 D_80801554_chmusicmenu;
extern MusicStyle62 D_8080155C_chmusicmenu;
typedef struct {
    s16 id;
    u8 unk2;
    s8 unk3;
} MusicEntry;
typedef struct {
    MusicEntry *entries;
    s32 pad4;
} MusicSet;
extern void func_800FEF94();
extern s32 func_800FCDE0(s32, s32, s32);
extern s32 func_800FCED0(s32, s32, s32);
typedef struct {
    MusicItem62 *local_0;
    s32 local_1;
} MusicMenuList;
extern MusicMenuList D_808014F4_chmusicmenu[];
typedef struct {
    s16 id;
    s16 pad2;
} MusicTrack;
typedef struct {
    MusicTrack *unk0;
    s32 unk4;
} MusicMenuEntry;
extern void func_800FEC60(s32);
extern void func_800DA544(s32);
extern void func_800FCAE0(s32, s32, s32);
extern void func_800FCA90(s32);
extern s16 D_808012A0_chmusicmenu[];
extern void *func_80100094(Actor *, s32);
typedef union {
    s32 local_0;
    struct {
        s16 local_1;
        s16 local_2;
    } local_3;
} MusicMenuEvent;
extern int D_8080157C_chmusicmenu[];
extern int D_808015C4_chmusicmenu[];
typedef struct {
    u8 pad0[0x64];
    u32 padH : 8;
    u32 f : 8;
    u32 padL : 16;
} ByteBf65;
extern int D_8080160C_chmusicmenu[];
extern s32 func_800FCF50();
extern void _gcnewoption_entrypoint_27(s32, s32, s32);
extern void func_800FC660(s32);
extern void _gcnewoption_entrypoint_37(void *, s32);
typedef struct {
    u8 local_0;
    u8 pad_0[7];
} MusicMenuCount521;
extern MusicMenuCount521 D_808014F8_chmusicmenu[];
extern void _gcnewoption_entrypoint_35(void);
extern u8 func_8010D5DC[];
extern void _gcnewoption_entrypoint_40(void *, s32, s32, s32, f32, f32);
extern void _gcnewoption_entrypoint_14(void *, s32, s32, s32, f32);
extern void func_8008F990(f32 *, f32);
extern s32 func_800FCCD4(s32);
void func_80800930_chmusicmenu();

// Jukebox actor: dance pulse, menu building, track playback, state machine and draw.
// Jukebox in Jolly's bar: toggles the dance state and tells listeners (message 0x6E).
void func_80800000_chmusicmenu(u8 *actor)
{
    s32 unk_0;
    s32 unk_1;

    if (func_800DA298(0xC0) != 0) {
        if (*(s32 *) ((char *) actor + 0x28) != 0) {
            *(f32 *) ((char *) actor + 0x58) = 10.0f;
            _capod_entrypoint_22();
            unk_0 = *(s32 *) ((char *) actor + 0);
            _capod_entrypoint_21(unk_0, unk_0, 0x11, 4);
            *(s32 *) ((char *) actor + 0x28) = 0;
            func_80101238(0x6E, 0);
            return;
        }
        *(f32 *) ((char *) actor + 0x58) = 15.0f;
        _capod_entrypoint_22();
        unk_1 = *(s32 *) ((char *) actor + 0);
        _capod_entrypoint_21(unk_1, unk_1, 0x12, 4);
        *(s32 *) ((char *) actor + 0x28) = 1;
        func_80101238(0x6E, 1);
    }
}

// Maps a category index to its menu title string id.
s32 func_808000B4_chmusicmenu(s32 category)
{
    if (category < 9) {
        return category + 0x1851;
    }
    return category + 0x1860;
}

void func_808000D0_chmusicmenu(u8 *actor, s32 menu)
{
    s32 i;

    switch ((u32) *(u16 *) (actor + 0x72) >> 10) {
        case 1:
            _gcnewoption_entrypoint_32(menu, 0x6F);
            for (i = 0; i < 12; i++) {
                if (((MusicCat76 *) D_808014F4_chmusicmenu)[i].id == 0x50 && func_800DC298(0.5f)) {
                    _gcnewoption_entrypoint_31(menu, i, 0x51);
                } else {
                    _gcnewoption_entrypoint_31(menu, i,
                                               ((MusicCat76 *) D_808014F4_chmusicmenu)[i].id);
                }
            }
            return;
        case 2:
            _gcnewoption_entrypoint_32(menu, 0x6F);
            _gcnewoption_entrypoint_33(menu);
            for (i = 0;
                 i < ((MusicCat76 *) D_808014F4_chmusicmenu)[*(s32 *) (actor + 0x30)].count;
                 i++) {
                _gcnewoption_entrypoint_31(
                    menu, i,
                    ((MusicCat76 *) D_808014F4_chmusicmenu)[*(s32 *) (actor + 0x30)].id);
            }
    }
}

void func_8080021C_chmusicmenu(Actor *actor, void *menu)
{
    s32 i;
    MusicStyle62 style_on;
    MusicStyle62 style_off;

    switch (actor->unk70_10) {
        case 1:
            for (i = 0; i < 12; i++)
                _gcnewoption_entrypoint_12(menu, i, (s16) (i + 10));
            if ((s32) actor->actorData[1] != -1) {
                _gcnewoption_entrypoint_27(menu, actor->actorData[1], 1);
                _gcnewoption_entrypoint_41(menu, actor->actorData[1]);
            }
            break;
        case 2:
            style_on = D_80801554_chmusicmenu;
            style_off = D_8080155C_chmusicmenu;
            for (i = 0;
                 i <
                 ((MusicCategory62 *) D_808014F4_chmusicmenu)[actor->actorData[6]].local_1;
                 i++) {
                _gcnewoption_entrypoint_12(menu, i, (s16) (i + 10));
                if (func_800FCF50((MusicCategory62 *) D_808014F4_chmusicmenu[actor->actorData[6]]
                                      .local_0[i]
                                      .local_0))
                    _gcnewoption_entrypoint_13(menu, i, &style_on);
                else
                    _gcnewoption_entrypoint_13(menu, i, &style_off);
            }
            if (actor->actorData[1] == actor->actorData[6] &&
                (s32) actor->actorData[0] != -1) {
                _gcnewoption_entrypoint_27(menu, actor->actorData[0], 1);
                _gcnewoption_entrypoint_41(menu, actor->actorData[0]);
            }
    }
}

void func_80800400_chmusicmenu(Actor *actor)
{
    MusicEntry *entries;
    s32 unk_0;
    s16 unk_1;
    s32 track_id;

    if ((s32) actor->actorData[0] >= 0 && (!actor->unk74_30 || !actor->unk74_29)) {
        entries = ((MusicSet *) D_808014F4_chmusicmenu)[actor->actorData[6]].entries;
        if (entries[actor->actorData[0]].unk3 != -1) {
            unk_0 = -1;
            unk_1 = -1;
            track_id = entries[actor->actorData[0]].id;
            func_800FEF94(4, entries[actor->actorData[0]].unk3,
                          entries[actor->actorData[0]].unk2, &unk_0, &unk_1);
            if (!actor->unk74_30) {
                actor->unk74_30 = func_800FCDE0(track_id, unk_0, actor->actorData[3]);
            }
            if (!actor->unk74_29) {
                actor->unk74_29 =
                    func_800FCED0(track_id, 60000000 / unk_1, actor->actorData[3]);
            }
        }
    }
}

void func_80800560_chmusicmenu(Actor *actor, s32 unk_1, f32 unk_2)
{
    MusicItem62 *items;

    items = D_808014F4_chmusicmenu[actor->actorData[6]].local_0;
    if (unk_2 == 0.0f) {
        func_800FC660(items[actor->actorData[0]].local_0);
    } else {
        func_800FCAE0(items[actor->actorData[0]].local_0, -1, 0x14D);
    }
    actor->unk74_30 = 0;
    actor->unk74_29 = 0;
    ((f32 *) actor->actorData)[3] = unk_2;
    func_80800400_chmusicmenu(actor);
}

void func_80800610_chmusicmenu(Actor *actor)
{
    s16 track_id;
    s16 *unk_1;
    MusicTrack *tracks;

    if (!actor->unk64_20) {
        func_800FEC60(5);
        actor->unk64_20 = 1;
        func_800DA544(0);
    }
    unk_1 = &track_id;
    tracks = ((MusicMenuEntry *) D_808014F4_chmusicmenu)[*(s32 *) ((u8 *) actor + 0x30)].unk0;
    track_id = tracks[*(s32 *) ((u8 *) actor + 0x18)].id;
    if (actor->unk74_7 != 0) {
        func_800FCAE0(actor->unk74_7, 0, 0x14D);
        func_800FCA90(actor->unk74_7);
    }
    if (actor->unk74_7 == track_id) {
        func_80800560_chmusicmenu(actor, track_id, 1.5f);
    } else {
        actor->unk64_19 = 1;
        *(f32 *) ((u8 *) actor + 0x2C) = 2.0f;
    }
    actor->unk74_7 = track_id;
}

void func_80800714_chmusicmenu(Actor *actor)
{
    if (actor->unk64_20) {
        func_800FECB8(5);
        actor->unk64_20 = 0;
        func_800FE8AC();
        func_800FCAE0(actor->unk74_7, 0, 0x14D);
        func_800FCA90(actor->unk74_7);
        actor->unk74_7 = 0;
        func_800DA524(0);
    }
}

void func_8080079C_chmusicmenu(actor, menu, index, event) Actor *actor;
s32 menu;
s32 index;
s32 event;
{
    s32 prev_index;

    switch (event) {
        case 4:
            if (func_800FCF50(
                    D_808014F4_chmusicmenu[actor->actorData[6]].local_0[index].local_0)) {
                if (!actor->unk64_19 && index != actor->actorData[0]) {
                    _gcnewoption_entrypoint_27(menu, index, 1);
                    prev_index = actor->actorData[0];
                    if (prev_index != -1) {
                        _gcnewoption_entrypoint_27(menu, prev_index, 0);
                    }
                    actor->actorData[2] = index;
                    actor->actorData[0] = index;
                    actor->actorData[1] = actor->actorData[6];
                    func_80800610_chmusicmenu(actor);
                }
            } else {
                func_800FC660(0xF);
            }
            break;
        case 3:
            actor->actorData[6] = index;
            func_80800930_chmusicmenu(actor, 2);
            break;
        case 0:
            func_8080021C_chmusicmenu(actor, menu);
            break;
        case 5:
            if (!actor->unk64_19) {
                _gcnewoption_entrypoint_37(func_80100094(actor, 1), 1);
            }
            break;
        case 2:
            switch (actor->unk70_10) {
                case 1:
                    func_80800930_chmusicmenu(actor, 3);
                    break;
                case 2:
                    func_80800930_chmusicmenu(actor, 1);
            }
    }
}

void func_80800930_chmusicmenu(actor, mode) Actor *actor;
s32 mode;
{
    void *menu;
    void *track_menu;
    f32 pos[3];

    switch (actor->unk70_10) {
        case 2:
            _gcnewoption_entrypoint_6(actor, 1);
            break;
        case 1:
            _gcnewoption_entrypoint_6(actor, 1);
            actor->actorData[0] = -1;
            actor->unk64_19 = 0;
            if (mode == 3) {
                _capod_entrypoint_22();
                func_80101238(0x6E, 0);
            }
            break;
        case 5:
            func_800F8300(func_800F54E4(), 2, actor->position);
            _capod_entrypoint_21(actor->unk0, actor->unk0, 0x11, 4);
            actor->actorData[4] = 0;
            actor->unk58 = 10.0f;
    }
    func_80102424(actor, mode);
    switch (actor->unk70_10) {
        case 1:
            _gcnewoption_entrypoint_4(actor, 1, _gcnewoption_entrypoint_35, 0, 0x1850);
            menu = func_80100094(actor, 1);
            _gcnewoption_entrypoint_40(menu, 0x41, 0x22, 0x20, 0.8f, 1.0f);
            _gcnewoption_entrypoint_8(menu, 5);
            _gcnewoption_entrypoint_9(menu, 12);
            _gcnewoption_entrypoint_10(menu, 0);
            func_808000D0_chmusicmenu(actor, menu);
            _gcnewoption_entrypoint_14(menu, 0, 1, 3, 4.0f);
            _gcnewoption_entrypoint_11(menu);
            return;
        case 2:
            _gcnewoption_entrypoint_4(actor, 1, _gcnewoption_entrypoint_35, 0,
                                      func_808000B4_chmusicmenu(actor->actorData[6]));
            track_menu = func_80100094(actor, 1);
            _gcnewoption_entrypoint_40(track_menu, 0x41, 0x22, 0x20, 0.8f, 1.0f);
            _gcnewoption_entrypoint_8(track_menu,
                                      D_808014F8_chmusicmenu[actor->actorData[6]].local_0 < 5
                                          ? D_808014F8_chmusicmenu[actor->actorData[6]].local_0
                                          : 5);
            _gcnewoption_entrypoint_9(track_menu,
                                      D_808014F8_chmusicmenu[actor->actorData[6]].local_0);
            _gcnewoption_entrypoint_10(track_menu, 2);
            func_808000D0_chmusicmenu(actor, track_menu);
            _gcnewoption_entrypoint_14(track_menu, 0, 1, 3, 4.0f);
            if (actor->actorData[1] == actor->actorData[6]) {
                if ((s32) actor->actorData[2] != -1) {
                    actor->actorData[0] = actor->actorData[2];
                }
            }
            _gcnewoption_entrypoint_11(track_menu);
            return;
        case 4:
            actor->actorData[1] = actor->actorData[2] = -1;
            break;
        case 3:
            func_800F82D4(func_800F54E4(), 0);
            func_80800714_chmusicmenu(actor);
            actor->actorData[2] = -1;
            actor->actorData[1] = -1;
            actor->actorData[6] = -1;
            break;
        case 5:
            _gccubesearch_entrypoint_12(pos, 0x299, actor->position);
            func_8008F8B0();
            func_8008F8D8(1);
            func_8008F904(func_8010D5DC, actor->unk0);
            func_8008F938(1);
            func_8008F990(pos, 400.0f);
    }
}

void func_80800CBC_chmusicmenu(Actor *actor)
{
    s32 i;

    *(s32 *) ((u8 *) actor + 0x30) = -1;
    actor->unk74_7 = 0;
    *(s32 *) ((u8 *) actor + 0x18) = -1;
    i = 0;
    func_8010A828(actor, 9);
    if (func_800D3E40(5)) {
        func_80800930_chmusicmenu(actor, 4);
    } else if (func_800DA298(0x344)) {
        func_80800930_chmusicmenu(actor, 6);
    } else {
        func_80800930_chmusicmenu(actor, 7);
    }
    while (D_808012A0_chmusicmenu[i] != 0x9A) {
        i++;
    }
    func_800DA3B8(i + 0x53E, func_800DA298(0x43));
}

// Jukebox main update: dialog, menu updates and music playback.
void func_80800DA4_chmusicmenu(Actor *actor)
{
    switch (actor->unk70_10) {
        case 4:
            if (func_8010C500(actor)) {
                if (!func_800DA298(0x3E1)) {
                    func_80800930_chmusicmenu(actor, 5);
                    func_800DA544(0x3E1);
                    return;
                }
                if (func_80016B30(0, 1)) {
                    func_80800930_chmusicmenu(actor, 5);
                }
            }
            break;
        case 2:
            if (actor->unk64_19 && func_800D90A4((f32 *) actor->actorData + 5)) {
                func_80800560_chmusicmenu(actor, actor->unk74_7, 0.0f);
                actor->unk64_19 = 0;
            }
        case 1:
            if (actor->unk74_7) {
                if (func_800FCCD4(actor->unk74_7) && !actor->unk64_19) {
                    func_80800400_chmusicmenu(actor);
                }
                if (func_800D90A4(&actor->unk58)) {
                    func_80800000_chmusicmenu(actor);
                }
            }
            _gcnewoption_entrypoint_0(func_80100094(actor, 1));
            break;
        case 3:
            func_80800930_chmusicmenu(actor, 4);
            break;
        case 7:
            if (func_8010C500(actor)) {
                _subaddiedialog_entrypoint_11(actor->unk0, 0x1048, 0xF, actor->position, 0x6F);
                func_800DA544(0x344);
                func_80800930_chmusicmenu(actor, 6);
            }
    }
}

void func_80800F50_chmusicmenu(u8 *actor)
{
    unsigned int state;
    func_80800714_chmusicmenu(actor);
    state = (unsigned int) *(u16 *) ((char *) actor + 0x72) >> 10;
    if ((state == 1) || (state == 2)) {
        _gcnewoption_entrypoint_6(actor, 1);
    }
}

void func_80800F98_chmusicmenu(Actor *actor, void *unk_1)
{
    void *menu;
    if (!func_800EB854(actor)) {
        if ((s32) actor->unk70_10 < 6) {
            func_800DF744(1, 0);
            func_800DF744(2, 1);
        } else {
            func_800DF744(1, 1);
            func_800DF744(2, 0);
        }
        func_80101870(actor, unk_1);
    } else {
        menu = func_80100094(actor, 1);
        if (menu != NULL)
            _gcnewoption_entrypoint_1(menu, unk_1);
    }
}

s32 func_80801040_chmusicmenu(Actor *actor, s32 msg, MusicMenuEvent data)
{
    switch (msg) {
        case 0x20:
            func_8080079C_chmusicmenu(actor, func_80101080(actor), data.local_3.local_1,
                                      data.local_3.local_2);
            return 1;
        case 0x32:
            func_80800930_chmusicmenu(actor, 1);
            return 1;
    }
    return 0;
}

int chmusicmenu_entrypoint_0()
{
    return (int) &D_8080157C_chmusicmenu;
}

int chmusicmenu_entrypoint_1()
{
    return &D_808015C4_chmusicmenu;
}

// Listener actor: reacts to the jukebox dance message.
// Dancer actor: on message 0x6E picks one of 14 dance animations at random, without repeats.
int func_808010C4_chmusicmenu(Actor *actor, s32 msg, s32 data)
{
    s32 candidates[14];
    s32 anim_id;
    s32 i;
    s32 count;
    s32 active;
    switch (msg) {
        case 0x95:
            if (!func_800D3E40(5) || !func_800DA298(0xC0) || _glcutDll_entrypoint_20())
                func_800FFAB0(actor);
            else
                ((ByteBf65 *) actor)->f &= ~1;
            return 1;
        case 0x6E:
            active = data & 1;
            ((ByteBf65 *) actor)->f = (active & 1) | (((ByteBf65 *) actor)->f & ~1);
            if (active) {
                count = 0;
                if ((u32) *(u16 *) ((u8 *) actor + 0x76) >> 7 != 0x33) {
                    for (i = 0; i < 14; i++) {
                        if (!func_800DA298(i + 1))
                            candidates[count++] = i;
                    }
                    if (count == 0) {
                        for (i = 0; i < 14; i++) {
                            func_800DA524(i + 1);
                        }
                        i = func_800DC128(0, 14);
                    } else
                        i = candidates[func_800DC128(0, count)];
                    anim_id = i + 1;
                    func_800DA544(anim_id);
                    func_80102424(actor, anim_id);
                }
            }
            return 1;
        default:
            return 0;
    }
}

int chmusicmenu_entrypoint_2()
{
    return &D_8080160C_chmusicmenu;
}

extern void func_80105834();
extern void func_80107C2C();
extern int func_80101870();
s16 D_808012A0_chmusicmenu[48] = {
    0x32, 0x33, 0x55, 0x39, 0x38, 0x3E, 0x42, 0x48, 0x40, 0x49, 0x47, 0x4C, 0x45, 0x4B, 0x4F, 0x50,
    0x53, 0x3B, 0x52, 0x4E, 0x3F, 0x63, 0x41, 0x56, 0x57, 0x61, 0x76, 0x75, 0x7E, 0x82, 0x7A, 0x58,
    0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x62, 0x7F, 0x5E, 0x5F, 0x1F, 0x20, 0x65, 0x66, 0x64, 0x54, 0x9A};
u32 D_80801300_chmusicmenu[5] = {0x320001, 0x32FF01, 0x320002, 0x3300FF, 0x5500FF};
u32 D_80801314_chmusicmenu[6] = {0x390003, 0x390103, 0x390008, 0x390005, 0x390006, 0x3800FF};
u32 D_8080132C_chmusicmenu[7] = {0x3E000B, 0x3E010B, 0x3E000C, 0x3E0011,
                                 0x3E000D, 0x4200FF, 0x4800FF};
u32 D_80801348_chmusicmenu[7] = {0x400013, 0x400014, 0x400015, 0x400016,
                                 0x4900FF, 0x4700FF, 0x4C00FF};
u32 D_80801364_chmusicmenu[11] = {0x45001D, 0x45011D, 0x45001F, 0x4B0122, 0x4B0020, 0x4B0123,
                                  0x4B0025, 0x4F00FF, 0x5000FF, 0x5300FF, 0x3B00FF};
u32 D_80801390_chmusicmenu[4] = {0x520026, 0x520126, 0x520027, 0x4E00FF};
u32 D_808013A0_chmusicmenu[4] = {0x3F0029, 0x3F002A, 0x3F002B, 0x6300FF};
u32 D_808013B0_chmusicmenu[6] = {0x41002C, 0x41012C, 0x41002D, 0x41002F, 0x410030, 0x5600FF};
u32 D_808013C8_chmusicmenu[8] = {0x570032, 0x570132, 0x570033, 0x570034,
                                 0x570035, 0x570036, 0x7600FF, 0x6100FF};
u32 D_808013E8_chmusicmenu[5] = {0x750039, 0x75003A, 0x7E00FF, 0x8200FF, 0x7A00FF};
u32 D_808013FC_chmusicmenu[23] = {0x58003B, 0x58013B, 0x58003C, 0x58003D, 0x58003E, 0x58003F,
                                  0x580041, 0x580043, 0x580040, 0x580042, 0x580044, 0x590037,
                                  0x590038, 0x5A00FF, 0x5B00FF, 0x5C00FF, 0x5D00FF, 0x6200FF,
                                  0x9A00FF, 0x7F00FF, 0x5F00FF, 0x5E00FF, 0x8300FF};
u32 D_80801458_chmusicmenu[9] = {0x7D00FF, 0x6700FF, 0x2400FF, 0x1F00FF, 0x2000FF,
                                 0x6500FF, 0x6600FF, 0x6400FF, 0x5400FF};
u32 D_8080147C_chmusicmenu[30] = {
    0x0,        0x0,       0x40600000, 0x1B60001, 0x404CCCCD, 0x2F0001,  0x3F800000, 0x850001,
    0x3F400000, 0x8F0001,  0x3F800000, 0x1570001, 0x3FACCCCD, 0x15A0001, 0x4084CCCD, 0x16C0101,
    0x40000000, 0x16D0001, 0x40800000, 0x17B0101, 0x40966666, 0x1890001, 0x40A00000, 0x1E70001,
    0x40500000, 0x2D30001, 0x3FC00000, 0x2FA0001, 0x40B00000, 0x32C0001};
MusicMenuList D_808014F4_chmusicmenu[12] = {
    (void *) &D_80801300_chmusicmenu, 0x50F0000,  (void *) &D_80801314_chmusicmenu, 0x6310000,
    (void *) &D_8080132C_chmusicmenu, 0x73F0000,  (void *) &D_80801348_chmusicmenu, 0x7500000,
    (void *) &D_80801364_chmusicmenu, 0xB6E0000,  (void *) &D_80801390_chmusicmenu, 0x4A60000,
    (void *) &D_808013A0_chmusicmenu, 0x4AD0000,  (void *) &D_808013B0_chmusicmenu, 0x6A80000,
    (void *) &D_808013C8_chmusicmenu, 0x8690000,  (void *) &D_808013E8_chmusicmenu, 0x5220000,
    (void *) &D_808013FC_chmusicmenu, 0x177E0000, (void *) &D_80801458_chmusicmenu, 0x96F0000};
MusicStyle62 D_80801554_chmusicmenu = {0xFF, 0xFF, 0xFF};
MusicStyle62 D_8080155C_chmusicmenu = {0x0, 0x0, 0x64};
static u32 D_8080155C_chmusicmenu_rest[6] = {0xC3FA0000, 0x0,        0xC4FA0000,
                                             0xC3A00000, 0x437A0000, 0xC4CE4000};
int D_8080157C_chmusicmenu[18] = {0x15801A5,
                                  0x99C0006,
                                  0x0,
                                  (u32) func_80800DA4_chmusicmenu,
                                  (u32) func_80105834,
                                  (u32) func_80800F98_chmusicmenu,
                                  0x0,
                                  0x0,
                                  0x0,
                                  0xC01,
                                  (u32) func_80800F50_chmusicmenu,
                                  0x0,
                                  0x0,
                                  (u32) func_80800CBC_chmusicmenu,
                                  (u32) func_80107C2C,
                                  -0x7FFFDBFE,
                                  (u32) func_80801040_chmusicmenu,
                                  0x0};
int D_808015C4_chmusicmenu[18] = {
    0x1580531, 0x9A30001, 0x0, 0x0, (u32) func_80105834, (u32) func_80101870, 0x0, 0x0, 0x0, 0x1808,
    0x0,       0x0,       0x0, 0x0, (u32) func_80107C2C, -0x7FFFD3FE,         0x0, 0x0};
int D_8080160C_chmusicmenu[21] = {0x1580534,
                                  0x6D60001,
                                  (u32) &D_8080147C_chmusicmenu,
                                  0x0,
                                  (u32) func_80105834,
                                  (u32) func_80101870,
                                  0x0,
                                  0x3F99999A,
                                  0x0,
                                  0x100,
                                  0x0,
                                  0x0,
                                  0x0,
                                  0x0,
                                  (u32) func_80107C2C,
                                  -0x7DFFD2FE,
                                  (u32) func_808010C4_chmusicmenu,
                                  0x0,
                                  0x0,
                                  0x0,
                                  0x0};
