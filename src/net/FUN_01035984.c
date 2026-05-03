/*
 * Function: FUN_01035984
 * Entry:    01035984
 * Prototype: undefined4 __stdcall FUN_01035984(undefined4 * param_1)
 */


undefined4 FUN_01035984(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  byte *pbVar3;
  int iVar4;
  undefined4 uVar5;
  
  if (((param_1 == (undefined4 *)0x0) || (pbVar3 = (byte *)*param_1, pbVar3 == (byte *)0x0)) ||
     (*pbVar3 == 0)) {
    uVar5 = 0xffffffea;
  }
  else {
    iVar4 = FUN_01035948(pbVar3,(undefined4 *)0x0);
    if (iVar4 == 0) {
      uVar5 = 0xffffffef;
    }
    else {
      param_1[7] = param_1 + 7;
      param_1[8] = param_1 + 7;
      puVar1 = DAT_21004b10;
      puVar2 = param_1 + 9;
      param_1[10] = DAT_21004b10;
      DAT_21004b10 = puVar2;
      param_1[9] = &DAT_21004b0c;
      *puVar1 = param_1 + 9;
      if ((6 < DAT_21004b04) && (DAT_21004b08 != (code *)0x0)) {
        (*DAT_21004b08)(7,"registered %s bus\n",*param_1);
      }
      uVar5 = 0;
    }
  }
  return uVar5;
}


