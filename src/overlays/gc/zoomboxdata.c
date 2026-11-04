// Zoombox portrait and voice table: per portrait a sprite asset, layout bytes and voice points,
// with getters and a function that plays a random voice blip (or a jingle) for a portrait.
#include "common.h"

// Voice point: sfx id (or music track when pitch == -1), volume/range, pitch.
typedef struct {
    s16 sound_id;
    s16 volume;
    f32 pitch;
} ZoomPt;
// Portrait table entry, indexed by portrait id.
typedef struct {
    u16 asset_id;
    s8 layout_0;
    s8 layout_1;
    ZoomPt *pts;
    u8 count;
    u8 pad_0[3];
} ZoomEntry;
typedef ZoomEntry ZoomEntry2;
typedef ZoomEntry ZoomBox;
extern ZoomEntry D_80800AA8_gczoomboxdata[];
extern int D_80800AB0_gczoomboxdata[];
extern s32 func_800D58FC(s32);
extern u8 func_800C2E04(void);
extern void func_800C301C(u8, s32);
extern int func_800C3058(u8, unsigned int);
extern void func_800C330C(u8, s32);
extern void func_800C3418(u8, s32);
extern void func_800C34CC(u8, s32);
extern void func_800C3BDC(u8);
extern f32 func_800DC264(f32, f32);
extern void func_800C31DC(u8, f32);
extern void func_800C3A40(u8, f32, f32, f32);

// Plays a random voice blip for the portrait, or a jingle when pitch == -1.
void gczoomboxdata_entrypoint_0(s32 portrait_id)
{
    s32 idx;
    f32 pitch;
    f32 pitch_down = 0.2f;
    s32 volume;
    s32 unk_0 = 6000;
    s32 unk_1 = 0;
    f32 pitch_up = 0.0f;
    f32 pitch_min;
    f32 pitch_max;
    u8 source;

    if (D_80800AA8_gczoomboxdata[portrait_id].pts && D_80800AA8_gczoomboxdata[portrait_id].count) {
        if (D_80800AA8_gczoomboxdata[portrait_id].pts[0].pitch == -1.0f) {
            if (!func_800FCCD4(D_80800AA8_gczoomboxdata[portrait_id].pts[0].sound_id))
                func_800FC6B0(D_80800AA8_gczoomboxdata[portrait_id].pts[0].sound_id);
        } else {
            do {
                idx = func_800DC214(0, D_80800AA8_gczoomboxdata[portrait_id].count);
                volume = D_80800AA8_gczoomboxdata[portrait_id].pts[idx].volume;
            } while (!volume);
            pitch = D_80800AA8_gczoomboxdata[portrait_id].pts[idx].pitch;
            pitch_min = pitch - pitch_down < 0.1f ? 0.1f : pitch - pitch_down;
            if (pitch_min >= 2.0f)
                pitch_min = 1.99f;
            pitch_max = pitch - pitch_up < 2.0f ? pitch - pitch_up : 2.0f;
            if (!(pitch_max > 0.1f))
                pitch_max = 0.1f;
            source = func_800C2E04();
            if (source) {
                func_800C301C(source, D_80800AA8_gczoomboxdata[portrait_id].pts[idx].sound_id);
                func_800C3058(source,
                              func_800DC214(volume - unk_0 < 0 ? 0 : volume - unk_0,
                                            volume - unk_1 < 0 ? 0 : volume - unk_1));
                func_800C31DC(source, func_800DC264(pitch_min, pitch_max));
                func_800C330C(source, 1);
                func_800C3418(source, 0);
                func_800C34CC(source, 0);
                if (func_800C42E0(D_80800AA8_gczoomboxdata[portrait_id].pts[idx].sound_id))
                    func_800C3A40(source, 0.1f, 0.5f, 0.1f);
                func_800C3BDC(source);
            }
        }
    }
}

u16 gczoomboxdata_entrypoint_1(s32 portrait_id)
{
    return D_80800AA8_gczoomboxdata[portrait_id].asset_id;
}

void gczoomboxdata_entrypoint_2(s32 portrait_id, s8 *out_layout_0, s8 *out_layout_1)
{
    ZoomEntry2 *entry = &((ZoomEntry2 *) D_80800AA8_gczoomboxdata)[portrait_id];
    *out_layout_0 = entry->layout_0;
    *out_layout_1 = entry->layout_1;
}

u8 gczoomboxdata_entrypoint_3(s32 portrait_id)
{
    return *(u8 *) ((char *) D_80800AB0_gczoomboxdata + portrait_id * 12);
}

void gczoomboxdata_entrypoint_4(s32 portrait_id, s32 point_idx, s16 *out_sound_id, s16 *out_volume, f32 *out_pitch)
{
    ZoomBox *entry = &((ZoomBox *) D_80800AA8_gczoomboxdata)[portrait_id];
    *out_sound_id = entry->pts[point_idx].sound_id;
    *out_volume = entry->pts[point_idx].volume;
    *out_pitch = entry->pts[point_idx].pitch;
}

// Returns the portrait asset id, or 0 if there is no portrait.
u16 gczoomboxdata_entrypoint_5(s32 portrait_id)
{
    u16 asset_id;

    if (portrait_id == 0x44) {
        return 0;
    }
    asset_id = D_80800AA8_gczoomboxdata[portrait_id].asset_id;
    // Matching: empty block needed for the match.
    if (1) {
    }
    if (asset_id == 0 || func_800D58FC(asset_id) == 4) {
        return 0;
    }
    return asset_id;
}

// "Has portrait" check used by option menus.
s32 gczoomboxdata_entrypoint_6(s32 portrait_id)
{
    s32 asset_id = gczoomboxdata_entrypoint_5(portrait_id);

    if ((asset_id == 0) || (asset_id == 0xBAE)) {
        return FALSE;
    }
    return TRUE;
}

// TU-NOTE: the overlay .data is defined here in C (values taken from the ROM).
// D_80800AB0_gczoomboxdata is a linker symbol at D_80800AA8_gczoomboxdata + 0x8.

u32 D_808003C0_gczoomboxdata[6] = {0x4573A98,  0x3F99999A, 0x4573A98,
                                   0x3F99999A, 0x4573A98,  0x3F99999A};
u32 D_808003D8_gczoomboxdata[14] = {0x5A83A98,  0x3FCCCCCD, 0x5A93A98,  0x3FCCCCCD, 0x5AA3A98,
                                    0x3FCCCCCD, 0x5AB3A98,  0x3FCCCCCD, 0x4783A98,  0x3F8CCCCD,
                                    0x4793A98,  0x3F8CCCCD, 0x47A3A98,  0x3F8CCCCD};
u32 D_80800410_gczoomboxdata[6] = {0x47861A8,  0x3F8CCCCD, 0x47961A8,
                                   0x3F8CCCCD, 0x47A61A8,  0x3F8CCCCD};
u32 D_80800428_gczoomboxdata[6] = {0x6504E20,  0x3F800000, 0x6514E20,
                                   0x3F800000, 0x6524E20,  0x3F800000};
u32 D_80800440_gczoomboxdata[6] = {0x64D4E20,  0x3F800000, 0x64E4E20,
                                   0x3F800000, 0x64F4E20,  0x3F800000};
u32 D_80800458_gczoomboxdata[2] = {0x5E24E20, 0x3FB33333};
u32 D_80800460_gczoomboxdata[2] = {0x4F23A98, 0x3F99999A};
u32 D_80800468_gczoomboxdata[6] = {0x4F23A98,  0x3F666666, 0x4F23A98,
                                   0x3F666666, 0x4F23A98,  0x3F666666};
u32 D_80800480_gczoomboxdata[8] = {0x4706978, 0x3FA66666, 0x4716978, 0x3FA66666,
                                   0x4726978, 0x3FA66666, 0x4736978, 0x3FA66666};
u32 D_808004A0_gczoomboxdata[8] = {0x4706978, 0x40000000, 0x4716978, 0x40000000,
                                   0x4726978, 0x40000000, 0x4736978, 0x40000000};
u32 D_808004C0_gczoomboxdata[6] = {0x4623A98,  0x3F8CCCCD, 0x4633A98,
                                   0x3F8CCCCD, 0x4643A98,  0x3F8CCCCD};
u32 D_808004D8_gczoomboxdata[6] = {0x46255F0,  0x3F8CCCCD, 0x46355F0,
                                   0x3F8CCCCD, 0x46455F0,  0x3F8CCCCD};
u32 D_808004F0_gczoomboxdata[6] = {0x4623A98,  0x3FB33333, 0x4633A98,
                                   0x3FB33333, 0x4643A98,  0x3FB33333};
u32 D_80800508_gczoomboxdata[6] = {0x4623A98,  0x3FCCCCCD, 0x4633A98,
                                   0x3FCCCCCD, 0x4643A98,  0x3FCCCCCD};
u32 D_80800520_gczoomboxdata[4] = {0x5BF3A98, 0x3F99999A, 0x5C03A98, 0x3F99999A};
u32 D_80800530_gczoomboxdata[10] = {0x3F759D8,  0x3F8CCCCD, 0x3F859D8,  0x3F8CCCCD, 0x3F959D8,
                                    0x3F8CCCCD, 0x3FA59D8,  0x3F8CCCCD, 0x3FB59D8,  0x3F8CCCCD};
u32 D_80800558_gczoomboxdata[10] = {0x5F459D8,  0x3F8CCCCD, 0x5F559D8,  0x3F8CCCCD, 0x5F659D8,
                                    0x3F8CCCCD, 0x5F759D8,  0x3F8CCCCD, 0x5F859D8,  0x3F8CCCCD};
u32 D_80800580_gczoomboxdata[6] = {0x49B2710,  0x3F800000, 0x46059D8,
                                   0x3F333333, 0x47B3A98,  0x3F99999A};
u32 D_80800598_gczoomboxdata[2] = {0x47C3A98, 0x3F800000};
u32 D_808005A0_gczoomboxdata[2] = {0x51F3A98, 0x3F800000};
u32 D_808005A8_gczoomboxdata[4] = {0x4D855F0, 0x3F800000, 0x4D955F0, 0x3F800000};
u32 D_808005B8_gczoomboxdata[4] = {0x4DA5DC0, 0x3F666666, 0x4DB5DC0, 0x3F666666};
u32 D_808005C8_gczoomboxdata[4] = {0x4D34E20, 0x3F800000, 0x4D44E20, 0x3F800000};
u32 D_808005D8_gczoomboxdata[4] = {0x4C33A98, 0x3F800000, 0x4C43A98, 0x3F800000};
u32 D_808005E8_gczoomboxdata[2] = {0x4CA4E20, 0x3F800000};
u32 D_808005F0_gczoomboxdata[6] = {0x4DA55F0,  0x3F666666, 0x4DB55F0,
                                   0x3F59999A, 0x4DB55F0,  0x3F666666};
u32 D_80800608_gczoomboxdata[4] = {0x4D655F0, 0x3F800000, 0x4D755F0, 0x3F800000};
u32 D_80800618_gczoomboxdata[6] = {0x5096D60,  0x3F8CCCCD, 0x50A6D60,
                                   0x3F8CCCCD, 0x50B6D60,  0x3F8CCCCD};
u32 D_80800630_gczoomboxdata[2] = {0x63E3A98, 0x3F99999A};
u32 D_80800638_gczoomboxdata[2] = {0x63E3A98, 0x3FC00000};
u32 D_80800640_gczoomboxdata[4] = {0x5223A98, 0x3FA66666, 0x5233A98, 0x3FA66666};
u32 D_80800650_gczoomboxdata[4] = {0x5223A98, 0x3FD9999A, 0x5233A98, 0x3FD9999A};
u32 D_80800660_gczoomboxdata[4] = {0x5223A98, 0x3F800000, 0x5233A98, 0x3F800000};
u32 D_80800670_gczoomboxdata[2] = {0x5264E20, 0x3FCCCCCD};
u32 D_80800678_gczoomboxdata[6] = {0x5483A98,  0x3F800000, 0x5493A98,
                                   0x3F800000, 0x54A3A98,  0x3F800000};
u32 D_80800690_gczoomboxdata[8] = {0x5576D60, 0x3F8CCCCD, 0x5406D60, 0x3F8CCCCD,
                                   0x5586D60, 0x3F8CCCCD, 0x5596D60, 0x3F8CCCCD};
u32 D_808006B0_gczoomboxdata[2] = {0x3ED3A98, 0x3F4CCCCD};
u32 D_808006B8_gczoomboxdata[2] = {0x3ED3A98, 0x3FC00000};
u32 D_808006C0_gczoomboxdata[4] = {0x6584A38, 0x3F800000, 0x6584A38, 0x3F4CCCCD};
u32 D_808006D0_gczoomboxdata[4] = {0x6403A98, 0x3F800000, 0x6463A98, 0x3F800000};
u32 D_808006E0_gczoomboxdata[6] = {0x5677530,  0x3F333333, 0x5687530,
                                   0x3F333333, 0x5697530,  0x3F333333};
u32 D_808006F8_gczoomboxdata[4] = {0x4D87530, 0x3ECCCCCD, 0x4D97530, 0x3ECCCCCD};
u32 D_80800708_gczoomboxdata[6] = {0x5677530,  0x3F000000, 0x5687530,
                                   0x3F000000, 0x5697530,  0x3F000000};
u32 D_80800720_gczoomboxdata[12] = {0x5672AF8, 0x3FC00000, 0x5683A98, 0x3FC00000,
                                    0x5694268, 0x3FC00000, 0x4B83A98, 0x3F666666,
                                    0x4B83A98, 0x3F4CCCCD, 0x4B83A98, 0x3F333333};
u32 D_80800750_gczoomboxdata[10] = {0x47B4E20,  0x3F666666, 0x42B4E20,  0x3F666666, 0x5596D60,
                                    0x3F666666, 0x5576D60,  0x3F666666, 0x5586D60,  0x3F666666};
u32 D_80800778_gczoomboxdata[2] = {0x6417D00, 0x3F666666};
u32 D_80800780_gczoomboxdata[6] = {0x5CB4E20,  0x3F800000, 0x5CC4E20,
                                   0x3F800000, 0x5CD4E20,  0x3F800000};
u32 D_80800798_gczoomboxdata[2] = {0x5D04E20, 0x3F800000};
u32 D_808007A0_gczoomboxdata[2] = {0x5D04E20, 0x3F99999A};
u32 D_808007A8_gczoomboxdata[2] = {0x6343A98, 0x3F4CCCCD};
u32 D_808007B0_gczoomboxdata[2] = {0x42B3A98, 0x3F4CCCCD};
u32 D_808007B8_gczoomboxdata[2] = {0x4D63A98, 0x3FE66666};
u32 D_808007C0_gczoomboxdata[2] = {0x47C3A98, 0x3FB33333};
u32 D_808007C8_gczoomboxdata[2] = {0x6424E20, 0x3F4CCCCD};
u32 D_808007D0_gczoomboxdata[4] = {0x4F54650, 0x3FB33333, 0x4F64650, 0x3FB33333};
u32 D_808007E0_gczoomboxdata[2] = {0x4E63A98, 0x3F800000};
u32 D_808007E8_gczoomboxdata[4] = {0x5374E20, 0x3F666666, 0x5384E20, 0x3F666666};
u32 D_808007F8_gczoomboxdata[6] = {0x5CB4E20,  0x3FC00000, 0x5CC4E20,
                                   0x3FC00000, 0x5CD4E20,  0x3FC00000};
u32 D_80800810_gczoomboxdata[2] = {0x5323A98, 0x3F99999A};
u32 D_80800818_gczoomboxdata[2] = {0x55F4E20, 0x3F8CCCCD};
u32 D_80800820_gczoomboxdata[2] = {0x55F4E20, 0x3F99999A};
u32 D_80800828_gczoomboxdata[2] = {0x55F4E20, 0x3F666666};
u32 D_80800830_gczoomboxdata[2] = {0x61C3A98, 0x3F99999A};
u32 D_80800838_gczoomboxdata[4] = {0x6302AF8, 0x3FA66666, 0x6302AF8, 0x3FA66666};
u32 D_80800848_gczoomboxdata[2] = {0x63F4E20, 0x3F800000};
u32 D_80800850_gczoomboxdata[2] = {0x6434E20, 0x3F666666};
u32 D_80800858_gczoomboxdata[2] = {0x63F55F0, 0x3F19999A};
u32 D_80800860_gczoomboxdata[2] = {0x6447D00, 0x3F800000};
u32 D_80800868_gczoomboxdata[2] = {0x6454268, 0x3F800000};
u32 D_80800870_gczoomboxdata[4] = {0x5BC3A98, 0x3F19999A, 0x5BD3A98, 0x3F19999A};
u32 D_80800880_gczoomboxdata[4] = {0x6474E20, 0x3F666666, 0x6484E20, 0x3F666666};
u32 D_80800890_gczoomboxdata[4] = {0x6494650, 0x3F800000, 0x64A4650, 0x3F800000};
u32 D_808008A0_gczoomboxdata[4] = {0x64B55F0, 0x3F800000, 0x64C55F0, 0x3F800000};
u32 D_808008B0_gczoomboxdata[8] = {0x68C4E20, 0x3F800000, 0x68D4E20, 0x3F800000,
                                   0x68E4E20, 0x3F800000, 0x68F4E20, 0x3F800000};
u32 D_808008D0_gczoomboxdata[6] = {0x6546590,  0x3F800000, 0x6554E20,
                                   0x3F800000, 0x6566590,  0x3F800000};
u32 D_808008E8_gczoomboxdata[4] = {0x4F54E20, 0x3FF33333, 0x4F64E20, 0x3FF33333};
u32 D_808008F8_gczoomboxdata[4] = {0x5315DC0, 0x3ECCCCCD, 0x5305DC0, 0x3ECCCCCD};
u32 D_80800908_gczoomboxdata[2] = {0x6414E20, 0x3F99999A};
u32 D_80800910_gczoomboxdata[2] = {0x6414E20, 0x3FCCCCCD};
u32 D_80800918_gczoomboxdata[2] = {0x4933E80, 0x3FA66666};
u32 D_80800920_gczoomboxdata[6] = {0x5672AF8,  0x3FF33333, 0x5683A98,
                                   0x3FF33333, 0x5694268,  0x3FF33333};
u32 D_80800938_gczoomboxdata[8] = {0x6744E20, 0x3F800000, 0x6754E20, 0x3F800000,
                                   0x6764E20, 0x3F800000, 0x6774E20, 0x3F800000};
u32 D_80800958_gczoomboxdata[2] = {0x4F23A98, 0x3F19999A};
u32 D_80800960_gczoomboxdata[2] = {0x4DD3A98, 0x3F800000};
u32 D_80800968_gczoomboxdata[4] = {0x4F03A98, 0x3FE66666, 0x4F13A98, 0x3FE66666};
u32 D_80800978_gczoomboxdata[2] = {0x49F3A98, 0x3F99999A};
u32 D_80800980_gczoomboxdata[2] = {0x33A98, 0xBF800000};
u32 D_80800988_gczoomboxdata[2] = {0x33A98, 0xBF800000};
u32 D_80800990_gczoomboxdata[2] = {0x713A98, 0xBF800000};
u32 D_80800998_gczoomboxdata[2] = {0x6E3A98, 0xBF800000};
u32 D_808009A0_gczoomboxdata[2] = {0x703A98, 0xBF800000};
u32 D_808009A8_gczoomboxdata[2] = {0x6D3A98, 0xBF800000};
u32 D_808009B0_gczoomboxdata[2] = {0x793A98, 0xBF800000};
u32 D_808009B8_gczoomboxdata[2] = {0x9B3A98, 0xBF800000};
u32 D_808009C0_gczoomboxdata[2] = {0x52A4650, 0x3F800000};
u32 D_808009C8_gczoomboxdata[26] = {
    0x5E74650,  0x3F800000, 0x4623A98,  0x3F8CCCCD, 0x4633A98,  0x3F8CCCCD, 0x4643A98,
    0x3F8CCCCD, 0x4623A98,  0x3F8CCCCD, 0x4633A98,  0x3F8CCCCD, 0x4643A98,  0x3F8CCCCD,
    0x4623A98,  0x3F8CCCCD, 0x4633A98,  0x3F8CCCCD, 0x4643A98,  0x3F8CCCCD, 0x4623A98,
    0x3F8CCCCD, 0x4633A98,  0x3F8CCCCD, 0x4643A98,  0x3F8CCCCD};
u32 D_80800A30_gczoomboxdata[30] = {
    0x4623A98, 0x3F8CCCCD, 0x4633A98, 0x3F8CCCCD, 0x4643A98, 0x3F8CCCCD, 0x4623A98, 0x3F8CCCCD,
    0x4633A98, 0x3F8CCCCD, 0x4643A98, 0x3F8CCCCD, 0x4623A98, 0x3F8CCCCD, 0x4633A98, 0x3F8CCCCD,
    0x4643A98, 0x3F8CCCCD, 0x4623A98, 0x3F8CCCCD, 0x4633A98, 0x3F8CCCCD, 0x4643A98, 0x3F8CCCCD,
    0x4623A98, 0x3F8CCCCD, 0x4633A98, 0x3F8CCCCD, 0x4643A98, 0x3F8CCCCD};
ZoomEntry D_80800AA8_gczoomboxdata[210] = {0xC06, 0x0,  0x0,  (void *) &D_80800960_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBE6, 0x0,  0x0,  (void *) &D_80800968_gczoomboxdata,
                                           0x2,   0x0,  0x0,  0x0,
                                           0xB4D, 0x0,  0x0,  (void *) &D_80800978_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xC03, 0x0,  0x0,  (void *) &D_808009C0_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xC00, 0x0,  0x0,  (void *) &D_808009C8_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xB8D, 0x0,  0x0,  (void *) &D_80800990_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xB94, 0x0,  0x0,  (void *) &D_80800998_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xB92, 0x0,  0x0,  (void *) &D_808009B0_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xB95, 0x0,  0x0,  (void *) &D_808009A8_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xB8C, 0x0,  0x0,  (void *) &D_808009A0_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xC10, 0x0,  0x0,  (void *) &D_80800980_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xC0F, 0x0,  0x0,  (void *) &D_80800988_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xB89, 0x0,  0x0,  (void *) &D_808003C0_gczoomboxdata,
                                           0x3,   0x0,  0x0,  0x0,
                                           0xB8B, 0x0,  0x0,  (void *) &D_80800480_gczoomboxdata,
                                           0x4,   0x0,  0x0,  0x0,
                                           0xB8B, 0x0,  0x0,  (void *) &D_808004A0_gczoomboxdata,
                                           0x4,   0x0,  0x0,  0x0,
                                           0xB8A, 0x0,  0x0,  (void *) &D_808004C0_gczoomboxdata,
                                           0x3,   0x0,  0x0,  0x0,
                                           0xBD9, 0x0,  0x0,  (void *) &D_80800530_gczoomboxdata,
                                           0x5,   0x0,  0x0,  0x0,
                                           0xBD0, 0x0,  0x0,  (void *) &D_80800460_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBD4, 0x0,  0x0,  (void *) &D_80800460_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBD3, 0x0,  0x0,  (void *) &D_80800460_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBD6, 0x0,  0x0,  (void *) &D_80800460_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBD5, 0x0,  0x0,  (void *) &D_80800460_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0xB93, 0x0,  0x0,  (void *) &D_80800580_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0xBA2, -0x8, -0x8, (void *) &D_80800410_gczoomboxdata,
                                           0x3,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0xB99, 0x0,  0x0,  (void *) &D_80800598_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0xBAB, 0x0,  0x0,  (void *) &D_808008B0_gczoomboxdata,
                                           0x4,   0x0,  0x0,  0x0,
                                           0xB8A, 0x0,  0x0,  (void *) &D_808004C0_gczoomboxdata,
                                           0x3,   0x0,  0x0,  0x0,
                                           0xBB2, 0x0,  0x0,  (void *) &D_80800608_gczoomboxdata,
                                           0x2,   0x0,  0x0,  0x0,
                                           0xBD8, 0x0,  0x0,  (void *) &D_80800958_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBD5, 0x0,  0x0,  (void *) &D_80800958_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBD0, 0x0,  0x0,  (void *) &D_80800958_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBD1, 0x0,  0x0,  (void *) &D_80800958_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0xBA6, 0x0,  -0xA, (void *) &D_808005A8_gczoomboxdata,
                                           0x2,   0x0,  0x0,  0x0,
                                           0xBA5, 0x0,  -0x7, (void *) &D_808005B8_gczoomboxdata,
                                           0x2,   0x0,  0x0,  0x0,
                                           0xBB8, 0x0,  0x0,  (void *) &D_808007E0_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBAC, 0x0,  0x0,  (void *) &D_808007C8_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBAC, 0x0,  0x0,  (void *) &D_808007C8_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBAC, 0x0,  0x0,  (void *) &D_808007C8_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBB0, 0x0,  0x0,  (void *) &D_808005C8_gczoomboxdata,
                                           0x2,   0x0,  0x0,  0x0,
                                           0xB90, 0x0,  0x0,  (void *) &D_808005D8_gczoomboxdata,
                                           0x2,   0x0,  0x0,  0x0,
                                           0xBE3, 0x0,  0x0,  (void *) &D_808005E8_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBC3, 0x0,  0x0,  (void *) &D_80800720_gczoomboxdata,
                                           0x3,   0x0,  0x0,  0x0,
                                           0xBA8, -0xA, -0x4, (void *) &D_80800868_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBC0, 0x0,  0x0,  (void *) &D_80800640_gczoomboxdata,
                                           0x2,   0x0,  0x0,  0x0,
                                           0xBC1, 0x0,  0x0,  (void *) &D_80800650_gczoomboxdata,
                                           0x2,   0x0,  0x0,  0x0,
                                           0xBC2, 0x0,  0x0,  (void *) &D_80800660_gczoomboxdata,
                                           0x2,   0x0,  0x0,  0x0,
                                           0xBAD, 0x0,  0x0,  (void *) &D_80800638_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBCC, 0x0,  0x0,  (void *) &D_80800890_gczoomboxdata,
                                           0x2,   0x0,  0x0,  0x0,
                                           0xBA4, 0x0,  0x0,  (void *) &D_808008D0_gczoomboxdata,
                                           0x3,   0x0,  0x0,  0x0,
                                           0xBED, 0x0,  0x0,  (void *) &D_80800520_gczoomboxdata,
                                           0x2,   0x0,  0x0,  0x0,
                                           0xBCD, 0x0,  0x0,  (void *) &D_808005F0_gczoomboxdata,
                                           0x3,   0x0,  0x0,  0x0,
                                           0xBA2, -0x8, -0x8, (void *) &D_80800410_gczoomboxdata,
                                           0x3,   0x0,  0x0,  0x0,
                                           0xBAE, 0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0xBEC, 0x0,  0x0,  (void *) &D_808005A0_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBF5, 0x0,  0x0,  (void *) &D_80800630_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0xBA2, 0x0,  0x0,  (void *) &D_80800410_gczoomboxdata,
                                           0x3,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0xBB9, 0x0,  0x0,  (void *) &D_80800850_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBB1, 0x0,  0x0,  (void *) &D_80800848_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xB9D, 0x0,  0x0,  (void *) &D_80800618_gczoomboxdata,
                                           0x3,   0x0,  0x0,  0x0,
                                           0xBB4, 0x0,  0x0,  (void *) &D_80800810_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xB9F, 0x0,  0x0,  (void *) &D_80800670_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBB5, 0x0,  0x0,  (void *) &D_808006D0_gczoomboxdata,
                                           0x2,   0x0,  0x0,  0x0,
                                           0xBB6, 0x0,  0x0,  (void *) &D_80800880_gczoomboxdata,
                                           0x2,   0x0,  0x0,  0x0,
                                           0xBDA, 0x0,  0x0,  (void *) &D_808007E8_gczoomboxdata,
                                           0x2,   0x0,  0x0,  0x0,
                                           0xBDC, 0x0,  0x0,  (void *) &D_80800858_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0xB89, 0x0,  0x0,  (void *) &D_808003C0_gczoomboxdata,
                                           0x3,   0x0,  0x0,  0x0,
                                           0xB8B, 0x0,  0x0,  (void *) &D_80800480_gczoomboxdata,
                                           0x4,   0x0,  0x0,  0x0,
                                           0xBAE, 0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0xBBF, 0x0,  0x0,  (void *) &D_808007D0_gczoomboxdata,
                                           0x2,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0xBBB, 0x0,  0x0,  (void *) &D_80800780_gczoomboxdata,
                                           0x3,   0x0,  0x0,  0x0,
                                           0xBBC, 0x0,  0x0,  (void *) &D_80800828_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBA0, 0x0,  0x0,  (void *) &D_80800690_gczoomboxdata,
                                           0x4,   0x0,  0x0,  0x0,
                                           0xBFC, 0x0,  0x0,  (void *) &D_80800708_gczoomboxdata,
                                           0x3,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0xBEB, 0x0,  0x0,  (void *) &D_808006B8_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0xBE0, 0x0,  0x0,  (void *) &D_808007A8_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBE4, 0x0,  0x0,  (void *) &D_808007B0_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBF6, 0x0,  0x0,  (void *) &D_808007B8_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0xB99, 0x0,  0x0,  (void *) &D_80800A30_gczoomboxdata,
                                           0x3,   0x0,  0x0,  0x0,
                                           0xBB7, 0x0,  0x0,  (void *) &D_80800678_gczoomboxdata,
                                           0x3,   0x0,  0x0,  0x0,
                                           0xBAB, 0x0,  0x0,  (void *) &D_808008B0_gczoomboxdata,
                                           0x4,   0x0,  0x0,  0x0,
                                           0xBD7, 0x0,  0x0,  (void *) &D_80800460_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0xBD8, 0x0,  0x0,  (void *) &D_80800460_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBD2, 0x0,  0x0,  (void *) &D_80800460_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBD1, 0x0,  0x0,  (void *) &D_80800460_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBDF, 0x0,  0x0,  (void *) &D_80800838_gczoomboxdata,
                                           0x2,   0x0,  0x0,  0x0,
                                           0xBDE, 0x0,  0x0,  (void *) &D_80800838_gczoomboxdata,
                                           0x2,   0x0,  0x0,  0x0,
                                           0xBE5, 0x0,  0x0,  (void *) &D_80800558_gczoomboxdata,
                                           0x5,   0x0,  0x0,  0x0,
                                           0xBC7, 0x0,  0x0,  (void *) &D_808008E8_gczoomboxdata,
                                           0x2,   0x0,  0x0,  0x0,
                                           0xBD9, 0x0,  0x0,  (void *) &D_80800530_gczoomboxdata,
                                           0x5,   0x0,  0x0,  0x0,
                                           0xB89, 0x0,  0x0,  (void *) &D_808003C0_gczoomboxdata,
                                           0x3,   0x0,  0x0,  0x0,
                                           0xB8B, 0x0,  0x0,  (void *) &D_80800480_gczoomboxdata,
                                           0x4,   0x0,  0x0,  0x0,
                                           0xB8A, 0x0,  0x0,  (void *) &D_808004C0_gczoomboxdata,
                                           0x3,   0x0,  0x0,  0x0,
                                           0xBA1, -0x9, -0xD, (void *) &D_80800428_gczoomboxdata,
                                           0x3,   0x0,  0x0,  0x0,
                                           0xBA3, 0x0,  0x0,  (void *) &D_80800440_gczoomboxdata,
                                           0x3,   0x0,  0x0,  0x0,
                                           0xB9A, 0x0,  0x0,  (void *) &D_808006E0_gczoomboxdata,
                                           0x3,   0x0,  0x0,  0x0,
                                           0xBA2, -0x8, -0x8, (void *) &D_80800410_gczoomboxdata,
                                           0x3,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0xBFD, 0x0,  0x0,  (void *) &D_808004D8_gczoomboxdata,
                                           0x3,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0xBD4, 0x0,  0x0,  (void *) &D_80800958_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBD7, 0x0,  0x0,  (void *) &D_80800958_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBD3, 0x0,  0x0,  (void *) &D_80800958_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBD6, 0x0,  0x0,  (void *) &D_80800958_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBD2, 0x0,  0x0,  (void *) &D_80800958_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBAE, 0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0xBBA, 0x0,  0x0,  (void *) &D_808003D8_gczoomboxdata,
                                           0x4,   0x0,  0x0,  0x0,
                                           0xBBA, 0x0,  0x0,  (void *) &D_808003D8_gczoomboxdata,
                                           0x4,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0xBF8, 0x0,  0x0,  (void *) &D_80800798_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xC11, 0x0,  0x0,  (void *) &D_80800908_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xC12, 0x0,  0x0,  (void *) &D_80800910_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xB99, 0x0,  0x0,  (void *) &D_808007C0_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xC11, 0x0,  0x0,  (void *) &D_80800908_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBE8, 0x0,  0x0,  (void *) &D_80800918_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0xB50, 0x0,  0x0,  (void *) &D_808003C0_gczoomboxdata,
                                           0x3,   0x0,  0x0,  0x0,
                                           0xBFD, 0x0,  0x0,  (void *) &D_808004D8_gczoomboxdata,
                                           0x3,   0x0,  0x0,  0x0,
                                           0xB4F, 0x0,  0x0,  (void *) &D_808009B8_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBBD, 0x0,  0x0,  (void *) &D_80800818_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBBD, 0x0,  0x0,  (void *) &D_80800820_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBDB, 0x0,  0x0,  (void *) &D_808007A0_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBAF, 0x0,  -0x3, (void *) &D_80800860_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xB9B, 0x0,  0x0,  (void *) &D_808006B0_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBCF, 0x0,  0x0,  (void *) &D_80800468_gczoomboxdata,
                                           0x3,   0x0,  0x0,  0x0,
                                           0xBF7, 0x0,  0x0,  (void *) &D_808007A0_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBFA, 0x0,  0x0,  (void *) &D_808006C0_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBE2, 0x0,  0x0,  (void *) &D_80800870_gczoomboxdata,
                                           0x2,   0x0,  0x0,  0x0,
                                           0xBF9, 0x0,  0x0,  (void *) &D_808006C0_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBDD, 0x0,  0x0,  (void *) &D_808008A0_gczoomboxdata,
                                           0x2,   0x0,  0x0,  0x0,
                                           0xB9A, 0x0,  0x0,  (void *) &D_808006E0_gczoomboxdata,
                                           0x3,   0x0,  0x0,  0x0,
                                           0xBFB, 0x0,  0x0,  (void *) &D_808006F8_gczoomboxdata,
                                           0x2,   0x0,  0x0,  0x0,
                                           0xB8F, 0x0,  0x0,  (void *) &D_80800750_gczoomboxdata,
                                           0x5,   0x0,  0x0,  0x0,
                                           0xBCE, 0x0,  0x0,  (void *) &D_80800468_gczoomboxdata,
                                           0x3,   0x0,  0x0,  0x0,
                                           0xBF4, 0x0,  0x0,  (void *) &D_808004F0_gczoomboxdata,
                                           0x3,   0x0,  0x0,  0x0,
                                           0xBF2, 0x0,  0x0,  (void *) &D_80800508_gczoomboxdata,
                                           0x3,   0x0,  0x0,  0x0,
                                           0xBF1, 0x0,  0x0,  (void *) &D_80800508_gczoomboxdata,
                                           0x3,   0x0,  0x0,  0x0,
                                           0xBA7, 0x0,  -0x5, (void *) &D_80800778_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBBE, 0x0,  0x0,  (void *) &D_808008F8_gczoomboxdata,
                                           0x2,   0x0,  0x0,  0x0,
                                           0xBA9, -0x6, -0x6, (void *) &D_80800458_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0xBAA, -0x7, -0x3, (void *) &D_80800830_gczoomboxdata,
                                           0x1,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0xBEE, 0x0,  0x0,  (void *) &D_808007F8_gczoomboxdata,
                                           0x3,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0xBFE, 0x0,  0x0,  (void *) &D_808004D8_gczoomboxdata,
                                           0x3,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0xBEF, 0x0,  0x0,  (void *) &D_808007F8_gczoomboxdata,
                                           0x3,   0x0,  0x0,  0x0,
                                           0xBF0, 0x0,  0x0,  (void *) &D_808007F8_gczoomboxdata,
                                           0x3,   0x0,  0x0,  0x0,
                                           0xBC5, 0x0,  0x0,  (void *) &D_80800720_gczoomboxdata,
                                           0x3,   0x0,  0x0,  0x0,
                                           0xBC4, 0x0,  0x0,  (void *) &D_80800920_gczoomboxdata,
                                           0x3,   0x0,  0x0,  0x0,
                                           0xBC4, 0x0,  0x0,  (void *) &D_80800720_gczoomboxdata,
                                           0x3,   0x0,  0x0,  0x0,
                                           0xBF3, 0x0,  0x0,  (void *) &D_80800938_gczoomboxdata,
                                           0x4,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0,
                                           0x0,   0x0,  0x0,  0,
                                           0x0,   0x0,  0x0,  0x0};
