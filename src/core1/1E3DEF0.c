// libultra audio: the delta-time ordered event queue and synth client/voice allocation.
#include "common.h"

typedef struct TTLink_s {
    struct TTLink_s *next;
    struct TTLink_s *prev;
} TTLink;
typedef struct {
    TTLink freeList;
    TTLink allocList;
    s32 eventCount;
} TTEvtq;
typedef struct {
    s16 type;
    u8 pad2[0xE];
} TTEvt16;
typedef struct {
    TTLink node;
    s32 delta;
    TTEvt16 evt;
} TTItem;
extern void func_80020E40(TTLink *, TTLink *);
extern void func_80020E74(TTLink *);
typedef struct TTPNode_s {
    struct TTPNode_s *next;
    u8 pad4[0xC];
    s32 time; // synth time when the client was added
} TTPNode;
typedef struct {
    TTPNode *head; // synth client list
    u8 pad4[0x1C];
    s32 time;
} TTAMgrE;
extern TTAMgrE *D_800411F4;
typedef struct TTHandleB_s {
    u8 pad0[0x8];
    struct TTPlayerB_s *unk8;
    s32 unkC;
    u8 pad10[4];
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
} TTHandleB;
typedef struct TTPlayerB_s {
    u8 pad0[0x8];
    TTHandleB *unk8;
    u8 padC[0x7C];
    s32 unk88;
} TTPlayerB;
typedef struct {
    s16 unk0;
    s16 unk2;
    u8 unk4;
} TTParamsB;
typedef struct {
    s32 unk0;
    s32 unk4;
    s16 type;
    u8 padA[2];
    s32 unkC;
    s32 unk10;
} TTQEvtH;
typedef struct {
    u8 pad0[0x1C];
    s32 unk1C;
} TTAMgrH;
extern TTQEvtH *func_80021794(void);
extern void func_8002B684(TTPlayerB *, s32, TTQEvtH *);
typedef struct TTHandleA_s {
    u8 pad0[0x8];
    struct TTPlayerA_s *unk8;
    u8 padC[0xA];
    s16 unk16;
} TTHandleA;
typedef struct TTPlayerA_s {
    struct TTPlayerA_s *next;
    u8 pad4[4];
    TTHandleA *unk8;
    u8 padC[0x7C];
    s32 unk88;
} TTPlayerA;
typedef struct {
    TTPlayerA *unk0;
    TTPlayerA *unk4;
    u8 pad8[4];
    TTPlayerA *unkC;
    u8 pad10[4];
    TTPlayerA *unk14;
} TTAMgrP;

s32 func_80026AA4(TTPlayerA **out, s16 prio);

// Delta-time ordered event queue shared by the sound and sequence players.
// alEvtqNew: all items start on the free list.
void func_800263C0(TTEvtq *evtq, TTItem *items, s32 item_count)
{
    s32 i;

    evtq->eventCount = 0;
    evtq->allocList.next = 0;
    evtq->allocList.prev = 0;
    evtq->freeList.next = 0;
    evtq->freeList.prev = 0;
    for (i = 0; i < item_count; i++) {
        func_80020E40(&items[i].node, &evtq->freeList);
    }
}

// alEvtqNextEvent: pop the first event, returns its delta (type -1 if the queue is empty).
s32 func_8002645C(TTEvtq *evtq, TTEvt16 *evt)
{
    TTItem *item;
    s32 delta;
    s32 mask;

    mask = osSetIntMask(1);

    item = (TTItem *) evtq->allocList.next;

    if (item) {
        func_80020E74(&item->node);
        bcopy(&item->evt, evt, sizeof(*evt));
        func_80020E40(&item->node, &evtq->freeList);
        delta = item->delta;
    } else {
        evt->type = -1;
        delta = 0;
    }

    osSetIntMask(mask);

    return delta;
}

// alEvtqPostEvent: insert the event into the delta-ordered list.
void func_80026500(TTEvtq *evtq, TTEvt16 *evt, s32 delta, s32 arg3)
{
    TTItem *item;
    TTItem *next_item;
    TTLink *node;
    s32 post_at_end = 0;
    s32 mask;

    mask = osSetIntMask(1);

    item = (TTItem *) evtq->freeList.next;
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
        post_at_end = -1;

    for (node = &evtq->allocList; node != 0; node = node->next) {
        if (!node->next) {
            if (post_at_end)
                item->delta = 0;
            else
                item->delta = delta;
            func_80020E40(&item->node, node);
            break;
        } else {
            next_item = (TTItem *) node->next;

            if (delta < next_item->delta) {
                item->delta = delta;
                next_item->delta -= delta;

                func_80020E40(&item->node, node);
                break;
            }

            delta -= next_item->delta;
        }
    }

    osSetIntMask(mask);
}

// alEvtqFlushType: remove all queued events of the given type.
void func_800266B0(TTEvtq *evtq, s16 type)
{
    TTLink *this_node;
    TTLink *next_node;
    TTItem *this_item;
    TTItem *next_item;
    s32 mask;

    mask = osSetIntMask(1);

    this_node = evtq->allocList.next;
    while (this_node != 0) {
        next_node = this_node->next;
        this_item = (TTItem *) this_node;
        next_item = (TTItem *) next_node;
        if (this_item->evt.type == type) {
            if (next_item) {
                next_item->delta += this_item->delta;
            }
            func_80020E74(this_node);
            func_80020E40(this_node, &evtq->freeList);
        }
        this_node = next_node;
    }

    osSetIntMask(mask);
}

// Synth client registration and voice allocation/stealing.
// alSynAddPlayer: push the client onto the synth list with the current time.
void func_80026780(TTPNode *client)
{
    s32 mask;

    mask = osSetIntMask(1);

    client->time = D_800411F4->time;
    client->next = D_800411F4->head;
    D_800411F4->head = client;

    osSetIntMask(mask);
}

// Same as func_80026780 (used by the sound player).
void func_800267F0(TTPNode *client)
{
    s32 mask;

    mask = osSetIntMask(1);

    client->time = D_800411F4->time;
    client->next = D_800411F4->head;
    D_800411F4->head = client;

    osSetIntMask(mask);
}

// Same as func_80026780 (used by the sequence player).
void func_80026860(TTPNode *client)
{
    s32 mask;

    mask = osSetIntMask(1);

    client->time = D_800411F4->time;
    client->next = D_800411F4->head;
    D_800411F4->head = client;

    osSetIntMask(mask);
}

// alSynAllocVoice: assign a voice, stealing one by fading it out when none is free.
s32 func_800268D0(TTHandleB *h, TTParamsB *params)
{
    TTPlayerB *voice = 0;
    TTQEvtH *evt;
    s32 stolen;

    h->unk16 = params->unk0;
    h->unk1A = params->unk4;
    h->unkC = 0;
    h->unk18 = params->unk2;
    h->unk14 = 0;
    h->unk8 = 0;

    stolen = func_80026AA4(&voice, params->unk0);

    if (voice) {
        if (stolen) {
            voice->unk88 = 0x228;
            voice->unk8->unk8 = 0;
            voice->unk8 = h;
            h->unk8 = voice;

            evt = func_80021794();
            if (evt) {
                evt->unk4 = ((TTAMgrH *) D_800411F4)->unk1C;
                evt->type = 0xB;
                evt->unkC = 0;
                evt->unk10 = 0x170;
                func_8002B684(h->unk8, 3, evt);
            } else {
            }

            evt = func_80021794();
            if (evt) {
                evt->unk4 = ((TTAMgrH *) D_800411F4)->unk1C + voice->unk88;
                evt->type = 0xF;
                evt->unk0 = 0;
                func_8002B684(h->unk8, 3, evt);
            } else {
            }
        } else {
            voice->unk88 = 0;
            voice->unk8 = h;
            h->unk8 = voice;
        }
    }

    return voice != 0;
}

// _allocatePVoice: take a voice from the free list (or the lame list), else pick the lowest-priority allocated one.
// Returns 1 if the voice has to be stolen.
s32 func_80026AA4(TTPlayerA **out, s16 prio)
{
    TTLink *node;
    TTPlayerA *player;
    s32 found = 0;

    if (node = (TTLink *) ((TTAMgrP *) D_800411F4)->unk14) {
        *out = (TTPlayerA *) node;
        func_80020E74(node);
        func_80020E40(node, (TTLink *) &((TTAMgrP *) D_800411F4)->unkC);
    } else if (node = (TTLink *) ((TTAMgrP *) D_800411F4)->unk4) {
        *out = (TTPlayerA *) node;
        func_80020E74(node);
        func_80020E40(node, (TTLink *) &((TTAMgrP *) D_800411F4)->unkC);
    } else {
        for (node = (TTLink *) ((TTAMgrP *) D_800411F4)->unkC; node != 0; node = node->next) {
            player = (TTPlayerA *) node;
            if (player->unk8->unk16 <= prio && player->unk88 == 0) {
                *out = player;
                prio = player->unk8->unk16;
                found = 1;
            }
        }
    }

    return found;
}
