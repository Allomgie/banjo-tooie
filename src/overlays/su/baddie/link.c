// Weak actor links (marker pointer plus marker id): clear, set, validate, re-resolve by id after
// the marker moved, get the actor, and copy.
#include "common.h"
// TU-NOTE: the .data of this overlay is defined here in C; values come from the ROM.

typedef struct {
    Unk80132ED0 *marker;
    s32 id;
} BaddieLink1425;
typedef struct {
    u8 pad_0[0x12];
    u16 id;
} BaddieMarker1425;
extern Actor *func_80106790(Unk80132ED0 *);
extern int _subaddiefind_entrypoint_8();

// Clears the link.
void subaddielink_entrypoint_0(link) void *link;
{
    s32 *base;
    *(s32 *) ((u8 *) link + 4) = 0;
    base = (u8 *) link;
    *(s32 *) (base + 0) = 0;
}

// Links to a marker and stores its id; clears the link if marker is NULL.
// Matching: the temporaries in this function are needed for the match.
void subaddielink_entrypoint_1(u8 *link, u8 *marker)
{
    u16 raw16;
    u32 id;
    long raw;
    if (marker != 0) {
        raw = *(u16 *) (marker + 0x12);
        raw16 = raw;
        *(u8 **) link = marker;
        id = raw16;
        id = id >> 1;
        *(u32 *) (link + 4) = id;
        return;
    }
    subaddielink_entrypoint_0();
}

// Returns 1 if the linked marker is still valid and its actor alive; otherwise clears the link.
int subaddielink_entrypoint_2(BaddieLink1425 *link)
{
    if (link->marker) {
        if (link->id == ((u32) ((BaddieMarker1425 *) link->marker)->id >> 1) &&
            !func_80106790(link->marker)->unk64_17) {
            return 1;
        }
        link->marker = NULL;
        link->id = 0;
    }
    return 0;
}

// Re-resolves the marker from the stored id. Returns 1 if the link is set.
int subaddielink_entrypoint_3(void *link)
{
    void *lookup;
    char *base;
    base = (char *) link;
    lookup = *(void **) (base + 4);
    *(void **) (base + 0) = 0;
    if (lookup != 0) {
        lookup = _subaddiefind_entrypoint_8(lookup);
        if (lookup != 0) {
            *(void **) base = *(void **) lookup;
        }
    }
    return *(void **) base != 0;
}

// Returns the linked actor if the link is valid, otherwise 0.
s32 subaddielink_entrypoint_4(ALLink *link)
{
    if (!subaddielink_entrypoint_2(link)) {
        return 0;
    } else {
        func_80106790(link->next);
    }
}

// Copies a link.
s32 subaddielink_entrypoint_5(s32 src[2], s32 dst[2])
{
    dst[0] = src[0];
    dst[1] = src[1];
}
