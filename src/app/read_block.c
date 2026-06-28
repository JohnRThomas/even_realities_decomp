/*
 * Function: $_read_block
 * Entry:    0007f784
 * Prototype: int __stdcall $_read_block(byte * param_1)
 */


int __read_block(byte *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_0007f752(param_1);
  iVar2 = __i2c_read_byte((int)param_1);
  return iVar2 + iVar1;
}


