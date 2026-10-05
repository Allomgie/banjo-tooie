#include "core2/1EA0AA0.h"

typedef struct { u8 pad0[6]; u16 f : 9; u16 rest : 7; } E_C71B0;
typedef struct { u8 pad0[4]; E_C71B0 *unk4; } S_C71B0;
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern u8 D_8011A8A0[];
extern void func_800FF000(s32);
extern s32 _gccubesearch_entrypoint_14(s32, s32);
extern unsigned char D_8012760D[7];
extern void func_800FECB8(u32 param_0);
typedef struct { u8 state; s8 disabled; } LocalState;

typedef struct {
    u8 unk0;
    s8 unk1;
} D_8012760C_unk;
extern u8 D_8011A904;
extern s16 D_8011A910[];
extern u8 D_8012760C;
extern u8 D_8012AAF0;

f32 func_800C71B0(s32 param_0, f32 param_1) {
    u32 t = ((S_C71B0 *)param_0)->unk4->f;
    f32 rv;
    if (t == 50) {
        rv = param_1;
    } else {
        rv = func_800F10B4((f32)t, 50.0f, 100.0f, 0.0f, 1.0f);
    }
    return rv;
}

void func_800C7230(s32 arg0)
{
    func_800FF01C(func_800C71B0(arg0, 0.2f));
}

void func_800C725C(s32 arg0)
{
    func_800C4308(func_800C71B0(arg0, 0.51f), 1.0f);
}

void func_800C7290(s32 arg0) 
{
    func_800FC9B4(1, func_800C71B0(arg0, 0.2f));
}
void func_800C72C0(s32* arg0)
{
    if (D_8011A904 != 0)
    {
        D_8011A904 = 0;
        arg0[1] = 0;
    }
}

void func_800C72E4(s32 arg0) 
{
}
void func_800C72EC(s32* arg0)
{
    if (D_8011A904 != 0) {
        D_8011A904 = 0;
        arg0[1] = 0;
    }
}

void func_800C7310(s32 arg0) 
{
    _gcgoto_entrypoint_8(0, 0);
}

s32 func_800C7338(s32 arg0)
{
    f32 sp1C[3];

    if (_gccubesearch_entrypoint_3(arg0, sp1C) != 0)
    {
        return 1;
    }
    return 0;
}

void func_800C7364(s32 arg0, s32 arg1, s32* arg2)
{
    if ((func_800C7338(arg0) != 0) && (*arg2 == 0))
    {
        *arg2 = arg1;
    }
}
void func_800C73A4(void) {
  s32 *ptr = ((s32 *)&D_8011A8A0);
  s32 val;
  func_800FF000(0);
  func_800FC9B4(0, 0);
  while (ptr != ((s32 *)&D_8011A8A0) + 0x19) {
      ptr[1] = _gccubesearch_entrypoint_14(*(s16 *)ptr, 0);
      if (ptr[1]) {
          if (ptr[2]) {
              ((void (*)(s32 *))ptr[2])(ptr);
          }
      }
      ptr += 5;
  }
  val = 0;
  func_800C7364(0x7b, 1, &val);
  func_800C7364(0x7c, 2, &val);
  func_800C7364(0x7d, 3, &val);
  func_800C7364(0x7e, 4, &val);
  func_800C7364(0x7f, 5, &val);
  if (val == 0) val = 2;
  func_80015178(val);
}

void func_800C7494(void) {
    void (*local_1)(void *);
    u8 *local_0;

    if (D_8012AAF0 != 0) {
        local_0 = ((s32 *) D_8011A8A0);
        do {
            if (*(s32 *)((char *)local_0 + 0x4) != 0) {
                local_1 = *(void (**)(void *))((char *)local_0 + 0xC);
                if (local_1 != NULL) {
                    local_1(local_0);
                }
            }
            local_0 += 0x14;
        } while (local_0 != ((u8 *)((s32 *) D_8011A8A0) + 0x64));
    }
}

void func_800C7500(void) {
    u8 *local_0;

    local_0 = &D_8011A8A0;
    do {
        if (*(u32 *)((char *)local_0 + 0x4) != 0) {
            if (*(u32 *)((char *)local_0 + 0x10) != 0) {
                ((void (*)(u8 *))*(u32 *)((char *)local_0 + 0x10))(local_0);
            }
        }
        local_0 = (u8 *)((char *)local_0 + 0x14);
    } while (local_0 != (D_8011A8A0 + 0x64));
    func_800C4308(0.0f, 1.0f);
}

void func_800C7574(s32 arg0, s32 arg1)
{
    if (arg1 == 2)
    {
        D_8012AAF0 = 1;
        return;
    }
    D_8012AAF0 = 0;
}

s32 func_800C75A0(s32 arg0)
{
    return D_8011A910[arg0];
}

u8 func_800C75B4(void) {
    return (*((D_8012760C_unk *) &D_8012760C)).unk0;
}

void func_800C75C0(void)
{
    func_800C77DC(1);
    func_800FC81C();
}

void func_800C75E8(void)
{
    (*((D_8012760C_unk *) &D_8012760C)).unk0 = 0;
    (*((D_8012760C_unk *) &D_8012760C)).unk1 = 0;
    func_800C77DC(1);
}

void func_800C7618(s32 param_0, s32 param_1)
{
    if (param_1 != 0)
    {
        if (func_800FCCD4(param_0) != 0)
        {
            if (param_1 == 1)
            {
                func_800FCDE0(param_0, 0, 0x3FC00000);
            }
            else
            {
                func_800FCDE0(param_0, -1, 0x3FC00000);
            }
            func_800FCAE0(param_0, param_1, 0x3E8);
            return;
        }
        func_800FC660(param_0);
        func_800FC788(param_0, 1);
        return;
    }
    func_800FCAE0(param_0, param_1, 0x3E8);
    func_800FCA90(param_0);
    func_800FC788(param_0, 0);
}

void func_800C76E8()
{
  s8 local_0;
  local_0 = *((s8 *) (((char *) (&D_8012760C)) + 1));
  if (((local_0 == 0) && (D_8012760C != 0)) && (D_8012760C != 1))
  {
    func_800C7618(func_800C75A0(D_8012760C), 1);
    func_800FECB8(0xA);
    local_0 = D_8012760D[0];
  }
  if ((!D_8012760C) && (!D_8012760C))
  {
  }
  *((s8 *) (((char *) (&D_8012760C)) + 1)) = (s8) (local_0 + 1);
}

void func_800C775C(void)
{
  int local_0;
  local_0 = 1;
  if (((s8 *) &D_8012760C)[local_0] == 1)
  {
    if ((((u8 *)((s8 *) &D_8012760C))[0] != 0) && ((local_0 = ((u8 *)((s8 *) &D_8012760C))[0]) != 1))
    {
      func_800C7618(func_800C75A0(((u8 *)((s8 *) &D_8012760C))[0]) | 0, -1);
      func_800FEC60(0xA);
    }
  }
  ((s8 *) &D_8012760C)[1]--;
  if (((s8) ((s8 *) &D_8012760C)[1]) < 0)
  {
    ((s8 *) &D_8012760C)[1] = 0;
  }
}

void func_800C77DC(s32 param_0)
{
    switch ((*((LocalState *) &D_8012760C)).state) {
    case 2: case 3: case 4: case 5: case 6: case 7: case 8:
        func_800C7618(func_800C75A0((*((LocalState *) &D_8012760C)).state), 0);
        break;
    case 1:
    default:
        if (!(*((LocalState *) &D_8012760C)).disabled) func_800FEC60(10);
        break;
    }
    (*((LocalState *) &D_8012760C)).state = param_0;
    if (!(*((LocalState *) &D_8012760C)).disabled) {
        switch ((*((LocalState *) &D_8012760C)).state) {
        case 2: case 3: case 4: case 5: case 6: case 7: case 8:
            func_800C7618(func_800C75A0((*((LocalState *) &D_8012760C)).state), -1);
            break;
        case 1:
        default:
            func_800FECB8(10);
            break;
        }
    }
}

void func_800C78CC(u32 arg0)
{
    if (arg0 != 0) {
        func_800C76E8();
        return;
    }
    func_800C775C();
}

void func_800C7900(void) 
{
    s32 sp1C;
    s32 temp_v0;

    if (((*((D_8012760C_unk *) &D_8012760C)).unk1 == 0) && ((s32)(*((D_8012760C_unk *) &D_8012760C)).unk0 >= 2) && (func_8001210C(3) != 0))
    {
        temp_v0 = func_800C75A0((*((D_8012760C_unk *) &D_8012760C)).unk0);
        sp1C = temp_v0;
        if (func_800FCCD4(temp_v0) == 0)
        {
            func_800C7618(sp1C, -1);
        }
    }
}