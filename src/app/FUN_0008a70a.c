/*
 * Function: $_?_FUN_0008a70a
 * Entry:    0008a70a
 * Prototype: undefined __stdcall $_?_FUN_0008a70a(int * param_1, int param_2, char * param_3, int param_4)
 */


void ____FUN_0008a70a(int *param_1,int param_2,char *param_3,int param_4)

{
  int iVar1;
  
  if ((int)((uint)*(ushort *)(param_2 + 0xc) << 0x17) < 0) {
    __swbuf_r(param_1,(int)*(short *)(param_2 + 0xe),0);
  }
  *(ushort *)(param_2 + 0xc) = *(ushort *)(param_2 + 0xc) & 0xefff;
  DAT_2000d60c = 0;
  iVar1 = _write((int)*(short *)(param_2 + 0xe),param_3,param_4);
  if ((iVar1 == -1) && (DAT_2000d60c != 0)) {
    *param_1 = DAT_2000d60c;
  }
  return;
}


