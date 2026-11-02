#include "gc/collectDLL.h"

extern s16 D_80800BE2_gccollectDll;
extern s16 D_80800BE4_gccollectDll;
extern s16 D_80800BE6_gccollectDll;
extern s16 D_80800BE8_gccollectDll;
extern s16 D_80800BEA_gccollectDll;
extern s32 D_80800BEC_gccollectDll;

extern s16 D_80800BE0_gccollectDll[];

extern s32 D_80800C0C_gccollectDll[3];
extern u32 D_80800C18_gccollectDll[10];
extern u8 D_8012762C;

s32 func_80800000_gccollectDll(void)
{
    s32 var_s0;
    u32 temp_s1;

    //Seems to be some indicator for which level you are in
    temp_s1 = D_8012762C;
    if (temp_s1 == 0x13) //If we are in SM
    {
        return 0x5B;
    }
    var_s0 = func_800D0820(1); //This will always return 1 since 1(Jiggy) is a valid item
    //If the number of Jiggies is greater than or equal to 1 (Always true)
    if (func_800D0894(1) >= var_s0)
    {
        //Loop through all Jiggies
        do
        {
            if (func_800D06D4(var_s0, 1) == temp_s1) //Return the index of the first jiggy found associated with the level
            {
                return var_s0;
            }
            var_s0 += 1;
        } while (func_800D0894(1) >= var_s0);
    }
    return -1;
}

void gccollectDll_entrypoint_0(s32 arg0) 
{
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s0;

    var_s0 = func_800D0820(arg0);
    if (var_s0 < func_800D0894(arg0)) 
    {
        do {
            temp_v0 = func_800D0A80(var_s0, arg0);
            if (temp_v0 != 0) 
            {
                func_800DA524(temp_v0);
            }
            temp_v0_2 = func_800D0908(var_s0, arg0);
            if (temp_v0_2 != 0) 
            {
                func_800DA524(temp_v0_2);
            }
            var_s0 += 1;
        } while (var_s0 < func_800D0894(arg0));
    }
}

void gccollectDll_entrypoint_1(void)
{
    s32 var_s0;

    var_s0 = 0;
    do {
        gccollectDll_entrypoint_0(var_s0);
        var_s0 += 1;
    } while (var_s0 != 9);
}

void gccollectDll_entrypoint_2(void)
{
    gccollectDll_entrypoint_1();
}

void gccollectDll_entrypoint_3(void) {
}

void gccollectDll_entrypoint_4(void)
{
    s32 pad1;
    s32 pad2;
    s32 sp2C;
    s32 var_s0;
    //Get First Jiggy Index for current level
    s32 temp_v0 = func_80800000_gccollectDll();
    s32 iterator;

    //Store Jiggy Index in 8011AE60
    func_800CF870(temp_v0);
    if (temp_v0 != -1) //If we found a jiggy
    {
        sp2C = func_800CFA90();
        for (iterator = temp_v0; iterator < temp_v0 + 0xA; iterator++)
        {
            func_800D0778(iterator, 1, D_80800C0C_gccollectDll);
            func_800D05E4(iterator, 1, 0);
            func_800D0594(iterator, 1, 0);
        }
        //If we are not in a cutscene
        if (func_800DB9B0() == 0)
        {
            _gcgamefix_entrypoint_1(sp2C);
        }
    }
}

void gccollectDll_entrypoint_5(void)
{
    u32 var_s0 = 0;

    if (func_800CF87C() != -1)
    {
        //Iterate through the list of collectables that are virtual objects e.g. they do not exist in the map file
        for (var_s0 = 0; var_s0 < 0x16; var_s0 += 2)
        {
            //If the item hasn't been collected but has been spawned
            if ((func_800D0B68((u32)D_80800BE0_gccollectDll[var_s0], (u32)D_80800BE0_gccollectDll[var_s0 + 1]) == 0) && (func_800D0A9C((u32)D_80800BE0_gccollectDll[var_s0], (u32)D_80800BE0_gccollectDll[var_s0 + 1]) != 0))
            {
                //Set Spawned Flag False
                func_800D0B38(D_80800BE0_gccollectDll[var_s0], D_80800BE0_gccollectDll[var_s0 + 1]);
            }
        }
    }
}

s32 func_808002C4_gccollectDll(s32 param_0, s32 param_1)
{
  s8 *local_0;
  int new_var;
  if ((param_0 == D_80800BE0_gccollectDll[0]) && (param_1 == D_80800BE2_gccollectDll))
  {
    return 1;
  }
  if ((param_0 == D_80800BE4_gccollectDll) && (param_1 == D_80800BE6_gccollectDll))
  {
    return 1;
  }
  local_0 = &D_80800BEC_gccollectDll;
  if ((param_0 == D_80800BE8_gccollectDll) && (param_1 == D_80800BEA_gccollectDll))
  {
    return 1;
  }
  new_var = 1;
  loop_10:
  if ((param_0 == (*((s16 *) (((s8 *) local_0) + 0)))) && (param_1 == (*((s16 *) (((s8 *) local_0) + 2)))))
  {
    return 1;
  }

  if ((param_0 == (*((s16 *) (((s8 *) local_0) + 4)))) && (param_1 == (*((s16 *) (((s8 *) local_0) + 6)))))
  {
    return 1;
  }
  if ((param_0 == (*((s16 *) (((s8 *) local_0) + 8)))) && (param_1 == (*((s16 *) (((s8 *) local_0) + 0xA)))))
  {
    return 1;
  }
  if ((param_0 == (*((s16 *) (((s8 *) local_0) + 0xC)))) && (param_1 == (*((s16 *) (((s8 *) local_0) + 0xE)))))
  {
    return new_var;
  }
  local_0 += 0x10;
  if (local_0 == (s8 *)&D_80800C0C_gccollectDll)
  {
    return (param_0 == (*((s16 *) (((s8 *) local_0) + 0)))) * 0;
  }
  goto loop_10;
}

s32 func_808003E0_gccollectDll(void *param_0, void *param_1)
{
    s32 local_0;
    s32 local_1;
    void *local_6;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    s32 local_9;
    s32 local_11;
    f32 local_8[3];
    u8 *local_7;
    s32 local_12;

    local_4 = 0;
    local_0 = func_800CF87C();
    for (local_1 = local_0; local_1 < local_0 + 10; local_1++) {
        if (!func_800D0B68(local_1, 1) && (local_2 = func_800D0908(local_1, 1))) {
            local_3 = func_800D0684(local_1, 1);
            if (func_800EA05C() == local_3 && !func_808002C4_gccollectDll(local_1, 1) && func_800DA298(local_2)) local_4++;
        }
    }
    local_12 = local_4 * 8 + 2; local_4 *= 1; /* probe: reassigning local_4 blocks the propagation of local_12, so the size is its own live range in v0 and the +2 is not reassociated */
    local_6 = heap_realloc(param_0, *(s32 *)param_1 + local_12);
    local_7 = (u8 *)local_6 + *(s32 *)param_1 * 4;
    *(s16 *)local_7 = local_4;
    local_7 += 4;
    for (local_11 = local_0, local_4 = 0; local_11 < local_0 + 10; local_11++, local_4++) {
        if (!func_800D0B68(local_11, 1) && (local_9 = func_800D0908(local_11, 1))) {
            local_3 = func_800D0684(local_11, 1);
            if (func_800EA05C() == local_3 && !func_808002C4_gccollectDll(local_11, 1) && func_800DA298(local_9)) {
                *(s16 *)local_7 = local_4;
                local_7 += 2;
                func_800D07CC(local_11, 1, local_8);
                func_800EE940(local_7, local_8);
                local_7 += 6;
            }
        }
    }
    *(s32 *)param_1 = (local_7 - (u8 *)local_6) >> 2;
    return (s32)local_6;
}

void func_808005BC_gccollectDll(u32 arg0, Prop* arg1)
{
    Actor* sp24;
    s32 sp18[3];

    sp18[0] = (s32)arg1->position[0];
    sp18[1] = (s32)arg1->position[1];
    sp18[2] = (s32)arg1->position[2];
    sp24 = func_80108C90(0x21F, sp18, 0U, NULL);
    func_800D053C(arg0, 1);
    func_800D05E4((s32)arg0, 1, (s32)sp24->unk0);
    func_800CFBC8(sp24, arg0, 1, 0);
    if ((_glreflight_entrypoint_0() & 0xFF) != 0xFE) 
    {
        func_8010A570(sp24);
    }
}

s32 func_80800660_gccollectDll(void *param_0, void *param_1)
{
    s16 *local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;

    local_0 = (s16 *)((s32 *)param_0 + *(s32 *)param_1);
    local_1 = *local_0;
    local_0 += 2;
    for (local_2 = 0; local_2 < local_1; local_2++) {
        local_3 = *local_0++;
        local_4 = func_800CF87C() + local_3;
        if (func_800D0A9C(local_4, 1) && !func_800D0B68(local_4, 1)) {
            func_808005BC_gccollectDll(local_4, local_0);
        }
        local_0 += 3;
    }
    *(s32 *)param_1 = (s32 *)local_0 - (s32 *)param_0;
    return (s32)param_0;
}

s32 gccollectDll_entrypoint_6(void* arg0, void* arg1)
{
    if (func_800CF87C() == -1)
    {
        return arg0;
    }
    if (func_800CF87C() == 0x5B)
    {
        return arg0;
    }
    return func_808003E0_gccollectDll(arg0, arg1);
}

s32 gccollectDll_entrypoint_7(void* arg0, void* arg1) {
    if (func_800CF87C() == -1) 
    {
        return arg0;
    }
    if (func_800CF87C() == 0x5B) 
    {
        return arg0;
    }
    return func_80800660_gccollectDll(arg0, arg1);
}

void func_808007D8_gccollectDll(Prop* arg0) 
{
    f32 sp24[3];

    if ((func_800D0A9C((u32)arg0->FlagOrRotation, 1U) != 0) && (func_800D0B68((u32)arg0->FlagOrRotation, 1U) == 0) && (func_800D0634((u32)arg0->FlagOrRotation, 1) == 0))
    {
        func_808005BC_gccollectDll((u32)arg0->FlagOrRotation, arg0);
        return;
    }
    func_800EE88C(sp24, arg0->position);
    func_800D0778(arg0->FlagOrRotation, 1, &sp24);
}

Actor* func_80800890_gccollectDll(Prop* arg0, u32 arg1)
{
    s32 sp1C[3];
    s32 sp18;
    //If Item is spawned but not collected
    if ((func_800D0A9C(arg0->FlagOrRotation, arg1) != 0) && (func_800D0B68(arg0->FlagOrRotation, arg1) == 0))
    {
        sp1C[0] = (s32)arg0->position[0];
        sp1C[1] = (s32)arg0->position[1];
        sp1C[2] = (s32)arg0->position[2];
        sp18 = func_80108C90(D_80800C18_gccollectDll[arg1], sp1C, arg0->FlagOrRotation, arg0);
        if ((_glreflight_entrypoint_0() & 0xFF) != 0xFE) 
        {
            func_8010A570(sp18);
        }
        return sp18;
    }
    return 0;
}

void gccollectDll_entrypoint_8(s16* arg0)
{
    u32 sp34 = D_8012762C;
    Prop* var_s1;
    Prop* temp_v0;
    u32 var_s0;
    u32 temp_v0_2;
    Actor* var_s2;

    if ((func_800CF87C() != -1) && (arg0 != 0) && (func_800E9DC4(arg0) != 0))
    {
        var_s1 = func_800E9D68(arg0);
        temp_v0 = func_800E9D90(arg0);
        for (var_s1; var_s1 < temp_v0; var_s1++)
        {
            if (var_s1->unk6_1 == 6)
            {
                temp_v0_2 = var_s1->ItemID;
                var_s2 = NULL;
                switch (temp_v0_2)
                {
                case 0x1F5:
                    var_s0 = 0;
                    break;
                case 0x1F6:                     /* switch 3 */
                    var_s0 = 1;
                    break;
                case 0x1F7:                     /* switch 3 */
                    var_s0 = 2;
                    break;
                case 0x1F8:                     /* switch 3 */
                    var_s0 = 3;
                    break;
                case 0x201:                     /* switch 3 */
                    var_s0 = 4;
                    break;
                case 0x29D:                     /* switch 3 */
                    var_s0 = 7;
                    break;
                case 0x4E6:                     /* switch 3 */
                    var_s0 = 8;
                    break;
                default:
                    continue;
                }

                if (func_800CFFBC(var_s1->FlagOrRotation, var_s0) != 0)
                {
                    temp_v0_2 = func_800D06D4(var_s1->FlagOrRotation, var_s0);
                    if (temp_v0_2 == sp34 || temp_v0_2 == -1)
                    {
                        switch (var_s0)
                        {
                        case 1:
                            func_808007D8_gccollectDll(var_s1);
                            break;
                        case 3:
                            var_s2 = func_80800890_gccollectDll(var_s1, var_s0);
                            if (var_s2 != NULL)
                            {
                                var_s2->unk74_7 = var_s1->unk6_7;
                            }
                            break;
                        case 0:
                        case 2:
                        case 4:
                        case 7:
                        case 8:
                            var_s2 = func_80800890_gccollectDll(var_s1, var_s0);
                            break;
                        }
                        if (var_s2 != NULL)
                        {
                            func_800CFBC8(var_s2, var_s1->FlagOrRotation, var_s0, 0);
                        }
                    }
                }
            }
        }
    }
}