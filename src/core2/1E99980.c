// Dialog front end (gcdialog, gczoombox), pause menu glue (gcnewpause) and framebuffer copy.
#include <ultra64.h>
#include "gfx.h"
#include "core2/1E99980.h"

extern void _gcdialogexec_entrypoint_7();
extern void _gczoombox_entrypoint_2(s32 param_0, s32 param_1);
extern s32 D_80128A18;
extern u8 D_801288B8[];
extern void *D_801289DC;
extern void _gcdialogexec_entrypoint_10(void *arg);
extern void _gczoombox_entrypoint_4(void *arg);
typedef struct {
    u8 pad_0[0x120];
    void *box[2];
    s16 x[2];
    u8 pad_12C[0x30];
    u32 unused : 18;
    u32 busy : 1;
    u32 opening : 1;
    u32 unused2 : 12;
    u8 pad_160[6];
    s8 step;
} LocalDialog;
extern s8 D_8011A7C0[];
extern void _gczoombox_entrypoint_38(void *, s32);
typedef struct {
    u32 f0 : 18;
    u32 busy : 1;
    u32 f2 : 13;
} G_C0438;
extern G_C0438 D_80128A0C;
extern u8 D_80128A11;
extern s32 func_800A819C(void);
extern void _gcdialogexec_entrypoint_1();
extern u8 D_80128A30[192];
extern s32 _gcdialogexec_entrypoint_0(u32 *, u32, u32, f32 *, Unk80132ED0 *, s32, s32, s32, s32);
extern s16 D_80128A12;
extern s32 _gcdialogexec_entrypoint_6(void *arg, s32 param_1);
typedef struct {
    u8 pad_0[0x15E];
    u8 unk_15E : 2;
    u8 page_changed : 1;
    u8 going_back : 1;
    u8 local_3 : 4;
    u8 pad_15F[7];
    s8 page;
} Struct800C06C4;
extern u32 func_800C7150();
extern u32 defrag();
extern s32 D_80128AF0;
extern s32 D_8011A7D0;
extern u8 D_8012762C;
extern void *func_80014F00(void);
extern int D_80128B00;
int func_800C0F8C();
void func_800C0FD8();
int func_800C1044();

// TU-NOTE: D_801288B0 is an object, not a pointer: the target materialises %hi/%lo of the
// address everywhere. As an array, every form of access in this file means the same thing.
extern u8 D_801288B0[];
void func_800C0658();
extern s32 D_80128AF4;

// Dialog front end: start/stop conversations, zoombox slide animation, text id, paging, defrag.
s32 func_800C0090(s32 entry, s32 id)
{
    s32 ret;
    if (id == -1) {
        ret = 0;
    } else {
        ret = (id == ((u32) *(u16 *) (entry + 0x12) >> 1));
    }
    return ret;
}

void func_800C00BC()
{
    _gcdialogDll_entrypoint_0(&D_801288B0);
}

void func_800C00E0(void)
{
    if (func_800C0638()) {
        func_800FECB8(0);
    }
    func_800C0658();
    _gcdialogexec_entrypoint_7((s32 *) D_801288B0);
    *(u8 *) ((u8 *) (s32 *) D_801288B0 + 0x15C) = 0;
    *(u8 *) ((u8 *) (s32 *) D_801288B0 + 0x180) = 0;
}

// Matching: the line breaks in this function are needed for the match.
void func_800C0130(s32 arg)
{
    s32 *cursor;
    s32 *end;
    s32 *arg_copy;
    cursor = (s32 *) D_801288B0; end = (s32 *) D_801288B8;
    arg_copy = (s32 *) arg;
    do
    {
        if (cursor[0x48] != 0)
        {
            _gczoombox_entrypoint_2(cursor[0x48], (s32) arg_copy);
        }
        cursor++;
    }
    while (cursor != end);
    if ((s32) D_801289DC != 0)
    {
        _gczoombox_entrypoint_2((s32) D_801289DC, (s32) arg_copy);
    }
}

int func_800C01A8(param_0, param_1)
s16 param_0;
s32 param_1;
{
    // Matching: `| 0` is needed for the match.
    _gcdialogcamera_entrypoint_10((s32 *) D_801288B0, param_0, param_1 | 0);
}

// Matching: the line breaks in this function are needed for the match.
int func_800C01D8(s32 param_0, s32 param_1) { return _gcdialogexec_entrypoint_5((s32 *) D_801288B0, param_0, param_1); }

int func_800C0208()
{
    s32 field_168 = ((s32 *) &D_801288B0)[0x168 / 4];

    if (field_168 == 0) {
        return 0;
    }

    if (func_800C0090(field_168, ((s32 *) &D_801288B0)[0x16C / 4]) != 0) {
        return D_80128A18;
    }

    return 0;
}

s16 func_800C0258(void)
{
    u32 base = (u32) D_801288B0;
    u32 flags = *(u16 *) (base + 0x15E) & 0xFFFF;
    u32 offset = (flags >> 15) << 1;
    return (s16) (*(s16 *) ((base + 0x118) + offset) + 0xC);
}

void func_800C0284()
{
    u8 *cursor;
    u8 *end;
    if (*(u8 *) &D_80128A0C != 0) {
        _gcdialogexec_entrypoint_10(&D_801288B0);
    }
    for (cursor = D_801288B0, end = D_801288B8;;) {
        void *box = *(void **) (cursor + 0x120);
        if (box != 0) {
            _gczoombox_entrypoint_4(box);
        }
        cursor += 4;
        if (cursor != end) {
            continue;
        }
        break;
    }

    if (D_801289DC != 0) {
        _gczoombox_entrypoint_4((void *) D_801289DC);
    }
}

// Slide the two portrait boxes in or out by one step.
void func_800C0308(void)
{
    s32 delta;
    if ((*(LocalDialog *) D_801288B0).opening) {
        (*(LocalDialog *) D_801288B0).step++;
        delta = D_8011A7C0[(*(LocalDialog *) D_801288B0).step];
        if ((*(LocalDialog *) D_801288B0).box[0]) {
            (*(LocalDialog *) D_801288B0).x[0] -= delta;
            _gczoombox_entrypoint_38((*(LocalDialog *) D_801288B0).box[0],
                                     (*(LocalDialog *) D_801288B0).x[0]);
        }
        if ((*(LocalDialog *) D_801288B0).box[1]) {
            (*(LocalDialog *) D_801288B0).x[1] += delta;
            _gczoombox_entrypoint_38((*(LocalDialog *) D_801288B0).box[1],
                                     (*(LocalDialog *) D_801288B0).x[1]);
        }
        if ((*(LocalDialog *) D_801288B0).step == 12)
            (*(LocalDialog *) D_801288B0).busy = 0;
    } else {
        (*(LocalDialog *) D_801288B0).step--;
        delta = D_8011A7C0[(*(LocalDialog *) D_801288B0).step];
        if ((*(LocalDialog *) D_801288B0).box[0]) {
            (*(LocalDialog *) D_801288B0).x[0] += delta;
            _gczoombox_entrypoint_38((*(LocalDialog *) D_801288B0).box[0],
                                     (*(LocalDialog *) D_801288B0).x[0]);
        }
        if ((*(LocalDialog *) D_801288B0).box[1]) {
            (*(LocalDialog *) D_801288B0).x[1] -= delta;
            _gczoombox_entrypoint_38((*(LocalDialog *) D_801288B0).box[1],
                                     (*(LocalDialog *) D_801288B0).x[1]);
        }
        if ((*(LocalDialog *) D_801288B0).step == 0)
            (*(LocalDialog *) D_801288B0).busy = 0;
    }
}

void func_800C0438(void)
{
    if (D_80128A0C.busy) {
        func_800C0308();
    }
    if (func_800A819C() != 0) {
        if (!D_80128A0C.busy) {
            if ((func_800C0638() == 0) && ((s32) ((u32) D_80128A11 >> 4) > 0)) {
                _gcdialogexec_entrypoint_1(D_801288B0);
            } else {
                func_800C0284();
            }
        }
    }
}

s32 func_800C04C8(s32 param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4)
{
    s32 result;

    if (*(u8 *) (int *) D_80128A30 != 0) {
        result = _gcdialogexec_entrypoint_3((int *) D_801288B0, param_0, param_1, param_2, param_3,
                                             param_4);
    } else {
        result = 0;
    }
    return result;
}

u32 func_800C0534(u32 param_0, u32 param_1, f32 *param_2, Unk80132ED0 *param_3, s32 param_4,
                  s32 param_5, s32 param_6, s32 param_7)
{
    u32 *dialog;
    s32 result;
    short unk_0;
    unk_0 = param_7;
    // Matching: `0 & 0xFF` index is needed for the match.
    if (D_80128A30[0 & 0xFF] != 0) {
        dialog = (u32 *) D_801288B0;
        result = _gcdialogexec_entrypoint_0(dialog, param_0, param_1, param_2, param_3, param_4,
                                             param_5, param_6, unk_0);
    } else {
        result = 0;
    }
    return result;
}

s32 func_800C05B8(s16 param_0, s32 param_1, f32 *param_2, Unk80132ED0 *param_3, s32 param_4,
                  s32 param_5, s32 param_6)
{
    s32 result;
    if (*(u8 *) D_80128A30 != 0) {
        // Matching: reads the params back through their stack addresses; needed for the match.
        result = _gcdialogexec_entrypoint_0((u32 *) D_801288B0, *(s32 *) ((u8 *) &param_0 - 2),
                                             param_1, param_2, param_3, param_4, param_5, 0,
                                             *(s16 *) ((u8 *) &param_6 + 2));
    } else {
        result = 0;
    }
    return result;
}

// True while a dialog is active.
s32 func_800C0638()
{
    // Matching: the float/long cast round trip is needed for the match.
    return D_80128A12 != (unsigned long) (float) -0x7FFF;
}

s32 func_800C064C()
{
    return D_80128A12;
}

void func_800C0658()
{
    _gcdialogexec_entrypoint_2(&D_801288B0);
}

s32 func_800C067C(s32 id)
{
    s32 result;
    s32 current_id;

    current_id = func_800C064C();
    if (current_id != id) {
        return 0;
    }
    _gcdialogexec_entrypoint_6((void *) (void **) D_801288B0, 6);
    result = 1;
    return result;
}

// Next page.
void func_800C06C4(void)
{
    if (func_800C0638() != 0) {
        (*(Struct800C06C4 *) D_801288B0).page_changed = 1;
        (*(Struct800C06C4 *) D_801288B0).going_back = 0;
        (*(Struct800C06C4 *) D_801288B0).page++;
    }
}

// Previous page.
void func_800C0710(void)
{
    if (func_800C0638()) {
        (*(Struct800C06C4 *) D_801288B0).page_changed = 1;
        (*(Struct800C06C4 *) D_801288B0).going_back = 1;
        (*(Struct800C06C4 *) D_801288B0).page--;
    }
}

// Defrag: refresh the stored handles.
void func_800C075C(void)
{
    s32 i;
    for (i = 0; i < 2; i++) {
        if (((u32 *) D_801288B0)[0x48 + i])
            ((u32 *) D_801288B0)[0x48 + i] =
                func_800C7150(((u32 *) D_801288B0)[0x48 + i]);
        if (((u32 *) D_801288B0)[0x4B])
            ((u32 *) D_801288B0)[0x4B] = func_800C7150(((u32 *) D_801288B0)[0x4B]);
        if (((u32 *) D_801288B0)[0x41 + i])
            ((u32 *) D_801288B0)[0x41 + i] = defrag(((u32 *) D_801288B0)[0x41 + i]);
    }
}

int func_800C07F4()
{
    return ((u32) *(int *) &D_80128A0C << 21) >> 31;
}

void func_800C0808()
{
    _gcdialogexec_entrypoint_8(&D_801288B0);
}

void func_800C082C(unsigned int param_0)
{
    int bits;
    // Matching: the `bits` temporary is needed for the match.
    D_801288B0[0x15E] = (D_801288B0[0x15E] & 0xFFF7) | ((bits = (param_0 & 0xFFFFu) * 8) & 8);
}

void func_800C0850()
{
    ((unsigned char *) D_801288B0)[0x11C] &= ~0xC0;
    ((unsigned char *) D_801288B0)[0x11D] &= ~0xC0;
    _gcdialogexec_entrypoint_6((unsigned char *) D_801288B0, 6);
}

int func_800C0890(s32 param_0, s32 param_1)
{
    _gcdialogexec_entrypoint_9((s32 *) D_801288B0, param_0 | 0, param_1 | 0);
}

// Pause menu glue: open, close, update, draw, per-controller pause check, frozen-frame background.
// Pause menu glue (gcnewpause): defrag, create, free, update.
int func_800C08C0()
{
    if (D_80128AF0 != 0) {
        D_80128AF0 = defrag(D_80128AF0);
    }
}

void func_800C08F8()
{
    D_80128AF0 = _gcnewpause_entrypoint_0(D_80128AF4);
}

void func_800C0920()
{
    _gcnewpause_entrypoint_1(D_80128AF0);
    D_80128AF0 = 0;
}

s32 func_800C0948()
{
    s32 local_0;
    if (D_80128AF0 != 0) {
        local_0 = _gcnewpause_entrypoint_2(D_80128AF0);
    } else {
        local_0 = 0;
    }
    return local_0;
}

void func_800C0984(s32 gfx)
{
    if (func_800A8184() != 4) {
        if (D_8011A7D0 == 0) {
            func_800C1044(gfx);
        }
        D_8011A7D0 = 1;
        return;
    }
    if (func_800A8178() == 0) {
        if (D_8011A7D0 != 0) {
            func_800D58CC();
            func_800C0F8C(gfx);
            D_8011A7D0 = 0;
        } else {
            func_800C0FD8(gfx);
        }
        if (D_80128AF0 != 0) {
            _gcnewpause_entrypoint_3(gfx, D_80128AF0);
        }
    }
}

void func_800C0A2C(void)
{
}

// Returns 1 when Start opens the pause menu and stores the player index in D_80128AF4.
s32 func_800C0A34(void)
{
    s32 can_pause;
    s32 player;
    s32 Struct800C06C4;
    s32 flags_allow;
    can_pause = D_8012762C != 0 && func_800C95D4() != 0 && !func_800C9510() && !func_800C0638();
    if (func_800D3948() == 0) {
        player = func_800F54E4();
        Struct800C06C4 = func_800F6438(player) != 0 && !func_800DB9B0();
        can_pause &= Struct800C06C4;
        if ((can_pause && (func_800F6774(player) != 0)) && (func_80015FA0(0) == 1)) {
            D_80128AF4 = 0;
            return 1;
        }
        goto block_21;
    }
    if (can_pause != 0) {
        s32 player_count;
        s32 i;
        player_count = _gcstatusDll_entrypoint_11();
        flags_allow = func_800DA298(0x6B6) != 0 && !func_800DA298(0x6E3);
        i = 0;
        if (player_count > 0) {
        loop_15:
            if ((func_80015FA0(i) == 1) &&
                ((flags_allow != 0) ||
                 ((func_800F6438(i) != 0) && (func_800F6774(i) != 0)))) {
                D_80128AF4 = i;
                return 1;
            }

            i += 1;
            if (i == player_count) {
                goto block_21;
            }
            goto loop_15;
        }
    }
block_21:
    return 0;
}

s32 func_800C0BB4()
{
    return D_80128AF4;
}

// Probably a file split here based on bk decomp and bss (D_80128AF4).

extern Gfx D_8011A7E0[];
extern Gfx D_8011A840[];

// Copies a 304x224 RGBA16 framebuffer to another buffer via 32x32 texture tiles.
// copy_framebuffer: copies source to destination in 32x32 texture tiles (frozen pause background).
#if 0

    void func_800C0BC0(Gfx** gfx, 0, 0) {

    #else
        void func_800C0BC0(Gfx **gfx, void *destination, void *source) {
        s32 row;
        s32 col;
        Gfx *cur_gfx = *gfx;

        gSPDisplayList(cur_gfx++, OS_K0_TO_PHYSICAL(D_8011A7E0));
        gDPSetColorImage(cur_gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, OS_PHYSICAL_TO_K0(destination));

        for (row = 0; row < SCREEN_HEIGHT / 32 + 1; row++) {
            for (col = 0; col < SCREEN_WIDTH / 32 + 1; col++) {
                gDPLoadTextureTile(
                    cur_gfx++, osVirtualToPhysical(source), G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, SCREEN_HEIGHT,
                (col * 32), (row * 32), ((col + 1) * 32 - 1), ((row + 1) * 32 - 1), 0,
                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                gSPScisTextureRectangle(
                    cur_gfx++,
                (col * 32) * 4, (row * 32) * 4,
                ((col + 1) * 32) * 4, ((row + 1) * 32) * 4,
                0,
                (col * 32) << 5, (row * 32) << 5,
                1 << 10, 1 << 10);
            }
        }

        gSPDisplayList(cur_gfx++, OS_K0_TO_PHYSICAL(D_8011A840));
        gDPSetColorImage(cur_gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, OS_PHYSICAL_TO_K0(func_80014F00()));

        *gfx = cur_gfx;
    }
    #endif

        int func_800C0F8C(gfx) s32 gfx;
    {
        // Matching: the `zero` temporary is needed for the match.
        int zero;
        s32 dest;
        zero = 0;
        func_800EA34C(zero);
        D_80128B00 = 2;
        dest = func_8001A0A8();
        func_800C0BC0(gfx, dest, (void *) ((s32) func_80014F00() | 0));
    }

    void func_800C0FD8(gfx) s32 gfx;
    {
        int pad;
        s32 dest;
        if (!(s32) D_80128B00)
        {
            func_800D6E54(2);
            func_800FFD10(2);
        }
        else
        {
            (s32) D_80128B00--;
        }
        dest = func_80014F00();
        func_800C0BC0(gfx, dest, func_8001A0A8());
    }

    int func_800C1044(gfx) s32 gfx;
    {
        func_800EA34C(1);
    }

    // TU-NOTE: the .data of this file is defined here in C. Values are taken from the ROM.
    s8 D_8011A7C0[16] = { 0x1, 0x1E, 0x14, 0xF, 0xB, 0x8, 0x6, 0x4, 0x3, 0x2, -0x1, -0x1, 0x0, 0x0, 0x0, 0x0 };
    s32 D_8011A7D0 = 0x1;
    static u32 D_8011A7D0_rest[3] = { 0x0, 0x0, 0x0 };
    Gfx D_8011A7E0[12] = { 0xE7000000, 0x0, 0xD9C0FFFA, 0x0, 0xD9FFFFFF, 0x200004, 0xD7000002, 0xFFFFFFFF, 0xE200001C, 0xF0A4000, 0xE3000A01, 0x0, 0xFC157E2A, 0xFFFFF3F9, 0xE3001201, 0x0, 0xE3000C00, 0x0, 0xFA000000, 0xFF, 0xE3001801, 0xC0, 0xDF000000, 0x0 };
    Gfx D_8011A840[6] = { 0xE7000000, 0x0, 0xE3001201, 0x2000, 0xE3000C00, 0x80000, 0xE3001801, 0x0, 0xDF000000, 0x0, 0x0, 0x0 };
