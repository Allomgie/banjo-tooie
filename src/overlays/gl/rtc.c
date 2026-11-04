// Block texture decompressor: 4x4 tiles of two endpoints plus 2-bit indices, S3TC-like.
#include "common.h"

void func_80800170_glrtc();
void func_808002C8_glrtc();
void func_8080031C_glrtc();
void func_80800474_glrtc();
void func_808005B0_glrtc();

// Decode a block-compressed texture: 3-byte header {format, tiles across, tiles down},
// then 4x4 tiles. `out` gets 16-bit (format 0) or 32-bit (formats 1, 2) pixels.
void glrtc_entrypoint_0(u8 *data, u8 *out)
{
    u8 *header;
    u8 *src;
    s32 stride;
    s32 i;
    s32 j;
    // Matching: the unused locals are needed for the match.
    s32 unused0;
    s32 unused1;
    s32 unused2;
    s32 unused3;

    header = data;
    src = data + 3;
    stride = data[1] * 4;
    for (i = 0; i < header[2]; i++) {
        for (j = 0; j < header[1]; j++) {
            switch (data[0]) {
                case 0:
                    func_80800170_glrtc(&src, (u16 *) out + i * 4 * stride + j * 4,
                                        stride);
                    break;
                case 1:
                    func_8080031C_glrtc(&src, (u32 *) out + i * 4 * stride + j * 4,
                                        stride);
                    break;
                case 2:
                    func_80800474_glrtc(&src, (u32 *) out + i * 4 * stride + j * 4,
                                        stride);
            }
        }
    }
}

// Format 0 tile: two RGBA5551 endpoints, one 2-bit index plane.
void func_80800170_glrtc(src, out, stride) u8 **src;
u16 *out;
s32 stride;
{
    u16 endpoints[2];
    u32 indices;
    u16 palette[4];
    u8 *cursor = *src;
    s32 y;
    s32 x;

    bcopy(cursor, endpoints, 4);
    cursor += 4;
    palette[0] = endpoints[0];
    palette[1] = 1;
    palette[2] = 1;
    palette[3] = endpoints[1];
    func_808002C8_glrtc(palette, 0xF800);
    func_808002C8_glrtc(palette, 0x7C0);
    func_808002C8_glrtc(palette, 0x3E);
    bcopy(cursor, &indices, 4);
    cursor += 4;
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            out[x] = palette[indices & 3];
            indices >>= 2;
        }
        out += stride;
    }
    *src = cursor;
}

// Fill palette[1], palette[2] with the 1/3 and 2/3 interpolation of one colour channel.
void func_808002C8_glrtc(palette, mask) u16 *palette;
u16 mask;
{
    u16 lo;
    u16 hi;
    u16 step;
    lo = palette[0] & mask;
    hi = palette[3] & mask;
    step = ((hi - lo) / 3) & (int) mask;
    palette[1] |= lo + step;
    palette[2] |= hi - step;
}

// Format 1 tile: two RGBA5551 endpoints, one index plane per colour channel (alpha 255).
void func_8080031C_glrtc(src, out, stride) u8 **src;
s32 out;
s32 stride;
{
    u16 endpoints[2];
    u8 channels[4][4];
    u8 *cursor = *src;
    u32 indices;
    s32 chan;
    u8 *plane;

    bcopy(cursor, endpoints, 4);
    cursor += 4;
    channels[0][0] = (endpoints[0] & 0xF800) >> 8;
    channels[1][0] = (endpoints[0] & 0x7C0) >> 3;
    channels[2][0] = (endpoints[0] & 0x3E) << 2;
    channels[3][0] = 255;
    channels[0][3] = (endpoints[1] & 0xF800) >> 8;
    channels[1][3] = (endpoints[1] & 0x7C0) >> 3;
    channels[2][3] = (endpoints[1] & 0x3E) << 2;
    channels[3][3] = 255;
    for (chan = 0, plane = &channels[0][0]; chan != 3; chan++, plane += 4) {
        if (plane[0] == plane[3])
            indices = 0;
        else {
            bcopy(cursor, &indices, 4);
            cursor += 4;
        }
        func_808005B0_glrtc(out, (u8) chan, stride, plane, indices);
    }
    // Matching: dead store and extra call after the loop are needed for the match.
    indices = 0;
    func_808005B0_glrtc(out, (u8) chan, stride, &channels[0][0], 0);
    *src = cursor;
}

// Format 2 tile: two 4x5-bit endpoints, one index plane per channel including alpha.
void func_80800474_glrtc(src, out, stride) u8 **src;
u32 out;
u32 stride;
{
    union {
        u64 all;
        u32 words[2];
        u8 bytes[8];
    } endpoints;
    u32 indices;
    u8 plane[4];
    s32 chan;
    u8 *cursor;
    u8 lo = 0;
    u8 hi = 0;

    cursor = *src;
    endpoints.bytes[3] = cursor[0];
    endpoints.bytes[2] = cursor[1];
    endpoints.bytes[1] = cursor[2] & 0xF;
    cursor += 5;
    endpoints.bytes[7] = cursor[-3];
    endpoints.bytes[6] = cursor[-2];
    endpoints.bytes[5] = cursor[-1];
    // Matching: empty block steers IDO's register allocation.
    if (endpoints.words[0]) {
    }
    endpoints.words[1] >>= 4;
    for (chan = 0; chan < 4; chan++) {
        lo = (endpoints.words[0] << 3) & 0xFF;
        endpoints.words[0] >>= 5;
        hi = (endpoints.words[1] << 3) & 0xFF;
        endpoints.words[1] >>= 5;
        plane[3] = hi;
        plane[0] = lo;
        if (hi == lo) {
            indices = 0;
        } else {
            bcopy(cursor, &indices, 4);
            cursor += 4;
        }
        func_808005B0_glrtc(out, (u8) chan, stride, plane, indices);
    }
    // Matching: empty block after the loop, needed for the match.
    if (chan) {
    }
    *src = cursor;
}

// Write one channel of a 4x4 tile: indices select plane[0..3]; plane[1], plane[2] are
// interpolated first unless indices is 0.
void func_808005B0_glrtc(out, channel, stride, plane, indices) u8 *out;
u8 channel;
s32 stride;
u8 *plane;
u32 indices;
{
    s32 i;
    s32 j;
    // char rather than s32: only used in u8 stores, so the value is the same modulo 256.
    char step;

    if (indices != 0) {
        step = (plane[3] - plane[0]) / 3;
        plane[1] = plane[0] + step;
        plane[2] = plane[3] - step;
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            *(out + (j << 2) + channel) = plane[indices & 3];
            indices >>= 2;
        }
        out += stride << 2;
    }
}
