/*
 * Function: FUN_0103bcfa
 * Entry:    0103bcfa
 * Prototype: undefined __stdcall FUN_0103bcfa(undefined1 * param_1, undefined1 * param_2, undefined1 * param_3, undefined1 * param_4)
 */


void FUN_0103bcfa(undefined1 *param_1,undefined1 *param_2,undefined1 *param_3,undefined1 *param_4)

{
  undefined1 *extraout_r1;
  undefined1 *extraout_r2;
  
  if (param_3 <= param_4) goto LAB_0103bd04;
LAB_0103bd00:
  do {
    param_1 = (undefined1 *)FUN_01030244(param_1,param_2,param_3,param_4);
    param_2 = extraout_r1;
    param_3 = extraout_r2;
LAB_0103bd04:
    if (param_2 <= param_1) {
      param_4 = param_2 + (int)param_3;
      if (param_1 < param_4) goto LAB_0103bd00;
      if (param_2 != param_1) goto LAB_0103bd18;
    }
    param_4 = param_1 + (int)param_3;
    if (param_4 <= param_2) {
LAB_0103bd18:
      FUN_0103bdd4((int)param_1,param_2,(int)param_3);
      return;
    }
  } while( true );
}


