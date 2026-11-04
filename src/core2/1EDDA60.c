// Pool of per-actor animation controllers (AnimCtrl freelist, s16 handle at actor+0x8C):
// init, free, defrag, get, acquire and release.
#include "common.h"

extern s32 D_80136E70;

// Creates the AnimCtrl freelist (initial capacity 0x20).
int func_80104170()
{
    s32 elem_size;
    elem_size = func_8008B4F4();
    // Matching: `| 0` needed for the match.
    D_80136E70 = freelist_new(elem_size | 0, 0x20);
}

s32 func_801041A0(void)
{
    freelist_free(D_80136E70);
    D_80136E70 = 0;
}

void func_801041C8()
{
    if (D_80136E70 != 0) {
        D_80136E70 = freelist_defrag(D_80136E70);
    }
}

// Returns the controller for a handle, or 0 for handle 0.
s32 func_80104200(handle)
s16 handle;
{
    s32 ctrl;
    ctrl = (handle) ? freelist_at(D_80136E70, handle) : 0;
    return ctrl;
}

// Returns the actor's controller (handle at actor+0x8C).
int func_80104248(s32 actor)
{
    s16 handle;
    handle = *(s16 *) ((char *) actor + 0x8c);
    func_80104200(handle);
}

// Acquires and initialises a controller; stores its handle in *handle_out.
int func_80104268(s16 *handle_out)
{
    s32 handle;
    s32 ctrl;
    handle = 0;
    ctrl = freelist_next(&D_80136E70, &handle);
    // Matching: `| 0` needed for the match.
    func_8008B518(ctrl | 0, 0 | 0);
    *handle_out = handle;
    return ctrl;
}

int func_801042B8(s32 actor)
{
    func_80104268(actor + 0x8C);
}

// Tears down and releases the controller for *handle_ptr.
void func_801042D8(s16 *handle_ptr)
{
    s32 ctrl;
    ctrl = func_80104200(*handle_ptr);

if (ctrl != 0) {
    func_8008B5E8(ctrl);
    freelist_erase((int) D_80136E70, *handle_ptr);
    *handle_ptr = 0;
}

}

int func_80104328(s32 actor)
{
    func_801042D8(actor + 0x8C);
}
