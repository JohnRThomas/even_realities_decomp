/*
 * Function: regulator_common_init
 * Entry:    0008787c
 * Prototype: int __stdcall regulator_common_init(device * dev, bool is_enabled)
 */


/* exclude_from_export */

int regulator_common_init(device *dev,bool is_enabled)

{
  int iVar1;
  uint uVar2;
  int32_t iVar3;
  undefined *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  uint local_1c;
  
  uVar2 = (uint)is_enabled;
  piVar6 = (int *)dev->config;
  puVar5 = (undefined4 *)dev->api;
  puVar4 = dev->data;
  local_1c = uVar2;
  if ((*(regulator_mode_t *)((int)piVar6 + 0x19) != 0xff) &&
     (iVar1 = regulator_set_mode(dev,*(regulator_mode_t *)((int)piVar6 + 0x19)), iVar1 < 0)) {
    return iVar1;
  }
  iVar3 = piVar6[2];
  if ((iVar3 != -0x80000000) && (iVar1 = regulator_set_voltage(dev,iVar3,iVar3), iVar1 < 0)) {
    return iVar1;
  }
  if ((*piVar6 != -0x80000000) || (piVar6[1] != 0x7fffffff)) {
    if (*(code **)(dev->api + 0x14) == (code *)0x0) {
      return -0x58;
    }
    iVar1 = (**(code **)(dev->api + 0x14))(dev,&local_1c);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar3 = *piVar6;
    if ((((int)local_1c < iVar3) || (iVar3 = piVar6[1], iVar3 < (int)local_1c)) &&
       (iVar1 = regulator_set_voltage(dev,iVar3,iVar3), iVar1 < 0)) {
      return iVar1;
    }
  }
  if (uVar2 == 0) {
    if ((*(byte *)((int)piVar6 + 0x1a) & 3) == 0) {
      return 0;
    }
    iVar1 = (*(code *)*puVar5)(dev);
    if (iVar1 < 0) {
      return iVar1;
    }
  }
  *(int *)(puVar4 + 0x14) = *(int *)(puVar4 + 0x14) + 1;
  return 0;
}


