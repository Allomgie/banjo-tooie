#include "common.h"
#define R(i) ((u32) ctx->gpr[i])
#define F(i) ((s32) ctx->fpr[1 + (i) * 2])

typedef struct {
    u32 mask;
    u32 value;
    char *name;
} RegisterBitName;
extern void func_8001D37C();
typedef struct {
    u64 gpr[29];
    u64 lohi[2];
    u32 sr;
    u32 pc;
    u32 cause;
    u32 badvaddr;
    u32 pad108;
    u32 fpcsr;
    u32 fpr[2 * 16];
} RegCtx;
typedef union {
    f32 as_f32;
    s32 as_s32;
} RegisterFloatBits;
extern s32 func_800F21C4(f32);

// TU-NOTE: the overlay data is defined here in C; IDO places the string literals in .rodata where the original has them.
// Bit-name tables: {mask, value, name}, terminated by a zero mask.
// RDP DPC_STATUS bit names
RegisterBitName D_80800EA0_gzreg[12] = {
    0x1,   0x1,   "DPC_STATUS_XBUS_DMEM_DMA", 0x2,   0x2,   "DPC_STATUS_FREEZE",
    0x4,   0x4,   "DPC_STATUS_FLUSH",         0x8,   0x8,   "DPC_STATUS_START_GCLK",
    0x10,  0x10,  "DPC_STATUS_TMEM_BUSY",     0x20,  0x20,  "DPC_STATUS_PIPE_BUSY",
    0x40,  0x40,  "DPC_STATUS_CMD_BUSY",      0x80,  0x80,  "DPC_STATUS_CBUF_READY",
    0x100, 0x100, "DPC_STATUS_DMA_BUSY",      0x200, 0x200, "DPC_STATUS_END_VALID",
    0x400, 0x400, "DPC_STATUS_START_VALID",   0x0,   0x0,   ""};
// RSP SP_STATUS bit names
RegisterBitName D_80800F30_gzreg[16] = {
    0x1,    0x1,    "SP_STATUS_HALT",       0x2,    0x2,    "SP_STATUS_BROKE",
    0x4,    0x4,    "SP_STATUS_DMA_BUSY",   0x8,    0x8,    "SP_STATUS_DMA_FULL",
    0x10,   0x10,   "SP_STATUS_IO_FULL",    0x20,   0x20,   "SP_STATUS_SSTEP",
    0x40,   0x40,   "SP_STATUS_INTR_BREAK", 0x80,   0x80,   "SP_STATUS_YIELD",
    0x100,  0x100,  "SP_STATUS_YIELDED",    0x200,  0x200,  "SP_STATUS_TASKDONE",
    0x400,  0x400,  "SP_STATUS_SIG3",       0x800,  0x800,  "SP_STATUS_SIG4",
    0x1000, 0x1000, "SP_STATUS_SIG5",       0x2000, 0x2000, "SP_STATUS_SIG6",
    0x4000, 0x4000, "SP_STATUS_SIG7",       0x0,    0x0,    ""};
// Cause bit names
u32 D_80800FF0_gzreg[84] = {
    0x80000000, 0x80000000, (u32) "BD",
    0x8000,     0x8000,     (u32) "IP8",
    0x4000,     0x4000,     (u32) "IP7",
    0x2000,     0x2000,     (u32) "IP6",
    0x1000,     0x1000,     (u32) "IP5",
    0x800,      0x800,      (u32) "IP4",
    0x400,      0x400,      (u32) "IP3",
    0x200,      0x200,      (u32) "IP2",
    0x100,      0x100,      (u32) "IP1",
    0x7C,       0x0,        (u32) "Interrupt",
    0x7C,       0x4,        (u32) "TLB modification exception",
    0x7C,       0x8,        (u32) "TLB exception on load or instruction fetch",
    0x7C,       0xC,        (u32) "TLB exception on store",
    0x7C,       0x10,       (u32) "Address error on load or instruction fetch",
    0x7C,       0x14,       (u32) "Address error on store",
    0x7C,       0x18,       (u32) "Bus error exception on instruction fetch",
    0x7C,       0x1C,       (u32) "Bus error exception on data reference",
    0x7C,       0x20,       (u32) "System call exception",
    0x7C,       0x24,       (u32) "Breakpoint exception",
    0x7C,       0x28,       (u32) "Reserved instruction exception",
    0x7C,       0x2C,       (u32) "Coprocessor unusable exception",
    0x7C,       0x30,       (u32) "Arithmetic overflow exception",
    0x7C,       0x34,       (u32) "Trap exception",
    0x7C,       0x38,       (u32) "Virtual coherency exception on intruction fetch",
    0x7C,       0x3C,       (u32) "Floating point exception (see fpcsr)",
    0x7C,       0x5C,       (u32) "Watchpoint exception",
    0x7C,       0x7C,       (u32) "Virtual coherency exception on data reference",
    0x0,        0x0,        (u32) ""};
// SR bit names
u32 D_80801140_gzreg[93] = {
    0x80000000,  0x80000000,  (u32) "CU3", 0x40000000,  0x40000000,  (u32) "CU2", 0x20000000,
    0x20000000,  (u32) "CU1", 0x10000000,  0x10000000,  (u32) "CU0", 0x8000000,   0x8000000,
    (u32) "RP",  0x4000000,   0x4000000,   (u32) "FR",  0x2000000,   0x2000000,   (u32) "RE",
    0x400000,    0x400000,    (u32) "BEV", 0x200000,    0x200000,    (u32) "TS",  0x100000,
    0x100000,    (u32) "SR",  0x40000,     0x40000,     (u32) "CH",  0x20000,     0x20000,
    (u32) "CE",  0x10000,     0x10000,     (u32) "DE",  0x8000,      0x8000,      (u32) "IM8",
    0x4000,      0x4000,      (u32) "IM7", 0x2000,      0x2000,      (u32) "IM6", 0x1000,
    0x1000,      (u32) "IM5", 0x800,       0x800,       (u32) "IM4", 0x400,       0x400,
    (u32) "IM3", 0x200,       0x200,       (u32) "IM2", 0x100,       0x100,       (u32) "IM1",
    0x80,        0x80,        (u32) "KX",  0x40,        0x40,        (u32) "SX",  0x20,
    0x20,        (u32) "UX",  0x18,        0x10,        (u32) "USR", 0x18,        0x8,
    (u32) "SUP", 0x18,        0x0,         (u32) "KER", 0x4,         0x4,         (u32) "ERL",
    0x2,         0x2,         (u32) "EXL", 0x1,         0x1,         (u32) "IE",  0x0,
    0x0,         (u32) ""};
// FPCSR bit names
u32 D_808012B4_gzreg[71] = {0x1000000, 0x1000000, (u32) "FS",
                            0x800000,  0x800000,  (u32) "C",
                            0x20000,   0x20000,   (u32) "Unimplemented operation",
                            0x10000,   0x10000,   (u32) "Invalid operation",
                            0x8000,    0x8000,    (u32) "Division by zero",
                            0x4000,    0x4000,    (u32) "Overflow",
                            0x2000,    0x2000,    (u32) "Underflow",
                            0x1000,    0x1000,    (u32) "Inexact operation",
                            0x800,     0x800,     (u32) "EV",
                            0x400,     0x400,     (u32) "EZ",
                            0x200,     0x200,     (u32) "EO",
                            0x100,     0x100,     (u32) "EU",
                            0x80,      0x80,      (u32) "EI",
                            0x40,      0x40,      (u32) "FV",
                            0x20,      0x20,      (u32) "FZ",
                            0x10,      0x10,      (u32) "FO",
                            0x8,       0x8,       (u32) "FU",
                            0x4,       0x4,       (u32) "FI",
                            0x3,       0x0,       (u32) "RN",
                            0x3,       0x1,       (u32) "RZ",
                            0x3,       0x2,       (u32) "RP",
                            0x3,       0x3,       (u32) "RM",
                            0x0,       0x0,       (u32) "",
                            0x0,       0x0};

// Prints "label: xVALUE <NAME,NAME,...>" for each table entry whose masked bits match.
void func_80800000_gzreg(u32 reg_value, char *label, RegisterBitName *table)
{
    s32 first;

    first = 1;
    func_8001D37C("%s: x%08X ", label, reg_value);
    func_8001D37C("<");
    for (; table->mask; table++) {
        if ((table->mask & reg_value) == table->value) {
            if (first)
                first = 0;
            else
                func_8001D37C(",");
            func_8001D37C("%s", table->name);
        }
    }
    func_8001D37C(">\n");
}

// Prints a float register as S.NaN/Q.NaN/INF, a decimal number, or the raw integer for denormals.
void func_808000CC_gzreg(buf, val) char *buf;
RegisterFloatBits val;
{
    switch (func_800F21C4(val.as_f32)) {
        case 0:
            sprintf(buf, "S.NaN");
            break;
        case 1:
            sprintf(buf, "Q.NaN");
            break;
        case 2:
            sprintf(buf, "+ve INF");
            break;
        case 3:
            sprintf(buf, "-ve INF");
            break;
        case 4:
        case 5:
        case 8:
        case 9:
            sprintf(buf, "%.6e", (f64) val.as_f32);
            break;
        case 6:
        case 7:
            sprintf(buf, "%d", val.as_s32);
    }
}

// First page: PC, cause, GPRs, FPCSR, FPRs, SR.
void gzreg_entrypoint_0(u8 *thread)
{
    char buf_a[24];
    char buf_b[16];
    char buf_c[16];
    RegCtx *ctx;

    ctx = (RegCtx *) (thread + 0x20);
    func_8001D37C("pc:x%08X\n", *(s32 *) (thread + 0x11C));
    func_80800000_gzreg(ctx->cause, "cause", D_80800FF0_gzreg);
    func_8001D37C("\n");
    func_8001D37C("at:x%08X v0:x%08X v1:x%08X a0:x%08X\n", R(0), R(1), R(2), R(3));
    func_8001D37C("a1:x%08X a2:x%08X a3:x%08X t0:x%08X\n", R(4), R(5), R(6), R(7));
    func_8001D37C("t1:x%08X t2:x%08X t3:x%08X t4:x%08X\n", R(8), R(9), R(10), R(11));
    func_8001D37C("t5:x%08X t6:x%08X t7:x%08X s0:x%08X\n", R(12), R(13), R(14), R(15));
    func_8001D37C("s1:x%08X s2:x%08X s3:x%08X s4:x%08X\n", R(16), R(17), R(18), R(19));
    func_8001D37C("s5:x%08X s6:x%08X s7:x%08X t8:x%08X\n", R(20), R(21), R(22), R(23));
    func_8001D37C("t9:x%08X gp:x%08X sp:x%08X s8:x%08X\n", R(24), R(25), R(26), R(27));
    func_8001D37C("ra:x%08X %s          badvaddr:x%08X\n", R(28), "          ", ctx->badvaddr);
    func_8001D37C("\n");
    func_80800000_gzreg(ctx->fpcsr, "fpcsr", D_808012B4_gzreg);
    func_8001D37C("\n");
    func_808000CC_gzreg(buf_a, F(0));
    func_808000CC_gzreg(buf_b, F(1));
    func_808000CC_gzreg(buf_c, F(2));
    func_8001D37C("f0  %-13s f2  %-13s f4  %-13s\n", buf_a, buf_b, buf_c);
    func_808000CC_gzreg(buf_a, F(3));
    func_808000CC_gzreg(buf_b, F(4));
    func_808000CC_gzreg(buf_c, F(5));
    func_8001D37C("f6  %-13s f8  %-13s f10 %-13s\n", buf_a, buf_b, buf_c);
    func_808000CC_gzreg(buf_a, F(6));
    func_808000CC_gzreg(buf_b, F(7));
    func_808000CC_gzreg(buf_c, F(8));
    func_8001D37C("f12 %-13s f14 %-13s f16 %-13s\n", buf_a, buf_b, buf_c);
    func_808000CC_gzreg(buf_a, F(9));
    func_808000CC_gzreg(buf_b, F(10));
    func_808000CC_gzreg(buf_c, F(11));
    func_8001D37C("f18 %-13s f20 %-13s f22 %-13s\n", buf_a, buf_b, buf_c);
    func_808000CC_gzreg(buf_a, F(12));
    func_808000CC_gzreg(buf_b, F(13));
    func_808000CC_gzreg(buf_c, F(14));
    func_8001D37C("f24 %-13s f26 %-13s f28 %-13s\n", buf_a, buf_b, buf_c);
    func_808000CC_gzreg(buf_a, F(15));
    func_8001D37C("f30 %-13s\n", buf_a);
    func_8001D37C("\n");
    func_80800000_gzreg(ctx->sr, "sr", D_80801140_gzreg);
}

// Second page: RDP and RSP registers, free heap size.
void gzreg_entrypoint_1(void)
{
    func_8001D37C("RDP current = 0x%08X   (0x%016llx) \n",
                  *(volatile u32 *) 0xA4100008 + 0x80000000,
                  *(u64 *) (*(volatile u32 *) 0xA4100008 + 0x80000000));
    func_8001D37C("RDP start   = 0x%08X   (0x%016llx) \n",
                  *(volatile u32 *) 0xA4100000 + 0x80000000,
                  *(u64 *) (*(volatile u32 *) 0xA4100000 + 0x80000000));
    func_8001D37C("RDP end     = 0x%08X   (0x%016llx) \n",
                  *(volatile u32 *) 0xA4100004 + 0x80000000,
                  *(u64 *) (*(volatile u32 *) 0xA4100004 + 0x80000000));
    func_80800000_gzreg(*(volatile u32 *) 0xA410000C, "\nRDP status:", D_80800EA0_gzreg);
    func_80800000_gzreg(*(volatile u32 *) 0xA4040010, "\nRSP status:", D_80800F30_gzreg);
    func_8001D37C("\nFree memory was %d bytes.\n", heap_bytes_free());
}

// Returns the faulted thread's saved PC.
int gzreg_entrypoint_2(union U *thread)
{
    return *(s32 *) ((char *) thread + 0x11C);
}
