#include "common.h"

extern s32 D_801245D0;
extern s32 D_801245E4;
extern s32 D_801245F8;
typedef struct { u8 pad00[0x5C]; u8 health[3]; } LocalHealth;
typedef struct { void *data; void *bones; u8 pad08[0x12]; u16 id : 11; u16 pad1A : 5; u8 pad1C[8]; u32 kind : 10; u32 pad24 : 22; } LocalMarker_80108F08;
extern s32 _glhittableDll_entrypoint_10(s32);
extern s32 _glhittableDll_entrypoint_7(s32);
extern s32 _glhittableDll_entrypoint_9(s32);
extern s32 _glhittableDll_entrypoint_6(s32);
extern s32 _glhittableDll_entrypoint_8(s32);
extern void *func_80100368(Actor *);
extern s32 func_800F70EC(s32);
extern s32 func_800F6C1C(s32);
extern s32 func_80102FA0(void *, u32);
extern void func_800EC398(LocalMarker_80108F08 *, f32 *);
extern f32 func_800F1DF4(f32 *, f32 *);
extern void _chbounce_entrypoint_3(f32);
extern void _chbounce_entrypoint_2(f32);
extern void _chbounce_entrypoint_5(s32, Actor *);
extern void _chflamer_entrypoint_1(Actor *, LocalMarker_80108F08 *);
extern void _chfreezy_entrypoint_1();
extern void func_800EC370();
extern f32 func_8010CD28(Actor *);
extern void func_800EE904(s32 *, f32 *);
extern void func_800DBEFC(void *, s32, f32 *);
extern void func_800EB860();
extern void func_800EB874(void);
extern void _chbaddiesetup_entrypoint_10(void);
extern void _chbaddiesetup_entrypoint_5(void (*)(void), s32, s32, s32, s32, s32);
extern f32 func_800EC708(LocalMarker_80108F08 *);
extern s32 _gccubesearch_entrypoint_16(s32 *, void **, s32 **, s32, s32);
extern void func_800EE88C(f32 *, s32 *);
extern void func_800C4B7C(s32);
extern void func_8010D930(s32, s32, f32 *, void *);
extern u8 D_8012460C[];
extern void _subaddiejoy_entrypoint_10(Actor *, f32, f32);
extern void func_800BBCB8(s32, s32, f32, s32, void *);
extern u8 D_8012461C[];
extern s32 D_8012464C;
extern u8 D_801245A0[];
typedef struct { u8 pad[0x24]; u32 kind:10, unused:22; } LocalMarker_80109538;
extern s32 _subaddiecustomhits_entrypoint_4(void *, f32 *, s32);
extern void func_800EE7F8(f32 *, f32 *);
extern s32 func_800B53A4();
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern f32 D_80124688[];
extern f32 func_800DC178(f32, f32);
extern u8 func_800DC128(s32, s32);
extern void func_800B4470(f32 *, f32 *, f32 *, s32, f32, f32, s32, s32, s32);
typedef struct local_marker local_marker;
typedef struct {u8 local_0[12]; s32 (*local_1)(local_marker *, f32 *, f32, f32 *, u32);} local_info;
struct local_marker {
    u8 local_0[12]; local_info *(*local_1)(void); u8 local_2[8];
    u32 local_3:11; u32 local_4:4; u32 local_5:12; u32 local_6:4; u32 local_7:1;
};
extern f32 func_800EC75C(local_marker *, f32 *);
extern void func_800EF3DC(f32 *, f32 *);
extern f32 func_800EEFD4(f32 *);
typedef struct Marker1099D0 Marker1099D0;
struct Marker1099D0 { u8 pad[0x14]; u16 local_0; u8 pad1[2]; u16 local_1; u8 pad2[10]; u32 local_2; u32 pad3:22; u32 local_3:1; u32 pad4:9; };
typedef struct { Marker1099D0 *local_0; s32 pad; u32 pad1:27; u32 local_1:1; u32 pad2:3; u32 local_2:1; } Entry1099D0;
typedef struct { u8 pad[0x64]; union { struct { u32 pad:14; u32 local_0:1; u32 pad1:17; } local_0; struct { u16 pad; u16 local_0; } local_1; } local_0; u8 pad1[11]; u8 local_1; } Actor1099D0_801099D0;
typedef struct { u8 pad[0x10]; s32 (*local_0)(Marker1099D0 *, Marker1099D0 *); } Handler1099D0;
extern void **func_800BE444();
extern s32 func_800CB854(s32);
extern Entry1099D0 *func_800E9E88(void *);
extern Entry1099D0 *func_800E9EB4(void *);
extern Actor1099D0_801099D0 *func_80106790(Marker1099D0 *);
extern Handler1099D0 *func_800EC3C4(Marker1099D0 *);
extern s32 _glhittableDll_entrypoint_1(Marker1099D0 *, Marker1099D0 *);
extern void func_800EB210(Marker1099D0 *, Marker1099D0 *, s32);
typedef struct {u8 local_0[0x24]; u32 local_1:10; u32 local_2:22;} local_type;
typedef struct { u8 pad[0x64]; union { struct { u32 pad:14; u32 local_0:1; u32 pad1:17; } local_0; struct { u16 pad; u16 local_0; } local_1; } local_0; u8 pad1[11]; u8 pad2:6; u8 local_1:1; u8 pad3:1; } Actor1099D0_80109CC4;
typedef struct LocalMarker_8010A01C { u8 pad00[0x14]; u16 id; u8 pad16[2]; u16 flags18; u8 pad1A[0xA]; u32 kind:10, pad24:22; u32 pad28:22, enabled:1, tail28:9; } LocalMarker_8010A01C;
typedef struct LocalEntry { LocalMarker_8010A01C *marker; u32 unknown; u32 pad08:27, selected:1, tail08:3, valid:1; } LocalEntry;
typedef struct LocalActor { u8 pad00[0x64]; union { struct {u32 upper:14, disabled:1, lower:17;} bits; struct {u16 upper, mask;} halves; } flags; u8 pad68[0x2C]; u32 upper94:14, enabled:1, lower94:17; } LocalActor;
extern s32 func_8010108C(Actor *, s32, s32);
extern Unk80132ED0 *func_80101080(void);
extern f32 func_800F0C68(f32 *, f32 *, f32, f32);
extern void func_80103DFC(Actor *, f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern s32 func_800F0BD0(f32 *, f32 *, f32, f32);
extern f32 func_800EEB40(f32 *, f32 *);
extern u8 D_8012762C;
int func_800DC298(f32 param_0);
int func_80102F74(int param_0, int param_1);
typedef struct { u8 pad0[8]; u32 f0 : 28; u32 bit : 1; u32 f2 : 3; } S2_10A654;
typedef struct { S2_10A654 *unk0; } S1_10A654;
int func_80109600();
void func_80109748(f32 *param_0, s32 param_1, s32 param_2, s32 param_3, f32 param_4, s32 param_5, s32 param_6, s32 param_7);
int func_8010A430();
int func_8010A610();

int func_80108ED0()
{
  return (int)&D_801245D0;
}

int func_80108EDC()
{
  return (int)&D_801245E4;
}

int func_80108EE8()
{
  return (int)&D_801245F8;
}

func_80108EF4(u16 *param_0, u16 param_1) {
    return param_0[4] == 0x23A;
}

void func_80108F08(LocalMarker_80108F08 *param_0, LocalMarker_80108F08 *param_1, s32 param_2)
{
    Actor *local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    void *local_5;
    s32 local_6;
    s32 local_7;
    s32 local_8;
    f32 local_9;
    f32 local_10[3];
    s16 local_11[3];
    f32 local_12;
    f32 local_13[3];
    void *local_14;
    s32 *local_15;
    s32 local_16[3];
    f32 local_17;
    f32 local_18;

    local_0 = func_80106790(param_0);
    local_1 = _glhittableDll_entrypoint_10(param_2);
    local_2 = _glhittableDll_entrypoint_7(param_2);
    local_3 = _glhittableDll_entrypoint_9(param_2);
    local_4 = _glhittableDll_entrypoint_6(param_2);
    local_5 = func_80100368(local_0);
    local_6 = param_1->kind == 0;
    if (local_6) {
        local_7 = param_1->id;
        if (!func_800F70EC(local_7) || !func_800F6C1C(local_7)) {
            if (_glhittableDll_entrypoint_8(param_2)) return;
        }
    }
    if (!local_4) {
        if (!local_3 && param_1->kind) return;
        if (local_3 <= 0) local_3 = 1;
    }
    if (local_3) {
        local_8 = func_80102FA0(local_5, 0x80000020) ? local_3 : 100 / local_3;
        local_6 = ((LocalHealth *)local_0)->health[local_4] - local_8;
        local_8 = local_6 < 0 ? 0 : local_6;
        if ((((LocalHealth *)local_0)->health[local_4] = local_8) && local_3 >= 2) local_2 /= 2;
    }
    if (local_2) {
        func_800EC398(param_1, local_10);
        local_9 = func_800F1DF4(local_10, local_0->position);
        _chbounce_entrypoint_3(local_9);
        _chbounce_entrypoint_2(local_9);
        if (local_0->unk64_25) _chbounce_entrypoint_5(local_2 + 10, local_0);
        else _chbounce_entrypoint_5(local_2 + 5, local_0);
    }
    if (local_3) {
        switch (local_4) {
        case 2:
            if (func_80102FA0(local_5, 0x2000000)) func_80109600(local_0, param_1);
            break;
        case 1:
            if (func_80102FA0(local_5, 0x1000000)) func_80109600(local_0, param_1);
            break;
        }
        if (func_80102FA0(local_5, 0x80020000) && param_1->kind == 0x26D) {
            _chflamer_entrypoint_1(local_0, param_1);
        }
        if (func_80102FA0(local_5, 0x200) && param_1->kind == 0x26E) {
            func_800EC370(param_1, local_11);
            _chfreezy_entrypoint_1(local_0, local_11);
        }
        if (!((LocalHealth *)local_0)->health[local_4] || (local_4 && func_80102FA0(local_5, 0x10000))) {
            if (((LocalHealth *)local_0)->health[local_4]) local_4--;
            if (local_4 != 2) ((LocalHealth *)local_0)->health[local_4] = 99;
            if (local_4 == 2 && local_1 && func_8010A430(local_0)) {
                local_12 = func_8010CD28(local_0) + 180.0f;
                func_800EE904(local_16, local_0->position);
                if (param_0->bones) func_800DBEFC(param_0->bones, 14, local_13);
                func_800EB860(func_80108EF4, local_0);
                if (param_0->bones && !(local_13[0] == 0.0f && local_13[1] == 0.0f && local_13[2] == 0.0f)) {
                    _chbaddiesetup_entrypoint_5(_chbaddiesetup_entrypoint_10, local_1 + 2, *(s32 *)&local_13[0], *(s32 *)&local_13[1], *(s32 *)&local_13[2], *(s32 *)&local_12);
                } else if (func_80102FA0(local_5, 0x81000000) && _gccubesearch_entrypoint_16(local_16, &local_14, &local_15, 3, (s32)(local_18 = func_800EC708(param_0) * 4.0f))) {
                    func_800EE88C(local_13, local_15);
                    _chbaddiesetup_entrypoint_5(_chbaddiesetup_entrypoint_10, local_1 + 2, *(s32 *)&local_13[0], *(s32 *)&local_13[1], *(s32 *)&local_13[2], *(s32 *)&local_12);
                } else {
                    local_17 = local_0->position[1] + func_800EC708(param_0);
                    _chbaddiesetup_entrypoint_5(_chbaddiesetup_entrypoint_10, local_1 + 2, *(s32 *)&local_0->position[0], *(s32 *)&local_17, *(s32 *)&local_0->position[2], *(s32 *)&local_12);
                }
                func_800EB874();
            }
            func_800EB210(param_0, param_1, local_4);
        }
        if (local_4 && local_2) {
            func_800C4B7C(local_0->unk6C_9 == 0x31E ? 0x41F : 0x415);
            func_8010D930(1, (*(u32 *)((u8 *)local_0 + 0x70)) & 1, local_0->position, D_8012460C);
            if (func_80102FA0(local_5, 0x2000000) || func_80102FA0(local_5, 0x1000000)) {
                _subaddiejoy_entrypoint_10(local_0, 1.0f, 0.25f);
            }
        }
    }
}

void func_801094E0(s32 param_0, f32 param_1) {
    func_800BBCB8(param_0, param_0, param_1, 3, D_8012461C);
}

int func_80109518()
{
    return (int)&D_8012464C;
}

int func_80109524(s32 param_0)
{
  s16 *new_var;
  new_var = &D_801245A0[param_0 << 4];
  return *new_var;
}

void func_80109538(void *param_0, f32 *param_1, LocalMarker_80109538 *param_2, s32 param_3)
{
    f32 local_0[3];
    s32 local_1;
    s32 local_2;
    if (!_subaddiecustomhits_entrypoint_4(param_0, local_0, 0)) func_800EE7F8(local_0, param_1);
    if (param_2 != NULL) {
        local_1 = param_2->kind == 0 ? 0 : 1;
    } else {
        local_1 = 0;
    }
    if (param_3) {
        local_2 = func_800B53A4(10, local_1);
        func_800BA3FC(local_2, func_80109524(local_1));
        func_800BABB8(local_2, local_0, local_0, 1.0f, func_80109518());
    }
    func_801094E0(local_0, 1.0f);
}

int func_80109600(param_0, param_1) s32 param_0; s32 param_1;
{
  f32 local_0[3];
  func_80103DFC(param_0, local_0);
  func_80109538(param_0, local_0, param_1, 1);
}

s32 func_8010963C(s32 param_0, s32 param_1, s32 param_2){
    func_80109538(param_0, param_1, param_2, 1);
}

void func_8010965C(s32 param_0)
{
    f32 local_1[3];
    s32 local_0;

    local_0 = _subaddiecustomhits_entrypoint_4(param_0, local_1, 0);
    if (local_0 != 0)
    {
        local_0 = func_800B53A4(0xA);
        func_800BA3FC(local_0, func_80109524(2));
        func_800BABB8(local_0, local_1, local_1, 1.0f, func_80109518());
    }
}

int func_801096C8(s32 param_0, s32 param_1)
{
  f32 local_0[3];
  func_80103DFC(param_0, local_0);
  func_80109538(param_0, local_0, param_1, 0);
}

void func_80109704(s32 param_0, s32 param_1, s32 param_2, s32 param_3, f32 param_4, s32 param_5, s32 param_6, s32 param_7) {
    func_80109748(param_0 + 4, param_1, param_2, param_3, param_4, param_5, param_6, param_7);
}

void func_80109748(f32 *param_0, s32 param_1, s32 param_2, s32 param_3, f32 param_4, s32 param_5, s32 param_6, s32 param_7) {
    f32 local_0[3];
    f32 local_1[3];
    s32 local_2;
    s32 local_3;
    local_1[0] = param_0[0];
    local_1[2] = param_0[2];
    for (local_2 = 0; local_2 < param_1; local_2++) {
        local_1[1] = param_0[1] + func_800DC178(param_2, param_3);
        local_0[1] = func_800DC178(4.0f, 10.0f);
        local_0[0] = func_800DC178(-8.0f, 8.0f);
        local_0[2] = func_800DC178(-8.0f, 8.0f);
        local_3 = func_800DC128(param_6, param_7);
        func_800B4470(local_1, local_0, D_80124688, 1, param_4, 50.0f, param_5, local_3, 0);
    }
}

s32 func_801098D0(f32 *param_0, f32 param_1, local_marker *param_2) {
    f32 local_0[3];
    f32 local_1;
    local_info *local_2;
    f32 local_3[3];
    s32 local_4;
    if (param_2->local_1) {
        local_2 = param_2->local_1();
        if (local_2->local_1) {
            local_4 = local_2->local_1(param_2, param_0, param_1, local_3, param_2->local_6);
            if (local_4) {
                param_2->local_4 = local_4;
                return 1;
            }
            return 0;
        }
    }
    local_1 = func_800EC75C(param_2, local_0) + param_1;
    func_800EF3DC(local_0, param_0);
    return func_800EEFD4(local_0) < local_1 * local_1 ? 1 : 0;
}

s32 func_801099D0(f32 *param_0, f32 param_1, s32 param_2, s32 (*param_3)(Actor1099D0_801099D0 *, void *), void *param_4, Marker1099D0 *param_5) {
    s32 local_8;
    void **local_0;
    Entry1099D0 *local_1, *local_2;
    Marker1099D0 *local_3;
    Actor1099D0_801099D0 *local_4;
    Handler1099D0 *local_5;
    s32 local_6 = 0;
    u32 local_7;
    local_0 = func_800BE444(param_0);
    local_7 = func_800CB854(0) ? 1 << (func_800CB854(0) - 1) : 0;
    for (; *local_0; local_0++) {
        local_1 = func_800E9E88(*local_0);
        local_2 = func_800E9EB4(*local_0);
        for (; local_1 < local_2; local_1++) {
            if (!local_1->local_1 || !local_1->local_2) continue;
            local_3 = local_1->local_0;
            if (local_3 == param_5 || !local_3->local_3 || !(local_3->local_1 & 1)) continue;
            if (local_3->local_0 == 0 || local_3->local_0 == 0xFFFF) continue;
            local_4 = func_80106790(local_3);
            if (local_4->local_0.local_0.local_0 || (local_4->local_0.local_1.local_0 & local_7)) continue;
            if (param_3 && !param_3(local_4, param_4)) continue;
            if (!func_801098D0(param_0, param_1, local_3)) continue;
            local_5 = func_800EC3C4(local_3);
            if (local_5->local_0 && !local_5->local_0(local_3, param_5)) continue;
            local_6 = 1;
            if (!_glhittableDll_entrypoint_1(param_5, local_3)) func_800EB210(local_3, param_5, param_2);
        }
    }
    return local_6;
}

void func_80109BEC(s32 p0, f32 p1, s32 p2, s32 p3, s32 p4, s32 p5) {
    func_801099D0(p0, p1, p2, p3, p4, p5);
}

void func_80109C20(s32 p0, f32 p1, s32 p2, s32 p3) { func_801099D0(p0,p1,p2,p3,0,0); }

void func_80109C4C(s32 param_0, f32 param_1, s32 param_2, s32 param_3, s32 param_4, local_type *param_5, s32 param_6) {
    f32 local_1 = param_1;
    u32 local_0;
    local_0 = param_5->local_1;
    param_5->local_1 = param_6;
    func_801099D0(param_0, local_1, param_2, param_3, param_4, param_5);
    param_5->local_1 = local_0;
}

s32 func_80109CC4(f32 *param_0, f32 param_1, Marker1099D0 *param_2) {
    s32 local_8;
    void **local_0;
    Entry1099D0 *local_1, *local_2;
    Marker1099D0 *local_3;
    Actor1099D0_80109CC4 *local_4;
    Handler1099D0 *local_5;
    s32 local_6 = 0;
    u32 local_7;
    local_0 = func_800BE444(param_0);
    local_7 = func_800CB854(0) ? 1 << (func_800CB854(0) - 1) : 0;
    for (; *local_0; local_0++) {
        local_1 = func_800E9E88(*local_0);
        local_2 = func_800E9EB4(*local_0);
        for (; local_1 < local_2; local_1++) {
            if (!local_1->local_1 || !local_1->local_2) continue;
            local_3 = local_1->local_0;
            if (local_3 == param_2 || !local_3->local_3 || !(local_3->local_1 & 1)) continue;
            if (local_3->local_0 == 0 || local_3->local_0 == 0xFFFF) continue;
            if ((local_3->local_2 >> 22) == (param_2->local_2 >> 22)) continue;
            local_4 = func_80106790(local_3);
            if (local_4->local_0.local_0.local_0 || (local_4->local_0.local_1.local_0 & local_7)) continue;
            if (!func_801098D0(param_0, param_1, local_3)) continue;
            local_5 = func_800EC3C4(local_3);
            if (local_5->local_0 && !local_5->local_0(local_3, param_2)) continue;
            local_6 = 1;
            local_4->local_1 = 1;
            if (!_glhittableDll_entrypoint_1(param_2, local_3)) func_800EB210(local_3, param_2, 1);
        }
    }
    return local_6;
}

int func_80109EE0(u16 *param_0, unsigned long param_1)
{
  return *(u16*)((s8*)param_0 + 102) & param_1;
}

void func_80109EEC(void *param_0, unsigned int param_1)
{
  ((s16 *) param_0)[0x33] = param_1;
}

int func_80109EF4(u16 *param_0, unsigned long param_1)
{
  param_0[0x33] &= ~param_1;
}

int func_80109F08(u16 *param_0, unsigned int param_1)
{
  param_0[0x33] |= param_1;
}

int func_80109F18(s32 param_0, s32 *param_1)
{
  int new_var2;
  s32 **new_var;
  new_var = &param_1;
  new_var2 = 0xFFFFFFFFFFFFFFFF;
  func_8010114C(param_0, ((((((0x3E & new_var2) & new_var2) & new_var2) & new_var2) & new_var2) & new_var2) & new_var2, *new_var);
}

int func_80109F40(s32 param_0, s32 volatile param_1)
{
  func_8010114C(param_0, 0x3F, param_1);
}

int func_80109F68(s32 param_0, s32 volatile param_1)
{
  func_8010114C(param_0, 0x40, param_1);
}

int func_80109F90(s32 param_0, s32 volatile param_1)
{
  func_8010114C(param_0, 0x41, param_1);
}

int func_80109FB8(s32 param_0, s32 param_1)
{
  extern s32 D_80109FB8_unk3A;
  typedef struct 
  {
    char pad[58];
    s32 unk3A;
  } Actor;
  Actor *local_0;
  local_0 = (Actor *) func_80106790((Marker1099D0 *) param_1);
  if (!param_1)
  {
  }
  local_0->unk3A = param_0;
}

void func_80109FE8(u8 **param_0, s32 param_1)
{
  u8 *new_var;
  u8 *temp_v0;
  u8 *temp_v0_2;
  if (param_1 != 0)
  {
    temp_v0 = *param_0;
    new_var = (u8 *) (((s8 *) temp_v0) + 0x1B);
    *((u8 *) (((s8 *) temp_v0) + 0x1B)) = (u8) ((*new_var) & 0xFFFE);
    return;
  }
  temp_v0_2 = *param_0;
  *((u8 *) (((s8 *) temp_v0_2) + 0x1B)) = (u8) (((*((u8 *) (((s8 *) temp_v0_2) + 0x1B))) & 0xFFFF) | 1);
}

LocalMarker_8010A01C *func_8010A01C(f32 *param_0, f32 *param_1, f32 param_2, f32 param_3, s32 param_4)
{
    void **local_0;
    s32 local_1;
    f32 local_2;
    f32 local_3;
    f32 local_4[3];
    s32 local_5;
    LocalActor *local_6;
    LocalEntry *local_7;
    LocalEntry *local_8;
    f32 *local_9;
    f32 local_10;
    LocalMarker_8010A01C *local_11;
    LocalMarker_8010A01C *local_12;
    f32 local_13[3];
    f32 local_14[3];
    f32 local_15[3];
    u16 local_16;

    local_0 = func_800BE444();
    if (func_800CB854(0)) local_1 = 1 << (func_800CB854(0) + 0x1F);
    else local_1 = 0;
    func_800EE7F8(local_4, param_1);
    local_3 = func_800F0C68(param_0, local_4, param_2, param_3);
    local_2 = 1e+08f;
    local_12 = 0;
    while (*local_0) {
        local_7 = func_800E9E88(*local_0);
        local_8 = func_800E9EB4(*local_0);
        for (; local_7 < local_8; local_7++) {
            if (!(local_7->selected && local_7->valid)) continue;
            local_11 = local_7->marker;
            if (!(!(param_4 + 1) || param_4 == (s32)local_11->kind) || !local_11->enabled) continue;
            local_16 = local_11->id;
            if (!(local_16 && local_16 != 0xFFFF && (local_11->flags18 & 1))) continue;
            local_6 = (LocalActor *)func_80106790((Unk80132ED0 *)local_11);
            if (!local_6->enabled) continue;
            if (local_6->flags.bits.disabled || (local_6->flags.halves.mask & local_1)) continue;
            local_5 = func_8010108C((Actor *)local_6, 0xA2, 0);
            if (local_5 > 0) {
                local_9 = (f32 *)func_80101080();
            } else {
                func_80103DFC((Actor *)local_6, local_13);
                local_9 = local_13;
                local_5 = 1;
            }
            while (local_5--) {
                func_800EE7F8(local_14, local_9);
                func_800EFB24(local_15, local_14, param_0);
                local_10 = func_800EEFD4(local_15);
                if (local_10 < local_2 && func_800F0BD0(local_15, local_4, param_2, local_3)) {
                    local_2 = local_10;
                    local_12 = local_11;
                }
                local_9 += 3;
            }
        }
        local_0++;
    }
    return local_12;
}

void func_8010A2FC(void **param_0, f32 *param_1, f32 *param_2)
{
    s32 local_0;
    f32 *local_2;
    f32 local_3;
    f32 local_1[3];
    f32 local_4;
    local_0 = func_8010108C(param_0, 0xA2, 0);
    if (local_0 > 0) {
        local_2 = func_80101080();
        local_3 = 1e+08f;
        while (local_0--) {
            func_800EE7F8(local_1, local_2);
            local_4 = func_800EEB40(local_1, param_2);
            if (local_4 < local_3) {
                func_800EE7F8(param_1, local_1);
                local_3 = local_4;
            }
            local_2 += 3;
        }
    } else func_800EC75C(*param_0, param_1);
}

void func_8010A3E8(Actor *param_0, f32 param_1) {
    s16 local_0;
    local_0 = 256.0f * param_1;
    *(s16 *)((char *)param_0 + 0x92) = local_0;
}

f32 func_8010A40C(u8 *param_0)
{
  f32 local_0;
  s16 local_1;
  ;
  ;
  return ((f32) (*((s16 *) (param_0 + 0x92)))) * 0.00390625f;
}

int func_8010A430(param_0) int param_0;
{
    if (func_80102F74(param_0, 0x8000) != 0)
        return 1;
    switch (D_8012762C - 0xF)
    {
    case 4: return func_800DC298(1.0f);
    case 1: return func_800DC298(0.8999939f);
    case 0: return func_800DC298(0.7999878f);
    case 3: return func_800DC298(0.69999695f);
    case 5: return func_800DC298(0.59999084f);
    case 6: return func_800DC298(0.5f);
    case 7: return func_800DC298(0.3999939f);
    case 8: return func_800DC298(0.2999878f);
    case 9: return func_800DC298(0.19999695f);
    case 10: return func_800DC298(0.099990845f);
    case 11: return func_800DC298(0.8999939f);
    case 2: break;
    }
    return 1;
}

s32 func_8010A5B0();

void func_8010A570(s32 arg0)
{
    func_8010A5B0(arg0,0);
}

void func_8010A590(s32 arg0)
{
    func_8010A5B0(arg0,1);
}

s32 func_8010A5B0(u8 **param_0, s32 param_1)
{
  s32 local_0;
  u8 *local_1;
  u8 *local_2;
  u8 **new_var;
  local_0 = func_8010A610();
  new_var = &(*param_0);
  if (param_1 != 0)
  {
    local_1 = *new_var;
    *((u8 *) (((s8 *) local_1) + 0x2A)) = (u8) ((*((u8 *) (((s8 *) (*param_0)) + 0x2A))) | 2);
  }
  else
  {
    local_2 = *param_0;
    *((u8 *) (((s8 *) local_2) + 0x2A)) = (u8) ((*((u8 *) (((s8 *) local_2) + 0x2A))) & 0xFFFD);
  }
  return local_0;
}

int func_8010A610(param_0) void *param_0; {

    return ((u32)(*(s32 *)((char *)((*(s32 **)((char *)param_0 + 0x0))) + 0x28)) << 0x16) >> 31;
}

void func_8010A624(param_0)
void *param_0;
{
  void *local_0;
  local_0 = param_0;
  ;
  ((u8 *) (*((void **) (*((void **) local_0)))))[0xb] &= ~8U;
}

void func_8010A63C(void *param_0)
{
  typedef struct {
    u8 pad_0[0xB];
    u8 local_1 : 4;
    u8 local_0 : 1;
    u8 local_2 : 3;
  } Struct8010A63C_0;
  typedef struct {
    Struct8010A63C_0 *local_0;
  } Struct8010A63C_1;
  typedef struct {
    Struct8010A63C_1 *local_0;
  } Struct8010A63C_2;

  ((Struct8010A63C_2 *)param_0)->local_0->local_0->local_0 = 1;
}

s32 func_8010A654(S1_10A654 **param_0, s32 param_1) {
    S2_10A654 *p = (*param_0)->unk0;
    s32 old = p->bit;
    if (param_1 != 0) { p->bit = 1; }
    else { p->bit = 0; }
    return old;
}

u32 func_8010A698(u8 ***param_0) {
    return (u32) ((*(s32 *)((s8 *)(**param_0) + (8))) << 0x1C) >> 0x1F;
}

int func_8010A6B0(s32 param_0, s32 param_1)
{
  f32 local_2[3];
  f32 local_1[3];
  f32 local_3[3];
  if (!func_800F4B4C(param_1))
  {
    return 0;
  }
  func_800F57F0(param_1, local_1);
  func_80103DFC(param_0, local_2);
  if (func_800C6A7C(local_1, local_2, local_3, 0x4A0021) != 0)
  {
    return 0;
  }
  return 1;
}
