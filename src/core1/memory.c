#include <ultra64.h>

void rare_memcpy(void *dst, void *src, int length)
{
    while (length > 0) {
        *(u8 *) dst = *(u8 *) src;
        length--;
        dst = (u8 *) dst + 1;
        src = (u8 *) src + 1;
    }
}

void aligned4_memcpy(void *dst, void *src, int length)
{
    while (length > 0) {
        *(u32 *) dst = *(u32 *) src;
        length -= 4;
        dst = (u32 *) dst + 1;
        src = (u32 *) src + 1;
    }
}

void rare_memmove(void *dst, void *src, int length)
{
    if (dst < src) {
        while (length--) {
            *(u8 *) dst = *(u8 *) src;
            dst = (u8 *) dst + 1;
            src = (u8 *) src + 1;
        }
    } else {
        dst = (u8 *) dst + length - 1;
        src = (u8 *) src + length - 1;
        while (length--) {
            *(u8 *) dst = *(u8 *) src;
            dst = (u8 *) dst - 1;
            src = (u8 *) src - 1;
        }
    }
}

void aligned4_memmove(void *dst, void *src, int length)
{
    length /= (s32) sizeof(u32);

    if (dst < src) {
        while (length--) {
            *(u32 *) dst = *(u32 *) src;
            dst = (u32 *) dst + 1;
            src = (u32 *) src + 1;
        }
    } else {
        dst = (u32 *) dst + length - 1;
        src = (u32 *) src + length - 1;
        while (length--) {
            *(u32 *) dst = *(u32 *) src;
            dst = (u32 *) dst - 1;
            src = (u32 *) src - 1;
        }
    }
}

void rare_memset(void *dst, u8 value, int length)
{
    u8 *cur = (u8 *) dst;
    u8 *end = (u8 *) dst + length;
    while (cur < end) {
        *cur = value;
        cur++;
    }
}
