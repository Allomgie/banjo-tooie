#include "core2/1EC2350.h"

extern f32 func_800D8FF8(void);
extern s32 freelist_capacity();
extern u8 freelist_is_element_alive(void *param_0, s32 param_1);
extern s32 D_8012D680;
extern void bzero(void *, int);
extern void *freelist_new(int, int);
extern void *freelist_next(void **, s32 *);
extern void *func_800D674C(u32);
extern int D_80123500;
float func_800F3780(float arg0, s32 arg1, s32 arg2);
extern u16 D_80132560[];
extern u8 *D_80123524;
extern u8 D_8012D960[];
extern u8 D_8012D690[];
extern void *rare_memcpy(void *, const void *, size_t);
extern u8 unknown3_ROM_START[];
extern s16 D_80131CE0;
extern struct struct_func_80131CFC { s16 unk0; } D_80131CF6[];
typedef struct { u8 pad[0x50]; s32 local_0[80]; s16 local_1[80], local_2[80]; u8 pad1[0xD8]; u8 local_3[80][0xD8]; u8 pad2[0x7A0]; s32 local_4[2]; } CacheE90D8;
extern s32 D_80123514[];
extern s32 D_8012351C[];
extern s32 func_8001211C(void);
extern u8 unknown2_ROM_START[];
typedef struct { u8 pad_0[0x4650]; s16 local_0; } Struct800E9438;
typedef struct { u8 local_0[80]; s32 local_1[80]; s16 local_2[80]; s16 local_3[80]; } local_type;
extern u8 D_80132650[940][2];
extern s32 D_80123510;
typedef struct { u8 field_0[80]; s32 field_50[80]; s16 field_190[80], field_230[80]; u8 pad_2D0[0x4EC8 - 0x2D0]; s32 field_4EC8[2]; } CacheState;
int func_800E8CB0(u8);
int func_800E8CDC(u8 volatile param_0);
void func_800E8D28(u8 param_0, f32 param_1);
int func_800E8DE4(f32 param_0[3], f32 param_1);
void func_800E8E3C();
void func_800E95AC();

void func_800E8A60(void) {
}

void func_800E8A68(void)
{
    s32 local_0;
    f32 local_1 = func_800D8FF8();
    if (((void *) D_8012D680) != 0)
    {
        local_0 = 1;
        if (freelist_capacity(((void *) D_8012D680)) >= 2)
        {
            while (1)
            {
                if (freelist_is_element_alive(((void *) D_8012D680), local_0))
                {
                    func_800E8DE4(func_800E8CB0(local_0), local_1);
                }
                local_0++;
                if (local_0 >= freelist_capacity(((void *) D_8012D680)))
                {
                    break;
                }
            }
        }
    }
}

int func_800E8B04()
{
  if (D_8012D680 != 0)
  {
    freelist_free(D_8012D680);
    D_8012D680 = 0;
  }
}

int func_800E8B3C()
{
  if (D_8012D680 != 0)
  {
    D_8012D680 = freelist_defrag(D_8012D680);
  }
}

u8 func_800E8B74(u32 param_0) {
    void *ptr;
    s32 local_0;
    void *ret;
    if (!((void *) D_8012D680)) {
        D_8012D680 = freelist_new(0x50, 2);
    }
    ptr = freelist_next(((void * *) &D_8012D680), &local_0);
    if (param_0 != 0) {
        ret = func_800D674C(param_0);
        *(s16 *)ptr = *(s16 *)ret;
    } else {
        bzero(ptr, 0x50);
    }
    func_800E8CDC(local_0);
    return local_0;
}

void func_800E8C08(param_0) u8 param_0;{
    freelist_erase(D_8012D680, param_0);
    if(!freelist_used_count(D_8012D680)){
        freelist_free(D_8012D680);
        D_8012D680 = 0;
    }
}

s32 func_800E8C58(param_0) u8 param_0;
{
  s32 new_var;
  s32 local_0 = func_800E8CB0(param_0);
  s32 local_1 = *((s16 *) local_0);
  f32 local_2;
  s32 local_3 = (s32) ((*((f32 *) (local_0 + 12))) * ((f32) local_1));
  if (local_3 >= local_1)
  {
 local_3 = (new_var = local_1) - 1; } if (local_3) { }
  return local_3;
}

int func_800E8CB0(u8 param_0){
    freelist_at(D_8012D680, param_0);
}

int func_800E8CDC(u8 volatile param_0)
{
  f32 *local_0;
  local_0 = func_800E8CB0(param_0);
  local_0[1] = 0.0f;
  func_800E8D28(param_0, 1.0f);
  func_800E8D5C(param_0, &D_80123500, 2);
}

void func_800E8D28(u8 param_0, f32 param_1) {
    *(f32 *)((char *)func_800E8CB0(param_0) + 8) = param_1;
}

void func_800E8D5C(param_0, param_1, param_2) u8 param_0; void * param_1; s16 param_2;
{
  u8 *local_0;
  local_0 = func_800E8CB0(param_0);
  *(s16 *)(local_0 + 2) = param_2;
  rare_memcpy(local_0 + 0x10, param_1, param_2 * 8);
  func_800E8E3C(local_0);
}

void func_800E8DB0(param_0, param_1) u8 param_0; s32 param_1;
{
  *(s16 *)func_800E8CB0(param_0) = param_1;
}

int func_800E8DE4(f32 param_0[3], f32 param_1)
{
  f32 local_0;
  f32 local_1;
  local_0 = param_0[1];
  local_1 = param_1 / param_0[2];
  param_0[1] += local_1;
  param_0[1] -= (f32)(s32)param_0[1];
  func_800E8E3C(param_0);
}

void func_800E8E3C(arg0) s32 arg0;{
    *(f32*)(arg0 + 0xc) = func_800F3780(*(float*)(arg0 + 4), arg0 + 0x10, *(s16*)(arg0 + 2));
}

void func_800E8E70(void *param_0, s32 param_1, void *param_2, s32 param_3) {
    s32 sp34;
    s32 sp30;

    if (param_3 == 0) {
        osWritebackDCache(param_0, param_2);
        sp30 = func_80012F6C();
        osPiStartDma(sp30, 1, 0, param_1, param_0, param_2, func_80012F60());
        osRecvMesg(func_80012F60(), 0, 1);
        osInvalDCache(param_0, param_2);
        return;
    }
    osWritebackDCache(param_0, param_2);
    sp30 = func_80012EF4();
    osPiStartDma(sp30, 1, 0, param_1, param_0, param_2, func_80012EE8());
    osRecvMesg(func_80012EE8(), 0, 1);
    osInvalDCache(param_0, param_2);
}

func_800E8F68(param_0)
s32 param_0;
{
    s32 *ptr = (s32 *)param_0;
    if (ptr[9] != ptr[8]) {
        return &ptr[8];
    } else {
        return 0;
    }
}

void func_800E8F8C(s32 param_0, s32 param_1, s32 param_2, s32 param_3) {
    s32 *local_3;
    u8 *local_0;
    s32 local_1;
    local_3 = &param_1;
    local_3 = &param_2;
    local_1 = D_80132560[param_1] + param_2;
    func_800E8E70(D_8012D960, (void *)((u32)D_80123524 + (u32)local_1 * 0xD8), 0xD8, param_3);
    local_0 = D_8012D690 + (param_0 * 0xD8 + 0x3A8);
    rare_memcpy(local_0, D_8012D960, 0xD8);
    *(u8 **)(local_0 + 0x18) += (u32)unknown3_ROM_START;
}

int func_800E9048()
{
  return D_80131CE0;
}

s16 func_800E9054(s32 param_0)
{
  int new_var;
  long new_var2;
 do { new_var = (new_var2 = ((((((param_0 * 9) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu; return D_80131CF6[(((new_var & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu].unk0; } while (0);
}

void func_800E9070(s32 param_0, u8 *param_1)
{
    s32 diff;
    u8 *target;

    diff = param_0 - (s32)&D_8012D690;
    target = &D_8012D690[(diff - 0x3A8) / 0xD8];
    *target += 1;
}

void func_800E90A4(s32 param_0, u8 *param_1)
{
    s32 idx;
    u8 *ptr;
    idx = (param_0 - (s32)&D_8012D690) - 0x3A8;
    idx /= 0xD8;
    ptr = &D_8012D690[idx];
    --*ptr;
}

u8 *func_800E90D8(s32 param_0, s32 param_1, s32 param_2) {
    s32 local_0;
    s32 local_1;
    s32 local_2;
    local_2 = D_80132560[param_0] + param_1;
    local_1 = ((u8 *) D_80132650)[local_2 * 2 + param_2];
    if (local_1 != 0xFF) {
        (*((CacheE90D8 *) D_8012D690)).local_0[local_1] = func_8001211C();
        return (*((CacheE90D8 *) D_8012D690)).local_3[local_1];
    }
    if ((*((CacheE90D8 *) D_8012D690)).local_4[param_2] >= D_80123514[param_2] - D_8012351C[param_2]) {
        func_800E95AC(0, param_2);
        if ((*((CacheE90D8 *) D_8012D690)).local_4[param_2] >= D_80123514[param_2] - D_8012351C[param_2]) {
            (*((CacheE90D8 *) D_8012D690)).local_0[D_8012351C[param_2]] = func_8001211C();
            return (*((CacheE90D8 *) D_8012D690)).local_3[D_8012351C[param_2]];
        }
    }
    for (local_0 = D_8012351C[param_2]; local_0 < D_80123514[param_2]; local_0++) {
        if ((*((CacheE90D8 *) D_8012D690)).local_1[local_0] == -1) break;
    }
    func_800E8F8C(local_0, param_0, param_1, param_2);
    (*((CacheE90D8 *) D_8012D690)).local_1[local_0] = param_0;
    (*((CacheE90D8 *) D_8012D690)).local_2[local_0] = param_1;
    (*((CacheE90D8 *) D_8012D690)).local_0[local_0] = func_8001211C();
    (*((CacheE90D8 *) D_8012D690)).local_4[param_2]++;
    ((u8 *) D_80132650)[local_2 * 2 + param_2] = local_0;
    return (*((CacheE90D8 *) D_8012D690)).local_3[local_0];
}

void func_800E9300(s32 arg0,s32 arg1)
{
    func_800E90D8(arg0,arg1,0x1);
}

void func_800E9320(s32 param_0, s32 param_1)
{
  func_800E90D8(param_0, param_1, 0);
}

void func_800E9340(s32 param_0, s32 param_1, u32 param_2)
{
  s32 base = param_1 * 18;
  func_800E8E70(param_0, &unknown2_ROM_START[base + 8], 0x12, param_2);
  rare_memcpy(&D_8012D690[base + 0x4658], param_0, 0x12);
}

u8 *func_800E93AC(s32 param_0) {
    return (u8 *)&D_8012D690 + (param_0 * 18) + 0x4658;
}

void func_800E93CC(s32 param_0)
{
  u32 unk;
  unk = ((u32) unknown2_ROM_START) ^ (unk * 0);
  func_800E8E70(&D_80131CE0, (u8 *) unk, 8, param_0);
  ((u32) D_80123524) = ((D_80131CE0 * 18) + 11) & (-4);
  ((u32) D_80123524) += unk;
}

void func_800E9438(s32 param_0)
{
  u8 *temp;
  s32 i;
  s32 sum = 0;
  temp = heap_alloc(0x12);
  for (i = 0; i < (*((Struct800E9438 *) D_8012D690)).local_0; i++)
  {
      func_800E9340(temp, i, param_0);
      ((s16 *) D_80132560)[i] = sum;
      sum += *(s16 *)(temp + 0xE);
  }
  heap_free(temp);
}

/* The bss of this unit starts before the static in func_800E94E4; this
 * stands in for the 8 bytes at 0x80132550 that belong to it as well. */
static s32 D_80132550[2];
void func_800E94E4(void) {
    static struct {s32 local_0; s32 local_1;} D_80132558;
    s32 local_0;
    for (local_0 = 0; local_0 < 79; local_0++) {
        (*((local_type *) D_8012D690)).local_0[local_0] = 0;
        (*((local_type *) D_8012D690)).local_1[local_0] = 0;
        (*((local_type *) D_8012D690)).local_2[local_0] = -1;
        (*((local_type *) D_8012D690)).local_3[local_0] = -1;
    }
    for (D_80132558.local_0 = 0, D_80132558.local_1 = 0, local_0 = 0; local_0 < 940; local_0++) {
        D_80132650[local_0][0] = 255;
        D_80132650[local_0][1] = 255;
    }
}

int func_800E9574()
{
  func_800E94E4();
  func_800E93CC(0);
  func_800E9438(0);
  D_80123510 = 1;
}

void func_800E95AC(param_0, param_1) u32 param_0; s32 param_1; {
    s32 local_0;
    s32 local_1;
    s16 local_5;
    s32 local_2, local_3, local_4;
    s16 local_6;
    local_0 = func_8001211C();
    local_6 = -1;
    local_2 = D_8012351C[param_1];
    local_3 = D_80123514[param_1];
    for (local_1 = local_2; local_1 < local_3; local_1++) {
        local_5 = (*((CacheState *) D_8012D690)).field_190[local_1];
        if (local_6 == local_5) continue;
        if ((*((CacheState *) D_8012D690)).field_0[local_1] != 0) continue;
        if (param_0 >= (u32)(local_0 - (*((CacheState *) D_8012D690)).field_50[local_1])) continue;
        local_4 = D_80132560[local_5] + (*((CacheState *) D_8012D690)).field_230[local_1];
        ((u8 (*)[2]) D_80132650)[local_4][param_1] = 255;
        (*((CacheState *) D_8012D690)).field_190[local_1] = local_6;
        (*((CacheState *) D_8012D690)).field_4EC8[param_1]--;
    }
}

func_800E96B0(s32 param_0) {
    func_800E95AC(0xC8, param_0 | 0);
}
