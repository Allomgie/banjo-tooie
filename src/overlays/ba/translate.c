#include "common.h"
#include "overlays/ba/translate.h"
#include "overlays/ba/yaw.h"
#include "overlays/db/skeleton.h"
#include "core2/1E6B900.h"
#include "core2/1E75920.h"
#include "core2/1EC8070.h"

void batranslate_entrypoint_3(PlayerState *self, s32 arg1);

s32 batranslate_entrypoint_0(void)
{
    return sizeof(BaTranslate);
}

// Scales the skeleton's root translation and rotates it by the player yaw.
void func_80800008_batranslate(PlayerState *self, f32 translation[3])
{
    f32 yaw;

    func_800EF334(translation, _dbskeleton_entrypoint_1(func_800B27E0(func_80092B04(self, 0))));

    yaw = yaw_get(self);
    func_800EF934(translation, translation, yaw);
}

void batranslate_entrypoint_1(PlayerState *self)
{
}

void batranslate_entrypoint_2(PlayerState *self)
{
    func_800EFD24(self->translate->unk8);
    func_800EFD24(self->translate->unk14);
    self->translate->unk0 = 0;
    self->translate->unk4 = 0;
    batranslate_entrypoint_3(self, 1);
}

// Mode 1 disables root motion, mode 2 enables it.
void batranslate_entrypoint_3(PlayerState *self, s32 mode)
{
    switch (mode) {
        case 1:
            func_8008C9E4(self, 0);
            func_8009ADF0(self, 6, 0);
            break;

        case 2:
            func_800EFD24(self->translate->unk8);
            self->translate->unk0 = 2;
            func_8009ADF0(self, 6, 1);
    }
    self->translate->unk4 = mode;
}

// Applies the animation's root translation to the player position instead of physics.
void batranslate_entrypoint_4(PlayerState *self)
{
    f32 pos[3];
    if (self->translate->unk4 != 2) {
        return;
    }
    if ((self->translate->unk0 != 0)) {
        self->translate->unk0--;
        if (self->translate->unk0 != 0) {
            return;
        }
        func_8008C9E4(self, 1);
    }
    func_8009C128(self, pos);
    func_800EF3DC(pos, self->translate->unk8);
    func_8008C958(self, self->translate->unk8);
    func_80800008_batranslate(self, self->translate->unk8);
    func_800EF04C(pos, self->translate->unk8);
    func_8009C0F8(self, pos);
}
