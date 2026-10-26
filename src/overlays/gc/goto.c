#include "gc/goto.h"

extern s16 D_80800710_gcgoto[];
extern s16 D_80800720_gcgoto[];
extern s16 D_8080072C_gcgoto[];
extern s16 D_8080073C_gcgoto[];
extern u8 D_80800740_gcgoto[];
extern void *_gccubesearch_entrypoint_5(void *, void *);
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_80090358(f32 *, f32, s32, s32);
extern void func_8008FE68(f32 *);
extern void _plcamera_entrypoint_11(s32, f32 *);
extern void func_800EE88C(f32 *, f32 *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800EEB9C(f32 *, f32, f32);
extern int D_801275C0[];
void gcgoto_entrypoint_4(s32 param_0, s32 param_1, f32 param_2, f32 param_3, s32 param_4);

typedef struct
{
    u8 unk0[0x42C];
    u8 unk42C;
} UNKD_80127194;

/* extern */
extern UNKD_80127194 D_80127194;

s32 func_80800000_gcgoto(s8 *param_0, s16 param_1) {
    s32 i = 0;
    while (param_0[i] != -1) {
        if (param_1 == param_0[i++]) {
            return 1;
        }
    }
    return 0;
}

void gcgoto_entrypoint_0(s32 *param_0, s32 *param_1)
{
    if (*param_0 == 0xFB) {
        if (func_80800000_gcgoto(D_80800710_gcgoto, ((s16 *)param_1)[1])) *param_0 = 0x1A7;
        else if (func_80800000_gcgoto(D_80800720_gcgoto, ((s16 *)param_1)[1])) *param_0 = 0x1A8;
        else if (func_80800000_gcgoto(D_8080072C_gcgoto, ((s16 *)param_1)[1])) *param_0 = 0x1A9;
        else if (func_80800000_gcgoto(D_8080073C_gcgoto, ((s16 *)param_1)[1])) *param_0 = 0x1A6;
    }
}

void func_8080011C_gcgoto(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    if (D_80127194.unk42C == 0)
    {
        if ((arg0 == 0xCE) && (arg1 == 4))
        {
            func_800DA544(FLAG_503_UNK);
        }
        gcgoto_entrypoint_0(&arg0, &arg1);
        func_800A7990(arg0, arg1, arg3);
        func_800EA334(arg2);
        gcgoto_entrypoint_14(1);
    }
}

void gcgoto_entrypoint_1(u32 a0, u32 a1)
{
    func_8080011C_gcgoto(a0, a1, 0, 1);
}

s32 gcgoto_entrypoint_2(s32 map, s32 exit, s32 param_2){
    func_8080011C_gcgoto(map, exit, 0, param_2);
}

void func_808001E0_gcgoto(f32 *param_0, s32 param_1, s32 param_2, s32 param_3)
{
    f32 local_0[3];
    f32 local_1[3];
    u8 *local_3;
    f32 local_2;

    if (!*((u8 *)&D_80127194 + 0x42C)) {
        local_3 = param_0 ? _gccubesearch_entrypoint_5(D_80800740_gcgoto, param_0) : NULL;
        func_8008FE68(local_0);
        if (local_3) {
            _gspropctrl_entrypoint_11(local_3, local_1);
            if (param_3) {
                local_2 = 500.0f;
                if (*(u16 *)(local_3 + 8) == 0x24F) {
                    local_2 = 1000.0f;
                }
            } else {
                local_2 = 1000.0f;
            }
            if (func_800EEAD4(param_0, local_1) < local_2) {
                if (*(u16 *)(local_3 + 8) == 0x24D) {
                    _plcamera_entrypoint_11(func_800F54E4(), local_1);
                    func_8080011C_gcgoto(param_1, param_2, 1, 1);
                    func_800A1618(1);
                    func_80090358(local_1, 1.0f, 0, 0);
                    return;
                }
                if (*(u16 *)(local_3 + 8) == 0x24E) {
                    gcgoto_entrypoint_4(param_1, param_2, local_1[1],
                        (f32)(*(u32 *)(local_3 + 0xC) >> 23), *(u32 *)(local_3 + 0xC) & 0x7FFFFF);
                    return;
                }
                gcgoto_entrypoint_4(param_1, param_2, local_0[1],
                    (f32)(*(u32 *)(local_3 + 0xC) >> 23), *(u32 *)(local_3 + 0xC) & 0x7FFFFF);
                return;
            }
        }
        func_8080011C_gcgoto(param_1, param_2, 0, 1);
    }
}

void func_808003D0_gcgoto(s32 param_0, s32 param_1)
{
    f32 local_0[3];
    s32 pad[2];

    if (!(*((u8 *) D_801275C0))) {
        if (param_0 != 0) {
            func_800EE88C(local_0, (f32 *)param_0);
            func_808001E0_gcgoto(local_0, param_1 >> 8, param_1 & 0xFF, 0);
        } else {
            func_808001E0_gcgoto(NULL, param_1 >> 8, param_1 & 0xFF, 1);
        }
    }
}

s32 gcgoto_entrypoint_3(s32 param_0, s32 param_1, s32 param_2) {
    s32 local_0 = param_1 << 8;
    local_0 += param_2;
    func_808003D0_gcgoto(param_0, local_0);
}

void gcgoto_entrypoint_4(s32 param_0, s32 param_1, f32 param_2, f32 param_3, s32 param_4)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];

    func_8008FE68(local_0);
    func_800EEB9C(local_2, param_3, func_800F10B4(param_4, 0.0f, 200.0f, 10.0f, 800.0f));
    local_2[0] += local_0[0];
    local_2[1] += local_0[1];
    local_2[2] += local_0[2];
    local_1[0] = local_2[0];
    local_1[1] = param_2;
    local_1[2] = local_2[2];
    _plcamera_entrypoint_11(func_800F54E4(), local_1);
    func_8080011C_gcgoto(param_0, param_1, 1, 1);
    func_800A1618(1);
    func_80090358(local_1, 1.0f, 0, 0);
}

void gcgoto_entrypoint_5(s32 param_0, s32 param_1, f32 param_2) {
    f32 local_0[3];
    func_8008FE68(local_0);
    gcgoto_entrypoint_4(param_0, param_1, local_0[1], param_2, 0x25);
}

void gcgoto_entrypoint_6(s32 p0, s32 p1) {
    func_8080011C_gcgoto(p0, p1, 0, 1);
}

void gcgoto_entrypoint_7(s32 arg0, s32 arg1) {
}
s32 gcgoto_entrypoint_8(s32 param_0, s32 param_1) {
    if (func_80015FA0(0) == 1) {
        func_800A7AD4(1, 2);
        func_800FC1CC(0, 0x320);
        func_800FE3EC();
        gcgoto_entrypoint_7(param_0, param_1);
    }
}

s32 gcgoto_entrypoint_9(s32 param_0, s32 param_1){
    if(func_8008FD48(param_0) == 8){
        func_808003D0_gcgoto(param_0, 0xBC02);
    }
}

s32 gcgoto_entrypoint_10(s32 param_0, s32 param_1) {
    if (func_8008FD48(param_0) == 8) {
        func_808003D0_gcgoto(param_0, 0xC403);
    }
}

void gcgoto_entrypoint_11(s32 arg0, u32 arg1)
{
    s32 sp1C;
    s32 sp18;

    _sutempleboss_entrypoint_0(arg0, &sp1C, &sp18);
    if (sp1C != 0)
    {
        func_808003D0_gcgoto(arg0, (sp1C << 8) + sp18);
    }
}

void gcgoto_entrypoint_12(void) {
}

int gcgoto_entrypoint_13()
{
  *(s8*)((char*)D_801275C0 + 0x0) = 0;
  D_801275C0[1] = 0;
}

void gcgoto_entrypoint_14(long param_0)
{
  (*(u8 *)((u8 *)((u8 *)&D_80127194) + 0x42c)) = param_0;
}

int gcgoto_entrypoint_15()
{
  u8 *local_0 = &((u8 *)&D_80127194)[0x42C];
  return *local_0;
}
