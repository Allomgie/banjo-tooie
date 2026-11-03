#include "common.h"

// TU-NOTE: D_8012AB70 holds 16 passenger slots of 0x30 bytes each; the structs below are views of it.

extern u8 D_8012AB71[];
typedef struct {
    u8 pad_0[0x1C];
    u8 committed_pos[0xC];
    f32 unk_28;
    s16 unk_2C;
    u8 pad_2E[2];
} Struct800CB3FC;
typedef struct {
    u8 pad_0;
    u8 state;
    s16 type;
    void *handlers;
    u8 pad_8[0x28];
} E_CB4D0;
extern s16 D_8012AB72[];
extern u8 D_8012AB70[];
extern u8 D_8012AB78[];
typedef struct {
    u8 pad_0[0x1C];
    u8 committed_pos[0xC];
    f32 unk_28;
    s16 unk_2C;
    u8 pad_2E[2];
} E_CB6B4;
typedef struct {
    u8 pad_0[8];
    f32 current_pos[3];
    f32 unk_14;
    s16 unk_18;
    s16 unk_1A;
    u8 pad_1C[0x14];
} E_CB764;
extern void func_800EE7F8(f32 *, f32 *);
typedef s32 (*Fn800CB7C4)(s32, s32, s32);
typedef struct {
    Fn800CB7C4 *(*fn)();
    s32 pad[11];
} S8012AB74;
extern S8012AB74 D_8012AB74[];
extern void func_800FC63C(s32, s32);
volatile char func_800CB698();

s32 func_800CB3E0(s32 index)
{
    return D_8012AB71[index * 48];
}

// Matching: volatile index needed for the match.
f32 func_800CB3FC(volatile s32 index, u32 param_1, s32 *param_2)
{
    Struct800CB3FC *slot;
    func_800EE7F8(param_1, (slot = &((Struct800CB3FC *) D_8012AB70)[index])->committed_pos);
    *param_2 = slot->unk_2C;
    return slot->unk_28;
}

f32 func_800CB45C(s32 index, u32 param_1, f32 *param_2, f32 *param_3)
{
    func_800EE7F8(param_1, (s16 *) ((s32) (int *) D_8012AB70 + index * 48 + 8));
    *(s32 *) param_2 = *(s16 *) ((s32) (int *) D_8012AB70 + index * 48 + 0x18);
    *(s32 *) param_3 = *(s16 *) ((s32) (int *) D_8012AB70 + index * 48 + 0x1A);
    return *(f32 *) ((s32) (int *) D_8012AB70 + index * 48 + 0x14);
}

s32 func_800CB4D0(s32 index, void *param_1, s32 param_2)
{
    s32 rv = 1;
    if (((E_CB4D0 *) D_8012AB70)[index].state != 0) {
        rv = 0;
        goto end; // Matching: goto needed for the match.
    }
    ((E_CB4D0 *) D_8012AB70)[index].state = 1;
    ((E_CB4D0 *) D_8012AB70)[index].handlers = param_1;
    ((E_CB4D0 *) D_8012AB70)[index].type = param_2;
    return rv;
end:
    return rv;
}

s32 func_800CB518(s32 index)
{
    return *(s16 *) ((char *) D_8012AB72 + index * 48);
}

void func_800CB534(s32 index, s32 param_1, s32 param_2)
{
    u8 *handlers;
    handlers = (s8 *) (*(u8 * (**) ())((s8 *) ((index * 0x30) + (u8 *) (s32 *) D_8012AB70) + 4))();
    (*(s32(**)(s32, s32, s32, s16))(handlers + 4))(
        index, param_1, param_2,
        *(s16 *) ((s8 *) ((index * 0x30) + (u8 *) (s32 *) D_8012AB70) + 0x1A));
}

int func_800CB598(s32 index, s32 param_1, s32 param_2)
{
    func_800CB698(index, 4);
    func_800CB534(index, param_1, param_2);
}

int func_800CB5D4(s32 index, s32 param_1, s32 param_2)
{
    func_800CB698(index, 3);
    func_800CB534(index, param_1, param_2);
}

void func_800CB610(void)
{
}

// Matching: the line breaks in this function are needed for the match.
void func_800CB618()
{
    u8 *slot;
    u8 *aux;
    s32 i;
    do { aux = &D_8012AB78; slot = &D_8012AB70; i = 0; do { slot[0] = i; slot[1] = 0; *(s32 *) &slot[4] = 0; *(f32 *) &slot[0x14] = 0.0f; func_800EFD24(aux); i++; slot += 0x30; aux += 0x30; } while (i != 0x10); } while (0);
}

volatile char func_800CB698(index, param_1)
s32 index;
int param_1;
{
    D_8012AB71[index * 0x30] = param_1;
}

void func_800CB6B4(s32 index, s32 param_1, f32 param_2, s32 param_3)
{
    func_800EE7F8(((E_CB6B4 *) D_8012AB70)[index].committed_pos, param_1);
    ((E_CB6B4 *) D_8012AB70)[index].unk_28 = param_2;
    ((E_CB6B4 *) D_8012AB70)[index].unk_2C = param_3;
}

// Copies the current pose of a slot into its committed pose.
// Matching: the cast and offset forms are needed for the match.
void func_800CB70C(s32 index)
{
    func_800EE7F8(&D_8012AB70[index * 48] + 0x1C, &D_8012AB70[index * 48] + 8);
    *(f32 *) (&D_8012AB70[index * 48] + 0x28) = *(f32 *) (&D_8012AB70[index * 48] + 0x14);
    *(s16 *) (&D_8012AB70[index * 48] + 0x2C) = *(s16 *) (&D_8012AB70[index * 48] + 0x18);
    *(s16 *) (&D_8012AB70[index * 48] + 0x2E) = *(s16 *) (&D_8012AB70[index * 48] + 0x1A);
}

void func_800CB764(s32 index, f32 *param_1, f32 param_2, s32 param_3, s32 param_4)
{
    func_800EE7F8(((E_CB764 *) D_8012AB70)[index].current_pos, param_1);
    ((E_CB764 *) D_8012AB70)[index].unk_14 = param_2;
    ((E_CB764 *) D_8012AB70)[index].unk_18 = param_3;
    ((E_CB764 *) D_8012AB70)[index].unk_1A = param_4;
}

s32 func_800CB7C4(s32 index, s32 param_1, s32 param_2)
{
    s32 ret = (*D_8012AB74[index].fn())(index, param_1, param_2);
    if (ret == 2) {
        func_800FC63C(0xE, 0x7FFF);
    }
    return ret;
}
