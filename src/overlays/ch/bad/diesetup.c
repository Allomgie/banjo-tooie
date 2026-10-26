#include "common.h"

#define BADDIE_SETUP_QUEUE_DEFINED
typedef struct { s32 unk0; s32 unk4; u8 pad8[0x14]; s32 unk1C; } BaddieSetupRecord;
typedef struct { BaddieSetupRecord *unk0; u8 unk4; } BaddieSetupQueue;
extern BaddieSetupQueue *func_800A5D60(void);
typedef struct { s32 local_0[5]; u8 pad_0[8]; s32 local_1; } BaddieSetupEntry;
typedef struct { BaddieSetupEntry *local_0; u8 local_1; } BaddieSetupList;
typedef struct { s32 local_0[7]; s32 local_1; } BaddieSetupEntry27;
typedef struct { BaddieSetupEntry27 *local_0; u8 local_1; } BaddieSetupList27;
typedef struct { s32 a; f32 x, y, z; } ArgS;
extern void _chbounce_entrypoint_6(s32, f32 *);
extern void _chbounce_entrypoint_2(f32);

int func_80800000_chbaddiesetup(s32 param_0[3])
{
  if (!param_0[0])
  {
    return 0;
  }
  if (((unsigned char *) param_0)[4] == 0x16)
  {
    return 0;
  }
  return 1;
}

void chbaddiesetup_entrypoint_0(s32 param_0)
{
    BaddieSetupQueue *local_0;

    local_0 = func_800A5D60();
    if (func_80800000_chbaddiesetup(local_0)) {
        local_0->unk0[local_0->unk4].unk0 = param_0;
        local_0->unk0[local_0->unk4].unk1C = 0;
        local_0->unk4++;
    }
}

void chbaddiesetup_entrypoint_1(s32 param_0, s32 param_1)
{
    BaddieSetupQueue *local_0;

    local_0 = func_800A5D60();
    if (func_80800000_chbaddiesetup(local_0)) {
        local_0->unk0[local_0->unk4].unk0 = param_0;
        local_0->unk0[local_0->unk4].unk4 = param_1;
        local_0->unk0[local_0->unk4].unk1C = 1;
        local_0->unk4++;
    }
}

void chbaddiesetup_entrypoint_2(s32 param_0, s32 param_1, s32 param_2) {
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_800A5D60();
    sp1C = temp_v0;
    if (func_80800000_chbaddiesetup(temp_v0) != 0) {
        *(s32 *)((u8 *)(*(s32 **)(sp1C)) + ((*(u8 *)(sp1C + 4)) << 5)) = param_0;
        *(s32 *)((u8 *)(*(s32 **)(sp1C)) + ((*(u8 *)(sp1C + 4)) << 5) + 4) = param_1;
        *(s32 *)((u8 *)(*(s32 **)(sp1C)) + ((*(u8 *)(sp1C + 4)) << 5) + 8) = param_2;
        *(s32 *)((u8 *)(*(s32 **)(sp1C)) + ((*(u8 *)(sp1C + 4)) << 5) + 0x1C) = 2;
        *(u8 *)(sp1C + 4) = *(u8 *)(sp1C + 4) + 1;
    }
}

void chbaddiesetup_entrypoint_3(s32 param_0, s32 param_1, s32 param_2, s32 param_3) {
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_800A5D60();
    sp1C = temp_v0;
    if (func_80800000_chbaddiesetup(temp_v0) != 0) {
        *(s32 *)(*(s32 *)(sp1C) + (sp1C[4] << 5)) = param_0;
        *(s32 *)(*(s32 *)(sp1C) + (sp1C[4] << 5) + 4) = param_1;
        *(s32 *)(*(s32 *)(sp1C) + (sp1C[4] << 5) + 8) = param_2;
        *(s32 *)(*(s32 *)(sp1C) + (sp1C[4] << 5) + 0xC) = param_3;
        *(s32 *)(*(s32 *)(sp1C) + (sp1C[4] << 5) + 0x1C) = 3;
        sp1C[4] = (u8)(sp1C[4] + 1);
    }
}

void chbaddiesetup_entrypoint_4(s32 param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4)
{
    BaddieSetupList *local_0;
    local_0 = (BaddieSetupList *)func_800A5D60();
    if (func_80800000_chbaddiesetup((BaddieSetupQueue *)local_0)) {
        local_0->local_0[local_0->local_1].local_0[0] = param_0;
        local_0->local_0[local_0->local_1].local_0[1] = param_1;
        local_0->local_0[local_0->local_1].local_0[2] = param_2;
        local_0->local_0[local_0->local_1].local_0[3] = param_3;
        local_0->local_0[local_0->local_1].local_0[4] = param_4;
        local_0->local_0[local_0->local_1].local_1 = 4;
        local_0->local_1++;
    }
}

void chbaddiesetup_entrypoint_5(s32 param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5)
{
  u8 *local_0;
  local_0 = func_800A5D60();
  if (func_80800000_chbaddiesetup(local_0) != 0)
  {
    *(s32 *)((s8 *)(*(s32 **)(local_0)) + (local_0[4] << 5)) = param_0;
    *(s32 *)((s8 *)(*(s32 **)(local_0)) + (local_0[4] << 5) + 4) = param_1;
    *(s32 *)((s8 *)(*(s32 **)(local_0)) + (local_0[4] << 5) + 8) = param_2;
    *(s32 *)((s8 *)(*(s32 **)(local_0)) + (local_0[4] << 5) + 0xC) = param_3;
    *(s32 *)((s8 *)(*(s32 **)(local_0)) + (local_0[4] << 5) + 0x10) = param_4;
    *(s32 *)((s8 *)(*(s32 **)(local_0)) + (local_0[4] << 5) + 0x14) = param_5;
    *(s32 *)((s8 *)(*(s32 **)(local_0)) + (local_0[4] << 5) + 0x1C) = 5;
    local_0[4] = local_0[4] + 1;
  }
}

void chbaddiesetup_entrypoint_6(s32 param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6)
{
    BaddieSetupList27 *local_0;

    local_0 = (BaddieSetupList27 *)func_800A5D60();
    if (func_80800000_chbaddiesetup((BaddieSetupQueue *)local_0)) {
        local_0->local_0[local_0->local_1].local_0[0] = param_0;
        local_0->local_0[local_0->local_1].local_0[1] = param_1;
        local_0->local_0[local_0->local_1].local_0[2] = param_2;
        local_0->local_0[local_0->local_1].local_0[3] = param_3;
        local_0->local_0[local_0->local_1].local_0[4] = param_4;
        local_0->local_0[local_0->local_1].local_0[5] = param_5;
        local_0->local_0[local_0->local_1].local_0[6] = param_6;
        local_0->local_0[local_0->local_1].local_1 = 6;
        local_0->local_1++;
    }
}

void chbaddiesetup_entrypoint_7(ArgS param_0) {
    f32 local_0[3];
    local_0[0] = param_0.x;
    local_0[1] = param_0.y;
    local_0[2] = param_0.z;
    func_80108474(param_0.a, local_0, 0);
}

void chbaddiesetup_entrypoint_8(s32 param_0, s32 param_1, s32 param_2, s32 param_3) {
    s32 local_0[3];
    local_0[0] = (&param_0)[1];
    local_0[1] = (&param_0)[2];
    local_0[2] = (&param_0)[3];
    func_80108454(param_0, local_0, 0);
}

void chbaddiesetup_entrypoint_9(ArgS param_0) {
    f32 local_0[3];
    local_0[0] = param_0.x;
    local_0[1] = param_0.y;
    local_0[2] = param_0.z;
    _chbounce_entrypoint_6(param_0.a, local_0);
}

void chbaddiesetup_entrypoint_10(ArgS param_0, f32 param_1) {
    f32 local_0[3];
    local_0[0] = param_0.x;
    local_0[1] = param_0.y;
    local_0[2] = param_0.z;
    _chbounce_entrypoint_2(param_1);
    _chbounce_entrypoint_6(param_0.a, local_0);
}
