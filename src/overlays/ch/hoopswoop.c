#include "common.h"

#define CODEX_PAIR_EVENT_PAYLOAD
extern int D_80801EC0_chhoopswoop[];
extern int D_80801F08_chhoopswoop[];
extern int D_80801F50_chhoopswoop[];
extern void func_800DA544(int);
extern void func_80108B04(void *, int);
typedef struct { s16 local_0 : 15; u16 local_1 : 1; s16 local_2[3]; f32 local_3; } HoopSwoopItem;
typedef struct { s32 local_0; u8 pad_0[0x10]; HoopSwoopItem local_1[1]; } HoopSwoopList;
extern void *func_80100094(Actor *, u32);
extern void func_800CE8D8(s32, f32, s32);
typedef struct { u8 pad_0[0x15]; u8 pad_1:7; u8 local_0:1; } HoopPlayerFlags26;
extern u32 func_800FDC28(u32);
extern void func_800FC6B0(u32);
extern Actor *_subaddiefind_entrypoint_2(s32, s32);
extern s32 func_800D211C(s32);
typedef struct ActorLocal_HoHooswoop { int unk3A; } ActorLocal_HoHooswoop;
extern f32 func_800DC178(f32, f32);
extern s32 func_800D9154(f32 *, f32);
extern s32 func_800D9078(f32 *);
extern void _sumultiscore_entrypoint_6();
typedef union { s32 word; s16 halves[2]; } PairEventPayload;
extern void _sumultiscore_entrypoint_11(void *, s32, s32, f32);
extern void func_8010A800(Actor *, s32);
extern f32 func_800D8FF8(void);
extern f32 func_800136E4(f32);
extern int D_80801F98_chhoopswoop[];
typedef struct { s32 arr[16]; } HsArr;
extern f32 func_80103F38(Actor *, s32);
extern f32 func_800EEFD4(f32 *);
extern f32 func_800EEAA4(f32 *, f32 *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EF934(f32 *, f32 *, f32);
extern int D_80801FB0_chhoopswoop[];
extern u8 D_80801FDC_chhoopswoop[];
extern u8 unk70[];
extern void func_800F7ECC(s32, s32, f32);
typedef struct { union { struct { s32 id : 15; u32 used : 1; } b; struct { s16 pad; s16 pos[3]; } p; } u; f32 timer; } HoopEntry;
typedef struct { s32 count; u8 pad4[0x10]; HoopEntry entries[1]; } HoopList;
extern s32 func_800DA298(s32);
extern s32 func_800DC128(s32, s32);
extern void func_800EE88C(f32 *, s16 *);
extern Actor *func_80108474(s32, f32 *, s32);
extern void _subaddiefade_entrypoint_2(Actor *);
extern f32 func_800DC0C0(void);
extern s32 func_800D3948(void);
extern void func_80103140(Actor *, u16, u16, s32);
extern void func_80102424(Actor *, s32);
extern void func_8010114C(Unk80132ED0 *, s32, s32);
void func_80800094_chhoopswoop();
int func_80801494_chhoopswoop();
s32 func_80801500_chhoopswoop();
int func_8080153C_chhoopswoop();
void func_808015A4_chhoopswoop();
int func_80801A10_chhoopswoop();
s32 func_80801AB4_chhoopswoop();
void func_80801D20_chhoopswoop();
int func_80801D8C_chhoopswoop();
int func_80801DCC_chhoopswoop();
void func_80800D28_chhoopswoop();
extern void func_80101870(), func_80105834(), func_80107C2C(), func_8080016C_chhoopswoop(), func_80800620_chhoopswoop();

int chhoopswoop_entrypoint_0()
{
    return &D_80801EC0_chhoopswoop;
}

int *chhoopswoop_entrypoint_1()
{
    return &D_80801F08_chhoopswoop;
}

int chhoopswoop_entrypoint_2(void)
{
    return &D_80801F50_chhoopswoop;
}

int func_80800024_chhoopswoop(param_0) Actor *param_0;
{
  s32 local_0;
  local_0 = func_800F54E4();
  func_800946C4(func_800F53D0(local_0), 1);
  func_800DA524(0);
  func_800DA524(3);
  func_800DA524(2);
  func_800DA524(1);
  {
    unsigned short temp;
    local_0 = *((unsigned short *) (((char *) param_0) + 0x6E));
    temp = local_0;
    temp &= 0xFE00;
    *((unsigned short *) (((char *) param_0) + 0x6E)) = temp;
  }
  func_80800094_chhoopswoop(param_0);
  _susubgame_entrypoint_11(0);
}

void func_80800094_chhoopswoop(param_0) Actor *param_0;
{
    u32 *local_0[100];
    HoopSwoopList *local_1;
    s32 local_2;

    local_1 = func_80100094(param_0, 0);
    local_1->local_0 = _gccubesearch_entrypoint_9(0x154, local_0, 100);
    for (local_2 = 0; local_2 < local_1->local_0; local_2++) {
        func_800EE814(local_1->local_1[local_2].local_2, local_0[local_2]);
        local_1->local_1[local_2].local_0 = local_0[local_2][3] >> 23;
        local_1->local_1[local_2].local_3 = 0.0f;
        local_1->local_1[local_2].local_1 = 0;
    }
}

s32 func_808007A4_chhoopswoop();

void func_8080016C_chhoopswoop(param_0) Actor *param_0;
{
    u8 *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 0);
    switch (param_0->unk70_10) {
    case 3:
        local_1 = *(s32 *)(local_0 + 4);
        func_800D24E8(0xC2, local_1, 0);
        for (local_1 = 0; local_1 < *(s32 *)local_0; local_1++) {
            func_800D90A4(local_0 + 0x1C + local_1 * 0xC);
        }
        if (func_800D9154(&param_0->unk58, func_800DC178(0.5f, 1.0f))) func_80108B04(param_0, -1);
        if (func_800CEAD0(param_0->unk6C_0)) {
            *(s32 *)(local_0 + 0xC) = func_808007A4_chhoopswoop(param_0, local_0 + 0x10);
            func_800F7ECC(func_800F54E4(), 3, 0.0f);
            func_800F8300(func_800F54E4(), 2, 0);
            *(f32 *)(local_0 + 0x9F8) = 3.0f;
            func_80101FDC(param_0, 4);
        }
        break;
    case 4:
        if (_susubgame_entrypoint_9() || func_800D9078((f32 *)(local_0 + 0x9F8))) {
            _susubgame_entrypoint_5(param_0, local_0 + 0x4C4, 5, 1, 0);
            func_80101FDC(param_0, 5);
            _subaddiedialog_entrypoint_11(param_0->unk0, *(s32 *)(local_0 + 0xC), *(s32 *)(local_0 + 0x10), NULL, 0x22);
            if (param_0) {}
        }
        break;
    case 1: case 2: case 5: case 6: break;
    }
}

void func_80800C9C_chhoopswoop();

u32 func_80800C04_chhoopswoop();

void func_80800910_chhoopswoop();

void func_808004BC_chhoopswoop();

int func_80800320_chhoopswoop(Actor *param_0, s32 param_1, s32 param_2)
{
    u8 *local_0;
    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
        case 0x2E:
            func_80800910_chhoopswoop(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
            break;
        case 0x2F:
            func_80800C9C_chhoopswoop(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
            break;
        case 0x30:
            return func_80800C04_chhoopswoop(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
        case 0x3D: func_80800D28_chhoopswoop(param_0, param_2); break;
        case 0x32:
            _subaddiedialog_entrypoint_11(param_0->unk0, func_800D395C() ? 0x1119 : 0x10C1, 0x46, param_0->position, 0x22);
            func_800F82D4(func_800F54E4(), 2);
            break;
        case 0x57:
            return _susubgame_entrypoint_3(param_0, local_0 + 0x4C4, param_2 & 0xFFFF, (param_2 & 0xFFFF0000) >> 16);
        case 0x95: func_808004BC_chhoopswoop(param_0); break;
        default: return 0;
    }
    return 1;
}

void func_808004BC_chhoopswoop(Actor *param_0)
{
    u8 *local_0 = func_80100094(param_0, 0);

    func_800BF744(1, 0);
    func_800BF744(2, 1);
    if (func_800D395C()) func_800A16BC(1);
    if (param_0->unk70_10 == 1) {
        if (_susubgame_entrypoint_10(param_0, 1, 0x320, 0x1AD)) {
            _chintrotext_entrypoint_2(1);
            _susubgame_entrypoint_6(param_0, local_0 + 0x4C4, 0, 0x20, 0);
        } else {
            _susubgame_entrypoint_5(param_0, local_0 + 0x4C4, 5, 1, 0);
            _subaddiedialog_entrypoint_11(param_0->unk0, 0xCEC, 7, param_0->position, 0x22);
            func_800F82D4(func_800F54E4(), 2);
        }
        func_80101FDC(param_0, 2);
        return;
    }
    func_800F8300(func_800F54E4(), 2, 0);
    _susubgame_entrypoint_5(param_0, local_0 + 0x4C4, 5, 1, 0);
    _subaddiedialog_entrypoint_11(param_0->unk0, 0xCEB, 0x46, NULL, 0x22);
}

void func_80800620_chhoopswoop(param_0) s32 param_0;
{
  s32 local_0;
  local_0 = func_80100094(param_0, 0);
  if (func_800CEAA8((*(s32 *)((char *)(param_0) + 0x6C)) & 0x1FF))
  {
    func_800CE88C((*(s32 *)((char *)(param_0) + 0x6C)) & 0x1FF, 0);
  }
  if (_susubgame_entrypoint_2(param_0, local_0 + 0x4C4))
  {
    _susubgame_entrypoint_4(param_0, local_0 + 0x4C4);
  }
}

void func_808006A0_chhoopswoop(param_0) Actor *param_0;
{
    u8 *local_0;
    s32 local_1;
    f32 local_2;

    local_0 = func_80100094(param_0, 0);
    if (1) {}
    local_2 = param_0->unk74_7;
    _subaddiemulti_entrypoint_2(local_0);
    for (local_1 = 0; local_1 < *(s32 *)local_0; local_1++) {
        *(f32 *)(local_0 + local_1 * 12 + 0x1C) = 0.0f;
        ((HoopPlayerFlags26 *)(local_0 + local_1 * 12))->local_0 = 0;
    }
    func_80101FDC(param_0, 3);
    func_800D2770(0xC2, 0);
    func_800CE8D8(param_0->unk6C_0, local_2, (s32)local_2);
    func_800CE88C(param_0->unk6C_0, 1);
    func_800DA524(0);
    func_800FDC28(12);
}

s32 func_808007A4_chhoopswoop(Actor *param_0, s32 *param_1)
{
    s32 *local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    u32 local_5;
    s32 local_6;
    s32 local_7;
    s32 local_8;

    local_0 = func_80100094(param_0, 0);
    local_1 = local_0[1];
    local_6 = func_800D0A9C(0x15, 1);
    local_7 = func_800D395C();
    local_8 = func_800D2054(0, 0x81, local_1);
    local_3 = local_8 == 1 && (local_6 || local_7);
    local_4 = local_1 >= 30;
    local_5 = local_4 && !local_6 && !local_7;
    func_800FDC28(0);
    func_800FC6B0((local_5 || local_3) ? 0x16 : 0x17);
    *param_1 = 6;
    if (local_5) {
        local_2 = 0x10D1;
    } else if (local_3) {
        local_2 = 0x10C3;
    } else if (!func_800D395C()) {
        if (local_6) {
            if (local_8 == 0) local_2 = 0x10F7;
            else local_2 = 0x10F6;
        } else {
            local_2 = 0x10F5;
        }
    } else {
        local_2 = 0xCEB;
        *param_1 = 0x46;
    }
    return local_2;
}

void func_80800910_chhoopswoop(Actor *param_0, s32 param_1, s32 param_2)
{
    u8 *local_0;
    Actor *local_1;

    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
    case 0x10C1:
    case 0x1119:
        if (param_2 > 0) {
            func_800DA544(0);
            _susubgame_entrypoint_6(param_0, local_0 + 0x4C4, 7, 0x20, 0);
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x10C2, 0x44, 0, 0x22);
            func_80108B04(param_0, 0);
        } else {
            _plcamera_entrypoint_8(func_800F54E4());
            _susubgame_entrypoint_5(param_0, local_0 + 0x4C4, 5, 1, 0);
            _subaddiedialog_entrypoint_11(param_0->unk0, 0xCEC, 7, 0, 0x22);
        }
        func_800DA544(0x1AD);
        _gcfrontend_entrypoint_9(0x67);
        break;
    case 0x10C2:
        _plcamera_entrypoint_8(func_800F54E4());
        _susubgame_entrypoint_5(param_0, local_0 + 0x4C4, 5, 1, 0);
        _subaddiedialog_entrypoint_11(param_0->unk0, 0xCEC, 7, 0, 0x22);
        break;
    case 0x10C3:
    case 0x10F5:
    case 0x10F6:
    case 0x10F7:
        _subaddiedialog_entrypoint_11(param_0->unk0, 0xCEB, 0x46, 0, 0x22);
        break;
    case 0xCEB:
        func_800F82D4(func_800F54E4(), 0);
        func_80101FDC(param_0, 6);
        if (func_800D395C()) {
            func_800A16BC(0);
            if (param_2 > 0) {
                _gcfrontend_entrypoint_11();
            } else {
                _gcfrontend_entrypoint_10();
            }
        } else if (param_2 > 0) {
            _gcgoto_entrypoint_1(0xE5, 1);
        } else {
            local_1 = _subaddiefind_entrypoint_2(0x21A, 0);
            if (local_1) {
                _subaddiefade_entrypoint_3(local_1);
                func_8010A570(local_1);
            }
            _susubgame_entrypoint_4(param_0, local_0 + 0x4C4);
        }
        break;
    case 0xCEC:
        _susubgame_entrypoint_4(param_0, local_0 + 0x4C4);
        func_808006A0_chhoopswoop(param_0);
        break;
    case 0x10D1:
        _susubgame_entrypoint_4(param_0, local_0 + 0x4C4);
        func_800F82D4(func_800F54E4(), 0);
        _glcutDll_entrypoint_6(0xE1, 0x21);
        break;
    }
}

u32 func_80800C04_chhoopswoop(Actor *param_0, s32 param_1, s32 param_2)
{
    u32 local_0;

    switch (param_1) {
    case 0x10C1:
        return param_2 == 0 ? param_0->unk74_7 : 0x1E;
    case 0x10C3:
    case 0x10F6:
        return func_800D211C(0x81);
    case 0x1119:
        if (param_2 == 0) {
            local_0 = param_0->unk74_7;
        } else {
            local_0 = func_800D211C(0x81);
        }
        return local_0;
    }
    return 0;
}

void func_80800C9C_chhoopswoop(Actor *param_0, s32 param_1, s32 param_2)
{
  s32 local_0 = param_0;
  switch (param_2)
  {
    case 1 :
      func_80108B04(local_0, 1);
      func_800DA544(3);
      break;

    case 2 :
      func_80108B04(local_0, 2);
      func_800DA544(2);
      break;

    case 3 :
      func_800DA544(1);
      *(s32 *)((char *)param_0 + 0x3c) = 0;
      break;
  }
}

void func_80800D28_chhoopswoop(Actor *param_0, s32 param_1)
{
    f32 pos[3];
    Actor *actor;
    HoopList *list;
    s32 idx;
    s32 found;
    s32 i;
    f32 r;
    s32 height;
    s32 flag;
    void *data;
    s32 sel;
    s32 snd;

    flag = func_800DA298(0);
    list = func_80100094(param_0, 0);
    idx = func_800DC128(0, list->count);
    if (flag) {
        func_800EFA4C(pos, 1400.0f, 260.0f, -1400.0f);
        idx = -1;
    } else {
        found = 0;
        for (i = 0; i < list->count; i++) {
            if (list->entries[idx].timer == 0.0f && !list->entries[idx].u.b.used) {
                found = 1;
                break;
            }
            idx++;
            if (idx >= list->count) {
                idx = 0;
            }
        }
        if (!found) {
            return;
        }
        func_800EE88C(pos, list->entries[idx].u.p.pos);
    }
    actor = func_80108474(0x356, pos, list->entries[idx].u.b.id);
    data = func_80100094(actor, 0);
    _subaddiefade_entrypoint_2(actor);
    r = func_800DC0C0();
    if (r < 0.1666f) {
        sel = 0;
    } else if (r < 0.5f) {
        sel = 1;
    } else {
        sel = 2;
    }
    if (param_1 != -1) {
        sel = param_1;
    }
    *(s32 *)((u8 *)data + 0x40) = 2 - sel;
    switch (sel) {
    case 0:
        snd = func_800D3948() ? 0x958 : 0x878;
        func_80103140(actor, snd, param_0->unk0->unk16, idx);
        func_80102424(actor, 4);
        height = 100;
        actor->unk58 = 10.0f;
        break;
    case 1:
        snd = func_800D3948() ? 0x957 : 0x877;
        func_80103140(actor, snd, param_0->unk0->unk16, idx);
        func_80102424(actor, 3);
        height = 150;
        actor->unk58 = 10.0f;
        break;
    case 2:
        snd = func_800D3948() ? 0x956 : 0x7A1;
        func_80103140(actor, snd, param_0->unk0->unk16, idx);
        func_80102424(actor, 2);
        height = 200;
        actor->unk58 = 10.0f;
        break;
    }
    if (!flag) {
        actor->position[1] = height + 80.0f;
    }
    actor->unk3C = param_0->unk0;
    actor->actorData[5] = idx;
    actor->unk6C_0 = param_0->unk6C_0;
    if (idx != -1) {
        list->entries[idx].u.b.used = 1;
    }
    if (flag) {
        actor->unk58 = 60.0f;
        if (param_0->unk3C != NULL) {
            func_8010114C(param_0->unk3C, 0x4F, 1);
        }
        param_0->unk3C = actor->unk0;
    }
    /* probe: three empty tests. They raise the block count (uopt: fixed cost of a fresh s register = blocks/4, here > 18),
     * so idx takes a3 plus spill 0x50 instead of s0 as in the target; if (actor) gives actor the weight for s0. The original probably had more control flow. */
    if (actor) {}
    if (1) {}
    if (1) {}
}

void func_80801130_chhoopswoop(u8 *param_0) {
    s32 local_0;
    s32 local_1;
    s32 local_2;

    local_0 = func_80100094(param_0, 0);
    *(u16 *)((char *)param_0 + 0x6E) = (*(u16 *)((char *)param_0 + 0x6E) & 0xFE00) | 5;
    func_80800094_chhoopswoop(param_0);
    _subaddiemulti_entrypoint_3(0xA);
    local_1 = local_0 + 0x4DC;
    _sumultiscore_entrypoint_3(local_1);
    _sumultiscore_entrypoint_4(local_1, 7, 0, 1);
    local_2 = 0;
    if (_gcstatusDll_entrypoint_11() > 0) {
        do {
            func_800946C4(func_800F53D0(local_2), 1);
            local_2 += 1;
        } while (local_2 < _gcstatusDll_entrypoint_11());
    }
}

void func_808011DC_chhoopswoop(Actor *param_0)
{
    u8 *local_2;
    s32 local_0;
    f32 *local_3;
    f32 local_1;

    local_2 = func_80100094(param_0, 0);
    _sumultiscore_entrypoint_6(local_2 + 0x4DC);
    switch (param_0->unk70_10) {
        case 1:
            if (!func_800C954C() && !func_800DA298(0x6AD)) {
                _subaddiedialog_entrypoint_11(param_0->unk0, 0xCEC, 7, NULL, 0x22);
                func_80101FDC(param_0, 2);
            }
            break;
        case 3:
            for (local_0 = 0, local_3 = (f32 *)(local_2 + 0x1C);
                 local_0 < *(s32 *)local_2; local_0++, local_3 += 3) {
                func_800D90A4(local_3);
            }
            if (_subaddiefind_entrypoint_9(0x356) < 5) {
                local_1 = func_800DC178(0.5f, 1.0f);
                if (func_800D9154(&param_0->unk58, local_1 / (f32)_gcstatusDll_entrypoint_11())) {
                    func_80108B04(param_0, -1);
                }
            }
            if (func_800CEAD0(param_0->unk6C_0)) {
                func_808015A4_chhoopswoop(param_0);
            }
            break;
        case 4:
            if (_susubgame_entrypoint_9() || func_800D9078(local_2 + 0x9F8)) {
                _susubgame_entrypoint_5(param_0, local_2 + 0x4C4, 5, 1, 0);
                _subaddiedialog_entrypoint_11(param_0->unk0, *(s32 *)(local_2 + 0xC),
                    *(s32 *)(local_2 + 0x10), NULL, 0x22);
                func_80101FDC(param_0, 5);
            }
            break;
    }
}

s32 func_808013C4_chhoopswoop(s32 param_0, s32 param_1){
    s32 temp = func_80100094(param_0, 0);
    _sumultiscore_entrypoint_12(temp + 0x4DC, param_1, 1);
}

s32 func_808013F8_chhoopswoop(Actor *param_0, s32 param_1, PairEventPayload param_2)
{
    switch (param_1) {
        case 0x2E:
            func_80801494_chhoopswoop(param_0, param_2.halves[0], param_2.halves[1]);
            break;
        case 0x30:
            return func_80801500_chhoopswoop(param_0, param_2.halves[0], param_2.halves[1]);
        case 0x3D:
            func_80800D28_chhoopswoop(param_0, -1);
            break;
        case 0x95:
            func_8080153C_chhoopswoop(param_0);
            break;
        default:
            return 0;
    }
    return 1;
}

int func_80801494_chhoopswoop(param_0, param_1, param_2) s32 param_0; s32 param_1; s32 param_2;
{
  switch (param_1)
  {
    case 0xCEC:
      func_808006A0_chhoopswoop();
      break;

    case 0x10CD:

    case 0x10CE:
      _subaddiemulti_entrypoint_2(param_0);
      if (param_0 && param_0)
    {
    }
      func_80101FDC(param_0, 6);
      _gcfrontend_entrypoint_10();

  }

}

s32 func_80801500_chhoopswoop(param_0, param_1, param_2) s32 param_0; s32 param_1; s32 param_2;
{
  s32 new_var;
  new_var = param_1;
  if (new_var == 0x10cd)
  {
    s32 local_0;
    local_0 = func_80100094(param_0, 0);
    ;
    ;
    return (*((s32 *) (((char *) local_0) + 8))) + 1;
  }
  return 0;
}

int func_8080153C_chhoopswoop(param_0) Actor *param_0;
{
    func_800BF744(1, 0);
    func_800BF744(2, 1);
    func_800BF544(0, 0, 0);
    if (((u32)(*(u16 *)((char *)(param_0) + 0x72)) >> 10) == 1)
    {
        _subaddiemulti_entrypoint_1(0, 0);
    }
}

void func_808015A4_chhoopswoop(param_0) Actor *param_0;
{
    u8 *local_1;
    s32 local_0[8];
    s32 local_2;
    s32 local_3;
    s32 local_4;
    s32 local_8;
    s32 local_5;
    s32 local_7;

    local_1 = func_80100094(param_0, 0);
    local_2 = -1;
    for (local_3 = 0; local_3 < _gcstatusDll_entrypoint_11(); local_3++) {
        local_0[local_3] = _sumultiscore_entrypoint_8(local_1 + 0x4DC, local_3, 7);
        if (local_2 < local_0[local_3]) {
            local_2 = local_0[local_3];
        }
        func_800AA20C(local_3, local_0[local_3]);
    }
    for (local_3 = 0; local_3 < _gcstatusDll_entrypoint_11(); local_3++) {
        if (local_2 == local_0[local_3]) {
            _sumultiscore_entrypoint_11(local_1 + 0x4DC, local_3, 7, 3.0f);
        }
    }
    for (local_4 = 1; local_4 < _gcstatusDll_entrypoint_11(); local_4++) {
        for (local_8 = local_4; local_8 > 0 && local_0[local_8 - 1] < local_0[local_8]; local_8--) {
            local_5 = local_0[local_8];
            local_0[local_8] = local_0[local_8 - 1];
            local_0[local_8 - 1] = local_5;
        }
    }
    func_800FC6B0(0x16);
    if (local_0[0] != local_0[1]) {
        for (local_8 = 0; _sumultiscore_entrypoint_8(local_1 + 0x4DC, local_8, 7) != local_0[0]; local_8++) {
        }
        *(s32 *)(local_1 + 8) = local_8;
        local_7 = 0x10CD;
    } else {
        local_7 = 0x10CE;
    }
    _subaddiemulti_entrypoint_1(0, 0);
    *(s32 *)(local_1 + 0xC) = local_7;
    *(s32 *)(local_1 + 0x10) = 6;
    *(f32 *)(local_1 + 0x9F8) = 3.0f;
    func_80101FDC(param_0, 4);
}

void func_808017C4_chhoopswoop(Actor *param_0)
{
    extern s32 func_800DC298(f32);
    extern f32 func_800DC178(f32, f32);
    f32 local_0;

    if (func_800DC298(0.5f)) {
        local_0 = 1.0f;
    } else {
        local_0 = -1.0f;
    }
    param_0->unk50 = func_800DC178(50.0f, 100.0f) * local_0;
    func_80801D8C_chhoopswoop(param_0);
}

void func_80801838_chhoopswoop(Actor *param_0)
{
    f32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;

    local_0 = func_800D8FF8();
    local_2 = func_800DA298(0);
    local_3 = 0;
    local_4 = 1;
    func_8010A800(param_0, (_subaddiefade_entrypoint_0(param_0) == 255) ? 1 : 0);
    local_1 = func_800D90A4(&param_0->unk58);
    if (!local_2 && func_800CEAD0(param_0->unk6C_0)) {
        param_0->unk64_20 = 1;
    }
    switch (param_0->unk70_10) {
    case 4: local_3 = func_800DA298(3); break;
    case 3: local_3 = func_800DA298(2); break;
    case 2: local_3 = func_800DA298(1); break;
    case 5:
        local_4 = 0;
        if (!_subaddiefade_entrypoint_0(param_0)) {
            func_80801DCC_chhoopswoop(param_0);
            func_800FFAB0(param_0);
            return;
        }
        break;
    }
    if (!local_2) func_80801AB4_chhoopswoop(param_0);
    param_0->rotation[2] = func_800136E4(param_0->rotation[2] + param_0->unk50 * local_0);
    if (local_4 && ((!local_2 && (local_1 != 0 || param_0->unk64_20)) || (local_2 && local_3))) {
        func_80801A10_chhoopswoop(param_0, 0x4F, local_1 != 0 && !local_2);
    }
}

int func_80801A10_chhoopswoop(actor, param_1, param_2) Actor *actor; s32 param_1; s32 param_2;
{
    if (param_1 == 0x4F) {
        if (((u32) *(u16 *)((char *)actor + 0x72) >> 0xA) != 5) {
            if (param_2 != 0) {
                func_8010D930(5, *(u32 *)((char *)actor + 0x70) & 1, (char *)actor + 4, &D_80801F98_chhoopswoop);
            }
            _subaddiefade_entrypoint_5(actor);
            func_80101FDC(actor, 5);
        }
        return 1;
    }
    return 0;
}

void func_80801A94_chhoopswoop()
{
    func_80101870();
}

s32 func_80801AB4_chhoopswoop(param_0) Actor *param_0;
{
    f32 local_0[3];
    s32 local_1;
    f32 local_4;
    s32 local_5;
    u8 *local_2;
    u8 *local_6;
    f32 local_3[3];
    u8 *local_7;

    local_2 = func_80100094(func_80106790(*(u32 *)((u8 *)param_0 + 0x3C)), 0);
    local_4 = func_80103F38(param_0, 0);
    if (param_0->unk64_20) return 0;
    local_6 = func_80100094(param_0, 0);
    for (local_5 = 0; local_5 < _gcstatusDll_entrypoint_11(); local_5++) {
        if (1) {}
        if (func_800F6438(local_5)) {
            local_7 = (u8 *)&((HsArr *)local_6)->arr[local_5];
            func_800F5A00(local_5, local_0);
            local_0[1] += 50.0f;
            func_800EF3DC(local_0, param_0->position);
            if (*(s32 *)(local_7 + 0x20) && func_800EEFD4(local_0) < local_4 * local_4) {
                func_800EFA4C(local_3, 0.0f, 0.0f, 1.0f);
                func_800EF934(local_3, local_3, *(f32 *)((u8 *)param_0 + 0x48));
                local_1 = (func_800EEAA4(local_0, local_3) >= 0) ? 1 : -1;
                if (local_1 == -*(s32 *)local_7) {
                    local_7 = (u8 *)(*(s32 *)(local_6 + 0x40) + 1);
                    if (func_800D3948()) {
                        _sumultiscore_entrypoint_7(local_2 + 0x4DC, local_5, 7, (s32)local_7);
                    } else {
                        *(s32 *)(local_2 + 4) += (s32)local_7;
                        func_80801D20_chhoopswoop(param_0, 0x9E2, 0xA);
                    }
                    param_0->unk64_20 = 1;
                    _chscorepoints_entrypoint_2((s32)local_7, local_5, param_0->position, 1);
                    return 1;
                }
            }
            *(s32 *)(local_7 + 0x20) = 1;
            *(s32 *)local_7 = local_1;
        }
    }
    return 0;
}

void func_80801D20_chhoopswoop(param_0, param_1, param_2) s32 param_0; s32 param_1; s32 param_2;
{
    s32 local_0;
    s32 *local_1 = &D_80801FB0_chhoopswoop;
    local_0 = func_800B53A4(param_2);
    func_800BABB8(local_0, param_0 + 4, param_0 + 4, 0x3F800000, local_1);
    func_800BA3FC(local_0, param_1);
    func_800BA22C(local_0, param_2);
}

int func_80801D8C_chhoopswoop(param_0) Actor *param_0;
{
  func_8010D930(4, (*(s32 *)((char *)(param_0) + 0x70)) & 1, (char *)(param_0) + 4, &D_80801FDC_chhoopswoop);
}

int func_80801DCC_chhoopswoop(param_0) Actor *param_0;
{
  Actor *new_var;
  s32 local_0;
  s32 *local_1 = (s32 *) (((char *) param_0) + 0x3C);
  new_var = param_0;
  local_0 = func_80106790(*local_1);
  if ((*((s32 *) (((char *) new_var) + 0x2C))) != (-1))
  {
    u8 *local_2 = func_80100094(local_0, 0);
    s32 *local_3;
    *((u8 *) (((char *) (local_2 + ((*((s32 *) (((char *) new_var) + 0x2C))) * 0xC))) + ((0, 0x15)))) &= ~1U;
    *((f32 *) ((((char *) local_2) + ((*((s32 *) (((char *) param_0) + 0x2C))) * 0xC)) + 0x1C)) = 5.0f;
  }
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/hoopswoop.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80801EC0_chhoopswoop -> int[], D_80801F08_chhoopswoop -> int[], D_80801F50_chhoopswoop -> int[], D_80801F98_chhoopswoop -> int[], D_80801FB0_chhoopswoop -> int[] */
int D_80801EC0_chhoopswoop[18] = { 0x2B70355, 0x1, 0x0, (u32)func_8080016C_chhoopswoop, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x0, 0x0, (u32)func_80800620_chhoopswoop, 0x0, 0x9FC0000, (u32)func_80800024_chhoopswoop, (u32)func_80107C2C, -0x7FFFF9FE, (u32)func_80800320_chhoopswoop, 0x0 };
int D_80801F08_chhoopswoop[18] = { 0x2B7044A, -0xFFFF, 0x0, (u32)func_808011DC_chhoopswoop, (u32)func_80105834, (u32)func_808013C4_chhoopswoop, 0x0, 0x0, 0x0, 0x400400, (u32)func_80800620_chhoopswoop, 0x0, 0x9FC0000, (u32)func_80801130_chhoopswoop, (u32)func_80107C2C, -0x7FFFFBFE, (u32)func_808013F8_chhoopswoop, 0x0 };
int D_80801F50_chhoopswoop[18] = { 0x2B80356, 0x1, 0x0, (u32)func_80801838_chhoopswoop, (u32)func_80105834, (u32)func_80801A94_chhoopswoop, 0x0, 0x0, 0x0, 0x804, 0x0, 0x0, 0x440000, (u32)func_808017C4_chhoopswoop, (u32)func_80107C2C, -0x7FFFFF7E, (u32)func_80801A10_chhoopswoop, 0x0 };
int D_80801F98_chhoopswoop[6] = { 0x1304EE, 0xD0119, 0x1330016, 0x46500001, 0x3200640, 0x0 };
int D_80801FB0_chhoopswoop[11] = { 0x161000, 0x150000, 0xCC002B, 0xC00100, 0x22004C, 0x590026, 0x33002D, 0x1900258, 0xD0014, 0x1BFCE0, -0x2580000 };
u8 D_80801FDC_chhoopswoop[36] = { 0x0, 0x13, 0x4, 0xED, 0x0, 0xD, 0x1, 0x19, 0x1, 0x33, 0x0, 0x16, 0x46, 0x50, 0x0, 0x1, 0x3, 0x20, 0x6, 0x40, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
