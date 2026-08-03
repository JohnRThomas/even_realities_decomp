/*
 * Function: __sfp
 * Entry:    00079ee4
 * Prototype: undefined4 * __stdcall __sfp(undefined4 * param_1)
 */


/* exclude_from_export */

undefined4 * __sfp(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  
  __sfp_lock_acquire();
  if (DAT_20002d5c == 0) {
    __sinit((undefined4 *)&_GLOBAL_REENT);
  }
  piVar3 = &DAT_20002d8c;
  do {
    iVar1 = piVar3[1];
    puVar2 = (undefined4 *)piVar3[2];
    while (iVar1 = iVar1 + -1, -1 < iVar1) {
      if (*(short *)(puVar2 + 3) == 0) {
        puVar2[0x19] = 0;
        puVar2[3] = 0xffff0001;
        __retarget_lock_init_recursive(puVar2 + 0x16);
        __sfp_lock_release();
        *puVar2 = 0;
        puVar2[6] = 0;
        puVar2[1] = 0;
        puVar2[2] = 0;
        puVar2[4] = 0;
        puVar2[5] = 0;
        memset(puVar2 + 0x17,0,8);
        puVar2[0xd] = 0;
        puVar2[0xe] = 0;
        puVar2[0x12] = 0;
        puVar2[0x13] = 0;
        return puVar2;
      }
      puVar2 = puVar2 + 0x1a;
    }
    if (*piVar3 == 0) {
      puVar2 = __sfmoreglue(param_1,4);
      *piVar3 = (int)puVar2;
      if (puVar2 == (undefined4 *)0x0) {
        __sfp_lock_release();
        *param_1 = 0xc;
        return (undefined4 *)0x0;
      }
    }
    piVar3 = (int *)*piVar3;
  } while( true );
}


