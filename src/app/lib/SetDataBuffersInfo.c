/*
 * Function: SetDataBuffersInfo
 * Entry:    0007e3d8
 * Prototype: drvError_t __stdcall SetDataBuffersInfo(uint8_t * pDataIn, size_t dataInSize, CCBuffInfo_t * pInputBuffInfo, uint8_t * pDataOut, size_t dataOutSize, CCBuffInfo_t * pOutputBuffInfo)
 */


/* exclude_from_export */

drvError_t
SetDataBuffersInfo(uint8_t *pDataIn,size_t dataInSize,CCBuffInfo_t *pInputBuffInfo,uint8_t *pDataOut
                  ,size_t dataOutSize,CCBuffInfo_t *pOutputBuffInfo)

{
  int iVar1;
  
  iVar1 = CC_PalDataBufferAttrGet();
  if (iVar1 != 0) {
    return 0xf50000;
  }
  *pInputBuffInfo = pDataIn;
  *(undefined1 *)(pInputBuffInfo + 1) = 0;
  if (pOutputBuffInfo != (CCBuffInfo_t *)0x0) {
    if ((pDataOut != (uint8_t *)0x0) && (iVar1 = CC_PalDataBufferAttrGet(), iVar1 != 0)) {
      return 0xf50000;
    }
    *pOutputBuffInfo = pDataOut;
    *(undefined1 *)(pOutputBuffInfo + 1) = 0;
  }
  return 0;
}


