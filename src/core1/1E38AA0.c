#include "common.h"
#ifndef M2C_MACROS_H
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr) ((s8 *) (expr) + (offset)))
#endif

typedef struct TTItemF_s {
    struct TTItemF_s *next;
    u8 pad_4[0x20];
} TTItemF;
typedef struct {
    u8 pad_0[0x8];
    s32 unk_8;
    u8 pad_C[0xB4];
} TTPlyrF;
typedef struct {
    u8 pad_0[2];
    s16 unk_2;
    u8 pad_4[0x28];
    void *unk_2C;
    void *unk_30;
} TTVceF;
typedef struct {
    u8 pad_0[0x14];
    s32 num_voices;
    s32 max_voices;
    TTPlyrF **voices;
    void *fx;
    u8 pad_24[0x20];
    TTVceF *unk_44;
} TTSlotF;
typedef struct {
    u8 pad_0[4];
    void *(*handler)();
} TTSynthF;
typedef struct {
    s32 client_list;
    s32 free_next;
    s32 free_prev;
    s32 alloc_next;
    s32 alloc_prev;
    s32 lame_next;
    s32 lame_prev;
    s32 param_samples;
    s32 cur_samples;
    void *dma_new;
    void *heap;
    TTItemF *param_list;
    TTSynthF *main_bus;
    TTSlotF *aux_buses;
    s32 num_pvoices;
    s32 num_aux;
    s32 output_rate;
    s32 max_chunk;
    s32 out_addr;
    s32 unk_4C;
} TTAMgrF;
typedef struct {
    u8 pad_0[4];
    s32 num_pvoices;
    s32 max_params;
    s32 num_aux;
    void *dma_new;
    void *heap;
    s32 output_rate;
    u8 fx_type[4];
} TTCfgF;
extern void *func_80020EE4(s32, s32, void *, s32, s32);
extern void *func_80027220(s32, TTCfgF *, void *);
extern void *func_800272B0();
extern void func_800293B4(void *, void *, void *);
typedef struct {
    u32 w0;
    u32 w1;
} TTAcmd4;
typedef struct TTSNode_s {
    struct TTSNode_s *next;
    u8 pad_4[4];
    s32 (*handler)(struct TTSNode_s *);
    u8 pad_C[4];
    s32 samples_left;
} TTSNode;
typedef struct {
    TTSNode *client_list;
    u8 pad_4[0x18];
    s32 param_samples;
    s32 cur_samples;
    u8 pad_24[0x20];
    s32 max_chunk;
    s32 out_addr;
} TTAMgrS;
extern TTAcmd4 *func_800295D0(s32, TTAcmd4 *);
typedef struct TTLink_s {
    struct TTLink_s *next;
    struct TTLink_s *prev;
} TTLink;
typedef struct TTFNode_s {
    struct TTFNode_s *next;
} TTFNode;
typedef struct {
    u8 pad_0[0x4];
    TTLink free_list;
    u8 pad_C[0x8];
    TTLink *lame_list;
    u8 pad_18[0x14];
    TTFNode *param_list;
    u8 pad_30[0x10];
    s32 output_rate;
} TTAMgrN;
extern TTAMgrN *D_800411F4;
extern void func_80020E40(TTLink *, TTLink *);
extern void func_80020E74(TTLink *);
typedef s32 M2C_UNK;
typedef struct TTPN_s {
    struct TTPN_s *next;
    u8 pad_4[0xC];
    s32 samples_left;
} TTPN;
typedef struct {
    TTPN *client_list;
    u8 pad_4[0x1C];
    s32 cur_samples;
} TTAMgrM;
extern u8 D_8007EA30;
extern u8 D_8007EA31;
extern u8 D_8007EA32;
extern u8 D_8007EA33[];
extern u8 D_8007EA34[];
extern u8 D_8007EA35[];

void func_80021820();
s32 func_800218C4();
s32 func_80021960(TTPN **out);
void func_80021AD0();

// Initializes the synth: aux buses, physical voices, parameter blocks and the main-bus FX handler.
void func_80020F70(TTCfgF *cfg)
{
    s32 i;
    s32 j;
    TTPlyrF *pvoice;
    TTPlyrF *pvoices;
    void *heap = cfg->heap;
    TTItemF *params;
    TTItemF *param;

    ((TTAMgrF *) D_800411F4)->client_list = 0;
    ((TTAMgrF *) D_800411F4)->num_pvoices = cfg->num_pvoices;
    ((TTAMgrF *) D_800411F4)->cur_samples = 0;
    ((TTAMgrF *) D_800411F4)->param_samples = 0;
    ((TTAMgrF *) D_800411F4)->output_rate = cfg->output_rate;
    ((TTAMgrF *) D_800411F4)->max_chunk = 0xB8;
    ((TTAMgrF *) D_800411F4)->dma_new = cfg->dma_new;
    ((TTAMgrF *) D_800411F4)->out_addr = 0;
    ((TTAMgrF *) D_800411F4)->unk_4C = 1;

    if (cfg->num_aux >= 2)
        ((TTAMgrF *) D_800411F4)->num_aux = 1;
    else if (cfg->num_aux <= 0)
        ((TTAMgrF *) D_800411F4)->num_aux = 1;
    else
        ((TTAMgrF *) D_800411F4)->num_aux = cfg->num_aux;

    ((TTAMgrF *) D_800411F4)->aux_buses =
        func_80020EE4(0, 0, heap, ((TTAMgrF *) D_800411F4)->num_aux, 0x48);

    for (i = 0; i < ((TTAMgrF *) D_800411F4)->num_aux; i++) {
        ((TTAMgrF *) D_800411F4)->aux_buses[i].num_voices = 0;
        ((TTAMgrF *) D_800411F4)->aux_buses[i].max_voices = cfg->num_pvoices;
        ((TTAMgrF *) D_800411F4)->aux_buses[i].voices = func_80020EE4(0, 0, heap, cfg->num_pvoices, 4);

        if (cfg->fx_type[i])
            ((TTAMgrF *) D_800411F4)->aux_buses[i].fx = func_80027220(i, cfg, heap);
        else
            ((TTAMgrF *) D_800411F4)->aux_buses[i].fx = 0;

        ((TTAMgrF *) D_800411F4)->aux_buses[i].unk_44 = func_80020EE4(0, 0, heap, 1, 0x38);
        ((TTAMgrF *) D_800411F4)->aux_buses[i].unk_44->unk_2 = 0;
        ((TTAMgrF *) D_800411F4)->aux_buses[i].unk_44->unk_2C = func_80020EE4(0, 0, heap, 1, 8);
        ((TTAMgrF *) D_800411F4)->aux_buses[i].unk_44->unk_30 = func_80020EE4(0, 0, heap, 1, 8);
    }

    ((TTAMgrF *) D_800411F4)->main_bus = func_80020EE4(0, 0, heap, 1, 0x14);
    ((TTAMgrF *) D_800411F4)->main_bus->handler = func_800272B0;
    ((TTAMgrF *) D_800411F4)->free_next = 0;
    ((TTAMgrF *) D_800411F4)->free_prev = 0;
    ((TTAMgrF *) D_800411F4)->lame_next = 0;
    ((TTAMgrF *) D_800411F4)->lame_prev = 0;
    ((TTAMgrF *) D_800411F4)->alloc_next = 0;
    ((TTAMgrF *) D_800411F4)->alloc_prev = 0;

    pvoices = func_80020EE4(0, 0, heap, cfg->num_pvoices, 0xC0);

    for (i = 0; i < cfg->num_pvoices; i++) {
        pvoice = (TTPlyrF *) (i * 0xC0 + (u8 *) pvoices);
        func_80020E40(pvoice, &((TTAMgrF *) D_800411F4)->free_next);
        pvoice->unk_8 = 0;
        func_800293B4(pvoice, ((TTAMgrF *) D_800411F4)->dma_new, heap);

        for (j = 0; j < ((TTAMgrF *) D_800411F4)->num_aux; j++) {
            (((TTAMgrF *) D_800411F4)->aux_buses[j].voices[((TTAMgrF *) D_800411F4)->aux_buses[j].num_voices] = pvoice,
             ((TTAMgrF *) D_800411F4)->aux_buses[j].num_voices++);
        }
    }

    params = func_80020EE4(0, 0, heap, cfg->max_params, 0x24);
    ((TTAMgrF *) D_800411F4)->param_list = 0;

    for (i = 0; i < cfg->max_params; i++) {
        param = (TTItemF *) (i * 0x24 + (u8 *) params);
        param->next = ((TTAMgrF *) D_800411F4)->param_list;
        ((TTAMgrF *) D_800411F4)->param_list = param;
    }

    ((TTAMgrF *) D_800411F4)->heap = heap;
}

// n_alAudioFrame: runs client handlers up to the end of the frame, then builds the RSP command list in chunks; returns the end of the list.
TTAcmd4 *func_80021574(TTAcmd4 *cmd_list, s32 *cmd_len, s32 out_phys, s32 frame_samples)
{
    TTSNode *client;
    TTAcmd4 *cmd_ptr;
    TTAcmd4 *prev_cmd;
    s32 chunk;
    s32 out_pos;

    cmd_ptr = cmd_list;
    out_pos = out_phys;

    if (!((TTAMgrS *) D_800411F4)->client_list) {
        *cmd_len = 0;
        return cmd_list;
    }

    for (((TTAMgrS *) D_800411F4)->param_samples = func_80021960(&client);
         ((TTAMgrS *) D_800411F4)->param_samples - ((TTAMgrS *) D_800411F4)->cur_samples < frame_samples;
         ((TTAMgrS *) D_800411F4)->param_samples = func_80021960(&client)) {
        ((TTAMgrS *) D_800411F4)->param_samples &= ~0xF;
        client->samples_left += func_800218C4(client->handler(client));
    }
    ((TTAMgrS *) D_800411F4)->param_samples &= ~0xF;

    if (frame_samples > 0) {
        do {
            chunk = (((TTAMgrS *) D_800411F4)->max_chunk < frame_samples) ? ((TTAMgrS *) D_800411F4)->max_chunk
                                                                 : frame_samples;

            prev_cmd = cmd_ptr;
            ((TTAMgrS *) D_800411F4)->out_addr = out_pos;
            cmd_ptr = func_800295D0(((TTAMgrS *) D_800411F4)->cur_samples, prev_cmd);

            frame_samples -= chunk;
            out_pos += chunk * 2 * 2;
            ((TTAMgrS *) D_800411F4)->cur_samples += chunk;
        } while (frame_samples > 0);
    }

    *cmd_len = ((u8 *) cmd_ptr - (u8 *) cmd_list) >> 3;
    func_80021820();

    return cmd_ptr;
}

// Pops a parameter block from the free list, or NULL.
TTFNode *func_80021794(void)
{
    TTFNode *param = 0;

    if (D_800411F4->param_list) {
        param = D_800411F4->param_list;
        D_800411F4->param_list = D_800411F4->param_list->next;
        param->next = 0;
    }
    return param;
}

// Returns a parameter block to the free list.
void func_800217F4(M2C_UNK *param)
{
    *param = M2C_FIELD((u8 *) D_800411F4, M2C_UNK **, 0x2C);
    M2C_FIELD((u8 *) D_800411F4, M2C_UNK **, 0x2C) = param;
}

// Moves all lame physical voices back to the free list.
void func_80021820(void)
{
    TTLink *pvoice;

    while (pvoice = D_800411F4->lame_list) {
        func_80020E74(pvoice);
        func_80020E40(pvoice, &D_800411F4->free_list);
    }
}

// Moves a physical voice to the lame list.
void func_80021884(TTLink *pvoice)
{
    func_80020E74(pvoice);
    func_80020E40(pvoice, (TTLink *) &D_800411F4->lame_list);
}

// Microseconds to output samples (rounded).
s32 func_800218C4(usec)
s32 usec;
{
    f32 samples;

    samples = (f32) usec * D_800411F4->output_rate / 1e+06f + 0.5f;
    return (s32) samples;
}

// Microseconds to samples, truncated to a multiple of 16.
s32 func_80021928(s32 usec)
{
    return func_800218C4(usec) & ~0xF;
}

// Returns the due time of the client that runs next; *out receives that client.
s32 func_80021960(TTPN **out)
{
    s32 min = 0x7FFFFFFF;
    TTPN *client;

    *out = 0;
    for (client = ((TTAMgrM *) D_800411F4)->client_list; client != 0; client = client->next) {
        if (client->samples_left - ((TTAMgrM *) D_800411F4)->cur_samples < min) {
            *out = client;
            min = client->samples_left - ((TTAMgrM *) D_800411F4)->cur_samples;
        }
    }

    return (*out)->samples_left;
}

// Sets the output-mode flags from a game-side mode, then refreshes bus 0.
void func_80021A00(mode) u8 mode;
{
    s32 i;

    D_8007EA30 = 0;
    D_8007EA31 = 0;
    D_8007EA32 = 0;

    switch (mode) {
        case 1:
            D_8007EA31 = 1;
            break;
        case 3:
            D_8007EA32 = 1;
            break;
        case 4:
            D_8007EA30 = 1;
            break;
    }

    for (i = 0; i <= 0; i++) {
        func_80021AD0(i, 0);
    }
}

// Recomputes the stereo-reverb/mix flags of one bus (0 = reuse its stored mode).
void func_80021AD0(bus, mode) s32 bus;
s32 mode;
{
    if (!mode)
        mode = D_8007EA35[bus];

    D_8007EA33[bus] = 0;
    D_8007EA34[bus] = 0;

    switch (mode) {
        case 2:
            if (D_8007EA30)
                D_8007EA34[bus] = 1;
            break;
        case 3:
            if (D_8007EA30)
                D_8007EA33[bus] = 1;
            break;
        case 4:
            if (!D_8007EA31)
                D_8007EA33[bus] = 1;
            break;
        case 5:
            if (!D_8007EA31) {
                D_8007EA33[bus] = 1;
                D_8007EA34[bus] = 1;
            }
            break;
    }

    D_8007EA35[bus] = mode;
}
