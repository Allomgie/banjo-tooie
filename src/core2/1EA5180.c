#include "common.h"

// TU-NOTE: D_8012AE84/D_8012AE8C/D_8012AE94 are the group-array fields (+4/+0xC/+0x14) of
// D_8012AE80; D_8012AE98 is its set_enabled table (+0x18).
// TU-NOTE: several wrappers call their callee with an empty argument list, so the incoming
// argument registers pass straight through.

extern void func_800B42A0(void *, void *);
extern s32 D_8012AF60;
extern u8 D_8012AE98[];
extern struct {
    s32 unk_0;
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
} *D_8012AE8C;
extern s32 D_8012AE94;
typedef struct {
    f32 pos[3];
    s16 pad_C;
    s16 half_height;
    f32 radius;
    s32 pad_14;
} EntryCBC3C;
extern f32 func_800EFC7C(f32 *, f32 *);
typedef struct {
    f32 pos[3];
    s16 unk_C, half_height;
    f32 radius;
    u32 pad_14 : 12;
    u32 type_bits : 3;
    u32 pad_14b : 17;
} VolumeCB;
typedef struct {
    u8 pad_0[2];
    u8 flags;
    u8 unk_3;
    f32 pos[3];
    f32 radius;
    s32 set_idx;
    s32 pad_18;
} GroupCB;
typedef struct {
    s32 group_count_0;
    GroupCB *groups_0;
    s32 group_count_1;
    GroupCB *groups_1;
    s32 group_count_2;
    GroupCB *groups_2;
    u8 set_enabled[1];
} StateCB;
extern s32 D_8012AE84;
extern f32 func_800DC178(f32, f32);
extern void func_800EF1B8(f32 *, f32, f32);
s32 func_800CC4D4();

extern StateCB D_8012AE80;

int func_800CB890(group)
s32 group;
{
    // Matching: copy of the parameter is needed for the match.
    s32 group_copy;
    group_copy = group;
    func_800B42A0((void *) D_8012AF60, (void *) (group_copy + 0x18));
}

int func_800CB8BC(group)
s32 group[3];
{
    // Matching: the two pointer temporaries are needed for the match.
    s32 *group_ptr;
    char *group_bytes;
    group_ptr = group;
    group_bytes = (char *) group_ptr;
    return (*(s16 *) (group_bytes + 0x1A) * 0x18) + func_800CB890();
}

int func_800CB8F0()
{
    func_800CB890();
}

u32 func_800CB910(group)
u32 *group;
{
    return ((group[0] >> 9) * 0x18) + func_800CB8F0();
}

int func_800CB948()
{
    func_800CB910();
}

int func_800CB968()
{
    func_800CB8BC();
}

void func_800CB988()
{
    _gcboundDll_entrypoint_0(&D_8012AE80);
}

void func_800CB9AC(void)
{
}

void func_800CB9B4()
{
    _gcboundDll_entrypoint_1(&D_8012AE80);
}

void func_800CB9D8()
{
    _gcboundDll_entrypoint_2(&D_8012AE80);
}

void func_800CB9FC()
{
    _gcboundDll_entrypoint_6(&D_8012AE80);
}

void func_800CBA20()
{
    _gcboundDll_entrypoint_7(&D_8012AE80);
}

void func_800CBA44()
{
    _gcboundDll_entrypoint_8(&D_8012AE80);
}

void func_800CBA68(s32 param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5,
                   s32 param_6)
{
    _gcboundDll_entrypoint_3((s32 *) &D_8012AE80, param_0, param_1, param_2, param_3, param_4,
                             param_5, param_6);
}

void func_800CBAC8(s32 param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4)
{
    _gcboundDll_entrypoint_4((s32 *) &D_8012AE80, param_0, param_1, param_2, param_3, param_4);
}

int func_800CBB18(s32 param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5)
{
    _gcboundDll_entrypoint_5((s32 *) &D_8012AE80, param_0, param_1, param_2, param_3, param_4,
                             param_5);
}

void func_800CBB70(s32 set_idx, s32 enabled)
{
    D_8012AE98[set_idx] = enabled;
}

void func_800CBB80(s32 group_idx, s32 enable)
{
    u8 *group;
    group = (group_idx * 0x1C) + (u8 *) D_8012AE8C;
    if (enable != 0) {
        *(u8 *) ((s8 *) group + 2) = (u8) ((*(u8 *) ((s8 *) group + 2) & 0xFFFFu) | 1);
        return;
    }
    *(u8 *) ((s8 *) group + 2) = (u8) (*(u8 *) ((s8 *) group + 2) & 0xFFFE);
}

int func_800CBBC0(s32 group_idx)
{
    struct {
        s32 unk_0;
        s32 unk_4;
        s32 unk_8;
        s32 unk_C;
        s32 unk_10;
        s32 unk_14;
    } *group;
    group = &D_8012AE8C[group_idx];
    return (*group).unk_14;
}

s32 func_800CBBE0(s32 group_idx)
{
    int group_addr;
    group_addr = (group_idx * 0x1C) + D_8012AE94;
    return *(s32 *) ((s8 *) group_addr + 0x14);
}

s32 func_800CBC00(s32 group_idx)
{
    return *(u16 *) ((s8 *) func_800CB8F0((group_idx * 0x1C) + D_8012AE94) + 0x14) & 1;
}

// Returns the index of the first list 0 group with a volume containing pos, or -1.
s32 func_800CBC3C(pos)
f32 *pos;
{
    GroupCB *group;
    EntryCBC3C *volume, *volume_end;
    for (group = D_8012AE80.groups_0; group < D_8012AE80.group_count_0 + D_8012AE80.groups_0; group++) {
        volume_end = func_800CB910(group);
        for (volume = func_800CB8F0(group); volume < volume_end; volume++) {
            if (volume->pos[1] - volume->half_height < pos[1] &&
                pos[1] < volume->pos[1] + volume->half_height &&
                func_800EFC7C(volume->pos, pos) < volume->radius)
                return group - D_8012AE80.groups_0;
        }
    }
    return -1;
}

int func_800CBD84(s32 pos)
{
    s32 group_idx;
    s32 volume_idx;
    group_idx = func_800CBC3C();
    if (group_idx != -1) {
        volume_idx = func_800CC4D4(pos, group_idx);
        if (volume_idx != -1) {
            return -1;

}
}
return group_idx;
}

// List 1: index of the group with a volume matching type_mask that contains pos, or -1.
s32 func_800CBDD4(f32 *pos, s32 height, s32 type_mask)
{
    GroupCB *group;
    VolumeCB *volume;
    VolumeCB *volume_end;
    f32 top;
    f32 bottom;
    GroupCB *group_end;
    top = pos[1] + height * 0.5f;
    bottom = pos[1] - height * 0.5f;
    for (group = D_8012AE80.groups_1;
         group < (group_end = D_8012AE80.groups_1 + D_8012AE80.group_count_1); group++) {
        if (!(group->flags & 1))
            continue;
        {
            if (func_800EFC7C(group->pos, pos) < group->radius) {
                volume_end = func_800CB910(group);
                if (!D_8012AE80.set_enabled[group->set_idx])
                    continue;
                if (type_mask & 1) {
                    for (volume = func_800CB8F0(group); volume < volume_end; volume++) {
                        if ((volume->type_bits & type_mask) && volume->pos[1] <= top &&
                            bottom < volume->pos[1] &&
                            func_800EFC7C(volume->pos, pos) < volume->radius) {
                            return group - D_8012AE80.groups_1;
                        }
                    }
                } else {
                    for (volume = func_800CB8F0(group); volume < volume_end; volume++) {
                        if ((volume->type_bits & type_mask) &&
                            ((volume->type_bits & 2) ||
                             (volume->pos[1] - volume->half_height <= pos[1] &&
                              pos[1] < volume->pos[1] + volume->half_height)) &&
                            func_800EFC7C(volume->pos, pos) < volume->radius) {
                            return group - D_8012AE80.groups_1;
                        }
                    }
                }
            }

}
}
return -1;
}

// List 2: index of the group with a volume containing pos, or -1. The volume type selects the height bounds.
s32 func_800CC078(f32 *pos)
{
    GroupCB *group;
    VolumeCB *volume;
    VolumeCB *volume_end;
    for (group = D_8012AE80.groups_2; group < D_8012AE80.groups_2 + D_8012AE80.group_count_2;
         group++) {
        if (func_800EFC7C(group->pos, pos) < group->radius) {
            volume_end = func_800CB910(group);
            for (volume = func_800CB8F0(group); volume < volume_end; volume++) {

switch (volume->type_bits) {
    case 0:
        if (func_800EFC7C(volume->pos, pos) < volume->radius)
            return group - D_8012AE80.groups_2;
        break;
    case 1:
        if (volume->pos[1] - volume->half_height < pos[1] &&
            pos[1] < volume->pos[1] + volume->half_height &&
            func_800EFC7C(volume->pos, pos) < volume->radius)
            return group - D_8012AE80.groups_2;
        break;
    case 2:
        if (volume->pos[1] - volume->half_height < pos[1] &&
            func_800EFC7C(volume->pos, pos) < volume->radius)
            return group - D_8012AE80.groups_2;
        break;
    case 3:
        if (pos[1] < volume->pos[1] + volume->half_height &&
            func_800EFC7C(volume->pos, pos) < volume->radius)
            return group - D_8012AE80.groups_2;
}

}
}
}
return -1;
}

// List 0: volume index in the group containing pos, trying volume_idx first; -1 if none.
s32 func_800CC338(f32 *pos, s32 group_idx, s32 volume_idx)
{
    // Matching: unused local, needed for the match.
    s32 unk_0[1];
    GroupCB *group;
    EntryCBC3C *volumes, *volume, *volume_end;
    group = &D_8012AE80.groups_0[group_idx];
    if (func_800CC4D4(pos) != -1)
        return -1;
    volumes = func_800CB8F0(group);
    volume = &volumes[volume_idx];
    if (volume->pos[1] - volume->half_height < pos[1] &&
        pos[1] < volume->pos[1] + volume->half_height &&
        func_800EFC7C(volume->pos, pos) < volume->radius)
        return volume_idx;
    volume_end = func_800CB910(group);
    for (volume = volumes; volume < volume_end; volume++) {
        if (volume->pos[1] - volume->half_height < pos[1] &&
            pos[1] < volume->pos[1] + volume->half_height &&
            func_800EFC7C(volume->pos, pos) < volume->radius)
            return volume - volumes;
    }
    return -1;
}

// Returns the index of the group volume containing pos, or -1.
s32 func_800CC4D4(pos, group_idx)
u8 *pos;
s32 group_idx;
{
    f32 centre_y;
    f32 pos_y;
    // Matching: the -1 result lives in a temporary.
    int not_found;
    u32 range_start;
    f32 half_height;
    u32 range_end;
    u32 volume;
    u8 *group;
    group = (group_idx * 0x1C) + D_8012AE84;
    not_found = -1;
    if ((*((u8 *) (((s8 *) group) + 3))) == 0) {
        return not_found;
    }
    range_start = func_800CB948(group);
    range_end = func_800CB968(group);
    volume = range_start;
    while (volume < range_end) {
        centre_y = *((f32 *) (((s8 *) volume) + 4));
        half_height = (f32) (*((s16 *) (((s8 *) volume) + 0xE)));
        pos_y = *((f32 *) (((s8 *) pos) + 4));
        if ((((centre_y - half_height) < pos_y) && (pos_y < (centre_y + half_height))) &&
            (func_800EFC7C((u8 *) volume, pos) < (*((f32 *) (((s8 *) volume) + 0x10))))) {
            return ((s32) (volume - range_start)) / 24;
        }
        volume += 0x18;
    }

    return not_found;
}

s32 func_800CC5E8()
{
    return *(s32 *) &D_8012AE80;
}

u32 func_800CC5F4(s32 group_idx)
{
    return *(u32 *) ((group_idx * 28) + (u8 *) D_8012AE84) >> 9;
}

u8 func_800CC61C(s32 group_idx)
{
    return (*(u8 *) ((s8 *) (((group_idx * 0x1C) + D_8012AE84)) + (3)));
}

s32 func_800CC63C(group_idx, volume_idx)
s32 group_idx;
s32 volume_idx;
{
    return func_800CB8F0((group_idx * 0x1C) + D_8012AE84) + (volume_idx * 0x18);
}

s32 func_800CC684(s32 group_idx, s32 volume_idx)
{
    return func_800CB948((group_idx * 0x1C) + D_8012AE84) + (volume_idx * 0x18);
}

s32 func_800CC6CC(void)
{
    u16 *flags;
    flags = (u16 *) (((char *) func_800CC63C()) + 0x14);
    return (*flags) & 1;
}

// List 2: volume index in the group containing pos, trying volume_idx first; -1 if none.
s32 func_800CC6F4(f32 *pos, s32 group_idx, s32 volume_idx)
{
    GroupCB *group;
    // Matching: unused local, needed for the match.
    s32 unk_0;
    VolumeCB *volumes;
    VolumeCB *volume_end;
    VolumeCB *volume;
    group = &D_8012AE80.groups_2[group_idx];
    volumes = func_800CB8F0(group);
    volume = &volumes[volume_idx];
    switch (volume->type_bits) {
        case 0:
            if (func_800EFC7C(volume->pos, pos) < volume->radius)
                return volume_idx;
            break;
        case 1:
            if (volume->pos[1] - volume->half_height < pos[1] &&
                pos[1] < volume->pos[1] + volume->half_height &&
                func_800EFC7C(volume->pos, pos) < volume->radius)
                return volume_idx;
            break;
        case 2:
            if (volume->pos[1] - volume->half_height < pos[1] &&
                func_800EFC7C(volume->pos, pos) < volume->radius)
                return volume_idx;
            break;
        case 3:
            if (pos[1] < volume->pos[1] + volume->half_height &&
                func_800EFC7C(volume->pos, pos) < volume->radius)
                return volume_idx;
    }
    volume_end = func_800CB910(group);
    for (volume = volumes; volume < volume_end; volume++) {
        switch (volume->type_bits) {
            case 0:
                if (func_800EFC7C(volume->pos, pos) < volume->radius)
                    return volume - volumes;
                break;
            case 1:
                if (volume->pos[1] - volume->half_height < pos[1] &&
                    pos[1] < volume->pos[1] + volume->half_height &&
                    func_800EFC7C(volume->pos, pos) < volume->radius)
                    return volume - volumes;
                break;
            case 2:
                if (volume->pos[1] - volume->half_height < pos[1] &&
                    func_800EFC7C(volume->pos, pos) < volume->radius)
                    return volume - volumes;
                break;
            case 3:
                if (pos[1] < volume->pos[1] + volume->half_height &&
                    func_800EFC7C(volume->pos, pos) < volume->radius)
                    return volume - volumes;
        }
    }
    return -1;
}

// List 1: volume index in the group matching type_mask that contains pos, trying volume_idx first; -1 if none.
s32 func_800CCAB0(f32 *pos, s32 group_idx, s32 volume_idx, s32 height, s32 type_mask)
{
    GroupCB *group;
    VolumeCB *volume;
    VolumeCB *volumes;
    VolumeCB *volume_end;
    f32 top;
    f32 bottom;
    group = &D_8012AE80.groups_1[group_idx];
    if (!(group->flags & 1))
        return -1;
    if (!D_8012AE80.set_enabled[group->set_idx])
        return -1;
    volumes = func_800CB8F0(group);
    volume = &volumes[volume_idx];
    top = pos[1] + height * 0.5f;
    bottom = pos[1] - height * 0.5f;
    if (type_mask & 1) {
        if ((volume->type_bits & type_mask) && volume->pos[1] <= top &&
            bottom < volume->pos[1] &&
            func_800EFC7C(volume->pos, pos) < volume->radius)
            return volume_idx;
    } else {
        if ((volume->type_bits & type_mask) &&
            ((volume->type_bits & 2) || (volume->pos[1] - volume->half_height <= pos[1] &&
                                        pos[1] < volume->pos[1] + volume->half_height)) &&
            func_800EFC7C(volume->pos, pos) < volume->radius)
            return volume_idx;
    }
    volume_end = func_800CB910(group);
    if (type_mask & 1) {
        for (volume = volumes; volume < volume_end; volume++) {
            if ((volume->type_bits & type_mask) && volume->pos[1] <= top &&
                bottom < volume->pos[1] &&
                func_800EFC7C(volume->pos, pos) < volume->radius)
                return volume - volumes;
        }
    } else {
        for (volume = volumes; volume < volume_end; volume++) {
            if ((volume->type_bits & type_mask) &&
                ((volume->type_bits & 2) || (volume->pos[1] - volume->half_height <= pos[1] &&
                                            pos[1] < volume->pos[1] + volume->half_height)) &&
                func_800EFC7C(volume->pos, pos) < volume->radius)
                return volume - volumes;
        }
    }
    return -1;
}

// List 1 point query using a cached group/volume pair, refreshed on a miss. Returns 1 if pos is inside.
s32 func_800CCDF4(s32 pos, s32 *cached_group, s32 *cached_volume, s32 height, s32 type_mask)
{
    s32 group;
    s32 volume;
    s32 group_retry;
    s32 volume_retry;
    s32 start_volume;

    if (-1 == *cached_group) {
        group = func_800CBDD4(pos, height, type_mask);
        *cached_group = group;
        if (group == -1) {
            *cached_volume = -1;
            return 0;
        }
    }
    if (-1 == *cached_volume) {
        start_volume = 0;
    } else {
        start_volume = *cached_volume;
    }
    volume = func_800CCAB0(pos, *cached_group, start_volume, height, type_mask);
    *cached_volume = volume;
    if (volume >= 0) {
        return 1;
    }
    group_retry = func_800CBDD4(pos, height, type_mask);
    *cached_group = group_retry;
    if (group_retry == -1) {
        *cached_volume = -1;
        return 0;
    }
    volume_retry = func_800CCAB0(pos, *cached_group, 0, height, type_mask);
    *cached_volume = volume_retry;
    if (volume_retry >= 0) {
        return 1;
    }
    *cached_group = -1;
    return 0;
}

// List 2 point query using a cached group/volume pair, refreshed on a miss. Returns 1 if pos is inside.
int func_800CCEF4(void *pos, s32 *cached_group, s32 *cached_volume, s32 param_3)
{
    if (*cached_group == -1) {
        *cached_group = func_800CC078(pos);
        if (*cached_group == -1) {
            *cached_volume = -1;
            return 0;
        }
    }
    *cached_volume = func_800CC6F4(pos, *cached_group, *cached_volume == -1 ? 0 : *cached_volume);
    if (*cached_volume >= 0)
        return 1;
    *cached_group = func_800CC078(pos);
    if (*cached_group == -1) {
        *cached_volume = -1;
        return 0;
    }
    *cached_volume = func_800CC6F4(pos, *cached_group, 0);
    if (*cached_volume >= 0)
        return 1;
    *cached_group = -1;
    return 0;
}

// Defrags the zone arrays.
int func_800CCFEC()
{
    if (((int *) &D_8012AE80)[1]) {
        ((int *) &D_8012AE80)[1] = defrag(((int *) &D_8012AE80)[1]);
    }
    if (((int *) &D_8012AE80)[3]) {
        ((int *) &D_8012AE80)[3] = defrag(((int *) &D_8012AE80)[3]);
    }
    if (((int *) &D_8012AE80)[5]) {
        ((int *) &D_8012AE80)[5] = defrag(((int *) &D_8012AE80)[5]);
    }
    if (((int *) &D_8012AE80)[56]) {
        ((int *) &D_8012AE80)[56] = defrag(((int *) &D_8012AE80)[56]);
    }
}

// Picks a random point inside a random volume of the group and writes it to out_pos.
void func_800CD08C(group_idx, out_pos) s32 group_idx;
u8 *out_pos;
{
    f32 angle;
    f32 max_angle;
    s16 half_height;
    s32 volumes;
    u32 *group;
    u32 volume_count;
    u8 *volume;

    group = (group_idx * 0x1C) + D_8012AE84;
    volume_count = (u32) *group >> 9;
    volumes = func_800CB8F0(group);
    max_angle = 359.0f;
    do {
        volume = (func_800DC128(0, volume_count) * 0x18) + volumes;
        func_800EE7F8(out_pos, volume);
        angle = func_800DC178(0.0f, max_angle);
        func_800EF1B8(out_pos, angle,
                      func_800DC178(0.0f, (f32) (*(s16 *) ((char *) volume + 0xC) - 5)));
        half_height = *(s16 *) ((char *) volume + 0xE);
        *(f32 *) ((char *) out_pos + 4) =
            (f32) (func_800DC178((f32) (5 - half_height), (f32) (half_height - 5)) +
                   *(f32 *) ((char *) out_pos + 4));
    } while (func_800CC4D4(out_pos, group_idx) != -1);
}

void func_800CD1E0(s32 group_idx, f32 *pos, f32 min_y)
{
    func_800CD08C(group_idx);
    if (pos[1] < min_y) {
        pos[1] = min_y;
    }
    // Matching: empty block needed for the match.
    if (!pos) {
    }
}
