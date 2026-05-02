/*
 * Function: pixelto4bithex_for_flash
 * Entry:    00037db0
 * Prototype: undefined __stdcall pixelto4bithex_for_flash(int param_1, int param_2, undefined4 param_3, undefined4 param_4)
 */


void pixelto4bithex_for_flash(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined1 uVar2;
  uint uVar3;
  
  if (DAT_2000a9ac == (void *)0x0) {
    DAT_2000a9ac = malloc(0x140);
    if (DAT_2000a9ac == (void *)0x0) {
      printk("[%s-%d]malloc error \n","pixelto4bithex_for_flash",0x28,param_4);
      return;
    }
    memset(DAT_2000a9ac,0,0x140);
  }
  uVar1 = 0;
  do {
    if (param_2 <= DAT_2000a9a4) {
      return;
    }
    DAT_2000a9a4 = DAT_2000a9a4 + 2;
    uVar3 = param_1 << (uVar1 & 0xff) & 0xc0;
    uVar2 = (undefined1)uVar3;
    if (uVar3 == 0xc0) {
      uVar2 = 0xff;
    }
    else if (uVar3 == 0x80) {
      uVar2 = 0xf0;
    }
    else if (uVar3 == 0x40) {
      uVar2 = 0xf;
    }
    else if (uVar3 != 0) {
      uVar2 = 0x99;
    }
    *(undefined1 *)((int)DAT_2000a9ac + DAT_2000a9a8) = uVar2;
    uVar1 = uVar1 + 2;
    DAT_2000a9a8 = DAT_2000a9a8 + 1;
  } while (uVar1 != 8);
  return;
}


