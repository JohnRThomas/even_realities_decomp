/*
 * Function: FUN_01035ff0
 * Entry:    01035ff0
 * Prototype: int __stdcall FUN_01035ff0(undefined1 * param_1, int param_2, undefined4 param_3, int param_4)
 */


int FUN_01035ff0(undefined1 *param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  char *local_28;
  char *local_24;
  undefined1 *local_20;
  undefined4 local_1c;
  
  if (((param_1 == (undefined1 *)0x0) || (param_2 == 0)) || (param_4 == 0)) {
    iVar3 = -0x7d3;
  }
  else {
    FUN_0103bdee(param_1,0,0x94);
    FUN_0103b9e4((int)(param_1 + 0x58),1,1);
    *(int *)(param_1 + 0xa0) = param_2;
    *(undefined4 *)(param_1 + 0x70) = param_3;
    *(undefined1 **)(param_2 + 0x24) = param_1;
    *(undefined4 *)(param_1 + 0x78) = 0x1035f2d;
    *(undefined1 **)(param_1 + 0x7c) = &LAB_0103b672_1;
    *(undefined4 *)(param_1 + 0x80) = 0x103b76d;
    *(undefined4 *)(param_1 + 0x84) = 0x103b7b3;
    *(undefined4 *)(param_1 + 0x88) = 0x1035d7d;
    *(undefined4 *)(param_1 + 0x8c) = 0x103b693;
    iVar3 = *(int *)(*(int *)(param_1 + 0xa0) + 0x18);
    if (iVar3 == 1) {
      do {
        while( true ) {
          iVar2 = (**(code **)(*(int *)(*(int *)(param_1 + 0xa0) + 0x20) + 8))();
          if (-1 < iVar2 << 0x19) break;
          (**(code **)(*(int *)(*(int *)(param_1 + 0xa0) + 0x20) + 0xc))(*(int *)(param_1 + 0xa0),0)
          ;
        }
      } while (-1 < iVar2 << 0x1d);
    }
    uVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 0xa0) + 0x20) + 0x10))();
    *(undefined4 *)(param_2 + 0x10) = uVar1;
    *(undefined4 *)(param_2 + 0x14) = 0;
    param_1[0x90] = (byte)uVar1 & 1;
    if (iVar3 == 1) {
      local_28 = "tx_vq";
      local_24 = "rx_vq";
      local_20 = &LAB_0103b680_1;
      local_1c = 0x1035e2d;
      *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(*(int *)(param_2 + 0x2c) + 0x18);
      *(undefined4 *)(param_1 + 0xa8) = **(undefined4 **)(param_2 + 0x2c);
    }
    *(undefined1 **)(param_1 + 0xb4) = param_1 + 0xb4;
    *(undefined1 **)(param_1 + 0xb8) = param_1 + 0xb4;
    *(int *)(param_1 + 0xac) = param_4;
    iVar3 = FUN_01035afc(*(int *)(param_1 + 0xa0),0,2,(int)&local_28,(int)&local_20);
    if (iVar3 == 0) {
      FUN_0103b458(*(int **)(param_1 + 0xa8));
      *(int *)(**(int **)(param_2 + 0x2c) + 0x28) = param_4;
      *(int *)(*(int *)(*(int *)(param_2 + 0x2c) + 0x18) + 0x28) = param_4;
      *(undefined1 **)param_1 = param_1;
      *(undefined1 **)(param_1 + 4) = param_1;
      if (param_1[0x90] != '\0') {
        FUN_01035c3c((int)param_1,param_1 + 8,"NS",0x35,0x35,0x103b6d5,0);
      }
    }
  }
  return iVar3;
}


