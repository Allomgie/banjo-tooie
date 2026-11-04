// Animation pose cache (a pool of bone-transform buffers with time-to-live) and the Animation
// object embedded in AnimCtrl, which evaluates, cross-fades and post-processes poses per frame.
#include "common.h"

// TU-NOTE: D_80126CC0 is the pose-buffer pool, defined here and viewed as a struct,
// a u32[2] or an s32 base address. Entries are 6 bytes: {handle, ttl, used}.
extern void func_800DFCC0();
typedef struct {
    s16 handle, ttl, used;
} LocalEntry;
typedef struct {
    LocalEntry *start, *end;
} LocalPool;
typedef union {
    LocalPool p;
    u32 a[2];
    s32 s;
} Pool80126CC0;
Pool80126CC0 D_80126CC0;
extern LocalEntry *D_80126CC4;
extern void *heap_realloc(void *, u32);
s32 func_800DFCE8();
s32 func_800DFD10();
typedef struct {
    u8 pad_0[8];
    u8 cur_slot;
    u8 pad_9;
    s16 slot_0, slot_1, slot_2;
    u8 pad_10[10];
    u8 unk_1A, cmd, mode, unk_1D;
} LocalObject;
LocalEntry *func_8008BAC0();
void func_8008BBC0();
int func_8008C1B8();
void func_8008C1C0(f32 *param_0, f32 param_1);
int func_8008C1D4();
int func_8008C1E4(f32 *param_0, f32 param_1);

// Pose (bone-transform) buffer cache with TTL: init, free, flush, defrag.
void func_8008B610(void)
{
    s32 pool_end;
    s32 pool_start;

    pool_start = heap_alloc(0x3C);
    pool_end = pool_start + 0x3C;
    *(s32 *) ((s8 *) (s32 *) D_80126CC0.a + 0) = pool_start;
    *(s32 *) ((s8 *) (s32 *) D_80126CC0.a + 4) = pool_end;
    func_8008BBC0(pool_start, pool_end);
}

// Free all pooled buffers and the pool itself.
void func_8008B64C(void)
{
    s16 *entry;
    for (entry = (s16 *) D_80126CC0.a[0]; entry < (s16 *) D_80126CC0.a[1]; entry += 3) {
        if (entry[2] != 0) {
            if (entry[0] != 0) {
                func_800DFCC0(entry[0]);
                entry[0] = 0;
            }
            entry[2] = 0;
        }
    }
    heap_free((void *) D_80126CC0.a[0]);
    D_80126CC0.a[1] = 0;
    D_80126CC0.a[0] = 0;
}

int func_8008B6E0()
{
    s16 *entry;
    entry = (s16 *) (s32 *) D_80126CC0.a[0];
    while (entry < (s16 *) (s32 *) D_80126CC0.a[1]) {
        if (((entry[2] != 0) && (entry[0] != 0)) && (entry[1] <= 0x3A)) {
            func_800DFCC0(entry[0]);
            entry[0] = 0;
        }
        entry += 3;
    }
}

// Free all buffers and shrink the pool to the last used entry (minimum 10).
void func_8008B768(void)
{
    LocalEntry *entry;
    s32 count = 0;
    for (entry = D_80126CC0.p.start; entry < D_80126CC0.p.end; entry++) {
        if (entry->used) {
            entry->ttl = 0;
            func_800DFCC0(entry->handle);
            entry->handle = 0;
            count = entry - D_80126CC0.p.start + 1;
        }
    }
    if (count < 10)
        count = 10;
    D_80126CC0.p.start = heap_realloc(D_80126CC0.p.start, count * sizeof(LocalEntry));
    D_80126CC0.p.end = D_80126CC0.p.start + count;
}

// Per-frame update: age entries and free buffers whose ttl ran out.
void func_8008B850(void)
{
    LocalEntry *entry;
    for (entry = D_80126CC0.p.start; entry < D_80126CC0.p.end; entry++) {
        if (!entry->used)
            continue;
        if (entry->handle) {
            entry->ttl--;
            if (entry->ttl <= 0) {
                func_800DFCC0(entry->handle);
                entry->handle = 0;
            }
        }
    }
}

// Claim a pool entry and return its 1-based slot index.
s16 func_8008B8E0(void)
{
    s32 index;
    LocalEntry *entry;
    entry = func_8008BAC0(&index);
    entry->ttl = 0;
    entry->handle = 0;
    return index;
}

// True if the slot currently holds a buffer.
s32 func_8008B90C(slot)
s16 slot;
{
    s16 *entry = (s16 *) (slot * 6 + D_80126CC0.s - 6);
    s32 result;

    if (*entry) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

// Free the slot's buffer and release the slot.
void func_8008B954(slot) s16 slot;
{
    u8 *entry;
    unsigned int handle;
    entry = (slot * 6) + D_80126CC0.s;
    handle = *(s16 *) (entry - 6);
    entry -= 6;
    if (handle != 0) {
        // Matching: extra argument needed for the match.
        func_800DFCC0((s16) handle, handle);
        *(s16 *) entry = 0;
    }
    *(s16 *) (entry + 4) = 0;
    *(s16 *) (entry + 2) = *(s16 *) (entry + 4);
}

// Refresh the slot's ttl and return its buffer in out_buf; allocate on miss.
// Returns 1 if the buffer is newly allocated.
s32 func_8008B9C4(s16 slot, s32 *out_buf)
{
    u8 *entry;
    s32 handle;
    entry = (slot * 6) + D_80126CC0.s;
    handle = *(s16 *) (entry - 6);
    entry -= 6;
    *(s16 *) (entry + 2) = 0x3C;
    if (handle != 0) {
        *out_buf = func_800DFCE8((s16) handle);
        return 0;
    }
    *(s16 *) entry = func_800DFD10();
    handle = *(s16 *) entry;
    *out_buf = func_800DFCE8(handle);
    return 1;
}

// Defragment the pool memory.
void func_8008BA5C()
{
    int count;
    count = (((int *) D_80126CC0.a)[1] - ((int *) D_80126CC0.a)[0]) / 6;
    ((int *) D_80126CC0.a)[0] = defrag(((int *) D_80126CC0.a)[0]);
    // Matching: comma expression needed for the match.
    ((int *) D_80126CC0.a)[1] = ((int *) D_80126CC0.a)[0] + ((0, count) * 6);
}

// Find a free entry, growing the pool by 10 when full. Returns the entry and its 1-based index.
LocalEntry *func_8008BAC0(out_index)
s32 *out_index;
{
    LocalEntry *entry;
    s32 old_count;
    s32 new_count;
    for (entry = D_80126CC0.p.start; entry < D_80126CC0.p.end; entry++) {
        if (!entry->used)
            break;
    }
    if (entry == D_80126CC0.p.end) {
        old_count = D_80126CC0.p.end - D_80126CC0.p.start;
        new_count = old_count + 10;
        D_80126CC0.p.start = heap_realloc(D_80126CC0.p.start, new_count * sizeof(LocalEntry));
        D_80126CC4 = D_80126CC0.p.start + new_count;
        entry = D_80126CC0.p.start + old_count;
        func_8008BBC0(entry, D_80126CC0.p.end);
    }
    entry->used = 1;
    *out_index = entry - D_80126CC0.p.start + 1;
    return entry;
}

// Clear the entries in [start, end).
// Matching: the extra temporaries are needed for the match.
void func_8008BBC0(start, end) u32 start;
u32 end;
{
    s16 zero;
    u32 tmp;
    u32 entry;
    entry = start;
    if (start < end) {
        do {
            *(s16 *) ((s8 *) entry + 4) = 0;
            tmp = *(s16 *) ((s8 *) entry + 4);
            zero = tmp;
            entry += 6;
            tmp = entry;
            *(s16 *) ((s8 *) tmp + -6) = 0;
            *(s16 *) ((s8 *) tmp + -4) = zero;
        } while (entry < end);
    }
}

// Animation object: evaluate at timer, cross-fade previous pose, post-process callback, accessors.
// Get a slot's pose buffer; initialise it to identity transforms when newly allocated.
void func_8008BBF0(s32 anim, s32 index)
{
    s32 buffer;
    // Matching: temporary needed for the match.
    long offset;
    offset = index * 2;
    if (func_8008B9C4(*(s16 *) ((anim + offset) + 0xA), &buffer) == 0) {
        func_800DFAD0(buffer);
    }
}

int func_8008BC2C(u8 *anim)
{
    func_8008BBF0(anim, anim[8]);
}

void func_8008BC4C(s32 anim)
{
    func_8008BBF0(anim, 0x2);
}

int func_8008BC6C(s16 *anim, s32 index)
{
    // Matching: the copies and the inline assignment are needed for the match.
    int offset;
    s16 *anim_copy;
    int index_copy;
    index_copy = index;
    anim_copy = anim;
    func_8008B90C(*(s16 *) ((s8 *) &anim_copy[index_copy] + (offset = 10)));
}

int func_8008BC94(anim)
u8 *anim;
{
    func_8008BC6C(anim, anim[8]);
}

int func_8008BCB4(u8 *anim)
{
    s32 other;
    // Matching: the alias variables are needed for the match.
    u8 *anim_bytes;
    void *anim_alias;
    anim_alias = anim;
    anim_bytes = (u8 *) anim;
    if (anim_bytes[8] != 0) {
        other = 0;
    } else {
        other = 1;
    }
    func_8008BC6C(anim_alias, other);
}

int func_8008BCEC(s16 *anim, s32 index)
{
    s32 buffer;
    func_8008B9C4(anim[index + 5], &buffer);
    return buffer;
}

int func_8008BD1C(anim)
u8 *anim;
{
    func_8008BCEC(anim, anim[8]);
}

int func_8008BD3C(void *anim)
{
    s32 other;
    // Matching: the alias variables are needed for the match.
    u8 *anim_bytes;
    void *anim_alias;
    anim_alias = anim;
    anim_bytes = (u8 *) anim;
    if (anim_bytes[8] != 0) {
        other = 0;
    } else {
        other = 1;
    }
    func_8008BCEC(anim_alias, other);
}

int func_8008BD74(s32 anim)
{
    func_8008BCEC(anim, 0x2);
}

// Evaluate the animation into the current pose buffer, blending with the other pose.
void func_8008BD94(u8 *anim)
{
    if ((*(u8 *) ((s8 *) anim + 0x1B) == 1) && (func_8008BC94() != 0)) {
        if (*(u8 *) ((s8 *) anim + 8) != 0) {
            *(u8 *) ((s8 *) anim + 8) = 0U;
        } else {
            *(u8 *) ((s8 *) anim + 8) = 1U;
        }
    }
    *(u8 *) ((s8 *) anim + 0x1B) = 0U;
    if ((*(f32 *) ((s8 *) anim + 0x14) < 1.0f) && (func_8008BCB4(anim) != 0)) {
        func_800E0170(func_800D674C(*(s16 *) ((s8 *) anim + 0x18)),
                      *(s32 *) ((s8 *) anim + 0x10), *(u8 *) ((s8 *) anim + 0x1E),
                      func_8008BD1C(anim));
        func_800DFD64(func_8008BD1C(anim), func_8008BD3C(anim), func_8008BD1C(anim),
                      *(s32 *) ((s8 *) anim + 0x14));
        return;
    }
    func_800E0170(func_800D674C(*(s16 *) ((s8 *) anim + 0x18)), *(s32 *) ((s8 *) anim + 0x10),
                  *(u8 *) ((s8 *) anim + 0x1E), func_8008BD1C(anim));
}

// Same as func_8008BD94 for animations with a third pose slot.
void func_8008BEB4(anim) void *anim;
{
    // Matching: zero kept in a variable for the match.
    int zero;
    s32 unk_0;
    s32 pose;
    s32 cmd;
    cmd = ((u8 *) anim)[0x1B];
    zero = 0;
    if ((cmd == 1) && !((u8 *) anim)[0x1D]) {
        if (func_8008BC94() != 0) {
            if (((u8 *) anim)[0x8] != zero) {
                ((u8 *) anim)[0x8] = 0;
            } else {
                ((u8 *) anim)[0x8] = 1;
            }
            func_8008BC4C(anim);
        }
    } else if (cmd == 2) {
        func_8008BC2C(anim);
    }
    ((u8 *) anim)[0x1B] = zero;
    if ((*(float *) &((u8 *) anim)[0x14] < 1.0f) || ((u8 *) anim)[0x1A]) {
        if (func_8008BCB4(anim) != 0) {
            if (!((u8 *) anim)[0x1D]) {
                ((u8 *) anim)[0x1A] = 0;
                unk_0 = func_800D674C(*(s16 *) ((u8 *) anim + 0x18));
                func_800E0170(unk_0, *(s32 *) ((u8 *) anim + 0x10), ((u8 *) anim)[0x1E],
                              func_8008BD74(anim));
                pose = func_8008BD1C(anim);
                unk_0 = func_8008BD3C(anim);
                func_800DFD64(pose, unk_0, func_8008BD74(anim),
                              *(s32 *) ((u8 *) anim + 0x14));
                return;
            }
        }
    }
    unk_0 = func_800D674C(*(s16 *) ((u8 *) anim + 0x18));
    func_800E0170(unk_0, *(s32 *) ((u8 *) anim + 0x10), ((u8 *) anim)[0x1E],
                  func_8008BD1C(anim));
    if (((u8 *) anim)[0x1D] != 0) {
        if (*(s16 *) ((u8 *) anim + 0x18) != zero) {
            ((u8 *) anim)[0x1D] = 0;
        }
    }
}

// Run the animation, then the optional post-process callback.
void func_8008C038(u8 *anim)
{
    if (*(u8 *) ((s8 *) anim + 0x1C) == 1) {
        func_8008BEB4();
    } else {
        func_8008BD94(anim);
    }
    if (*(s32(**)(s32, s32))((s8 *) anim + 0) != NULL) {
        (*(s32(**)(s32, s32))((s8 *) anim + 0))(func_8008BD1C(anim),
                                                *(s32 *) ((s8 *) anim + 4));
    }
}

void func_8008C0AC(s32 anim)
{
    *(u8 *) (anim + 0x1B) = 1;
}

s32 func_8008C0B8(void)
{
    return 0x20;
}

s32 func_8008C0C0(s32 anim)
{
    return (s16) *(s16 *) (anim + 0x18);
}

f32 func_8008C0C8(f32 anim[5])
{
    // Matching: the extra index variables are needed for the match.
    int index;
    int index_copy;
    index = 3;
    index++;
    return anim[index_copy = index];
}

f32 func_8008C0D0(f32 *anim)
{
    return anim[5];
}

// Release the pose slots.
s32 func_8008C0D8(s32 *anim)
{
    func_8008B954(*(s16 *) ((u8 *) anim + 0xA));
    func_8008B954(*(s16 *) ((u8 *) anim + 0xC));
    if (*((u8 *) anim + 0x1C) == 1) {
        func_8008B954(*(s16 *) ((u8 *) anim + 0xE));
    }
}

void func_8008C124(LocalObject *anim, s32 mode)
{
    anim->mode = mode;
    func_8008C1B8(anim, 0);
    func_8008C1C0(anim, 0);
    func_8008C1E4(anim, 1.0f);
    func_8008C1D4(anim, 0);
    anim->cmd = 0;
    anim->unk_1D = 1;
    anim->unk_1A = 0;
    anim->cur_slot = 0;
    anim->slot_0 = func_8008B8E0();
    anim->slot_1 = func_8008B8E0();
    if (anim->mode == 1)
        anim->slot_2 = func_8008B8E0();
}

int func_8008C1B8(anim, anim_id)
s32 anim;
int anim_id;
{
    *(s16 *) ((u8 *) anim + 0x18) = anim_id;
}

void func_8008C1C0(f32 *anim, f32 timer)
{
    // Matching: the index temporary and its odd initialiser are needed for the match.
    int index;
    index = 3 & 0xFFFFFFFFu;
    index++;
    anim[index] = timer;
}

void func_8008C1CC(s32 anim, s32 flag)
{
    *(u8 *) (anim + 0x1E) = flag;
}

func_8008C1D4(anim, callback) s32 *anim;
s32 callback;
{
    *anim = callback;
}

func_8008C1DC(s32 *anim, s32 arg)
{
    anim[1] = arg;
}

func_8008C1E4(f32 *anim, f32 blend)
{
    anim[5] = blend;
}

func_8008C1F0(u8 *anim, s32 unk_0)
{
    u8 flag = 1;
    anim[0x1A] = flag;
}

int func_8008C200(param_0, param_1, anim)
s16 param_0;
s32 param_1;
s32 anim;
{
    u32 pose;
    // Matching: the `| 0` operations are needed for the match.
    pose = func_8008BD1C(anim | 0);
    func_800AE1E8(param_0, param_1, pose | 0);
}

int func_8008C238(param_0, param_1, anim)
s16 param_0;
s32 param_1;
s32 anim;
{
    u32 pose;
    // Matching: the `| 0` operations are needed for the match.
    pose = func_8008BD1C(anim | 0);
    func_800AE290(param_0, param_1, pose | 0);
}

func_8008C270(anim)
{
    ((u8 *) anim)[0x1B] = 2;
}

int func_8008C27C()
{
    func_8008BD1C();
}
