/*
 * Function: parse_string
 * Entry:    0007c5d4
 * Prototype: undefined4 __stdcall parse_string(undefined4 param_1, uint * param_2, int * param_3, undefined4 * param_4)
 */


/* exclude_from_export_ai */

undefined4 parse_string(undefined4 param_1,uint *param_2,int *param_3,undefined4 *param_4)

{
  void *pvVar1;
  undefined4 uVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  undefined4 *puVar6;
  uint *puVar7;
  uint *puVar8;
  int iVar9;
  uint *puVar10;
  int iVar11;
  char *local_34 [4];
  
  iVar11 = 0;
  local_34[0] = "+-";
  local_34[1] = "00";
  local_34[2] = "xX";
  puVar6 = &UNK_0008a8da;
  if (param_2[6] == 3) {
    puVar6 = &SUB_0008a8d6;
  }
  if (param_2[2] - 1 < 0x15d) {
    iVar9 = 0;
  }
  else {
    iVar9 = param_2[2] - 0x15d;
    param_2[2] = 0x15d;
  }
  puVar8 = param_2 + 7;
  *param_2 = *param_2 | 0xd00;
  puVar10 = puVar8;
LAB_0007c62c:
  do {
    pvVar1 = memchr(local_34[iVar11],(uint)*(byte *)*param_3,2);
    puVar7 = puVar10;
    if (pvVar1 != (void *)0x0) {
      if (iVar11 == 1) {
        if (param_2[1] == 0) {
          param_2[1] = 8;
          *param_2 = *param_2 | 0x200;
        }
        *param_2 = *param_2 & 0xfffffaff;
        uVar3 = param_2[2];
        param_2[2] = uVar3 - 1;
        if (uVar3 == 0) {
          iVar11 = 2;
          goto LAB_0007c62c;
        }
      }
      else if (iVar11 == 2) {
        if ((*param_2 & 0x600) != 0x200) break;
        *param_2 = *param_2 | 0x100;
        uVar3 = param_2[2];
        param_2[1] = 0x10;
        param_2[2] = uVar3 - 1;
        if (uVar3 == 0) break;
      }
      else {
        uVar3 = param_2[2];
        param_2[2] = uVar3 - 1;
        if (uVar3 == 0) {
          iVar11 = 1;
          goto LAB_0007c62c;
        }
      }
      pbVar4 = (byte *)*param_3;
      *param_3 = (int)(pbVar4 + 1);
      puVar7 = (uint *)((int)puVar10 + 1);
      *(byte *)puVar10 = *pbVar4;
      iVar5 = param_3[1];
      param_3[1] = iVar5 + -1;
      if ((iVar5 + -1 < 1) && (iVar5 = (*(code *)param_2[0x60])(param_1,param_3), iVar5 != 0)) {
        iVar11 = 0;
        goto LAB_0007c748;
      }
    }
    iVar11 = iVar11 + 1;
    puVar10 = puVar7;
  } while (iVar11 != 3);
  if (param_2[1] == 0) {
    param_2[1] = 10;
  }
  iVar11 = 0;
  ____FUN_0008b04c(param_2[5],(byte *)("A-Fa-f8901234567]" + (0x10 - param_2[1])));
  while( true ) {
    puVar7 = puVar10;
    if (param_2[2] == 0) break;
    pbVar4 = (byte *)*param_3;
    uVar3 = (uint)*pbVar4;
    if (*(char *)(param_2[5] + uVar3) == '\0') break;
    if ((uVar3 == 0x30) && ((int)(*param_2 << 0x14) < 0)) {
      iVar11 = iVar11 + 1;
      if (iVar9 != 0) {
        iVar9 = iVar9 + -1;
        param_2[2] = param_2[2] + 1;
      }
    }
    else {
      *param_2 = *param_2 & 0xfffff6ff;
      puVar7 = (uint *)((int)puVar10 + 1);
      *(byte *)puVar10 = *pbVar4;
    }
    iVar5 = param_3[1];
    param_3[1] = iVar5 + -1;
    if (iVar5 + -1 < 1) {
      iVar5 = (*(code *)param_2[0x60])(param_1,param_3);
      if (iVar5 != 0) break;
    }
    else {
      *param_3 = *param_3 + 1;
    }
    param_2[2] = param_2[2] - 1;
    puVar10 = puVar7;
  }
LAB_0007c748:
  puVar10 = puVar7;
  if ((int)(*param_2 << 0x17) < 0) {
    if (puVar8 < puVar7) {
      puVar10 = (uint *)((int)puVar7 + -1);
      (*(code *)param_2[0x5f])(param_1,*(byte *)((int)puVar7 + -1),param_3);
    }
    if (puVar10 == puVar8) {
      return 1;
    }
  }
  if ((*param_2 & 0x10) == 0) {
    *(byte *)puVar10 = 0;
    uVar2 = (*(code *)((int)puVar6 + 1))(param_1,puVar8,0,param_2[1]);
    puVar6 = (undefined4 *)*param_4;
    uVar3 = *param_2;
    *param_4 = puVar6 + 1;
    puVar6 = (undefined4 *)*puVar6;
    if ((uVar3 & 0x20) == 0) {
      if ((int)(uVar3 << 0x1f) < 0) {
        *(short *)puVar6 = (short)uVar2;
      }
      else {
        *puVar6 = uVar2;
      }
    }
    else {
      *puVar6 = uVar2;
    }
    param_2[3] = param_2[3] + 1;
  }
  param_2[4] = (uint)((int)puVar10 + param_2[4] + (iVar11 - (int)puVar8));
  return 0;
}


