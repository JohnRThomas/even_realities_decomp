/*
 * Function: print_value
 * Entry:    0007c520
 * Prototype: undefined4 __stdcall print_value(undefined4 param_1, uint * param_2, int * param_3, undefined4 * param_4)
 */


/* exclude_from_export_ai */

undefined4 print_value(undefined4 param_1,uint *param_2,int *param_3,undefined4 *param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined1 *unaff_r6;
  undefined1 *puVar4;
  int iVar5;
  
  if (param_2[2] == 0) {
    if (param_2[6] == 0) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0xffffffff;
    }
    param_2[2] = uVar1;
  }
  iVar5 = 0;
  if (-1 < (int)(*param_2 << 0x1b)) {
    puVar2 = (undefined4 *)*param_4;
    *param_4 = puVar2 + 1;
    unaff_r6 = (undefined1 *)*puVar2;
  }
  do {
    uVar1 = param_2[6];
    if (uVar1 != 0) {
      if (uVar1 == 1) {
        if (*(char *)(param_2[5] + (uint)*(byte *)*param_3) == '\0') {
          if (iVar5 == 0) {
            return 1;
          }
LAB_0007c5ae:
          if (((*param_2 & 0x10) == 0) && (param_2[3] = param_2[3] + 1, param_2[6] != 0)) {
            *unaff_r6 = 0;
          }
          param_2[4] = param_2[4] + iVar5;
          return 0;
        }
      }
      else if ((uVar1 != 2) || ((int)((uint)(byte)(&DAT_000f6aa2)[*(byte *)*param_3] << 0x1c) < 0))
      goto LAB_0007c5ae;
    }
    iVar5 = iVar5 + 1;
    puVar4 = unaff_r6;
    if (-1 < (int)(*param_2 << 0x1b)) {
      puVar4 = unaff_r6 + 1;
      *unaff_r6 = *(undefined1 *)*param_3;
    }
    iVar3 = param_3[1];
    *param_3 = *param_3 + 1;
    uVar1 = param_2[2];
    param_3[1] = iVar3 + -1;
    uVar1 = uVar1 - 1;
    param_2[2] = uVar1;
    unaff_r6 = puVar4;
    if ((uVar1 == 0) ||
       ((iVar3 + -1 < 1 &&
        (iVar3 = (*(code *)param_2[0x60])(param_1,param_3,uVar1,(code *)param_2[0x60],param_4),
        iVar3 != 0)))) goto LAB_0007c5ae;
  } while( true );
}


