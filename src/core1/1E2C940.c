#include "types.h"
#include "gfx.h"
#include "threads.h"
#include "common.h"

extern u32 *D_80078F70[];
extern void *heap_alloc_sided(s32, s32);
extern s32 D_80078F88;
extern s16 D_80078F62;
extern s16 D_80078F60;
typedef struct {
    OSMesgQueue *queue;
    OSMesg msg;
} Struct80014FE8;
extern OSThread D_80079140;
extern OSMesgQueue D_80078FD0;
extern OSMesgQueue D_80079010;
extern OSMesgQueue D_80079030;
extern OSMesg D_80079048[];
extern s32 D_80079700;
extern u16 D_80078F64;
extern volatile s32 D_80079138;
extern void *D_80078F68;
extern void *D_8003F530;
extern void *D_8003F4E0;
extern OSMesg D_80078FE8[10];
extern OSMesg D_80079028[1];
extern __OSThreadOddFpStorage D_800792F0;
extern s32 D_8007913C;
extern s32 D_80079704;
extern s32 func_80015184(void);
extern s32 func_80013474(void);
extern s32 func_80081D28(void);
extern void *D_80078F80[];
typedef struct {
    OSMesgQueue *queue;
    OSMesg msg;
} Pair_F90;
extern s32 D_8003F5D0;
extern Pair_F90 D_80078F90[8];
extern void *D_80078F84;
extern void aligned8_memset(void *dst, int val, int len);
extern s16 D_80079778[0x20];
extern s16 D_8003F5E0;
extern u8 D_80079710[8];
typedef struct {
    s32 vp_index;
    s16 x;
    s16 y;
    s16 w;
    s16 h;
} Struct8001592C_0;
typedef struct {
    s16 scale_x;
    s16 scale_y;
    s16 scale_z;
    s16 pad_6;
    s16 trans_x;
    s16 trans_y;
    s16 trans_z;
    s16 pad_E;
} Struct8001592C_1;
extern Struct8001592C_0 D_80079718[];
extern Struct8001592C_1 D_800797B8[];
typedef struct {
    s16 scale_x, scale_y, scale_z, pad_6, trans_x, trans_y, trans_z, pad_E;
} TileEntry;
extern void func_800CA510(s32, f32);

s32 func_80014F38();
s16 func_80014F58();
void func_80015178();
void func_8001546C();
f32 func_80015D14(OSLogItem *param_0);

// Allocates a heap block for slot and returns its 64-byte-aligned address.
u32 *func_80014E10(s32 slot, s32 size)
{
    u32 *block;
    char *aligned;
    block = (u32 *) heap_alloc_sided(size + 0x40, 1);
    D_80078F70[slot] = block;
    aligned = (char *) block;
    while ((u32) aligned & 0x3F) {
        aligned++;
    }
    return (u32 *) aligned;
}

// Allocates the two framebuffers and the extra 0x10EC0-byte buffer.
void func_80014E6C()
{
    *(int *) D_80078F80 = func_80014E10(0, 0x21D80);
    D_80078F84 = func_80014E10(1, 0x21D80);
    D_80078F88 = func_80014E10(2, 0x10EC0);
}

// Returns the framebuffer size in bytes.
u32 func_80014EC8()
{
    return FRAMEBUFFER_SIZE_BYTES;
}

// Returns the back buffer.
int func_80014ED4()
{
    int idx = func_80014F38();
    return ((int *) D_80078F80)[idx];
}

s32 func_80014F00()
{
    return ((s32 *) D_80078F80)[D_80078F62 ^ func_80014F58()];
}

s32 func_80014F38(void)
{
    return D_80078F60 ^ 1;
}

int func_80014F4C(void)
{
    return *(s16 *) &D_80078F64;
}

s16 func_80014F58()
{
    return D_80078F60;
}

// Registers a queue and message for VI events (max 8).
void func_80014F64(OSMesgQueue *queue, OSMesg mesg)
{
    s32 i;
    for (i = 0; i < ARRLEN(D_80078F90); i++) {
        if (D_80078F90[i].queue == NULL) {
            D_80078F90[i].queue = queue;
            D_80078F90[i].msg = mesg;
            return;
        }
    }
}

// Sets up the VI manager and mode for the TV type and starts the retrace thread.
void func_80014FE8(void)
{
    s32 i;

    osCreateViManager(0xFE);
    switch (osTvType) {
        case 0:
        case 1:
            D_80078F68 = &D_8003F4E0;
            break;
        case 2:
            D_80078F68 = &D_8003F530;
    }
    osViSetMode(D_80078F68);
    osViBlack(1);
    D_80079700 = 1;
    osViSetSpecialFeatures(0x40);
    osViSetSpecialFeatures(2);
    osViSetSpecialFeatures(0x20);
    osCreateMesgQueue(&D_80078FD0, D_80078FE8, 10);
    osCreateMesgQueue(&D_80079010, D_80079028, 1);
    osCreateMesgQueue(&D_80079030, D_80079048, 60);
    osViSetEvent(&D_80078FD0, NULL, 1);
    *(u16 *) &D_80078F60 = 0;
    D_80078F64 = 1;
    for (i = 0; i < 8; i++) {
        ((Struct80014FE8 *) D_80078F90)[i].queue = NULL;
    }
    D_80079138 = 0;
    func_80015178(2);
    func_8001DCB0(&D_80079140, &D_800792F0, 0, func_8001546C, NULL, &D_80079700, 0x50);
    osStartThread(&D_80079140);
}

// Sets the retraces per frame used for frame pacing.
void func_80015178(retraces) s32 retraces;
{
    D_8007913C = retraces;
}

s32 func_80015184()
{
    return D_8007913C;
}

void func_80015190(void)
{
    osSendMesg(&D_80079010, NULL, 0);
}

// End-of-frame sync: waits for the retraces, swaps buffers and unblanks after the first frame.
void func_800151BC(s32 wait_signal)
{
    void *fb;
    s32 *late_ptr;
    osSetThreadPri(0, 0x7F);
    func_80013500(0x23);
    func_80013488();
    if (wait_signal != 0) {
        osRecvMesg(&D_80079010, 0, 1);
    }
    while (D_80079138 < (func_80015184() - D_80079704)) {
        osRecvMesg(&D_80079030, 0, 1);
    }

    while (*(s32 *) ((u8 *) &D_80079030 + 8) != 0) {
        osRecvMesg(&D_80079030, 0, 0);
    }

    if (*(volatile s16 *) &D_80078F62 == 0) {
        if (D_80079700 != 0) {
            D_80079700--;
            if (D_80079700 == 0) {
                osViBlack(0);
            }
        }
        D_80078F60 = func_80014F38();
        osViSwapBuffer((void *) (u32 *) D_80078F80[D_80078F60]);
        late_ptr = &D_80079704;
        D_80079704 = 0;
        if (!(osDpGetStatus() & 2)) {
            fb = osViGetCurrentFramebuffer();
            if (osViGetNextFramebuffer() != fb) {
                // Matching: needed for the match.
                if (!D_80079704) {
                }
                do {
                    osRecvMesg(&D_80079030, 0, 1);
                    D_80079704 = *late_ptr + 1;
                    if (osDpGetStatus() & 2) {
                        break;
                    }
                    fb = osViGetCurrentFramebuffer();
                } while (osViGetNextFramebuffer() != fb);
            }
        }
    } else {
        *(volatile s16 *) &D_80078F62 = 0;
    }
    D_80078F64 = D_80079138;
    D_80079138 = 0;
    func_800134C4();
    osSetThreadPri(0, 0x14);
    if ((func_80013474() == 0) && (func_80081D28() != 0)) {
        do {
            osYieldThread();
        } while ((func_80013474() == 0) && (func_80081D28() != 0));
    }
    func_80013500(0xA);
}

void func_80015410()
{
    func_800151BC(0x1);
}

// Selects the displayed framebuffer and swaps to it.
void func_80015430(unsigned int index)
{
    void **buffers;
    void **table;
    D_80078F60 = index;
    // Matching: the copies of the buffer table and the ^ 0 are needed for the match.
    table = D_80078F80;
    buffers = table;
    osViSwapBuffer(buffers[D_80078F60 ^ 0]);
}

// VI retrace thread: counts retraces and forwards the VI event to the registered queues.
void func_8001546C(arg) s32 arg;
{
    s32 limit_reached;
    OSMesg msg;
    s32 unk_0;
    s32 unk_1;
    s32 i;

    while (1) {
        osRecvMesg(&D_80078FD0, &msg, 1);
        func_80014A54();
        // Matching: needed for the match.
        if (1) {
            D_80079138++;
            limit_reached = (D_80079138 == 0x258);
            unk_0 = (func_8001E7C0() == 0);
        }
        unk_1 = D_8003F5D0;
        if (((limit_reached != 0) && (unk_0 != 0)) && (unk_1 != 0)) {
            func_8001E5DC(2);
            D_8003F5D0 = 0;
        }
        osSendMesg(&D_80079030, NULL, 0);
        for (i = 0; i < 8; i++) {
            if (D_80078F90[i].queue != NULL) {
                osSendMesg(D_80078F90[i].queue, D_80078F90[i].msg, 0);
            }
        }
    }
}

int func_8001559C(long blank)
{
    osViBlack(blank);
}

// Clears the framebuffers.
void func_800155BC()
{
    if (*(void **) D_80078F80 != 0) {
        aligned8_memset(*(void **) D_80078F80, 0x10001, 0x21D80);
        osWritebackDCache(*(void **) D_80078F80, 0x21D80);
    }

    if (D_80078F84 != 0) {
        aligned8_memset(D_80078F84, 0x10001, 0x21D80);
        osWritebackDCache(D_80078F84, 0x21D80);
    }

    if (*(void **) &D_80078F88 != 0) {
        aligned8_memset(*(void **) &D_80078F88, 0x10001, 0x10EC0);
        osWritebackDCache(*(void **) &D_80078F88, 0x10EC0);
    }
}

// Shifts the screen by (dx, dy), clamped, by patching the VI mode.
void func_80015670(s32 dx, s32 dy)
{
    u8 *v_start_src = ((u8 *) D_80078F68) + 0x30;
    u8 *v_start_copy = ((u8 *) D_80078F68) + 0x44;
    u8 *h_start = ((u8 *) D_80078F68) + 0x1C;
    s32 mask;
    u8 *v_start_begin = ((u8 *) D_80078F68) + 0x30;
    u8 *v_start_end = ((u8 *) D_80078F68) + 0x32;

    if (dx < -0x20) {
        dx = -0x20;
    }

    else if (dx >= 0x21) {
        dx = 0x20;
    }

    if (dy < -0x28) {
        dy = -0x28;
    }

    else if (dy >= 0x19) {
        dy = 0x18;
    }

    mask = osSetIntMask(0x80401);
    *((s16 *) (h_start + 0)) = dx + 0x80;
    *((s16 *) (h_start + 2)) = dx + 0x2E0;
    *((s16 *) (v_start_begin + 0)) = dy + 0x30;
    *((s16 *) (v_start_end + 0)) = dy + 0x1F4;
    *((s32 *) (v_start_copy + 0)) = *((s32 *) (v_start_src + 0));
    osSetIntMask(mask);
}

s32 func_8001575C()
{
    return D_80078F88;
}

int func_80015768()
{
    D_80078F62 = 1;
}

// Busy-waits on the VI scanline.
void wait_one_frame(void)
{
    while (osViGetCurrentLine() < 5) {
    }

    while (osViGetCurrentLine() > 5) {
    }
}

void set_widescreen(s32 enabled)
{
    widescreen_enabled = enabled;
}

// Emits a gSPViewport command for the viewport handle.
void func_800157EC(s32 *vp_handle, u8 **gfx)
{
    u8 *vp_base;
    u8 *cmd;
    // Matching: the extra temporary and the 4 ^ 0 below are needed for the match.
    vp_base = (cmd = ((u32 *) D_800797B8));
    cmd = *gfx;
    {
        *gfx += 8;
        *(s32 *) ((s8 *) cmd + 0) = 0xDC080008;
        *(u8 **) ((s8 *) cmd + 4) =
            (u8 *) ((((*vp_handle * (4 ^ 0)) * 4) + 0x80000000) + vp_base);
    }
}

// Allocates a free Vp slot and returns its index.
s32 func_80015828(void)
{
    s32 i;

    for (i = 0; i < 0x20; i++) {
        if (D_80079778[i] == 0) {
            break;
        }
    }

    D_80079778[i] = -1;
    return i;
}

// Marks a Vp slot for release.
void func_80015860(s32 index)
{
    ((u16 *) D_80079778)[index] = 1;
}

// Clears the release marks of the Vp slots.
// Matching: the line breaks in this function are needed for the match.
void func_80015878(void)
{
    s16 *slot;
    s16 *slots_end;

    do { 0; slots_end = (s16 *) D_800797B8; slots_end += 0; slot = (s16 *) D_80079778; local_loop: { if (slot[0] > 0) { slot[0] = 0; } if (slot[1] > 0) { slot[1] = 0; } if (slot[2] > 0) { slot[2] = 0; } if (slot[3] > 0) { slot[3] = 0; } slot += 4; } } while (0);
    if (slot != slots_end)
    {
        goto local_loop;
    }

    D_8003F5E0 = -1;
}

// Releases a viewport handle and its Vp slot.
void func_800158E4(s32 *handle)
{
    func_80015860(*handle);
    *(u8 *) ((char *) D_80079710 + ((s32) handle - (s32) ((u8 *) D_80079718)) / 12) = 0;
}

// Creates a viewport handle (pool of 8) with its Vp entry.
// Matching: the line breaks in this function are needed for the match.
Struct8001592C_0 *func_8001592C(s32 x, s32 y, s32 w, s32 h)
{
    s32 i;
    Struct8001592C_0 *handle;
    Struct8001592C_1 *vp;
    i = 0; while (1) {

        if (D_80079710[i] != 0) {
            i++;
            if (i == 8) {
                break;
            }
        }

        else
        {
            break;
        }
    }

    D_80079710[i] = 1;
    handle = &D_80079718[i];
    handle->vp_index = func_80015828();
    handle->x = x;
    handle->y = y;
    handle->w = w;
    handle->h = h;
    vp = &D_800797B8[handle->vp_index];
    vp->scale_x = w * 2;
    vp->scale_y = h * 2;
    vp->scale_z = 0x1FF;
    vp->pad_6 = 0;
    vp->trans_x = (s32) ((x + (w * 0.5f)) * 4.0f);
    vp->trans_y = (s32) ((y + (h * 0.5f)) * 4.0f);
    vp->trans_z = 0x1FF;
    vp->pad_E = 0;
    osWritebackDCache(vp, 0x200);
    return handle;
}

// Reallocates the Vp slot and stores the given scale and translation (pixels * 4).
void func_80015A70(s32 *vp_index, f32 scale_x, f32 scale_y, f32 trans_x, f32 trans_y)
{
    s32 index;
    u8 *vp;

    func_80015860(*vp_index);
    index = func_80015828();
    *vp_index = index;
    vp = (u8 *) ((s32 *) D_800797B8) + (index * 0x10);
    (*(s16 *) ((s8 *) (vp) + 4)) = 0x1FF;
    (*(s16 *) ((s8 *) (vp) + 6)) = 0;
    (*(s16 *) ((s8 *) (vp) + 0xC)) = 0x1FF;
    (*(s16 *) ((s8 *) (vp) + 0xE)) = 0;
    (*(s16 *) ((s8 *) (vp) + 0)) = (s16) (s32) (scale_x * 4.0f);
    (*(s16 *) ((s8 *) (vp) + 2)) = (s16) (s32) (scale_y * 4.0f);
    (*(s16 *) ((s8 *) (vp) + 8)) = (s16) (s32) (trans_x * 4.0f);
    (*(s16 *) ((s8 *) (vp) + 0xA)) = (s16) (s32) (trans_y * 4.0f);
    osWritebackDCache(vp, 0x200);
}

// Updates a viewport handle, clamping the rectangle to 304x228.
void func_80015B34(void *handle, s32 x, s32 y, s32 width, s32 height)
{
    s32 idx;
    s32 x_end, y_end;
    s32 w, h;
    f32 cx, cy;
    func_80015860(*(u32 *) handle);
    idx = func_80015828();
    *(u32 *) handle = idx;

    x_end = x + width;
    y_end = y + height;
    if (x < 0)
        x = 0;
    else if (x >= 0x131)
        x = 0x130;
    if (y < 0)
        y = 0;
    else if (y >= 0xE5)
        y = 0xE4;
    if (x_end < 0)
        x_end = 0;
    else if (x_end >= 0x131)
        x_end = 0x130;
    if (y_end < 0)
        y_end = 0;
    else if (y_end >= 0xE5)
        y_end = 0xE4;

    w = x_end - x;
    h = y_end - y;
    cx = (f32) x + (f32) w * 0.5f;
    cy = (f32) y + (f32) h * 0.5f;

    ((s16 *) handle)[4] = w;
    ((s16 *) handle)[5] = h;
    ((s16 *) handle)[2] = x;
    ((s16 *) handle)[3] = y;

    ((TileEntry *) D_800797B8)[idx].scale_x = w * 2;
    ((TileEntry *) D_800797B8)[idx].scale_y = h * 2;
    ((TileEntry *) D_800797B8)[idx].scale_z = 0x1FF;
    ((TileEntry *) D_800797B8)[idx].pad_6 = 0;
    ((TileEntry *) D_800797B8)[idx].trans_z = 0x1FF;
    ((TileEntry *) D_800797B8)[idx].pad_E = 0;
    ((TileEntry *) D_800797B8)[idx].trans_x = cx * 4.0f;
    ((TileEntry *) D_800797B8)[idx].trans_y = cy * 4.0f;
    osWritebackDCache(&((TileEntry *) D_800797B8)[idx], 0x200);
}

// Reads x, y, w, h out of a viewport handle.
int func_80015CC0(s16 handle[5], s32 *out_x, s32 *out_y, s32 *out_w, s32 *out_h)
{
    *out_x = handle[2];
    *out_y = handle[3];
    *out_w = handle[4];
    *out_h = handle[5];
}

// Feeds the viewport aspect ratio to the perspective setup.
void func_80015CE8(s32 vp, s32 camera)
{
    func_800CA510(camera, func_80015D14(vp));
}

// Viewport aspect ratio, scaled by 4/3 when widescreen is enabled.
f32 func_80015D14(OSLogItem *vp)
{
    f32 aspect;
    aspect = (f32) (s16) vp->argCount / (f32) (s16) vp->eventID;
    if (widescreen_enabled) {
        aspect *= 1.3333334f;
    }
    return aspect;
}

// TU-NOTE: the .data of this file (formerly asm/data/core1/1E2C940.data.s) is defined here;
// values come from the ROM. Each *_rest array continues the symbol before it.
void *D_8003F4E0 = 0;
static u32 D_8003F4E0_rest[19] = {0x320E, 0x130, 0x3E52239, 0x20D,   0xC15,    0xC150C15, 0x8002E0,
                                  0x200,  0x0,   0x260,     0x400,   0x2F01F5, 0xE0204,   0x2,
                                  0x260,  0x400, 0x2F01F5,  0xE0204, 0x2};
void *D_8003F530 = (void *) 0x1C000000;
static u32 D_8003F530_rest[39] = {
    0x320E, 0x130,    0x4651E39, 0x20D, 0x40C11,  0xC190C1A, 0x8002E0, 0x200,   0x0, 0x260,
    0x400,  0x2F01F5, 0xE0204,   0x2,   0x260,    0x400,     0x2F01F5, 0xE0204, 0x2, 0xE000000,
    0x320E, 0x130,    0x4541E3A, 0x271, 0x170C69, 0xC6F0C6D, 0x9002F0, 0x200,   0x0, 0x260,
    0x400,  0x3F0259, 0x9026B,   0x2,   0x260,    0x400,     0x3F0259, 0x9026B, 0x2};
s32 D_8003F5D0 = 0x1;
static u32 D_8003F5D0_rest[3] = {0x0, 0x0, 0x0};
s16 D_8003F5E0 = -0x1;
