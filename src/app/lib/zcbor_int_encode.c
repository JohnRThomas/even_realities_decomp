/*
 * Function: zcbor_int_encode
 * Entry:    00089a4e
 * Prototype: bool __stdcall zcbor_int_encode(zcbor_state_t * state, void * input_int, size_t int_size)
 */


/* exclude_from_export_ai */

bool zcbor_int_encode(zcbor_state_t *state,void *input_int,size_t int_size)

{
  bool bVar1;
  zcbor_major_type_t major_type;
  int err;
  zcbor_state_t **ppzVar2;
  byte *pbVar3;
  zcbor_state_t *pzStack_18;
  void *pvStack_14;
  
  pzStack_18 = state;
  pvStack_14 = input_int;
  if (int_size < 9) {
    pbVar3 = (byte *)((int)input_int + int_size);
    ppzVar2 = &pzStack_18;
    if ((char)pbVar3[-1] < '\0') {
      for (; input_int != pbVar3; input_int = (void *)((int)input_int + 1)) {
        *(byte *)ppzVar2 = ~*(byte *)input_int;
        ppzVar2 = (zcbor_state_t **)((int)ppzVar2 + 1);
      }
      major_type = ZCBOR_MAJOR_TYPE_NINT;
      input_int = &pzStack_18;
    }
    else {
      major_type = ZCBOR_MAJOR_TYPE_PINT;
    }
    if (int_size != 0) {
      bVar1 = value_encode(state,major_type,input_int,int_size);
      return bVar1;
    }
    err = 0xe;
  }
  else {
    err = 5;
  }
  zcbor_error(state,err);
  return false;
}


