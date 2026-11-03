#include "common.h"

struct OSPiInfo {
    u32 field0;
    u32 field4;
};
extern u8 *D_8007BCC0;
extern u16 *D_8007BCC4;
extern OSMesgQueue D_8007BEE0;
extern s16 D_8007BED8;
extern void func_80013D10(void *);
extern OSMesg D_8007BEF8;
extern void func_80014C40(void);
extern void *D_8007BCD4;
extern void *D_8007BCDC;
extern void *D_8007BCE4;
extern void heap_free();
extern s32 D_8007BCD0;
extern s32 D_8007BCD8;
extern s32 D_8007BCE0;
extern s16 D_8007BEDA;
typedef struct {
    s32 words[6];
} Struct8001A440;
extern Struct8001A440 D_8007BCF8[];
extern void *D_8007BCE8;
extern void *D_8007BCF0;
extern void *D_8007BCEC;
extern void *D_8007BCF4;

void func_8001A63C();

void func_8001A010(void)
{
}

// Allocates a buffer and rounds the address up to 64 bytes.
s32 func_8001A018(s32 size)
{
    s32 addr;
    addr = (s32) (D_8007BCC0 = heap_alloc(size + 0x40));
    while (addr % 0x40) {
        addr += 2;
    }

    return addr;
}

// Allocates the z-buffer.
void func_8001A080()
{
    D_8007BCC4 = func_8001A018(0x21D80);
}

// Returns the z-buffer.
s32 func_8001A0A8()
{
    return (s32) D_8007BCC4;
}

int func_8001A0B4()
{
    return 0x21D80;
}

// Reads the 16-bit depth sample at (x, y).
u16 func_8001A0C0(s32 x, s32 y)
{
    s32 row;
    s32 row_offset;

    row = y * 19;
    row_offset = row << 5;
    return *(u16 *) ((u8 *) D_8007BCC4 + row_offset + (x << 1));
}

// Takes the message-ring lock.
void func_8001A0F0()
{
    OSMesgQueue *queue = &D_8007BEE0;
    osRecvMesg(queue, 0, 1);
}

// Releases the message-ring lock.
void func_8001A11C()
{
    osSendMesg((void **) &D_8007BEE0, 0, OS_MESG_BLOCK);
}

// Sends a type 0 (audio) message through the ring.
void func_8001A148(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    u8 *msg;
    s16 *index;

    func_8001A0F0();
    index = &D_8007BED8;
    msg = (u8 *) D_8007BCF8 + *index * 0x18;
    *index = (s16) ((s32) (*index + 1) % 20);
    // Matching: the extra argument is needed for the match.
    func_8001A11C(msg);
    *(s32 *) (msg + 0) = 0;
    *(s32 *) (msg + 8) = arg0;
    *(s32 *) (msg + 12) = arg1;
    *(s32 *) (msg + 16) = arg2;
    *(s32 *) (msg + 20) = arg3;
    func_80013D10(msg);
}

// Sends a type 1 (gfx 3D) message through the ring.
void func_8001A1E0(s32 arg0, s32 arg1, s32 arg2)
{
    u32 *msg;

    func_8001A0F0();
    msg = (u32 *) ((char *) (u32 *) D_8007BCF8 + D_8007BED8 * 24);
    D_8007BED8 = (s16) ((D_8007BED8 + 1) % 20);
    // Matching: the extra argument is needed for the match.
    func_8001A11C(msg);
    msg[0] = 1;
    msg[1] = arg2;
    msg[2] = arg0;
    msg[3] = arg1;
    func_80013D10(msg);
}

void func_8001A270(s32 arg0, s32 arg1)
{
    func_8001A1E0(arg0, arg1, 0x40000000);
}

void func_8001A290()
{
    func_80015190();
}

void func_8001A2B0()
{
    func_80013D10(0x3);
}

// Resets the message ring and initialises the scheduler.
void func_8001A2D0()
{
    D_8007BED8 = 0;
    osCreateMesgQueue(&D_8007BEE0, &D_8007BEF8, 1);
    osSendMesg(&D_8007BEE0, 0, OS_MESG_BLOCK);
    func_80014C40();
}

// Frees the display-list, matrix and vertex buffers.
void func_8001A324()
{
    if ((void *) D_8007BCD0 != 0) {
        heap_free((void *) D_8007BCD0);
        heap_free(D_8007BCD4);
        heap_free((void *) D_8007BCD8);
        heap_free(D_8007BCDC);
        heap_free((void *) D_8007BCE0);
        heap_free(D_8007BCE4);
        D_8007BCD0 = 0;
    }
    func_8001A63C();
}

// Allocates the double-buffered display-list, matrix and vertex arenas.
int func_8001A3A0()
{
    if (!D_8007BCD0) {
        D_8007BCD0 = heap_alloc(30400);
        D_8007BCD4 = heap_alloc(30400);
        D_8007BCD8 = heap_alloc(0x12C00);
        D_8007BCDC = heap_alloc(0x12C00);
        D_8007BCE0 = heap_alloc(6880);
        D_8007BCE4 = heap_alloc(6880);
        func_8001A570();
    }
    D_8007BEDA = 0;
    func_800A9800();
}

void func_8001A440(s32 fb_index)
{
    Struct8001A440 *msg;

    func_8001A0F0();
    func_80015430(fb_index);
    msg = &D_8007BCF8[D_8007BED8];
    D_8007BED8 = (D_8007BED8 + 1) % 20;
    // Matching: the extra argument is needed for the match.
    func_8001A11C(msg);
    msg->words[0] = 7;
    func_80013D10(msg);
}

// Flips the buffer set and writes the current buffer pointers to out.
void func_8001A4B8(u8 *out)
{
    D_8007BEDA = 1 - D_8007BEDA;
    if (D_8007BCE8 != 0) {
        *(s32 *) ((s8 *) out + 0) = (s32) *(s32 *) ((u8 *) &D_8007BCE8 + (D_8007BEDA * 4));
    } else {
        *(s32 *) ((s8 *) out + 0) = (s32) *(s32 *) ((u8 *) &D_8007BCD0 + (D_8007BEDA * 4));
    }
    if (D_8007BCF0 != 0) {
        *(s32 *) ((s8 *) out + 4) = (s32) *(s32 *) ((u8 *) &D_8007BCF0 + (D_8007BEDA * 4));
    } else {
        *(s32 *) ((s8 *) out + 4) = (s32) *(s32 *) ((u8 *) &D_8007BCD8 + (D_8007BEDA * 4));
    }
    *(s32 *) ((s8 *) out + 8) = (s32) *(s32 *) ((u8 *) &D_8007BCE0 + (D_8007BEDA * 4));
}

int func_8001A570(void)
{
}

// Allocates the larger per-map display-list and matrix buffers.
void func_8001A578(s32 scale)
{
    u32 dl_a;
    s32 dl_b;
    s32 mtx_a;
    s32 size;
    s32 dl_count;
    s32 mtx_count;

    if (func_800D3948() != 0) {
        dl_count = 0x1388;
        if (scale != 0) {
            dl_count = scale * 0xE00;
            mtx_count = scale * 0x1DB;
        } else {
            mtx_count = 0;
        }
        size = dl_count * 8;
        if (dl_count != 0) {
            dl_a = (u32) heap_alloc(size);
            dl_b = heap_alloc(size);
            (*(struct OSPiInfo *) &D_8007BCE8).field0 = dl_a;
            (*(struct OSPiInfo *) &D_8007BCE8).field4 = dl_b;
        }
        size = mtx_count << 6;
        if (mtx_count != 0) {
            mtx_a = heap_alloc(size);
            (*(struct OSPiInfo *) &D_8007BCF0).field4 = (u32) heap_alloc(size);
            *(s32 *) ((char *) (struct OSPiInfo *) &D_8007BCF0 + 0) = mtx_a;
        }
    }
}

// Frees the per-map buffers.
void func_8001A63C()
{
    void *dl_bufs;
    void *mtx_bufs;
    dl_bufs = D_8007BCE8;
    mtx_bufs = D_8007BCF0;
    if (dl_bufs != 0) {
        heap_free(dl_bufs);
        heap_free(D_8007BCEC);
        D_8007BCE8 = 0;
    }
    if (mtx_bufs != 0) {
        heap_free(D_8007BCF0);
        heap_free(D_8007BCF4);
        D_8007BCF0 = 0;
    }
}
