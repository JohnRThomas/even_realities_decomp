/*
 * Function: att_op_get_type
 * Entry:    0005b564
 * Prototype: att_type_t __stdcall att_op_get_type(uint8_t op)
 */


/* exclude_from_export_ai */

att_type_t att_op_get_type(uint8_t op)

{
  att_type_t aVar1;
  uint uVar2;
  
  uVar2 = (uint)op;
  if (0x23 < uVar2) {
    if ((uVar2 & 0x7f) == 0x52) {
      return 0;
    }
switchD_0005b57e_caseD_1c:
    if ((op & 0x40) == 0) {
      aVar1 = 6;
    }
    else {
      aVar1 = 0;
    }
    return aVar1;
  }
  if (0x1a < uVar2) {
    switch(uVar2) {
    case 0x1b:
    case 0x23:
      return 3;
    default:
      goto switchD_0005b57e_caseD_1c;
    case 0x1d:
      return 5;
    case 0x1e:
      return 4;
    case 0x20:
      return 1;
    case 0x21:
      goto switchD_0005b57e_caseD_21;
    }
  }
  if (0x18 < uVar2 - 1) {
    return 6;
  }
  if ((1 << uVar2 & 0x28aaaaaU) == 0) {
    if ((1 << uVar2 & 0x1455554U) == 0) {
      aVar1 = 6;
    }
    else {
      aVar1 = 1;
    }
    return aVar1;
  }
switchD_0005b57e_caseD_21:
  return 2;
}


