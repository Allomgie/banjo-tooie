#include "common.h"

extern u32 func_801168AC(u64 *);

// Hashes [start, end) forward, then backward, into two 32-bit halves.
void func_80800000_glcrc(u8 *start, u8 *end, u32 *out)
{
    u32 hash_fwd;
    u32 hash_bwd;
    u64 state;
    s32 shift;
    u8 *p;

    shift = 0;
    // Seed.
    state = 0x8F809F473108B3C1ULL;
    hash_fwd = 0;
    hash_bwd = 0;
    for (p = start; p < end; p++, shift += 7) {
        state += *p << (shift & 0xF);
        hash_fwd ^= func_801168AC(&state);
    }
    for (p = end - 1; p >= start; p--, shift += 3) {
        state += *p << (shift & 0xF);
        hash_bwd ^= func_801168AC(&state);
    }
    out[0] = hash_fwd;
    out[1] = hash_bwd;
}

// Writes the checksum into the last 8 bytes of buf.
s32 glcrc_entrypoint_0(u8 *buf, s32 size)
{
    u8 *crc = buf + size - 8;
    func_80800000_glcrc(buf, crc, crc);
    return *(s32 *) crc;
}

// Verifies the checksum in the last 8 bytes of buf; 0x6E382 on mismatch.
s32 glcrc_entrypoint_1(u8 *buf, s32 size)
{
    u32 computed[2];
    u32 *stored;

    stored = (u32 *) (buf + size - 8);
    func_80800000_glcrc(buf, stored, computed);
    return (stored[0] != computed[0] || stored[1] != computed[1]) ? 0x6E382 : 0;
}
