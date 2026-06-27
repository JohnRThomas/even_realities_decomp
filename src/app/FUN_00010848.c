/*
 * Function: FUN_00010848
 * Entry:    00010848
 * Prototype: byte __stdcall FUN_00010848(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 */


byte FUN_00010848(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  uint uVar2;
  GlassesState *pGVar3;
  float fVar4;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  uint extraout_r3;
  byte bVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  
  if ((DAT_20019a6f == '\0') || (uVar2 = __opt3007_read(0,param_2,param_3), uVar2 + 1 < 2)) {
    bVar5 = 0xff;
  }
  else {
    pGVar3 = __get_dashboard_state();
    if (((*(int *)&pGVar3->field_0xfb4 == 0) ||
        (pGVar3 = __get_dashboard_state(), *(int *)&pGVar3->field_0xfb4 == -1)) ||
       (pGVar3 = __get_dashboard_state(), *(int *)&pGVar3->field_0xfb4 < 0xea61)) {
      if ((int)uVar2 < 0x32) {
        bVar5 = (byte)((int)uVar2 / 5);
      }
      else if ((int)uVar2 < 200) {
        bVar5 = (char)((uVar2 - 0x32) / 10) + 10;
      }
      else if ((int)uVar2 < 1000) {
        bVar5 = (char)((uVar2 - 200) / 0x32) + 0x19;
      }
      else if ((int)uVar2 < 10000) {
        bVar5 = (char)((uVar2 - 1000) / 1000) + 0x29;
      }
      else {
        if (79999 < (int)uVar2) {
          return 0x2a;
        }
        bVar5 = (char)((uVar2 - 10000) / 5000) + 0x32;
      }
      if (0x29 < bVar5) {
        bVar5 = 0x2a;
      }
    }
    else {
      uVar6 = __floatsidf(uVar2);
      pGVar3 = __get_dashboard_state();
      uVar7 = __floatsidf(*(uint *)&pGVar3->field_0xfb4);
      uVar7 = __divdf3((uint)uVar7,(uint)(uVar7 >> 0x20),0,0x412e8480);
      uVar6 = __muldf3((uint)uVar7,(uint)(uVar7 >> 0x20),(uint)uVar6,(uint)(uVar6 >> 0x20));
      fVar4 = (float)__truncdfsf2((uint)uVar6,(uint)(uVar6 >> 0x20));
      bVar5 = DAT_20019a6e;
      if (DAT_20019a6e == 0xc) {
        if (120.0 < fVar4) {
          bVar5 = 0x13;
          DAT_20019a6e = bVar5;
        }
        else {
          DAT_20019a6e = bVar5;
          if ((int)((uint)(fVar4 < 8.0) << 0x1f) < 0) {
            bVar5 = 6;
            DAT_20019a6e = bVar5;
          }
        }
      }
      else if (DAT_20019a6e < 0xd) {
        if (DAT_20019a6e == 3) {
          if (6.0 < fVar4) {
            bVar5 = 6;
            DAT_20019a6e = bVar5;
          }
          else {
            uVar6 = __aeabi_f2d((uint)fVar4,extraout_r1,extraout_r2,extraout_r3);
            bVar1 = __gedf2((uint)uVar6,(uint)(uVar6 >> 0x20),0x9999999a,0x3ff99999);
            DAT_20019a6e = bVar5;
            if (bVar1) {
              bVar5 = 0;
              DAT_20019a6e = bVar5;
            }
          }
        }
        else if (DAT_20019a6e == 6) {
          if (12.0 < fVar4) {
            bVar5 = 0xc;
            DAT_20019a6e = bVar5;
          }
          else {
            DAT_20019a6e = bVar5;
            if ((int)((uint)(fVar4 < 4.0) << 0x1f) < 0) {
              bVar5 = 3;
              DAT_20019a6e = bVar5;
            }
          }
        }
        else {
          DAT_20019a6e = bVar5;
          if (DAT_20019a6e == 0) {
            uVar6 = __aeabi_f2d((uint)fVar4,extraout_r1,extraout_r2,extraout_r3);
            bVar1 = __ltdf2((uint)uVar6,(uint)(uVar6 >> 0x20),0x33333333,0x40033333);
            DAT_20019a6e = bVar5;
            if (bVar1) {
              bVar5 = 3;
              DAT_20019a6e = bVar5;
            }
          }
        }
      }
      else if (DAT_20019a6e == 0x1a) {
        if (1440.0 < fVar4) {
          bVar5 = 0x2a;
          DAT_20019a6e = bVar5;
        }
        else {
          DAT_20019a6e = bVar5;
          if ((int)((uint)(fVar4 < 372.0) << 0x1f) < 0) {
            bVar5 = 0x13;
            DAT_20019a6e = bVar5;
          }
        }
      }
      else if (DAT_20019a6e == 0x2a) {
        DAT_20019a6e = bVar5;
        if ((int)((uint)(fVar4 < 960.0) << 0x1f) < 0) {
          bVar5 = 0x1a;
          DAT_20019a6e = bVar5;
        }
      }
      else {
        DAT_20019a6e = bVar5;
        if (DAT_20019a6e == 0x13) {
          if (496.0 < fVar4) {
            bVar5 = 0x1a;
            DAT_20019a6e = bVar5;
          }
          else if ((int)((uint)(fVar4 < 75.0) << 0x1f) < 0) {
            bVar5 = 0xc;
            DAT_20019a6e = bVar5;
          }
        }
      }
    }
  }
  return bVar5;
}


