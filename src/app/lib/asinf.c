/*
 * Function: asinf
 * Entry:    00079230
 * Prototype: float __stdcall asinf(float param_1)
 */


/* exclude_from_export_ai */

float asinf(float param_1)

{
  float fVar1;
  undefined *puVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float square;
  
  puVar2 = (undefined *)((uint)param_1 & 0x7fffffff);
  if (puVar2 == (undefined *)0x3f800000) {
    fVar5 = param_1 * -4.371139e-08 + param_1 * 1.5707964;
  }
  else if (puVar2 < (undefined *)0x3f800001) {
    if (puVar2 < (undefined *)0x3f000000) {
      if ((undefined *)0x31ffffff < puVar2) {
        fVar3 = param_1 * param_1;
        return param_1 + param_1 * (((((((fVar3 * 3.479331e-05 + 0.000791535) * fVar3 + -0.040055536
                                        ) * fVar3 + 0.20121253) * fVar3 + -0.32556581) * fVar3 +
                                     0.16666667) * fVar3) /
                                   ((((fVar3 * 0.077038154 + -0.688284) * fVar3 + 2.0209458) * fVar3
                                    + -2.403395) * fVar3 + 1.0));
      }
      if (1.0 < param_1 + 1e+30) {
        return param_1;
      }
    }
    fVar3 = fabsf(param_1);
    square = (1.0 - fVar3) * 0.5;
    fVar3 = sqrtf(square);
    fVar4 = ((((((square * 3.479331e-05 + 0.000791535) * square + -0.040055536) * square +
               0.20121253) * square + -0.32556581) * square + 0.16666667) * square) /
            ((((square * 0.077038154 + -0.688284) * square + 2.0209458) * square + -2.403395) *
             square + 1.0);
    if (puVar2 < &DAT_3f79999a) {
      fVar1 = (float)((uint)fVar3 & 0xfffff000);
      fVar5 = 0.7853982;
      fVar3 = (-(-((square + -fVar1 * fVar1) / (fVar3 + fVar1)) * 2.0 + -4.371139e-08) +
              (fVar3 + fVar3) * fVar4) - (-fVar1 * 2.0 + 0.7853982);
    }
    else {
      fVar3 = (fVar3 + fVar3 * fVar4) * 2.0 + 4.371139e-08;
      fVar5 = 1.5707964;
    }
    fVar5 = fVar5 - fVar3;
    if ((int)param_1 < 1) {
      fVar5 = -fVar5;
    }
  }
  else {
    fVar5 = (param_1 - param_1) / (param_1 - param_1);
  }
  return fVar5;
}


