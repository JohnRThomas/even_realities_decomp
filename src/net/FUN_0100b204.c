/*
 * Function: FUN_0100b204
 * Entry:    0100b204
 * Prototype: char __stdcall FUN_0100b204(int param_1, undefined4 * param_2)
 */


char FUN_0100b204(int param_1,undefined4 *param_2)

{
  undefined2 uVar1;
  char cVar2;
  undefined2 uVar3;
  char cVar4;
  
  uVar3 = DAT_21000c44;
  cVar2 = DAT_21000c3e;
  uVar1 = DAT_21000c3c;
  cVar4 = DAT_21000c34;
  if (param_1 == 0) {
    if (DAT_21000c34 != '\0') {
      *param_2 = DAT_21000c38;
      *(undefined2 *)(param_2 + 1) = uVar1;
    }
  }
  else {
    if (param_1 != 1) {
      return '\0';
    }
    cVar4 = '\0';
    if (DAT_21000c3e != '\0') {
      *param_2 = DAT_21000c40;
      *(undefined2 *)(param_2 + 1) = uVar3;
      return cVar2;
    }
  }
  return cVar4;
}


