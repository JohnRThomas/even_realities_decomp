/*
 * Function: FUN_000294d0
 * Entry:    000294d0
 * Prototype: uint __stdcall FUN_000294d0(int param_1, int param_2, void * param_3, size_t param_4)
 */


uint FUN_000294d0(int param_1,int param_2,void *param_3,size_t param_4)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  code *pcVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 *m2;
  
  cVar1 = FUN_00033d5c();
  uVar9 = 0;
  if (cVar1 != '\x01') {
    while (DAT_20019a5a != '\0') {
      uVar9 = uVar9 + 1;
      if (uVar9 == 2000) {
        DAT_20019a5a = 0;
        return 2000;
      }
      k_msleep(1);
    }
    DAT_20019a5a = 1;
    uVar9 = uVar9 & 0xffff;
    *(char *)(param_1 + 0x6e1) = *(char *)(param_1 + 0x6e1) + '\x01';
    *(byte *)(param_1 + 0x6cc) = (byte)param_2 & 0x3f | 0x80;
    m2 = (undefined4 *)(param_1 + 0x6cc);
    *(undefined1 *)(param_1 + 0x6cd) = *(undefined1 *)(param_1 + 0xfd3);
    *(undefined1 *)(param_1 + 0x6ce) = *(undefined1 *)(param_1 + 0xfd4);
    *(undefined1 *)(param_1 + 0x6cf) = *(undefined1 *)(param_1 + 0xfd5);
    *(undefined4 *)(param_1 + 0x6d8) = *(undefined4 *)(param_1 + 0xfe4);
    *(undefined2 *)(param_1 + 0x6dc) = *(undefined2 *)(param_1 + 0xfe8);
    *(undefined1 *)(param_1 + 0x6d0) = *(undefined1 *)(param_1 + 0xfc4);
    if (param_2 - 0xcU < 2) {
      DAT_2001993d = 4;
      puVar5 = m2;
      puVar8 = &DAT_2001993e;
      do {
        puVar4 = puVar5 + 1;
        puVar7 = puVar8 + 1;
        *puVar8 = *puVar5;
        puVar5 = puVar4;
        puVar8 = puVar7;
      } while (puVar4 != (undefined4 *)(param_1 + 0x6e0));
      *(undefined2 *)puVar7 = *(undefined2 *)puVar4;
      memcpy((void *)((int)&DAT_2001993e + 1),param_3,param_4);
      uVar3 = 0xdc;
      *(undefined1 *)(param_1 + 0x106e) = 1;
      pcVar6 = *(code **)(param_1 + 0x774);
    }
    else {
      if ((param_3 != (void *)0x0) && (param_4 != 0)) {
        if (1 < param_4) {
          param_4 = 2;
        }
        memcpy((void *)(param_1 + 0x6df),param_3,param_4);
      }
      if (param_2 == 1) {
        DAT_20019a4e = *(undefined1 *)(param_1 + 0x6e1);
        iVar2 = memcmp(&DAT_20019a39,m2,0x16);
        if (iVar2 == 0) {
          DAT_20019a5a = 0;
          return uVar9;
        }
        DAT_2001993d = 4;
        puVar5 = m2;
        puVar8 = &DAT_2001993e;
        do {
          puVar4 = puVar5 + 1;
          puVar7 = puVar8 + 1;
          *puVar8 = *puVar5;
          puVar5 = puVar4;
          puVar8 = puVar7;
        } while (puVar4 != (undefined4 *)(param_1 + 0x6e0));
      }
      else {
        DAT_2001993d = 4;
        puVar5 = m2;
        puVar8 = &DAT_2001993e;
        do {
          puVar4 = puVar5 + 1;
          puVar7 = puVar8 + 1;
          *puVar8 = *puVar5;
          puVar5 = puVar4;
          puVar8 = puVar7;
        } while (puVar4 != (undefined4 *)(param_1 + 0x6e0));
      }
      uVar3 = 0x21;
      *(undefined2 *)puVar7 = *(undefined2 *)puVar4;
      *(undefined1 *)(param_1 + 0x106e) = 1;
      pcVar6 = *(code **)(param_1 + 0x774);
    }
    (*pcVar6)(&DAT_2001993d,uVar3);
    while (*(char *)(param_1 + 0x106e) != '\x02') {
      uVar9 = uVar9 + 1 & 0xffff;
      if (uVar9 == 2000) {
        if (param_2 != 1) {
          DAT_20019a5a = 0;
          return 2000;
        }
        memset(&DAT_20019a39,0,0x16);
        DAT_20019a5a = 0;
        return 2000;
      }
      k_msleep(1);
    }
    if (param_2 == 1) {
      puVar5 = &DAT_20019a39;
      do {
        puVar4 = m2 + 1;
        puVar8 = puVar5 + 1;
        *puVar5 = *m2;
        puVar5 = puVar8;
        m2 = puVar4;
      } while (puVar4 != (undefined4 *)(param_1 + 0x6e0));
      *(undefined2 *)puVar8 = *(undefined2 *)puVar4;
    }
  }
  DAT_20019a5a = 0;
  return uVar9;
}


