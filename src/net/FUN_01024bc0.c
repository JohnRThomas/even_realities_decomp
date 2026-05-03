/*
 * Function: FUN_01024bc0
 * Entry:    01024bc0
 * Prototype: int __stdcall FUN_01024bc0(uint param_1, uint param_2, uint param_3, int param_4, int param_5)
 */


int FUN_01024bc0(uint param_1,uint param_2,uint param_3,int param_4,int param_5)

{
  int iVar1;
  undefined2 *puVar2;
  uint extraout_r2;
  undefined1 *puVar3;
  undefined1 *extraout_r3;
  char *unaff_r6;
  char cStack_1d;
  uint local_1c;
  int aiStack_18 [2];
  
  if (param_4 == 0) {
    unaff_r6 = &cStack_1d;
    iVar1 = FUN_01024c40(param_3);
    FUN_01024d24(param_1,param_2,&local_1c,aiStack_18,unaff_r6);
    puVar3 = (undefined1 *)(iVar1 - local_1c);
    if ((undefined1 *)0xf423fff < puVar3) {
      local_1c = local_1c - iVar1;
      if (local_1c < 256000000) {
        puVar3 = (undefined1 *)-local_1c;
      }
      else if (&DAT_1e847fff < puVar3) {
        puVar3 = puVar3 + 512000000;
      }
      else {
        if (local_1c < 512000000) goto LAB_01024c28;
        puVar3 = (undefined1 *)(-512000000 - local_1c);
      }
    }
    return (param_5 + -0xf) - (int)puVar3;
  }
  FUN_01025edc(0x70,0xc43,param_3,param_4);
  local_1c = extraout_r2;
  puVar3 = extraout_r3;
LAB_01024c28:
  puVar2 = (undefined2 *)FUN_01025edc(0x70,0xb76,local_1c,puVar3);
  *puVar2 = (short)puVar2;
  *(char **)(puVar2 + 3) = unaff_r6;
  return 0;
}


