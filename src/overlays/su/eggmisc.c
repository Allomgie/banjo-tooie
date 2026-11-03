#include "common.h"

extern Actor *func_80106790(Unk80132ED0 *);
extern s16 *func_80100368(Actor *);
void sueggmisc_entrypoint_2();

// Is this prop/marker an egg, or an actor of the egg's own id?
s32 sueggmisc_entrypoint_0(Unk80132ED0 *prop)
{
    s32 id;

    if (!(*(u16 *) &prop->unk18 & 1)) {
        return 0;
    }
    id = prop->unk24 >> 22;
    switch (id) {
        case 0x16D:
        case 0x26C:
        case 0x26D:
        case 0x26E:
            return 1;
        case 0x26F:
        case 0x270:
            return (prop->unk24 >> 22) == *func_80100368(func_80106790(prop));
    }
    return 0;
}

// Collect the egg: refund one egg of its type to the current player.
void sueggmisc_entrypoint_1(u8 *actor)
{
    s32 egg_type_copy;
    s32 egg_type;
    s32 player;

    egg_type = _gcegg_entrypoint_1((u32) (*(s32 *) ((char *) actor + 0x6C) << 0xB) >> 0x14);
    // Matching: the extra copy of the egg type is needed for the match.
    egg_type_copy = egg_type;
    sueggmisc_entrypoint_2(actor + 4, egg_type);
    player = func_800F54E4();
    func_800F7664(player, _gcegg_entrypoint_5(egg_type_copy), 1);
    func_800FFAB0(actor);
}

// Sparkle and jingle for the egg type.
void sueggmisc_entrypoint_2(pos, egg_type) s32 pos;
s32 egg_type;
{
    _fxsparkle_entrypoint_1(pos, _gcegg_entrypoint_4(egg_type));
    func_800FC660(_gcegg_entrypoint_3(egg_type));
}

// Turn off homing eggs (sets flag 0xA31).
s32 sueggmisc_entrypoint_3(void)
{
    func_800DA544(0xA31);
}
