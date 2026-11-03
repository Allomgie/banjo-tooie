#include "core2/1ECE0B0.h"
#include "types.h"

// Party swap: parked character records (0x3C bytes each, vector at D_801354F0),
// party mode (D_801354F8) and the swap state machine (D_80135520).
// TU-NOTE: second half of the former 1ECE0B0 range, from func_800F88A0 on. Functions
// defined in 1ECE0B0 are declared here exactly as defined there (prototype for ANSI,
// empty parameter list for K&R) so every call compiles as in the combined file.

extern s32 func_800DB9B0(void);
extern s32 _plsu_entrypoint_1(s32);
extern s32 D_801354F0;
typedef struct {
    u8 transform_id;
    u8 is_controlled;
    u8 form;
    u8 pad_3[0x19];
    u8 unk_1C;
    u8 unk_1D;
    u8 pad_1E[4];
    s16 map_id;
    u8 pos[0xC];
    u8 rot[0xC];
} EntryF8B94;
extern u8 D_80135510[];
extern u8 D_8013551C[];
extern u8 D_80135500[];
void func_800EE7F8();
void *vector_begin();
void *vector_end();
void func_800EFA4C(f32 *param_0, f32 param_1, f32 param_2, f32 param_3);
extern u8 D_801354FA;
extern void *vector_defrag(void *);
extern f32 func_800EEB40(f32 *, f32 *);
extern u8 D_80135520;
extern u8 D_80135522[];
extern u8 D_80135521[];
extern s32 func_800EA05C(void);
void func_800F8D80();
int func_800F9214();
int func_800F9A24();
int func_800F9A44();
void func_800F9C6C();
extern u8 D_801354F8[];
extern u8 D_801354F9;
extern u8 D_801354FC;
extern u8 D_801354FD;
extern f32 D_8013550C;
s32 func_800F5410();
int func_800F58F8(s32 arg0);
int func_800F5924(s32 arg0);
void func_800F5B38();
int func_800F6204();
s32 func_800F6224(s32 param_0);
int func_800F65D0(s32 param_0);
int func_800F6720();
void func_800F759C(s32 param_0);
void func_800F7CF4(s32 param_0, f32 param_1[3], s32 arg2);
void func_800F7E64(s32 param_0, f32 param_1[3]);
void func_800F80D8(u32 arg0);
void func_800F8128(s32 arg0);
void func_800F8268(s32 arg0, s32 a1, s32 a2);
void func_800F8358(s32 param_0, s32 param_1);

// Find the parked record with the given transformation id, or NULL.
u8 *func_800F88A0(id)
s32 id;
{
    u8 *entry;
    u8 *end;
    entry = vector_begin((void *) D_801354F0, id);
    end = vector_end((void *) D_801354F0);
    if (entry < end) {
        do {
            if (id == *entry) {
                return entry;
            }
            entry += 0x3C;
        } while (entry < end);
    }
    return 0;
}

// Fill a record from the current state of a character.
void func_800F8914(u8 *record, s32 character)
{
    func_800F5A00(character, record + 0x24);
    func_800F5B38(character, record + 0x30);
    _plcamera_entrypoint_14(character, record + 4, record + 0x10);
    *(s8 *) ((s8 *) record + 2) = func_800F9214(character);
    *(s8 *) ((s8 *) record + 0) = func_800F5410(character);
    *(s8 *) ((s8 *) record + 1) = func_800F65D0(character);
    *(s16 *) ((s8 *) record + 0x22) = func_800EA05C();
    *(s8 *) ((s8 *) record + 0x21) = func_800EA090();
    *(s8 *) ((s8 *) record + 0x20) = 2;
    *(s8 *) ((s8 *) record + 0x1D) = func_800F58F8(character);
    *(s8 *) ((s8 *) record + 0x1C) = func_800F5924(character);
}

int func_800F89BC()
{
    u8 *mode = (u8 *) (s32 *) D_801354F8;
    if (*mode == 2) {
        return 0xb;
    }
    return 1;
}

int func_800F89E4(s32 id, s32 out_pos)
{
    s32 map_id;
    if (id == 0xA) {
        // Matching: the "| 0" operands are needed for the match.
        func_800EE7F8(out_pos | 0, (s32 *) D_80135500);
        map_id = *(s32 *) D_8013551C;
    } else if (id == 0xB) {
        func_800EE7F8(out_pos | 0, (s32 *) D_80135510);
        map_id = *(s32 *) D_8013551C;
    }
    return map_id;
}

f32 func_800F8A50(void)
{
    return D_8013550C;
}

int func_800F8A5C()
{
    return *(s16 *) (func_800F88A0() + 0x22);
}

int func_800F8A80()
{
    u8 *record;
    record = func_800F88A0();
    return record[0x21];
}

// Transformation id of the first controlled record.
u8 func_800F8AA4()
{
    u8 *entry = vector_begin((void *) D_801354F0);
    u8 *end = vector_end((void *) D_801354F0);
    while (entry < end) {
        // Matching: "^ 0" is needed for the match.
        u8 controlled = *(u8 *) ((char *) entry + 1) ^ 0;
        if (controlled != 0) {
            return *entry;
        }
        entry += 0x3C;
    }

    return 0;
}

int func_800F8B0C(s32 id, s32 out_pos)
{
    s32 record;
    record = func_800F88A0(id);
    func_800EE7F8(out_pos, record + 0x24);
}

int func_800F8B38(s32 id, s32 out_rot)
{
    s32 record;
    record = func_800F88A0(id);
    func_800EE7F8(out_rot, record + 0x30);
}

s32 func_800F8B64(void)
{
    return (s32) D_801354F9;
}

u8 func_800F8B70(void)
{
    return D_801354FC;
}

u8 func_800F8B7C(void)
{
    return D_801354FD;
}

u8 func_800F8B88(void)
{
    return D_801354F8[0];
}

// Respawn every parked character whose record belongs to the current map.
void func_800F8B94(void)
{
    s32 character;
    EntryF8B94 *begin;
    EntryF8B94 *end;
    EntryF8B94 *entry;
    s32 *saved_pos;
    s32 tmp;

    begin = (EntryF8B94 *) vector_begin(D_801354F0);
    end = (EntryF8B94 *) vector_end(D_801354F0);
    for (entry = begin; entry < end; entry++) {
        if (func_800EA05C() == entry->map_id) {
            character = func_800F6204(0);
            func_800F7E64(character, tmp = entry->transform_id);
            func_800F8268(character, entry->unk_1D, entry->unk_1C);
            if (D_801354F8[1] != 0 && (entry->transform_id == 0xA || entry->transform_id == 0xB)) {
                if (entry->transform_id == 0xA) {
                    saved_pos = (s32 *) D_80135500;
                } else {
                    saved_pos = (s32 *) D_80135510;
                }
                func_800F8294(character, saved_pos);
            } else {
                func_800F8294(character, entry->pos);
            }
            func_800F832C(character, entry->rot);
            if (entry->is_controlled != 0) {
                func_800F80D8(character);
            }
            if (D_801354F8[0] != 1 && (entry->transform_id == 0xA || entry->transform_id == 0xB)) {
                func_800F8358(character, 1);
            }
            tmp = entry->form;
            switch (tmp) {
                case 1:
                    break;
                case 2:
                    func_800F608C(character, 2);
            }
            if (entry->is_controlled != 0) {
                func_800F8D80(character, entry);
            }
        }
    }
}

int func_800F8D50(s32 character, s32 id)
{
    s32 record;
    // Matching: the "| 0" operands are needed for the match.
    record = func_800F88A0(id | 0);
    func_800F8D80(character, record | 0);
}

void func_800F8D80(character, record) s32 character;
s32 record;
{
    _plcamera_entrypoint_12(character, record + 4, record + 0x10);
}

int func_800F8DA8()
{
    int found;
    if (func_800F88A0()) {
        found = 1;
    } else {
        found = 0;
    }
    // Matching: the "| 0" is needed for the match.
    return found | 0;
}

void func_800F8DD8(void)
{
    func_800F9A24();
    vector_free(D_801354F0);
    D_801354F0 = 0;
}

void func_800F8E08(void)
{
    *(s32 **) ((char *) (u8 *) &D_801354F0 + 0) = (s32 *) vector_new(0x3C, 2);
    *(u8 *) ((char *) &D_801354F8 + 0x1) = 0;
    *(u8 *) ((char *) &D_801354F8 + 0x4) = 0;
    *(u8 *) ((char *) &D_801354F8 + 0x5) = 0;
    *(u8 *) ((char *) &D_801354F8 + 0x0) = 0;
    func_800F911C(1);
    func_800EFD24(&D_80135500);
    func_800EFD24(&D_80135510);
    *(s32 *) ((char *) &D_8013551C + 0) = 0;
    func_800F9A44();
}

// Remove the record of the given transformation id, if present.
s32 func_800F8E78()
{
    s32 record = func_800F88A0();
    if (record != 0) {
        vector_erase((void *) D_801354F0, vector_index_of((void *) D_801354F0, record));
    }
}

void func_800F8EBC(s32 character)
{
    func_800F8E78(func_800F5410(character));
}

// Park a character: update its record, or add a new one.
void func_800F8EE4(s32 character)
{
    s32 record;

    record = func_800F88A0(func_800F5410());
    if (record != 0) {
        func_800F8914(record, character);
        return;
    }
    func_800F8914(vector_push_back(&D_801354F0), character);
}

// In split-up mode, move the parked Banjo/Kazooie records to the saved positions.
void func_800F8F3C(void)
{
    u8 *begin;
    u8 *end;
    u8 *entry;
    if ((*(u8 *) ((s8 *) (u8 *) D_801354F8 + 0) == 2) && ((u8 *) D_801354F0 != 0)) {
        begin = vector_begin((u8 *) D_801354F0);
        end = vector_end((u8 *) D_801354F0);
        entry = begin;
        if (begin < end) {
            do {
                if (*(u8 *) ((s8 *) entry + 0) == 0xA) {
                    func_800EE7F8(entry + 0x24, (u32 *) D_80135500);
                    *(s16 *) ((s8 *) entry + 0x22) =
                        (s16) *(s32 *) ((s8 *) (u8 *) D_801354F8 + 0x24);
                    func_800EFA4C(entry + 0x30, 0.0f, *(f32 *) ((s8 *) (u8 *) D_801354F8 + 0x14),
                                  0.0f);
                } else if (*(u8 *) ((s8 *) entry + 0) == 0xB) {
                    func_800EE7F8(entry + 0x24, (u32 *) D_80135510);
                    *(s16 *) ((s8 *) entry + 0x22) =
                        (s16) *(s32 *) ((s8 *) (u8 *) D_801354F8 + 0x24);
                    func_800EFA4C(entry + 0x30, 0.0f, *(f32 *) ((s8 *) (u8 *) D_801354F8 + 0x14),
                                  0.0f);
                }
                entry += 0x3C;
            } while (entry < end);
        }
    }
}

// Set the is-controlled flag of a record.
int func_800F9070(s32 id, s32 controlled)
{
    u8 *flag;
    flag = func_800F88A0(id);
    flag++;
    *flag = controlled;
}

void func_800F9098(s32 id)
{
    if (id == 0xA) {
        func_800EE7F8((int *) D_80135500);
    } else if (id == 0xB) {
        func_800EE7F8((int *) D_80135510);
    }
    *(int *) D_8013551C = func_800EA05C();
}

void func_800F90EC(f32 value)
{
    D_8013550C = value;
}

void func_800F90F8(s32 value)
{
    D_801354F9 = value;
}

void func_800F9104(unsigned int value)
{
    D_801354FC = value;
}

int func_800F9110(int value)
{
    D_801354FD = value;
}

void func_800F911C(mode) s32 mode;
{
    if (*(u8 *) D_801354F8 == 3) {
        func_800CF840(0);
    }

    (*((u8 *) D_801354F8)) = mode;

    if (*(u8 *) D_801354F8 == 3) {
        func_800CF840(1);
    }
}

int func_800F9178()
{
    D_801354FA = 0;
}

int func_800F9184()
{
    return !D_801354FA;
}

void func_800F9198()
{
    if (!D_801354FA) {
        func_800F90F8(0);
        func_800F9104(0);
        func_800F9110(0);
        D_801354FA = 1;
    }

    func_800F9C6C();
}

void func_800F91EC()
{
    D_801354F0 = (s32) vector_defrag((void *) D_801354F0);
}

int func_800F9214()
{
    if (func_800F6720()) {
        return 2;
    }

    return 1;
}

// Write a position offset by 200 on X and Z from the character's position.
void func_800F9240(f32 *out_pos, s32 character)
{
    f32 pos[3];
    func_800F5A00(character, pos);
    pos[0] += 200.0f;
    func_800EFA4C(out_pos, pos[0], pos[1], pos[2] + 200.0f);
}

int func_800F929C()
{
    if (func_800F8B88() == 2) {
        return 0xB;
    }

    return 1;
}

// Outputs the current character, its id, the other character (Banjo <-> Kazooie)
// and the other one's id.
void func_800F92CC(s32 *out_character, volatile s32 *out_id, s32 *out_other, s32 *out_other_id)
{
    s32 character;
    s32 id;

    character = func_800F54E4();
    *out_character = character;
    id = func_800F5410(character);
    *out_id = id;

    switch (id) {
        case 10:
            *out_other_id = 0xB;
            break;
        case 11:
            *out_other_id = 0xA;
    }

    *out_other = _plsu_entrypoint_1(*out_other_id);
}

void func_800F9354(s32 *out_character, s32 *out_id, s32 *out_other_id)
{
    s32 character;
    s32 id;

    character = func_800F54E4();
    *out_character = character;
    id = func_800F5410(character);
    *out_id = id;

    switch (id) {
        case 10:
            *out_other_id = 0xB;
            return;
        case 11:
            *out_other_id = 0xA;
    }
}

int func_800F93C4(s32 *out_character, s32 *out_id)
{
    s32 character;
    character = func_800F54E4();
    *out_character = character;
    // Matching: the "| 0" is needed for the match.
    *out_id = func_800F5410(character | 0);
}

// Start screen wipe 0xC or 0xE, depending on the character id.
int func_800F9400(s32 id)
{
    if (id == 0xA || id == 1) {
        func_800C964C(0xC);
    }

    else {
        func_800C964C(0xE);
    }
}

// Start screen wipe 0xD or 0xF, depending on the character id.
int func_800F9444(s32 id)
{
    if (id == 0xA || id == 1) {
        func_800C964C(0xD);
    }

    else {
        func_800C964C(0xF);
    }
}

// Enter swap state `state` (1..19), running the exit actions of the previous state first.
void func_800F9488(s32 state)
{
    s32 id;
    s32 character;
    s32 other_id;
    s32 other;
    f32 offset_pos[3];
    f32 spawn_pos[3];
    f32 other_pos[3];
    f32 character_pos[3];

    switch (D_80135520) {
        case 3:
            if (state == 1) {
                func_800F92CC(&character, &id, &other, &other_id);
                func_800F82D4(character, 0);
                func_800F8268(character, 1, 1);
            }
            break;

        case 6:
            if (state == 1) {
                func_800F9354(&character, &id, &other_id);
                func_800F8EBC(character);
                func_800F8268(character, 1, 1);
                func_800F82D4(character, 0);
            }
            break;

        case 9:
            if (state == 1) {
                func_800F93C4(&character, &id);
                func_800F8EBC(character);
                func_800F8268(character, 1, 1);
                func_800F82D4(character, 0);
            }
            break;

        case 15:
            if (state == 1) {
                func_800F93C4(&character, &id);
                func_800F8E78(0xA);
            }
    }

    switch (D_80135520 = state) {
        case 2:
            func_800F92CC(&character, &id, &other, &other_id);
            func_800F82D4(character, 2);
            func_800F8268(character, 0, 1);
            func_800F9444(id);
            return;

        case 3:
            func_800F92CC(&character, &id, &other, &other_id);
            func_800F8128(other);
            func_800F8EE4(character);
            func_800F8EBC(other);
            func_800F9400(other_id);
            return;

        case 4:
            func_800F9354(&character, &id, &other_id);
            func_800F82D4(character, 2);
            func_800F9444(id);
            return;

        case 5:
            func_800F9354(&character, &id, &other_id);
            func_800F9070(other_id, 1);
            func_800F8268(character, 0, 1);
            func_800F8EE4(character);
            func_800F9070(id, 0);
            func_800A7990(func_800F8A5C(other_id), 0, 0);
            return;

        case 6:
            func_800F9354(&character, &id, &other_id);
            func_800F82D4(character, 2);
            func_800F9400(id);
            return;

        case 7:
            func_800F9444(func_800F929C());
            return;

        case 8:
            other_id = func_800F929C();
            func_800F9070(other_id, 1);
            if (func_800DB9B0() == 0) {
                func_800A7990(func_800F8A5C(other_id), 0, 0);
            }

            return;

        case 9:
            func_800F93C4(&character, &id);
            func_800F82D4(character, 2);
            func_800F9400(id);
            return;

        case 10:
            func_800F93C4(&character, &id);
            other = _plsu_entrypoint_1(0x11);
            func_800F8128(character);
            func_800F759C(other);
            func_800F8268(character, 1, 1);
            return;

        case 11:
            other = D_80135522[0];
            character = D_80135521[0];
            func_800F8128(other);
            func_800F759C(character);
            func_800F8268(other, 1, 1);
            return;

        case 13:
            func_800F93C4(&character, &id);
            func_800F82D4(character, 2);
            func_800F9444(0xB);
            return;

        case 14:
            func_800F9070(0xA, 1);
            func_800A7990(func_800F8A5C(0xA), 0, 0);
            return;

        case 15:
            func_800F93C4(&character, &id);
            other = func_800F6224(character);
            func_800F7E64(other, 0xB);
            func_800F608C(other, 1);
            func_800F9240(offset_pos, character);
            func_800F7CF4(other, 0x50, offset_pos);
            func_800F9400(0xA);
            return;

        case 16:
            character = _plsu_entrypoint_1(0xB);
            other = _plsu_entrypoint_1(0xA);
            func_800F5A00(character, character_pos);
            func_800F5A00(other, other_pos);
            if (func_800EEB40(character_pos, other_pos) < 4.84e+04f) {
                func_800EE7F8(spawn_pos, character_pos);
            } else {
                func_800F9240(spawn_pos, other);
            }
            func_800F7CF4(character, 0x50, spawn_pos);
            func_800F8128(other);
            func_800F8EBC(other);
            func_800F8268(other, 1, 1);
            return;

        case 17:
            character = _plsu_entrypoint_1(0xB);
            other = _plsu_entrypoint_1(0xA);
            func_800F759C(character);
            func_800D5234(0);
            func_800A16BC(0);
            func_800F8128(other);
            func_800F8EBC(other);
            func_800F7B9C(other, 0x60);
            func_800F8268(other, 1, 1);
    }
}

int func_800F99E8()
{
    u8 *state = (u8 *) ((s32 *) &D_80135520);
    return *state != 1;
}

int func_800F99FC()
{
    u8 *state = &D_80135520;

    if (*state == 0x0E) {
        return 1;
    }

    return 0;
}

int func_800F9A24()
{
    func_800F9488(0);
}

int func_800F9A44()
{
    D_80135520 = 0;
    func_800F9488(1);
}

int func_800F9A6C()
{
    if (_plsu_entrypoint_2()) {
        func_800F9488(2);
    }

    else {
        func_800F9488(4);
    }
}

// Start the Clockwork Kazooie hand-over (state 11), passing two characters.
void func_800F9AAC(long first, int second)
{
    *((s8 *) (((s8 *) (&D_80135520)) + 1)) = first;
    *((s8 *) (((s8 *) (&D_80135520)) + 2)) = second;
    func_800F9488(0xB);
}

void func_800F9ADC()
{
    func_800F9488(0xC);
}

void func_800F9AFC()
{
    s32 id;
    s32 character;
    s32 other;
    func_800F93C4(&character, &id);
    other = _plsu_entrypoint_1(func_800F929C());
    func_800F8128(other);
    func_800F8EBC(other);
    func_800F8268(other, 1, 1);
}

int func_800F9B54()
{
    s32 character;
    s32 clockwork;
    character = func_800F54E4();
    clockwork = _plsu_entrypoint_1(0x11);
    func_800F8128(character);
    func_800F8268(character, 1, 1);
    func_800F82C0(clockwork);
}

void func_800F9BA4()
{
    func_800D9240(0x11);
}

void func_800F9BC4()
{
    if (func_800F8B88() == 3) {
        if (!func_800DB9B0()) {
            switch (D_80135520 - 0xD) {
                case 0:

                case 1:

                case 2:

                case 3:

                case 4:

                case 5:

                case 6:
                    break;

                default:
                    func_800BEAF4();
                    func_800F9488(0x12);
            }
        }
    }
}

int func_800F9C38()
{
    if (func_800F8B88() == 3) {
        func_800F9488(0x13);
    }
}

// Per-frame update: advance the swap state machine once a wipe has finished.
void func_800F9C6C(void)
{
    s32 unk_0;
    s32 map_id;

    switch (D_80135520) {
        case 2:
            if (!func_800C9510())
                func_800F9488(3);
            break;
        case 3:
            if (func_800C95D4())
                func_800F9488(1);
            break;
        case 4:
            if (!func_800C9510())
                func_800F9488(5);
            break;
        case 5:
            func_800F9488(6);
            break;
        case 6:
            if (func_800C95D4())
                func_800F9488(1);
            break;
        case 7:
            if (!func_800C9510())
                func_800F9488(8);
            break;
        case 8:
            func_800F9488(9);
            break;
        case 9:
            if (func_800C95D4())
                func_800F9488(1);
            break;
        case 10:
            func_800F9488(1);
            break;
        case 11:
            func_800F9488(1);
            break;
        case 12:
            if (_plsu_entrypoint_1(func_800F929C()) == -1)
                func_800F9488(7);
            else
                func_800F9488(10);
            break;
        case 13:
            if (!func_800C9510())
                func_800F9488(14);
            break;
        case 14:
            func_800F9488(15);
            break;
        case 15:
            if (func_800C95D4())
                func_800F9488(1);
            break;
        case 16:
            func_800F9488(1);
            break;
        case 17:
            func_800F9488(1);
            break;
        case 18:
            map_id = func_800F8A5C(10);
            if (map_id == func_800EA05C())
                func_800F9488(16);
            else
                func_800F9488(13);
            break;
        case 19:
            map_id = func_800F8A5C(10);
            if (map_id == func_800EA05C())
                func_800F9488(17);
    }
}
