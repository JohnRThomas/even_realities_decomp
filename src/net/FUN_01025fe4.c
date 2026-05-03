/*
 * Function: FUN_01025fe4
 * Entry:    01025fe4
 * Prototype: undefined __stdcall FUN_01025fe4(undefined4 param_1, undefined4 param_2, undefined4 param_3, int param_4)
 */


void FUN_01025fe4(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 extraout_r2;
  ulonglong uVar3;
  
  uVar3 = 0x21001c2400000005;
  do {
    uVar1 = (int)uVar3 - 1;
    uVar3 = CONCAT44((int)(uVar3 >> 0x20),uVar1) & 0xffffffff000000ff;
    if ((uVar1 & 0xff) == 0xff) {
      uVar3 = FUN_01025edc(0x69,0x48,param_1,param_4);
      param_1 = extraout_r2;
    }
    iVar2 = (int)(uVar3 >> 0x20);
    param_4 = iVar2 + (int)uVar3 * 8;
  } while (*(char *)(param_4 + 4) != '\0');
  *(undefined4 *)(iVar2 + (int)uVar3 * 8) = param_1;
  *(undefined1 *)(param_4 + 5) = 0;
  *(undefined1 *)(param_4 + 6) = 0;
  *(undefined1 *)(param_4 + 4) = 1;
  return;
}


