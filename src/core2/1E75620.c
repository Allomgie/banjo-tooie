#include "core2/1E75620.h"
#include <ultra64.h>
#include "types.h"

extern void bastatetimer_set(void *, int, f32);
extern s32 bastatetimer_isDone(void *, s32);

s32 func_8009BD30()
{
    return 0x1;
}

// Damage-vulnerability mode byte at player+0xD4: 1 = vulnerable, 3 = temporarily invulnerable.
// Invulnerability ends when state timer 4 expires.
void func_8009BD38(void *player, s32 mode)
{
    ((s8 *) *(void **) ((char *) player + 0xD4))[0] = mode;
}

s32 func_8009BD44(void *player)
{
    return ((u8 *) *(void **) ((char *) player + 0xD4))[0];
}

void func_8009BD50(void *player)
{
    *(u8 *) *(void **) ((char *) player + 0xD4) = 0;
    func_8009BD38(player, 1);
    bastatetimer_clear(player, 4);
}

// Invulnerable for the default 0.6 s.
void func_8009BD88(PlayerState *player)
{
    func_8009BDAC(player, 0.6f);
}

void func_8009BDAC(PlayerState *player, f32 duration)
{
    bastatetimer_set(player, 4, duration);
    func_8009BD38(player, 3);
}

// Called every frame; reverts to vulnerable once the timer is done.
void func_8009BDE4(void *player)
{
    if (bastatetimer_isDone(player, 4)) {
        func_8009BD38(player, 1);
    }
}
