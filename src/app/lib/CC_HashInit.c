/*
 * Function: CC_HashInit
 * Entry:    0007df60
 * Prototype: bool __stdcall CC_HashInit(undefined4 * param_1, undefined4 param_2)
 */


/* exclude_from_export_ai */

bool CC_HashInit(undefined4 *param_1,undefined4 param_2)

{
  drvError_t dVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    CC_HalWriteRegister(param_1,0xf0);
    *param_1 = param_2;
    param_1[0x17] = 0x40;
    dVar1 = InitHashDrv(param_1);
    return dVar1 != 0;
  }
  return true;
}


