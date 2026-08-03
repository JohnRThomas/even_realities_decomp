/*
 * Function: kmu_derive_cmac
 * Entry:    0007f0cc
 * Prototype: drvError_t __stdcall kmu_derive_cmac(undefined4 param_1, undefined4 param_2, uint8_t * param_3, size_t param_4, uint8_t * param_5, size_t param_6, int param_7, uint param_8)
 */


/* exclude_from_export */

drvError_t
kmu_derive_cmac(undefined4 param_1,undefined4 param_2,uint8_t *param_3,size_t param_4,
               uint8_t *param_5,size_t param_6,int param_7,uint param_8)

{
  drvError_t dVar1;
  char cVar2;
  uint n;
  int iVar3;
  size_t local_13c;
  CCBuffInfo_t apuStack_138 [2];
  CCBuffInfo_t apuStack_130 [2];
  uint8_t local_128 [16];
  AesContext_t aAStack_118 [12];
  undefined4 local_e8;
  undefined4 local_e4;
  CCUtilError_t local_e0;
  undefined1 local_dc;
  undefined4 local_d8;
  undefined4 local_c0;
  undefined4 uStack_bc;
  undefined4 local_b8;
  uint8_t local_a4 [132];
  
  memset(aAStack_118,0,0x74);
  local_a4[0] = '\0';
  local_a4[1] = '\0';
  local_a4[2] = '\0';
  local_a4[3] = '\0';
  memset(local_a4 + 4,0,0x80);
  local_128[0] = '\0';
  local_128[1] = '\0';
  local_128[2] = '\0';
  local_128[3] = '\0';
  local_128[4] = '\0';
  local_128[5] = '\0';
  local_128[6] = '\0';
  local_128[7] = '\0';
  local_128[0xc] = '\0';
  local_128[0xd] = '\0';
  local_128[0xe] = '\0';
  local_128[0xf] = '\0';
  local_128[8] = '\0';
  local_128[9] = '\0';
  local_128[10] = '\0';
  local_128[0xb] = '\0';
  local_13c = 0x84;
  if (0xff0 < param_8) {
    return 0xf1000f;
  }
  write_invalid_key();
  local_e0 = UtilCmacBuildDataForDerivation
                       (param_3,param_4,param_5,param_6,local_a4,&local_13c,param_8);
  if (local_e0 != 0) {
    return 0xf1000e;
  }
  local_e4 = 7;
  local_dc = 2;
  cVar2 = '\x01';
  local_c0 = 0;
  uStack_bc = 1;
  local_b8 = 1;
  local_e8 = param_2;
  local_d8 = param_1;
  CC_HalWriteRegister(aAStack_118,0x10);
  dVar1 = SetDataBuffersInfo(local_a4,local_13c,apuStack_138,local_128,0x10,apuStack_130);
  iVar3 = 0;
  if (dVar1 == 0) {
    do {
      local_a4[0] = cVar2;
      dVar1 = FinishAesDrv(aAStack_118,apuStack_138,apuStack_130,local_13c);
      if (dVar1 != 0) goto LAB_0007f1b4;
      n = param_8;
      if (0xf < param_8) {
        n = 0x10;
      }
      memmove((void *)(param_7 + iVar3),aAStack_118,n);
      CC_HalWriteRegister(aAStack_118,0x10);
      cVar2 = cVar2 + '\x01';
      param_8 = param_8 - n;
      iVar3 = iVar3 + n;
    } while (param_8 != 0);
    dVar1 = 0;
  }
LAB_0007f1b4:
  memset(aAStack_118,0,0x74);
  write_invalid_key();
  return dVar1;
}


