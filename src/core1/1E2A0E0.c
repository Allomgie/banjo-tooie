// Audio manager (heap, synth, sample DMA cache, audio thread) plus cartridge ROM PI-DMA helpers.
#include "common.h"

extern s32 D_80046A88;
extern s32 osViClock;
typedef struct Struct_69A40_s {
    struct Struct_69A40_s *next;
    struct Struct_69A40_s *prev;
    u8 pad_8[8];
    void *buffer;
} Struct_69A40;
typedef struct Obj_s {
    u8 *cmd_list;
    u32 pad_4;
    u16 unk_8;
    u16 pad_A;
    struct Obj_s *unk_C;
} Obj;
typedef struct {
    u8 *out_bufs[2];
    Obj *cmd_lists[3];
    void *unk_14;
} Struct_459E0;
typedef struct {
    s32 max_vvoices;
    s32 num_pvoices;
    s32 max_params;
    s32 num_aux;
    s32 *(*dma_new)(s32 **);
    void *heap;
    s32 output_rate;
    u8 fx_type;
    u8 pad_1D[3];
    void *fx_params;
} Struct_6A1A8;
extern OSMesg D_800694A0[];
extern OSMesgQueue D_80045BF0;
extern OSMesg D_80045C08[];
extern OSMesgQueue D_80045BB8;
extern OSMesg D_80045BD0[];
extern u8 D_8006A1D2;
extern Struct_6A1A8 D_8006A1A8;
extern u8 D_8006A158[];
extern Struct_69A40 D_80069A40[90];
extern u8 D_8006A1D8[2][0x4E20];
extern s16 D_80073E18[3][0x730];
extern Struct_459E0 D_800459E0;
extern u8 D_800459F8[];
extern u8 D_80045BA8[];
extern u8 D_80046A78[];
extern u8 D_8003CA44[];
extern void func_80020D80(void *param_0, Struct_6A1A8 *param_1);
extern void func_80020E40(Struct_69A40 *param_0, Struct_69A40 *param_1);
extern void *func_80020EE4(s32 param_0, s32 param_1, void *param_2, s32 param_3, s32 param_4);
extern void func_8001DCB0(void *param_0, void *param_1, s32 param_2, void *param_3, void *param_4,
                          void *param_5, s32 param_6);
extern u8 *D_8003CC5C;
extern s32 D_8003CC60;
typedef struct {
    void *buf;
    s16 num_samples;
} AiBuf;
extern u32 D_8006A150;
extern s32 D_80076938;
extern s32 func_80021574(u32, s32 *, u32, s32);
extern void func_8001A148();
extern s32 D_8003CC64;
typedef struct Struct80012BB4Node {
    struct Struct80012BB4Node *next;
    struct Struct80012BB4Node *prev;
    u32 address;
    u32 last_frame;
    u8 *buffer;
} Struct80012BB4Node;
typedef struct {
    u32 initialized;
    Struct80012BB4Node *list_head;
    Struct80012BB4Node *free_list;
} Struct80012BB4Manager;
typedef struct {
    u32 pad_0[6];
} Struct80012BB4Mesg;
extern u32 D_8006A148;
extern u32 D_8006A14C;
extern Struct80012BB4Mesg D_80069580[];
extern s32 D_80069A30;
extern s32 D_80069488;
extern s32 D_8003CA40;
extern int D_80069568;
extern u16 D_8006A1CC;
extern u16 D_8006A1CE;
extern OSMesgQueue D_8007695C;
extern u32 D_8003CC70;
extern OSMesg D_80076958;
extern OSMesgQueue D_800769B8;
extern OSMesgQueue D_80076978;
extern u32 *D_800769CC[];
extern u32 *D_800769D0[];
extern OSPiHandle *D_80076940;

void func_8001268C();
void func_800128C0();
s32 func_800129FC(u8 *frame, AiBuf *prev_buf);
void func_80012B74();
s32 *func_80012D4C(s32 **state);
void func_80012D84();
s32 func_80012EA0();
void func_80012F0C();
void func_80012F34();

// Audio manager: audio heap, synth init, sample DMA cache, audio thread and frame building, volume.
// Audio manager init: clears the heap, sets the VI clock, starts the audio thread.
void func_800125B0(void)
{
    s32 *heap;
    bzero(&D_80046A88, 0x22A00);
    heap = &D_80046A88;
    *(s32 **) ((s8 *) (s32 *) D_80046A78 + 4) =
        (*(s32 **) ((s8 *) (s32 *) D_80046A78 + 0) = heap);
    *(s32 *) ((s8 *) (s32 *) D_80046A78 + 8) = 0x22A00;
    *(s32 **) ((s8 *) (s32 *) D_80046A78 + 4) =
        (*(s32 **) ((s8 *) (s32 *) D_80046A78 + 0) = heap);
    *(s32 *) (0, (s8 *) (s32 *) D_80046A78 + 0xC) = 0;
    switch (osTvType) {
        case 0:

        case 1:
            osViClock = 0x02E6D354;
            break;

        case 2:
            osViClock = 0x02E6025C;
    }

    func_8001268C();
    func_800DC380();
    func_80016C00();
    func_80012F0C(4);
    func_80012F34(0, 4);
    func_80012F34(1, 4);
    func_80012EA0();
}

// Creates the queues, initializes the synth and allocates DMA buffers, output buffers and command lists, then creates the audio thread.
void func_8001268C(void)
{
    s32 i;

    osCreateMesgQueue((OSMesgQueue *) &D_80069488, D_800694A0, 0x32);
    osCreateMesgQueue(&D_80045BF0, D_80045C08, 8);
    osCreateMesgQueue(&D_80045BB8, D_80045BD0, 8);

    D_8006A1D2 = 0;
    D_8006A1A8.max_vvoices = 0x18;
    D_8006A1A8.num_pvoices = 0x18;
    D_8006A1A8.max_params = 0x80;
    D_8006A1A8.num_aux = 1;
    D_8006A1A8.dma_new = func_80012D4C;
    D_8006A1A8.fx_type = 6;
    D_8006A1A8.fx_params = D_8003CA44;
    D_8006A1A8.heap = D_80046A78;
    D_8006A1A8.output_rate = osAiSetFrequency(0x5622);
    func_80020D80(D_8006A158, &D_8006A1A8);

    D_80069A40[0].prev = NULL;
    D_80069A40[0].next = NULL;
    for (i = 0; i < 89; i++) {
        func_80020E40(&D_80069A40[i + 1], &D_80069A40[i]);
        D_80069A40[i].buffer = func_80020EE4(0, 0, D_8006A1A8.heap, 1, 0x200);
    }
    D_80069A40[i].buffer = func_80020EE4(0, 0, D_8006A1A8.heap, 1, 0x200);

    for (i = 0; i < 2; i++) {
        D_800459E0.out_bufs[i] = D_8006A1D8[i];
    }

    for (i = 0; i < 3; i++) {
        D_800459E0.cmd_lists[i] = func_80020EE4(0, 0, D_8006A1A8.heap, 1, 0x10);
        D_800459E0.cmd_lists[i]->unk_8 = 0;
        D_800459E0.cmd_lists[i]->unk_C = D_800459E0.cmd_lists[i];
        D_800459E0.cmd_lists[i]->cmd_list = D_80073E18[i];
    }

    func_8001DCB0(D_800459F8, D_80045BA8, 4, func_800128C0, NULL, D_80046A78, 0x32);
}

// audio_thread_entry
void func_800128C0(param_0) s32 param_0;
{
    s32 warmup;

    warmup = 1;
loop_1:
    osRecvMesg(((s32 *) &D_80045BB8), NULL, 1);

if (func_800129FC(*(s32 *) ((s8 *) ((s32 *) &D_800459E0 + ((s32) (s32) D_8006A148 % 3)) + 8),
                  D_8003CC60) != 0) {
    if (warmup == 0) {
        osRecvMesg((s32 *) &D_80045BF0, &D_8003CC5C, 1);
        func_80012B74(*(s32 *) ((s8 *) D_8003CC5C + 4));
        D_8003CC60 = *(s32 *) ((s8 *) D_8003CC5C + 4);
    } else {
        warmup -= 1;
    }
}

func_800E96B0(1);
goto loop_1;
}

// Queues the previous frame buffer, picks the sample count for the next frame, builds the command list and submits the audio task.
// TU-NOTE: D_80076938 is also written as D_80076940[-2].
// Returns 0 if nothing was submitted.
s32 func_800129FC(u8 *frame, AiBuf *prev_buf)
{
    u32 phys;
    s32 unk_0;
    s32 cmd_len;
    s32 len;
    // Matching: self-referencing initializer is needed for the match.
    s32 ret = ret * 0;

    phys = osVirtualToPhysical(*((void **) frame));
    func_80012D84();
    len = osAiGetLength() >> 2;

if (prev_buf != 0) {
    ret = osAiSetNextBuffer(prev_buf->buf, prev_buf->num_samples << 2);
}

if (ret == -1) {
    return 0;
}

if ((len < 0x5C) && ((unk_0 = D_80076938) == 0)) {
    *(s16 *) (frame + 4) = 0x398;
    // Matching: * 0 is needed for the match.
    unk_0 = 2 + unk_0 * 0;
    ((s32 *) &D_80076940)[-2] = unk_0;
} else {

unk_0 = D_80076938;

if ((len >= 0x115) && (unk_0 == 0)) {
    *(s16 *) (frame + 4) = 0x228;
    // Matching: * 0 is needed for the match.
    unk_0 = 2 + unk_0 * 0;
    ((s32 *) &D_80076940)[-2] = unk_0;
} else {

*((s16 *) (frame + 4)) = 0x2E0;

if (unk_0 != 0) {
    unk_0--;
    ((s32 *) &D_80076940)[-2] = unk_0;
}

}
}
ret = func_80021574(((u32 *) &D_800459E0)[D_8006A150], &cmd_len, phys, *((s16 *) (frame + 4)));
if (cmd_len == 0) {
    return 0;
}
func_8001A148(((u32 *) &D_800459E0)[D_8006A150], ret, ((u32 *) &D_80045BF0), frame + 8);
D_8006A150 ^= 1;
return 1;
}

void func_80012B74(param_0) s32 param_0;
{
    int zero;
    zero = 0;
    if (((osAiGetLength() >> 2) == 0) && (D_8003CC64 == zero)) {
        D_8003CC64 = zero;
    }
}

// DMA callback: returns the physical address of the 0x200-byte sample buffer for addr, starting a PI DMA if it is not cached.
void *func_80012BB4(u32 addr, u32 len, s32 state)
{
    u8 *buf;
    u32 end;
    u32 unk_0;
    Struct80012BB4Node *node;
    u32 tmp;
    Struct80012BB4Node *prev;
    prev = 0;
    tmp = (u32) (*((Struct80012BB4Manager *) &D_80069A30)).list_head;
    node = (Struct80012BB4Node *) tmp;
    while (node != 0) {
        end = node->address + 0x200;
        if (addr < node->address) {
            break;
        }
        if (!(((s32) end) < ((s32) (addr + len)))) {
            node->last_frame = D_8006A148;
            return osVirtualToPhysical(
                (void *) ((((u32) node->buffer) + addr) - node->address));
        }
        prev = node;
        node = node->next;
    }

    node = (*((Struct80012BB4Manager *) &D_80069A30)).free_list;
    if (node == 0) {
        return osVirtualToPhysical((Struct80012BB4Node *) tmp);
    }
    (*((Struct80012BB4Manager *) &D_80069A30)).free_list = node->next;
    func_80020E74(node);
    if (prev != 0) {
        func_80020E40(node, prev);
    } else {
        tmp = (u32) (*((Struct80012BB4Manager *) &D_80069A30)).list_head;
        if (tmp != 0) {
            (*((Struct80012BB4Manager *) &D_80069A30)).list_head = node;
            node->next = (Struct80012BB4Node *) tmp;
            node->prev = 0;
            ((Struct80012BB4Node *) tmp)->prev = node;
        } else {
            (*((Struct80012BB4Manager *) &D_80069A30)).list_head = node;
            node->next = 0;
            node->prev = 0;
        }
    }
    tmp = addr & 1;
    addr = addr - tmp;
    node->address = addr;
    node->last_frame = D_8006A148;
    buf = node->buffer;
    osPiStartDma(&D_80069580[D_8006A14C++], 1, 0, addr, buf, 0x200, ((u32 *) &D_80069488));
    return (void *) (((u32) osVirtualToPhysical(buf)) + tmp);
}
typedef struct ListNode {
    u32 pad_0[6];

} DmaMesg;

// Returns the DMA callback and its state; sets up the buffer lists on first use.
s32 *func_80012D4C(s32 **state)
{
    if ((*(u8 *) ((s8 *) (&D_80069A30) + (0))) == 0) {
        (*(s32 *) ((s8 *) (&D_80069A30) + (4))) = 0;
        (*(s32 **) ((s8 *) (&D_80069A30) + (8))) = ((s32 *) D_80069A40);
        (*(u8 *) ((s8 *) (&D_80069A30) + (0))) = 1U;
    }
    *state = &D_80069A30;
    return &func_80012BB4;
}

// Waits for pending DMAs and recycles sample buffers not used in the last frame.
void func_80012D84(void)
{
    u32 i;
    s32 msg;
    u8 *next;
    u8 *node;

    msg = 0;
    i = 0;
    if (D_8006A14C != 0) {
        do {
            osRecvMesg(&D_80069488, &msg, 0);
            i += 1;
        } while (i < (u32) D_8006A14C);
    }
    node = (*(u8 **) ((s8 *) (&D_80069A30) + (4)));
    if (node != NULL) {
        do {
            next = (*(u8 **) ((s8 *) (node) + (0)));

if ((u32) (*(s32 *) ((s8 *) node + 0xC) + 1) < (u32) D_8006A148) {
    if (node == *(u8 **) ((s8 *) &D_80069A30 + 4)) {
        *(u8 **) ((s8 *) &D_80069A30 + 4) = *(u8 **) ((s8 *) node + 0);
    }
    func_80020E74(node);
    if (*(u8 **) ((s8 *) &D_80069A30 + 8) != NULL) {
        func_80020E40(node, *(u8 **) ((s8 *) &D_80069A30 + 8));
    } else {
        *(u8 **) ((s8 *) &D_80069A30 + 8) = node;
        *(u8 **) ((s8 *) node + 0) = NULL;
        *(s32 *) ((s8 *) node + 4) = 0;
    }
}

node = next;
} while (next != NULL);
}
D_8006A14C = 0;
D_8006A148 += 1;
}

// Starts the audio thread (once).
s32 func_80012EA0(void){
    if(D_8003CA40 == 0){
        D_8003CA40 = 1;
        osStartThread(((s32 *) D_800459F8));
    }
}

int func_80012EDC()
{
    return (int)((int *) D_80046A78);
}

s32 func_80012EE8(void){
    s32 addr = (s32)&D_80069488;
    return addr;
}

int func_80012EF4()
{
    return &D_80069568;
}

int func_80012F00()
{
    return (int)((int *) &D_80045BB8);
}

// Sets the output mode.
void func_80012F0C(mode) int mode;
{
    D_8006A1CC = mode;
    func_80021A00(mode & 0xFF);
}

// Sets the mode of one bus.
void func_80012F34(bus, mode) s32 bus; long mode;
{
    u16 *modes = (u16 *) (&D_8006A1CE);
    // Matching: empty block steers IDO's register allocation.
    {
    }
    // Matching: ^ 0 is needed for the match.
    modes[bus ^ 0] = mode;
    func_80021AD0();
}

// Blocking and stacked-async PI DMA reads from cartridge ROM, PI manager init.
int *func_80012F60()
{
    return ((int *) &D_8007695C);
}

int func_80012F6C()
{
    return (int)((int *) &D_80076940);
}

// Reads size bytes from ROM in 128 KB chunks.
// Matching: the line breaks in this function are needed for the match.
void rom_dma_read(void *vaddr, s32 devaddr, s32 size)
{
    s32 block_cnt;
    s32 block_remainder;
    int i;
    osWritebackDCache(vaddr, size);
    block_cnt = size / 0x20000; block_cnt++; block_cnt--; block_remainder = size % 0x20000; for (i = 0; i < block_cnt; i++) { ((s32) D_8003CC70)++; osPiStartDma(((OSIoMesg *) &D_80076940), 0, 0, devaddr, vaddr, 0x20000, &D_8007695C); osRecvMesg(&D_8007695C, 0, 1); devaddr += 0x20000; vaddr = ((u32 *) vaddr) + 0x8000;
        ((s32) D_8003CC70)--;
    }

    ((s32) D_8003CC70)++;
    osPiStartDma(((OSIoMesg *) &D_80076940), 0, 0, devaddr, vaddr, block_remainder, &D_8007695C);
    osRecvMesg(&D_8007695C, 0, 1);
    ((s32) D_8003CC70)--;
    osInvalDCache(vaddr, size);
}

// Reads a fixed 0x1800 bytes from ROM.
void func_8001311C(s32 vaddr, s32 devaddr)
{
    osWritebackDCache(vaddr, 0x1800);
    D_8003CC70 += 1;
    osPiStartDma(((OSPiHandle *) &D_80076940), 0, 0, devaddr, vaddr, 0x1800, &D_8007695C);
    osRecvMesg(&D_8007695C, 0, 1);
    D_8003CC70 -= 1;
    osInvalDCache(vaddr, 0x1800);
}

// Creates the PI message queues and the PI manager.
void func_800131C0()
{
    osCreateMesgQueue(&D_8007695C, &D_80076958, 1);
    osCreateMesgQueue(&D_800769B8, &D_80076978, 16);
    osCreatePiManager(0x96, &D_800769B8, &D_80076978, 16);
}

// Starts an asynchronous ROM read; completed by func_800132BC.
void func_80013224(s32 devaddr, u32 *vaddr, u32 *size)
{

    D_8003CC70++;
    D_800769CC[D_8003CC70] = vaddr;
    D_800769D0[D_8003CC70] = size;
    osWritebackDCache(vaddr, size);
    osPiStartDma(&D_80076940, 0, 0, devaddr, vaddr, size, ((u32 *) &D_8007695C));
}

// Waits for the oldest asynchronous ROM read and invalidates its cache range.
void func_800132BC()
{
    osRecvMesg(&D_8007695C, 0, 1);
    osInvalDCache(((u8 * *) D_800769CC)[D_8003CC70], ((u8 * *) D_800769D0)[D_8003CC70]);
    D_8003CC70--;
}

// Matching: the unprototyped weak alias is needed for the match.
#pragma weak func_80013224_unproto = func_80013224
    extern void func_80013224_unproto();

// Starts an asynchronous ROM read and waits for it.
void func_80013324()
{
    func_80013224_unproto();
    func_800132BC();
}

// Waits for all pending asynchronous ROM reads.
void func_8001334C(void)
{
    while (((int) D_8003CC70) > 0)
    {
        func_800132BC();
    }
}

// TU-NOTE: the .data of this file (formerly asm/data/core1/1E2A0E0.data.s) is defined here in C; values are taken from the ROM.
s32 D_8003CA40 = 0x0;
u8 D_8003CA44[536] = { 0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x1A, 0x40, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xC0, 0x0, 0x0, 0x26, 0x66, 0xFF, 0xFF, 0xD9, 0x9A, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xC0, 0x0, 0x0, 0x1, 0x88, 0x0, 0x0, 0x26, 0x66, 0xFF, 0xFF, 0xD9, 0x9A, 0x0, 0x0, 0x2B, 0x84, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0x70, 0x0, 0x0, 0xB, 0x0, 0x0, 0x0, 0x40, 0x0, 0xFF, 0xFF, 0xC0, 0x0, 0x0, 0x0, 0x11, 0xEB, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4, 0x20, 0x0, 0x0, 0x8, 0x40, 0x0, 0x0, 0x20, 0x0, 0xFF, 0xFF, 0xE0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xD, 0xC8, 0x0, 0x0, 0x18, 0x18, 0x0, 0x0, 0x40, 0x0, 0xFF, 0xFF, 0xC0, 0x0, 0x0, 0x0, 0x11, 0xEB, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xE, 0x78, 0x0, 0x0, 0x14, 0xA8, 0x0, 0x0, 0x20, 0x0, 0xFF, 0xFF, 0xE0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x14, 0xA8, 0x0, 0x0, 0x17, 0x40, 0x0, 0x0, 0x20, 0x0, 0xFF, 0xFF, 0xE0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x19, 0x78, 0x0, 0x0, 0x32, 0xC8, 0xFF, 0xFF, 0xCD, 0x38, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x7C, 0x0, 0x0, 0x0, 0xA, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0xA, 0x50, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0x98, 0x0, 0x0, 0x33, 0x34, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x73, 0x35, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
u8 *D_8003CC5C = 0;
s32 D_8003CC60 = 0x0;
s32 D_8003CC64 = 0x1;
static u32 D_8003CC64_rest[2] = { 0x0, 0x0 };
u32 D_8003CC70 = 0x0;
static u32 D_8003CC70_rest[7] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
