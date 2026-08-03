/*
 * Function: bt_ancs_get_notif_attrs
 * Entry:    00082e52
 * Prototype: int __stdcall bt_ancs_get_notif_attrs(bt_ancs_client * ancs_c, uint32_t uid, bt_ancs_write_cb func)
 */


/* exclude_from_export_ai */

int bt_ancs_get_notif_attrs(bt_ancs_client *ancs_c,uint32_t uid,bt_ancs_write_cb func)

{
  undefined2 uVar1;
  bt_ancs_client bVar2;
  int iVar3;
  bt_ancs_client *pbVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  
  if ((*(byte *)(uid + 4) < 3) && (*(byte *)(uid + 6) < 0xc)) {
    ancs_c[0x1108] = (bt_ancs_client)0x0;
    uVar6 = *(undefined4 *)uid;
    bVar2 = (bt_ancs_client)atomic_test_and_set_bit((atomic_t *)(ancs_c + 4),2);
    if (!(bool)bVar2) {
      *(undefined4 *)(ancs_c + 0x10f8) = 0;
      ancs_c[0x29] = SUB41(uVar6,0);
      ancs_c[0x2a] = SUB41((uint)uVar6 >> 8,0);
      ancs_c[0x2b] = SUB41((uint)uVar6 >> 0x10,0);
      ancs_c[0x28] = bVar2;
      ancs_c[0x2c] = SUB41((uint)uVar6 >> 0x18,0);
      iVar3 = 5;
      pbVar4 = ancs_c + 0x1068;
      iVar5 = 0;
LAB_00082eaa:
      do {
        iVar8 = iVar5 + 1;
        iVar7 = iVar3;
        if (*pbVar4 != (bt_ancs_client)0x0) {
          ancs_c[iVar3 + 0x28] = SUB41(iVar5,0);
          iVar7 = iVar3 + 1;
          if (iVar5 - 1U < 3) {
            uVar1 = *(undefined2 *)(pbVar4 + 8);
            ancs_c[iVar3 + 0x29] = SUB21(uVar1,0);
            ancs_c[iVar3 + 0x2a] = SUB21((ushort)uVar1 >> 8,0);
            *(int *)(ancs_c + 0x10f8) = *(int *)(ancs_c + 0x10f8) + 1;
            iVar3 = iVar3 + 3;
            pbVar4 = pbVar4 + 0x10;
            iVar5 = iVar8;
            goto LAB_00082eaa;
          }
          *(int *)(ancs_c + 0x10f8) = *(int *)(ancs_c + 0x10f8) + 1;
        }
        iVar3 = iVar7;
        pbVar4 = pbVar4 + 0x10;
        iVar5 = iVar8;
        if (iVar8 == 8) {
          *(undefined4 *)(ancs_c + 0x1104) = *(undefined4 *)(ancs_c + 0x10f8);
          iVar3 = bt_ancs_cp_write(ancs_c,(uint16_t)iVar7,func);
          return iVar3;
        }
      } while( true );
    }
    iVar3 = -0x10;
  }
  else {
    iVar3 = -0x16;
  }
  return iVar3;
}


