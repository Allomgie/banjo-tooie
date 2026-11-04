// Rare's memory helpers: byte and 4-byte aligned memcpy and memmove, plus a byte memset.
#include <ultra64.h>

// Custom memcpy: void return and signed length.
void rare_memcpy(void *dst, void *src, int length)
{
    while (length > 0) {
        *(u8 *) dst = *(u8 *) src;
        length--;
        dst = (u8 *) dst + 1;
        src = (u8 *) src + 1;
    }
}

// Custom memcpy in 4-byte steps. Both pointers must be 4-byte aligned.
void aligned4_memcpy(void *dst, void *src, int length)
{
    while (length > 0) {
        *(u32 *) dst = *(u32 *) src;
        length -= 4;
        dst = (u32 *) dst + 1;
        src = (u32 *) src + 1;
    }
}

// Custom memmove: void return and signed length.
void rare_memmove(void *dst, void *src, int length)
{
    // Pick the copy direction so source bytes are not overwritten before they are read.
    if (dst < src) {
        // Copy forwards.
        while (length--) {
            *(u8 *) dst = *(u8 *) src;
            dst = (u8 *) dst + 1;
            src = (u8 *) src + 1;
        }
    } else {
        // Copy backwards.
        dst = (u8 *) dst + length - 1;
        src = (u8 *) src + length - 1;
        while (length--) {
            *(u8 *) dst = *(u8 *) src;
            dst = (u8 *) dst - 1;
            src = (u8 *) src - 1;
        }
    }
}

// Custom memmove in 4-byte steps. Both pointers must be 4-byte aligned.
void aligned4_memmove(void *dst, void *src, int length)
{
    // Matching: the s32 cast makes the division signed. Converts length to words.
    length /= (s32) sizeof(u32);

    // Pick the copy direction so source words are not overwritten before they are read.
    if (dst < src) {
        // Copy forwards.
        while (length--) {
            *(u32 *) dst = *(u32 *) src;
            dst = (u32 *) dst + 1;
            src = (u32 *) src + 1;
        }
    } else {
        // Copy backwards.
        dst = (u32 *) dst + length - 1;
        src = (u32 *) src + length - 1;
        while (length--) {
            *(u32 *) dst = *(u32 *) src;
            dst = (u32 *) dst - 1;
            src = (u32 *) src - 1;
        }
    }
}

// Custom memset: void return, u8 value and signed length.
void rare_memset(void *dst, u8 value, int length)
{
    u8 *cur = (u8 *) dst;
    u8 *end = (u8 *) dst + length;
    while (cur < end) {
        *cur = value;
        cur++;
    }
}
