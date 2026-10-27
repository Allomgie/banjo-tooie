#include "common.h"

extern OSMesgQueue *func_80016928(void);
extern void func_80016934(s32);
extern void cic_send_challenge();
extern void cic_read_response(OSMesgQueue *);
extern void *heap_alloc(s32);
extern u8 D_80079D70[];

void func_80800000_gldbDll(u8 *param_0, s32 param_1)
{
    s32 local_1;
    u8 local_0[16];
    OSMesgQueue *local_3;
    u16 local_2;

    local_3 = func_80016928();
    for (local_1 = 0; local_1 < 14; local_1 += 2) {
        local_2 = (param_1 >> local_1) | (param_1 << (16 - local_1));
        local_0[local_1] = local_2;
        local_0[local_1 + 1] = local_2 & 0xFF00;
    }
    local_0[14] = 0;
    local_0[15] = 2;
    for (local_1 = 0; local_1 < 16; local_1++) {
        param_0[local_1] = 0;
    }
    func_80016934(5);
    cic_send_challenge(local_0, local_3);
    osRecvMesg(local_3, NULL, OS_MESG_BLOCK);
    cic_read_response(local_3);
    osRecvMesg(local_3, NULL, OS_MESG_BLOCK);
    func_8001E170(param_0);
    func_80016934(0);
}

void func_808000E8_gldbDll(u8 *param_0, s32 param_1, s32 param_2)
{
    u8 local_0[14];
    s32 local_1;
    func_80800000_gldbDll(local_0, param_1);
    for (local_1 = 0; local_1 < param_2; local_1++) param_0[local_1] = param_0[local_1] ^ local_0[local_1 % 14];
}

void *gldbDll_entrypoint_0(s32 param_0, s32 *param_1)
{
    s32 *local_2;
    s32 local_1;
    s32 local_0;

    local_1 = func_800D5DB8(param_0);
    local_0 = local_1;
    if (local_1 & 1) {
        local_1++;
    }
    local_2 = heap_alloc(local_1);
    rom_dma_read(local_2, func_800D5A6C(param_0), local_1);
    func_808000E8_gldbDll(local_2, param_0 - 0x955, local_0);
    local_0 = *local_2;
    local_0 = (local_0 >> 16) * 0x10;
    *param_1 = local_0;
    local_0 = (s32)heap_alloc(local_0);
    func_8001C2AC(local_2, local_0);
    heap_free(local_2);
    return (void *)local_0;
}

int gldbDll_entrypoint_1()
{
  int local_0;
  int new_var;
  for (local_0 = 0; local_0 < 4; local_0++) {
    new_var = local_0 * 8;
    func_800DA544(((int) (_gleeprom_entrypoint_0() & (0xFF << new_var)) >> new_var) + 0x9C4);
  }

  for (local_0 = 0; local_0 < 4; local_0++)
  {
    new_var = local_0 * 8;
    func_800DA544(((int) (_glreflight_entrypoint_0() & (0xFF << new_var)) >> new_var) + 0x9C4);
  }

}

void gldbDll_entrypoint_2(void)
{
    s32 local_0;
    u32 local_1;
    u32 local_2;

    local_2 = _gleeprom_entrypoint_0();
    local_1 = (*(u32 *)(D_80079D70 + 0x1EC) | _glreflight_entrypoint_0()) | local_2;
    for (local_0 = 0; local_0 < 8; local_0++) {
        func_800DA3B8(local_0 + 0x648, ((1 << local_0) & local_1) >> local_0);
    }
    for (local_0 = 8; local_0 < 16; local_0++) {
        func_800DA3B8(local_0 + 0x658, ((1 << local_0) & local_1) >> local_0);
    }
    for (local_0 = 16; local_0 < 24; local_0++) {
        func_800DA3B8(local_0 + 0x670, ((1 << local_0) & local_1) >> local_0);
    }
    for (local_0 = 24; local_0 < 32; local_0++) {
        func_800DA3B8(local_0 + 0x680, ((1 << local_0) & local_1) >> local_0);
    }
}
