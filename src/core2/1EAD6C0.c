#include "common.h"

// TU-NOTE: D_8011B5B8 is the cheat table, 4 x u16 per cheat: unlock flag, disabled flag, active flag, value.
extern u16 D_8011B5B8[][4];
extern u16 D_8011B5BA[][4];
extern u16 D_8011B5BC[][4];
typedef struct {
    u16 unk_0;
    u16 unk_2;
    u16 unk_4;
    u16 unk_6;
} S8_D3F58;
extern S8_D3F58 D_8011B5C0[];
extern S8_D3F58 D_8011B608[];
extern void func_800DA3B8(s32);
extern void *func_800F54E4(void);
extern void func_800F4924(void *, s32);
extern u16 D_8011B5BE[][4];
typedef struct {
    s16 key;
    s16 val;
} P8011B620;
extern P8011B620 D_8011B620[];
void func_800D4298();
int func_800D42E8();
int func_800D433C();
int func_800D4398();

int func_800D3DD0(s32 cheat)
{
    u16 *unlock_flag = &D_8011B5B8[cheat][0];
    if (*unlock_flag) {
        return func_800DA298(*unlock_flag);
    }
    return 0;
}

// Matching: K&R parameter list, chained pointer copies and missing return are needed for the match.
s32 func_800D3E14(cheat)
s32 cheat;
{
    u16 *disabled_flag;
    u16 *disabled_flag2;
    u16 *disabled_flag3;
    disabled_flag3 = (disabled_flag = (disabled_flag2 = &D_8011B5BA[cheat][0]));
    func_800DA298(*disabled_flag);
}

// Matching: no return statement, needed for the match.
int func_800D3E40(s32 cheat)
{
    u16 *active_flag;
    active_flag = &D_8011B5BC[cheat][0];
    func_800DA298(*active_flag);
}

s32 func_800D3E6C(s32 cheat)
{
    u16 unlock_flag;
    if (func_800D3E14()) {
        return 0;
    }
    unlock_flag = D_8011B5B8[cheat][0];
    if (unlock_flag) {
        return func_800DA298(unlock_flag);
    }
    return 1;
}

// Matching: `| 0` and the extra block are needed for the match.
int func_800D3EC8()
{
    if (func_800D3E14()) {
        return 0 | 0;
    }
    {
        return 1;
    }
}

int func_800D3EF4(s32 cheat)
{
    u16 *unlock_flag = &D_8011B5B8[cheat][0];
    {
        if (*unlock_flag) {
            func_800DA544(*unlock_flag);
        }
    }
}

// Matching: chained pointer copies and missing return are needed for the match.
int func_800D3F2C(s32 cheat)
{
    u16 *disabled_flag;
    u16 *disabled_flag2;
    u16 *disabled_flag3;
    disabled_flag3 = (disabled_flag = (disabled_flag2 = &D_8011B5BA[cheat][0]));
    func_800DA544(*disabled_flag);
}

void func_800D3F58(s32 index, s32 flag)
{
    func_800DA3B8(D_8011B5C0[index - 1].unk_4);
    if (D_8011B608 == &D_8011B5C0[index]) {
        if (flag != 0) {
            func_800F4924(func_800F54E4(), 0x3E7);
        }
    }
}

unsigned short func_800D3FC0(s32 cheat)
{
    unsigned short *value;
    value = &D_8011B5BE[cheat][0];
    return *value;
}

// Apply cheat effects (infinite or doubled capacity) to eggs and feathers.
void func_800D3FD4(s32 enable)
{
    s32 has_effect;
    s32 eggs_on;
    s32 feathers_on;
    has_effect = 0;
    eggs_on = 0;
    feathers_on = 0;
    if (0 != func_800D3E40(0xA)) {
        func_800D42E8(0x40, enable);
        func_800D42E8(0x41, enable);
        func_800D42E8(0x42, enable);
        func_800D42E8(0x43, enable);
        func_800D42E8(0x44, enable);
        func_800D42E8(0x46, enable);
        func_800D42E8(0x47, enable);
        has_effect = eggs_on = feathers_on = 1;
    } else {
        if (func_800D3E40(2) != 0) {
            func_800D4398(0x40, enable);
            func_800D4398(0x41, enable);
            func_800D4398(0x42, enable);
            func_800D4398(0x43, enable);
            func_800D4398(0x44, enable);
            has_effect = eggs_on = 1;
        }
        if (func_800D3E40(1) != 0) {
            func_800D4398(0x46, enable);
            has_effect = 1;
            func_800D4398(0x47, enable);
            feathers_on = 1;
        }
    }
    if (has_effect == 0) {
        func_800D433C(0x40, enable);
        eggs_on = 1;
        feathers_on = 1;
        func_800D433C(0x41, enable);
        func_800D433C(0x42, enable);
        func_800D433C(0x43, enable);
        func_800D433C(0x44, enable);
        func_800D433C(0x46, enable);
        func_800D433C(0x47, enable);
    }
    if (enable == 0) {
        feathers_on = 0;
        eggs_on = 0;
    }
    func_800D4298(0x40, eggs_on);
    func_800D4298(0x41, eggs_on);
    func_800D4298(0x42, eggs_on);
    func_800D4298(0x43, eggs_on);
    func_800D4298(0x44, eggs_on);
    func_800D4298(0x46, feathers_on);
    func_800D4298(0x47, 0);
}

// Ability required for an item, 0x3C if none.
s16 func_800D41D8(item)
s32 item;
{
    s32 i;
    for (i = 0; i < 7; i++) {
        if (item == D_8011B620[i].key) {
            return D_8011B620[i].val;
        }
    }
    return 0x3C;
}

void func_800D4298(item, value) s32 item;
s32 value;
{
    s32 ability;
    ability = func_800D41D8();

if ((ability != 0x3C) && (func_800C6E38(ability) == 0)) {
    value = 0;
}

func_800D192C(item, value);
}

int func_800D42E8(item, value)
s32 item;
s32 value;
{
    s32 ability;
    ability = func_800D41D8();

if (ability != 0x3C && func_800C6E38(ability) == 0) {
    value = 0;
}

func_800D1960(item, -2, value);
}

int func_800D433C(item, value)
s32 item;
s32 value;
{
    s32 ability;
    ability = func_800D41D8(item);

if (ability != 0x3C) {
    ability = func_800C6E38(ability);
    if (!ability) {
        value = 0;
    }
}

func_800D1960(item, func_800D1ACC(item), value);
}

// Matching: `| 0` is needed for the match.
int func_800D4398(item, value)
s32 item;
s32 value;
{
    s32 ability;
    s32 temp;
    ability = func_800D41D8(item);

if (ability != 0x3C) {
    temp = func_800C6E38(ability | 0);
    if (!temp) {
        value = 0;
    }
}

temp = func_800D1ACC(item);
func_800D1960(item, temp << 1, value);
}

// TU-NOTE: the .data of this file (formerly asm/data/core2/1EAD6C0.data.s) is defined here in C, values from the ROM.
// Labels inside an object are linker symbols in undefined_syms.us.txt: D_8011B622 = D_8011B620 + 0x2,
// D_8011B626 = D_8011B624 + 0x2, D_8011B62A = D_8011B628 + 0x2.
// The extern for D_8011B608 is S8_D3F58[] (same address, uses written as NAME[0]).
S8_D3F58 D_8011B5C0[9] = {0x6C, 0x71, 0x534, 0xA, 0x6D, 0x72, 0x535, 0x5,  0x6E, 0x73, 0x536, 0x2,
                          0x6F, 0x74, 0x537, 0x2, 0x70, 0x75, 0x538, 0x55, 0x76, 0x77, 0x539, 0x1,
                          0x0,  0x78, 0x53A, 0xC, 0x0,  0x79, 0x53B, 0x22, 0x0,  0x7A, 0x53C, 0x2};
S8_D3F58 D_8011B608[3] = {0x0, 0x42, 0x53D, 0xB, 0x0, 0x4B, 0x4C, 0x97, 0x5A4, 0x446, 0x5A3, 0xCB};
P8011B620 D_8011B620[1] = {0x40, 0x6};
u32 D_8011B624[1] = {0x41002C};
u32 D_8011B628[6] = {0x42002F, 0x43002D, 0x44002E, 0x460009, 0x470012, 0x0};
