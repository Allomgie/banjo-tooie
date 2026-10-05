#include "common.h"

#define AF614_FIELD(v,s,n) (((u32)(v) & ((1U << (n))-1)) << (s))
#define AF614_MAX(a,b) ((a) > (b) ? (a) : (b))
#define AF614_MIN(a,b) ((a) < (b) ? (a) : (b))
#define AF614_TEXEL_WORDS(w,b) AF614_MAX(1, ((w)*(b)/8))
#define AF614_CALC_DXT(w,b) ((2048 + AF614_TEXEL_WORDS(w,b) - 1)/AF614_TEXEL_WORDS(w,b))
#define AF614_CALC_DXT_4B(w) ((2048 + AF614_MAX(1,(w)/16) - 1)/AF614_MAX(1,(w)/16))
#define AF614_COMMAND(pkt,a,b) { AF614Gfx *_g=(pkt); _g->w0=(a); _g->w1=(u32)(b); }
#define AF614_SYNC(pkt,a) { AF614Gfx *_g=(pkt); _g->w0=(a); _g->w1=0; }
#define AF614_SET_TILE(pkt,fmt,siz,line,tmem,tile,cms,cmt,masks,maskt) { \
 AF614Gfx *_g=(pkt); \
 _g->w0=0xF5000000|AF614_FIELD(fmt,21,3)|AF614_FIELD(siz,19,2)|AF614_FIELD(line,9,9)|AF614_FIELD(tmem,0,9); \
 _g->w1=AF614_FIELD(tile,24,3)|AF614_FIELD(cmt,18,2)|AF614_FIELD(maskt,14,4)|AF614_FIELD(cms,8,2)|AF614_FIELD(masks,4,4); }
#define AF614_LOAD_BLOCK(pkt,count,dxt) { AF614Gfx *_g=(pkt); _g->w0=0xF3000000; \
 _g->w1=0x07000000|AF614_FIELD(AF614_MIN(count,2047),12,12)|AF614_FIELD(dxt,0,12); }
#define AF614_SET_TILE_SIZE(pkt,tile,w,h) AF614_COMMAND(pkt,0xF2000000,AF614_FIELD(tile,24,3)|AF614_FIELD(((w)-1)<<2,12,12)|AF614_FIELD(((h)-1)<<2,0,12))
#define AF614_LOAD_TLUT(pkt,img,count) { \
 { AF614Gfx *_g=(pkt); _g->w0=0xE3001001; _g->w1=0x8000; } \
 AF614_COMMAND(pkt,0xFD100000,img); AF614_SYNC(pkt,0xE8000000); \
 { AF614Gfx *_g=(pkt); _g->w0=0xF5000100; _g->w1=0x07000000; } \
 AF614_SYNC(pkt,0xE6000000); \
 { AF614Gfx *_g=(pkt); _g->w0=0xF0000000; _g->w1=0x07000000|((count)<<14); } \
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
typedef struct { u32 w0, w1; } AF614Gfx;

func_800AF5A0(s16 *param_0) {
    return param_0[0];
}

func_800AF5A8(s16 *param_0) {
    return param_0[1];
}

int func_800AF5B0(s16 param_0[3], s32 *param_1, s32 *param_2)
{
  s16 *new_var;
  int new_var3;
  s16 new_var2;
  new_var = &(new_var = param_0)[1];
  ;
  new_var++;
  *param_1 = *new_var;
  new_var--;
  new_var3 = 2;
  *param_2 = new_var[new_var3];
}

void func_800AF5C4(u8 *param_0, s32 *param_1, s32 *param_2) {
    *param_1 = (s32) *(s16 *)(param_0 + 8);
    *param_2 = (s32) *(s16 *)(param_0 + 10);
}

int func_800AF5D8(s32 param_0)
{
  s16 *new_var;
  new_var = (s16 *) (((int) param_0) + 0x12);
  return (*new_var) + ((0, param_0));
}

s32 func_800AF5E4(s32 param_0)
{
  s32 new_var;
  s32 new_var2;
  new_var2 = (*((s32 *) (param_0 + 0x14))) & 0xFFFFFFFFFFFFFFFF;
  new_var2 = new_var2;
  new_var = new_var2;
  return param_0 + new_var;
}

s32 func_800AF5F0(s32 param_0)
{
  s32 new_var;
  s32 new_var2;
  new_var2 = (*((s32 *) (param_0 + 0x18))) & 0xFFFFFFFFFFFFFFFF;
  new_var2 = new_var2;
  new_var = new_var2;
  return param_0 + new_var;
}

func_800AF5FC(s32 param_0, s32 param_1){
    return (void*)((char*)param_0 + 0x1C + param_1 * 0xC);
}

void func_800AF614(AF614Gfx **gfx, u8 *sprite, s32 frame, s32 tmem, s32 rtile, s32 cms, s32 cmt, s32 *width, s32 *height)
{
    u8 *sprite_frame;
    s32 masks;
    s32 maskt;
    s32 timg;
    s32 remaining;
    /* Tooie uses a 12-byte frame directory and a separate sprite data base. */
    sprite_frame=func_800AF5FC(sprite,frame);
    timg=func_800AF5D8(sprite);
    /* Frame +8: image offset from that base; frame +6: palette offset from timg. */
    timg+=*(s32 *)(sprite_frame+8);
    /* Unlike the BK chunk loader, dimensions belong to the sprite header. */
    *width=*(s16 *)(sprite+8);
    *height=*(s16 *)(sprite+10);
    /* CI4/CI8 load an RGBA16 TLUT; other formats leave the LUT state untouched. */
    if (*(s16 *)(sprite + 2) & AF614_SPRITE_CI4) {
        AF614_LOAD_TLUT((*gfx)++,timg+*(s16 *)(sprite_frame+6),15);
    } else if (*(s16 *)(sprite + 2) & AF614_SPRITE_CI8) {
        AF614_LOAD_TLUT((*gfx)++,timg+*(s16 *)(sprite_frame+6),255);
    }
    /* For positive dimensions divisible by eight, compute ceil(log2(size)).
     * Positive dimensions not divisible by eight use mask zero.
     * Initialize the counter inside each branch to preserve its lifetime. */
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
    /* BK counterpart: rare_gDPLoadMultiBlock / rare_gDPLoadMultiBlock_4b.
     * Each branch emits image, load tile, load sync, load block, pipe sync,
     * render tile, then tile size. Tooie uses zero texture origins.
     *
     * Reconstruction note: image stores use separate source lines; pipe-sync
     * stores currently share a line after the pointer initializer. The tested
     * SDK-shaped macro forms differ only in scheduling. Recovering the exact
     * original macro/preprocessor form remains open; reverify any reformat. */
    if (*(s16 *)(sprite + 2) & AF614_SPRITE_RGBA32) {
        /* RGBA32: the render-line stride uses the SDK's two-byte line unit. */
        {
            AF614Gfx *_g = (*gfx)++;
            _g->w0 = 0xFD000000|AF614_FIELD(0,21,3)|AF614_FIELD(3,19,2);
            _g->w1 = (u32)(timg);
        }
        AF614_SET_TILE((*gfx)++,0,3,0,tmem,7,cms,cmt,masks,maskt);
        AF614_SYNC((*gfx)++,0xE6000000);
        AF614_LOAD_BLOCK((*gfx)++,((*width) * (*height)) - 1,AF614_CALC_DXT(*width,4));
        {
            AF614Gfx *_g = (*gfx)++;
            _g->w0 = 0xE7000000; _g->w1 = 0;
        }
        AF614_SET_TILE((*gfx)++,0,3,((*width) * 2 + 7) >> 3,tmem,rtile,cms,cmt,masks,maskt);
        AF614_SET_TILE_SIZE((*gfx)++,rtile,*width,*height);
    } else if (*(s16 *)(sprite + 2) & AF614_SPRITE_RGBA16) {
        /* RGBA16. */
        {
            AF614Gfx *_g = (*gfx)++;
            _g->w0 = 0xFD000000|AF614_FIELD(0,21,3)|AF614_FIELD(2,19,2);
            _g->w1 = (u32)(timg);
        }
        AF614_SET_TILE((*gfx)++,0,2,0,tmem,7,cms,cmt,masks,maskt);
        AF614_SYNC((*gfx)++,0xE6000000);
        AF614_LOAD_BLOCK((*gfx)++,((*width) * (*height)) - 1,AF614_CALC_DXT(*width,2));
        {
            AF614Gfx *_g = (*gfx)++;
            _g->w0 = 0xE7000000; _g->w1 = 0;
        }
        AF614_SET_TILE((*gfx)++,0,2,((*width) * 2 + 7) >> 3,tmem,rtile,cms,cmt,masks,maskt);
        AF614_SET_TILE_SIZE((*gfx)++,rtile,*width,*height);
    } else if (*(s16 *)(sprite + 2) & AF614_SPRITE_IA16) {
        /* IA16. */
        {
            AF614Gfx *_g = (*gfx)++;
            _g->w0 = 0xFD000000|AF614_FIELD(3,21,3)|AF614_FIELD(2,19,2);
            _g->w1 = (u32)(timg);
        }
        AF614_SET_TILE((*gfx)++,3,2,0,tmem,7,cms,cmt,masks,maskt);
        AF614_SYNC((*gfx)++,0xE6000000);
        AF614_LOAD_BLOCK((*gfx)++,((*width) * (*height)) - 1,AF614_CALC_DXT(*width,2));
        {
            AF614Gfx *_g = (*gfx)++;
            _g->w0 = 0xE7000000; _g->w1 = 0;
        }
        AF614_SET_TILE((*gfx)++,3,2,((*width) * 2 + 7) >> 3,tmem,rtile,cms,cmt,masks,maskt);
        AF614_SET_TILE_SIZE((*gfx)++,rtile,*width,*height);
    } else if (*(s16 *)(sprite + 2) & AF614_SPRITE_CI8) {
        /* CI8: transfer as 16-bit texels, then render as 8-bit CI. */
        {
            AF614Gfx *_g = (*gfx)++;
            _g->w0 = 0xFD000000|AF614_FIELD(2,21,3)|AF614_FIELD(2,19,2);
            _g->w1 = (u32)(timg);
        }
        AF614_SET_TILE((*gfx)++,2,2,0,tmem,7,cms,cmt,masks,maskt);
        AF614_SYNC((*gfx)++,0xE6000000);
        AF614_LOAD_BLOCK((*gfx)++,(((*width) * (*height) + 1) >> 1) - 1,AF614_CALC_DXT(*width,1));
        {
            AF614Gfx *_g = (*gfx)++;
            _g->w0 = 0xE7000000; _g->w1 = 0;
        }
        AF614_SET_TILE((*gfx)++,2,1,((*width) + 7) >> 3,tmem,rtile,cms,cmt,masks,maskt);
        AF614_SET_TILE_SIZE((*gfx)++,rtile,*width,*height);
    } else if (*(s16 *)(sprite + 2) & AF614_SPRITE_IA8) {
        /* IA8: transfer as 16-bit texels. */
        {
            AF614Gfx *_g = (*gfx)++;
            _g->w0 = 0xFD000000|AF614_FIELD(3,21,3)|AF614_FIELD(2,19,2);
            _g->w1 = (u32)(timg);
        }
        AF614_SET_TILE((*gfx)++,3,2,0,tmem,7,cms,cmt,masks,maskt);
        AF614_SYNC((*gfx)++,0xE6000000);
        AF614_LOAD_BLOCK((*gfx)++,(((*width) * (*height) + 1) >> 1) - 1,AF614_CALC_DXT(*width,1));
        {
            AF614Gfx *_g = (*gfx)++;
            _g->w0 = 0xE7000000; _g->w1 = 0;
        }
        AF614_SET_TILE((*gfx)++,3,1,((*width) + 7) >> 3,tmem,rtile,cms,cmt,masks,maskt);
        AF614_SET_TILE_SIZE((*gfx)++,rtile,*width,*height);
    } else if (*(s16 *)(sprite + 2) & AF614_SPRITE_I8) {
        /* I8: transfer as 16-bit texels. */
        {
            AF614Gfx *_g = (*gfx)++;
            _g->w0 = 0xFD000000|AF614_FIELD(4,21,3)|AF614_FIELD(2,19,2);
            _g->w1 = (u32)(timg);
        }
        AF614_SET_TILE((*gfx)++,4,2,0,tmem,7,cms,cmt,masks,maskt);
        AF614_SYNC((*gfx)++,0xE6000000);
        AF614_LOAD_BLOCK((*gfx)++,(((*width) * (*height) + 1) >> 1) - 1,AF614_CALC_DXT(*width,1));
        {
            AF614Gfx *_g = (*gfx)++;
            _g->w0 = 0xE7000000; _g->w1 = 0;
        }
        AF614_SET_TILE((*gfx)++,4,1,((*width) + 7) >> 3,tmem,rtile,cms,cmt,masks,maskt);
        AF614_SET_TILE_SIZE((*gfx)++,rtile,*width,*height);
    } else if (*(s16 *)(sprite + 2) & AF614_SPRITE_CI4) {
        /* CI4 flag: the target deliberately encodes RGBA format in this 4-bit path. */
        {
            AF614Gfx *_g = (*gfx)++;
            _g->w0 = 0xFD000000|AF614_FIELD(0,21,3)|0x100000;
            _g->w1 = (u32)(timg);
        }
        AF614_SET_TILE((*gfx)++,0,2,0,tmem,7,cms,cmt,masks,maskt);
        AF614_SYNC((*gfx)++,0xE6000000);
        AF614_LOAD_BLOCK((*gfx)++,(((*width)*(*height)+3)>>2)-1,AF614_CALC_DXT_4B(*width));
        {
            AF614Gfx *_g = (*gfx)++;
            _g->w0 = 0xE7000000; _g->w1 = 0;
        }
        AF614_SET_TILE((*gfx)++,0,0,(((*width)>>1)+7)>>3,tmem,rtile,cms,cmt,masks,maskt);
        AF614_SET_TILE_SIZE((*gfx)++,rtile,*width,*height);
    } else if (*(s16 *)(sprite + 2) & AF614_SPRITE_IA4) {
        /* IA4: pack four texels per 16-bit transfer unit. */
        {
            AF614Gfx *_g = (*gfx)++;
            _g->w0 = 0xFD000000|AF614_FIELD(3,21,3)|0x100000;
            _g->w1 = (u32)(timg);
        }
        AF614_SET_TILE((*gfx)++,3,2,0,tmem,7,cms,cmt,masks,maskt);
        AF614_SYNC((*gfx)++,0xE6000000);
        AF614_LOAD_BLOCK((*gfx)++,(((*width)*(*height)+3)>>2)-1,AF614_CALC_DXT_4B(*width));
        {
            AF614Gfx *_g = (*gfx)++;
            _g->w0 = 0xE7000000; _g->w1 = 0;
        }
        AF614_SET_TILE((*gfx)++,3,0,(((*width)>>1)+7)>>3,tmem,rtile,cms,cmt,masks,maskt);
        AF614_SET_TILE_SIZE((*gfx)++,rtile,*width,*height);
    } else if (*(s16 *)(sprite + 2) & AF614_SPRITE_I4) {
        /* I4: pack four texels per 16-bit transfer unit. */
        {
            AF614Gfx *_g = (*gfx)++;
            _g->w0 = 0xFD000000|AF614_FIELD(4,21,3)|0x100000;
            _g->w1 = (u32)(timg);
        }
        AF614_SET_TILE((*gfx)++,4,2,0,tmem,7,cms,cmt,masks,maskt);
        AF614_SYNC((*gfx)++,0xE6000000);
        AF614_LOAD_BLOCK((*gfx)++,(((*width)*(*height)+3)>>2)-1,AF614_CALC_DXT_4B(*width));
        {
            AF614Gfx *_g = (*gfx)++;
            _g->w0 = 0xE7000000; _g->w1 = 0;
        }
        AF614_SET_TILE((*gfx)++,4,0,(((*width)>>1)+7)>>3,tmem,rtile,cms,cmt,masks,maskt);
        AF614_SET_TILE_SIZE((*gfx)++,rtile,*width,*height);
    }
}

s32 func_800B0CFC(s16 *param_0)
{
    s32 wert;

    if (param_0 == 0) {
        return 1;
    }
    wert = (param_0[7] < param_0[6]) ? param_0[6] : param_0[7];
    return (wert <= 0) ? 1 : wert;
}
