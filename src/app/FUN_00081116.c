/*
 * Function: FUN_00081116
 * Entry:    00081116
 * Prototype: uint __stdcall FUN_00081116(uint param_1, uint param_2, uint param_3, int param_4, char param_5, byte * param_6, int param_7)
 */


uint FUN_00081116(uint param_1,uint param_2,uint param_3,int param_4,char param_5,byte *param_6,
                 int param_7)

{
  byte *pbVar1;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  byte *pbVar2;
  
  uVar4 = 0;
  if (param_6 != (byte *)0x0) {
    if (param_7 < 1) {
      uVar4 = 0;
    }
    else {
      pbVar2 = param_6;
      do {
        pbVar1 = pbVar2 + 1;
        uVar4 = (uint)*pbVar2;
        if (param_4 != 0) {
          uVar6 = 7;
          uVar3 = 0;
          uVar7 = uVar4;
          do {
            uVar4 = uVar3;
            if ((uVar7 & 1) != 0) {
              uVar4 = uVar4 | 1 << (uVar6 & 0xff) & 0xffU;
            }
            bVar8 = uVar6 != 0;
            uVar6 = uVar6 - 1;
            uVar7 = uVar7 >> 1;
            uVar3 = uVar4;
          } while (bVar8);
        }
        param_1 = param_1 ^ uVar4 << 8;
        iVar5 = 8;
        do {
          uVar4 = param_1 & 0x8000;
          param_1 = (param_1 & 0x7fff) << 1;
          if (uVar4 != 0) {
            param_1 = param_1 ^ param_2;
          }
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
        pbVar2 = pbVar1;
      } while (param_6 + param_7 != pbVar1);
      uVar4 = param_1;
      if (param_5 != '\0') {
        uVar3 = 0xf;
        uVar4 = 0;
        do {
          if ((int)(param_1 << 0x1f) < 0) {
            uVar4 = (uint)(ushort)((ushort)(1 << (uVar3 & 0xff)) | (ushort)uVar4);
          }
          bVar8 = uVar3 != 0;
          uVar3 = uVar3 - 1;
          param_1 = (param_1 & 0x1ffff) >> 1;
        } while (bVar8);
      }
      uVar4 = param_3 ^ uVar4;
    }
  }
  return uVar4;
}


