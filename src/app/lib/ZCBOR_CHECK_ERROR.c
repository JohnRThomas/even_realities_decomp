/*
 * Function: ZCBOR_CHECK_ERROR
 * Entry:    00089552
 * Prototype: int __stdcall ZCBOR_CHECK_ERROR(int * state, int * input)
 */


/* exclude_from_export */

int ZCBOR_CHECK_ERROR(int *state,int *input)

{
  int iVar1;
  
  iVar1 = zcbor_assert_state(state,input);
  if (iVar1 != 0) {
    if (input == (int *)(uint)(*(byte *)*state >> 5)) {
      return iVar1;
    }
    zcbor_error((int)state,10);
  }
  return 0;
}


