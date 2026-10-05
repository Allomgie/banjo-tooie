#include "core2/1E7BFA0.h"

extern s32 D_80119320[];
extern void func_80095870(s32, f32 *, f32 *);
extern s32 _fxsplash_entrypoint_2(f32 *, f32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern void func_8009FC34(void *, s32);
extern f32 func_8009BB5C();
extern void func_8008FE94();
extern void func_800BA930(s32, s16, s16, s16, s16, s16, s16);
extern void func_800BA22C(s32, s32);
extern PlayerState *func_800F53D0(s32);
extern s32 player_inWater(PlayerState *);
extern s32 func_8008FD48();
extern f32 _basnowball_entrypoint_5(PlayerState *);
extern void _basnowball_entrypoint_10(PlayerState *);
extern void func_8009DB04(PlayerState *, s32, f32, s32);
extern void func_8009DBF0(PlayerState *, s32, f32);
extern void func_8009DC98(PlayerState *, s32, f32, f32);
extern void _bashake_entrypoint_0(PlayerState *, s32, s32);
extern void _fxstep_entrypoint_10(s32, s32);
extern void _fxstep_entrypoint_13(s32, s32);
extern void _bsvan_entrypoint_2(PlayerState *);
extern void _bswasher_entrypoint_0(PlayerState *);
extern s32 func_8009E674(PlayerState *, s32);
extern s32 _bashoes_entrypoint_1(PlayerState *);
extern void func_8009C128(void *, f32 *);
extern void _fxstep_entrypoint_6(void *, f32 *);
extern f32 func_800964DC();
extern void _fxstep_entrypoint_5(void *, s32, f32);
extern void *baanim_getAnimCtrlPtr(void);
extern s32 anctrl_isAt(void *, f32);
extern void _fxstep_entrypoint_8(s32, f32, s32);
extern void _fxstep_entrypoint_9(s32 param_0);
extern void _fxstep_entrypoint_11(s32 param_0, f32 param_1, s32 param_2);
extern f32 D_801194D0[];
extern void func_800EFA4C(s32 param_0, f32 param_1, f32 param_2, f32 param_3);
extern u8 D_80119340[];
extern void _bsfirstp_entrypoint_6();
extern f32 _basnowball_entrypoint_4(void);
extern s32 D_80119430;
struct AnotherStruct { char pad[0x44]; int unk44; };
struct SomeStruct { char pad[0xA0]; struct AnotherStruct *unkA0; };
extern s32 func_8008EF3C(s32, s32);
extern f32 func_8009C150(void);
extern s32 func_800F3ED0(s32);
extern s32 player_isStable(s32);
extern void bastatetimer_set(void *param_0, s32 param_1, f32 param_2);
extern f32 func_800963E4(void *param_0);
extern s32 func_80096434(void *param_0);
extern s32 func_8009650C(void *param_0);
extern s32 func_80096518(void *param_0);
extern s32 func_80096628(void *param_0);
extern f32 func_800D8FF8(void);
extern f32 func_800F10B4(f32 param_0, f32 param_1, f32 param_2, f32 param_3, f32 param_4);
extern f32 func_800F13F0(f32 param_0, f32 param_1);
extern u8 unkA0[];
int func_800A2EDC(s32 param_0, f32 param_1);
void func_800A2EEC();
void func_800A2FCC();
void func_800A3148();

s32 func_800A26B0() 
{
    return 0xC;
}

void func_800A26B8(s32 param_0)
{
    f32 local_0[3];
    f32 local_1;
    f32 local_2;
    f32 local_3;
    func_8009C128(param_0, local_0);
    local_1 = func_800964DC(param_0);
    func_80095870(param_0, &local_2, &local_3);
    if (!(local_2 + local_3 < local_1 - local_0[1])) {
        local_0[1] = local_1;
        func_8009FC34(param_0, 1);
        func_800BABB8(_fxsplash_entrypoint_2(local_0, 25.0f), 0, 0, 1.0f, D_80119320);
    }
}

void func_800A275C(u8 *param_0, s32 param_1) {
  s32 pad0;
    volatile f32 sp38;
    s32 sp34;
    f32 sp30;
    s32 sp2C;

    func_8009FC34(param_0, 2);
    sp30 = func_800F10B4(func_8009BB5C(param_0), 0.0f, 500.0f, 70.0f, 250.0f);
    func_8008FE94((*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + 0x124))) + 4)), &sp34);
    if (param_1 == 0) {
        sp38 = func_800964DC(param_0);
    }
    sp2C = _fxsplash_entrypoint_2(&sp34, 8.0f);
    func_800BA930(sp2C, (s16) -sp30, 0x12C, (s16) -sp30, (s16) sp30, 0x15E, (s16) sp30);
    func_800BA22C(sp2C, 5);
}

void func_800A2848(s32 param_0, s32 param_1, s32 param_2)
{
    s32 local_1;
    s32 local_0;
    s32 local_3;
    PlayerState *local_2;
    local_2 = func_800F53D0(param_2);
    local_3 = param_1 == 4 || param_1 == 11 || ((param_1 == 21) != 0);
    local_0 = player_inWater(local_2);
    if (local_3) func_800A275C(local_2, param_1 == 21);
    switch (func_8008FD48(local_2)) {
    case 15:
        if (local_3 || local_0) _fxstep_entrypoint_13(param_0, 14);
        else func_8009DB04(local_2, 0x448, 1.0f, 5000);
        break;
    case 14:
        _bashake_entrypoint_0(local_2, 0, 0);
        _fxstep_entrypoint_13(param_0, 19);
        if (param_1 == 20) _fxstep_entrypoint_13(param_0, 20);
        break;
    case 19:
        _bashake_entrypoint_0(local_2, 0, 0);
        _fxstep_entrypoint_13(param_0, 22);
        break;
    case 1: case 11:
        if (func_8009E674(local_2, 0x80)) {
            switch (_bashoes_entrypoint_1(local_2)) {
            case 4: _fxstep_entrypoint_13(param_0, 23); break;
            case 5: _fxstep_entrypoint_13(param_0, 26); break;
            }
        }
        break;
    }
}

void func_800A2A00(s32 param_0, s32 param_1, s32 param_2) {
    PlayerState *local_2;
    s32 local_3;
    f32 local_0;
    s32 local_4;
    s32 local_5;
    f32 local_1;

    local_2 = func_800F53D0(param_2);
    local_5 = param_1 == 4;
    if (local_5 == 0) {
        local_5 = param_1 == 0xB;
        if (local_5 == 0) {
            local_5 = player_inWater(local_2) != 0;
        }
    }
    if (local_5 != 0) {
        func_800A26B8(local_2);
    }
    local_3 = func_8008FD48();
    switch (local_3) {                              
    case 2:                                         
        local_0 = _basnowball_entrypoint_5(local_2);
        _basnowball_entrypoint_10(local_2);
        local_1 = func_800F10B4(local_0, 0.0f, 1.0f, 1.5f, 0.85f);
        func_8009DB04(local_2, 0x56E, local_1, (s32)func_800F10B4(local_0, 0.0f, 1.0f, 8000.0f, 32767.0f));
        if (local_0 == 1.0f) {
            _bashake_entrypoint_0(local_2, 1, 2);
            return;
        }
    default:                                        
        return;
    case 14:                                        
        _fxstep_entrypoint_10(param_0, 0x13);
        if (param_1 == 0x14) {
            _fxstep_entrypoint_13(param_0, 0x14);
        }
        _bashake_entrypoint_0(local_2, 3, 3);
        return;
    case 19:                                        
        _fxstep_entrypoint_10(param_0, 0x16);
        _bashake_entrypoint_0(local_2, 3, 3);
        return;
    case 18:                                        
        _bashake_entrypoint_0(local_2, 1, 2);
        return;
    case 16:                                        
        func_8009DBF0(local_2, 0x4C7, 1.3f);
        _bashake_entrypoint_0(local_2, 1, 2);
        _bsvan_entrypoint_2(local_2);
        return;
    case 7:                                         
        func_8009DC98(local_2, 0x4C1, 0.9f, 0.92f);
        _bashake_entrypoint_0(local_2, 1, 2);
        _bswasher_entrypoint_0(local_2);
        return;
    case 1: ;                                         
    case 11:                                        
        if (func_8009E674(local_2, 0x80) != 0) {
            local_4 = _bashoes_entrypoint_1(local_2);
            switch (local_4) {                    
            case 4:                                 
                _fxstep_entrypoint_10(param_0, 0x17);
                return;
            case 5:                                 
                _fxstep_entrypoint_10(param_0, 0x1A);
                break;
            }
        }
        break;
    }
}

void func_800A2C84(param_0) void * param_0; {
    f32 sp2C[4];
    s32 t;
    func_8009C128(param_0, &sp2C[1]);
    _fxstep_entrypoint_6(**(void ***)((u8 *)param_0 + 0x124), &sp2C[1]);
    t = func_80096628(param_0);
    _fxstep_entrypoint_5(**(void ***)((u8 *)param_0 + 0x124), t, func_800964DC(param_0));
}

void func_800A2CE8(PlayerState *param_0, f32 param_1, s32 param_2)
{
    if (anctrl_isAt(baanim_getAnimCtrlPtr(), param_1))
    {
        func_800A2EEC(param_0, param_2);
    }
}

void func_800A2D2C(PlayerState *param_0, f32 param_1, s32 param_2)
{
  void *local_0 = baanim_getAnimCtrlPtr();
  if (anctrl_isAt(local_0, param_1))
  {
    func_800A2FCC(param_0, param_2);
  }
}

void func_800A2D70(u8 *param_0) {
    _fxstep_entrypoint_0(*(*(s32 **)((s8 *)(param_0) + (0x124))));
}

void func_800A2D94(u8 *param_0) {
    *(*(s32 **)((s8 *)(param_0) + (0x124))) = _fxstep_entrypoint_1();
    func_800A2EDC(param_0, 1.0f);
    _fxstep_entrypoint_3(*(*(s32 **)((s8 *)(param_0) + (0x124))), func_800D3948() == 0);
    _fxstep_entrypoint_4(*(*(s32 **)((s8 *)(param_0) + (0x124))), &func_800A2A00, (*(s32 *)((s8 *)(param_0) + (0x184))));
    _fxstep_entrypoint_7(*(*(s32 **)((s8 *)(param_0) + (0x124))), &func_800A2848, (*(s32 *)((s8 *)(param_0) + (0x184))));
}

void func_800A2E18(Actor *param_0) {
    s32 state;
    void *temp_v0;

    state = bs_getCurrentState();
    func_800A2C84(param_0);
    if ((func_8009CBDC(param_0, state) == 8) || (func_8009CA70(param_0, state, 0x40) != 0)) {
        temp_v0 = *(void **)((char *)param_0 + 0x124);
        _fxstep_entrypoint_8(*(s32 *)((char *)temp_v0 + 0), 0.2f, *(s32 *)((char *)temp_v0 + 8));
        return;
    }
    temp_v0 = *(void **)((char *)param_0 + 0x124);
    _fxstep_entrypoint_8(*(s32 *)((char *)temp_v0 + 0), 0, *(s32 *)((char *)temp_v0 + 8));
}

void func_800A2EAC(void *param_0)
{
  s32 *ptr;
  s32 val;
  char *new_var;
  new_var = (char *) param_0;
  func_800A2C84();
  ;
  ;
  _fxstep_entrypoint_9(*(*((s32 **) (new_var + 0x124))));
}

func_800A2EDC(s32 param_0, f32 param_1){
    f32 local_0;
    local_0 = param_1;
    *(f32*)(*(s32*)(param_0 + 0x124) + 0x8) = local_0;
}

void func_800A2EEC(param_0, param_1) u8 * param_0; s32 param_1; {
    s32 local_0;
    u8 *local_1;
    u8 *local_2;

    local_0 = bs_getCurrentState();
    func_800A2C84(param_0);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x124)))) + (4))) = (s8) param_1;
    if ((func_8009CBDC(param_0, local_0) == 8) || (func_8009CA70(param_0, local_0, 0x40) != 0)) {
        local_1 = (*(u8 **)((s8 *)(param_0) + (0x124)));
        _fxstep_entrypoint_11((*(s32 *)((s8 *)(local_1) + (0))), 0.2f, (*(s32 *)((s8 *)(local_1) + (8))));
        return;
    }
    local_2 = (*(u8 **)((s8 *)(param_0) + (0x124)));
    _fxstep_entrypoint_11((*(s32 *)((s8 *)(local_2) + (0))), 0.0f, (*(s32 *)((s8 *)(local_2) + (8))));
}

void func_800A2F90(u8 *param_0, s32 param_1) {
    _fxstep_entrypoint_2(*(*(s32 **)((s8 *)(param_0) + (0x124))), 0);
    func_800A2EEC(param_0, param_1);
}

void func_800A2FCC(param_0, param_1) u8 * param_0; s32 param_1;
{
  func_800A2C84();
 *((s8 *) (((char *) (*((u8 **) (param_0 + 0x124)))) + 4)) = (s8) param_1; { s32 *temp_var;
    ;
    if (param_0)
    {
    }
    _fxstep_entrypoint_12(*(*((s32 **) (((char *) param_0) + 0x124))));
  }
}

void func_800A300C(u8 *param_0) {
    *(*(s32 **)((s8 *)(param_0) + (0x124))) = func_800BC3F0(*(*(s32 **)((s8 *)(param_0) + (0x124))));
}

s32 func_800A3040() 
{
    return 0x58;
}

f32 func_800A3048(u8 *param_0)
{
    if (func_800D3E40(7) == 0) {
        return 1.0f;
    }
    if (func_8008E40C(param_0) != 0) {
        return 1.2f;
    }
    return *(f32 *)((u8 *)D_801194D0 + (*(u8 **)(param_0 + 0xA0))[0x29] * 4);
}

void func_800A30B4(s32 param_0, s32 param_1, s32 param_2) {
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;

    func_800A3148(param_0, &sp24, &sp20, &sp1C);
    sp18 = sp1C * 0.5f;
    func_800EFA4C(param_1, -sp24, sp20 - sp18, -sp24);
    func_800EFA4C(param_2, sp24, sp20 + sp18, sp24);
}

void func_800A3148(param_0, param_1, param_2, param_3) u8 * param_0; f32 * param_1; f32 * param_2; f32 * param_3; {
    u8 temp_v1;
    u8 *temp_v0;

    temp_v1 = *(u8 *)((char *)(*(u8 **)((char *)param_0 + 0xA0)) + 0x29);
    temp_v0 = D_80119340 + (temp_v1 * 12);
    *param_1 = *(f32 *)((char *)temp_v0 + 0);
    *param_2 = *(f32 *)((char *)temp_v0 + 4);
    *param_3 = *(f32 *)((char *)temp_v0 + 8);

    switch (temp_v1) {
    case 2:
        {
            f32 t0 = _basnowball_entrypoint_4();
            *param_1 *= t0;
            *param_2 *= t0;
            *param_3 *= t0;
        }
        return;
    case 9:
        _bsfirstp_entrypoint_6();
        return;
    }
}

void func_800A3200(u8 *param_0, f32 *param_1, f32 *param_2) {
    f32 local_0;
    u32 local_1;
    u8 *local_2;

    local_1 = (*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xA0)))) + (0x29)));
    local_2 = (u8 *)((local_1 * 8) + (u8 *)&D_80119430);
    *param_1 = (*(f32 *)((s8 *)(local_2) + (0)));
    *param_2 = (*(f32 *)((s8 *)(local_2) + (4)));
    if (local_1 == 2) {
        local_0 = _basnowball_entrypoint_4();
        *param_1 *= local_0;
        *param_2 *= local_0;
    }
}

TransformationId func_800A3274(PlayerState *param_0) {
    return ((u8 *)((*(s32 *)((char *)(param_0) + 160))))[0x29];
}

s32 func_800A3280(s32 param_0)
{
    return ((u8 *)(*(u8 **)(param_0 + 0xa0)))[0x2A];
}

f32 func_800A328C(u8 *param_0)
{

    return *(f32 *)((char *)(*(u8 **)((char *)param_0 + 0xA0)) + 0x48);
}

f32 func_800A3298(PlayerState *param_0)
{
    return *(f32 *)(((u8 *)*(void **)((u8 *)param_0 + 0xA0)) + 0x48) - func_800964DC();
}

void func_800A32C4(PlayerState *param_0, f32 param_1[3])
{
  int new_var;
  s32 new_var2;
  int new_var5;
  s32 new_var4;
  s32 *new_var3;
  new_var = 0xA0;
  new_var3 = (s32 *) (((s32) param_0) + new_var);
  if (((new_var5 = param_1 && param_1) && param_1) != 0)
  {
  }
  new_var4 = *new_var3;
  new_var2 = new_var4;
  func_800EE7F8((s32) param_1, new_var2);
}

s32 func_800A32EC(s32 param_0)
{
  short new_var;
  u8 new_var2;
  new_var = 0x2B;
  new_var2 = ((u8 *) ((s32 **) (param_0 + 0xA0))[0])[new_var];
  new_var = 5;
  return new_var2;
}

int func_800A32F8(struct SomeStruct *param_0)
{
    return param_0->unkA0->unk44;
}

int func_800A3304(s32 param_0)
{
  s32 *new_var;
  s32 local_0;
  new_var = &param_0;
  local_0 = func_800F8B88(*new_var);
  return local_0 == 1;
}

void func_800A3328(s32 param_0, s32 param_1)
{
  s32 new_var;
  int new_var2;
  unsigned char new_var3;
  new_var = param_1;
  new_var2 = 0x2C;
  new_var3 = 0;
  func_800EE7F8(new_var | 0, ((s32 *)param_0)[0x28] + new_var2);
}

s32 func_800A3354(s32 param_0)
{
  u8 **new_var;
  int new_var2;
  new_var2 = 0xFFFFFFFFFFFFFFFFu;
  ;
  param_0 = param_0;
  return ((u8 *) (*(&(*((u8 **) (param_0 + 160))))))[84];
}

s32 func_800A3360(s32 param_0)
{
  u8 new_var;
 new_var = ((u8 **) (param_0 + 0xA0))[0][0x55]; return new_var;
}

s32 func_800A336C(void *arg)
{
    return ((u8 *)(*(void **)((char *)arg + 0xA0)))[60];
}

f32 func_800A3378(f32 *param_0)
{
  unsigned int new_var;
  new_var = 0x28;
  return ((f32 **) param_0)[new_var][0xE] * ((unsigned int) 1.5f);
}

f32 func_800A3394(PlayerState *param_0){
    return *(f32 *)((char *)(*(struct ba_input_s **)((char *)param_0 + 0xA0)) + 0x24);
}

void func_800A33A0(PlayerState *player, f32 *param_1)
{
  char *new_var;
  if (1)
  {
    new_var = param_1;
  }
  func_800EE7F8(new_var, new_var = ((char *) (*((struct ba_unknown_C0_s **) (((char *) player) + 0xA0)))) + 12);
}

void func_800A33CC(PlayerState *player, f32 *param_1)
{
  char *new_var;
  if (1)
  {
    new_var = param_1;
  }
  func_800EE7F8(new_var, new_var = ((char *) (*((struct ba_unknown_C0_s **) (((char *) player) + 0xA0)))) + 24);
}

u8 func_800A33F8(s32 param_0)
{
  s32 new_var4;
  int new_var2;
  u8 new_var3;
  s32 new_var;
  u8 **new_var5;
  new_var = param_0;
  new_var2 = 0x54;
  dummy_label_933336:
  ;

  ;
  new_var5 = (u8 **) (new_var4 = new_var);
  ;
  new_var2 = 5;
  new_var2 = 0x28;
  new_var = new_var + new_var2;
  new_var3 = new_var5[new_var2][new_var2];
  return new_var3;
}

s32 func_800A3404(s32 param_0)
{
    return ((u8 *)(*(u8 **)(param_0 + 0xa0)))[0x3F];
}

void func_800A3410(PlayerState *param_0, s32 param_1)
{
  s32 local_0;
  ;
  if ((*((u8 *) (((char *) (*((s32 *) (((char *) param_0) + 0xA0)))) + 0x29))) == 0xA)
  {
    func_800947EC(param_0, 1, 0);
    func_800A0D68(param_0, 0);
  }
  *((u8 *) (((char *) (*((s32 *) (((char *) param_0) + 0xA0)))) + 0x29)) = param_1;
  if ((*((u8 *) (((char *) (*((s32 *) (((char *) param_0) + 0xA0)))) + 0x29))) == 0xA)
  {
    func_800947EC(param_0, 1, 1);
    func_800A0D68(param_0, 1);
  }
}

void func_800A34A0(void *arg, s32 v)
{
    ((s8 *)(*(void **)((char *)arg + 0xA0)))[42] = v;
}

void func_800A34AC(PlayerState *param_0, f32 param_1[3])
{
    func_800EE7F8(((s32 *)param_0)[0x28], param_1);
}

void func_800A34CC(void *arg, s32 v)
{
    ((s8 *)(*(void **)((char *)arg + 0xA0)))[43] = v;
}

func_800A34D8(s32 param_0, s32 param_1){
    *(s32*)(*(s32*)(param_0 + 0xA0) + 0x44) = param_1;
}

void func_800A34E4(void *arg, s32 v)
{
    ((s8 *)(*(void **)((char *)arg + 0xA0)))[60] = v;
}

void func_800A34F0(Actor *param_0)
{
  char *new_var;
 new_var = new_var + 0x58; func_800EE7F8((*((s32 *) ((char *) param_0 + 160))) + 12);
}

void func_800A3514(Actor *param_0)
{
  char *new_var;
  s32 *new_var2;
  new_var = (char *) param_0;
  new_var = new_var + 0x58;
  new_var = new_var + 0x48;
  new_var2 = &(*((s32 *) new_var));
  func_800EE7F8((*new_var2) + 24);
}

void func_800A3538(void *arg, s32 v)
{
    ((s8 *)(*(void **)((char *)arg + 0xA0)))[40] = v;
}

void func_800A3544(u8 *param_0, int param_1)
{
  *((s8 *) ((*((u8 **) (param_0 + 0xA0))) + 0x3F)) = param_1;
}

void func_800A3550(void *arg, s32 v)
{
    ((s8 *)(*(void **)((char *)arg + 0xA0)))[80] = v;
}

void func_800A355C(s32 param_0)
{
  f32 local_0;
  s32 local_1;
  s32 *local_2;
  local_0 = func_8009C150();
  local_1 = func_800F3ED0(param_0);
  if ((((player_isStable(param_0) != 0) || (player_inWater(param_0) != 0)) || ((local_1 == 0xA) && (func_8008EF3C(param_0, 0) != 3))) || (local_1 == 5))
  {
    func_800A3550(param_0, 1);
  }
  else
  {
    func_800A3550(param_0, 2);
  }
  local_2 = *((s32 **) (((char *) param_0) + 0xA0));
  if (((*((u8 *) (((char *) (*((s32 **) (((char *) param_0) + 0xA0)))) + 0x50))) != 2) || (!(local_0 <= (*((f32 *) (((char *) (*((s32 **) (((char *) param_0) + 0xA0)))) + 0x4C))))))
  {
    *((f32 *) (((char *) (*((s32 **) (((char *) param_0) + 0xA0)))) + 0x48)) = *((f32 *) (((char *) (*((s32 **) (((char *) param_0) + 0xA0)))) + 0x4C));
    *((f32 *) (((char *) (*((s32 **) (((char *) param_0) + 0xA0)))) + 0x4C)) = local_0;
  }
}

void func_800A3644(void *param_0)
{
  f32 sp3C;
  f32 sp38;
  f32 sp34;
  s32 sp30;
  s32 sp2C;
  u8 *temp_v1;
  sp34 = func_800D8FF8();
  sp38 = func_800963E4(param_0);
  sp30 = func_80096628(param_0);
  ;
  if ((*((u8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0xA0)))) + 0x3D))) != 0)
  {
    if (sp38 > 35.0f)
    {
      if (1)
      {
      }
      *((f32 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0xA0)))) + 0x38)) = 1.0f;
    }
    else
    {
      *((f32 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0xA0)))) + 0x38)) = 0.0f;
    }
  }
  else
  {
    sp3C = func_800F10B4(sp38, 20.0f, 60.0f, 0.6f, 1.3f);
    if ((func_80096518(param_0) == 0) && (!(sp30 & 0x50)))
    {
      sp2C = func_80096434(param_0);
      if ((func_8009650C(param_0) != 0) && (sp2C & 0x50))
      {
        sp30 = sp2C;
      }
    }
    if ((sp30 & 0x50) && (player_inWater(param_0) == 0))
    {
      *((f32 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0xA0)))) + 0x38)) = func_800F13F0((*((f32 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0xA0)))) + 0x38))) + (sp34 * sp3C), 1.0f);
    }
    else
    {
      *((f32 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0xA0)))) + 0x38)) = 0.0f;
    }
    if ((*((f32 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0xA0)))) + 0x38))) == 1.0f)
    {
      if (sp30 & 0x10)
      {
        bastatetimer_set(param_0, 5, 0.18f);
      }
      else
        if (sp30 & 0x40)
      {
        bastatetimer_set(param_0, 6, 0.18f);
      }
    }
  }
  *((s8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0xA0)))) + 0x3D)) = 0;
}

void func_800A380C(Actor *param_0)
{

    *(f32 *)((char *)(*(s32 **)((char *)param_0 + 0xA0)) + 0x38) = 0.98f;
}

void func_800A3820(u8 *param_0) {
    extern f32 func_8009C150();
    f32 local_0;

    func_800EFD24((*(u8 **)((s8 *)(param_0) + (0xA0))));
    func_800EFD24((*(u8 **)((s8 *)(param_0) + (0xA0))) + 0xC);
    func_8009C128(param_0, (*(u8 **)((s8 *)(param_0) + (0xA0))) + 0x2C);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xA0)))) + (0x3D))) = 0;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xA0)))) + (0x38))) = 0.0f;
    func_800A380C(param_0);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xA0)))) + (0x3C))) = 1;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xA0)))) + (0x40))) = 0.0f;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xA0)))) + (0x50))) = 0;
    local_0 = func_8009C150(param_0);
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xA0)))) + (0x48))) = local_0;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xA0)))) + (0x4C))) = local_0;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xA0)))) + (0x29))) = 0;
    func_800A3410(param_0, func_8009E958());
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xA0)))) + (0x54))) = 1;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xA0)))) + (0x55))) = 1;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xA0)))) + (0x3E))) = 1;
}

void func_800A38F0(PlayerState *param_0, s32 param_1, s32 param_2) {


    *(u8 *)((char *)((*(s32 *)((char *)(param_0) + 160))) + 0x54) = param_1;
    *(u8 *)((char *)((*(s32 *)((char *)(param_0) + 160))) + 0x55) = param_2;
}

void func_800A3904(PlayerState *param_0, s32 param_1)
{
  *(u8 *)(*(s32 *)((char *)param_0 + 0xA0) + 0x3E) = param_1;
}

void func_800A3910(void *arg, s32 v)
{
    ((s8 *)(*(void **)((char *)arg + 0xA0)))[61] = v;
}

int func_800A391C(s32 param_0, f32 param_1)
{
  int new_var;
  new_var = new_var + 0x50;
  new_var = param_0;
  if (1)
  {
    *((f32 *) ((*((s32 *)((char *)(new_var) + 160))) + 36)) = param_1;
  }
}

int func_800A392C(s32 param_0, s32 param_1)
{
  f32 local_0[3];
  func_8009C128(param_0, local_0);
  func_800C05B8(param_1, 2, local_0, 0, 0, 0, 0);
}

s32 func_800A3970(PlayerState *param_0, s32 param_1)
{
  f32 *local_0;
  s32 local_1;

  local_0 = *(f32**)((char*)param_0 + 0xA0);
  if (local_0[0x10] != 0.0f)
  {
    return 0;
  }
  local_0[0x10] = 10.0f;
  if (func_800A3274(param_0) == 0x11)
  {
    func_8009E7C8(param_0, 0x1F);
  }
  if (param_1 != 0)
  {
    return func_800A392C(param_0, param_1);
  }
  local_1 = func_800A3274(param_0);
  switch (local_1)
  {
    case 10:
      return func_800A392C(param_0, 0x1212);
    case 11:
      return func_800A392C(param_0, 0x1213);
    case 13:
      return func_800A392C(param_0, 0x1214);
    case 17:
      return func_800A392C(param_0, 0x1216);
    default:
      return func_800A392C(param_0, 0x1217);
  }
}

void func_800A3A80(Actor *param_0)
{
  f32 local_0[3];
  s32 local_1;
  f32 *new_var;
  u8 **local_2;

  local_2 = (*(s32 *)((char *)(param_0) + 0xA0));
  if ((*(f32 *)((char *)(local_2) + 0x40)) != 0.0f)
  {
    func_800D9078(&(*(s32 *)((char *)(local_2) + 0x40)));
  }
  if (player_isStable(param_0))
  {
    func_8009C128(param_0, (*(s32 *)((char *)(param_0) + 0xA0)) + 0x2C);
  }
  if ((player_isStable(param_0) != 0) || (func_8009E71C(param_0, 0xA) != 0))
  {
    baflag_clear(param_0, 5);
    baflag_clear(param_0, 0x12);
  }
  if (player_inWater(param_0) != 0)
  {
    baflag_clear(param_0, 5);
    baflag_clear(param_0, 0x12);
  }
  func_800A3644(param_0);
  func_800A355C(param_0);
  if (func_80096568(param_0, 0x600) != 0)
  {
    func_8009BD18(param_0, 0x3F400000);
  }
}
