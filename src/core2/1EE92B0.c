#include "common.h"

extern void func_80114CB0(s32, f32);
extern void func_80114CC0(s32, f32);
extern s32 D_80137320;
extern s32 D_80137330;
extern void func_80114C9C();
// Camera controller, only the pointer members used here.
typedef struct {
    void *view;
    void *follow_cam;
    u8 pad8[4];
    void *helper;
    void *effect;
} S_110068;
extern S_110068 *defrag(S_110068 *);
extern void *func_80110FCC(void *, S_110068 *);
extern void *func_80115324(void *, S_110068 *);
extern void *func_80114CD4(void *);

// Switches the camera mode (1 none, 2 dynamic follow, 3 fixed pos/rot, 8 pod), tearing down the old one.
void func_8010F9C0(u8 *ctrl, s32 mode)
{
    if (mode != *(s16 *) ((s8 *) ctrl + 0x16)) {
        switch (*(s16 *) ((s8 *) ctrl + 0x16)) {
            case 1:
                break;
            case 3:
                _ncfixposrot_entrypoint_1(*(s32 *) ((s8 *) ctrl + 8));
                *(s32 *) ((s8 *) ctrl + 8) = 0;
                break;
            case 8:
                _ncpod_entrypoint_1(*(s16 *) ((s8 *) ctrl + 0x14));
                *(s16 *) ((s8 *) ctrl + 0x14) = 0;
                break;
            case 2:
                if (*(s32 *) ((s8 *) ctrl + 4) != 0) {
                    func_80110B68(*(s32 *) ((s8 *) ctrl + 4), 0);
                }
        }
        *(s16 *) ((s8 *) ctrl + 0x16) = (s16) mode;
        switch (mode) {
            case 1:
                break;
            case 3:
                *(s32 *) ((s8 *) ctrl + 8) = _ncfixposrot_entrypoint_0();
                return;
            case 2:
                if (*(s32 *) ((s8 *) ctrl + 4) != 0) {
                    func_80110B68(*(s32 *) ((s8 *) ctrl + 4), 1);
                    return;
                }
                *(s32 *) ((s8 *) ctrl + 4) =
                    func_80110424(ctrl, *(s32 *) ((s8 *) ctrl + 0x1C));
                return;
            case 8:
                *(s16 *) ((s8 *) ctrl + 0x14) =
                    _ncpod_entrypoint_0(*(s32 *) ((s8 *) ctrl + 0x1C));
        }
    }
}

// Returns the current camera mode.
int func_8010FAE4(s16 *ctrl)
{
    s16 mode;
    mode = ctrl[11];
    return mode;
}

void func_8010FAEC(void *unk_0, void *ctrl)
{
    s32 *ctrl_words;
    ctrl_words = (s32 *) ctrl;
    if (ctrl_words[3]) {
        if (func_800A9420(ctrl_words[7]) != 0) {
            func_80114FA4(unk_0, ctrl_words[3], ctrl);
        }
    }
}

// Allocates a camera controller for one viewport.
u8 *func_8010FB34(s32 view, s32 player)
{
    u8 *ctrl;

    ctrl = heap_alloc(0x40);
    *(s32 **) ((char *) ctrl + 0) = (s32 *) view;
    *(s8 *) ((char *) ctrl + 0x18) = 0;
    *(s8 *) ((char *) ctrl + 0x19) = 0;
    *(s8 *) ((char *) ctrl + 0x20) = 0;
    *(s32 **) ((char *) ctrl + 0x10) = (s32 *) func_80114BD4();
    if (func_800DA298(0x6B5) != 0) {
        *(s32 **) ((char *) ctrl + 0xC) = (s32 *) func_80115118(ctrl);
    } else {
        *(s32 **) ((char *) ctrl + 0xC) = (s32 *) 0;
    }
    *(s32 **) ((char *) ctrl + 0x1C) = (s32 *) player;
    *(s32 **) ((char *) ctrl + 4) = (s32 *) func_80110424(ctrl, player);
    *(s32 **) ((char *) ctrl + 8) = (s32 *) 0;
    *(s16 *) ((char *) ctrl + 0x14) = 0;
    *(s16 *) ((char *) ctrl + 0x16) = 0;
    func_8010F9C0(ctrl, 1);
    return ctrl;
}

void func_8010FBD4(void *ctrl_arg)
{
    // Matching: local copy of the parameter.
    void *ctrl = ctrl_arg;
    func_8010F9C0(ctrl, 1);
    if (*(void **) ((u8 *) ctrl + 0x4) != 0) {
        func_801104F4(*(void **) ((u8 *) ctrl + 0x4));
    }
    if (*(void **) ((u8 *) ctrl + 0xC) != 0) {
        func_801150F8(*&*(void **) ((u8 *) ctrl + 0xC));
    }
    func_80114C7C(*(void **) ((u8 *) ctrl + 0x10));
    heap_free(ctrl);
}

// Per-frame camera update: runs the mode update and writes pos/rot to the view.
void func_8010FC38(u8 *ctrl)
{
    f32 pos[3];
    f32 rot[3];
    s16 mode;

    mode = *(s16 *) (ctrl + 0x16);
    if ((ctrl[0x18] == 0) && (ctrl[0x19] == 0)) {
        mode = 0;
    }
    switch (mode) {
        case 2:
            func_80110588(*(s32 *) (ctrl + 4));
            break;
        case 3:
            _ncfixposrot_entrypoint_6(*(s32 *) (ctrl + 8), ctrl);
            break;
        case 8:
            _ncpod_entrypoint_14(*(s16 *) (ctrl + 0x14), ctrl);
    }
    func_800CA8B4(*(s32 *) ctrl, &pos, &rot);
    func_800E1A58(&pos, &rot);
    func_800CA628(*(s32 *) ctrl, &pos, &rot);
    if (*(s32 *) (ctrl + 0xC) != 0) {
        func_801151C4(*(s32 *) (ctrl + 0xC));
    }
}

void func_8010FD08(ctrl_addr) s32 ctrl_addr;
{
    // Matching: local copy of the parameter.
    s32 ctrl;
    ctrl = ctrl_addr;
    *(u8 *) (ctrl + 0x19) = 1;
    func_8010FC38(ctrl);
    *(u8 *) (ctrl + 0x19) = 0;
}

void func_8010FD38(void *ctrl, f32 value)
{
    func_80114CB0(*(s32 *) ((u8 *) ctrl + 0x10), value);
}

void func_8010FD60(void *ctrl, f32 value)
{
    func_80114CC0(*(s32 *) ((u8 *) ctrl + 0x10), value);
}

void func_8010FD88()
{
    func_8010FD08();
}

// Queues a "set position/rotation" request (code 0x28).
void func_8010FDA8(u8 *ctrl, s32 pos, u8 *rot)
{
    *(u8 *) ((char *) ctrl + 32) = 0x28;
    func_800EE7F8(ctrl + 0x24, pos);
    func_800EE7F8(ctrl + 0x30, rot);
}

// Queues a request with code 0x29.
func_8010FDEC(s32 ctrl, f32 value)
{
    ((u8 *) ctrl)[0x20] = 0x29;
    ((f32 *) ((u8 *) ctrl + 0x3C))[0] = value;
}

void func_8010FE00(s32 ctrl, s32 unk_1, unsigned int value)
{
    u8 *flag = (u8 *) ((s32 *) ctrl + 6);
    *flag = value == 2;
}

int func_8010FE14(ctrl)
s32 ctrl[3];
{
    func_800CA628(ctrl[0]);
}

// Applies queued requests, consults the ncstart overlay and writes pos/rot to the view.
void func_8010FE34(u8 *ctrl, s32 player)
{
    u8 request;

    request = *(u8 *) ((s8 *) ctrl + 0x20);
    if (request != 0) {
        *(u8 *) ((s8 *) ctrl + 0x20) = 0U;
        if (*(s16 *) ((s8 *) ctrl + 0x16) == 2) {
            switch (request) {
                case 40:
                    func_8010FE14(ctrl, ctrl + 0x24, ctrl + 0x30);
                    func_801108A0(*(s32 *) ((s8 *) ctrl + 4));
                    break;
                case 41:
                    func_80110970(*(s32 *) ((s8 *) ctrl + 4), *(s32 *) ((s8 *) ctrl + 0x3C));
            }
            func_8010FD08(ctrl);
            return;
        }
    }
    if (_ncstart_entrypoint_0(player, &D_80137320, &D_80137330) == 0) {
        if (*(s16 *) ((s8 *) ctrl + 0x16) == 2) {
            func_80110928(*(s32 *) ((s8 *) ctrl + 4));
        }
        func_8010FD08(ctrl);
        return;
    }
    if (*(s16 *) ((s8 *) ctrl + 0x16) == 2) {
        func_80110A24(*(s32 *) ((s8 *) ctrl + 4), &D_80137330, &D_80137320);
    }
    func_800CA5B8(*(s32 *) ((s8 *) ctrl + 0), &D_80137320);
    func_800CA668(*(s32 *) ((s8 *) ctrl + 0), &D_80137330);
    func_800CAF34(*(s32 *) ((s8 *) ctrl + 0));
    if (*(s16 *) ((s8 *) ctrl + 0x16) == 2) {
        func_801108A0(*(s32 *) ((s8 *) ctrl + 4));
        func_8010FD08(ctrl);
    }
}

func_8010FF80(s32 ctrl)
{
    return *(s32 *) ctrl;
}

void func_8010FF88(Actor *ctrl)
{
    func_80114C9C(*(int *) ((char *) ctrl + 0x10));
}

func_8010FFA8(s32 ctrl)
{
    s16 mode;
    mode = *(s16 *) ((char *) ctrl + 0x16);
    return mode;
}

int func_8010FFB0(ctrl)
s32 ctrl[3];
{
    func_800CA8B4(ctrl[0]);
}

func_8010FFD0(u8 *ctrl)
{
    return ctrl[0x19];
}

s32 func_8010FFD8(s32 ctrl)
{
    s32 result;
    s32 helper;
    helper = *(s32 *) (ctrl + 0xC);
    if (helper != 0) {
        result = func_801150F0(helper);
    } else {
        result = 0;
    }
    return result;
}

int func_80110014(s32 ctrl[3])
{
    return ctrl[1];
}

func_8011001C(ctrl)
{
    return ((s32 *) ctrl)[2];
}

int func_80110024(s32 ctrl, s32 pod)
{
    pod = *(s16 *) (ctrl + 0x14);
    if (pod != 0) {
        return _ncpod_entrypoint_2((s16) pod);
    }
    return 0;
}

func_80110060(Actor *ctrl)
{
    return *(s32 *) ((char *) ctrl + 0x10);
}

// Relocates the controller and its inner objects after defrag().
S_110068 *func_80110068(S_110068 *old_ctrl, void *view)
{
    S_110068 *ctrl = defrag(old_ctrl);
    ctrl->view = view;
    if (ctrl->follow_cam != 0) {
        ctrl->follow_cam = func_80110FCC(ctrl->follow_cam, ctrl);
    }
    if (ctrl->helper != 0) {
        ctrl->helper = func_80115324(ctrl->helper, ctrl);
    }
    if (ctrl->effect != 0) {
        ctrl->effect = func_80114CD4(ctrl->effect);
    }
    return ctrl;
}

void func_801100E4(s32 *dst, s32 *src)
{
    f32 pos[3];
    f32 rot[3];

    if (dst != src) {
        func_800CA314((void *) dst[0], (void *) src[0]);
        if (dst[1] != 0) {
            func_8010FFB0((void *) src, pos, rot);
            func_80110770((void *) dst[1], pos);
            func_80110790((void *) dst[1], rot);
            func_80111018((void *) dst[1], (void *) src[1]);
        }
    }
}

void func_80110164(u8 *ctrl)
{
    s32 unk_0;
    s32 unk_1;

    func_8011490C(*(s32 *) ((s8 *) ctrl + 0x10), ctrl, *(s32 *) ((s8 *) ctrl + 0x1C));
    func_80114C9C(*(s32 *) ((s8 *) ctrl + 0x10), &unk_0, &unk_1, ctrl);
    func_800CA6C0(*(s32 *) ((s8 *) ctrl + 0), unk_0, unk_1, ctrl);
}
