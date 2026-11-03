#include "common.h"

// Zeroes all 23 points of the buffer.
void func_800DBEB0(s32 buffer)
{
    unsigned int point;
    s32 end;
    point = buffer + 4;
    end = buffer + 0x118;
    if (point < end) {
        do {
            func_800EFD24(point);
            point += 0xC;
        } while (point < end);
    }
}

// Copies point `index` into out.
void func_800DBEFC(s32 buffer, s32 index, s32 out)
{
    s32 base = buffer;
    s32 offset = index * 12;
    func_800EE7F8(out, base + offset + 4);
}

void func_800DBF38(s32 buffer, s32 index, s32 out)
{
    s32 base = buffer;
    s32 offset = index * 12;
    func_800EE904(out, base + offset + 4);
}

// Outputs the normalized difference of two points.
void func_800DBF74(s32 buffer, s32 *index_b, s32 index_a, s32 out)
{
    s32 base = buffer;
    s32 offset_a = index_a * 12;
    // Matching: the "^ 0" is needed for the match.
    s32 offset_b = ((s32) index_b ^ 0) * 12;
    func_800EFB24(out, (base + offset_a) + 4, (base + offset_b) + 4);
    func_800EF2A0(out);
}

void func_800DBFD8(void *arg0)
{
    heap_free(arg0);
}

// Allocates the 0x118-byte buffer: 23 vec3 points at +4.
int func_800DBFF8()
{
    void *buffer;
    buffer = heap_alloc(0x118);
    // Matching: the "| 0" is needed for the match.
    func_800DBEB0((s32) buffer | 0);
    return (int) buffer;
}

// Stores a point at `index`.
void func_800DC028(s32 buffer, s32 index, s32 point)
{
    // Matching: needed for the match.
    func_800EE7F8((buffer + (index * (0xC & 0xFFu))) + 4, point);
}

s32 func_800DC060(s32 buffer)
{
    if (buffer != 0) {
        buffer = (s32) defrag((void *) buffer);
    }
    return buffer;
}
