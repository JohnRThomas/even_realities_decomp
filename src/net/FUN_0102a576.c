/*
 * Function: FUN_0102a576
 * Entry:    0102a576
 * Prototype: byte __stdcall FUN_0102a576(byte * param_1, byte * param_2, undefined4 param_3)
 */


byte FUN_0102a576(byte *param_1,byte *param_2,undefined4 param_3)

{
  bool bVar1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar2;
  undefined4 extraout_r2_01;
  undefined2 uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint extraout_r3;
  byte bVar6;
  char *pcVar7;
  
  if (param_2 == (byte *)0x0) {
switchD_0102a58c_default:
    param_1[0x29] = 1;
LAB_0102a600:
    FUN_0102221c();
switchD_0102a58c_caseD_0:
    bVar6 = 2;
  }
  else {
    bVar6 = *param_2;
    switch(bVar6) {
    case 0:
      goto switchD_0102a58c_caseD_0;
    case 1:
      if ((*(uint *)(param_2 + 4) < 200) ||
         (uVar5 = FUN_010246a8(*(uint *)(param_2 + 4),3,param_3), uVar5 != 0)) {
        bVar6 = 0;
      }
      else {
        FUN_0102a568((int)param_1,*(int *)(param_2 + 4),extraout_r2);
      }
      break;
    case 2:
      FUN_0102221c();
      break;
    case 3:
      if (param_1[0x24] == 0) {
        pcVar7 = *(char **)(param_2 + 4);
        bVar1 = FUN_010221c4(pcVar7);
        if (!bVar1) goto switchD_0102a58c_default;
        if (*pcVar7 == '\0') {
          param_1[0xb] = 0;
          *param_1 = 1;
          if (pcVar7[4] == '\0') {
            uVar3 = 0x2b;
          }
          else {
            uVar3 = 0;
          }
          *(undefined2 *)(param_1 + 8) = uVar3;
          if (pcVar7[5] == '\0') {
            bVar6 = 2;
          }
          param_1[10] = bVar6;
          *(int *)(param_1 + 4) = *(int *)(pcVar7 + 8) + 0x73;
          uVar4 = *(undefined4 *)(pcVar7 + 0xc);
          param_1[0x25] = 1;
          *(undefined4 *)(param_1 + 0x10) = uVar4;
          param_1[0x26] = 3;
        }
        else {
          uVar5 = (uint)param_1[0x26];
          if (uVar5 == 5) goto LAB_0102a61a;
          uVar4 = 0x17c;
          uVar2 = extraout_r2_00;
          while( true ) {
            FUN_01025edc(0x6a,uVar4,uVar2,uVar5);
LAB_0102a61a:
            *param_1 = 0;
            param_1[0xb] = 0;
            if (pcVar7[4] == '\0') {
              uVar3 = 0x2b;
            }
            else {
              uVar3 = 0;
            }
            *(undefined2 *)(param_1 + 8) = uVar3;
            if (pcVar7[5] == '\0') {
              bVar6 = 2;
            }
            param_1[10] = bVar6;
            uVar5 = *(uint *)(pcVar7 + 8);
            *(int *)(param_1 + 4) = *(int *)(pcVar7 + 0xc) + 0x73;
            *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x18) + uVar5;
            *(uint *)(param_1 + 0x14) =
                 *(int *)(param_1 + 0x1c) +
                 ((int)uVar5 >> 0x1f) + (uint)CARRY4(*(uint *)(param_1 + 0x18),uVar5);
            param_1[0x26] = 4;
            uVar5 = FUN_010239c8((uint)param_1[0x27],param_1);
            if (uVar5 != 0) break;
            uVar4 = 0x17e;
            uVar2 = extraout_r2_01;
            uVar5 = extraout_r3;
          }
        }
      }
      goto LAB_0102a600;
    default:
      goto switchD_0102a58c_default;
    }
  }
  return bVar6;
}


