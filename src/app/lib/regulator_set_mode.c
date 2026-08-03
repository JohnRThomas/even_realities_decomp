/*
 * Function: regulator_set_mode
 * Entry:    00087840
 * Prototype: int __stdcall regulator_set_mode(device * dev, regulator_mode_t mode)
 */


/* exclude_from_export */

int regulator_set_mode(device *dev,regulator_mode_t mode)

{
  int iVar1;
  regulator_mode_t *prVar2;
  regulator_mode_t *prVar3;
  uint uVar5;
  regulator_mode_t *prVar4;
  
  if (*(code **)(dev->api + 0x20) == (code *)0x0) {
    iVar1 = -0x58;
  }
  else {
    uVar5 = (uint)(byte)dev->config[0x18];
    if (uVar5 == 0) {
LAB_00087852:
                    /* WARNING: Could not recover jumptable at 0x00087856. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (**(code **)(dev->api + 0x20))(dev,mode);
      return iVar1;
    }
    prVar2 = *(regulator_mode_t **)(dev->config + 0x14);
    prVar4 = prVar2;
    do {
      prVar3 = prVar4 + 1;
      if (*prVar4 == mode) goto LAB_00087852;
      prVar4 = prVar3;
    } while (prVar3 != prVar2 + uVar5);
    iVar1 = -0x86;
  }
  return iVar1;
}


