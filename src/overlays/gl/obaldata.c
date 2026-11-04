// Global-settings block serializer: a 0x80-byte image with a version byte and the data of two
// providers; build with CRC, apply, version check, clear and size.
#include "common.h"

typedef void (*GlobalDataQuery)(s32 *, void **);
extern GlobalDataQuery D_80800238_glglobaldata[];
extern GlobalDataQuery D_80800230_glglobaldata[];
extern void rare_memcpy(void *, void *, s32);
extern s32 _glcrc_entrypoint_0(void *, s32);
int glglobaldata_entrypoint_4();

// Settings image: 0x80 bytes, version byte 8, then the data of the two providers.
// Computes the total size (result unused).
void glglobaldata_entrypoint_0(void)
{
    s32 i;
    s32 total;
    s32 size;
    void *data;
    total = 1;
    for (i = 0; i < 2; i++) {
        ((GlobalDataQuery *) D_80800230_glglobaldata)[i](&size, &data);
        total += size;
    }
}

// Checks the version byte.
int glglobaldata_entrypoint_1(u8 *buf)
{
    return buf[0] == 8;
}

// Applies the image: copies each provider's block out of buf.
// Matching: the line breaks in this function are needed for the match.
void glglobaldata_entrypoint_2(s32 buf)
{
    s8 _sfpad[8];
    s32 size;
    s32 data;
    void (**provider)(s32 *, s32 *);
    s32 offset;
    offset = 1;
    provider = &D_80800230_glglobaldata; do { (*provider)(&size, &data); rare_memcpy(data, (void *) ((char *) buf + offset), size);
        provider += 1;
        offset += size;
    }
    while (provider != (void *) &D_80800238_glglobaldata);
}

s32 func_80800124_glglobaldata(u8 *buf, s32 *offset)
{
    buf[*offset + 0] = 8;
    (*offset)++;
}

// Builds the image (version byte + provider data) and returns its CRC.
s32 glglobaldata_entrypoint_3(u8 *buf)
{
    s32 i;
    s32 offset;
    s32 size;
    void *data;

    glglobaldata_entrypoint_4(buf);
    offset = 0;
    func_80800124_glglobaldata(buf, &offset);
    for (i = 0; i < 2; i++) {
        D_80800230_glglobaldata[i](&size, &data);
        rare_memcpy(buf + offset, data, size);
        offset += size;
    }
    return _glcrc_entrypoint_0(buf, 0x80);
}

// Clears the 0x80-byte image.
int glglobaldata_entrypoint_4(buf)
u8 *buf;
{
    u32 i;
    for (i = 0; i < 0x80; i++) {
        buf[i] = 0;
    }
}

// TU-NOTE: .data is defined here in C. The tables hold pointers to functions of this file, and
// IDO's assembler schedules some of them differently unless the tables are in the same unit.
extern void func_800DABF0();
extern void func_800D21B0();
GlobalDataQuery D_80800230_glglobaldata[2] = {(void *) func_800DABF0, (void *) func_800D21B0};
GlobalDataQuery D_80800238_glglobaldata[2] = {0, 0};
