#include "core2/1EC2350.h"

extern f32 func_800D8FF8(void);
extern s32 freelist_capacity();
extern u8 freelist_is_element_alive(void *param_0, s32 param_1);
extern s32 D_8012D680;
extern void *freelist_new(int, int);
extern void *freelist_next(void **, s32 *);
extern void *func_800D674C(u32);
extern int D_80123500[];
float func_800F3780(float arg0, s32 arg1, s32 arg2);
extern u16 D_80132560[];
extern u8 *D_80123524;
extern u8 D_8012D960[];
extern u8 D_8012D690[];
extern void *rare_memcpy(void *, const void *, size_t);
extern u8 unknown3_ROM_START[];
extern s16 D_80131CE0;
extern struct struct_func_80131CFC {
    s16 unk_0;
} D_80131CF6[];
typedef struct {
    u8 refcount[0x50];
    s32 last_used[80];
    s16 bank_id[80], item_id[80];
    u8 pad_2D0[0xD8];
    u8 waves[80][0xD8];
    u8 pad_4728[0x7A0];
    s32 used_count[2];
} CacheE90D8;
extern s32 D_80123514[];
extern s32 D_8012351C[];
extern s32 func_8001211C(void);
extern u8 unknown2_ROM_START[];
typedef struct {
    u8 pad_0[0x4650];
    s16 inst_count;
} Struct800E9438;
typedef struct {
    u8 refcount[80];
    s32 last_used[80];
    s16 bank_id[80];
    s16 item_id[80];
} local_type;
extern u8 D_80132650[940][2];
extern s32 D_80123510;
typedef struct {
    u8 refcount[80];
    s32 last_used[80];
    s16 bank_id[80], item_id[80];
    u8 pad_2D0[0x4EC8 - 0x2D0];
    s32 used_count[2];
} CacheState;
int func_800E8CB0(u8);
int func_800E8CDC(u8 volatile param_0);
int func_800E8DE4(f32 param_0[3], f32 param_1);
void func_800E8E3C();
void func_800E95AC();

void func_800E8A60(void)
{
}

// Advances every live sprite animator by the frame delta.
void func_800E8A68(void)
{
    s32 id;
    f32 dt = func_800D8FF8();
    if ((void *) D_8012D680 != 0) {
        id = 1;
        if (freelist_capacity((void *) D_8012D680) >= 2) {
            while (1) {
                if (freelist_is_element_alive((void *) D_8012D680, id)) {
                    func_800E8DE4(func_800E8CB0(id), dt);
                }
                id++;
                if (id >= freelist_capacity((void *) D_8012D680)) {
                    break;
                }
            }
        }
    }
}

int func_800E8B04()
{
    if (D_8012D680 != 0) {
        freelist_free(D_8012D680);
        D_8012D680 = 0;
    }
}

int func_800E8B3C()
{
    if (D_8012D680 != 0) {
        D_8012D680 = freelist_defrag(D_8012D680);
    }
}

// Creates an animator; the frame count comes from the sprite asset.
u8 func_800E8B74(u32 sprite_id)
{
    void *anim;
    s32 id;
    void *asset;
    if (!(void *) D_8012D680) {
        D_8012D680 = freelist_new(0x50, 2);
    }
    anim = freelist_next((void **) &D_8012D680, &id);
    if (sprite_id != 0) {
        asset = func_800D674C(sprite_id);
        *(s16 *) anim = *(s16 *) asset;
    } else {
        bzero(anim, 0x50);
    }
    func_800E8CDC(id);
    return id;
}

void func_800E8C08(id) u8 id;
{
    freelist_erase(D_8012D680, id);

if (!freelist_used_count(D_8012D680)) {
    freelist_free(D_8012D680);
    D_8012D680 = 0;
}

}

// Returns the current frame index from the animator's evaluated curve value.
s32 func_800E8C58(id)
u8 id;
{
    s32 frame_count_copy;
    s32 anim = func_800E8CB0(id);
    s32 frame_count = *((s16 *) anim);
    s32 frame = (s32) ((*((f32 *) (anim + 12))) * ((f32) frame_count));

// Matching: the extra temporary and the empty if below are needed for the match.
if (frame >= frame_count) {
    frame = (frame_count_copy = frame_count) - 1;
}
if (frame) {
}

return frame;
}

int func_800E8CB0(u8 id)
{
    freelist_at(D_8012D680, id);
}

int func_800E8CDC(u8 volatile id)
{
    f32 *anim;
    anim = func_800E8CB0(id);
    anim[1] = 0.0f;
    func_800E8D28(id, 1.0f);
    func_800E8D5C(id, D_80123500, 2);
}

void func_800E8D28(u8 id, f32 duration)
{
    *(f32 *) ((char *) func_800E8CB0(id) + 8) = duration;
}

void func_800E8D5C(id, keys, key_count) u8 id;
void *keys;
s16 key_count;
{
    u8 *anim;
    anim = func_800E8CB0(id);
    *(s16 *) (anim + 2) = key_count;
    rare_memcpy(anim + 0x10, keys, key_count * 8);
    func_800E8E3C(anim);
}

void func_800E8DB0(id, frame_count) u8 id;
s32 frame_count;
{
    *(s16 *) func_800E8CB0(id) = frame_count;
}

int func_800E8DE4(f32 anim[3], f32 dt)
{
    f32 step;
    step = dt / anim[2];
    anim[1] += step;
    anim[1] -= (f32) (s32) anim[1];
    func_800E8E3C(anim);
}

void func_800E8E3C(anim) s32 anim;
{
    *(f32 *) (anim + 0xc) = func_800F3780(*(float *) (anim + 4), anim + 0x10, *(s16 *) (anim + 2));
}

// Blocking PI DMA from ROM into RAM; pool selects the PI handle.
void func_800E8E70(void *dst, s32 rom_addr, void *size, s32 pool)
{
    s32 unk_0;
    s32 pi_handle;

if (pool == 0) {
    osWritebackDCache(dst, size);
    pi_handle = func_80012F6C();
    osPiStartDma(pi_handle, 1, 0, rom_addr, dst, size, func_80012F60());
    osRecvMesg(func_80012F60(), 0, 1);
    osInvalDCache(dst, size);
    return;
}

osWritebackDCache(dst, size);
pi_handle = func_80012EF4();
osPiStartDma(pi_handle, 1, 0, rom_addr, dst, size, func_80012EE8());
osRecvMesg(func_80012EE8(), 0, 1);
osInvalDCache(dst, size);
}

func_800E8F68(addr)
{
    s32 *words = (s32 *) addr;

if (words[9] != words[8]) {
    return &words[8];
} else {

return 0;
}
}

// Loads a wave record into cache slot and relocates its sample pointer.
void func_800E8F8C(s32 slot, s32 bank_id, s32 item_id, s32 pool)
{
    s32 *unk_0;
    u8 *record;
    s32 index;
    index = D_80132560[bank_id] + item_id;
    func_800E8E70(D_8012D960, (void *) ((u32) D_80123524 + (u32) index * 0xD8), 0xD8, pool);
    record = D_8012D690 + (slot * 0xD8 + 0x3A8);
    rare_memcpy(record, D_8012D960, 0xD8);
    *(u8 **) (record + 0x18) += (u32) unknown3_ROM_START;
}

int func_800E9048()
{
    return D_80131CE0;
}

s16 func_800E9054(s32 param_0)
{
    int index;
    long scaled;
    // Matching: the redundant masks and the do/while (0) are needed for the match.
    do {
        index = (scaled = ((((((param_0 * 9) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) &
                                 0xFFFFFFFFFFFFFFFFu) &
                                0xFFFFFFFFFFFFFFFFu) &
                               0xFFFFFFFFFFFFFFFFu) &
                              0xFFFFFFFFFFFFFFFFu) &
                  0xFFFFFFFFFFFFFFFFu;
        return D_80131CF6[(((index & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) &
                           0xFFFFFFFFFFFFFFFFu) &
                          0xFFFFFFFFFFFFFFFFu]
            .unk_0;
    } while (0);
}

// Increments the refcount of a cached wave record.
void func_800E9070(s32 wave, u8 *unk_0)
{
    s32 offset;
    u8 *refcount;

    offset = wave - (s32) &D_8012D690;
    refcount = &D_8012D690[(offset - 0x3A8) / 0xD8];
    *refcount += 1;
}

// Decrements the refcount of a cached wave record.
void func_800E90A4(s32 wave, u8 *unk_0)
{
    s32 index;
    u8 *refcount;
    index = (wave - (s32) &D_8012D690) - 0x3A8;
    index /= 0xD8;
    refcount = &D_8012D690[index];
    --*refcount;
}

// Returns the cached wave record, loading it (and evicting if full) when missing.
u8 *func_800E90D8(s32 bank_id, s32 item_id, s32 pool)
{
    s32 slot;
    s32 cached;
    s32 key;
    key = D_80132560[bank_id] + item_id;
    cached = ((u8 *) D_80132650)[key * 2 + pool];

if (cached != 0xFF) {
    (*(CacheE90D8 *) D_8012D690).last_used[cached] = func_8001211C();
    return (*(CacheE90D8 *) D_8012D690).waves[cached];
}

if ((*(CacheE90D8 *) D_8012D690).used_count[pool] >= D_80123514[pool] - D_8012351C[pool]) {
    func_800E95AC(0, pool);
    if ((*(CacheE90D8 *) D_8012D690).used_count[pool] >=
        D_80123514[pool] - D_8012351C[pool]) {
        (*(CacheE90D8 *) D_8012D690).last_used[D_8012351C[pool]] = func_8001211C();
        return (*(CacheE90D8 *) D_8012D690).waves[D_8012351C[pool]];
    }
}

for (slot = D_8012351C[pool]; slot < D_80123514[pool]; slot++) {
    if ((*((CacheE90D8 *) D_8012D690)).bank_id[slot] == -1)
        break;
}
func_800E8F8C(slot, bank_id, item_id, pool);
(*((CacheE90D8 *) D_8012D690)).bank_id[slot] = bank_id;
(*((CacheE90D8 *) D_8012D690)).item_id[slot] = item_id;
(*((CacheE90D8 *) D_8012D690)).last_used[slot] = func_8001211C();
(*((CacheE90D8 *) D_8012D690)).used_count[pool]++;
((u8 *) D_80132650)[key * 2 + pool] = slot;
return (*((CacheE90D8 *) D_8012D690)).waves[slot];
}

void func_800E9300(s32 bank_id, s32 item_id)
{
    func_800E90D8(bank_id, item_id, 0x1);
}

void func_800E9320(s32 bank_id, s32 item_id)
{
    func_800E90D8(bank_id, item_id, 0);
}

// Loads one 18-byte instrument entry from ROM into the cache.
void func_800E9340(s32 buf, s32 index, u32 pool)
{
    s32 offset = index * 18;
    func_800E8E70(buf, &unknown2_ROM_START[offset + 8], 0x12, pool);
    rare_memcpy(&D_8012D690[offset + 0x4658], buf, 0x12);
}

u8 *func_800E93AC(s32 index)
{
    return (u8 *) &D_8012D690 + (index * 18) + 0x4658;
}

// Reads the ROM table header and sets the ROM address of the wave records.
void func_800E93CC(s32 pool)
{
    u32 rom_base;
    // Matching: the self-referencing multiply by 0 is needed for the match.
    rom_base = ((u32) unknown2_ROM_START) ^ (rom_base * 0);
    func_800E8E70(&D_80131CE0, (u8 *) rom_base, 8, pool);
    ((u32) D_80123524) = ((D_80131CE0 * 18) + 11) & (-4);
    ((u32) D_80123524) += rom_base;
}

// Loads all instrument entries and builds the first-wave index per instrument.
void func_800E9438(s32 pool)
{
    u8 *entry;
    s32 i;
    s32 total = 0;
    entry = heap_alloc(0x12);
    for (i = 0; i < (*((Struct800E9438 *) D_8012D690)).inst_count; i++) {
        func_800E9340(entry, i, pool);
        ((s16 *) D_80132560)[i] = total;
        total += *(s16 *) (entry + 0xE);
    }
    heap_free(entry);
}

// TU-NOTE: the bss of this unit starts before the static in func_800E94E4; D_80132550
// stands in for the 8 bytes at 0x80132550 that belong to it as well.
static s32 D_80132550[2];
// Resets both wave caches and the lookup table.
void func_800E94E4(void)
{
    static struct {
        s32 unk_0;
        s32 unk_4;
    } D_80132558;
    s32 i;
    for (i = 0; i < 79; i++) {
        (*((local_type *) D_8012D690)).refcount[i] = 0;
        (*((local_type *) D_8012D690)).last_used[i] = 0;
        (*((local_type *) D_8012D690)).bank_id[i] = -1;
        (*((local_type *) D_8012D690)).item_id[i] = -1;
    }
    for (D_80132558.unk_0 = 0, D_80132558.unk_4 = 0, i = 0; i < 940; i++) {
        D_80132650[i][0] = 255;
        D_80132650[i][1] = 255;
    }
}

int func_800E9574()
{
    func_800E94E4();
    func_800E93CC(0);
    func_800E9438(0);
    D_80123510 = 1;
}

// Evicts unreferenced entries of a pool that are older than min_age.
void func_800E95AC(min_age, pool) u32 min_age;
s32 pool;
{
    s32 now;
    s32 i;
    s16 bank_id;
    s32 first, end, key;
    s16 empty_id;
    now = func_8001211C();
    empty_id = -1;
    first = D_8012351C[pool];
    end = D_80123514[pool];
    for (i = first; i < end; i++) {
        bank_id = (*((CacheState *) D_8012D690)).bank_id[i];
        if (empty_id == bank_id)
            continue;
        if ((*((CacheState *) D_8012D690)).refcount[i] != 0)
            continue;
        if (min_age >= (u32) (now - (*((CacheState *) D_8012D690)).last_used[i]))
            continue;
        key = D_80132560[bank_id] + (*((CacheState *) D_8012D690)).item_id[i];
        ((u8(*)[2]) D_80132650)[key][pool] = 255;
        (*((CacheState *) D_8012D690)).bank_id[i] = empty_id;
        (*((CacheState *) D_8012D690)).used_count[pool]--;
    }
}

// Evicts entries not used for more than 200 frames.
func_800E96B0(s32 pool)
{
    // Matching: the no-op OR is needed for the match.
    func_800E95AC(0xC8, pool | 0);
}

// TU-NOTE: the .data of this file is defined here in C, with values taken from the ROM.
// D_80123500 is declared as int[] (uses written as NAME[0]).
int D_80123500[4] = {0x0, 0x0, 0x3F800000, 0x3F800000};
s32 D_80123510 = 0x0;
s32 D_80123514[2] = {0x4F, 0x2F};
s32 D_8012351C[2] = {0x2F, 0x0};
u8 *D_80123524 = 0;
static u32 D_80123524_rest[6] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
