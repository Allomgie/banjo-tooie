// Actor state snapshot for per-map storage: entrypoint_0 serialises the live actors into a blob
// (full records, or unique ids only); entrypoint_1 restores it at map start, matching actors by
// unique id, despawning those without an entry and respawning stored ones that no longer exist.
#include "common.h"

extern Actor *func_801067C4(int *);
extern Actor *func_8010682C(int *);
extern u8 *func_80108474();
void typedef struct {
    u8 pad[0x70];
    u32 pad_a : 14;
    u32 f17 : 1;
    u32 pad_b : 17;
} Bit70;
extern s32 func_800DB9B0();
extern s32 func_80102F74();
extern s32 func_800EA05C();
extern s32 _glcutDll_entrypoint_8();
extern s32 func_8001B7B8();
typedef struct {
    u8 pad_0[0x75];
    u8 p0 : 5;
    u8 b2 : 1;
    u8 p1 : 2;
} SSB75;
typedef struct {
    u8 pad_0[0x64];
    u8 p0 : 5;
    u8 b2 : 1;
    u8 p1 : 2;
} SSB64;
typedef struct {
    u8 pad_0[0x73];
    u8 p0 : 4;
    u8 b3 : 1;
    u8 p1 : 3;
} SSB73;
typedef struct {
    u8 pad_0[0x74];
    u8 b7 : 1;
    u8 p0 : 7;
} SSB74;
typedef struct {
    u8 pad_0[0xAC];
    u16 b15 : 1;
    u16 v : 15;
} SSHAC;
typedef struct {
    u8 pad_0[0x9C];
    u8 b7 : 1;
    u8 b6 : 1;
    u8 b5 : 1;
    u8 p0 : 5;
} SSB9C;
typedef struct {
    u8 pad_0[0x9F];
    u8 p0 : 6;
    u8 b1 : 1;
    u8 p1 : 1;
} SSB9F;
typedef struct {
    u8 pad_0[0xAE];
    u8 b7 : 1;
    u8 f : 6;
    u8 b0 : 1;
} SSBAE;
typedef struct {
    u8 pad_0[0xAF];
    u8 b7 : 1;
    u8 p0 : 7;
} SSBAF;
typedef struct {
    u8 pad_0[0x9E];
    u16 idx : 14;
    u16 p0 : 2;
} SSH9E;
typedef struct {
    u8 pad_0[0x9D];
    u8 p0 : 5;
    u8 t : 3;
} SSB9D;
typedef struct {
    u8 pad_0[0xAC];
    u8 b7 : 1;
    u8 p0 : 7;
} SSBAC;
typedef struct {
    u8 pad_0[0x28];
    u32 p0 : 21;
    u32 b10 : 1;
    u32 b9 : 1;
    u32 f : 8;
    u32 b0 : 1;
} SSU28;
typedef struct {
    u8 pad_0[0x12];
    u16 v : 15;
    u16 b0 : 1;
} SSH12;
typedef struct {
    u8 pad_0[0x9C];
    u32 p0 : 3;
    u32 f : 10;
    u32 p1 : 19;
} SSW9C;
typedef struct {
    u8 pad_0[0x94];
    u32 p0 : 2;
    u32 f : 10;
    u32 p1 : 20;
} SSA94;
extern f32 func_8008B2AC();
extern f32 func_8008B2D4();
extern f32 anctrl_getAnimTimer();
extern void func_80105634();
extern void func_80106EE0();
extern u8 *func_8010556C();
extern u8 *func_80106E88();
extern void rare_memcpy(void *, void *, s32);
extern void func_8001B754();
extern s32 func_8001B668(s32, s32);
extern u8 *func_8001B798();
extern u8 *func_80104248();
extern u8 *func_801042B8();
extern void anctrl_setPlaybackType();
extern void anctrl_setIndex();
extern void func_8008B188();
extern void anctrl_setSmoothTransition();
extern void anctrl_setDuration(u8 *, f32);
extern f32 func_800F0D50(f32, f32, f32);
extern void func_8008B10C(u8 *, f32);
extern void anctrl_setSubrange(u8 *, f32, f32);
extern void anctrl_start();
extern void func_8008B2DC(u8 *, f32);
extern void func_80104328();
extern void func_8010A654();
extern void func_80103014();
typedef struct {
    u8 p[0x12];
    u16 hi : 15;
    u16 lo : 1;
} SB12;
typedef struct {
    u8 p[0x13];
    u8 pad : 7;
    u8 b : 1;
} SB13;
typedef struct {
    u8 p[0x1B];
    u8 pad : 7;
    u8 b : 1;
} SB1B;
typedef struct {
    u8 p[0x28];
    u32 q : 16;
    u32 pad : 5;
    u32 b2 : 1;
    u32 b1 : 1;
    u32 b0 : 1;
    u32 r : 8;
} SB2A;
typedef struct {
    u8 p[0x28];
    u32 q : 16;
    u32 pad : 7;
    u32 f : 8;
    u32 lo : 1;
} SB2AH;
typedef struct {
    u8 p[0x7E];
    u8 b7 : 1;
    u8 b6 : 1;
    u8 b5 : 1;
    u8 b4 : 1;
    u8 rest : 4;
} SB7E;
typedef struct {
    u8 p[0xAE];
    u16 neg : 1;
    u16 rest : 15;
} SBAE;
typedef struct {
    u8 p[0x9C];
    u16 hi : 13;
    u16 pb : 3;
} SB9C;
typedef struct {
    u8 p[0xAE];
    u8 r : 7;
    u8 b0 : 1;
    u8 b7 : 1;
    u8 r2 : 7;
} SRAEB;
int func_80800330_subaddiestore();
s32 func_808003AC_subaddiestore();
s32 *func_808004FC_subaddiestore();
int func_80800AD8_subaddiestore();
void func_80800B24_subaddiestore();
s32 func_80800F98_subaddiestore();
u8 *func_80800FD0_subaddiestore();
int func_80801054_subaddiestore();

// Group: serialise actors and look up their records for save-and-restore.
// Serialises the live actors into the blob.
u8 *subaddiestore_entrypoint_0(u8 *blob, u8 *blob_end)
{
    s32 add_size;
    s32 blob_size;
    u8 *write;
    u8 *id_write;
    Actor *actor;
    s32 pad;
    s32 full_count;
    s32 id_count;
    int iter;

    add_size = func_808003AC_subaddiestore(&full_count, &id_count);
    blob_size = blob_end - blob;
    blob = heap_realloc(blob, blob_size + add_size);
    write = blob + blob_size;
    *(s16 *) (write + 0) = full_count;
    *(s16 *) (write + 2) = id_count;
    write += 4;
    for (actor = func_801067C4(&iter); actor; actor = func_8010682C(&iter)) {
        write = func_808004FC_subaddiestore(actor, write);
    }
    id_write = write;
    for (actor = func_801067C4(&iter); actor; actor = func_8010682C(&iter)) {
        id_write = func_80800AD8_subaddiestore(actor, id_write);
    }
    return blob;
}

// Restores the blob: matches live actors by unique id, despawns unlisted ones, respawns missing ones.
subaddiestore_entrypoint_1(s32 unk_0, s16 *blob)
{
    u8 *actor;
    u8 *record;
    s32 kind;
    s32 iter;
    s32 i;
    s16 *counts = blob;

    for (actor = func_801067C4(&iter); actor != 0; actor = func_8010682C(&iter)) {
        // Matching: empty block steers IDO's register allocation.
        if (1) {
        }
        if ((*(u32 *) (actor + 0x6C) >> 21) != 0) {
            kind = func_80801054_subaddiestore(blob, actor, &record);
            if (kind != 0) {
                if (kind == 1 && (!((Bit70 *) record)->f17 || _glcutDll_entrypoint_1())) {
                    func_80800B24_subaddiestore(record, actor);
                }
            } else if (!((Bit70 *) actor)->f17 && func_80102F74(actor, 0x80000) == 0) {
                func_800FFAB0(actor);
            }
        }
    }
    record = (u8 *) blob + 4;
    for (i = 0; i < *counts; i++) {
        if (func_80800330_subaddiestore(record)) {
            func_80800B24_subaddiestore(
                record, func_80108474((*(u32 *) (record + 0x6C) << 11) >> 20, record + 4,
                                       (s32) *(f32 *) (record + 0x48)));
        }
        record = func_80800FD0_subaddiestore(record);
    }
}

// Group: restore a snapshot onto the map (match, apply, despawn, respawn).
// Classifies an actor: 0 skip, 1 store fully, 2 store id only.
s32 func_80800260_subaddiestore(actor)
Actor *actor;
{
    s32 active;
    if (actor->unk0 == 0) {
        return 0;
    }
    if (!actor->unk74_17 || actor->unk64_17) {
        return 0;
    }
    if (((Bit70 *) actor)->f17) {
        active = func_800DB9B0() && _glcutDll_entrypoint_8() != func_800EA05C();
        return active ? 1 : 0;
    }
    if (func_80102F74(actor, 0x80) != 0) {
        return 2;
    }
    // Matching: empty if keeps the parameter in its home slot.
    if (actor) {
    }
    return 1;
}

// True if the stored actor has no live counterpart.
int func_80800330_subaddiestore(actor)
Actor *actor;
{
    u32 unique_id;
    int iter;
    Actor *other;

    unique_id = actor->pad6C_21;
    if (unique_id == 0) {
        return 1;
    }
    for (other = func_801067C4(&iter); other; other = func_8010682C(&iter)) {
        if (unique_id == other->pad6C_21) {
            return 0;
        }
    }
    return 1;
}

// Computes the blob size and the counts of full and id-only actors.
s32 func_808003AC_subaddiestore(out_full_count, out_id_count)
s32 *out_full_count;
s32 *out_id_count;
{
    s32 full_count;
    s32 id_count;
    s32 size;
    Actor *actor;
    s32 has_data;
    int iter;
    s32 j;

    full_count = 0;
    id_count = 0;
    size = 4;
    for (actor = func_801067C4(&iter); actor; actor = func_8010682C(&iter)) {
        has_data = 0;
        switch (func_80800260_subaddiestore(actor)) {
            case 0:
                break;
            case 1:
                size += 0xB0;
                if (actor->unk7C_0) {
                    size += 0x48;
                }
                if ((*(u32 *) ((u8 *) actor + 0x94) << 2) >> 22) {
                    size += 0x18;
                }
                for (j = 0; j < 3; j++) {
                    if (((s16 *) ((u8 *) actor + 0x82))[j]) {
                        has_data = 1;
                        size += func_8001B7B8(((s16 *) ((u8 *) actor + 0x82))[j]);
                    }
                }
                if (has_data) {
                    size += 0xC;
                }
                full_count++;
                break;
            case 2:
                size += 4;
                id_count++;
        }
    }
    *out_full_count = full_count;
    *out_id_count = id_count;
    return size;
}

// Serialises a full actor into the blob; returns the new write pointer.
s32 *func_808004FC_subaddiestore(actor, out)
Actor *actor;
u8 *out;
{
    s32 unused; // Matching: unused local reserves a frame slot.
    s32 size;
    f32 range_start;
    f32 range_end;
    s32 prev; // old write pointer, kept across the copy call
    s32 *dst;
    s32 *sizes;
    s32 i;
    s32 tmp;

    if (func_80800260_subaddiestore() != 1) {
        return (s32 *) out;
    }
    rare_memcpy(out, actor, 0x9C);
    *(s16 *) (out + 0x60) = 0;
    ((SSB75 *) out)->b2 = 0;
    ((SSB64 *) out)->b2 = 0;
    *(u8 *) (out + 0x5F) = 0;
    *(s32 *) (out + 0x40) = 0;
    *(s32 *) (out + 0x3C) = 0;
    *(s16 *) (out + 0x90) = 0;
    *(s16 *) (out + 0x80) = 0;
    *(s16 *) (out + 0x8E) = 0;
    ((SSB73 *) out)->b3 = 0;
    ((SSB74 *) out)->b7 = 0;
    ((SSW9C *) out)->f = actor->unk0->unk24 >> 22;
    ((SSHAC *) out)->v = ((SSH12 *) actor->unk0)->v;
    ((SSB9C *) out)->b6 = ((SSU28 *) actor->unk0)->b10;
    ((SSB9C *) out)->b5 = ((SSU28 *) actor->unk0)->b9;
    tmp = func_8010A698(actor);
    ((SSB9F *) out)->b1 = tmp;
    ((SSBAE *) out)->f = ((SSU28 *) actor->unk0)->f;
    tmp = actor->unk0->unk10 & 1;
    ((SSBAE *) out)->b0 = tmp;
    ((SSBAF *) out)->b7 = actor->unk0->unk18;
    if (*(s16 *) ((u8 *) actor + 0x8C) != 0) {
        tmp = func_80104248(actor);
        ((SSH9E *) out)->idx = anctrl_getIndex(tmp);
        ((SSB9D *) out)->t = anctrl_getPlaybackType(tmp);
        ((SSBAC *) out)->b7 = func_8008B28C(tmp);
        ((SSB9C *) out)->b7 = func_8008B29C(tmp);
        *(f32 *) (out + 0xA0) = func_8008B2AC(tmp);
        func_8008B238(tmp, &range_start, &range_end);
        *(s16 *) (out + 0xA8) = (u32) (range_start * 32768);
        *(s16 *) (out + 0xAA) = (u32) (range_end * 32768);
        *(s16 *) (out + 0xA4) = (u32) (anctrl_getAnimTimer(tmp) * 32768);
        *(s16 *) (out + 0xA6) = (u32) (func_8008B2D4(tmp) * 32768);
    }
    if (*(s16 *) ((u8 *) actor + 0x8C) != 0) {
        ((SSBAE *) out)->b7 = 1;
    } else {
        ((SSBAE *) out)->b7 = 0;
    }
    *(s16 *) (out + 0x8C) = 0;
    *(s32 *) out = 0;
    dst = (s32 *) (out + 0xB0);
    if (actor->unk7C_0) {
        prev = (s32) dst;
        rare_memcpy(dst, func_80105494(actor), 0x48);
        dst = (s32 *) (prev + 0x48);
    }
    prev = (s32) dst;
    if (((SSA94 *) actor)->f != 0) {
        rare_memcpy(dst, func_80106F30(actor), 0x18);
        dst = (s32 *) (prev + 0x18);
    }
    if (func_80800F98_subaddiestore(actor) != 0) {
        sizes = dst;
        dst = (s32 *) ((u8 *) dst + 0xC);
        for (i = 0; i < 3; i++) {
            if (((s16 *) ((u8 *) actor + 0x82))[i] != 0) {
                size = func_8001B7B8(((s16 *) ((u8 *) actor + 0x82))[i]);
                sizes[i] = size;
                rare_memcpy(dst, func_8001B798(((s16 *) ((u8 *) actor + 0x82))[i]), size);
                dst = (s32 *) ((u8 *) dst + size);
            } else {
                sizes[i] = 0;
            }
        }
    }
    return dst;
}

// Writes the unique id of an id-only actor.
int func_80800AD8_subaddiestore(actor, out)
Actor *actor;
u32 *out;
{
    if (func_80800260_subaddiestore() != 2) {
        return out;
    }
    out[0] = *(u32 *) ((char *) actor + 0x6C) >> 21;
    return out + 1;
}

// Restores a stored record into the live actor.
void func_80800B24_subaddiestore(record, actor) u8 *record;
u8 *actor;
{
    u8 *tmp;
    u8 *src;
    u8 *sizes;
    u8 *src_prev;
    u8 *dst;
    s32 i;
    s32 unk_0;
    s32 unk_1;
    s32 unk_2;
    f32 timer;
    f32 unk_3;
    f32 range_start;
    f32 range_end;
    f32 scale;

    tmp = record + 0xB0;
    src = tmp;

    *(s32 *) (record + 0) = *(s32 *) (actor + 0);
    *(s16 *) (record + 0x8C) = *(s16 *) (actor + 0x8C);

    if ((*(u32 *) (actor + 0x7C) & 0xFFF) != 0) {
        func_80105634(actor);
    }

    if ((*(u32 *) (actor + 0x94) << 2) >> 22 != 0) {
        func_80106EE0(actor);
    }

    if ((*(u32 *) (record + 0x7C) & 0xFFF) != 0) {
        src_prev = src;
        *(u16 *) (record + 0x7E) &= 0xF000;
        dst = func_8010556C(record);
        rare_memcpy(dst, src, 0x48);
        src = src_prev + 0x48;
    }

    if ((*(u32 *) (record + 0x94) << 2) >> 22 != 0) {
        tmp = src;
        *(u16 *) (record + 0x94) &= 0xC00F;
        dst = func_80106E88(record);
        rare_memcpy(dst, src, 0x18);
        src = tmp + 0x18;
    }

    if (func_80800F98_subaddiestore(record)) {
        sizes = src;
        src += 0xC;
        for (i = 0; i < 3; i++) {
            if (((s16 *) (actor + 0x82))[i] != 0) {
                func_8001B754(((s16 *) (actor + 0x82))[i]);
                ((s16 *) (actor + 0x82))[i] = 0;
            }
            if (((s32 *) sizes)[i] > 0) {
                ((s16 *) (record + 0x82))[i] = func_8001B668(0, ((s32 *) sizes)[i]);
                rare_memcpy(func_8001B798(((s16 *) (record + 0x82))[i]), src, ((s32 *) sizes)[i]);
                src = ((s32 *) sizes)[i] + src;
            }
        }
    }

    rare_memcpy(actor, record, 0x9C);

    if ((*(s16 *) (actor + 0x8C) != 0) || ((SBAE *) record)->neg) {
        tmp = func_80104248(actor);

        if (((SBAE *) record)->neg) {
            if (tmp == 0) {
                tmp = func_801042B8(actor);
            }

            if (((SB9C *) record)->pb) {
                anctrl_setPlaybackType(tmp, ((SB9C *) record)->pb);
            }

            anctrl_setIndex(tmp, (u32) *(u16 *) (record + 0x9E) >> 2);
            func_8008B188(tmp, *(u32 *) (record + 0xAC) >> 31);
            anctrl_setSmoothTransition(tmp, *(u32 *) (record + 0x9C) >> 31);
            anctrl_setDuration(tmp, *(f32 *) (record + 0xA0));

            scale = 0.000030517578125f;
            range_start = (f32) *(u16 *) (record + 0xA8) * scale;
            range_end = (f32) *(u16 *) (record + 0xAA) * scale;
            timer = (f32) *(u16 *) (record + 0xA4) * scale;
            timer = func_800F0D50(timer, range_start, range_end);
            unk_3 = (f32) *(u16 *) (record + 0xA6) * scale;
            unk_3 = func_800F0D50(unk_3, range_start, range_end);

            func_8008B10C(tmp, timer);
            anctrl_setSubrange(tmp, range_start, range_end);
            anctrl_start(tmp);
            func_8008B2DC(tmp, unk_3);
            func_8008B10C(tmp, timer);
        } else {
            func_80104328(actor);
        }
    }

    tmp = *(u8 **) actor;
    ((SB12 *) tmp)->hi = *(u16 *) (record + 0xAC);

    func_8010A654(actor, (*(u32 *) (record + 0x9C) << 30) >> 31);

    tmp = *(u8 **) actor;
    ((SB2A *) tmp)->b2 = (*(u32 *) (record + 0x9C) << 1) >> 31;

    tmp = *(u8 **) actor;
    ((SB2A *) tmp)->b1 = (*(u32 *) (record + 0x9C) << 2) >> 31;

    ((SB7E *) actor)->b7 = 0;
    ((SB7E *) actor)->b4 = 0;

    tmp = *(u8 **) actor;
    ((SB2AH *) tmp)->f = (*(u32 *) (record + 0xAC) << 17) >> 26;

    tmp = *(u8 **) actor;
    ((SB13 *) tmp)->b = ((SRAEB *) record)->b0;

    tmp = *(u8 **) actor;
    ((SB1B *) tmp)->b = ((SRAEB *) record)->b7;

    func_80103014(actor);
}

// True if any of the three data handles is set.
s32 func_80800F98_subaddiestore(actor)
u8 *actor;
{
    s32 i;

    for (i = 0; i < 3; i++) {
        if (((s16 *) (actor + 0x82))[i] != 0) {
            return 1;
        }
    }
    return 0;
}

// Returns the end of this record, i.e. the start of the next one.
u8 *func_80800FD0_subaddiestore(record)
Actor *record;
{
    u8 *end;
    s32 i;
    s32 *sizes;

    end = (u8 *) record + 0xB0;
    if (record->unk7C_0) {
        end += 0x48;
    }
    if ((record->pad94 << 2) >> 22) {
        end += 0x18;
    }
    if (func_80800F98_subaddiestore(record, end)) {
        sizes = (s32 *) end;
        end += 0xC;
        for (i = 0; i < 3; i++) {
            end = sizes[i] + end;
        }
    }
    return end;
}

// Finds the full record (returns 1) or id-only entry (returns 2) for the actor's unique id; 0 if none.
int func_80801054_subaddiestore(blob, actor, out_record)
OSIoMesgHdr *blob;
void *actor;
OSMesg **out_record;
{
    s16 id_count;
    void *record;
    OSMesg *id_ptr;
    s32 i;
    u32 unique_id;

    unique_id = (*(u32 *) ((char *) actor + 0x6C)) >> 0x15;
    record = (void *) ((char *) blob + 4);
    i = 0;
    if (*(s16 *) blob > 0) {
    loop_1:
        if (unique_id == ((*(u32 *) ((char *) record + 0x6C)) >> 0x15)) {
            *out_record = (OSMesg *) record;
            return 1;
        }
        record = func_80800FD0_subaddiestore(record);
        i += 1;
        if (i >= *(s16 *) blob) {
            i = 0;
            goto block_5;
        }
        goto loop_1;
    }
block_5:
    id_count = *(s16 *) ((char *) blob + 2);
    id_ptr = (OSMesg *) record;
    if (id_count > 0) {
    loop_6:
        i += 1;
        if (unique_id == *(u32 *) id_ptr) {
            *out_record = NULL;
            return 2;
        }
        id_ptr = (OSMesg *) ((char *) id_ptr + 4);
        if (i >= id_count) {
            goto block_9;
        }
        goto loop_6;
    }
block_9:
    return 0;
}

// TU-NOTE: the .data of this overlay is defined in C; values are taken from the ROM.
