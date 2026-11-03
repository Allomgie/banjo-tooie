#include "common.h"

typedef struct CollisionC6 CollisionC6;
typedef struct {
    CollisionC6 *(*line_test)(f32 *, f32 *, f32 *, u32);
    CollisionC6 *(*sweep_test)(f32 *, f32 *, f32, f32 *, s32, u32);
    CollisionC6 *(*vertical_test)(f32 *, f32, f32 *, u32);
    void *(*get_owner)(void);
} EntryC6;
extern struct {
    EntryC6 entries[8];
    EntryC6 *end;
    void *hit_owner;
} D_8012AA40;
int func_800C696C(f32 pos[3], f32 start_dy, f32 end_dy, s32 mask, f32 *out_y);
void func_800C6A28();
CollisionC6 *func_800C6A7C();

// TU-NOTE: D_8012AAC4 is the hit_owner field at D_8012AA40 + 0x84.
extern s32 D_8012AAC4;

// Vertical floor-height probe; defaults to 100.0 when nothing is hit.
f32 func_800C6920(s32 pos, f32 start_dy, f32 end_dy, s32 mask)
{
    f32 height;
    if (func_800C696C(pos, start_dy, end_dy, mask, &height) == 0) {
        height = 100.0f;
    }
    return height;
}

int func_800C696C(f32 pos[3], f32 start_dy, f32 end_dy, s32 mask, f32 *out_y)
{
    f32 start[3];
    f32 end[3];
    f32 unk_0[3];
    func_800EE7F8(start, pos);
    start[1] += start_dy;
    func_800EE7F8(end, pos);
    end[1] += end_dy;
    if (func_800C6A7C(start, end, unk_0, mask)) {
        *out_y = end[1];
        return 1;
    }
    return 0;
}

// Returns the hit owner of the last query.
s32 func_800C69FC()
{
    return D_8012AAC4;
}

// Registers a provider without an owner getter.
s32 func_800C6A08(s32 line_test, s32 sweep_test, s32 vertical_test)
{
    func_800C6A28(line_test, sweep_test, vertical_test, 0);
}

// Appends a 16-byte provider entry to D_8012AA40.
void func_800C6A28(line_test, sweep_test, vertical_test, get_owner) s32 line_test;
s32 sweep_test;
s32 vertical_test;
s32 get_owner;
{
    (*(s32 *) ((s8 *) ((*(u8 **) ((s8 *) (((s32 *) &D_8012AA40)) + (0x80)))) + (0))) = line_test;
    (*(s32 *) ((s8 *) ((*(u8 **) ((s8 *) (((s32 *) &D_8012AA40)) + (0x80)))) + (4))) = sweep_test;
    (*(s32 *) ((s8 *) ((*(u8 **) ((s8 *) (((s32 *) &D_8012AA40)) + (0x80)))) + (8))) = vertical_test;
    (*(s32 *) ((s8 *) ((*(u8 **) ((s8 *) (((s32 *) &D_8012AA40)) + (0x80)))) + (0xC))) = get_owner;
    (*(u8 **) ((s8 *) (((s32 *) &D_8012AA40)) + (0x80))) =
        (u8 *) ((*(u8 **) ((s8 *) (((s32 *) &D_8012AA40)) + (0x80))) + 0x10);
}

void func_800C6A60(void)
{
}

// Clears the provider list and the hit owner.
int func_800C6A68()
{
    *(int **) ((char *) ((int *) &D_8012AA40) + 0x80) = ((int *) &D_8012AA40);
    *(int *) ((char *) ((int *) &D_8012AA40) + 0x84) = 0;
}

// Line test on every provider; returns the last hit and records its owner.
CollisionC6 *func_800C6A7C(start, end, unk_0, unk_1)
f32 *start;
f32 *end;
f32 *unk_0;
u32 unk_1;
{
    EntryC6 *entry;
    CollisionC6 *hit;
    CollisionC6 *result;
    result = 0;
    D_8012AA40.hit_owner = 0;
    for (entry = &D_8012AA40.entries[0]; entry < D_8012AA40.end; entry++) {

if (entry->line_test != 0) {
    hit = entry->line_test(start, end, unk_0, unk_1);
    if (hit != 0) {
        if (entry->get_owner != 0) {
            D_8012AA40.hit_owner = entry->get_owner();
        } else {
            D_8012AA40.hit_owner = 0;
        }
    }
    result = hit != 0 ? hit : result;
}

}
return result;
}

// Same as func_800C6A7C, with the sphere-sweep test.
CollisionC6 *func_800C6B78(f32 *unk_0, f32 *unk_1, f32 unk_2, f32 *unk_3, s32 unk_4,
                           u32 unk_5)
{
    EntryC6 *entry;
    CollisionC6 *hit;
    CollisionC6 *result;
    result = 0;
    D_8012AA40.hit_owner = 0;
    for (entry = &D_8012AA40.entries[0]; entry < D_8012AA40.end; entry++) {
        if (entry->sweep_test != 0) {
            hit = entry->sweep_test(unk_0, unk_1, unk_2, unk_3, unk_4, unk_5);
            if (hit != 0) {
                if (entry->get_owner != 0) {
                    D_8012AA40.hit_owner = entry->get_owner();
                } else {
                    D_8012AA40.hit_owner = 0;
                }
            }
            result = hit != 0 ? hit : result;
        }

}
return result;
}

// Same as func_800C6A7C, with the vertical/radius test.
CollisionC6 *func_800C6C94(f32 *unk_0, f32 unk_1, f32 *unk_2, u32 unk_3)
{
    EntryC6 *entry;
    CollisionC6 *hit;
    CollisionC6 *result;
    result = 0;
    D_8012AA40.hit_owner = 0;
    for (entry = &D_8012AA40.entries[0]; entry < D_8012AA40.end; entry++) {
        if (entry->vertical_test != 0) {
            hit = entry->vertical_test(unk_0, unk_1, unk_2, unk_3);
            if (hit != 0) {
                if (entry->get_owner != 0) {
                    D_8012AA40.hit_owner = entry->get_owner();
                } else {
                    D_8012AA40.hit_owner = 0;
                }
            }
            result = hit != 0 ? hit : result;
        }

}
return result;
}
