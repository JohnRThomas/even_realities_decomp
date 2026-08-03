/*
 * Function: atanf
 * Entry:    00079b88
 * Prototype: float __stdcall atanf(float param_1)
 */


/* exclude_from_export_ai */

float atanf(float param_1)

{
  int iVar1;
  undefined *puVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  puVar2 = (undefined *)((uint)param_1 & 0x7fffffff);
  if (puVar2 < (undefined *)0x50800000) {
    if (&DAT_3edfffff < puVar2) {
      fVar5 = fabsf(param_1);
      if (puVar2 < (undefined *)0x3f980000) {
        if (puVar2 < (undefined *)0x3f300000) {
          iVar1 = 0;
          fVar5 = (fVar5 * 2.0 + -1.0) / (fVar5 + 2.0);
        }
        else {
          iVar1 = 1;
          fVar5 = (fVar5 - 1.0) / (fVar5 + 1.0);
        }
      }
      else if (puVar2 < (undefined *)0x401c0000) {
        iVar1 = 2;
        fVar5 = (fVar5 - 1.5) / (fVar5 * 1.5 + 1.0);
      }
      else {
        iVar1 = 3;
        fVar5 = -1.0 / fVar5;
      }
    }
    else {
      if ((puVar2 < &DAT_31000000) && (1.0 < param_1 + 1e+30)) {
        return param_1;
      }
      iVar1 = -1;
      fVar5 = param_1;
    }
    fVar3 = fVar5 * fVar5;
    fVar4 = fVar3 * fVar3;
    fVar3 = fVar5 * (((((fVar4 * -0.03653157 + -0.058335703) * fVar4 + -0.07691876) * fVar4 +
                      -0.111111104) * fVar4 + -0.2) * fVar4 +
                    (((((fVar4 * 0.01628582 + 0.04976878) * fVar4 + 0.06661073) * fVar4 + 0.09090887
                      ) * fVar4 + 0.14285715) * fVar4 + 0.33333334) * fVar3);
    if (iVar1 == -1) {
      fVar5 = fVar5 - fVar3;
    }
    else {
      fVar5 = *(float *)(&UNK_0009c25c + iVar1 * 4) -
              ((fVar3 - *(float *)(&UNK_0009c24c + iVar1 * 4)) - fVar5);
      if ((int)param_1 < 0) {
        fVar5 = -fVar5;
      }
    }
  }
  else if (puVar2 < (undefined *)0x7f800001) {
    fVar5 = (float)((uint)(0 < (int)param_1) * 0x3fc90fdb + (uint)((int)param_1 < 1) * -0x4036f025);
  }
  else {
    fVar5 = param_1 + param_1;
  }
  return fVar5;
}


