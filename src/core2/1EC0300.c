#include "common.h"

#define va_arg(list, mode) ((mode *)(list = \
(char *) (sizeof(mode) > 4 ? ((int)list + 2*8 - 1) & -8 \
: ((int)list + 2*4 - 1) & -4)))[-1]
typedef char *va_list;
void func_800E6AFC(char *, u8);
void func_800E6DB4(s32, s32);
void func_800E6DD8();
void func_800E7480(s32 param_0, char *fmt, va_list args);

void func_800E6A10(u8 *param_0, u8 *param_1){
    while(*param_0 != '\0'){
        param_0++;
    }

    while(*param_1 != '\0'){
        *param_0 = *param_1;
        param_0++;
        param_1++;
    }
    *param_0 = '\0';
}

int func_800E6A58(param_0, param_1) u8 *param_0; u8 param_1;
{
  while ((*param_0) != 0)
  {
    param_0++;
  }

  *param_0 = param_1;
  {
    param_0++;
  }
  *param_0 = 0;
}

void func_800E6A90(s32 param_0, u8 *param_1) {
    while (*param_1 != 0) {
        func_800E6AFC(param_0, *param_1++);
        func_800E6A10(param_0, " ");
    }
}

void func_800E6AFC(char *str, u8 num) {
    s32 i;
    s32 d;
    while (*str != '\0') {
        str++;
    }
    *str = '0';
    str++;
    *str = 'x';
    str++;
    for (i = 1; i >= 0; i--) {
        d = (num >> (i * 4)) & 0xF;
        if ((u8)(d < 10)) {
            *str = '0' + d;
        } else {
            *str = 'a' - 10 + d;
        }
        str++;
    }
    *str = '\0';
}

int func_800E6B7C(f32 *param_0, f32 param_1)
{
  return (param_1 < 0.0f) ? -1 : 1;
}

void func_800E6BAC(char *param_0, f32 param_1) {
    s32 local_1;
    char *local_0;
    switch (func_800E6B7C(&local_0, param_1)) {
        case 0:
            func_800E6A10(param_0, local_0);
            break;
        case -1:
            func_800E6A10(param_0, "-");
            param_1 = -param_1;
        case 1:
            local_1 = param_1;
            func_800E6DB4(param_0, local_1);
            func_800E6A10(param_0, ".");
            if ((s32)((param_1 - local_1) * 100.0f) < 10) func_800E6A10(param_0, "0");
            func_800E6DB4(param_0, (param_1 - local_1) * 100.0f);
            break;
    }
}

void func_800E6CA8(char *param_0, f32 param_1, s32 param_2) {
    char *local_0;
    switch (func_800E6B7C(&local_0, param_1)) {
    case 0: func_800E6A10(param_0, local_0); break;
    case -1:
        func_800E6A10(param_0, "-");
        param_1 = -param_1;
    case 1:
        func_800E6DB4(param_0, param_1);
        if (param_2) {
            func_800E6A10(param_0, ".");
            while (param_2--) {
                param_1 -= (s32)param_1;
                param_1 *= 10.0f;
                func_800E6DB4(param_0, param_1);
            }
        }
        break;
    }
}

void func_800E6DB4(p0, p1) s32 p0; s32 p1; {
    func_800E6DD8(p0, p1, 0, 0);
}

void func_800E6DD8(param_0, param_1, param_2, param_3) u8 * param_0; s32 param_1; u8 param_2; s32 param_3; {
    s32 local_0;
    while (*param_0) param_0++;
    if (param_1 < 0) {
        *param_0++ = '-';
        param_1 = -param_1;
    } else if (param_2) {
        *param_0++ = param_2;
    }
    local_0 = 1000000000;
    while (param_1 < local_0) local_0 /= 10;
    if (local_0 == 0) {
        *param_0++ = '0';
    } else {
        while (local_0 > 0) {
            if (param_3) *param_0++ = param_1 / local_0 + 0x10;
            else *param_0++ = param_1 / local_0 + '0';
            param_1 %= local_0;
            local_0 /= 10;
        }
    }
    *param_0 = 0;
}

void func_800E6F7C(char *str, u32 num) {
    s32 i;
    s32 d;
    while (*str != '\0') {
        str++;
    }
    *str = '0';
    str++;
    *str = 'x';
    str++;
    for (i = 7; i >= 0; i--) {
        d = (num >> (i * 4)) & 0xF;
        if ((u8)(d < 10)) {
            *str = '0' + d;
        } else {
            *str = 'a' - 10 + d;
        }
        str++;
    }
    *str = '\0';
}

void func_800E6FEC(char *str, u32 num) {
    s32 i;
    s32 d;
    while (*str != '\0') {
        str++;
    }
    *str = '0';
    str++;
    *str = '.';
    str++;
    for (i = 7; i >= 0; i--) {
        d = (num >> (i * 4)) & 0xF;
        if ((u8)(d < 10)) {
            *str = '0' + d;
        } else {
            *str = 'A' - 10 + d;
        }
        str++;
    }
    *str = '\0';
}

void func_800E705C(char *str, u8 num) {
    s32 i;
    s32 d;
    while (*str != '\0') {
        str++;
    }
    *str = '0';
    str++;
    *str = 'x';
    str++;
    for (i = 1; i >= 0; i--) {
        d = (num >> (i * 4)) & 0xF;
        if ((u8)(d < 10)) {
            *str = '0' + d;
        } else {
            *str = 'A' - 10 + d;
        }
        str++;
    }
    *str = '\0';
}

func_800E70DC(char *param_0, char *param_1){
    while (*param_0 && *param_1 && *param_0 == *param_1) {
        param_0++;
        param_1++;
    }
    if (*param_0 == *param_1)
        return 0;
    else if (*param_0 == '\0' || *param_0 < *param_1)
        return -1;
        return 1;
}

func_800E715C(u8 *param_0, u8 *param_1){
    while(*param_1 != '\0'){
        *param_0++ = *param_1++;
    }
    *param_0 = '\0';
}

s32 func_800E7188(u8 *str){
    u32 len = 0;
    while(*str++){
        len++;
    }
    return len;
}

s32 func_800E71B8(s32 param_0)
{
  if (_gldialog_entrypoint_1())
  {
    if ((param_0 && param_0) && param_0)
    {
    }
    return param_0 + 2;
  }
  return param_0;
}

func_800E71EC(char *param_0, char* param_1, char* param_2){
    while (*param_1 == *param_2) {
        param_1++;
        param_2++;
        if ((*param_1 == '\0' || *param_1 == *param_0) && (*param_2 == '\0' || *param_2 == *param_0)){
            return 1;
        }
    }
    return 0;
}

func_800E7254(u8 *param_0, u8 *param_1) {
    while (*param_1 != '\0' && *param_1 != *param_0) {
        param_1++;
    }

    if (*param_1 == *param_0) {
        param_1++;
    }
    return param_1;
}

void func_800E729C(u8 *param_0, u8 *param_1, u8 *param_2) {
    while ((*param_2 != 0) && (*param_2 != *param_0)) {
        *param_1 = *param_2;
        param_2++;
        param_1++;
    }
    *param_1 = 0;
}

s32 func_800E72E0(char *str){
    u8 *ptr = (u8*)str;
    while(*(u8*)ptr){
        if( (*ptr >= 0x61) && (*ptr < 0x7B)){
            *ptr -= 0x20;
        }
        ptr++;
    }
}

func_800E7324(u8 *param_0){
    u8 *local_0;
    local_0 = param_0;
    while(*local_0 != '\0'){
        if(0x41 <= *local_0 && *local_0 < 0x5B){
            *local_0 += 0x20;
        }
        local_0++;
    }
}

int func_800E7368(s32 param_0, u32 param_1)
{
  s32 local_0;
  u32 local_1;
  for (local_0 = 31; local_0 >= 0; local_0--)
  {
    if ((1 << local_0) & param_1)
    {
      local_1 = 0x31;
    }
    else
    {
      local_1 = 0x30;
    }
    func_800E6A58(param_0, (((((((((local_1 & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu) & 0xFFu);
  }

}

func_800E73D4(u8 *param_0){
    param_0[0] = 0;
}

int func_800E73DC(s32 param_0, s32 param_1, short param_2, s32 param_3)
{
  u8 *local_0;
  int new_var;
  int new_var2;
  if (!new_var)
  {
  }
  func_800E73D4(param_0);
  local_0 = &param_2;
  new_var2 = ~3;
  new_var = new_var2;
  func_800E7480(param_0, param_1, ((((u32) local_0) + 1) & new_var) | 0);
}

void func_800E7428(u8 *param_0, u8 *param_1, ...) {
    char *args;
    args = (char *)((((s32)&param_1) + 4 + 3) & ~3);
    while (*param_0 != 0) {
        param_0++;
    }
    func_800E7480(param_0, param_1, args);
}

void func_800E7480(s32 param_0, char *fmt, va_list args)
{
    s32 i;
    f64 d;

    for (i = 0; fmt[i] != 0; i++) {
        if (fmt[i] != '%') {
            do {
                if (fmt[i] >= 0x20) {
                    func_800E6A58((u8 *) param_0, fmt[i]);
                }
            } while (0);
        } else {
            i++;
            switch (fmt[i]) {
                case 'b':
                    func_800E7368(param_0, va_arg(args, s32));
                    break;
                case 'c':
                    func_800E6A58((u8 *) param_0, va_arg(args, char));
                    break;
                case 'd':
                    func_800E6DB4(param_0, va_arg(args, s32));
                    break;
                case 'f':
                    d = va_arg(args, f64);
                    func_800E6BAC((char *) param_0, d);
                    break;
                case 'p':
                    func_800E6F7C((char *) param_0, va_arg(args, s32));
                    break;
                case 's':
                    func_800E6A10((u8 *) param_0, (u8 *) va_arg(args, s32));
                    break;
                case 'x':
                    func_800E6F7C((char *) param_0, va_arg(args, s32));
                    break;
                default:
                    func_800E6A58((u8 *) param_0, fmt[i]);
                    break;
            }
        }
    }
}
