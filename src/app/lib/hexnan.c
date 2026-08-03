/*
 * Function: hexnan
 * Entry:    0008ab66
 * Prototype: undefined4 __stdcall hexnan(int * param_1, uint * param_2, uint * param_3)
 */


/* exclude_from_export_ai */

undefined4 hexnan(int *param_1,uint *param_2,uint *param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  uint *puVar10;
  uint *puVar11;
  int iVar12;
  uint *puVar13;
  int iVar14;
  int local_38;
  uint *puVar9;
  
  iVar3 = *param_1;
  uVar6 = *param_2 & 0x1f;
  iVar12 = 0;
  puVar10 = param_3 + ((int)*param_2 >> 5);
  iVar14 = 0;
  if (uVar6 != 0) {
    puVar10 = puVar10 + 1;
  }
  local_38 = 0;
  puVar13 = puVar10 + -1;
  puVar10[-1] = 0;
  puVar11 = puVar13;
  puVar5 = puVar13;
LAB_0008ab96:
  while( true ) {
    iVar7 = iVar3 + 1;
    uVar4 = (uint)*(byte *)(iVar3 + 1);
    if (uVar4 == 0) break;
    cVar1 = __hexdig_fun(uVar4);
    if ((int)cVar1 != 0) {
      iVar12 = iVar12 + 1;
      iVar14 = iVar14 + 1;
      if (8 < iVar12) goto code_r0x0008ac5a;
      goto LAB_0008ac66;
    }
    if (0x20 < uVar4) {
      if (uVar4 != 0x29) goto LAB_0008ac98;
      *param_1 = iVar3 + 2;
      break;
    }
    iVar3 = iVar7;
    if (local_38 < iVar14) {
      if ((puVar11 < puVar5) && (iVar12 < 8)) {
        L_shift(puVar11,puVar5,iVar12);
      }
      if (param_3 < puVar11) {
        puVar5 = puVar11 + -1;
        puVar11[-1] = 0;
        iVar12 = 0;
        puVar11 = puVar5;
        local_38 = iVar14;
      }
      else {
        iVar12 = 8;
      }
    }
  }
  if (iVar14 == 0) {
LAB_0008ac98:
    uVar2 = 4;
  }
  else {
    if ((puVar11 < puVar5) && (iVar12 < 8)) {
      L_shift(puVar11,puVar5,iVar12);
    }
    if (param_3 < puVar11) {
      puVar5 = param_3 + -1;
      puVar8 = puVar11;
      do {
        puVar9 = puVar8 + 1;
        puVar5 = puVar5 + 1;
        *puVar5 = *puVar8;
        puVar8 = puVar9;
      } while (puVar9 <= puVar13);
      iVar3 = ((int)puVar13 - (int)puVar11 & 0xfffffffcU) + 4;
      if ((int)puVar10 - 3U < (int)puVar11 + 1U) {
        iVar3 = 4;
      }
      puVar10 = (uint *)(iVar3 + (int)param_3);
      do {
        puVar11 = puVar10 + 1;
        *puVar10 = 0;
        puVar10 = puVar11;
      } while (puVar11 <= puVar13);
    }
    else if (uVar6 != 0) {
      puVar10[-1] = puVar10[-1] & 0xffffffffU >> (0x20 - uVar6 & 0xff);
    }
    for (; *puVar13 == 0; puVar13 = puVar13 + -1) {
      if (puVar13 == param_3) {
        *puVar13 = 1;
        break;
      }
    }
    uVar2 = 5;
  }
  return uVar2;
code_r0x0008ac5a:
  iVar3 = iVar7;
  if (param_3 < puVar11) {
    puVar11 = puVar11 + -1;
    iVar12 = 1;
    *puVar11 = 0;
LAB_0008ac66:
    *puVar11 = (int)cVar1 & 0xfU | *puVar11 << 4;
    iVar3 = iVar7;
  }
  goto LAB_0008ab96;
}


