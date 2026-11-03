#include "common.h"

extern s32 D_8012AE74;
extern int D_8012AE70[];

// TU-NOTE: D_8012AE70 is the current collision querier token: an s16 mode (1 = player)
// followed by a pointer, which D_8012AE74 aliases.

// Sets the current collision querier.
void func_800CB840(s32 mode, s32 querier)
{
    *(s16 *) (s32 *) D_8012AE70 = (s16) mode;
    *(s32 *) ((char *) (s32 *) D_8012AE70 + 4) = querier;
}

// Returns the mode and stores the querier pointer in *querier_out if it is not NULL.
int func_800CB854(s32 *querier_out)
{
    if (querier_out != 0) {
        *querier_out = D_8012AE74;
    }
    return *(s16 *) D_8012AE70;
}

// Clears the current collision querier.
int func_800CB870()
{
    *(s16 *) D_8012AE70 = 0;
    D_8012AE70[1] = 0;
}
