// Deferred-call queue API (chbaddiesetup): entrypoints 0-6 queue a call with 0..6 int args so
// actors spawn after the update loop; 7-10 are by-value spawn wrappers.
#include "common.h"

// Deferred-call queue: each record holds a function pointer, up to 6 int args and the arg count.
// The queue itself is owned by core2/1E7F4D0 and holds at most 0x16 records.
typedef struct {
    s32 func;
    s32 arg0;
    u8 pad_8[0x14];
    s32 argc;
} BaddieSetupRecord;
typedef struct {
    BaddieSetupRecord *records;
    u8 count;
} BaddieSetupQueue;
extern BaddieSetupQueue *func_800A5D60(void);
typedef struct {
    s32 words[5];
    u8 pad_14[8];
    s32 argc;
} BaddieSetupEntry;
typedef struct {
    BaddieSetupEntry *entries;
    u8 count;
} BaddieSetupList;
typedef struct {
    s32 words[7];
    s32 argc;
} BaddieSetupEntry27;
typedef struct {
    BaddieSetupEntry27 *entries;
    u8 count;
} BaddieSetupList27;
typedef struct {
    s32 id;
    f32 x, y, z;
} ArgS;
extern void _chbounce_entrypoint_6(s32, f32 *);
extern void _chbounce_entrypoint_2(f32);

// Returns 1 if the queue exists and has room for another record.
int func_80800000_chbaddiesetup(s32 queue[3])
{
    if (!queue[0]) {
        return 0;
    }
    if (((unsigned char *) queue)[4] == 0x16) {
        return 0;
    }
    return 1;
}

void chbaddiesetup_entrypoint_0(s32 func)
{
    BaddieSetupQueue *queue;

    queue = func_800A5D60();
    if (func_80800000_chbaddiesetup(queue)) {
        queue->records[queue->count].func = func;
        queue->records[queue->count].argc = 0;
        queue->count++;
    }
}

void chbaddiesetup_entrypoint_1(s32 func, s32 arg0)
{
    BaddieSetupQueue *queue;

    queue = func_800A5D60();
    if (func_80800000_chbaddiesetup(queue)) {
        queue->records[queue->count].func = func;
        queue->records[queue->count].arg0 = arg0;
        queue->records[queue->count].argc = 1;
        queue->count++;
    }
}

void chbaddiesetup_entrypoint_2(s32 func, s32 arg0, s32 arg1)
{
    u8 *queue;
    u8 *queue_tmp;

    // Matching: the extra temporary is needed for the match.
    queue_tmp = func_800A5D60();
    queue = queue_tmp;
    if (func_80800000_chbaddiesetup(queue_tmp) != 0) {
        *(s32 *) ((u8 *) *(s32 **) queue + (*(u8 *) (queue + 4) << 5)) = func;
        *(s32 *) ((u8 *) *(s32 **) queue + (*(u8 *) (queue + 4) << 5) + 4) = arg0;
        *(s32 *) ((u8 *) *(s32 **) queue + (*(u8 *) (queue + 4) << 5) + 8) = arg1;
        *(s32 *) ((u8 *) *(s32 **) queue + (*(u8 *) (queue + 4) << 5) + 0x1C) = 2;
        *(u8 *) (queue + 4) = *(u8 *) (queue + 4) + 1;
    }
}

void chbaddiesetup_entrypoint_3(s32 func, s32 arg0, s32 arg1, s32 arg2)
{
    u8 *queue;
    u8 *queue_tmp;

    // Matching: the extra temporary is needed for the match.
    queue_tmp = func_800A5D60();
    queue = queue_tmp;
    if (func_80800000_chbaddiesetup(queue_tmp) != 0) {
        *(s32 *) (*(s32 *) queue + (queue[4] << 5)) = func;
        *(s32 *) (*(s32 *) queue + (queue[4] << 5) + 4) = arg0;
        *(s32 *) (*(s32 *) queue + (queue[4] << 5) + 8) = arg1;
        *(s32 *) (*(s32 *) queue + (queue[4] << 5) + 0xC) = arg2;
        *(s32 *) (*(s32 *) queue + (queue[4] << 5) + 0x1C) = 3;
        queue[4] = (u8) (queue[4] + 1);
    }
}

void chbaddiesetup_entrypoint_4(s32 func, s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    BaddieSetupList *queue;
    queue = (BaddieSetupList *) func_800A5D60();
    if (func_80800000_chbaddiesetup((BaddieSetupQueue *) queue)) {
        queue->entries[queue->count].words[0] = func;
        queue->entries[queue->count].words[1] = arg0;
        queue->entries[queue->count].words[2] = arg1;
        queue->entries[queue->count].words[3] = arg2;
        queue->entries[queue->count].words[4] = arg3;
        queue->entries[queue->count].argc = 4;
        queue->count++;
    }
}

void chbaddiesetup_entrypoint_5(s32 func, s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                                s32 arg4)
{
    u8 *queue;
    queue = func_800A5D60();
    if (func_80800000_chbaddiesetup(queue) != 0) {
        *(s32 *) ((s8 *) *(s32 **) queue + (queue[4] << 5)) = func;
        *(s32 *) ((s8 *) *(s32 **) queue + (queue[4] << 5) + 4) = arg0;
        *(s32 *) ((s8 *) *(s32 **) queue + (queue[4] << 5) + 8) = arg1;
        *(s32 *) ((s8 *) *(s32 **) queue + (queue[4] << 5) + 0xC) = arg2;
        *(s32 *) ((s8 *) *(s32 **) queue + (queue[4] << 5) + 0x10) = arg3;
        *(s32 *) ((s8 *) *(s32 **) queue + (queue[4] << 5) + 0x14) = arg4;
        *(s32 *) ((s8 *) *(s32 **) queue + (queue[4] << 5) + 0x1C) = 5;
        queue[4] = queue[4] + 1;
    }
}

void chbaddiesetup_entrypoint_6(s32 func, s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                                s32 arg4, s32 arg5)
{
    BaddieSetupList27 *queue;

    queue = (BaddieSetupList27 *) func_800A5D60();
    if (func_80800000_chbaddiesetup((BaddieSetupQueue *) queue)) {
        queue->entries[queue->count].words[0] = func;
        queue->entries[queue->count].words[1] = arg0;
        queue->entries[queue->count].words[2] = arg1;
        queue->entries[queue->count].words[3] = arg2;
        queue->entries[queue->count].words[4] = arg3;
        queue->entries[queue->count].words[5] = arg4;
        queue->entries[queue->count].words[6] = arg5;
        queue->entries[queue->count].argc = 6;
        queue->count++;
    }
}

void chbaddiesetup_entrypoint_7(ArgS spawn)
{
    f32 pos[3];
    pos[0] = spawn.x;
    pos[1] = spawn.y;
    pos[2] = spawn.z;
    func_80108474(spawn.id, pos, 0);
}

void chbaddiesetup_entrypoint_8(s32 id, s32 x, s32 y, s32 z)
{
    s32 pos[3];
    pos[0] = (&id)[1];
    pos[1] = (&id)[2];
    pos[2] = (&id)[3];
    func_80108454(id, pos, 0);
}

void chbaddiesetup_entrypoint_9(ArgS spawn)
{
    f32 pos[3];
    pos[0] = spawn.x;
    pos[1] = spawn.y;
    pos[2] = spawn.z;
    _chbounce_entrypoint_6(spawn.id, pos);
}

void chbaddiesetup_entrypoint_10(ArgS spawn, f32 speed)
{
    f32 pos[3];
    pos[0] = spawn.x;
    pos[1] = spawn.y;
    pos[2] = spawn.z;
    _chbounce_entrypoint_2(speed);
    _chbounce_entrypoint_6(spawn.id, pos);
}
