#include "common.h"

typedef struct {
    u8 pad_0[0xB];
    u8 pad_B : 6, unk_B : 1, pad_B1 : 1;
} LocalMarker;
typedef struct {
    LocalMarker *unk_0;
    void *unk_4;
    u8 pad_8[4];
    s32 unk_C;
    s16 unk_10;
    u8 pad_12[2];
    u16 model_id, anim_id;
    u16 unk_18 : 11, pad_18 : 5;
    u8 pad_1A[4];
    s16 center[3];
} LocalObject;
typedef struct {
    LocalObject *marker;
    u8 pad_4[0x5C];
    s16 model_instance, radius;
    u8 pad_64[4];
    u16 unk_68, unk_6A;
    u8 pad_6C[4];
    u32 pad_70 : 28, has_resources : 1, pad_73 : 3;
    u8 unk_74 : 1, pad_74 : 7;
    u8 has_anim : 1, pad_75 : 7;
    u8 pad_76[0xA];
    u16 unk_80;
    u8 pad_82[6];
    s16 min_y, max_y, anim_ctrl, floor_tint, glid;
} LocalActor_80103140;
typedef struct {
    u8 pad_0[0x12];
    u16 unk_12, unk_14;
} LocalModel;
extern s32 func_800D58FC(s32);
extern s16 func_80104328(void *param_0);
typedef struct {
    LocalObject *marker;
    u8 pad_4[0x5C];
    s16 model_instance, radius;
    u8 pad_64[4];
    u16 unk_68, unk_6A;
    u8 pad_6C[4];
    u32 pad_70 : 28, has_resources : 1, pad_73 : 3;
    u8 unk_74 : 1, pad_74 : 7;
    u8 has_anim : 1, pad_75 : 7;
    u8 pad_76[0xA];
    u16 unk_80;
    u8 pad_82[6];
    s16 min_y, max_y, anim_ctrl, floor_tint, glid;
} LocalActor_80103328;
extern LocalModel *func_800B2840(void *);
extern s32 func_800B2248(LocalModel *);
extern void func_800B2198(LocalModel *, s32 *, s32 *);
extern void func_800B237C(LocalModel *, f32 *, f32 *);
extern void func_800EE940();
extern s32 func_80106790();
extern void func_800DF7F8(s32, f32, f32);
typedef struct {
    LocalObject *marker;
    u8 pad_4[0x5C];
    s16 model_instance, radius;
    u8 pad_64[4];
    u16 unk_68, unk_6A;
    u8 pad_6C[4];
    u32 pad_70 : 7, unk_70 : 1, pad_71 : 2, unk_71 : 1, pad_71b : 5, init_anim : 6, pad_72 : 6,
        has_resources : 1, pad_73 : 3;
    u8 unk_74 : 1, pad_74 : 7;
    u8 has_anim : 1, pad_75 : 7;
    u8 pad_76[5];
    u8 unk_7B : 2, pad_7B : 6;
    u8 pad_7C[4];
    u16 unk_80;
    u8 pad_82[6];
    s16 min_y, max_y, anim_ctrl, floor_tint, glid;
    u8 pad_92[4];
    u16 unk_96 : 1, pad_96 : 15;
} LocalActor_80103508;
extern void *func_80100368(void);
extern void *func_800D674C(s32);
extern void _subaddiefade_entrypoint_9(LocalActor_80103508 *, s32 *);
extern s16 func_80100D24(void *, s32, s32, s32, s32, s32 *);
extern void func_800B25D8(void *, LocalModel *, void *);
extern void func_800D6CEC(s32);
extern s32 func_80102FA0(void *, s32);
extern void *func_800DBFF8(void);
extern void func_80105DFC(LocalActor_80103508 *);
extern s16 func_800AE020(void);
extern s16 func_800D88F8(void);
extern void func_80102424(LocalActor_80103508 *, s32);
extern void func_80104460(LocalActor_80103508 *);
extern void func_8010108C(LocalActor_80103508 *, s32, void *);
typedef struct {
    LocalObject *marker;
    u8 pad_4[0x5C];
    s16 model_instance, radius;
    u8 pad_64[4];
    u16 unk_68, unk_6A;
    u8 pad_6C[4];
    u32 pad_70 : 28, has_resources : 1, pad_73 : 3;
    u8 unk_74 : 1, pad_74 : 7;
    u8 has_anim : 1, pad_75 : 7;
    u8 pad_76[0xA];
    u16 unk_80;
    u8 pad_82[6];
    s16 min_y, max_y, anim_ctrl, floor_tint, glid;
} LocalActor_8010381C;
extern void func_80100E18(s32);
extern void func_800DBFD8(void *);
extern void func_80106138(LocalActor_8010381C *);
extern void func_800ADFE0(s32);
extern void func_800D8954(s16);
extern void func_80104504();
extern u8 _subaddiecustomhits_entrypoint_1[];
typedef struct {
    u8 pad0[0x60];
    s16 unk60;
    u8 pad62[0xE];
    u8 pad70 : 7;
    u8 flag70 : 1;
    u8 flag71 : 1;
    u32 pad71 : 1;
    u32 flag71_2 : 1;
    u32 pad71b : 21;
} S80103B24;
extern s32 func_80100A74(s32, s32);
typedef struct {
    u8 pad_0[0x70];
    u32 pad_70 : 10;
    u32 unk_70_10 : 1;
    u32 pad_70_11 : 21;
} local_type;
extern void func_800EE7F8(void *, void *);
extern void func_800EE88C(s32, s32);
extern void func_800EF04C();
typedef struct {
    u8 pad0[0x38];
    f32 unk38;
    u8 pad3C[0x2E];
    u16 unk6A;
} S_103FB8;
void func_80103930();

extern void func_800D62E4();
extern void func_800EE84C(s32, u32 *);
extern void func_800EF334(s32, f32);
void func_80103328();
void func_8010381C();
void func_80103938();
int func_80103964();
int func_801039A4();
s32 func_801039E4();
int func_80103C94();
s32 func_80103D24();
void func_80103D48();
void func_80103D70();

// Changes the actor's model and animation ids, releasing and reloading its resources.
s32 func_80103140(LocalActor_80103140 *actor, u16 model_id, u16 anim_id)
{
    u16 old_id;
    u32 had_resources;
    s32 unk_1;
    s32 old_model_id;
    old_id = actor->marker->model_id;
    old_model_id = old_id;
    if (old_model_id == model_id && anim_id == actor->marker->anim_id)
        return old_id;
    had_resources = actor->has_resources;
    func_8010381C(actor);
    func_80103938(actor);
    actor->unk_74 = 0;
    actor->marker->unk_C = 0;
    actor->unk_68 = 0;
    actor->unk_6A = 0;
    actor->radius = 0;
    actor->marker->unk_18 = 0;
    if (actor->anim_ctrl != 0)
        func_80104328(actor);
    unk_1 = func_800D58FC(model_id);
    actor->marker->model_id = model_id;
    actor->marker->anim_id = anim_id;
    if (unk_1 == 0)
        actor->marker->unk_0->unk_B = 1;
    else
        actor->marker->unk_0->unk_B = 0;
    if (unk_1 == 0)
        func_80103328(actor);
    func_80103930(actor);
    if (had_resources && !actor->has_resources && unk_1 == 0) {
        func_801039E4(actor->marker);
        func_800D62E4(actor->marker->model_id);
    }
    return old_model_id;
}

// Like func_80103140, but preserves the anim controller handle at +0x8C.
unsigned int func_801032B0(void *actor, u16 model_id, u16 anim_id)
{
    s32 result;
    s32 saved;
    saved = ((s16 *) actor)[70];
    ((s16 *) actor)[70] = 0;
    result = func_80103140(actor, model_id, anim_id);
    if (((s16 *) actor)[70] != 0) {
        func_80104328(actor);
    }
    ((s16 *) actor)[70] = saved;
    return result;
}

// Loads the model asset once and caches its bounding-box metrics in the actor.
void func_80103328(actor) LocalActor_80103328 *actor;
{
    s32 min_pos[3];
    s32 max_pos[3];
    f32 center[3];
    LocalModel *model;
    f32 unk_4;
    void *asset;
    if (actor->unk_68 == 0) {
        asset = func_80103964(actor->marker);
        if (asset != 0) {
            func_800D62E4(actor->marker->model_id);
            model = func_800B2840(asset);
            actor->unk_68 = model->unk_12;
            actor->unk_6A = model->unk_14;
            actor->radius = func_800B2248(model);
            func_800B2198(model, min_pos, max_pos);
            actor->min_y = min_pos[1];
            actor->max_y = max_pos[1];
            func_800B237C(model, center, &unk_4);
            func_800EE940(actor->marker->center, center);
            actor->marker->unk_18 = unk_4;
        }
    }
}

int func_8010347C(s32 param_0)
{
    s32 actor;
    u16 model_id;
    actor = func_80106790();
    func_80103328(actor);
    model_id = *(u16 *) (param_0 + 0x14);
    func_800DF7F8(model_id, (f32) *(u16 *) (actor + 0x68), (f32) *(u16 *) (actor + 0x6A));
    return 0;
}

// Acquires the actor's resources according to its ActorInfo flags, then sends message 0x29.
void func_80103508(LocalActor_80103508 *actor)
{
    void *info;
    LocalObject *marker;
    void *anim_asset;
    void *model_asset;
    s32 unk_4;
    s32 unk_5;
    s32 unk_6[3];
    LocalModel *model;
    void *unk_7;
    if (!actor->has_resources) {
        marker = actor->marker;
        info = func_80100368();
        model_asset = func_801039A4(marker);
        if (!model_asset)
            model_asset = func_801039E4(marker);
        func_80103328(actor);
        if (marker->anim_id)
            anim_asset = func_800D674C(marker->anim_id);
        else
            anim_asset = 0;
        unk_4 = actor->unk_7B ? 1 : 0;
        unk_5 = actor->unk_70 ? 2 : (actor->unk_71 ? 1 : 0);
        if ((unk_4 || unk_5) && !actor->model_instance) {
            if (actor->unk_96)
                _subaddiefade_entrypoint_9(actor, unk_6);
            actor->model_instance = func_80100D24(model_asset, marker->model_id, unk_5, unk_4,
                                              marker->anim_id, actor->unk_96 ? unk_6 : 0);
        }
        if (anim_asset && unk_5 >= 2) {
            unk_7 = func_80103D24(actor);
            model = func_800B2840(model_asset);
            func_800B25D8(unk_7, model, anim_asset);
        }
        if (anim_asset) {
            unk_7 = func_80103C94(actor);
            model = func_800B2840(model_asset);
            func_800B25D8(unk_7, model, anim_asset);
            func_800D6CEC(marker->anim_id);
        }
        if (!marker->unk_4 && func_80102FA0(info, 0x40))
            marker->unk_4 = func_800DBFF8();
        if (!actor->glid && func_80102FA0(info, 0x1000))
            func_80105DFC(actor);
        if (!marker->unk_10 && func_80102FA0(info, 0x20))
            marker->unk_10 = func_800AE020();
        if (!actor->unk_80 && func_80102FA0(info, 0x4000))
            actor->unk_80 = func_800D88F8();
        if (!actor->anim_ctrl && actor->has_anim)
            func_80102424(actor, actor->init_anim);
        if (!actor->floor_tint && func_80102FA0(info, 0x40000))
            func_80104460(actor);
        actor->has_resources = 1;
        func_8010108C(actor, 0x29, model_asset);
    }
}

// Releases the resources acquired by func_80103508, then sends message 0x2A.
void func_8010381C(actor) LocalActor_8010381C *actor;
{
    LocalObject *marker;
    marker = actor->marker;
    if (actor->has_resources) {
        if (actor->model_instance) {
            func_80100E18(actor->model_instance);
            actor->model_instance = 0;
        }
        if (marker->unk_4) {
            func_800DBFD8(marker->unk_4);
            marker->unk_4 = 0;
        }
        if (actor->glid)
            func_80106138(actor);
        if (marker->unk_10) {
            func_800ADFE0(marker->unk_10);
            marker->unk_10 = 0;
        }
        if (actor->unk_80) {
            func_800D8954(actor->unk_80);
            actor->unk_80 = 0;
        }
        if (actor->has_anim && actor->anim_ctrl)
            func_80104328(actor);
        if (actor->floor_tint)
            func_80104504(actor);
        actor->has_resources = 0;
        func_8010108C(actor, 0x2A, 0);
    }
}

void func_80103930(s32 arg0)
{
}

void func_80103938(actor) u8 *actor;
{
    if (*(s16 *) (actor + 0x8E) != 0) {
        func_80104504();
    }
}

// Loads the model asset for marker+0x14; returns 0 for id 0 or 0xFFFF.
int func_80103964(marker)
Actor *marker;
{
    if ((*(u16 *) ((char *) marker + 0x14) == 0) ||
        (*(u16 *) ((char *) marker + 0x14) == 0xFFFF)) {
        return 0;
    }
    {
        // Matching: `| 0` needed for the match.
        return func_800D674C(*(u16 *) ((char *) marker + 0x14) | 0);
    }
}

int func_801039A4(marker)
Actor *marker;
{
    int model_id;
    model_id = *(u16 *) ((char *) marker + 0x14);
    if ((*(u16 *) ((char *) marker + 0x14) == 0) || (model_id == 0xFFFF)) {
        return 0;
    }
    {
        // Matching: `| 0` needed for the match.
        return func_800D6B0C(*(u16 *) ((char *) marker + 0x14) | 0);
    }
}

s32 func_801039E4(marker)
Actor *marker;
{
    typedef struct {
        u32 pad_0[2];
        u32 pad_8_2 : 30;
        u32 unk_8_30 : 1;
    } Struct801039E4;
    s32 model_asset;
    Actor *actor;
    model_asset = func_80103964();
    if (model_asset == 0) {
        return 0;
    }
    actor = func_80106790(marker);
    func_80103D48(actor);
    func_80103508(actor);
    if ((((u32) *(u32 *) ((char *) actor + 0x74) >> 0x1F) == 0) &&
        (*(s32 *) ((char *) marker + 0xC) == 0)) {
        if ((((Struct801039E4 *) marker->unk0)->unk_8_30 != 0) && (func_800B2824(model_asset) != 0)) {
            _subaddiecustomhits_entrypoint_0(actor, &_subaddiecustomhits_entrypoint_1);
        }
        actor->pad74_31 = 1;
    }
    func_80103D70(actor);
    return model_asset;
}

void func_80103AA0()
{
    func_801039A4();
}

int func_80103AC0(void **marker_ref)
{
    s32 raw_id;
    s32 model_id;
    raw_id = ((u16 *) marker_ref[0])[0xA];
    model_id = raw_id;
    func_800D6C34(model_id);
}

int func_80103AE4(Actor *marker)
{
    if ((*(u16 *) ((char *) marker + 0x14) == 0) ||
        (*(u16 *) ((char *) marker + 0x14) == 0xFFFF)) {
        return 0;
    }
    {
        // Matching: `| 0` needed for the match.
        return func_800D674C(*(u16 *) ((char *) marker + 0x14) | 0);
    }
}

// Returns the vertex buffer: the instance's if one exists, otherwise the asset's.
s32 func_80103B24(S80103B24 *actor, s32 flip, s32 asset)
{
    if (asset == 0) {
        return 0;
    }
    if (actor->flag70 && actor->unk60 != 0) {
        return func_80100A74(actor->unk60, actor->flag71 ^ flip);
    }
    if (actor->flag71_2 && actor->unk60 != 0) {
        return func_80100A74(actor->unk60, 0);
    }
    return func_800B2840(asset);
}

int func_80103BBC(s32 *actor)
{
    s32 asset;
    asset = func_801039A4(*actor);
    // Matching: `| 0` needed for the match.
    func_80103B24(actor, 0, asset | 0);
}

int func_80103BF0(s32 *actor, s32 flip, s32 asset)
{
    if (asset == 0)
        asset = func_80103964(actor[0]);
    if (asset == 0)
        return 0;
    if (*(u8 *) ((u8 *) actor + 0x70) & 1) {
        return func_80100A74(*(s16 *) ((u8 *) actor + 0x60),
                             ((u32) *(u8 *) ((u8 *) actor + 0x71) >> 7) ^ flip);
    }
    if (((local_type *) actor)->unk_70_10)
        return func_80100A74(*(s16 *) ((u8 *) actor + 0x60), 0);
    return func_800B2840(asset);
}

int func_80103C94(actor)
s32 actor;
{
    func_80103BF0(actor, 0, 0);
}

int func_80103CB8(s32 actor, s32 asset)
{
    // Matching: `| 0` needed for the match.
    func_80103BF0(actor, 0 | 0, asset | 0);
}

int func_80103CDC(s32 actor, s32 asset)
{
    // Matching: `| 0` needed for the match.
    func_80103B24(actor, 0 | 0, asset | 0);
}

void func_80103D00(s32 actor, s32 asset)
{
    func_80103B24(actor, 0x1, asset);
}

s32 func_80103D24(actor)
s32 actor;
{
    func_80103BF0(actor, 1, 0);
}

void func_80103D48(actor) void *actor;
{
    func_800D70F8(*(u16 *) ((char *) *(s32 *) actor + 0x14), 1);
}

void func_80103D70(actor) int actor;
{
    func_800D70F8(*(u16 *) (*(int *) actor + 0x14), 0);
}

s32 func_80103D98(void *marker)
{
    s32 model_asset;

if (func_800AE0E8(*(s16 *) ((u8 *) marker + 0x10)) == 0) {
    return 0;
}

model_asset = func_801039A4(marker);

if (model_asset == 0) {
    return 0;
}

func_800D62E4(*(u16 *) ((u8 *) marker + 0x14), model_asset);
return func_800B2824(model_asset);

}

// Writes the model centre in world space to out_pos.
void func_80103DFC(Actor *actor, f32 *out_pos)
{
    if (*(u16 *) (*(u32 *) (u8 *) actor + 0x14) == 0xFFFF) {
        func_800EE7F8(out_pos, (u8 *) actor + 4);
        return;
    }

func_80103328(actor);
func_800EE7F8(out_pos, (u8 *) actor + 4);
*((f32 *) (out_pos + 1)) +=
    *((f32 *) ((u8 *) actor + 0x38)) *
    (*((s16 *) ((u8 *) actor + 0x88)) +
     (*((s16 *) ((u8 *) actor + 0x8A)) - *((s16 *) ((u8 *) actor + 0x88))) * 0.5f);
}

// Returns the model radius scaled by the actor's scale.
f32 func_80103EAC(u8 *actor)
{
    f32 radius;
    u16 radius_u16;
    int raw_radius;
    // Matching: do/while(0) and the repeated load are needed for the match.
    do {
        func_80103328();
        radius_u16 = *((u16 *) (((s8 *) actor) + 0x62));
        raw_radius = *((u16 *) (((s8 *) actor) + 0x62));
        radius_u16 = raw_radius;
        radius = (f32) radius_u16;
        return (*((f32 *) (((s8 *) actor) + 0x38))) * radius;
    } while (0);
}

// Returns the model height (max_y - min_y) scaled by the actor's scale.
f32 func_80103EF4(u8 *actor)
{
    func_80103328();
    return (*((f32 *) (((s8 *) actor) + 0x38))) *
           ((f32) ((*((s16 *) (((s8 *) actor) + 0x8A))) -
                   (*((s16 *) (((s8 *) actor) + 0x88)))));
}

f32 func_80103F38(u8 *actor, s32 unk_1)
{
    func_80103328(actor);

if (unk_1 != 0) {
    func_800EE88C(unk_1, *(s32 *) actor + 0x1E);
    func_800EF334(unk_1, *(f32 *) (actor + 0x38));
    func_800EF04C(unk_1, actor + 4);
}

return *(f32 *) (actor + 0x38) * (u32) *(u16 *) (actor + 0x68);
}

f32 func_80103FB8(S_103FB8 *actor)
{
    func_80103328(actor);
    return (f32) (u32) actor->unk6A * actor->unk38;
}

int func_80104004(OSTask_t **actor, s32 unk_1, s32 unk_2)
{
    OSTask_t **marker_ref;
    u32 min_pos[2];
    s32 pad0;
    u32 max_pos[2];
    OSTask_t *model;
    u32 model_asset;
    model_asset = func_801039E4(*actor);

if (!model_asset) {
    return 0;
}

marker_ref = &(*actor);
func_800D62E4(*((u16 *) (((u8 *) (*marker_ref)) + 0x14)), model_asset);
model = func_800B2840(model_asset);
func_800B2198(model, &min_pos, &max_pos);
func_800EE84C(unk_1, &min_pos);
func_800EE84C(unk_2, &max_pos);
func_800EF334(unk_1, *((f32 *) (((char *) actor) + 56)));
func_800EF334(unk_2, *((f32 *) (((char *) actor) + 56)));
return 1;
}

void func_801040A8(u8 **actor)
{
    func_800AE080(*(s16 *) ((u8 *) *actor + 0x10));
}
