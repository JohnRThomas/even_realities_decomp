/*
 * Function: FUN_0102aec0
 * Entry:    0102aec0
 * Prototype: int * __stdcall FUN_0102aec0(int param_1)
 */


int * FUN_0102aec0(int param_1)

{
  int *piVar1;
  undefined1 auStack_10c [256];
  
  FUN_0103bdd4((int)auStack_10c,&DAT_0103c758,0xfb);
  if (DAT_210045c0 == 0) {
    piVar1 = (int *)&DAT_00000001;
  }
  else {
    piVar1 = FUN_01036a90((int *)&DAT_210045b0,(int)auStack_10c,0,(int *)0x0);
    if (piVar1 == (int *)0x0) {
      FUN_0103bdd4(param_1,auStack_10c,0xfb);
    }
  }
  return piVar1;
}


