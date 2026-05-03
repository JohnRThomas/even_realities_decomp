/*
 * Function: FUN_0100b3a4
 * Entry:    0100b3a4
 * Prototype: undefined __stdcall FUN_0100b3a4(undefined1 * param_1)
 */


void FUN_0100b3a4(undefined1 *param_1)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  
  pbVar2 = DAT_21000c74;
  iVar1 = DAT_21000c70;
  if ((*DAT_21000c74 & 3) == 3) {
    DAT_21000c7a = DAT_21000c7a | 1;
    *(undefined1 *)(DAT_21000c70 + 0xb8) = 1;
    DAT_21000c78 = DAT_21000c78 | 0x800;
    (*DAT_21000c7c)();
    pbVar2 = DAT_21000c74;
  }
  else if (((*DAT_21000c74 & 3) != 0) && (DAT_21000c74[1] != 0)) {
    DAT_21000c78 = DAT_21000c78 | 0x800;
    if (DAT_21000c80 == 0) {
      return;
    }
    if (0xfb < DAT_21000c74[1]) {
      DAT_21000c85 = DAT_21000c85 | 0x10;
      return;
    }
    if (DAT_21000c84 != '\0') {
                    /* WARNING: Could not recover jumptable at 0x0100b41a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*DAT_21000c7c)(0x20,0);
      return;
    }
    *param_1 = 1;
  }
  *(bool *)(iVar1 + 0xc0) = *(char *)(iVar1 + 0xc0) != '\x01';
  if (pbVar2[1] != 0) {
    uVar3 = *(uint *)(iVar1 + 0x128);
    *(uint *)(iVar1 + 0x128) = uVar3 + 1;
    *(uint *)(iVar1 + 300) = *(int *)(iVar1 + 300) + (uint)(0xfffffffe < uVar3);
  }
  return;
}


