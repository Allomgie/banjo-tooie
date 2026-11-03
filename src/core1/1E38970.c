#include "common.h"

typedef struct TTLink_s {
    struct TTLink_s *next;
    struct TTLink_s *prev;
} TTLink;

// Inserts node into the list after the given node.
void func_80020E40(TTLink *node, TTLink *after)
{
    node->next = after->next;
    node->prev = after;
    if (after->next)
        after->next->prev = node;
    after->next = node;
}

// Removes node from its list.
void func_80020E74(TTLink *node)
{
    if (node->next)
        node->next->prev = node->prev;
    if (node->prev)
        node->prev->next = node->next;
}
