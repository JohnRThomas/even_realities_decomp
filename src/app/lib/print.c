/*
 * Function: print
 * Entry:    0007ab7c
 * Prototype: undefined4 __stdcall print(char * param_1)
 */


/* exclude_from_export_ai */

undefined4 print(char *param_1)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  char **local_2c;
  undefined4 local_28;
  int local_24;
  char *local_20;
  size_t sStack_1c;
  char *local_18;
  undefined4 local_14;
  
  piVar2 = _REENT;
  sStack_1c = strlen(param_1);
  local_18 = "\n";
  local_14 = 1;
  local_24 = sStack_1c + 1;
  local_2c = &local_20;
  local_28 = 2;
  local_20 = param_1;
  if (piVar2 == (int *)0x0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)software_udf(0xff,0x7aaf2);
    (*pcVar1)();
  }
  if (piVar2[6] == 0) {
    __sinit(piVar2);
    piVar4 = (int *)piVar2[2];
    if (piVar2[6] == 0) {
      __sinit(piVar2);
    }
  }
  else {
    piVar4 = (int *)piVar2[2];
  }
  if (piVar4 == (int *)&DAT_0009c2ac) {
    piVar4 = (int *)piVar2[1];
  }
  else if (piVar4 == (int *)&DAT_0009c28c) {
    piVar4 = (int *)piVar2[2];
  }
  else if (piVar4 == (int *)&DAT_0009c26c) {
    piVar4 = (int *)piVar2[3];
  }
  if ((-1 < piVar4[0x19] << 0x1f) && (-1 < (int)((uint)*(ushort *)(piVar4 + 3) << 0x16))) {
    __retarget_lock_acquire_recursive(piVar4[0x16]);
  }
  iVar3 = ensure(piVar2,piVar4,&local_2c);
  if (iVar3 == 0) {
    uVar5 = 10;
  }
  else {
    uVar5 = 0xffffffff;
  }
  if ((-1 < piVar4[0x19] << 0x1f) && (-1 < (int)((uint)*(ushort *)(piVar4 + 3) << 0x16))) {
    __retarget_lock_release_recursive(piVar4[0x16]);
  }
  return uVar5;
}


