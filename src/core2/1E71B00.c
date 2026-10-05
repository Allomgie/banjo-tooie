#include "common.h"

#define STATE(p) (*(LocalState **)((u8 *)(p)+0xAC))
#define QQ (*(S_987CC **)((u8 *)param_0 + 0xE0))
extern void func_800DFFA0(s32,s32,f32 *);
extern void func_800DFF64(s32,s32,f32 *);
extern void func_800DFFDC(s32,s32,f32 *);
typedef struct { f32 angles[4], scale[3], rotation[3]; u8 angleActive, scaleActive, rotationActive, pad2B; f32 factor; } LocalState;
extern void func_800EFA4C(f32 *,f32,f32,f32);
extern u8 D_80117E9C[];
extern u8 D_80117E90[];
extern int D_80117EB0;
typedef struct { u8 pad0[0x28]; f32 unk28; u8 unk2C; } S_987CC;
extern f32 func_800D8FF8(void *);
extern f32 func_800F0E00(f32, f32);
extern s32 func_800C6E38(s32);
extern void func_8009E7C8();
extern f32 D_80124E20;
void func_80098480();
void func_80098494(u8 *param_0, f32 param_1, f32 param_2, f32 param_3, f32 param_4);
void func_800984CC();
void func_800984F0();
int func_80098520(s32 param_0, f32 param_1);

s32 func_80098210() 
{
    return 0x30;
}

void func_80098218(void *param_0, s32 param_1)
{
    f32 local_0[3];
    f32 local_1;
    switch (func_80092B80(param_0)) {
    case 0x607: case 0x608:
        if (STATE(param_0)->angleActive) {
            func_800EFD24(local_0);
            local_0[0] = STATE(param_0)->angles[0];
            func_800DFFDC(param_1, 0x2C, local_0);
            local_0[0] = STATE(param_0)->angles[1];
            func_800DFFDC(param_1, 0x2D, local_0);
            local_0[0] = STATE(param_0)->angles[2];
            func_800DFFDC(param_1, 0x2E, local_0);
            local_0[0] = STATE(param_0)->angles[3];
            func_800DFFDC(param_1, 0x3D, local_0);
        }
        if (STATE(param_0)->rotationActive) func_800DFFA0(param_1, 0x3C, STATE(param_0)->rotation);
        if (STATE(param_0)->scaleActive) {
            func_800DFF64(param_1, 0x3C, STATE(param_0)->scale);
            if (STATE(param_0)->scale[0] == STATE(param_0)->scale[1] && STATE(param_0)->scale[1] == STATE(param_0)->scale[2] && STATE(param_0)->scale[2] == 1.0f)
                STATE(param_0)->scaleActive = 0;
        }
        if (STATE(param_0)->factor != 1.0f) {
            func_800DFC20(param_1, 0x6C, local_0);
            local_1 = STATE(param_0)->factor;
            func_800EFA4C(local_0, local_0[0]*local_1, local_0[1]*local_1, local_0[2]*local_1);
            func_800DFFA0(param_1, 0x6C, local_0);
        }
    case 0x61C: case 0x623: break;
    }
}

void func_80098408(void *param_0) {
    func_80098480(param_0, 0, 0);
    func_80098494(param_0, 0.0f, 0.0f, 0.0f, 0.0f);
    func_800984F0(param_0, D_80117E9C);
    func_800984CC(param_0, D_80117E90);
    func_80098520(param_0, 1.0f);
}

void func_80098480(param_0, param_1, param_2) u8 * param_0; int param_1; int param_2; {
    *(s8 *)(*(u8 **)(param_0 + 0xAC) + 0x28) = param_1;
    *(s8 *)(*(u8 **)(param_0 + 0xAC) + 0x2A) = param_2;
}

void func_80098494(u8 *param_0, f32 param_1, f32 param_2, f32 param_3, f32 param_4) {
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xAC)))) + (0))) = param_1;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xAC)))) + (4))) = param_2;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xAC)))) + (8))) = param_3;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xAC)))) + (0xC))) = param_4;
}

void func_800984CC(param_0) Actor * param_0;
{
  s32 *new_var2;
  s32 *new_var;
  new_var2 = (s32 *) ((new_var = (char *) param_0) + 43);
  new_var = new_var2;
  func_800EE7F8((*new_var) + 28);
}

void func_800984F0(param_0) Actor * param_0;
{
  char *new_var3;
  s8 **new_var2;
  char *new_var;
  new_var = (char *) param_0;
  new_var3 = new_var + 0xAC;
  new_var2 = (s8 **) new_var3;
  (*new_var2)[0x29] = 1;
  func_800EE7F8((*(new_var2 = &(*((s32 **) new_var3)))) + 0x10);
}

func_80098520(s32 param_0, f32 param_1) {
    *(f32*)(*(s32*)(param_0 + 172) + 44) = param_1;
}

s32 func_80098530() 
{
    return 0x34;
}

void func_80098538(u8 *param_0) {
    func_800EFD24((*(u8 **)((s8 *)(param_0) + (0xE0))), param_0);
    func_800EFD24((*(u8 **)((s8 *)(param_0) + (0xE0))) + 0xC, param_0);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xE0)))) + (0x2C))) = 0;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xE0)))) + (0x28))) = 0.0f;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xE0)))) + (0x2F))) = 0;
}

s32 func_80098590(s32 param_0, s32 param_1)
{
    func_800EE7F8(param_1, *(s32 *)(param_0 + 224));
}

f32 func_800985B8(void *arg)
{
    return ((f32 *)(*(void **)((char *)arg + 0xE0)))[1];
}

s32 func_800985C4(s32 param_0, s32 param_1)
{
  s32 out;
  func_8009C128(param_0);
  out = _gccubesearch_entrypoint_6(&D_80117EB0, param_1);
  if (out == 0)
  {
    return 0;
  }
  _gspropctrl_entrypoint_11(out, param_1);
  return 1;
}

f32 func_80098610(struct Func80098610Arg *param_0)
{

    return *(f32 *)((char *)(*(s32 **)((char *)param_0 + 0xE0)) + 0x30);
}

s32 func_8009861C(void *param_0)
{
  void *ptr;
  ;
  return ((u8 *) (*((void **) (((u8 *) param_0) + 0xE0))))[0x2E];
}

f32 func_80098628(void *arg)
{
    return ((f32 *)(*(void **)((char *)arg + 0xE0)))[6];
}

s32 func_80098634(s32 param_0)
{
  return ((u8 *) (*(s32 **)(param_0 + 0xE0)))[0x2F];
}

s32 func_80098640(s32 param_0)
{
    return ((u8 *)(*(u8 **)(param_0 + 0xe0)))[0x2D];
}

f32 func_8009864C(void *arg)
{
    return ((f32 *)(*(void **)((char *)arg + 0xE0)))[4];
}

void func_80098658(u8 *param_0, u8 *param_1, u8 *param_2, f32 param_3, s32 param_4, s32 param_5) {
    u8 *local_0;

    local_0 = (*(u8 **)((s8 *)(param_0) + (0xE0)));
    if (!((*(f32 *)((s8 *)(local_0) + (0x28))) > 0.0f) || ((*(f32 *)((s8 *)(local_0) + (0x1C))) != (*(f32 *)((s8 *)(param_1) + (0)))) || ((*(f32 *)((s8 *)(local_0) + (0x20))) != (*(f32 *)((s8 *)(param_1) + (4)))) || ((*(f32 *)((s8 *)(local_0) + (0x24))) != (*(f32 *)((s8 *)(param_1) + (8))))) {
        func_800EE7F8(local_0, param_1);
        func_800EE7F8((*(u8 **)((s8 *)(param_0) + (0xE0))) + 0xC, param_2);
        (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xE0)))) + (0x18))) = param_3;
        (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xE0)))) + (0x2D))) = (s8) param_4;
        (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xE0)))) + (0x2F))) = (s8) param_5;
        (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xE0)))) + (0x2C))) = 1;
    }
}

void func_80098730(s32 *param_0, s32 param_1, s32 param_2, f32 param_3, s32 param_4, s32 param_5) {
    func_80098658(param_0, param_1, param_2, param_3, param_4, param_5);
    *(s8 *)(param_0[0x38] + 0x2E) = 1;
}

void func_80098778(void *p0, s32 p1, s32 p2, f32 p3, s32 p4, s32 p5, f32 p6) {
    func_80098658(p0, p1, p2, p3, p4, p5);
    (*(u8 **)((u8 *)p0 + 0xE0))[0x2E] = 2;
    *(f32 *)((*(u8 **)((u8 *)p0 + 0xE0)) + 0x30) = p6;
}

void func_800987CC(void *param_0) {
    QQ->unk28 = func_800F0E00(QQ->unk28 - func_800D8FF8(param_0), 0.0f);
    if (QQ->unk2C != 0) {
        if (func_800C6E38(5) != 0) { func_8009E7C8(param_0, 0xC); }
    }
    QQ->unk2C = 0;
}

void func_80098840(u8 *param_0) {
    u8 *local_0;

    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xE0)))) + (0x2C))) = 0;
    local_0 = (*(u8 **)((s8 *)(param_0) + (0xE0)));
    func_800EE7F8(local_0 + 0x1C, local_0, param_0);
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xE0)))) + (0x28))) = (f32) D_80124E20;
}
