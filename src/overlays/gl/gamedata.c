#include "common.h"

// Section provider table entry. Length callbacks take no arguments.
typedef struct {
    s32 (*length)(void);
    void *read, *write;
} GameDataLength1446;
extern GameDataLength1446 D_808004F0_glgamedata[];
typedef struct GameDataCodec1627 {
    s32 (*length)(void);
    void (*read)(u8 *);
    void (*write)(u8 *, s32, u8, s32 *);
} GameDataCodec1627;
typedef struct {
    void (*read)(u8 *, s32);
    s32 pad_4;
    s32 pad_8;
} GameDataRecord60;
extern GameDataRecord60 D_808004F4_glgamedata[];
typedef struct {
    s32 (*func)(void);
    u8 pad_4[8];
} GameDataCheck;
int glgamedata_entrypoint_6();

// Length of section 1 (version).
s32 func_80800000_glgamedata()
{
    return 0x2;
}

// Section 1 writer: version byte.
s32 func_80800008_glgamedata(u8 *param_0)
{
    *param_0 = 0x1E;
}

// Total image size: magic plus every section with its 2-byte header.
void glgamedata_entrypoint_0(void)
{
    s32 total;
    s32 len;
    s32 i;

    total = 4;
    for (i = 0; i < 7; i++) {
        if (D_808004F0_glgamedata[i].length) {
            len = D_808004F0_glgamedata[i].length();
        } else {
            len = 0;
        }
        total += len;
        total += 2;
    }
}

// Writes the magic 'KHJC'.
s32 func_80800084_glgamedata(u32 *out)
{
    *out = 0x4B484A43;
    return 4;
}

// Appends one section {id, length, data} at *offset.
void func_80800098_glgamedata(void *image, s32 *offset, u8 id)
{
    s32 len;
    u8 *p;

    if (((GameDataCodec1627 *) D_808004F0_glgamedata)[id].length) {
        len = ((GameDataCodec1627 *) D_808004F0_glgamedata)[id].length();
    } else {
        len = 0;
    }
    p = (u8 *) image + *offset;
    p[0] = id;
    p[1] = len;
    p += 2;
    if (((GameDataCodec1627 *) D_808004F0_glgamedata)[id].write) {
        ((GameDataCodec1627 *) D_808004F0_glgamedata)[id].write(p, len, id,
                                                                       offset);
    }
    *offset += len + 2;
}

// Builds the save image and its checksum.
void glgamedata_entrypoint_1(void *image)
{
    s32 id;
    s32 offset = 0;
    glgamedata_entrypoint_6(image);
    offset = func_80800084_glgamedata(image);
    for (id = 1; id < 7; id++)
        func_80800098_glgamedata(image, &offset, (u8) id);
    func_80800098_glgamedata(image, &offset, 0);
    _glcrc_entrypoint_0(image, 0x1C0);
}

s32 func_808001E4_glgamedata(s32 image)
{
    return 4;
}

// Reads one section and calls its read callback; returns its id.
s32 func_808001F0_glgamedata(u8 *image, s32 *offset)
{
    s32 len;
    u8 *p;
    u8 id;
    void (*read)(u8 *, s32);

    p = image + *offset;
    id = p[0];
    len = p[1];
    p += 2;
    read = D_808004F4_glgamedata[id].read;
    if (read != NULL) {
        read(p, len);
    }
    *offset += len + 2;
    return id;
}

// Applies the save image section by section until the terminator (id 0).
s32 glgamedata_entrypoint_2(enum file_e image)
{
    u32 offset;

    offset = func_808001E4_glgamedata(image);
    while (func_808001F0_glgamedata(image, &offset) != 0)
        ;
}

// Offset of the first section (4), or 0 if the magic does not match.
s32 func_808002CC_glgamedata(image) void *image;
{
    s32 *head = (s32 *) image;
    return (*head == 0x4B484A43) ? 4 : 0;
}

// Finds section id; returns 1 and its data offset and length, else 0.
s32 glgamedata_entrypoint_3(u8 *image, u8 id, s32 *out_offset, s32 *out_len)
{
    u8 *p;
    u8 cur_id;

    *out_offset = func_808002CC_glgamedata(image);
    if (*out_offset == 0) {
        return 0;
    }
    do {
        p = image + *out_offset;
        cur_id = *p++;
        *out_len = *p;
        *out_offset += 2;
        if (cur_id == id) {
            return 1;
        }
        *out_offset += *out_len;
    } while (cur_id != 0);
    return 0;
}

// Checks the version section.
int glgamedata_entrypoint_4(u8 *image)
{
    u32 offset;
    u32 len;
    if (glgamedata_entrypoint_3(image, 1, &offset, &len)) {
        return image[offset] == 0x1E;
    }
    {
        return 0;
    }
}

// Validates the structure: 2 = bad magic or unknown id, 1 = length mismatch.
s32 glgamedata_entrypoint_5(u8 *image)
{
    s32 offset;
    u8 id;
    s32 expected_len;
    u8 *hdr;

    offset = func_808002CC_glgamedata();
    if (offset == 0) {
        return 2;
    }
    do {
        id = image[offset];
        hdr = image + offset + 1;
        if (id >= 7) {
            return 2;
        }
        if (((GameDataCheck *) D_808004F0_glgamedata)[id].func != NULL) {
            expected_len = ((GameDataCheck *) D_808004F0_glgamedata)[id].func();
        } else {
            expected_len = 0;
        }
        if (expected_len != *hdr) {
            return 1;
        }
        offset += *hdr + 2;
    } while (id != 0);
    return 0;
}

// Clears the image.
int glgamedata_entrypoint_6(image)
u8 *image;
{
    u32 i;
    for (i = 0; i < 0x1C0; i++) {
        image[i] = 0;
    }
}

extern void _glsavegame_entrypoint_5();
extern void _glsavegame_entrypoint_6();
extern void func_800DAFC4();
extern void func_800DB67C();
extern void func_800DAFCC();
extern void func_800D1C70();
extern void func_800D1C78();
extern void func_800D1DFC();
extern void func_800D2140();
extern void func_800D2148();
extern void func_800D2188();
extern void func_800DAC08();
extern void func_800DAC10();
extern void func_800DAC50();
// TU-NOTE: the .data of this overlay is defined here in C; values are taken from the ROM.
// The tables hold pointers to functions of this file, and IDO's assembler
// schedules some of them differently unless they are in the same unit.
// D_808004F4_glgamedata = D_808004F0_glgamedata + 0x4 (linker symbol).
GameDataLength1446 D_808004F0_glgamedata[7] = {0,
                                               0,
                                               0,
                                               (void *) func_80800000_glgamedata,
                                               0,
                                               (void *) func_80800008_glgamedata,
                                               (void *) _glsavegame_entrypoint_5,
                                               0,
                                               (void *) _glsavegame_entrypoint_6,
                                               (void *) func_800DAFC4,
                                               (void *) func_800DB67C,
                                               (void *) func_800DAFCC,
                                               (void *) func_800D1C70,
                                               (void *) func_800D1C78,
                                               (void *) func_800D1DFC,
                                               (void *) func_800D2140,
                                               (void *) func_800D2148,
                                               (void *) func_800D2188,
                                               (void *) func_800DAC08,
                                               (void *) func_800DAC10,
                                               (void *) func_800DAC50};
GameDataLength1446 D_80800544_glgamedata[1] = {0, 0, 0};
