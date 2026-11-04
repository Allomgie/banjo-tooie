#include "su/baddiedialog.h"

// Distance test to the player; flags & 7 selects the check, else a 150-unit box.
s32 func_80800000_subaddiedialog(f32 *pos, s32 range, s32 flags)
{
    if (flags & 7) {
        return func_8010CAC0(pos, range);
    }
    return func_8010CB0C(pos, range, 0x96, -0x96);
}

// Fires once when the player can talk; re-arms after the player leaves range.
s32 subaddiedialog_entrypoint_0(Actor *actor, s32 range, s32 flags)
{
    if (actor->unk74_30) {
        actor->unk74_30 = func_80800000_subaddiedialog(actor->position, range, flags);
        return 0;
    }
    if (subaddiedialog_entrypoint_1(actor->position, (u32) range, flags) != 0) {
        actor->unk74_30 = 1;
        return 1;
    }
    return 0;
}

// In range and player able to talk.
s32 subaddiedialog_entrypoint_1(f32 *pos, u32 range, s32 flags)
{
    if (func_80800000_subaddiedialog(pos, range, flags) == 0) {
        return 0;
    }
    if (func_800F4B8C(func_800F54E4(), -1, flags) == 0) {
        return 0;
    }
    return 1;
}

// In range, player able to talk and facing the actor.
s32 subaddiedialog_entrypoint_2(f32 *pos, s32 range, s32 angle, s32 flags)
{
    if (func_80800000_subaddiedialog(pos, range, flags) == 0) {
        return 0;
    }
    if (func_800F4B8C(func_800F54E4(), -1U, flags) == 0) {
        return 0;
    }
    if (func_8080110C_subaddiedialog(pos, range, angle) == 0) {
        return func_8080141C_subaddiedialog();
    }
    return 1;
}

// Like entrypoint_2, but the actor must also face the player.
s32 subaddiedialog_entrypoint_3(f32 *pos, s32 yaw, s32 range, s32 angle, s32 flags)
{
    if (func_80800000_subaddiedialog(pos, range, flags) == 0) {
        return 0;
    }
    if (func_800F4B8C(func_800F54E4(), -1U, flags) == 0) {
        return 0;
    }
    if ((func_8080110C_subaddiedialog(pos, range, angle) == 0) ||
        (func_8080118C_subaddiedialog(pos, yaw, range, angle) == 0)) {
        return func_8080141C_subaddiedialog();
    }
    return 1;
}

// Range (if pos is given) and B button pressed with the player able to talk.
s32 subaddiedialog_entrypoint_4(f32 *pos, s32 range, s32 flags)
{
    if ((pos != NULL) && (func_80800000_subaddiedialog(pos, range, flags) == 0)) {
        return 0;
    }
    // If B button is being held
    if (func_80016B30(0, 1) != 1) {
        return 0;
    }
    return func_800F4BB8(func_800F54E4(), -1, flags);
}

// Range, player-facing check and B button pressed.
s32 subaddiedialog_entrypoint_5(f32 *pos, s32 range, s32 angle, s32 flags)
{
    if (func_80800000_subaddiedialog(pos, range, flags) == 0) {
        return 0;
    }
    if (func_8080110C_subaddiedialog(pos, range, angle) == 0) {
        return 0;
    }
    // If B button is being held
    if (func_80016B30(0U, 1U) != 1) {
        return 0;
    }
    return func_800F4BB8(func_800F54E4(), -1U, flags);
}

// Range, both facing checks and B button pressed.
s32 subaddiedialog_entrypoint_6(f32 *pos, s32 yaw, s32 range, s32 angle, s32 flags)
{
    if (func_80800000_subaddiedialog(pos, range, flags) == 0) {
        return 0;
    }
    if ((func_8080110C_subaddiedialog(pos, range, angle) == 0) ||
        (func_8080118C_subaddiedialog(pos, yaw, range, angle) == 0)) {
        return 0;
    }
    // If B button is being held
    if (func_80016B30(0U, 1U) != 1) {
        return 0;
    }
    return func_800F4BB8(func_800F54E4(), -1U, flags);
}

// Data-driven approach dialog: checks once-only flag, range, facing and player state; returns the dialog id or 0.
u32 subaddiedialog_entrypoint_7(Actor *actor, f32 *pos, subaddiedialog_UnkStruct0 *entry)
{
    s32 opts;
    u32 unk_0;
    u32 unk_1;
    u32 flags;

    opts = (s32) entry->unk16;
    if (((entry->unk8 != -1) && (entry->unkC != 0)) &&
        (func_800F64A4(func_800F54E4(), entry->unk8) == 0)) {
        flags = entry->unkE;
        if ((flags != 0) && (func_800DA298(entry->unkE) == 0)) {
            flags = entry->unk12;
            if (opts & 0x20) {
                flags |= 1;
            }
            if (func_80800000_subaddiedialog(pos, (s32) entry->unk2, (s32) flags) == 0) {
                return 0U;
            }
            if ((opts & 2) &&
                (func_8080110C_subaddiedialog(pos, (s32) entry->unk2, (s32) entry->unk17) == 0)) {
                return 0U;
            }
            if ((opts & 4) &&
                (func_8080118C_subaddiedialog(pos, (s32) actor->rotation[1], (s32) entry->unk2,
                                              (s32) entry->unk17) == 0)) {
                return 0U;
            }
            if (!(opts & 1) && (func_800F4B8C(func_800F54E4(), -1U, (s32) entry->unk12) == 0)) {
                return 0U;
            }
            flags = entry->unk14;
            if (!(opts & 0x10)) {
                flags |= 2;
            }
            if (subaddiedialog_entrypoint_11(actor->unk0, (u32) entry->unkC, (u32) flags, pos,
                                             (s16) (s32) entry->unk10) != 0) {
                func_800DA544(entry->unkE);

                flags = entry->unk18;
                if (flags != 0) {
                    func_80102424(actor, entry->unk18);
                }
                return entry->unkC;
            }
        } else if (func_80801208_subaddiedialog(pos, entry->unk2, entry->unk12, opts) != 0) {
            if ((opts & 2) &&
                (func_8080110C_subaddiedialog(pos, (s32) entry->unk2, (s32) entry->unk17) == 0)) {
                return func_8080141C_subaddiedialog();
            }
            if ((opts & 4) &&
                (func_8080118C_subaddiedialog(pos, (s32) actor->rotation[1], (s32) entry->unk2,
                                              (s32) entry->unk17) == 0)) {
                return func_8080141C_subaddiedialog();
            }
            flags = entry->unk14;
            if (!(opts & 8)) {
                flags |= 3;
            }
            if (subaddiedialog_entrypoint_11(actor->unk0, (u32) entry->unkC, flags, pos,
                                             (s16) (s32) entry->unk10) != 0) {
                flags = entry->unk18;
                if (flags != 0) {
                    func_80102424(actor, entry->unk18);
                }
                return entry->unkC;
            }
        }
        return func_8080141C_subaddiedialog();
    }
    if (func_80801394_subaddiedialog(actor, opts, entry->unk0) != 0) {
        flags = entry->unk12;
        if (func_800F64A4(func_800F54E4(), entry->unk8) == 0) {
            return 0U;
        }
        if (opts & 0x20) {
            flags |= 1;
        }
        if (func_80800000_subaddiedialog(pos, entry->unk2, flags) == 0) {
            return 0U;
        }
        if ((opts & 2) &&
            (func_8080110C_subaddiedialog(pos, (s32) entry->unk2, (s32) entry->unk17) == 0)) {
            return 0U;
        }
        if ((opts & 4) &&
            (func_8080118C_subaddiedialog(pos, actor->rotation[1], entry->unk2, entry->unk17) == 0)) {
            return 0U;
        }
        if (!(opts & 1) && (func_800F4B8C(func_800F54E4(), -1U, (s32) entry->unk12) == 0)) {
            return 0U;
        }
        flags = entry->unk14;
        if (!(opts & 0x10)) {
            flags |= 2;
        }
        if (subaddiedialog_entrypoint_11(actor->unk0, (u32) entry->unk4, flags, pos,
                                         (s16) (s32) entry->unk10) != 0) {
            func_808013E4_subaddiedialog(actor, opts, (u32) entry->unk0);
            flags = entry->unk18;
            if (flags != 0) {
                func_80102424(actor, entry->unk18);
            }
            return entry->unk4;
        }
        return func_8080141C_subaddiedialog();
    }
    if (func_80801208_subaddiedialog(pos, entry->unk2, entry->unk12, opts) != 0) {
        if (func_800F64A4(func_800F54E4(), entry->unk8) == 0) {
            return func_8080141C_subaddiedialog();
        }
        if ((opts & 2) &&
            (func_8080110C_subaddiedialog(pos, (s32) entry->unk2, (s32) entry->unk17) == 0)) {
            return func_8080141C_subaddiedialog();
        }
        if ((opts & 4) &&
            (func_8080118C_subaddiedialog(pos, (s32) actor->rotation[1], (s32) entry->unk2,
                                          (s32) entry->unk17) == 0)) {
            return func_8080141C_subaddiedialog();
        }
        flags = entry->unk14;
        if (!(opts & 8)) {
            flags |= 3;
        }
        if (subaddiedialog_entrypoint_11(actor->unk0, (u32) entry->unk6, (u32) flags, pos,
                                         (s16) (s32) entry->unk10) != 0) {
            if (entry->unk18) {
                func_80102424(actor, entry->unk18);
            }
            return entry->unk6;
        }
        return func_8080141C_subaddiedialog();
    }
    return 0U;
}

// Approach dialog with per-transformation text tables; returns the dialog id or 0.
s32 subaddiedialog_entrypoint_8(Actor *actor, f32 *pos, subaddiedialog_UnkStruct2 *entry,
                                subaddiedialog_UnkStruct1 *texts, s32 count)
{
    s32 pad2;
    s32 dialog_1;
    s32 dialog_2;
    s32 dialog_3;
    s32 opts;
    s32 pad;
    u32 player;
    s32 value;
    s32 i;
    u32 result;
    s32 flags;
    dialog_1 = 0;
    dialog_2 = 0;
    dialog_3 = 0;
    opts = entry->unkC;
    player = func_800F54E4();
    i = 0;
    if (count > 0) {
        do {
            if (((dialog_1 == 0) && (func_800F64A4(player, texts[i].TransformationType) != 0)) &&
                (texts[i].unk6 == 1)) {
                dialog_1 = texts[i].unk4;
            }
            if (((dialog_2 == 0) && (func_800F64A4(player, texts[i].TransformationType) != 0)) &&
                (texts[i].unk6 == 2)) {
                dialog_2 = texts[i].unk4;
            }
            if (((dialog_3 == 0) && (func_800F64A4(player, texts[i].TransformationType) != 0)) &&
                (texts[i].unk6 == 3)) {
                dialog_3 = texts[i].unk4;
            }
            i += 1;
        } while (i != count);
    }
    if (dialog_1 != 0) {
        flags = entry->unk8;
        if (func_80801394_subaddiedialog(actor, opts, entry->DialogFlag) != 0) {
            if (opts & 0x20) {
                flags |= 1;
            }
            if (func_80800000_subaddiedialog(pos, entry->unk4, flags) == 0) {
                return 0;
            }
            if ((opts & 2) && (func_8080110C_subaddiedialog(pos, entry->unk4, entry->unkD) == 0)) {
                return 0;
            }
            if ((opts & 4) && (func_8080118C_subaddiedialog(pos, actor->rotation[1], entry->unk4,
                                                            entry->unkD) == 0)) {
                return 0;
            }
            if (!(opts & 1) && (func_800F4B8C(player, -1U, entry->unk8) == 0)) {
                return 0;
            }
            flags = entry->unkA;
            if (!(opts & 0x10)) {
                flags |= 2;
            }
            value = func_808010C8_subaddiedialog(actor, dialog_1, 1);
            dialog_1 = value;
            if (subaddiedialog_entrypoint_11(actor->unk0, value, flags, pos, entry->unk6) != 0) {
                func_808013E4_subaddiedialog(actor, opts, entry->DialogFlag);
                value = entry->unkE;
                if (entry->unkE != 0) {
                    func_80102424(actor, value);
                }
                return dialog_1;
            }
            return func_8080141C_subaddiedialog();
        }
    }
    if (dialog_2 != 0) {
        if (func_80801208_subaddiedialog(pos, entry->unk4, entry->unk8, opts) != 0) {
            if ((opts & 2) && (func_8080110C_subaddiedialog(pos, entry->unk4, entry->unkD) == 0)) {
                return func_8080141C_subaddiedialog();
            }
            if ((opts & 4) && (func_8080118C_subaddiedialog(pos, actor->rotation[1], entry->unk4,
                                                            entry->unkD) == 0)) {
                return func_8080141C_subaddiedialog();
            }
            flags = entry->unkA;
            if (!(opts & 8)) {
                flags |= 3;
            }
            dialog_2 = func_808010C8_subaddiedialog(actor, dialog_2, 2);
            if (subaddiedialog_entrypoint_11(actor->unk0, dialog_2, flags, pos, (s16) entry->unk6) !=
                0) {
                flags = entry->unkE;
                if (entry->unkE != 0) {
                    func_80102424(actor, flags);
                }
                return dialog_2;
            }
            return func_8080141C_subaddiedialog();
        }
        return 0;
    }
    result = 0;
    if (dialog_3 != 0) {
        // Matching: `^ 0` is needed for the match.
        if ((entry->unk2 != 0) && (func_800DA298(entry->unk2 ^ 0) == 0)) {
            value = entry->unk8;
            if (opts & 0x20) {
                value |= 1;
            }
            if (func_80800000_subaddiedialog(pos, entry->unk4, value) == 0) {
                return 0;
            }
            if ((opts & 2) && (func_8080110C_subaddiedialog(pos, entry->unk4, entry->unkD) == 0)) {
                return 0;
            }
            if ((opts & 4) && (func_8080118C_subaddiedialog(pos, actor->rotation[1], entry->unk4,
                                                            entry->unkD) == 0)) {
                return 0;
            }
            if (!(opts & 1) && (func_800F4B8C(player, -1U, entry->unk8) == 0)) {
                return 0;
            }
            flags = entry->unkA;
            if (!(opts & 0x10)) {
                flags |= 2;
            }
            dialog_3 = func_808010C8_subaddiedialog(actor, dialog_3, 3);
            if (subaddiedialog_entrypoint_11(actor->unk0, dialog_3, flags, pos, entry->unk6) != 0) {
                func_800DA544(entry->unk2);
                flags = entry->unkE;
                if (entry->unkE) {
                    func_80102424(actor, flags);
                }
                return dialog_3;
            }
        } else if (func_80801208_subaddiedialog(pos, entry->unk4, entry->unk8, opts) != 0) {
            if ((opts & 2) && (func_8080110C_subaddiedialog(pos, entry->unk4, entry->unkD) == 0)) {
                return func_8080141C_subaddiedialog();
            }
            if ((opts & 4) && (func_8080118C_subaddiedialog(pos, actor->rotation[1], entry->unk4,
                                                            entry->unkD) == 0)) {
                return func_8080141C_subaddiedialog();
            }
            flags = entry->unkA;
            if (!(opts & 8)) {
                flags |= 3;
            }
            dialog_3 = func_808010C8_subaddiedialog(actor, dialog_3, 3);
            if (subaddiedialog_entrypoint_11(actor->unk0, dialog_3, flags, pos, entry->unk6) != 0) {
                flags = entry->unkE;
                if (entry->unkE != 0) {
                    func_80102424(actor, flags);
                }
                return dialog_3;
            }
        }
        return func_8080141C_subaddiedialog();
    }
    return result;
}

// Returns the text type of the table entry whose resolved dialog matches dialog_id, else 0.
u8 subaddiedialog_entrypoint_9(Actor *actor, s32 dialog_id, subaddiedialog_UnkStruct1 *texts, s32 count)
{
    s32 i;
    u32 player;
    player = func_800F54E4();
    i = 0;
    if (count > 0) {
        do {
            if ((func_800F64A4(player, texts[i].TransformationType) != 0) &&
                (func_808010C8_subaddiedialog(actor, texts[i].unk4, texts[i].unk6) ==
                 dialog_id)) {
                return texts[i].unk6;
            }
            i += 1;
        } while (i != count);
    }
    return 0U;
}

// Returns 1 if value is neither 0 nor 3. The false path has no return, so v0 carries the result.
s32 subaddiedialog_entrypoint_10(s32 value)
{
    s32 result;
    result = value != 0;
    // Matching: the empty if steers IDO's code generation.
    if (value) {
    }
    if (result) {
        result = value != 3;
        return result;
    }
}

// Resolves a negative dialog id by asking the actor for a reply (message 0xB8).
s32 func_808010C8_subaddiedialog(Actor *actor, s32 dialog_id, s32 variant)
{
    if (dialog_id < 0) {
        dialog_id = func_8010108C(actor, 0xB8, (variant << 0x10) | (-dialog_id & 0xFFFF), dialog_id);
    }
    return dialog_id;
}

// Player faces the actor within the angle window.
s32 func_8080110C_subaddiedialog(f32 *pos, s32 range, s32 angle)
{
    f32 player_pos[3];
    u32 pad;
    f32 angle_to_actor;
    func_8010D254(player_pos);
    angle_to_actor = func_800F1DF4(player_pos, pos);
    return mlAbsF(func_800F1DCC(func_800F5F24(func_800F54E4()), angle_to_actor)) < (f32) angle;
}

// Actor faces the player within the angle window.
s32 func_8080118C_subaddiedialog(f32 *pos, s32 yaw, s32 range, s32 angle)
{
    f32 player_pos[3];

    func_8010D254(player_pos);
    return mlAbsF(func_800F1DCC((f32) yaw, func_800F1DF4(pos, player_pos))) < (f32) angle;
}

// In range and B button pressed with the player able to talk.
s32 func_80801208_subaddiedialog(f32 *pos, s32 range, s32 flags, s32 opts)
{
    s32 talk_flags;

    talk_flags = flags;
    if (opts & 0x20) {
        talk_flags = flags | 1;
    }
    if (func_80800000_subaddiedialog(pos, range, talk_flags) == 0) {
        return 0;
    }
    // If B button is being held
    if (func_80016B30(0U, 1U) != 1) {
        return 0;
    }
    return func_800F4BB8(func_800F54E4(), -1U, flags);
}

// Starts a dialog with the given camera target.
u32 subaddiedialog_entrypoint_11(Unk80132ED0 *owner, u32 dialog_id, u32 flags, f32 *camera_target,
                                 s16 unk_4)
{
    return func_800C0534(dialog_id, flags, camera_target, owner, 0, 0, 0, unk_4);
}

// Sends dialog-reply message 0x2E with two s16 values packed into one word.
void subaddiedialog_entrypoint_12(s32 target, s32 first, s32 second)
{
    s16 packed[2];
    packed[0] = first;
    packed[1] = second;
    func_8010114C(target, 0x2E, ((s32 *) packed)[0]);
}

// Sends dialog-reply message 0x2F with two s16 values packed into one word.
void subaddiedialog_entrypoint_13(s32 target, s32 first, s32 second)
{
    s16 packed[2];
    packed[0] = first;
    packed[1] = second;
    func_8010114C(target, 0x2F, ((s32 *) packed)[0]);
}

// Sends dialog-reply message 0x30 with two s16 values packed into one word.
void subaddiedialog_entrypoint_14(s32 target, s32 first, s32 second)
{
    s16 packed[2];
    packed[0] = first;
    packed[1] = second;
    func_8010114C(target, 0x30, ((s32 *) packed)[0]);
}

// Sends dialog-reply message 0x3A with two s16 values packed into one word.
void subaddiedialog_entrypoint_15(s32 target, s32 first, s32 second)
{
    s16 packed[2];
    packed[0] = first;
    packed[1] = second;
    func_8010114C(target, 0x3a, ((s32 *) packed)[0]);
}

// Returns 1 if the once-only dialog has not been triggered yet.
s32 func_80801394_subaddiedialog(Actor *actor, s32 opts, s32 flag)
{
    s32 result;

    if (opts & 0x40) {
        return actor->unk74_30 == 0;
    }
    // Matching: the empty if steers IDO's code generation.
    if (flag) {
    }
    // Matching: the redundant `!= 0` is needed for the match.
    result = (flag != 0) != 0;
    if (result) {
        result = func_800DA298(flag) == 0;
        return result;
    }
}

// Marks the once-only dialog as triggered (flag, or the actor latch when opts & 0x40).
void func_808013E4_subaddiedialog(Actor *actor, s32 opts, u32 flag)
{
    if (opts & 0x40) {
        actor->unk74_30 = 1;
        return;
    }
    func_800DA544(flag);
}

s32 func_8080141C_subaddiedialog(void)
{
    func_800F5FE0(func_800F54E4());
    return 0;
}

// Returns 1 when a dialog may start right now.
s32 subaddiedialog_entrypoint_16(void)
{
    u32 player;

    if (func_800DB9B0() != 0) {
        return 0;
    }
    player = func_800F54E4();
    if ((player == -1U) || (func_800F6438(player) == 0)) {
        return 0;
    }
    if (func_800F6774(player) == 0) {
        return 0;
    }
    if (func_800C0638() != 0) {
        return 0;
    }
    return 1;
}

// TU-NOTE: the .data of this overlay (formerly asm/data/overlays/su/baddie/dialog.data.s) is defined in C, with values taken from the ROM.
