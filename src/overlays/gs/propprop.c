// Static prop rendering: sprite animation frames, prop radius from model or sprite size and scale,
// and drawing a prop as model or sprite with tint, scale and flags.
#include "common.h"

// Sprite asset header (animation info only)
typedef struct {
    s16 frame_count;
    u8 pad_2[0xE];
    u32 time_div : 4;
    u32 mode : 3;
    u32 unk_10_24 : 2;
    u32 unk_10_22 : 2;
    u32 rest : 21;
} GsSprite;
// Prop fields touched by the sprite animation
typedef struct {
    u8 pad_0[3];
    u8 pad_3_7 : 6;
    u8 is_mirrored : 1;
    u8 pad_3_0 : 1;
    u8 pad_4[6];
    u16 frame : 5;
    u16 pad_lo : 11;
} GsSpriteProp;
typedef struct {
    u8 pad_0[8];
    u32 pad_8_hi : 26;
    u32 unk_8_5 : 1;
    u32 pad_8_lo : 5;
} GsSpriteProp2;
extern GsSprite *func_800EC3E8(s32);
extern s32 _gsproplookup_entrypoint_1();
extern GsSprite *func_800BFC94(s32);
extern s32 func_8001211C();
typedef struct {
    u32 pad_0 : 22;
    u32 sprite_scale : 8; // percent
    u32 pad_1 : 2;
    u32 pad_4;
    u32 pad_8 : 16;
    u32 model_scale : 8; // percent
    u32 pad_8b : 6;
    u32 is_model : 1;
    u32 pad_8c : 1;
} PropPropertyScale;
extern void func_800BFAD0(s32, f32 *, f32 *, f32, void *);
extern void func_800BFB58(s32, f32 *, f32, void *, s32, s32, s32, s32, s32);

void gspropprop_entrypoint_0(s16 src[3], s32 *out)
{
    unsigned char idx;
    out[0] = *(s16 *) ((s8 *) src + 4);
    // Matching: index assigned inside the subscript.
    out[idx = 1] = *(s16 *) ((s8 *) src + 6);
    out[2] = src[4];
}

f32 func_8080001C_gspropprop()
{
    return (f32) func_800B0CFC(func_800BFC94(_gsproplookup_entrypoint_1()));
}

f32 func_80800050_gspropprop()
{
    func_800B2354(func_800B2840(func_800BFC34(_gsproplookup_entrypoint_0())));
}

// Prop radius: half the model/sprite extent times the prop's percent scale
f32 gspropprop_entrypoint_1(PropPropertyScale *prop)
{
    if (prop->is_model)
        return func_80800050_gspropprop(prop) * 0.5f * prop->model_scale * 0.01f;
    return func_8080001C_gspropprop(prop) * 0.5f * prop->sprite_scale * 0.01f;
}

// Advance the prop's sprite frame from the global timer, per the sprite's animation mode
void gspropprop_entrypoint_2(u8 *prop)
{
    GsSprite *sprite;
    s32 time_div;
    s32 mode;
    s32 unk_0;
    s32 unk_1;
    s32 frame_count;
    s32 unk_2;
    s32 cycle_len;
    s32 start_offset;
    s32 unk_3;
    s32 frame;

    sprite = ((u32) ((u16 *) prop)[5] & 1) ? func_800EC3E8(*(s32 *) prop)
                                           : func_800BFC94(_gsproplookup_entrypoint_1(prop));
    if ((sprite != NULL) && (sprite->mode != 0)) {
        time_div = sprite->time_div;
        mode = sprite->mode;
        unk_0 = sprite->unk_10_24;
        unk_1 = sprite->unk_10_22;
        frame_count = sprite->frame_count;
        unk_2 = (mode == 1) || (mode == 2U);
        cycle_len = (mode == 3) ? frame_count : (frame_count - unk_2) * 2;

        start_offset = (s32) ((((u32) ((u16 *) prop)[5] << 0x15) >> 0x1B) * cycle_len) / 32;
        frame = (((func_8001211C(unk_2, cycle_len, prop, unk_0) % (cycle_len * time_div)) / time_div) + start_offset) % cycle_len;
        unk_3 = 0;
        switch (unk_0) {
            default:
                unk_0 = 0;
                break;
            case 1:
                unk_0 = ((((u32) ((u16 *) prop)[5] << 0x15) >> 0x1B) & 2) ? 1 : 0;
                break;
            case 2:
                unk_0 = 1;
                break;
            case 3:
                unk_0 = (((u32) ((u16 *) prop)[1] << 0x1e) >> 0x1f);
        }

        switch (mode) {
            case 4:
                unk_3 = frame_count <= frame;
            case 1:
                unk_1 = frame_count <= frame;
                break;
            case 2:
                unk_3 = frame_count <= frame;
            default:
                switch (unk_1) {
                    case 1:
                        unk_1 = ((((u32) ((u16 *) prop)[5] << 0x15) >> 0x1b) & 1) ? 1 : 0;
                        break;
                    case 2:
                        unk_1 = 1;
                        break;
                    default:
                        if ((u32) ((u16 *) prop)[5] & 1) {
                            unk_1 = (((u32) ((u32 *) prop)[2] << 0x1a) >> 0x1f);
                        } else {
                            unk_1 = (((u32) ((u16 *) prop)[1] << 0x1e) >> 0x1f);
                        }
                        // Matching: empty statement needed for the match.
                        if (1)
                            ;
                        break;
                }
        }

        if ((unk_1 ^ unk_0 ^ unk_3)) {
            frame = cycle_len - frame;
        }

        frame += unk_2 ? unk_0 : -unk_0;
        frame = (frame < 0) ? frame + frame_count : frame % frame_count;
        ((GsSpriteProp *) prop)->frame = frame;
        if (((u32) ((u16 *) prop)[5] & 1)) {
            ((GsSpriteProp2 *) prop)->unk_8_5 = unk_1;
        } else {
            ((GsSpriteProp *) prop)->is_mirrored = unk_1;
        }
    }
}

// Draw a static prop as a model or a sprite
void gspropprop_entrypoint_3(u8 *prop, s32 arg1)
{
    f32 pos[3];
    f32 rot[3];
    void *model;
    func_800EE88C(pos, prop + 4);
    if ((*(u32 *) (prop + 8) << 30) >> 31) {
        model = (void *) _gsproplookup_entrypoint_0(prop);
        rot[0] = 0.0f;
        rot[1] = 2.0f * (f32) (u32) prop[2];
        rot[2] = 2.0f * (f32) (u32) prop[3];
        func_800BFAD0(arg1, pos, rot, (f32) (u32) prop[10] * 0.01f, model);
    } else {
        func_800BFB58(arg1, pos, (f32) ((*(u32 *) prop << 22) >> 24) * 0.01f,
                      (void *) _gsproplookup_entrypoint_1(prop), *(u16 *) prop & 7,
                      (u32) *(u16 *) (prop + 2) >> 13, (*(u32 *) prop << 19) >> 29,
                      (*(u32 *) prop << 30) >> 31, (u32) *(u16 *) (prop + 10) >> 11);
    }
}
