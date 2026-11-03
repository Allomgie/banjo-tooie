#include "common.h"
#include "core2/anctrl.h"

extern void *func_80100094(Actor *, s32);
extern s32 func_800DA564(s32, s32);
extern void func_800DA7A8(s32, s32, s32);
typedef struct { u16 local_0; u8 pad_0[6]; } FlySaucerRecord;
typedef struct { u8 pad_0[0x2A]; s16 local_0; } FlySaucerData;
extern void _capod_entrypoint_2(Unk80132ED0 *, s32, s32);
extern void _capod_entrypoint_6(s32, s32, s32);
extern s16 D_808045DA_chflysaucer[];
typedef struct { u8 pad_0[0x26]; u8 local_0; } SaucerCourse;
extern void _suspline_entrypoint_20(Actor *, s32, s32, s32, s32, s32);
extern f32 *_suspline_entrypoint_10(void *, s32);
extern f32 *_suspline_entrypoint_11(void *, s32);
extern void func_800A5800();
extern void func_800EE7F8(f32 *, f32 *);
extern void _cadbfunc_entrypoint_0(f32 *);
extern void _cadbfunc_entrypoint_2(f32 *);
extern void _cadbfunc_entrypoint_10(f32 *);
extern void _cadbfunc_entrypoint_12(f32 *);
extern void _cadbfunc_entrypoint_14(f32 *);
extern void _cadbfunc_entrypoint_29(s32, s32 *);
extern void _suspline_entrypoint_0(void *, s32, s32);
extern void _cadbfunc_entrypoint_16();
extern void func_800F0EF0(s32, f32 *);
extern void func_8010FD38(s32, f32);
extern s32 func_80104200();
typedef struct { u8 pad[0x74]; u32 a : 11; u32 f : 1; u32 b : 20; } Fs74;
extern void func_800BF4A4();
extern void func_800EF04C(f32 *, f32 *);
extern void func_800EF334(f32 *, f32);
extern f32 _suspline_entrypoint_6(void *);
extern void _suspline_entrypoint_8(void *, f32);
extern Actor *func_80106790(Unk80132ED0 *);
extern s16 D_808045E8_chflysaucer[];
extern void func_8008FB10(s32, f32, f32, f32);
extern f32 D_80804274_chflysaucer[];
extern s16 D_80804624_chflysaucer[];
extern s32 _suspline_entrypoint_2(void *, f32);
extern s16 D_80804634_chflysaucer[];
extern s32 func_800C4350(u8, f32 *, s16 *);
extern void func_800C31DC(u8, f32);
typedef struct { u8 pad_0[0x2C]; u8 local_0; u8 local_1; } SaucerSound1581;
extern f32 D_8080465C_chflysaucer[];
extern s16 D_80804648_chflysaucer[];
extern void func_800C4B64(f32);
extern void func_800C2FDC();
typedef struct { u8 pad0[0x10]; f32 unk10; u8 pad14[8]; f32 unk1C; u8 pad20[4]; u8 unk24; } SaucerCam;
extern s32 func_800F54E4(void);
extern void func_800F81D4(s32, f32 *);
extern void func_800EF6A8(f32 *, f32 *, f32, f32, f32);
extern void func_800EF4E4(f32 *, f32, f32, f32, f32, f32);
extern void func_800906B0(f32 *);
extern void func_800906DC(f32 *);
extern u8 func_800D731C(u16);
extern void func_800DBE60(u8, s32, s32);
extern void *func_800B27E0(s32);
extern void *func_800AE080(s32);
extern void func_800AE630(void *, void *, s32, f32 *);
extern f32 func_800F1828(f32 *, f32 *);
extern void func_801015D0();
extern int D_80804668_chflysaucer[];
extern Actor *func_80108474(s32, f32 *, s32);
extern s32 D_808046C4_chflysaucer[];
extern void func_80102424(Actor *, s32);
extern void func_8010A800(Actor *param_0, int param_1);
extern void _subaddiefade_entrypoint_3(Actor *param_0);
extern f32 func_800D8FF8(void);
extern int D_808046DC_chflysaucer[];
extern void _chscorepoints_entrypoint_2(s32, s32, f32 *, s32);
extern s16 D_801275C8;
extern s16 D_80804704_chflysaucer[];
extern int D_8080470C_chflysaucer[];
extern u8 D_808042D4_chflysaucer[];
extern u8 D_80804324_chflysaucer[];
extern u8 D_808043BC_chflysaucer[];
extern u8 D_80804474_chflysaucer[];
extern u8 D_80804514_chflysaucer[];
typedef struct { u16 time; u8 id; u8 flags; f32 arg; } FlyEvent;
typedef struct { s16 unk0; s16 unk2; f32 unk4; } FlySound;
extern FlySound D_80804294_chflysaucer[];
extern void func_800C4140(s32, f32 *, s32);
extern s16 D_80127194[];
extern void func_800F7C0C(s32, s32, f32);
extern s32 _gcdialogcamera_entrypoint_3(f32 *, f32);
typedef struct { s16 local_0; s16 local_1; } FlySaucerDialogMessage;
typedef union { s32 local_0; FlySaucerDialogMessage local_1; } FlySaucerMessage;
typedef struct { s16 local_0; s16 local_1; f32 local_2[2]; u8 pad_0[0x18]; u8 local_3; u8 pad_1[2]; u8 local_4; } SaucerControls;
extern void func_80016068(s32, f32 *);
extern s32 func_800DA298(s32);
extern f32 func_800F1DCC(f32, f32);
extern f32 func_800EEB40(f32 *, f32 *);
extern f32 func_80101F24(Actor *);
extern void _suspline_entrypoint_9(void *, f32);
extern s32 func_80101E14(Actor *, f32);
extern void *func_800D674C(s32);
extern void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
extern f32 func_800DC0C0(void);
extern s32 D_808046B0_chflysaucer[];
extern void func_80103140();
void func_808017D0_chflysaucer();
void func_80802CF0_chflysaucer();
s32 func_80800080_chflysaucer();
void func_808005FC_chflysaucer();
void func_808012A4_chflysaucer();
void func_80801568_chflysaucer();
void func_808024E0_chflysaucer();
void func_80802ED8_chflysaucer();
extern void func_80105834(), func_80107C2C(), func_808024E0_chflysaucer(), func_80802ED8_chflysaucer(), func_80803150_chflysaucer(), func_808035C4_chflysaucer();
extern u8 D_808045A4_chflysaucer[];

u8 func_80800000_chflysaucer(Actor *param_0);
void func_8080003C_chflysaucer(s32 param_0, s32 param_1);
void func_8080013C_chflysaucer(Actor *param_0, s32 param_1);
void func_808001B4_chflysaucer(Actor *param_0, s32 param_1);
void func_80800388_chflysaucer(s32 *param_0, s32 param_1, s32 param_2);
void func_80800424_chflysaucer(Actor *param_0, s32 param_1, s32 param_2, s32 param_3);
void func_808004B0_chflysaucer(s32 param_0);
int func_808004F0_chflysaucer();
void func_80800514_chflysaucer(Actor *param_0);
int func_80800728_chflysaucer(int param_0);
void func_808007C4_chflysaucer(Actor *this, s16 id);
int func_808009DC_chflysaucer(Actor *param_0, s32 param_1);
int func_80800C3C_chflysaucer(Actor *param_0);
s32 func_80800DAC_chflysaucer(Actor *param_0, f32 *param_1, f32 *param_2, s32 param_3);
s32 func_80800E48_chflysaucer();
int func_80800F98_chflysaucer();
int func_80800FF0_chflysaucer(s32 param_0);
int func_80801034_chflysaucer(f32 param_0[3]);
void func_8080105C_chflysaucer();
int func_80801130_chflysaucer(Actor *param_0);
void func_808013B4_chflysaucer(s32 param_0);
void func_80801428_chflysaucer();
void func_8080149C_chflysaucer();
void chflysaucer_entrypoint_0(Unk80132ED0 *param_0, f32 param_1);
void func_80801534_chflysaucer(s32 param_0);
s32 func_8080185C_chflysaucer(Actor *param_0, s32 param_1, FlySaucerMessage param_2);
void func_80801E98_chflysaucer(Actor *param_0);
int func_80802014_chflysaucer(s32 param_0);
void func_80802044_chflysaucer(Actor *param_0);
void func_80802114_chflysaucer(Actor *param_0, f32 param_1);
void func_808021C0_chflysaucer(Actor *param_0, SaucerSound1581 *param_1, s32 param_2);
void func_80802290_chflysaucer(Actor *param_0);
void func_808031C8_chflysaucer(u8 **param_0);
f32 func_80803224_chflysaucer(Actor *param_0);
void func_8080329C_chflysaucer(Actor *param_0, f32 *param_1, f32 *param_2, f32 param_3);
int chflysaucer_entrypoint_1();
s32 func_80803844_chflysaucer(void);
void func_808038C4_chflysaucer(Unk80132ED0 *param_0, f32 *param_1, f32 *param_2, s32 param_3, s32 param_4, f32 param_5);
void func_808039B8_chflysaucer(Unk80132ED0 *param_0, f32 *param_1, f32 *param_2, s32 *param_3, s32 param_4, f32 param_5);
void func_80803AF0_chflysaucer(Actor *param_0, s32 param_1, s32 param_2, f32 param_3);
void func_80803B60_chflysaucer(Actor *param_0);
void func_80803BE8_chflysaucer(s32 arg0);
void func_80803BF0_chflysaucer(Actor *param_0, s32 param_1);
void func_80803C3C_chflysaucer(Actor *param_0);
int func_80803CC4_chflysaucer(s32 param_0, s32 param_1);
s32 func_80803D30_chflysaucer(Actor *param_0, s32 param_1, u32 param_2);
int chflysaucer_entrypoint_2();
u8 func_80800000_chflysaucer(Actor *param_0)
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    local_0[0x26] = func_800DA564(0xA34, 3);
    return local_0[0x26];
}

void func_8080003C_chflysaucer(s32 param_0, s32 param_1) {
    u8 *local_0 = func_80100094(param_0, 0);
    func_800DA7A8(0xA34, param_1, 3);
    local_0[0x26] = param_1;
}

s32 func_80800080_chflysaucer(param_0, param_1) Actor *param_0; void **param_1;
{
    SaucerCourse *local_1;
    local_1 = func_80100094(param_0, 0);
    switch (local_1->local_0) {
    case 1: *param_1 = D_808042D4_chflysaucer; return 10;
    case 2: *param_1 = D_80804324_chflysaucer; return 19;
    case 3: *param_1 = D_808043BC_chflysaucer; return 23;
    case 4: *param_1 = D_80804474_chflysaucer; return 20;
    case 5: *param_1 = D_80804514_chflysaucer; return 18;
    }
    return 0;
}

void func_8080013C_chflysaucer(Actor *param_0, s32 param_1)
{
    FlySaucerData *local_0;
    FlySaucerRecord *local_1;
    s32 local_2;
    local_0 = func_80100094(param_0, 0);
    local_1 = NULL;
    local_2 = func_80800080_chflysaucer(param_0, &local_1);
    if (local_2 && local_0->local_0 < local_2) {
        if (local_1[local_0->local_0].local_0 < param_1) {
            func_80108B04(param_0, param_1);
        }
    }
}

void func_808001B4_chflysaucer(Actor *param_0, s32 param_1)
{
    u8 *local_0;
    FlyEvent *local_1;
    s32 local_2;
    s32 local_3;

    local_0 = func_80100094(param_0, 0);
    local_1 = NULL;
    local_2 = func_80800080_chflysaucer(param_0, &local_1);
    while (*(s16 *)(local_0 + 0x2A) < local_2 && local_1[*(s16 *)(local_0 + 0x2A)].time < param_1) {
        if (local_1[*(s16 *)(local_0 + 0x2A)].flags & 1) {
            local_3 = local_1[*(s16 *)(local_0 + 0x2A)].id;
            func_800C4140(((D_80804294_chflysaucer[local_3].unk0 & 0x7FF) + (((D_80804294_chflysaucer[local_3].unk2 >> 5) & 0x3FF) << 11)) + (u32)((u16)(u32)(D_80804294_chflysaucer[local_3].unk4 * 1023.0f) << 21), param_0->position, 0x09C404E2);
        } else {
            func_80803AF0_chflysaucer(param_0, local_1[*(s16 *)(local_0 + 0x2A)].id, local_1[*(s16 *)(local_0 + 0x2A)].flags, local_1[*(s16 *)(local_0 + 0x2A)].arg);
        }
        (*(s16 *)(local_0 + 0x2A))++;
    }
}

void func_80800388_chflysaucer(s32 *param_0, s32 param_1, s32 param_2) {
    u8 *local_0;
    u8 local_1;
    u8 *local_2;

    local_2 = func_80100094(param_0, 0);
    local_0 = local_2;
    local_1 = *(u8 *)((char *)local_2 + 0x28);
    switch (local_1) {
    case 0:
        _capod_entrypoint_2(*param_0, 5, 0);
        /* fallthrough */
    case 2:
        _capod_entrypoint_8(1);
        *(u8 *)((char *)local_0 + 0x28) = 1;
        _gcdialogcamera_entrypoint_6(*param_0);
        _gcdialogcamera_entrypoint_8();
        /* fallthrough */
    case 1:
        _capod_entrypoint_7(param_1, param_2);
        return;
    }
}

void func_80800424_chflysaucer(Actor *param_0, s32 param_1, s32 param_2, s32 param_3)
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    switch (*(u8 *)(local_0 + 0x28)) {
        case 0:
            _capod_entrypoint_2(param_0->unk0, 5, param_2);
        case 1:
            *(u8 *)(local_0 + 0x28) = 2;
        case 2:
            _capod_entrypoint_6(param_3, param_1, param_2);
            return;
    }
}

void func_808004B0_chflysaucer(s32 param_0) {
    u8 *sp1C;

    sp1C = func_80100094(param_0, 0);
    if (*(u8 *)(sp1C + 0x28) != 0) {
        _capod_entrypoint_3(0);
        *(u8 *)(sp1C + 0x28) = 0;
    }
}

int func_808004F0_chflysaucer()
{
  (*(u16 *)((u8 *)((u8 *) D_80127194) + 0x434)) = 0;
  func_808017D0_chflysaucer();
}

void func_80800514_chflysaucer(Actor *param_0)
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    param_0->unk64_19 = 1;
    func_800FE850();
    switch (local_0[0x26]) {
        case 1:
            _gcgoto_entrypoint_1(0x124, 8);
            break;
        case 2:
            _gcgoto_entrypoint_1(0x13C, 1);
            break;
        case 3:
            _gcgoto_entrypoint_1(0x124, 8);
            break;
        case 4:
            _gcgoto_entrypoint_1(0x13B, 1);
            break;
        case 5:
            _gcgoto_entrypoint_1(0x124, 1);
            break;
        case 6:
            _gcgoto_entrypoint_1(0xD6, 8);
            param_0->unk64_19 = 0;
            break;
    }
}

void func_808005FC_chflysaucer(param_0) Actor *param_0;
{
    switch (*(u8 *)((u8 *)func_80100094(param_0, 0) + 0x26)) {
        case 0:
            func_808012A4_chflysaucer(param_0, 1);
            func_808009DC_chflysaucer(param_0, 3);
            func_8080003C_chflysaucer(param_0, 1);
            if (!func_800D395C()) {
                func_80800514_chflysaucer(param_0);
            }
            break;
        case 1:
            func_8080003C_chflysaucer(param_0, 2);
            func_80800514_chflysaucer(param_0);
            break;
        case 2:
            func_8080003C_chflysaucer(param_0, 3);
            func_80800514_chflysaucer(param_0);
            break;
        case 3:
            func_8080003C_chflysaucer(param_0, 4);
            func_80800514_chflysaucer(param_0);
            break;
        case 4:
            func_8080003C_chflysaucer(param_0, 5);
            func_80800514_chflysaucer(param_0);
            break;
        case 5:
            func_8080003C_chflysaucer(param_0, 6);
            func_80800514_chflysaucer(param_0);
            break;
        case 6:
            func_8080003C_chflysaucer(param_0, 0);
            break;
    }
}

int func_80800728_chflysaucer(int param_0)
{
  s16 *local_0;
  ;
  return D_808045DA_chflysaucer[*((unsigned char *) ((u8 *)func_80100094(param_0, 0) + 0x26))];
}

int func_80800758_chflysaucer(param_0) s16 param_0;
{
  s32 local_0;
  s32 local_1;
  local_0 = 0;
  while (param_0 != -1)
  {
    func_800A5800(param_0);
    _cadbfunc_entrypoint_16(&param_0);
    local_0++;
  }

  return local_0;
}

void func_808007C4_chflysaucer(Actor *this, s16 id)
{
    SaucerCourse *local;
    f32 *pos[2];
    f32 *arr[3];
    s32 count;
    void *spl;
    s32 first;
    s16 i;
    s32 tmp;

    local = func_80100094(this, 0);
    count = func_80800758_chflysaucer(id);
    if (local->local_0 == 1) {
        first = 1;
    } else {
        first = 0;
    }
    _suspline_entrypoint_20(this, count, 2, 3, 0, 0);
    spl = func_80100094(this, 1);
    for (i = 0; i < 2; i++) {
        pos[i] = _suspline_entrypoint_10(spl, i);
    }
    for (i = 0; i < 3; i++) {
        arr[i] = _suspline_entrypoint_11(spl, i);
    }
    i = 0;
    while (id != -1) {
        func_800A5800(id);
        if (i == 0 && first) {
            func_800EE7F8(pos[0], this->position);
            pos[0][1] += 175.0f;
        } else {
            _cadbfunc_entrypoint_0(pos[0]);
        }
        _cadbfunc_entrypoint_2(pos[1]);
        _cadbfunc_entrypoint_10(arr[0]);
        _cadbfunc_entrypoint_12(arr[1]);
        _cadbfunc_entrypoint_14(arr[2]);
        _cadbfunc_entrypoint_29(8, &tmp);
        _suspline_entrypoint_0(spl, i, tmp);
        pos[0] += 3;
        pos[1] += 3;
        arr[0]++;
        arr[1]++;
        arr[2]++;
        i++;
        _cadbfunc_entrypoint_16(&id);
    }
    func_800F0EF0(count, _suspline_entrypoint_10(spl, 1));
}

int func_808009DC_chflysaucer(Actor *param_0, s32 param_1)
{
    u8 *local_0;
    s32 local_9;
    s32 local_1;
    s32 local_2;
    s32 local_3;

    local_0 = func_80100094(param_0, 0);
    if (param_1 != local_0[0x24]) {
        switch (local_0[0x24]) {
        case 0:
            if ((u32)param_1 == 1 || (u32)param_1 == 3) {
                func_800904F4(0x27, param_0->unk0, param_1);
                func_80104268(local_0);
                func_80801428_chflysaucer(param_0);
                func_800F4CEC(func_800F54E4(), 0x71);
                func_80802CF0_chflysaucer(param_0);
            }
            break;
        case 2:
            if (param_1 == 1 || param_1 == 3) {
                func_800904C8(0x4B);
                func_800F4CC0(func_800F54E4());
                func_800BF4A4(0, 1);
                func_800BF4A4(1, 1);
                ((Fs74 *)param_0)->f = 1;
                func_8010FD38(func_8008FFE8(), 0.0f);
                local_1 = func_80104200(*(s16 *)local_0);
                anctrl_setIndex(local_1, 0x486);
                anctrl_setDuration(local_1, 1.0f);
                anctrl_setPlaybackType(local_1, 3);
                anctrl_start(local_1);
            }
            break;
        case 1:
        case 3:
            if (param_1 != 0) {
                if (param_1 == 2) {
                    func_800F4CEC(func_800F54E4(), 0x60);
                    func_800BF4A4(0, 0);
                    func_800BF4A4(1, 0);
                    ((Fs74 *)param_0)->f = 0;
                    func_800904C8(0x4B);
                    func_80802CF0_chflysaucer(param_0);
                    func_8010FD38(func_8008FFE8(), 75.0f);
                    local_2 = func_80104200(*(s16 *)(local_0 + 2));
                    local_3 = func_80104200(*(s16 *)local_0);
                    anctrl_setIndex(local_2, 0x484);
                    anctrl_setIndex(local_3, 0x489);
                    anctrl_setPlaybackType(local_2, 3);
                    anctrl_start(local_2);
                    anctrl_setPlaybackType(local_3, 3);
                    anctrl_start(local_3);
                }
            } else {
                func_800904C8(0x28);
                func_800F4CC0(func_800F54E4());
                func_8080149C_chflysaucer(param_0);
            }
            break;
        }
        local_0[0x24] = param_1;
    }
}

int func_80800C3C_chflysaucer(Actor *param_0)
{
    u8 *local_0;
    void *local_1;
    s32 local_2;
    f32 local_3[3];
    local_0 = func_80100094(param_0, 0);
    local_1 = func_80100094(param_0, 1);
    local_2 = 0;
    _suspline_entrypoint_14(local_1);
    _suspline_entrypoint_17(local_1);
    _suspline_entrypoint_3(local_1, 0, (f32 *)&param_0->actorData[4]);
    _suspline_entrypoint_3(local_1, 1, param_0->rotation);
    param_0->rotation[1] += 180.0f;
    param_0->rotation[0] = -param_0->rotation[0];
    _suspline_entrypoint_5(local_1, (f32 *)&param_0->actorData[4]);
    if (_suspline_entrypoint_1(local_1)) {
        if (local_0[0x26] == 5) {
            func_808012A4_chflysaucer(param_0, 3);
            func_808009DC_chflysaucer(param_0, 1);
        } else {
            func_808009DC_chflysaucer(param_0, 1);
            func_808012A4_chflysaucer(param_0, 4);
            func_808005FC_chflysaucer(param_0);
        }
        local_2 = 1;
    }
    _suspline_entrypoint_16(local_1);
    if (param_0->unk74_29) {
        func_800EFB24(local_3, (f32 *)&param_0->actorData[4], param_0->position);
        func_800EF334(local_3, 0.3f);
        func_800EF04C(param_0->position, local_3);
    } else {
        func_800EE7F8(param_0->position, (f32 *)&param_0->actorData[4]);
        param_0->unk74_29 = 1;
    }
    return local_2;
}

s32 func_80800DAC_chflysaucer(Actor *param_0, f32 *param_1, f32 *param_2, s32 param_3)
{
    void *local_0;
    f32 local_1;
    local_0 = func_80100094(param_0, 1);
    local_1 = _suspline_entrypoint_6(local_0);
    _suspline_entrypoint_15(local_0, param_3);
    _suspline_entrypoint_17(local_0);
    _suspline_entrypoint_3(local_0, 0, param_1);
    _suspline_entrypoint_3(local_0, 1, param_2);
    param_2[1] += 180.0f;
    _suspline_entrypoint_8(local_0, local_1);
    return 1;
}

s32 func_80800E48_chflysaucer(param_0) s32 param_0; {
    if (func_800D395C() != 0) {
        if (func_800D211C(0x8D) < (*(s16 *)((s8 *)(((s32 *) D_80127194)) + (0x434)))) {
            return 4;
        }
        return 5;
    }
    if ((func_800D0A9C(0x18, 1) == 0) && (func_800D0A9C(9, 4) == 0)) {
        if (((*(s16 *)((s8 *)(((s32 *) D_80127194)) + (0x434))) >= 0x1F4) && ((*(s16 *)((s8 *)(((s32 *) D_80127194)) + (0x434))) >= 0x190)) {
            return 3;
        }
        if ((*(s16 *)((s8 *)(((s32 *) D_80127194)) + (0x434))) >= 0x1F4) {
            return 1;
        }
        if ((*(s16 *)((s8 *)(((s32 *) D_80127194)) + (0x434))) >= 0x190) {
            return 2;
        }
        return 0;
    }
    if (func_800D0A9C(0x18, 1) == 0) {
        if ((*(s16 *)((s8 *)(((s32 *) D_80127194)) + (0x434))) >= 0x1F4) {
            return 1;
        }
        return 0;
    }
    if (func_800D0A9C(9, 4) == 0) {
        if ((*(s16 *)((s8 *)(((s32 *) D_80127194)) + (0x434))) >= 0x190) {
            return 2;
        }
        return 0;
    }
    if (func_800D211C(0x8D) < (*(s16 *)((s8 *)(((s32 *) D_80127194)) + (0x434)))) {
        return 4;
    }
    return 5;
}

int func_80800F98_chflysaucer()
{
  switch (func_80800E48_chflysaucer())
  {
    case 0 :
    case 5 :
      func_800FC6B0(0x17);
      break;

    case 1 :
    case 2 :
    case 3 :
    case 4 :
      func_800FC6B0(0x16);
      break;
  }
}

int func_80800FF0_chflysaucer(s32 param_0)
{
    u8 local_0;
    Actor *local_1 = func_80100094(param_0, 0);
    local_0 = *(u8 *)((char *)local_1 + 0x24);
    if (local_0 == 1 || local_0 == 2 || local_0 == 3)
    {
        return 1;
    }
    return 0;
}

int func_80801034_chflysaucer(f32 param_0[3])
{
  f32 _pad0, _pad1;
  f32 local_0 = -7800;
  f32 local_1 = 1700;
  int new_var;
  f32 local_2 = -2900;
  new_var = 1;
  if (1)
  {
  }
  param_0[1] = local_0;
  param_0[2] = local_1;
  param_0[3] = local_2;
  param_0[3] = local_2;
  ;
}

void func_8080105C_chflysaucer(param_0, param_1, param_2) Actor *param_0; s32 param_1; u32 param_2; {
    param_2 |= 6;
    if (func_80800FF0_chflysaucer(param_0) == 0) {
        param_2 |= 8;
    }
    switch (param_1) {
    case 0x10C6: ;
    case 0x10C7:
    case 0x10C8: ;
    case 0x10C9:
    case 0x10E2: ;
    case 0x10E3:
    case 0x10E4: ;
    case 0x10E5:
    case 0x10E6: ;
    case 0x10E7:
    case 0x10E8:
        func_80800388_chflysaucer(param_0, 2, 1);
        break;
    case 0x10DB: ;
    case 0x10DD:
        func_80800388_chflysaucer(param_0, 4, 0);
        break;
    case 0x10DC: ;
    case 0x10DE:
        func_80800388_chflysaucer(param_0, 2, 1);
        break;
    }
    _subaddiedialog_entrypoint_11(*(s32 **)(param_0), param_1, param_2, (s8 *)param_0 + 4, 0x41);
    param_0->unk74_30 = 1;
}

int func_80801130_chflysaucer(Actor *param_0)
{
  Actor *new_var;
  new_var = param_0;
  switch (func_80800E48_chflysaucer())
  {
    case 0:
      if (!func_800DA9E4(0x415, 1))
    {
      func_8080105C_chflysaucer(new_var, 0x10C6, 1);
    }
    else
    {
      func_8080105C_chflysaucer(new_var, 0x10C7, 1);
    }
      break;

    case 1:
      func_808012A4_chflysaucer(new_var, 7);
      func_800D2054(0, 0x8D, D_80127194[0x21A]);
      break;

    case 2:
      func_808012A4_chflysaucer(param_0, 8);
      func_800D2054(0, 0x8D, D_80127194[0x21A]);
      break;

    case 3:
      func_808012A4_chflysaucer(new_var, 9);
      func_800D2054(0, 0x8D, D_80127194[0x21A]);
      break;

    case 4:
      func_800D2054(0, 0x8D, D_80127194[0x21A]);
      func_8080105C_chflysaucer(new_var, 0x10E4, 1);
      break;

    case 5:
      if (!func_800DA9E4(0x416, 1))
    {
      func_8080105C_chflysaucer(new_var, 0x10E2, 1);
    }
    else
    {
      func_8080105C_chflysaucer(new_var, 0x10E3, 1);
    }

  }

}

void func_808012A4_chflysaucer(param_0, param_1) Actor *param_0; s32 param_1;
{
    u8 *local_0;
    local_0 = (u8 *)func_80100094(param_0, 0);
    switch (local_0[0x25]) {
    case 2: break;
    case 5:
    case 6: func_80090658(0); break;
    }
    local_0[0x25] = param_1;
    switch (local_0[0x25]) {
    case 2: break;
    case 5:
    case 6: func_80090658(1); break;
    case 3:
        param_0->unk58 = 2.0f;
        func_800FDC28(0);
        func_80800F98_chflysaucer(param_0);
        break;
    case 7: func_8080105C_chflysaucer(param_0, 0x10C8, 1); break;
    case 8: func_8080105C_chflysaucer(param_0, 0x10C9, 1); break;
    case 9: func_8080105C_chflysaucer(param_0, 0x10E5, 1); break;
    }
}

void func_808013B4_chflysaucer(s32 param_0) {
    void *temp_v0;

    temp_v0 = func_80104200(*(s16 *)((char *)func_80100094(param_0, 0) + 2));
    anctrl_reset(temp_v0);
    anctrl_setPlaybackType(temp_v0, 3);
    anctrl_setIndex(temp_v0, 0x481);
    anctrl_setDuration(temp_v0, 1.0f);
    func_8008B188(temp_v0, 1);
    anctrl_start(temp_v0);
}

void func_80801428_chflysaucer(param_0) s32 param_0; {
    void *temp_v0;

    temp_v0 = func_80104200(*(s16 *)((char *)func_80100094(param_0, 0) + 0));
    anctrl_reset(temp_v0);
    anctrl_setPlaybackType(temp_v0, 3);
    anctrl_setIndex(temp_v0, 0x486);
    anctrl_setDuration(temp_v0, 1.0f);
    func_8008B188(temp_v0, 1);
    anctrl_start(temp_v0);
}

void func_8080149C_chflysaucer(param_0) s32 param_0; {
    s16 *temp_v0;

    temp_v0 = func_80100094(param_0, 0);
    if (*temp_v0 != 0) {
        func_801042D8(temp_v0);
  }
}

void chflysaucer_entrypoint_0(Unk80132ED0 *param_0, f32 param_1)
{
  s32 pad0;
    s16 *local_0;
    AnimCtrl *local_1;

    local_0 = func_80100094(func_80106790(param_0), 0);
    if (local_0[0] != 0) {
        local_1 = func_80104200(local_0[0]);
        if (anctrl_getIndex(local_1) == 0x486) {
            func_8008B10C(local_1, param_1);
        }
    }
}

void func_80801534_chflysaucer(s32 param_0) {
    u8 *temp_v0;

    temp_v0 = func_80100094(param_0, 0);
    if ((*(s16 *)((s8 *)(temp_v0) + (2))) != 0) {
        func_801042D8(temp_v0 + 2);
    }
}

void func_80801568_chflysaucer(param_0, param_1) Actor *param_0; s32 param_1;
{   u8 *local_0; for (;;) {
        local_0 = func_80100094(param_0, 0);
        switch ((s32)param_0->unk70_10) {
        case 5:
            func_800F7C0C(func_800F54E4(), 0x5F, 0.0f);
            func_80801534_chflysaucer(param_0);
            break;
        case 4:
            func_808004B0_chflysaucer(param_0);
            break;
        }
        func_80102424(param_0, param_1);
        switch ((s32)param_0->unk70_10) {
        case 6:
            param_0->unk64_20 = 1;
            break;
        case 2:
            func_80800424_chflysaucer(param_0, 0x9C, 0x4020, 0);
            *(f32 *)(local_0 + 0x18) = 0.3f;
            func_808012A4_chflysaucer(param_0, 1);
            func_808009DC_chflysaucer(param_0, 3);
            return;
        case 4:
            if (!func_800D395C() && (!func_800D0A9C(0x18, 1) || !func_800D0A9C(9, 4))) {
                if (!func_800DA9E4(0x417, 1)) {
                    func_8080105C_chflysaucer(param_0, 0x10C5, 1);
                    _gcfrontend_entrypoint_9(0x69);
                } else {
                    func_8080105C_chflysaucer(param_0, 0x1102, 1);
                }
                return;
            }
            if (!func_800DA9E4(0x418, 1)) {
                func_8080105C_chflysaucer(param_0, 0x10E1, 1);
                return;
            }
            func_808004F0_chflysaucer(param_0);
            param_1 = 5;
            continue;
        case 5:
            *(s16 *)(local_0 + 0x2A) = 0;
            *(f32 *)(local_0 + 0x18) = 0.8f;
            _subaddieDll_entrypoint_4(param_0, 1);
            _subaddieDll_entrypoint_0(param_0);
            func_800FDC28(0x11);
            func_808007C4_chflysaucer(param_0, (s16)func_80800728_chflysaucer(param_0));
            func_808012A4_chflysaucer(param_0, 1);
            func_808009DC_chflysaucer(param_0, 1);
            func_80800C3C_chflysaucer(param_0);
            func_800F7C0C(func_800F54E4(), 0x5F, -1.0f);
            func_80104268(local_0 + 2);
            func_808013B4_chflysaucer(param_0);
            break;
        }
        return;
    }
}

void func_808017D0_chflysaucer(param_0) Actor *param_0;
{
    s32 local_1;
    s32 local_0;
    local_0 = ((u8 *)func_80100094(param_0, 0))[0x26];
    func_80801568_chflysaucer(param_0, 5);
    local_1 = D_808045E8_chflysaucer[local_0];
    if (local_1 != -1) _capod_entrypoint_13(param_0->unk0, 0, local_1, 0x2C21);
    else {
        func_808012A4_chflysaucer(param_0, 2);
        func_808009DC_chflysaucer(param_0, 2);
    }
}

s32 func_8080185C_chflysaucer(Actor *param_0, s32 param_1, FlySaucerMessage param_2)
{
    extern u8 D_808045F8_chflysaucer[];
    extern u8 D_80804608_chflysaucer[];
    extern u8 D_80804618_chflysaucer[];
    char *local_0;
    s16 *local_1;
    s32 local_2;

    local_0 = func_80100094(param_0, 0);
    local_2 = param_2.local_0;
    switch (param_1) {
        default:
            return 0;

        case 0x52:
            if (local_0[0x24] == 0) {
                _gcdialogcamera_entrypoint_3(D_808045F8_chflysaucer, param_0->scale);
            } else {
                _gcdialogcamera_entrypoint_3(D_80804608_chflysaucer, param_0->scale);
            }
            return 1;

        case 0x2E:
            switch (param_2.local_1.local_0) {
                case 0x10E2:
                case 0x10E3:
                case 0x10E4:
                    if (func_800D395C()) {
                        break;
                    }
                default:
                    func_808004B0_chflysaucer(param_0);
                    break;
                case 0xCEB:
                case 0x10C5:
                case 0x10C8:
                case 0x10C9:
                case 0x10E5:
                case 0x10E6:
                case 0x1102:
                    break;
            }
            if (local_0[0x26] == 6) {
                switch (param_2.local_1.local_0) {
                    case 0xCEB:
                        if (param_2.local_1.local_1 == 1) {
                            func_8080003C_chflysaucer(param_0, 0);
                            _gcgoto_entrypoint_1(0x124, 8);
                        } else {
                            _gcfrontend_entrypoint_10();
                        }
                        break;
                    case 0x10E2:
                    case 0x10E3:
                    case 0x10E4:
                        if (func_800D395C()) {
                            func_8080105C_chflysaucer(param_0, 0xCEB, 0x40);
                            break;
                        }
                    default:
                        func_808005FC_chflysaucer(param_0);
                        func_808012A4_chflysaucer(param_0, 0);
                        break;
                    case 0x10C8:
                    case 0x10C9:
                    case 0x10E5:
                    case 0x10E6:
                        break;
                }
            } else {
                switch (param_0->unk70_10) {
                    case 4:
                        switch (param_2.local_1.local_0) {
                            case 0x10C5:
                            case 0x1102:
                                if (!func_800D0A9C(9, 4)) {
                                    func_8080105C_chflysaucer(param_0, 0x1103, 1);
                                } else {
                                    func_8080105C_chflysaucer(param_0, 0x1104, 1);
                                }
                                break;
                            case 0x1103:
                            case 0x1104:
                                func_808004F0_chflysaucer(param_0);
                                break;
                            case 0x10E1:
                                func_808004F0_chflysaucer(param_0);
                                break;
                        }
                        break;
                }
            }
            param_0->unk74_30 = 0;
            break;

        case 0x30:
            local_1 = (s16 *)&param_2;
            switch (local_1[0]) {
                case 0x10C5:
                case 0x1103:
                    switch (local_1[1]) {
                        case 0: return 500;
                        case 1: return 400;
                    }
                    break;
                case 0x1104:
                    return 500;
                case 0x10E4:
                    return func_800D211C(0x8D);
                case 0x10E2:
                case 0x10E3:
                    return func_800D211C(0x8D);
            }
            break;

        case 0x2F:
            switch (param_2.local_1.local_0) {
                case 0x10C8:
                case 0x10E6:
                    func_800D1000(0x18, 1, 0, 1, param_0->unk0);
                    break;
                case 0x10C9:
                case 0x10E5:
                    func_800D1000(9, 4, D_80804618_chflysaucer, 1, param_0->unk0);
                    break;
            }
            break;

        case 0x56:
            switch (param_2.local_0) {
                case 0x1B:
                case 0x1D:
                case 0x66:
                case 0x68:
                case 0x6A:
                case 0x6C:
                    func_808009DC_chflysaucer(param_0, 1);
                    func_808012A4_chflysaucer(param_0, 1);
                    break;
            }
            break;

        case 0x0B:
            switch (local_2) {
                case 0x19:
                case 0x1B:
                case 0x64:
                case 0x6A:
                case 0x6E:
                    func_80108BD4(param_0, param_2.local_0);
                    return 3;
                case 0x70:
                    switch (local_0[0x25]) {
                        case 9:
                            func_8080105C_chflysaucer(param_0, 0x10E6, 1);
                            return 4;
                        case 8:
                            if (func_800D0A9C(0x18, 1)) {
                                func_8080105C_chflysaucer(param_0, 0x10E8, 1);
                            } else {
                                func_8080105C_chflysaucer(param_0, 0x10E7, 1);
                            }
                            return 4;
                    }
                    break;
                case 0x72:
                    switch (local_0[0x25]) {
                        case 7:
                            if (func_800D0A9C(9, 4)) {
                                func_8080105C_chflysaucer(param_0, 0x10E8, 1);
                            } else {
                                func_8080105C_chflysaucer(param_0, 0x10E7, 1);
                            }
                            return 4;
                        case 9:
                            func_8080105C_chflysaucer(param_0, 0x10E8, 1);
                            return 4;
                    }
                    break;
            }
            return 3;

        case 0x59:
            switch (param_2.local_0) {
                case 0x19:
                case 0x1B:
                case 0x64:
                case 0x6A:
                case 0x6E:
                    _capod_entrypoint_14();
                    func_808012A4_chflysaucer(param_0, 2);
                    func_808009DC_chflysaucer(param_0, 2);
                    return 4;
            }
            return 3;

        case 0x3D:
            func_808001B4_chflysaucer(param_0, param_2.local_0);
            return 1;

        case 0x0D:
            switch ((param_2.local_0 >> 16) & 0xFFFF) {
                case 0x18:
                    func_80800424_chflysaucer(param_0, 0x72, 0x418, func_80101080());
                    break;
                case 9:
                    func_80800424_chflysaucer(param_0, 0x70, 0x418, func_80101080());
                    break;
            }
            break;
    }
    return 1;
}

void func_80801E98_chflysaucer(Actor *param_0)
{
    f32 local_0[3];
    if (!param_0->unk74_30 && func_8010CAC0(param_0->position, 250) && !func_800DB9B0()) {
        if (param_0->unk64_20) {
            if (!func_800DA298(0x414)) {
                if (func_8008FA2C(1, 0)) {
                    func_800DA544(0x414);
                    func_8080105C_chflysaucer(param_0, 0x10DB, 1);
                }
                return;
            }
            if (!func_80090178(1)) return;
            func_800EE7F8(local_0, param_0->position);
            local_0[1] += 150.0f;
            if (func_8010CAC0(local_0, 120)) func_808012A4_chflysaucer(param_0, 5);
            else if (func_8008FA60(1, 0) && func_80016B30(0, 1) == 1) func_8080105C_chflysaucer(param_0, 0x10DC, 1);
        } else {
            if (!func_800DA9E4(0x413, 1)) func_8080105C_chflysaucer(param_0, 0x10DD, 1);
            else if (func_80016B30(0, 1) == 1) func_8080105C_chflysaucer(param_0, 0x10DE, 1);
        }
    }
}

int func_80802014_chflysaucer(s32 param_0)
{
  func_8008FB10(param_0 + 4, 65.0f, 0.0f, 90.0f);
}

void func_80802044_chflysaucer(Actor *param_0)
{
    SaucerCourse *local_0;
    void *local_1;
    s16 *local_2;

    u8 local_4;

    local_0 = func_80100094(param_0, 0);
    local_1 = func_80100094(param_0, 1);
    local_4 = local_0->local_0;
    local_2 = &D_80804624_chflysaucer[local_4];
    if (D_80804274_chflysaucer[local_4] == -1.0f || *local_2 == -1) return;
    if (_suspline_entrypoint_2(local_1, D_80804274_chflysaucer[local_4])) {
        _capod_entrypoint_13(param_0->unk0, 0, *local_2, 0x4C21);
        func_808012A4_chflysaucer(param_0, 1);
        func_808009DC_chflysaucer(param_0, 1);
    }
}

void func_80802114_chflysaucer(Actor *param_0, f32 param_1)
{
    u8 local_0;

    local_0 = param_0->unk5F;
    if (!local_0) {
        param_0->unk5F = func_800C4350(0, param_0->position, D_80804634_chflysaucer);
        return;
    }
    if (param_1 < 0.5f) {
        param_1 = 0.5f;
    }
    if (param_1 > 1.5f) {
        param_1 = 1.5f;
    }
    func_800C31DC(local_0, param_1);
    func_800C4350(param_0->unk5F, param_0->position, NULL);
}

void func_808021C0_chflysaucer(Actor *param_0, SaucerSound1581 *param_1, s32 param_2)
{
    if (param_2 == param_1->local_1) {
        if (param_2 != 3) func_800C4350(param_1->local_0, param_0->position, NULL);
    } else {
        switch (param_2) {
            case 3:
                func_800C2FDC(param_1->local_0);
                param_1->local_0 = 0;
                break;
            case 0:
            case 1:
            case 2:
                func_800C4B64(D_8080465C_chflysaucer[param_2]);
                param_1->local_0 = func_800C4350(param_1->local_0, param_0->position, D_80804648_chflysaucer);
                break;
        }
        param_1->local_1 = param_2;
    }
}

void func_80802290_chflysaucer(Actor *param_0)
{
    SaucerControls *local_0;
    s32 local_1;
    s32 local_2;
    f32 local_3[2];
    f32 local_5;
    f32 local_6;
    f32 local_7;
    f32 local_8;
    s32 local_4;

    local_0 = func_80100094(param_0, 0);
    if (local_0->local_3 == 2) {
        local_1 = func_80104200(local_0->local_1);
        local_2 = func_80104200(local_0->local_0);
        local_4 = 0;
        func_80016068(0, local_3);
        local_5 = local_3[0] - local_0->local_2[0];
        local_6 = local_3[1] - local_0->local_2[1];
        local_7 = local_5 > 0.0f ? local_5 : -local_5;
        local_8 = local_6 > 0.0f ? local_6 : -local_6;
        if (local_7 > local_8) {
            if (local_5 > 0.25f) {
                local_4 = 4;
            } else if (local_5 < -0.25f) {
                local_4 = 3;
            }
        } else if (local_6 > 0.25f) {
            local_4 = 2;
        } else if (local_6 < -0.25f) {
            local_4 = 1;
        }
        if (local_4 != local_0->local_4) {
            switch (local_4) {
            case 0:
                break;
            case 3:
                anctrl_setIndex(local_1, 0x484);
                anctrl_setIndex(local_2, 0x489);
                break;
            case 4:
                anctrl_setIndex(local_1, 0x485);
                anctrl_setIndex(local_2, 0x48A);
                break;
            case 1:
                anctrl_setIndex(local_1, 0x482);
                anctrl_setIndex(local_2, 0x487);
                break;
            case 2:
                anctrl_setIndex(local_1, 0x483);
                anctrl_setIndex(local_2, 0x488);
                break;
            }
            if (local_4 != 0) {
                anctrl_setPlaybackType(local_1, 1);
                anctrl_start(local_1);
                anctrl_setPlaybackType(local_2, 1);
                anctrl_start(local_2);
            }
            local_0->local_4 = local_4;
        }
        func_8008ADE4(local_1);
        func_8008ADE4(local_2);
    }
}

void func_808024E0_chflysaucer(param_0) Actor *param_0;
{
    extern u8 D_80804260_chflysaucer[];
    extern s16 D_80127194[];

    char *local_0;
    f32 local_3[3];
    f32 local_2[3];
    f32 local_5;
    f32 local_8[3];
    f32 local_4[3];
    f32 local_6;
    f32 local_7;
    char *local_1;
    s32 local_9;
    s32 local_10;

    local_0 = (char *)func_80100094(param_0, 0);

    if (!param_0->unk64_20 && func_800DA298(0xEB)) {
        param_0->unk64_20 = 1;
    }

    switch (param_0->unk70_10) {
        case 1:
            local_9 = *(u8 *)(local_0 + 0x26);
            switch (local_9) {
            case 0:
                local_10 = *(u8 *)(local_0 + 0x25);
                switch (local_10) {
                case 0:
                    func_80801E98_chflysaucer(param_0);
                    func_80802014_chflysaucer(param_0);
                    break;
                case 5:
                    func_808012A4_chflysaucer(param_0, 6);
                    func_800904F4(
                        0x27,
                        *(s32 *)((char *)param_0 + 0)
                    );
                    break;
                case 6:
                    func_8008FF40(local_2);

                    local_5 = func_800F1DCC(
                        *(f32 *)((char *)param_0 + 0x48),
                        local_2[1]
                    );

                    local_2[1] += local_5 * 0.45f;

                    func_800906DC(local_2);
                    func_8010D254(local_3);

                    func_800EE7F8(
                        local_4,
                        (char *)param_0 + 4
                    );

                    local_4[1] += 90.0f;

                    func_800EFB24(
                        local_8,
                        local_4,
                        local_3
                    );

                    func_800EF334(local_8, 0.45f);
                    func_800EF04C(local_3, local_8);
                    func_800906B0(local_3);

                    if (func_800EEB40(local_3, local_4) <
                            2500.0f &&
                        local_5 > -5.0f &&
                        local_5 < 5.0f) {
                        func_800904C8(0x28);
                        func_808005FC_chflysaucer(param_0);
                    }
                    break;
                }
                break;
            case 6:
                func_80802014_chflysaucer(param_0);
                break;
            }
            break;

        case 2:
            local_6 = func_80101F24(param_0);

            if (func_80101DDC(param_0)) {
                func_80801568_chflysaucer(param_0, 3);
            }

            if (local_6 > 0.05f && local_6 < 0.14f) {
                if (*(f32 *)(local_0 + 0x18) < 0.4f) {
                    *(f32 *)(local_0 + 0x18) += 0.02f;
                }
            }

            if (local_6 > 0.14f && local_6 < 0.31f) {
                if (*(f32 *)(local_0 + 0x18) > 0.2f) {
                    *(f32 *)(local_0 + 0x18) -= 0.03f;
                }
            }

            if (local_6 > 0.31f && local_6 < 0.46f) {
                if (*(f32 *)(local_0 + 0x18) < 0.55f) {
                    *(f32 *)(local_0 + 0x18) += 0.02f;
                }
            }

            if (local_6 > 0.46f && local_6 < 0.55f) {
                if (*(f32 *)(local_0 + 0x18) > 0.45f) {
                    *(f32 *)(local_0 + 0x18) -= 0.03f;
                }
            }

            if (local_6 > 0.55f && local_6 < 0.58f) {
                if (*(f32 *)(local_0 + 0x18) < 0.7f) {
                    *(f32 *)(local_0 + 0x18) += 0.02f;
                }
            }

            if (local_6 > 0.58f && local_6 < 0.65f) {
                if (*(f32 *)(local_0 + 0x18) > 0.6f) {
                    *(f32 *)(local_0 + 0x18) -= 0.03f;
                }
            }

            if (local_6 > 0.65f && local_6 < 0.71f) {
                if (*(f32 *)(local_0 + 0x18) < 0.85f) {
                    *(f32 *)(local_0 + 0x18) += 0.02f;
                }
            }

            if (local_6 > 0.71f && local_6 < 0.85f) {
                if (*(f32 *)(local_0 + 0x18) > 0.8f) {
                    *(f32 *)(local_0 + 0x18) -= 0.03f;
                }
            }

            func_80802CF0_chflysaucer(param_0);

            func_80802114_chflysaucer(
                param_0,
                *(f32 *)(local_0 + 0x18)
            );

            if (func_80101E14(param_0, 0.62f)) {
                _subaddieaudioquick_entrypoint_2(
                    param_0,
                    (char *)param_0 + 4,
                    D_80804260_chflysaucer
                );

                func_808021C0_chflysaucer(
                    param_0,
                    local_0,
                    3
                );
            } else if (local_6 < 0.21f) {
                func_808021C0_chflysaucer(
                    param_0,
                    local_0,
                    0
                );
            } else if (local_6 > 0.3f &&
                       local_6 < 0.44f) {
                func_808021C0_chflysaucer(
                    param_0,
                    local_0,
                    1
                );
            } else if (local_6 > 0.5f &&
                       local_6 < 0.62f) {
                func_808021C0_chflysaucer(
                    param_0,
                    local_0,
                    2
                );
            }
            break;

        case 3:
            if (*(f32 *)(local_0 + 0x18) <= 0.99f) {
                *(f32 *)(local_0 + 0x18) += 0.01f;
            } else {
                func_80801568_chflysaucer(param_0, 4);
            }

            func_80802CF0_chflysaucer(param_0);

            func_80802114_chflysaucer(
                param_0,
                *(f32 *)(local_0 + 0x18)
            );
            break;

        case 4:
            func_80802CF0_chflysaucer(param_0);

            func_80802114_chflysaucer(
                param_0,
                *(f32 *)(local_0 + 0x18)
            );
            break;

        case 5:
            local_10 = *(u8 *)(local_0 + 0x25);
            switch (local_10) {
            case 3:
                *(f32 *)((char *)param_0 + 0x58) -= func_800D8FF8();

                if (*(f32 *)((char *)param_0 + 0x58) <= 0.0f) {
                    func_808005FC_chflysaucer(param_0);
                }
                break;
            default:
                local_1 = (char *)func_80100094(param_0, 1);

                _suspline_entrypoint_13(local_1);

                local_7 = _suspline_entrypoint_6(local_1);

                _suspline_entrypoint_9(
                    local_1,
                    local_7
                );

                if (!func_80800C3C_chflysaucer(param_0)) {
                    local_7 = _suspline_entrypoint_6(local_1);

                    func_8080013C_chflysaucer(
                        param_0,
                        (s32)(65535.0f * local_7)
                    );
                }
                break;
            case 4:
                break;
            }

            func_80802CF0_chflysaucer(param_0);

            func_80802114_chflysaucer(
                param_0,
                *(f32 *)(local_0 + 0x18)
            );

            if (*(u8 *)(local_0 + 0x2E) == 0 &&
                func_80800000_chflysaucer(param_0) == 1) {
                func_800D2770(0xC0, 0);
                *(u8 *)(local_0 + 0x2E) = 1;
            } else {
                func_800D24E8(
                    0xC0,
                    D_80127194[0x21A],
                    0
                );
            }

            func_80802044_chflysaucer(param_0);
            break;
    }

    func_80802290_chflysaucer(param_0);
}

void func_80802CF0_chflysaucer(this) Actor *this;
{
    SaucerCam *local;
    f32 pos[3];
    f32 rot[3];
    f32 tmp[3];
    f32 h;

    local = func_80100094(this, 0);
    rot[0] = this->rotation[0];
    rot[1] = this->rotation[1];
    rot[2] = this->rotation[2] - local->unk1C;
    switch (local->unk24) {
    case 2:
        pos[0] = this->position[0];
        pos[1] = this->position[1] - 100.0f;
        pos[2] = this->position[2];
        rot[1] += 180.0f;
        rot[0] = -rot[0];
        rot[2] = this->rotation[2];
        func_800F81D4(func_800F54E4(), rot);
        rot[1] -= 180.0f;
        rot[0] = -rot[0];
        break;
    case 1:
        func_800EE7F8(tmp, this->rotation);
        tmp[2] = -tmp[2];
        func_800EF6A8(pos, tmp, 0.0f, -70.0f, 0.0f);
        func_800EF04C(pos, this->position);
        rot[2] = -rot[2];
        break;
    case 0:
        func_800EF4E4(pos, this->rotation[0], this->rotation[1], 0.0f, 90.0f, 0.0f);
        func_800EF04C(pos, this->position);
        rot[2] = -rot[2];
        break;
    case 3:
        h = local->unk10;
        h += 40.0f;
        func_800EF4E4(pos, this->rotation[0], this->rotation[1], 0.0f, h, 0.0f);
        func_800EF04C(pos, this->position);
        rot[2] = -rot[2];
        break;
    }
    func_800906B0(pos);
    func_800906DC(rot);
}

void func_80802ED8_chflysaucer(param_0) Actor *param_0;
{
    extern void func_800EFA4C(f32 *, f32, f32, f32);
    extern s32 func_800DC298(f32);
    u8 *local_0;
    s32 local_1;
    local_0 = (u8 *)func_80100094(param_0, 0);
    local_1 = func_800EA05C();
    local_0[0x2D] = 3;
    if (func_800D211C(0x8D) < 0x226) {
        func_800D2054(0, 0x8D, 0x226);
    }
    func_800EFA4C((f32 *)(local_0 + 0xC), 0.0f, 110.0f, 0.0f);
    switch (func_80800000_chflysaucer(param_0)) {
    case 0:
        if (_glcutDll_entrypoint_20()) {
            func_80801568_chflysaucer(param_0, 6);
        } else if (func_800D395C() && local_1 == 0x124) {
            func_80801034_chflysaucer(param_0);
            func_808005FC_chflysaucer(param_0);
            func_80801568_chflysaucer(param_0, 2);
        } else if (local_1 == 0xD6 && func_800DA298(0x94)) {
            func_80801034_chflysaucer(param_0);
        } else {
            func_800FFAB0(param_0);
        }
        break;
    case 6:
        if (local_1 == 0xD6) {
            func_80801034_chflysaucer(param_0);
            func_80801130_chflysaucer(param_0);
        } else {
            func_800FFAB0(param_0);
        }
        break;
    case 2:
        if (local_1 == 0x13C) {
            func_808017D0_chflysaucer(param_0);
        } else {
            func_800FFAB0(param_0);
        }
        break;
    case 3:
        if (local_1 == 0x124) {
            func_808017D0_chflysaucer(param_0);
        } else {
            func_800FFAB0(param_0);
        }
        break;
    case 4:
        if (local_1 == 0x13B) {
            func_808017D0_chflysaucer(param_0);
        } else {
            func_800FFAB0(param_0);
        }
        break;
    case 5:
        if (local_1 == 0x124) {
            func_808017D0_chflysaucer(param_0);
        } else {
            func_800FFAB0(param_0);
        }
        break;
    case 1:
        if (local_1 == 0x124) {
            func_800DA3B8(0x6E9, func_800DC298(0.001f) ? 1 : 0);
            func_80801568_chflysaucer(param_0, 2);
        }
        break;
    }
}

void func_80803150_chflysaucer(param_0) Actor *param_0;
{
    void *local_0;
    local_0 = func_80100094(param_0, 0);
    func_8080149C_chflysaucer(param_0);
    func_80801534_chflysaucer(param_0);
    if (!param_0->unk64_19) func_808009DC_chflysaucer(param_0, 0);
    func_808012A4_chflysaucer(param_0, 0);
    func_808021C0_chflysaucer(param_0, local_0, 3);
}

void func_808031C8_chflysaucer(u8 **param_0) {
    u8 local_0 = func_800D731C(*(u16 *)(*param_0 + 0x14));
    if (local_0) {
        func_800DBE60(local_0, 0, 0);
        func_800DBE60(local_0, 1, 4);
        func_800DBE60(local_0, 2, 8);
    }
}

f32 func_80803224_chflysaucer(Actor *param_0)
{
    void *local_0;
    f32 local_1[3];
    f32 local_2[3];
    f32 local_4;
    void *local_3;
    local_0 = func_800B27E0(func_801039E4(param_0->unk0));
    local_3 = func_800AE080(*(s16 *)((u8 *)param_0->unk0 + 0x10));
    func_800AE630(local_3, local_0, 0x2A, local_1);
    func_800AE630(local_3, local_0, 0x2B, local_2);
    local_4 = func_800F1828(local_1, local_2);
    return local_4;
}

void func_8080329C_chflysaucer(Actor *param_0, f32 *param_1, f32 *param_2, f32 param_3)
{
    u8 *local_0;
    void *local_1;
    void *local_2;
    Vec3f local_3;
    f32 local_4;
    Vec3f local_5;
    s32 local_6;
    Vec3f local_7;
    s32 local_8;
    Vec3f local_9;
    s32 local_10;

    local_0 = func_80100094(param_0, 0);
    local_1 = func_800D674C(0x829);
    local_2 = func_800D674C(0x82A);
    func_800D70F8(0x829, 1);
    func_800D70F8(0x82A, 1);
    local_4 = func_80803224_chflysaucer(param_0);
    *(f32 *)(local_0 + 0x1C) = local_4;
    func_800EE7F8(local_3.f, param_2);
    local_3.pos.z += local_4;
    switch (local_0[0x24]) {
    case 2:
        if (local_2) {
            local_6 = func_80104200(*(s16 *)local_0);
            func_800EF6A8(local_5.f, param_2, 0.0f, 105.0f, 8.0f);
            func_800EF04C(local_5.f, param_1);
            func_8008B304(local_6);
            func_800DF41C(func_8008C27C(func_8008AEDC(local_6)));
            func_800DF440(0);
            func_800DF830((u32)*(u16 *)((u8 *)param_0 + 0x7A) >> 14);
            func_800DE448(local_5.f, local_3.f, param_0->scale * 0.95f, NULL, (s32)local_2);
        }
        break;
    case 1:
    case 3:
        if (local_2) {
            local_8 = func_80104200(*(s16 *)local_0);
            func_800EF6A8(local_7.f, param_2, 0.0f, *(f32 *)(local_0 + 0x10) + 35.0f, 15.0f);
            func_800EF04C(local_7.f, param_1);
            func_8008B304(local_8);
            func_800DF41C(func_8008C27C(func_8008AEDC(local_8)));
            func_800DF440(0);
            func_800DF830((u32)*(u16 *)((u8 *)param_0 + 0x7A) >> 14);
            func_800DE448(local_7.f, local_3.f, param_0->scale * 0.95f, NULL, (s32)local_2);
        }
        break;
    }
    if (local_0[0x24] == 2 && local_1) {
        local_10 = func_80104200(*(s16 *)(local_0 + 2));
        func_800EF6A8(local_9.f, param_2, 0.0f, 105.0f, 11.0f);
        func_800EF04C(local_9.f, param_1);
        func_8008B304(local_10);
        func_800DF41C(func_8008C27C(func_8008AEDC(local_10)));
        func_800DF440(0);
        func_800DF830((u32)*(u16 *)((u8 *)param_0 + 0x7A) >> 14);
        func_800DE448(local_9.f, local_3.f, param_0->scale * 0.95f, NULL, (s32)local_1);
    }
    func_800D70F8(0x829, 0);
    func_800D70F8(0x82A, 0);
}

void func_808035C4_chflysaucer(param_0, param_1) Actor *param_0; u32 *param_1;
{
    extern void func_800EFA4C(f32 *, f32, f32, f32);
    extern void func_800EF6A8(f32 *, f32 *, f32, f32, f32);
    extern void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4[3];
    u8 *local_0;
    f32 local_5[3];
    s32 local_7;
    local_0 = (u8 *)func_80100094(param_0, 0);
    func_800DF744(1, 0);
    if (1) {}
    switch (local_0[0x24]) {
    case 2:
        func_800E41CC();
        func_800EFA4C(local_3, 0.0f, 0.0f, 300.0f);
        func_800EFD24(local_4);
        func_800E3BAC(local_3);
        func_800E3C30(local_4);
        func_800E3CE8();
        func_800E44FC(param_1);
        func_800EFA4C(local_2, -10.0f, -180.0f, 0.0f);
        func_800EFA4C(local_1, 0, -180.0f, 163.0f);
        break;
    case 1:
        func_800EE7F8(local_2, param_0->rotation);
        func_800EE7F8(local_5, param_0->rotation);
        local_5[2] = -local_5[2];
        func_800EF6A8(local_1, local_5, 0, -180.0f, 0);
        func_800EF04C(local_1, param_0->position);
        local_2[2] = -local_2[2];
        break;
    case 0:
        func_800DF744(1, 1);
    case 3:
        func_800EE7F8(local_1, param_0->position);
        func_800EE7F8(local_2, param_0->rotation);
        local_2[2] = -local_2[2];
        break;
    }
    if (!param_0->unk64_20) {
        func_808031C8_chflysaucer(param_0);
    }
    func_80101970(param_0);
    func_800DF47C(func_801015D0, param_0);
    func_800DE448(local_1, local_2, param_0->scale, (f32 *)func_801018D8(param_0), func_8010347C(param_0->unk0));
    local_2[0] -= 5.0f;
    if (param_0->unk7C_12) {
        local_7 = func_800B27E0(func_801039E4(param_0->unk0));
        func_8080329C_chflysaucer(param_0, local_1, local_2, *(f32 *)&param_1);
        func_800AE630(func_800AE080(*(s16 *)((u8 *)param_0->unk0 + 0x10)), local_7, 3, local_0 + 0xC);
    }
    if (local_0[0x24] == 2) {
        func_800E4208();
        func_800E44FC(param_1);
    }
}

int chflysaucer_entrypoint_1()
{
    return (int)&D_80804668_chflysaucer;
}

s32 func_80803844_chflysaucer(void)
{
    f32 local_0;

    local_0 = func_800DC0C0();
    if (func_800DA298(0x6E9)) return 2;
    if (local_0 < 0.5f) return 0;
    if (local_0 < 0.8333333f) return 1;
    return 2;
}

void func_808038C4_chflysaucer(Unk80132ED0 *param_0, f32 *param_1, f32 *param_2, s32 param_3, s32 param_4, f32 param_5)
{
    f32 local_0[3];
    Actor *local_1;

    local_1 = func_80108474(0x2A4, param_1, (s32)(param_2[1] + 180.0f));
    local_0[0] = param_2[0];
    local_0[1] = param_2[1];
    local_0[2] = (f32)param_3 - param_2[2];
    local_1->unk3C = param_0;
    local_1->rotation[0] = -local_0[0];
    local_1->unk79_4 = param_4;
    func_800EF6A8(local_1->position, local_0, 0.0f, 150.0f, 1000.0f);
    func_800EF04C(local_1->position, param_1);
    func_800EE7F8((f32 *)((u8 *)local_1 + 0x28), param_1);
    local_1->unk58 = param_5;
}

void func_808039B8_chflysaucer(Unk80132ED0 *param_0, f32 *param_1, f32 *param_2, s32 *param_3, s32 param_4, f32 param_5)
{
    s32 *local_0;
    s32 local_1;
    s32 i;

    for (i = 0; param_3[i] != -1; i++) {
        switch (param_4) {
        case 1:
            local_1 = func_80803844_chflysaucer();
            break;
        case 2:
            local_1 = 0;
            break;
        case 3:
            local_1 = 1;
            break;
        case 4:
            local_1 = 2;
            break;
        case 5:
            local_1 = D_808046B0_chflysaucer[i];
            break;
        default:
            break;
        }
        func_808038C4_chflysaucer(param_0, param_1, param_2, param_3[i], local_1, param_5);
    }
}

void func_80803AF0_chflysaucer(Actor *param_0, s32 param_1, s32 param_2, f32 param_3)
{
    f32 local_0[3];
    f32 local_1[3];
    s32 local_3;
    void *local_2;

    local_2 = param_0->unk0;
    local_3 = 0x447A0000;
    func_80800DAC_chflysaucer(param_0, local_0, local_1, local_3);
    local_1[0] = -local_1[0];
    func_808039B8_chflysaucer(local_2, local_0, local_1, &D_808046C4_chflysaucer, param_1, param_3);
}

void func_80803B60_chflysaucer(Actor *param_0)
{
    switch (param_0->unk79_4) {
    case 1:
        func_80103140(param_0, 0x826, param_0->unk0->unk16);
        break;
    case 2:
        func_80103140(param_0, 0x827, param_0->unk0->unk16);
        break;
    }
    param_0->scale = 0.3f;
    ((f32 *)param_0->actorData)[3] = 100000000.0f;
}

void func_80803BE8_chflysaucer(s32 arg0) 
{
}
void func_80803BF0_chflysaucer(Actor *param_0, s32 param_1)
{
  unsigned short new_var;
  s32 *local_0;
  local_0 = (s32 *) (&param_0->unk0);
  func_80102424(param_0, param_1);
  if ((((new_var = local_0[0x72 / 4]) & 0xFFFFu) >> 10) == 2)
  {
    _subaddiefade_entrypoint_3(param_0);
    func_8010A800(param_0, 2);
  }
}

void func_80803C3C_chflysaucer(Actor *param_0)
{
    switch (param_0->unk70_10) {
    case 1:
        if (param_0->unk58 > 0.0f) param_0->unk58 -= func_800D8FF8();
        else func_80803BF0_chflysaucer(param_0, 2);
        break;
    case 2:
        _subaddiefade_entrypoint_6(param_0, -60);
        break;
    }
}

int func_80803CC4_chflysaucer(s32 param_0, s32 param_1)
{
  s32 local_0;
  local_0 = func_800B53A4(6);
  func_800BABB8(local_0, param_0 + 4, param_0 + 4, 0x3FB33333, &D_808046DC_chflysaucer);
  func_800BA3FC(local_0, param_1);
  func_800BA22C(local_0, 6);
}

s32 func_80803D30_chflysaucer(Actor *param_0, s32 param_1, u32 param_2)
{
    Unk80132ED0 *local_0;

    switch (param_1) {
    case 0x40: {
        s16 *local_1;
        local_0 = (Unk80132ED0 *)(*(u32 *)&param_2);
        if (_subaddiefade_entrypoint_0(param_0) >= 0x61) {
            func_80803CC4_chflysaucer(param_0, D_80804704_chflysaucer[param_0->unk79_4]);
            _chscorepoints_entrypoint_2(param_0->unk79_4 + 1, 0, param_0->position, 1);
            local_1 = &D_801275C8;
            *local_1 = *local_1 + param_0->unk79_4 + 1;
            func_80803BF0_chflysaucer(param_0, 2);
            func_8010A570(param_0);
        }
        if (*(u16 *)((u8 *)local_0 + 0x18) & 1) {
            func_8010114C(local_0, 0x98, 0);
        }
        break;
    }
    default:
        return 0;
    }
    return 1;
}

int chflysaucer_entrypoint_2()
{
  return &D_8080470C_chflysaucer;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/flysaucer.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * Labels inside an object are linker symbols in undefined_syms.us.txt: D_808045DA_chflysaucer = D_808045A4_chflysaucer + 0x36
 * extern declarations adjusted to the object (same addresses): D_80804668_chflysaucer -> int[], D_808046C4_chflysaucer -> s32[], D_808046DC_chflysaucer -> int[], D_8080470C_chflysaucer -> int[] */
extern void func_80101870();
extern void func_80108ED0();
u8 D_80804260_chflysaucer[20] = { 0x0, 0x13, 0x5, 0xE7, 0x0, 0xA, 0x0, 0xB3, 0x0, 0x16, 0x42, 0x68, 0x0, 0x1, 0x4, 0xE2, 0x9, 0xC4, 0x0, 0x0 };
f32 D_80804274_chflysaucer[8] = { -1.0f, 0.89f, 0.91f, 0.97f, 0.93f, 0.95f, -1.0f, -1.0f };
FlySound D_80804294_chflysaucer[8] = { 0x446, 0x7FBC, 1.0f, 0x439, 0x7FBC, 1.0f, 0x436, 0x7FBC, 1.0f, 0x43A, 0x7FBC, 1.0f, 0x43B, 0x7FBC, 1.0f, 0x43C, 0x7FBC, 1.0f, 0x43D, 0x7FBC, 1.0f, 0x420, 0x7FBC, 1.0f };
u8 D_808042D4_chflysaucer[80] = { 0x0, 0x0, 0x2, 0x1, 0x0, 0x0, 0x0, 0x0, 0x33, 0x33, 0x1, 0x0, 0x40, 0x0, 0x0, 0x0, 0x51, 0xEB, 0x1, 0x0, 0x40, 0x0, 0x0, 0x0, 0x61, 0x47, 0x1, 0x0, 0x40, 0x0, 0x0, 0x0, 0x73, 0x32, 0x1, 0x0, 0x40, 0x0, 0x0, 0x0, 0x85, 0x1E, 0x1, 0x0, 0x40, 0x0, 0x0, 0x0, 0x9E, 0x34, 0x1, 0x0, 0x40, 0x0, 0x0, 0x0, 0xAB, 0x84, 0x1, 0x0, 0x40, 0x0, 0x0, 0x0, 0xB5, 0xC1, 0x1, 0x0, 0x40, 0xC, 0xCC, 0xCD, 0xC5, 0x1D, 0x1, 0x0, 0x40, 0x20, 0x0, 0x0 };
u8 D_80804324_chflysaucer[152] = { 0xC, 0xCC, 0x1, 0x0, 0x40, 0x79, 0x99, 0x9A, 0x19, 0x99, 0x1, 0x0, 0x40, 0x40, 0x0, 0x0, 0x33, 0x33, 0x1, 0x0, 0x40, 0xC, 0xCC, 0xCD, 0x3F, 0xFF, 0x1, 0x0, 0x40, 0xC, 0xCC, 0xCD, 0x46, 0x66, 0x1, 0x0, 0x40, 0x19, 0x99, 0x9A, 0x4C, 0xCC, 0x1, 0x0, 0x40, 0x0, 0x0, 0x0, 0x53, 0x32, 0x1, 0x0, 0x40, 0x0, 0x0, 0x0, 0x59, 0x99, 0x1, 0x0, 0x40, 0x0, 0x0, 0x0, 0x5F, 0xFF, 0x1, 0x0, 0x40, 0x0, 0x0, 0x0, 0x66, 0x66, 0x1, 0x0, 0x40, 0x0, 0x0, 0x0, 0x73, 0x32, 0x1, 0x0, 0x40, 0x88, 0x0, 0x0, 0x7F, 0xFF, 0x1, 0x0, 0x40, 0x80, 0x0, 0x0, 0x97, 0x9, 0x1, 0x0, 0x3F, 0x80, 0x0, 0x0, 0x99, 0x99, 0x3, 0x1, 0x0, 0x0, 0x0, 0x0, 0x9E, 0xB7, 0x1, 0x0, 0x3F, 0x80, 0x0, 0x0, 0xB3, 0x32, 0x1, 0x0, 0x40, 0x0, 0x0, 0x0, 0xBF, 0xFF, 0x1, 0x0, 0x40, 0x53, 0x33, 0x33, 0xCC, 0xCC, 0x1, 0x0, 0x40, 0x39, 0x99, 0x9A, 0xD4, 0x7A, 0x1, 0x0, 0x40, 0x19, 0x99, 0x9A };
u8 D_808043BC_chflysaucer[184] = { 0x6, 0x66, 0x1, 0x0, 0x40, 0x0, 0x0, 0x0, 0x11, 0x26, 0x1, 0x0, 0x40, 0x0, 0x0, 0x0, 0x1F, 0xFF, 0x1, 0x0, 0x40, 0x0, 0x0, 0x0, 0x26, 0x66, 0x1, 0x0, 0x40, 0x0, 0x0, 0x0, 0x2A, 0x3D, 0x1, 0x0, 0x40, 0x20, 0x0, 0x0, 0x2E, 0x14, 0x1, 0x0, 0x40, 0x26, 0x66, 0x66, 0x31, 0xEB, 0x1, 0x0, 0x40, 0xC, 0xCC, 0xCD, 0x34, 0x7A, 0x1, 0x0, 0x40, 0xC, 0xCC, 0xCD, 0x39, 0x99, 0x1, 0x0, 0x40, 0x26, 0x66, 0x66, 0x3F, 0xFF, 0x1, 0x0, 0x40, 0x0, 0x0, 0x0, 0x57, 0x9, 0x7, 0x1, 0x0, 0x0, 0x0, 0x0, 0x59, 0x99, 0x4, 0x0, 0x3F, 0xC0, 0x0, 0x0, 0x73, 0x32, 0x1, 0x0, 0x3F, 0xB3, 0x33, 0x33, 0x78, 0x51, 0x1, 0x0, 0x3F, 0xD9, 0x99, 0x9A, 0x7D, 0x70, 0x1, 0x0, 0x40, 0x0, 0x0, 0x0, 0x82, 0x8E, 0x1, 0x0, 0x40, 0x19, 0x99, 0x9A, 0x85, 0x1E, 0x1, 0x0, 0x40, 0x20, 0x0, 0x0, 0x8A, 0x3C, 0x1, 0x0, 0x40, 0x20, 0x0, 0x0, 0xAF, 0x5B, 0x1, 0x0, 0x3F, 0x99, 0x99, 0x9A, 0xBD, 0x6F, 0x1, 0x0, 0x3F, 0x99, 0x99, 0x9A, 0xC8, 0xF4, 0x1, 0x0, 0x3F, 0x99, 0x99, 0x9A, 0xD8, 0x51, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0xD9, 0x98, 0x1, 0x0, 0x40, 0x0, 0x0, 0x0 };
u8 D_80804474_chflysaucer[160] = { 0xC, 0xCC, 0x1, 0x0, 0x40, 0x59, 0x99, 0x9A, 0x13, 0x33, 0x1, 0x0, 0x40, 0x59, 0x99, 0x9A, 0x19, 0x99, 0x1, 0x0, 0x40, 0x53, 0x33, 0x33, 0x1F, 0xFF, 0x1, 0x0, 0x40, 0x4C, 0xCC, 0xCD, 0x26, 0x66, 0x1, 0x0, 0x40, 0x4C, 0xCC, 0xCD, 0x2C, 0xCC, 0x1, 0x0, 0x40, 0x33, 0x33, 0x33, 0x33, 0x33, 0x1, 0x0, 0x40, 0x33, 0x33, 0x33, 0x3F, 0xFF, 0x1, 0x0, 0x3F, 0xD9, 0x99, 0x9A, 0x4C, 0xCC, 0x1, 0x0, 0x3F, 0xD9, 0x99, 0x9A, 0x59, 0x99, 0x1, 0x0, 0x3F, 0xC0, 0x0, 0x0, 0x66, 0x66, 0x1, 0x0, 0x3F, 0xC0, 0x0, 0x0, 0x73, 0x32, 0x1, 0x0, 0x3F, 0xC0, 0x0, 0x0, 0x7F, 0xFF, 0x1, 0x0, 0x3F, 0xC0, 0x0, 0x0, 0x8C, 0xCC, 0x1, 0x0, 0x3F, 0xC0, 0x0, 0x0, 0x99, 0x99, 0x1, 0x0, 0x3F, 0xC0, 0x0, 0x0, 0xA6, 0x65, 0x1, 0x0, 0x3F, 0xC0, 0x0, 0x0, 0xB3, 0x32, 0x1, 0x0, 0x3F, 0xC0, 0x0, 0x0, 0xBF, 0xFF, 0x1, 0x0, 0x3F, 0xC0, 0x0, 0x0, 0xCC, 0xCC, 0x1, 0x0, 0x40, 0xC, 0xCC, 0xCD, 0xD4, 0x7A, 0x1, 0x0, 0x40, 0xC, 0xCC, 0xCD };
u8 D_80804514_chflysaucer[144] = { 0xF, 0x5C, 0x1, 0x0, 0x40, 0x0, 0x0, 0x0, 0x1E, 0xB8, 0x1, 0x0, 0x3F, 0xE6, 0x66, 0x66, 0x28, 0xF5, 0x1, 0x0, 0x3F, 0xE6, 0x66, 0x66, 0x33, 0x33, 0x1, 0x0, 0x3F, 0xC0, 0x0, 0x0, 0x3F, 0xFF, 0x1, 0x0, 0x3F, 0xE6, 0x66, 0x66, 0x4C, 0xCC, 0x1, 0x0, 0x40, 0x0, 0x0, 0x0, 0x59, 0x99, 0x1, 0x0, 0x3F, 0xCC, 0xCC, 0xCD, 0x70, 0xA3, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x73, 0x32, 0x4, 0x0, 0x3F, 0xC0, 0x0, 0x0, 0x8C, 0xCC, 0x1, 0x0, 0x3F, 0xC0, 0x0, 0x0, 0x99, 0x99, 0x1, 0x0, 0x3F, 0xE6, 0x66, 0x66, 0xA6, 0x65, 0x1, 0x0, 0x3F, 0xE6, 0x66, 0x66, 0xB3, 0x32, 0x1, 0x0, 0x3F, 0xE6, 0x66, 0x66, 0xBF, 0xFF, 0x1, 0x0, 0x3F, 0xE6, 0x66, 0x66, 0xCC, 0xCC, 0x1, 0x0, 0x3F, 0xE6, 0x66, 0x66, 0xD6, 0x44, 0x1, 0x0, 0x3F, 0xF3, 0x33, 0x33, 0xDF, 0xFF, 0x1, 0x0, 0x40, 0xC, 0xCC, 0xCD, 0xF3, 0x32, 0x4, 0x1, 0x0, 0x0, 0x0, 0x0 };
u8 D_808045A4_chflysaucer[68] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40, 0x6, 0x66, 0x66, 0x0, 0x91, 0x0, 0x41, 0x40, 0x82, 0x8F, 0x5C, 0x0, 0x92, 0x0, 0x42, 0x3F, 0x54, 0x7A, 0xE1, 0x0, 0x93, 0x0, 0x41, 0x3F, 0x54, 0x7A, 0xE1, 0x0, 0x93, 0x0, 0x1, 0x3F, 0x54, 0x7A, 0xE1, 0x0, 0x93, 0x0, 0x1, 0x40, 0x6, 0x66, 0x66, 0x0, 0x91, 0x0, 0x41, 0x0, 0x5B, 0x0, 0xF, 0x0, 0x8, 0x0, 0x14, 0x0, 0x4E, 0x0, 0x0 };
s16 D_808045E8_chflysaucer[8] = { -0x1, 0x64, 0x19, 0x6E, 0x1B, 0x6A, -0x1, -0x1 };
u8 D_808045F8_chflysaucer[16] = { 0x42, 0xFA, 0x0, 0x0, 0x43, 0x2F, 0x0, 0x0, 0x43, 0x2F, 0x0, 0x0, 0x42, 0x48, 0x0, 0x0 };
u8 D_80804608_chflysaucer[16] = { 0x43, 0x48, 0x0, 0x0, 0x43, 0x7A, 0x0, 0x0, 0x43, 0x7A, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
u8 D_80804618_chflysaucer[12] = { 0xC5, 0xE5, 0xB8, 0x0, 0x44, 0xCE, 0x40, 0x0, 0xC5, 0x22, 0x40, 0x0 };
s16 D_80804624_chflysaucer[8] = { -0x1, 0x66, 0x1B, 0x6C, 0x1D, 0x68, -0x1, -0x1 };
s16 D_80804634_chflysaucer[10] = { 0x206, 0x13, 0x4E0, 0x16, 0x2710, 0x1, 0xC8, 0x7D0, 0x0, 0x0 };
s16 D_80804648_chflysaucer[10] = { 0x206, 0x13, 0x672, 0x16, 0x7530, 0x1D, 0x1, 0xC8, 0x7D0, 0x0 };
f32 D_8080465C_chflysaucer[3] = { 0.8f, 0.75f, 0.85f };
int D_80804668_chflysaucer[18] = { 0x20202A2, 0x6900001, (u32)&D_808045A4_chflysaucer, (u32)func_808024E0_chflysaucer, (u32)func_80105834, (u32)func_808035C4_chflysaucer, 0x9C40000, 0x4019999A, 0x0, 0x80024, (u32)func_80803150_chflysaucer, 0x0, 0x300000, (u32)func_80802ED8_chflysaucer, (u32)func_80107C2C, -0x7BFFFFFE, (u32)func_8080185C_chflysaucer, 0x0 };
s32 D_808046B0_chflysaucer[5] = { 0x2, 0x1, 0x0, 0x1, 0x2 };
s32 D_808046C4_chflysaucer[6] = { 0x50, 0x28, 0x0, -0x28, -0x50, -0x1 };
int D_808046DC_chflysaucer[10] = { 0x161200, 0x150000, 0xCC002B, 0x73008C, 0x22004C, 0x590026, 0x33002D, 0x1900258, 0xE000A, 0x140000 };
s16 D_80804704_chflysaucer[4] = { 0x9E4, 0x9E8, 0x9E0, 0x0 };
int D_8080470C_chflysaucer[21] = { 0x20402A4, 0x8250001, 0x0, (u32)func_80803C3C_chflysaucer, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x0, 0x4, (u32)func_80803BE8_chflysaucer, (u32)func_80108ED0, 0x0, (u32)func_80803B60_chflysaucer, (u32)func_80107C2C, 0x0, (u32)func_80803D30_chflysaucer, 0x0, 0x0, 0x0, 0x0 };
