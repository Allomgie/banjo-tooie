// Rare's modified libultra sound player (n_alSndPlayer): sound states, event handling,
// chained playback by sound id, group volumes, and n_alInit/n_alClose.
#include "common.h"
#ifndef M2C_MACROS_H
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr) ((s8 *) (expr) + (offset)))
#endif

// TU-NOTE: sound player (n_alSndPlayer). D_800411D0/D_800411D4 = head/tail of the playing list,
// D_800411D8 = free list, D_800411DC = player state (D_8007E9C0), D_800411E0 = active voice count,
// D_8007EA24 = per-channel-group volume table.

typedef struct {
    s16 type;
    u8 pad2[0xE];
} TTEvtC;
typedef struct TTSndI_s {
    u8 pad0[0x48];
} TTSndI;
typedef struct {
    s32 unk0;
    void *self;
    void *handler;
    u8 padC[8];
    u8 evtq;
    u8 pad15[0x13];
    TTEvtC cur_evt;
    u8 pad38[4];
    s32 last_snd;
    TTSndI *snds;
    void *max_voices;
    s32 tick_us;
    s32 next_delay;
} TTCSMgr;
typedef struct {
    u32 snd_count;
    u32 evt_count;
    void *max_voices;
    void *heap;
    u16 group_count;
} TTCfgI;
extern TTSndI *D_800411D8;
extern void *func_80020EE4(s32, s32, void *, s32, s32);
extern void func_800263C0(void *, void *, s32);
extern void func_80020E40(void *, void *);
extern void func_800267F0();
extern s32 func_8002645C(void *, TTEvtC *);
typedef struct {
    u8 pad0[0x14];
    u8 evtq;
    u8 pad15[0x13];
    TTEvtC cur_evt;
    u8 pad38[0x10];
    s32 tick_us;
    s32 next_delay;
    s32 time;
} TTCSPmp;
extern u8 *D_800411D4;
extern u8 *D_800411DC;
extern s16 D_800411E0;
extern u8 *D_800411F4;
extern s16 *D_8007EA24;
void func_80026CB0(u8 *, s32, f32, s32, s32, s32, s32, f32, s32, s32);
void func_80026E90(u8 *, f32);
typedef struct {
    s16 unk0;
    s16 unk2;
    s8 unk4;
} VConfig;
typedef struct {
    u16 unk0;
    u8 pad2[2];
    void *unk4;
    u32 unk8;
    u8 padC[4];
} Evt;
typedef struct {
    s16 type;
    u8 pad2[2];
    void *p;
    s32 data;
    u8 padC[4];
} TTEvtK2;
typedef struct TTSnd_s {
    struct TTSnd_s *next;
    u8 pad4[4];
    void *def;
    u8 padC[0x38];
    u8 flags;
} TTSnd;
typedef struct {
    u8 pad0[0x14];
    u8 evtq;
} TTSMgr;
extern TTSnd *D_800411D0;
extern void func_80026500(void *, TTEvtK2 *, s32, s32);
typedef struct {
    u8 pad0[0xC];
    u8 unkC;
} TTSndB_800200B8;
extern void func_80026FF0(void *);
extern void func_80027090(void *);
typedef struct {
    u8 pad0[0x8];
    void *unk8;
    u8 padC[0x20];
    f32 unk2C;
} TTSndP;
typedef struct {
    u8 pad0[0x15];
    s8 unk15;
} TTWaveP;
extern f32 func_80027170(s32);
typedef struct TTLinkS_s {
    struct TTLinkS_s *next;
    struct TTLinkS_s *prev;
} TTLinkS;
typedef struct {
    u16 type;
    u8 pad2[2];
    void *p;
} TTEvtF;
typedef struct TTItemS_s {
    struct TTItemS_s *next;
    u8 pad4[4];
    s32 delay;
    TTEvtF evt;
} TTItemS;
typedef struct {
    TTLinkS freeList;
    TTItemS *pending;
} TTEvtqS;
extern void func_80020E74(void *);
typedef struct TTSndL_s {
    struct TTSndL_s *next;
    struct TTSndL_s *prev;
} TTSndL;
typedef struct {
    u8 pad0[3];
    u8 unk3;
    u8 unk4;
    s8 unk5;
} TTPrmSub;
typedef struct {
    u8 pad0[4];
    s32 unk4;
    u8 pad8[8];
    TTPrmSub unk10;
} TTPrmA;
typedef struct TTSndA_s {
    struct TTSndA_s *next;
    struct TTSndA_s *prev;
    void *def;
    u8 padC[0x1C];
    f32 base_pitch;
    f32 pitch;
    s32 owner;
    s32 retries;
    s16 volume;
    u8 pad3A[6];
    u8 unk_40;
    u8 pan;
    u8 fx_mix;
    u8 pad43[1];
    u8 flags;
    u8 state;
} TTSndA;
extern void func_800E9070(void *, s32);
typedef struct TTSndU_s {
    struct TTSndU_s *next;
    struct TTSndU_s *prev;
    void *def;
    u8 padC[0x24];
    struct TTSndU_s **owner;
    u8 pad34[0x10];
    u8 flags;
    u8 state;
} TTSndU;
extern void func_800E90A4(void *, s32);
typedef struct {
    s16 type;
    u8 pad2[2];
    void *p;
    u8 pad8[8];
} TTEvtK1;
typedef struct {
    u8 next_id_lo;
    u8 pad1[1];
    u8 unk2;  // flags; bits 6-7 extend the next id
} TTPrmSubB;
typedef struct {
    u8 pad0[0x11];
    u8 duration;  // ticks of 33333 us
} TTPrmB2;
typedef struct TTSndB_s {
    struct TTSndB_s *next;
    u8 pad4[0x28];
    f32 pitch;
    void *owner;
    u8 pad34[4];
    s16 volume;
    u8 pad3A[7];
    u8 pan;
    u8 fx_mix;
    u8 unk_43;
    u8 flags;
} TTSndB_80020790;
typedef struct {
    u8 pad0[0x14];
    u8 evtq;
    u8 pad15[0x27];
    TTSndB_80020790 *unk3C;
} TTSMgrB;
extern void *func_800E9320(s32, s32);
typedef struct {
    u8 pad0[0x12];
    u8 unk12;
} TTWaveC;
extern void *D_800411F0;
extern void func_80020F70(void *);
extern void func_80027200(void);

s32 func_8001ED68(TTCSPmp *player);
void func_8001EE34(u16 *evt);
void func_800200B8(TTSnd *snd);
void func_80020128(TTSndP *snd);
void func_800201A4(TTEvtqS *evtq, void *target, u16 mask);
u16 func_80020298(u16 *out_free, u16 *out_playing);
void func_800205D0(TTSndU *snd);
TTSndB_80020790 *func_80020790(s16 id, u16 vol, u8 pan, f32 pitch_mul, u8 fx_mix, u8 unk_0,
                               TTSndB_80020790 **out);

// Sound player: init, event state machine, sound state alloc/free, play/stop, group volumes.
// Sets up the sound-state pool, the event queue and the group volume table (default 0x7FFF).
void func_8001EB10(TTCfgI *cfg)
{
    u32 i;
    void *mem;
    TTEvtC evt;
    TTSndI *snd;

    ((TTCSMgr *) D_800411DC)->max_voices = cfg->max_voices;
    ((TTCSMgr *) D_800411DC)->last_snd = 0;
    ((TTCSMgr *) D_800411DC)->tick_us = 0x3E80;

    mem = func_80020EE4(0, 0, cfg->heap, 1, cfg->snd_count * 0x48);
    ((TTCSMgr *) D_800411DC)->snds = mem;

    mem = func_80020EE4(0, 0, cfg->heap, 1, cfg->evt_count * 0x1C);
    func_800263C0(&((TTCSMgr *) D_800411DC)->evtq, mem, cfg->evt_count);

    D_800411D8 = ((TTCSMgr *) D_800411DC)->snds;

    for (i = 1; i < cfg->snd_count; i++) {
        snd = ((TTCSMgr *) D_800411DC)->snds;
        func_80020E40(&snd[i], &snd[i] - 1);
    }

    D_8007EA24 = func_80020EE4(0, 0, cfg->heap, 2, cfg->group_count);

    for (i = 0; i < cfg->group_count; i++) {
        ((u16 *) D_8007EA24)[i] = 0x7FFF;
    }

    ((TTCSMgr *) D_800411DC)->unk0 = 0;
    ((TTCSMgr *) D_800411DC)->handler = func_8001ED68;
    ((TTCSMgr *) D_800411DC)->self = (TTCSMgr *) D_800411DC;

    func_800267F0((TTCSMgr *) D_800411DC);

    evt.type = 0x20;
    func_80026500(&((TTCSMgr *) D_800411DC)->evtq, &evt, ((TTCSMgr *) D_800411DC)->tick_us, 1);
    ((TTCSMgr *) D_800411DC)->next_delay =
        func_8002645C(&((TTCSMgr *) D_800411DC)->evtq, &((TTCSMgr *) D_800411DC)->cur_evt);
}

// Player handler: runs queued events until the next one has a non-zero delay.
s32 func_8001ED68(TTCSPmp *player)
{
    TTCSPmp *p = player;
    TTEvtC evt;

    do {
        switch (p->cur_evt.type) {
            // timer tick
            case 0x20:
                evt.type = 0x20;
                func_80026500(&p->evtq, &evt, p->tick_us, 1);
                break;
            default:
                func_8001EE34(&p->cur_evt);
                break;
        }

        p->next_delay = func_8002645C(&p->evtq, &p->cur_evt);
    } while (p->next_delay == 0);

    p->time = p->time + p->next_delay;
    return p->next_delay;
}

// Handles one sound event (play, stop, pan, volume, pitch, fx mix) and follows chained sounds.
void func_8001EE34(u16 *evt)
{
    VConfig config;
    u8 *def;
    u8 *def_sub;
    u8 pan;
    Evt new_evt;
    Evt chain_evt;
    s32 ticks;
    s32 fxmix;
    s32 vol;
    s32 pan_raw;
    s32 voices_full;
    s32 stop_bits;
    s32 is_last;
    s32 voice_ok;
    u8 *snd;
    u8 *next;
    s16 n_free;
    s16 n_playing;
    u8 *victim;
    Evt steal_evt;
    is_last = 1;
    voice_ok = 0;
    snd = 0;
    next = 0;
    do {
        if (next != 0) {
            chain_evt.unk4 = snd;
            chain_evt.unk0 = *(u16 *) ((s8 *) evt + 0);
            chain_evt.unk8 = *(u32 *) ((s8 *) evt + 8);
            evt = (u16 *) &chain_evt;
        }
        snd = *(u8 **) ((s8 *) evt + 4);
        def = *(u8 **) ((s8 *) snd + 8);
        if (def == 0) {
            func_80020298(&n_free, &n_playing);
            return;
        }
        def_sub = def + 0x10;
        next = *(u8 **) ((s8 *) snd + 0);
        switch ((s32) *(u16 *) ((s8 *) evt + 0)) {
            // play
            case 0x1:
                if ((*(u8 *) ((s8 *) snd + 0x45) != 5) && (*(u8 *) ((s8 *) snd + 0x45) != 4)) {
                    return;
                }
                config.unk2 = (s16) *(u8 *) (snd + 0x43);
                config.unk0 = (s16) *(u8 *) ((s8 *) snd + 0x40);
                config.unk4 = 0;
                voices_full = D_800411E0 >= *(s32 *) ((s8 *) D_800411DC + 0x44);
                if ((voices_full == 0) || (*(u8 *) ((s8 *) snd + 0x44) & 0x10)) {
                    voice_ok = func_800268D0(snd + 0xC, &config);
                }
                if (voice_ok == 0) {
                    if ((*(u8 *) ((s8 *) snd + 0x44) & 0x12) ||
                        (*(s32 *) ((s8 *) snd + 0x34) > 0)) {
                        *(u8 *) ((s8 *) snd + 0x45) = 4U;
                        *(s32 *) ((s8 *) snd + 0x34) = (s32) (*(s32 *) ((s8 *) snd + 0x34) - 1);
                        func_80026500(D_800411DC + 0x14, evt, 0x8235, 0);
                    } else if (voices_full != 0) {
                        victim = D_800411D4;
                        do {
                            if ((!(*(u8 *) ((s8 *) victim + 0x44) & 0x12) &&
                                 (*(u8 *) ((s8 *) victim + 0x44) & 4)) &&
                                (*(u8 *) ((s8 *) victim + 0x45) != 3)) {
                                voices_full = 0;
                                steal_evt.unk0 = 0x80;
                                steal_evt.unk4 = victim;
                                *(u8 *) ((s8 *) victim + 0x45) = 3U;
                                func_80026500(D_800411DC + 0x14, &steal_evt, 0x3E8, 0);
                                func_80026BE0(victim + 0xC, 0, 0x3E8);
                            }
                            victim = *(u8 **) ((s8 *) victim + 4);
                        } while ((voices_full != 0) && (victim != 0));
                        if (voices_full == 0) {
                            *(s32 *) ((s8 *) snd + 0x34) = 2;
                            func_80026500(D_800411DC + 0x14, evt, 0x3E9, 0);
                        } else {
                            func_800200B8(snd);
                        }
                    } else {
                        func_800200B8(snd);
                    }
                    return;
                }
                *(u8 *) ((s8 *) snd + 0x44) = (u8) (*(u8 *) ((s8 *) snd + 0x44) | 4);
                *(s16 *) ((s8 *) snd + 0x3A) = (s16) *(u8 *) ((s8 *) def + 0xC);
                *(u8 *) ((s8 *) snd + 0x43) = (u8) config.unk2;
                ticks = (s32) (((f32) *(s32 *) ((s8 *) def + 0) / *(f32 *) ((s8 *) snd + 0x2C)) /
                              *(f32 *) ((s8 *) snd + 0x28));
                *(s32 *) ((s8 *) snd + 0x3C) = (s32) (*(s32 *) ((s8 *) D_800411DC + 0x50) + ticks);
                if (((s32) ((((*(s16 *) ((s8 *) snd + 0x3A) * *(s16 *) ((s8 *) snd + 0x38)) *
                              *(u8 *) ((s8 *) def + 0xD5)) /
                             16129) *
                            D_8007EA24[*(u8 *) ((s8 *) def_sub + 2) & 0x1F]) /
                     32767) <= 0) {
                    vol = 0;
                } else {
                    vol =
                        ((s32) ((((*(s16 *) ((s8 *) snd + 0x3A) * *(s16 *) ((s8 *) snd + 0x38)) *
                                  *(u8 *) ((s8 *) def + 0xD5)) /
                                 16129) *
                                D_8007EA24[*(u8 *) ((s8 *) def_sub + 2) & 0x1F]) /
                         32767) -
                        1;
                }
                pan_raw = (*(u8 *) ((s8 *) def + 0xD4) + *(u8 *) ((s8 *) snd + 0x41)) - 0x40;
                pan = (u8) ((((pan_raw > 0) ? pan_raw : 0) < 0x7F) ? ((pan_raw > 0) ? pan_raw : 0) : 0x7F);
                fxmix =
                    ((*(u8 *) ((s8 *) def_sub + 3) & 0xF) * 8) + (*(u8 *) ((s8 *) snd + 0x42) & 0x7F);
                fxmix = (127 < ((0 > fxmix) ? 0 : fxmix)) ? 127 : ((0 > fxmix) ? 0 : fxmix);
                fxmix |= *(u8 *) ((s8 *) snd + 0x42) & 0x80;
                func_80026CB0(snd + 0xC, def + 0x18,
                              *(f32 *) ((s8 *) snd + 0x28) * *(f32 *) ((s8 *) snd + 0x2C), vol,
                              (s32) pan, fxmix, 0, 0.0f, 0, ticks);
                *(u8 *) ((s8 *) snd + 0x45) = 1U;
                D_800411E0 += 1;
                if (!(*(u8 *) ((s8 *) snd + 0x44) & 2)) {
                    if (ticks == 0) {
                        *(s16 *) ((s8 *) snd + 0x3A) = (s16) *(u8 *) ((s8 *) def + 0xD);
                        if (((s32) ((((*(s16 *) ((s8 *) snd + 0x3A) *
                                       *(s16 *) ((s8 *) snd + 0x38)) *
                                      *(u8 *) ((s8 *) def + 0xD5)) /
                                     16129) *
                                    D_8007EA24[*(u8 *) ((s8 *) def_sub + 2) & 0x1F]) /
                             32767) <= 0) {
                            vol = 0;
                        } else {
                            vol = ((s32) ((((*(s16 *) ((s8 *) snd + 0x3A) *
                                              *(s16 *) ((s8 *) snd + 0x38)) *
                                             *(u8 *) ((s8 *) def + 0xD5)) /
                                            16129) *
                                           D_8007EA24[*(u8 *) ((s8 *) def_sub + 2) & 0x1F]) /
                                    32767) -
                                   1;
                        }
                        ticks = (s32) (((f32) *(s32 *) ((s8 *) def + 4) /
                                       *(f32 *) ((s8 *) snd + 0x28)) /
                                      *(f32 *) ((s8 *) snd + 0x2C));
                        *(s32 *) ((s8 *) snd + 0x3C) =
                            (s32) (*(s32 *) ((s8 *) D_800411DC + 0x50) + ticks);
                        func_80026BE0(snd + 0xC, vol, ticks);
                        new_evt.unk0 = 2;
                        new_evt.unk4 = snd;
                        func_80026500(D_800411DC + 0x14, &new_evt, ticks, 0);
                        if (*(u8 *) ((s8 *) snd + 0x44) & 0x20) {
                            func_80020128(snd);
                        }
                    } else {
                        new_evt.unk0 = 0x40;
                        new_evt.unk4 = snd;
                        ticks = (s32) (((f32) *(s32 *) ((s8 *) def + 0) /
                                       *(f32 *) ((s8 *) snd + 0x2C)) /
                                      *(f32 *) ((s8 *) snd + 0x28));
                        func_80026500(D_800411DC + 0x14, &new_evt, ticks, 0);
                    }
                }
                break;

            // stop / release
            case 0x2:

            case 0x400:

            case 0x1000:
                if ((*(u16 *) ((s8 *) evt + 0) != 0x1000) || (*(u8 *) ((s8 *) snd + 0x44) & 2)) {
                    switch (*(u8 *) ((s8 *) snd + 0x45)) {
                        case 1:
                            func_800201A4(D_800411DC + 0x14, snd, 0x40);
                            ticks = (s32) (((f32) *(s32 *) ((s8 *) def + 8) /
                                           *(f32 *) ((s8 *) snd + 0x28)) /
                                          *(f32 *) ((s8 *) snd + 0x2C));
                            func_80026BE0(snd + 0xC, 0, ticks);
                            if (ticks != 0) {
                                new_evt.unk0 = 0x80;
                                new_evt.unk4 = snd;
                                func_80026500(D_800411DC + 0x14, &new_evt, ticks, 0);
                                *(u8 *) ((s8 *) snd + 0x45) = 2U;
                            } else {
                                func_800200B8(snd);
                            }
                            break;

                        case 4:

                        case 5:
                            func_800200B8(snd);
                            break;

                        default:
                            break;
                    }

                    if (*(u16 *) ((s8 *) evt + 0) == 2) {
                        *(u16 *) ((s8 *) evt + 0) = 0x1000;
                    }
                }
                break;

            // pan
            case 0x4:
                *(u8 *) ((s8 *) snd + 0x41) = (u8) *(u32 *) ((s8 *) evt + 8);
                if (*(u8 *) ((s8 *) snd + 0x45) == 1) {
                    pan_raw = (*(u8 *) ((s8 *) def + 0xD4) + *(u8 *) ((s8 *) snd + 0x41)) - 0x40;
                    pan = (u8) ((((pan_raw > 0) ? pan_raw : 0) < 0x7F) ? ((pan_raw > 0) ? pan_raw : 0) : 0x7F);
                    func_80026DE0(snd + 0xC, pan);
                }
                break;

            // pitch
            case 0x10:
                *(f32 *) ((s8 *) snd + 0x2C) = *(f32 *) ((s8 *) evt + 8);
                if (*(u8 *) ((s8 *) snd + 0x45) == 1) {
                    func_80026E90(snd + 0xC,
                                  *(f32 *) ((s8 *) snd + 0x28) * *(f32 *) ((s8 *) snd + 0x2C));
                    if (*(u8 *) ((s8 *) snd + 0x44) & 0x20) {
                        func_80020128(snd);
                    }
                }
                break;

            // fx mix
            case 0x100:
                *(u8 *) ((s8 *) snd + 0x42) = (u8) *(u32 *) ((s8 *) evt + 8);
                if (*(u8 *) ((s8 *) snd + 0x45) == 1) {
                    fxmix = ((*(u8 *) ((s8 *) def_sub + 3) & 0xF) * 8) +
                           (*(u8 *) ((s8 *) snd + 0x42) & 0x7F);
                    fxmix = (127 < ((0 > fxmix) ? 0 : fxmix)) ? 127 : ((0 > fxmix) ? 0 : fxmix);
                    fxmix |= *(u8 *) ((s8 *) snd + 0x42) & 0x80;
                    func_80026F40(snd + 0xC, fxmix);
                }
                break;

            case 0x2000:
                *(u8 *) ((s8 *) snd + 0x43) = (u8) *(u32 *) ((s8 *) evt + 8);
                if ((s32) *(u8 *) ((s8 *) snd + 0x43) >= *(s32 *) ((s8 *) D_800411F4 + 0x3C)) {
                    *(u8 *) ((s8 *) snd + 0x43) = 0U;
                }
                if (*(u8 *) ((s8 *) snd + 0x45) == 1) {
                    *(s16 *) ((s8 *) snd + 0x24) = (s16) *(u8 *) ((s8 *) snd + 0x43);
                }
                break;

            // volume
            case 0x8:
                *(s16 *) ((s8 *) snd + 0x38) = (s16) *(u32 *) ((s8 *) evt + 8);
                if (*(u8 *) ((s8 *) snd + 0x45) == 1) {
                    if (((s32) ((((*(s16 *) ((s8 *) snd + 0x3A) * *(s16 *) ((s8 *) snd + 0x38)) *
                                  *(u8 *) ((s8 *) def + 0xD5)) /
                                 16129) *
                                D_8007EA24[*(u8 *) ((s8 *) def_sub + 2) & 0x1F]) /
                         32767) <= 0) {
                        vol = 0;
                    } else {
                        vol = ((s32) ((((*(s16 *) ((s8 *) snd + 0x3A) *
                                          *(s16 *) ((s8 *) snd + 0x38)) *
                                         *(u8 *) ((s8 *) def + 0xD5)) /
                                        16129) *
                                       D_8007EA24[*(u8 *) ((s8 *) def_sub + 2) & 0x1F]) /
                                32767) -
                               1;
                    }
                    func_80026BE0(snd + 0xC, vol,
                                  (0x3E8 > (*(s32 *) ((s8 *) snd + 0x3C) -
                                            *(s32 *) ((s8 *) D_800411DC + 0x50)))
                                      ? 0x3E8
                                      : (*(s32 *) ((s8 *) snd + 0x3C) -
                                         *(s32 *) ((s8 *) D_800411DC + 0x50)));
                }
                break;

            // group volume update
            case 0x800:
                if (*(u8 *) ((s8 *) snd + 0x45) == 1) {
                    ticks =
                        (s32) (((f32) *(s32 *) ((s8 *) def + 8) / *(f32 *) ((s8 *) snd + 0x28)) /
                               *(f32 *) ((s8 *) snd + 0x2C));
                    if (((s32) ((((*(s16 *) ((s8 *) snd + 0x3A) * *(s16 *) ((s8 *) snd + 0x38)) *
                                  *(u8 *) ((s8 *) def + 0xD5)) /
                                 16129) *
                                D_8007EA24[*(u8 *) ((s8 *) def_sub + 2) & 0x1F]) /
                         32767) <= 0) {
                        vol = 0;
                    } else {
                        vol = ((s32) ((((*(s16 *) ((s8 *) snd + 0x3A) *
                                          *(s16 *) ((s8 *) snd + 0x38)) *
                                         *(u8 *) ((s8 *) def + 0xD5)) /
                                        16129) *
                                       D_8007EA24[*(u8 *) ((s8 *) def_sub + 2) & 0x1F]) /
                                32767) -
                               1;
                    }
                    func_80026BE0(snd + 0xC, vol, ticks);
                }
                break;

            case 0x40:
                if (!(*(u8 *) ((s8 *) snd + 0x44) & 2)) {
                    *(s16 *) ((s8 *) snd + 0x3A) = (s16) *(u8 *) ((s8 *) def + 0xD);
                    if (((s32) ((((*(s16 *) ((s8 *) snd + 0x3A) * *(s16 *) ((s8 *) snd + 0x38)) *
                                  *(u8 *) ((s8 *) def + 0xD5)) /
                                 16129) *
                                D_8007EA24[*(u8 *) ((s8 *) def_sub + 2) & 0x1F]) /
                         32767) <= 0) {
                        vol = 0;
                    } else {
                        vol = ((s32) ((((*(s16 *) ((s8 *) snd + 0x3A) *
                                          *(s16 *) ((s8 *) snd + 0x38)) *
                                         *(u8 *) ((s8 *) def + 0xD5)) /
                                        16129) *
                                       D_8007EA24[*(u8 *) ((s8 *) def_sub + 2) & 0x1F]) /
                                32767) -
                               1;
                    }
                    ticks =
                        (s32) (((f32) *(s32 *) ((s8 *) def + 4) / *(f32 *) ((s8 *) snd + 0x28)) /
                               *(f32 *) ((s8 *) snd + 0x2C));
                    *(s32 *) ((s8 *) snd + 0x3C) =
                        (s32) (*(s32 *) ((s8 *) D_800411DC + 0x50) + ticks);
                    func_80026BE0(snd + 0xC, vol, ticks);
                    new_evt.unk0 = 2;
                    new_evt.unk4 = snd;
                    func_80026500(D_800411DC + 0x14, &new_evt, ticks, 0);
                    if (*(u8 *) ((s8 *) snd + 0x44) & 0x20) {
                        func_80020128(snd);
                    }
                }
                break;

            // free the sound
            case 0x80:
                func_800200B8(snd);
                break;

            // start next sound of the chain
            case 0x200:
                if (*(u8 *) ((s8 *) snd + 0x44) & 0x10) {
                    func_80020790(*(u32 *) ((s8 *) evt + 8), *(s16 *) ((s8 *) snd + 0x38),
                                  *(u8 *) ((s8 *) snd + 0x41), *(f32 *) ((s8 *) snd + 0x2C),
                                  (s32) *(u8 *) ((s8 *) snd + 0x42),
                                  (s32) *(u8 *) ((s8 *) snd + 0x43),
                                  *(s32 *) ((s8 *) snd + 0x30));
                }
                break;
            default:
                break;
        }

        stop_bits = *(u16 *) ((s8 *) evt + 0) & 0x2D1;
        if (((snd = next) != 0) && (stop_bits == 0)) {
            is_last = *(u8 *) ((s8 *) snd + 0x44) & 1;
        }
    } while (((is_last == 0) && (snd != 0)) && (stop_bits == 0));
}

// Stops the voice if active, frees the sound state and drops its queued events.
void func_800200B8(TTSnd *snd)
{
    if (snd->flags & 4) {
        func_80026FF0(&((TTSndB_800200B8 *) snd)->unkC);
        func_80027090(&((TTSndB_800200B8 *) snd)->unkC);
    }
    func_800205D0(snd);
    func_800201A4(&((TTSMgr *) D_800411DC)->evtq, snd, 0xFFFF);
}

// Posts a pitch event: wave base pitch times the sound's pitch.
void func_80020128(TTSndP *snd)
{
    TTEvtK2 evt;
    f32 pitch;

    pitch = func_80027170(((TTWaveP *) snd->unk8)->unk15) * snd->unk2C;
    evt.type = 0x10;
    evt.p = snd;
    evt.data = *(s32 *) &pitch;
    func_80026500(&((TTSMgr *) D_800411DC)->evtq, &evt, 0x8235, 0);
}

// Removes queued events of `target` matching `mask`; their delay is passed on to the next event.
void func_800201A4(TTEvtqS *evtq, void *target, u16 mask)
{
    TTItemS *item;
    TTItemS *next;
    TTItemS *cur_item;
    TTItemS *next_item;
    TTEvtF *evt;
    s32 prev_mask;

    prev_mask = osSetIntMask(1);

    item = evtq->pending;
    while (item != 0) {
        next = item->next;
        cur_item = item;
        next_item = next;
        evt = &cur_item->evt;
        if (evt->p == target && (evt->type & mask)) {
            if (next_item != 0) {
                next_item->delay += cur_item->delay;
            }
            func_80020E74(item);
            func_80020E40(item, evtq);
        }
        item = next;
    }

    osSetIntMask(prev_mask);
}

// Counts the sounds on the free and playing lists.
u16 func_80020298(u16 *out_free, u16 *out_playing)
{
    s32 prev_mask;
    u16 playing_cnt;
    u16 free_cnt;
    u16 back_cnt;
    TTSndL *play_node;
    TTSndL *free_node;
    TTSndL *back_node;

    prev_mask = osSetIntMask(1);

    play_node = (TTSndL *) D_800411D0;
    free_node = (TTSndL *) D_800411D8;
    back_node = (TTSndL *) D_800411D4;

    for (playing_cnt = 0; play_node != 0; playing_cnt++, play_node = play_node->next)
        ;
    for (free_cnt = 0; free_node != 0; free_cnt++, free_node = free_node->next)
        ;
    for (back_cnt = 0; back_node != 0; back_cnt++, back_node = back_node->prev)
        ;

    *out_free = free_cnt;
    *out_playing = playing_cnt;

    osSetIntMask(prev_mask);

    return back_cnt;
}

// Takes a sound state from the free list, links it into the playing list and fills it from its definition.
TTSndA *func_8002039C(TTPrmA *def)
{
    TTSndA *snd;
    TTPrmSub *sub;
    s32 flag;
    s32 prev_mask;

    sub = &def->unk10;
    prev_mask = osSetIntMask(1);

    snd = (TTSndA *) D_800411D8;
    if (snd != 0) {
        D_800411D8 = snd->next;
        func_80020E74(snd);

        if ((TTSndA *) D_800411D0 != 0) {
            snd->next = (TTSndA *) D_800411D0;
            snd->prev = 0;
            ((TTSndA *) D_800411D0)->prev = snd;
            D_800411D0 = snd;
        } else {
            snd->prev = 0;
            snd->next = snd->prev;
            D_800411D0 = snd;
            D_800411D4 = snd;
        }

        osSetIntMask(prev_mask);
        func_800E9070(def, 0);

        flag = def->unk4 + 1 == 0;

        snd->def = def;
        snd->unk_40 = flag + 0x40;
        snd->state = 5;
        snd->pitch = 1.0f;
        snd->retries = 2;
        snd->flags = sub->unk3 & 0xF0;
        snd->owner = 0;

        if (snd->flags & 0x20) {
            snd->base_pitch = func_80027170(sub->unk4 * 100 - 6000);
        } else {
            snd->base_pitch = func_80027170(sub->unk4 * 100 + sub->unk5 - 6000);
        }

        if (flag) {
            snd->flags = snd->flags | 2;
        }

        snd->fx_mix = 0;
        snd->pan = 0x40;
        snd->volume = 0x7FFF;
    } else {
        osSetIntMask(prev_mask);
    }

    return snd;
}

// Moves a sound state from the playing list back to the free list.
void func_800205D0(TTSndU *snd)
{
    s32 prev_mask;

    prev_mask = osSetIntMask(1);

    if ((TTSndU *) D_800411D0 == snd)
        D_800411D0 = snd->next;

    if ((TTSndU *) D_800411D4 == snd)
        D_800411D4 = snd->prev;

    func_80020E74(snd);

    if ((TTSndU *) D_800411D8 != 0) {
        snd->next = (TTSndU *) D_800411D8;
        snd->prev = 0;
        ((TTSndU *) D_800411D8)->prev = snd;
        D_800411D8 = snd;
    } else {
        snd->prev = 0;
        snd->next = snd->prev;
        D_800411D8 = snd;
    }

    if (snd->flags & 4) {
        D_800411E0 = D_800411E0 - 1;
    }

    snd->state = 0;

    if (snd->owner != 0) {
        if (*snd->owner == snd)
            *snd->owner = 0;
        snd->owner = 0;
    }

    func_800E90A4(snd->def, 0);

    osSetIntMask(prev_mask);
}

void func_80020738(u8 *snd, u8 value)
{
    if (snd != NULL) {
        M2C_FIELD(snd, s8 *, 0x40) = (s8) (s16) value;
    }
}

u8 func_80020760(u8 *snd)
{
    if (snd != NULL) {
        return M2C_FIELD(snd, u8 *, 0x45);
    } else {
        return 0U;
    }
}

// Starts sound `id` and the sounds chained after it; stores the last one in *out.
TTSndB_80020790 *func_80020790(s16 id, u16 vol, u8 pan, f32 pitch_mul, u8 fx_mix, u8 unk_0,
                               TTSndB_80020790 **out)
{
    TTSndB_80020790 *snd;
    TTSndB_80020790 *last;
    TTPrmSubB *link;
    TTPrmB2 *def;
    s16 next_id;
    s32 next_delay;
    s32 dur;
    s32 elapsed;
    s32 pan_val;
    TTEvtK1 play_evt;
    TTEvtK2 chain_evt;

    last = 0;
    next_id = 0;
    elapsed = 0;

    if (id != 0) {
        do {
            def = func_800E9320(0, id - 1);
            snd = func_8002039C(def);

            if (snd != 0) {
                ((TTSMgrB *) D_800411DC)->unk3C = snd;

                play_evt.type = 1;
                play_evt.p = snd;

                pan_val = pan + snd->pan - 0x40;
                if (pan_val >= 0x80)
                    pan_val = 0x7F;
                else if (pan_val < 0)
                    pan_val = 0;
                snd->pan = pan_val;

                snd->volume = (u32) (vol * snd->volume) >> 15;
                snd->pitch *= pitch_mul;
                snd->fx_mix = fx_mix;
                snd->unk_43 = unk_0;

                dur = def->duration * 33333;

                if (snd->flags & 0x10) {
                    snd->flags = snd->flags & ~0x10;
                    func_80026500(&((TTSMgrB *) D_800411DC)->evtq, &play_evt, elapsed + 1, 0);
                    next_delay = dur + 1;
                    next_id = id;
                } else {
                    func_80026500(&((TTSMgrB *) D_800411DC)->evtq, &play_evt, dur + 1, 0);
                }

                last = snd;
            }

            elapsed = elapsed + dur;

            link = (TTPrmSubB *) ((u8 *) def + 0x10);
            id = link->next_id_lo + ((link->unk2 & 0xC0) << 2);
        } while (id != 0 && snd != 0);

        if (last != 0) {
            last->flags = last->flags | 1;
            last->owner = out;

            if (next_id != 0) {
                last->flags = last->flags | 0x10;

                chain_evt.type = 0x200;
                chain_evt.p = last;
                chain_evt.data = next_id;
                func_80026500(&((TTSMgrB *) D_800411DC)->evtq, &chain_evt, next_delay, 0);
            }
        }
    }

    if (out != 0) {
        *out = last;
    }

    return last;
}

// Posts an end event (0x400) for the sound and clears its 0x10 flag.
void func_80020A60(TTSnd *snd)
{
    TTEvtK2 evt;

    evt.type = 0x400;
    evt.p = snd;
    if (snd != 0) {
        ((TTSnd *) evt.p)->flags = ((TTSnd *) evt.p)->flags & ~0x10;
        func_80026500(&((TTSMgr *) D_800411DC)->evtq, &evt, 0, 0);
    }
}

// Posts an end event to every playing sound whose flags contain all bits of `mask`.
// Matching: old-style parameter declaration, needed for the match.
void func_80020AD0(mask) u8 mask;
{
    s32 prev_mask;
    TTEvtK2 evt;
    TTSnd *snd;

    prev_mask = osSetIntMask(1);
    snd = D_800411D0;
    while (snd != 0) {
        evt.type = 0x400;
        evt.p = snd;
        if ((snd->flags & mask) == mask) {
            ((TTSnd *) evt.p)->flags = ((TTSnd *) evt.p)->flags & ~0x10;
            func_80026500(&((TTSMgr *) D_800411DC)->evtq, &evt, 0, 0);
        }
        snd = snd->next;
    }
    osSetIntMask(prev_mask);
}

void func_80020B90(void)
{
    func_80020AD0(1);
}

void func_80020BB8(void)
{
    func_80020AD0(0x11);
}

void func_80020BE0(void)
{
    func_80020AD0(3);
}

void func_80020C08(TTSnd *snd, s16 type, s32 data)
{
    TTEvtK2 evt;

    evt.type = type;
    evt.p = snd;
    evt.data = data;
    if (snd != 0) {
        func_80026500(&((TTSMgr *) D_800411DC)->evtq, &evt, 0, 0);
    }
}

// Matching: old-style parameter declaration, needed for the match.
u16 func_80020C74(chan)
u8 chan;
{
    return D_8007EA24[chan];
}

// Sets the volume of channel group `chan` and posts a volume update to its sounds.
// Matching: old-style parameter declaration, needed for the match.
void func_80020CA0(chan, val) u8 chan;
u16 val;
{
    s32 prev_mask;
    TTSnd *snd;
    s32 i;
    TTEvtK2 evt;

    prev_mask = osSetIntMask(1);
    snd = D_800411D0;
    ((u16 *) D_8007EA24)[chan] = val;
    for (i = 0; snd != 0;) {

if ((((TTWaveC *) snd->def)->unk12 & 0x1F) == chan) {
    evt.type = 0x800;
    evt.p = snd;
    func_80026500(&((TTSMgr *) D_800411DC)->evtq, &evt, 0, 0);
}

(i++, snd = snd->next);
}
osSetIntMask(prev_mask);
}

// n_alInit / n_alClose: install the audio globals, create and delete the synthesizer.
// Creates the synthesizer once (same sequence as n_alInit).
void func_80020D80(void *unk_0, void *cfg)
{
    if (D_800411F0 == 0) {
        D_800411F0 = unk_0;

if ((void *) D_800411F4 == 0) {
    D_800411F4 = D_800411F0;
    func_80020F70(cfg);
}

}
}

void func_80020DEC(s32 unk_0)
{
    if (((s32) D_800411F0)) {
        func_80027200();
        D_800411F0 = 0;
        D_800411F4 = 0;
    }
}

// TU-NOTE: the .data of this file (formerly asm/data/core1/1E36640.data.s) is defined here in C;
// values are taken from the ROM. The *_rest arrays are the data that follows D_800411E0/D_800411F4.
extern u8 D_8007E9C0[];
TTSnd *D_800411D0 = 0;
u8 *D_800411D4 = 0;
TTSndI *D_800411D8 = 0;
u8 *D_800411DC = (void *) &D_8007E9C0;
s16 D_800411E0 = 0x0;
static u32 D_800411E0_rest[3] = {0x0, 0x0, 0x0};
void *D_800411F0 = 0;
u8 *D_800411F4 = 0;
static u32 D_800411F4_rest[26] = {0x0, 0x0, 0x3, 0x898, 0x0,    0x4A0, 0x2666,     0xFFFFD99A, 0x0,
                                  0x0, 0x0, 0x0, 0x1A0, 0x340,  0xCCC, 0xFFFFF334, 0x3FFF,     0x0,
                                  0x0, 0x0, 0x0, 0x528, 0x1388, 0x0,   0x0,        0x0};
