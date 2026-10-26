#include "common.h"

s32 gcextra_entrypoint_0(void){
    func_800DA564(0x4EA, 3);
}

s32 gcextra_entrypoint_1() 
{
    return 0x5;
}

void gcextra_entrypoint_2(s32 param_0)
{
    s32 local_0;
    s32 local_1;

    local_0 = gcextra_entrypoint_0() + param_0;
    local_1 = gcextra_entrypoint_1();
    if (local_1 < local_0) {
        local_0 = local_1;
    }
    func_800DA7A8(0x4EA, local_0, 3);
    func_800D517C();
}
