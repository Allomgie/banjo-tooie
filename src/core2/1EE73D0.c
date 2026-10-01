#include "common.h"

typedef struct { f32 duration; u32 index:14, unused:2, flags:16; } LocalEntry_8010DAE0;
extern LocalEntry_8010DAE0 D_80124740[];
extern void anctrl_reset(void *);
extern void anctrl_setDuration(void *,f32);
extern void anctrl_setIndex(void *,s32);
extern void anctrl_setPlaybackType(void *,s32);
extern void anctrl_start(void *);
extern void func_8008B10C(void *,f32);
extern void func_8008B188(void *,s32);
extern void func_8008B4A8(void *,s32);
extern f32 func_800DC0C0(void);
extern s32 func_800DC298(f32);
extern u8 *func_80104148();
extern u8 *func_80104268();
extern s32 func_800AE020(void);
extern void func_800DF72C(s32);
typedef struct { u8 pad[0x74]; u32 unused:4, enabled:1, rest:27; } LocalActor;
extern u8 *func_800A7180(void);
typedef struct { s16 id, pad2; u16 flags, pad6; } LocalEntry_8010DD20;
extern u8 D_80124744[];
extern void func_800ADFE0();

void func_8010DAE0(void *param_0, s32 param_1)
{
    s32 local_0;
    local_0 = D_80124740[param_1].flags;
    anctrl_reset(param_0);
    anctrl_setIndex(param_0, D_80124740[param_1].index);
    anctrl_setDuration(param_0, D_80124740[param_1].duration);
    if (local_0 & 1) {
        anctrl_setPlaybackType(param_0, 2);
        func_8008B4A8(param_0, (local_0 & 0x100) ? 0 : 1);
    }
    if (local_0 & 2) anctrl_setPlaybackType(param_0, 1);
    if (local_0 & 4) anctrl_setPlaybackType(param_0, 3);
    if (local_0 & 8) func_8008B188(param_0, 1);
    if (local_0 & 0x10) func_8008B188(param_0, 0);
    if (local_0 & 0x800) func_8008B188(param_0, func_800DC298(0.5f) ? 1 : 0);
    if (local_0 & 0x40) func_8008B10C(param_0, 0);
    if (local_0 & 0x80) func_8008B10C(param_0, 0.999f);
    if (local_0 & 0x400) func_8008B10C(param_0, func_800DC0C0());
    anctrl_start(param_0);
}

void func_8010DC50(s32 param_0) {
    u8 *local_0;
    u8 *local_1;
    local_0 = func_80104148(param_0);
    if (local_0[4] == 0) {
        local_1 = func_80104268(local_0 + 2);
        func_8010DAE0(local_1, param_0);
        *(u16 *)local_0 = func_800AE020();
    }
    local_0[4]++;
}

void func_8010DCB4(void) {
    s16 local_0;
    u8 local_1;
    u8 local_2;
    u8 *local_3;

    local_3 = func_80104148();
    local_2 = *(u8 *)((char *)local_3 + 0x4);
    local_1 = local_2 - 1;
    if ((s32) local_2 > 0) {
        *(u8 *)((char *)local_3 + 0x4) = local_1;
        if (!(local_1 & 0xFF)) {
            func_801042D8(local_3 + 2);
            func_800ADFE0(*(s16 *)((char *)local_3 + 0x0));
            local_0 = *(s16 *)((char *)local_3 + 0x8);
            *(s16 *)((char *)local_3 + 0x0) = 0;
            if (local_0 != 0) {
                func_80100E18(local_0);
                *(s16 *)((char *)local_3 + 0x8) = 0;
            }
        }
    }
}

void func_8010DD20(u8 *param_0, s32 param_1, u8 *param_2) {
    u8 *local_0;
    s32 local_1;
    u8 *local_2;
    union { u8 *pointer; s32 id; } local_3;
    s32 local_4;
    LocalEntry_8010DD20 *volatile local_5;

    local_0 = func_80104148(param_1);
    func_801015D0(param_0);
    if (((LocalActor *)param_0)->enabled) {
        local_1 = func_80104200(*(s16 *)(local_0 + 2));
        if (local_1 && *(s16 *)(local_0)) {
            if (*(u8 *)(local_0 + 5) == 0) {
                func_8008B304(local_1);
                local_4 = func_800B27E0(param_2);
                func_8008C200(*(s16 *)(local_0), local_4, func_8008AEDC(local_1));
                if ((*(u16 *)(D_80124744 + param_1 * 8) & 3) == 2) {
                    local_2 = func_800A7180();
                    *(s32 *)(local_0 + 0x10) = *(s32 *)(local_2 + 4) + 0x40;
                    func_800AE598(func_800AE080(*(s16 *)(local_0)), local_2 + 4);
                }
            }
            func_800DF72C(func_800AE080((local_3.id = *(s16 *)local_0,
                local_5 = &((LocalEntry_8010DD20 *) D_80124740)[param_1], local_3.id)));
            switch (local_5->flags & 3) {
            case 1:
                if (*(s16 *)(local_0 + 8) == 0) {
                    local_3.pointer = *(u8 **)param_0;
                    *(s16 *)(local_0 + 8) = func_80100D24(param_2, *(u16 *)(local_3.pointer + 0x14), 2, 0, *(u16 *)(local_3.pointer + 0x16), 0);
                    *(s32 *)(local_0 + 0xC) = *(s32 *)(param_2 + 0x28);
                }
                func_800DF818(func_80100A74(*(s16 *)(local_0 + 8), *(u8 *)(local_0 + 6)));
                *(s32 *)(param_2 + 0x28) = *(u8 *)(local_0 + 5) ? 0 : *(s32 *)(local_0 + 0xC);
                break;
            case 2:
                func_800DF714(*(s32 *)(local_0 + 0x10));
                break;
            }
        }
        *(u8 *)(local_0 + 5) = 1;
    }
}

int func_8010DEFC()
{
  s32 local_0;
  u8 *local_1;
  for (local_0 = 0; local_0 < 0xB; local_0++)
  {
    local_1 = func_80104148(local_0);
    local_1[5] = 0;
  }

}

void func_8010DF3C()
{
  s32 local_0;
  u8 *local_1;
  local_0 = 0;
  do
  {
    local_1 = func_80104148(local_0);
    if (*((s16 *) ((0, ((char *) local_1) + 0x2))))
    {
      func_8008ADE4(func_80104200(*((s16 *) (((char *) local_1) + 0x2))));
    }
    local_0 += 1;
  }
  while (local_0 != 11);
}

void func_8010DF98(void)
{
  s32 var_s0;
  u8 *temp_v0;
  var_s0 = 0;
  do
  {
    temp_v0 = func_80104148(var_s0);
    if ((((*((u8 *) (((s8 *) temp_v0) + 4))) != 0) || ((*((s16 *) (((s8 *) temp_v0) + 2))) != 0)) || ((*((s16 *) (((s8 *) temp_v0) + 8))) != 0))
    {
      *((u8 *) (((s8 *) temp_v0) + 4)) = 0U;
      *((s16 *) (((s8 *) temp_v0) + 2)) = 0;
      *((s16 *) (((s8 *) temp_v0) + 8)) = 0;
    }
    if ((*((s16 *) (((s8 *) temp_v0) + 0))) != 0)
    {
      func_800ADFE0(*((s16 *) (((s8 *) temp_v0) + 0)));
      *((s16 *) (((s8 *) temp_v0) + 0)) = 0;
    }
    var_s0 += 1;
  }
  while (var_s0 != 0xB);
}
