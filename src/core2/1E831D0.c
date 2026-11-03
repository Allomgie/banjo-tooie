#include "core2/1E831D0.h"

extern s8 D_80127763;
extern void func_8001608C(void);
extern void func_800D3D28(void);
extern void _glrecord_entrypoint_3();
typedef struct {
    u8 kind;
    u8 next_kind;
    u8 pad_2[2];
    u8 unk_4;
    u8 pad_5[1];
    s16 map_id;
    s16 exit_id;
} Struct_80127760;
extern s32 func_800EA05C();
extern s32 func_800EA090(void);
extern unsigned char D_80127760;
extern u8 D_8011A470[];
extern u8 D_8011A478[];
extern u8 D_8011A47C[];
extern void func_800D39A8(void);
extern void func_800D39DC();
extern void func_800D3A88(void);
extern void func_800D3AF0();
extern void func_800D3A20();
void func_800A9D08();

void func_800A98E0()
{
    switch (((u8 *) &D_80127760)[0]) {
        case 1:
            break;

        case 2:
            _gsattract_entrypoint_3();
    }
    D_80127763 = 1;
}

// Called on warp type 3: activates the queued kind and starts recording.
void func_800A9924(unk_0, unk_1) s16 unk_0;
u8 unk_1;
{
    ((u8 *) &D_80127760)[0] = ((u8 *) &D_80127760)[1];
    ((u8 *) &D_80127760)[1] = 0;
    func_800D3D28();

if ((((u8 *) &D_80127760)[0] == 1) || (((u8 *) &D_80127760)[0] == 2)) {
    _glrecord_entrypoint_3(*(s16 *) &((u8 *) &D_80127760)[6], *(s16 *) &((u8 *) &D_80127760)[8]);
}

func_800A9D08();
func_8001608C();

}

// Starts the active sequence kind (1 = Jiggywiggy, 2 = attract demo).
void func_800A9998(void)
{
    switch (((u8 *) &D_80127760)[0]) {
        case 1:
            func_800E80A0();
            break;
        case 2:
            _gsattract_entrypoint_0();
    }

if (((u8 *) &D_80127760)[4] != 0) {
    ((u8 *) &D_80127760)[4] = 0;
}

func_800A1618(1);
}

// Per-frame update.
void func_800A9A14()
{
    func_8001211C();
    _gcgoto_entrypoint_14(1);

if ((((u8 *) &D_80127760)[2] != 0) && (((u8 *) &D_80127760)[3] == 0)) {
    func_800A98E0();
}

switch (((u8 *) &D_80127760)[0]) {
    case 1:
        func_800E8144();
        break;

    case 2:
        _gsattract_entrypoint_1();
}

}

// Per-frame draw.
int func_800A9AA4()
{
    switch (*(u8 *) &D_80127760) {
        case 1:
            func_800E817C();
            break;

        case 2:
            _gsattract_entrypoint_2();
    }

}

// Ends the sequence and restores state.
void func_800A9AF8(void)
{
    switch (*(u8 *) ((s8 *) (u8 *) &D_80127760 + 0)) {
        case 2:
            break;

        case 1:
            func_800E8104();
    }

if (*(u8 *) ((s8 *) (u8 *) &D_80127760 + 4) == 0) {
    func_800D3D58();
    do {
        *(u8 *) ((s8 *) (u8 *) &D_80127760 + 0) = 0;
    } while (0);
    _glrecord_entrypoint_4();
}

*((s8 *) (((s8 *) (((u8 *) &D_80127760))) + 3)) = 0;
*((s8 *) (((s8 *) (((u8 *) &D_80127760))) + 2)) = 0;
func_800A1618(0);
}

void func_800A9B84(void)
{
}

// Stores the map/exit to return to after the sequence.
void func_800A9B8C(s32 ret_map_id, s32 ret_exit_id)
{
    *(s16 *) ((char *) ((s16 *) &D_80127760) + 0xa) = (s16) ret_map_id;
    *(s16 *) ((char *) ((s16 *) &D_80127760) + 0xc) = (s16) ret_exit_id;
}

// Queues a special sequence of the given kind and warps to the map/exit (transition type 3).
void func_800A9BA0(s32 kind, s32 map_id, s32 exit_id)
{
    (*((Struct_80127760 *) &D_80127760)).next_kind = kind;

if ((*(Struct_80127760 *) &D_80127760).kind != 0) {
    (*(Struct_80127760 *) &D_80127760).unk_4 = 1;
}

(*((Struct_80127760 *) &D_80127760)).map_id = map_id;
(*((Struct_80127760 *) &D_80127760)).exit_id = exit_id;
func_800A79D4(map_id, exit_id);
func_800A7A90(1);
func_800A7B18(3);
}

void func_800A9BFC(s32 kind, s32 map_id, s32 exit_id)
{
    // Matching: needed for the match.
    volatile s32 unk_0;
    s32 ret_map_id;
    func_800A9B84();
    ret_map_id = func_800EA05C();
    func_800A9B8C(ret_map_id, func_800EA090());
    func_800A9BA0(kind, map_id, exit_id);

}

// Warps back to the stored return map/exit (transition type 1).
void func_800A9C50()
{
    if (func_800A8264() == 0) {
        func_800A79D4(*(s16 *) ((s8 *) &((u16 *) &D_80127760)[0] + 0xA),
                      *(s16 *) ((s8 *) &((u16 *) &D_80127760)[0] + 0xC));
        func_800A7A90(1);
        func_800A7B18(1);
    }

}

// Nonzero while a special sequence is active.
s32 func_800A9C98()
{
    return (s32) (*((u8 *) &D_80127760)) != 0;
}

int func_800A9CAC(void)
{
    return (*((u8 *) &D_80127760)) ? 1 : 0;
}

unsigned char func_800A9CD0(void)
{
    return D_80127760;

}

int func_800A9CDC()
{
    if (!((u8 *) (s32 *) &D_80127760)[2]) {
        ((u8 *) (s32 *) &D_80127760)[2] = 1;
    }

}

void func_800A9D00(void)
{
}

// Registers the state-restore commands for the flag lists.
void func_800A9D08(void)
{
    u8 *cursor;
    // Matching: bound is first a counter, then an end pointer.
    u8 *bound;
    func_800D39A8();
    func_800D39DC(0);
    func_800D3A88();
    cursor = D_8011A470;
    bound = 0;
    do {
        func_800D3AF0(*cursor);
        cursor++;
        bound++;
    } while ((u32) bound < 7);
    cursor = D_8011A478, bound = D_8011A47C;
    do {
        func_800D3A20(*(s16 *) cursor);
        cursor += 2;
    } while (cursor != bound);
}

// TU-NOTE: the data of this file is defined here in C; values are taken from the ROM.
u8 D_8011A470[8] = {0x40, 0x41, 0x42, 0x43, 0x44, 0x46, 0x47, 0x0};
u8 D_8011A478[4] = {0x0, 0x35, 0x5, 0x9C};
u8 D_8011A47C[4] = {0x0, 0x0, 0x0, 0x0};
