#include "core2/1E93440.h"

typedef struct {
    u16 flags;
    u8 pad02[2];
    u8 unk4;
    u8 unk5;
    u8 pad06[0x0C];
    s16 unk12[3];
    f32 unk18;
    u8 pad1C[0x0C];
    s16 unk28[3];
    s16 unk2E[3];
    s16 unk34[3];
    s16 unk3A[3];
    s16 unk40[3];
    s16 unk46[3];
    s16 unk4C[3];
    u8 unk52;
    u8 unk53;
    u8 pad54[0x24];
    f32 unk78;
    f32 unk7C;
    u8 pad80[4];
    s16 unk84;
    s16 unk86;
    u8 pad88[0x12];
    s16 unk9A;
    s16 unk9C;
    s16 unk9E;
    s16 unkA0;
    s16 unkA2;
    s16 unkA4;
    u8 padA6[2];
    u16 unkA8;
    u8 padAA[0x1A];
    s16 unkC4[3];
    s16 unkCA[3];
} Quelle;
typedef struct {
    s16 unk0[3];
    s16 unk6[3];
    f32 unkC;
    f32 unk10[3];
    f32 unk1C;
    s16 unk20[3];
    s16 unk26[3];
    s16 unk2C;
    s16 unk2E;
    s16 unk30;
    s16 unk32;
    s16 unk34;
    s16 unk36;
    u8 unk38;
    unsigned char active : 1;
    unsigned char low : 7;
} Ziel;
s32 func_800DC128(s32, s32);
f32 func_800DC0C0(void);
s32 func_800F0E44(s32);
s32 func_800EEDA0();
void func_800EE88C();
void func_800EFE50(f32 *, f32 *, f32 *, f32);
void func_800EF214(f32 *, f32, f32, f32);
void func_800EF1B8(f32 *, f32, f32);
void func_800EF368(f32 *, f32);
void func_800EF4E4(f32 *, f32, f32, f32, f32, f32);
typedef struct {
    u8 b[60];
} Eintrag;
typedef struct {
    u8 pad00[7];
    u8 unk7;
    u8 pad08[0x14];
    f32 unk1C;
    u8 pad20[0x32];
    u8 unk52;
    u8 unk53;
    u8 pad54[0x2C];
    u8 unk80;
    u8 unk81;
    u8 unk82;
    u8 unk83;
    u8 pad84[8];
    Eintrag *unk8C;
    Eintrag *unk90;
    Eintrag *unk94;
    u8 pad98[0x3C];
    Eintrag unkD4[1];
} Obj;
void *heap_alloc(s32);
void rare_memset(void *, s32, s32);
int func_800EFA6C(s32, s16, s16, s16);
extern f32 func_800DC178(f32, f32);
void func_800EFA4C(s32 a, f32 b, f32 c, f32 d);
extern void func_800EE940();
extern int func_800DC298(f32);
s32 func_800B53A4(s32);
void func_800BA4C4(f32 *emitter, f32 unk_0);
void func_800BA4D0();
int func_800BA54C();
int func_800BA554(f32 *emitter, f32 unk_0, f32 unk_1);
void func_800BA568();
void func_800BA7C4(s32 param_0, f32 param_1, f32 param_2);
void func_800BA894(f32 param_0[3], f32 param_1, f32 param_2);
void func_800BA8F8(s32 param_0, f32 param_1, f32 param_2);

// Initializes one particle from the emitter's spawn ranges.
// Matching: the line breaks in this function are needed for the match.
void func_800B9B50(Quelle *emitter, Ziel *particle)
{
    s32 unk_0;
    f32 pos_min[3];
    f32 pos_max[3];
    f32 pos_offset[3];
    f32 sphere_pos[3];
    f32 cylinder_pos[3];
    f32 vec[3];
    f32 dir[3];
    s32 unk_1;
    f32 angle_b;
    f32 angle_a;
    s32 i;
    for (i = 0; i < 3; i++)
    {
        particle->unk0[i] = func_800DC128(emitter->unk34[i], emitter->unk3A[i]);
    }

    particle->unk38 = emitter->unkA8;
    if (emitter->unk18 == 0)
    {
        particle->unkC = 1.0f;
    }
    else
    {
        particle->unkC = 0.0f;
    }
    particle->unk2C = func_800DC178((f32) emitter->unk84, (f32) emitter->unk86) * 256.0f;
    particle->unk2E = func_800DC178(emitter->unk78, emitter->unk7C) * 256.0f;
    switch (emitter->unk5) // spawn shape: 0 box, 1 sphere, 2 cylinder
    {
        case 0:
        if (emitter->flags & 0x40)
        {
            func_800EE88C(pos_min, emitter->unk28);
            func_800EE88C(pos_max, emitter->unk2E);
            func_800EFE50(pos_offset, pos_min, pos_max, func_800DC0C0());
            func_800EE940(particle->unk6, pos_offset);
        }
        else
        {
            for (i = 0; i < 3; i++)
            {
                particle->unk6[i] = emitter->unk12[i] + func_800DC128(emitter->unk28[i], emitter->unk2E[i]);
            }

        }
        break;
        case 1: func_800EE88C(sphere_pos, emitter->unk12); angle_a = func_800DC178(0.0f, 359.0f); angle_b = func_800DC178(0.0f, 359.0f); func_800EF214(sphere_pos, angle_a, angle_b, (f32) func_800DC128(emitter->unk28[0], emitter->unk28[1])); func_800EE940(particle->unk6, sphere_pos); break; case 2: func_800EE88C(cylinder_pos, emitter->unk12); angle_b = func_800DC178(0.0f, 359.9f); func_800EF1B8(cylinder_pos, angle_b, (f32) func_800DC128(emitter->unk28[0], emitter->unk28[1])); func_800EE940(particle->unk6, cylinder_pos); particle->unk6[1] = func_800DC128(emitter->unk2E[0], emitter->unk28[2]) + particle->unk6[1]; break;

    }

    particle->unk30 = func_800DC128(emitter->unk9A, emitter->unk9C);
    particle->unk32 = particle->unk30;
    if ((emitter->unk9E == 0) && (emitter->unkA0 == 0))
    {
        particle->unk34 = 0;
    }
    else
    {
        particle->unk34 = func_800DC128(emitter->unk9E, emitter->unkA0) - particle->unk32;
    }
    if (emitter->flags & 0x400)
    {
        for (i = 0; i < 3; i++)
        {
            particle->unk10[i] = func_800DC178(0.0, 360.0f);
        }

    }
    else
    {
        func_800EFA4C(particle->unk10, (f32) emitter->unk4C[0], (f32) emitter->unk4C[1], (f32) emitter->unk4C[2]);
    }
    for (i = 0; i < 3; i++)
    {
        particle->unk20[i] = func_800DC128(emitter->unk40[i], emitter->unk46[i]);
    }

    particle->unk1C = 0.0f;
    particle->unk36 = func_800DC128(emitter->unkA2, emitter->unkA4) + 1;
    switch (emitter->unk4)
    {
        case 0:
        for (i = 0; i < 3; i++)
        {
            particle->unk26[i] = func_800DC128(emitter->unkC4[i], emitter->unkCA[i]);
        }

        break;

        case 1:
        {
            s32 angle_c;
            s32 angle_d;
            angle_c = func_800F0E44(emitter->unkC4[2] + func_800DC128(0, func_800F0E44(emitter->unkCA[0] - emitter->unkC4[2])));
            angle_d = func_800F0E44(emitter->unkC4[0] + func_800DC128(0, func_800F0E44(emitter->unkC4[1] - emitter->unkC4[0])));
            func_800EF4E4(vec, (f32) angle_c, (f32) angle_d, 0.0f, 0.0f, (f32) func_800DC128(emitter->unkCA[1], emitter->unkCA[2]));
            func_800EE940(particle->unk26, vec);
        }
        break;

        case 2:
        if (func_800EEDA0(particle->unk6, emitter->unkC4 + 2) == 0)
        {
            if (emitter->flags & 0x8000)
            {
                dir[0] = (f32) (emitter->unkC4[2] - particle->unk6[0]);
                dir[1] = (f32) (emitter->unkCA[0] - particle->unk6[1]);
                dir[2] = (f32) (emitter->unkCA[1] - particle->unk6[2]);
            }
            else
            {
                dir[0] = (f32) (particle->unk6[0] - emitter->unkC4[2]);
                dir[1] = (f32) (particle->unk6[1] - emitter->unkCA[0]);
                dir[2] = (f32) (particle->unk6[2] - emitter->unkCA[1]);
            }
            func_800EF368(dir, func_800DC178((f32) emitter->unkC4[0], (f32) emitter->unkC4[1]));
            func_800EE940(particle->unk26, dir);
        }
        else
        {
            particle->unk26[2] = 0;
            particle->unk26[0] = particle->unk26[2];
            particle->unk26[1] = func_800DC128(emitter->unkC4[0], emitter->unkC4[1]);
        }

    }

    particle->active = 1;
    if (emitter->flags & 8)
    {
        emitter->unk52 = 0;
    }
    if (emitter->flags & 0x10)
    {
        emitter->unk53 = 0;
    }
}

// Returns the number of spawned particles.
int func_800BA198(void *emitter)
{
    int begin_offset;
    begin_offset = 0x8C;
    if ((emitter != 0) && (*(s32 *) ((char *) emitter + 0x90) != 0)) {
        return (*(s32 *) ((char *) emitter + 0x90) - *(s32 *) ((char *) emitter + begin_offset)) / 0x3C;
    }
    return 0;
}

void func_800BA1D0(u8 *emitter, s32 pos_min, u32 pos_max, u32 count)
{
    *(u16 *) emitter |= 0x40;
    func_800EE940(emitter + 0x28, pos_min);
    func_800EE940(emitter + 0x2E, pos_max);
    emitter[5] = 0;
    func_800BA22C(emitter, count);
}

void func_800BA22C(param_0, param_1) s32 param_0;
s32 param_1;
{
    s32 *local_0;
    local_0 = (s32 *) param_0;
    while (param_1 > 0) {
        s32 val = local_0[36];
        if ((u32) val < (u32) local_0[37]) {
            local_0[36] = val + 0x3C;
            func_800B9B50(local_0, val);
        }
        param_1--;
    }
}

s32 func_800BA28C(u8 *emitter)
{
    s32 is_empty;
    is_empty =
        ((s32) (*(s32 *) ((u8 *) emitter + 0x90) - *(s32 *) ((u8 *) emitter + 0x8C)) / 60) == 0;
    if (is_empty != 0) {
        return *(u8 *) ((u8 *) emitter + 7) == 2;
    }
}

int func_800BA2C4()
{
    heap_free();

    return 0;
}

// Allocates an emitter with room for count particles.
Obj *func_800BA2E8(s32 count)
{
    Obj *emitter;

    emitter = heap_alloc(count * 60 + 0xD4);
    rare_memset(emitter, 0, count * 60 + 0xD4);
    emitter->unk7 = 2;
    emitter->unk80 = emitter->unk81 = emitter->unk82 = emitter->unk83 = 0xFF;
    emitter->unk1C = 1.0f;
    func_800BA4D0(emitter, -0x8000);
    func_800BA568(emitter, 0x7FFF);
    func_800BA894(emitter, 0.0f, 5.0f);
    func_800BA8F8(emitter, 0.0f, 5.0f);
    func_800BA4C4(emitter, 0.9f);
    func_800BA554(emitter, 1.0f, 1.0f);
    func_800BA7C4(emitter, 1.0f, 1.0f);
    emitter->unk8C = emitter->unkD4;
    emitter->unk90 = emitter->unkD4;
    emitter->unk94 = emitter->unk8C + count;
    emitter->unk52 = 1;
    emitter->unk53 = 1;
    return emitter;
}

void func_800BA3FC(s32 emitter, s32 asset_id)
{
    u8 *bytes = (u8 *) emitter;
    if (((u16 *) emitter)[1] != asset_id) {
        *(u16 *) (emitter + 2) = asset_id;
        bytes[0xA] = func_800D738C((u16) asset_id);
        bytes[0xB] = func_800AF5A0(func_800D674C(((u16 *) bytes)[1]));
    }
}

void func_800BA450(emitter, min_x, min_y, min_z, max_x, max_y, max_z) s32 emitter;
s16 min_x;
s16 min_y;
s16 min_z;
s16 max_x;
s16 max_y;
s16 max_z;
{
    func_800EFA6C(emitter + 0x34, min_x, min_y, min_z);
    func_800EFA6C(emitter + 0x3A, max_x, max_y, max_z);
}

int func_800BA4B0(u8 *emitter, unsigned int alpha)
{
    emitter[0x83] = alpha;
    // Matching: empty block, needed for the match.
    {
    }
}

void func_800BA4B8(u8 *emitter, unsigned long unk_0, s32 unk_1)
{
    *((s16 *) (((u8 *) emitter) + 0xAA)) = unk_0;
    *((s32 *) (((u8 *) emitter) + 0xBC)) = unk_1;
}

void func_800BA4C4(f32 *emitter, f32 unk_0)
{
    emitter[44] = unk_0;
}

// Sets the minimum Y, clamped to the plane height from func_800B5698.
void func_800BA4D0(emitter, min_y) void *emitter;
s16 min_y;
{
    s16 plane_y;

if (func_800B5698(&plane_y) != 0) {
    if (min_y < plane_y) {
        min_y = plane_y;
    }
    if (*(s16 *) ((s8 *) emitter + 0xA8) == 0) {
        func_800BA54C(emitter, 2);
    }
}

*(s16 *)((s8 *)emitter + 0xAC) = min_y;
}

func_800BA544(void *emitter, s32 unk_0){
    s32 unk_1;
    unk_1 = unk_0;
    *(s32 *)((char *)emitter + 0xC0) = unk_1;
}

int func_800BA54C(emitter, unk_0) s32 emitter; unsigned int unk_0;
{
    *((s16 *) (emitter + 0xA8)) = unk_0;
}

int func_800BA554(f32 *emitter, f32 unk_0, f32 unk_1)
{
    unsigned int index;
    // Matching: index assignment inside the subscript is needed for the match.
    emitter[index = 45] = unk_0;
    emitter[46] = unk_1;
}

void func_800BA568(param_0, param_1) s32 param_0; s16 param_1; {
    *(s16 *)(param_0 + 0xae) = param_1;
}

int func_800BA574(s32 param_0)
{
    func_800EE814(param_0 + 0xC);
}

void func_800BA594(u8 *arg0, f32 arg1, f32 arg2) {
    *(f32 *)(arg0 + 0x18) = arg1;
    *(f32 *)(arg0 + 0x1C) = arg2;
}

int func_800BA5A8(s16 *param_0, unsigned int param_1)
{
    *param_0 = param_1;
}

void func_800BA5B0(s32 param_0, int param_1, int param_2)
{
    *((s16 *) (((char *) param_0) + 0x84)) = param_1;
    *((s16 *) (((char *) param_0) + 0x86)) = param_2;
}

int func_800BA5BC(f32 *param_0, f32 param_1, f32 param_2)
{
    param_0[30] = param_1 * 1.0f;
    param_0[31] = param_2;
}

void func_800BA5D0(u8 *arg0, s16 arg1)
{
    u32 var_v0;
    var_v0 = *((u32 *) (arg0 + 0x8C)); *((s16 *) (arg0 + 0x14)) = arg1; if (var_v0 < (*((u32 *) (arg0 + 0x90)))) {
        do
        {
            *((s16 *) (var_v0 + 8)) = arg1;
            var_v0 += 0x3C;
        }
        while (var_v0 < (*((u32 *) (arg0 + 0x90))));
    }
}

int func_800BA610(param_0, param_1, param_2) s32 param_0; s16 param_1; s16 param_2;
{
    func_800EFA6C(param_0 + 0x34, 0, param_1, 0);
    func_800EFA6C(param_0 + 0x3A, 0, param_2, 0);
}

func_800BA660(s32 param_0[2], s32 param_1, s16 param_2){
    param_0[0x22] = param_1;
    ((s16*)param_0)[0x4C] = param_2;
}

void func_800BA670(s32 param_0, s32 param_1)
{
    u16 *ptr = (u16 *)param_0;
    if (ptr[1] != param_1) {
        ptr[1] = param_1;
        *(u8 *)(ptr + 5) = func_800D738C((u16)param_1);
    }
}

int func_800BA6B0(param_0, param_1, param_2, param_3, param_4, param_5, param_6) s32 param_0; s16 param_1; s16 param_2; s16 param_3; s16 param_4; s16 param_5; s16 param_6;
{
    *((u8 *) (param_0 + 5)) = 0;
    func_800EFA6C(param_0 + 0x28, param_1, param_2, param_3);
    func_800EFA6C(param_0 + (0x2e ^ 0), param_4, param_5, param_6);
}

func_800BA714(u8 volatile *param_0, s16 param_1, s16 param_2) {
    u8 local_0 = 1;
    param_0[5] = local_0;
    *(s16 *)(param_0 + 0x28) = param_1;
    *(s16 *)(param_0 + 0x2A) = param_2;
}

void func_800BA730(void *param_0, s16 param_1, s16 param_2, s16 param_3, s16 param_4) {
    *(u8 *)((char *)param_0 + 5) = 2;
    *(s16 *)((char *)param_0 + 0x28) = param_1;
    *(s16 *)((char *)param_0 + 0x2A) = param_2;
    *(s16 *)((char *)param_0 + 0x2C) = param_3;
    *(s16 *)((char *)param_0 + 0x2E) = param_4;
}

int func_800BA75C(s32 param_0)
{
    func_800EE940(param_0 + 0x12);
}

void func_800BA77C(param_0, param_1, param_2, param_3) s32 param_0; s16 param_1; s16 param_2; s16 param_3;
{
    func_800EFA6C(param_0 + 0x4C, param_1, param_2, param_3);
}

void func_800BA7C4(s32 param_0, f32 param_1, f32 param_2) {
    s16 local_0;
    s16 local_1;

    local_0 = param_1 * 256.0f;
    local_1 = param_2 * 256.0f;
    *(s16 *)(param_0 + 0x9A) = local_0;
    *(s16 *)(param_0 + 0x9C) = local_1;
}

void func_800BA7FC(s32 param_0, f32 param_1, f32 param_2)
{
    s32 local_0;
    s32 local_1;
    local_0 = param_1 * 256.0f;
    local_1 = param_2 * 256.0f;
    *((s16 *) (param_0 + 0x9E)) = local_0;
    *((s16 *) (param_0 - -0xA0)) = local_1;
}

int func_800BA834(param_0, param_1, param_2, param_3, param_4, param_5, param_6) s32 param_0; s16 param_1; s16 param_2; s16 param_3; s16 param_4; s16 param_5; s16 param_6;
{
    func_800EFA6C(param_0 + 0x40, param_1, param_2, param_3);
    func_800EFA6C(param_0 + 0x46, param_4, param_5, param_6);
}

void func_800BA894(f32 param_0[3], f32 param_1, f32 param_2)
{
    f32 local_0;
    param_0[21] = param_1;
    param_0[22] = param_2;
    if ((0.0f == param_0[8]) || (param_2 < param_0[8]))
    {
        local_0 = func_800DC178(param_0[21], param_0[22]);
        param_0[8] = local_0;
    }
}

void func_800BA8F8(s32 param_0, f32 param_1, f32 param_2) {
    s16 local_0;
    s16 local_1;

    local_0 = param_1 * 256.0f;
    local_1 = param_2 * 256.0f;
    *(s16 *)(param_0 + 0xA2) = local_0;
    *(s16 *)(param_0 + 0xA4) = local_1;
}

void func_800BA930(param_0, param_1, param_2, param_3, param_4, param_5, param_6) s32 param_0; s16 param_1; s16 param_2; s16 param_3; s16 param_4; s16 param_5; s16 param_6;
{
    *((s8 *) (((s8 *) param_0) + 4)) = 0;
    func_800EFA6C(param_0 + 0xC4, param_1, param_2, param_3);
    func_800EFA6C(param_0 + 0xCA, param_4, param_5, param_6);
}

void func_800BA994(u8 *param_0, s16 param_1, s16 param_2, s16 param_3, s16 param_4, s16 param_5, s16 param_6) {
    f32 func_800136E4(f32);
    (*(s8 *)((s8 *)(param_0) + (4))) = 1;
    (*(s16 *)((s8 *)(param_0) + (0xC4))) = (s16)(s32)func_800136E4((f32)param_2);
    (*(s16 *)((s8 *)(param_0) + (0xC6))) = (s16)(s32)func_800136E4((f32)param_5);
    (*(s16 *)((s8 *)(param_0) + (0xC8))) = (s16)(s32)func_800136E4((f32)param_1);
    (*(s16 *)((s8 *)(param_0) + (0xCA))) = (s16)(s32)func_800136E4((f32)param_4);
    (*(s16 *)((s8 *)(param_0) + (0xCC))) = param_3;
    (*(s16 *)((s8 *)(param_0) + (0xCE))) = param_6;
}

void func_800BAA60(s16 *param_0, s32 param_1, s16 param_2, s16 param_3)
{
    *(s8 *)(param_0 + 2) = 2;
    *(s16 *)(param_0 + 0x62) = param_2;
    *(s16 *)(param_0 + 0x63) = param_3;
    func_800EE940((s32 *)(param_0 + 0x64), param_1);
}

void func_800BAA9C(s32 param_0, f32 param_1)
{
    func_800BA7C4(param_0, param_1, param_1);
    func_800BA7FC(param_0, param_1, param_1);
}

void func_800BAAE4(s32 param_0, f32 param_1, f32 param_2, f32 param_3)
{
    func_800EFA4C(param_0 + 0x6C, param_1, param_2, param_3);
}

void func_800BAB1C(s32 param_0, f32 param_1, f32 param_2, f32 param_3) {
    func_800EFA4C(param_0 + 0x60, param_1, param_2, param_3);
}

void func_800BAB54(f32 *param_0, f32 param_1)
{
    param_0[23] = param_1;
}

int func_800BAB60(s32 param_0)
{
    func_800F2EA0(param_0 + 0x80);
}

int func_800BAB80(s32 param_0)
{
    func_800F2EBC(param_0 + 0x80);
}

func_800BABA0(s32 param_0, f32 param_1) {
    ((f32*)((s8*)param_0 + 36))[0] = param_1;
    ((s8*)param_0)[7] = 0;
}

void func_800BABB0(s32 arg0)
{
}
s32 func_800BABB8(s32 param_0, f32 *param_1, f32 *param_2, f32 param_3, s32 *param_4)
{
    f32 local_1;
    f32 local_2;
    s32 local_0;
    f32 local_3;
    f32 local_7;
    f32 local_10;
    f32 local_12;
    f32 local_13;
    f32 local_14;
    f32 local_16;
    f32 local_18;
    f32 local_9;
    f32 local_19;
    f32 local_20;
    f32 local_21;
    f32 local_22;
    s16 local_24;
    s16 local_25;
    s16 local_26;
    s16 local_27;
    s16 local_28;
    s16 local_29;
    s16 local_30;
    s16 local_31;
    s16 local_32;
    s16 local_33;
    s16 local_34;
    s16 local_35;
    s16 local_36;
    s16 local_37;
    s16 local_38;
    s16 local_39;
    s16 local_40;
    f32 local_42;
    f32 local_43;
    s16 local_44;
    s16 local_45;
    s16 local_46;
    f32 local_47;
    s16 local_48;
    f32 local_50;
    s16 local_51;
    s16 local_52;
    s16 local_53;
    f32 local_54;
    f32 local_55;
    s16 local_56;
    f32 local_57;
    f32 local_58;
    s16 local_59;
    f32 local_60;
    s16 local_61;
    f32 local_62;
    f32 local_63;
    f32 local_64;
    s16 local_65;
    s16 local_66;
    s16 local_67;
    s16 local_68;
    s16 local_69;
    s16 local_70;
    s16 local_71;
    s16 local_72;
    s16 local_73;
    s16 local_74;
    s16 local_75;
    s16 local_76;
    s16 local_78;
    s32 local_79;
    s32 local_80;
    f32 local_17;
    f32 local_15;
    s32 local_81;
    s32 local_82;
    s32 local_83;
    s32 local_84;
    s32 local_85;
    f32 local_4;
    f32 local_5;
    f32 local_6;
    f32 local_11;
    s32 local_86;
    s32 local_87;
    u8 local_88;
    u8 *local_89;
    u8 *local_90;
    u8 *local_8;
    u8 *local_92;
    u8 *local_94;
    u8 *local_95;
    local_22 = 1.0f;
    local_0 = 0;
    if ((param_0 != 0) && (param_1 != 0))
    {
        func_800EE940(param_0 + 0x12, param_1);
    }
    if (param_4 == 0)
    {
        return (s32)param_0;
    }
    {
        local_78 = *(s16 *)param_4;
        param_4 = (s32 *)((u8 *)param_4 + 2);

if (local_78 != 0) {
    do {
        local_85 = local_78 & 0xFF;
        switch (local_85) {
            case 0x1:
                local_86 = 0;
                local_89 = (u8 *) param_0;
                for (; local_86 < 3; local_86++) {
                    *(s16 *) (local_89 + 52) = (s16) (s32) ((f32) *(s16 *) param_4 * local_22);
                    *(s16 *) (local_89 + 58) =
                        (s16) (s32) ((f32) *(s16 *) ((u8 *) param_4 + 6) * local_22);
                    local_89 += 2;
                    param_4 = (s32 *) ((u8 *) param_4 + 2);
                }
                param_4 = (s32 *) ((u8 *) param_4 + 6);
                break;

            case 0x2:
                *(u8 *) (param_0 + 0x83) = (s8) ((s32) (local_78 & 0xFF00) >> 8);
                break;

            case 0x3:
                *(s16 *) (param_0 + 0xAA) = *(s16 *) param_4;
                param_4 = (s32 *) ((u8 *) param_4 + 4);
                *(s32 *) (param_0 + 0xBC) = *(s16 *) ((u8 *) param_4 - 2);
                break;

            case 0x4:
                local_62 = (f32) *(s16 *) param_4 * 0.00390625f;
                param_4 = (s32 *) ((u8 *) param_4 + 2);
                *(f32 *) (param_0 + 176) = local_62;
                break;

            case 0x5:
                local_68 = *(s16 *) param_4;
                param_4 = (s32 *) ((u8 *) param_4 + 2);
                *(s16 *) (param_0 + 0xAC) = local_68;
                break;

            case 0x6:
                local_69 = *(s16 *) param_4;
                param_4 = (s32 *) ((u8 *) param_4 + 2);
                *(s16 *) (param_0 + 0xAC) =
                    (s16) (s32) (*(f32 *) ((s8 *) param_1 + 4) + (f32) local_69);
                break;

            case 0x7:
                *(s16 *) (param_0 + 0xA8) = *(s16 *) param_4;
                param_4 = (s32 *) ((u8 *) param_4 + 2);
                break;

            case 0x8:
                local_42 = (f32) *(s16 *) param_4 * 0.00390625f;
                local_47 = (f32) *(s16 *) ((u8 *) param_4 + 2) * 0.00390625f;
                param_4 = (s32 *) ((u8 *) param_4 + 4);
                *(f32 *) (param_0 + 180) = local_42;
                *(f32 *) (param_0 + 184) = local_47;
                break;

            case 0x9:
                local_70 = *(s16 *) param_4;
                param_4 = (s32 *) ((u8 *) param_4 + 2);
                *(s16 *) (param_0 + 0xAE) = local_70;
                break;

            case 0xA:
                local_87 = 0;
                local_89 = (u8 *) param_0;
                for (; local_87 < 3; local_87++) {
                    *(s16 *) (local_89 + 40) = (s16) (s32) ((f32) *(s16 *) param_4 * param_3);
                    *(s16 *) (local_89 + 46) =
                        (s16) (s32) ((f32) *(s16 *) ((u8 *) param_4 + 6) * param_3);
                    local_89 += 2;
                    param_4 = (s32 *) ((u8 *) param_4 + 2);
                }
                *(s8 *) (param_0 + 5) = 0;
                param_4 = (s32 *) ((u8 *) param_4 + 6);
                break;

            case 0xB:
                *(s8 *) (param_0 + 5) = 2;
                *(s16 *) (param_0 + 0x28) = (s16) ((f32) *(s16 *) param_4 * param_3);
                param_4 = (s32 *) ((u8 *) param_4 + 8);
                *(s16 *) (param_0 + 42) = (s16) ((f32) *(s16 *) ((u8 *) param_4 - 6) * param_3);
                *(s16 *) (param_0 + 44) = (s16) ((f32) *(s16 *) ((u8 *) param_4 - 4) * param_3);
                *(s16 *) (param_0 + 46) = (s16) ((f32) *(s16 *) ((u8 *) param_4 - 2) * param_3);
                break;

            case 0xC:
                local_9 = (f32) *(s16 *) param_4;
                *(s8 *) (param_0 + 5) = 0;
                param_4 = (s32 *) ((u8 *) param_4 + 2);
                local_9 *= param_3;
                local_81 = (s32) -local_9;
                func_800EFA6C(param_0 + 0x28, (s16) local_81, (s16) local_81, (s16) local_81);
                local_79 = (s32) local_9;
                func_800EFA6C(param_0 + 0x2E, (s16) local_79, (s16) local_79, (s16) local_79);
                break;

            case 0xD:
                local_35 = *(s16 *) param_4;
                param_4 = (s32 *) ((u8 *) param_4 + 2);
                *(s8 *) (param_0 + 5) = 0;
                local_35 = (s32) ((f32) local_35 * param_3);
                local_24 = -(s16) local_35;
                func_800EFA6C(param_0 + 0x28, local_24, 0, local_24);
                func_800EFA6C(param_0 + 0x2E, (s16) local_35, (s16) local_35, (s16) local_35);
                break;

            case 0xE:
                *(s8 *) (param_0 + 5) = 1;
                *(s16 *) (param_0 + 0x28) = (s16) ((f32) *(s16 *) param_4 * param_3);
                param_4 = (s32 *) ((u8 *) param_4 + 4);
                *(s16 *) (param_0 + 42) = (s16) ((f32) *(s16 *) ((u8 *) param_4 - 2) * param_3);
                break;

            case 0xF:
                *(s8 *) (param_0 + 7) = 1;
                *(f32 *) (param_0 + 0x20) =
                    func_800DC178(*(f32 *) (param_0 + 0x54), *(f32 *) (param_0 + 0x58));
                break;

            case 0x10:
                local_94 = func_800B53A4((s32) (local_78 & 0xFF00) >> 8);
                param_0 = local_94;
                if (param_1 != 0) {
                    func_800EE940(local_94 + 0x12, param_1);
                }
                break;

            case 0x11:
                local_84 = (s32) (local_78 & 0xFF00) >> 8;
                local_0 = local_84;
                local_95 = func_800B53A4(local_84);
                param_0 = local_95;
                if (param_1 != 0) {
                    func_800EE940(local_95 + 0x12, param_1);
                }
                break;

            case 0x12:
                local_25 = *(s16 *) ((u8 *) param_4 + 0);
                local_26 = *(s16 *) ((u8 *) param_4 + 2);
                local_27 = *(s16 *) ((u8 *) param_4 + 4);
                param_4 = (s32 *) ((u8 *) param_4 + 6);
                func_800EFA6C(param_0 + 0xC, local_25, local_26, local_27);
                param_4 = (s32 *) ((u8 *) param_4 + 6);
                break;

            case 0x13:
                if (((s32) (local_78 & 0xFF00) >> 8) != 0) {
                    local_22 = param_3;
                } else {
                    local_22 = 1.0f;
                }
                break;

            case 0x14:
                *(s16 *) (param_0 + 0) = 0x586;
                *(f32 *) (param_0 + 0xB0) = 0.4f;
                *(f32 *) (param_0 + 0x18) = 0.0f;
                *(s16 *) (param_0 + 0xA8) = 4;
                *(s16 *) (param_0 + 0xA2) = 0x300;
                *(s16 *) (param_0 + 0xA4) = 0x400;
                *(f32 *) (param_0 + 0x1C) = 0.8f;
                local_8 = param_0 + 0x34;
                func_800EFA6C(param_0 + 0x40, 0xC8, 0, 0xC8);
                func_800EFA6C(param_0 + 0x46, 0x190, 0, 0x190);
                func_800EFA6C(local_8, 0, -0x3E8, 0);
                func_800EFA6C(param_0 + 0x3A, 0, -0x320, 0);
                break;

            case 0x15:
                local_63 = (f32) *(s16 *) param_4 * 0.00390625f;
                local_64 = (f32) *(s16 *) ((u8 *) param_4 + 2) * 0.00390625f;
                param_4 = (s32 *) ((u8 *) param_4 + 4);
                *(f32 *) (param_0 + 24) = local_63;
                *(f32 *) (param_0 + 28) = local_64;
                break;

            case 0x16:
                *(s16 *) param_0 = *(s16 *) param_4;
                param_4 = (s32 *) ((u8 *) param_4 + 2);
                break;

            case 0x17:
                param_4 = (s32 *) ((u8 *) param_4 + 2);
                if (func_800DC298((f32) *(s16 *) ((u8 *) param_4 - 2) * 0.00390625f) != 0) {
                    *(s16 *) param_0 = (u16) *(s16 *) param_0 | 0x800;
                }
                break;

            case 0x18:
                local_16 = (f32) *(s16 *) ((u8 *) param_4 + 4) * 0.00390625f;
                local_18 = (f32) *(s16 *) ((u8 *) param_4 + 6) * 0.00390625f;
                local_72 = *(s16 *) param_4;
                local_73 = *(s16 *) ((u8 *) param_4 + 2);
                *(s16 *) (param_0 + 0x86) = local_73;
                param_4 = (s32 *) ((u8 *) param_4 + 8);
                *(s16 *) (param_0 + 0x84) = local_72;
                *(f32 *) (param_0 + 0x78) = local_16;
                *(f32 *) (param_0 + 0x7C) = local_18;
                break;

            case 0x19:
                local_72 = *(s16 *) param_4;
                local_73 = *(s16 *) ((u8 *) param_4 + 2);
                param_4 = (s32 *) ((u8 *) param_4 + 4);
                *(s16 *) (param_0 + 0x86) = local_73;
                *(s16 *) (param_0 + 0x84) = local_72;
                break;

            case 0x1A:
                func_800BA22C(param_0, (s32) (local_78 & 0xFF00) >> 8);
                break;

            case 0x1B:
                func_800EFA6C(param_0 + 0x34, 0, (s16) (s32) ((f32) *(s16 *) param_4 * local_22),
                              0);
                func_800EFA6C(param_0 + 0x3A, 0,
                              (s16) (s32) ((f32) *(s16 *) ((u8 *) param_4 + 2) * local_22), 0);
                param_4 = (s32 *) ((u8 *) param_4 + 4);
                break;

            case 0x1C:
                local_92 = func_800BA2E8((s32) (local_78 & 0xFF00) >> 8);
                param_0 = local_92;
                if (param_1 != 0) {
                    func_800EE940(local_92 + 0x12, param_1);
                }
                break;

            case 0x1D:
                local_65 = *(s16 *) param_4;
                param_4 = (s32 *) ((u8 *) param_4 + 2);
                if (local_65 == *(u16 *) (param_0 + 2)) {
                    break;
                }
                {
                    *(u16 *) (param_0 + 2) = (u16) local_65;
                    *(u8 *) (param_0 + 0xA) = func_800D738C(local_65 & 0xFFFF);
                    if (*(u8 *) (param_0 + 0xA) == 7) {
                        *(s8 *) (param_0 + 0xB) =
                            func_800AF5A0(func_800D674C(*(u16 *) (param_0 + 2)));
                    }
                }
                break;

            case 0x1E:
                *(s16 *) (param_0 + 0x14) +=
                    (s16) (param_3 * func_800DC178((f32) *(s16 *) param_4,
                                                   (f32) *(s16 *) ((u8 *) param_4 + 2)));
                param_4 = (s32 *) ((u8 *) param_4 + 4);
                break;

            case 0x1F:
                local_66 = *(s16 *) param_4;
                local_74 = *(s16 *) ((u8 *) param_4 + 2);
                param_4 = (s32 *) ((u8 *) param_4 + 4);
                func_800F31EC(param_0 + 0x80, (u32) (local_66 & 0xFF00) >> 8, local_66 & 0xFF,
                              (u32) (local_74 & 0xFF00) >> 8);
                break;

            case 0x20:
                local_67 = *(s16 *) param_4;
                local_75 = *(s16 *) ((u8 *) param_4 + 2);
                param_4 = (s32 *) ((u8 *) param_4 + 4);
                func_800F31FC(param_0 + 0x80, (u32) (local_67 & 0xFF00) >> 8, local_67 & 0xFF,
                              (u32) (local_75 & 0xFF00) >> 8, local_75 & 0xFF);
                break;

            case 0x21:
                local_25 = *(s16 *) param_4;
                local_26 = *(s16 *) ((u8 *) param_4 + 2);
                local_27 = *(s16 *) ((u8 *) param_4 + 4);
                param_4 = (s32 *) ((u8 *) param_4 + 6);
                func_800EFA6C(param_0 + 0x4C, local_25, local_26, local_27);
                break;

            case 0x22:
                local_1 = (f32) *(s16 *) param_4 * 0.00390625f;
                local_2 = (f32) *(s16 *) ((u8 *) param_4 + 2) * 0.00390625f;
                local_3 = (f32) *(s16 *) ((u8 *) param_4 + 4) * 0.00390625f;
                local_7 = (f32) *(s16 *) ((u8 *) param_4 + 6) * 0.00390625f;
                param_4 = (s32 *) ((u8 *) param_4 + 8);
                *(s16 *) (param_0 + 0x9a) = (s16) (s32) ((local_1 * param_3) * 256.0f);
                *(s16 *) (param_0 + 0x9c) = (s16) (s32) ((local_2 * param_3) * 256.0f);
                *(s16 *) (param_0 + 0x9e) = (s16) (s32) ((local_3 * param_3) * 256.0f);
                *(s16 *) (param_0 + 0xa0) = (s16) (s32) ((local_7 * param_3) * 256.0f);
                break;

            case 0x23:
                local_1 = (f32) *(s16 *) param_4 * 0.00390625f;
                param_4 = (s32 *) ((u8 *) param_4 + 2);
                local_1 = (local_1 * param_3) * 256.0f;
                local_83 = (s32) local_1;
                *(s16 *) (param_0 + 0x9a) = (s16) local_83;
                *(s16 *) (param_0 + 0x9c) = (s16) local_83;
                *(s16 *) (param_0 + 0x9e) = (s16) local_83;
                *(s16 *) (param_0 + 0xa0) = (s16) local_83;
                break;

            case 0x24:
                local_1 = (f32) *(s16 *) param_4 * 0.00390625f;
                local_2 = (f32) *(s16 *) ((u8 *) param_4 + 2) * 0.00390625f;
                param_4 = (s32 *) ((u8 *) param_4 + 4);
                *(s16 *) (param_0 + 0x9a) = (s16) (s32) ((local_1 * param_3) * 256.0f);
                *(s16 *) (param_0 + 0x9c) = (s16) (s32) ((local_2 * param_3) * 256.0f);
                break;

            case 0x25:
                local_1 = (f32) *(s16 *) param_4 * 0.00390625f;
                local_2 = (f32) *(s16 *) ((u8 *) param_4 + 2) * 0.00390625f;
                param_4 = (s32 *) ((u8 *) param_4 + 4);
                *(s16 *) (param_0 + 0x9e) = (s16) (s32) ((local_1 * param_3) * 256.0f);
                *(s16 *) (param_0 + 0xa0) = (s16) (s32) ((local_2 * param_3) * 256.0f);
                break;

            case 0x26:
                func_800EFA6C(param_0 + 0x40, *(s16 *) param_4, *(s16 *) ((u8 *) param_4 + 2),
                              *(s16 *) ((u8 *) param_4 + 4));
                func_800EFA6C(param_0 + 0x46, *(s16 *) ((u8 *) param_4 + 6),
                              *(s16 *) ((u8 *) param_4 + 8), *(s16 *) ((u8 *) param_4 + 0xA));
                param_4 = (s32 *) ((u8 *) param_4 + 0xC);
                break;

            case 0x27:
                func_800EFA6C(param_0 + 0x40, *(s16 *) param_4, 0, *(s16 *) ((u8 *) param_4 + 2));
                func_800EFA6C(param_0 + 0x46, *(s16 *) ((u8 *) param_4 + 4), 0,
                              *(s16 *) ((u8 *) param_4 + 6));
                param_4 = (s32 *) ((u8 *) param_4 + 8);
                break;

            case 0x28:
                local_1 = (f32) *(s16 *) param_4 * 0.00390625f;
                param_4 = (s32 *) ((u8 *) param_4 + 2);
                func_800BABA0(param_0, local_1);
                break;

            case 0x29:
                func_800B5534(param_0);
                break;

            case 0x2A:
                local_12 = (f32) *(s16 *) param_4 * 0.00390625f;
                local_14 = (f32) *(s16 *) ((u8 *) param_4 + 2) * 0.00390625f;
                local_17 = (f32) *(s16 *) ((u8 *) param_4 + 4) * 0.00390625f;
                local_15 = (f32) *(s16 *) ((u8 *) param_4 + 6) * 0.00390625f;
                param_4 = (s32 *) ((u8 *) param_4 + 8);
                *(f32 *) (param_0 + 0x54) = local_12;
                *(f32 *) (param_0 + 0x58) = local_14;
                if (*(f32 *) (param_0 + 0x20) == 0.0f || local_14 < *(f32 *) (param_0 + 0x20)) {
                    *(f32 *) (param_0 + 0x20) = func_800DC178(local_12, local_14);
                }
                *(s16 *) (param_0 + 0xA2) = (s16) (s32) (local_17 * 256.0f);
                *(s16 *) (param_0 + 0xA4) = (s16) (s32) (local_15 * 256.0f);
                break;

            case 0x2B:
                local_58 = (f32) *(s16 *) param_4 * 0.00390625f;
                local_60 = (f32) *(s16 *) ((u8 *) param_4 + 2) * 0.00390625f;
                param_4 = (s32 *) ((u8 *) param_4 + 4);
                *(s16 *) (param_0 + 0xA2) = (s16) (s32) (local_58 * 256.0f);
                *(s16 *) (param_0 + 0xA4) = (s16) (s32) (local_60 * 256.0f);
                break;

            case 0x2C:
                *(s8 *) (param_0 + 4) = 0;
                *(s16 *) (param_0 + 0xC4) = (s16) (s32) ((f32) *(s16 *) param_4 * local_22);
                param_4 = (s32 *) ((u8 *) param_4 + 12);
                *(s16 *) (param_0 + 0xC6) =
                    (s16) (s32) ((f32) *(s16 *) ((u8 *) param_4 - 0xA) * local_22);
                *(s16 *) (param_0 + 0xC8) =
                    (s16) (s32) ((f32) *(s16 *) ((u8 *) param_4 - 8) * local_22);
                *(s16 *) (param_0 + 0xCA) =
                    (s16) (s32) ((f32) *(s16 *) ((u8 *) param_4 - 6) * local_22);
                *(s16 *) (param_0 + 0xCC) =
                    (s16) (s32) ((f32) *(s16 *) ((u8 *) param_4 - 4) * local_22);
                *(s16 *) (param_0 + 0xCE) =
                    (s16) (s32) ((f32) *(s16 *) ((u8 *) param_4 - 2) * local_22);
                break;

            case 0x2D:
                *(s8 *) (param_0 + 4) = 2;
                *(s16 *) (param_0 + 0xC4) = (s16) (s32) ((f32) *(s16 *) param_4 * local_22);
                param_4 = (s32 *) ((u8 *) param_4 + 4);
                *(s16 *) (param_0 + 0xC6) =
                    (s16) (s32) ((f32) *(s16 *) ((u8 *) param_4 - 2) * local_22);
                func_800EE940(param_0 + 0xC8, param_2);
                break;

            case 0x2E:
                *(s8 *) (param_0 + 4) = 1;
                *(s16 *) (param_0 + 0xC8) = *(s16 *) param_4;
                param_4 = (s32 *) ((u8 *) param_4 + 12);
                *(s16 *) (param_0 + 0xC4) = (s16) *(s16 *) ((u8 *) param_4 - 0xA);
                *(s16 *) (param_0 + 0xCC) =
                    (s16) (s32) ((f32) *(s16 *) ((u8 *) param_4 - 8) * local_22);
                *(s16 *) (param_0 + 0xCA) = (s16) *(s16 *) ((u8 *) param_4 - 6);
                *(s16 *) (param_0 + 0xC6) = (s16) *(s16 *) ((u8 *) param_4 - 4);
                *(s16 *) (param_0 + 0xCE) =
                    (s16) (s32) ((f32) *(s16 *) ((u8 *) param_4 - 2) * local_22);
                break;

            case 0x2F:
                local_1 = (f32) *(s16 *) param_4 * 0.00390625f;
                local_2 = (f32) *(s16 *) ((u8 *) param_4 + 2) * 0.00390625f;
                local_3 = (f32) *(s16 *) ((u8 *) param_4 + 4) * 0.00390625f;
                local_4 = (f32) *(s16 *) ((u8 *) param_4 + 6) * 0.00390625f;
                local_5 = (f32) *(s16 *) ((u8 *) param_4 + 8) * 0.00390625f;
                local_6 = (f32) *(s16 *) ((u8 *) param_4 + 10) * 0.00390625f;
                local_11 = (f32) *(s16 *) ((u8 *) param_4 + 12) * 0.00390625f;
                param_4 = (s32 *) ((u8 *) param_4 + 14);
                func_800EFA4C((f32 *) (param_0 + 0x6C), local_1 * param_3, local_2 * param_3,
                              local_3 * param_3);
                func_800EFA4C((f32 *) (param_0 + 0x60), local_4 * param_3, local_5 * param_3,
                              local_6 * param_3);
                *(f32 *) (param_0 + 0x5C) = local_11;
                break;

            case 0x30:
                local_54 = (f32) *(s16 *) param_4 * 0.00390625f;
                param_4 = (s32 *) ((u8 *) param_4 + 2);
                *(f32 *) (param_0 + 208) = local_54;
                break;

            case 0x31:
                local_80 = func_800DC128(*(s16 *) param_4, *(s16 *) ((u8 *) param_4 + 2));
                param_4 = (s32 *) ((u8 *) param_4 + 4);
                *(s16 *) (param_0 + 0xCA) += (s16) (param_3 * (f32) local_80);
                break;

            case 0x32:
                local_46 = *(s16 *) param_4;
                param_4 = (s32 *) ((u8 *) param_4 + 2);
                *(s8 *) (param_0 + 0x52) = (s8) (local_46 & 0xFF);
                break;

            case 0x33:
                local_52 = *(s16 *) param_4;
                param_4 = (s32 *) ((u8 *) param_4 + 2);
                *(s8 *) (param_0 + 0x53) = (s8) (local_52 & 0xFF);
                break;

            case 0x34:
                for (local_86 = 0; local_86 < 4; local_86++) {
                    ((u8 *) param_0)[0x80 + local_86] = 255;
                }
                func_800BA930(param_0, 0, 0, 0, 0, 0, 0);
                func_800BA450(param_0, 0, 0, 0, 0, 0, 0);
                func_800BA834(param_0, 0, 0, 0, 0, 0, 0);
        }

        local_78 = *(s16 *) (u8 *) param_4;
        param_4 = (s32 *) ((u8 *) param_4 + 2);
    } while (local_78 != 0);
}

if (local_0 != 0) {
    func_800BA22C(param_0, local_0);
}

}
return param_0;
}

s32 func_800BBCB8(f32 param_0[3], s32 param_1, f32 param_2, s32 param_3, s32 *param_4)
{
    s32 local_0;

    local_0 = func_800B53A4(param_3);
    func_800BABB8(local_0, param_0, param_1, param_2, param_4);
    func_800BA22C(local_0, param_3);
    return local_0;
}

int func_800BBD18(s32 param_0, s32 param_1, s32 param_2, f32 param_3, s32 param_4)
{
    if (param_0 != 0) {
        func_800BABB8(param_0, param_1, param_2, param_3, param_4);
        func_800B4790(param_0);
    }
}
