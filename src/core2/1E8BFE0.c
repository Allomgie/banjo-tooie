#include "common.h"

// Model header accessors.

// Model base + section offset at +0x28, or 0 if absent.
s32 func_800B26F0(s32 model)
{
    s32 offset = *(s32 *) (model + 0x28);
    if (offset == 0) {
        return 0;
    }
    return model + offset;
}

// Returns the s16 field at +0xA.
func_800B270C(s16 *model)
{
    return model[5];
}

// Model base + section offset at +0xC (no zero check).
s32 func_800B2714(s32 model)
{
    s32 offset_copy;
    s32 offset;
    // Matching: the 64-bit mask and the extra copy are needed for the match.
    offset = *(s32 *) (model + 0xc) & 0xFFFFFFFFFFFFFFFF;
    offset_copy = offset;
    return model + offset_copy;
}

// Model base + section offset at +0x1C, or 0 if absent.
s32 func_800B2720(s32 model)
{
    s32 offset;
    if (model == 0) {
        return 0;
    }
    offset = *(s32 *) (model + 0x1C);
    if (offset == 0) {
        return 0;
    }
    return model + offset;
}

// Model base + section offset at +0x24, or 0 if absent.
func_800B274C(model)
{
    s32 offset = *(s32 *) (model + 0x24);
    if (offset == 0) {
        return 0;
    }
    return model + offset;
}

// Model base + section offset at +0x40, or 0 if absent.
func_800B2768(model)
{
    s32 offset = *(s32 *) (model + 0x40);
    if (offset == 0) {
        return 0;
    }
    return model + offset;
}

// Model base + section offset at +0x3C, or 0 if absent.
func_800B2784(model)
{
    s32 offset = *(s32 *) (model + 0x3c);
    if (offset == 0) {
        return 0;
    }
    return model + offset;
}

// Model base + section offset at +0x38, or 0 if absent.
func_800B27A0(model)
{
    s32 offset = *(s32 *) (model + 0x38);
    if (offset == 0) {
        return 0;
    }
    return model + offset;
}

// Model base + section offset at +0x30, or 0 if absent.
func_800B27BC(model)
{
    s32 offset = *(s32 *) (model + 0x30);
    if (offset == 0) {
        return 0;
    }
    return model + offset;
}

// Returns the f32 field at +0x48.
f32 func_800B27D8(f32 *model)
{
    return model[18];
}

// Model base + section offset at +0x18, or 0 if absent.
func_800B27E0(model)
{
    s32 offset = *(s32 *) (model + 0x18);
    if (offset == 0) {
        return 0;
    }
    return model + offset;
}

// Model base + s16 offset at +0x8 (no zero check).
int func_800B27FC(s32 model)
{
    s16 *offset_ptr;
    offset_ptr = (s16 *) ((int) model + 0x8);
    // Matching: the comma expression is needed for the match.
    return *offset_ptr + (0, model);
}

// Model base + section offset at +0x2C, or 0 if absent.
func_800B2808(s32 model)
{
    s32 offset;
    offset = *(s32 *) (model + 0x2C);
    if (offset == 0) {
        return 0;
    }
    return model + offset;
}

// Model base + section offset at +0x14, or 0 if absent.
s32 func_800B2824(Actor *this)
{
    if (this->unk14 == 0)
        return 0;
    return (Actor *) ((s32) this + this->unk14);
}

// Model base + section offset at +0x10 (vertex list; no zero check).
s32 func_800B2840(s32 model)
{
    s32 base;
    base = model;
    // Matching: volatile read and ^ (0, 0) are needed for the match.
    return (base + *(volatile s32 *) (base + 0x10)) ^ (0, 0);
}

// Model base + section offset at +0x20, or 0 if absent.
s32 func_800B284C(s32 *model)
{
    s32 offset = model[8];
    return offset == 0 ? 0 : (s32) model + offset;
}

// Model base + section offset at +0x34, or 0 if absent.
func_800B2868(s32 model)
{
    s32 offset;
    offset = *(s32 *) (model + 0x34);
    if (offset == 0) {
        return 0;
    }
    return model + offset;
}
