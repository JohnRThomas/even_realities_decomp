/*
 * Function: FUN_0101a1f4
 * Entry:    0101a1f4
 * Prototype: uint __stdcall FUN_0101a1f4(int param_1, int param_2, int param_3, uint param_4, byte param_5, char param_6)
 */


uint FUN_0101a1f4(int param_1,int param_2,int param_3,uint param_4,byte param_5,char param_6)

{
  ushort *puVar1;
  int iVar2;
  ushort uStack_e;
  int local_c;
  
  if (param_6 != '\0') {
    if (param_6 != '\x01') {
      if (param_6 != '\x02') {
        param_4 = param_4 | 1;
      }
      return param_4;
    }
    if (param_3 == 0) {
      if (param_4 != 0) {
        puVar1 = (ushort *)FUN_0100ada0();
        FUN_0102794a(puVar1,&local_c,&uStack_e);
        iVar2 = FUN_010278d2(local_c);
        return (uint)(*(char *)(iVar2 + 0x25) != -1);
      }
      puVar1 = (ushort *)FUN_0100ada0();
      FUN_0102794a(puVar1,&local_c,&uStack_e);
      iVar2 = FUN_010278d2(local_c);
      return (uint)(*(char *)(iVar2 + 0x13) != -1);
    }
    if (param_3 != 1) {
      return (uint)(param_3 != 2);
    }
    return (uint)(*(char *)(param_1 + 0xc) == '\x02');
  }
  if (param_3 != 2) {
    if (param_3 == 1) {
      if (param_4 != 0) {
        return param_4;
      }
      return (uint)(param_5 != 2);
    }
    if (param_3 == 0) {
      if ((param_5 & 0xc) == 0) {
        return param_5 & 0xc;
      }
      return ((uint)*(byte *)(param_2 + 1) << 0x1b) >> 0x1f;
    }
  }
  return 1;
}


