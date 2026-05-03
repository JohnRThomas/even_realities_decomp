/*
 * Function: FUN_01026074
 * Entry:    01026074
 * Prototype: undefined __stdcall FUN_01026074(void)
 */


void FUN_01026074(void)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  
  cVar3 = '\x06';
  while (cVar3 = cVar3 + -1, cVar3 != '\0') {
    uVar2 = (uint)DAT_21001c4c;
    iVar1 = uVar2 * 8;
    if (((&DAT_21001c28)[iVar1] == '\x01') && ((&DAT_21001c29)[iVar1] != (&DAT_21001c2a)[iVar1])) {
      (&DAT_21001c2a)[iVar1] = (&DAT_21001c29)[iVar1];
      (**(code **)(&DAT_21001c24 + uVar2 * 8))();
    }
    DAT_21001c4c = DAT_21001c4c + 1;
    if (4 < DAT_21001c4c) {
      DAT_21001c4c = 0;
    }
  }
  return;
}


