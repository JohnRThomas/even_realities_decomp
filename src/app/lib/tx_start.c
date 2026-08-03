/*
 * Function: tx_start
 * Entry:    0008811c
 * Prototype: int __stdcall tx_start(bool indicate)
 */


/* exclude_from_export_ai */

int tx_start(bool indicate)

{
  device *dev;
  int iVar1;
  undefined4 in_r1;
  undefined4 in_r2;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uStack_1c;
  
  dev = (device *)(uint)indicate;
  piVar4 = (int *)dev->config;
  iVar3 = *piVar4;
  uStack_1c = in_r1;
  iVar1 = pm_device_state_get(dev,(pm_device_state *)((int)&uStack_1c + 3));
  if (uStack_1c._3_1_ == '\0') {
    *(undefined4 *)(iVar3 + 0x544) = in_r1;
    *(undefined4 *)(iVar3 + 0x548) = in_r2;
    *(undefined4 *)(iVar3 + 0x120) = 0;
    *(undefined4 *)(iVar3 + 0x158) = 0;
    if (piVar4[1] << 0x1b < 0) {
      iVar2 = *(int *)(dev->data + 0xc);
      if (iVar2 != 0) {
        *(uint *)(iVar2 + 0xc0) = *(uint *)(iVar2 + 0xc0) | 1;
      }
      *(undefined4 *)(*(int *)dev->config + 0x500) = 8;
      *(undefined4 *)(iVar3 + 0x304) = 0x400000;
    }
    *(undefined4 *)(iVar3 + 8) = 1;
  }
  return iVar1;
}


