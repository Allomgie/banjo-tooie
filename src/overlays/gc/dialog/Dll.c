// Resets the global dialog state block: both speaker slots, the pending-dialog ring buffer,
// phase bitfields and callbacks, and sets defaults.
#include "common.h"

typedef struct {
    s16 unk_0;
    s16 unk_2;
    f32 unk_4[3];
    s32 unk_10;
    s16 unk_14;
    u8 pad_16[2];
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
    s32 unk_24;
    u8 pad_28[4];
} DialogInitRecord;
typedef struct {
    u8 available : 2;
    u8 busy : 2;
    u8 pad_0 : 4;
} DialogInitChannelFlags;
typedef struct {
    u32 state : 8;
    u32 field_15D : 8;
    u32 selected : 1;
    u32 opening : 1;
    u32 unk_15E_5 : 1;
    u32 pad_0 : 1;
    u32 unk_15E_3 : 1;
    u32 pad_1 : 3;
    u8 completed : 2;
    u8 count : 2;
    u8 unk_15F_2 : 2;
    u8 unk_15F_0 : 2;
} DialogInitFlags;
typedef struct {
    s16 confirmed : 8;
    u16 unk_161_4 : 4;
    u16 unk_161_0 : 4;
} DialogInitMode;
typedef struct {
    u8 pad_0[0x100];
    s32 asset;
    s32 commands[2];
    s32 text[2];
    u8 count[2];
    u8 index[2];
    s16 command[2];
    DialogInitChannelFlags box_flags[2];
    u8 pad_11E[2];
    s32 box[2];
    u8 pad_128[0x30];
    s8 field_158;
    u8 unk_159;
    u16 flags;
    DialogInitFlags status;
    DialogInitMode unk_160;
    s16 text_id;
    s16 unk_164;
    u8 unk_166;
    u8 pad_167;
    s32 caller;
    u8 pad_16C[4];
    s32 unk_170;
    s32 unk_174;
    s32 unk_178;
    u8 pad_17C[4];
    u8 unk_180;
    u8 pad_181[3];
    DialogInitRecord pending[4];
} DialogInitState;
extern void func_800EFD24(f32 *);

// Resets the global dialog state block (called via core2/1E99980).
void gcdialogDll_entrypoint_0(DialogInitState *dialog)
{
    s32 i;

    dialog->asset = 0;
    // Both speaker slots.
    for (i = 0; i < 2; i++) {
        dialog->commands[i] = 0;
        dialog->count[i] = 0;
        dialog->box[i] = 0;
        dialog->index[i] = 0;
        dialog->command[i] = -1;
        dialog->text[i] = 0;
        dialog->box_flags[i].available = 0;
        dialog->box_flags[i].busy = 0;
    }
    // Pending-dialog ring buffer.
    for (i = 0; i < 4; i++) {
        dialog->pending[i].unk_0 = -1;
        dialog->pending[i].unk_2 = 0;
        dialog->pending[i].unk_10 = 0;
        dialog->pending[i].unk_14 = 0;
        dialog->pending[i].unk_18 = 0;
        dialog->pending[i].unk_1C = 0;
        dialog->pending[i].unk_20 = 0;
        dialog->pending[i].unk_24 = 0;
        func_800EFD24(dialog->pending[i].unk_4);
    }
    dialog->status.state = 0;
    dialog->flags = dialog->status.unk_15E_5 = 0;
    dialog->status.completed = dialog->status.count = dialog->status.unk_15F_2 =
        dialog->status.unk_15F_0 = 0;
    dialog->status.field_15D = dialog->status.selected = 0;
    dialog->status.opening = 1;
    dialog->unk_160.confirmed = -1;
    dialog->unk_160.unk_161_4 = dialog->unk_160.unk_161_0 = 0;
    dialog->text_id = -1;
    dialog->unk_164 = -1;
    dialog->caller = 0;
    dialog->unk_170 = 0;
    dialog->unk_174 = 0;
    dialog->unk_178 = 0;
    dialog->unk_166 = 0xC;
    dialog->unk_159 = 0;
    dialog->field_158 = -1;
    dialog->status.unk_15E_3 = 1;
    dialog->unk_180 = 1;
}
