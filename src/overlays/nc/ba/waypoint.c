#include "common.h"

typedef struct { f32 local_0[3]; f32 local_1[3]; f32 local_2; s32 pad_0; } CameraWaypoint61;
typedef struct { s32 local_0; CameraWaypoint61 local_1[4]; } CameraWaypointList61;
typedef struct { u8 pad_0[0x5C]; CameraWaypointList61 *local_0; } CameraWaypointOwner61;
typedef struct { f32 local_0[3]; f32 local_1[3]; f32 local_2; f32 key; } CameraWaypoint62;
typedef struct { s32 local_0; CameraWaypoint62 local_1[4]; } CameraWaypointList62;
typedef struct { u8 pad_0[0x5C]; CameraWaypointList62 *local_0; } CameraWaypointOwner62;
extern f32 func_800EEAD4(f32 *, f32 *);
extern void aligned4_memcpy(void *, void *, s32);
extern f32 func_800EEAA4(f32 *, f32 *);
extern void func_800EE7F8(f32 *, f32 *);

s32 ncbawaypoint_entrypoint_0() 
{
    return 0x84;
}

void ncbawaypoint_entrypoint_1(u8 *param_0) {
    *(*(s32 **)((s8 *)(param_0) + (0x5C))) = 0;
}

s32 ncbawaypoint_entrypoint_2(CameraWaypointOwner61 *param_0, f32 *param_1, f32 *param_2, f32 param_3)
{
    CameraWaypoint61 *local_0;

    if (param_0->local_0->local_0 >= 4) {
        return 0;
    }
    local_0 = &param_0->local_0->local_1[param_0->local_0->local_0];
    func_800EE7F8(local_0->local_0, param_1);
    func_800EE7F8(local_0->local_1, param_2);
    local_0->local_2 = param_3;
    param_0->local_0->local_0++;
    return 1;
}

f32 ncbawaypoint_entrypoint_3(CameraWaypointOwner62 *this, f32 *pos, f32 *target)
{
    CameraWaypoint62 *end;
    CameraWaypoint62 *p;
    CameraWaypoint62 *q;
    CameraWaypoint62 tmp;
    f32 d1;
    f32 d2;
    f32 sum;

    sum = 0.0f;
    if (this->local_0->local_0 != 0) {
    end = &this->local_0->local_1[this->local_0->local_0];
    for (p = this->local_0->local_1; p < end; p++) {
        p->key = func_800EEAD4(p->local_0, pos);
    }
    for (p = this->local_0->local_1 + 1; p < end; p++) {
        q = p - 1;
        aligned4_memcpy(&tmp, p, sizeof(CameraWaypoint62));
        while (q >= this->local_0->local_1 && tmp.key < q->key) {
            aligned4_memcpy(q + 1, q, sizeof(CameraWaypoint62));
            q--;
        }
        aligned4_memcpy(q + 1, &tmp, sizeof(CameraWaypoint62));
    }
    for (p = this->local_0->local_1; p < end; p++) {
        d1 = func_800EEAA4(target, p->local_1) - p->local_2;
        d2 = func_800EEAA4(pos, p->local_1) - p->local_2;
        if ((d2 <= 0.0f && d1 <= 0.0f) || (0.0f <= d2 && 0.0f <= d1)) {
            continue;
        }
        sum += func_800EEAD4(pos, p->local_0);
        func_800EE7F8(pos, p->local_0);
    }
    }
    return sum;
}
