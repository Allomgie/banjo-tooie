#include "common.h"

#define va_arg(list, mode)                                                                         \
    ((mode *) (list = (char *) (sizeof(mode) > 4 ? ((int) list + 2 * 8 - 1) & -8                   \
                                                 : ((int) list + 2 * 4 - 1) & -4)))[-1]
typedef char *va_list;
void func_800E6AFC(char *, u8);
void func_800E6DB4(s32, s32);
void func_800E6DD8();
void func_800E7480(s32 param_0, char *fmt, va_list args);

// strcat
void func_800E6A10(u8 *dst, u8 *src)
{
    while (*dst != '\0') {
        dst++;
    }

    while (*src != '\0') {
        *dst = *src;
        dst++;
        src++;
    }
    *dst = '\0';
}

// Appends one character.
int func_800E6A58(dst, c)
u8 *dst;
u8 c;
{
    while (*dst != 0) {
        dst++;
    }

    *dst = c;
    {
        dst++;
    }
    *dst = 0;
}

// Appends each byte as hex, followed by a space.
void func_800E6A90(s32 dst, u8 *bytes)
{
    while (*bytes != 0) {
        func_800E6AFC(dst, *bytes++);
        func_800E6A10(dst, " ");
    }
}

// Appends a byte as 0xNN (lowercase hex).
void func_800E6AFC(char *str, u8 num)
{
    s32 i;
    s32 digit;
    while (*str != '\0') {
        str++;
    }
    *str = '0';
    str++;
    *str = 'x';
    str++;
    for (i = 1; i >= 0; i--) {
        digit = (num >> (i * 4)) & 0xF;
        if ((u8) (digit < 10)) {
            *str = '0' + digit;
        } else {
            *str = 'a' - 10 + digit;
        }
        str++;
    }
    *str = '\0';
}

// Returns -1 for negative values, 1 otherwise.
int func_800E6B7C(f32 *unk_0, f32 value)
{
    return (value < 0.0f) ? -1 : 1;
}

// Appends a float as integer part, '.' and two decimals.
void func_800E6BAC(char *str, f32 value)
{
    s32 int_part;
    char *unk_0;
    switch (func_800E6B7C(&unk_0, value)) {
        case 0:
            func_800E6A10(str, unk_0);
            break;
        case -1:
            func_800E6A10(str, "-");
            value = -value;
        case 1:
            int_part = value;
            func_800E6DB4(str, int_part);
            func_800E6A10(str, ".");
            if ((s32) ((value - int_part) * 100.0f) < 10)
                func_800E6A10(str, "0");
            func_800E6DB4(str, (value - int_part) * 100.0f);
    }
}

// Appends a float with the given number of decimals.
void func_800E6CA8(char *str, f32 value, s32 decimals)
{
    char *unk_0;
    switch (func_800E6B7C(&unk_0, value)) {
        case 0:
            func_800E6A10(str, unk_0);
            break;
        case -1:
            func_800E6A10(str, "-");
            value = -value;
        case 1:
            func_800E6DB4(str, value);
            if (decimals) {
                func_800E6A10(str, ".");
                while (decimals--) {
                    value -= (s32) value;
                    value *= 10.0f;
                    func_800E6DB4(str, value);
                }
            }
    }
}

// Appends an integer.
void func_800E6DB4(str, value) s32 str;
s32 value;
{
    func_800E6DD8(str, value, 0, 0);
}

// Appends an integer. With use_glyphs, digits are value + 0x10 (game font glyph indices).
void func_800E6DD8(str, value, prefix, use_glyphs) u8 *str;
s32 value;
u8 prefix;
s32 use_glyphs;
{
    s32 divisor;
    while (*str)
        str++;

if (value < 0) {
    *str++ = '-';
    value = -value;
} else if (prefix) {

*str++ = prefix;
}
divisor = 1000000000;
while (value < divisor)
    divisor /= 10;
if (divisor == 0) {
    *str++ = '0';

}
else
{
    while (divisor > 0) {
        if (use_glyphs)
            *str++ = value / divisor + 0x10;
        else
            *str++ = value / divisor + '0';
        value %= divisor;
        divisor /= 10;
    }

}
*str = 0;
}

// Appends a u32 as 0xXXXXXXXX (lowercase hex).
void func_800E6F7C(char *str, u32 num)
{
    s32 i;
    s32 digit;
    while (*str != '\0') {
        str++;
    }
    *str = '0';
    str++;
    *str = 'x';
    str++;
    for (i = 7; i >= 0; i--) {
        digit = (num >> (i * 4)) & 0xF;

if ((u8) (digit < 10)) {
    *str = '0' + digit;
} else {

*str = 'a' - 10 + digit;
}
str++;
}
*str = '\0';
}

// Like func_800E6F7C, but with a "0." prefix and uppercase digits.
void func_800E6FEC(char *str, u32 num)
{
    s32 i;
    s32 digit;
    while (*str != '\0') {
        str++;
    }
    *str = '0';
    str++;
    *str = '.';
    str++;
    for (i = 7; i >= 0; i--) {
        digit = (num >> (i * 4)) & 0xF;
        if ((u8) (digit < 10)) {
            *str = '0' + digit;
        } else {
            *str = 'A' - 10 + digit;
        }
        str++;
    }
    *str = '\0';
}

// Appends a byte as 0xNN (uppercase hex).
void func_800E705C(char *str, u8 num)
{
    s32 i;
    s32 digit;
    while (*str != '\0') {
        str++;
    }
    *str = '0';
    str++;
    *str = 'x';
    str++;
    for (i = 1; i >= 0; i--) {
        digit = (num >> (i * 4)) & 0xF;
        if ((u8) (digit < 10)) {
            *str = '0' + digit;
        } else {
            *str = 'A' - 10 + digit;
        }
        str++;
    }
    *str = '\0';
}

// strcmp
func_800E70DC(char *a, char *b)
{
    while (*a && *b && *a == *b) {
        a++;
        b++;
    }
    if (*a == *b)
        return 0;
    else if (*a == '\0' || *a < *b)
        return -1;
    return 1;
}

// strcpy
func_800E715C(u8 *dst, u8 *src)
{
    while (*src != '\0') {
        *dst++ = *src++;
    }
    *dst = '\0';
}

// strlen
s32 func_800E7188(u8 *str)
{
    u32 len = 0;
    while (*str++) {
        len++;
    }
    return len;
}

// Adds 2 to value when _gldialog_entrypoint_1() is true.
s32 func_800E71B8(s32 value)
{
    if (_gldialog_entrypoint_1()) {
        // Matching: the redundant empty if is needed for the match.
        if ((value && value) && value) {
        }
        return value + 2;
    }
    return value;
}

// Returns 1 when both strings reach their end or the delimiter at the same position.
func_800E71EC(char *delim, char *str_a, char *str_b)
{
    while (*str_a == *str_b) {
        str_a++;
        str_b++;
        if ((*str_a == '\0' || *str_a == *delim) &&
            (*str_b == '\0' || *str_b == *delim)) {
            return 1;
        }
    }
    return 0;
}

// Returns the position after the next delimiter in str.
func_800E7254(u8 *delim, u8 *str)
{
    while (*str != '\0' && *str != *delim) {
        str++;
    }

    if (*str == *delim) {
        str++;
    }
    return str;
}

// Copies src up to the delimiter into dst.
void func_800E729C(u8 *delim, u8 *dst, u8 *src)
{
    while ((*src != 0) && (*src != *delim)) {
        *dst = *src;
        src++;
        dst++;
    }
    *dst = 0;
}

// toupper, in place
s32 func_800E72E0(char *str)
{
    u8 *ptr = (u8 *) str;
    while (*(u8 *) ptr) {
        if ((*ptr >= 0x61) && (*ptr < 0x7B)) {
            *ptr -= 0x20;
        }
        ptr++;
    }
}

// tolower, in place
func_800E7324(u8 *str)
{
    u8 *ptr;
    ptr = str;
    while (*ptr != '\0') {
        if (0x41 <= *ptr && *ptr < 0x5B) {
            *ptr += 0x20;
        }
        ptr++;
    }
}

// Appends value as 32 binary digits.
int func_800E7368(s32 str, u32 value)
{
    s32 bit;
    u32 digit;
    for (bit = 31; bit >= 0; bit--) {
        if ((1 << bit) & value) {
            digit = 0x31;
        } else {
            digit = 0x30;

}
// Matching: the repeated & 0xFFu is needed for the match.
func_800E6A58(str,
              (((((((((digit & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu) &
                0xFFu) &
               0xFFu) &
                  0xFFu);
}
}

// Clears the string.
func_800E73D4(u8 *str)
{
    str[0] = 0;
}

// sprintf; the varargs start at first_arg.
int func_800E73DC(s32 dst, s32 fmt, short first_arg, s32 param_3)
{
    u8 *args;
    int align_mask;
    int mask;
    // Matching: the empty if and the extra variables are needed for the match.
    if (!align_mask) {
    }
    func_800E73D4(dst);
    args = &first_arg;
    mask = ~3;
    align_mask = mask;
    func_800E7480(dst, fmt, (((u32) args + 1) & align_mask) | 0);
}

// sprintf that appends to dst.
void func_800E7428(u8 *dst, u8 *fmt, ...)
{
    char *args;
    args = (char *) (((s32) &fmt + 4 + 3) & ~3);
    while (*dst != 0) {
        dst++;
    }
    func_800E7480(dst, fmt, args);
}

// Minimal vsprintf: %b %c %d %f %p %s %x.
void func_800E7480(s32 dst, char *fmt, va_list args)
{
    s32 i;
    f64 value;

    for (i = 0; fmt[i] != 0; i++) {
        if (fmt[i] != '%') {
            do {
                if (fmt[i] >= 0x20) {
                    func_800E6A58((u8 *) dst, fmt[i]);
                }
            } while (0);

}
else
{
    i++;

switch (fmt[i]) {
    case 'b':
        func_800E7368(dst, va_arg(args, s32));
        break;
    case 'c':
        func_800E6A58((u8 *) dst, va_arg(args, char));
        break;
    case 'd':
        func_800E6DB4(dst, va_arg(args, s32));
        break;
    case 'f':
        value = va_arg(args, f64);
        func_800E6BAC((char *) dst, value);
        break;
    case 'p':
        func_800E6F7C((char *) dst, va_arg(args, s32));
        break;
    case 's':
        func_800E6A10((u8 *) dst, (u8 *) va_arg(args, s32));
        break;
    case 'x':
        func_800E6F7C((char *) dst, va_arg(args, s32));
        break;
    default:
        func_800E6A58((u8 *) dst, fmt[i]);
}

}
}
}
