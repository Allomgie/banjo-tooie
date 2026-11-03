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

int func_80800000_gcdialogexec(u16 *param_0, u32 param_1)
{
    s32 ret;
    if (param_1 == -1) {
        ret = 0;
    } else {
        ret = (param_1 == ((u32) *(u16 *) (param_0 + 9) >> 1));
    }
    return ret;
}

void func_8080002C_gcdialogexec(u8 *param_0)
{
    s32 temp_a0;
    s32 var_s1;
    u8 *var_s0;

    var_s0 = param_0;
    var_s1 = 0;
    do {
        _gczoombox_entrypoint_0(*(s32 *) ((s8 *) var_s0 + 0x120));
        var_s1 += 1;
        var_s0 += 4;
        *(s32 *) ((s8 *) var_s0 + 0x11C) = 0;
    } while (var_s1 != 2);
    temp_a0 = *(s32 *) ((s8 *) param_0 + 0x12C);
    if (temp_a0 != 0) {
        _gczoombox_entrypoint_0(temp_a0);
        *(s32 *) ((s8 *) param_0 + 0x12C) = 0;
    }
}

short func_808000A0_gcdialogexec(void *param_0)
{
    void *local_0;
    void *local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    local_0 = param_0;
    local_1 = param_0;
    local_2 = 0;
    do {
        local_3 = 0;
        local_4 = 0;
        if ((s32) *(u8 *) ((char *) local_0 + 0x114) > 0) {
            do {
                local_3 += 1;
                *(s32 *) ((char *) *(s32 **) ((char *) local_1 + 0x104) + local_4 + 4) = 0;
                local_4 += 8;
            } while (local_3 < (s32) *(u8 *) ((char *) local_0 + 0x114));
        }
        *(u8 *) ((char *) local_0 + 0x114) = 0;
        heap_free(*(void **) ((char *) local_1 + 0x104));
        local_2 += 1;
        local_0 = (void *) ((char *) local_0 + 1);
        local_1 = (void *) ((char *) local_1 + 4);
        *(s32 *) ((char *) local_1 + 0x100) = 0;
    } while (local_2 != 2);
    if (*(s16 *) ((char *) param_0 + 0x162) != -1) {
        _gldialog_entrypoint_5(*(s16 *) ((char *) param_0 + 0x162));
    }
    *(s32 *) ((char *) param_0 + 0x100) = 0;
}

void func_80800164_gcdialogexec(param_0) DialogExecResetState *param_0;
{
    func_808000A0_gcdialogexec(param_0);
    if (!param_0->local_0[0].local_0 && !param_0->local_0[1].local_0) {
        func_8080002C_gcdialogexec(param_0);
    }
    param_0->local_3 = -1;
    param_0->local_1 = param_0->local_2 = 0;
    param_0->local_5 = NULL;
    param_0->local_4 = 0;
    param_0->local_6 = NULL;
    param_0->local_7 = NULL;
    param_0->local_8 = NULL;
}

void func_808001DC_gcdialogexec(DialogExec27 *param_0)
{
    param_0->local_4 = param_0->local_3;
    if (param_0->local_7) {
        if (param_0->local_5 == NULL) {
            param_0->local_7(param_0->local_5, param_0->local_3, param_0->local_2);
        } else if (func_80800000_gcdialogexec(param_0->local_5, param_0->local_6)) {
            param_0->local_7(param_0->local_5, param_0->local_3, param_0->local_2);
        }
    }
    if (param_0->local_5 && func_80800000_gcdialogexec(param_0->local_5, param_0->local_6) &&
        (*(u16 *) ((u8 *) param_0->local_5 + 0x18) & 1)) {
        _subaddiedialog_entrypoint_12(param_0->local_5, param_0->local_3, param_0->local_2);
    }
    if (param_0->local_0 & 8) {
        if (!func_800A9C98() || !param_0->local_1) {
            if (func_800F6438(param_0->local_8)) {
                func_800F82D4(param_0->local_8, 0);
            }
        }
    }
    func_800FECB8(0);
    func_80800164_gcdialogexec(param_0);
}

s32 func_808002E4_gcdialogexec(u8 *param_0)
{
    s32 local_1;
    s32 local_0 = 0;
    u8 *local_2;

    local_1 = _gldialog_entrypoint_1(param_0);
    for (local_2 = param_0; *local_2 != 0; local_2++) {
        if (*local_2 == (local_1 ? 0xAE : 0x7E)) {
            local_0++;
            if (param_0) {
            }
        }
    }
    return local_0;
}

void func_80800350_gcdialogexec(u8 *next_state, u8 *arg1, u8 *arg2, s32 arg3, s32 arg4)
{
    s32 var_v0;
    s32 i;
    s32 j;

    j = 0;
    var_v0 = 0;
    for (i = 0; arg1[i] != '\0'; i++) {
        if (arg1[i] == (arg3 ? 0xAE : '~')) {
            if (arg4) {
                next_state[var_v0++] = 0xFD;
                next_state[var_v0++] = 0x68;
            }

            for (; arg2[j] != '\0'; j++) {
                next_state[var_v0++] = arg2[j];
                if (arg4 && !arg3 && arg2[j] == ' ') {
                    next_state[var_v0++] = 0xFD;
                    next_state[var_v0++] = 0x68;
                }
            }
            j++;

            if (arg4) {
                next_state[var_v0++] = 0xFD;
                next_state[var_v0++] = 0x6C;
            }
        } else {
            next_state[var_v0++] = arg1[i];
        }
    }

    next_state[var_v0] = '\0';
}

void func_80800478_gcdialogexec(u8 *param_0, s32 param_1)
{
    s32 (*temp_v0)(u8 *, s16, s32);
    u8 *temp_a0;
    u8 *temp_a0_2;
    u8 *temp_a0_3;

    temp_v0 = *(s32(**)(u8 *, s16, s32))((s8 *) param_0 + 0x174);
    if (temp_v0 != NULL) {
        temp_a0 = *(u8 **) ((s8 *) param_0 + 0x168);
        if (temp_a0 == NULL) {
            temp_v0(temp_a0, *(s16 *) ((s8 *) param_0 + 0x162), param_1);
        } else if (func_80800000_gcdialogexec(temp_a0, *(s32 *) ((s8 *) param_0 + 0x16C)) != 0) {
            (*(s32(**)(u8 *, s16, s32))((s8 *) param_0 + 0x174))(
                *(u8 **) ((s8 *) param_0 + 0x168), *(s16 *) ((s8 *) param_0 + 0x162), param_1);
        }
    }
    temp_a0_2 = *(u8 **) ((s8 *) param_0 + 0x168);
    if ((temp_a0_2 != NULL) &&
        (func_80800000_gcdialogexec(temp_a0_2, *(s32 *) ((s8 *) param_0 + 0x16C)) != 0)) {
        temp_a0_3 = *(u8 **) ((s8 *) param_0 + 0x168);
        if (*(u16 *) ((s8 *) temp_a0_3 + 0x18) & 1) {
            _subaddiedialog_entrypoint_13(temp_a0_3, *(s16 *) ((s8 *) param_0 + 0x162), param_1);
        }
    }
}

void func_8080052C_gcdialogexec(u8 *param_0)
{
    f32 local_0;
    if (*(s8 *) (param_0 + 0x158) >= 0) {
        func_800E715C(param_0 + 0x130, _gldbstring_entrypoint_1(_gldbstring_entrypoint_0(0, 0x1865),
                                                                *(s8 *) (param_0 + 0x158)));
        _gldbstring_entrypoint_2(0x1865);
        *(void **) (param_0 + 0x12C) = _gczoombox_entrypoint_5(0x72, 0x44, 2, 0, func_800C0890);
        local_0 = ((f32 *) D_80802EA0_gcdialogexec)[*(s8 *) (param_0 + 0x158)];
        _gczoombox_entrypoint_26(*(void **) (param_0 + 0x12C),
                                 (s32) ((304.0f - local_0 * 216.0f) * 0.5f), 1.0f, local_0, 0);
        _gczoombox_entrypoint_20(*(void **) (param_0 + 0x12C), 100.0f, 0, 2, 0.1f, 0, 0);
        _gczoombox_entrypoint_8(*(void **) (param_0 + 0x12C), param_0 + 0x130);
        _gczoombox_entrypoint_9(*(void **) (param_0 + 0x12C));
        _gczoombox_entrypoint_11(*(void **) (param_0 + 0x12C));
    }
}

s32 func_8080064C_gcdialogexec(DlgExec_8080064C_gcdialogexec *param_0)
{
    s32 local_0;

    param_0->cur[param_0->idx] =
        ((DlgEntry_8080064C_gcdialogexec *) ((s32) param_0->unk104[param_0->idx] +
                                             param_0->unk116[param_0->idx] * 8))
            ->code;
    param_0->unk10C[param_0->idx] =
        (u8 *) ((DlgEntry_8080064C_gcdialogexec *) ((s32) param_0->unk104[param_0->idx] +
                                                    param_0->unk116[param_0->idx] * 8))
            ->unk4;
    switch (param_0->cur[param_0->idx]) {
        case -8:
            func_80800478_gcdialogexec(param_0, *param_0->unk10C[param_0->idx]);
            param_0->unk116[param_0->idx]++;
            return 1;
        case -9:
            param_0->unk116[param_0->idx]++;
            return *param_0->unk10C[param_0->idx] + 1;
        case -2:
            param_0->unk158 = *param_0->unk10C[param_0->idx];
            param_0->unk116[param_0->idx]++;
            return 1;
        case -1:
            return 1;
    }
    if (param_0->unk120[param_0->idx] == 0 ||
        _gczoombox_entrypoint_39(param_0->unk120[param_0->idx]) ||
        param_0->unk11C[param_0->idx].f4 != 0) {
        param_0->idx ^= 1;
        return 0;
    }
    switch (param_0->cur[param_0->idx]) {
        case -11:
        case -10:
            do {
                param_0->unk116[param_0->idx]++;
                param_0->cur[param_0->idx] =
                    ((DlgEntry_8080064C_gcdialogexec *) ((s32) param_0->unk104[param_0->idx] +
                                                         param_0->unk116[param_0->idx] * 8))
                        ->code;
            } while (param_0->cur[param_0->idx] == -10 || param_0->cur[param_0->idx] == -11);
            return 1;
        case -4:
            param_0->unk11C[param_0->idx].f6 = 1;
            param_0->unk11C[param_0->idx].f4 = 1;
            param_0->flag6 = 1;
            param_0->idx ^= 1;
            return 0;
        case -5:
            param_0->unk11C[param_0->idx].f6 = 0;
            param_0->unk11C[param_0->idx].f4 = 1;
            param_0->flag6 = 1;
            param_0->idx ^= 1;
            return 0;
        case -7:
            for (local_0 = param_0->unk116[param_0->idx];
                 param_0->unk104[param_0->idx][local_0].code < -5; local_0++) {
            }
            param_0->unk11C[param_0->idx].f6 = 0;
            param_0->unk116[param_0->idx]++;
            param_0->idx ^= 1;
            return 1;
        case -6:
            param_0->unk11C[param_0->idx].f6 = 0;
            param_0->unk116[param_0->idx]++;
            param_0->idx ^= 1;
            param_0->flag6 = 1;
            return 1;
        default:
            param_0->unk116[param_0->idx]++;
            return 1;
    }
}

void func_80800A50_gcdialogexec(param_0, param_1) DlgExec_80800A50_gcdialogexec *param_0;
u32 param_1;
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;

    if (param_0->state == 6) {
        if (param_1 == 6) {
            return;
        }
    }
    switch (param_1) {
        case 1:
            for (local_0 = 0; local_0 < 2; local_0++) {
                if (param_0->unk120[local_0] != 0) {
                    if (param_0->unk11C[local_0].unk0_6 == 0) {
                        _gczoombox_entrypoint_9(param_0->unk120[local_0]);
                    }
                    param_0->unk11C[local_0].unk0_6 = 0;
                }
            }
            param_0->unk158 = -1;
            break;
        case 5:
            for (local_0 = 0; local_0 < 2; local_0++) {
                if (param_0->unk120[local_0] != 0 && param_0->unk11C[local_0].unk0_6 == 0) {
                    _gczoombox_entrypoint_12(param_0->unk120[local_0]);
                    _gczoombox_entrypoint_10(param_0->unk120[local_0]);
                }
            }
            if (param_0->unk12C != 0) {
                _gczoombox_entrypoint_12(param_0->unk12C);
                _gczoombox_entrypoint_10(param_0->unk12C);
            }
            break;
        case 6:
            param_0->busy = 1;
            local_1 = -1;
            while ((local_2 = func_8080064C_gcdialogexec(param_0)) != 0) {
                if (local_2 >= 2) {
                    local_1 = local_2 - 1;
                }
            }
            while ((local_3 = func_8080064C_gcdialogexec(param_0)) != 0) {
                if (local_3 >= 2) {
                    local_1 = local_3 - 1;
                }
            }
            if (local_1 != -1 && !(param_0->unk15A & 0x200)) {
                _gcdialogcamera_entrypoint_10(param_0, local_1, 0);
            }
            param_0->sel = 0;
            for (local_0 = 0; local_0 < 2; local_0++) {
                param_0->unk11C[local_0].unk0_6 = 0;
                if (param_0->unk120[local_0] != 0) {
                    local_2 = _gczoombox_entrypoint_33(param_0->unk120[local_0]);
                    param_0->sel = param_0->sel + local_2;
                }
            }
            param_0->busy = 0;
            break;
        case 7:
            func_808001DC_gcdialogexec(param_0);
            param_1 = 0;
            break;
        case 8:
            for (local_0 = 0; local_0 < 2; local_0++) {
                if (param_0->unk11C[local_0].unk0_6 == 0) {
                    _gczoombox_entrypoint_0(param_0->unk120[local_0]);
                    param_0->unk120[local_0] = 0;
                }
            }
            func_808001DC_gcdialogexec(param_0);
            break;
        case 10:
            if (param_0->unk12C != 0) {
                _gczoombox_entrypoint_12(param_0->unk12C);
                _gczoombox_entrypoint_10(param_0->unk12C);
            }
            break;
        case 11:
            func_8080052C_gcdialogexec(param_0);
    }
    param_0->state = param_1;
}

void func_80800D30_gcdialogexec(this, arg1, msg) DialogExecBits *this;
{
    s32 p;
    s32 q;

    switch (msg) {
        case 1:
            this->a++;
            break;
        case 3:
            func_80800A50_gcdialogexec(this, 2);
            break;
        case 4:
            if (this->state == 6) {
                this->d--;
                if (this->d == 0) {
                    p = ((u32) this->unk11C >> 6) ? 1 : 0;
                    q = ((u32) this->unk11D >> 6) ? 1 : 0;
                    func_80800A50_gcdialogexec(this, (q + p) ? 8 : 5);
                }
            } else {
                if ((s32) this->b <
                    (((u32) this->unk11C >> 6) ? 1 : 0) + (((u32) this->unk11D >> 6) ? 1 : 0)) {
                    this->b++;
                    if (this->b + this->c == this->total) {
                        func_80800A50_gcdialogexec(this, 8);
                    }
                }
            }
            break;
        case 6:
            this->c++;
            if (this->c == this->total) {
                func_80800A50_gcdialogexec(this, 7);
            }
            if (this->b + this->c == this->total) {
                func_80800A50_gcdialogexec(this, 8);
            }
    }
}

void func_80800F60_gcdialogexec(param_0, param_1, param_2) DialogExecEvent *param_0;
{
    s32 local_0;
    switch (param_2) {
        case 3:
            if (param_0->state == 11)
                func_80800A50_gcdialogexec(param_0, 4);
        case 1:
        case 4:
            break;
        case 6:
            if (param_0->state == 10) {
                local_0 = param_0->text[param_0->selected].available ? 8 : 2;
                func_80800A50_gcdialogexec(param_0, local_0);
            }
    }
}

s32 func_80801008_gcdialogexec(s32 param_0)
{
    return param_0 ? 0x1C : 0xC8;
}

s32 func_80801020_gcdialogexec(s32 param_0)
{
    return param_0 ? 1 : 0;
}

void func_80801038_gcdialogexec(DialogExec *param_0, s32 param_1)
{
    s32 i;
    s32 j;
    u8 *local_0;
    s32 local_1;
    char local_3;
    s32 local_2;

    local_0 = param_0->unk100 = _gldialog_entrypoint_4(param_1);
    for (i = 0; i < 2; i++) {
        param_0->unk114[i] = *local_0++;
        param_0->unk104[i] = heap_alloc(param_0->unk114[i] * sizeof(DialogLine));
        for (j = 0; j < param_0->unk114[i]; j++) {
            local_1 = local_3 = *local_0++;
            if (local_3 > 0 && local_3 < 0x20) {
                local_1 = -local_3;
                if (local_3 == 3) {
                    local_1 = *local_0++ + 0x75;
                }
            } else {
                local_1 = (local_3 >= 0x80) ? local_3 - 0x80 : local_3;
            }
            if (local_1 == 0x51 || local_1 == 0x79) {
                local_1 = param_0->unk167 - 0xC;
            }
            param_0->unk104[i][j].unk0 = local_1;
            local_2 = *local_0;
            local_0++;
            param_0->unk104[i][j].unk4 = local_0;
            local_0 += local_2;
        }
    }
}

void func_808011A4_gcdialogexec(param_0, param_1, param_2, param_3, param_4,
                                param_5) DialogZoomBoxes *param_0;
s32 param_1;
s32 param_2;
s32 param_3;
s32 param_4;
s32 param_5;
{
    s32 local_0;

    for (local_0 = 0; local_0 < 2; local_0++) {
        if (param_0->local_0[local_0]) {
            _gczoombox_entrypoint_20(param_0->local_0[local_0], (f32) param_3, param_1, param_2,
                                     0.4f, param_4, param_5);
        }
    }
}

void func_80801268_gcdialogexec(DlgExec_80801268_gcdialogexec *param_0, s32 param_1, s32 param_2,
                                DlgObj_80801268_gcdialogexec *param_3, s32 param_4, s32 param_5,
                                s32 param_6, s16 param_7)
{
    s32 i;
    s32 j;
    s32 local_0;

    param_0->unk167 = param_7;
    func_80801038_gcdialogexec(param_0, param_1);
    param_0->unk168 = param_3;
    param_0->b = 0;
    param_0->total = param_0->c = param_0->a = param_0->d = param_0->b;
    param_0->unk170 = param_4;
    param_0->unk174 = param_5;
    param_0->unk178 = param_6;
    param_0->unk16C = (param_3 != NULL) ? (param_3->unk12_1 ? param_3->unk12_1 : -1) : -1;
    param_0->cnt = 0;
    for (i = 0; i < 2; i++) {
        j = 0;
        local_0 = param_0->unk104[i][0].code;
        while (param_0->unk104[i][j].code < -5 && j < param_0->unk114[i]) {
            j++;
        }
        param_0->cur[i] = local_0;
        param_0->unk10C[i] = param_0->unk104[i]->str;
        param_0->unk116[i] = 0;
        param_0->unk128[i] = func_80801008_gcdialogexec(i);
        param_0->unk11C[i].f4 = 0;
        if (param_0->unk104[i][j].code >= 0) {
            if (!param_0->unk11C[i].f6) {
                if (param_0->unk104[i][j].code + 0xC != 0x29 &&
                    param_0->unk104[i][j].code + 0xC != 0x84) {
                    param_0->unk120[i] = _gczoombox_entrypoint_5(
                        param_0->unk128[i], param_0->unk104[i][j].code + 0xC, 0,
                        func_80801020_gcdialogexec(i), func_800C01D8);
                } else {
                    param_0->unk120[i] = _gczoombox_entrypoint_5(
                        param_0->unk128[i], param_0->unk104[i][j].code + 0xC, 0,
                        1 - func_80801020_gcdialogexec(i), func_800C01D8);
                }
                if (param_2 & 0x100) {
                    _gczoombox_entrypoint_24(param_0->unk120[i], 0);
                }
                if (param_2 & 0x400) {
                    _gczoombox_entrypoint_25(param_0->unk120[i], 1);
                }
            } else {
                if (func_80800000_gcdialogexec(param_0->unk168, param_0->unk16C)) {
                    _gczoombox_entrypoint_35(param_0->unk120[i], param_0->unk168, param_0->unk167,
                                             param_0->unk16C);
                }
                param_0->a++;
            }
            param_0->total++;
        } else {
            if (param_0->unk104[i][j].code < -4) {
                if (param_0->unk11C[i].f6) {
                    _gczoombox_entrypoint_10(param_0->unk120[i]);
                    param_0->total++;
                } else {
                    param_0->unk120[i] = 0;
                }
                param_0->unk11C[i].f6 = 0;
            } else {
                if (param_0->unk11C[i].f6) {
                    param_0->total++;
                    param_0->a++;
                }
            }
        }
    }
    param_0->unk162 = param_1;
    param_0->unk15A = param_2;
    if (param_0->cur[0] < 0) {
        param_0->idx = 0;
    } else {
        param_0->idx = 1;
    }
    param_0->flag6 = 1;
    param_0->unk160 = (func_800A9C98() && param_0->f11) ? 1 : -1;
    func_80800A50_gcdialogexec(param_0, (func_800A9C98() && param_0->f11) ? 6 : 1);
    func_808011A4_gcdialogexec(param_0, 5, 2, 15, param_2 & 2, param_2 & 0x80);
}

s32 gcdialogexec_entrypoint_0(DialogExecQueue *param_0, s32 param_1, s32 param_2, f32 *param_3,
                              Unk80132ED0 *param_4, void *param_5, void *param_6, void *param_7,
                              s16 param_8)
{
    s32 local_0;

    if (!func_800C0638()) {
        param_0->local_5 = func_800F54E4();
        func_80801268_gcdialogexec(param_0, param_1, param_2, param_4, param_5, param_6, param_7,
                                   param_8);
        if (param_2 & 8) {
            if (!func_800A9C98() || !param_0->local_2) {
                if (param_3 != NULL) {
                    func_800F8300(param_0->local_5, param_0->local_0 < 0 ? 1 : 3, param_3);
                } else {
                    func_800F82D4(param_0->local_5, param_0->local_0 < 0 ? 1 : 3);
                }
            }
        }
        func_800FEC60(0);
        return 1;
    }
    if ((param_2 & 0x20)) {
        if (!(param_0->local_1 & 0x40)) {
            func_800C0658();
        } else {
            param_0->local_3 = 0;
            param_0->local_4 = 0;
        }
    }
    if ((param_2 & 4) || (param_2 & 0x20)) {
        local_0 = param_0->local_4 + param_0->local_3;
        if (local_0 >= 4) {
            local_0 -= 4;
        }
        param_0->local_6[local_0].local_0 = param_1;
        param_0->local_6[local_0].local_1 = param_2;
        if (param_3 != NULL) {
            func_800EE7F8(param_0->local_6[local_0].local_2.f, param_3);
        } else {
            func_800EFD24(param_0->local_6[local_0].local_2.f);
        }
        param_0->local_6[local_0].local_3 = param_4;
        param_0->local_6[local_0].local_4 = param_8;
        param_0->local_6[local_0].local_5 =
            (param_4 != NULL) ? (((u32) *(u16 *) ((u8 *) param_4 + 0x12) >> 1)
                                     ? ((u32) *(u16 *) ((u8 *) param_4 + 0x12) >> 1)
                                     : -1)
                              : -1;
        param_0->local_6[local_0].local_6 = param_5;
        param_0->local_6[local_0].local_7 = param_6;
        param_0->local_6[local_0].local_8 = param_7;
        param_0->local_6[local_0].local_9 = func_800F54E4();
        param_0->local_3++;
        if (param_2 & 8) {
            if (!func_800A9C98() || !param_0->local_2) {
                if (!func_800F5B0C(param_0->local_6[local_0].local_9)) {
                    if (param_3 != NULL) {
                        func_800F8300(param_0->local_6[local_0].local_9, 2, param_3);
                    } else {
                        func_800F82D4(param_0->local_6[local_0].local_9, 2);
                    }
                } else {
                    func_800F82D4(param_0->local_6[local_0].local_9,
                                  func_800F5B0C(param_0->local_6[local_0].local_9));
                }
            }
        }
        return 1;
    }
    return 0;
}

void gcdialogexec_entrypoint_1(DialogExecQueueState *this)
{
    DialogQueueEntry *e;

    e = &this->queue[this->read];
    func_80801268_gcdialogexec(this, e->unk0, e->unk2, e->unk10, e->unk1C, e->unk20, e->unk24,
                               e->unk14);
    this->unk16C = e->unk18;
    this->unk17C = e->unk28;
    func_800FEC60(0);
    if ((e->unk2 & 8) && (!func_800A9C98() || !this->unk15C_11)) {
        if (func_800F6438(this->unk17C)) {
            func_800F82D4(this->unk17C, 0);
        }
        if (func_800EEEA8(e->unk4)) {
            if (func_800F6438(this->unk17C)) {
                func_800F82D4(this->unk17C, (this->unk11A < 0) ? 1 : 3);
            }
        } else {
            if (func_800F6438(this->unk17C)) {
                func_800F8300(this->unk17C, (this->unk11A < 0) ? 1 : 3, e->unk4);
            }
        }
    }
    this->read++;
    if (this->read >= 4) {
        this->read -= 4;
    }
    this->count--;
}

void gcdialogexec_entrypoint_2(u8 *param_0)
{
    s32 local_3;
    u8 *local_1;
    s32 local_2;
    u8 *local_0;

    ((DialogExecFlags_gcdialogexec_entrypoint_2 *) (param_0 + 0x11C))->local_0 = 0;
    ((DialogExecFlags_gcdialogexec_entrypoint_2 *) (param_0 + 0x11D))->local_0 = 0;
    if (func_800C0638()) {
        func_80800A50_gcdialogexec(param_0, 6);
    } else {
        local_0 = param_0;
        local_2 = 0;
        if (param_0[0x15C] != 6) {
            ((DialogCounterBits *) (param_0 + 0x15F))->local_0 = 0;
            for (local_1 = param_0; local_2 != 8; local_2 += 4, local_0++, local_1 += 4) {
                ((DialogExecFlags_gcdialogexec_entrypoint_2 *) (local_0 + 0x11C))->local_0 = 0;
                local_3 = *(s32 *) (local_1 + 0x120);
                if (local_3) {
                    local_3 = _gczoombox_entrypoint_33(local_3);
                    ((DialogCounterBits *) (param_0 + 0x15F))->local_0 =
                        ((DialogCnt *) (param_0 + 0x15C))->cnt + local_3;
                }
            }
            if (*(s32 *) (param_0 + 0x15C) & 3) {
                param_0[0x15C] = 6;
            }
        }
    }
    ((DialogNibbleFlags *) (param_0 + 0x161))->local_0 = 0;
    ((DialogNibbleFlags *) (param_0 + 0x161))->local_1 = 0;
}

s32 gcdialogexec_entrypoint_3(s32 param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4,
                              s32 param_5)
{
    gcdialogexec_entrypoint_0(param_0, param_1 + 0xE06, 0x44, 0, 0, 0, 0, param_5, 0);
    func_808011A4_gcdialogexec(param_0, param_3, param_4, param_2, 0, 0);
    return 1;
}

void gcdialogexec_entrypoint_4(void *param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4,
                               s32 param_5)
{
    func_808011A4_gcdialogexec(param_0, param_1, param_2, param_3, param_4, param_5);
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

void gcdialogexec_entrypoint_8(s32 arg0)
{
    func_80800A50_gcdialogexec(arg0, 0x2);
}

void gcdialogexec_entrypoint_9()
{
    func_80800F60_gcdialogexec();
}

s32 func_80801DB4_gcdialogexec(DlgExec_80801DB4_gcdialogexec *param_0)
{
    s32 local_0;
    s32 local_1;
    s32 local_5;
    s32 local_2;
    s32 local_3;

    local_0 = -1;
    if (param_0->unk178) {
        local_1 = 1;
        if (param_0->unk168 == NULL) {
            local_0 = ((DlgCb) param_0->unk178)(param_0->unk168, param_0->unk162,
                                                param_0->unk116[param_0->idx]);
        } else if (func_80800000_gcdialogexec(param_0->unk168, param_0->unk16C)) {
            local_0 = ((DlgCb) param_0->unk178)(param_0->unk168, param_0->unk162,
                                                param_0->unk116[param_0->idx]);
        }
        if (local_0 < 0) {
            local_0 = -1 - local_0;
            local_1 = 0;
        }
        if (local_0 >= 0 &&
            (local_3 = local_0 * 8,
             *(s16 *) ((u8 *) (param_0->unk104[param_0->idx] + param_0->unk116[param_0->idx]) +
                       local_3 + 8) == -10)) {
            local_2 = _gldialog_entrypoint_1(
                (s32) (param_0->unk104[param_0->idx] + param_0->unk116[param_0->idx])->str);
            func_80800350_gcdialogexec(
                param_0, (s32) (param_0->unk104[param_0->idx] + param_0->unk116[param_0->idx])->str,
                *(s32 *) ((u8 *) (param_0->unk104[param_0->idx] + param_0->unk116[param_0->idx]) +
                          local_3 + 0xC),
                local_2, local_1);
        } else {
            local_0 = -1;
        }
    }
    if (param_0->unk168 && func_80800000_gcdialogexec(param_0->unk168, param_0->unk16C) &&
        (*(u16 *) ((u8 *) param_0->unk168 + 0x18) & 1)) {
        local_5 = 1;
        local_0 = _subaddiedialog_entrypoint_14(param_0->unk168, param_0->unk162,
                                                param_0->unk116[param_0->idx]);
        if (local_0 < 0) {
            local_0 = -1 - local_0;
            local_5 = 0;
        }
        if (local_0 >= 0 &&
            (local_3 = local_0 * 8,
             *(s16 *) ((u8 *) (param_0->unk104[param_0->idx] + param_0->unk116[param_0->idx]) +
                       local_3 + 8) == -10)) {
            local_2 = _gldialog_entrypoint_1(
                (s32) (param_0->unk104[param_0->idx] + param_0->unk116[param_0->idx])->str);
            func_80800350_gcdialogexec(
                param_0, (s32) (param_0->unk104[param_0->idx] + param_0->unk116[param_0->idx])->str,
                *(s32 *) ((u8 *) (param_0->unk104[param_0->idx] + param_0->unk116[param_0->idx]) +
                          local_3 + 0xC),
                local_2, local_5);
        } else {
            local_0 = -1;
        }
    }
    return local_0;
}

s32 func_80802020_gcdialogexec(DlgExec_80802020_gcdialogexec *param_0)
{
    s32 local_1;
    s32 local_2;
    s32 local_3;
    char local_0[16];
    s32 local_4;
    s32 local_5;
    s32 local_6;

    local_4 = -1;
    local_1 = func_808002E4_gcdialogexec(
        ((DlgEntry_80802020_gcdialogexec *) ((s32) param_0->unk104[param_0->idx] +
                                             param_0->unk116[param_0->idx] * 8))
            ->unk4);
    local_2 = _gldialog_entrypoint_1(
        ((DlgEntry_80802020_gcdialogexec *) ((s32) param_0->unk104[param_0->idx] +
                                             param_0->unk116[param_0->idx] * 8))
            ->unk4);
    local_0[0] = 0;
    if (param_0->unk178 != NULL) {
        local_5 = 0;
        for (local_3 = 0; local_3 < local_1; local_3++) {
            if (param_0->unk168 == NULL) {
                local_4 = param_0->unk178(param_0->unk168, param_0->unk162, param_0->cnt++);
            } else if (func_80800000_gcdialogexec(param_0->unk168, param_0->unk16C)) {
                local_4 = param_0->unk178(param_0->unk168, param_0->unk162, param_0->cnt++);
            }
            func_800E6DD8(local_0 + local_5, local_4, 0, local_2);
            while (local_0[local_5] != 0) {
                local_5++;
            }
            local_5++;
            local_0[local_5] = 0;
        }
    }
    if (param_0->unk168 != NULL && func_80800000_gcdialogexec(param_0->unk168, param_0->unk16C)) {
        if (param_0->unk168->unk18 & 1) {
            local_0[0] = 0;
            local_5 = 0;
            for (local_6 = 0; local_6 < local_1; local_6++) {
                func_800E6DD8(
                    local_0 + local_5,
                    _subaddiedialog_entrypoint_14(param_0->unk168, param_0->unk162, param_0->cnt++),
                    0, local_2);
                while (local_0[local_5] != 0) {
                    local_5++;
                }
                local_5++;
                local_0[local_5] = 0;
            }
        }
    }
    func_80800350_gcdialogexec(
        param_0,
        ((DlgEntry_80802020_gcdialogexec *) ((s32) param_0->unk104[param_0->idx] +
                                             param_0->unk116[param_0->idx] * 8))
            ->unk4,
        local_0,
        _gldialog_entrypoint_1(
            ((DlgEntry_80802020_gcdialogexec *) ((s32) param_0->unk104[param_0->idx] +
                                                 param_0->unk116[param_0->idx] * 8))
                ->unk4),
        0);
    return 0;
}

void gcdialogexec_entrypoint_10(DialogUpdateState *param_0)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3[6];
    s32 local_4[3];
    s32 local_5;
    u8 *local_6[8];

    local_2 = -1;
    if (param_0->flags & 0x80) {
        func_80015ECC(0, local_3);
        func_80015F5C(0, local_4);
    } else {
        func_80015E80(0, local_3);
        func_80015F28(0, local_4);
    }

    switch (param_0->status.half.state) {
        case 1:
            for (local_1 = 0, local_0 = 0; local_0 < 2; local_0++) {
                if (param_0->box[local_0] == NULL) {
                    local_1++;
                }
            }
            if (local_1 == 2) {
                func_80800A50_gcdialogexec(param_0, 7);
            } else if (param_0->status.byte.completed == param_0->status.half.field_15D) {
                param_0->status.byte.completed = 0;
                func_80800A50_gcdialogexec(param_0, 2);
            }
            break;

        case 2:
            local_5 = 0;
            param_0->command[param_0->status.half.selected] =
                DIALOG_UPDATE_CMD(param_0->index[param_0->status.half.selected])->command;
            param_0->text[param_0->status.half.selected] =
                DIALOG_UPDATE_CMD(param_0->index[param_0->status.half.selected])->text;

            switch (param_0->command[param_0->status.half.selected]) {
                case -8:
                    func_80800478_gcdialogexec(param_0,
                                               *param_0->text[param_0->status.half.selected]);
                    param_0->index[param_0->status.half.selected]++;
                    local_5 = 1;
                    break;
                case -9:
                    if (!(param_0->flags & 0x200)) {
                        _gcdialogcamera_entrypoint_10(
                            param_0, *param_0->text[param_0->status.half.selected], 0);
                    }
                    param_0->index[param_0->status.half.selected]++;
                    local_5 = 1;
                    break;
                case -2:
                    param_0->field_158 = *param_0->text[param_0->status.half.selected];
                    param_0->index[param_0->status.half.selected]++;
                    func_80800A50_gcdialogexec(param_0, 11);
                    local_5 = 1;
                    break;
                case -1:
                    if (_subaddiedialog_entrypoint_15(
                            param_0->caller, param_0->text_id,
                            param_0->index[param_0->status.half.selected]) == 1U) {
                        func_80800A50_gcdialogexec(param_0, 9);
                    }
                    param_0->index[param_0->status.half.selected]++;
                    local_5 = 1;
            }
            if (local_5) {
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
                        for (local_1 = param_0->index[param_0->status.half.selected];
                             param_0->commands[param_0->status.half.selected][local_1].command < -5;
                             local_1++) {
                        }
                        if (param_0->commands[param_0->status.half.selected][local_1].command >=
                            0) {
                            _gczoombox_entrypoint_37(
                                param_0->box[param_0->status.half.selected],
                                param_0->commands[param_0->status.half.selected][local_1].command +
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
                            local_2 = func_80801DB4_gcdialogexec(param_0);
                        } else if (DIALOG_UPDATE_CMD(param_0->index[param_0->status.half.selected] +
                                                     1)
                                       ->command == -11) {
                            local_2 = func_80802020_gcdialogexec(param_0);
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
                            if (local_2 == -1) {
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
                            if (local_2 == -1) {
                                for (local_1 = param_0->index[param_0->status.half.selected];
                                     DIALOG_UPDATE_CMD(local_1)->command ==
                                         param_0->command[param_0->status.half.selected] &&
                                     local_1 - param_0->index[param_0->status.half.selected] < 8 &&
                                     DIALOG_UPDATE_CMD(local_1 + 1)->command != -11 &&
                                     DIALOG_UPDATE_CMD(local_1 + 1)->command != -10;
                                     local_1++) {
                                    local_6[local_1 -
                                            param_0->index[param_0->status.half.selected]] =
                                        DIALOG_UPDATE_CMD(local_1)->text;
                                }
                                _gczoombox_entrypoint_32(
                                    param_0->box[param_0->status.half.selected]);
                                _gczoombox_entrypoint_7(
                                    param_0->box[param_0->status.half.selected],
                                    local_1 - param_0->index[param_0->status.half.selected],
                                    local_6);
                                param_0->index[param_0->status.half.selected] = local_1;
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
            if ((param_0->flags & 1) && local_3[1] == 1U) {
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
            if (local_3[0] == 1) {
                param_0->confirmed = 1;
                _gcaudiolist_entrypoint_0(6);
            } else if (local_3[1] == 1) {
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

u8 D_80802EA0_gcdialogexec[16] = {0x3F, 0xA, 0x3D, 0x71, 0x3F, 0x19, 0x99, 0x9A,
                                  0x3F, 0xC, 0xCC, 0xCD, 0x0,  0x0,  0x0,  0x0};
