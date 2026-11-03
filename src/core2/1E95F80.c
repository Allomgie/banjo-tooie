#include "common.h"

typedef struct {
    s16 map, value, mode, enabled;
    f32 origin[3], normal[3];
} LocalEntry;
typedef struct {
    u8 *dl_buf[2], *saved_dl;
    u8 buf_idx, active, unk_E, unk_F, reflecting, mode;
    s16 model_id;
    f32 matrix[4][4];
    u8 pad_54[0x74];
    u8 matrix_dl[2][0x30];
} LocalState_800BC690;
extern LocalEntry D_8011A760[];
extern LocalState_800BC690 D_801282E0;
extern f32 D_80128324[];
extern f32 D_801282F4[4][4];
extern f32 D_80128384[];
extern f32 D_80128378[];
extern void *heap_alloc(s32);
extern f32 func_800EEAA4(f32 *, f32 *);
extern void func_800EFA20(f32 *, f32 *, f32);
extern s32 D_80128390;
extern s32 D_8012839C;
extern char D_801282ED;
extern void *D_80128338;
void func_800BCC90();

// Looks up the current map in D_8011A760 and sets up the mirror: reflection matrix
// I - 2nn^T plus translation, and two display list buffers.
void func_800BC690(void)
{
    s32 map_id;
    s32 i;
    f32 normal[3];
    map_id = func_800EA05C();
    for (i = 0; i < 3; i++) {
        if (map_id == D_8011A760[i].map)
            break;
    }
    if (i != 3) {
        if (D_8011A760[i].enabled)
            func_800B5680((s32) D_8011A760[i].origin[1]);
        D_801282E0.reflecting = D_801282E0.active = 1;
        D_801282E0.unk_F = D_801282E0.unk_E = 0;
        D_801282E0.model_id = D_8011A760[i].value;
        D_801282E0.mode = D_8011A760[i].mode;
        D_801282E0.dl_buf[0] = heap_alloc(0x5DC0);
        D_801282E0.dl_buf[1] = heap_alloc(0x5DC0);
        func_800EF410(normal, D_8011A760[i].normal);
        D_801282E0.matrix[0][0] = 1.0f - (2.0f * normal[0]) * normal[0];
        D_801282E0.matrix[1][0] = (2.0f * -normal[1]) * normal[0];
        D_801282E0.matrix[2][0] = (2.0f * -normal[2]) * normal[0];
        D_801282E0.matrix[0][1] = (2.0f * -normal[0]) * normal[1];
        D_801282E0.matrix[1][1] = 1.0f - (2.0f * normal[1]) * normal[1];
        D_801282E0.matrix[2][1] = (2.0f * -normal[2]) * normal[1];
        D_801282E0.matrix[0][2] = (2.0f * -normal[0]) * normal[2];
        D_801282E0.matrix[1][2] = (2.0f * -normal[1]) * normal[2];
        D_801282E0.matrix[2][2] = 1.0f - (2.0f * normal[2]) * normal[2];
        D_801282E0.matrix[0][3] = D_801282E0.matrix[1][3] = D_801282E0.matrix[2][3] = 0.0f;
        func_800EFA20(D_80128324, normal,
                      2.0f * func_800EEAA4(D_8011A760[i].origin, normal));
        D_801282E0.matrix[3][3] = 1.0f;
        guMtxF2L(D_801282F4, (Mtx *) &D_80128338);
        func_800EE7F8(D_80128384, normal);
        func_800EE7F8(D_80128378, D_8011A760[i].origin);
    }
}

// Frees the two display list buffers.
void func_800BC8A0()
{
    if (((u8 *) &D_801282E0)[0xd] != 0) {
        heap_free(*(u32 *) &((u8 *) &D_801282E0)[0]);
        heap_free(*(u32 *) &((u8 *) &D_801282E0)[4]);
        *(u32 *) &((u8 *) &D_801282E0)[4] = 0;
        *(u32 *) &((u8 *) &D_801282E0)[0] = 0;
        ((u8 *) &D_801282E0)[0xd] = 0;
    }
}

// Redirects scene rendering into the active mirror buffer, saving the current display list pointer.
int func_800BC8F8(s32 *gfx)
{
    if (*(u8 *) ((char *) (int *) &D_801282E0 + 0xD)) {
        ((int *) &D_801282E0)[2] = gfx[0];
        gfx[0] = ((int *) &D_801282E0)[*(u8 *) ((char *) (int *) &D_801282E0 + 0xC)];
        func_800E42E4(1);
    }
}

// Closes the mirror buffer (G_ENDDL), restores the saved display list, then emits the mirror matrix,
// the buffered scene and the mirror-surface model.
void func_800BC948(u8 **gfx)
{
    u8 *head;
    u8 *tail;
    u8 *scene_dl;
    u8 *head_end;
    u8 *tail_end;
    u8 *end_cmd;
    u8 *head_base;
    u8 *geo_cmd;
    s32 model;
    u8 *call_cmd;
    u8 *geo_cmd2;
    u8 *call_cmd2;
    if (D_801282E0.active != 0) {
        D_801282E0.reflecting = 0;
        end_cmd = *gfx;
        *gfx = end_cmd + 8;
        *(s32 *) (end_cmd + 4) = 0;
        *(s32 *) end_cmd = 0xDF000000;
        scene_dl = D_801282E0.dl_buf[D_801282E0.buf_idx];
        osWritebackDCache(scene_dl, ((s32) (*gfx - scene_dl) >> 3) * 8);
        *gfx = D_801282E0.saved_dl;
        func_800E42E4(0);
        head = D_801282E0.matrix_dl[D_801282E0.buf_idx];
        func_800E4640(&head);
        func_800BCC90(&head);
        head_end = head;
        head = head_end + 8;
        *(s32 *) (head_end + 4) = 0;
        *(s32 *) head_end = 0xDF000000;
        tail = head;
        func_800E4640(&head);
        tail_end = head;
        head = tail_end + 8;
        *(s32 *) (tail_end + 4) = 0;
        // Matching: the goto and its label are needed for the match.
        goto dummy_label_498827;
    dummy_label_498827:

        *(s32 *) tail_end = 0xDF000000;
        head_base = ((u8 *) &D_801282E0 + D_801282E0.buf_idx * 0x30);
        osWritebackDCache(head_base + 0xC8, ((s32) ((head - head_base) - 0xC8) >> 3) * 8);
        if ((D_801282E0.unk_E == 0) ||
            (func_800CAA24(func_800E42A8(), &D_80128390, &D_8012839C) != 0)) {
            func_800E46E0(gfx, D_801282E0.matrix_dl[D_801282E0.buf_idx]);
            func_800BCC90(gfx);
            geo_cmd = *gfx;
            *gfx = geo_cmd + 8;
            *(s32 *) (geo_cmd + 4) = 0;
            *(s32 *) geo_cmd = 0xD9FFF9FF;
            func_800E7FF8(gfx, 0x200);
            // Matching: empty blocks here and below are needed for the match.
            if (0) {
            }
            call_cmd = *gfx;
            *gfx = call_cmd + 8;
            *(s32 *) call_cmd = 0xDE000000;
            *(s32 *) (call_cmd + 4) =
                // Matching: the comma expression (0, ...) is needed for the match.
                (s32) ((s32) D_801282E0.dl_buf[D_801282E0.buf_idx] + (0, 0x80000000));
            func_800E4640(gfx);
            if ((&D_801282E0 && &D_801282E0) && &D_801282E0) {
            }
            geo_cmd2 = *gfx;
            *gfx = geo_cmd2 + 8;
            *(s32 *) (geo_cmd2 + 4) = 0;
            *(s32 *) geo_cmd2 = 0xD9FFF9FF;
            func_800E7FF8(gfx, 0x400);
            if (D_801282E0.model_id != 0) {
                model = func_800D674C(D_801282E0.model_id);
                if (D_801282E0.unk_F == 0) {
                    func_800B21CC(func_800B2840(model), &D_80128390, &D_8012839C);
                    D_801282E0.unk_F = (D_801282E0.unk_E = 1);
                }
                func_800DF440(0);
                func_800DF830(1);
                func_800DF410(D_801282E0.mode);
                func_800DE498(gfx, 0, 0, 0x3F800000, 0, model);
            }
            D_801282E0.reflecting = 1;
        }
        func_800E46E0(gfx, tail);
        if (gfx) {
        }
        call_cmd2 = *gfx;
        *gfx = call_cmd2 + 8;
        *(s32 *) call_cmd2 = 0xDE000000;
        *(s32 *) (call_cmd2 + 4) = (s32) ((s32) D_801282E0.dl_buf[D_801282E0.buf_idx] + 0x80000000);
        D_801282E0.buf_idx ^= 1;
    }
}

// Reflects a point with the mirror matrix.
int func_800BCC28(s32 point, s32 result)
{
    // Matching: the `| 0` operands are needed for the match.
    func_800F23D0((s32 *) D_801282F4, point | 0, result | 0);
}

// Returns whether the reflection is active.
int func_800BCC58()
{
    u8 *state = (int *) &D_801282E0;
    state += 0; // Matching: no-op add needed for the match.
    return state[0xD] && state[0x10];
}

u8 func_800BCC84()
{
    return D_801282ED;
}

// Appends the G_MTX command for the mirror matrix.
// Matching: the line breaks in this function are needed for the match.
void func_800BCC90(gfx) s32 * gfx;
{
    s32 cur = gfx[0];
    s32 *cmd;
    cmd = (s32 *) cur;
    gfx[0] += 8;
    *cmd = 0xDA380005U; cmd[1] = (s32) ((u8 *) &D_80128338 - 0x80000000);
}

// TU-NOTE: the .data of this file (formerly asm/data/core2/1E95F80.data.s) is defined here in C.
// Values are taken from the ROM.
LocalEntry D_8011A760[3] = {0x151, 0x861, 0xFF, 0x1, 0.0f,      0.0f, 0.0f, 0.0f,  1.0f, 0.0f,
                            0x103, 0x860, 0xFF, 0x0, 1.05e+03f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
                            0x15E, 0x857, 0xFF, 0x1, 0.0f,      0.0f, 0.0f, 0.0f,  1.0f, 0.0f};
