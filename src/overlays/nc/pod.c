#include "common.h"

extern void _glcutDll_entrypoint_6(int a, int b);
extern int func_800EA05C(void);
// Layout of the pod camera object (handle 0x4C).
typedef struct {
    s16 sub_cam[3]; // dialog, ucam, fixpos handles
    u8 pad_0[2];
    s32 target;
    s32 target_id;
    s32 flags;
    s32 saved_mode; // dynamic camera restored on release
    f32 pos[3];
    f32 rot[3];
    f32 fov;
    f32 unk_34;
    s32 player;
    s16 kind;
    u8 unk_3E[6];
    f32 saved_fov;
    f32 unk_48;
} PodInitialState;
extern f32 func_800C517C(s32);
extern f32 func_800C5190(s32);
extern void func_800C5148(s32, f32);
extern void func_800C51A4(s32, f32);
typedef struct {
    u8 pad_0[2];
    s16 ucam;
    u8 pad_1[0x38];
    s16 kind;
} PodEventState;
typedef struct PodDispatchState {
    u8 pad_0[8];
    u8 *target;
    s32 target_id;
} PodDispatchState;
extern void func_80101074(s32);
extern int func_800A940C(s32);
extern s32 func_800C52F4(s32, s32);
extern s32 func_800C53EC(s32, s32);
typedef struct {
    u8 pad[0x3E];
    u32 letterbox : 8;
    u32 pad2 : 24;
} PodFlags;
extern void *func_80110024();
extern void func_80015178();
extern void func_8010F9C0();
s32 ncpod_entrypoint_2();
void ncpod_entrypoint_12();
void ncpod_entrypoint_15();
int ncpod_entrypoint_17();
void ncpod_entrypoint_19();

// Freeze the player (once).
void func_80800000_ncpod(pod) u8 *pod;
{

if (pod[0x42] == 0) {
    pod[0x42] = 1;
    func_800F82D4(*(s32 *) (pod + 0x38), 2);
}

}

// Unfreeze the player.
void func_80800038_ncpod(s32 pod)
{
    if (*(u8 *) ((u8 *) pod + 0x42) != 0) {
        *(u8 *) ((u8 *) pod + 0x42) = 0;
        func_800F82D4(*(s32 *) ((u8 *) pod + 0x38), 0);
    }

}

// Hook the cutscene skip.
void func_8080006C_ncpod(void *pod)
{
    if (!(*(int *) ((char *) pod + 0x10) & 0x800)) {
        *(unsigned char *) ((char *) pod + 0x43) = 1;
        // Matching: `| 0` is needed for the match.
        _glcutDll_entrypoint_6(func_800EA05C() | 0, 0x79);
    }

}

// Unhook the cutscene skip.
int func_808000AC_ncpod(u8 *pod)
{
    if (pod[0x43]) {
        _glcutDll_entrypoint_17(pod);
        pod[0x43] = 0;
    }

}

s16 ncpod_entrypoint_0(s32 player)
{
    s16 handle;
    PodInitialState *pod;
    s32 camera;
    handle = func_8001B668(0, 0x4C);
    pod = ncpod_entrypoint_2(handle);
    camera = func_800A940C(player);
    pod->sub_cam[0] = 0;
    pod->sub_cam[1] = 0;
    pod->sub_cam[2] = 0;
    pod->target = 0;
    pod->target_id = -1;
    func_800EFD24(pod->pos);
    func_800EFD24(pod->rot);
    pod->unk_34 = 1.0f;
    pod->fov = 40.0f;
    pod->saved_mode = func_80015184();
    pod->unk_3E[0] = 0;
    pod->unk_3E[4] = 0;
    pod->unk_3E[2] = 0;
    pod->unk_3E[5] = 0;
    pod->kind = 0;
    pod->player = player;
    pod->flags = 0;
    pod->unk_3E[3] = 0;
    pod->saved_fov = func_800C517C(camera);
    pod->unk_48 = func_800C5190(camera);
    return handle;
}

// Free the pod: release the sub-camera, restore letterbox, FOV and dynamic camera.
void ncpod_entrypoint_1(handle) s16 handle;
{
    u8 *pod;
    s32 camera;

    pod = (u8 *) ncpod_entrypoint_2(handle);
    camera = func_800A940C(*(s32 *) (pod + 0x38));
    ncpod_entrypoint_12(pod, 0);

if (pod[0x3E]) {
    ncpod_entrypoint_15(pod, 0, (*(u32 *) (pod + 0x10) & 0x4000) ? 0 : 1);
}

if (!(*(u32 *) (pod + 0x10) & 0x8000)) {
    func_800C5148(camera,
                  (*(u32 *) (pod + 0x10) & 0x80000) ? 40.0f : *(f32 *) (pod + 0x44));
    func_800C51A4(camera,
                  (*(u32 *) (pod + 0x10) & 0x80000) ? 1.0f : *(f32 *) (pod + 0x48));
}

func_80015178(*(s32 *) (pod + 0x14));
func_808000AC_ncpod(pod);
func_8001B754(handle);
}

// Get the pod object for a handle.
s32 ncpod_entrypoint_2(handle)
s16 handle;
{
    // Matching: the extra s32 copy is needed for the match.
    s32 id = handle;
    func_8001B798(id);
}

void ncpod_entrypoint_3(pod, kind)
{
    *((u16 *) (((char *) pod) + 60)) = kind;
}

// Get the player.
int ncpod_entrypoint_4(Actor *pod)
{
    return (*(s32 *) ((char *) (pod) + 0x38));
}

// Whether target_id is the id of target; -1 never matches.
int func_808002E8_ncpod(target, target_id)
u16 *target;
u32 target_id;
{
    s32 ret;

if (target_id == -1) {
    ret = 0;
} else {

ret = (target_id == ((u32) *(u16 *) (target + 9) >> 1));
}
return ret;
}

// Forward an event to the active sub-camera.
s32 func_80800314_ncpod(s32 controller, PodEventState *pod, s32 event, s32 unk_0, s32 unk_1)
{
    s32 status;

    switch (pod->kind) {
        case 0:
            break;
        case 1:
            status = _ncpoducam_entrypoint_5(_ncpoducam_entrypoint_1(pod->ucam));

if (event == 11) {
    if (status & 0x100)
        _glcutDll_entrypoint_17();
    if (!(status & 0x20))
        return ncpod_entrypoint_17(controller, 0);
    return 3;
}

break;
case 6:
    return _gcdialogcamera_entrypoint_1(event, unk_0, unk_1);
case 11:
    break;

}
return -1;
}

s32 ncpod_entrypoint_5(s32 controller, PodDispatchState *pod, s32 event, s32 unk_0,
                       s32 unk_1)
{
    s32 result;

    if (func_808002E8_ncpod(pod->target, pod->target_id)) {
        if (*(u16 *) (pod->target + 0x18) & 1) {
            func_80101074(unk_1);
            result = func_8010114C(pod->target, event, unk_0);
            switch (result) {
                case 4:
                    return 4;
                case 5:
                    return result;
            }
            result = func_80800314_ncpod(controller, pod, event, unk_0, unk_1);
            if (result == 4) {
                return 4;
            }
            return result;
        }

}
else
{
    return func_80800314_ncpod(controller, pod, event, unk_0, unk_1);
}
return -1;
}

s32 ncpod_entrypoint_6(s32 controller, u8 *pod, s32 event, s32 unk_0, s32 unk_1)
{
    if ((func_808002E8_ncpod((*(u8 **) ((s8 *) (pod) + (8))),
                             (*(s32 *) ((s8 *) (pod) + (0xC)))) != 0) &&
        ((*(u16 *) ((s8 *) ((*(u8 **) ((s8 *) (pod) + (8)))) + (0x18))) & 1)) {
        func_80101074(unk_1);
        return func_8010114C((*(u8 **) ((s8 *) (pod) + (8))), event, unk_0);
    }
    return -1;
}

void ncpod_entrypoint_7(u8 *pod, u8 *target)
{
    *((u8 **) (((u8 *) pod) + 8)) = target;
    // Matching: the repeated & 0xFFFFFFFF masks are needed for the match.
    *((u32 *) (((u8 *) pod) + 0xC)) =
        (u32) (((((((((((u16) (*((u16 *) (((u8 *) target) + 0x12)))) & 0xFFFFFFFF) & 0xFFFFFFFF) &
                     0xFFFFFFFF) &
                    0xFFFFFFFF) &
                   0xFFFFFFFF) &
                  0xFFFFFFFF) &
                 0xFFFFFFFF) &
                0xFFFFFFFF) >>
               1);
}

// Set the position and rotation applied to the view by the update.
void ncpod_entrypoint_8(s32 pod, s32 pos, s32 rot)
{
    func_800EE7F8(pod + 0x18, pos);
    func_800EE7F8(pod + 0x24, rot);
    *(s8 *) (pod + 0x40) = 1;
}

void ncpod_entrypoint_9(void *pod, f32 fov)
{
    *(f32 *) ((char *) pod + 0x30) = fov;
}

f32 ncpod_entrypoint_10(void *pod)
{
    return ((f32 *) pod)[12];
}

int ncpod_entrypoint_11(f32 *pod, f32 value)
{
    pod[13] = value;
}

// Free the current sub-camera and create one of the given type (1 dialog, 2 ucam, 3 fixpos).
void ncpod_entrypoint_12(pod, type) u8 *pod;
s32 type;
{
    s32 new_type;
    u8 old_type;
    s32 *type_ref;
    old_type = *((u8 *) (((s8 *) pod) + 0x41));
    switch (old_type) {
        case 1:
            _ncpoddialog_entrypoint_3(*((s16 *) (((s8 *) pod) + 0)));
            *((s16 *) (((s8 *) pod) + 0)) = 0;
            break;

        case 2:
            _ncpoducam_entrypoint_6(*((s16 *) (((s8 *) pod) + 2)));
            *((s16 *) (((s8 *) pod) + 2)) = 0;
            break;

        case 3:
            _ncpodfixpos_entrypoint_1(*((s16 *) (((s8 *) pod) + 4)));
            *((s16 *) (((s8 *) pod) + 4)) = 0;
    }

    // Matching: the mask temporary and the pointer to the parameter are needed for the match.
    new_type = 0xFF;
    new_type = type & new_type;
    type_ref = &type;
    *((u8 *) (((s8 *) pod) + 0x41)) = (u8) (*type_ref);
    switch (new_type) {
        case 1:
            *((s16 *) (((s8 *) pod) + 0)) = _ncpoddialog_entrypoint_2();
            return;

        case 2:
            *((s16 *) (((s8 *) pod) + 2)) = _ncpoducam_entrypoint_0();
            return;

        case 3:
            *((s16 *) (((s8 *) pod) + 4)) = _ncpodfixpos_entrypoint_0();
    }
}

// Get the active sub-camera type.
int ncpod_entrypoint_13(u8 *pod)
{
    return pod[0x41];
}

// Per-frame update: run the sub-camera and apply its position, rotation and FOV.
void ncpod_entrypoint_14(handle, controller) s16 handle;
s32 controller;
{
    u8 *pod;
    s32 status;
    s32 camera;

    pod = (u8 *) ncpod_entrypoint_2(handle);
    status = 2;
    switch (pod[0x41]) {
        case 0:
            break;
        case 1:
            status = _ncpoddialog_entrypoint_1(*(s16 *) pod, controller);
            break;
        case 2:
            status = _ncpoducam_entrypoint_7(*(s16 *) (pod + 2), controller);
            break;
        case 3:
            status = _ncpodfixpos_entrypoint_6(*(s16 *) (pod + 4), controller);
            break;
    }
    if (status != 4 && pod[0x40]) {
        camera = func_800A940C(*(s32 *) (pod + 0x38));
        func_8010FE14(controller, pod + 0x18, pod + 0x24);
        func_800C5148(camera, *(f32 *) (pod + 0x30));

if (*(f32 *) (pod + 0x30) == 40.0f && *(f32 *) (pod + 0x34) != 1.0f) {
    func_800C51A4(camera, *(f32 *) (pod + 0x34));
} else {

func_800C51A4(camera, 1.0f);
}
}
}

// Apply the pod flags: player freeze, camera mode and letterbox.
void func_808007D8_ncpod(pod, flags) u8 *pod;
s32 flags;
{
    s32 mode;
    s32 unk_0;
    s32 unk_1;

    if (flags & 0x10) {
        func_80800000_ncpod();
    } else {
        func_80800038_ncpod(pod);
    }
    if (flags & 0x60000) {
        if (flags & 0x40000) {
            mode = 4;
        } else if (flags & 0x20000) {
            mode = 3;
        } else {
            mode = *(s32 *) ((char *) pod + 0x14);
        }
        func_80015178(mode, flags);
    }
    if (flags & 4) {
        if (flags & 0x4000) {
            unk_0 = 0;
        } else {
            unk_0 = 1;
        }
        ncpod_entrypoint_15(pod, 0, unk_0);
        return;
    }
    if (flags & 0x2000) {
        unk_1 = 0;
    } else {
        unk_1 = 1;
    }
    ncpod_entrypoint_15(pod, 1, unk_1);
}

// Switch the letterbox on or off.
void ncpod_entrypoint_15(pod, enable, unk_0) u8 *pod;
s32 enable;
s32 unk_0;
{
    s32 camera;

    if (enable != ((PodFlags *) pod)->letterbox) {
        if (enable) {
            camera = func_800A940C(*(s32 *) (pod + 0x38));
            func_800C52F4(camera, unk_0 ? 2 : 0);
        } else {
            camera = func_800A940C(*(s32 *) (pod + 0x38));
            func_800C53EC(camera, unk_0 ? 2 : 0);
        }
        ((PodFlags *) pod)->letterbox = enable;
    }
}

// Switch the controller to pod mode (8); returns 0 if it already is.
int ncpod_entrypoint_16(s32 controller, s32 target, s32 kind, s32 flags)
{
    s32 pod;
    if (func_8010FAE4(controller) == 8) {
        return 0;
    }
    func_8010F9C0(controller, 8);
    pod = func_80110024(controller);
    ncpod_entrypoint_3(pod, kind);
    if (target != 0) {
        ncpod_entrypoint_7(pod, target);
    }
    ncpod_entrypoint_19(pod, flags);
    func_8080006C_ncpod(pod);
    return 1;
}

// Release the pod and switch the controller back to its normal mode.
int ncpod_entrypoint_17(controller, unk_0)
s32 controller;
s32 unk_0;
{
    u8 *pod;
    s32 camera;
    s32 flag;
    pod = func_80110024();
    camera = func_800A940C(*(s32 *) (pod + 0x38));
    ncpod_entrypoint_12(pod, 0);
    if (!unk_0 && !(*(u32 *) (pod + 0x10) & 0x8000)) {
        ncpod_entrypoint_15(pod, 0, (*(u32 *) (pod + 0x10) & 0x4000) ? 0 : 1);
        func_800C5148(camera,
                      (*(u32 *) (pod + 0x10) & 0x80000) ? 40.0f : *(f32 *) (pod + 0x44));
        func_800C51A4(camera,
                      (*(u32 *) (pod + 0x10) & 0x80000) ? 1.0f : *(f32 *) (pod + 0x48));
    }
    if (*(u32 *) (pod + 0x10) & 0x10) {
        func_80800038_ncpod(pod);
    }
    func_808000AC_ncpod(pod);
    if (unk_0) {
        *(u32 *) (pod + 0x10) |= 0x8000;
    }
    func_80015178(*(s32 *) (pod + 0x14));
    if (*(u32 *) (pod + 0x10) & 0x200) {
        flag = 0x200;
    } else if (*(u32 *) (pod + 0x10) & 0x10000) {
        flag = 0x10000;
    } else {
        flag = 0;
    }
    func_8010F9C0(controller, 2);
    if (flag == 0x200) {
        func_801108A0(func_80110014(controller));
    } else if (flag == 0x10000) {
        func_80110928(func_80110014(controller));
    }
    if (!unk_0) {
        func_8010FD88(controller);
    }
    return 4;
}

// Get the pod's kind, or -1 if there is no pod.
s16 ncpod_entrypoint_18(void)
{
    u8 *pod;

    pod = func_80110024();
    if (pod == NULL) {
        return -1;
    }
    return (*(s16 *) ((s8 *) pod + 0x3C));
}

void ncpod_entrypoint_19(pod, flags) void *pod;
s32 flags;
{
    func_808007D8_ncpod();
    *(s32 *) ((char *) pod + 0x10) = flags;
}

// Start the ucam camera on the current pod.
s32 ncpod_entrypoint_20(s32 controller, s32 unk_0, s32 unk_1, s32 flags)
{
    s32 pod;
    s32 ucam;
    pod = func_80110024();
    ncpod_entrypoint_12(pod, 2);
    ucam = _ncpoducam_entrypoint_1(*(s16 *) (pod + 2));
    _ncpoducam_entrypoint_4(ucam, flags);
    ncpod_entrypoint_19(pod, flags);
    if (unk_0 != 0) {
        _ncpoducam_entrypoint_3(ucam, unk_0);
    }
    _ncpoducam_entrypoint_2(ucam, controller, unk_1);
    func_8010FD88(controller);
    return 4;
}

void ncpod_entrypoint_21(s32 unk_0, s32 unk_1, s32 unk_2)
{
    _ncpoddialog_entrypoint_9(_ncpoddialog_entrypoint_0(*(s16 *) func_80110024()), unk_0, unk_1,
                              unk_2);
}

int ncpod_entrypoint_22(s16 *pod, s32 unk_0, s32 unk_1)
{
    // Matching: `| 0` is needed for the match.
    _ncpoddialog_entrypoint_4(_ncpoddialog_entrypoint_0(*pod) | 0, unk_0, unk_1);
}

int ncpod_entrypoint_23(s16 *pod, s32 unk_0, s32 unk_1)
{
    s32 dialog;
    dialog = _ncpoddialog_entrypoint_0(*pod);
    // Matching: `| 0` is needed for the match.
    _ncpoddialog_entrypoint_5(dialog | 0, unk_0, unk_1);
}

int ncpod_entrypoint_24(s16 *pod, s32 unk_0, s32 unk_1)
{
    u32 dialog;
    dialog = _ncpoddialog_entrypoint_0(*pod);
    // Matching: `| 0` is needed for the match.
    _ncpoddialog_entrypoint_6(dialog | 0, unk_0, unk_1);
}

int ncpod_entrypoint_25(s16 *pod, s32 unk_0)
{
    // Matching: `| 0` is needed for the match.
    _ncpoddialog_entrypoint_7(_ncpoddialog_entrypoint_0(*pod) | 0, unk_0);
}

// Enter pod mode with a ucam camera.
s32 ncpod_entrypoint_26(s32 controller, s32 unk_0, s32 target, s32 unk_1, s32 flags)
{
    s32 pod;
    s32 ucam;

    if (!ncpod_entrypoint_16(controller, 0, 1, flags))
        return 0;
    pod = func_80110024(controller);
    ncpod_entrypoint_12(pod, 2);
    if (target)
        ncpod_entrypoint_7(pod, target);
    else if (unk_0)
        ncpod_entrypoint_7(pod, unk_0);
    ucam = _ncpoducam_entrypoint_1(*(s16 *) (pod + 2));
    if (unk_0)
        _ncpoducam_entrypoint_3(ucam, unk_0);
    _ncpoducam_entrypoint_4(ucam, flags);
    _ncpoducam_entrypoint_2(ucam, controller, unk_1);
    func_8010FD88(controller);
    return 1;
}

int ncpod_entrypoint_27(s32 controller, s32 unk_0)
{
    s32 pod;
    s32 result;
    // Matching: the unused pod lookup is needed for the match.
    pod = func_80110024(controller);
    result = ncpod_entrypoint_17(controller, unk_0);
    func_8010F9C0(controller, 2);
    return result;
}

int ncpod_entrypoint_28(s32 controller, s32 unk_0)
{
    u32 pod;
    pod = func_80110024(controller);
    _ncpoducam_entrypoint_8(_ncpoducam_entrypoint_1(*(s16 *) ((char *) pod + 2)), unk_0);
}

int ncpod_entrypoint_29(s32 controller, s32 unk_0)
{
    u32 pod;
    pod = func_80110024(controller);
    _ncpoducam_entrypoint_9(_ncpoducam_entrypoint_1(*(s16 *) ((char *) pod + 2)), unk_0);
}

int ncpod_entrypoint_30()
{
    _ncpoducam_entrypoint_10(_ncpoducam_entrypoint_1(((s16 *) func_80110024())[1]));
}

int ncpod_entrypoint_31(s32 controller, s32 unk_0)
{
    u32 pod;
    pod = func_80110024(controller);
    _ncpoducam_entrypoint_11(_ncpoducam_entrypoint_1(*(s16 *) ((char *) pod + 2)), unk_0);
}

// Start the fixed-position camera on the current pod.
s32 ncpod_entrypoint_32(s32 controller, s32 unk_0, s32 unk_1, s32 flags)
{
    s32 pod;
    s32 fixpos;

    pod = func_80110024();
    ncpod_entrypoint_12(pod, 3);
    fixpos = _ncpodfixpos_entrypoint_2(*(s16 *) (pod + 4));
    _ncpodfixpos_entrypoint_5(fixpos, flags);
    if (unk_0 != 0) {
        _ncpodfixpos_entrypoint_4(fixpos, unk_0);
    }
    _ncpodfixpos_entrypoint_3(fixpos, controller, unk_1);
    return 4;
}

// Enter pod mode with a fixed-position camera.
s32 ncpod_entrypoint_33(s32 controller, s32 unk_0, s32 target, s32 unk_1, s32 flags)
{
    s32 pod;
    s32 fixpos;

    if (!ncpod_entrypoint_16(controller, 0, 0xB, flags))
        return 0;
    pod = func_80110024(controller);
    ncpod_entrypoint_12(pod, 3);
    if (target)
        ncpod_entrypoint_7(pod, target);
    else if (unk_0)
        ncpod_entrypoint_7(pod, unk_0);
    fixpos = _ncpodfixpos_entrypoint_2(*(s16 *) (pod + 4));
    _ncpodfixpos_entrypoint_5(fixpos, flags);
    if (unk_0)
        _ncpodfixpos_entrypoint_4(fixpos, unk_0);
    _ncpodfixpos_entrypoint_3(fixpos, controller, unk_1);
    func_8010FD88(controller);
    return 1;
}
