#include "common.h"

typedef struct TTLink_s { struct TTLink_s *next; struct TTLink_s *prev; } TTLink;

void func_80020E40(TTLink *param_0, TTLink *param_1)
{
    param_0->next = param_1->next;
    param_0->prev = param_1;
    if (param_1->next)
        param_1->next->prev = param_0;
    param_1->next = param_0;
}

void func_80020E74(TTLink *param_0)
{
    if (param_0->next)
        param_0->next->prev = param_0->prev;
    if (param_0->prev)
        param_0->prev->next = param_0->next;
}
