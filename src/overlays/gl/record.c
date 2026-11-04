// Demo input playback for attract mode: loads a recorded input stream, feeds one record per frame.
#include "common.h"

typedef struct {
    u8 buttons;
    u8 stick;
    u16 held;
    u8 state;
    u8 unused;
} RecordedInput;
typedef struct {
    RecordedInput *records;
    void *unused;
    s32 cursor;
    s32 count;
    RecordedInput fallback;
} RecordPlaybackState;
typedef struct {
    u16 held;
    u8 buttons;
    u8 stick;
} PlaybackInput;
struct glrecord_entrypoint {
    s32 unk_0;
    s32 unk_8;
    u32 unk_C;
};
extern struct glrecord_entrypoint D_8012D5B0;
int glrecord_entrypoint_4();

// Feeds the next recorded input; the fallback record is used past the end.
s32 glrecord_entrypoint_0(PlaybackInput *out_input, s32 *out_state)
{
    RecordPlaybackState *playback = (RecordPlaybackState *) (s32 *) &D_8012D5B0;
    RecordedInput *record;
    s32 has_more;

    record = &playback->records[playback->cursor++];
    has_more = playback->cursor < playback->count;
    if (!has_more) {
        record = &playback->fallback;
    }
    out_input->buttons = record->buttons;
    out_input->stick = record->stick;
    out_input->held = record->held;
    *out_state = record->state;
    return has_more;
}

void glrecord_entrypoint_1(s32 records, u32 size, s32 unused)
{
    *(s32 *) ((s8 *) &D_8012D5B0 + 0) = records;
    *(u32 *) ((s8 *) &D_8012D5B0 + 0xC) = (u32) (size / 6U);
    *(s32 *) ((s8 *) &D_8012D5B0 + 8) = 0;
}

int glrecord_entrypoint_2()
{
    int *cursor_ptr = &((int *) &D_8012D5B0)[2];
    return *cursor_ptr * 6;
}

void glrecord_entrypoint_3(s32 map, s32 demo_index)
{
    s32 size;
    if (*(s32 **) ((s8 *) (s32 *) &D_8012D5B0 + 4) != 0) {
        glrecord_entrypoint_4();
    }
    *(s8 *) ((s8 *) (s32 *) &D_8012D5B0 + 0x14) = 2;
    func_800D5B24();
    *(s32 **) ((s8 *) (s32 *) &D_8012D5B0 + 4) =
        func_800D5B34((_gcsectionDll_entrypoint_4(map) + (demo_index * 0xD)) + 0xC57);
    size = **(s32 **) ((s8 *) (s32 *) &D_8012D5B0 + 4);
    glrecord_entrypoint_1((u8 *) *(s32 **) ((s8 *) (s32 *) &D_8012D5B0 + 4) + 4, size, 0);
}

int glrecord_entrypoint_4()
{
    if (((s32 *) &D_8012D5B0)[1] != 0) {
        func_800D56C4(((s32 *) &D_8012D5B0)[1]);
        ((s32 *) &D_8012D5B0)[1] = 0;
    }
}
