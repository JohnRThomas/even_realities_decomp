/*
 * Function: process_pt_protocol
 * Entry:    00033a30
 * Prototype: undefined4 __stdcall process_pt_protocol(int param_1, char * param_2, int param_3, int * param_4, byte * param_5, undefined4 param_6)
 */


undefined4
process_pt_protocol(int param_1,char *param_2,int param_3,int *param_4,byte *param_5,
                   undefined4 param_6)

{
  char cVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  char *pcVar5;
  undefined1 *puVar6;
  undefined4 local_24;
  
  if ((((param_2 == (char *)0x0) || (param_3 == 0)) || (param_4 == (int *)0x0)) ||
     ((param_5 == (byte *)0x0 || (param_1 == 2)))) {
    printk("process_pt_protocol para is error\n");
    return 0xffffffff;
  }
  iVar3 = 0;
  cVar1 = *param_2;
  pcVar5 = "\"";
  while ((*pcVar5 != cVar1 || (*(code **)(pcVar5 + 4) == (code *)0x0))) {
    iVar3 = iVar3 + 1;
    pcVar5 = pcVar5 + 8;
    if (iVar3 == 0x30) {
      pcVar5 = (char *)*param_4;
      pcVar5[1] = '\x01';
      pcVar5[3] = '\x01';
      *pcVar5 = cVar1;
      pcVar5[2] = '\x03';
      pcVar5[4] = '\x02';
      *param_5 = 5;
LAB_00033a74:
      if (param_1 != 0) {
        if (param_1 != 1) {
          return 0;
        }
        local_24 = CONCAT13(*param_5,0xffa55a);
        puVar4 = (undefined4 *)*param_4;
        puVar6 = &DAT_2001abc4;
        for (iVar3 = 0; iVar3 < (int)(uint)*param_5; iVar3 = iVar3 + 1) {
          *puVar6 = *(undefined1 *)((int)puVar4 + iVar3);
          puVar6 = puVar6 + 1;
        }
        puVar6 = (undefined1 *)((int)puVar4 + 3);
        *puVar4 = local_24;
        puVar2 = &DAT_2001abc4;
        while ((int)(puVar6 + (-3 - (int)puVar4)) < (int)(uint)*param_5) {
          puVar6 = puVar6 + 1;
          *puVar6 = *puVar2;
          puVar2 = puVar2 + 1;
        }
        *param_5 = *param_5 + 4;
      }
      iVar3 = FUN_00080674(param_4,param_5);
      if (iVar3 == 0) {
        return 0;
      }
      return 0xfffffffc;
    }
  }
  (**(code **)(pcVar5 + 4))(param_2,param_3,param_4,param_5,param_6);
  goto LAB_00033a74;
}


