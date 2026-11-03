#include "core2/1E76360.h"

extern s32 D_80117F34[];
extern u32 D_80117F38[1202];
extern u16 D_80117F32[];

s32 func_8009CA70(PlayerState *param_0, s32 param_1, s32 param_2)
{
    s32 local_0 = param_1 * 12;
    return (*(s32 *) ((char *) D_80117F34 + local_0) & param_2) ? 1 : 0;
}

s32 func_8009CAAC(s32 param_0, s32 param_1)
{
    s32 (*local_0)(s32);

    local_0 = (s32(*)(s32)) * (u32 *) &((u8 *) D_80117F38)[param_1 * 0xC];
    if (local_0 != NULL) {
        return local_0(0);
    }
    return 0;
}

int func_8009CAF8(s32 param_0, s32 param_1)
{
    int new_var;
    u32 idx;
    int new_var2;
    new_var =
        ((((param_1 * 3) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) &
        0xFFFFFFFFFFFFFFFFu;
    new_var2 = (((new_var & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) &
               0xFFFFFFFFFFFFFFFFu;
    idx = (new_var2 & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu;
    if (D_80117F38[idx] != 0) {
        return ((int (*)(s32)) D_80117F38[idx])(1);
    }
    return 0;
}

s32 func_8009CB44(s32 param_0, s32 param_1)
{
    s32 *new_var;
    s32 (*local_0)(s32);
    new_var = (s32 *) &((u8 *) D_80117F38)[param_1 * 0xC];
    local_0 = *new_var;
    if (local_0 != 0) {
        return local_0(3);
    }
    return 0;
}

int func_8009CB90(s32 param_0, s32 param_1)
{
    int new_var3;
    int (*new_var)(s32);
    int new_var2;
    new_var3 = (((3 * param_1) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu;
    new_var2 = (((((new_var3 & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) &
                 0xFFFFFFFFFFFFFFFFu) &
                0xFFFFFFFFFFFFFFFFu) &
               0xFFFFFFFFFFFFFFFFu;
    new_var = (int (*)(s32)) D_80117F38[(new_var2 & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu];
    if (new_var != 0) {
        return new_var(2);
    }
    return 0;
}

short func_8009CBDC(s32 param_0, s32 param_1)
{
    return *(s16 *) ((char *) D_80117F32 + param_1 * 12);
}

func_8009CBFC(s32 param_0)
{
}

extern void _bsstand_entrypoint_3();
extern void _bswalk_entrypoint_9();
extern void _bswalk_entrypoint_13();
extern void _bswalk_entrypoint_17();
extern void _bsjump_entrypoint_3();
extern void _bsclaw_entrypoint_3();
extern void _bscrouch_entrypoint_3();
extern void _bsbtrot_entrypoint_15();
extern void _bsbegghead_entrypoint_3();
extern void _bsbeggass_entrypoint_3();
extern void _bsturn_entrypoint_3();
extern void _bstimeout_entrypoint_7();
extern void _bsow_entrypoint_3();
extern void _bsbbuster_entrypoint_0();
extern void _bsbflap_entrypoint_3();
extern void _bsbpeck_entrypoint_3();
extern void _bsbflip_entrypoint_3();
extern void _bsbbarge_entrypoint_0();
extern void _bsbtrot_entrypoint_3();
extern void _bsbtrot_entrypoint_7();
extern void _bsbtrot_entrypoint_11();
extern void _bsbtrot_entrypoint_19();
extern void _bsbfly_entrypoint_7();
extern void _bsbswim_entrypoint_2();
extern void _bsbwhirl_entrypoint_3();
extern void _bsbwhirl_entrypoint_7();
extern void _bsbwhirl_entrypoint_11();
extern void _bsbwhirl_entrypoint_15();
extern void _bsbwhirl_entrypoint_19();
extern void _bswalk_entrypoint_5();
extern void _bsstand_entrypoint_7();
extern void _bsbshock_entrypoint_3();
extern void _bsbshock_entrypoint_7();
extern void _bsbfly_entrypoint_0();
extern void _bsbfly_entrypoint_1();
extern void _bsblongleg_entrypoint_3();
extern void _bsblongleg_entrypoint_7();
extern void _bsblongleg_entrypoint_11();
extern void _bsblongleg_entrypoint_19();
extern void _bsblongleg_entrypoint_15();
extern void _bsbfly_entrypoint_2();
extern void _bsbswim_entrypoint_0();
extern void _bsbswim_entrypoint_1();
extern void _bsswim_entrypoint_0();
extern void _bsswim_entrypoint_1();
extern void _bsjump_entrypoint_7();
extern void _bsbswim_entrypoint_7();
extern void _bstwirl_entrypoint_0();
extern void _bswasher_entrypoint_9();
extern void _bswasher_entrypoint_5();
extern void _bsjig_entrypoint_11();
extern void _bswasher_entrypoint_4();
extern void _bswasher_entrypoint_3();
extern void _bswasher_entrypoint_10();
extern void _bswasher_entrypoint_11();
extern void _bsbswim_entrypoint_3();
extern void _bscarry_entrypoint_1();
extern void _bscarry_entrypoint_2();
extern void _bstalk_entrypoint_3();
extern void _bsjump_entrypoint_20();
extern void _bswasher_entrypoint_6();
extern void _bsjump_entrypoint_15();
extern void _bscarry_entrypoint_3();
extern void _bsdie_entrypoint_3();
extern void _bssilowait_entrypoint_0();
extern void _bswasher_entrypoint_1();
extern void _bsjig_entrypoint_6();
extern void _bsbtrot_entrypoint_23();
extern void _bssub_entrypoint_5();
extern void _bskazstilt_entrypoint_3();
extern void _bskazstilt_entrypoint_7();
extern void _bskazstilt_entrypoint_11();
extern void _bskazstilt_entrypoint_19();
extern void _bskazstilt_entrypoint_15();
extern void _bsbswim_entrypoint_10();
extern void _bskazstilt_entrypoint_23();
extern void _bskazstilt_entrypoint_27();
extern void _bsclimb_entrypoint_3();
extern void _bsclimb_entrypoint_7();
extern void _bsjump_entrypoint_11();
extern void _bstimeout_entrypoint_3();
extern void _bsbswim_entrypoint_8();
extern void _bsblongleg_entrypoint_23();
extern void _bsrebound_entrypoint_0();
extern void _bsbfly_entrypoint_3();
extern void _bsbfly_entrypoint_4();
extern void _bsbfly_entrypoint_5();
extern void _bsthrow_entrypoint_3();
extern void _bskazstilt_entrypoint_31();
extern void _bswasher_entrypoint_2();
extern void _bsbanshack_entrypoint_4();
extern void _bsbanshack_entrypoint_5();
extern void _bsbansnooze_entrypoint_3();
extern void _bsbansnooze_entrypoint_4();
extern void _bsblongleg_entrypoint_27();
extern void _bstntswim_entrypoint_4();
extern void _bstntswim_entrypoint_3();
extern void _bskazpaddle_entrypoint_4();
extern void _bskazpaddle_entrypoint_5();
extern void _bskazegghead_entrypoint_3();
extern void _bskazeggass_entrypoint_3();
extern void _bssplitup_entrypoint_19();
extern void _bssplitup_entrypoint_15();
extern void _bsbeemain_entrypoint_10();
extern void _bsbanbflip_entrypoint_3();
extern void _bsbanswim_entrypoint_0();
extern void _bsbansack_entrypoint_6();
extern void _bstaxi_entrypoint_6();
extern void _bsstatue_entrypoint_5();
extern void _bsbtrot_entrypoint_27();
extern void _bssplat_entrypoint_1();
extern void _bsrest_entrypoint_4();
extern void _bsrest_entrypoint_12();
extern void _bsrest_entrypoint_8();
extern void _bsbfly_entrypoint_8();
extern void _bsswim_entrypoint_2();
extern void _bsbswim_entrypoint_9();
extern void _bsbtrot_entrypoint_31();
extern void _bswalk_entrypoint_21();
extern void _bsbtrot_entrypoint_35();
extern void _bsride_entrypoint_0();
extern void _bsbansack_entrypoint_4();
extern void _bsbansack_entrypoint_5();
extern void _bsbswim_entrypoint_4();
extern void _bsbansack_entrypoint_7();
extern void _bsbanswim_entrypoint_1();
extern void _bsbanswim_entrypoint_2();
extern void _bssub_entrypoint_4();
extern void _bsbswim_entrypoint_14();
extern void _bsbeemain_entrypoint_0();
extern void _bsbeemain_entrypoint_1();
extern void _bsbeemain_entrypoint_2();
extern void _bsbeemain_entrypoint_3();
extern void _bsbeemain_entrypoint_7();
extern void _bsbeemain_entrypoint_9();
extern void _bsbeefly_entrypoint_0();
extern void _bsbeefly_entrypoint_1();
extern void _bsbeefly_entrypoint_2();
extern void _bswasher_entrypoint_7();
extern void _bskazstill_entrypoint_10();
extern void _bsbanswim_entrypoint_3();
extern void _bsbfly_entrypoint_6();
extern void _bswasher_entrypoint_8();
extern void _bskazstill_entrypoint_9();
extern void _bsbabykaz_entrypoint_12();
extern void _bsbtrot_entrypoint_47();
extern void _bsswim_entrypoint_3();
extern void _bsbswim_entrypoint_11();
extern void _bsstand_entrypoint_12();
extern void _bsbfly_entrypoint_9();
extern void _bsbtrot_entrypoint_39();
extern void _bsblongleg_entrypoint_31();
extern void _bsbtrot_entrypoint_43();
extern void _bsbeemain_entrypoint_11();
extern void _bsclimb_entrypoint_11();
extern void _bscarry_entrypoint_0();
extern void _bscarry_entrypoint_4();
extern void _bsfirstp_entrypoint_31();
extern void _bsbswim_entrypoint_6();
extern void _bsbeemain_entrypoint_8();
extern void _bsbwhirl_entrypoint_23();
extern void _bsbwhirl_entrypoint_27();
extern void _bsledge_entrypoint_4();
extern void _bsledge_entrypoint_3();
extern void _bsledge_entrypoint_2();
extern void _bsledge_entrypoint_0();
extern void _bsledge_entrypoint_1();
extern void _bsstonehead_entrypoint_7();
extern void _bsstonehead_entrypoint_11();
extern void _bsstonehead_entrypoint_15();
extern void _bsstonehead_entrypoint_19();
extern void _bsstonehead_entrypoint_27();
extern void _bsstonehead_entrypoint_31();
extern void _bsstonehead_entrypoint_35();
extern void _bsstonehead_entrypoint_23();
extern void _bsstonehead_entrypoint_43();
extern void _bsstonehead_entrypoint_3();
extern void _bsstonehead_entrypoint_39();
extern void _bsbbilldrill_entrypoint_3();
extern void _bsride_entrypoint_2();
extern void _bssplitup_entrypoint_11();
extern void _bssplitup_entrypoint_3();
extern void _bssplitup_entrypoint_7();
extern void _bskazstill_entrypoint_3();
extern void _bskazmove_entrypoint_4();
extern void _bskazjump_entrypoint_3();
extern void _bskazglide_entrypoint_0();
extern void _bsbswim_entrypoint_5();
extern void _bsbeefly_entrypoint_3();
extern void _bskazshock_entrypoint_8();
extern void _bskazwingwhack_entrypoint_1();
extern void _bskazshock_entrypoint_4();
extern void _bskazwingwhack_entrypoint_0();
extern void _bskazhatch_entrypoint_0();
extern void _bskazspring_entrypoint_0();
extern void _bskazmove_entrypoint_10();
extern void _bsfirstp_entrypoint_19();
extern void _bsfirstp_entrypoint_22();
extern void _bsfirstp_entrypoint_35();
extern void _bsfirstp_entrypoint_20();
extern void _bsfirstp_entrypoint_21();
extern void _bsfirstp_entrypoint_23();
extern void _bsfirstp_entrypoint_24();
extern void _bsfirstp_entrypoint_32();
extern void _bsfirstp_entrypoint_33();
extern void _bsfirstp_entrypoint_36();
extern void _bsfirstp_entrypoint_34();
extern void _bsfirstp_entrypoint_8();
extern void _bsfirstp_entrypoint_29();
extern void _bsfirstp_entrypoint_9();
extern void _bsfirstp_entrypoint_11();
extern void _bsfirstp_entrypoint_15();
extern void _bsfirstp_entrypoint_16();
extern void _bsfirstp_entrypoint_17();
extern void _bskazcrouch_entrypoint_4();
extern void _bskazstill_entrypoint_8();
extern void _bskazjump_entrypoint_7();
extern void _bskazjump_entrypoint_15();
extern void _bskazjump_entrypoint_11();
extern void _bsbanpackwhack_entrypoint_3();
extern void _bsmumstill_entrypoint_1();
extern void _bsmummove_entrypoint_4();
extern void _bsmummove_entrypoint_3();
extern void _bsmum_entrypoint_6();
extern void _bsmum_entrypoint_5();
extern void _bsmum_entrypoint_7();
extern void _bsmum_entrypoint_3();
extern void _bsmum_entrypoint_11();
extern void _bsbswim_entrypoint_13();
extern void _bsmum_entrypoint_14();
extern void _bsmumstill_entrypoint_0();
extern void _bsmumswim_entrypoint_4();
extern void _bsmumswim_entrypoint_5();
extern void _bsmumswim_entrypoint_6();
extern void _bsmumswim_entrypoint_7();
extern void _bsmumswim_entrypoint_3();
extern void _bsmum_entrypoint_4();
extern void _bsmum_entrypoint_12();
extern void _bsmumattack_entrypoint_0();
extern void _bsstatue_entrypoint_7();
extern void _bsstatue_entrypoint_8();
extern void _bsstatue_entrypoint_9();
extern void _bsstatue_entrypoint_3();
extern void _bsstatue_entrypoint_4();
extern void _bsstatue_entrypoint_6();
extern void _bsstatue_entrypoint_2();
extern void _bsmumsplat_entrypoint_0();
extern void _bskazow_entrypoint_0();
extern void _bskazdie_entrypoint_3();
extern void _bsdie_entrypoint_7();
extern void _bsdie_entrypoint_11();
extern void _bstnt_entrypoint_5();
extern void _bstnt_entrypoint_6();
extern void _bstnt_entrypoint_7();
extern void _bstnt_entrypoint_9();
extern void _bstnt_entrypoint_11();
extern void _bstnt_entrypoint_12();
extern void _bstnt_entrypoint_13();
extern void _bstnt_entrypoint_14();
extern void _bstnt_entrypoint_15();
extern void _bstnt_entrypoint_1();
extern void _bstnt_entrypoint_0();
extern void _bstntswim_entrypoint_1();
extern void _bstntswim_entrypoint_2();
extern void _bstntswim_entrypoint_0();
extern void _bsvan_entrypoint_4();
extern void _bsvan_entrypoint_5();
extern void _bsvan_entrypoint_6();
extern void _bsvan_entrypoint_7();
extern void _bsvan_entrypoint_10();
extern void _bsvan_entrypoint_11();
extern void _bsvan_entrypoint_12();
extern void _bsvan_entrypoint_13();
extern void _bsvan_entrypoint_14();
extern void _bsvanswim_entrypoint_1();
extern void _bsvanswim_entrypoint_2();
extern void _bsvanswim_entrypoint_0();
extern void _bsmumcast_entrypoint_4();
extern void _bscrashout_entrypoint_3();
extern void _bschokedie_entrypoint_3();
extern void _bsvan_entrypoint_16();
extern void _bstaxi_entrypoint_10();
extern void _bstaxi_entrypoint_22();
extern void _bstaxi_entrypoint_31();
extern void _bstaxi_entrypoint_35();
extern void _bstaxi_entrypoint_18();
extern void _bstaxi_entrypoint_26();
extern void _bstaxi_entrypoint_5();
extern void _bstaxi_entrypoint_14();
extern void _bsride_entrypoint_1();
extern void _bsride_entrypoint_3();
extern void _bssub_entrypoint_2();
extern void _bssub_entrypoint_3();
extern void _bssub_entrypoint_0();
extern void _bssub_entrypoint_6();
extern void _bssub_entrypoint_1();
extern void _bssub_entrypoint_7();
extern void _bsbabykaz_entrypoint_2();
extern void _bsbabykaz_entrypoint_7();
extern void _bsbabykaz_entrypoint_8();
extern void _bsbabykaz_entrypoint_10();
extern void _bsbabykaz_entrypoint_11();
extern void _bsbabykaz_entrypoint_9();
extern void _bsbabykaz_entrypoint_6();
extern void _bsfirstp_entrypoint_30();
extern void _bskazow_entrypoint_1();
extern void _bstrexsmall_entrypoint_0();
extern void _bstrexsmall_entrypoint_4();
extern void _bstrexsmall_entrypoint_5();
extern void _bstrexsmall_entrypoint_6();
extern void _bstrexsmall_entrypoint_8();
extern void _bstrexsmall_entrypoint_9();
extern void _bstrexsmall_entrypoint_10();
extern void _bstrexsmall_entrypoint_11();
extern void _bstrexsmall_entrypoint_12();
extern void _bstrexsmall_entrypoint_13();
extern void _bstrexsmall_entrypoint_14();
extern void _bstrexsmall_entrypoint_15();
extern void _bstrexlarge_entrypoint_0();
extern void _bstrexlarge_entrypoint_4();
extern void _bstrexlarge_entrypoint_5();
extern void _bstrexlarge_entrypoint_6();
extern void _bstrexlarge_entrypoint_8();
extern void _bstrexlarge_entrypoint_9();
extern void _bstrexlarge_entrypoint_10();
extern void _bstrexlarge_entrypoint_11();
extern void _bstrexlarge_entrypoint_12();
extern void _bstrexlarge_entrypoint_13();
extern void _bstrexlarge_entrypoint_14();
extern void _bstrexlarge_entrypoint_15();
extern void _bskaztorpedo_entrypoint_0();
extern void _bskaztorpedo_entrypoint_1();
extern void _bskaztorpedo_entrypoint_2();
extern void _bskaztorpedo_entrypoint_3();
extern void _bsbswim_entrypoint_12();
extern void _bskaztorpedo_entrypoint_4();
extern void _bskaztorpedo_entrypoint_5();
extern void _bskaztorpedo_entrypoint_6();
extern void _bskazglide_entrypoint_1();
extern void _bskazglide_entrypoint_2();
extern void _bskazpaddle_entrypoint_2();
extern void _bskazpaddle_entrypoint_1();
extern void _bskazpaddle_entrypoint_3();
extern void _bskazpaddle_entrypoint_0();
extern void _bskazfly_entrypoint_0();
extern void _bskazfly_entrypoint_1();
extern void _bsbansack_entrypoint_1();
extern void _bsbansack_entrypoint_2();
extern void _bsbansack_entrypoint_9();
extern void _bsbansack_entrypoint_8();
extern void _bsbansack_entrypoint_0();
extern void _bskaztorpedo_entrypoint_7();
extern void _bsbansack_entrypoint_3();
extern void _bsbanshack_entrypoint_0();
extern void _bsbanshack_entrypoint_1();
extern void _bsbanshack_entrypoint_6();
extern void _bsbanshack_entrypoint_3();
extern void _bsbanshack_entrypoint_2();
extern void _bsbansnooze_entrypoint_5();
extern void _bsbansnooze_entrypoint_2();
extern void _bsbansnooze_entrypoint_0();
extern void _bsbansnooze_entrypoint_1();
extern void _bskazfly_entrypoint_7();
extern void _bskazfly_entrypoint_2();
extern void _bskazfly_entrypoint_3();
extern void _bskazfly_entrypoint_4();
extern void _bskazfly_entrypoint_5();
extern void _bskazfly_entrypoint_8();
extern void _bskazfly_entrypoint_6();
extern void _bskazfly_entrypoint_9();
extern void _bsbtrot_entrypoint_55();
extern void _bsbtrot_entrypoint_51();
extern void _bssnowball_entrypoint_11();
extern void _bssnowball_entrypoint_7();
extern void _bssnowball_entrypoint_6();
extern void _bssnowball_entrypoint_5();
extern void _bssnowball_entrypoint_8();
extern void _bssnowball_entrypoint_3();
extern void _bssnowball_entrypoint_4();
extern void _bssnowball_entrypoint_9();
extern void _bssnowball_entrypoint_10();
extern void _bskazshoesspringjump_entrypoint_3();
extern void _bskazshoessuckspline_entrypoint_8();
extern void _bskazshoessuckspline_entrypoint_4();
extern void _bsbreegullbash_entrypoint_3();
extern void _bsbkflamethrower_entrypoint_4();
extern void _bskazflamethrower_entrypoint_4();
extern void _bsbeefly_entrypoint_4();
extern void _bskazglide_entrypoint_3();
extern void _bskazglide_entrypoint_4();
extern void _bsledge_entrypoint_8();
u32 D_80117F30[1] = {0x0};
s32 D_80117F34[1] = {0x0};
u32 D_80117F38[1202] = {0x0,
                        0x10000,
                        0x500000,
                        (u32) _bsstand_entrypoint_3,
                        0x20000,
                        0x500000,
                        (u32) _bswalk_entrypoint_9,
                        0x30000,
                        0x500000,
                        (u32) _bswalk_entrypoint_13,
                        0x40000,
                        0x500000,
                        (u32) _bswalk_entrypoint_17,
                        0x50000,
                        0x500000,
                        (u32) _bsjump_entrypoint_3,
                        0x60000,
                        0x500000,
                        (u32) _bsclaw_entrypoint_3,
                        0x70000,
                        0x508000,
                        (u32) _bscrouch_entrypoint_3,
                        0x80000,
                        0x5000C0,
                        (u32) _bsbtrot_entrypoint_15,
                        0x90000,
                        0x180000,
                        (u32) _bsbegghead_entrypoint_3,
                        0xA0000,
                        0x180000,
                        (u32) _bsbeggass_entrypoint_3,
                        0xB0000,
                        0x0,
                        0x0,
                        0xC0000,
                        0x500000,
                        (u32) _bsturn_entrypoint_3,
                        0xD0000,
                        0x500000,
                        (u32) _bstimeout_entrypoint_7,
                        0xE0000,
                        0x402000,
                        (u32) _bsow_entrypoint_3,
                        0xF0000,
                        0x500000,
                        (u32) _bsbbuster_entrypoint_0,
                        0x100000,
                        0x500000,
                        (u32) _bsbflap_entrypoint_3,
                        0x110000,
                        0x500000,
                        (u32) _bsbpeck_entrypoint_3,
                        0x120000,
                        0x500000,
                        (u32) _bsbflip_entrypoint_3,
                        0x130000,
                        0x500000,
                        (u32) _bsbbarge_entrypoint_0,
                        0x140000,
                        0x500040,
                        (u32) _bsbtrot_entrypoint_3,
                        0x150000,
                        0x5000C0,
                        (u32) _bsbtrot_entrypoint_7,
                        0x160000,
                        0x5000C0,
                        (u32) _bsbtrot_entrypoint_11,
                        0x170000,
                        0x5000C0,
                        (u32) _bsbtrot_entrypoint_19,
                        0x180009,
                        0x0,
                        (u32) _bsbfly_entrypoint_7,
                        0x19000B,
                        0x100002,
                        (u32) _bsbswim_entrypoint_2,
                        0x1A0000,
                        0x500000,
                        (u32) _bsbwhirl_entrypoint_3,
                        0x1B0000,
                        0x500000,
                        (u32) _bsbwhirl_entrypoint_7,
                        0x1C0000,
                        0x500000,
                        (u32) _bsbwhirl_entrypoint_11,
                        0x1D0000,
                        0x500000,
                        (u32) _bsbwhirl_entrypoint_15,
                        0x1E0000,
                        0x500000,
                        (u32) _bsbwhirl_entrypoint_19,
                        0x1F0000,
                        0x501000,
                        (u32) _bswalk_entrypoint_5,
                        0x200000,
                        0x500000,
                        (u32) _bsstand_entrypoint_7,
                        0x210000,
                        0x100000,
                        (u32) _bsbshock_entrypoint_3,
                        0x220000,
                        0x100000,
                        (u32) _bsbshock_entrypoint_7,
                        0x230000,
                        0x0,
                        (u32) _bsbfly_entrypoint_0,
                        0x240009,
                        0x0,
                        (u32) _bsbfly_entrypoint_1,
                        0x250008,
                        0x0,
                        (u32) _bsblongleg_entrypoint_3,
                        0x260008,
                        0x0,
                        (u32) _bsblongleg_entrypoint_7,
                        0x270008,
                        0x0,
                        (u32) _bsblongleg_entrypoint_11,
                        0x280008,
                        0x0,
                        (u32) _bsblongleg_entrypoint_19,
                        0x290008,
                        0x0,
                        (u32) _bsblongleg_entrypoint_15,
                        0x2A0009,
                        0x0,
                        (u32) _bsbfly_entrypoint_2,
                        0x2B000B,
                        0x100002,
                        (u32) _bsbswim_entrypoint_0,
                        0x2C000B,
                        0x100002,
                        (u32) _bsbswim_entrypoint_1,
                        0x2D0000,
                        0x100001,
                        (u32) _bsswim_entrypoint_0,
                        0x2E0000,
                        0x100001,
                        (u32) _bsswim_entrypoint_1,
                        0x2F0000,
                        0x500000,
                        (u32) _bsjump_entrypoint_7,
                        0x30000B,
                        0x100002,
                        (u32) _bsbswim_entrypoint_7,
                        0x310000,
                        0x500000,
                        (u32) _bstwirl_entrypoint_0,
                        0x320015,
                        0x0,
                        (u32) _bswasher_entrypoint_9,
                        0x330015,
                        0x0,
                        (u32) _bswasher_entrypoint_5,
                        0x340000,
                        0x0,
                        (u32) _bsjig_entrypoint_11,
                        0x350015,
                        0x0,
                        (u32) _bswasher_entrypoint_4,
                        0x360015,
                        0x0,
                        (u32) _bswasher_entrypoint_3,
                        0x370015,
                        0x0,
                        (u32) _bswasher_entrypoint_10,
                        0x380015,
                        0x0,
                        (u32) _bswasher_entrypoint_11,
                        0x39000B,
                        0x100002,
                        (u32) _bsbswim_entrypoint_3,
                        0x3A0000,
                        0x100400,
                        (u32) _bscarry_entrypoint_1,
                        0x3B0000,
                        0x100400,
                        (u32) _bscarry_entrypoint_2,
                        0x3C0000,
                        0x0,
                        (u32) _bstalk_entrypoint_3,
                        0x3D0000,
                        0x0,
                        (u32) _bsjump_entrypoint_20,
                        0x3E0015,
                        0x2000,
                        (u32) _bswasher_entrypoint_6,
                        0x3F0000,
                        0x0,
                        (u32) _bsjump_entrypoint_15,
                        0x400000,
                        0x408,
                        (u32) _bscarry_entrypoint_3,
                        0x410000,
                        0x4,
                        (u32) _bsdie_entrypoint_3,
                        0x420000,
                        0x0,
                        (u32) _bssilowait_entrypoint_0,
                        0x430015,
                        0x4,
                        (u32) _bswasher_entrypoint_1,
                        0x440000,
                        0x0,
                        (u32) _bsjig_entrypoint_6,
                        0x450000,
                        0x1000C0,
                        (u32) _bsbtrot_entrypoint_23,
                        0x46000F,
                        0x2,
                        (u32) _bssub_entrypoint_5,
                        0x470008,
                        0x0,
                        (u32) _bskazstilt_entrypoint_3,
                        0x480008,
                        0x0,
                        (u32) _bskazstilt_entrypoint_7,
                        0x490008,
                        0x0,
                        (u32) _bskazstilt_entrypoint_11,
                        0x4A0008,
                        0x0,
                        (u32) _bskazstilt_entrypoint_19,
                        0x4B0008,
                        0x0,
                        (u32) _bskazstilt_entrypoint_15,
                        0x4C0000,
                        0x140002,
                        (u32) _bsbswim_entrypoint_10,
                        0x4D0008,
                        0x0,
                        (u32) _bskazstilt_entrypoint_23,
                        0x4E0008,
                        0x0,
                        (u32) _bskazstilt_entrypoint_27,
                        0x4F000A,
                        0x0,
                        (u32) _bsclimb_entrypoint_3,
                        0x50000A,
                        0x0,
                        (u32) _bsclimb_entrypoint_7,
                        0x510000,
                        0x0,
                        (u32) _bsjump_entrypoint_11,
                        0x520000,
                        0x0,
                        0x0,
                        0x530000,
                        0x0,
                        (u32) _bstimeout_entrypoint_3,
                        0x54000B,
                        0x2,
                        (u32) _bsbswim_entrypoint_8,
                        0x550008,
                        0x0,
                        (u32) _bsblongleg_entrypoint_23,
                        0x560000,
                        0x0,
                        (u32) _bsrebound_entrypoint_0,
                        0x570009,
                        0x0,
                        (u32) _bsbfly_entrypoint_3,
                        0x580000,
                        0x0,
                        (u32) _bsbfly_entrypoint_4,
                        0x590009,
                        0x2000,
                        (u32) _bsbfly_entrypoint_5,
                        0x5A0000,
                        0x0,
                        0x0,
                        0x5B0000,
                        0x0,
                        (u32) _bsthrow_entrypoint_3,
                        0x5C0008,
                        0x8,
                        (u32) _bskazstilt_entrypoint_31,
                        0x5D0015,
                        0x8,
                        (u32) _bswasher_entrypoint_2,
                        0x5E0013,
                        0x8,
                        (u32) _bsbanshack_entrypoint_4,
                        0x5F0013,
                        0x10,
                        (u32) _bsbanshack_entrypoint_5,
                        0x600014,
                        0x8,
                        (u32) _bsbansnooze_entrypoint_3,
                        0x610014,
                        0x10,
                        (u32) _bsbansnooze_entrypoint_4,
                        0x620008,
                        0x10,
                        (u32) _bsblongleg_entrypoint_27,
                        0x63000C,
                        0x8,
                        (u32) _bstntswim_entrypoint_4,
                        0x64000C,
                        0x10,
                        (u32) _bstntswim_entrypoint_3,
                        0x650000,
                        0x100001,
                        (u32) _bskazpaddle_entrypoint_4,
                        0x660000,
                        0x100009,
                        (u32) _bskazpaddle_entrypoint_5,
                        0x670000,
                        0x180000,
                        (u32) _bskazegghead_entrypoint_3,
                        0x680000,
                        0x180000,
                        (u32) _bskazeggass_entrypoint_3,
                        0x690000,
                        0x0,
                        (u32) _bssplitup_entrypoint_19,
                        0x6A0000,
                        0x0,
                        (u32) _bssplitup_entrypoint_15,
                        0x6B0001,
                        0x10,
                        (u32) _bsbeemain_entrypoint_10,
                        0x6C0000,
                        0x500000,
                        (u32) _bsbanbflip_entrypoint_3,
                        0x6D000B,
                        0x100002,
                        (u32) _bsbanswim_entrypoint_0,
                        0x6E0012,
                        0x8,
                        (u32) _bsbansack_entrypoint_6,
                        0x6F000E,
                        0x8000,
                        (u32) _bstaxi_entrypoint_6,
                        0x700007,
                        0x10,
                        (u32) _bsstatue_entrypoint_5,
                        0x710000,
                        0xC0,
                        (u32) _bsbtrot_entrypoint_27,
                        0x720000,
                        0x0,
                        (u32) _bssplat_entrypoint_1,
                        0x730000,
                        0x10,
                        (u32) _bsrest_entrypoint_4,
                        0x740000,
                        0x10,
                        (u32) _bsrest_entrypoint_12,
                        0x750000,
                        0x10,
                        (u32) _bsrest_entrypoint_8,
                        0x760009,
                        0x10,
                        (u32) _bsbfly_entrypoint_8,
                        0x770000,
                        0x100011,
                        (u32) _bsswim_entrypoint_2,
                        0x78000B,
                        0x100012,
                        (u32) _bsbswim_entrypoint_9,
                        0x790000,
                        0xD0,
                        (u32) _bsbtrot_entrypoint_31,
                        0x7A0000,
                        0x100000,
                        (u32) _bswalk_entrypoint_21,
                        0x7B0000,
                        0x20C0,
                        (u32) _bsbtrot_entrypoint_35,
                        0x7C0000,
                        0x2000,
                        (u32) _bsride_entrypoint_0,
                        0x7D0012,
                        0x2000,
                        (u32) _bsbansack_entrypoint_4,
                        0x7E0012,
                        0x0,
                        (u32) _bsbansack_entrypoint_5,
                        0x7F000B,
                        0x2002,
                        (u32) _bsbswim_entrypoint_4,
                        0x800012,
                        0x10,
                        (u32) _bsbansack_entrypoint_7,
                        0x81000B,
                        0x100002,
                        (u32) _bsbanswim_entrypoint_1,
                        0x82000B,
                        0x100002,
                        (u32) _bsbanswim_entrypoint_2,
                        0x83000F,
                        0x100002,
                        (u32) _bssub_entrypoint_4,
                        0x84000B,
                        0x108002,
                        (u32) _bsbswim_entrypoint_14,
                        0x850001,
                        0x0,
                        (u32) _bsbeemain_entrypoint_0,
                        0x860001,
                        0x0,
                        (u32) _bsbeemain_entrypoint_1,
                        0x870001,
                        0x0,
                        (u32) _bsbeemain_entrypoint_2,
                        0x880001,
                        0x0,
                        (u32) _bsbeemain_entrypoint_3,
                        0x890001,
                        0x2000,
                        (u32) _bsbeemain_entrypoint_7,
                        0x8A0001,
                        0x4,
                        (u32) _bsbeemain_entrypoint_9,
                        0x8B0001,
                        0x0,
                        (u32) _bsbeefly_entrypoint_0,
                        0x8C0001,
                        0x4000,
                        (u32) _bsbeefly_entrypoint_1,
                        0x8D0001,
                        0x4010,
                        (u32) _bsbeefly_entrypoint_2,
                        0x8E0015,
                        0x0,
                        (u32) _bswasher_entrypoint_7,
                        0x8F0000,
                        0x90,
                        (u32) _bskazstill_entrypoint_10,
                        0x90000B,
                        0x100002,
                        (u32) _bsbanswim_entrypoint_3,
                        0x910009,
                        0x2000,
                        (u32) _bsbfly_entrypoint_6,
                        0x920015,
                        0x10,
                        (u32) _bswasher_entrypoint_8,
                        0x930000,
                        0x100088,
                        (u32) _bskazstill_entrypoint_9,
                        0x940000,
                        0x2020,
                        (u32) _bsbabykaz_entrypoint_12,
                        0x950000,
                        0x1000C0,
                        (u32) _bsbtrot_entrypoint_47,
                        0x960000,
                        0x100009,
                        (u32) _bsswim_entrypoint_3,
                        0x97000B,
                        0x10000A,
                        (u32) _bsbswim_entrypoint_11,
                        0x980000,
                        0x100008,
                        (u32) _bsstand_entrypoint_12,
                        0x990009,
                        0x8,
                        (u32) _bsbfly_entrypoint_9,
                        0x9A0000,
                        0xC8,
                        (u32) _bsbtrot_entrypoint_39,
                        0x9B0008,
                        0x8,
                        (u32) _bsblongleg_entrypoint_31,
                        0x9C0000,
                        0x1000C0,
                        (u32) _bsbtrot_entrypoint_43,
                        0x9D0001,
                        0x8,
                        (u32) _bsbeemain_entrypoint_11,
                        0x9E000A,
                        0x10,
                        (u32) _bsclimb_entrypoint_11,
                        0x9F0000,
                        0x1400,
                        (u32) _bscarry_entrypoint_0,
                        0xA00000,
                        0x400,
                        (u32) _bscarry_entrypoint_4,
                        0xA10005,
                        0x20020,
                        (u32) _bsfirstp_entrypoint_31,
                        0xA2000B,
                        0x2,
                        (u32) _bsbswim_entrypoint_6,
                        0xA30001,
                        0x0,
                        (u32) _bsbeemain_entrypoint_8,
                        0xA40000,
                        0x8,
                        (u32) _bsbwhirl_entrypoint_23,
                        0xA50000,
                        0x10,
                        (u32) _bsbwhirl_entrypoint_27,
                        0xA60002,
                        0x0,
                        (u32) _bsledge_entrypoint_4,
                        0xA70002,
                        0x0,
                        (u32) _bsledge_entrypoint_3,
                        0xA80002,
                        0x0,
                        (u32) _bsledge_entrypoint_2,
                        0xA90002,
                        0x0,
                        (u32) _bsledge_entrypoint_0,
                        0xAA0002,
                        0x0,
                        (u32) _bsledge_entrypoint_1,
                        0xAB0003,
                        0x4,
                        (u32) _bsstonehead_entrypoint_7,
                        0xAC0003,
                        0x100008,
                        (u32) _bsstonehead_entrypoint_11,
                        0xAD0003,
                        0x100000,
                        (u32) _bsstonehead_entrypoint_15,
                        0xAE0003,
                        0x100000,
                        (u32) _bsstonehead_entrypoint_19,
                        0xAF0003,
                        0x2000,
                        (u32) _bsstonehead_entrypoint_27,
                        0xB00003,
                        0x0,
                        (u32) _bsstonehead_entrypoint_31,
                        0xB10003,
                        0x10,
                        (u32) _bsstonehead_entrypoint_35,
                        0xB20003,
                        0x100000,
                        (u32) _bsstonehead_entrypoint_23,
                        0xB30003,
                        0x100000,
                        (u32) _bsstonehead_entrypoint_43,
                        0xB40003,
                        0x100000,
                        (u32) _bsstonehead_entrypoint_3,
                        0xB50003,
                        0x100000,
                        (u32) _bsstonehead_entrypoint_39,
                        0xB60000,
                        0x100000,
                        (u32) _bsbbilldrill_entrypoint_3,
                        0xB70000,
                        0x0,
                        (u32) _bsride_entrypoint_2,
                        0xB80000,
                        0x0,
                        (u32) _bssplitup_entrypoint_11,
                        0xB90000,
                        0x0,
                        (u32) _bssplitup_entrypoint_3,
                        0xBA0000,
                        0x0,
                        (u32) _bssplitup_entrypoint_7,
                        0xBB0000,
                        0x500080,
                        (u32) _bskazstill_entrypoint_3,
                        0xBC0000,
                        0x500080,
                        (u32) _bskazmove_entrypoint_4,
                        0xBD0000,
                        0x500080,
                        (u32) _bskazjump_entrypoint_3,
                        0xBE0000,
                        0x400200,
                        (u32) _bskazglide_entrypoint_0,
                        0xBF000B,
                        0x2,
                        (u32) _bsbswim_entrypoint_5,
                        0xC00001,
                        0x4000,
                        (u32) _bsbeefly_entrypoint_3,
                        0xC10000,
                        0x100000,
                        (u32) _bskazshock_entrypoint_8,
                        0xC20000,
                        0x500000,
                        (u32) _bskazwingwhack_entrypoint_1,
                        0xC30000,
                        0x100000,
                        (u32) _bskazshock_entrypoint_4,
                        0xC40000,
                        0x100000,
                        (u32) _bskazwingwhack_entrypoint_0,
                        0xC50000,
                        0x8000,
                        (u32) _bskazhatch_entrypoint_0,
                        0xC60000,
                        0x500000,
                        (u32) _bskazspring_entrypoint_0,
                        0xC70000,
                        0x500080,
                        (u32) _bskazmove_entrypoint_10,
                        0xC80005,
                        0x0,
                        (u32) _bsfirstp_entrypoint_19,
                        0xC90005,
                        0x0,
                        (u32) _bsfirstp_entrypoint_22,
                        0xCA0005,
                        0x10000,
                        (u32) _bsfirstp_entrypoint_35,
                        0xCB0005,
                        0x0,
                        (u32) _bsfirstp_entrypoint_20,
                        0xCC0005,
                        0x0,
                        (u32) _bsfirstp_entrypoint_21,
                        0xCD0005,
                        0x8,
                        (u32) _bsfirstp_entrypoint_23,
                        0xCE0005,
                        0x8,
                        (u32) _bsfirstp_entrypoint_24,
                        0xCF0005,
                        0x0,
                        (u32) _bsfirstp_entrypoint_32,
                        0xD00005,
                        0x0,
                        (u32) _bsfirstp_entrypoint_33,
                        0xD10005,
                        0x10000,
                        (u32) _bsfirstp_entrypoint_36,
                        0xD20005,
                        0x0,
                        (u32) _bsfirstp_entrypoint_34,
                        0xD30000,
                        0x0,
                        0x0,
                        0xD40000,
                        0x0,
                        0x0,
                        0xD50000,
                        0x0,
                        0x0,
                        0xD60005,
                        0x10000,
                        (u32) _bsfirstp_entrypoint_8,
                        0xD70005,
                        0x20000,
                        (u32) _bsfirstp_entrypoint_29,
                        0xD80005,
                        0x10000,
                        (u32) _bsfirstp_entrypoint_9,
                        0xD90005,
                        0x0,
                        (u32) _bsfirstp_entrypoint_11,
                        0xDA0005,
                        0x0,
                        (u32) _bsfirstp_entrypoint_15,
                        0xDB0005,
                        0x4,
                        (u32) _bsfirstp_entrypoint_16,
                        0xDC0005,
                        0x4,
                        (u32) _bsfirstp_entrypoint_17,
                        0xDD0000,
                        0x508000,
                        (u32) _bskazcrouch_entrypoint_4,
                        0xDE0000,
                        0x500080,
                        (u32) _bskazstill_entrypoint_8,
                        0xDF0000,
                        0x80,
                        (u32) _bskazjump_entrypoint_7,
                        0xE00000,
                        0x0,
                        (u32) _bskazjump_entrypoint_15,
                        0xE10000,
                        0x0,
                        (u32) _bskazjump_entrypoint_11,
                        0xE20000,
                        0x0,
                        0x0,
                        0xE30000,
                        0x0,
                        0x0,
                        0xE40000,
                        0x0,
                        (u32) _bsbanpackwhack_entrypoint_3,
                        0xE50006,
                        0x500000,
                        (u32) _bsmumstill_entrypoint_1,
                        0xE60006,
                        0x500000,
                        (u32) _bsmummove_entrypoint_4,
                        0xE70006,
                        0x500000,
                        (u32) _bsmummove_entrypoint_3,
                        0xE80006,
                        0x500000,
                        (u32) _bsmum_entrypoint_6,
                        0xE90006,
                        0x500000,
                        (u32) _bsmum_entrypoint_5,
                        0xEA0006,
                        0x402000,
                        (u32) _bsmum_entrypoint_7,
                        0xEB0006,
                        0x4,
                        (u32) _bsmum_entrypoint_3,
                        0xEC0006,
                        0x400000,
                        (u32) _bsmum_entrypoint_11,
                        0xED000B,
                        0x8102,
                        (u32) _bsbswim_entrypoint_13,
                        0xEE0006,
                        0x0,
                        (u32) _bsmum_entrypoint_14,
                        0xEF0006,
                        0x500000,
                        (u32) _bsmumstill_entrypoint_0,
                        0xF00006,
                        0x100001,
                        (u32) _bsmumswim_entrypoint_4,
                        0xF10006,
                        0x100001,
                        (u32) _bsmumswim_entrypoint_5,
                        0xF20006,
                        0x100011,
                        (u32) _bsmumswim_entrypoint_6,
                        0xF30006,
                        0x100009,
                        (u32) _bsmumswim_entrypoint_7,
                        0xF40006,
                        0x140002,
                        (u32) _bsmumswim_entrypoint_3,
                        0xF50006,
                        0x100008,
                        (u32) _bsmum_entrypoint_4,
                        0xF60006,
                        0x10,
                        (u32) _bsmum_entrypoint_12,
                        0xF70006,
                        0x500000,
                        (u32) _bsmumattack_entrypoint_0,
                        0xF80007,
                        0x0,
                        (u32) _bsstatue_entrypoint_7,
                        0xF90007,
                        0x0,
                        (u32) _bsstatue_entrypoint_8,
                        0xFA0007,
                        0x0,
                        (u32) _bsstatue_entrypoint_9,
                        0xFB0007,
                        0x0,
                        (u32) _bsstatue_entrypoint_3,
                        0xFC0007,
                        0x0,
                        (u32) _bsstatue_entrypoint_4,
                        0xFD0007,
                        0x0,
                        (u32) _bsstatue_entrypoint_6,
                        0xFE0007,
                        0x8,
                        (u32) _bsstatue_entrypoint_2,
                        0xFF0006,
                        0x0,
                        (u32) _bsmumsplat_entrypoint_0,
                        0x1000000,
                        0x2080,
                        (u32) _bskazow_entrypoint_0,
                        0x1010000,
                        0x4,
                        (u32) _bskazdie_entrypoint_3,
                        0x1020000,
                        0x4,
                        (u32) _bsdie_entrypoint_7,
                        0x1030000,
                        0x4,
                        (u32) _bsdie_entrypoint_11,
                        0x104000C,
                        0x4,
                        (u32) _bstnt_entrypoint_5,
                        0x105000C,
                        0x8,
                        (u32) _bstnt_entrypoint_6,
                        0x106000C,
                        0x0,
                        (u32) _bstnt_entrypoint_7,
                        0x107000C,
                        0x0,
                        (u32) _bstnt_entrypoint_9,
                        0x108000C,
                        0x0,
                        (u32) _bstnt_entrypoint_11,
                        0x109000C,
                        0x2000,
                        (u32) _bstnt_entrypoint_12,
                        0x10A000C,
                        0x0,
                        (u32) _bstnt_entrypoint_13,
                        0x10B000C,
                        0x10,
                        (u32) _bstnt_entrypoint_14,
                        0x10C000C,
                        0x0,
                        (u32) _bstnt_entrypoint_15,
                        0x10D000C,
                        0x0,
                        (u32) _bstnt_entrypoint_1,
                        0x10E000C,
                        0x0,
                        (u32) _bstnt_entrypoint_0,
                        0x10F000C,
                        0x100001,
                        (u32) _bstntswim_entrypoint_1,
                        0x110000C,
                        0x100001,
                        (u32) _bstntswim_entrypoint_2,
                        0x111000C,
                        0x140002,
                        (u32) _bstntswim_entrypoint_0,
                        0x112000D,
                        0x4,
                        (u32) _bsvan_entrypoint_4,
                        0x113000D,
                        0x8,
                        (u32) _bsvan_entrypoint_5,
                        0x114000D,
                        0x0,
                        (u32) _bsvan_entrypoint_6,
                        0x115000D,
                        0x0,
                        (u32) _bsvan_entrypoint_7,
                        0x116000D,
                        0x0,
                        (u32) _bsvan_entrypoint_10,
                        0x117000D,
                        0x2000,
                        (u32) _bsvan_entrypoint_11,
                        0x118000D,
                        0x0,
                        (u32) _bsvan_entrypoint_12,
                        0x119000D,
                        0x10,
                        (u32) _bsvan_entrypoint_13,
                        0x11A000D,
                        0x0,
                        (u32) _bsvan_entrypoint_14,
                        0x11B000D,
                        0x1,
                        (u32) _bsvanswim_entrypoint_1,
                        0x11C000D,
                        0x1,
                        (u32) _bsvanswim_entrypoint_2,
                        0x11D000D,
                        0x40002,
                        (u32) _bsvanswim_entrypoint_0,
                        0x11E0006,
                        0x0,
                        (u32) _bsmumcast_entrypoint_4,
                        0x11F0000,
                        0x0,
                        (u32) _bscrashout_entrypoint_3,
                        0x1200000,
                        0x4,
                        (u32) _bschokedie_entrypoint_3,
                        0x121000D,
                        0x0,
                        (u32) _bsvan_entrypoint_16,
                        0x122000E,
                        0x108000,
                        (u32) _bstaxi_entrypoint_10,
                        0x123000E,
                        0x108000,
                        (u32) _bstaxi_entrypoint_22,
                        0x124000E,
                        0x108000,
                        (u32) _bstaxi_entrypoint_31,
                        0x125000E,
                        0x108000,
                        (u32) _bstaxi_entrypoint_35,
                        0x126000E,
                        0x108000,
                        (u32) _bstaxi_entrypoint_18,
                        0x127000E,
                        0x108000,
                        (u32) _bstaxi_entrypoint_26,
                        0x128000E,
                        0x108000,
                        (u32) _bstaxi_entrypoint_5,
                        0x129000E,
                        0x108000,
                        (u32) _bstaxi_entrypoint_14,
                        0x12A0000,
                        0x2000,
                        (u32) _bsride_entrypoint_1,
                        0x12B0000,
                        0x2000,
                        (u32) _bsride_entrypoint_3,
                        0x12C000F,
                        0x2,
                        (u32) _bssub_entrypoint_2,
                        0x12D000F,
                        0x2002,
                        (u32) _bssub_entrypoint_3,
                        0x12E000F,
                        0x6,
                        (u32) _bssub_entrypoint_0,
                        0x12F000F,
                        0x12,
                        (u32) _bssub_entrypoint_6,
                        0x130000F,
                        0xA,
                        (u32) _bssub_entrypoint_1,
                        0x131000F,
                        0x2,
                        (u32) _bssub_entrypoint_7,
                        0x1320000,
                        0x20,
                        (u32) _bsbabykaz_entrypoint_2,
                        0x1330000,
                        0x20,
                        (u32) _bsbabykaz_entrypoint_7,
                        0x1340000,
                        0x20,
                        (u32) _bsbabykaz_entrypoint_8,
                        0x1350000,
                        0x20,
                        (u32) _bsbabykaz_entrypoint_10,
                        0x1360000,
                        0x20,
                        (u32) _bsbabykaz_entrypoint_11,
                        0x1370000,
                        0x30,
                        (u32) _bsbabykaz_entrypoint_9,
                        0x1380000,
                        0x28,
                        (u32) _bsbabykaz_entrypoint_6,
                        0x1390005,
                        0x20020,
                        (u32) _bsfirstp_entrypoint_30,
                        0x13A0000,
                        0x0,
                        (u32) _bskazow_entrypoint_1,
                        0x13B0010,
                        0x0,
                        (u32) _bstrexsmall_entrypoint_0,
                        0x13C0010,
                        0x4,
                        (u32) _bstrexsmall_entrypoint_4,
                        0x13D0010,
                        0x8,
                        (u32) _bstrexsmall_entrypoint_5,
                        0x13E0010,
                        0x0,
                        (u32) _bstrexsmall_entrypoint_6,
                        0x13F0010,
                        0x0,
                        (u32) _bstrexsmall_entrypoint_8,
                        0x1400010,
                        0x2000,
                        (u32) _bstrexsmall_entrypoint_9,
                        0x1410010,
                        0x0,
                        (u32) _bstrexsmall_entrypoint_10,
                        0x1420010,
                        0x10,
                        (u32) _bstrexsmall_entrypoint_11,
                        0x1430010,
                        0x200000,
                        (u32) _bstrexsmall_entrypoint_12,
                        0x1440010,
                        0x0,
                        (u32) _bstrexsmall_entrypoint_13,
                        0x1450010,
                        0x0,
                        (u32) _bstrexsmall_entrypoint_14,
                        0x1460010,
                        0x0,
                        (u32) _bstrexsmall_entrypoint_15,
                        0x1470011,
                        0x0,
                        (u32) _bstrexlarge_entrypoint_0,
                        0x1480011,
                        0x4,
                        (u32) _bstrexlarge_entrypoint_4,
                        0x1490011,
                        0x8,
                        (u32) _bstrexlarge_entrypoint_5,
                        0x14A0011,
                        0x0,
                        (u32) _bstrexlarge_entrypoint_6,
                        0x14B0011,
                        0x0,
                        (u32) _bstrexlarge_entrypoint_8,
                        0x14C0011,
                        0x2000,
                        (u32) _bstrexlarge_entrypoint_9,
                        0x14D0011,
                        0x0,
                        (u32) _bstrexlarge_entrypoint_10,
                        0x14E0011,
                        0x10,
                        (u32) _bstrexlarge_entrypoint_11,
                        0x14F0011,
                        0x200000,
                        (u32) _bstrexlarge_entrypoint_12,
                        0x1500011,
                        0x0,
                        (u32) _bstrexlarge_entrypoint_13,
                        0x1510011,
                        0x0,
                        (u32) _bstrexlarge_entrypoint_14,
                        0x1520011,
                        0x0,
                        (u32) _bstrexlarge_entrypoint_15,
                        0x1530000,
                        0x8102,
                        (u32) _bskaztorpedo_entrypoint_0,
                        0x1540000,
                        0x8102,
                        (u32) _bskaztorpedo_entrypoint_1,
                        0x1550000,
                        0x8112,
                        (u32) _bskaztorpedo_entrypoint_2,
                        0x1560000,
                        0x810A,
                        (u32) _bskaztorpedo_entrypoint_3,
                        0x157000B,
                        0x8102,
                        (u32) _bsbswim_entrypoint_12,
                        0x1580000,
                        0x8102,
                        (u32) _bskaztorpedo_entrypoint_4,
                        0x1590000,
                        0x8102,
                        (u32) _bskaztorpedo_entrypoint_5,
                        0x15A0000,
                        0xA102,
                        (u32) _bskaztorpedo_entrypoint_6,
                        0x15B0000,
                        0x2200,
                        (u32) _bskazglide_entrypoint_1,
                        0x15C0000,
                        0x0,
                        (u32) _bskazglide_entrypoint_2,
                        0x15D0000,
                        0x100001,
                        (u32) _bskazpaddle_entrypoint_2,
                        0x15E0000,
                        0x100001,
                        (u32) _bskazpaddle_entrypoint_1,
                        0x15F0000,
                        0x100001,
                        (u32) _bskazpaddle_entrypoint_3,
                        0x1600000,
                        0x140002,
                        (u32) _bskazpaddle_entrypoint_0,
                        0x1610000,
                        0x0,
                        (u32) _bskazfly_entrypoint_0,
                        0x1620009,
                        0x0,
                        (u32) _bskazfly_entrypoint_1,
                        0x1630012,
                        0x0,
                        (u32) _bsbansack_entrypoint_1,
                        0x1640012,
                        0x0,
                        (u32) _bsbansack_entrypoint_2,
                        0x1650012,
                        0x0,
                        (u32) _bsbansack_entrypoint_9,
                        0x1660012,
                        0x0,
                        (u32) _bsbansack_entrypoint_8,
                        0x1670012,
                        0x1,
                        (u32) _bsbansack_entrypoint_0,
                        0x1680000,
                        0x8102,
                        (u32) _bskaztorpedo_entrypoint_7,
                        0x1690012,
                        0x0,
                        (u32) _bsbansack_entrypoint_3,
                        0x16A0013,
                        0x0,
                        (u32) _bsbanshack_entrypoint_0,
                        0x16B0013,
                        0x0,
                        (u32) _bsbanshack_entrypoint_1,
                        0x16C0013,
                        0x0,
                        (u32) _bsbanshack_entrypoint_6,
                        0x16D0013,
                        0x0,
                        (u32) _bsbanshack_entrypoint_3,
                        0x16E0013,
                        0x0,
                        (u32) _bsbanshack_entrypoint_2,
                        0x16F0014,
                        0x0,
                        (u32) _bsbansnooze_entrypoint_5,
                        0x1700014,
                        0x0,
                        (u32) _bsbansnooze_entrypoint_2,
                        0x1710014,
                        0x0,
                        (u32) _bsbansnooze_entrypoint_0,
                        0x1720014,
                        0x0,
                        (u32) _bsbansnooze_entrypoint_1,
                        0x1730009,
                        0x0,
                        (u32) _bskazfly_entrypoint_7,
                        0x1740009,
                        0x0,
                        (u32) _bskazfly_entrypoint_2,
                        0x1750009,
                        0x0,
                        (u32) _bskazfly_entrypoint_3,
                        0x1760000,
                        0x0,
                        (u32) _bskazfly_entrypoint_4,
                        0x1770009,
                        0x2000,
                        (u32) _bskazfly_entrypoint_5,
                        0x1780009,
                        0x10,
                        (u32) _bskazfly_entrypoint_8,
                        0x1790009,
                        0x2000,
                        (u32) _bskazfly_entrypoint_6,
                        0x17A0009,
                        0x8,
                        (u32) _bskazfly_entrypoint_9,
                        0x17B0000,
                        0x8C0,
                        (u32) _bsbtrot_entrypoint_55,
                        0x17C0000,
                        0x8C0,
                        (u32) _bsbtrot_entrypoint_51,
                        0x17D0016,
                        0x0,
                        (u32) _bssnowball_entrypoint_11,
                        0x17E0016,
                        0x0,
                        (u32) _bssnowball_entrypoint_7,
                        0x17F0016,
                        0x0,
                        (u32) _bssnowball_entrypoint_6,
                        0x1800016,
                        0x0,
                        (u32) _bssnowball_entrypoint_5,
                        0x1810016,
                        0x2000,
                        (u32) _bssnowball_entrypoint_8,
                        0x1820016,
                        0x0,
                        (u32) _bssnowball_entrypoint_3,
                        0x1830016,
                        0x8,
                        (u32) _bssnowball_entrypoint_4,
                        0x1840016,
                        0x0,
                        (u32) _bssnowball_entrypoint_9,
                        0x1850016,
                        0x10,
                        (u32) _bssnowball_entrypoint_10,
                        0x1860000,
                        0x80,
                        (u32) _bskazshoesspringjump_entrypoint_3,
                        0x1870000,
                        0x880,
                        (u32) _bskazshoessuckspline_entrypoint_8,
                        0x1880000,
                        0x880,
                        (u32) _bskazshoessuckspline_entrypoint_4,
                        0x1890000,
                        0x100000,
                        (u32) _bsbreegullbash_entrypoint_3,
                        0x18A0000,
                        0x0,
                        (u32) _bsbkflamethrower_entrypoint_4,
                        0x18B0000,
                        0x0,
                        (u32) _bskazflamethrower_entrypoint_4,
                        0x18C0001,
                        0x4000,
                        (u32) _bsbeefly_entrypoint_4,
                        0x18D0000,
                        0x210,
                        (u32) _bskazglide_entrypoint_3,
                        0x18E0000,
                        0x208,
                        (u32) _bskazglide_entrypoint_4,
                        0x18F0002,
                        0x0,
                        (u32) _bsledge_entrypoint_8,
                        0xFFFF0000,
                        0x0,
                        0x0,
                        0x0};
