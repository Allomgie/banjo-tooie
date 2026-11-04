// Warp routing inside Targitzan's temple: decides whether a warp leads to the boss room or to
// the Slightly Sacred Chamber, depending on the map and exit used.
#include "common.h"

extern f32 func_800EEB40(f32 *, f32 *);
extern void func_800DA3B8();
extern void func_800EE88C();

// Picks the warp target map and entrance inside Targitzan's temple.
void sutempleboss_entrypoint_0(void *actor, s32 *out_map, s32 *out_entrance)
{
    s32 use_boss;
    s32 exit_idx;
    f32 dist_b;
    f32 pos[3];
    f32 exit_pos[3];
    f32 dist_a;

    if (!func_800F4BE4(func_800F54E4())) {
        *out_entrance = 0;
        *out_map = 0;
        return;
    }
    switch (func_800EA05C()) {
        case 0x177:
            *out_map = 0x178;
            if (func_800DA298(0x9D2))
                *out_entrance = 2;
            else
                *out_entrance = 1;
            return;
        case 0x17A:
            *out_map = 0x178;
            if (func_800DA298(0x9D2))
                *out_entrance = 1;
            else
                *out_entrance = 2;
            return;
        case 0x178:
            func_800EE88C(pos, actor);
            func_800EE88C(exit_pos, _gccubesearch_entrypoint_15(1, 0, pos));
            dist_a = func_800EEB40(pos, exit_pos);
            func_800EE88C(exit_pos, _gccubesearch_entrypoint_15(2, 0, pos));
            dist_b = func_800EEB40(pos, exit_pos);
            exit_idx = dist_a < dist_b ? 0 : 1;
            // Flag 0x9D2 swaps the two doors; chosen once on first use.
            if (func_800D0B68(2, 1, exit_idx)) {
                if (func_800DA298(0x9D2))
                    use_boss = exit_idx ^ 1;
                else
                    use_boss = exit_idx;
            } else {
                use_boss = 0;
                func_800DA3B8(0x9D2, exit_idx);
            }
            if (use_boss)
                *out_map = 0x17A;
            else
                *out_map = 0x177;
            *out_entrance = 1;
    }
}
