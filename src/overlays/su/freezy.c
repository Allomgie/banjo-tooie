#include "common.h"

extern f32 func_800DC178(f32, f32);
extern s32 D_80800300_sufreezy[];
extern void func_8010A570(s32);
extern s32 _sueggmisc_entrypoint_0(s32);
extern void func_8010114C(s32, s32, s32);
extern u8 D_80800328_sufreezy[];
extern u8 D_80800314_sufreezy[];
extern Actor *func_80106790();
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern void func_801094E0(f32 *, f32);
extern void _subaddieaudioquick_entrypoint_2();

// Sets a random thaw time of 6-10 seconds.
void sufreezy_entrypoint_0(block) u8 *block;
{
    *(f32 *) (block + 0x58) = func_800DC178(6.0f, 10.0f);
}

void sufreezy_entrypoint_1()
{
    sufreezy_entrypoint_0();
}

// Releases the frozen victim linked to the block.
void sufreezy_entrypoint_2(s32 block)
{
    u8 *victim;

    victim = _subaddielink_entrypoint_4(func_80100094(block, 1));
    func_8010A570(block);

if (victim != NULL) {
    // Clear the frozen bit.
    *(u8 *) ((s8 *) victim + 0x7B) = (u8) (*(u8 *) ((s8 *) victim + 0x7B) & 0xFFFB);
    func_80102190(victim, 0);
    func_8010A590(victim);
    func_8010108C(victim, 4, 0);
}

_subaddielink_entrypoint_0(func_80100094(block, 1));
}

void sufreezy_entrypoint_3(s32 block)
{
    _subaddieaudioquick_entrypoint_2(block, 0, &D_80800300_sufreezy);
}

// Shatter: sound, particles and radial damage.
void sufreezy_entrypoint_4(Unk80132ED0 *component, s32 unk_1)
{
    Actor *block;

    block = func_80106790(component);
    func_800BBCB8(block->position, block->position, block->scale, unk_1,
                  D_80800328_sufreezy);
    _subaddieaudioquick_entrypoint_2(block, NULL, D_80800314_sufreezy);
    func_801094E0(block->position, block->scale * 1.4f);
}

// Deflects eggs that hit the block.
void sufreezy_entrypoint_5(s32 component, s32 other)
{
    func_8010A570(func_80106790(component));

if (_sueggmisc_entrypoint_0(other) != 0) {
    func_8010114C(other, 5, 0);
}

}

void sufreezy_entrypoint_6(s32 component, s32 unk_1)
{
    u8 *block = func_80106790(component);
    *(f32 *) (block + 0x58) = func_800DC178(6.0f, 10.0f);
}

// A hit on the block is passed on to the victim.
int sufreezy_entrypoint_7(s32 attacker, s32 unk_1)
{
    s32 block;
    s32 link;
    s32 hit_cell;
    u8 *victim;
    block = func_80106790();
    link = func_80100094(block, 1);
    victim = _subaddielink_entrypoint_4(link);
    func_8010A570(block);
    func_8010A590(victim);
    func_80102190(victim, 0);
    victim[0x7B] = victim[0x7B] & 0xFFFB;
    func_8010108C(victim, 4, 0);
    hit_cell = _glhittableDll_entrypoint_4(attacker, *(s32 *) victim);

if (_glhittableDll_entrypoint_2(hit_cell) != 0) {
    func_800EB2DC(*(s32 *) victim, attacker, hit_cell);
}

else
{
    func_800EB210(*(s32 *) victim, attacker, 2);
}
_subaddielink_entrypoint_0(func_80100094(block, 1));
}

// TU-NOTE: the .data of this overlay is defined here in C (values taken from the ROM).
// D_80800300_sufreezy is declared as s32[].
s32 D_80800300_sufreezy[5] = {0x13052B, 0x180001, 0x4E209C4, 0xD00E6, 0x1190000};
u8 D_80800314_sufreezy[20] = {0x0, 0x13, 0x4, 0x8D, 0x0, 0x18, 0x0, 0x1,  0x4, 0xE2,
                              0x9, 0xC4, 0x0, 0xD,  0x1, 0x33, 0x1, 0x4C, 0x0, 0x0};
u8 D_80800328_sufreezy[72] = {0x0, 0x1D, 0x7, 0x5E, 0x0, 0x16, 0x15, 0x86, 0x0,  0x2B, 0x1,  0x33,
                              0x1, 0x99, 0x0, 0x27, 0x0, 0xC8, 0x0,  0xC8, 0x1,  0x90, 0x1,  0x90,
                              0x0, 0x2D, 0x1, 0xF4, 0x2, 0x58, 0x0,  0x1B, 0xFC, 0x18, 0xFC, 0xE0,
                              0x0, 0x22, 0x1, 0x0,  0x1, 0x33, 0x0,  0x80, 0x0,  0x99, 0x0,  0x15,
                              0x0, 0x0,  0x0, 0xCC, 0x0, 0xE,  0x0,  0x1E, 0x0,  0x32, 0x0,  0x7,
                              0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0};
