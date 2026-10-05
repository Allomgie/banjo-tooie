#include "common.h"
#include "overlays/ba/playerstate.h"

extern s16 D_80117EC0;
extern void func_800BED18(void *, void *);
extern s32 func_800EA05C(void);
extern void func_800EE84C(void *, void *);
struct Unknown { s16 field_0; s16 field_2; s16 field_4; s16 field_6; s16 field_8; s16 field_A; s16 field_C; };
typedef struct { f32 first[3], second[3]; u8 active, disabled; } LocalBounds;
typedef struct { u8 pad[0xBC]; LocalBounds *bounds; u8 pad1[0xC4]; s32 index; } LocalPlayer;
extern f32 bastatetimer_get(PlayerState *,s32);
extern void func_8009EB0C(f32);
extern void func_8009E9FC(f32);

s32 func_80098890() 
{
    return 0x1C;
}

void func_80098898(u8 *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    s32 local_2;
    struct Unknown *local_3;
    f32 local_4;

    local_2 = func_800EA05C();
    func_800BED18(local_1, local_0);
    func_800EE84C(*((u8 **)(param_0 + 0xBC)) + 0xC, local_1);
    func_800EE84C(*((u8 **)(param_0 + 0xBC)), local_0);

    local_3 = (struct Unknown *)&D_80117EC0;
    while (local_3->field_0 != 0 && local_2 != local_3->field_0) local_3++;

    *(f32 *)(*(u8 **)(param_0 + 0xBC) + 12) -= local_3->field_2;

    *(f32 *)(*(u8 **)(param_0 + 0xBC) + 16) -= local_3->field_4;

    *(f32 *)(*(u8 **)(param_0 + 0xBC) + 20) -= local_3->field_6;

    *(f32 *)(*(u8 **)(param_0 + 0xBC)) += local_3->field_8;

    *(f32 *)(*(u8 **)(param_0 + 0xBC) + 4) += local_3->field_A;

    *(f32 *)(*(u8 **)(param_0 + 0xBC) + 8) += local_3->field_C;

    *(s8 *)(*(u8 **)(param_0 + 0xBC) + 0x18) = 0;
    *(s8 *)(*(u8 **)(param_0 + 0xBC) + 0x19) = 0;
}

void func_800989E4(LocalPlayer *param_0)
{
    f32 local_0[3];
    s32 local_1;
    s32 local_2;
    s32 local_3;
    if (!func_8008DAA8() || param_0->bounds->disabled) return;
    local_1 = func_800BF6B8();
    if (local_1 == 1) return;
    func_8009C128(param_0, local_0);
    if (local_1 == 2 || !func_800EFED0(param_0->bounds->second, param_0->bounds->first, local_0)) {
        if (!param_0->bounds->active) {
            param_0->bounds->active = 1;
            if (func_800D3948() || func_800D395C()) {
                _gcfrontend_entrypoint_12();
                return;
            }
            local_2 = 0;
            local_3 = 0;
            switch (func_800A3274(param_0)) {
            case 0x11: local_2 = 1; break;
            case 0xB: if (func_800F8B88() == 3) local_3 = 1; break;
            }
            if (local_2) { func_800F7B9C(param_0->index, 0x1F); return; }
            if (local_3) { func_800F7B9C(param_0->index, 0x88); return; }
            func_800A05DC(param_0);
            return;
        } else baphysics_set_type(param_0, 7);
    }
}

int func_80098B4C(s32 param_0[3], s32 param_1)
{
  s32 *ptr = param_0;
  s32 val = !param_1;
  s32 t7;
  *((u8 *) (((char *) ptr[0x2F]) + 25)) = (u8) val;
}

int func_80098B5C(s32 param_0[3], s32 param_1, s32 param_2)
{
  func_800EE7F8(param_1 | 0, param_0[0x2F] + 0xC);
  func_800EE7F8(param_2, param_0[0x2F]);
}

s32 func_80098BA0() 
{
    return 0xC;
}

int func_80098BA8(s32 param_0, s32 param_1)
{
  if (func_80091E80(param_0, 1))
  {
    func_80092444(param_0, param_1);
  }
}

void func_80098BE0(s32 param_0)
{
    s32 local_0;
    local_0 = param_0 | 0;
    if (func_800A9420(*(s32 *)(param_0 + 0x184))) {
        if (func_8009AD78(param_0, 8) != 0) {
            _baeggcursor_entrypoint_1(param_0);
        }
        if (func_8009AD78(param_0, 0xB) != 0) {
            _bsfirstp_entrypoint_37(param_0);
        }
    }
}

void func_80098C48(u8 *param_0) {
    (*(s8 *)((s8 *)((*(s32 **)((s8 *)(param_0) + (0xB8)))) + (8))) = 1;
    func_8009AD90();
    _badronemem_entrypoint_3(param_0);
    _bastatemem_entrypoint_3(param_0);
    func_800A3820(param_0);
    *(*(s32 **)((s8 *)(param_0) + (0xB8))) = 0;
    bakey_init(param_0);
    func_8009FE78(param_0);
    func_8009C038(param_0);
    _badrone_entrypoint_32(param_0);
    _badust_entrypoint_11(param_0);
    func_800955CC(param_0);
    baflag_clearAll(param_0);
    func_800A0FF0(param_0);
    bastick_reset(param_0);
    bainput_init(param_0);
    _bainvisible_entrypoint_3(param_0);
    func_80098408(param_0);
    func_8009CBFC(param_0);
    func_8009E7AC(param_0);
    func_800A16F4(param_0);
    func_80091E20(param_0);
    func_80094644(param_0);
    _baeggcursor_entrypoint_5(param_0);
    _bafpctrl_entrypoint_8(param_0);
    _bapackctrl_entrypoint_3(param_0);
    _bababykaz_entrypoint_2(param_0);
    func_800A4168(param_0);
    _bacough_entrypoint_3(param_0);
    func_80091EC8(param_0);
    _badeathmatch_entrypoint_1(param_0);
    _baduo_entrypoint_6(param_0);
    _baattach_entrypoint_4(param_0);
    func_80098898(param_0);
    func_8009AC6C(param_0);
    func_8009B4FC(param_0);
    func_8009BD50(param_0);
    func_8009BF04(param_0);
    func_80098538(param_0);
    func_8009CC90(param_0);
    baroll_reset(param_0);
    func_8009CF98(param_0);
    func_80094F38(param_0);
    func_800A0C44(param_0);
    func_80095068(param_0);
    func_80090938(param_0);
    func_8009105C(param_0);
    bastatetimerlist_init(param_0);
    _bahold_entrypoint_1(param_0);
    func_80095AD0(param_0);
    _bamum_entrypoint_2(param_0);
    baanim_init(param_0);
    func_800A21C8(param_0);
    func_80092898(param_0);
    func_8008E618(param_0);
    _basetup_entrypoint_4(param_0);
    func_8009D4D8(param_0);
    func_800A1F78(param_0);
    _bashoes_entrypoint_4(param_0);
    func_8009E390(param_0);
    _basquash_entrypoint_2(param_0);
    func_800A2D94(param_0);
    _batranslate_entrypoint_2(param_0);
}

void func_80098E64(PlayerState *param_0)
{
    s32 local_4;
    s32 local_0;
    f32 local_1;
    s32 local_2;
    if (func_800A3274(param_0)==0xE) {
        if (baflag_isTrue(param_0,0x40)) {
            func_800A3410(param_0,0xD);
            func_800F8EBC(param_0->unk184);
        }
    }
    local_4=bs_getCurrentState(param_0);
    local_0=func_8009CBDC(param_0,local_4);
    if (func_8008DAA8(param_0)) {
        func_8009E880();
        if (func_800A81C4() || func_800EA068(0x800)) _bashoes_entrypoint_6(param_0,1);
        local_1=0.0f;
        local_2=0;
        if (func_8008E39C(param_0)) {
            local_1=bastatetimer_get(param_0,3);
            local_2=1;
        } else if (func_8009E674(param_0,0x40)) {
            local_2=1;
        }
        if (local_2) func_8009EAD0(2);
        func_8009EB0C(local_1);
        func_8009EAF4(_bashoes_entrypoint_1(param_0));
        func_8009E9D8(func_800A3274(param_0));
        func_8009E9FC(0.0f);
        switch (local_0) {
            case 8: func_8009E9FC(bastatetimer_get(param_0,2)); break;
            case 9: if (func_800A3274(param_0)==6) func_8009EAD0(4); break;
            case 18: func_8009EAD0(3); break;
            case 19: func_8009EAD0(6); break;
            case 20: func_8009EAD0(7); break;
        }
    }
    { s32 local_3;
    local_3=func_8009E71C(param_0,5) ? 1 : 0;
    local_3 &= func_800EA068(8) ? 1 : 0;
    func_8009EB18(local_3);
    }
    bs_setState(param_0, 0x5A);

    _baattach_entrypoint_3(param_0);
    func_8008E6BC(param_0);
    func_80091054(param_0);
    _bababykaz_entrypoint_1(param_0);
    bastatetimerlist_free(param_0);
    _baeggcursor_entrypoint_4(param_0);
    func_80094538(param_0);
    func_80092A1C(param_0);
    func_800A22A8(param_0);
    baanim_free(param_0);
    func_80095C10(param_0);
    _bahold_entrypoint_2(param_0);
    _bamum_entrypoint_1(param_0);
    _basetup_entrypoint_3(param_0);
    func_8009D5E0(param_0);
    func_800A2058(param_0);
    _bashoes_entrypoint_3(param_0);
    _basquash_entrypoint_1(param_0);
    func_800A2D70(param_0);
    _batranslate_entrypoint_1(param_0);
    _bastatemem_entrypoint_2(param_0);
    _badronemem_entrypoint_2(param_0);
    _bapackctrl_entrypoint_2(param_0);
    _baduo_entrypoint_5(param_0);
    func_8009E388(param_0);
    _bafpctrl_entrypoint_7(param_0);
    func_80091E18(param_0);
    bakey_free(param_0);
    _bacough_entrypoint_2(param_0);
    _badeathmatch_entrypoint_2(param_0);
    func_80091EA8(param_0);
    _bainvisible_entrypoint_4(param_0);
    func_8009AD88(param_0);
    func_800A4160(param_0);

    (*(u8 **)((u8 *)param_0 + 0xB8))[8] = 0;
}

int func_8009919C(u8* param_0, s32 param_1, s32 param_2)
{
  *(s32*)(*(u32*)(param_0 + 0xb8)) = param_1;
  *((s32*)(*(u32*)(param_0 + 0xb8)) + 1) = param_2;
}

void func_800991B0(u8 *param_0)
{
  s32 sp24;
  s32 sp20;
  s32 (*temp_v1)(s32);
  u8 *temp_v0;
  sp24 = func_800EA068(8) == 0;
  sp20 = func_800DA298(0x6B5);
  if (func_80091E80(param_0, 0x20) != 0)
  {
    func_80092AB0(param_0);
    func_80099970(param_0);
    func_8009CF04(param_0);
    bastatetimerlist_update(param_0);
    func_800A0DDC(param_0);
    bakey_update(param_0);
    bastick_update(param_0);
    bainput_update(param_0);
    if (func_8009AD78(param_0, 2) != 0)
    {
      _baduo_entrypoint_13(param_0);
    }
    func_8009E83C(param_0);
    if ((func_80091E80(param_0, 2) != 0) && (func_8008E454(param_0) != 0))
    {
      func_8009B590(param_0);
    }
    if (func_8009AD78(param_0, 6) != 0)
    {
      _batranslate_entrypoint_4(param_0);
    }
    func_8009C25C(param_0);
    if (sp24 != 0)
    {
      func_8009561C(param_0);
    }
    func_80095C94(param_0);
    if (func_80091E80(param_0, 2) != 0)
    {
      func_8009BF34(param_0);
      baroll_update(param_0);
      func_8009D088(param_0);
    }
    if (sp20 != 0)
    {
      func_80091110(param_0);
    }
    if (func_80091E80(param_0, 0x10) != 0)
    {
      baanim_update(param_0);
    }
    func_800A2060(param_0);
    if (sp24 != 0)
    {
      func_800987CC(param_0);
    }
    if (func_8009AD78(param_0, 4) != 0)
    {
      func_80090A4C(param_0);
    }
    if (sp24 != 0)
    {
      func_800951F4(param_0);
    }
    if (func_8009AD78(param_0, 3) != 0)
    {
      _badust_entrypoint_13(param_0);
    }
    func_8009C08C(param_0);
    func_8008E6F0(param_0);
    if (func_8009AD78(param_0, 0xE) != 0)
    {
      _bahold_entrypoint_3(param_0);
    }
    func_800A10A0(param_0);
    func_8009BDE4(param_0);
    func_800A3A80(param_0);
    func_800A4B08(param_0);
    if ((*((s32 *) (((s8 *) param_0) + 0x158))) == 0)
    {
      func_80094864(param_0);
    }
    else
    {
      _badeathmatch_entrypoint_3(param_0);
    }
    if (func_8009AD78(param_0, 9) != 0)
    {
      _bacough_entrypoint_5(param_0);
    }
    if (func_8009AD78(param_0, 8) != 0)
    {
      _baeggcursor_entrypoint_11(param_0);
    }
    if (func_8009AD78(param_0, 0xC) != 0)
    {
      _bainvisible_entrypoint_6(param_0);
    }
    if (func_8009AD78(param_0, 5) != 0)
    {
      _bamum_entrypoint_3(param_0);
    }
    if (func_8009AD78(param_0, 7) != 0)
    {
      _bafpctrl_entrypoint_15(param_0);
    }
    if (func_8009AD78(param_0, 0xA) != 0)
    {
      _basquash_entrypoint_4(param_0);
    }
    if (func_8009AD78(param_0, 0xD) != 0)
    {
      _bashoes_entrypoint_13(param_0);
    }
    func_80093448(param_0);
    func_800A2534(param_0);
    if (((func_800D3E40(4) != 0) && (func_8008DAA8(param_0) != 0)) && (func_8008E124(param_0) == 0))
    {
      func_800A18E8(param_0);
    }
    func_80091F30(param_0);
 goto dummy_label_665677; dummy_label_665677: ;
    temp_v0 = *((u8 **) (((s8 *) param_0) + 0xB8));
    temp_v1 = *((s32 (**)(s32)) (((s8 *) temp_v0) + 0));
    if (temp_v1 != 0)
    {
      temp_v1(*((s32 *) (((s8 *) temp_v0) + 4)));
      *((s32 (**)(s32)) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0xB8)))) + 0)) = 0;
    }
    func_800989E4(param_0);
  }
}

void func_80099544(u8 *param_0)
{
  u8 *local_4;
  u8 *new_var2;
  u8 *new_var3;
  int new_var;
  new_var = 0xB8;
  ;
  new_var2 = param_0;
  if ((*((u8 **) (param_0 + new_var)))[8])
  {
    baanim_defrag();
    func_800934C4(param_0);
    func_80096728(param_0);
    func_800A300C(new_var2);
    new_var3 = param_0;
 bakey_defrag(new_var3); func_800A266C(new_var3);
  }
}
