/*
 * Function: FUN_0102a922
 * Entry:    0102a922
 * Prototype: undefined4 __stdcall FUN_0102a922(uint param_1, char * param_2)
 */


undefined4 FUN_0102a922(uint param_1,char *param_2)

{
  bool bVar1;
  byte *pbVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 extraout_r2;
  byte bVar5;
  undefined2 uVar6;
  undefined4 extraout_r3;
  uint uVar7;
  
  pbVar2 = (byte *)FUN_010222c0(param_1);
  if (pbVar2 == (byte *)0x0) {
    uVar4 = 0xfffffffe;
  }
  else {
    uVar7 = (uint)pbVar2[0x26];
    if (uVar7 - 1 < 2) {
      if ((param_2 == (char *)0x0) || (bVar1 = FUN_010221c4(param_2), !bVar1)) {
        uVar4 = 0xffffffea;
      }
      else {
        if (*param_2 != '\0') goto LAB_0102a990;
        pbVar2[0xb] = 0;
        *pbVar2 = 1;
        if (param_2[4] == '\0') {
          uVar6 = 0x2b;
        }
        else {
          uVar6 = 0;
        }
        *(undefined2 *)(pbVar2 + 8) = uVar6;
        if (param_2[5] == '\0') {
          bVar5 = 2;
        }
        else {
          bVar5 = 3;
        }
        pbVar2[10] = bVar5;
        *(int *)(pbVar2 + 4) = *(int *)(param_2 + 8) + 0x73;
        *(undefined4 *)(pbVar2 + 0x10) = *(undefined4 *)(param_2 + 0xc);
        bVar5 = 3;
        while( true ) {
          pbVar2[0x26] = bVar5;
          uVar3 = FUN_010239c8((uint)pbVar2[0x27],pbVar2);
          if (uVar3 != 0) break;
          FUN_01025edc(0x6a,0x2b1,extraout_r2,extraout_r3);
LAB_0102a990:
          if (uVar7 != 2) goto LAB_0102a9d6;
          *pbVar2 = 0;
          pbVar2[0xb] = 0;
          if (param_2[4] == '\0') {
            uVar6 = 0x2b;
          }
          else {
            uVar6 = 0;
          }
          *(undefined2 *)(pbVar2 + 8) = uVar6;
          if (param_2[5] != '\0') {
            uVar7 = 3;
          }
          pbVar2[10] = (byte)uVar7;
          uVar3 = *(uint *)(param_2 + 8);
          *(int *)(pbVar2 + 4) = *(int *)(param_2 + 0xc) + 0x73;
          *(uint *)(pbVar2 + 0x10) = *(uint *)(pbVar2 + 0x18) + uVar3;
          *(uint *)(pbVar2 + 0x14) =
               *(int *)(pbVar2 + 0x1c) +
               ((int)uVar3 >> 0x1f) + (uint)CARRY4(*(uint *)(pbVar2 + 0x18),uVar3);
          bVar5 = 4;
        }
        uVar4 = 0;
      }
    }
    else {
LAB_0102a9d6:
      uVar4 = 0xffffffdd;
    }
  }
  return uVar4;
}


