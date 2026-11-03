#include "common.h"

typedef struct {
    f32 duration;
    u32 index : 14, unused : 2, flags : 16;
} LocalEntry_8010DAE0;
extern LocalEntry_8010DAE0 D_80124740[];
extern void anctrl_reset(void *);
extern void anctrl_setDuration(void *, f32);
extern void anctrl_setIndex(void *, s32);
extern void anctrl_setPlaybackType(void *, s32);
extern void anctrl_start(void *);
extern void func_8008B10C(void *, f32);
extern void func_8008B188(void *, s32);
extern void func_8008B4A8(void *, s32);
extern f32 func_800DC0C0(void);
extern s32 func_800DC298(f32);
extern u8 *func_80104148();
extern u8 *func_80104268();
extern s32 func_800AE020(void);
extern void func_800DF72C(s32);
typedef struct {
    u8 pad[0x74];
    u32 unused : 4, enabled : 1, rest : 27;
} LocalActor;
extern u8 *func_800A7180(void);
typedef struct {
    s16 id, pad2;
    u16 flags, pad6;
} LocalEntry_8010DD20;
extern u8 D_80124744[];
extern void func_800ADFE0();

// Configures a shared anim controller from table entry `slot`.
void func_8010DAE0(void *anctrl, s32 slot)
{
    s32 flags;
    flags = D_80124740[slot].flags;
    anctrl_reset(anctrl);
    anctrl_setIndex(anctrl, D_80124740[slot].index);
    anctrl_setDuration(anctrl, D_80124740[slot].duration);
    if (flags & 1) {
        anctrl_setPlaybackType(anctrl, 2);
        func_8008B4A8(anctrl, (flags & 0x100) ? 0 : 1);
    }
    if (flags & 2)
        anctrl_setPlaybackType(anctrl, 1);
    if (flags & 4)
        anctrl_setPlaybackType(anctrl, 3);
    if (flags & 8)
        func_8008B188(anctrl, 1);
    if (flags & 0x10)
        func_8008B188(anctrl, 0);
    if (flags & 0x800)
        func_8008B188(anctrl, func_800DC298(0.5f) ? 1 : 0);
    if (flags & 0x40)
        func_8008B10C(anctrl, 0);
    if (flags & 0x80)
        func_8008B10C(anctrl, 0.999f);
    if (flags & 0x400)
        func_8008B10C(anctrl, func_800DC0C0());
    anctrl_start(anctrl);
}

// Takes a reference on a slot; allocates and configures its controller on first use.
void func_8010DC50(s32 slot)
{
    u8 *entry;
    u8 *anctrl;
    entry = func_80104148(slot);
    if (entry[4] == 0) {
        anctrl = func_80104268(entry + 2);
        func_8010DAE0(anctrl, slot);
        *(u16 *) entry = func_800AE020();
    }
    entry[4]++;
}

// Drops a reference on a slot; frees its controller when the count reaches zero.
void func_8010DCB4(void)
{
    s16 instance;
    u8 new_count;
    u8 refcount;
    u8 *entry;

    entry = func_80104148();
    refcount = *(u8 *) ((char *) entry + 0x4);
    new_count = refcount - 1;
    if ((s32) refcount > 0) {
        *(u8 *) ((char *) entry + 0x4) = new_count;
        if (!(new_count & 0xFF)) {
            func_801042D8(entry + 2);
            func_800ADFE0(*(s16 *) ((char *) entry + 0x0));
            instance = *(s16 *) ((char *) entry + 0x8);
            *(s16 *) ((char *) entry + 0x0) = 0;
            if (instance != 0) {
                func_80100E18(instance);
                *(s16 *) ((char *) entry + 0x8) = 0;
            }
        }
    }
}

// Applies the shared animation of `slot` to the actor's skeleton before drawing.
void func_8010DD20(u8 *actor, s32 slot, u8 *unk_0)
{
    u8 *entry;
    s32 anctrl;
    u8 *unk_1;
    union {
        u8 *pointer;
        s32 id;
    } scratch;
    s32 unk_2;
    // Matching: volatile pointer is needed for the match.
    LocalEntry_8010DD20 *volatile config;

    entry = func_80104148(slot);
    func_801015D0(actor);
    if (((LocalActor *) actor)->enabled) {
        anctrl = func_80104200(*(s16 *) (entry + 2));
        if (anctrl && *(s16 *) entry) {
            if (*(u8 *) (entry + 5) == 0) {
                func_8008B304(anctrl);
                unk_2 = func_800B27E0(unk_0);
                func_8008C200(*(s16 *) entry, unk_2, func_8008AEDC(anctrl));
                if ((*(u16 *) (D_80124744 + slot * 8) & 3) == 2) {
                    unk_1 = func_800A7180();
                    *(s32 *) (entry + 0x10) = *(s32 *) (unk_1 + 4) + 0x40;
                    func_800AE598(func_800AE080(*(s16 *) entry), unk_1 + 4);
                }
            }
            // Matching: the comma expression is needed for the match.
            func_800DF72C(func_800AE080((scratch.id = *(s16 *) entry,
                                         config = &((LocalEntry_8010DD20 *) D_80124740)[slot],
                                         scratch.id)));
            switch (config->flags & 3) {
                case 1:
                    if (*(s16 *) (entry + 8) == 0) {
                        scratch.pointer = *(u8 **) actor;
                        *(s16 *) (entry + 8) =
                            func_80100D24(unk_0, *(u16 *) (scratch.pointer + 0x14), 2, 0,
                                          *(u16 *) (scratch.pointer + 0x16), 0);
                        *(s32 *) (entry + 0xC) = *(s32 *) (unk_0 + 0x28);
                    }
                    func_800DF818(func_80100A74(*(s16 *) (entry + 8), *(u8 *) (entry + 6)));
                    *(s32 *) (unk_0 + 0x28) =
                        *(u8 *) (entry + 5) ? 0 : *(s32 *) (entry + 0xC);
                    break;
                case 2:
                    func_800DF714(*(s32 *) (entry + 0x10));
            }
        }
        *(u8 *) (entry + 5) = 1;
    }
}

// Clears the per-frame "applied" flag of all slots.
int func_8010DEFC()
{
    s32 i;
    u8 *entry;
    for (i = 0; i < 0xB; i++) {
        entry = func_80104148(i);
        entry[5] = 0;
    }
}

// Updates the controllers of all slots that have one.
void func_8010DF3C()
{
    s32 i;
    u8 *entry;
    i = 0;
    do {
        entry = func_80104148(i);
        // Matching: the comma operand is needed for the match.
        if (*(s16 *) (0, (char *) entry + 0x2)) {
            func_8008ADE4(func_80104200(*(s16 *) ((char *) entry + 0x2)));
        }
        i += 1;
    } while (i != 11);
}

// Resets all slots, freeing their controllers.
void func_8010DF98(void)
{
    s32 i;
    u8 *entry;
    i = 0;
    do {
        entry = func_80104148(i);
        if (((*(u8 *) ((s8 *) entry + 4) != 0) || (*(s16 *) ((s8 *) entry + 2) != 0)) ||
            (*(s16 *) ((s8 *) entry + 8) != 0)) {
            *(u8 *) ((s8 *) entry + 4) = 0U;
            *(s16 *) ((s8 *) entry + 2) = 0;
            *(s16 *) ((s8 *) entry + 8) = 0;
        }
        if (*(s16 *) ((s8 *) entry + 0) != 0) {
            func_800ADFE0(*(s16 *) ((s8 *) entry + 0));
            *(s16 *) ((s8 *) entry + 0) = 0;
        }
        i += 1;
    } while (i != 0xB);
}

// TU-NOTE: the .data of this file (was asm/data/core2/1EE73D0.data.s) is defined here in C,
// values from the ROM. D_80124744 is a linker symbol in undefined_syms.us.txt (= D_80124740 + 0x4).
LocalEntry_8010DAE0 D_80124740[12] = {
    2.0f, 0x114, 0x0, 0x9, 1.0f, 0x1CC, 0x0, 0x9, 1.0f,  0x20C, 0x0, 0x9, 3.93f, 0x1FC, 0x0, 0x9,
    1.0f, 0x207, 0x2, 0x9, 1.0f, 0x3C9, 0x1, 0x9, 0.75f, 0x3CA, 0x1, 0x9, 4.0f,  0x362, 0x1, 0x9,
    4.0f, 0x362, 0x1, 0x9, 4.0f, 0x362, 0x1, 0x9, 0.35f, 0x3CC, 0x2, 0x9, 0.0f,  0x0,   0x0, 0x0};
