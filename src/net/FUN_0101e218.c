/*
 * Function: FUN_0101e218
 * Entry:    0101e218
 * Prototype: undefined __stdcall FUN_0101e218(undefined4 * param_1, int param_2)
 */


void FUN_0101e218(undefined4 *param_1,int param_2)

{
  uint uVar1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  short sVar2;
  uint uVar3;
  undefined4 extraout_r3;
  uint uVar4;
  
  if (param_2 == 0) {
    return;
  }
  uVar4 = param_2 - 1U & 0xffff;
  do {
    *(short *)((int)param_1 + 0x302) = *(short *)((int)param_1 + 0x302) + 1;
    *(short *)((int)param_1 + 0xf6) = *(short *)((int)param_1 + 0xf6) + 1;
    if ((*(char *)((int)param_1 + 0xcb) != '\0') ||
       (uVar1 = FUN_0100dbc0((int)(param_1 + 0x2a),6,(uint)*(byte *)((int)param_1 + 0xc5),0),
       uVar1 != 0)) {
      uVar1 = param_1[0x3b];
      uVar3 = param_1[0x3a] + 1;
      param_1[0x3a] = uVar3;
      if ((uVar1 < uVar3) || (uVar1 - uVar3 <= *(ushort *)(param_1 + 7) + 5)) {
        *(undefined1 *)(param_1 + 0x3d) = 1;
      }
      if (uVar1 <= uVar3) {
        param_1[0x3a] = 0;
        FUN_0100f7c8((undefined4 *)((int)param_1 + 0x1c5),0x10109cd,2);
      }
    }
    if (*(char *)(param_1 + 0x40) != '\0') {
      *(short *)(param_1 + 0x3f) = *(short *)(param_1 + 0x3f) + 1;
    }
    if (*(char *)(param_1 + 0x41) != '\0') {
      *(short *)((int)param_1 + 0x102) = *(short *)((int)param_1 + 0x102) + 1;
    }
    if ((*(char *)(param_1 + 0x58) != '\0') ||
       (uVar1 = FUN_0100dbc0((int)(param_1 + 0x2a),1,(uint)*(byte *)((int)param_1 + 199),0),
       uVar1 != 0)) {
      *(short *)((int)param_1 + 0xfa) = *(short *)((int)param_1 + 0xfa) + 1;
    }
    uVar1 = (uint)*(byte *)((int)param_1 + 0xc5);
    sVar2 = *(short *)(param_1 + 0x2f);
    if (uVar1 - 0xc < 2) {
      sVar2 = sVar2 + 1;
      if (*(short *)((int)param_1 + 0x316) == sVar2) {
        *(undefined4 *)((int)param_1 + 0xce) = *(undefined4 *)(param_1[0xc4] + 1);
        *(undefined1 *)((int)param_1 + 0xd2) = *(undefined1 *)(param_1[0xc4] + 5);
        FUN_0100d94c(param_1,3);
        if (*(char *)param_1[0xc4] == '\0') {
          FUN_01009500(0x36,0x21e,extraout_r2,0);
          DAT_210003a4 = 0x10103bd;
          DAT_210003a8 = 0x1010305;
          DAT_21000450 = 0x10102c1;
          DAT_21000454 = 0x101cae5;
          return;
        }
        if (*(char *)(DAT_21001128 + 0x14e) != '\x01') {
          **(char **)(DAT_21001128 + 0x310) = **(char **)(DAT_21001128 + 0x310) + -1;
        }
        *(undefined1 *)((int)param_1 + 0xc5) = 0;
        sVar2 = *(short *)(param_1 + 0x2f);
        *(undefined1 *)((int)param_1 + 0x11e) = 0xff;
        uVar1 = (uint)*(byte *)((int)param_1 + 0xc5);
        goto LAB_0101e286;
      }
    }
    else {
LAB_0101e286:
      sVar2 = sVar2 + 1;
      if ((uVar1 - 0xe < 2) && (*(short *)((int)param_1 + 0x31e) == sVar2)) {
        *(undefined2 *)((int)param_1 + 0x22e) = *(undefined2 *)param_1;
        uVar1 = FUN_0100ddd0(param_1[0xca]);
        *(short *)(param_1 + 0x8c) = (short)uVar1;
        *(undefined2 *)((int)param_1 + 0x232) = *(undefined2 *)(param_1 + 0xcb);
        *(undefined1 *)((int)param_1 + 0x22d) = 0;
        *(undefined2 *)(param_1 + 0x8d) = *(undefined2 *)((int)param_1 + 0x32e);
        FUN_0100f7c8(param_1 + 0x89,&LAB_010101cc_1,2);
        *(undefined1 *)(param_1 + 199) = 0;
        FUN_0100d94c(param_1,2);
        FUN_0101c5d4(param_1,3,extraout_r2_00,extraout_r3);
        *(undefined1 *)((int)param_1 + 0xc5) = 0;
        sVar2 = *(short *)(param_1 + 0x2f) + 1;
      }
    }
    *(short *)(param_1 + 0x2f) = sVar2;
    uVar4 = uVar4 - 1 & 0xffff;
    if (uVar4 == 0xffff) {
      return;
    }
  } while( true );
}


