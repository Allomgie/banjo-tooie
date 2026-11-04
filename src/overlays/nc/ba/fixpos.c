#include "common.h"

extern void func_801124D0();
extern u32 func_80110840(void *);
extern f32 func_800F5628(u32);
extern f32 func_800F5E7C(u32);
extern f32 func_80115460(void *);

typedef struct {
    f32 position[3];
    f32 unk_C[3];
    u8 fixed_height;
    u8 unk_19;
    u8 disabled;
} FixedCameraPosition;
typedef struct {
    u8 pad_0[0x20];
    FixedCameraPosition *data;
} FixedCameraNode;

s32 ncbafixpos_entrypoint_0()
{
    return 0x1C;
}

void ncbafixpos_entrypoint_1(u8 *cam)
{
    (*(u8 **) (cam + 0x20))[0x1A] = 1;
    func_801124D0(cam, 1);
}

void ncbafixpos_entrypoint_2(s32 arg0)
{
}

// Camera height derived from the player's height.
f32 func_8080003C_ncbafixpos(void *cam)
{
    u32 player;
    f32 height;

    player = func_80110840(cam);
    func_800F5628(player);
    if (func_800F71D4(player)) {
        height = func_800F5E7C(player);
    } else {
        height = func_800F5628(player);
    }
    return func_80115460(cam) + height;
}

void ncbafixpos_entrypoint_3(FixedCameraNode *cam)
{
    f32 look_target[3];
    f32 pos[3];
    f32 rot[3];
    f32 unk_0[3];
    if (!cam->data->disabled) {
        func_801107F0(cam, pos);
        func_800EE7F8(unk_0, cam->data->unk_C);
        pos[0] = cam->data->position[0];
        pos[2] = cam->data->position[2];
        if (cam->data->fixed_height)
            pos[1] = cam->data->position[1];
        else
            pos[1] = func_8080003C_ncbafixpos(cam);
        func_80111AE0(cam, pos);
        if (cam->data->unk_19)
            func_8011329C(cam);
        func_80112524(cam, look_target);
        func_80110A68(cam, rot, look_target);
        func_80110790(cam, rot);
    }
}

void ncbafixpos_entrypoint_4(u8 *cam, s32 node)
{
    s32 unk_0;
    s32 unk_1;
    s32 flag;

    func_800A5800(node);
    _cadbfunc_entrypoint_29(2, &flag);
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) cam + 0x20) + 0x18) = (s8) flag;
    _cadbfunc_entrypoint_29(1, &flag);
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) cam + 0x20) + 0x19) = (s8) flag;
    _cadbfunc_entrypoint_4(*(u8 **) ((s8 *) cam + 0x20) + 0xC);
    _cadbfunc_entrypoint_0(*(u8 **) ((s8 *) cam + 0x20));
    _cadbfunc_entrypoint_6(&unk_0, &unk_1);
    func_80111B8C(cam, unk_0, unk_1);
    _cadbfunc_entrypoint_8(&unk_0, &unk_1);
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) cam + 0x20) + 0x1A) = 0;
    func_80112570(cam, *(u8 **) ((s8 *) cam + 0x20) + 0xC, 0x42C80000);
}

// TU-NOTE: the overlay .data (formerly asm/data/overlays/nc/ba/fixpos.data.s) is defined in C; values come from the ROM.
