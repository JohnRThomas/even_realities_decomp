/*
 * Function: UtilCmacBuildDataForDerivation
 * Entry:    0007f1ec
 * Prototype: CCUtilError_t __stdcall UtilCmacBuildDataForDerivation(uint8_t * pLabel, size_t labelSize, uint8_t * pContextData, size_t contextSize, uint8_t * pDataIn, size_t * pDataInSize, size_t derivedKeySize)
 */


/* exclude_from_export */

CCUtilError_t
UtilCmacBuildDataForDerivation
          (uint8_t *pLabel,size_t labelSize,uint8_t *pContextData,size_t contextSize,
          uint8_t *pDataIn,size_t *pDataInSize,size_t derivedKeySize)

{
  size_t sVar1;
  uint uVar2;
  int iVar3;
  uint local_20;
  uint local_1c;
  
  local_1c = 0;
  if (derivedKeySize < 0xff1) {
    uVar2 = derivedKeySize * 8;
    if (uVar2 < 0x100) {
      local_20 = 3;
    }
    else {
      local_20 = 4;
    }
    if (((((labelSize - 1 < 0x40) && (pLabel != (uint8_t *)0x0)) &&
         ((contextSize == 0 || ((pContextData != (uint8_t *)0x0 && (contextSize < 0x41)))))) &&
        (pDataIn != (uint8_t *)0x0)) &&
       ((*pDataInSize != 0 && (local_20 + labelSize + contextSize <= *pDataInSize)))) {
      memmove(pDataIn + 1,pLabel,labelSize);
      iVar3 = labelSize + 2;
      pDataIn[labelSize + 1] = '\0';
      if (contextSize != 0) {
        memmove(pDataIn + iVar3,pContextData,contextSize);
        iVar3 = iVar3 + contextSize;
      }
      local_20 = uVar2;
      if (uVar2 < 0x100) {
        memmove(pDataIn + iVar3,&local_20,1);
        sVar1 = iVar3 + 1;
      }
      else {
        local_1c = (derivedKeySize & 0x1f) << 0xb | (derivedKeySize & 0x1fffffff) >> 5;
        memmove(pDataIn + iVar3,&local_1c,2);
        sVar1 = iVar3 + 2;
      }
      *pDataInSize = sVar1;
      return 0;
    }
  }
  return -0x7ffffffa;
}


