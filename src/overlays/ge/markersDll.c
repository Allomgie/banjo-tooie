#include "ge/markersDll.h"

extern s32 *D_80800090_gemarkersDll[490];

// Maps a placed marker/prop id (0xB6..0x545) to the ActorInfo getter of its actor kind.
s32 gemarkersDll_entrypoint_0(s32 id)
{
    if ((id < 0xB6) || (id >= 0x546)) {
        return 0;
    }
    return D_80800090_gemarkersDll[id - 0xB6];
}

// Maps an entrance number to the id of its entrance marker (0 if out of range).
s32 gemarkersDll_entrypoint_1(s32 entrance)
{
    s32 marker_id;
    s32 init;

    // Matching: the extra temporary is needed for the match.
    init = 0;
    marker_id = init;
    if (func_800A9C98() != 0) {
        if ((entrance > 0) && (entrance < 9)) {
            marker_id = entrance + 0x7F;
        }
    } else if ((entrance > 0) && (entrance < 0x29)) {
        marker_id = entrance;
    }
    return marker_id;
}

extern void _chjamjarsdummy_entrypoint_0();
extern void _chjadesnake_entrypoint_0();
extern void _chgoldsnakehead_entrypoint_0();
extern void _chgoldsnakehead_entrypoint_1();
extern void _chbilldrillboulder_entrypoint_0();
extern void _chcoderoomdoor_entrypoint_0();
extern void _chwallsnakebaddy_entrypoint_0();
extern void _chwarriorbaddy_entrypoint_0();
extern void _chstonedartgunhead_entrypoint_0();
extern void _chfriendlystonehead_entrypoint_0();
extern void _chamazongoldhordeofficial_entrypoint_0();
extern void _chamazonstadiumguard_entrypoint_0();
extern void _chprisonbits_entrypoint_4();
extern void _chboilerboss_entrypoint_0();
extern void _chtntbox_entrypoint_0();
extern void _chnewshovel_entrypoint_0();
extern void _chwaterfallgrill_entrypoint_1();
extern void _chwaterfallgrillswitch_entrypoint_0();
extern void _chprisonbits_entrypoint_0();
extern void _chprisonbits_entrypoint_1();
extern void _chprisonbits_entrypoint_2();
extern void _chprisonbits_entrypoint_3();
extern void _chstonedartgunhead_entrypoint_1();
extern void _chweldarbossfireball_entrypoint_0();
extern void _chgate1doors_entrypoint_0();
extern void _chgate1doors_entrypoint_1();
extern void _chtemplebrokendoorpiece_entrypoint_0();
extern void _chcrackarchwall_entrypoint_0();
extern void _chlightdemon_entrypoint_0();
extern void _chstonepillar_entrypoint_0();
extern void _chstonepillar_entrypoint_1();
extern void _chdinoswitches_entrypoint_0();
extern void _chdiggerground_entrypoint_0();
extern void _chdiggergroundgen_entrypoint_0();
extern void _chdiggerfly_entrypoint_0();
extern void _chdiggerfly_entrypoint_1();
extern void _chcheato_entrypoint_0();
extern void _chcheatopage_entrypoint_0();
extern void _chgobiwitchy_entrypoint_0();
extern void _chbabydino_entrypoint_0();
extern void _chcactusofstrength_entrypoint_0();
extern void _chcactusofstrength_entrypoint_2();
extern void _chcactusofstrength_entrypoint_1();
extern void _chinflatableboss_entrypoint_0();
extern void _chballoonbomb_entrypoint_0();
extern void _chboxingglove_entrypoint_0();
extern void _chmrsboggy_entrypoint_0();
extern void _chboggyboy_entrypoint_0();
extern void _chboggygirl_entrypoint_0();
extern void _chboggyfatboy_entrypoint_1();
extern void _chmineprospector_entrypoint_0();
extern void _chonearmbandit_entrypoint_0();
extern void _chtntblockage_entrypoint_0();
extern void _chweldarhead_entrypoint_0();
extern void _chkingjinjo_entrypoint_1();
extern void _chcamerawibble_entrypoint_0();
extern void _chtntdetonator_entrypoint_0();
extern void _chtnthut_entrypoint_0();
extern void _chtntminecelldoor_entrypoint_0();
extern void _chcaveofhorrorsdoors_entrypoint_0();
extern void _chbanjoctrl_entrypoint_0();
extern void _chscorepoints_entrypoint_0();
extern void _chmadamegrunty_entrypoint_0();
extern void _chhillbilly_entrypoint_0();
extern void _chmineprospector_entrypoint_1();
extern void _chmineprospector_entrypoint_2();
extern void _chevilspirit_entrypoint_0();
extern void _chstoneballcontrol_entrypoint_2();
extern void _chpodiumbankaz_entrypoint_1();
extern void _chpodiumbankaz_entrypoint_0();
extern void _chswappy_entrypoint_1();
extern void _cheggnormal_entrypoint_0();
extern void _cheggfire_entrypoint_0();
extern void _cheggice_entrypoint_0();
extern void _chegggrenade_entrypoint_1();
extern void _cheggclockwork_entrypoint_0();
extern void _chegggolden_entrypoint_0();
extern void _cheggproximity_entrypoint_0();
extern void _chlaundry_entrypoint_0();
extern void _chgoldstatue_entrypoint_0();
extern void _chwandglow_entrypoint_3();
extern void _chfaircoinbox_entrypoint_2();
extern void _chfaircoin_entrypoint_1();
extern void _chtorpedo_entrypoint_1();
extern void _chping_entrypoint_1();
extern void _chfootwear_entrypoint_3();
extern void _chclimbbase_entrypoint_1();
extern void _chstinger_entrypoint_1();
extern void _chfactoryworkerdirty_entrypoint_0();
extern void _chclockworkmouse_entrypoint_0();
extern void _chstadiumdoors_entrypoint_0();
extern void _chstoneballcoach_entrypoint_0();
extern void _chcredits_entrypoint_2();
extern void _chsounder_entrypoint_0();
extern void _chcanarymarycage_entrypoint_0();
extern void _chfog_entrypoint_0();
extern void _chcrusher_entrypoint_0();
extern void _chcrusher_entrypoint_2();
extern void _chcrusher_entrypoint_1();
extern void _chcrusher_entrypoint_3();
extern void _chcrusherboulder_entrypoint_0();
extern void _chjigsawbitcont_entrypoint_1();
extern void _chjigsawbitcont_entrypoint_0();
extern void _chmole_witchy_entrypoint_0();
extern void _chmole_hailfire_entrypoint_0();
extern void _chmole_factory_entrypoint_0();
extern void _chmole_prehist_entrypoint_0();
extern void _chcheatomenu_entrypoint_0();
extern void _chmoley_entrypoint_2();
extern void _chnewmumbo_entrypoint_1();
extern void _chhoney_entrypoint_1();
extern void _chhoney_entrypoint_2();
extern void _chsignpost_entrypoint_0();
extern void _chbadbeehive_entrypoint_0();
extern void _chmayafarmer_entrypoint_0();
extern void _chbadjinjo_entrypoint_0();
extern void _chsilo_entrypoint_0();
extern void _chcollballcontrol_entrypoint_0();
extern void _chcollballcontrol_entrypoint_5();
extern void _chintrocam_entrypoint_0();
extern void _chcollballcontrol_entrypoint_2();
extern void _chcollballcontrol_entrypoint_4();
extern void _chcollballcontrol_entrypoint_3();
extern void _chcolldoors_entrypoint_0();
extern void _chmusicmenu_entrypoint_0();
extern void _chmole_maya_entrypoint_0();
extern void _chmole_mine_entrypoint_0();
extern void _chmole_training_entrypoint_1();
extern void _chfiregen_entrypoint_0();
extern void _chfiregen_entrypoint_6();
extern void _chfiregen_entrypoint_1();
extern void _chfiregen_entrypoint_7();
extern void _chfiregen_entrypoint_2();
extern void _chfiregen_entrypoint_8();
extern void _chfiregen_entrypoint_3();
extern void _chfiregen_entrypoint_9();
extern void _chfiregen_entrypoint_4();
extern void _chfiregen_entrypoint_10();
extern void _chfiregen_entrypoint_5();
extern void _chfiregen_entrypoint_11();
extern void _chstoneballcontrol_entrypoint_5();
extern void _chstoneballcontrol_entrypoint_0();
extern void _chstoneballcontrol_entrypoint_3();
extern void _chwaterfallfx_entrypoint_0();
extern void _chidgoldhorde_entrypoint_0();
extern void _chfishshootgame_entrypoint_0();
extern void _chfishshootgame_entrypoint_1();
extern void _chlagoonufoext_entrypoint_0();
extern void _chlagoonufoint_entrypoint_1();
extern void _chlagoonufoint_entrypoint_4();
extern void _chlagoonufoint_entrypoint_0();
extern void _chlagoonufoint_entrypoint_2();
extern void _chlagoonufoint_entrypoint_3();
extern void _chnests_entrypoint_0();
extern void _chnests_entrypoint_1();
extern void _chnests_entrypoint_2();
extern void _chnests_entrypoint_3();
extern void _chnests_entrypoint_4();
extern void _chnests_entrypoint_5();
extern void _chnests_entrypoint_7();
extern void _chnests_entrypoint_8();
extern void _chfishshootgame_entrypoint_2();
extern void _chbanjocurrent_entrypoint_0();
extern void _chbanjocurrent_entrypoint_1();
extern void _chnests_entrypoint_9();
extern void _chnests_entrypoint_10();
extern void _chpickups_entrypoint_0();
extern void _chnastycavemen_entrypoint_0();
extern void _chnastycavemen_entrypoint_1();
extern void _chcamwaypoint_entrypoint_0();
extern void _chjiggygamenew_entrypoint_4();
extern void _chjiggygamenew_entrypoint_0();
extern void _chlightdemon_entrypoint_1();
extern void _chmasterjiggy_entrypoint_0();
extern void _chjiggygamenew_entrypoint_3();
extern void _chwaspnestgame_entrypoint_0();
extern void _chwaspnestgame_entrypoint_1();
extern void _chwarppad_entrypoint_0();
extern void _chjiggytemple_entrypoint_0();
extern void _chjiggytemple_entrypoint_1();
extern void _chscreenadjust_entrypoint_0();
extern void _chnests_entrypoint_11();
extern void _chquicksandbaddy_entrypoint_1();
extern void _chcrate_entrypoint_0();
extern void _chjinjo_entrypoint_5();
extern void _chclimbbase_entrypoint_0();
extern void _chsabreman_entrypoint_3();
extern void _chexploder_entrypoint_0();
extern void _chtntbox_entrypoint_1();
extern void _chmumbopadstatue_entrypoint_0();
extern void _chdiggerboss_entrypoint_1();
extern void _chweather_entrypoint_0();
extern void _chweather_entrypoint_1();
extern void _chweather_entrypoint_2();
extern void _chweather_entrypoint_3();
extern void _chweather_entrypoint_4();
extern void _chweather_entrypoint_5();
extern void _chweather_entrypoint_6();
extern void _chweather_entrypoint_7();
extern void _chshockjump_entrypoint_0();
extern void _chbeehive_entrypoint_0();
extern void _chzubba_entrypoint_0();
extern void func_800A7168();
extern void _chquizremotectrl_entrypoint_0();
extern void _chfootwear_entrypoint_0();
extern void _chglowbo_entrypoint_0();
extern void _chjigsaw_entrypoint_0();
extern void _chhoneycarrier_entrypoint_0();
extern void _chboilerboss_entrypoint_1();
extern void _chboilerboss_entrypoint_2();
extern void _chboilerboss_entrypoint_3();
extern void _chhoney_entrypoint_0();
extern void _chjigsawdance_entrypoint_2();
extern void _chfootwear_entrypoint_1();
extern void _chshockjump_entrypoint_1();
extern void _chfactoryworkerwear_entrypoint_0();
extern void _chbadshad_entrypoint_0();
extern void _chlavaslabswitch_entrypoint_0();
extern void _chmolehill_entrypoint_6();
extern void _chmineproplight_entrypoint_0();
extern void _chlavaslab_entrypoint_0();
extern void _chusefeather_entrypoint_2();
extern void _chusefeather_entrypoint_3();
extern void _chlavacolumnswitch_entrypoint_0();
extern void _chlavacolumns_entrypoint_0();
extern void _chmumboskullfakearchpanellava_entrypoint_0();
extern void _chlavatraindoor_entrypoint_0();
extern void _chlavatraindoorswitch_entrypoint_0();
extern void _chlavaarchgrillswitch_entrypoint_0();
extern void _chlavaarchgrill_entrypoint_0();
extern void _chfirefx_entrypoint_1();
extern void _chfactoryroofbits_entrypoint_0();
extern void _chfactorybattery_entrypoint_1();
extern void _chwumbawigwam_entrypoint_0();
extern void _chswampplatform_entrypoint_0();
extern void _chsmalltrexdoor_entrypoint_0();
extern void _chdinofamilymother_entrypoint_0();
extern void _chdinofamilysick_entrypoint_1();
extern void _chdinofamilysmall_entrypoint_0();
extern void _chdinofamilymissing_entrypoint_0();
extern void _chcaptainblubber_entrypoint_0();
extern void _chtransparentfish_entrypoint_0();
extern void _chsunlightspell_entrypoint_0();
extern void _chdummyjigsaw_entrypoint_0();
extern void _chpufferfish_entrypoint_0();
extern void _chlinkpipefan_entrypoint_1();
extern void _chstoneballcontrol_entrypoint_4();
extern void _chglowbo_entrypoint_1();
extern void _chglowbo_entrypoint_3();
extern void _chhumba_entrypoint_0();
extern void _chflysaucer_entrypoint_1();
extern void _chflysaucercrate_entrypoint_0();
extern void _chflysaucer_entrypoint_2();
extern void _chchuffy_entrypoint_0();
extern void _chchuffycont_entrypoint_2();
extern void _chfiregen_entrypoint_12();
extern void _chfiregen_entrypoint_13();
extern void _chfiregen_entrypoint_14();
extern void _chfiregen_entrypoint_15();
extern void _chfiregen_entrypoint_16();
extern void _chfiregen_entrypoint_17();
extern void _chstatictorch_entrypoint_0();
extern void _chfloorbubbles_entrypoint_0();
extern void _chmumbopad_entrypoint_1();
extern void _cheggsplode_entrypoint_0();
extern void _chjadestatue_entrypoint_0();
extern void _chtemplebossdoor_entrypoint_0();
extern void _chtemplelobbydoor_entrypoint_0();
extern void _chtempleinternaldoor_entrypoint_0();
extern void _chnests_entrypoint_6();
extern void _chminelobbydoor_entrypoint_0();
extern void _chtransparencypot_entrypoint_0();
extern void _chtntmineshoot_entrypoint_1();
extern void _chtntmineshoot_entrypoint_2();
extern void _chtntmineshoot_entrypoint_0();
extern void _chclinker_entrypoint_1();
extern void _chclinker_entrypoint_2();
extern void _chclinker_entrypoint_0();
extern void _chfactorylobbydoor_entrypoint_0();
extern void _chtntmineshoot_entrypoint_3();
extern void _chfpsgame_entrypoint_0();
extern void _ch1pfreeze_entrypoint_0();
extern void _chmayafarmer_entrypoint_1();
extern void _chjujubagfx_entrypoint_0();
extern void _chpiranha_entrypoint_0();
extern void _chpiranha_entrypoint_1();
extern void _chpiranha_entrypoint_2();
extern void _chnewfreezy_entrypoint_1();
extern void _chlakemonster_entrypoint_0();
extern void _chlakemonster_entrypoint_4();
extern void _chminelightswitch_entrypoint_0();
extern void _chminelight_entrypoint_0();
extern void _chskeletonexplode_entrypoint_9();
extern void _chdodgemcontrol_entrypoint_2();
extern void _chdodgemcontrol_entrypoint_0();
extern void _chdodgemdoors_entrypoint_0();
extern void _chmole_maya_entrypoint_1();
extern void _chflysaucerdoor_entrypoint_0();
extern void _chflysaucerdoor_entrypoint_1();
extern void _chchuffyglow_entrypoint_1();
extern void _chtoothyfish_entrypoint_0();
extern void _chtoothyfish_entrypoint_1();
extern void _chmole_overworld_entrypoint_0();
extern void _chmole_lagoon_entrypoint_0();
extern void _chchuffy_entrypoint_2();
extern void _chintrochar_entrypoint_0();
extern void _chblackeye_entrypoint_0();
extern void _cheel_entrypoint_0();
extern void _chlagoonfish_entrypoint_0();
extern void _chboilerid_entrypoint_0();
extern void _chbilldrillboulder_entrypoint_1();
extern void _chklungoleave_entrypoint_0();
extern void _chhotfloorsmoke_entrypoint_0();
extern void _chfairgroundworker_entrypoint_0();
extern void _chfairgroundworker_entrypoint_1();
extern void _chfairgroundworker_entrypoint_2();
extern void _chfairgroundworker_entrypoint_3();
extern void _chburgerstand_entrypoint_0();
extern void _chburgerstand_entrypoint_1();
extern void _chfriesstand_entrypoint_0();
extern void _chfriesstand_entrypoint_1();
extern void _chburgerstand_entrypoint_2();
extern void _chburgerstand_entrypoint_3();
extern void _chfriesstand_entrypoint_2();
extern void _chfriesstand_entrypoint_3();
extern void _chconga_entrypoint_0();
extern void _chstarspinnerplanet_entrypoint_0();
extern void _chstarspinnerplanet_entrypoint_1();
extern void _chstarspinnerstar_entrypoint_0();
extern void _chstarspinnerctrl_entrypoint_0();
extern void _chstarspinnerctrl_entrypoint_1();
extern void _chhellterskelter_entrypoint_0();
extern void _chhellterskelter_entrypoint_2();
extern void _chhellterskelter_entrypoint_1();
extern void _chlightfader_entrypoint_0();
extern void _chcablespark_entrypoint_0();
extern void _chcablecar_entrypoint_0();
extern void _chcablecar_entrypoint_1();
extern void _chhellterskeltermouth_entrypoint_0();
extern void _chweldarbossdoors_entrypoint_0();
extern void _charea51gate_entrypoint_0();
extern void _chdiggerboss_entrypoint_0();
extern void _chghostdoor_entrypoint_0();
extern void _chweldarbossfusebox_entrypoint_0();
extern void _chsabreman_entrypoint_1();
extern void _chsabreman_entrypoint_2();
extern void _chghostdoor_entrypoint_1();
extern void _chfloater_entrypoint_0();
extern void _chpumproomgrill_entrypoint_0();
extern void _chpumproomswitch_entrypoint_0();
extern void _chbouncycastle_entrypoint_0();
extern void _chspotlight_entrypoint_0();
extern void _chboggykidshome_entrypoint_2();
extern void _chballoonburst_entrypoint_0();
extern void _chballoonburst_entrypoint_2();
extern void _chbouncycastle_entrypoint_1();
extern void _chpawnbroker_entrypoint_0();
extern void _chpawnbroker_entrypoint_1();
extern void _chpawnbroker_entrypoint_2();
extern void _chhoopswoop_entrypoint_0();
extern void _chhoopswoop_entrypoint_2();
extern void _chtiptup_entrypoint_0();
extern void _chtiptup_entrypoint_1();
extern void _chtiptup_entrypoint_2();
extern void _chonearmbandit_entrypoint_1();
extern void _chseaweedbaddy_entrypoint_0();
extern void _chseaweedbaddy_entrypoint_1();
extern void _choctopus_entrypoint_0();
extern void _chanemone_entrypoint_0();
extern void _chjollyroger_entrypoint_0();
extern void _chjollyroger_entrypoint_1();
extern void _chdinofoot_entrypoint_0();
extern void _chfreezy_entrypoint_0();
extern void _chdinoswitches_entrypoint_3();
extern void _chbigterrysbits_entrypoint_1();
extern void _chlagoonbits_entrypoint_0();
extern void _chlagoonbits_entrypoint_1();
extern void _chlagoonbits_entrypoint_2();
extern void _chlagoonbits_entrypoint_3();
extern void _chjollyroger_entrypoint_2();
extern void _chlagoonbilldrillcover_entrypoint_0();
extern void _chlagoonbits_entrypoint_4();
extern void _chlagoonbits_entrypoint_5();
extern void _chboxingglove_entrypoint_1();
extern void _chdinoboss_entrypoint_0();
extern void _chlakemonster_entrypoint_5();
extern void _chdrips_entrypoint_0();
extern void _chintroticker_entrypoint_0();
extern void _chmole_cuckoo_entrypoint_0();
extern void _chdragonbrothers_entrypoint_0();
extern void _chdragonbrothers_entrypoint_1();
extern void _chdragonbrothers_entrypoint_2();
extern void _chdragonbrothers_entrypoint_3();
extern void _chdragonbrothers_entrypoint_4();
extern void _chevilmumbo_entrypoint_0();
extern void _chevilmumbo_entrypoint_1();
extern void _chevilmumbo_entrypoint_2();
extern void _chdodgemcontrol_entrypoint_1();
extern void _chevilmumbo_entrypoint_3();
extern void _chhumba_entrypoint_1();
extern void _chtimetable_entrypoint_0();
extern void _chclockworkmouse_entrypoint_1();
extern void _chcrusher_entrypoint_4();
extern void _chhandcart_entrypoint_0();
extern void _chgruntylairexttowerwindow_entrypoint_0();
extern void _chhagstraindoor_entrypoint_0();
extern void _chhagstraindoorswitch_entrypoint_0();
extern void _chlavaentrancebridge_entrypoint_0();
extern void _chlavaentrancebridgeswitch_entrypoint_0();
extern void _chmayaentrydoor_entrypoint_0();
extern void _chlagoonentrygate_entrypoint_0();
extern void _chmineentrygrille_entrypoint_0();
extern void _chlavaentrydoor_entrypoint_0();
extern void _chcauldronentrydoor_entrypoint_1();
extern void _chterryteeth_entrypoint_0();
extern void _chphlegm_entrypoint_0();
extern void _chphlegm_entrypoint_1();
extern void _chlilterry_entrypoint_0();
extern void _chdinocoaster_entrypoint_0();
extern void _chpowerhutwitchy_entrypoint_0();
extern void _chpowerhutwitchy_entrypoint_1();
extern void _chpowerhutwitchy_entrypoint_2();
extern void _chpowerhutwitchy_entrypoint_3();
extern void _chphlegm_entrypoint_2();
extern void _chflamer_entrypoint_0();
extern void _chpoolkids_entrypoint_0();
extern void _chpoolkids_entrypoint_1();
extern void _chnicecavemenguard_entrypoint_0();
extern void _chnicecavemen_entrypoint_0();
extern void _chfactorylight_entrypoint_0();
extern void _chnicecavemen_entrypoint_3();
extern void _chbonfirecavern_entrypoint_0();
extern void _chterryegg_entrypoint_1();
extern void _charmouredcaveman_entrypoint_0();
extern void _chfirefx_entrypoint_0();
extern void _chweldarbossfusebox_entrypoint_1();
extern void _chicywind_entrypoint_0();
extern void _chintrotext_entrypoint_0();
extern void _chfactoryprop_entrypoint_0();
extern void _chfactoryprop_entrypoint_1();
extern void _chtrashcompactor_entrypoint_0();
extern void _chtrashcompactor_entrypoint_1();
extern void _chtrashcompactor_entrypoint_2();
extern void _chtrashcompactor_entrypoint_3();
extern void _chfactoryliftdoor_entrypoint_0();
extern void _chfactoryliftdoor_entrypoint_1();
extern void _chfactorycrusher_entrypoint_0();
extern void _chfactorycrusher_entrypoint_1();
extern void _chcrate_entrypoint_1();
extern void _chfactoryrobot_entrypoint_0();
extern void _chfactoryrobot_entrypoint_1();
extern void _chfactoryrobot_entrypoint_2();
extern void _chmermaidstatue_entrypoint_0();
extern void _chmermaidstatue_entrypoint_1();
extern void _chcrate_entrypoint_2();
extern void _chfactorygoblin_entrypoint_0();
extern void _chfactorytoxicpools_entrypoint_0();
extern void _chfactorytoxicpools_entrypoint_1();
extern void _chbigtopticket_entrypoint_0();
extern void _chbouncycastle_entrypoint_2();
extern void _chbouncycastle_entrypoint_3();
extern void _chlagoonpirate_entrypoint_0();
extern void _chpickups_entrypoint_1();
extern void _chpickups_entrypoint_2();
extern void _chvandoor_entrypoint_0();
extern void _chpoolkids_entrypoint_2();
extern void _chcoderoombits_entrypoint_0();
extern void _chbilldrillboulder_entrypoint_2();
extern void _chdingpot_entrypoint_0();
extern void _chpumproomswitch_entrypoint_1();
extern void _chelectricfence_entrypoint_0();
extern void _chmadamegrunty_entrypoint_1();
extern void _chfactorysmoke_entrypoint_0();
extern void _chterryegg_entrypoint_2();
extern void _chterryegg_entrypoint_3();
extern void _chdinoboss_entrypoint_1();
extern void _chappearfx_entrypoint_0();
extern void _chfootwear_entrypoint_2();
extern void _chbilldrillplate_entrypoint_0();
extern void _chbilldrillplate_entrypoint_1();
extern void _chbilldrillplate_entrypoint_2();
extern void _chrainripples_entrypoint_0();
extern void _chdumbwaiterlift_entrypoint_0();
extern void _chmrsicecube_entrypoint_0();
extern void _chmrsicecube_entrypoint_1();
extern void _chgobihailfire_entrypoint_0();
extern void _chboggykidshome_entrypoint_1();
extern void _chbigfoot_entrypoint_0();
extern void _chbiggafoot_entrypoint_0();
extern void _chmricecube_entrypoint_0();
extern void _chfactorylinkgrill_entrypoint_0();
extern void _chlavahand_entrypoint_0();
extern void _chtoxicroombits_entrypoint_0();
extern void _chtoxicroombits_entrypoint_1();
extern void _chtoxicroomprops_entrypoint_0();
extern void _chfactorysparkroom_entrypoint_1();
extern void _chfactoryempspell_entrypoint_1();
extern void _chgoldfish_entrypoint_0();
extern void _chfactorydrums_entrypoint_2();
extern void _chfactorylinkgrill_entrypoint_1();
extern void _chfactoryroofbits_entrypoint_1();
extern void _chfactoryroofbits_entrypoint_2();
extern void _chfactoryroofbits_entrypoint_3();
extern void _chfactorymagnet_entrypoint_1();
extern void _chfactorymagnet_entrypoint_2();
extern void _chfactorybtwmdoor_entrypoint_0();
extern void _chfactorymaindoor_entrypoint_0();
extern void _chfactorymaindoor_entrypoint_1();
extern void _chfactorylinkgrill_entrypoint_2();
extern void _chfactorybattery_entrypoint_2();
extern void _chbosskogsdoor_entrypoint_1();
extern void _chbosskogsdoor_entrypoint_0();
extern void _chlensflare_entrypoint_1();
extern void _chfactorytoxiccloud_entrypoint_0();
extern void _chlavahand_entrypoint_1();
extern void _chlavagargoyle_entrypoint_0();
extern void _chlavagargoyle_entrypoint_2();
extern void _chfactorytrashbelt_entrypoint_0();
extern void _chpotogoldgame_entrypoint_4();
extern void _chfactorystationdoors_entrypoint_0();
extern void _chpotogoldbits_entrypoint_0();
extern void _chpotogoldbits_entrypoint_2();
extern void _chpotogoldbits_entrypoint_3();
extern void _chfantasydrillfield_entrypoint_0();
extern void _chfantasytrashcanbits_entrypoint_1();
extern void _chfantasytrashcanbits_entrypoint_0();
extern void _chbeanstalkseed_entrypoint_0();
extern void _chrainbow_entrypoint_1();
extern void _chwaspstatue_entrypoint_1();
extern void _chwaspstatue_entrypoint_2();
extern void _chbubbleelevator_entrypoint_0();
extern void _chfactorysparkroom_entrypoint_0();
extern void _chfantasylakebits_entrypoint_2();
extern void _chfantasylakebits_entrypoint_1();
extern void _chtoxicroomprops_entrypoint_2();
extern void _chfantasysafe_entrypoint_0();
extern void _chfantasysafeswitch_entrypoint_0();
extern void _chicestationbits_entrypoint_0();
extern void _chicestationbits_entrypoint_1();
extern void _chiciclebits_entrypoint_0();
extern void _chboggykidshome_entrypoint_0();
extern void _chklungo_entrypoint_0();
extern void _chklungodoors_entrypoint_0();
extern void _chklungodoors_entrypoint_1();
extern void _chklungoforcefield_entrypoint_0();
extern void _chklungophial_entrypoint_0();
extern void _chklungophial_entrypoint_1();
extern void _chvolcanobits_entrypoint_0();
extern void _chvolcanobits_entrypoint_1();
extern void _chcrystalbaddie_entrypoint_0();
extern void _chhotwaterpoolbits_entrypoint_0();
extern void _chhotwaterpoolbits_entrypoint_1();
extern void _chvolcanobits_entrypoint_2();
extern void _chvolcanobits_entrypoint_3();
extern void _chnicecavemen_entrypoint_1();
extern void _chnicecavemen_entrypoint_2();
extern void _chdippy_entrypoint_0();
extern void _chfactoryflypad_entrypoint_0();
extern void _chfactoryflypad_entrypoint_1();
extern void _chmrsboggyhome_entrypoint_0();
extern void _chweldarbossdoors_entrypoint_1();
extern void _chfactorytoxicpools_entrypoint_2();
extern void _chdinoswitches_entrypoint_1();
extern void _chdinoswitches_entrypoint_2();
extern void _chloggo_entrypoint_0();
extern void _chloggo_entrypoint_1();
extern void _chkingjinjo_entrypoint_0();
extern void _chhotwaterpoolbits_entrypoint_2();
extern void _chhotwaterpoolbits_entrypoint_3();
extern void _chbottlesfamily_entrypoint_0();
extern void _chbottlesfamily_entrypoint_1();
extern void _chbottlesfamily_entrypoint_2();
extern void _chnutsnbolts_entrypoint_0();
extern void _chnutsnbolts_entrypoint_1();
extern void _chnutsnbolts_entrypoint_2();
extern void _chdippy_entrypoint_1();
extern void _chfactorytwinklies_entrypoint_0();
extern void _chfactorytwinklies_entrypoint_3();
extern void _chfactorytwinklies_entrypoint_4();
extern void _chfactorytwinklies_entrypoint_5();
extern void _chfactorytwinklies_entrypoint_2();
extern void _chstatueboss_entrypoint_0();
extern void _chstatuebossbits_entrypoint_0();
extern void _chstatuebossbits_entrypoint_1();
extern void _chhoopswoop_entrypoint_1();
extern void _chproplighter_entrypoint_0();
extern void _chballoonburst_entrypoint_1();
extern void _chfactorytwinklies_entrypoint_1();
extern void _chbiggafoot_entrypoint_1();
extern void _chstatuebossbits_entrypoint_3();
extern void _chstatuebossbits_entrypoint_2();
extern void _chmonsterinterior_entrypoint_0();
extern void _chmonsterinterior_entrypoint_2();
extern void _chmonsterinterior_entrypoint_3();
extern void _chmonsterinterior_entrypoint_4();
extern void _chmonsterinterior_entrypoint_1();
extern void _chalienkids_entrypoint_0();
extern void _chalienkids_entrypoint_1();
extern void _chalienkids_entrypoint_2();
extern void _chalienkids_entrypoint_3();
extern void _chaliendad_entrypoint_0();
extern void _chaliendad_entrypoint_2();
extern void _chlifeforcespell_entrypoint_0();
extern void _changlerboss_entrypoint_0();
extern void _changlerboss_entrypoint_1();
extern void _changlerbossflare_entrypoint_0();
extern void _changlerbossbubble_entrypoint_0();
extern void _chbigterrysbits_entrypoint_0();
extern void _chfireimp_entrypoint_0();
extern void _chmumboskulls_entrypoint_0();
extern void _ch2dbaddy_entrypoint_0();
extern void _chweldarboss_entrypoint_0();
extern void _chalienbeam_entrypoint_0();
extern void _chaliendad_entrypoint_1();
extern void _chweldarboss_entrypoint_1();
extern void _chbigterrysbits_entrypoint_2();
extern void _chweldarbossfusebox_entrypoint_2();
extern void _chflowerbaddie_entrypoint_0();
extern void _changlerbossdoor_entrypoint_0();
extern void _chboilerbossdoor_entrypoint_0();
extern void _chinflatablebossdoor_entrypoint_0();
extern void _chhotwatersteam_entrypoint_0();
extern void _chcastleshockpadswitch_entrypoint_0();
extern void _chfootwear_entrypoint_4();
extern void _chtalontorpedoboulder_entrypoint_0();
extern void _chexplodingchainlinks_entrypoint_0();
extern void _chfactoryroofbits_entrypoint_4();
extern void _chtrashcangame_entrypoint_0();
extern void _chtrashcangame_entrypoint_2();
extern void _chfantasyathlete_entrypoint_0();
extern void _chtoxicroomprops_entrypoint_1();
extern void _chfantasycannon_entrypoint_0();
extern void _chfantasycannon_entrypoint_1();
extern void _chfantasyonion_entrypoint_0();
extern void _chbeanstalkseed_entrypoint_1();
extern void _chpickups_entrypoint_3();
extern void _chfantasyeyeball_entrypoint_0();
extern void _chfantasyeyeball_entrypoint_1();
extern void _choildrill_entrypoint_1();
extern void _choildrill_entrypoint_2();
extern void _chfloaty_entrypoint_1();
extern void _chLagoonInnBlockedWall_entrypoint_0();
extern void _chwitchyentrygates_entrypoint_0();
extern void _chfactoryentrydoors_entrypoint_0();
extern void _chcauldronenergybars_entrypoint_0();
extern void _chjinjovillagecamera1_entrypoint_0();
extern void _chjinjo_entrypoint_6();
extern void _chLagoonInnBlockedWall_entrypoint_1();
extern void _chlavaarchgrill3switches_entrypoint_0();
extern void _chlavaarchgrill3switches_entrypoint_1();
extern void _chlavaarchgrill3switches_entrypoint_2();
extern void _chmumboskullfakearchpanellava_entrypoint_1();
extern void _chlagoonlockerdoorhits_entrypoint_0();
extern void _chTalTorpWall_entrypoint_0();
extern void _chufoextdoor_entrypoint_0();
extern void _chdinotraindoor_entrypoint_0();
extern void _chdinotraindoorswitch_entrypoint_0();
extern void _chminegrill2switches_entrypoint_0();
extern void _chminegrill2switches_entrypoint_1();
extern void _chcauldronentrydoor_entrypoint_2();
extern void _chdrawbridgeswitches_entrypoint_0();
extern void _chdrawbridgeswitches_entrypoint_1();
extern void _chdinoroargrill_entrypoint_0();
extern void _chlavaexplodbuild_entrypoint_0();
extern void _chboggy_entrypoint_0();
extern void _chnests_entrypoint_12();
extern void _chgameselect_entrypoint_0();
extern void _chgameselect_entrypoint_2();
extern void _chgameselect_entrypoint_3();
extern void _chgameselect_entrypoint_4();
extern void _chgameselect_entrypoint_1();
extern void _chgameselect_entrypoint_5();
extern void _chminisubgame_entrypoint_0();
extern void _chminisubgame_entrypoint_1();
extern void _chjiggypost_entrypoint_0();
extern void _chhoneyb_entrypoint_0();
extern void _chmasterjiggy_entrypoint_1();
extern void _chjiggytemple_entrypoint_2();
extern void _chjiggybeam_entrypoint_0();
extern void _chattract_entrypoint_0();
extern void _chgameselect_entrypoint_6();
extern void _chpickups_entrypoint_10();
extern void _chhoneyb_entrypoint_1();
extern void _chgameselect_entrypoint_7();
extern void _chboggyfish_entrypoint_0();
extern void _chbottlesdead_entrypoint_0();
extern void _chjrinnlight_entrypoint_0();
extern void _chfoodwarn_entrypoint_0();
extern void _chperspexbox_entrypoint_0();
extern void _chperspexboxswitch_entrypoint_0();
extern void _chminegrilldoor_entrypoint_0();
extern void _chwitchytents_entrypoint_0();
extern void _chwitchytents_entrypoint_1();
extern void _chfantasybounce_entrypoint_0();
extern void _chfantasybounce_entrypoint_1();
extern void _chgoldsnakehead_entrypoint_2();
extern void _chquizexitdoor_entrypoint_0();
extern void _chsparkle_entrypoint_0();
extern void _chpickups_entrypoint_7();
extern void _chmumbohealspell_entrypoint_0();
extern void _chfactoryroofbits_entrypoint_5();
extern void _chfactorymaindoor_entrypoint_2();
extern void _chfactoryentrydoors_entrypoint_1();
extern void _chpickups_entrypoint_4();
extern void _chpickups_entrypoint_5();
extern void _chpickups_entrypoint_6();
extern void _chdoubloon_entrypoint_2();
extern void _chwitchyshockpadswitch_entrypoint_0();
extern void _chsquits_entrypoint_0();
extern void _chbottlesplantgrill_entrypoint_0();
extern void _chkingjinjobits_entrypoint_0();
extern void _chklungospiral_entrypoint_0();
extern void _chfactoryposter_entrypoint_0();
extern void _chjigsawcollect_entrypoint_0();
extern void _chdiggerbossdoor_entrypoint_0();
extern void _chgruntyfireball_entrypoint_0();
extern void _chdiggerbossshell_entrypoint_0();
extern void _chdiggerbossshell_entrypoint_1();
extern void _chdiggerbossbattery_entrypoint_0();
extern void _chgruntyfireballbig_entrypoint_0();
extern void _chdiggerbossinterior_entrypoint_0();
extern void _chbottlesparty_entrypoint_0();
extern void _chbottlesparty_entrypoint_1();
extern void _chspiralgrill_entrypoint_0();
extern void _chfireicestorm_entrypoint_0();
extern void _chfireicestorm_entrypoint_1();
extern void _chfactoryprop_entrypoint_2();
extern void _chdiggerbossdeflect_entrypoint_0();
extern void _chgobihailfire_entrypoint_1();
extern void _chchompaslunch_entrypoint_0();
extern void _chlavafall_entrypoint_0();
extern void _chlighthalo_entrypoint_0();
extern void _chcrashmat_entrypoint_0();
extern void _chjellycastle_entrypoint_0();
extern void _chfantasysafe_entrypoint_1();
extern void _chtrashcangame_entrypoint_3();
extern void _chfactorymagnet_entrypoint_3();
extern void _chicekeydoor_entrypoint_0();
extern void _chicekey_entrypoint_0();
extern void _chheggy_entrypoint_0();
extern void _chpickups_entrypoint_8();
extern void _chpickups_entrypoint_9();
extern void _chsecreteggs_entrypoint_0();
extern void _chplatuegrill_entrypoint_0();
extern void _chplatuegrill_entrypoint_1();
extern void _chbkcart_entrypoint_0();
extern void _chworlddoors_entrypoint_0();
extern void _chtrashcangame_entrypoint_1();
extern void _chhandcart_entrypoint_2();
extern void _chglowbo_entrypoint_2();
extern void _chjigsaw_entrypoint_1();
extern void _chquiz_entrypoint_4();
extern void _chquiz_entrypoint_1();
extern void _chheggy_entrypoint_1();
extern void _chquiz_entrypoint_2();
extern void _chquiz_entrypoint_0();
extern void _chdinofamilysick_entrypoint_2();
extern void _chquiz_entrypoint_3();
extern void _chfactorymagnet_entrypoint_4();
extern void _chboggy_entrypoint_1();
extern void _chmusicmenu_entrypoint_1();
extern void _chbobpanel_entrypoint_0();
extern void _chtrashcangame_entrypoint_4();
extern void _chmusicmenu_entrypoint_2();
extern void _chdeflect_entrypoint_0();
extern void _chjadestatue_entrypoint_1();
extern void _chdrawbridgeswitches_entrypoint_2();
s32 *D_80800090_gemarkersDll[490] = {0,
                                     (void *) _chjamjarsdummy_entrypoint_0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     (void *) _chjadesnake_entrypoint_0,
                                     (void *) _chgoldsnakehead_entrypoint_0,
                                     (void *) _chgoldsnakehead_entrypoint_1,
                                     (void *) _chbilldrillboulder_entrypoint_0,
                                     (void *) _chcoderoomdoor_entrypoint_0,
                                     (void *) _chwallsnakebaddy_entrypoint_0,
                                     (void *) _chwarriorbaddy_entrypoint_0,
                                     (void *) _chstonedartgunhead_entrypoint_0,
                                     (void *) _chfriendlystonehead_entrypoint_0,
                                     (void *) _chamazongoldhordeofficial_entrypoint_0,
                                     (void *) _chamazonstadiumguard_entrypoint_0,
                                     (void *) _chprisonbits_entrypoint_4,
                                     (void *) _chboilerboss_entrypoint_0,
                                     (void *) _chtntbox_entrypoint_0,
                                     (void *) _chnewshovel_entrypoint_0,
                                     (void *) _chwaterfallgrill_entrypoint_1,
                                     (void *) _chwaterfallgrillswitch_entrypoint_0,
                                     0,
                                     (void *) _chprisonbits_entrypoint_0,
                                     (void *) _chprisonbits_entrypoint_1,
                                     (void *) _chprisonbits_entrypoint_2,
                                     (void *) _chprisonbits_entrypoint_3,
                                     0,
                                     (void *) _chstonedartgunhead_entrypoint_1,
                                     (void *) _chweldarbossfireball_entrypoint_0,
                                     0,
                                     0,
                                     0,
                                     (void *) _chgate1doors_entrypoint_0,
                                     (void *) _chgate1doors_entrypoint_1,
                                     (void *) _chtemplebrokendoorpiece_entrypoint_0,
                                     (void *) _chcrackarchwall_entrypoint_0,
                                     0,
                                     (void *) _chlightdemon_entrypoint_0,
                                     (void *) _chstonepillar_entrypoint_0,
                                     (void *) _chstonepillar_entrypoint_1,
                                     (void *) _chdinoswitches_entrypoint_0,
                                     (void *) _chdiggerground_entrypoint_0,
                                     (void *) _chdiggergroundgen_entrypoint_0,
                                     (void *) _chdiggerfly_entrypoint_0,
                                     (void *) _chdiggerfly_entrypoint_1,
                                     (void *) _chcheato_entrypoint_0,
                                     (void *) _chcheatopage_entrypoint_0,
                                     (void *) _chgobiwitchy_entrypoint_0,
                                     (void *) _chbabydino_entrypoint_0,
                                     (void *) _chcactusofstrength_entrypoint_0,
                                     (void *) _chcactusofstrength_entrypoint_2,
                                     (void *) _chcactusofstrength_entrypoint_1,
                                     (void *) _chinflatableboss_entrypoint_0,
                                     (void *) _chballoonbomb_entrypoint_0,
                                     (void *) _chboxingglove_entrypoint_0,
                                     (void *) _chmrsboggy_entrypoint_0,
                                     (void *) _chboggyboy_entrypoint_0,
                                     (void *) _chboggygirl_entrypoint_0,
                                     (void *) _chboggyfatboy_entrypoint_1,
                                     (void *) _chmineprospector_entrypoint_0,
                                     (void *) _chonearmbandit_entrypoint_0,
                                     (void *) _chtntblockage_entrypoint_0,
                                     (void *) _chweldarhead_entrypoint_0,
                                     (void *) _chkingjinjo_entrypoint_1,
                                     (void *) _chcamerawibble_entrypoint_0,
                                     (void *) _chtntdetonator_entrypoint_0,
                                     (void *) _chtnthut_entrypoint_0,
                                     (void *) _chtntminecelldoor_entrypoint_0,
                                     (void *) _chcaveofhorrorsdoors_entrypoint_0,
                                     (void *) _chbanjoctrl_entrypoint_0,
                                     (void *) _chscorepoints_entrypoint_0,
                                     (void *) _chmadamegrunty_entrypoint_0,
                                     (void *) _chhillbilly_entrypoint_0,
                                     (void *) _chmineprospector_entrypoint_1,
                                     (void *) _chmineprospector_entrypoint_2,
                                     (void *) _chevilspirit_entrypoint_0,
                                     0,
                                     (void *) _chstoneballcontrol_entrypoint_2,
                                     (void *) _chpodiumbankaz_entrypoint_1,
                                     (void *) _chpodiumbankaz_entrypoint_0,
                                     (void *) _chswappy_entrypoint_1,
                                     0,
                                     (void *) _cheggnormal_entrypoint_0,
                                     (void *) _cheggfire_entrypoint_0,
                                     (void *) _cheggice_entrypoint_0,
                                     (void *) _chegggrenade_entrypoint_1,
                                     (void *) _cheggclockwork_entrypoint_0,
                                     (void *) _chegggolden_entrypoint_0,
                                     (void *) _cheggproximity_entrypoint_0,
                                     0,
                                     (void *) _chlaundry_entrypoint_0,
                                     (void *) _chgoldstatue_entrypoint_0,
                                     (void *) _chwandglow_entrypoint_3,
                                     (void *) _chfaircoinbox_entrypoint_2,
                                     (void *) _chfaircoin_entrypoint_1,
                                     0,
                                     (void *) _chtorpedo_entrypoint_1,
                                     (void *) _chping_entrypoint_1,
                                     (void *) _chfootwear_entrypoint_3,
                                     0,
                                     0,
                                     0,
                                     (void *) _chclimbbase_entrypoint_1,
                                     (void *) _chstinger_entrypoint_1,
                                     (void *) _chfactoryworkerdirty_entrypoint_0,
                                     (void *) _chclockworkmouse_entrypoint_0,
                                     (void *) _chstadiumdoors_entrypoint_0,
                                     (void *) _chstoneballcoach_entrypoint_0,
                                     (void *) _chcredits_entrypoint_2,
                                     (void *) _chsounder_entrypoint_0,
                                     (void *) _chcanarymarycage_entrypoint_0,
                                     0,
                                     (void *) _chfog_entrypoint_0,
                                     0,
                                     (void *) _chcrusher_entrypoint_0,
                                     (void *) _chcrusher_entrypoint_2,
                                     (void *) _chcrusher_entrypoint_1,
                                     (void *) _chcrusher_entrypoint_3,
                                     (void *) _chcrusherboulder_entrypoint_0,
                                     (void *) _chjigsawbitcont_entrypoint_1,
                                     (void *) _chjigsawbitcont_entrypoint_0,
                                     0,
                                     (void *) _chmole_witchy_entrypoint_0,
                                     0,
                                     (void *) _chmole_hailfire_entrypoint_0,
                                     (void *) _chmole_factory_entrypoint_0,
                                     (void *) _chmole_prehist_entrypoint_0,
                                     0,
                                     0,
                                     0,
                                     (void *) _chcheatomenu_entrypoint_0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     (void *) _chmoley_entrypoint_2,
                                     (void *) _chnewmumbo_entrypoint_1,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     (void *) _chhoney_entrypoint_1,
                                     (void *) _chhoney_entrypoint_2,
                                     (void *) _chsignpost_entrypoint_0,
                                     0,
                                     (void *) _chbadbeehive_entrypoint_0,
                                     (void *) _chmayafarmer_entrypoint_0,
                                     (void *) _chbadjinjo_entrypoint_0,
                                     (void *) _chsilo_entrypoint_0,
                                     (void *) _chcollballcontrol_entrypoint_0,
                                     (void *) _chcollballcontrol_entrypoint_5,
                                     (void *) _chintrocam_entrypoint_0,
                                     (void *) _chcollballcontrol_entrypoint_2,
                                     (void *) _chcollballcontrol_entrypoint_4,
                                     (void *) _chcollballcontrol_entrypoint_3,
                                     (void *) _chcolldoors_entrypoint_0,
                                     (void *) _chmusicmenu_entrypoint_0,
                                     0,
                                     (void *) _chmole_maya_entrypoint_0,
                                     (void *) _chmole_mine_entrypoint_0,
                                     (void *) _chmole_training_entrypoint_1,
                                     (void *) _chfiregen_entrypoint_0,
                                     (void *) _chfiregen_entrypoint_6,
                                     (void *) _chfiregen_entrypoint_1,
                                     (void *) _chfiregen_entrypoint_7,
                                     (void *) _chfiregen_entrypoint_2,
                                     (void *) _chfiregen_entrypoint_8,
                                     (void *) _chfiregen_entrypoint_3,
                                     (void *) _chfiregen_entrypoint_9,
                                     (void *) _chfiregen_entrypoint_4,
                                     (void *) _chfiregen_entrypoint_10,
                                     (void *) _chfiregen_entrypoint_5,
                                     (void *) _chfiregen_entrypoint_11,
                                     (void *) _chstoneballcontrol_entrypoint_5,
                                     (void *) _chstoneballcontrol_entrypoint_0,
                                     (void *) _chstoneballcontrol_entrypoint_3,
                                     0,
                                     0,
                                     (void *) _chwaterfallfx_entrypoint_0,
                                     0,
                                     (void *) _chidgoldhorde_entrypoint_0,
                                     (void *) _chfishshootgame_entrypoint_0,
                                     (void *) _chfishshootgame_entrypoint_1,
                                     0,
                                     0,
                                     (void *) _chlagoonufoext_entrypoint_0,
                                     (void *) _chlagoonufoint_entrypoint_1,
                                     (void *) _chlagoonufoint_entrypoint_4,
                                     (void *) _chlagoonufoint_entrypoint_0,
                                     (void *) _chlagoonufoint_entrypoint_2,
                                     (void *) _chlagoonufoint_entrypoint_3,
                                     (void *) _chnests_entrypoint_0,
                                     (void *) _chnests_entrypoint_1,
                                     (void *) _chnests_entrypoint_2,
                                     (void *) _chnests_entrypoint_3,
                                     (void *) _chnests_entrypoint_4,
                                     (void *) _chnests_entrypoint_5,
                                     (void *) _chnests_entrypoint_7,
                                     (void *) _chnests_entrypoint_8,
                                     (void *) _chfishshootgame_entrypoint_2,
                                     (void *) _chbanjocurrent_entrypoint_0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     (void *) _chbanjocurrent_entrypoint_1,
                                     (void *) _chnests_entrypoint_9,
                                     (void *) _chnests_entrypoint_10,
                                     (void *) _chpickups_entrypoint_0,
                                     (void *) _chnastycavemen_entrypoint_0,
                                     (void *) _chnastycavemen_entrypoint_1,
                                     0,
                                     (void *) _chcamwaypoint_entrypoint_0,
                                     (void *) _chjiggygamenew_entrypoint_4,
                                     (void *) _chjiggygamenew_entrypoint_0,
                                     (void *) _chlightdemon_entrypoint_1,
                                     (void *) _chmasterjiggy_entrypoint_0,
                                     (void *) _chjiggygamenew_entrypoint_3,
                                     (void *) _chwaspnestgame_entrypoint_0,
                                     (void *) _chwaspnestgame_entrypoint_1,
                                     (void *) _chwarppad_entrypoint_0,
                                     (void *) _chjiggytemple_entrypoint_0,
                                     (void *) _chjiggytemple_entrypoint_1,
                                     (void *) _chscreenadjust_entrypoint_0,
                                     (void *) _chnests_entrypoint_11,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     (void *) _chquicksandbaddy_entrypoint_1,
                                     (void *) _chcrate_entrypoint_0,
                                     0,
                                     0,
                                     0,
                                     (void *) _chjinjo_entrypoint_5,
                                     0,
                                     0,
                                     0,
                                     0,
                                     (void *) _chclimbbase_entrypoint_0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     (void *) _chsabreman_entrypoint_3,
                                     (void *) _chexploder_entrypoint_0,
                                     (void *) _chtntbox_entrypoint_1,
                                     0,
                                     (void *) _chmumbopadstatue_entrypoint_0,
                                     (void *) _chdiggerboss_entrypoint_1,
                                     (void *) _chweather_entrypoint_0,
                                     (void *) _chweather_entrypoint_1,
                                     (void *) _chweather_entrypoint_2,
                                     (void *) _chweather_entrypoint_3,
                                     (void *) _chweather_entrypoint_4,
                                     (void *) _chweather_entrypoint_5,
                                     (void *) _chweather_entrypoint_6,
                                     (void *) _chweather_entrypoint_7,
                                     0,
                                     0,
                                     0,
                                     0,
                                     (void *) _chshockjump_entrypoint_0,
                                     (void *) _chbeehive_entrypoint_0,
                                     0,
                                     (void *) _chzubba_entrypoint_0,
                                     0,
                                     (void *) func_800A7168,
                                     0,
                                     (void *) _chquizremotectrl_entrypoint_0,
                                     0,
                                     0,
                                     (void *) _chfootwear_entrypoint_0,
                                     (void *) _chglowbo_entrypoint_0,
                                     0,
                                     0,
                                     0,
                                     (void *) _chjigsaw_entrypoint_0,
                                     (void *) _chhoneycarrier_entrypoint_0,
                                     0,
                                     0,
                                     (void *) _chboilerboss_entrypoint_1,
                                     (void *) _chboilerboss_entrypoint_2,
                                     (void *) _chboilerboss_entrypoint_3,
                                     0,
                                     0,
                                     0,
                                     (void *) _chhoney_entrypoint_0,
                                     0,
                                     0,
                                     (void *) _chjigsawdance_entrypoint_2,
                                     0,
                                     (void *) _chfootwear_entrypoint_1,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     (void *) _chshockjump_entrypoint_1,
                                     0,
                                     0,
                                     0,
                                     0,
                                     (void *) _chfactoryworkerwear_entrypoint_0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     (void *) _chbadshad_entrypoint_0,
                                     0,
                                     0,
                                     (void *) _chlavaslabswitch_entrypoint_0,
                                     (void *) _chmolehill_entrypoint_6,
                                     0,
                                     0,
                                     0,
                                     0,
                                     (void *) _chmineproplight_entrypoint_0,
                                     0,
                                     0,
                                     0,
                                     (void *) _chlavaslab_entrypoint_0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     (void *) _chusefeather_entrypoint_2,
                                     (void *) _chusefeather_entrypoint_3,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     (void *) _chlavacolumnswitch_entrypoint_0,
                                     (void *) _chlavacolumns_entrypoint_0,
                                     (void *) _chmumboskullfakearchpanellava_entrypoint_0,
                                     (void *) _chlavatraindoor_entrypoint_0,
                                     0,
                                     0,
                                     0,
                                     (void *) _chlavatraindoorswitch_entrypoint_0,
                                     0,
                                     (void *) _chlavaarchgrillswitch_entrypoint_0,
                                     (void *) _chlavaarchgrill_entrypoint_0,
                                     (void *) _chfirefx_entrypoint_1,
                                     0,
                                     (void *) _chfactoryroofbits_entrypoint_0,
                                     (void *) _chfactorybattery_entrypoint_1,
                                     (void *) _chwumbawigwam_entrypoint_0,
                                     (void *) _chswampplatform_entrypoint_0,
                                     (void *) _chsmalltrexdoor_entrypoint_0,
                                     (void *) _chdinofamilymother_entrypoint_0,
                                     (void *) _chdinofamilysick_entrypoint_1,
                                     (void *) _chdinofamilysmall_entrypoint_0,
                                     (void *) _chdinofamilymissing_entrypoint_0,
                                     (void *) _chcaptainblubber_entrypoint_0,
                                     (void *) _chtransparentfish_entrypoint_0,
                                     0,
                                     (void *) _chsunlightspell_entrypoint_0,
                                     (void *) _chdummyjigsaw_entrypoint_0,
                                     0,
                                     (void *) _chpufferfish_entrypoint_0,
                                     0,
                                     (void *) _chlinkpipefan_entrypoint_1,
                                     0,
                                     (void *) _chstoneballcontrol_entrypoint_4,
                                     (void *) _chglowbo_entrypoint_1};
static u32 D_80800090_gemarkersDll_rest[678] = {(u32) _chglowbo_entrypoint_3,
                                                (u32) _chhumba_entrypoint_0,
                                                (u32) _chflysaucer_entrypoint_1,
                                                (u32) _chflysaucercrate_entrypoint_0,
                                                (u32) _chflysaucer_entrypoint_2,
                                                (u32) _chchuffy_entrypoint_0,
                                                (u32) _chchuffycont_entrypoint_2,
                                                (u32) _chfiregen_entrypoint_12,
                                                (u32) _chfiregen_entrypoint_13,
                                                (u32) _chfiregen_entrypoint_14,
                                                (u32) _chfiregen_entrypoint_15,
                                                (u32) _chfiregen_entrypoint_16,
                                                (u32) _chfiregen_entrypoint_17,
                                                0x0,
                                                (u32) _chstatictorch_entrypoint_0,
                                                (u32) _chfloorbubbles_entrypoint_0,
                                                (u32) _chmumbopad_entrypoint_1,
                                                0x0,
                                                (u32) _cheggsplode_entrypoint_0,
                                                (u32) _chjadestatue_entrypoint_0,
                                                (u32) _chtemplebossdoor_entrypoint_0,
                                                (u32) _chtemplelobbydoor_entrypoint_0,
                                                (u32) _chtempleinternaldoor_entrypoint_0,
                                                0x0,
                                                (u32) _chnests_entrypoint_6,
                                                (u32) _chminelobbydoor_entrypoint_0,
                                                0x0,
                                                (u32) _chtransparencypot_entrypoint_0,
                                                (u32) _chtntmineshoot_entrypoint_1,
                                                (u32) _chtntmineshoot_entrypoint_2,
                                                (u32) _chtntmineshoot_entrypoint_0,
                                                (u32) _chclinker_entrypoint_1,
                                                (u32) _chclinker_entrypoint_2,
                                                (u32) _chclinker_entrypoint_0,
                                                (u32) _chfactorylobbydoor_entrypoint_0,
                                                (u32) _chtntmineshoot_entrypoint_3,
                                                (u32) _chfpsgame_entrypoint_0,
                                                (u32) _ch1pfreeze_entrypoint_0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                (u32) _chmayafarmer_entrypoint_1,
                                                (u32) _chjujubagfx_entrypoint_0,
                                                0x0,
                                                0x0,
                                                (u32) _chpiranha_entrypoint_0,
                                                (u32) _chpiranha_entrypoint_1,
                                                (u32) _chpiranha_entrypoint_2,
                                                (u32) _chnewfreezy_entrypoint_1,
                                                (u32) _chlakemonster_entrypoint_0,
                                                (u32) _chlakemonster_entrypoint_4,
                                                (u32) _chminelightswitch_entrypoint_0,
                                                (u32) _chminelight_entrypoint_0,
                                                (u32) _chskeletonexplode_entrypoint_9,
                                                (u32) _chdodgemcontrol_entrypoint_2,
                                                (u32) _chdodgemcontrol_entrypoint_0,
                                                (u32) _chdodgemdoors_entrypoint_0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                (u32) _chmole_maya_entrypoint_1,
                                                (u32) _chflysaucerdoor_entrypoint_0,
                                                (u32) _chflysaucerdoor_entrypoint_1,
                                                (u32) _chchuffyglow_entrypoint_1,
                                                (u32) _chtoothyfish_entrypoint_0,
                                                (u32) _chtoothyfish_entrypoint_1,
                                                (u32) _chmole_overworld_entrypoint_0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                (u32) _chmole_lagoon_entrypoint_0,
                                                (u32) _chchuffy_entrypoint_2,
                                                (u32) _chintrochar_entrypoint_0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                (u32) _chblackeye_entrypoint_0,
                                                (u32) _cheel_entrypoint_0,
                                                (u32) _chlagoonfish_entrypoint_0,
                                                0x0,
                                                (u32) _chboilerid_entrypoint_0,
                                                (u32) _chbilldrillboulder_entrypoint_1,
                                                (u32) _chklungoleave_entrypoint_0,
                                                0x0,
                                                0x0,
                                                (u32) _chhotfloorsmoke_entrypoint_0,
                                                (u32) _chfairgroundworker_entrypoint_0,
                                                (u32) _chfairgroundworker_entrypoint_1,
                                                (u32) _chfairgroundworker_entrypoint_2,
                                                (u32) _chfairgroundworker_entrypoint_3,
                                                (u32) _chburgerstand_entrypoint_0,
                                                (u32) _chburgerstand_entrypoint_1,
                                                (u32) _chfriesstand_entrypoint_0,
                                                (u32) _chfriesstand_entrypoint_1,
                                                (u32) _chburgerstand_entrypoint_2,
                                                (u32) _chburgerstand_entrypoint_3,
                                                (u32) _chfriesstand_entrypoint_2,
                                                (u32) _chfriesstand_entrypoint_3,
                                                (u32) _chconga_entrypoint_0,
                                                (u32) _chstarspinnerplanet_entrypoint_0,
                                                (u32) _chstarspinnerplanet_entrypoint_1,
                                                (u32) _chstarspinnerstar_entrypoint_0,
                                                (u32) _chstarspinnerctrl_entrypoint_0,
                                                (u32) _chstarspinnerctrl_entrypoint_1,
                                                (u32) _chhellterskelter_entrypoint_0,
                                                (u32) _chhellterskelter_entrypoint_2,
                                                (u32) _chhellterskelter_entrypoint_1,
                                                (u32) _chlightfader_entrypoint_0,
                                                (u32) _chcablespark_entrypoint_0,
                                                (u32) _chcablecar_entrypoint_0,
                                                (u32) _chcablecar_entrypoint_1,
                                                (u32) _chhellterskeltermouth_entrypoint_0,
                                                (u32) _chweldarbossdoors_entrypoint_0,
                                                (u32) _charea51gate_entrypoint_0,
                                                (u32) _chdiggerboss_entrypoint_0,
                                                (u32) _chghostdoor_entrypoint_0,
                                                (u32) _chweldarbossfusebox_entrypoint_0,
                                                (u32) _chsabreman_entrypoint_1,
                                                (u32) _chsabreman_entrypoint_2,
                                                (u32) _chghostdoor_entrypoint_1,
                                                (u32) _chfloater_entrypoint_0,
                                                (u32) _chpumproomgrill_entrypoint_0,
                                                (u32) _chpumproomswitch_entrypoint_0,
                                                (u32) _chbouncycastle_entrypoint_0,
                                                (u32) _chspotlight_entrypoint_0,
                                                (u32) _chboggykidshome_entrypoint_2,
                                                (u32) _chballoonburst_entrypoint_0,
                                                (u32) _chballoonburst_entrypoint_2,
                                                (u32) _chbouncycastle_entrypoint_1,
                                                (u32) _chpawnbroker_entrypoint_0,
                                                (u32) _chpawnbroker_entrypoint_1,
                                                (u32) _chpawnbroker_entrypoint_2,
                                                (u32) _chhoopswoop_entrypoint_0,
                                                (u32) _chhoopswoop_entrypoint_2,
                                                0x0,
                                                (u32) _chtiptup_entrypoint_0,
                                                (u32) _chtiptup_entrypoint_1,
                                                (u32) _chtiptup_entrypoint_2,
                                                (u32) _chonearmbandit_entrypoint_1,
                                                (u32) _chseaweedbaddy_entrypoint_0,
                                                (u32) _chseaweedbaddy_entrypoint_1,
                                                (u32) _choctopus_entrypoint_0,
                                                (u32) _chanemone_entrypoint_0,
                                                (u32) _chjollyroger_entrypoint_0,
                                                (u32) _chjollyroger_entrypoint_1,
                                                (u32) _chdinofoot_entrypoint_0,
                                                (u32) _chfreezy_entrypoint_0,
                                                (u32) _chdinoswitches_entrypoint_3,
                                                (u32) _chbigterrysbits_entrypoint_1,
                                                (u32) _chlagoonbits_entrypoint_0,
                                                (u32) _chlagoonbits_entrypoint_1,
                                                (u32) _chlagoonbits_entrypoint_2,
                                                (u32) _chlagoonbits_entrypoint_3,
                                                (u32) _chjollyroger_entrypoint_2,
                                                (u32) _chlagoonbilldrillcover_entrypoint_0,
                                                (u32) _chlagoonbits_entrypoint_4,
                                                (u32) _chlagoonbits_entrypoint_5,
                                                (u32) _chboxingglove_entrypoint_1,
                                                (u32) _chdinoboss_entrypoint_0,
                                                (u32) _chlakemonster_entrypoint_5,
                                                (u32) _chdrips_entrypoint_0,
                                                0x0,
                                                0x0,
                                                (u32) _chintroticker_entrypoint_0,
                                                0x0,
                                                (u32) _chmole_cuckoo_entrypoint_0,
                                                (u32) _chdragonbrothers_entrypoint_0,
                                                (u32) _chdragonbrothers_entrypoint_1,
                                                (u32) _chdragonbrothers_entrypoint_2,
                                                (u32) _chdragonbrothers_entrypoint_3,
                                                (u32) _chdragonbrothers_entrypoint_4,
                                                (u32) _chevilmumbo_entrypoint_0,
                                                (u32) _chevilmumbo_entrypoint_1,
                                                (u32) _chevilmumbo_entrypoint_2,
                                                (u32) _chdodgemcontrol_entrypoint_1,
                                                (u32) _chevilmumbo_entrypoint_3,
                                                (u32) _chhumba_entrypoint_1,
                                                (u32) _chtimetable_entrypoint_0,
                                                (u32) _chclockworkmouse_entrypoint_1,
                                                0x0,
                                                0x0,
                                                (u32) _chcrusher_entrypoint_4,
                                                0x0,
                                                0x0,
                                                0x0,
                                                (u32) _chhandcart_entrypoint_0,
                                                (u32) _chgruntylairexttowerwindow_entrypoint_0,
                                                (u32) _chhagstraindoor_entrypoint_0,
                                                (u32) _chhagstraindoorswitch_entrypoint_0,
                                                (u32) _chlavaentrancebridge_entrypoint_0,
                                                (u32) _chlavaentrancebridgeswitch_entrypoint_0,
                                                0x0,
                                                (u32) _chmayaentrydoor_entrypoint_0,
                                                (u32) _chlagoonentrygate_entrypoint_0,
                                                (u32) _chmineentrygrille_entrypoint_0,
                                                (u32) _chlavaentrydoor_entrypoint_0,
                                                (u32) _chcauldronentrydoor_entrypoint_1,
                                                (u32) _chterryteeth_entrypoint_0,
                                                0x0,
                                                (u32) _chphlegm_entrypoint_0,
                                                (u32) _chphlegm_entrypoint_1,
                                                (u32) _chlilterry_entrypoint_0,
                                                (u32) _chdinocoaster_entrypoint_0,
                                                (u32) _chpowerhutwitchy_entrypoint_0,
                                                (u32) _chpowerhutwitchy_entrypoint_1,
                                                (u32) _chpowerhutwitchy_entrypoint_2,
                                                (u32) _chpowerhutwitchy_entrypoint_3,
                                                (u32) _chphlegm_entrypoint_2,
                                                0x0,
                                                (u32) _chflamer_entrypoint_0,
                                                (u32) _chpoolkids_entrypoint_0,
                                                (u32) _chpoolkids_entrypoint_1,
                                                (u32) _chnicecavemenguard_entrypoint_0,
                                                (u32) _chnicecavemen_entrypoint_0,
                                                (u32) _chfactorylight_entrypoint_0,
                                                (u32) _chnicecavemen_entrypoint_3,
                                                (u32) _chbonfirecavern_entrypoint_0,
                                                (u32) _chterryegg_entrypoint_1,
                                                (u32) _charmouredcaveman_entrypoint_0,
                                                (u32) _chfirefx_entrypoint_0,
                                                0x0,
                                                (u32) _chweldarbossfusebox_entrypoint_1,
                                                (u32) _chicywind_entrypoint_0,
                                                (u32) _chintrotext_entrypoint_0,
                                                0x0,
                                                (u32) _chfactoryprop_entrypoint_0,
                                                (u32) _chfactoryprop_entrypoint_1,
                                                (u32) _chtrashcompactor_entrypoint_0,
                                                (u32) _chtrashcompactor_entrypoint_1,
                                                (u32) _chtrashcompactor_entrypoint_2,
                                                (u32) _chtrashcompactor_entrypoint_3,
                                                (u32) _chfactoryliftdoor_entrypoint_0,
                                                (u32) _chfactoryliftdoor_entrypoint_1,
                                                (u32) _chfactorycrusher_entrypoint_0,
                                                (u32) _chfactorycrusher_entrypoint_1,
                                                (u32) _chcrate_entrypoint_1,
                                                (u32) _chfactoryrobot_entrypoint_0,
                                                (u32) _chfactoryrobot_entrypoint_1,
                                                (u32) _chfactoryrobot_entrypoint_2,
                                                (u32) _chmermaidstatue_entrypoint_0,
                                                (u32) _chmermaidstatue_entrypoint_1,
                                                (u32) _chcrate_entrypoint_2,
                                                (u32) _chfactorygoblin_entrypoint_0,
                                                (u32) _chfactorytoxicpools_entrypoint_0,
                                                (u32) _chfactorytoxicpools_entrypoint_1,
                                                (u32) _chbigtopticket_entrypoint_0,
                                                (u32) _chbouncycastle_entrypoint_2,
                                                (u32) _chbouncycastle_entrypoint_3,
                                                (u32) _chlagoonpirate_entrypoint_0,
                                                (u32) _chpickups_entrypoint_1,
                                                (u32) _chpickups_entrypoint_2,
                                                (u32) _chvandoor_entrypoint_0,
                                                (u32) _chpoolkids_entrypoint_2,
                                                (u32) _chcoderoombits_entrypoint_0,
                                                (u32) _chbilldrillboulder_entrypoint_2,
                                                0x0,
                                                (u32) _chdingpot_entrypoint_0,
                                                (u32) _chpumproomswitch_entrypoint_1,
                                                (u32) _chelectricfence_entrypoint_0,
                                                (u32) _chmadamegrunty_entrypoint_1,
                                                (u32) _chfactorysmoke_entrypoint_0,
                                                (u32) _chterryegg_entrypoint_2,
                                                (u32) _chterryegg_entrypoint_3,
                                                (u32) _chdinoboss_entrypoint_1,
                                                (u32) _chappearfx_entrypoint_0,
                                                0x0,
                                                (u32) _chfootwear_entrypoint_2,
                                                (u32) _chbilldrillplate_entrypoint_0,
                                                (u32) _chbilldrillplate_entrypoint_1,
                                                (u32) _chbilldrillplate_entrypoint_2,
                                                (u32) _chrainripples_entrypoint_0,
                                                (u32) _chdumbwaiterlift_entrypoint_0,
                                                (u32) _chmrsicecube_entrypoint_0,
                                                (u32) _chmrsicecube_entrypoint_1,
                                                (u32) _chgobihailfire_entrypoint_0,
                                                (u32) _chboggykidshome_entrypoint_1,
                                                (u32) _chbigfoot_entrypoint_0,
                                                (u32) _chbiggafoot_entrypoint_0,
                                                (u32) _chmricecube_entrypoint_0,
                                                (u32) _chfactorylinkgrill_entrypoint_0,
                                                (u32) _chlavahand_entrypoint_0,
                                                (u32) _chtoxicroombits_entrypoint_0,
                                                (u32) _chtoxicroombits_entrypoint_1,
                                                (u32) _chtoxicroomprops_entrypoint_0,
                                                (u32) _chfactorysparkroom_entrypoint_1,
                                                (u32) _chfactoryempspell_entrypoint_1,
                                                (u32) _chgoldfish_entrypoint_0,
                                                (u32) _chfactorydrums_entrypoint_2,
                                                (u32) _chfactorylinkgrill_entrypoint_1,
                                                (u32) _chfactoryroofbits_entrypoint_1,
                                                (u32) _chfactoryroofbits_entrypoint_2,
                                                (u32) _chfactoryroofbits_entrypoint_3,
                                                (u32) _chfactorymagnet_entrypoint_1,
                                                (u32) _chfactorymagnet_entrypoint_2,
                                                (u32) _chfactorybtwmdoor_entrypoint_0,
                                                (u32) _chfactorymaindoor_entrypoint_0,
                                                (u32) _chfactorymaindoor_entrypoint_1,
                                                (u32) _chfactorylinkgrill_entrypoint_2,
                                                (u32) _chfactorybattery_entrypoint_2,
                                                (u32) _chbosskogsdoor_entrypoint_1,
                                                (u32) _chbosskogsdoor_entrypoint_0,
                                                (u32) _chlensflare_entrypoint_1,
                                                (u32) _chfactorytoxiccloud_entrypoint_0,
                                                (u32) _chlavahand_entrypoint_1,
                                                (u32) _chlavagargoyle_entrypoint_0,
                                                (u32) _chlavagargoyle_entrypoint_2,
                                                (u32) _chfactorytrashbelt_entrypoint_0,
                                                0x0,
                                                (u32) _chpotogoldgame_entrypoint_4,
                                                (u32) _chfactorystationdoors_entrypoint_0,
                                                (u32) _chpotogoldbits_entrypoint_0,
                                                (u32) _chpotogoldbits_entrypoint_2,
                                                (u32) _chpotogoldbits_entrypoint_3,
                                                (u32) _chfantasydrillfield_entrypoint_0,
                                                (u32) _chfantasytrashcanbits_entrypoint_1,
                                                (u32) _chfantasytrashcanbits_entrypoint_0,
                                                (u32) _chbeanstalkseed_entrypoint_0,
                                                (u32) _chrainbow_entrypoint_1,
                                                (u32) _chwaspstatue_entrypoint_1,
                                                0x0,
                                                (u32) _chwaspstatue_entrypoint_2,
                                                (u32) _chbubbleelevator_entrypoint_0,
                                                (u32) _chfactorysparkroom_entrypoint_0,
                                                (u32) _chfantasylakebits_entrypoint_2,
                                                (u32) _chfantasylakebits_entrypoint_1,
                                                (u32) _chtoxicroomprops_entrypoint_2,
                                                (u32) _chfantasysafe_entrypoint_0,
                                                (u32) _chfantasysafeswitch_entrypoint_0,
                                                0x0,
                                                (u32) _chicestationbits_entrypoint_0,
                                                (u32) _chicestationbits_entrypoint_1,
                                                (u32) _chiciclebits_entrypoint_0,
                                                (u32) _chboggykidshome_entrypoint_0,
                                                (u32) _chklungo_entrypoint_0,
                                                (u32) _chklungodoors_entrypoint_0,
                                                (u32) _chklungodoors_entrypoint_1,
                                                (u32) _chklungoforcefield_entrypoint_0,
                                                (u32) _chklungophial_entrypoint_0,
                                                (u32) _chklungophial_entrypoint_1,
                                                (u32) _chvolcanobits_entrypoint_0,
                                                (u32) _chvolcanobits_entrypoint_1,
                                                (u32) _chcrystalbaddie_entrypoint_0,
                                                (u32) _chhotwaterpoolbits_entrypoint_0,
                                                (u32) _chhotwaterpoolbits_entrypoint_1,
                                                (u32) _chvolcanobits_entrypoint_2,
                                                (u32) _chvolcanobits_entrypoint_3,
                                                (u32) _chnicecavemen_entrypoint_1,
                                                (u32) _chnicecavemen_entrypoint_2,
                                                (u32) _chdippy_entrypoint_0,
                                                (u32) _chfactoryflypad_entrypoint_0,
                                                (u32) _chfactoryflypad_entrypoint_1,
                                                (u32) _chmrsboggyhome_entrypoint_0,
                                                (u32) _chweldarbossdoors_entrypoint_1,
                                                (u32) _chfactorytoxicpools_entrypoint_2,
                                                (u32) _chdinoswitches_entrypoint_1,
                                                (u32) _chdinoswitches_entrypoint_2,
                                                (u32) _chloggo_entrypoint_0,
                                                (u32) _chloggo_entrypoint_1,
                                                0x0,
                                                (u32) _chkingjinjo_entrypoint_0,
                                                (u32) _chhotwaterpoolbits_entrypoint_2,
                                                (u32) _chhotwaterpoolbits_entrypoint_3,
                                                (u32) _chbottlesfamily_entrypoint_0,
                                                (u32) _chbottlesfamily_entrypoint_1,
                                                (u32) _chbottlesfamily_entrypoint_2,
                                                (u32) _chnutsnbolts_entrypoint_0,
                                                (u32) _chnutsnbolts_entrypoint_1,
                                                (u32) _chnutsnbolts_entrypoint_2,
                                                (u32) _chdippy_entrypoint_1,
                                                (u32) _chfactorytwinklies_entrypoint_0,
                                                (u32) _chfactorytwinklies_entrypoint_3,
                                                (u32) _chfactorytwinklies_entrypoint_4,
                                                (u32) _chfactorytwinklies_entrypoint_5,
                                                (u32) _chfactorytwinklies_entrypoint_2,
                                                (u32) _chstatueboss_entrypoint_0,
                                                (u32) _chstatuebossbits_entrypoint_0,
                                                (u32) _chstatuebossbits_entrypoint_1,
                                                (u32) _chhoopswoop_entrypoint_1,
                                                (u32) _chproplighter_entrypoint_0,
                                                (u32) _chballoonburst_entrypoint_1,
                                                (u32) _chfactorytwinklies_entrypoint_1,
                                                (u32) _chbiggafoot_entrypoint_1,
                                                (u32) _chstatuebossbits_entrypoint_3,
                                                (u32) _chstatuebossbits_entrypoint_2,
                                                (u32) _chmonsterinterior_entrypoint_0,
                                                (u32) _chmonsterinterior_entrypoint_2,
                                                (u32) _chmonsterinterior_entrypoint_3,
                                                (u32) _chmonsterinterior_entrypoint_4,
                                                (u32) _chmonsterinterior_entrypoint_1,
                                                (u32) _chalienkids_entrypoint_0,
                                                (u32) _chalienkids_entrypoint_1,
                                                (u32) _chalienkids_entrypoint_2,
                                                (u32) _chalienkids_entrypoint_3,
                                                (u32) _chaliendad_entrypoint_0,
                                                (u32) _chaliendad_entrypoint_2,
                                                (u32) _chlifeforcespell_entrypoint_0,
                                                (u32) _changlerboss_entrypoint_0,
                                                (u32) _changlerboss_entrypoint_1,
                                                (u32) _changlerbossflare_entrypoint_0,
                                                (u32) _changlerbossbubble_entrypoint_0,
                                                (u32) _chbigterrysbits_entrypoint_0,
                                                (u32) _chfireimp_entrypoint_0,
                                                (u32) _chmumboskulls_entrypoint_0,
                                                (u32) _ch2dbaddy_entrypoint_0,
                                                (u32) _chweldarboss_entrypoint_0,
                                                (u32) _chalienbeam_entrypoint_0,
                                                (u32) _chaliendad_entrypoint_1,
                                                (u32) _chweldarboss_entrypoint_1,
                                                (u32) _chbigterrysbits_entrypoint_2,
                                                (u32) _chweldarbossfusebox_entrypoint_2,
                                                (u32) _chflowerbaddie_entrypoint_0,
                                                (u32) _changlerbossdoor_entrypoint_0,
                                                (u32) _chboilerbossdoor_entrypoint_0,
                                                (u32) _chinflatablebossdoor_entrypoint_0,
                                                (u32) _chhotwatersteam_entrypoint_0,
                                                (u32) _chcastleshockpadswitch_entrypoint_0,
                                                (u32) _chfootwear_entrypoint_4,
                                                (u32) _chtalontorpedoboulder_entrypoint_0,
                                                (u32) _chexplodingchainlinks_entrypoint_0,
                                                (u32) _chfactoryroofbits_entrypoint_4,
                                                (u32) _chtrashcangame_entrypoint_0,
                                                (u32) _chtrashcangame_entrypoint_2,
                                                (u32) _chfantasyathlete_entrypoint_0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                (u32) _chtoxicroomprops_entrypoint_1,
                                                (u32) _chfantasycannon_entrypoint_0,
                                                (u32) _chfantasycannon_entrypoint_1,
                                                (u32) _chfantasyonion_entrypoint_0,
                                                (u32) _chbeanstalkseed_entrypoint_1,
                                                (u32) _chpickups_entrypoint_3,
                                                (u32) _chfantasyeyeball_entrypoint_0,
                                                (u32) _chfantasyeyeball_entrypoint_1,
                                                (u32) _choildrill_entrypoint_1,
                                                (u32) _choildrill_entrypoint_2,
                                                (u32) _chfloaty_entrypoint_1,
                                                0x0,
                                                (u32) _chLagoonInnBlockedWall_entrypoint_0,
                                                (u32) _chwitchyentrygates_entrypoint_0,
                                                0x0,
                                                (u32) _chfactoryentrydoors_entrypoint_0,
                                                0x0,
                                                (u32) _chcauldronenergybars_entrypoint_0,
                                                (u32) _chjinjovillagecamera1_entrypoint_0,
                                                (u32) _chjinjo_entrypoint_6,
                                                0x0,
                                                (u32) _chLagoonInnBlockedWall_entrypoint_1,
                                                (u32) _chlavaarchgrill3switches_entrypoint_0,
                                                (u32) _chlavaarchgrill3switches_entrypoint_1,
                                                (u32) _chlavaarchgrill3switches_entrypoint_2,
                                                (u32) _chmumboskullfakearchpanellava_entrypoint_1,
                                                (u32) _chlagoonlockerdoorhits_entrypoint_0,
                                                0x0,
                                                0x0,
                                                (u32) _chTalTorpWall_entrypoint_0,
                                                (u32) _chufoextdoor_entrypoint_0,
                                                (u32) _chdinotraindoor_entrypoint_0,
                                                (u32) _chdinotraindoorswitch_entrypoint_0,
                                                (u32) _chminegrill2switches_entrypoint_0,
                                                (u32) _chminegrill2switches_entrypoint_1,
                                                (u32) _chcauldronentrydoor_entrypoint_2,
                                                (u32) _chdrawbridgeswitches_entrypoint_0,
                                                (u32) _chdrawbridgeswitches_entrypoint_1,
                                                (u32) _chdinoroargrill_entrypoint_0,
                                                0x0,
                                                (u32) _chlavaexplodbuild_entrypoint_0,
                                                (u32) _chboggy_entrypoint_0,
                                                (u32) _chnests_entrypoint_12,
                                                (u32) _chgameselect_entrypoint_0,
                                                (u32) _chgameselect_entrypoint_2,
                                                (u32) _chgameselect_entrypoint_3,
                                                (u32) _chgameselect_entrypoint_4,
                                                (u32) _chgameselect_entrypoint_1,
                                                (u32) _chgameselect_entrypoint_5,
                                                (u32) _chminisubgame_entrypoint_0,
                                                (u32) _chminisubgame_entrypoint_1,
                                                (u32) _chjiggypost_entrypoint_0,
                                                (u32) _chhoneyb_entrypoint_0,
                                                (u32) _chmasterjiggy_entrypoint_1,
                                                (u32) _chjiggytemple_entrypoint_2,
                                                (u32) _chjiggybeam_entrypoint_0,
                                                0x0,
                                                (u32) _chattract_entrypoint_0,
                                                (u32) _chgameselect_entrypoint_6,
                                                (u32) _chpickups_entrypoint_10,
                                                (u32) _chhoneyb_entrypoint_1,
                                                (u32) _chgameselect_entrypoint_7,
                                                (u32) _chboggyfish_entrypoint_0,
                                                0x0,
                                                (u32) _chbottlesdead_entrypoint_0,
                                                (u32) _chjrinnlight_entrypoint_0,
                                                0x0,
                                                (u32) _chfoodwarn_entrypoint_0,
                                                (u32) _chperspexbox_entrypoint_0,
                                                (u32) _chperspexboxswitch_entrypoint_0,
                                                (u32) _chminegrilldoor_entrypoint_0,
                                                0x0,
                                                (u32) _chwitchytents_entrypoint_0,
                                                (u32) _chwitchytents_entrypoint_1,
                                                (u32) _chfantasybounce_entrypoint_0,
                                                (u32) _chfantasybounce_entrypoint_1,
                                                0x0,
                                                (u32) _chgoldsnakehead_entrypoint_2,
                                                0x0,
                                                0x0,
                                                0x0,
                                                (u32) _chquizexitdoor_entrypoint_0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                (u32) _chsparkle_entrypoint_0,
                                                (u32) _chpickups_entrypoint_7,
                                                (u32) _chmumbohealspell_entrypoint_0,
                                                (u32) _chfactoryroofbits_entrypoint_5,
                                                (u32) _chfactorymaindoor_entrypoint_2,
                                                (u32) _chfactoryentrydoors_entrypoint_1,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                (u32) _chpickups_entrypoint_4,
                                                (u32) _chpickups_entrypoint_5,
                                                (u32) _chpickups_entrypoint_6,
                                                (u32) _chdoubloon_entrypoint_2,
                                                0x0,
                                                (u32) _chwitchyshockpadswitch_entrypoint_0,
                                                0x0,
                                                (u32) _chsquits_entrypoint_0,
                                                (u32) _chbottlesplantgrill_entrypoint_0,
                                                (u32) _chkingjinjobits_entrypoint_0,
                                                (u32) _chklungospiral_entrypoint_0,
                                                (u32) _chfactoryposter_entrypoint_0,
                                                0x0,
                                                (u32) _chjigsawcollect_entrypoint_0,
                                                0x0,
                                                (u32) _chdiggerbossdoor_entrypoint_0,
                                                (u32) _chgruntyfireball_entrypoint_0,
                                                (u32) _chdiggerbossshell_entrypoint_0,
                                                (u32) _chdiggerbossshell_entrypoint_1,
                                                (u32) _chdiggerbossbattery_entrypoint_0,
                                                (u32) _chgruntyfireballbig_entrypoint_0,
                                                (u32) _chdiggerbossinterior_entrypoint_0,
                                                (u32) _chbottlesparty_entrypoint_0,
                                                (u32) _chbottlesparty_entrypoint_1,
                                                (u32) _chspiralgrill_entrypoint_0,
                                                0x0,
                                                (u32) _chfireicestorm_entrypoint_0,
                                                (u32) _chfireicestorm_entrypoint_1,
                                                (u32) _chfactoryprop_entrypoint_2,
                                                (u32) _chdiggerbossdeflect_entrypoint_0,
                                                (u32) _chgobihailfire_entrypoint_1,
                                                (u32) _chchompaslunch_entrypoint_0,
                                                (u32) _chlavafall_entrypoint_0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                (u32) _chlighthalo_entrypoint_0,
                                                (u32) _chcrashmat_entrypoint_0,
                                                (u32) _chjellycastle_entrypoint_0,
                                                (u32) _chfantasysafe_entrypoint_1,
                                                (u32) _chtrashcangame_entrypoint_3,
                                                (u32) _chfactorymagnet_entrypoint_3,
                                                0x0,
                                                0x0,
                                                (u32) _chicekeydoor_entrypoint_0,
                                                (u32) _chicekey_entrypoint_0,
                                                (u32) _chheggy_entrypoint_0,
                                                (u32) _chpickups_entrypoint_8,
                                                (u32) _chpickups_entrypoint_9,
                                                (u32) _chsecreteggs_entrypoint_0,
                                                (u32) _chplatuegrill_entrypoint_0,
                                                (u32) _chplatuegrill_entrypoint_1,
                                                (u32) _chbkcart_entrypoint_0,
                                                (u32) _chworlddoors_entrypoint_0,
                                                (u32) _chtrashcangame_entrypoint_1,
                                                0x0,
                                                (u32) _chhandcart_entrypoint_2,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                (u32) _chglowbo_entrypoint_2,
                                                (u32) _chjigsaw_entrypoint_1,
                                                0x0,
                                                0x0,
                                                0x0,
                                                (u32) _chquiz_entrypoint_4,
                                                (u32) _chquiz_entrypoint_1,
                                                (u32) _chheggy_entrypoint_1,
                                                (u32) _chquiz_entrypoint_2,
                                                (u32) _chquiz_entrypoint_0,
                                                (u32) _chdinofamilysick_entrypoint_2,
                                                (u32) _chquiz_entrypoint_3,
                                                (u32) _chfactorymagnet_entrypoint_4,
                                                (u32) _chboggy_entrypoint_1,
                                                (u32) _chmusicmenu_entrypoint_1,
                                                (u32) _chbobpanel_entrypoint_0,
                                                (u32) _chtrashcangame_entrypoint_4,
                                                (u32) _chmusicmenu_entrypoint_2,
                                                (u32) _chdeflect_entrypoint_0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                (u32) _chjadestatue_entrypoint_1,
                                                (u32) _chdrawbridgeswitches_entrypoint_2,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0};
