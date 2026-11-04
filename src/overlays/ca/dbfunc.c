// Typed field accessors for the current camera-database node: a private resolver per field plus
// get/set entrypoints, returning 0 when the node kind lacks the field.
#include "common.h"

extern void func_800EE7F8(s32, s32);

// Camera node fields. Each func_*_cadbfunc resolver returns the field address in the
// current node (kind from func_800A587C, data from func_800A586C), or 0 when the kind
// lacks the field. Even entrypoints get the field, odd ones set it (0 = missing).

s32 func_80800000_cadbfunc()
{
    s32 kind;

    kind = func_800A587C();
    switch (kind) {
        case 3:
            return func_800A586C();
        case 1:
            return func_800A586C();
        case 2:
            return func_800A586C();
        case 5:
            return func_800A586C();
        case 6:
            return func_800A586C();
        case 8:
            return func_800A586C();
        default:
            return 0;
    }
}

s32 cadbfunc_entrypoint_0(s32 out)
{
    s32 field = func_80800000_cadbfunc(out);
    if (field == 0) {
        return 0;
    }
    func_800EE7F8(out, field);
    return 1;
}

int cadbfunc_entrypoint_1(s32 value)
{
    s32 field;
    field = func_80800000_cadbfunc();
    if (!field)
        return 0;
    // Matching: the `| 0` is needed for the match.
    func_800EE7F8(field | 0, value);
    return 1;
}

int func_80800120_cadbfunc()
{
    switch (func_800A587C()) {
        case 2:
            return func_800A586C() + 0xc;
        case 5:
            return func_800A586C() + 0xc;
        case 6:
            return func_800A586C() + 0xc;
        case 8:
            return func_800A586C() + 0xc;
        default:
            return 0;
    }
}

int cadbfunc_entrypoint_2(Actor *out)
{
    s32 field;
    field = func_80800120_cadbfunc();
    if (!field) {
        return 0;
    }
    // Matching: the extra block is needed for the match.
    {
        func_800EE7F8(out, field);
        return 1;
    }
}

s32 cadbfunc_entrypoint_3(s32 value)
{
    s32 field;

    field = func_80800120_cadbfunc();
    if (field == 0) {
        return 0;
    }
    func_800EE7F8(field, value);
    return 1;
}

int func_80800224_cadbfunc()
{
    switch (func_800A587C()) {
        case 1:
            return func_800A586C() + 0x1C;
        case 3:
            return func_800A586C() + 0x24;
        default:
            return 0;
    }
}

s32 cadbfunc_entrypoint_4(s32 out)
{
    s32 field;

    field = func_80800224_cadbfunc();
    if (field == 0) {
        return 0;
    }
    // Matching: the `| 0` is needed for the match.
    func_800EE7F8(out, field | 0);
    return 1;
}

int cadbfunc_entrypoint_5(s32 value)
{
    s32 field;
    field = func_80800224_cadbfunc();
    if (!field) {
        return 0;
    }
    // Matching: the `| 0` is needed for the match.
    func_800EE7F8(field | 0, value);
    return 1;
}

int func_808002F8_cadbfunc()
{
    switch (func_800A587C()) {
        case 1:
            return func_800A586C() + 0xC;

        case 3:
            return func_800A586C() + 0xC;

        default:
            return 0;
    }
}

int cadbfunc_entrypoint_6(f32 *out_first, f32 *out_second)
{
    s32 field;
    f32 *values;
    field = func_808002F8_cadbfunc();
    if (!field)
        return 0;
    // Matching: the pointer copy is needed for the match.
    values = field;
    out_first[0] = values[0];
    out_second[0] = values[1];
    return 1;
}

s32 cadbfunc_entrypoint_7(f32 first, f32 second)
{
    s32 *field;

    field = func_808002F8_cadbfunc();
    if (field == 0) {
        return 0;
    }
    *(f32 *) field = first;
    *(f32 *) (field + 1) = second;
    return 1;
}

int func_808003EC_cadbfunc()
{
    switch (func_800A587C()) {
        case 1:
            return func_800A586C() + 0x14;

        case 3:
            return func_800A586C() + 0x14;

        default:
            return 0;
    }
}

s32 cadbfunc_entrypoint_8(f32 out_first[3], f32 out_second[3])
{
    f32 *field = func_808003EC_cadbfunc(out_first);

    if (!field) {
        return 0;
    }

    out_first[0] = field[0];
    out_second[0] = field[1];
    return 1;
}

int cadbfunc_entrypoint_9(f32 first, f32 second)
{
    s32 ok;
    f32 *field = func_808003EC_cadbfunc();
    if (!field) {
        return 0;
    }
    ok = 1;
    field[0] = first;
    field[1] = second;
    return ok;
}

int func_808004E0_cadbfunc()
{
    switch (func_800A587C()) {
        case 5:
            return func_800A586C() + 0x18;

        case 6:
            return func_800A586C() + 0x1C;
    }

    return 0;
}

s32 cadbfunc_entrypoint_10(s32 out)
{
    f32 *field = func_808004E0_cadbfunc(out);
    if (field == 0) {
        return 0;
    }
    *(f32 *) out = *field;
    return 1;
}

s32 cadbfunc_entrypoint_11(f32 value)
{
    f32 *field = func_808004E0_cadbfunc();
    if (field == 0) {
        return 0;
    }
    *field = value;
    return 1;
}

int func_808005B8_cadbfunc()
{
    switch (func_800A587C()) {
        case 5:
            return func_800A586C() + 0x1C;

        case 6:
            return func_800A586C() + 0x20;

        case 8:
            return func_800A586C() + 0x1C;
    }

    return 0;
}

s32 cadbfunc_entrypoint_12(void *out)
{
    void *field;

    field = func_808005B8_cadbfunc();
    if (field == 0) {
        return 0;
    }
    *(f32 *) out = *(f32 *) field;
    return 1;
}

s32 cadbfunc_entrypoint_13(f32 value)
{
    f32 copy;
    f32 *field;

    field = (f32 *) func_808005B8_cadbfunc();
    if (field == 0) {
        return 0;
    }
    // Matching: the copy is needed for the match.
    copy = value;
    *field = copy;
    return 1;
}

int func_808006A8_cadbfunc()
{
    switch (func_800A587C()) {
        case 5:
            return func_800A586C() + 0x20;

        case 6:
            return func_800A586C() + 0x24;

        case 8:
            return func_800A586C() + 0x20;
    }
    return 0;
}

int cadbfunc_entrypoint_14(f32 out[3])
{
    f32 *field;
    field = func_808006A8_cadbfunc();
    if (!field) {
        return 0;
    }
    out[0] = field[0];
    return 1;
}

int cadbfunc_entrypoint_15(f32 value)
{
    s32 ok;
    f32 *field = func_808006A8_cadbfunc();
    if (!field) {
        return 0;
    }
    // Matching: the extra block is needed for the match.
    {
        ok = 1;
    }
    *field = value;
    return ok;
}

int func_80800798_cadbfunc()
{
    switch (func_800A587C()) {
        case 5:
            return func_800A586C() + 0x28;

        case 6:
            return func_800A586C() + 0x30;

        case 8:
            return func_800A586C() + 0x2C;
    }
    return 0;
}

s32 cadbfunc_entrypoint_16(void *out)
{
    void *field;
    void *src;

    field = func_80800798_cadbfunc();
    if (field == 0) {
        return 0;
    }
    // Matching: the pointer copy is needed for the match.
    src = field;
    *(s16 *) out = *(s16 *) src;
    return 1;
}

int cadbfunc_entrypoint_17(value)
s16 value;
{
    s16 *field;
    field = func_80800798_cadbfunc();
    if (!field) {
        return 0;
    }
    // Matching: the extra block is needed for the match.
    {
        *field = value;
        return 1;
    }
}

int func_80800888_cadbfunc()
{
    s32 result;
    switch (func_800A587C()) {
        case 3:
            return func_800A586C() + 0x1C;

        case 6:
            return func_800A586C() + 0x18;

        default:
            result = 0;
    }

    return result;
}

int cadbfunc_entrypoint_18(f32 *out)
{
    s32 field;
    field = func_80800888_cadbfunc();
    if (field == 0) {
        return 0;
    }
    out[0] = *(f32 *) field;
    return 1;
}

int cadbfunc_entrypoint_19(f32 value)
{
    // Matching: the temporary and the extra block are needed for the match.
    int is_null;
    s32 ok;
    f32 *field = func_80800888_cadbfunc();
    is_null = !field;
    if (is_null) {
        return 0;
    }
    {
        ok = 1;
        *field = value;
        return ok;
    }
}

int func_80800960_cadbfunc()
{
    s32 result;
    if (func_800A587C() == 3) {
        return func_800A586C() + 0x20;
    }
    result = 0;
    return result;
}

int cadbfunc_entrypoint_20(f32 out[3])
{
    f32 *field;
    field = func_80800960_cadbfunc();
    if (!field) {
        return 0;
    }
    out[0] = field[0];
    return 1;
}

s32 cadbfunc_entrypoint_21(f32 value)
{
    s32 *field;

    field = func_80800960_cadbfunc();
    if (field == 0) {
        return 0;
    }
    *(f32 *) field = value;
    return 1;
}

s32 func_80800A1C_cadbfunc(void)
{
    // Matching: the temporary is needed for the match.
    int is_kind_4;
    s32 result;
    result = func_800A587C();
    is_kind_4 = result == 4;
    if (is_kind_4) {
        result = func_800A586C();
    } else {
        result = 0;
        return result;
    }
}

s32 cadbfunc_entrypoint_22(void *out)
{
    void *field;
    void *src;

    field = func_80800A1C_cadbfunc();
    if (field == 0) {
        return 0;
    }
    // Matching: the pointer copy is needed for the match.
    src = field;
    *(void **) out = *(void **) src;
    return 1;
}

s32 cadbfunc_entrypoint_23(s32 value)
{
    s32 *field;

    field = func_80800A1C_cadbfunc();
    if (field == 0) {
        return 0;
    }
    *field = value;
    return 1;
}

int func_80800AD8_cadbfunc()
{
    switch (func_800A587C()) {
        case 4:
            return func_800A586C() + 8;
        case 6:
            return func_800A586C() + 0x2C;
        case 7:
            return func_800A586C();
        case 8:
            return func_800A586C() + 0x28;
        default:
            return 0;
    }
}

s32 cadbfunc_entrypoint_24(void *out)
{
    void *field;
    void *src;

    field = func_80800AD8_cadbfunc();
    if (field == 0) {
        return 0;
    }
    // Matching: the pointer copy is needed for the match.
    src = field;
    *(void **) out = *(void **) src;
    return 1;
}

int cadbfunc_entrypoint_25(s32 value)
{
    s32 *field;
    field = (s32 *) func_80800AD8_cadbfunc();
    if (!field) {
        return 0;
    }
    // Matching: the extra block is needed for the match.
    {
        *field = value;
        return 1;
    }
}

int func_80800BE0_cadbfunc()
{
    s32 result;
    if (func_800A587C() == 4) {
        return func_800A586C() + 0xC;
    }
    result = 0;
    return result;
}

s32 cadbfunc_entrypoint_26(void *out)
{
    void *field;
    void *src;

    field = func_80800BE0_cadbfunc();
    if (field == 0) {
        return 0;
    }
    // Matching: the pointer copy is needed for the match.
    src = field;
    *(void **) out = *(void **) src;
    return 1;
}

s32 cadbfunc_entrypoint_27(s32 value)
{
    s32 *field;

    field = func_80800BE0_cadbfunc();
    if (field == 0) {
        return 0;
    }
    *field = value;
    return 1;
}

s32 func_80800C9C_cadbfunc(void)
{
    s32 kind;

    kind = func_800A587C();
    switch (kind) {
        case 4:
            return func_800A586C() + 4;
        case 3:
            return func_800A586C() + 0x30;
        case 1:
            return func_800A586C() + 0x28;
        case 5:
            return func_800A586C() + 0x24;
        case 6:
            return func_800A586C() + 0x28;
        case 8:
            return func_800A586C() + 0x24;
        default:
            return 0;
    }
}

// Sets (set != 0) or clears the mask bits in the flags field.
int cadbfunc_entrypoint_28(s32 mask, s32 set)
{
    s32 addr;
    s32 *flags;
    addr = func_80800C9C_cadbfunc();
    if (!addr) {
        return 0;
    }
    // Matching: the pointer copy is needed for the match.
    flags = addr;
    if (set != 0) {
        *flags |= mask;
    } else {
        *flags &= ~mask;
    }
    return 1;
}

// Tests whether any mask bit is set in the flags field.
s32 cadbfunc_entrypoint_29(u32 mask, s32 *out_set)
{
    u32 *flags;

    flags = func_80800C9C_cadbfunc();
    if (flags == NULL) {
        return 0;
    }
    if (flags[0] & mask) {
        *out_set = 1;
    } else {
        *out_set = 0;
    }
    return 1;
}

s32 cadbfunc_entrypoint_30(void *out)
{
    void *field;
    void *src;

    field = func_80800C9C_cadbfunc();
    if (field == 0) {
        return 0;
    }
    // Matching: the pointer copy is needed for the match.
    src = field;
    *(void **) out = *(void **) src;
    return 1;
}

s32 cadbfunc_entrypoint_31(s32 value)
{
    s32 *field;

    field = func_80800C9C_cadbfunc();
    if (field == 0) {
        return 0;
    }
    *field = value;
    return 1;
}

int func_80800E80_cadbfunc()
{
    s32 result;
    if (func_800A587C() == 4) {
        return func_800A586C() + 0x10;
    }
    result = 0;
    return result;
}

s32 cadbfunc_entrypoint_32(f32 *out)
{
    s32 *field = func_80800E80_cadbfunc();
    if (!field) {
        return 0;
    }
    *out = *(f32 *) field;
    return 1;
}

s32 cadbfunc_entrypoint_33(f32 value)
{
    s32 *field;

    field = func_80800E80_cadbfunc();
    if (field == 0) {
        return 0;
    }
    *(f32 *) field = value;
    return 1;
}

int func_80800F3C_cadbfunc()
{
    s32 result;
    if (func_800A587C() == 4) {
        return func_800A586C() + 0x14;
    }
    result = 0;
    return result;
}

s32 cadbfunc_entrypoint_34(void *out)
{
    void *field;
    void *src;

    field = func_80800F3C_cadbfunc();
    if (field == 0) {
        return 0;
    }
    // Matching: the pointer copy is needed for the match.
    src = field;
    *(void **) out = *(void **) src;
    return 1;
}

int cadbfunc_entrypoint_35(s32 value)
{
    int *field = func_80800F3C_cadbfunc();
    if (field == NULL) {
        return 0;
    }
    *field = value;
    return 1;
}
