#include "common.h"

typedef struct { s16 origin[3]; u16 pad6[3]; u16 stride_y; u16 stride_z; } RtLightGrid32_80800000_rtlight;
typedef struct { u8 pad0[0x10]; u16 n; s16 size; s32 m; u16 cells[1][2]; } RtSrc;
typedef struct { u8 b[15]; s8 f; s16 min[3]; s16 max[3]; u16 unk1C; u16 unk1E; } RtCell_rtlight_entrypoint_1;
typedef struct { u8 pad0[6]; s16 idx; u8 col[3]; u8 padB; } RtLight_rtlight_entrypoint_1;
typedef struct { u8 pad0[0xC]; u8 col[3]; u8 padF; } RtTblEntry_rtlight_entrypoint_1;
typedef struct { RtSrc *src; s16 size; u16 n; f32 inv; RtCell_rtlight_entrypoint_1 cells[1]; } RtOut_rtlight_entrypoint_1;
extern void *heap_alloc(s32);
extern RtTblEntry_rtlight_entrypoint_1 *func_800B2190(s32);
typedef struct { s16 origin[3]; s16 max[3]; u16 stride_y; u16 stride_z; } RtLightGrid32_8080036C_rtlight;
typedef struct { u8 b[15]; s8 f; s16 min[3]; s16 max[3]; u16 unk1C; u16 unk1E; } RtCell_8080036C_rtlight;
typedef struct { RtLightGrid32_8080036C_rtlight *src; s16 size; u16 n; f32 inv; RtCell_8080036C_rtlight cells[1]; } RtOut_8080036C_rtlight;
typedef struct { RtCell_8080036C_rtlight *list[150]; RtCell_8080036C_rtlight **cur; } RtCellList;
extern RtCellList D_80135550;
extern void func_800C8898(s32, f32[3]);
typedef struct { u8 b[15]; s8 f; s16 min[3]; s16 max[3]; s16 unk1C; s16 unk1E; } RtCell_rtlight_entrypoint_2;
typedef struct { s16 s[3]; s16 idx; u8 col[3]; u8 padB; } RtLight_rtlight_entrypoint_2;
typedef struct { s16 pos[3]; u8 pad6[6]; u8 col[3]; u8 padF; } RtTblEntry_rtlight_entrypoint_2;
typedef struct { void *src; s16 size; s16 n; f32 inv; RtCell_rtlight_entrypoint_2 cells[1]; } RtOut_rtlight_entrypoint_2;
extern s32 func_800C8760(s32, s32);
extern s32 func_800C878C(s32, s32, s32);
extern void func_800C8800(s32, f32 *);
extern void func_800C883C(s32, f32 *);
extern s32 func_800E3DC0();
extern void func_800C8900(s32, s32 *);
extern f32 sqrtf(f32);

void func_80800000_rtlight(RtLightGrid32_80800000_rtlight *param_0, s32 param_1, s32 param_2[3])
{
    param_2[2] = param_1 / param_0->stride_z;
    param_2[1] = (param_1 % param_0->stride_z) / param_0->stride_y;
    param_2[0] = (param_1 % param_0->stride_z) % param_0->stride_y;
    param_2[0] += param_0->origin[0];
    param_2[1] += param_0->origin[1];
    param_2[2] += param_0->origin[2];
}

void rtlight_entrypoint_0(void* arg0) 
{
    heap_free(arg0);
}
RtOut_rtlight_entrypoint_1 *rtlight_entrypoint_1(RtSrc *src, s32 arg1, s32 arg2)
{
    RtOut_rtlight_entrypoint_1 *out;
    RtCell_rtlight_entrypoint_1 *c;
    RtLight_rtlight_entrypoint_1 *lend;
    RtCell_rtlight_entrypoint_1 *end;
    RtCell_rtlight_entrypoint_1 *first;
    u16 *sc;
    RtLight_rtlight_entrypoint_1 *l;
    RtTblEntry_rtlight_entrypoint_1 *tbl;
    s32 i;
    s32 n;
    s16 *si;
    RtTblEntry_rtlight_entrypoint_1 *ps;
    s32 pos[3];

    n = src->n;
    out = heap_alloc(n * 32 + src->m * 12 + 12);
    out->src = src;
    out->size = src->size;
    out->n = n;
    out->inv = 1.0f / src->size;
    sc = src->cells[0];
    first = out->cells;
    end = (RtCell_rtlight_entrypoint_1 *)((n << 5) + (u8 *)out + 12);
    for (c = first; c < end; c++, sc += 2) {
        if (sc[1] == 0) {
            c->f = -1;
            continue;
        }
        for (i = 0; i < 15; i++) {
            c->b[i] = 0;
        }
        func_80800000_rtlight(out->src, c - first, pos);
        for (i = 0; i < 3; i++) {
            c->min[i] = pos[i] * src->size - 20;
            c->max[i] = (pos[i] + 1) * src->size + 20;
        }
        c->unk1C = sc[0];
        c->unk1E = sc[1];
        c->f = 0;
    }
    l = (RtLight_rtlight_entrypoint_1 *)c;
    lend = l + src->m;
    si = (s16 *)sc;
    tbl = func_800B2190(arg1);
    for (; l < lend; l++, si++) {
        l->idx = *si;
        ps = &tbl[*si];
        for (i = 0; i < 3; i++) {
            l->col[i] = ps->col[i];
        }
    }
    return out;
}

void func_8080036C_rtlight(RtOut_8080036C_rtlight *grid, f32 *pos, f32 r, RtCell_8080036C_rtlight ***outList, RtCell_8080036C_rtlight ***outEnd)
{
    s32 lo[3];
    s32 hi[3];
    RtLightGrid32_8080036C_rtlight *src;
    RtCell_8080036C_rtlight *c;
    f32 p;
    f32 a0f;
    f32 b0f;
    s32 a;
    s32 b;
    s32 i;
    s32 x;
    s32 y;
    s32 z;
    s32 o;
    s32 m;

    src = grid->src;
    for (i = 0; i < 3; i++) {
        a0f = pos[i] - r;
        b0f = pos[i] + r;
        a = grid->inv * a0f;
        b = grid->inv * b0f;
        if (a0f < 0.0f) {
            a--;
        }
        if (b0f < 0.0f) {
            b--;
        }
        o = src->origin[i];
        m = src->max[i];
        if (a < o) {
            a = o;
        }
        if (m < a) {
            a = m;
        }
        if (b < o) {
            b = o;
        }
        if (m < b) {
            b = m;
        }
        lo[i] = a - o;
        hi[i] = b - o;
    }
    D_80135550.cur = D_80135550.list;
    for (z = lo[2]; z <= hi[2]; z++) {
        for (y = lo[1]; y <= hi[1]; y++) {
            for (x = lo[0]; x <= hi[0]; x++) {
                c = (RtCell_8080036C_rtlight *)(((src->stride_z * z) << 5) + (u8 *)grid + (x << 5) + ((y * src->stride_y) << 5) + 12);
                if (c->f >= 0 && D_80135550.cur < &D_80135550.list[150]) {
                    *D_80135550.cur = c;
                    D_80135550.cur++;
                }
            }
        }
    }
    *outList = D_80135550.list;
    *outEnd = D_80135550.cur;
}

void func_80800544_rtlight(s32 param_0, s32 *param_1)
{
  f32 local_0[3];
  func_800C8800(param_0, local_0);
  param_1[0] = local_0[0];
  param_1[1] = local_0[1];
  param_1[2] = local_0[2];
}

void func_808005AC_rtlight(s32 param_0, s32 *param_1)
{
    f32 local_0[3];

    func_800C8898(param_0, local_0);
    param_1[0] = (s32)(local_0[0] * 256.0f);
    param_1[1] = (s32)(local_0[1] * local_0[1]);
    param_1[2] = (s32)(local_0[2] * 16384.0f);
}

void rtlight_entrypoint_2(RtOut_rtlight_entrypoint_2 *grid, s32 arg1, s32 arg2, s32 flag)
{
    s32 h;
    s32 k;
    RtCell_rtlight_entrypoint_2 *c;
    RtCell_rtlight_entrypoint_2 *end;
    s32 pad[2];
    f32 pos[3];
    f32 range[2];
    RtCell_rtlight_entrypoint_2 **list;
    RtCell_rtlight_entrypoint_2 **listEnd;
    s32 dx;
    s32 dy;
    s32 dz;
    RtTblEntry_rtlight_entrypoint_2 *e1;
    RtTblEntry_rtlight_entrypoint_2 *e2;
    RtTblEntry_rtlight_entrypoint_2 *e3;
    s32 t;
    s32 lpos[3];
    s32 r[3];
    s32 col[3];
    s32 j;
    RtTblEntry_rtlight_entrypoint_2 *tbl;
    RtLight_rtlight_entrypoint_2 *l;
    RtLight_rtlight_entrypoint_2 *lend;
    RtLight_rtlight_entrypoint_2 *p;
    u8 *pb;
    s32 d2;
    s32 d;
    s32 s;
    s32 v;

    end = (RtCell_rtlight_entrypoint_2 *)((grid->n << 5) + (u8 *)grid + 12);
    for (h = func_800C8760(2, 2); h != 0; h = func_800C878C(h, 2, 2)) {
        for (c = grid->cells; c < end; c++) {
            if (c->f < 0) {
                continue;
            }
            for (j = 0; j < 15; j++) {
                if (c->b[j] == h) {
                    c->b[j] = 0;
                    c->f = flag;
                    break;
                }
            }
        }
        func_800C8800(h, pos);
        func_800C883C(h, range);
        func_8080036C_rtlight(grid, pos, range[1], &list, &listEnd);
        for (; list < listEnd; list++) {
            for (d2 = 0; d2 < 15; d2++) {
                if ((*list)->b[d2] == 0) {
                    (*list)->b[d2] = h;
                    (*list)->f = flag;
                    break;
                }
            }
        }
    }
    c = grid->cells;
    tbl = func_800B2190(arg1);
    for (; c < end; c++) {
        if (c->f <= 0) {
            continue;
        }
        if (!func_800E3DC0(c->min, c->max)) {
            continue;
        }
        k = 0;
        pb = c->b;
        for (; k < 15; k++, pb++) {
            if (*pb != 0) {
                break;
            }
        }
        l = c->unk1C + (RtLight_rtlight_entrypoint_2 *)end;
        lend = l + c->unk1E;
        if (k == 15) {
            for (; l < lend; l++) {
                e1 = &tbl[l->idx];
                e1->col[0] = l->col[0];
                e1->col[1] = l->col[1];
                e1->col[2] = l->col[2];
            }
        } else {
            for (p = l; p < lend; p++) {
                p->s[0] = p->col[0];
                p->s[1] = p->col[1];
                p->s[2] = p->col[2];
            }
            for (; k < 15; k++, pb++) {
                if (!*pb) {
                    continue;
                }
                func_80800544_rtlight(*pb, lpos);
                func_808005AC_rtlight(*pb, r);
                func_800C8900(*pb, col);
                for (p = l; p < lend; p++) {
                    e2 = &tbl[p->idx];
                    dx = lpos[0] - e2->pos[0];
                    dy = lpos[1] - e2->pos[1];
                    dz = lpos[2] - e2->pos[2];
                    d2 = dx * dx + dy * dy + dz * dz;
                    d = d2;
                    if (d2 < r[1]) {
                        if (d2 != 0) {
                            d = sqrtf(d2) * 256.0f;
                        }
                        if (r[0] < d) {
                            t = 0x4000 - (((d - r[0]) * r[2]) >> 8);
                            s = t << 2;
                        } else {
                            s = 0x10000;
                        }
                        p->s[0] += (col[0] * s) >> 16;
                        p->s[1] += (col[1] * s) >> 16;
                        p->s[2] += (col[2] * s) >> 16;
                    }
                }
            }
            for (; l < lend; l++) {
                e3 = &tbl[l->idx];
                v = l->s[0];
                if (v >= 0x100) {
                    v = 0xFF;
                }
                e3->col[0] = v;
                v = l->s[1];
                if (v >= 0x100) {
                    v = 0xFF;
                }
                e3->col[1] = v;
                v = l->s[2];
                if (v >= 0x100) {
                    v = 0xFF;
                }
                e3->col[2] = v;
            }
        }
        c->f--;
    }
}
