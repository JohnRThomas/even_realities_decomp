/*
 * Function: zcbor_int32_decode
 * Entry:    000897ec
 * Prototype: undefined1 __stdcall zcbor_int32_decode(int * param_1, size_t param_2, undefined4 param_3, zcbor_state_t * param_4)
 */


/* exclude_from_export_ai */

bool zcbor_int32_decode(int *param_1,size_t param_2,undefined4 param_3,zcbor_state_t *param_4)

{
  bool bVar1;
  int iVar2;
  zcbor_decoder_t decoder;
  void *unaff_r4;
  size_t unaff_r5;
  
  iVar2 = ZCBOR_CHECK_ERROR(param_1,(int *)&DAT_00000006);
  if ((iVar2 == 0) ||
     (bVar1 = value_extract((size_t)param_1,param_2,(size_t *)&Reset,decoder,param_4,unaff_r4,
                            unaff_r5), !bVar1)) {
    bVar1 = false;
  }
  else {
    param_1[2] = param_1[2] + 1;
  }
  return bVar1;
}


