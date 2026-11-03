#include "common.h"

extern u8 D_80127115;
extern u8 D_80127114;
extern s32 defrag(s32);

extern s32 D_80127110;

// Boot: initialises the chbaddie DLL state block.
void func_800A5BE0()
{
    _chbaddieDll_entrypoint_0(&D_80127110);
}

// Allocates the 0x2C0-byte chbaddie DLL state block.
void func_800A5C04()
{
    D_80127110 = heap_alloc(0x2C0);
}

// Map-start setup: gccollect, chbaddie, subaddietaxi and cosectionstor for the current map.
int func_800A5C28()
{
    _gccollectDll_entrypoint_4();
    _chbaddieDll_entrypoint_1((int *) &D_80127110);
    _subaddietaxi_entrypoint_4();
    _cosectionstor_entrypoint_4(func_800EA05C());
    func_80108C14();
    func_800FFB74();
    if (!func_8001E204()) {
        func_800BDCDC();
    }
}

// After a map load: spawns auto-baddies if D_80127115 is set.
int func_800A5C94()
{
    if ((char) *(s8 *) &D_80127115 != 0) {
        func_801002C0();
    }
}

// Tears down subaddietaxi and the chbaddie DLL.
int func_800A5CC4()
{
    _subaddietaxi_entrypoint_3();
    _chbaddieDll_entrypoint_2(&D_80127110);
}

// Sets the auto-baddie spawn flag.
int func_800A5CF0(int spawn_flag)
{
    D_80127115 = spawn_flag;
}

void func_800A5CFC()
{
    func_800FF62C();
}

// Per-frame post-update, run after the game update and draw.
int func_800A5D1C()
{
    if (D_80127114 != 0) {
        func_8010D1E8();
        _chbaddieDll_entrypoint_3((int *) &D_80127110);
    }
    func_800FFB74();
}

// Returns the chbaddie DLL state block.
int func_800A5D60()
{
    return (int) &D_80127110;
}

// Defragments the chbaddie DLL state block.
int func_800A5D6C()
{
    if (D_80127110 != 0) {
        D_80127110 = defrag(D_80127110);
    }
}
