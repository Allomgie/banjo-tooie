#include "common.h"

extern s32 D_80011000;
extern s32 D_8000E800;
extern s32* D_80124A8C;
struct LocalHuft { u8 e,b; union { u16 n; struct LocalHuft *t; } v; };
extern struct LocalHuft *D_80124A80;
extern u32 D_80137388;

void func_801168F0()
{
  D_80124A8C = &D_80011000;
  D_80124A80 = &D_8000E800;
}

void func_80116914(u32 *param_0,u32 param_1,u32 param_2,u16 *param_3,u16 *param_4,struct LocalHuft **param_5,s32 *param_6)
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
     return;
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

         
        local_10 = D_80124A80 + D_80137388;
        
        D_80137388 += local_18 + 1;         
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


   

}
