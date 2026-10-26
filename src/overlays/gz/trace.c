#include "common.h"

typedef struct { s16 blocks[4]; s16 words, shorts, pointers; u8 extra_size; u8 pad_0[0x1D]; s16 type; u8 pad_1[6]; } TraceHeader1459;
typedef struct { s32 type; TraceHeader1459 *header; u8 *words; s32 word_count; u8 *shorts, *pointers, *prefix, *extra; u8 *blocks[4]; u8 *end; } TraceState1459;
extern TraceState1459 B_80800A70_gztrace;
extern s32 B_80800AA8_gztrace;
extern s32 B_80800ABA_gztrace;
extern s32 B_80800ABD_gztrace;
extern s32 B_80800AC3_gztrace;
extern s32 B_80800ACD_gztrace;
extern s32 B_80800AD5_gztrace;
extern s32 B_80800AD6_gztrace;
extern s32 overlay_syscalls;
extern s32 overlay_syscalls_end;
extern s32 func_8001D37C();

s32 func_80800000_gztrace(u32 param_0) {
    if ((param_0 < 0x80000000U) || (param_0 >= 0x80800001U) || (param_0 & 3)) {
        return 0;
    }
    return 1;
}

int func_80800038_gztrace(u8 *param_0, u8 *param_1)
{
  u8 *local_0 = param_0;
  while ((*param_0++ = *param_1++) != '\0');
}

void func_80800068_gztrace(char *param_0, char *param_1) {
    char *local_0 = param_0;
    while (*local_0++) {
    }
    local_0--;
    while (*local_0++ = *param_1++) {
    }
}

s32 func_808000B8_gztrace(void *arg)
{
  u8 *v0;
  u32 v1;
  v1 = 0;
  v0 = (u8 *) arg;
  if (*v0)
  {
    do
    {
      v1++;
      v0++;
    }
    while (*v0);
  }
  return v1;
}

void func_808000E8_gztrace(u8 *param_0, u8 *param_1, s32 param_2, u8 param_3, s32 param_4)
{
    s32 local_2;
    s32 local_3;
    s32 local_0;
    s32 local_1;

    local_0 = func_808000B8_gztrace(param_1);
    local_1 = param_2 + param_4 + 1;
    if (local_1 >= local_0) {
        func_80800038_gztrace(param_0, param_1);
        for (local_2 = local_0; local_2 < local_1; local_2++) {
            param_0[local_2] = ' ';
        }
    } else {
        for (local_2 = 0; local_2 < param_2; local_2++) {
            param_0[local_2] = param_1[local_2];
        }
        param_0[local_2++] = param_3;
        for (local_3 = local_0 - param_4; local_2 < local_1; local_2++) {
            param_0[local_2] = param_1[local_3++];
        }
    }
    param_0[local_1] = 0;
}

u8 *func_80800290_gztrace(u32 param_0, s32 param_1, u8 *param_2)
{
    s32 local_0;
    u8 *local_1 = param_2;
    u8 *local_2 = (u8 *)&param_0;

    for (local_0 = 4 - param_1; local_0 < 4; local_0++) {
        *local_1 = (local_2[local_0] >> 4) + 0x30;
        if (*local_1 >= 0x3A) {
            *local_1 += 0x27;
        }
        local_1++;
        *local_1 = (local_2[local_0] & 0xF) + 0x30;
        if (*local_1 >= 0x3A) {
            *local_1 += 0x27;
        }
        local_1++;
    }
    return local_1;
}

void func_808003D0_gztrace(TraceHeader1459 *param_0)
{
  int new_var;
  B_80800A70_gztrace.type = param_0->type;
  B_80800A70_gztrace.word_count = param_0->words;
  B_80800A70_gztrace.header = param_0;
  B_80800A70_gztrace.prefix = ((u8 *) param_0) + 0x34;
  B_80800A70_gztrace.words = ((u8 *) param_0) + 0x38;
  B_80800A70_gztrace.extra = (((u8 *) param_0) + 0x38) + (param_0->words * 4);
  B_80800A70_gztrace.shorts = (u8 *) (((((u32) B_80800A70_gztrace.extra) + param_0->extra_size) + 3) & (~3U));
  B_80800A70_gztrace.pointers = B_80800A70_gztrace.shorts + (param_0->shorts * 2);
  B_80800A70_gztrace.pointers += 3;
  B_80800A70_gztrace.pointers = (u8 *) (((u32) B_80800A70_gztrace.pointers) & (~3U));
  new_var = 0;
  B_80800A70_gztrace.blocks[new_var] = B_80800A70_gztrace.pointers + (param_0->pointers * 4);
  B_80800A70_gztrace.blocks[0] += 15;
  B_80800A70_gztrace.blocks[0] = (u8 *) (((u32) B_80800A70_gztrace.blocks[0]) & (~15U));
  if ((param_0 && param_0) != 0)
  {
  }
  B_80800A70_gztrace.blocks[1] = B_80800A70_gztrace.blocks[0] + (param_0->blocks[0] * 16);
  B_80800A70_gztrace.blocks[2] = B_80800A70_gztrace.blocks[1] + (param_0->blocks[1] * 16);
  B_80800A70_gztrace.blocks[3] = B_80800A70_gztrace.blocks[2] + (param_0->blocks[2] * 16);
  B_80800A70_gztrace.end = B_80800A70_gztrace.blocks[3] + (param_0->blocks[3] * 16);
}

s32 func_808004B0_gztrace(u32 **param_0, u32 **param_1, u32 *param_2, u32 **param_3, u32 *param_4)
{
    u32 *pc;
    u32 *sp;
    u32 insn;
    s32 done;

    sp = *param_0;
    pc = *param_1;
    done = 0;
    *param_3 = *param_1 - 2;
    do {
        insn = *pc++;
        switch (insn >> 16) {
        case 0x8FBF:
            param_4 = *(u32 **)((u8 *)sp + (s16)insn);
            break;
        case 0x27BD:
            sp += (s16)insn >> 2;
            break;
        case 0x3E0:
            done = 1;
            break;
        }
    } while (!done);
    insn = *pc;
    if ((insn >> 16) == 0x27BD) {
        sp += (s16)insn >> 2;
    }
    *param_1 = param_4;
    *param_0 = sp;
    if (param_4 != NULL) {
        insn = param_4[-2];
        switch (insn >> 26) {
        case 3:
            *param_2 = ((insn + 0xF4000000) << 2) + 0x80000000;
            return 1;
        case 0:
            if ((insn & 0x3F) == 9) {
                *param_2 = 0;
                return 1;
            }
            break;
        default:
            return 0;
        }
    }
    return 0;
}

void func_808005C4_gztrace(s32 param_0, u8 *param_1, s32 param_2, s32 param_3, s32 param_4)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    s32 local_5;
    s32 i;

    i = 0;
    if (func_808004B0_gztrace(&param_1, &param_0, &local_0, &local_1, param_2) != 0) {
        do {
            local_4 = local_0;
            local_5 = local_1;
            if (local_0 != 0) {
                local_3 = local_0;
            } else {
                local_3 = local_1;
            }
            local_2 = func_80081AA4(local_3);
            if (local_2 != 0) {
                func_808003D0_gztrace(local_2);
                func_808000E8_gztrace(&B_80800AA8_gztrace, *(s32 *)((u8 *)((s32 *) &B_80800A70_gztrace) + 0x1C), 0xD, 0x7E, 2);
                if (param_3 == 0) {
                    if (local_4 != 0 && (local_4 < (s32)&overlay_syscalls || (s32)&overlay_syscalls_end < local_4)) {
                        local_4 -= *(s32 *)((u8 *)((s32 *) &B_80800A70_gztrace) + 0x20);
                    }
                    local_5 -= *(s32 *)((u8 *)((s32 *) &B_80800A70_gztrace) + 0x20);
                }
            } else {
                func_808000E8_gztrace(&B_80800AA8_gztrace, "core", 0xD, 0x7E, 2);
            }
            switch (param_3) {
            case 0:
                func_80800068_gztrace(&B_80800AA8_gztrace, " (********,********) ");
                func_80800290_gztrace(*(u8 **)param_1, 4, &B_80800ABA_gztrace);
                func_80800290_gztrace(*(u8 **)(param_1 + 4), 4, &B_80800AC3_gztrace);
                break;
            case 1:
                func_80800068_gztrace(&B_80800AA8_gztrace, " SP: ********    PC: ");
                func_80800290_gztrace(param_1, 4, &B_80800ABD_gztrace);
                break;
            }
            if (local_0 != 0) {
                func_80800290_gztrace((u8 *)local_4, 4, &B_80800ACD_gztrace);
            } else {
                func_80800068_gztrace(&B_80800ACD_gztrace, " (*f)() ");
            }
            func_80800068_gztrace(&B_80800AD5_gztrace, "-********");
            func_80800290_gztrace((u8 *)local_5, 4, &B_80800AD6_gztrace);
            *(s8 *)((u8 *)&B_80800AA8_gztrace + 0x36) = 0;
            if (param_4 == 0) {
                func_8001D37C("%s\n", &B_80800AA8_gztrace);
            }
            i += 1;
        } while (i < 16 && func_808004B0_gztrace(&param_1, &param_0, &local_0, &local_1, param_2) != 0);
    }
}

void gztrace_entrypoint_0(void) {
}

void gztrace_entrypoint_1(OSThread *param_0, s32 param_1, s32 param_2, s32 param_3)
{
    s32 local_4;
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;

    local_0 = param_0->context.pc;
    local_1 = param_0->context.sp;
    local_4 = param_0->context.ra;
    func_8001D37C("Stack trace: %s\n\nSP = %08X, PC = %08X, RA = %08X\n\n",
        param_2 == 0 ? "Work-Station" : "N64", local_1, local_0, local_4);
    if (!func_80800000_gztrace(local_0)) {
        local_0 = local_4;
        local_4 = 0;
        if (!func_80800000_gztrace(local_0)) {
            func_8001D37C("Unable to trace, invalid PC,RA!\n");
            return;
        }
    }
    while (param_1--) {
        func_808004B0_gztrace(&local_1, &local_0, &local_2, &local_3, local_4);
        local_4 = 0;
    }
    func_808005C4_gztrace(local_0, local_1, local_4, param_2, param_3);
}
