#include "common.h"

#define AF614_FIELD(v, s, n) (((u32) (v) & ((1U << (n)) - 1)) << (s))
#define AF614_MAX(a, b) ((a) > (b) ? (a) : (b))
#define AF614_MIN(a, b) ((a) < (b) ? (a) : (b))
#define AF614_TEXEL_WORDS(w, b) AF614_MAX(1, ((w) * (b) / 8))
#define AF614_CALC_DXT(w, b) ((2048 + AF614_TEXEL_WORDS(w, b) - 1) / AF614_TEXEL_WORDS(w, b))
#define AF614_CALC_DXT_4B(w) ((2048 + AF614_MAX(1, (w) / 16) - 1) / AF614_MAX(1, (w) / 16))
// Matching: the line breaks in this macro are needed for the match.
#define AF614_COMMAND(pkt, a, b)                                                                   \
    {                                                                                              \
        AF614Gfx *_g = (pkt);                                                                      \
        _g->w0 = (a);                                                                              \
        _g->w1 = (u32) (b);                                                                        \
    }
// Matching: the line breaks in this macro are needed for the match.
#define AF614_SYNC(pkt, a)                                                                         \
    {                                                                                              \
        AF614Gfx *_g = (pkt);                                                                      \
        _g->w0 = (a);                                                                              \
        _g->w1 = 0;                                                                                \
    }
#define AF614_SET_TILE(pkt, fmt, siz, line, tmem, tile, cms, cmt, masks, maskt)                    \
    {                                                                                              \
        AF614Gfx *_g = (pkt);                                                                      \
        _g->w0 = 0xF5000000 | AF614_FIELD(fmt, 21, 3) | AF614_FIELD(siz, 19, 2) |                  \
                 AF614_FIELD(line, 9, 9) | AF614_FIELD(tmem, 0, 9);                                \
        _g->w1 = AF614_FIELD(tile, 24, 3) | AF614_FIELD(cmt, 18, 2) | AF614_FIELD(maskt, 14, 4) |  \
                 AF614_FIELD(cms, 8, 2) | AF614_FIELD(masks, 4, 4);                                \
    }
#define AF614_LOAD_BLOCK(pkt, count, dxt)                                                          \
    {                                                                                              \
        AF614Gfx *_g = (pkt);                                                                      \
        _g->w0 = 0xF3000000;                                                                       \
        _g->w1 =                                                                                   \
            0x07000000 | AF614_FIELD(AF614_MIN(count, 2047), 12, 12) | AF614_FIELD(dxt, 0, 12);    \
    }
#define AF614_SET_TILE_SIZE(pkt, tile, w, h)                                                       \
    AF614_COMMAND(pkt, 0xF2000000,                                                                 \
                  AF614_FIELD(tile, 24, 3) | AF614_FIELD(((w) -1) << 2, 12, 12) |                  \
                      AF614_FIELD(((h) -1) << 2, 0, 12))

#define AF614_LOAD_TLUT(pkt,img,count) { \
 { AF614Gfx *_g=pkt; _g->w0=0xE3001001; _g->w1=0x8000; } \
 AF614_COMMAND(pkt,0xFD100000,img); AF614_SYNC(pkt,0xE8000000); \
 { AF614Gfx *_g=pkt; _g->w0=0xF5000100; _g->w1=0x07000000; } \
 AF614_SYNC(pkt,0xE6000000); \
 { AF614Gfx *_g=pkt; _g->w0=0xF0000000; _g->w1=0x07000000|(count<<14); } \
AF614_SYNC(pkt,0xE7000000); }
#define AF614_SPRITE_RGBA32 0x800
    #define AF614_SPRITE_RGBA16 0x400
    #define AF614_SPRITE_IA16 0x200
    #define AF614_SPRITE_CI8 4
    #define AF614_SPRITE_IA8 0x100
    #define AF614_SPRITE_I8 0x40
    #define AF614_SPRITE_CI4 1
    #define AF614_SPRITE_IA4 0x80
    #define AF614_SPRITE_I4 0x20

// Sprite asset accessors and the RDP texture-load emitter.
typedef struct {
    u32 w0, w1;
} AF614Gfx;

// Frame count.
func_800AF5A0(s16 *sprite)
{
    return sprite[0];
}

// Format flags (see AF614_SPRITE_*).
func_800AF5A8(s16 *sprite)
{
    return sprite[1];
}

// Outputs the s16 header fields at +4 and +6.
int func_800AF5B0(s16 sprite[3], s32 *width, s32 *height)
{
    s16 *field;
    int index;
    // Matching: the pointer stepping and the index temporary are needed for the match.
    field = &(field = sprite)[1];
    field++;
    *width = *field;
    field--;
    index = 2;
    *height = field[index];
}

// Outputs width and height from the sprite header.
void func_800AF5C4(u8 *sprite, s32 *width, s32 *height)
{
    *width = (s32) *(s16 *) (sprite + 8);
    *height = (s32) *(s16 *) (sprite + 10);
}

// Sprite base + s16 offset at +0x12 (image data base).
int func_800AF5D8(s32 sprite)
{
    s16 *offset_ptr;
    offset_ptr = (s16 *) ((int) sprite + 0x12);
    // Matching: the comma expression is needed for the match.
    return *offset_ptr + (0, sprite);
}

// Sprite base + offset stored at +0x14.
s32 func_800AF5E4(s32 sprite)
{
    s32 offset_copy;
    s32 offset;
    // Matching: the 64-bit mask and the extra copy are needed for the match.
    offset = *(s32 *) (sprite + 0x14) & 0xFFFFFFFFFFFFFFFF;
    offset_copy = offset;
    return sprite + offset_copy;
}

// Sprite base + offset stored at +0x18.
s32 func_800AF5F0(s32 sprite)
{
    s32 offset_copy;
    s32 offset;
    // Matching: the 64-bit mask and the extra copy are needed for the match.
    offset = *(s32 *) (sprite + 0x18) & 0xFFFFFFFFFFFFFFFF;
    offset_copy = offset;
    return sprite + offset_copy;
}

// Frame directory entry: 12-byte entries starting at +0x1C.
func_800AF5FC(s32 sprite, s32 frame)
{
    return (void *) ((char *) sprite + 0x1C + frame * 0xC);
}

// Emits the RDP commands that load one sprite frame as a texture (TLUT first for CI4/CI8).
// Frame entry +8: image offset from the data base; +6: palette offset from the image.
// Width and height come from the sprite header. Masks are ceil(log2(size)) for sizes
// divisible by 8, else 0. Each format branch emits: set image, load tile, load sync,
// load block, pipe sync, render tile, tile size (BK: rare_gDPLoadMultiBlock[_4b]).
// TU-NOTE: the exact original macro form is unknown; reverify any reformat.
// Matching: the line breaks in this function are needed for the match.
void func_800AF614(AF614Gfx **gfx, u8 *sprite, s32 frame, s32 tmem, s32 rtile, s32 cms, s32 cmt, s32 *width, s32 *height)
{
    u8 *sprite_frame;
    s32 masks;
    s32 maskt;
    s32 timg;
    s32 remaining;
    sprite_frame=func_800AF5FC(sprite,frame);
    timg=func_800AF5D8(sprite);
    timg+=*(s32 *)(sprite_frame+8);
    *width=*(s16 *)(sprite+8);
    *height=*(s16 *)(sprite+10);
    if (*(s16 *)(sprite + 2) & AF614_SPRITE_CI4) {
        AF614_LOAD_TLUT((*gfx)++,timg+*(s16 *)(sprite_frame+6),15);
    } else if (*(s16 *)(sprite + 2) & AF614_SPRITE_CI8) {
        AF614_LOAD_TLUT((*gfx)++,timg+*(s16 *)(sprite_frame+6),255);
    }
    if ((*width&7)==0) {
        masks=0;
        remaining=*width-1;
        while (remaining!=0) {
            masks++;
            remaining>>=1;
        }
    } else {
        masks=0;
    }
    if ((*height&7)==0) {
        maskt=0;
        remaining=*height-1;
        while (remaining!=0) {
            maskt++;
            remaining>>=1;
        }
    } else {
        maskt=0;
    }
    if (*(s16 *)(sprite + 2) & AF614_SPRITE_RGBA32) {
        {
            AF614Gfx *_g = (*gfx)++;
            _g->w0 = 0xFD000000|AF614_FIELD(0,21,3)|AF614_FIELD(3,19,2);
            _g->w1 = (u32)timg;
        }
        AF614_SET_TILE((*gfx)++,0,3,0,tmem,7,cms,cmt,masks,maskt);
        AF614_SYNC((*gfx)++,0xE6000000);
        AF614_LOAD_BLOCK((*gfx)++,(*width * *height) - 1,AF614_CALC_DXT(*width,4));
        {
            AF614Gfx *_g = (*gfx)++;
            _g->w0 = 0xE7000000; _g->w1 = 0;
        }
        AF614_SET_TILE((*gfx)++,0,3,(*width * 2 + 7) >> 3,tmem,rtile,cms,cmt,masks,maskt);
        AF614_SET_TILE_SIZE((*gfx)++,rtile,*width,*height);
    } else if (*(s16 *)(sprite + 2) & AF614_SPRITE_RGBA16) {
        {
            AF614Gfx *_g = (*gfx)++;
            _g->w0 = 0xFD000000|AF614_FIELD(0,21,3)|AF614_FIELD(2,19,2);
            _g->w1 = (u32)timg;
        }
        AF614_SET_TILE((*gfx)++,0,2,0,tmem,7,cms,cmt,masks,maskt);
        AF614_SYNC((*gfx)++,0xE6000000);
        AF614_LOAD_BLOCK((*gfx)++,(*width * *height) - 1,AF614_CALC_DXT(*width,2));
        {
            AF614Gfx *_g = (*gfx)++;
            _g->w0 = 0xE7000000; _g->w1 = 0;
        }
        AF614_SET_TILE((*gfx)++,0,2,(*width * 2 + 7) >> 3,tmem,rtile,cms,cmt,masks,maskt);
        AF614_SET_TILE_SIZE((*gfx)++,rtile,*width,*height);
    } else if (*(s16 *)(sprite + 2) & AF614_SPRITE_IA16) {
        {
            AF614Gfx *_g = (*gfx)++;
            _g->w0 = 0xFD000000|AF614_FIELD(3,21,3)|AF614_FIELD(2,19,2);
            _g->w1 = (u32)timg;
        }
        AF614_SET_TILE((*gfx)++,3,2,0,tmem,7,cms,cmt,masks,maskt);
        AF614_SYNC((*gfx)++,0xE6000000);
        AF614_LOAD_BLOCK((*gfx)++,(*width * *height) - 1,AF614_CALC_DXT(*width,2));
        {
            AF614Gfx *_g = (*gfx)++;
            _g->w0 = 0xE7000000; _g->w1 = 0;
        }
        AF614_SET_TILE((*gfx)++,3,2,(*width * 2 + 7) >> 3,tmem,rtile,cms,cmt,masks,maskt);
        AF614_SET_TILE_SIZE((*gfx)++,rtile,*width,*height);
    } else if (*(s16 *)(sprite + 2) & AF614_SPRITE_CI8) {
        {
            AF614Gfx *_g = (*gfx)++;
            _g->w0 = 0xFD000000|AF614_FIELD(2,21,3)|AF614_FIELD(2,19,2);
            _g->w1 = (u32)timg;
        }
        AF614_SET_TILE((*gfx)++,2,2,0,tmem,7,cms,cmt,masks,maskt);
        AF614_SYNC((*gfx)++,0xE6000000);
        AF614_LOAD_BLOCK((*gfx)++,((*width * *height + 1) >> 1) - 1,AF614_CALC_DXT(*width,1));
        {
            AF614Gfx *_g = (*gfx)++;
            _g->w0 = 0xE7000000; _g->w1 = 0;
        }
        AF614_SET_TILE((*gfx)++,2,1,(*width + 7) >> 3,tmem,rtile,cms,cmt,masks,maskt);
        AF614_SET_TILE_SIZE((*gfx)++,rtile,*width,*height);
    } else if (*(s16 *)(sprite + 2) & AF614_SPRITE_IA8) {
        {
            AF614Gfx *_g = (*gfx)++;
            _g->w0 = 0xFD000000|AF614_FIELD(3,21,3)|AF614_FIELD(2,19,2);
            _g->w1 = (u32)timg;
        }
        AF614_SET_TILE((*gfx)++,3,2,0,tmem,7,cms,cmt,masks,maskt);
        AF614_SYNC((*gfx)++,0xE6000000);
        AF614_LOAD_BLOCK((*gfx)++,((*width * *height + 1) >> 1) - 1,AF614_CALC_DXT(*width,1));
        {
            AF614Gfx *_g = (*gfx)++;
            _g->w0 = 0xE7000000; _g->w1 = 0;
        }
        AF614_SET_TILE((*gfx)++,3,1,(*width + 7) >> 3,tmem,rtile,cms,cmt,masks,maskt);
        AF614_SET_TILE_SIZE((*gfx)++,rtile,*width,*height);
    } else if (*(s16 *)(sprite + 2) & AF614_SPRITE_I8) {
        {
            AF614Gfx *_g = (*gfx)++;
            _g->w0 = 0xFD000000|AF614_FIELD(4,21,3)|AF614_FIELD(2,19,2);
            _g->w1 = (u32)timg;
        }
        AF614_SET_TILE((*gfx)++,4,2,0,tmem,7,cms,cmt,masks,maskt);
        AF614_SYNC((*gfx)++,0xE6000000);
        AF614_LOAD_BLOCK((*gfx)++,((*width * *height + 1) >> 1) - 1,AF614_CALC_DXT(*width,1));
        {
            AF614Gfx *_g = (*gfx)++;
            _g->w0 = 0xE7000000; _g->w1 = 0;
        }
        AF614_SET_TILE((*gfx)++,4,1,(*width + 7) >> 3,tmem,rtile,cms,cmt,masks,maskt);
        AF614_SET_TILE_SIZE((*gfx)++,rtile,*width,*height);
    } else if (*(s16 *)(sprite + 2) & AF614_SPRITE_CI4) {
        {
            AF614Gfx *_g = (*gfx)++;
            _g->w0 = 0xFD000000|AF614_FIELD(0,21,3)|0x100000;
            _g->w1 = (u32)timg;
        }
        AF614_SET_TILE((*gfx)++,0,2,0,tmem,7,cms,cmt,masks,maskt);
        AF614_SYNC((*gfx)++,0xE6000000);
        AF614_LOAD_BLOCK((*gfx)++,((*width**height+3)>>2)-1,AF614_CALC_DXT_4B(*width));
        {
            AF614Gfx *_g = (*gfx)++;
            _g->w0 = 0xE7000000; _g->w1 = 0;
        }
        AF614_SET_TILE((*gfx)++,0,0,((*width>>1)+7)>>3,tmem,rtile,cms,cmt,masks,maskt);
        AF614_SET_TILE_SIZE((*gfx)++,rtile,*width,*height);
    } else if (*(s16 *)(sprite + 2) & AF614_SPRITE_IA4) {
        {
            AF614Gfx *_g = (*gfx)++;
            _g->w0 = 0xFD000000|AF614_FIELD(3,21,3)|0x100000;
            _g->w1 = (u32)timg;
        }
        AF614_SET_TILE((*gfx)++,3,2,0,tmem,7,cms,cmt,masks,maskt);
        AF614_SYNC((*gfx)++,0xE6000000);
        AF614_LOAD_BLOCK((*gfx)++,((*width**height+3)>>2)-1,AF614_CALC_DXT_4B(*width));
        {
            AF614Gfx *_g = (*gfx)++;
            _g->w0 = 0xE7000000; _g->w1 = 0;
        }
        AF614_SET_TILE((*gfx)++,3,0,((*width>>1)+7)>>3,tmem,rtile,cms,cmt,masks,maskt);
        AF614_SET_TILE_SIZE((*gfx)++,rtile,*width,*height);
    } else if (*(s16 *)(sprite + 2) & AF614_SPRITE_I4) {
        {
            AF614Gfx *_g = (*gfx)++;
            _g->w0 = 0xFD000000|AF614_FIELD(4,21,3)|0x100000;
            _g->w1 = (u32)timg;
        }
        AF614_SET_TILE((*gfx)++,4,2,0,tmem,7,cms,cmt,masks,maskt);
        AF614_SYNC((*gfx)++,0xE6000000);
        AF614_LOAD_BLOCK((*gfx)++,((*width**height+3)>>2)-1,AF614_CALC_DXT_4B(*width));
        {
            AF614Gfx *_g = (*gfx)++;
            _g->w0 = 0xE7000000; _g->w1 = 0;
        }
        AF614_SET_TILE((*gfx)++,4,0,((*width>>1)+7)>>3,tmem,rtile,cms,cmt,masks,maskt);
        AF614_SET_TILE_SIZE((*gfx)++,rtile,*width,*height);
    }
}

// Larger of the two header dimensions (at least 1); 1 if sprite is NULL.
s32 func_800B0CFC(s16 *sprite)
{
    s32 size;

    if (sprite == 0) {
        return 1;
    }
    size = (sprite[7] < sprite[6]) ? sprite[6] : sprite[7];
    return (size <= 0) ? 1 : size;
}
