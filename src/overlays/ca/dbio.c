#include "common.h"

extern s32 _gsmaker_entrypoint_16(s32, s32);
extern s32 _gsmaker_entrypoint_19(s32, s32, f32 *);
extern s32 _gsmaker_entrypoint_20(s32, s32, f32 *, s32);
extern s32 _gsmaker_entrypoint_21(s32, s32, s32 *);
extern s32 _gsmaker_entrypoint_24();
extern void func_800A58A8(s32, s32);
extern s32 _cadbfunc_entrypoint_1(f32 *);
extern s32 _cadbfunc_entrypoint_3(f32 *);
extern s32 _cadbfunc_entrypoint_5(f32 *);
extern s32 _cadbfunc_entrypoint_7(f32, f32);
extern s32 _cadbfunc_entrypoint_9(f32, f32);
extern s32 _cadbfunc_entrypoint_11(f32);
extern s32 _cadbfunc_entrypoint_13(f32);
extern s32 _cadbfunc_entrypoint_15(f32);
extern s32 _cadbfunc_entrypoint_17();
extern s32 _cadbfunc_entrypoint_19(f32);
extern s32 _cadbfunc_entrypoint_21(f32);
extern s32 _cadbfunc_entrypoint_23(s32);
extern s32 _cadbfunc_entrypoint_25(s32);
extern s32 _cadbfunc_entrypoint_27(s32);
extern s32 _cadbfunc_entrypoint_31(s32);
extern s32 _cadbfunc_entrypoint_33(f32);
extern s32 _cadbfunc_entrypoint_35(s32);

void func_80800000_cadbio(s32 file)
{
    f32 vec[3];
    f32 f;
    s16 h;
    s32 v;
    s32 b;
    s32 a;

    while (!_gsmaker_entrypoint_16(file, 0)) {
        if (_gsmaker_entrypoint_21(file, 1, &a)) {
        } else if (_gsmaker_entrypoint_21(file, 2, &b)) {
            func_800A58A8(a, b);
        } else if (_gsmaker_entrypoint_20(file, 3, vec, 3)) {
            if (!_cadbfunc_entrypoint_1(vec)) {}
        } else if (_gsmaker_entrypoint_20(file, 4, vec, 3)) {
            if (!_cadbfunc_entrypoint_3(vec)) {}
        } else if (_gsmaker_entrypoint_20(file, 5, vec, 3)) {
            if (!_cadbfunc_entrypoint_5(vec)) {}
        } else if (_gsmaker_entrypoint_20(file, 6, vec, 2)) {
            if (!_cadbfunc_entrypoint_7(vec[0], vec[1])) {}
        } else if (_gsmaker_entrypoint_20(file, 7, vec, 2)) {
            if (!_cadbfunc_entrypoint_9(vec[0], vec[1])) {}
        } else if (_gsmaker_entrypoint_20(file, 8, &f, 1)) {
            if (!_cadbfunc_entrypoint_11(f)) {}
        } else if (_gsmaker_entrypoint_20(file, 9, &f, 1)) {
            if (!_cadbfunc_entrypoint_13(f)) {}
        } else if (_gsmaker_entrypoint_20(file, 0x11, &f, 1)) {
            if (!_cadbfunc_entrypoint_15(f)) {}
        } else if (_gsmaker_entrypoint_24(file, 0xA, &h)) {
            if (!_cadbfunc_entrypoint_17(h)) {}
        } else if (_gsmaker_entrypoint_19(file, 0xB, &f)) {
            if (!_cadbfunc_entrypoint_19(f)) {}
        } else if (_gsmaker_entrypoint_19(file, 0xC, &f)) {
            if (!_cadbfunc_entrypoint_21(f)) {}
        } else if (_gsmaker_entrypoint_21(file, 0xD, &v)) {
            if (!_cadbfunc_entrypoint_31(v)) {}
        } else if (_gsmaker_entrypoint_21(file, 0xE, &v)) {
            if (!_cadbfunc_entrypoint_23(v)) {}
        } else if (_gsmaker_entrypoint_21(file, 0xF, &v)) {
            if (!_cadbfunc_entrypoint_25(v)) {}
        } else if (_gsmaker_entrypoint_21(file, 0x10, &v)) {
            if (!_cadbfunc_entrypoint_27(v)) {}
        } else if (_gsmaker_entrypoint_20(file, 0x12, &f, 1)) {
            if (!_cadbfunc_entrypoint_33(f)) {}
        } else if (_gsmaker_entrypoint_21(file, 0x13, &v)) {
            _cadbfunc_entrypoint_35(v);
        }
    }
}

void cadbio_entrypoint_0(s32 param_0) {
    s32 sp24;

    func_800A5630();
    if (_gsmaker_entrypoint_21(param_0, 0x14, &sp24) == 0) {
        sp24 = 0x7D;
    }
    func_800A5608(sp24);
    if (_gsmaker_entrypoint_16(param_0, 0) == 0) {
        do {
            func_80800000_cadbio(param_0);
        } while (_gsmaker_entrypoint_16(param_0, 0) == 0);
    }
}
