#include "common.h"

typedef struct TTLink_s { struct TTLink_s *next; struct TTLink_s *prev; } TTLink;
typedef struct { TTLink freeList; /* 0x00 */ TTLink allocList; /* 0x08 */ s32 eventCount; /* 0x10 */ } TTEvtq;
typedef struct { s16 type; /* 0x0 */ u8 pad2[0xE]; } TTEvt16;
typedef struct { TTLink node; /* 0x00 */ s32 delta; /* 0x08 */ TTEvt16 evt; /* 0x0C */ } TTItem;
extern void func_80020E40(TTLink *, TTLink *);
extern void func_80020E74(TTLink *);
typedef struct TTPNode_s { struct TTPNode_s *unk0; /* 0x00: next */ u8 pad4[0xC]; s32 unk10; /* 0x10: Zeitstempel */ } TTPNode;
typedef struct { TTPNode *unk0; /* 0x00: Listenkopf */ u8 pad4[0x1C]; s32 unk20; /* 0x20: globale Zeit */ } TTAMgrE;
extern TTAMgrE *D_800411F4;
typedef struct TTHandleB_s { u8 pad0[0x8]; struct TTPlayerB_s *unk8; /* 0x08 */ s32 unkC; /* 0x0C */ u8 pad10[4]; s16 unk14; /* 0x14 */ s16 unk16; /* 0x16 */ s16 unk18; /* 0x18 */ s16 unk1A; /* 0x1A */ } TTHandleB;
typedef struct TTPlayerB_s { u8 pad0[0x8]; TTHandleB *unk8; /* 0x08 */ u8 padC[0x7C]; s32 unk88; /* 0x88 */ } TTPlayerB;
typedef struct { s16 unk0; /* 0x0: Prioritaet */ s16 unk2; /* 0x2 */ u8 unk4; /* 0x4 */ } TTParamsB;
typedef struct { s32 unk0; /* 0x00 */ s32 unk4; /* 0x04: Zeit */ s16 type; /* 0x08 */ u8 padA[2]; s32 unkC; /* 0x0C */ s32 unk10; /* 0x10 */ } TTQEvtH;
typedef struct { u8 pad0[0x1C]; s32 unk1C; /* 0x1C: globale Zeit */ } TTAMgrH;
extern TTQEvtH *func_80021794(void);
extern void func_8002B684(TTPlayerB *, s32, TTQEvtH *);
typedef struct TTHandleA_s { u8 pad0[0x8]; struct TTPlayerA_s *unk8; /* 0x8 */ u8 padC[0xA]; s16 unk16; /* 0x16: Prioritaet */ } TTHandleA;
typedef struct TTPlayerA_s { struct TTPlayerA_s *next; /* 0x00 */ u8 pad4[4]; TTHandleA *unk8; /* 0x08 */ u8 padC[0x7C]; s32 unk88; /* 0x88 */ } TTPlayerA;
typedef struct { TTPlayerA *unk0; /* 0x00 */ TTPlayerA *unk4; /* 0x04 */ u8 pad8[4]; TTPlayerA *unkC; /* 0x0C: aktive Liste */ u8 pad10[4]; TTPlayerA *unk14; /* 0x14 */ } TTAMgrP;

/* Vorwaertsdeklarationen der Funktionen dieser TU. */
s32 func_80026AA4(TTPlayerA **out, s16 prio);

void func_800263C0(TTEvtq *evtq, TTItem *items, s32 itemCount)
{
    s32 i;

    evtq->eventCount     = 0;
    evtq->allocList.next = 0;
    evtq->allocList.prev = 0;
    evtq->freeList.next  = 0;
    evtq->freeList.prev  = 0;
    for (i = 0; i < itemCount; i++) {
        func_80020E40(&items[i].node, &evtq->freeList);
    }
}

s32 func_8002645C(TTEvtq *evtq, TTEvt16 *evt)
{
    TTItem *item;
    s32 delta;
    s32 mask;

    mask = osSetIntMask(1);

    item = (TTItem *)evtq->allocList.next;

    if (item) {
        func_80020E74(&item->node);
        bcopy(&item->evt, evt, sizeof(*evt));
        func_80020E40(&item->node, &evtq->freeList);
        delta = item->delta;
    }
    else {
        evt->type = -1;
        delta = 0;
    }

    osSetIntMask(mask);

    return delta;
}

void func_80026500(TTEvtq *evtq, TTEvt16 *evt, s32 delta, s32 arg3)
{
    TTItem *item;
    TTItem *nextItem;
    TTLink *node;
    s32 postAtEnd = 0;
    s32 mask;

    mask = osSetIntMask(1);

    item = (TTItem *)evtq->freeList.next;
    if (!item) {
        osSetIntMask(mask);
        return;
    }

    if (!item->node.next && !arg3) {
        osSetIntMask(mask);
        return;
    }

    func_80020E74(&item->node);
    bcopy(evt, &item->evt, sizeof(item->evt));

    if (delta == 0x7FFFFFFF)
        postAtEnd = -1;

    for (node = &evtq->allocList; node != 0; node = node->next) {
        if (!node->next) {
            if (postAtEnd)
                item->delta = 0;
            else
                item->delta = delta;
            func_80020E40(&item->node, node);
            break;
        } else {
            nextItem = (TTItem *)node->next;

            if (delta < nextItem->delta) {
                item->delta = delta;
                nextItem->delta -= delta;

                func_80020E40(&item->node, node);
                break;
            }

            delta -= nextItem->delta;
        }
    }

    osSetIntMask(mask);
}

void func_800266B0(TTEvtq *evtq, s16 type)
{
    TTLink *thisNode;
    TTLink *nextNode;
    TTItem *thisItem;
    TTItem *nextItem;
    s32 mask;

    mask = osSetIntMask(1);

    thisNode = evtq->allocList.next;
    while (thisNode != 0) {
        nextNode = thisNode->next;
        thisItem = (TTItem *)thisNode;
        nextItem = (TTItem *)nextNode;
        if (thisItem->evt.type == type) {
            if (nextItem) {
                nextItem->delta += thisItem->delta;
            }
            func_80020E74(thisNode);
            func_80020E40(thisNode, &evtq->freeList);
        }
        thisNode = nextNode;
    }

    osSetIntMask(mask);
}

void func_80026780(TTPNode *n)
{
    s32 mask;

    mask = osSetIntMask(1);

    n->unk10 = D_800411F4->unk20;
    n->unk0 = D_800411F4->unk0;
    D_800411F4->unk0 = n;

    osSetIntMask(mask);
}

void func_800267F0(TTPNode *n)
{
    s32 mask;

    mask = osSetIntMask(1);

    n->unk10 = D_800411F4->unk20;
    n->unk0 = D_800411F4->unk0;
    D_800411F4->unk0 = n;

    osSetIntMask(mask);
}

void func_80026860(TTPNode *n)
{
    s32 mask;

    mask = osSetIntMask(1);

    n->unk10 = D_800411F4->unk20;
    n->unk0 = D_800411F4->unk0;
    D_800411F4->unk0 = n;

    osSetIntMask(mask);
}

s32 func_800268D0(TTHandleB *h, TTParamsB *params)
{
    TTPlayerB *picked = 0;
    TTQEvtH *evt;
    s32 stolen;

    h->unk16 = params->unk0;
    h->unk1A = params->unk4;
    h->unkC = 0;
    h->unk18 = params->unk2;
    h->unk14 = 0;
    h->unk8 = 0;

    stolen = func_80026AA4(&picked, params->unk0);

    if (picked) {
        if (stolen) {
            picked->unk88 = 0x228;
            picked->unk8->unk8 = 0;
            picked->unk8 = h;
            h->unk8 = picked;

            evt = func_80021794();
            if (evt) {
                evt->unk4 = ((TTAMgrH *) D_800411F4)->unk1C;
                evt->type = 0xB;
                evt->unkC = 0;
                evt->unk10 = 0x170;
                func_8002B684(h->unk8, 3, evt);
            }
            else {
            }

            evt = func_80021794();
            if (evt) {
                evt->unk4 = ((TTAMgrH *) D_800411F4)->unk1C + picked->unk88;
                evt->type = 0xF;
                evt->unk0 = 0;
                func_8002B684(h->unk8, 3, evt);
            }
            else {
            }
        }
        else {
            picked->unk88 = 0;
            picked->unk8 = h;
            h->unk8 = picked;
        }
    }

    return picked != 0;
}

s32 func_80026AA4(TTPlayerA **out, s16 prio)
{
    TTLink *node;
    TTPlayerA *q;
    s32 found = 0;

    if (node = (TTLink *)((TTAMgrP *) D_800411F4)->unk14) {
        *out = (TTPlayerA *)node;
        func_80020E74(node);
        func_80020E40(node, (TTLink *)&((TTAMgrP *) D_800411F4)->unkC);
    }
    else if (node = (TTLink *)((TTAMgrP *) D_800411F4)->unk4) {
        *out = (TTPlayerA *)node;
        func_80020E74(node);
        func_80020E40(node, (TTLink *)&((TTAMgrP *) D_800411F4)->unkC);
    }
    else {
        for (node = (TTLink *)((TTAMgrP *) D_800411F4)->unkC; node != 0; node = node->next) {
            q = (TTPlayerA *)node;
            if (q->unk8->unk16 <= prio && q->unk88 == 0) {
                *out = q;
                prio = q->unk8->unk16;
                found = 1;
            }
        }
    }

    return found;
}
