// printf front-end for the on-screen debug text console (_Printf callback, console_printf[_at]).
#include "common.h"

extern s32 D_8007D160;
extern void func_8001DA00(s32, s32);
extern void _Printf(void *param_0, ...);
extern void func_8001D9CC();

// _Printf output callback: forwards the formatted chunk to the console buffer.
int func_8001D340(s32 ctx, s32 buf, s32 len)
{
    if (D_8007D160 & 1) {
        // Matching: the `| 0` operands are needed for the match.
        func_8001DA00(buf | 0, len | 0);
    }
    return 1;
}

// printf to the on-screen console. The va_list is built by hand from the first argument.
void func_8001D37C(s32 fmt, ...)
{
    s32 args;

    D_8007D160 = 1;
    args = (s32) &fmt;
    args += 7;
    args &= ~3;
    _Printf(&func_8001D340, 0, fmt, args);
}

// printf at console position (x, y).
void func_8001D3D8(s16 x, s16 y, s32 fmt, ...)
{
    s32 args;

    D_8007D160 = 1;
    func_8001D9CC((u16) x, (u16) y);
    args = (s32) &fmt;
    args += 7;
    args &= ~3;
    _Printf(&func_8001D340, 0, fmt, args);
}
