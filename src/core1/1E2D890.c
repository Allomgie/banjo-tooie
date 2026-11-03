#include "threads.h"
#include "types.h"
#include "core1/1E2D890.h"

extern u32 D_8007DB54;
// Per button: number of frames held (14 buttons).
typedef struct {
    s32 frames[14];
} Struct80015E80;
extern Struct80015E80 D_800799E0[];
extern s32 D_800799C0[256][2];
extern long long D_80079A14[];
extern u8 D_80079D69;
extern u8 D_80079B93;
extern s32 D_80079AF4;
extern s32 D_80079AC0[13];
typedef struct {
    s32 state[2];
    f32 stick[2];
} Struct80016068;
extern Struct80016068 D_80079AF8[];
typedef struct {
    u16 button;
    s8 stick_x;
    s8 stick_y;
    u8 errnum;
} ContPad1608C;
typedef struct {
    u16 cur;
    u16 prev;
    u16 pressed;
    u16 released;
    f32 joy[2];
} PadState1608C;
extern ContPad1608C D_80079B40[4];
extern ContPad1608C D_80079B58;
extern OSThread D_80079BA8;
extern u8 D_80079D6C[4];
extern s32 func_800A9CAC(void);
extern s32 _glrecord_entrypoint_0(ContPad1608C *, s32 *);
extern void func_800D8FA0(s32);
extern void func_800A9CDC(void);
extern void func_800DC0C0(void);
extern f32 func_80013B70(f32 param_0, f32 param_1, f32 param_2);
extern s32 D_800799F8[][14];
extern s32 D_80079A04[][14];
extern u32 D_80079AFC[];

extern s32 D_8003F5F0;

extern OSMesg D_80079B38;
extern OSMesg D_80079B3C;
extern OSMesgQueue D_80079B60;
extern OSMesgQueue D_80079B78;
extern OSContStatus D_80079B90[4];
extern volatile s32 D_80079BA0;

extern __OSThreadOddFpStorage D_80079D58;

extern u8 D_80079D68;
extern u64 D_80079D70[JOY_THREAD_STACK_SIZE / sizeof(u64)];

extern OSMesgQueue D_80079F70;
extern OSMesg D_80079F88[6];

void func_80016934(s32 arg0);
void func_80016A48(void);
void func_80016864(void);
void func_80016A04(void);

// Normalises a raw stick axis (dead zone to upper) to +-80, scaled by a float derived from D_8007DB54.
f32 func_80015D60(s32 stick, s32 dead_zone, s32 upper)
{
    f32 scale;
    u32 bits;

    bits = 0xE955CCDD - D_8007DB54;
    scale = *(f32 *) &bits;
    if (stick > 0) {
        stick = (upper < stick) ? upper : (stick < dead_zone) ? dead_zone : stick;
        stick = ((stick - dead_zone) * 0x50) / (upper - dead_zone);
    } else if (stick < 0) {
        stick = (stick < -upper) ? -upper : (-dead_zone < stick) ? -dead_zone : stick;
        stick = ((stick + dead_zone) * 0x50) / (upper - dead_zone);
    }
    return scale *= stick;
}

void func_80015E80(s32 pad, s32 *out)
{
    Struct80015E80 *holds;

    holds = &D_800799E0[pad];
    out[0] = holds->frames[0];
    out[1] = holds->frames[1];
    out[2] = holds->frames[2];
    out[3] = holds->frames[3];
    out[4] = holds->frames[4];
    out[5] = holds->frames[5];
}

// Matching: no return value, as in the original.
int func_80015ECC(s32 pad, s32 *out)
{
    out[0] = D_80079AC0[0];
    out[1] = D_80079AC0[1];
    out[2] = D_80079AC0[2];
    out[3] = D_80079AC0[3];
    out[4] = D_80079AC0[4];
    out[5] = D_80079AC0[5];
}

s32 func_80015F0C(s32 pad, s32 idx)
{
    s32 *row = D_800799C0[pad];
    return row[idx];
}

void func_80015F28(s32 pad, s32 *out)
{
    Struct80015E80 *holds;

    holds = &D_800799E0[pad];
    out[0] = holds->frames[6];
    out[1] = holds->frames[7];
    out[2] = holds->frames[8];
}

void func_80015F5C(s32 pad, s32 *out)
{
    out[0] = ((s32 *) D_80079AC0)[6];
    out[1] = ((s32 *) D_80079AC0)[7];
    out[2] = ((s32 *) D_80079AC0)[8];
}

// Matching: redundant masks and the pointer copy chain are needed for the match.
s32 func_80015F84(s32 pad)
{
    int slot;
    long long *entry_copy;
    long long *entry;
    int masked;
    slot = (((pad * 7) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu;
    masked = (((slot & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) &
              0xFFFFFFFFFFFFFFFFu;
    entry = &D_80079A14[((masked & ((0xFFFFFFFFFFFFFFFFu & 0xFFFFFFFFFFFFFFFF) ^
                                        (0xFFFFFFFFFFFFFFFFu * 0))) &
                            0xFFFFFFFFFFFFFFFFu) &
                           0xFFFFFFFFFFFFFFFFu];
    return *(s32 *) (entry_copy = (entry = &*entry));
}

s32 func_80015FA0(s32 pad)
{
    s32 frames;

    if ((D_80079D69 == 0) || (D_80079B93 != 0)) {
        return 0;
    }
    if (pad != 0) {
        frames = ((s32(*)[14]) D_80079A14)[pad][0];
    } else {
        frames = D_80079AF4;
    }
    return frames;
}

void func_80015FFC(s32 pad, s32 *out)
{
    s32 *holds;
    holds = (s32 *) ((s8 *) (s32 *) D_800799E0 + (pad * 0x38));
    out[0] = *(s32 *) ((s8 *) holds + 0x24);
    out[1] = *(s32 *) ((s8 *) holds + 0x28);
    out[2] = *(s32 *) ((s8 *) holds + 0x2C);
    out[3] = *(s32 *) ((s8 *) holds + 0x30);
}

void func_80016038(s32 pad[4], s32 *out)
{
    out[0] = D_80079AC0[0x24 / 4];
    out[1] = D_80079AC0[0x28 / 4];
    out[2] = D_80079AC0[0x2c / 4];
    out[3] = D_80079AC0[0x30 / 4];
}

void func_80016068(s32 pad, f32 *out)
{
    out[0] = D_80079AF8[pad].stick[0];
    out[1] = D_80079AF8[pad].stick[1];
}

// Per-frame pad update: copies pad 0 (with demo record/playback), then updates hold-frame
// counters, button masks and normalised stick values for all four pads.
// Matching: `register` on i, `^ 0` and the redundant `& 0xFFu` index are needed for the match.
void func_8001608C(void)
{
    s32 j;
    register s32 i;
    s32 old_pri;
    s32 unk_0;
    old_pri = osGetThreadPri(&D_80079BA8);

    osSetThreadPri(&D_80079BA8, 0);

    D_80079B58.stick_x = D_80079B40[0].stick_x;

    D_80079B58.stick_y = D_80079B40[0].stick_y;

    D_80079B58.button = D_80079B40[0].button;

    if (func_800A9CAC()) {
        if (_glrecord_entrypoint_0(D_80079B40, &unk_0) == 0) {
            func_800A9CDC();
        } else {
            func_800D8FA0(unk_0);
        }
    }
    func_800DC0C0();
    for (i = 0; 3 >= i; ++i) {
        D_80079D6C[i] = (D_80079B40[i].errnum & 8) ? 0 : 1;

        if ((D_80079B40[i].button & 0x20) && (D_80079B40[i].button & 0x10)) {
            ((s32(*)[2]) D_800799C0)[i][0] =
                (D_80079B40[i].button & 0x4000) ? (((s32(*)[2]) D_800799C0)[i][0] + 1) : 0;
        } else {
            for (j = 0; 2 > j; ++j) {
                ((s32(*)[2]) D_800799C0)[i][j] = 0;
            }
        }
        ((s32(*)[14]) D_800799E0)[i][0] =
            (D_80079B40[i].button & 0x8000) ? (((s32(*)[14]) D_800799E0)[i][0] + 1) : 0;
        ((s32(*)[14]) D_800799E0)[i][1] =
            (D_80079B40[i].button & (0x4000 ^ 0)) ? (((s32(*)[14]) D_800799E0)[i][1] + 1) : 0;
        ((s32(*)[14]) D_800799E0)[i][2] =
            (D_80079B40[i].button & 0x2) ? (((s32(*)[14]) D_800799E0)[i][2] + 1) : 0;
        ((s32(*)[14]) D_800799E0)[i][3] =
            (D_80079B40[i].button & 0x4) ? (((s32(*)[14]) D_800799E0)[i][3] + 1) : 0;
        ((s32(*)[14]) D_800799E0)[i][4] =
            (D_80079B40[i].button & 0x8) ? (((s32(*)[14]) D_800799E0)[i][4] + 1) : 0;
        ((s32(*)[14]) D_800799E0)[i][5] =
            (D_80079B40[i].button & 0x1) ? (((s32(*)[14]) D_800799E0)[i][5] + 1) : 0;

        ((s32(*)[14]) D_800799E0)[i][6] =
            (D_80079B40[i].button & 0x2000) ? (((s32(*)[14]) D_800799E0)[i][6] + 1) : 0;
        ((s32(*)[14]) D_800799E0)[i][7] =
            (D_80079B40[i].button & 0x20) ? (((s32(*)[14]) D_800799E0)[i][7] + 1) : 0;

        ((s32(*)[14]) D_800799E0)[i][8] =
            (D_80079B40[i].button & 0x10) ? (((s32(*)[14]) D_800799E0)[i][8] + 1) : 0;
        ((s32(*)[14]) D_800799E0)[i][9] =
            (D_80079B40[i].button & 0x800) ? (((s32(*)[14]) D_800799E0)[i][9] + 1) : 0;
        ((s32(*)[14]) D_800799E0)[i][10] =
            (D_80079B40[i].button & 0x400) ? (((s32(*)[14]) D_800799E0)[i][10] + 1) : 0;
        ((s32(*)[14]) D_800799E0)[i][11] =
            (D_80079B40[i].button & 0x200) ? (((s32(*)[14]) D_800799E0)[i][11] + 1) : 0;
        ((s32(*)[14]) D_800799E0)[i][12] =
            (D_80079B40[i].button & 0x100) ? (((s32(*)[14]) D_800799E0)[i][12] + 1) : 0;
        ((s32(*)[14]) D_800799E0)[i][13] =
            (D_80079B40[i].button & 0x1000) ? (((s32(*)[14]) D_800799E0)[i][13] + 1) : 0;
        if (i == 0) {
            s32 buttons;
            buttons = D_80079B58.button;

            ((s32 *) D_80079AC0)[0] = (buttons & 0x8000) ? (((s32 *) D_80079AC0)[0] + 1) : 0;
            ((s32 *) D_80079AC0)[1] = (buttons & 0x4000) ? (((s32 *) D_80079AC0)[1] + 1) : 0;
            ((s32 *) D_80079AC0)[2] = (buttons & 0x2) ? (((s32 *) D_80079AC0)[2] + 1) : 0;
            ((s32 *) D_80079AC0)[3] = (buttons & 0x4) ? (((s32 *) D_80079AC0)[3] + 1) : 0;
            ((s32 *) D_80079AC0)[4] = (buttons & 0x8) ? (((s32 *) D_80079AC0)[4] + 1) : 0;
            ((s32 *) D_80079AC0)[5] = (buttons & 0x1) ? ((((s32 *) D_80079AC0)[5] ^ 0) + 1) : 0;
            ((s32 *) D_80079AC0)[6] =
                (buttons & 0x2000) ? (((s32 *) D_80079AC0)[((6 & 0xFFu) & 0xFFu) & 0xFFu] + 1)
                                     : 0;
            ((s32 *) D_80079AC0)[7] = (buttons & 0x20) ? (((s32 *) D_80079AC0)[7] + 1) : 0;
            ((s32 *) D_80079AC0)[8] = (buttons & 0x10) ? (((s32 *) D_80079AC0)[8] + 1) : 0;
            ((s32 *) D_80079AC0)[9] = (buttons & 0x800) ? (((s32 *) D_80079AC0)[9] + 1) : 0;
            ((s32 *) D_80079AC0)[10] = (buttons & 0x400) ? (((s32 *) D_80079AC0)[10] + 1) : 0;
            ((s32 *) D_80079AC0)[11] = (buttons & 0x200) ? (((s32 *) D_80079AC0)[11] + 1) : 0;
            ((s32 *) D_80079AC0)[12] = (buttons & 0x100) ? (((s32 *) D_80079AC0)[12] + 1) : 0;
            ((s32 *) D_80079AC0)[13] = (buttons & 0x1000) ? (((s32 *) D_80079AC0)[13] + 1) : 0;
            if ((buttons & 0x20) && (buttons & 0x10)) {
                ((s32(*)[2]) D_800799C0)[i][1] =
                    (buttons & 0x4000) ? (((s32(*)[2]) D_800799C0)[i][1] + 1) : 0;
            }
        }
        ((PadState1608C *) D_80079AF8)[i].prev = ((PadState1608C *) D_80079AF8)[i].cur;
        ((PadState1608C *) D_80079AF8)[i].cur = D_80079B40[i].button;
        ((PadState1608C *) D_80079AF8)[i].pressed =
            (u16) (((PadState1608C *) D_80079AF8)[i].cur & ~((PadState1608C *) D_80079AF8)[i].prev);
        ((PadState1608C *) D_80079AF8)[i].released =
            ((PadState1608C *) D_80079AF8)[i].prev & ~((PadState1608C *) D_80079AF8)[i].cur;
        ((PadState1608C *) D_80079AF8)[i].joy[0] = func_80015D60(D_80079B40[i].stick_x, 7, 0x3B);
        ((PadState1608C *) D_80079AF8)[i].joy[1] = func_80015D60(D_80079B40[i].stick_y, 7, 0x3D);
    }

    D_80079D69 = 1;
    osSetThreadPri(&D_80079BA8, old_pri);
}

void func_800165F0(void)
{
    func_80016934(0);
    if (D_80079B90[0].errno == 0) {
        osContGetReadData(D_80079B40);
    }
}

void func_8001662C(void)
{
    while (TRUE) {
        osRecvMesg(&D_80079B60, NULL, OS_MESG_BLOCK);
        if (D_80079BA0 == 1) {
            func_800165F0();
        } else {
            osSendMesg(&D_80079B78, NULL, OS_MESG_NOBLOCK);
        }
    }
}

// Joy thread entry.
void func_800166DC(UNUSED void *arg0)
{
    s32 eeprom_type = osEepromProbe(&D_80079B60);
    func_80016864();
    func_80014DC4();
    if (eeprom_type < EEPROM_TYPE_16K) {
        D_80079B90[0].errno = 8;
    }
    func_8001662C();
}

// Joy init: creates the queues and joy thread, registers the SI event, runs osContInit.
void func_80016734(void)
{
    osCreateMesgQueue(&D_80079B60, &D_80079B38, 1);
    osCreateMesgQueue(&D_80079B78, &D_80079B3C, 1);
    func_8001DCB0(&D_80079BA8, &D_80079D58, THREAD_ID_JOY, func_800166DC, NULL,
                  &D_80079D70[JOY_THREAD_STACK_SIZE / sizeof(u64)], JOY_THREAD_PRI);
    osSetEventMesg(OS_EVENT_SI, &D_80079B60, &D_80079B38);
    osContInit(&D_80079B60, &D_80079D68, D_80079B90);
    osStartThread(&D_80079BA8);
}

u8 func_800167F4(void)
{
    return D_80079B90[0].errno;
}

u8 func_80016800(s32 pad)
{
    return D_80079D6C[pad];
}

void func_80016810(void)
{
    if (MQ_GET_COUNT(&D_80079F70) == 1) {
        func_80016934(1);
        osStopThread(&D_80079BA8);
        osContStartReadData(&D_80079B60);
        osStartThread(&D_80079BA8);
    }
}

void func_80016864(void)
{
    s32 i;
    s32 j;

    for (i = 0; i < 4; i++) {
        ((u16 *) &D_80079AF8[i])[0] = 0;
        ((u16 *) &D_80079AF8[i])[1] = 0;
        ((u16 *) &D_80079AF8[i])[2] = 0;
        ((u16 *) &D_80079AF8[i])[3] = 0;
        D_80079AF8[i].stick[0] = 0.0f;
        D_80079AF8[i].stick[1] = 0.0f;

        for (j = 0; j < (s32) ARRLEN(D_800799C0[i]); j++) {
            D_800799C0[i][j] = 0;
        }

        for (j = 0; j < ARRLEN(D_800799E0[i].frames); j++) {
            D_800799E0[i].frames[j] = 0;
        }
    }
}

void func_8001690C(s32 pad, s32 value)
{
    D_800799E0[pad].frames[6] = value;
}

OSMesgQueue *func_80016928(void)
{
    return &D_80079B78;
}

// SI bus lock: mode 0 releases it, nonzero acquires it (also used by EEPROM and rumble code).
void func_80016934(s32 mode)
{
    s32 saved_int;

    if (mode == 0) {
        func_80016A48();
    } else {
        func_80016A04();
    }
    saved_int = __osDisableInt();
    if (mode != 0 || MQ_GET_COUNT(&D_80079F70) == 1) {
        D_80079BA0 = mode;
    }
    __osRestoreInt(saved_int);
}

OSContPad *func_800169A8(void)
{
    return &D_80079B58;
}

void func_800169B4(void)
{
    D_8003F5F0 = 1;
    osCreateMesgQueue(&D_80079F70, D_80079F88, ARRLEN(D_80079F88));
    osSendMesg(&D_80079F70, NULL, OS_MESG_NOBLOCK);
}

void func_80016A04(void)
{
    if (D_8003F5F0 == 0) {
        func_800169B4();
    }
    osRecvMesg(&D_80079F70, NULL, OS_MESG_BLOCK);
}

void func_80016A48()
{
    osSendMesg(&D_80079F70, NULL, OS_MESG_NOBLOCK);
}

s32 func_80016A74(s32 pad, f32 *magnitude_out)
{
    f32 xy[2];
    f32 magnitude;
    f32 angle;

    angle = -1.0f;
    func_80016068(pad, xy);
    magnitude = sqrtf((xy[0] * xy[0]) + (xy[1] * xy[1]));
    if (magnitude != 0.0f) {
        angle = func_80013B70(xy[1], xy[0], magnitude);
    }
    if (magnitude_out != NULL) {
        if (magnitude > 1.0f) {
            *magnitude_out = 1.0f;
        } else {
            *magnitude_out = magnitude;
        }
    }
    return (s32) angle;
}

s32 func_80016B30(s32 pad, s32 button)
{
    return ((s32(*)[14]) D_800799E0)[pad][button];
}

s32 func_80016B54(s32 pad, s32 button)
{
    return D_800799F8[pad][button];
}

s32 func_80016B78(s32 pad, s32 button)
{
    return D_80079A04[pad][button];
}

// Matching: old-style parameter list and the temporaries are needed for the match.
u32 func_80016B9C(pad, mask)
s32 pad;
u16 mask;
{
    int masked;
    s32 *offset_ptr;
    s32 offset;
    int result;
    offset = pad;
    offset = offset * 4;
    offset_ptr = &offset;
    masked = (*(u16 *) &((u32 *) D_80079AF8)[*offset_ptr] & mask) & 0xFFFFFFFFFFFFFFFFu;
    return result = masked;
}

// Matching: same as above.
unsigned int func_80016BBC(pad, mask)
s32 pad;
u16 mask;
{
    int masked_copy;
    s32 *offset_ptr;
    int masked;
    s32 offset;
    int result;
    offset = pad;
    offset = offset * 4;
    offset_ptr = &offset;
    masked = (*(u16 *) &D_80079AFC[*offset_ptr] & mask) & 0xFFFFFFFFFFFFFFFFu;
    masked_copy = masked;
    return result = masked_copy;
}

// Matching: no return value, as in the original.
int func_80016BDC(int channel)
{
    osContSetCh(channel);
}

// TU-NOTE: the .data of this file (formerly asm/data/core1/1E2D890.data.s) is defined here in C;
// values are taken from the ROM.
s32 D_8003F5F0 = 0x0;
