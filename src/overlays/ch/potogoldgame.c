#include "common.h"

extern void func_800D1000();
extern void *func_80100094(Actor *, u32);
extern void _subaddielink_entrypoint_0(void *);
typedef struct {
    u8 pad_0[0xC];
    u8 local_0[8];
    u8 local_1;
    u8 pad_1[3];
} Mass69PotGoldLink;
extern void func_800FC660();
extern u8 D_808024FC_chpotogoldgame[];
extern void func_800BBCB8(s32, s32, f32, s32, void *);
typedef struct {
    f32 ranges[4][2];
} PotGoldHeightRanges;
extern PotGoldHeightRanges D_80802558_chpotogoldgame;
extern void func_800F1EA4(f32 *, f32 *);
extern f32 func_800136E4(f32);
extern f32 func_800F13C4(f32, f32);
extern void _glid_entrypoint_0();
extern s32 _chpotogoldgame_entrypoint_1;
extern s32 func_800BEA88();
extern Actor *func_80106790(Unk80132ED0 *);
extern void _chpotogoldgame_entrypoint_3();
extern s32 func_800D91EC(f32 *, f32);
extern f32 func_800F5F24(s32);
extern void func_800EEB9C(f32 *, f32, f32);
extern int D_80802578_chpotogoldgame[];
typedef struct {
    u8 pad_0[0x64];
    u8 local_0;
    u8 local_1;
    u8 local_2;
} PotGameData88;
extern void func_800CE8D8(s32, f32, s32);
extern void func_800F7C0C(s32, s32, f32);
typedef struct {
    f32 local_0[3];
} PotoVector1238;
extern PotoVector1238 D_808024F0_chpotogoldgame;
extern void _chpotogoldgame_entrypoint_0();
typedef struct {
    u8 pad[0x72];
    u16 st : 6;
    u16 rest : 10;
} PgD;
typedef struct {
    u8 pad[0x65];
    u8 hi : 3;
    u8 f : 1;
    u8 lo : 4;
} PgC;
typedef struct {
    u8 pad[0x64];
    u32 hi : 11;
    u32 b20 : 1;
    u32 lo : 20;
} PgB;
extern void _chappearfx_entrypoint_1(Actor *, u32, u32, f32);
typedef struct {
    s32 value[3];
} PotGoldVector;
extern s32 D_80802540_chpotogoldgame[];
extern s32 D_8080254C_chpotogoldgame[];
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800F3214(s32 *, s32 *, s32 *, f32);
extern void func_800BF48C(s32, s32, s32);
typedef struct {
    s16 ob[3];
    u16 flag;
    s16 tc[2];
    u8 cn[4];
} PotVtx;
void func_808011DC_chpotogoldgame();
void func_808013BC_chpotogoldgame();
void func_80801494_chpotogoldgame();
int func_808016E8_chpotogoldgame();
void func_80801870_chpotogoldgame();
int func_80801998_chpotogoldgame();
s32 func_80801A7C_chpotogoldgame();
s32 func_8080206C_chpotogoldgame();
void func_80802124_chpotogoldgame();
int func_80800434_chpotogoldgame();
void func_80801558_chpotogoldgame();

void func_80800000_chpotogoldgame(u8 *actor)
{
    func_808011DC_chpotogoldgame();
    actor[0x65] &= 0xFFEF;
    if (func_800DA298(0x6B6) != 0) {
        func_80800434_chpotogoldgame(actor, 0xF);
    } else if ((func_800D0A9C(0x49, 1) != 0) || (func_800D0A9C(0x17, 4) != 0) ||
               (func_800DA298(0x1DB) != 0) || (func_800D395C() != 0)) {
        *(f32 *) &actor[0x18] = 2.0f;
        *(f32 *) &actor[0x2C] = 2.0f;
        *(f32 *) &actor[0x28] = 2.0f;
        *(f32 *) &actor[0x30] = 2.0f;
        *(f32 *) &actor[0x1C] = 2.0f;
        if (func_800D395C() != 0) {
            func_80800434_chpotogoldgame(actor, 0xD);
        } else {
            func_80800434_chpotogoldgame(actor, 4);
        }
    } else {
        *(f32 *) &actor[0x18] = 0.0f;
        *(f32 *) &actor[0x2C] = 0.0f;
        *(f32 *) &actor[0x28] = 0.0f;
        *(f32 *) &actor[0x30] = 0.0f;
        *(f32 *) &actor[0x1C] = 0.0f;
    }
    func_80801A7C_chpotogoldgame(actor);
    func_80801494_chpotogoldgame(actor, 1);
    func_80801558_chpotogoldgame(actor);
    *(s32 *) &actor[0x34] = 0;
    _sueggmisc_entrypoint_3();
}

void func_80801244_chpotogoldgame();

void func_80800124_chpotogoldgame(Actor *actor)
{
    s32 count;
    PotGameData88 *data;

    data = func_80100094(actor, 0);
    switch (actor->unk70_10) {
        case 1:
            func_80801A7C_chpotogoldgame((u8 *) actor);
            if (func_800DA298(0x9F6) && func_800DA298(0x9F7) && func_800DA298(0x9F8) &&
                func_800DA298(0x9F9)) {
                func_80800434_chpotogoldgame(actor, 2);
            }
            break;
        case 2:
            if (func_80801A7C_chpotogoldgame((u8 *) actor)) {
                func_808013BC_chpotogoldgame(actor, data->local_0, data->local_1,
                                             data->local_2, 0, 0);
                if (++data->local_1 == 4) {
                    data->local_1 = 0;
                    if (++data->local_2 == 5) {
                        data->local_2 = 0;
                        if (++data->local_0 == 5) {
                            func_80800434_chpotogoldgame(actor, 4);
                        }
                    }
                }
            }
            break;
        case 4:
            if (actor->unk64_20 && !_subaddiefind_entrypoint_2(0x1CD, 0)) {
                actor->unk64_20 = 0;
                if (func_800F64A4(func_800F54E4(), 0x10220)) {
                    func_80800434_chpotogoldgame(actor, 12);
                } else {
                    func_80800434_chpotogoldgame(actor, 5);
                }
            }
            break;
        case 5:
            if (data->local_0 < 5) {
                func_808011DC_chpotogoldgame(actor);
                for (count = 0; count != 4; count++) {
                    func_808013BC_chpotogoldgame(actor, data->local_0, count,
                                                 data->local_2, 0, 0);
                }
                if (++data->local_2 == 5) {
                    data->local_2 = 0;
                    data->local_0++;
                }
            }
            break;
        case 7:
            func_80801244_chpotogoldgame(actor);
            count = func_8080206C_chpotogoldgame(actor);
            func_800D2498(0xEB, count, 0);
            if (count == 100) {
                actor->actorData[2] = (s32) (45.0f - func_800CEA84(0));
                if (func_800D395C()) {
                    func_80800434_chpotogoldgame(actor, 14);
                } else {
                    func_80800434_chpotogoldgame(actor, 8);
                }
                func_800CE88C(0, 0);
            }
            break;
        case 12:
            if (!func_8010CB84(actor->position, 500) &&
                !func_800F64A4(func_800F54E4(), 0x10220)) {
                func_80108B04(actor, 0);
                func_80800434_chpotogoldgame(actor, 4);
            }
    }
    func_80801558_chpotogoldgame(actor);
}

void func_8080219C_chpotogoldgame();

s32 func_8080117C_chpotogoldgame();

int func_80800434_chpotogoldgame(actor, state)
Actor *actor;
s32 state;
{
    s32 end_dialog;
    s32 replay_dialog;
    PotoVector1238 pos;
    s32 intro_dialog;
    s32 replay_cells;
    s32 cells;
    s32 k;
    s32 j;
    s32 i;
    u8 *data;
    data = func_80100094(actor, 0);
    switch (state) {
        case 2:
            func_800DA544(0x1DB);
            func_80108B04(actor, 0);
            *(s8 *) ((s8 *) data + 0x65) = 0;
            *(s8 *) ((s8 *) data + 0x66) = 0;
            *(s8 *) ((s8 *) data + 0x64) = 0;
            func_80802124_chpotogoldgame(actor, 0, 0x10);
            break;

        case 5:
            if (func_800D211C(0x84) == 0x64) {
                intro_dialog = 0x1425;
            } else if (func_800D0A9C(0x49, 1) != 0) {
                intro_dialog = 0x13D1;
            } else if (func_800D0A9C(0x17, 4) != 0) {
                intro_dialog = 0x13D0;
            } else {
                intro_dialog = (func_800DA298(0x1E2) != 0) ? 0x13CF : 0x13CD;
            }
            func_800F8294(func_800F54E4(), (u8 *) actor + 4);
            func_8080219C_chpotogoldgame(actor, intro_dialog, 0x4E);
            *(s8 *) ((s8 *) data + 0x65) = 0;
            *(s8 *) ((s8 *) data + 0x66) = 0;
            *(s8 *) ((s8 *) data + 0x64) = 0;
            *(u8 *) ((s8 *) actor + 0x65) = (u8) (*(u8 *) ((s8 *) actor + 0x65) & 0xFFEF);
            break;

        case 6:
            func_8080219C_chpotogoldgame(actor, 0xCEC, 0xE);
            func_800CE8D8(0, 45.0f, 45);
            func_800CE928(0, &_chpotogoldgame_entrypoint_0, *(s32 *) ((s8 *) actor + 0));
            _gcfrontend_entrypoint_9(0x71);
            break;

        case 7:
            pos = D_808024F0_chpotogoldgame;
            for (i = 0; i < 5; i++) {
                for (j = 0; j < 4; j++) {
                    for (k = 0; k < 5; k++) {
                        func_808013BC_chpotogoldgame(actor, i, j, k, 0, 0);
                    }
                }
            }

            func_808011DC_chpotogoldgame(actor);
            func_8080227C_chpotogoldgame(actor);
            func_800F7C0C(func_800F54E4(), 0x5F, -1.0f);
            func_800F7CF4(func_800F54E4(), 0x5E, pos.local_0);
            func_800CE88C(0, 1);
            func_800FDC28(0xC);
            func_800DA544(0x1E2);
            break;

        case 8:
            cells = func_8080206C_chpotogoldgame(actor);
            if (func_800D211C(0x84) == 0x64) {
                if (cells < 0x64) {
                    func_800FC6B0(0x17);
                    end_dialog = 0x141E;
                } else if (*(s32 *) ((s8 *) actor + 0x20) < func_800D211C(0x89)) {
                    func_800FC6B0(0x16);
                    end_dialog = 0x1421;
                } else if (func_800D211C(0x89) == *(s32 *) ((s8 *) actor + 0x20)) {
                    func_800FC6B0(0x17);
                    end_dialog = 0x1420;
                } else {
                    func_800FC6B0(0x17);
                    end_dialog = 0x141F;
                }
            } else if (func_800D0A9C(0x49, 1) != 0) {
                if (func_800D211C(0x84) == cells) {
                    func_800FC6B0(0x17);
                    end_dialog = 0x13D9;
                } else if (cells < func_800D211C(0x84)) {
                    func_800FC6B0(0x17);
                    end_dialog = 0x13D7;
                } else if (cells == 0x64) {
                    func_800FC6B0(0x16);
                    end_dialog = 0x1422;
                } else {
                    func_800FC6B0(0x16);
                    end_dialog = 0x13D8;
                }
            } else if (func_800D0A9C(0x17, 4) != 0) {
                if (cells < 0x5A) {
                    func_800FC6B0(0x17);
                    end_dialog = 0x13D5;
                } else if (cells == 0x64) {
                    func_800FC6B0(0x16);
                    end_dialog = 0x1423;
                } else {
                    func_800FC6B0(0x16);
                    end_dialog = 0x13D6;
                }
            } else if (cells < 0x4B) {
                func_800FC6B0(0x17);
                end_dialog = 0x13D2;
            } else if (cells < 0x5A) {
                func_800FC6B0(0x16);
                end_dialog = 0x13D3;
            } else if (cells == 0x64) {
                func_800FC6B0(0x16);
                end_dialog = 0x1424;
            } else {
                func_800FC6B0(0x16);
                end_dialog = 0x13D4;
            }
            func_8080219C_chpotogoldgame(actor, end_dialog, 0xE);
            func_800F7C0C(func_800F54E4(), 0x5F, 0.0f);
            func_800FDC28(0);
            break;

        case 9:
            func_8080117C_chpotogoldgame(actor);
            break;

        case 10:
            func_8080111C_chpotogoldgame(actor);
            break;

        case 11:
            func_8080117C_chpotogoldgame(actor);
            break;

        case 12:
            if (func_800F64A4(func_800F54E4(), 0x10220) == 0) {
                func_8080219C_chpotogoldgame(actor, 0x141D, 0xE);
            }
            break;

        case 4:
            func_8080227C_chpotogoldgame(actor);
            func_80108B04(actor, 1);
            break;

        case 13:
            func_800F8294(func_800F54E4(), (u8 *) actor + 4);
            if (func_800D211C(0x84) == 0x64) {
                func_8080219C_chpotogoldgame(actor, 0x1439, 0xE);
            } else {
                func_8080219C_chpotogoldgame(actor, 0x1438, 0xE);
            }
            break;

        case 14:
            replay_cells = func_8080206C_chpotogoldgame(actor);
            if (func_800D211C(0x84) == 0x64) {
                if (replay_cells < 0x64) {
                    func_800FC6B0(0x17);
                    replay_dialog = 0x143A;
                } else if (*(s32 *) ((s8 *) actor + 0x20) < func_800D211C(0x89)) {
                    func_800FC6B0(0x16);
                    replay_dialog = 0x143D;
                } else if (func_800D211C(0x89) == *(s32 *) ((s8 *) actor + 0x20)) {
                    func_800FC6B0(0x17);
                    replay_dialog = 0x143C;
                } else {
                    func_800FC6B0(0x17);
                    replay_dialog = 0x143B;
                }
            } else if (func_800D211C(0x84) == replay_cells) {
                func_800FC6B0(0x17);
                replay_dialog = 0x1440;
            } else if (replay_cells < func_800D211C(0x84)) {
                func_800FC6B0(0x17);
                replay_dialog = 0x143F;
            } else if (replay_cells == 0x64) {
                func_800FC6B0(0x16);
                replay_dialog = 0x143E;
            } else {
                func_800FC6B0(0x16);
                replay_dialog = 0x1441;
            }
            func_8080219C_chpotogoldgame(actor, replay_dialog, 0xE);
            func_800FDC28(0);
    }

    func_80101FDC(actor, state);
}

void func_808010A0_chpotogoldgame();

s32 func_80800A94_chpotogoldgame(Actor *actor, s32 msg, s32 arg)
{
    Actor *spawned;
    s16 *args;
    s32 code;
    s32 value;

    args = (s16 *) &arg;

    switch (msg) {
        case 0x3D:
            if (!((PgB *) actor)->b20) {
                spawned = (Actor *) func_80108528(0x1CD, (char *) actor + 4, 0, &actor);

                *(u16 *) ((char *) spawned + 0x76) =
                    (*(u16 *) ((char *) spawned + 0x76) & 0x7F) | 0x1900;

                ((PgC *) actor)->f = 1;

                if (arg == 0) {
                    _chappearfx_entrypoint_1(spawned, 0x20, 0, 1.0f);
                }

                return 1;
            }
            return 0;

        case 0x30:
            code = args[0];

            switch (code) {
                case 0x141F:
                case 0x1420:
                case 0x1421:
                    if (args[1] != 0) {
                        return func_800D211C(0x89);
                    }
                    return *(s32 *) ((char *) actor + 0x20);

                case 0x1422:
                case 0x1423:
                case 0x1424:
                    return *(s32 *) ((char *) actor + 0x20);

                case 0x1425:
                    return func_800D211C(0x89);

                case 0x13D2:
                case 0x13D3:
                case 0x13D4:
                case 0x13D5:
                case 0x13D6:
                case 0x13D9:
                case 0x141E:
                    return func_8080206C_chpotogoldgame(actor);

                case 0x13D7:
                case 0x13D8:
                    if (args[1] != 0) {
                        return func_800D211C(0x84);
                    }
                    return func_8080206C_chpotogoldgame(actor);

                case 0x13CD:
                case 0x13CF:
                    value = args[1];

                    switch (value) {
                        case 1:
                            return 0x2D;
                        case 2:
                            return 0x5A;
                    }
                    return 0x4B;

                case 0x13D0:
                    if (args[1] != 0) {
                        return 0x2D;
                    }
                    return 0x5A;

                case 0x13D1:
                    return func_800D211C(0x84);

                case 0x1438:
                    if (args[1] != 0) {
                        return func_800D211C(0x84);
                    }
                    return 0x2D;

                case 0x1439:
                    if (args[1] != 0) {
                        return func_800D211C(0x89);
                    }
                    return 0x2D;

                case 0x143A:
                    return func_8080206C_chpotogoldgame(actor);

                case 0x143D:
                    if (args[1] != 0) {
                        return func_800D211C(0x89);
                    }
                    return *(s32 *) ((char *) actor + 0x20);

                case 0x143C:
                    return *(s32 *) ((char *) actor + 0x20);

                case 0x143B:
                    if (args[1] != 0) {
                        return func_800D211C(0x89);
                    }
                    return *(s32 *) ((char *) actor + 0x20);

                case 0x1440:
                    return func_8080206C_chpotogoldgame(actor);

                case 0x143F:
                    if (args[1] != 0) {
                        return func_800D211C(0x84);
                    }
                    return func_8080206C_chpotogoldgame(actor);

                case 0x143E:
                    return *(s32 *) ((char *) actor + 0x20);

                case 0x1441:
                    if (args[1] != 0) {
                        return func_800D211C(0x84);
                    }
                    return func_8080206C_chpotogoldgame(actor);

                default:
                    return 1;
            }

        case 0x2E:
            code = args[0];

            switch (code) {
                case 0xCEC:
                    func_80800434_chpotogoldgame(actor, 7);
                    return 1;

                case 0x13CD:
                case 0x13CF:
                case 0x13D0:
                case 0x13D1:
                case 0x1425:
                    if (args[1] != 0) {
                        func_80800434_chpotogoldgame(actor, 6);
                    } else {
                        func_80800434_chpotogoldgame(actor, 0xC);
                    }
                    return 1;

                case 0x13D3:
                    func_808010A0_chpotogoldgame(actor);
                    func_80800434_chpotogoldgame(actor, 9);
                    return 1;

                case 0x13D6:
                case 0x1423:
                    func_808010A0_chpotogoldgame(actor);
                    func_80800434_chpotogoldgame(actor, 0xA);
                    return 1;

                case 0x13D4:
                case 0x1424:
                    func_808010A0_chpotogoldgame(actor);
                    func_80800434_chpotogoldgame(actor, 0xB);
                    return 1;

                case 0x13D2:
                case 0x13D5:
                case 0x13D7:
                case 0x13D8:
                case 0x13D9:
                case 0x141E:
                case 0x141F:
                case 0x1420:
                case 0x1421:
                case 0x1422:
                    func_808010A0_chpotogoldgame(actor);
                    func_80800434_chpotogoldgame(actor, 5);
                    return 1;

                case 0x141D:
                    func_8080227C_chpotogoldgame(actor);
                    value = func_800F54E4();
                    func_800F7B9C(value, 0x93);
                    return 1;

                case 0x1438:
                case 0x1439:
                    func_80800434_chpotogoldgame(actor, 6);
                    return 1;

                case 0x143A:
                case 0x143B:
                case 0x143C:
                case 0x143D:
                case 0x143E:
                case 0x143F:
                case 0x1440:
                case 0x1441:
                    func_808010A0_chpotogoldgame(actor);
                    func_8080219C_chpotogoldgame(actor, 0x1442, 0x4E);
                    return 1;

                case 0x1442:
                    if (args[1] != 0) {
                        func_80800434_chpotogoldgame(actor, 6);
                    } else {
                        func_8080227C_chpotogoldgame(actor);
                        func_800C0850();
                        _gcfrontend_entrypoint_10();
                    }
                    return 1;

                default:
                    return 1;
            }

        case 0x0B:
            if (arg == 5 && ((PgD *) actor)->st == 0xB) {
                {
                    func_8080111C_chpotogoldgame(actor);
                    return 4;
                }
            }

            if (arg == 0) {
                func_80800434_chpotogoldgame(actor, 4);
                return 4;
            }
            if (arg == 3 || arg == 5) {
                func_80800434_chpotogoldgame(actor, 5);
                return 4;
            }
            func_80800434_chpotogoldgame(actor, 5);
            return 4;

        case 0x95:
            if (((PgD *) actor)->st == 4) {
                func_80108B04(actor, 1);
                ((PgC *) actor)->f = 0;
            }

            return 1;

        default:
            return 0;
    }
}

int chpotogoldgame_entrypoint_0(s32 unk_0, s32 unk_1)
{
    if (func_800D395C()) {
        return func_80800434_chpotogoldgame(func_80106790(unk_1), 0xE);
    }
    {
        return func_80800434_chpotogoldgame(func_80106790(unk_1), 8);
    }
}

void func_808010A0_chpotogoldgame(Actor *actor)
{
    s32 cells;
    cells = func_8080206C_chpotogoldgame(actor);
    if (func_800D211C(0x84) == 100) {
        func_800D2054(1, 0x89, actor->actorData[2]);
    } else {
        if (cells == 100) {
            func_800D2054(1, 0x89, actor->actorData[2]);
        }
        func_800D2054(0, 0x84, cells);
    }
}

int func_8080111C_chpotogoldgame(s32 actor)
{
    f32 pos[3];
    _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_1(0x1F6, actor + 4), pos);
    func_800D1000(0x49, 1, pos, 1, 0);
    func_80802124_chpotogoldgame(actor, 3, 0x10);
}

s32 func_8080117C_chpotogoldgame(s32 actor)
{
    f32 pos[3];

    _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_1(0x201, actor + 0x4), pos);
    func_800D1000(0x17, 0x4, pos, 1, 0);
    func_80802124_chpotogoldgame(actor, 5, 0x10);
}

void func_808011DC_chpotogoldgame(actor) Actor *actor;
{
    s32 i;
    Mass69PotGoldLink *links;

    links = func_80100094(actor, 1);
    for (i = 0; i < 10; i++) {
        links[i].local_1 = 0;
        _subaddielink_entrypoint_0(links[i].local_0);
    }
}

void func_80801244_chpotogoldgame(s32 actor)
{
    s32 off;
    s32 n;
    s32 *objs[10];
    u8 *base;
    s32 x;
    s32 y;
    s32 z;
    s32 i;

    base = func_80100094(actor, 1);
    off = 0;
    if (base[0x14] != 0) {
        do {
            if (_subaddielink_entrypoint_4(base + off + 0xC) == 0 &&
                func_808016E8_chpotogoldgame(base + off, &x, &y, &z) != 0) {
                func_808013BC_chpotogoldgame(actor, y, x, z, 1, base + off);
                // Matching: empty test steers IDO's code generation.
                if (off) {
                }
            }
            off += 0x18;
        } while (off < 0xF0 && base[off + 0x14] != 0);
    }
    n = _subaddiefind_entrypoint_4(0x15F, objs, 10);
    i = 0;
    if (n > 0) {
        do {
            // Matching: empty block steers IDO's code generation.
            if (1) {
            }
            off = i * 0x18;
            func_800EE7F8(base + off, objs[i] + 1);
            _subaddielink_entrypoint_1(base + off + 0xC, *objs[i]);
            i += 1;
            base[i * 0x18 - 4] = 1;
        } while (i < n);
    }
    if (i < 10) {
        do {
            i += 1;
            base[i * 0x18 - 4] = 0;
        } while (i < 10);
    }
}

// Sets one grid cell (sector, layer, slot) lit or unlit and updates its vertex colours.
void func_808013BC_chpotogoldgame(actor, sector, layer, slot, lit,
                                  egg) Actor *actor;
s32 sector;
s32 layer;
s32 slot;
s32 lit;
s32 egg;
{
    u8(*cells)[4][5];
    cells = func_80100094(actor, 0);
    if (lit && !cells[sector][layer][slot]) {
        if (egg)
            func_800BBCB8(egg, egg, 1.0f, 30, D_808024FC_chpotogoldgame);
        func_800FC660(14);
    }
    cells[sector][layer][slot] = lit;
    func_80801870_chpotogoldgame(layer, sector, slot, lit);
}

void func_80801494_chpotogoldgame(actor, value) Actor *actor;
s32 value;
{
    u8(*cells)[4][5];
    s32 sector;
    s32 layer;
    s32 slot;

    cells = func_80100094(actor, 0);
    for (sector = 0; sector < 5; sector++) {
        for (layer = 0; layer < 4; layer++) {
            for (slot = 0; slot < 5; slot++) {
                cells[sector][layer][slot] = value;
                func_80801870_chpotogoldgame(layer, sector, slot, value);
            }
        }
    }
}

void func_80801558_chpotogoldgame(actor) Actor *actor;
{
    s32 color[3];
    PotGoldVector low;
    PotGoldVector high;
    f32 blend;
    low = *(PotGoldVector *) &D_80802540_chpotogoldgame;
    high = *(PotGoldVector *) &D_8080254C_chpotogoldgame;
    blend = func_800F10B4((f32) func_8080206C_chpotogoldgame(), 100.0f, 0.0f, 0.0f, 0.5f);
    blend += func_800F10B4(*(f32 *) ((u8 *) actor + 0x2C), 0.0f, 2.0f, 0.0f, 0.1f);
    blend += func_800F10B4(*(f32 *) ((u8 *) actor + 0x30), 0.0f, 2.0f, 0.0f, 0.1f);
    blend += func_800F10B4(((f32 *) actor->actorData)[0], 0.0f, 2.0f, 0.0f, 0.1f);
    blend += func_800F10B4(*(f32 *) ((u8 *) actor + 0x28), 0.0f, 2.0f, 0.0f, 0.1f);
    blend += func_800F10B4(((f32 *) actor->actorData)[1], 0.0f, 2.0f, 0.0f, 0.1f);
    func_800F3214(color, low.value, high.value, blend);
    func_800BF48C(color[0], color[1], color[2]);
    func_800C8C90(color);
}

int func_808016E8_chpotogoldgame(pos, layer, sector, slot)
f32 *pos;
s32 *layer;
s32 *sector;
s32 *slot;
{
    f32 angle;
    PotGoldHeightRanges ranges = D_80802558_chpotogoldgame;
    for (*layer = 0; *layer < 4; (*layer)++) {
        if (ranges.ranges[0][*layer << 1] < pos[1])
            return 0;
        if (ranges.ranges[0][(*layer << 1) + 1] < pos[1])
            break;
    }
    if (*layer >= 4)
        return 0;
    func_800F1EA4(pos, &angle);
    angle = func_800136E4(angle - 7.0f);
    *sector = (s32) (angle / 72.0f);
    angle = func_800F13C4(angle, 72.0f);
    if (angle > 58.0f)
        return 0;
    *slot = (s32) (angle / 12.0f);
    if (func_800F13C4(angle, 12.0f) > 10.0f)
        return 0;
    return 1;
}

void func_80801870_chpotogoldgame(layer, sector, slot, lit) s32 layer;
s32 sector;
s32 slot;
s32 lit;
{
    s32 temp_a1;
    temp_a1 = (sector = ((lit & 1) * 0x10) | sector);
    _glid_entrypoint_0(func_800BEA88(0, temp_a1), ((layer * 5) - slot) + 5,
                       &_chpotogoldgame_entrypoint_1, sector);
}

void chpotogoldgame_entrypoint_1(s32 unk_0, Vtx *src_vtx, Vtx *vtx, s32 count, s32 arg)
{
    s32 dim;
    Vtx *end;

    dim = arg & 0x10;
    arg &= 0xF;
    end = vtx + count;
    while (vtx < end) {
        if (func_80801998_chpotogoldgame((s32) src_vtx) == arg) {
            if (dim) {
                vtx->v.cn[0] = 100;
                vtx->v.cn[1] = 100;
                vtx->v.cn[2] = 100;
            } else {
                vtx->v.cn[0] = 255;
                vtx->v.cn[1] = 255;
                vtx->v.cn[2] = 255;
            }
        }
        vtx++;
        src_vtx++;
    }
}

int func_80801998_chpotogoldgame(vtx)
s32 vtx;
{
    f32 angle;
    f32 pos[3];
    // Matching: "| 0" is needed for the match.
    func_800EE88C(pos, vtx | 0);
    func_800F1EA4(pos, &angle);
    return angle / 72.0f;
}

void chpotogoldgame_entrypoint_2(s32 unk_0, Unk80132ED0 *unk_1)
{
    s32 flag;
    Actor *actor;
    actor = func_80106790(unk_1);
    switch (actor->unk6C_9) {
        case 0x15A:
            flag = 0x9F6;
            break;
        case 0x15B:
            flag = 0x9F7;
            break;
        case 0x15C:
            flag = 0x9F8;
            break;
        case 0x15D:
            flag = 0x9F9;
            break;
        default:
            return;
    }
    if (!func_800DA298(flag)) {
        func_800FC6B0(0xE);
        func_800DA544(flag);
    }
}

s32 func_80801A7C_chpotogoldgame(actor)
u8 *actor;
{
    s32 result;

    result = 1;
    if (func_800DA298(0x9F6) || func_800DA298(0x1DB)) {
        result &= func_800D91EC((f32 *) (actor + 0x18), 2.0f);
    }
    if (func_800DA298(0x9F7) || func_800DA298(0x1DB)) {
        result &= func_800D91EC((f32 *) (actor + 0x2C), 2.0f);
    }
    if (func_800DA298(0x9F8) || func_800DA298(0x1DB)) {
        result &= func_800D91EC((f32 *) (actor + 0x28), 2.0f);
    }
    if (func_800DA298(0x9F9) || func_800DA298(0x1DB)) {
        result &= func_800D91EC((f32 *) (actor + 0x30), 2.0f);
    }
    if (func_800DA298(0x9F6) && func_800DA298(0x9F7) && func_800DA298(0x9F8) &&
        func_800DA298(0x9F9)) {
        result &= func_800D91EC((f32 *) (actor + 0x1C), 2.0f);
    }
    _glid_entrypoint_0(func_800BEA88(0), 0x18, _chpotogoldgame_entrypoint_3, *(s32 *) actor);
    _glid_entrypoint_0(func_800BEA88(0), 0x15, _chpotogoldgame_entrypoint_3, *(s32 *) actor);
    _glid_entrypoint_0(func_800BEA88(0), 0x17, _chpotogoldgame_entrypoint_3, *(s32 *) actor);
    _glid_entrypoint_0(func_800BEA88(0), 0x16, _chpotogoldgame_entrypoint_3, *(s32 *) actor);
    _glid_entrypoint_0(func_800BEA88(0), 0x19, _chpotogoldgame_entrypoint_3, *(s32 *) actor);
    return result;
}

void chpotogoldgame_entrypoint_3(s32 light_id, s32 unk_1, PotVtx *vtx, s32 count,
                                 s32 link)
{
    Actor *actor;
    PotVtx *end;
    u8 brightness;

    actor = func_80106790(link);
    switch (light_id) {
        case 0x15:
            brightness = func_800F10B4(((f32 *) actor->actorData)[5], 0.0f, 2.0f, 100.0f, 255.0f);
            break;
        case 0x16:
            brightness = func_800F10B4(((f32 *) actor->actorData)[6], 0.0f, 2.0f, 100.0f, 255.0f);
            break;
        case 0x17:
            brightness = func_800F10B4(((f32 *) actor->actorData)[4], 0.0f, 2.0f, 100.0f, 255.0f);
            break;
        case 0x18:
            brightness = func_800F10B4(((f32 *) actor->actorData)[0], 0.0f, 2.0f, 100.0f, 255.0f);
            break;
        case 0x19:
            brightness = func_800F10B4(((f32 *) actor->actorData)[1], 0.0f, 2.0f, 100.0f, 255.0f);
    }
    for (end = vtx + count; vtx < end; vtx++) {
        vtx->cn[0] = brightness;
        vtx->cn[1] = brightness;
        vtx->cn[2] = brightness;
    }
}

// Returns the number of lit cells (0-100).
s32 func_8080206C_chpotogoldgame(actor)
Actor *actor;
{
    u8(*cells)[4][5];
    s32 layer;
    s32 sector;
    s32 count;
    s32 slot;

    count = 0;
    cells = func_80100094(actor, 0);
    for (sector = 0; sector < 5; sector++) {
        for (layer = 0; layer < 4; layer++) {
            for (slot = 0; slot < 5; slot++) {
                if (cells[sector][layer][slot]) {
                    count++;
                }
            }
        }
    }
    return count;
}

void func_80802124_chpotogoldgame(actor, unk_1, unk_2) s32 *actor;
s32 unk_1;
s32 unk_2;
{
    s32 state;
    state = actor[13];

switch (state) {
    case 0:
        _capod_entrypoint_2(actor[0], 0x29, 0x10, actor);
    case 1:
        actor[13] = 2;
    case 2:
        _capod_entrypoint_6(actor[0], unk_1, unk_2, actor);
}

}

void func_8080219C_chpotogoldgame(Actor *actor, s32 dialog_id, s32 unk_2)
{
    f32 pos[3];
    f32 offset[3];

switch (actor->actorData[7]) {
    case 1:
        break;
    case 0:
        _capod_entrypoint_2(actor->unk0, 0x29, 0x10);
    default:
        _capod_entrypoint_8(1);
        actor->actorData[7] = 1;
        _gcdialogcamera_entrypoint_6(actor->unk0);
        _gcdialogcamera_entrypoint_8();
        _capod_entrypoint_7(5, 1);
}

func_800F5A00(func_800F54E4(), pos);
func_800EEB9C(offset, func_800F5F24(func_800F54E4()), 300.0f);
func_800EF04C(pos, offset);
_subaddiedialog_entrypoint_11(actor->unk0, dialog_id, unk_2, pos, 0x22);
}

int func_8080227C_chpotogoldgame(Actor *actor)
{
    s32 *ptr = (s32 *) ((char *) actor + 0x34);

if (*ptr) {
    _capod_entrypoint_3(0, actor);
    *ptr = 0;
}

}

int chpotogoldgame_entrypoint_4()
{
    return (int) &D_80802578_chpotogoldgame;
}

// TU-NOTE: the .data of this overlay is defined here in C. The tables point to
// functions of this file; IDO's assembler schedules some of them differently unless
// the tables live in the same unit. Values come from the ROM.
extern void func_80105834();
extern void func_8010A730();
extern void func_80108ED0();
extern void func_80107C2C();
PotoVector1238 D_808024F0_chpotogoldgame = {0.0f, 1075.0f, -2.7e+03f};
u8 D_808024FC_chpotogoldgame[68] = {
    0x0, 0x1D, 0x9, 0xE2, 0x0, 0x1B, 0xFD, 0xA8, 0xFC, 0xE0, 0x0, 0x2D, 0x0, 0xC8,
    0x1, 0x2C, 0x0, 0xE,  0x0, 0xA,  0x0,  0x28, 0x0,  0x22, 0x0, 0x26, 0x0, 0x4C,
    0x0, 0x19, 0x0, 0x19, 0x0, 0x15, 0x0,  0x19, 0x0,  0xE6, 0x0, 0x2B, 0x1, 0x0,
    0x1, 0x80, 0x0, 0x2F, 0x0, 0x66, 0x0,  0x5C, 0x0,  0x51, 0x0, 0x19, 0x0, 0x14,
    0x0, 0x1E, 0x0, 0xC0, 0x0, 0x31, 0xFF, 0xCE, 0xFF, 0x9C, 0x0, 0x0};
s32 D_80802540_chpotogoldgame[3] = {0x50, 0x50, 0x50};
s32 D_8080254C_chpotogoldgame[3] = {0xDC, 0xDC, 0xDC};
PotGoldHeightRanges D_80802558_chpotogoldgame = {1825.0f, 1.57e+03f, 1475.0f, 1125.0f,
                                                 1025.0f, 6.5e+02f,  575.0f,  2.5e+02f};
int D_80802578_chpotogoldgame[18] = {0x1630405,
                                     0x1,
                                     0x0,
                                     (u32) func_80800124_chpotogoldgame,
                                     (u32) func_80105834,
                                     (u32) func_8010A730,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x0,
                                     (u32) func_80108ED0,
                                     0x6700F0,
                                     (u32) func_80800000_chpotogoldgame,
                                     (u32) func_80107C2C,
                                     -0x7FFFDC00,
                                     (u32) func_80800A94_chpotogoldgame,
                                     0x0};
