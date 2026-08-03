/*
 * Function: pm_device_action_run
 * Entry:    00051258
 * Prototype: int __stdcall pm_device_action_run(device * dev, pm_device_action action)
 */


/* WARNING: Removing unreachable block (ram,0x000512c4) */
/* exclude_from_export_ai */

int pm_device_action_run(device *dev,pm_device_action action)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  int extraout_r1;
  undefined4 extraout_r3;
  undefined *puVar4;
  
  puVar4 = dev->pm;
  if (puVar4 == (undefined *)0x0) {
    iVar3 = -0x58;
  }
  else {
    bVar2 = pm_device_state_is_locked(dev);
    if (bVar2) {
      iVar3 = -1;
    }
    else {
      cVar1 = (&DAT_000ef007)[extraout_r1];
      if (puVar4[8] == cVar1) {
        iVar3 = -0x78;
      }
      else if ("pm_device"[extraout_r1 + 10] == puVar4[8]) {
        iVar3 = (**(code **)(puVar4 + 0xc))(extraout_r3);
        if (iVar3 < 0) {
          if (action != 2) {
            if (action != 3) {
              return iVar3;
            }
            if (iVar3 != -0x86) {
              *(uint *)(puVar4 + 4) = *(uint *)(puVar4 + 4) | 2;
            }
          }
          puVar4[8] = cVar1;
        }
        else {
          puVar4[8] = cVar1;
          if (action == 2) {
            *(uint *)(puVar4 + 4) = *(uint *)(puVar4 + 4) & 0xfffffffd;
          }
          iVar3 = 0;
        }
      }
      else {
        iVar3 = -0x86;
      }
    }
  }
  return iVar3;
}


