/*
 * Function: FUN_01039288
 * Entry:    01039288
 * Prototype: int __stdcall FUN_01039288(uint * param_1, uint * param_2)
 */


int FUN_01039288(uint *param_1,uint *param_2)

{
  bool bVar1;
  uint uVar2;
  
  uVar2 = *param_2;
  param_1[7] = uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
               uVar2 >> 0x18;
  uVar2 = param_2[1];
  param_1[6] = uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
               uVar2 >> 0x18;
  uVar2 = param_2[2];
  param_1[5] = uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
               uVar2 >> 0x18;
  uVar2 = param_2[3];
  param_1[4] = uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
               uVar2 >> 0x18;
  uVar2 = param_2[4];
  param_1[3] = uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
               uVar2 >> 0x18;
  uVar2 = param_2[5];
  param_1[2] = uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
               uVar2 >> 0x18;
  uVar2 = param_2[6];
  param_1[1] = uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
               uVar2 >> 0x18;
  uVar2 = param_2[7];
  *param_1 = uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
             uVar2 >> 0x18;
  bVar1 = FUN_01008ab0((int *)param_1,param_1,(uint *)&DAT_0103cb20);
  FUN_01008af0(param_1,(uint *)&DAT_0103cb20,(uint)bVar1);
  return bVar1 - 1;
}


