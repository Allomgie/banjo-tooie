// Dialog executor: runs a conversation from a dialog asset as a script of lines and commands,
// drives up to two zoombox portraits, input, choices, sounds and the dialog camera, then cleans up.
#include "common.h"

#define DIALOG_UPDATE_CMD(i) (param_0->commands[param_0->status.half.selected] + i)
extern void _gczoombox_entrypoint_0();
extern void _gldialog_entrypoint_5(s32);
extern void heap_free(void *);
typedef struct {
    u8 local_0 : 2;
    u8 pad_0 : 6;
} DialogExecFlags_80800164_gcdialogexec;
typedef struct {
    u8 pad_0[0x11C];
    DialogExecFlags_80800164_gcdialogexec local_0[2];
    u8 pad_1[0x3C];
    s16 local_1;
    u8 pad_2[1];
    u8 local_2;
    u8 pad_3[4];
    s16 local_3;
    u8 pad_4[3];
    u8 local_4;
    void *local_5;
    u8 pad_5[4];
    void *local_6;
    void *local_7;
    void *local_8;
} DialogExecResetState;
extern s32 func_800A9C98(void);
extern s32 func_800F6438(u32);
extern void func_800F82D4(s32, s32);
typedef struct {
    u8 pad_0[0x15A];
    u16 local_0;
    u32 pad_1 : 20;
    u32 local_1 : 1;
    u32 pad_2 : 11;
    s8 local_2;
    u8 pad_3;
    s16 local_3;
    s16 local_4;
    u8 pad_4[2];
    Unk80132ED0 *local_5;
    s32 local_6;
    void (*local_7)(Unk80132ED0 *, s32, s32);
    u8 pad_5[8];
    s32 local_8;
} DialogExec27;
typedef struct {
    u8 pad0[0x11C];
    u8 unk11C;
    u8 unk11D;
    u8 pad11E[0x3E];
    u32 state : 8;
    u32 total : 8;
    u32 pad15E : 8;
    u32 a : 2;
    u32 b : 2;
    u32 c : 2;
    u32 d : 2;
} DialogExecBits;
typedef struct {
    u8 available : 2;
    u8 pad_0 : 6;
} DialogExecTextFlags;
typedef struct {
    u8 pad_0[0x11C];
    DialogExecTextFlags text[2];
    u8 pad_1[0x3E];
    u8 state;
    u8 pad_2;
    u16 selected : 1;
    u16 pad_3 : 15;
} DialogExecEvent;
typedef struct {
    s16 unk0;
    s16 pad2;
    u8 *unk4;
} DialogLine;
typedef struct {
    u8 pad0[0x100];
    u8 *unk100;
    DialogLine *unk104[2];
    u8 pad10C[8];
    u8 unk114[2];
    u8 pad116[0x51];
    u8 unk167;
} DialogExec;
extern u8 *_gldialog_entrypoint_4(s32);
extern void *heap_alloc(s32);
typedef struct {
    s16 code;
    s16 pad2;
    u8 *str;
} DlgEntry_80801268_gcdialogexec;
typedef struct {
    u8 f6 : 2;
    u8 f4 : 2;
    u8 f0 : 4;
} DlgFlag_80801268_gcdialogexec;
typedef struct {
    u8 pad0[0x12];
    u16 unk12_1 : 15;
    u16 unk12_0 : 1;
} DlgObj_80801268_gcdialogexec;
typedef struct DlgExec_80801268_gcdialogexec {
    u8 pad0[0x104];
    DlgEntry_80801268_gcdialogexec *unk104[2];
    u8 *unk10C[2];
    u8 unk114[2];
    u8 unk116[2];
    s16 cur[2];
    DlgFlag_80801268_gcdialogexec unk11C[2];
    u8 pad11E[2];
    s32 unk120[2];
    s16 unk128[2];
    u8 pad12C[0x2E];
    u16 unk15A;
    u32 state : 8;
    u32 total : 8;
    u32 idx : 1;
    u32 flag6 : 1;
    u32 pad15E_4 : 2;
    u32 f11 : 1;
    u32 busy : 1;
    u32 cnt : 2;
    u8 a : 2;
    u8 b : 2;
    u8 c : 2;
    u8 d : 2;
    s8 unk160;
    u8 pad161;
    s16 unk162;
    u8 pad164[3];
    u8 unk167;
    DlgObj_80801268_gcdialogexec *unk168;
    s32 unk16C;
    s32 unk170;
    s32 unk174;
    s32 unk178;
} DlgExec_80801268_gcdialogexec;
extern void func_800C01D8();
extern void _gczoombox_entrypoint_24(s32, s32);
extern void _gczoombox_entrypoint_25(s32, s32);
extern void _gczoombox_entrypoint_35(s32, DlgObj_80801268_gcdialogexec *, s32, s32);
extern void _gczoombox_entrypoint_10(s32);
typedef struct {
    s16 local_0;
    s16 local_1;
    Vec3f local_2;
    Unk80132ED0 *local_3;
    s16 local_4;
    u8 pad_0[2];
    s32 local_5;
    void *local_6;
    void *local_7;
    void *local_8;
    s32 local_9;
} DialogExecPending;
typedef struct {
    u8 pad_0[0x11A];
    s16 local_0;
    u8 pad_1[0x3E];
    u16 local_1;
    u32 pad_2 : 20;
    u32 local_2 : 1;
    u32 pad_3 : 11;
    u16 pad_4 : 8;
    u16 local_3 : 4;
    u16 local_4 : 4;
    u8 pad_5[0x1A];
    s32 local_5;
    u8 pad_6[4];
    DialogExecPending local_6[4];
} DialogExecQueue;
extern s32 func_800C0638(void);
extern s32 func_800F54E4(void);
extern void func_800F8300(s32, s32, f32 *);
extern void func_800FEC60(s32);
extern void func_800C0658(void);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EFD24(f32 *);
extern s32 func_800F5B0C(s32);
typedef struct {
    s16 unk0;
    u16 unk2;
    f32 unk4[3];
    s32 unk10;
    s16 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
} DialogQueueEntry;
typedef struct {
    u8 pad0[0x11A];
    s16 unk11A;
    u8 pad11C[0x40];
    u32 pad15C_12 : 20;
    u32 unk15C_11 : 1;
    u32 pad15C_0 : 11;
    u8 unk160;
    u8 count : 4;
    u8 read : 4;
    u8 pad162[0xA];
    s32 unk16C;
    u8 pad170[0xC];
    s32 unk17C;
    u8 pad180[4];
    DialogQueueEntry queue[4];
} DialogExecQueueState;
extern s32 func_800EEEA8(f32 *);
typedef struct DialogCnt {
    u32 pad : 30;
    u32 cnt : 2;
} DialogCnt;
typedef struct DialogExecFlags_gcdialogexec_entrypoint_2 {
    u8 local_0 : 2;
    u8 pad_0 : 6;
} DialogExecFlags_gcdialogexec_entrypoint_2;
typedef struct DialogCounterBits {
    u8 pad_0 : 6;
    u8 local_0 : 2;
} DialogCounterBits;
typedef struct DialogNibbleFlags {
    u8 local_0 : 4;
    u8 local_1 : 4;
} DialogNibbleFlags;
typedef struct {
    s16 code;
    s16 pad2;
    u8 *str;
} DlgEntry_80801DB4_gcdialogexec;
typedef struct {
    u8 f6 : 2;
    u8 f4 : 2;
    u8 f0 : 4;
} DlgFlag_80801DB4_gcdialogexec;
typedef struct {
    u8 pad0[0x12];
    u16 unk12_1 : 15;
    u16 unk12_0 : 1;
} DlgObj_80801DB4_gcdialogexec;
typedef struct DlgExec_80801DB4_gcdialogexec {
    u8 pad0[0x104];
    DlgEntry_80801DB4_gcdialogexec *unk104[2];
    u8 *unk10C[2];
    u8 unk114[2];
    u8 unk116[2];
    s16 cur[2];
    DlgFlag_80801DB4_gcdialogexec unk11C[2];
    u8 pad11E[2];
    s32 unk120[2];
    s16 unk128[2];
    u8 pad12C[0x2E];
    u16 unk15A;
    u32 state : 8;
    u32 total : 8;
    u32 idx : 1;
    u32 flag6 : 1;
    u32 pad15E_4 : 2;
    u32 f11 : 1;
    u32 busy : 1;
    u32 cnt : 2;
    u32 a : 2;
    u32 b : 2;
    u32 c : 2;
    u32 d : 2;
    s8 unk160;
    u8 pad161;
    s16 unk162;
    u8 pad164[3];
    u8 unk167;
    DlgObj_80801DB4_gcdialogexec *unk168;
    s32 unk16C;
    s32 unk170;
    s32 unk174;
    s32 unk178;
} DlgExec_80801DB4_gcdialogexec;
typedef s32 (*DlgCb)(DlgObj_80801DB4_gcdialogexec *, s16, u8);
typedef struct {
    s32 unk0;
    s32 unk4;
} DlgEntry_80802020_gcdialogexec;
typedef struct {
    u8 pad0[0x18];
    u16 unk18;
} DlgObj_80802020_gcdialogexec;
typedef struct DlgExec_80802020_gcdialogexec {
    u8 pad0[0x104];
    DlgEntry_80802020_gcdialogexec *unk104[2];
    u8 pad10C[0xA];
    u8 unk116[2];
    u8 pad118[0x46];
    u16 idx : 1;
    u16 pad15E_1 : 5;
    u16 cnt : 2;
    u16 pad15F : 8;
    u8 pad160[2];
    s16 unk162;
    u8 pad164[4];
    DlgObj_80802020_gcdialogexec *unk168;
    s32 unk16C;
    u8 pad170[8];
    s32 (*unk178)(DlgObj_80802020_gcdialogexec *, s16, s32);
} DlgExec_80802020_gcdialogexec;
extern s32 _gldialog_entrypoint_1(s32);
extern void func_800E6DD8();
extern s32 _subaddiedialog_entrypoint_14();
extern u8 D_80802EA0_gcdialogexec[];
extern void func_800C0890();
extern void *_gldbstring_entrypoint_0(s32, s32);
extern void *_gldbstring_entrypoint_1();
extern void *_gczoombox_entrypoint_5(s32, s32, s32, s32, void *);
extern void _gczoombox_entrypoint_26(void *, s32, f32, f32, s32);
extern void _gczoombox_entrypoint_20(void *, f32, s32, s32, f32, s32, s32);
typedef struct {
    s16 code;
    s16 pad2;
    s32 unk4;
} DlgEntry_8080064C_gcdialogexec;
typedef struct {
    u8 f6 : 2;
    u8 f4 : 2;
    u8 f0 : 4;
} DlgFlag_8080064C_gcdialogexec;
typedef struct DlgExec_8080064C_gcdialogexec {
    u8 pad0[0x104];
    DlgEntry_8080064C_gcdialogexec *unk104[2];
    u8 *unk10C[2];
    u8 pad114[2];
    u8 unk116[2];
    s16 cur[2];
    DlgFlag_8080064C_gcdialogexec unk11C[2];
    u8 pad11E[2];
    s32 unk120[2];
    u8 pad128[0x30];
    u8 unk158;
    u8 pad159[5];
    u16 idx : 1;
    u16 flag6 : 1;
    u16 pad15E_2 : 14;
} DlgExec_8080064C_gcdialogexec;
extern s32 _gczoombox_entrypoint_39();
typedef struct {
    u8 unk0_6 : 2;
    u8 pad0_0 : 6;
} DlgFlag_80800A50_gcdialogexec;
typedef struct DlgExec_80800A50_gcdialogexec {
    u8 pad0[0x11C];
    DlgFlag_80800A50_gcdialogexec unk11C[2];
    u8 pad11E[2];
    s32 unk120[2];
    u8 pad128[4];
    s32 unk12C;
    u8 pad130[0x28];
    s8 unk158;
    u8 pad159;
    u16 unk15A;
    u32 state : 8;
    u32 pad15D : 8;
    u32 idx : 1;
    u32 pad15E_1 : 4;
    u32 busy : 1;
    u32 cnt : 2;
    u32 pad15F : 6;
    u32 sel : 2;
} DlgExec_80800A50_gcdialogexec;
extern void _gczoombox_entrypoint_9(s32);
extern s32 _gczoombox_entrypoint_33(s32);
extern void _gcdialogcamera_entrypoint_10(DlgExec_80800A50_gcdialogexec *, s32, s32);
typedef struct {
    u8 pad_0[0x120];
    void *local_0[2];
} DialogZoomBoxes;
typedef struct {
    s16 command;
    u16 pad_0;
    u8 *text;
} DialogUpdateCommand;
typedef struct {
    u8 available : 2;
    u8 busy : 2;
    u8 pad_0 : 4;
} DialogUpdateBoxFlags;
typedef struct {
    u8 output[0x100];
    void *asset;
    DialogUpdateCommand *commands[2];
    u8 *text[2];
    u8 count[2];
    u8 index[2];
    s16 command[2];
    DialogUpdateBoxFlags box_flags[2];
    u8 pad_1[2];
    void *box[2];
    u8 pad_2[0x30];
    u8 field_158;
    u8 pad_3;
    u16 flags;
    union {
        struct {
            u8 state;
            u8 field_15D;
            u16 selected : 1;
            u16 opening : 1;
            u16 pad_0 : 6;
            u16 completed : 2;
            u16 count : 2;
            u16 pad_1 : 4;
        } half;
        struct {
            u32 pad_0 : 17;
            u32 opening : 1;
            u32 pad_1 : 8;
            u32 count : 2;
            u32 pad_2 : 4;
        } word;
        struct {
            u8 pad_0[3];
            u8 completed : 2;
            u8 pad_1 : 6;
        } byte;
    } status;
    s8 confirmed;
    u8 pad_4;
    s16 text_id;
    u8 pad_5[3];
    u8 field_167;
    void *caller;
    s32 caller_id;
} DialogUpdateState;
extern s32 _gczoombox_entrypoint_37(void *, s16);
extern void _gczoombox_entrypoint_12(s32);

// Returns 1 if obj's id equals id; -1 never matches.
int func_80800000_gcdialogexec(u16 *obj, u32 id)
{
    s32 ret;
    if (id == -1) {
        ret = 0;
    } else {
        ret = (id == ((u32) *(u16 *) (obj + 9) >> 1));
    }
    return ret;
}

void func_8080002C_gcdialogexec(u8 *dialog)
{
    s32 extra_box;
    s32 i;
    u8 *cursor;

    cursor = dialog;
    i = 0;
    do {
        _gczoombox_entrypoint_0(*(s32 *) ((s8 *) cursor + 0x120));
        i += 1;
        cursor += 4;
        *(s32 *) ((s8 *) cursor + 0x11C) = 0;
    } while (i != 2);
    extra_box = *(s32 *) ((s8 *) dialog + 0x12C);
    if (extra_box != 0) {
        _gczoombox_entrypoint_0(extra_box);
        *(s32 *) ((s8 *) dialog + 0x12C) = 0;
    }
}

// Frees the line tables and releases the dialog asset.
short func_808000A0_gcdialogexec(void *dialog)
{
    void *counts;
    void *tables;
    s32 i;
    s32 j;
    s32 offset;
    counts = dialog;
    tables = dialog;
    i = 0;
    do {
        j = 0;
        offset = 0;
        if ((s32) *(u8 *) ((char *) counts + 0x114) > 0) {
            do {
                j += 1;
                *(s32 *) ((char *) *(s32 **) ((char *) tables + 0x104) + offset + 4) = 0;
                offset += 8;
            } while (j < (s32) *(u8 *) ((char *) counts + 0x114));
        }
        *(u8 *) ((char *) counts + 0x114) = 0;
        heap_free(*(void **) ((char *) tables + 0x104));
        i += 1;
        counts = (void *) ((char *) counts + 1);
        tables = (void *) ((char *) tables + 4);
        *(s32 *) ((char *) tables + 0x100) = 0;
    } while (i != 2);
    if (*(s16 *) ((char *) dialog + 0x162) != -1) {
        _gldialog_entrypoint_5(*(s16 *) ((char *) dialog + 0x162));
    }
    *(s32 *) ((char *) dialog + 0x100) = 0;
}

// Matching: K&R-style definition, needed for the match.
// Resets the dialog state after freeing its lines.
void func_80800164_gcdialogexec(dialog) DialogExecResetState *dialog;
{
    func_808000A0_gcdialogexec(dialog);
    if (!dialog->local_0[0].local_0 && !dialog->local_0[1].local_0) {
        func_8080002C_gcdialogexec(dialog);
    }
    dialog->local_3 = -1;
    dialog->local_1 = dialog->local_2 = 0;
    dialog->local_5 = NULL;
    dialog->local_4 = 0;
    dialog->local_6 = NULL;
    dialog->local_7 = NULL;
    dialog->local_8 = NULL;
}

// Ends the dialog: notifies the callback and the player, then resets.
void func_808001DC_gcdialogexec(DialogExec27 *dialog)
{
    dialog->local_4 = dialog->local_3;
    if (dialog->local_7) {
        if (dialog->local_5 == NULL) {
            dialog->local_7(dialog->local_5, dialog->local_3, dialog->local_2);
        } else if (func_80800000_gcdialogexec(dialog->local_5, dialog->local_6)) {
            dialog->local_7(dialog->local_5, dialog->local_3, dialog->local_2);
        }
    }
    if (dialog->local_5 && func_80800000_gcdialogexec(dialog->local_5, dialog->local_6) &&
        (*(u16 *) ((u8 *) dialog->local_5 + 0x18) & 1)) {
        _subaddiedialog_entrypoint_12(dialog->local_5, dialog->local_3, dialog->local_2);
    }
    if (dialog->local_0 & 8) {
        if (!func_800A9C98() || !dialog->local_1) {
            if (func_800F6438(dialog->local_8)) {
                func_800F82D4(dialog->local_8, 0);
            }
        }
    }
    func_800FECB8(0);
    func_80800164_gcdialogexec(dialog);
}

s32 func_808002E4_gcdialogexec(u8 *text)
{
    s32 use_alt;
    s32 count = 0;
    u8 *cursor;

    use_alt = _gldialog_entrypoint_1(text);
    for (cursor = text; *cursor != 0; cursor++) {
        if (*cursor == (use_alt ? 0xAE : 0x7E)) {
            count++;
            // Matching: empty block, needed for the match.
            if (text) {
            }
        }
    }
    return count;
}

// Copies src to out, replacing each marker character with the next string from replacements.
void func_80800350_gcdialogexec(u8 *out, u8 *src, u8 *replacements, s32 use_alt, s32 add_codes)
{
    s32 out_pos;
    s32 i;
    s32 repl_pos;

    repl_pos = 0;
    out_pos = 0;
    for (i = 0; src[i] != '\0'; i++) {
        if (src[i] == (use_alt ? 0xAE : '~')) {
            if (add_codes) {
                out[out_pos++] = 0xFD;
                out[out_pos++] = 0x68;
            }

            for (; replacements[repl_pos] != '\0'; repl_pos++) {
                out[out_pos++] = replacements[repl_pos];
                if (add_codes && !use_alt && replacements[repl_pos] == ' ') {
                    out[out_pos++] = 0xFD;
                    out[out_pos++] = 0x68;
                }
            }
            repl_pos++;

            if (add_codes) {
                out[out_pos++] = 0xFD;
                out[out_pos++] = 0x6C;
            }
        } else {
            out[out_pos++] = src[i];
        }
    }

    out[out_pos] = '\0';
}

void func_80800478_gcdialogexec(u8 *dialog, s32 value)
{
    s32 (*callback)(u8 *, s16, s32);
    u8 *caller;
    u8 *caller_2;
    u8 *caller_3;

    callback = *(s32(**)(u8 *, s16, s32))((s8 *) dialog + 0x174);
    if (callback != NULL) {
        caller = *(u8 **) ((s8 *) dialog + 0x168);
        if (caller == NULL) {
            callback(caller, *(s16 *) ((s8 *) dialog + 0x162), value);
        } else if (func_80800000_gcdialogexec(caller, *(s32 *) ((s8 *) dialog + 0x16C)) != 0) {
            (*(s32(**)(u8 *, s16, s32))((s8 *) dialog + 0x174))(
                *(u8 **) ((s8 *) dialog + 0x168), *(s16 *) ((s8 *) dialog + 0x162), value);
        }
    }
    caller_2 = *(u8 **) ((s8 *) dialog + 0x168);
    if ((caller_2 != NULL) &&
        (func_80800000_gcdialogexec(caller_2, *(s32 *) ((s8 *) dialog + 0x16C)) != 0)) {
        caller_3 = *(u8 **) ((s8 *) dialog + 0x168);
        if (*(u16 *) ((s8 *) caller_3 + 0x18) & 1) {
            _subaddiedialog_entrypoint_13(caller_3, *(s16 *) ((s8 *) dialog + 0x162), value);
        }
    }
}

void func_8080052C_gcdialogexec(u8 *dialog)
{
    f32 scale;
    if (*(s8 *) (dialog + 0x158) >= 0) {
        func_800E715C(dialog + 0x130, _gldbstring_entrypoint_1(_gldbstring_entrypoint_0(0, 0x1865),
                                                                *(s8 *) (dialog + 0x158)));
        _gldbstring_entrypoint_2(0x1865);
        *(void **) (dialog + 0x12C) = _gczoombox_entrypoint_5(0x72, 0x44, 2, 0, func_800C0890);
        scale = ((f32 *) D_80802EA0_gcdialogexec)[*(s8 *) (dialog + 0x158)];
        _gczoombox_entrypoint_26(*(void **) (dialog + 0x12C),
                                 (s32) ((304.0f - scale * 216.0f) * 0.5f), 1.0f, scale, 0);
        _gczoombox_entrypoint_20(*(void **) (dialog + 0x12C), 100.0f, 0, 2, 0.1f, 0, 0);
        _gczoombox_entrypoint_8(*(void **) (dialog + 0x12C), dialog + 0x130);
        _gczoombox_entrypoint_9(*(void **) (dialog + 0x12C));
        _gczoombox_entrypoint_11(*(void **) (dialog + 0x12C));
    }
}

// Runs one script command of the current box; returns 0 when this step is done.
s32 func_8080064C_gcdialogexec(DlgExec_8080064C_gcdialogexec *dialog)
{
    s32 scan;

    dialog->cur[dialog->idx] =
        ((DlgEntry_8080064C_gcdialogexec *) ((s32) dialog->unk104[dialog->idx] +
                                             dialog->unk116[dialog->idx] * 8))
            ->code;
    dialog->unk10C[dialog->idx] =
        (u8 *) ((DlgEntry_8080064C_gcdialogexec *) ((s32) dialog->unk104[dialog->idx] +
                                                    dialog->unk116[dialog->idx] * 8))
            ->unk4;
    switch (dialog->cur[dialog->idx]) {
        case -8:
            func_80800478_gcdialogexec(dialog, *dialog->unk10C[dialog->idx]);
            dialog->unk116[dialog->idx]++;
            return 1;
        case -9:
            dialog->unk116[dialog->idx]++;
            return *dialog->unk10C[dialog->idx] + 1;
        case -2:
            dialog->unk158 = *dialog->unk10C[dialog->idx];
            dialog->unk116[dialog->idx]++;
            return 1;
        case -1:
            return 1;
    }
    if (dialog->unk120[dialog->idx] == 0 ||
        _gczoombox_entrypoint_39(dialog->unk120[dialog->idx]) ||
        dialog->unk11C[dialog->idx].f4 != 0) {
        dialog->idx ^= 1;
        return 0;
    }
    switch (dialog->cur[dialog->idx]) {
        case -11:
        case -10:
            do {
                dialog->unk116[dialog->idx]++;
                dialog->cur[dialog->idx] =
                    ((DlgEntry_8080064C_gcdialogexec *) ((s32) dialog->unk104[dialog->idx] +
                                                         dialog->unk116[dialog->idx] * 8))
                        ->code;
            } while (dialog->cur[dialog->idx] == -10 || dialog->cur[dialog->idx] == -11);
            return 1;
        case -4:
            dialog->unk11C[dialog->idx].f6 = 1;
            dialog->unk11C[dialog->idx].f4 = 1;
            dialog->flag6 = 1;
            dialog->idx ^= 1;
            return 0;
        case -5:
            dialog->unk11C[dialog->idx].f6 = 0;
            dialog->unk11C[dialog->idx].f4 = 1;
            dialog->flag6 = 1;
            dialog->idx ^= 1;
            return 0;
        case -7:
            for (scan = dialog->unk116[dialog->idx];
                 dialog->unk104[dialog->idx][scan].code < -5; scan++) {
            }
            dialog->unk11C[dialog->idx].f6 = 0;
            dialog->unk116[dialog->idx]++;
            dialog->idx ^= 1;
            return 1;
        case -6:
            dialog->unk11C[dialog->idx].f6 = 0;
            dialog->unk116[dialog->idx]++;
            dialog->idx ^= 1;
            dialog->flag6 = 1;
            return 1;
        default:
            dialog->unk116[dialog->idx]++;
            return 1;
    }
}

// Matching: K&R-style definition, needed for the match.
void func_80800A50_gcdialogexec(dialog, new_state) DlgExec_80800A50_gcdialogexec *dialog;
u32 new_state;
{
    s32 i;
    s32 camera_arg;
    s32 result;
    s32 result_2;

    if (dialog->state == 6) {
        if (new_state == 6) {
            return;
        }
    }
    switch (new_state) {
        case 1:
            for (i = 0; i < 2; i++) {
                if (dialog->unk120[i] != 0) {
                    if (dialog->unk11C[i].unk0_6 == 0) {
                        _gczoombox_entrypoint_9(dialog->unk120[i]);
                    }
                    dialog->unk11C[i].unk0_6 = 0;
                }
            }
            dialog->unk158 = -1;
            break;
        case 5:
            for (i = 0; i < 2; i++) {
                if (dialog->unk120[i] != 0 && dialog->unk11C[i].unk0_6 == 0) {
                    _gczoombox_entrypoint_12(dialog->unk120[i]);
                    _gczoombox_entrypoint_10(dialog->unk120[i]);
                }
            }
            if (dialog->unk12C != 0) {
                _gczoombox_entrypoint_12(dialog->unk12C);
                _gczoombox_entrypoint_10(dialog->unk12C);
            }
            break;
        case 6:
            dialog->busy = 1;
            camera_arg = -1;
            while ((result = func_8080064C_gcdialogexec(dialog)) != 0) {
                if (result >= 2) {
                    camera_arg = result - 1;
                }
            }
            while ((result_2 = func_8080064C_gcdialogexec(dialog)) != 0) {
                if (result_2 >= 2) {
                    camera_arg = result_2 - 1;
                }
            }
            if (camera_arg != -1 && !(dialog->unk15A & 0x200)) {
                _gcdialogcamera_entrypoint_10(dialog, camera_arg, 0);
            }
            dialog->sel = 0;
            for (i = 0; i < 2; i++) {
                dialog->unk11C[i].unk0_6 = 0;
                if (dialog->unk120[i] != 0) {
                    result = _gczoombox_entrypoint_33(dialog->unk120[i]);
                    dialog->sel = dialog->sel + result;
                }
            }
            dialog->busy = 0;
            break;
        case 7:
            func_808001DC_gcdialogexec(dialog);
            new_state = 0;
            break;
        case 8:
            for (i = 0; i < 2; i++) {
                if (dialog->unk11C[i].unk0_6 == 0) {
                    _gczoombox_entrypoint_0(dialog->unk120[i]);
                    dialog->unk120[i] = 0;
                }
            }
            func_808001DC_gcdialogexec(dialog);
            break;
        case 10:
            if (dialog->unk12C != 0) {
                _gczoombox_entrypoint_12(dialog->unk12C);
                _gczoombox_entrypoint_10(dialog->unk12C);
            }
            break;
        case 11:
            func_8080052C_gcdialogexec(dialog);
    }
    dialog->state = new_state;
}

// Matching: K&R-style definition, needed for the match.
void func_80800D30_gcdialogexec(dialog, arg1, msg) DialogExecBits *dialog;
{
    s32 avail_0;
    s32 avail_1;

    switch (msg) {
        case 1:
            dialog->a++;
            break;
        case 3:
            func_80800A50_gcdialogexec(dialog, 2);
            break;
        case 4:
            if (dialog->state == 6) {
                dialog->d--;
                if (dialog->d == 0) {
                    avail_0 = ((u32) dialog->unk11C >> 6) ? 1 : 0;
                    avail_1 = ((u32) dialog->unk11D >> 6) ? 1 : 0;
                    func_80800A50_gcdialogexec(dialog, (avail_1 + avail_0) ? 8 : 5);
                }
            } else {
                if ((s32) dialog->b <
                    (((u32) dialog->unk11C >> 6) ? 1 : 0) + (((u32) dialog->unk11D >> 6) ? 1 : 0)) {
                    dialog->b++;
                    if (dialog->b + dialog->c == dialog->total) {
                        func_80800A50_gcdialogexec(dialog, 8);
                    }
                }
            }
            break;
        case 6:
            dialog->c++;
            if (dialog->c == dialog->total) {
                func_80800A50_gcdialogexec(dialog, 7);
            }
            if (dialog->b + dialog->c == dialog->total) {
                func_80800A50_gcdialogexec(dialog, 8);
            }
    }
}

// Matching: K&R-style definition, needed for the match.
void func_80800F60_gcdialogexec(dialog, param_1, msg) DialogExecEvent *dialog;
{
    s32 next_state;
    switch (msg) {
        case 3:
            if (dialog->state == 11)
                func_80800A50_gcdialogexec(dialog, 4);
        case 1:
        case 4:
            break;
        case 6:
            if (dialog->state == 10) {
                next_state = dialog->text[dialog->selected].available ? 8 : 2;
                func_80800A50_gcdialogexec(dialog, next_state);
            }
    }
}

s32 func_80801008_gcdialogexec(s32 box_index)
{
    return box_index ? 0x1C : 0xC8;
}

s32 func_80801020_gcdialogexec(s32 box_index)
{
    return box_index ? 1 : 0;
}

// Parses the dialog asset into per-box line tables.
void func_80801038_gcdialogexec(DialogExec *dialog, s32 text_id)
{
    s32 i;
    s32 j;
    u8 *data;
    s32 code;
    char raw;
    s32 len;

    data = dialog->unk100 = _gldialog_entrypoint_4(text_id);
    for (i = 0; i < 2; i++) {
        dialog->unk114[i] = *data++;
        dialog->unk104[i] = heap_alloc(dialog->unk114[i] * sizeof(DialogLine));
        for (j = 0; j < dialog->unk114[i]; j++) {
            code = raw = *data++;
            if (raw > 0 && raw < 0x20) {
                code = -raw;
                if (raw == 3) {
                    code = *data++ + 0x75;
                }
            } else {
                code = (raw >= 0x80) ? raw - 0x80 : raw;
            }
            if (code == 0x51 || code == 0x79) {
                code = dialog->unk167 - 0xC;
            }
            dialog->unk104[i][j].unk0 = code;
            len = *data;
            data++;
            dialog->unk104[i][j].unk4 = data;
            data += len;
        }
    }
}

// Matching: K&R-style definition, needed for the match.
void func_808011A4_gcdialogexec(dialog, param_1, param_2, param_3, param_4,
                                param_5) DialogZoomBoxes *dialog;
s32 param_1;
s32 param_2;
s32 param_3;
s32 param_4;
s32 param_5;
{
    s32 i;

    for (i = 0; i < 2; i++) {
        if (dialog->local_0[i]) {
            _gczoombox_entrypoint_20(dialog->local_0[i], (f32) param_3, param_1, param_2,
                                     0.4f, param_4, param_5);
        }
    }
}

// Starts a dialog: loads the lines, creates the zoom boxes, sets the initial state.
void func_80801268_gcdialogexec(DlgExec_80801268_gcdialogexec *dialog, s32 text_id, s32 flags,
                                DlgObj_80801268_gcdialogexec *caller, s32 param_4, s32 event_callback,
                                s32 value_callback, s16 param_7)
{
    s32 i;
    s32 j;
    s32 first_code;

    dialog->unk167 = param_7;
    func_80801038_gcdialogexec(dialog, text_id);
    dialog->unk168 = caller;
    dialog->b = 0;
    // Matching: chained assignment, needed for the match.
    dialog->total = dialog->c = dialog->a = dialog->d = dialog->b;
    dialog->unk170 = param_4;
    dialog->unk174 = event_callback;
    dialog->unk178 = value_callback;
    dialog->unk16C = (caller != NULL) ? (caller->unk12_1 ? caller->unk12_1 : -1) : -1;
    dialog->cnt = 0;
    for (i = 0; i < 2; i++) {
        j = 0;
        first_code = dialog->unk104[i][0].code;
        while (dialog->unk104[i][j].code < -5 && j < dialog->unk114[i]) {
            j++;
        }
        dialog->cur[i] = first_code;
        dialog->unk10C[i] = dialog->unk104[i]->str;
        dialog->unk116[i] = 0;
        dialog->unk128[i] = func_80801008_gcdialogexec(i);
        dialog->unk11C[i].f4 = 0;
        if (dialog->unk104[i][j].code >= 0) {
            if (!dialog->unk11C[i].f6) {
                if (dialog->unk104[i][j].code + 0xC != 0x29 &&
                    dialog->unk104[i][j].code + 0xC != 0x84) {
                    dialog->unk120[i] = _gczoombox_entrypoint_5(
                        dialog->unk128[i], dialog->unk104[i][j].code + 0xC, 0,
                        func_80801020_gcdialogexec(i), func_800C01D8);
                } else {
                    dialog->unk120[i] = _gczoombox_entrypoint_5(
                        dialog->unk128[i], dialog->unk104[i][j].code + 0xC, 0,
                        1 - func_80801020_gcdialogexec(i), func_800C01D8);
                }
                if (flags & 0x100) {
                    _gczoombox_entrypoint_24(dialog->unk120[i], 0);
                }
                if (flags & 0x400) {
                    _gczoombox_entrypoint_25(dialog->unk120[i], 1);
                }
            } else {
                if (func_80800000_gcdialogexec(dialog->unk168, dialog->unk16C)) {
                    _gczoombox_entrypoint_35(dialog->unk120[i], dialog->unk168, dialog->unk167,
                                             dialog->unk16C);
                }
                dialog->a++;
            }
            dialog->total++;
        } else {
            if (dialog->unk104[i][j].code < -4) {
                if (dialog->unk11C[i].f6) {
                    _gczoombox_entrypoint_10(dialog->unk120[i]);
                    dialog->total++;
                } else {
                    dialog->unk120[i] = 0;
                }
                dialog->unk11C[i].f6 = 0;
            } else {
                if (dialog->unk11C[i].f6) {
                    dialog->total++;
                    dialog->a++;
                }
            }
        }
    }
    dialog->unk162 = text_id;
    dialog->unk15A = flags;
    if (dialog->cur[0] < 0) {
        dialog->idx = 0;
    } else {
        dialog->idx = 1;
    }
    dialog->flag6 = 1;
    dialog->unk160 = (func_800A9C98() && dialog->f11) ? 1 : -1;
    func_80800A50_gcdialogexec(dialog, (func_800A9C98() && dialog->f11) ? 6 : 1);
    func_808011A4_gcdialogexec(dialog, 5, 2, 15, flags & 2, flags & 0x80);
}

// Starts the dialog, or queues it when one is already running.
s32 gcdialogexec_entrypoint_0(DialogExecQueue *dialog, s32 text_id, s32 flags, f32 *pos,
                              Unk80132ED0 *caller, void *param_5, void *event_callback, void *value_callback,
                              s16 param_8)
{
    s32 slot;

    if (!func_800C0638()) {
        dialog->local_5 = func_800F54E4();
        func_80801268_gcdialogexec(dialog, text_id, flags, caller, param_5, event_callback, value_callback,
                                   param_8);
        if (flags & 8) {
            if (!func_800A9C98() || !dialog->local_2) {
                if (pos != NULL) {
                    func_800F8300(dialog->local_5, dialog->local_0 < 0 ? 1 : 3, pos);
                } else {
                    func_800F82D4(dialog->local_5, dialog->local_0 < 0 ? 1 : 3);
                }
            }
        }
        func_800FEC60(0);
        return 1;
    }
    if ((flags & 0x20)) {
        if (!(dialog->local_1 & 0x40)) {
            func_800C0658();
        } else {
            dialog->local_3 = 0;
            dialog->local_4 = 0;
        }
    }
    if ((flags & 4) || (flags & 0x20)) {
        slot = dialog->local_4 + dialog->local_3;
        if (slot >= 4) {
            slot -= 4;
        }
        dialog->local_6[slot].local_0 = text_id;
        dialog->local_6[slot].local_1 = flags;
        if (pos != NULL) {
            func_800EE7F8(dialog->local_6[slot].local_2.f, pos);
        } else {
            func_800EFD24(dialog->local_6[slot].local_2.f);
        }
        dialog->local_6[slot].local_3 = caller;
        dialog->local_6[slot].local_4 = param_8;
        dialog->local_6[slot].local_5 =
            (caller != NULL) ? (((u32) *(u16 *) ((u8 *) caller + 0x12) >> 1)
                                     ? ((u32) *(u16 *) ((u8 *) caller + 0x12) >> 1)
                                     : -1)
                              : -1;
        dialog->local_6[slot].local_6 = param_5;
        dialog->local_6[slot].local_7 = event_callback;
        dialog->local_6[slot].local_8 = value_callback;
        dialog->local_6[slot].local_9 = func_800F54E4();
        dialog->local_3++;
        if (flags & 8) {
            if (!func_800A9C98() || !dialog->local_2) {
                if (!func_800F5B0C(dialog->local_6[slot].local_9)) {
                    if (pos != NULL) {
                        func_800F8300(dialog->local_6[slot].local_9, 2, pos);
                    } else {
                        func_800F82D4(dialog->local_6[slot].local_9, 2);
                    }
                } else {
                    func_800F82D4(dialog->local_6[slot].local_9,
                                  func_800F5B0C(dialog->local_6[slot].local_9));
                }
            }
        }
        return 1;
    }
    return 0;
}

// Starts the next queued dialog.
void gcdialogexec_entrypoint_1(DialogExecQueueState *dialog)
{
    DialogQueueEntry *entry;

    entry = &dialog->queue[dialog->read];
    func_80801268_gcdialogexec(dialog, entry->unk0, entry->unk2, entry->unk10, entry->unk1C, entry->unk20, entry->unk24,
                               entry->unk14);
    dialog->unk16C = entry->unk18;
    dialog->unk17C = entry->unk28;
    func_800FEC60(0);
    if ((entry->unk2 & 8) && (!func_800A9C98() || !dialog->unk15C_11)) {
        if (func_800F6438(dialog->unk17C)) {
            func_800F82D4(dialog->unk17C, 0);
        }
        if (func_800EEEA8(entry->unk4)) {
            if (func_800F6438(dialog->unk17C)) {
                func_800F82D4(dialog->unk17C, (dialog->unk11A < 0) ? 1 : 3);
            }
        } else {
            if (func_800F6438(dialog->unk17C)) {
                func_800F8300(dialog->unk17C, (dialog->unk11A < 0) ? 1 : 3, entry->unk4);
            }
        }
    }
    dialog->read++;
    if (dialog->read >= 4) {
        dialog->read -= 4;
    }
    dialog->count--;
}

void gcdialogexec_entrypoint_2(u8 *dialog)
{
    s32 box;
    u8 *box_cursor;
    s32 offset;
    u8 *flag_cursor;

    ((DialogExecFlags_gcdialogexec_entrypoint_2 *) (dialog + 0x11C))->local_0 = 0;
    ((DialogExecFlags_gcdialogexec_entrypoint_2 *) (dialog + 0x11D))->local_0 = 0;
    if (func_800C0638()) {
        func_80800A50_gcdialogexec(dialog, 6);
    } else {
        flag_cursor = dialog;
        offset = 0;
        if (dialog[0x15C] != 6) {
            ((DialogCounterBits *) (dialog + 0x15F))->local_0 = 0;
            for (box_cursor = dialog; offset != 8; offset += 4, flag_cursor++, box_cursor += 4) {
                ((DialogExecFlags_gcdialogexec_entrypoint_2 *) (flag_cursor + 0x11C))->local_0 = 0;
                box = *(s32 *) (box_cursor + 0x120);
                if (box) {
                    box = _gczoombox_entrypoint_33(box);
                    ((DialogCounterBits *) (dialog + 0x15F))->local_0 =
                        ((DialogCnt *) (dialog + 0x15C))->cnt + box;
                }
            }
            if (*(s32 *) (dialog + 0x15C) & 3) {
                dialog[0x15C] = 6;
            }
        }
    }
    ((DialogNibbleFlags *) (dialog + 0x161))->local_0 = 0;
    ((DialogNibbleFlags *) (dialog + 0x161))->local_1 = 0;
}

s32 gcdialogexec_entrypoint_3(s32 dialog, s32 text_index, s32 param_2, s32 param_3, s32 param_4,
                              s32 value_callback)
{
    gcdialogexec_entrypoint_0(dialog, text_index + 0xE06, 0x44, 0, 0, 0, 0, value_callback, 0);
    func_808011A4_gcdialogexec(dialog, param_3, param_4, param_2, 0, 0);
    return 1;
}

void gcdialogexec_entrypoint_4(void *dialog, s32 param_1, s32 param_2, s32 param_3, s32 param_4,
                               s32 param_5)
{
    func_808011A4_gcdialogexec(dialog, param_1, param_2, param_3, param_4, param_5);
}

void gcdialogexec_entrypoint_5()
{
    func_80800D30_gcdialogexec();
}

void gcdialogexec_entrypoint_6()
{
    func_80800A50_gcdialogexec();
}

void gcdialogexec_entrypoint_7()
{
    func_80800164_gcdialogexec();
}

void gcdialogexec_entrypoint_8(s32 dialog)
{
    func_80800A50_gcdialogexec(dialog, 0x2);
}

void gcdialogexec_entrypoint_9()
{
    func_80800F60_gcdialogexec();
}

// Asks the callbacks for a choice and substitutes its text into the output buffer.
s32 func_80801DB4_gcdialogexec(DlgExec_80801DB4_gcdialogexec *dialog)
{
    s32 choice;
    s32 add_codes;
    s32 add_codes_2;
    s32 use_alt;
    s32 offset;

    choice = -1;
    if (dialog->unk178) {
        add_codes = 1;
        if (dialog->unk168 == NULL) {
            choice = ((DlgCb) dialog->unk178)(dialog->unk168, dialog->unk162,
                                                dialog->unk116[dialog->idx]);
        } else if (func_80800000_gcdialogexec(dialog->unk168, dialog->unk16C)) {
            choice = ((DlgCb) dialog->unk178)(dialog->unk168, dialog->unk162,
                                                dialog->unk116[dialog->idx]);
        }
        if (choice < 0) {
            choice = -1 - choice;
            add_codes = 0;
        }
        if (choice >= 0 &&
            (offset = choice * 8,
             *(s16 *) ((u8 *) (dialog->unk104[dialog->idx] + dialog->unk116[dialog->idx]) +
                       offset + 8) == -10)) {
            use_alt = _gldialog_entrypoint_1(
                (s32) (dialog->unk104[dialog->idx] + dialog->unk116[dialog->idx])->str);
            func_80800350_gcdialogexec(
                dialog, (s32) (dialog->unk104[dialog->idx] + dialog->unk116[dialog->idx])->str,
                *(s32 *) ((u8 *) (dialog->unk104[dialog->idx] + dialog->unk116[dialog->idx]) +
                          offset + 0xC),
                use_alt, add_codes);
        } else {
            choice = -1;
        }
    }
    if (dialog->unk168 && func_80800000_gcdialogexec(dialog->unk168, dialog->unk16C) &&
        (*(u16 *) ((u8 *) dialog->unk168 + 0x18) & 1)) {
        add_codes_2 = 1;
        choice = _subaddiedialog_entrypoint_14(dialog->unk168, dialog->unk162,
                                                dialog->unk116[dialog->idx]);
        if (choice < 0) {
            choice = -1 - choice;
            add_codes_2 = 0;
        }
        if (choice >= 0 &&
            (offset = choice * 8,
             *(s16 *) ((u8 *) (dialog->unk104[dialog->idx] + dialog->unk116[dialog->idx]) +
                       offset + 8) == -10)) {
            use_alt = _gldialog_entrypoint_1(
                (s32) (dialog->unk104[dialog->idx] + dialog->unk116[dialog->idx])->str);
            func_80800350_gcdialogexec(
                dialog, (s32) (dialog->unk104[dialog->idx] + dialog->unk116[dialog->idx])->str,
                *(s32 *) ((u8 *) (dialog->unk104[dialog->idx] + dialog->unk116[dialog->idx]) +
                          offset + 0xC),
                use_alt, add_codes_2);
        } else {
            choice = -1;
        }
    }
    return choice;
}

// Collects replacement strings from the callbacks and substitutes them into the output buffer.
s32 func_80802020_gcdialogexec(DlgExec_80802020_gcdialogexec *dialog)
{
    s32 marker_count;
    s32 use_alt;
    s32 i;
    char buf[16];
    s32 value;
    s32 buf_pos;
    s32 j;

    value = -1;
    marker_count = func_808002E4_gcdialogexec(
        ((DlgEntry_80802020_gcdialogexec *) ((s32) dialog->unk104[dialog->idx] +
                                             dialog->unk116[dialog->idx] * 8))
            ->unk4);
    use_alt = _gldialog_entrypoint_1(
        ((DlgEntry_80802020_gcdialogexec *) ((s32) dialog->unk104[dialog->idx] +
                                             dialog->unk116[dialog->idx] * 8))
            ->unk4);
    buf[0] = 0;
    if (dialog->unk178 != NULL) {
        buf_pos = 0;
        for (i = 0; i < marker_count; i++) {
            if (dialog->unk168 == NULL) {
                value = dialog->unk178(dialog->unk168, dialog->unk162, dialog->cnt++);
            } else if (func_80800000_gcdialogexec(dialog->unk168, dialog->unk16C)) {
                value = dialog->unk178(dialog->unk168, dialog->unk162, dialog->cnt++);
            }
            func_800E6DD8(buf + buf_pos, value, 0, use_alt);
            while (buf[buf_pos] != 0) {
                buf_pos++;
            }
            buf_pos++;
            buf[buf_pos] = 0;
        }
    }
    if (dialog->unk168 != NULL && func_80800000_gcdialogexec(dialog->unk168, dialog->unk16C)) {
        if (dialog->unk168->unk18 & 1) {
            buf[0] = 0;
            buf_pos = 0;
            for (j = 0; j < marker_count; j++) {
                func_800E6DD8(
                    buf + buf_pos,
                    _subaddiedialog_entrypoint_14(dialog->unk168, dialog->unk162, dialog->cnt++),
                    0, use_alt);
                while (buf[buf_pos] != 0) {
                    buf_pos++;
                }
                buf_pos++;
                buf[buf_pos] = 0;
            }
        }
    }
    func_80800350_gcdialogexec(
        dialog,
        ((DlgEntry_80802020_gcdialogexec *) ((s32) dialog->unk104[dialog->idx] +
                                             dialog->unk116[dialog->idx] * 8))
            ->unk4,
        buf,
        _gldialog_entrypoint_1(
            ((DlgEntry_80802020_gcdialogexec *) ((s32) dialog->unk104[dialog->idx] +
                                                 dialog->unk116[dialog->idx] * 8))
                ->unk4),
        0);
    return 0;
}

void gcdialogexec_entrypoint_10(DialogUpdateState *param_0)
{
    s32 i;
    s32 j;
    s32 result;
    s32 buttons[6];
    s32 unk_0[3];
    s32 handled;
    u8 *answers[8];

    result = -1;
    if (param_0->flags & 0x80) {
        func_80015ECC(0, buttons);
        func_80015F5C(0, unk_0);
    } else {
        func_80015E80(0, buttons);
        func_80015F28(0, unk_0);
    }

    switch (param_0->status.half.state) {
        case 1:
            // Count empty boxes; both empty means the dialog is over.
            for (j = 0, i = 0; i < 2; i++) {
                if (param_0->box[i] == NULL) {
                    j++;
                }
            }
            if (j == 2) {
                func_80800A50_gcdialogexec(param_0, 7);
            } else if (param_0->status.byte.completed == param_0->status.half.field_15D) {
                param_0->status.byte.completed = 0;
                func_80800A50_gcdialogexec(param_0, 2);
            }
            break;

        case 2:
            // Fetch the current line; negative codes are script commands.
            handled = 0;
            param_0->command[param_0->status.half.selected] =
                DIALOG_UPDATE_CMD(param_0->index[param_0->status.half.selected])->command;
            param_0->text[param_0->status.half.selected] =
                DIALOG_UPDATE_CMD(param_0->index[param_0->status.half.selected])->text;

            switch (param_0->command[param_0->status.half.selected]) {
                case -8:
                    func_80800478_gcdialogexec(param_0,
                                               *param_0->text[param_0->status.half.selected]);
                    param_0->index[param_0->status.half.selected]++;
                    handled = 1;
                    break;
                case -9:
                    if (!(param_0->flags & 0x200)) {
                        _gcdialogcamera_entrypoint_10(
                            param_0, *param_0->text[param_0->status.half.selected], 0);
                    }
                    param_0->index[param_0->status.half.selected]++;
                    handled = 1;
                    break;
                case -2:
                    param_0->field_158 = *param_0->text[param_0->status.half.selected];
                    param_0->index[param_0->status.half.selected]++;
                    func_80800A50_gcdialogexec(param_0, 11);
                    handled = 1;
                    break;
                case -1:
                    if (_subaddiedialog_entrypoint_15(
                            param_0->caller, param_0->text_id,
                            param_0->index[param_0->status.half.selected]) == 1U) {
                        func_80800A50_gcdialogexec(param_0, 9);
                    }
                    param_0->index[param_0->status.half.selected]++;
                    handled = 1;
            }
            if (handled) {
                break;
            }
            if (param_0->box[param_0->status.half.selected] == NULL ||
                _gczoombox_entrypoint_39(param_0->box[param_0->status.half.selected]) ||
                param_0->box_flags[param_0->status.half.selected].busy) {
                param_0->status.half.selected ^= 1;
            } else {
                switch (param_0->command[param_0->status.half.selected]) {
                    case -11:
                    case -10:
                        do {
                            param_0->index[param_0->status.half.selected]++;
                            param_0->command[param_0->status.half.selected] =
                                DIALOG_UPDATE_CMD(param_0->index[param_0->status.half.selected])
                                    ->command;
                        } while (param_0->command[param_0->status.half.selected] == -10 ||
                                 param_0->command[param_0->status.half.selected] == -11);
                        break;
                    case -4:
                        if (param_0->index[param_0->status.half.selected] == 0) {
                            param_0->status.word.count++;
                        }
                        _gczoombox_entrypoint_12(param_0->box[param_0->status.half.selected]);
                        param_0->box_flags[param_0->status.half.selected].available = 1;
                        param_0->box_flags[param_0->status.half.selected].busy = 1;
                        param_0->status.half.selected ^= 1;
                        param_0->status.word.opening = 1;
                        break;
                    case -5:
                        _gczoombox_entrypoint_12(param_0->box[param_0->status.half.selected]);
                        _gczoombox_entrypoint_10(param_0->box[param_0->status.half.selected]);
                        param_0->box_flags[param_0->status.half.selected].available = 0;
                        param_0->box_flags[param_0->status.half.selected].busy = 1;
                        param_0->status.half.selected ^= 1;
                        param_0->status.word.opening = 1;
                        break;
                    case -7:
                        for (j = param_0->index[param_0->status.half.selected];
                             param_0->commands[param_0->status.half.selected][j].command < -5;
                             j++) {
                        }
                        if (param_0->commands[param_0->status.half.selected][j].command >=
                            0) {
                            _gczoombox_entrypoint_37(
                                param_0->box[param_0->status.half.selected],
                                param_0->commands[param_0->status.half.selected][j].command +
                                    12);
                        }
                        if (param_0->index[param_0->status.half.selected]) {
                            _gczoombox_entrypoint_12(param_0->box[param_0->status.half.selected]);
                        }
                        if (!param_0->index[param_0->status.half.selected] &&
                            param_0->box_flags[param_0->status.half.selected].available == 2) {
                            _gczoombox_entrypoint_12(param_0->box[param_0->status.half.selected]);
                        }
                        param_0->box_flags[param_0->status.half.selected].available = 0;
                        param_0->index[param_0->status.half.selected]++;
                        param_0->status.half.selected ^= 1;
                        param_0->status.word.opening = 1;
                        break;
                    case -6:
                        _gczoombox_entrypoint_12(param_0->box[param_0->status.half.selected]);
                        param_0->box_flags[param_0->status.half.selected].available = 0;
                        param_0->index[param_0->status.half.selected]++;
                        param_0->status.half.selected ^= 1;
                        param_0->status.word.opening = 1;
                        break;
                    default:
                        if (DIALOG_UPDATE_CMD(param_0->index[param_0->status.half.selected] + 1)
                                ->command == -10) {
                            result = func_80801DB4_gcdialogexec(param_0);
                        } else if (DIALOG_UPDATE_CMD(param_0->index[param_0->status.half.selected] +
                                                     1)
                                       ->command == -11) {
                            result = func_80802020_gcdialogexec(param_0);
                        }
                        if (!_gczoombox_entrypoint_1(
                                DIALOG_UPDATE_CMD(param_0->index[param_0->status.half.selected])
                                    ->text)) {
                            param_0->index[param_0->status.half.selected]++;
                        } else {
                            if (func_80800000_gcdialogexec(param_0->caller, param_0->caller_id)) {
                                _gczoombox_entrypoint_35(
                                    param_0->box[param_0->status.half.selected], param_0->caller,
                                    param_0->field_167, param_0->caller_id);
                            }
                            if (result == -1) {
                                if (_gczoombox_entrypoint_37(
                                        param_0->box[param_0->status.half.selected],
                                        param_0->command[param_0->status.half.selected] + 12)) {
                                    _gczoombox_entrypoint_12(
                                        param_0->box[param_0->status.half.selected]);
                                    param_0->status.word.opening = 1;
                                } else {
                                    _gczoombox_entrypoint_18(
                                        param_0->box[param_0->status.half.selected]);
                                }
                            }
                            if (param_0->status.word.opening) {
                                _gczoombox_entrypoint_11(
                                    param_0->box[param_0->status.half.selected]);
                                param_0->status.word.opening = 0;
                            }
                            if (result == -1) {
                                for (j = param_0->index[param_0->status.half.selected];
                                     DIALOG_UPDATE_CMD(j)->command ==
                                         param_0->command[param_0->status.half.selected] &&
                                     j - param_0->index[param_0->status.half.selected] < 8 &&
                                     DIALOG_UPDATE_CMD(j + 1)->command != -11 &&
                                     DIALOG_UPDATE_CMD(j + 1)->command != -10;
                                     j++) {
                                    answers[j -
                                            param_0->index[param_0->status.half.selected]] =
                                        DIALOG_UPDATE_CMD(j)->text;
                                }
                                _gczoombox_entrypoint_32(
                                    param_0->box[param_0->status.half.selected]);
                                _gczoombox_entrypoint_7(
                                    param_0->box[param_0->status.half.selected],
                                    j - param_0->index[param_0->status.half.selected],
                                    answers);
                                param_0->index[param_0->status.half.selected] = j;
                            } else {
                                _gczoombox_entrypoint_32(
                                    param_0->box[param_0->status.half.selected]);
                                _gczoombox_entrypoint_8(param_0->box[param_0->status.half.selected],
                                                        param_0->output);
                                param_0->index[param_0->status.half.selected]++;
                            }
                            func_80800A50_gcdialogexec(param_0, 3);
                        }
                }
            }
            break;
        case 3:
            // Wait for the player to advance the text.
            if ((param_0->flags & 1) && buttons[1] == 1U) {
                func_80800A50_gcdialogexec(param_0, 6);
                break;
            }
            if (param_0->flags & 0x40) {
                break;
            }
            if ((param_0->flags & 0x80) ? (func_80015F0C(0, 1) ^ 1) : (func_80015F0C(0, 0) ^ 1)) {
                break;
            }
            func_80800A50_gcdialogexec(param_0, 6);
            break;
        case 4:
            // Wait for the answer: first button confirms, second cancels.
            if (buttons[0] == 1) {
                param_0->confirmed = 1;
                _gcaudiolist_entrypoint_0(6);
            } else if (buttons[1] == 1) {
                param_0->confirmed = 0;
                _gcaudiolist_entrypoint_0(7);
            }
            if (param_0->confirmed != -1) {
                func_80800A50_gcdialogexec(param_0, 10);
            }
            break;
        case 7:
            func_80800A50_gcdialogexec(param_0, 0);
    }
}

// TU-NOTE: this overlay's .data is defined here in C; the values are taken from the ROM.
u8 D_80802EA0_gcdialogexec[16] = {0x3F, 0xA, 0x3D, 0x71, 0x3F, 0x19, 0x99, 0x9A,
                                  0x3F, 0xC, 0xCC, 0xCD, 0x0,  0x0,  0x0,  0x0};
