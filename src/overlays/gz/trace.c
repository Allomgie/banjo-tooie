#include "common.h"

typedef struct {
    s16 blocks[4];
    s16 words, shorts, pointers;
    u8 extra_size;
    u8 pad_F[0x1D];
    s16 type;
    u8 pad_2E[6];
} TraceHeader1459;
typedef struct {
    s32 type;
    TraceHeader1459 *header;
    u8 *words;
    s32 word_count;
    u8 *shorts, *pointers, *prefix, *extra;
    u8 *blocks[4];
    u8 *end;
} TraceState1459;
extern s32 B_80800ABA_gztrace;
extern s32 B_80800ABD_gztrace;
extern s32 B_80800AC3_gztrace;
extern s32 B_80800ACD_gztrace;
extern s32 B_80800AD5_gztrace;
extern s32 B_80800AD6_gztrace;
extern s32 overlay_syscalls;
extern s32 overlay_syscalls_end;
extern s32 func_8001D37C();

// Returns 1 if addr is word-aligned and in the 0x80000000-0x80800000 range.
s32 func_80800000_gztrace(u32 addr)
{
    if ((addr < 0x80000000U) || (addr >= 0x80800001U) || (addr & 3)) {
        return 0;
    }
    return 1;
}

// strcpy
int func_80800038_gztrace(u8 *dst, u8 *src)
{
    while ((*dst++ = *src++) != '\0')
        ;
}

// strcat
void func_80800068_gztrace(char *dst, char *src)
{
    char *end = dst;
    while (*end++) {
    }
    end--;
    while (*end++ = *src++) {
    }
}

// strlen
s32 func_808000B8_gztrace(void *str)
{
    u8 *p;
    u32 len;
    len = 0;
    p = (u8 *) str;
    if (*p) {
        do {
            len++;
            p++;
        } while (*p);
    }
    return len;
}

// Fits src into head_len + tail_len + 1 chars: pads with spaces, or keeps the head and tail joined by sep.
void func_808000E8_gztrace(u8 *dst, u8 *src, s32 head_len, u8 sep, s32 tail_len)
{
    s32 i;
    s32 j;
    s32 src_len;
    s32 width;

    src_len = func_808000B8_gztrace(src);
    width = head_len + tail_len + 1;
    if (width >= src_len) {
        func_80800038_gztrace(dst, src);
        for (i = src_len; i < width; i++) {
            dst[i] = ' ';
        }
    } else {
        for (i = 0; i < head_len; i++) {
            dst[i] = src[i];
        }
        dst[i++] = sep;
        for (j = src_len - tail_len; i < width; i++) {
            dst[i] = src[j++];
        }
    }
    dst[width] = 0;
}

// Writes the low num_bytes of value as lowercase hex to buf; returns the end of the output.
u8 *func_80800290_gztrace(u32 value, s32 num_bytes, u8 *buf)
{
    s32 i;
    u8 *out = buf;
    u8 *bytes = (u8 *) &value;

    for (i = 4 - num_bytes; i < 4; i++) {
        *out = (bytes[i] >> 4) + 0x30;
        if (*out >= 0x3A) {
            *out += 0x27;
        }
        out++;
        *out = (bytes[i] & 0xF) + 0x30;
        if (*out >= 0x3A) {
            *out += 0x27;
        }
        out++;
    }
    return out;
}

// TU-NOTE: .bss is defined here in C, ahead of its first use: IDO places .bss objects used before
// their definition first, the rest in definition order.
// TU-NOTE: the _pad/_tail objects fill bytes that no code names.
// TU-NOTE: B_80800ABA/ABD/AC3/ACD/AD5/AD6_gztrace are labels inside these objects (linker symbols
// in undefined_syms.us.txt).
TraceState1459 B_80800A70_gztrace;
u8 B_80800A70_gztrace_pad[4];
s32 B_80800AA8_gztrace;
u8 B_80800AD6_gztrace_tail[4];
u8 B_80800AD6_gztrace_tail1[256];

// Fills B_80800A70_gztrace with the section pointers of a trace header.
void func_808003D0_gztrace(TraceHeader1459 *header)
{
    // Matching: the temporary index variable and the always-true empty if below are needed.
    int block_index;
    B_80800A70_gztrace.type = header->type;
    B_80800A70_gztrace.word_count = header->words;
    B_80800A70_gztrace.header = header;
    B_80800A70_gztrace.prefix = (u8 *) header + 0x34;
    B_80800A70_gztrace.words = (u8 *) header + 0x38;
    B_80800A70_gztrace.extra = ((u8 *) header + 0x38) + (header->words * 4);
    B_80800A70_gztrace.shorts =
        (u8 *) ((((u32) B_80800A70_gztrace.extra + header->extra_size) + 3) & ~3U);
    B_80800A70_gztrace.pointers = B_80800A70_gztrace.shorts + (header->shorts * 2);
    B_80800A70_gztrace.pointers += 3;
    B_80800A70_gztrace.pointers = (u8 *) ((u32) B_80800A70_gztrace.pointers & ~3U);
    block_index = 0;
    B_80800A70_gztrace.blocks[block_index] = B_80800A70_gztrace.pointers + (header->pointers * 4);
    B_80800A70_gztrace.blocks[0] += 15;
    B_80800A70_gztrace.blocks[0] = (u8 *) ((u32) B_80800A70_gztrace.blocks[0] & ~15U);
    if ((header && header) != 0) {
    }
    B_80800A70_gztrace.blocks[1] = B_80800A70_gztrace.blocks[0] + (header->blocks[0] * 16);
    B_80800A70_gztrace.blocks[2] = B_80800A70_gztrace.blocks[1] + (header->blocks[1] * 16);
    B_80800A70_gztrace.blocks[3] = B_80800A70_gztrace.blocks[2] + (header->blocks[2] * 16);
    B_80800A70_gztrace.end = B_80800A70_gztrace.blocks[3] + (header->blocks[3] * 16);
}

// Unwinds one stack frame: scans forward from *pc_ref for the saved ra and the sp adjustment.
s32 func_808004B0_gztrace(u32 **sp_ref, u32 **pc_ref, u32 *jal_target, u32 **fallback_pc, u32 *ret_addr)
{
    u32 *pc;
    u32 *sp;
    u32 insn;
    s32 done;

    sp = *sp_ref;
    pc = *pc_ref;
    done = 0;
    *fallback_pc = *pc_ref - 2;
    do {
        insn = *pc++;
        switch (insn >> 16) {
            case 0x8FBF:
                ret_addr = *(u32 **) ((u8 *) sp + (s16) insn);
                break;
            case 0x27BD:
                sp += (s16) insn >> 2;
                break;
            case 0x3E0:
                done = 1;
        }
    } while (!done);
    insn = *pc;
    if ((insn >> 16) == 0x27BD) {
        sp += (s16) insn >> 2;
    }
    *pc_ref = ret_addr;
    *sp_ref = sp;
    if (ret_addr != NULL) {
        insn = ret_addr[-2];
        switch (insn >> 26) {
            case 3:
                *jal_target = ((insn + 0xF4000000) << 2) + 0x80000000;
                return 1;
            case 0:
                if ((insn & 0x3F) == 9) {
                    *jal_target = 0;
                    return 1;
                }
                break;
            default:
                return 0;
        }
    }
    return 0;
}

// Prints up to 16 frames of a stack trace; prints nothing if quiet is set.
void func_808005C4_gztrace(s32 pc, u8 *sp, s32 ret_addr, s32 platform, s32 quiet)
{
    s32 func_addr;
    s32 fallback_pc;
    s32 header;
    s32 lookup_addr;
    s32 shown_func;
    s32 shown_pc;
    s32 i;

    i = 0;
    if (func_808004B0_gztrace(&sp, &pc, &func_addr, &fallback_pc, ret_addr) != 0) {
        do {
            shown_func = func_addr;
            shown_pc = fallback_pc;
            if (func_addr != 0) {
                lookup_addr = func_addr;
            } else {
                lookup_addr = fallback_pc;
            }
            header = func_80081AA4(lookup_addr);
            if (header != 0) {
                func_808003D0_gztrace(header);
                // Raw offsets into B_80800A70_gztrace: 0x1C = extra, 0x20 = blocks[0].
                func_808000E8_gztrace(&B_80800AA8_gztrace,
                                      *(s32 *) ((u8 *) (s32 *) &B_80800A70_gztrace + 0x1C), 0xD,
                                      0x7E, 2);
                if (platform == 0) {
                    if (shown_func != 0 && (shown_func < (s32) &overlay_syscalls ||
                                            (s32) &overlay_syscalls_end < shown_func)) {
                        shown_func -= *(s32 *) ((u8 *) (s32 *) &B_80800A70_gztrace + 0x20);
                    }
                    shown_pc -= *(s32 *) ((u8 *) (s32 *) &B_80800A70_gztrace + 0x20);
                }
            } else {
                func_808000E8_gztrace(&B_80800AA8_gztrace, "core", 0xD, 0x7E, 2);
            }
            switch (platform) {
                case 0:
                    func_80800068_gztrace(&B_80800AA8_gztrace, " (********,********) ");
                    func_80800290_gztrace(*(u8 **) sp, 4, &B_80800ABA_gztrace);
                    func_80800290_gztrace(*(u8 **) (sp + 4), 4, &B_80800AC3_gztrace);
                    break;
                case 1:
                    func_80800068_gztrace(&B_80800AA8_gztrace, " SP: ********    PC: ");
                    func_80800290_gztrace(sp, 4, &B_80800ABD_gztrace);
            }
            if (func_addr != 0) {
                func_80800290_gztrace((u8 *) shown_func, 4, &B_80800ACD_gztrace);
            } else {
                func_80800068_gztrace(&B_80800ACD_gztrace, " (*f)() ");
            }
            func_80800068_gztrace(&B_80800AD5_gztrace, "-********");
            func_80800290_gztrace((u8 *) shown_pc, 4, &B_80800AD6_gztrace);
            // Terminate the line buffer.
            *(s8 *) ((u8 *) &B_80800AA8_gztrace + 0x36) = 0;
            if (quiet == 0) {
                func_8001D37C("%s\n", &B_80800AA8_gztrace);
            }
            i += 1;
        } while (i < 16 &&
                 func_808004B0_gztrace(&sp, &pc, &func_addr, &fallback_pc, ret_addr) != 0);
    }
}

void gztrace_entrypoint_0(void)
{
}

// Prints a stack trace of thread, skipping the first skip_frames frames.
void gztrace_entrypoint_1(OSThread *thread, s32 skip_frames, s32 platform, s32 quiet)
{
    s32 ret_addr;
    s32 pc;
    s32 sp;
    s32 func_addr;
    s32 fallback_pc;

    pc = thread->context.pc;
    sp = thread->context.sp;
    ret_addr = thread->context.ra;
    func_8001D37C("Stack trace: %s\n\nSP = %08X, PC = %08X, RA = %08X\n\n",
                  platform == 0 ? "Work-Station" : "N64", sp, pc, ret_addr);
    if (!func_80800000_gztrace(pc)) {
        pc = ret_addr;
        ret_addr = 0;
        if (!func_80800000_gztrace(pc)) {
            func_8001D37C("Unable to trace, invalid PC,RA!\n");
            return;
        }
    }
    while (skip_frames--) {
        func_808004B0_gztrace(&sp, &pc, &func_addr, &fallback_pc, ret_addr);
        ret_addr = 0;
    }
    func_808005C4_gztrace(pc, sp, ret_addr, platform, quiet);
}

// TU-NOTE: the .data of this overlay is defined here in C; the values come from the ROM.
u32 D_80800A30_gztrace[16] = {
    0x2D2D2D2D, 0x2D2D2D2D, 0x2D2D2D2D, 0x2D2D2D2D, 0x2D2D2D2D, 0x2D2D2D2D, 0x2D2D2D2D, 0x2D2D2D2D,
    0x2D2D2D2D, 0x2D2D2D2D, 0x2D2D2D2D, 0x2D2D2D2D, 0x2D2D2D2D, 0x2D2D2D2D, 0x2D2D2D2D, 0x2D000000};
