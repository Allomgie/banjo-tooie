#include "common.h"

typedef struct { u8 buttons; u8 stick; u16 held; u8 state; u8 unused; } RecordedInput;
typedef struct { RecordedInput *records; void *unused; s32 cursor; s32 count; RecordedInput fallback; } RecordPlaybackState;
typedef struct { u16 held; u8 buttons; u8 stick; } PlaybackInput;
struct glrecord_entrypoint { s32 unk0; s32 unk8; u32 unkC; };
extern struct glrecord_entrypoint D_8012D5B0;
int glrecord_entrypoint_4();

s32 glrecord_entrypoint_0(PlaybackInput *param_0, s32 *param_1)
{
    RecordPlaybackState *local_0 = (RecordPlaybackState *)((s32 *) &D_8012D5B0);
    RecordedInput *local_1;
    s32 local_2;

    local_1 = &local_0->records[local_0->cursor++];
    local_2 = local_0->cursor < local_0->count;
    if (!local_2) {
        local_1 = &local_0->fallback;
    }
    param_0->buttons = local_1->buttons;
    param_0->stick = local_1->stick;
    param_0->held = local_1->held;
    *param_1 = local_1->state;
    return local_2;
}

void glrecord_entrypoint_1(s32 param_0, u32 param_1, s32 param_2) {
    (*(s32 *)((s8 *)(&D_8012D5B0) + (0))) = param_0;
    (*(u32 *)((s8 *)(&D_8012D5B0) + (0xC))) = (u32) (param_1 / 6U);
    (*(s32 *)((s8 *)(&D_8012D5B0) + (8))) = 0;
}

int glrecord_entrypoint_2()
{
    int *ptr = &((int *) &D_8012D5B0)[2];
    return *ptr * 6;
}

void glrecord_entrypoint_3(s32 param_0, s32 param_1)
{
  s32 local_0;
  if ((*((s32 **) (((s8 *) (((s32 *) &D_8012D5B0))) + 4))) != 0)
  {
    glrecord_entrypoint_4();
  }
  *((s8 *) (((s8 *) (((s32 *) &D_8012D5B0))) + 0x14)) = 2;
  func_800D5B24();
  *((s32 **) (((s8 *) (((s32 *) &D_8012D5B0))) + 4)) = func_800D5B34((_gcsectionDll_entrypoint_4(param_0) + (param_1 * 0xD)) + 0xC57);
  local_0 = *(*((s32 **) (((s8 *) (((s32 *) &D_8012D5B0))) + 4)));
  glrecord_entrypoint_1((u8 *)(*((s32 **) (((s8 *) (((s32 *) &D_8012D5B0))) + 4))) + 4, local_0, 0);
}

int glrecord_entrypoint_4()
{
  if (((s32 *) &D_8012D5B0)[1] != 0)
  {
    func_800D56C4(((s32 *) &D_8012D5B0)[1]);
    ((s32 *) &D_8012D5B0)[1] = 0;
  }
}
