/*
 * Function: $_?_cvt
 * Entry:    0008a48a
 * Prototype: char * __stdcall $_?_cvt(_PRINTF_FLOAT_TYPE param_1, int param_2, int param_3, char * param_4, int * param_5, int param_6, int * param_7, char * param_8)
 */


char * ____cvt(_PRINTF_FLOAT_TYPE param_1,int param_2,int param_3,char *param_4,int *param_5,
              int param_6,int *param_7,char *param_8)

{
  uint uVar1;
  _PRINTF_FLOAT_TYPE _Var2;
  bool bVar3;
  char *pcVar4;
  uint uVar5;
  undefined1 uVar6;
  int iVar7;
  char *pcVar8;
  uint uVar9;
  undefined4 uStack_30;
  char *local_2c [2];
  
  iVar7 = (int)((ulonglong)param_1 >> 0x20);
  pcVar4 = param_4;
  if ((longlong)param_1 < 0) {
    iVar7 = iVar7 + -0x80000000;
    pcVar4 = SUB84(param_1,0);
  }
  _Var2 = (_PRINTF_FLOAT_TYPE)CONCAT44(iVar7,pcVar4);
  uVar9 = (uint)param_7 & 0xffffffdf;
  if ((longlong)param_1 < 0) {
    uVar6 = 0x2d;
  }
  else {
    uVar6 = 0;
    _Var2 = param_1;
  }
  uVar1 = (uint)((ulonglong)_Var2 >> 0x20);
  *(undefined1 *)param_5 = uVar6;
  if (uVar9 == 0x46) {
    uVar5 = 3;
  }
  else {
    if (uVar9 == 0x45) {
      param_3 = param_3 + 1;
    }
    uVar5 = 2;
  }
  pcVar4 = _dtoa_r(param_2,uVar5,(char *)param_3,(int *)param_6,&uStack_30,local_2c);
  if ((param_7 == (int *)0x67) || (param_7 == (int *)0x47)) {
    if (((uint)param_4 & 1) == 0) goto LAB_0008a50e;
    pcVar8 = pcVar4 + param_3;
  }
  else {
    pcVar8 = pcVar4 + param_3;
    if (uVar9 == 0x46) {
      if ((*pcVar4 == '0') && (bVar3 = __aeabi_dcmpeq(SUB84(_Var2,0),uVar1,0,0), !bVar3)) {
        *(int *)param_6 = 1 - param_3;
      }
      pcVar8 = pcVar8 + *(int *)param_6;
    }
  }
  bVar3 = __aeabi_dcmpeq(SUB84(_Var2,0),uVar1,0,0);
  if (bVar3) {
    local_2c[0] = pcVar8;
  }
  while (local_2c[0] < pcVar8) {
    *local_2c[0] = '0';
    local_2c[0] = local_2c[0] + 1;
  }
LAB_0008a50e:
  *(int *)param_8 = (int)local_2c[0] - (int)pcVar4;
  return pcVar4;
}


