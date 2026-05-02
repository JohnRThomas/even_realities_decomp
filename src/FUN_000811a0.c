/*
 * Function: FUN_000811a0
 * Entry:    000811a0
 * Prototype: uint __stdcall FUN_000811a0(uint param_1, byte * param_2, int param_3)
 */


uint FUN_000811a0(uint param_1,byte *param_2,int param_3)

{
  uint uVar1;
  
  if ((param_2 == (byte *)0x0) || (param_3 < 1)) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_00081116(param_1,0x8005,0xffff,1,'\x01',param_2,param_3);
  }
  return uVar1;
}


