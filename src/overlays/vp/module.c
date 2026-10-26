#include "common.h"

typedef struct { u8 pad_0[0x20]; s16 local_0; s16 local_1; u8 pad_1[8]; s32 local_2; s32 local_3[1]; } VpInput62;
typedef struct { s32 local_0; s32 local_1; } VpOutput62;
typedef struct { u8 local_0; u8 local_1; u16 local_2; void *local_3; } VpEntry62;
typedef struct { void *(*local_0)(VpInput62 *, void *); s32 local_1[4]; } VpCallback62;
typedef struct { u8 type; u8 pad_0[3]; void *payload; } ViewModuleEntry;
typedef struct { u8 pad_0[8]; ViewModuleEntry entries[1]; } ViewModuleEntries;
typedef struct { u8 pad_0[0x2C]; s32 count; } ViewModuleHeader;
typedef struct { void *pad_0[2]; void (*destroy)(void *); void *pad_1[2]; } ViewModuleType;
typedef struct { u8 type; u8 enabled; u8 pad_0[2]; void *payload; } ViewModuleUpdateEntry;
typedef struct { u8 pad_0[8]; ViewModuleUpdateEntry entries[1]; } ViewModuleUpdateList;
typedef struct { void *pad_0; void (*update)(void *, ViewModuleHeader *); void *pad_1[3]; } ViewModuleUpdateType;
typedef struct { u8 type; u8 enabled; s16 idx; void *payload; } VMEntry;
typedef struct { s32 unk0; s32 unk4; VMEntry entries[1]; } VMList;
typedef struct { u8 pad0[0x14]; s32 count14; u8 pad18[4]; s32 unk1C; u8 pad20[0xC]; s32 count; } VMHeader;
typedef struct { s16 unk0; u8 unk2; u8 unk3; u8 unk4[6]; u8 unkA[10]; } VMTrack;
typedef struct { u16 off; u16 cnt; } VMSub;
typedef struct { void *pad0[3]; void (*apply)(void *, s32, void *, s32); void *pad10; } VMType_vpmodule_entrypoint_3;
extern VMType_vpmodule_entrypoint_3 D_808008C0_vpmodule[];
extern s32 func_800E3DC0(void *, void *);
extern void aligned8_memcpy(void *, void *, s32);
typedef struct { void *pad0[4]; void (*init)(void *, s32); } VMType_808005C4_vpmodule;
typedef struct { u8 local_0; u8 local_1; s16 local_2; u32 local_3; } ModuleEntry1279;
void func_808005C4_vpmodule();

int func_80800000_vpmodule(s32 param_0)
{
  if (param_0 == 0)
  {
    return 0;
  }
  if (((param_0 >= 0x4B0) && (param_0 < 0x6A4)) || ((param_0 >= 0x834) && (param_0 < 0x898)))
  {
    return 1;
  }
  if ((param_0 >= 0xC8) && (param_0 < 0x12C))
  {
    return 2;
  }
  if ((param_0 >= 0x1F4) && (param_0 < 0x258))
  {
    return 3;
  }
  if ((param_0 >= 0x64) && (param_0 < 0xC8))
  {
    return 4;
  }
  return -1;
}

VpOutput62 *vpmodule_entrypoint_0(VpInput62 *param_0, s32 param_1, s32 param_2)
{
    VpOutput62 *local_0;
    VpEntry62 *local_1;
    u8 *local_2;
    u8 *local_3;
    s32 local_4;
    s32 local_5;
    s32 local_6;
    s32 local_7;

    local_6 = param_0->local_2;
    if (local_6 == 0) return NULL;
    local_5 = local_6 * 8 + 8;
    while (local_5 & 0xF) local_5++;
    local_5 += param_0->local_0 * 16 + param_0->local_1 * 16;
    local_0 = heap_alloc(local_5);
    local_1 = (VpEntry62 *)(local_0 + 1);
    for (local_4 = 0; local_4 < local_6; local_4++, local_1++) {
        local_2 = (u8 *)param_0 + param_0->local_3[local_4];
        local_7 = func_80800000_vpmodule(*(s32 *)local_2);
        local_1->local_0 = local_7;
        local_1->local_1 = 1;
        local_1->local_2 = local_4;
        local_1->local_3 = ((VpCallback62 *) D_808008C0_vpmodule)[local_7].local_0(param_0, local_2);
    }
    local_3 = (u8 *)local_1;
    while ((u32)local_3 & 0xF) local_3++;
    local_0->local_0 = local_3 - (u8 *)local_0;
    _dbvpl_entrypoint_1(param_0, local_3, param_1, param_2);
    local_0->local_1 = local_0->local_0 + param_0->local_0 * 16;
    func_808005C4_vpmodule(local_0, param_0, param_1);
    return local_0;
}

void vpmodule_entrypoint_1(ViewModuleEntries *param_0, ViewModuleHeader *param_1)
{
    ViewModuleEntry *local_0;
    ViewModuleEntry *local_1;
    local_0 = param_0->entries;
    local_1 = local_0 + param_1->count;
    for (; local_0 < local_1; local_0++) {
        ((ViewModuleType *) D_808008C0_vpmodule)[local_0->type].destroy(local_0->payload);
    }
    heap_free(param_0);
}

void vpmodule_entrypoint_2(ViewModuleUpdateList *param_0, ViewModuleHeader *param_1)
{
    ViewModuleUpdateEntry *local_0;
    ViewModuleUpdateEntry *local_1;
    local_1 = (ViewModuleUpdateEntry *)((param_1->count * sizeof(ViewModuleUpdateEntry)) + (u8 *)param_0 + 8);
    for (local_0 = param_0->entries; local_0 < local_1; local_0++) {
        if (local_0->enabled) ((ViewModuleUpdateType *) D_808008C0_vpmodule)[local_0->type].update(local_0->payload, param_1);
    }
}

void vpmodule_entrypoint_3(VMList *mod, VMHeader *hdr, u8 *out)
{
    s32 pad;
    VMEntry *lim;
    VMTrack *start;
    VMTrack *t;
    VMTrack *end;
    VMEntry *e;
    u8 *buf;
    u8 *bend;
    u8 *data;
    VMSub *sub;
    u8 *k;
    u8 *kend;
    u8 *p;
    s32 n;

    start = (VMTrack *)((u8 *)hdr + hdr->unk1C);
    end = start + hdr->count14;
    lim = (VMEntry *)((hdr->count * sizeof(VMEntry)) + (u8 *)mod + 8);
    for (t = start; t < end; t++) {
        if (!t->unk3) {
            continue;
        }
        if (!func_800E3DC0(t->unk4, t->unkA)) {
            continue;
        }
        buf = (u8 *)mod + mod->unk4;
        aligned8_memcpy(buf, (u8 *)mod + mod->unk0 + t->unk0 * 16, t->unk2 * 16);
        n = t - start;
        for (e = mod->entries; e < lim; e++) {
            data = (u8 *)hdr + *((s32 *)((u8 *)hdr + 0x30) + e->idx);
            sub = (VMSub *)(data + 0x14) + n;
            if (sub->cnt == 0) {
                continue;
            }
            k = (u8 *)((s32 *)data + hdr->count14) + sub->off + 0x14;
            kend = k + sub->cnt;
            for (; k < kend; k += 2) {
                D_808008C0_vpmodule[e->type].apply(e->payload, n, buf + k[1] * 16, k[0]);
            }
        }
        p = out + 0x18;
        bend = buf + t->unk2 * 16;
        for (; buf < bend; buf += 16) {
            aligned8_memcpy(p + (*(u16 *)(buf + 6) & 0x7FFF) * 16, buf, 16);
        }
        t->unk3 = 0;
    }
}

void func_808005C4_vpmodule(mod, hdr, out) VMList *mod; VMHeader *hdr; u8 *out;
{
    s32 pad;
    VMEntry *lim;
    VMTrack *start;
    VMTrack *t;
    VMTrack *end;
    VMEntry *e;
    u8 *buf;
    u8 *bend;
    u8 *data;
    VMSub *sub;
    u8 *k;
    u8 *kend;
    u8 *p;
    s32 n;
    s32 v;

    start = (VMTrack *)((u8 *)hdr + hdr->unk1C);
    end = start + hdr->count14;
    lim = (VMEntry *)((hdr->count * sizeof(VMEntry)) + (u8 *)mod + 8);
    for (t = start; t < end; t++) {
        buf = (u8 *)mod + mod->unk4;
        aligned8_memcpy(buf, (u8 *)mod + mod->unk0 + t->unk0 * 16, t->unk2 * 16);
        for (e = mod->entries; e < lim; e++) {
            if (((VMType_808005C4_vpmodule *) D_808008C0_vpmodule)[e->type].init == NULL) {
                continue;
            }
            data = (u8 *)hdr + *((s32 *)((u8 *)hdr + 0x30) + e->idx);
            n = t - start;
            sub = (VMSub *)(data + 0x14) + n;
            if (sub->cnt == 0) {
                continue;
            }
            k = (u8 *)((s32 *)data + hdr->count14) + sub->off + 0x14;
            kend = k + sub->cnt;
            for (; k < kend; k++) {
                v = k[1];
                ((VMType_808005C4_vpmodule *) D_808008C0_vpmodule)[e->type].init(buf + v * 16, *k++);
            }
        }
        aligned8_memcpy((u8 *)mod + mod->unk0 + t->unk0 * 16, buf, t->unk2 * 16);
        p = out + 0x18;
        bend = buf + t->unk2 * 16;
        for (; buf < bend; buf += 16) {
            aligned8_memcpy(p + (*(u16 *)(buf + 6) & 0x7FFF) * 16, buf, 16);
        }
    }
}

s32 vpmodule_entrypoint_4(u8 *param_0, u8 *param_1, s32 param_2, int param_3)
{
    ModuleEntry1279 *local_0;
    ModuleEntry1279 *local_1;
    s32 *local_2;

    local_0 = (ModuleEntry1279 *)(param_0 + 8);
    local_1 = local_0 + *(s32 *)(param_1 + 0x2C);
    while (local_0 < local_1) {
        local_2 = (s32 *)(param_1 + *((s32 *)(param_1 + 0x30) + local_0->local_2));
        if (*local_2 == param_2) {
            local_0->local_1 = param_3;
            return 1;
        }
        local_0++;
    }
    return 0;
}
