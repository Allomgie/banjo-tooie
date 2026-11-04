// Falling-leaves weather: leaf models spawn around the player in view, drift with random velocity
// and spin, are removed below the player or when too far, and are drawn as models.
#include "common.h"
#include "vector.h"

extern f32 func_800DC178(f32, f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern f32 func_800EEFD4();
extern void func_800EF934(f32 *, f32 *, f32);
extern s32 func_800E3F8C(f32, f32, f32);
extern void func_800EE780(f32 *, f32 *, f32 *);
typedef struct {
    u8 pad_0[0x24];
    s32 model_ids[4];
} Broad51LeafTextures;
typedef struct {
    s32 model;
    f32 position[3];
    u8 pad_10[0xC];
    f32 rotation[3];
    u8 pad_28[0xC];
    u8 state;
    u8 pad_35[3];
} LeafParticle;
typedef struct {
    u8 pad_0[0x1C];
    Vector *particles;
} LeafParticles;
extern s32 func_800DF350(void);
extern void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
// Emitter: 'mode' 1 = spawning, 2 = stopping (leaves finish falling).
typedef struct {
    f32 player_pos[3];
    f32 player_delta[3];
    s32 check_index;
    Vector *particles;
    s16 max_count;
    u8 mode;
    u8 pad_23;
    s32 model_ids[4];
    u8 model_index;
    u8 pad_35[3];
    f32 spawn_timer;
} LeafEmitter61;
extern void *heap_alloc(s32);
extern f32 func_800D8FF8(void);
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern s32 func_800F1574(f32 *, f32);

typedef struct {
    s32 model;
    f32 position[3];
    f32 velocity[3];
    f32 rotation[3];
    f32 angular_velocity[3];
    u8 state;
    u8 pad_35[3];
} Mass63Leaf;

// Spawns a leaf around the player in the camera view direction, lifted above ground.
void func_80800000_fxleaves(u8 *emitter)
{
    f32 player_pos[3];
    f32 cam_dir[3];
    f32 cam_rot[3];
    f32 spin_x;
    f32 spin_y;
    u8 *leaf;
    f32 spawn_pos[3];
    f32 dist;
    s32 i;

    if (vector_size(*(Vector **) (emitter + 0x1C)) < *(s16 *) (emitter + 0x20)) {
        func_8008FE68(player_pos);
        func_800E3958(cam_dir);
        func_800E3A58(cam_rot);
        leaf = vector_push_back((Vector **) (emitter + 0x1C));
        dist = func_800DC178(50.0f, 1200.0f);
        func_800EFA4C(spawn_pos, 0.0f, func_800DC178(200.0f, 500.0f), -dist);
        if (func_800EEFD4((f32 *) (emitter + 0xC)) < 25.0f) {
            func_800EF934(spawn_pos, spawn_pos, func_800DC178(0.0f, 360.0f));
        } else {
            func_800EF934(spawn_pos, spawn_pos, cam_rot[1] + func_800DC178(-70.0f, 70.0f));
        }
        func_800EE780(spawn_pos, player_pos, spawn_pos);
        if (dist < 600.0f) {
            for (i = 0;
                 i < 10 && func_800E3F8C(spawn_pos[0], spawn_pos[1] - 10.0f, spawn_pos[2]);
                 i++) {
                spawn_pos[1] += 100.0f;
            }
        }
        func_800EE7F8((f32 *) (leaf + 4), spawn_pos);
        func_800EFA4C((f32 *) (leaf + 0x10), 0.0f, -100.0f, 0.0f);
        func_800EFD24((f32 *) (leaf + 0x1C));
        spin_x = func_800DC178(-300.0f, 300.0f);
        spin_y = func_800DC178(-300.0f, 300.0f);
        func_800EFA4C((f32 *) (leaf + 0x28), spin_x, spin_y, func_800DC178(-300.0f, 300.0f));
        emitter[0x34]++;
        if (emitter[0x34] >= 4) {
            emitter[0x34] = 0;
        }
        *(s32 *) leaf = ((Broad51LeafTextures *) emitter)->model_ids[emitter[0x34]];
    }
}

int func_80800288_fxleaves(u8 *emitter, int mode)
{
    emitter[0x22] = mode;
}

void fxleaves_entrypoint_0(void *emitter)
{
    vector_clear(*(void **) ((char *) emitter + 0x1C));
}

void fxleaves_entrypoint_1(LeafParticles *emitter)
{
    LeafParticle *begin;
    LeafParticle *end;
    LeafParticle *leaf;
    begin = vector_begin(emitter->particles);
    end = vector_end(emitter->particles);
    for (leaf = begin; leaf < end; leaf++) {
        func_800DF830(2);
        func_800DE448(leaf->position, leaf->rotation, 1.0f, NULL,
                      (s32) func_800D674C(leaf->model));
        leaf->state = func_800DF350();
    }
}

// Returns 1 once spawning is off and all leaves are gone.
s32 fxleaves_entrypoint_2(u8 *emitter)
{
    // Matching: the extra temporaries are needed for the match.
    char *base;
    int offset;
    s32 done;
    u8 *emitter_copy;
    done = *(u8 *) ((char *) emitter - -0x22) != 1;
    if (done != 0) {
        offset = 0x1C;
        emitter_copy = emitter;
        done = vector_size(*(s32 *) ((base = (char *) emitter_copy) + offset)) == 0;
        return done;
    }
}

int fxleaves_entrypoint_3(s32 emitter)
{
    vector_free(*(s32 *) ((char *) emitter + 0x1C));
    heap_free(emitter);
}

LeafEmitter61 *fxleaves_entrypoint_4(s32 max_count)
{
    LeafEmitter61 *emitter;

    emitter = heap_alloc(sizeof(LeafEmitter61));
    emitter->check_index = 0;
    emitter->player_pos[0] = emitter->player_pos[1] = emitter->player_pos[2] = 0.0f;
    emitter->player_delta[0] = emitter->player_delta[1] = emitter->player_delta[2] = 0.0f;
    emitter->particles = vector_new(0x38, max_count);
    emitter->max_count = max_count;
    emitter->mode = 0;
    emitter->model_ids[0] = 0x9ED;
    emitter->model_ids[1] = 0x9EE;
    emitter->model_ids[2] = 0x9EF;
    emitter->model_ids[3] = 0x9F0;
    emitter->model_index = 0;
    emitter->spawn_timer = 0.1f;
    return emitter;
}

void fxleaves_entrypoint_5(s32 emitter)
{
    func_80800288_fxleaves(emitter, 1);
}

void fxleaves_entrypoint_6(s32 emitter)
{
    func_80800288_fxleaves(emitter, 0x2);
}

// Per-frame update: moves leaves, removes far or low ones, spawns new ones on a timer.
void fxleaves_entrypoint_7(u8 *emitter)
{
    f32 player_pos[3];
    f32 dt;
    s32 i;
    Mass63Leaf *leaf;

    dt = func_800D8FF8();
    func_8008FE68(player_pos);
    func_800EFB24((f32 *) (emitter + 0xC), player_pos, (f32 *) emitter);
    func_800EE7F8((f32 *) emitter, player_pos);
    if (func_800A5490()) {
        vector_clear(*(Vector **) (emitter + 0x1C));
    }
    for (i = 0; i < vector_size(*(Vector **) (emitter + 0x1C)); i++) {
        leaf = vector_at(*(Vector **) (emitter + 0x1C), i);
        leaf->position[0] += leaf->velocity[0] * dt;
        leaf->position[1] += leaf->velocity[1] * dt;
        leaf->position[2] += leaf->velocity[2] * dt;
        leaf->velocity[0] += func_800DC178(-400.0f, 400.0f) * dt;
        leaf->velocity[2] += func_800DC178(-400.0f, 400.0f) * dt;
        leaf->rotation[0] += leaf->angular_velocity[0] * dt;
        leaf->rotation[1] += leaf->angular_velocity[1] * dt;
        leaf->rotation[2] += leaf->angular_velocity[2] * dt;
        leaf->angular_velocity[0] += func_800DC178(-300.0f, 300.0f) * dt;
        leaf->angular_velocity[1] += func_800DC178(-300.0f, 300.0f) * dt;
        leaf->angular_velocity[2] += func_800DC178(-300.0f, 300.0f) * dt;
        if (leaf->position[1] < player_pos[1] - 500.0f && !leaf->state) {
            vector_erase(*(Vector **) (emitter + 0x1C), i);
            i--;
        }
    }
    // One leaf per frame is checked against the 1320 distance limit.
    (*(s32 *) (emitter + 0x18))++;
    if (*(s32 *) (emitter + 0x18) < vector_size(*(Vector **) (emitter + 0x1C))) {
        leaf = vector_at(*(Vector **) (emitter + 0x1C), *(s32 *) (emitter + 0x18));
        if (func_800EEAD4(leaf->position, player_pos) > 1320.0f) {
            vector_erase(*(Vector **) (emitter + 0x1C), *(s32 *) (emitter + 0x18));
        }
    } else {
        *(s32 *) (emitter + 0x18) = 0;
    }
    if (func_800F1574((f32 *) (emitter + 0x38), dt)) {
        if (emitter[0x22] == 1 && !func_800A5490()) {
            func_80800000_fxleaves(emitter);
        }
        *(f32 *) (emitter + 0x38) = 0.1f;
    }
}
