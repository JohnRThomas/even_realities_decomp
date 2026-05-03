/*
 * Function: $_?__printf_i
 * Entry:    0007a3d4
 * Prototype: uint __stdcall $_?__printf_i(int param_1, uint * param_2, undefined4 param_3, undefined * param_4, int * param_5)
 */


uint _____printf_i(int param_1,uint *param_2,undefined4 param_3,undefined *param_4,int *param_5)

{
  _PRINTF_FLOAT_TYPE _Var1;
  bool bVar2;
  undefined4 *puVar3;
  size_t sVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  char *s;
  _PRINTF_FLOAT_TYPE *p_Var9;
  char *pcVar10;
  uint uVar11;
  uint uVar12;
  int *fmtch;
  uint uVar13;
  char local_35;
  uint local_34;
  uint local_30;
  uint local_2c [2];
  
  puVar3 = (undefined4 *)FUN_0007b838();
  s = (char *)*puVar3;
  sVar4 = ____strlen(s);
  local_30 = 0;
  fmtch = (int *)(uint)(byte)param_2[6];
  uVar13 = *param_2;
  p_Var9 = (_PRINTF_FLOAT_TYPE *)(*param_5 + 7U & 0xfffffff8);
  *param_5 = (int)(p_Var9 + 1);
  uVar11 = *(uint *)p_Var9;
  uVar12 = *(uint *)((int)p_Var9 + 4);
  _Var1 = *p_Var9;
  param_2[0x12] = uVar11;
  param_2[0x13] = uVar12;
  iVar5 = __unorddf2(uVar11,uVar12 & 0x7fffffff,-1,0x7fefffff);
  if ((iVar5 != 0) || (bVar2 = __ledf2(uVar11,uVar12 & 0x7fffffff,0xffffffff,0x7fefffff), bVar2)) {
    iVar5 = __unorddf2(uVar11,uVar12,uVar11,uVar12);
    if (iVar5 != 0) {
      pcVar8 = "NAN";
      if ((int)uVar12 < 0) {
        *(undefined1 *)((int)param_2 + 0x43) = 0x2d;
      }
      pcVar10 = "nan";
      goto LAB_0007a45e;
    }
    if (param_2[1] == 0xffffffff) {
      uVar11 = 6;
LAB_0007a4bc:
      param_2[1] = uVar11;
    }
    else if ((((uint)fmtch & 0xdf) == 0x47) && (param_2[1] == 0)) {
      uVar11 = 1;
      goto LAB_0007a4bc;
    }
    pcVar8 = (char *)(uVar13 | 0x400);
    *param_2 = (uint)pcVar8;
    pcVar8 = ____cvt(_Var1,param_1,param_2[1],pcVar8,(int *)&local_35,(int)&local_34,fmtch,
                     (char *)&local_30);
    if (fmtch == (int *)0x67) {
      if (((int)local_34 < -3) || ((int)param_2[1] < (int)local_34)) {
        fmtch = (int *)0x65;
        goto LAB_0007a534;
      }
LAB_0007a4f6:
      if ((int)local_34 < (int)local_30) {
        if ((int)local_34 < 1) {
          iVar5 = 2 - local_34;
        }
        else {
          iVar5 = 1;
        }
        uVar11 = local_30 + iVar5;
LAB_0007a58e:
        param_2[4] = uVar11;
      }
      else {
        param_2[4] = local_34;
        if ((int)(*param_2 << 0x1f) < 0) {
          uVar11 = local_34 + 1;
          goto LAB_0007a58e;
        }
      }
LAB_0007a590:
      uVar11 = 0;
      param_2[0x16] = local_34;
    }
    else {
      if (fmtch == (int *)0x47) {
        if ((-4 < (int)local_34) && ((int)local_34 <= (int)param_2[1])) {
          fmtch = (int *)0x67;
          goto LAB_0007a4f6;
        }
        fmtch = (int *)0x45;
      }
      else if ((int *)0x65 < fmtch) {
        if (fmtch != (int *)0x66) goto LAB_0007a4f6;
        uVar11 = param_2[1];
        if ((int)local_34 < 1) {
          if ((uVar11 == 0) && (-1 < (int)(*param_2 << 0x1f))) {
            uVar11 = 1;
          }
          else {
            uVar11 = uVar11 + 2;
          }
        }
        else {
          param_2[4] = local_34;
          if ((uVar11 == 0) && (-1 < (int)(*param_2 << 0x1f))) goto LAB_0007a590;
          uVar11 = uVar11 + 1 + local_34;
        }
        goto LAB_0007a58e;
      }
LAB_0007a534:
      local_34 = local_34 - 1;
      uVar11 = __exponent((char *)(param_2 + 0x14),local_34,(int)fmtch);
      param_2[4] = local_30 + uVar11;
      if ((1 < (int)local_30) || ((int)(*param_2 << 0x1f) < 0)) {
        param_2[4] = local_30 + uVar11 + 1;
      }
    }
    if (local_35 != '\0') {
      *(undefined1 *)((int)param_2 + 0x43) = 0x2d;
    }
  }
  else {
    bVar2 = __gedf2(uVar11,uVar12,0,0);
    if (bVar2) {
      *(undefined1 *)((int)param_2 + 0x43) = 0x2d;
    }
    pcVar8 = "INF";
    pcVar10 = "inf";
LAB_0007a45e:
    if ((int *)0x47 < fmtch) {
      pcVar8 = pcVar10;
    }
    uVar11 = 0;
    param_2[4] = 3;
    *param_2 = uVar13 & 0xfffffffb;
  }
  iVar5 = _printf_common(param_1,param_2,local_2c,param_3,param_4);
  uVar12 = local_30;
  if (iVar5 == -1) {
    return 0xffffffff;
  }
  if ((int)(*param_2 << 0x15) < 0) {
    if (fmtch < (int *)0x66) {
      if (((int)local_30 < 2) && (-1 < (int)(*param_2 << 0x1f))) {
        iVar5 = 1;
LAB_0007a7d4:
        iVar5 = (*(code *)param_4)(param_1,param_3,pcVar8,iVar5);
        if (iVar5 == -1) {
          return 0xffffffff;
        }
      }
      else {
        iVar5 = (*(code *)param_4)(param_1,param_3,pcVar8,1);
        if (iVar5 == -1) {
          return 0xffffffff;
        }
        iVar5 = (*(code *)param_4)(param_1,param_3,s,sVar4);
        if (iVar5 == -1) {
          return 0xffffffff;
        }
        iVar5 = uVar12 - 1;
        bVar2 = __aeabi_dcmpeq(param_2[0x12],param_2[0x13],0,0);
        if (!bVar2) {
          pcVar8 = (char *)((int)pcVar8 + 1);
          goto LAB_0007a7d4;
        }
        for (iVar7 = 0; iVar7 < iVar5; iVar7 = iVar7 + 1) {
          iVar6 = (*(code *)param_4)(param_1,param_3,(int)param_2 + 0x1a,1);
          if (iVar6 == -1) {
            return 0xffffffff;
          }
        }
      }
      pcVar8 = (char *)(param_2 + 0x14);
    }
    else {
      bVar2 = __aeabi_dcmpeq(param_2[0x12],param_2[0x13],0,0);
      uVar11 = local_30;
      if (bVar2) {
        iVar5 = (*(code *)param_4)(param_1,param_3,"0",1);
        uVar11 = local_30;
        if (iVar5 == -1) {
          return 0xffffffff;
        }
        if (((int)local_34 < (int)local_30) || ((int)(*param_2 << 0x1f) < 0)) {
          iVar5 = (*(code *)param_4)(param_1,param_3,s,sVar4);
          if (iVar5 == -1) {
            return 0xffffffff;
          }
          for (iVar5 = 0; iVar5 < (int)(uVar11 - 1); iVar5 = iVar5 + 1) {
            iVar7 = (*(code *)param_4)(param_1,param_3,(int)param_2 + 0x1a,1);
            if (iVar7 == -1) {
              return 0xffffffff;
            }
          }
        }
        goto LAB_0007a622;
      }
      if (0 < (int)local_34) {
        uVar12 = param_2[0x16];
        if ((int)local_30 <= (int)param_2[0x16]) {
          uVar12 = local_30;
        }
        if ((0 < (int)uVar12) && (iVar5 = (*(code *)param_4)(param_1,param_3,pcVar8), iVar5 == -1))
        {
          return 0xffffffff;
        }
        for (iVar5 = 0; uVar13 = param_2[0x16],
            iVar5 < (int)(uVar13 - (uVar12 & ~((int)uVar12 >> 0x1f))); iVar5 = iVar5 + 1) {
          iVar7 = (*(code *)param_4)(param_1,param_3,(int)param_2 + 0x1a,1);
          if (iVar7 == -1) {
            return 0xffffffff;
          }
        }
        if ((((int)local_34 < (int)uVar11) || ((int)(*param_2 << 0x1f) < 0)) &&
           (iVar5 = (*(code *)param_4)(param_1,param_3,s,sVar4), iVar5 == -1)) {
          return 0xffffffff;
        }
        uVar12 = uVar11 - local_34;
        if ((int)(uVar11 - uVar13) <= (int)(uVar11 - local_34)) {
          uVar12 = uVar11 - uVar13;
        }
        if ((0 < (int)uVar12) &&
           (iVar5 = (*(code *)param_4)(param_1,param_3,(char *)(uVar13 + (int)pcVar8),uVar12),
           iVar5 == -1)) {
          return 0xffffffff;
        }
        for (iVar5 = 0; iVar5 < (int)((uVar11 - local_34) - (uVar12 & ~((int)uVar12 >> 0x1f)));
            iVar5 = iVar5 + 1) {
          iVar7 = (*(code *)param_4)(param_1,param_3,(int)param_2 + 0x1a,1);
          if (iVar7 == -1) {
            return 0xffffffff;
          }
        }
        goto LAB_0007a622;
      }
      iVar5 = (*(code *)param_4)(param_1,param_3,"0",1);
      uVar11 = local_30;
      if (iVar5 == -1) {
        return 0xffffffff;
      }
      if ((local_30 == 0 && local_34 == 0) && (-1 < (int)(*param_2 << 0x1f))) goto LAB_0007a622;
      iVar5 = (*(code *)param_4)(param_1,param_3,s,sVar4);
      if (iVar5 == -1) {
        return 0xffffffff;
      }
      for (iVar5 = 0; -iVar5 != local_34 && iVar5 <= (int)-local_34; iVar5 = iVar5 + 1) {
        iVar7 = (*(code *)param_4)(param_1,param_3,(int)param_2 + 0x1a,1);
        if (iVar7 == -1) {
          return 0xffffffff;
        }
      }
    }
  }
  else {
    uVar11 = param_2[4];
  }
  iVar5 = (*(code *)param_4)(param_1,param_3,pcVar8,uVar11);
  if (iVar5 == -1) {
    return 0xffffffff;
  }
LAB_0007a622:
  if ((int)(*param_2 << 0x1e) < 0) {
    for (iVar5 = 0; iVar5 < (int)(param_2[3] - local_2c[0]); iVar5 = iVar5 + 1) {
      iVar7 = (*(code *)param_4)(param_1,param_3,(int)param_2 + 0x19,1);
      if (iVar7 == -1) {
        return 0xffffffff;
      }
    }
  }
  if ((int)param_2[3] < (int)local_2c[0]) {
    return local_2c[0];
  }
  return param_2[3];
}


