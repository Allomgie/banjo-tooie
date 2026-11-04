// Dialog asset front end: loads a dialog text asset through the cache and returns its string
// block, releases it, checks the text-format marker, and resets per-world dialog state.
#include "common.h"

extern s32 D_80127600[];
extern void func_800D70D0();
typedef struct {
    u8 pad_0[0x20];
    u8 *data;
    s32 asset_id;
} DialogAsset59;
extern DialogAsset59 D_801275E0;
extern void *func_800D674C(s32);

// Language index; hard-wired to 0 in this build.
s32 gldialog_entrypoint_0(void)
{
    return 0;
}

// Text-format marker check (0xFD 0x6A).
int gldialog_entrypoint_1(u8 *text)
{
    return text[0] == 0xFD && text[1] == 0x6A;
}

// Reset the per-world dialog state.
void gldialog_entrypoint_2(void)
{
    D_80127600[0] = 0;
    D_80127600[1] = -1;
}

void gldialog_entrypoint_3(void)
{
}

// Load a dialog asset and return the string block of the current language.
u8 *gldialog_entrypoint_4(s32 asset_id)
{
    u8 *cursor;
    s32 offset;
    u8 *block;

    D_801275E0.data = func_800D674C(asset_id);
    func_800D70D0(1);
    func_800D71F4(1);
    cursor = D_801275E0.data;
    cursor++;
    cursor += gldialog_entrypoint_0() * 2;
    offset = *cursor++;
    offset += *cursor++ << 8;
    block = D_801275E0.data + offset;
    D_801275E0.asset_id = asset_id;
    return block;
}

// Release the dialog asset and reset the dialog state.
void gldialog_entrypoint_5(s32 unk_0)
{
    func_800D721C(D_801275E0.asset_id, 0);
    func_800D70F8(D_801275E0.asset_id, 0);
    func_800D6CEC(D_801275E0.asset_id);
    D_80127600[0] = 0;
    D_80127600[1] = -1;
}
