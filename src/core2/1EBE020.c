#include "common.h"

#define NEED_E4(n) \
    while (local_8 < (n)) { \
        if (param_0->local_1 >= 0x1800) { \
            param_0->local_1 = 0; \
            func_8001311C(param_0->local_0, param_0->local_10); \
            param_0->local_10 += 0x1800; \
        } \
        local_7 |= (u32)param_0->local_0[param_0->local_1++] << local_8; \
        local_8 += 8; \
    }
#define DUMP_E4(n) local_7 >>= (n); local_8 -= (n);
#define NEEDBITS(n) { while (local_12 < (n)) { \
    if (param_0->cursor>=0x1800) { param_0->cursor=0; func_8001311C(param_0->input,param_0->rom); param_0->rom+=0x1800; } \
    local_13 |= (u32)param_0->input[param_0->cursor++] << local_12; local_12+=8; } }
#define DUMPBITS(n) { local_13 >>= (n); local_12 -= (n); }
#define NEED_BITS(n) \
    while (local_2 < (n)) { \
        if (param_0->field_4 >= 0x1800) { \
            param_0->field_4 = 0; \
            func_8001311C(param_0->field_0, param_0->field_30); \
            param_0->field_30 += 0x1800; \
        } \
        local_1 |= (u32)param_0->field_0[param_0->field_4++] << local_2; \
        local_2 += 8; \
    }
#define DUMP_BITS(n) local_1 >>= (n); local_2 -= (n);
extern void *D_8012D564;
extern void *D_8012D568;
extern void *D_8012D56C;
typedef struct LocalStream { u32 *input; s32 cursor; void *output; u32 bits, bitCount, written; void *literal, *distance; s32 literalBits, distanceBits; void *pool; u32 count, rom; void *allocation; u8 state, final; s16 id, limit; } LocalStream;
extern LocalStream *D_8012D560[];
extern void *heap_alloc(s32);
extern void heap_free();
extern u32 func_800D5A6C(s32);
extern void osWritebackDCache(void *, s32);
typedef struct { void *unk0; u8 pad4[0x24]; void *unk28; u8 pad2C[8]; void *unk34; } S_E4B1C;
extern int D_8012D570;
extern int func_8001311C(s32, s32);
typedef struct HuftE4 { u8 local_0, local_1; union { u16 local_0; struct HuftE4 *local_1; } local_2; } HuftE4;
typedef struct { u8 *local_0; s32 local_1; u8 *local_2; u32 local_3, local_4, local_5; HuftE4 *local_6, *local_7; s32 local_8, local_9; u8 pad28[8]; u32 local_10; u8 pad34[8]; s16 local_11; } StreamE4;
extern u16 D_801232C0[];
struct LocalHuft { u8 e,b; union { u16 n; struct LocalHuft *t; } v; };
typedef struct { u8 pad[0x28]; struct LocalHuft *pool; u32 count; } LocalInflate_800E589C;
typedef struct { u8 *input; s32 cursor; u8 *output; u32 bits,bitCount,written; struct LocalHuft *literal,*distance; s32 literalBits,distanceBits; struct LocalHuft *pool; u32 count,rom; } LocalInflate_800E5EC0;
extern u8 D_801231F0[];
extern u16 D_80123204[];
extern u16 D_80123244[];
extern u16 D_80123264[];
extern u16 D_801232A0[];
typedef struct { u8 *field_0; s32 field_4; u8 *field_8; u32 field_C, field_10, field_14; u8 pad_18[0x18]; u32 field_30; } InflateStream;
extern u32 func_800D5950(s32);
extern void rom_read_word(u32, u32 *);
extern void func_800D5FDC(u32);
extern void func_80117248(u32, u32, void *);
extern u8 D_801275E0;
void func_800E4B1C();
s32 func_800E4D28();
s32 func_800E4E54();
s32 func_800E5EC0();
s32 func_800E659C();
s32 func_800E6728();

int func_800E4730(param_0) s32 param_0;
{
    s32 val;

    val = (*((u32 *) D_8012D560));
    if (val != 0 && param_0 == *(s16 *)((char *)val + 0x3A)) {
        return 0;
    }

    val = ((u32) D_8012D564);
    if (val != 0 && param_0 == *(s16 *)((char *)val + 0x3A)) {
        return 1;
    }

    val = ((u32) D_8012D568);
    if (val != 0 && param_0 == *(s16 *)((char *)val + 0x3A)) {
        return 2;
    }

    val = ((u32) D_8012D56C);
    if (val != 0 && param_0 == *(s16 *)((char *)val + 0x3A)) {
        return 3;
    }

    return -1;
}

int func_800E47CC()
{
    s16 *ptr;

    ptr = (*((void * *) D_8012D560));
    if (ptr == 0) {
        return 0;
    }
    if (*(s16 *)((char *)ptr + 0x3a) == -1) {
        return 0;
    }

    ptr = D_8012D564;
    if (ptr == 0) {
        return 1;
    }
    if (*(s16 *)((char *)ptr + 0x3a) == -1) {
        return 1;
    }

    ptr = D_8012D568;
    if (ptr == 0) {
        return 2;
    }
    if (*(s16 *)((char *)ptr + 0x3a) == -1) {
        return 2;
    }

    ptr = D_8012D56C;
    if (ptr == 0) {
        return 3;
    }
    if (*(s16 *)((char *)ptr + 0x3a) == -1) {
        return 3;
    }

    return -1;
}

s32 func_800E488C(s32 param_0)
{
    s32 local_0;
    LocalStream *local_1;
    s32 local_2[3];
    s32 *local_3 = local_2;
    u32 local_4;
    s32 local_5;


    local_0 = func_800E4730(param_0);
    if (local_0 == -1) {
        local_0 = func_800E47CC();
        if (local_0 < 0) return 0;
        D_8012D560[local_0] = heap_alloc(0x40);
        D_8012D560[local_0]->state = 1;
        D_8012D560[local_0]->id = param_0;
        D_8012D560[local_0]->limit = 0x9C4;
    }
    local_1 = D_8012D560[local_0];
    if (local_1->state == 0) return 1;
    switch (local_1->state) {
    case 1:
        local_1->allocation = 0;
        local_1->bits = 0;
        local_1->bitCount = 0;
        local_1->written = 0;
        local_1->pool = heap_alloc(0x2800);
        local_1->rom = func_800D5A6C(local_1->id);
        local_1->input = heap_alloc(0x1800);
        func_8001311C(local_1->input, local_1->rom);
        local_1->rom += 0x1800;
        local_4 = *local_1->input;
        local_4 = (local_4 >> 16) << 4;
        local_1->cursor = 2;
        local_1->allocation = heap_alloc(local_4);
        if (!local_1->allocation) {
            func_800E4B1C(local_0);
            return 0;
        }
        local_1->output = local_1->allocation;
        local_1->state = 2;
        return 0;
    case 2:
        local_1->count = 0;
        local_2[0] = 0;
        local_4 = func_800E4D28(local_1);
        local_5 = local_2[0];
        switch (local_4) {
        case 2:
            local_2[0] = local_5;
            func_800E5EC0(local_1);
            local_1->state = 3;
            break;
        case 0:
            func_800E6728(local_1);
            local_1->state = 4;
            break;
        case 1:
            func_800E659C(local_1);
            local_1->state = 4;
            break;
        }
        return 0;
    case 3:
        if (!func_800E4E54(local_1)) local_1->state = 4;
        return 0;
    case 4:
        if (local_1->final) {
            if (local_1->pool) {
                heap_free(local_1->pool);
                local_1->pool = 0;
            }
            if (local_1->input) {
                heap_free(local_1->input);
                local_1->input = 0;
            }
            local_1->state = 0;
            osWritebackDCache(local_1->allocation, local_1->written);
            return 1;
        } else {
            local_1->state = 2;
            return 0;
        }
    case 0:
        return 1;
    }
    return 0;
}

int func_800E4AF0()
{
  s32 local_0;
  local_0 = func_800E4730();
  if (local_0 < 0)
  {
    return 0 | 0;
  }
  else
  {
    return 1;
  }
}

void func_800E4B1C(param_0) s32 param_0; {
    if (((S_E4B1C * *) D_8012D560)[param_0] == 0) { return; }
    if (((S_E4B1C * *) D_8012D560)[param_0]->unk34 != 0) { heap_free(((S_E4B1C * *) D_8012D560)[param_0]->unk34); }
    if (((S_E4B1C * *) D_8012D560)[param_0]->unk0 != 0) { heap_free(((S_E4B1C * *) D_8012D560)[param_0]->unk0); }
    if (((S_E4B1C * *) D_8012D560)[param_0]->unk28 != 0) { heap_free(((S_E4B1C * *) D_8012D560)[param_0]->unk28); }
    heap_free(((S_E4B1C * *) D_8012D560)[param_0]);
    ((S_E4B1C * *) D_8012D560)[param_0] = 0;
}

int func_800E4BB8()
{
  s32 local_0;
  local_0 = func_800E4730();
  if (local_0 < 0)
  {
    return 0;
  }
  else
  {
    func_800E4B1C(local_0);
    return 1;
  }
}

s32 func_800E4BF4(s32 param_0)
{
    s32 local_0;
    s32 local_1;

    local_0 = func_800E4730();
    if (local_0 == -1)
    {
        return 0;
    }
    if (func_800E488C(param_0) == 0)
    {
        do
        {
        } while (func_800E488C(param_0) == 0);
    }
    {
        void **local_2 = &((void * *) D_8012D560)[local_0];
        local_1 = *(s32 **)((char *)*local_2 + 0x34);
        heap_free(*local_2);
        *local_2 = NULL;
        return local_1;
    }
}

int func_800E4C7C()
{
  s32 local_0;
  for (local_0 = 0; local_0 < 4; local_0++)
  {
    if (((int *) D_8012D560)[local_0] != 0)
    {
      ((int *) D_8012D560)[local_0] = defrag(((int *) D_8012D560)[local_0]);
    }
  }

  D_8012D570 = defrag(D_8012D570);
}

int func_800E4CE8()
{
  s32 local_0;
  for (local_0 = 0; local_0 < 4; local_0++)
  {
    func_800E4B1C(local_0);
  }

}

s32 func_800E4D28(param_0) u8 * param_0;
{
  s32 var_s1;
  u8 *var_s2;
  u32 var_s3_2;

  var_s1 = *(s32 *)((s8 *) param_0 + 0x10);
  var_s3_2 = *(u32 *)((s8 *) param_0 + 0xC);
  if (var_s1 == 0) {
    do {
      if (*(s32 *)((s8 *) param_0 + 4) >= 0x1800) {
        *(s32 *)((s8 *) param_0 + 4) = 0;
        func_8001311C(*(s32 *)((s8 *) param_0 + 0), *(s32 *)((s8 *) param_0 + 0x30));
        *(s32 *)((s8 *) param_0 + 0x30) += 0x1800;
      }
      var_s2 = (u8 *)(*(s32 *)((s8 *) param_0 + 0));
      var_s3_2 |= (*(var_s2 + *(s32 *)((s8 *) param_0 + 4))) << var_s1;
      *(s32 *)((s8 *) param_0 + 4) += 1;
      var_s1 += 8;
    } while (var_s1 == 0);
  }
  var_s1 -= 1;
  *(s8 *)((s8 *) param_0 + 0x39) = (s8) (var_s3_2 & 1);
  var_s3_2 >>= 1;
  if ((u32)var_s1 < 2) {
    do {
      if (*(s32 *)((s8 *) param_0 + 4) >= 0x1800) {
        *(s32 *)((s8 *) param_0 + 4) = 0;
        func_8001311C(*(s32 *)((s8 *) param_0 + 0), *(s32 *)((s8 *) param_0 + 0x30));
        *(s32 *)((s8 *) param_0 + 0x30) += 0x1800;
      }
      var_s2 = (u8 *)(*(s32 *)((s8 *) param_0 + 0));
      var_s3_2 |= (*(var_s2 + *(s32 *)((s8 *) param_0 + 4))) << var_s1;
      *(s32 *)((s8 *) param_0 + 4) += 1;
      var_s1 += 8;
    } while ((u32)var_s1 < 2);
  }
  *(u32 *)((s8 *) param_0 + 0xC) = var_s3_2 >> 2;
  var_s1 -= 2;
  *(s32 *)((s8 *) param_0 + 0x10) = var_s1;
  return var_s3_2 & 3;
}

s32 func_800E4E54(param_0) StreamE4 * param_0;
{
    u32 local_0;
    u32 local_1;
    u32 local_2;
    u32 local_3;
    u32 local_5;
    u32 local_6;
    s32 local_12 = 0;
    HuftE4 *local_10;
    HuftE4 *local_11;
    u8 *local_9;
    HuftE4 *local_4;
    u32 local_7;
    u32 local_8;
    local_9 = param_0->local_2;
    local_10 = param_0->local_6;
    local_11 = param_0->local_7;
    local_7 = param_0->local_3;
    local_8 = param_0->local_4;
    local_3 = param_0->local_5;
    local_5 = D_801232C0[param_0->local_8];
    local_6 = D_801232C0[param_0->local_9];
    for (;;) {
        NEED_E4(param_0->local_8)
        if ((local_0 = (local_4 = local_10 + (local_7 & local_5))->local_0) > 16) {
            do {
                DUMP_E4(local_4->local_1)
                local_0 -= 16;
                NEED_E4(local_0)
            } while ((local_0 = (local_4 = local_4->local_2.local_1 + (local_7 & D_801232C0[local_0]))->local_0) > 16);
        }
        DUMP_E4(local_4->local_1)
        if (local_0 == 16) {
            local_9[local_3++] = local_4->local_2.local_0;
        } else {
            if (local_0 == 15) break;
            NEED_E4(local_0)
            local_1 = local_4->local_2.local_0 + (local_7 & D_801232C0[local_0]);
            DUMP_E4(local_0)
            NEED_E4(param_0->local_9)
            if ((local_0 = (local_4 = local_11 + (local_7 & local_6))->local_0) > 16) {
                do {
                    DUMP_E4(local_4->local_1)
                    local_0 -= 16;
                    NEED_E4(local_0)
                } while ((local_0 = (local_4 = local_4->local_2.local_1 + (local_7 & D_801232C0[local_0]))->local_0) > 16);
            }
            DUMP_E4(local_4->local_1)
            NEED_E4(local_0)
            local_2 = local_3 - local_4->local_2.local_0 - (local_7 & D_801232C0[local_0]);
            DUMP_E4(local_0)
            do {
                local_9[local_3++] = local_9[local_2++];
            } while (--local_1);
        }
        if (param_0->local_11 < local_12++) {
            param_0->local_5 = local_3;
            param_0->local_3 = local_7;
            param_0->local_4 = local_8;
            return 1;
        }
    }
    param_0->local_5 = local_3;
    param_0->local_3 = local_7;
    param_0->local_4 = local_8;
    return 0;
}

s32 func_800E5390(StreamE4 *param_0)
{
    u32 local_0;
    u32 local_1;
    u32 local_2;
    u32 local_3;
    u32 local_5;
    u32 local_6;
    u8 *local_9;
    HuftE4 *local_10;
    HuftE4 *local_11;
    HuftE4 *local_4;
    u32 local_7;
    u32 local_8;
    local_9 = param_0->local_2;
    local_10 = param_0->local_6;
    local_11 = param_0->local_7;
    local_7 = param_0->local_3;
    local_8 = param_0->local_4;
    local_3 = param_0->local_5;
    local_5 = D_801232C0[param_0->local_8];
    local_6 = D_801232C0[param_0->local_9];
    for (;;) {
        NEED_E4(param_0->local_8)
        if ((local_0 = (local_4 = local_10 + (local_7 & local_5))->local_0) > 16) {
            do {
                DUMP_E4(local_4->local_1)
                local_0 -= 16;
                NEED_E4(local_0)
            } while ((local_0 = (local_4 = local_4->local_2.local_1 + (local_7 & D_801232C0[local_0]))->local_0) > 16);
        }
        DUMP_E4(local_4->local_1)
        if (local_0 == 16) {
            local_9[local_3++] = local_4->local_2.local_0;
        } else {
            if (local_0 == 15) break;
            NEED_E4(local_0)
            local_1 = local_4->local_2.local_0 + (local_7 & D_801232C0[local_0]);
            DUMP_E4(local_0)
            NEED_E4(param_0->local_9)
            if ((local_0 = (local_4 = local_11 + (local_7 & local_6))->local_0) > 16) {
                do {
                    DUMP_E4(local_4->local_1)
                    local_0 -= 16;
                    NEED_E4(local_0)
                } while ((local_0 = (local_4 = local_4->local_2.local_1 + (local_7 & D_801232C0[local_0]))->local_0) > 16);
            }
            DUMP_E4(local_4->local_1)
            NEED_E4(local_0)
            local_2 = local_3 - local_4->local_2.local_0 - (local_7 & D_801232C0[local_0]);
            DUMP_E4(local_0)
            do {
                local_9[local_3++] = local_9[local_2++];
            } while (--local_1);
        }
    }
    param_0->local_5 = local_3;
    param_0->local_3 = local_7;
    param_0->local_4 = local_8;
    return 0;
}

int func_800E589C(u32 *param_0,u32 param_1,u32 param_2,u16 *param_3,u16 *param_4,struct LocalHuft **param_5,s32 *param_6,LocalInflate_800E589C *param_7)
{
  unsigned local_0;                   
  unsigned local_1[16+1];           
  unsigned local_2;                   
  int local_3;                        
  int local_4;                        
  register unsigned local_5;          
  register unsigned local_6;          
  register int local_7;               
  int local_8;                        
  register unsigned *local_9;         
  register struct LocalHuft *local_10;      
  struct LocalHuft local_11;                
  struct LocalHuft *local_12[16];         
  unsigned local_13[288];            
  register int local_14;               
  unsigned local_15[16+1];           
  unsigned *local_16;                 
  int local_17;                        
  unsigned local_18;                   


   
   bzero(local_1, sizeof(local_1));
   local_9 = param_0;  local_5 = param_1;
   do {
     local_1[*local_9]++;                    
     local_9++;                      
   } while (--local_5);
   if (local_1[0] == param_1)                
   {
     *param_5 = (struct LocalHuft *)NULL;
     *param_6 = 0;
     return 0;
   }


   
   local_8 = *param_6;
   for (local_6 = 1; local_6 <= 16; local_6++)
     if (local_1[local_6])
       break;
   local_7 = local_6;                        
   if ((unsigned)local_8 < local_6)
     local_8 = local_6;
   for (local_5 = 16; local_5; local_5--)
     if (local_1[local_5])
       break;
   local_3 = local_5;                        
   if ((unsigned)local_8 > local_5)
     local_8 = local_5;
   *param_6 = local_8;


  
  for (local_17 = 1 << local_6; local_6 < local_5; local_6++, local_17 <<= 1){
    (local_17 -= local_1[local_6]);
  }
  local_17 -= local_1[local_5];
  local_1[local_5] += local_17;


  
  local_15[1] = local_6 = 0;
  local_9 = local_1 + 1;  local_16 = local_15 + 2;
  while (--local_5) {                 
    *local_16++ = (local_6 += *local_9++);
  }


  
  local_9 = param_0;  local_5 = 0;
  do {
    if ((local_6 = *local_9++) != 0)
      local_13[local_15[local_6]++] = local_5;
  } while (++local_5 < param_1);


  
  local_15[0] = local_5 = 0;                 
  local_9 = local_13;                        
  local_4 = -1;                       
  local_14 = -local_8;                       
  local_12[0] = (struct LocalHuft *)NULL;   
  local_10 = (struct LocalHuft *)NULL;      
  local_18 = 0;                        

  
  for (; local_7 <= local_3; local_7++)
  {
     local_0 = local_1[local_7];
     while (local_0--)
     {
       
       
       while (local_7 > local_14 + local_8)
       {
        local_4++;
        local_14 += local_8;                 

        
        local_18 = (local_18 = local_3 - local_14) > (unsigned)local_8 ? local_8 : local_18;  
        if ((local_2 = 1 << (local_6 = local_7 - local_14)) > local_0 + 1)     
        {                       
          local_2 -= local_0 + 1;           
          local_16 = local_1 + local_7;
          while (++local_6 < local_18)       
          {
            if ((local_2 <<= 1) <= *++local_16)
              break;            
            local_2 -= *local_16;           
          }
        }
        local_18 = 1 << local_6;             

         
        local_10 = param_7->pool + param_7->count;
        
        param_7->count += local_18 + 1;         
        *param_5 = local_10 + 1;             
        *(param_5 = &(local_10->v.t)) = (struct LocalHuft *)NULL;
        local_12[local_4] = ++local_10;             

        
        if (local_4)
        {
          local_15[local_4] = local_5;             
          local_11.b = (u8)local_8;         
          local_11.e = (u8)(16 + local_6);  
          local_11.v.t = local_10;            
          local_6 = local_5 >> (local_14 - local_8);     
          local_12[local_4-1][local_6] = local_11;        
        }
       }

      
      local_11.b = (u8)(local_7 - local_14);
      if (local_9 >= local_13 + param_1)
        local_11.e = 99;               
      else if (*local_9 < param_2)
      {
        local_11.e = (u8)(*local_9 < 256 ? 16 : 15);    
        local_11.v.n = *local_9;             
	      local_9++;                   
      }
      else
      {
        local_11.e = *((u8 *)param_4 + (*local_9 - param_2));   
        local_11.v.n = param_3[*local_9++ - param_2];
      }

      
      local_2 = 1 << (local_7 - local_14);
      for (local_6 = local_5 >> local_14; local_6 < local_18; local_6 += local_2)
        local_10[local_6] = local_11;

      
      for (local_6 = 1 << (local_7 - 1); local_5 & local_6; local_6 >>= 1)
        local_5 ^= local_6;
      local_5 ^= local_6;

      
      while ((local_5 & ((1 << local_14) - 1)) != local_15[local_4])
      {
        local_4--;                    
        local_14 -= local_8;
      }
     }
   }


   
   return local_17 != 0 && local_3 != 1;
}

s32 func_800E5EC0(param_0) LocalInflate_800E5EC0 * param_0;
{
  int local_0;                
  unsigned local_1;
  unsigned local_2;           
  unsigned local_3;           
  unsigned local_4;           
  struct LocalHuft *local_5;      
  struct LocalHuft *local_6;      
  int local_7;               
  int local_8;               
  unsigned local_9;          
  unsigned local_10;          
  unsigned local_11;          



  unsigned local_14[286+30];
  register unsigned local_12;
  register u32 local_13;  

  
  local_7=param_0->literalBits;
  local_8=param_0->distanceBits;
  local_5=param_0->literal;
  local_6=param_0->distance;
  local_13 = param_0->bits;
  local_12 = param_0->bitCount;


   
   NEEDBITS(5)
   local_10 = 257 + ((unsigned)local_13 & 0x1f);      
   DUMPBITS(5)
   NEEDBITS(5)
   local_11 = 1 + ((unsigned)local_13 & 0x1f);        
   DUMPBITS(5)
   NEEDBITS(4)
   local_9 = 4 + ((unsigned)local_13 & 0xf);         
   DUMPBITS(4)

   
   for (local_1 = 0; local_1 < local_9; local_1++)
   {
     NEEDBITS(3)
     local_14[D_801231F0[local_1]] = (unsigned)local_13 & 7;
     DUMPBITS(3)
   }
   for (; local_1 < 19; local_1++)
     local_14[D_801231F0[local_1]] = 0;


    
    local_7 = 7;
    func_800E589C(local_14, 19, 19, NULL, NULL, &local_5, &local_7, param_0);


   
   local_4 = local_10 + local_11;
   local_3 = D_801232C0[local_7];
   local_0 = local_2 = 0;
   while ((unsigned)local_0 < local_4)
   {
      NEEDBITS((unsigned)local_7)
     local_1 = (local_6 = local_5 + ((unsigned)local_13 & local_3))->b;
     DUMPBITS(local_1)
     local_1 = local_6->v.n;
     if (local_1 < 16)                 
       local_14[local_0++] = local_2 = local_1;          
     else if (local_1 == 16)           
     {
       NEEDBITS(2)
       local_1 = 3 + ((unsigned)local_13 & 3);
       DUMPBITS(2)
       while (local_1--)
         local_14[local_0++] = local_2;
     }
     else if (local_1 == 17)           
     {
       NEEDBITS(3)
       local_1 = 3 + ((unsigned)local_13 & 7);
       DUMPBITS(3)
       while (local_1--)
         local_14[local_0++] = 0;
       local_2 = 0;
     }
     else                        
     {
       NEEDBITS(7)
       local_1 = 11 + ((unsigned)local_13 & 0x7f);
       DUMPBITS(7)
       while (local_1--)
         local_14[local_0++] = 0;
       local_2 = 0;
     }
    }

   
   param_0->bits = local_13;
   param_0->bitCount = local_12;

   
   local_7 = 9;
   func_800E589C(local_14, local_10, 257, D_80123204, D_80123244, &local_5, &local_7, param_0);
   local_8 = 6;
   func_800E589C(local_14 + local_10, local_11, 0, D_80123264, D_801232A0, &local_6, &local_8, param_0);

   
   param_0->literalBits=local_7;
   param_0->distanceBits=local_8;
   param_0->literal=local_5;
   param_0->distance=local_6;

  return 0;
}

s32 func_800E659C(param_0) s32 * param_0; {
    s32 local_5;
    void *local_0;
    void *local_1;
    u32 local_2;
    u32 local_3;
    u32 local_4[288];
    for (local_5 = 0; local_5 < 144; local_5++) {
        local_4[local_5] = 8;
    }
    for (; local_5 < 256; local_5++) {
        local_4[local_5] = 9;
    }
    for (; local_5 < 280; local_5++) {
        local_4[local_5] = 7;
    }
    for (; local_5 < 288; local_5++) {
        local_4[local_5] = 8;
    }
    local_2 = 7;
    func_800E589C(local_4, 288, 257, D_80123204, D_80123244, &local_0, &local_2, param_0);
    for (local_5 = 0; local_5 < 30; local_5++) {
        local_4[local_5] = 5;
    }
    local_3 = 5;
    func_800E589C(local_4, 30, 0, D_80123264, D_801232A0, &local_1, &local_3, param_0);
    param_0[8] = local_2;
    param_0[9] = local_3;
    param_0[6] = (s32)local_0;
    param_0[7] = (s32)local_1;
    func_800E5390(param_0);
    return 0;
}

s32 func_800E6728(param_0) InflateStream * param_0; {
    u32 local_0;
    u32 local_1;
    u32 local_2;
    u32 local_3;
    u8 *local_5;
    u32 local_4;
    local_5 = param_0->field_8;
    local_1 = param_0->field_C;
    local_2 = param_0->field_10;
    local_3 = param_0->field_14;
    local_4 = local_2 & 7;
    DUMP_BITS(local_4)
    NEED_BITS(16)
    local_0 = local_1 & 0xFFFF;
    DUMP_BITS(16)
    NEED_BITS(16)
    DUMP_BITS(16)
    while (local_0--) {
        NEED_BITS(8)
        local_5[local_3++] = local_1;
        DUMP_BITS(8)
    }
    param_0->field_14 = local_3;
    param_0->field_C = local_1;
    param_0->field_10 = local_2;
    return 0;
}

void func_800E692C()
{
  D_8012D570 = heap_alloc(0x40);
}

void *func_800E6950(s32 param_0, s32 param_1, void *param_2)
{
  union
  {
    s32 side;
    void *buffer;
  } local_2;
  u32 local_0;
  u32 local_4;
  u32 local_1[1];

  local_2.side = param_1;
  local_0 = func_800D5A6C(param_0);
  rom_read_word(local_0, local_1);
  local_4 = local_1[0];
  local_1[0] = (local_4 >>= 16);
  local_4 = local_1[0] * 16;
  local_1[0] = local_4;
  func_800D5FDC(local_1[0]);
  if (!param_2)
  {
    local_2.buffer = heap_alloc_sided(local_4, local_2.side);
    if (!local_2.buffer)
    {
      return 0;
    }
  }
  else
  {
    local_2.buffer = param_2;
  }
  func_80117248(local_0, func_800D5950(param_0), local_2.buffer);
  if (!local_2.buffer)
  {
  }
  osWritebackDCache(local_2.buffer, local_4);
  return local_2.buffer;

}

s32 func_800E6A00(void)
{
  return D_801275E0;
}
