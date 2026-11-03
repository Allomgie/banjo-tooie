#include "core2/1EC1380.h"

s16 func_800A8184(void);

extern Gfx D_80123340[];
extern s16 D_80127750;
extern s16 D_80127752;

typedef struct {
    s16 x;
    s16 y;
    s16 width;
    s16 height;
} ScissorRect;

typedef struct {
    // Scissor of the frame as a whole.
    ScissorRect frame_scissor;
    // Current active scissor.
    ScissorRect active_scissor;
} ScissorState;

extern ScissorState D_8012D5D0;
extern u32 D_8012D5E0;

// get_depth_buffer
void* func_8001A0A8();
// get_framebuffer? If so, why is it in core2 instead of core1 like from get_depth_buffer?
void* func_800A989C();


void func_800E7FB0(s32 x, s32 y, s32 width, s32 height);
void func_800E7FF8(Gfx** gfx, u32 geometry_mode);

void func_800E7A90(Gfx** gfx, s32 x, s32 y, s32 width, s32 height) {
    if ((x != D_8012D5D0.active_scissor.x) || (y != D_8012D5D0.active_scissor.y) || (width != D_8012D5D0.active_scissor.width) || (height != D_8012D5D0.active_scissor.height)) {
        gDPSetScissor((*gfx)++, G_SC_NON_INTERLACE, x, y, x + width, y + height);
        D_8012D5D0.active_scissor.x = x;
        D_8012D5D0.active_scissor.y = y;
        D_8012D5D0.active_scissor.width = width;
        D_8012D5D0.active_scissor.height = height;
    }
}

void func_800E7B88(Gfx** gfx) {
    gSPDisplayList((*gfx)++, OS_K0_TO_PHYSICAL(D_80123340));
    func_800E7FF8(gfx, G_CULL_BACK);
}

void func_800E7BC8(Gfx** gfx) {
    void* depth_buffer = func_8001A0A8();
    if (depth_buffer != NULL && func_800A8184() != 4) {
        gDPSetDepthImage((*gfx)++, OS_K0_TO_PHYSICAL(depth_buffer));
    }
}

void func_800E7C28(Gfx** gfx) {
    void* depth_buffer = func_8001A0A8();
    if (depth_buffer != NULL && (func_800A8184() != 4 || func_800EA358() != 0)) {
        gDPSetColorImage((*gfx)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_80127750, OS_K0_TO_PHYSICAL(depth_buffer));
        func_800E7A90(gfx, 0, 0, D_80127750, D_80127752);
        func_800BC5B0(gfx, 0, 0, D_80127750, D_80127752);
    }
}

void func_800E7CF4(Gfx** gfx) {
    gDPSetColorImage((*gfx)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_80127750, OS_K0_TO_PHYSICAL(func_800A989C()));
}

void func_800E7D4C(Gfx** gfx) {
    func_800E7A90(gfx, 0, 0, D_80127750, D_80127752);
    func_800BC580(gfx, 0, 0, D_80127750, D_80127752);
}

// apply_frame_scissor_impl
void func_800E7DAC(Gfx** gfx) {
    func_800E7A90(gfx, D_8012D5D0.frame_scissor.x, D_8012D5D0.frame_scissor.y, D_8012D5D0.frame_scissor.width, D_8012D5D0.frame_scissor.height);
}

void func_800E7DE4(Gfx** gfx, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void* depth_buffer = func_8001A0A8();
    if (depth_buffer != NULL) {
        gDPSetColorImage((*gfx)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_80127750, OS_K0_TO_PHYSICAL(depth_buffer));
        func_800BC5B0(gfx, arg1, arg2, arg3, arg4);
        func_800E7CF4(gfx);
    }
}

void func_800E7E70(Gfx** gfx) {
    func_800E7B88(gfx);
    func_800E7BC8(gfx);
    func_800E7C28(gfx);
    func_800E7CF4(gfx);
    func_800E7D4C(gfx);
    func_800E7DAC(gfx);
}

// apply_frame_scissor
void func_800E7EC0(Gfx** gfx) {
    gDPPipeSync((*gfx)++);
    func_800E7DAC(gfx);
}

// end_frame_displaylist
void func_800E7EF4(Gfx** gfx) {
    gDPFullSync((*gfx)++);
    gSPEndDisplayList((*gfx)++);
    func_800A9800();
}

void func_800E7F40(Gfx** gfx) {
    func_80014DD4(gfx);
}

// reset_scissor
void func_800E7F60() {
    // Seems like a chained assignment for x and y from the codegen, but doesn't work as one.
    D_8012D5D0.active_scissor.width = D_8012D5D0.active_scissor.height = 0;
    D_8012D5D0.active_scissor.y = D_8012D5D0.active_scissor.height;
    D_8012D5D0.active_scissor.x = D_8012D5D0.active_scissor.height;
    func_800E7FB0(0, 0, D_80127750, D_80127752);
}

// set_frame_scissor
void func_800E7FB0(s32 x, s32 y, s32 width, s32 height) {
    D_8012D5D0.frame_scissor.x = x;
    D_8012D5D0.frame_scissor.y = y;
    D_8012D5D0.frame_scissor.width = width;
    D_8012D5D0.frame_scissor.height = height;
}

// get_active_scissor
void func_800E7FCC(s32* arg0) {
    arg0[0] = D_8012D5D0.active_scissor.x;
    arg0[1] = D_8012D5D0.active_scissor.y;
    arg0[2] = D_8012D5D0.active_scissor.width;
    arg0[3] = D_8012D5D0.active_scissor.height;
}

// backface_culling_dl
extern Gfx D_80123418[];
// frontface_culling_dl
extern Gfx D_80123428[];

// set_face_culling_mode
void func_800E7FF8(Gfx** gfx, u32 geometry_mode) {
    D_8012D5E0 = geometry_mode;
    gSPSetGeometryMode((*gfx)++, geometry_mode);
    gSPSegment((*gfx)++, RSP_SEGMENT_FACE_CULLING, osVirtualToPhysical(geometry_mode == G_CULL_BACK ? D_80123418 : D_80123428));
}

// restore_face_culling_mode
void func_800E8078(Gfx** gfx) {
    gSPDisplayList((*gfx)++, RSP_SEGMENT_FACE_CULLING << 24);
}

/* TU-NOTE: the .data of this file (formerly asm/data/core2/1EC1380.data.s) is defined here in C.
 * Values are taken from the ROM. */
Gfx D_80123340[27] = { 0xDB060000, 0x0, 0xD9C0F9FA, 0x0, 0xDB040004, 0x1, 0xDB04000C, 0x1, 0xDB040014, 0xFFFF, 0xDB04001C, 0xFFFF, 0xE7000000, 0x0, 0xE2001E01, 0x0, 0xE3001801, 0x0, 0xE3001402, 0xC00, 0xE3000D01, 0x0, 0xE3001201, 0x2000, 0xE3000F00, 0x0, 0xE3001001, 0x0, 0xE3000C00, 0x80000, 0xDF000000, 0x0, 0xD9C0F9FA, 0x0, 0xD9FFFFFF, 0x200005, 0xD7000000, 0x0, 0xE7000000, 0x0, 0xE3000A01, 0x0, 0xE3000800, 0x0, 0xFCFFFFFF, 0xFFFE793C, 0xE2001E01, 0x0, 0xE3001801, 0xC0, 0xE200001C, 0x507858, 0xDF000000, 0x0 };
Gfx D_80123418[2] = { 0xD9FFFFFF, 0x400, 0xDF000000, 0x0 };
Gfx D_80123428[19] = { 0xD9FFFFFF, 0x200, 0xDF000000, 0x0, 0x0, 0x0, 0xE7000000, 0x0, 0xD9C0FFFA, 0x0, 0xD9FFFFFF, 0x200004, 0xD7000002, 0xFFFFFFFF, 0xE200001C, 0xF0A4000, 0xE3000A01, 0x0, 0xFC157E2A, 0xFFFFF3F9, 0xE3001201, 0x0, 0xE3000C00, 0x0, 0xFA000000, 0x78, 0xDF000000, 0x0, 0xE7000000, 0x0, 0xE3001201, 0x2000, 0xE3000C00, 0x80000, 0xDF000000, 0x0, 0x0, 0x0 };
