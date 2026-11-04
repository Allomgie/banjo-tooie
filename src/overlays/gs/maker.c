// Binary stream reader/writer for level setup files: tag matching and typed value/array reads.
#include "common.h"

// Level setup stream. Modes: 2 = asset, 3 = memory, 4 = growable write buffer.
extern s32 *heap_alloc(s32);
typedef struct {
    s32 pad_0;
    u8 *source;
    u8 *start;
    u8 *current;
    u8 *end;
    s32 mode;
} MakerStream30;
extern void *heap_realloc(void *, s32);

typedef struct {
    u8 pad_0[0x14];
    s32 mode;
    s32 peeked_tag;
} MakerSelectionState;

// Free the stream; asset streams release their asset.
int gsmaker_entrypoint_0(Actor *stream)
{
    if (*(s32 *) ((char *) stream + 0x14) == 2) {
        func_800D721C(*(s16 *) ((char *) stream + 0x20), 0);
        func_800D70F8(*(s16 *) ((char *) stream + 0x20), 0);
        func_800D6CEC(*(s16 *) ((char *) stream + 0x20));
    }
    heap_free(stream);
}

// Open an asset stream (mode 2); NULL if the asset does not load.
u8 *gsmaker_entrypoint_1(s32 asset_id)
{
    s32 data;
    u8 *stream;

    stream = heap_alloc(0x24);
    if (stream == NULL) {
        return NULL;
    }
    *(s32 *) ((s8 *) stream + 0x14) = 2;
    *(s32 *) ((s8 *) stream + 0x18) = -1;
    *(s32 *) ((s8 *) stream + 0x1C) = -1;
    *(s16 *) ((s8 *) stream + 0x20) = (s16) asset_id;
    data = func_800D674C(*(s16 *) ((s8 *) stream + 0x20));
    *(s32 *) ((s8 *) stream + 0) = data;
    *(s32 *) ((s8 *) stream + 4) = data;
    func_800D70D0(1);
    func_800D71F4(1);
    if (*(s32 *) ((s8 *) stream + 0) != 0) {
        return stream;
    }
    heap_free(stream);
    return NULL;
}

// Open the setup stream of a map (asset id map + 0x955).
s32 gsmaker_entrypoint_2(s32 map)
{
    gsmaker_entrypoint_1(map + 0x955);
}

s32 gsmaker_entrypoint_3(s32 base, s32 offset)
{
    s32 asset_id = base + offset;
    gsmaker_entrypoint_1(asset_id);
}

// Open a read stream over a memory block (mode 3).
s32 *gsmaker_entrypoint_4(s32 data, s32 size)
{
    s32 *stream = heap_alloc(0x24);
    stream[5] = 3;
    stream[6] = -1;
    stream[7] = -1;
    stream[2] = data;
    stream[3] = data;
    stream[4] = data + size;
}

// Open a growable write stream (mode 4), initial buffer 0x20 bytes.
u8 *gsmaker_entrypoint_5(void)
{
    u8 *stream;
    u8 *buffer;

    stream = heap_alloc(0x24);
    *(s32 *) ((s8 *) stream + 0x14) = 4;
    *(s32 *) ((s8 *) stream + 0x18) = -1;
    *(s32 *) ((s8 *) stream + 0x1C) = -1;
    buffer = heap_alloc(0x20);
    *(u8 **) ((s8 *) stream + 8) = buffer;
    *(u8 **) ((s8 *) stream + 0xC) = buffer;
    *(s32 *) ((s8 *) stream + 0x10) = (s32) (buffer + 0x20);
    return stream;
}

// Take the written data out of a write stream and free the stream.
void gsmaker_entrypoint_6(void *stream, void **out_data, s32 *out_size)
{
    s32 size;
    // Matching: the 64-bit mask is needed for the match.
    size = (*(s32 *) ((char *) stream + 0xC) - *(s32 *) ((char *) stream + 0x8)) &
           0xFFFFFFFFFFFFFFFFu;
    *out_size = size;
    *out_data = heap_realloc(*(void **) ((char *) stream + 0x8), size);
    *(s32 *) ((char *) stream + 0x8) = 0;
    gsmaker_entrypoint_0(stream);
}

void gsmaker_entrypoint_13();

// Read (modes 2, 3) or write (mode 4) one byte.
void gsmaker_entrypoint_7(s32 stream, s32 buf)
{
    gsmaker_entrypoint_13(stream, buf, 0x1);
}

int gsmaker_entrypoint_8(int stream, int buf, int count)
{
    while (count > 0) {
        gsmaker_entrypoint_7(stream, buf);
        count--;
        buf++;
    }
}

void gsmaker_entrypoint_9(s32 stream, s32 buf)
{
    gsmaker_entrypoint_13(stream, buf, 0x4);
}

void gsmaker_entrypoint_10(s32 stream, s32 buf, s32 count)
{
    while (count > 0) {
        gsmaker_entrypoint_9(stream, buf);
        count--;
        buf += 4;
    }
}

void gsmaker_entrypoint_11(s32 stream, s32 buf)
{
    gsmaker_entrypoint_13(stream, buf, 0x4);
}

s32 gsmaker_entrypoint_12(s32 stream, s32 buf, s32 count)
{
    while (count > 0) {
        gsmaker_entrypoint_11(stream, buf);
        count--;
        buf += 4;
    }
}

// Copy size bytes between buf and the stream; mode 4 doubles its buffer until the data fits.
void gsmaker_entrypoint_13(MakerStream30 *stream, u8 *buf, s32 size)
{
    s32 used;
    s32 capacity;
    if (stream->mode == 2) {
        rare_memcpy(buf, stream->source, size);
        stream->source += size;
    } else if (stream->mode == 3) {
        rare_memcpy(buf, stream->current, size);
        stream->current += size;
    } else if (stream->mode == 4) {
        if (stream->end < stream->current + size) {
            capacity = (stream->end - stream->start) * 2;
            used = stream->current - stream->start;
            while (stream->start + capacity < stream->current + size)
                capacity *= 2;
            stream->start = heap_realloc(stream->start, capacity);
            stream->current = stream->start + used;
            stream->end = stream->start + capacity;
        }
        rare_memcpy(stream->current, buf, size);
        stream->current += size;
    }
}

void gsmaker_entrypoint_14(s32 stream, s32 buf)
{
    gsmaker_entrypoint_13(stream, buf, 0x2);
}

void gsmaker_entrypoint_15(int stream, int buf, int count)
{
    while (count > 0) {
        gsmaker_entrypoint_14(stream, buf);
        count--;
        buf += 2;
    }
}

// Tag match with one-tag lookahead. Returns 1 if the next tag is `tag`.
// Matching: old-style (K&R) definition.
s32 gsmaker_entrypoint_16(stream, tag)
MakerSelectionState *stream;
s32 tag;
{
    u8 read_tag;
    read_tag = tag;
    if (stream->mode == 1 || stream->mode == 4) {
        gsmaker_entrypoint_7(stream, &read_tag);
        return 1;
    }
    if (stream->peeked_tag == -1) {
        gsmaker_entrypoint_7(stream, &read_tag);
        if (tag == read_tag)
            return 1;
        stream->peeked_tag = read_tag;
        return 0;
    }
    if (tag == stream->peeked_tag) {
        stream->peeked_tag = -1;
        return 1;
    }
    return 0;
}

// 17..25: expect `tag`, then read/write a value (17, 19, 21, 24) or an array (18, 20, 22, 23, 25).
int gsmaker_entrypoint_17(s32 stream, s32 tag, s32 buf)
{
    if (!gsmaker_entrypoint_16(stream, tag)) {
        return 0;
    }
    {
        gsmaker_entrypoint_7(stream, buf);
        return 1;
    }
}

s32 gsmaker_entrypoint_18(enum gsworld_map_e stream, enum gsworld_exit_e tag, s32 buf,
                          s32 count)
{
    // Matching: the extra copy of buf is needed for the match.
    s32 buf_copy;
    buf_copy = buf;
    if (!gsmaker_entrypoint_16(stream, tag, buf_copy, count)) {
        return 0;
    }
    gsmaker_entrypoint_8(stream, buf_copy, count);
    return 1;
}

int gsmaker_entrypoint_19(s32 stream, s32 tag, s32 buf)
{
    if (!gsmaker_entrypoint_16(stream, tag)) {
        return 0;
    }
    {
        gsmaker_entrypoint_9(stream, buf);
        return 1;
    }
}

s32 gsmaker_entrypoint_20(enum gsworld_map_e stream, enum gsworld_exit_e tag, s32 buf,
                          s32 count)
{
    // Matching: the extra copy of buf is needed for the match.
    s32 buf_copy;
    buf_copy = buf;
    if (!gsmaker_entrypoint_16(stream, tag, buf_copy, count)) {
        return 0;
    }
    gsmaker_entrypoint_10(stream, buf_copy, count);
    return 1;
}

int gsmaker_entrypoint_21(s32 stream, s32 tag, s32 buf)
{
    if (!gsmaker_entrypoint_16(stream, tag)) {
        return 0;
    }
    {
        gsmaker_entrypoint_11(stream, buf);
        return 1;
    }
}

s32 gsmaker_entrypoint_22(enum gsworld_map_e stream, enum gsworld_exit_e tag, s32 buf,
                          s32 count)
{
    // Matching: the extra copy of buf is needed for the match.
    s32 buf_copy;
    buf_copy = buf;
    if (!gsmaker_entrypoint_16(stream, tag, buf_copy, count)) {
        return 0;
    }
    gsmaker_entrypoint_12(stream, buf_copy, count);
    return 1;
}

s32 gsmaker_entrypoint_23(enum gsworld_map_e stream, enum gsworld_exit_e tag, s32 buf,
                          s32 size)
{
    // Matching: the extra copy of buf is needed for the match.
    s32 buf_copy;
    buf_copy = buf;
    if (!gsmaker_entrypoint_16(stream, tag, buf_copy, size)) {
        return 0;
    }
    gsmaker_entrypoint_13(stream, buf_copy, size);
    return 1;
}

int gsmaker_entrypoint_24(s32 stream, s32 tag, s32 buf)
{
    if (!gsmaker_entrypoint_16(stream, tag)) {
        return 0;
    }
    {
        gsmaker_entrypoint_14(stream, buf);
        return 1;
    }
}

s32 gsmaker_entrypoint_25(enum gsworld_map_e stream, enum gsworld_exit_e tag, s32 buf,
                          s32 count)
{
    // Matching: the extra copy of buf is needed for the match.
    s32 buf_copy;
    buf_copy = buf;
    if (!gsmaker_entrypoint_16(stream, tag, buf_copy, count)) {
        return 0;
    }
    gsmaker_entrypoint_15(stream, buf_copy, count);
    return 1;
}
