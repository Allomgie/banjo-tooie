#include "common.h"

extern s32 _cadbmgrDll_entrypoint_0(void *, s32);
// Camera node database block (D_80119540 points to it).
struct struct_80119540 {
    char pad_0[0x30];
    s32 cur_node;  // current node, -1 = none
    s32 node_data; // resolved data pointer of the current node
};
void func_8001B754();
extern u32 D_8011951C[];
typedef struct {
    u8 pad_0[0x30];
    u32 cur_node;
    u8 pad_34[8];
    u8 nodes[1]; // (kind, sub-index) byte pairs
} Struct800A587C;

extern s32 D_80119540;

// Spline camera callbacks: look up the per-player camera instance.
s32 func_800A5550(s32 param_0, s32 param_1)
{
    s32 player_idx;
    s32 camera;
    player_idx = (s32) ((u32) *(u16 *) ((char *) param_1 + 0x1A) >> 5);
    camera = func_800A93E4(player_idx);
    camera = func_80110014(camera);
    _ncbaspline_entrypoint_5(camera, param_0, param_1);
}

s32 func_800A5598(s32 param_0, u16 *param_1)
{
    s32 player_idx;
    s32 camera;
    player_idx = (s32) ((u32) *(u16 *) ((char *) param_1 + 0x1A) >> 5);
    camera = func_800A93E4(player_idx);
    camera = func_80110014(camera);
    _ncbaspline_entrypoint_6(camera, param_0, param_1);
}

void func_800A55E0(void)
{
    _cadbmgrDll_entrypoint_0((u8 *) &D_80119540, 0x7D);
}

int func_800A5608(s32 param_0)
{
    s32 value;
    // Matching: the no-op `| 0` is needed for the match.
    value = param_0 | 0;
    return _cadbmgrDll_entrypoint_0(&D_80119540, value);
}

void func_800A5630()
{
    _cadbmgrDll_entrypoint_1(&D_80119540);
}

void func_800A5654()
{
    if ((u8 *) D_80119540 != 0) {
        (u8 *) D_80119540 = (s32) defrag((void *) (u8 *) D_80119540);
        ((struct struct_80119540 *) (u8 *) D_80119540)->cur_node = -1;
        ((struct struct_80119540 *) (u8 *) D_80119540)->node_data = 0;
    }
}

// Free all loaded node-data assets and reset the node table.
void func_800A56A4(void)
{
    s32 slot;
    s32 asset_off;
    s32 node_off;
    s32 node_idx;
    s16 asset_id;
    if ((u8 *) D_80119540 != 0) {
        slot = 1;
        asset_off = 2;
        do {
            asset_id = *(s16 *) (((u8 *) D_80119540 + asset_off) + 0x1E);
            if (asset_id != 0) {
                // Matching: do/while (0) wrapper is needed for the match.
                do {
                    func_8001B754(asset_id, (u8 *) D_80119540);
                } while (0);
                *(s16 *) (((u8 *) D_80119540 + asset_off) + 0x1E) = 0;
                *(s32 *) (((u8 *) D_80119540 + (slot * 4)) - 4) = 0;
            }
            slot++;
            asset_off += 2;
        } while (slot != 9);
        node_idx = 0;
        node_off = 0;
        if (*(s32 *) ((u8 *) D_80119540 + 0x38) >= 0) {
            do {
                *(u8 *) (((u8 *) D_80119540 + node_off) + 0x3C) = 0;
                node_idx++;
                *(u8 *) (((u8 *) D_80119540 + node_off) + 0x3D) = 0xFF;
                node_off += 2;
            } while (*(s32 *) ((u8 *) D_80119540 + 0x38) >= node_idx);
        }
        *(s32 *) ((u8 *) D_80119540 + 0x30) = -1;
        *(s32 *) ((u8 *) D_80119540 + 0x34) = 0;
    }
}

// Data pointer = asset base of the kind + index * per-kind stride.
s32 func_800A5790(s32 kind, s32 index)
{
    s32 data;
    data = (index * D_8011951C[kind]) +
           func_8001B798(*(s16 *) ((s8 *) (s32 *) D_80119540 + kind * 2 + 0x1E));
    return data;
}

// Per-kind stride.
int func_800A57EC(s32 kind)
{
    return ((s32 *) D_8011951C)[kind];
}

// Make `node` current and resolve its data pointer.
s32 func_800A5800(s32 node)
{
    unsigned int entry_off;
    u8 *entry;
    entry_off = node * 2;
    *(s32 *) (0x30 + (s8 *) (u8 *) D_80119540) = node;
    entry = (u8 *) D_80119540 + entry_off;
    *(s32 *) ((s8 *) (u8 *) D_80119540 + 0x34) =
        func_800A5790(*(u8 *) ((s8 *) entry + 0x3C), *(u8 *) ((s8 *) entry + 0x3D));
    return *(s32 *) ((s8 *) (u8 *) D_80119540 + 0x34);
}

// Kind of `node`.
u8 func_800A5854(node)
s32 node;
{
    int entry_off;
    entry_off = (node * 2) + 0x3c;
    return ((u8 *) D_80119540)[entry_off];
}

int func_800A586C()
{
    return ((s32 *) D_80119540)[0x34 / 4];
}

u8 func_800A587C()
{
    return ((Struct800A587C *) D_80119540)->nodes[((Struct800A587C *) D_80119540)->cur_node * 2];
}

int func_800A5898()
{
    return ((s32 *) D_80119540)[0x30 / 4];
}

// Change the kind of `node` unless it is unchanged or 0.
void func_800A58A8(s32 node, s32 kind)
{
    int db;
    u8 *entry;
    db = D_80119540;
    entry = (u8 *) (db + (node * 2));
    if ((kind != entry[0x3C]) && (kind != 0)) {
        _cadbmgrDll_entrypoint_2(db, kind, node);
    }
}

s32 func_800A58F0(void)
{
    return *(s32 *) ((s8 *) (s8 *) D_80119540 + 0x38) + 1;
}

s32 func_800A5904()
{
    s32 kind = func_800A5854();
    return (kind != 0);
}

// TU-NOTE: the .data of this file is defined here in C; values are taken from the ROM.
u32 D_80119510[3] = {0x3FCCCCCD, 0x3F800000, 0x3FA66666};
u32 D_8011951C[9] = {0x3FA66666, 0x2C, 0x18, 0x34, 0x18, 0x2C, 0x34, 0x4, 0x30};
s32 D_80119540 = 0x0;
