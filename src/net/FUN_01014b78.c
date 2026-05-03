/*
 * Function: FUN_01014b78
 * Entry:    01014b78
 * Prototype: undefined4 __stdcall FUN_01014b78(byte * param_1, int param_2, undefined4 param_3)
 */


undefined4 FUN_01014b78(byte *param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 extraout_r2;
  int iVar4;
  
  uVar3 = (uint)*(byte *)(param_2 + 4);
  cVar1 = *(char *)(DAT_21000f6c + 0xc5);
  if (cVar1 != '\"') {
    if (cVar1 != '/') {
      if (cVar1 != ')') {
        if (cVar1 == '\x04') {
          iVar4 = 0xe;
        }
        else if (cVar1 == '\x10') {
          iVar4 = 0x12;
        }
        else if (cVar1 == '\x1e') {
          iVar4 = 0x14;
        }
        else {
          if (*(char *)(DAT_21000f6c + 0xc6) != '$') {
            return 0;
          }
          iVar4 = 0x17;
        }
        uVar2 = FUN_010149f4(iVar4,0,param_1);
        return uVar2;
      }
      if (DAT_210001f0 == (code *)0x0) {
        return 0;
      }
                    /* WARNING: Could not recover jumptable at 0x01014bea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*DAT_210001f0)(0x23);
      return uVar2;
    }
    uVar3 = FUN_0100dbc0(DAT_21000f6c + 0xa8,0xb,(uint)*(byte *)(DAT_21000f6c + 0xc6),1);
    if (uVar3 != 0) goto LAB_01014bce;
    uVar3 = 0x2a;
    param_3 = extraout_r2;
  }
  FUN_01020134(0x21000f68,uVar3,param_3);
LAB_01014bce:
  iVar4 = DAT_21000f6c;
  *(undefined1 *)(DAT_21000f6c + 0xc5) = 0;
  *(undefined1 *)(iVar4 + 0x100) = 0;
  return 0;
}


