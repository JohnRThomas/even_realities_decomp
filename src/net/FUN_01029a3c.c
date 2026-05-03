/*
 * Function: FUN_01029a3c
 * Entry:    01029a3c
 * Prototype: int __stdcall FUN_01029a3c(char * param_1, undefined4 param_2)
 */


int FUN_01029a3c(char *param_1,undefined4 param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  undefined1 local_18 [4];
  undefined4 uStack_14;
  
  local_18 = (undefined1  [4])param_1;
  uStack_14 = param_2;
  pcVar2 = (char *)FUN_0101ee2c();
  if (*param_1 != '\0') {
    local_18 = (undefined1  [4])((uint)local_18 & 0xffffff00);
    cVar1 = FUN_0100b204(1,(undefined4 *)(local_18 + 1));
    if ((cVar1 != '\0') && (iVar3 = FUN_010299d4(local_18), iVar3 != 0)) {
      return iVar3;
    }
  }
  local_18 = (undefined1  [4])((uint)local_18 & 0xffffff00);
  uVar4 = FUN_01012ec0((int)pcVar2);
  if (uVar4 == 0) {
    local_18._1_2_ = 0;
  }
  else {
    local_18._1_2_ = 0x80;
  }
  local_18[3] = 0;
  if (*param_1 == '\x01') {
    iVar3 = FUN_0101fc40(pcVar2,local_18);
  }
  else if (*param_1 == '\0') {
    iVar3 = FUN_01028e08(pcVar2);
  }
  else {
    iVar3 = 0x12;
  }
  return iVar3;
}


