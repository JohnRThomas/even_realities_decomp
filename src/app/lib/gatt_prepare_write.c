/*
 * Function: gatt_prepare_write
 * Entry:    00085bb2
 * Prototype: int __stdcall gatt_prepare_write(bt_conn * conn, bt_gatt_write_params * params)
 */


/* exclude_from_export_ai */

int gatt_prepare_write(bt_conn *conn,bt_gatt_write_params *params)

{
  bt_att *pbVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  pbVar1 = att_get(conn);
  uVar3 = 0;
  if (pbVar1 != (bt_att *)0x0) {
    piVar2 = *(int **)((int)&pbVar1[1].prep_queue + 2);
    uVar3 = 0;
    if (piVar2 != (int *)0x0) {
      iVar5 = *piVar2;
      if (iVar5 != 0) {
        iVar5 = iVar5 + -400;
      }
      uVar3 = (uint)*(ushort *)((int)piVar2 + -0x172);
      if ((uint)*(ushort *)((int)piVar2 + -0x162) <= (uint)*(ushort *)((int)piVar2 + -0x172)) {
        uVar3 = (uint)*(ushort *)((int)piVar2 + -0x162);
      }
      if (iVar5 != 0) {
        while( true ) {
          uVar4 = (uint)*(ushort *)(iVar5 + 0x1e);
          uVar6 = (uint)*(ushort *)(iVar5 + 0x2e);
          if (*(int *)(iVar5 + 400) == 0) break;
          if (uVar4 <= uVar6) {
            uVar6 = uVar4;
          }
          if (uVar3 < uVar6) {
            uVar3 = uVar6;
          }
          iVar5 = *(int *)(iVar5 + 400) + -400;
        }
        if (uVar6 <= uVar4) {
          uVar4 = uVar6;
        }
        if (uVar3 < uVar4) {
          uVar3 = uVar4;
        }
      }
    }
  }
  return uVar3;
}


