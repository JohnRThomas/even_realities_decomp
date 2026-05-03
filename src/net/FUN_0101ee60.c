/*
 * Function: FUN_0101ee60
 * Entry:    0101ee60
 * Prototype: undefined4 __stdcall FUN_0101ee60(int param_1, undefined4 param_2, undefined4 param_3)
 */


undefined4 FUN_0101ee60(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 local_1c;
  undefined4 uStack_18;
  
  uVar2 = DAT_21000ec0;
  uVar4 = (uint)DAT_21000ebe;
  uVar5 = (uint)DAT_21000ebf;
  local_1c = param_2;
  uStack_18 = param_3;
  if (uVar4 == 0) {
    uVar4 = FUN_010200d8();
  }
  uVar1 = uVar4;
  if (((uVar5 == 0) && (uVar5 = FUN_010200d8(), uVar1 = uVar5, uVar4 == 0)) || (uVar1 == 0)) {
    uVar3 = 9;
  }
  else {
    local_1c = CONCAT22(uVar2,CONCAT11((char)uVar5,(char)uVar4));
    FUN_0100dd84(param_1,&local_1c);
    uVar3 = 0;
  }
  return uVar3;
}


