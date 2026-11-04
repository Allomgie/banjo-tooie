// Parser for the camera database section of a map's setup file: reads tagged records through
// the stream reader and stores them via the ca/dbfunc setters.
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

// Reads records until the end: tags 1/2 select node kind/index, 3-0x13 set node fields.
void func_80800000_cadbio(s32 file)
{
    f32 vec[3];
    f32 float_val;
    s16 short_val;
    s32 int_val;
    s32 index;
    s32 kind;

    // Matching: the empty if bodies below are needed for the match.
    while (!_gsmaker_entrypoint_16(file, 0)) {
        if (_gsmaker_entrypoint_21(file, 1, &kind)) {
        } else if (_gsmaker_entrypoint_21(file, 2, &index)) {
            func_800A58A8(kind, index);
        } else if (_gsmaker_entrypoint_20(file, 3, vec, 3)) {
            if (!_cadbfunc_entrypoint_1(vec)) {
            }
        } else if (_gsmaker_entrypoint_20(file, 4, vec, 3)) {
            if (!_cadbfunc_entrypoint_3(vec)) {
            }
        } else if (_gsmaker_entrypoint_20(file, 5, vec, 3)) {
            if (!_cadbfunc_entrypoint_5(vec)) {
            }
        } else if (_gsmaker_entrypoint_20(file, 6, vec, 2)) {
            if (!_cadbfunc_entrypoint_7(vec[0], vec[1])) {
            }
        } else if (_gsmaker_entrypoint_20(file, 7, vec, 2)) {
            if (!_cadbfunc_entrypoint_9(vec[0], vec[1])) {
            }
        } else if (_gsmaker_entrypoint_20(file, 8, &float_val, 1)) {
            if (!_cadbfunc_entrypoint_11(float_val)) {
            }
        } else if (_gsmaker_entrypoint_20(file, 9, &float_val, 1)) {
            if (!_cadbfunc_entrypoint_13(float_val)) {
            }
        } else if (_gsmaker_entrypoint_20(file, 0x11, &float_val, 1)) {
            if (!_cadbfunc_entrypoint_15(float_val)) {
            }
        } else if (_gsmaker_entrypoint_24(file, 0xA, &short_val)) {
            if (!_cadbfunc_entrypoint_17(short_val)) {
            }
        } else if (_gsmaker_entrypoint_19(file, 0xB, &float_val)) {
            if (!_cadbfunc_entrypoint_19(float_val)) {
            }
        } else if (_gsmaker_entrypoint_19(file, 0xC, &float_val)) {
            if (!_cadbfunc_entrypoint_21(float_val)) {
            }
        } else if (_gsmaker_entrypoint_21(file, 0xD, &int_val)) {
            if (!_cadbfunc_entrypoint_31(int_val)) {
            }
        } else if (_gsmaker_entrypoint_21(file, 0xE, &int_val)) {
            if (!_cadbfunc_entrypoint_23(int_val)) {
            }
        } else if (_gsmaker_entrypoint_21(file, 0xF, &int_val)) {
            if (!_cadbfunc_entrypoint_25(int_val)) {
            }
        } else if (_gsmaker_entrypoint_21(file, 0x10, &int_val)) {
            if (!_cadbfunc_entrypoint_27(int_val)) {
            }
        } else if (_gsmaker_entrypoint_20(file, 0x12, &float_val, 1)) {
            if (!_cadbfunc_entrypoint_33(float_val)) {
            }
        } else if (_gsmaker_entrypoint_21(file, 0x13, &int_val)) {
            _cadbfunc_entrypoint_35(int_val);
        }
    }
}

// Parses the camera database section; tag 0x14 is the node-data asset id (default 0x7D).
void cadbio_entrypoint_0(s32 file)
{
    s32 asset_id;

    func_800A5630();
    if (_gsmaker_entrypoint_21(file, 0x14, &asset_id) == 0) {
        asset_id = 0x7D;
    }
    func_800A5608(asset_id);
    if (_gsmaker_entrypoint_16(file, 0) == 0) {
        do {
            func_80800000_cadbio(file);
        } while (_gsmaker_entrypoint_16(file, 0) == 0);
    }
}
