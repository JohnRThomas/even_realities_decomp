/*
 * Function: lc3_tns_get_nbits
 * Entry:    00073c80
 * Prototype: int __stdcall lc3_tns_get_nbits(lc3_tns_data_t * data)
 */


/* exclude_from_export_ai */

int lc3_tns_get_nbits(lc3_tns_data_t *data)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (0 < *(int *)data->opaque) {
    iVar1 = *(int *)data[2].opaque;
    if (iVar1 < 1) {
      iVar1 = 1;
    }
    else {
      iVar2 = (uint)*(ushort *)(&DAT_000938e0 + (*(int *)data[4].opaque + 8) * 2) +
              *(ushort *)(&DAT_00093c10 + (iVar1 + -1 + (uint)data[1].opaque[0] * 8) * 2) + 0x800;
      if ((((iVar1 != 1) &&
           (iVar2 = iVar2 + (uint)*(ushort *)(&DAT_000938e0 + (*(int *)data[5].opaque + 0x19) * 2),
           iVar1 != 2)) &&
          (iVar2 = iVar2 + (uint)*(ushort *)(&DAT_000938e0 + (*(int *)data[6].opaque + 0x2a) * 2),
          iVar1 != 3)) &&
         (((iVar2 = iVar2 + (uint)*(ushort *)(&DAT_000938e0 + (*(int *)data[7].opaque + 0x3b) * 2),
           iVar1 != 4 &&
           (iVar2 = iVar2 + (uint)*(ushort *)(&DAT_000938e0 + (*(int *)data[8].opaque + 0x4c) * 2),
           iVar1 != 5)) &&
          ((iVar2 = iVar2 + (uint)*(ushort *)(&DAT_000938e0 + (*(int *)data[9].opaque + 0x5d) * 2),
           iVar1 != 6 &&
           (iVar2 = iVar2 + (uint)*(ushort *)(&DAT_000938e0 + (*(int *)data[10].opaque + 0x6e) * 2),
           iVar1 != 7)))))) {
        iVar2 = iVar2 + (uint)*(ushort *)(&DAT_000938e0 + (*(int *)data[0xb].opaque + 0x7f) * 2);
      }
      iVar1 = iVar2 + 0x7ff >> 0xb;
    }
    if (*(int *)data->opaque != 1) {
      iVar2 = *(int *)data[3].opaque;
      if (iVar2 < 1) {
        iVar2 = 1;
      }
      else {
        iVar3 = (uint)*(ushort *)(&DAT_000938e0 + (*(int *)data[0xc].opaque + 8) * 2) +
                *(ushort *)(&DAT_00093c10 + (iVar2 + -1 + (uint)data[1].opaque[0] * 8) * 2) + 0x800;
        if ((((iVar2 != 1) &&
             (iVar3 = iVar3 + (uint)*(ushort *)
                                     (&DAT_000938e0 + (*(int *)data[0xd].opaque + 0x19) * 2),
             iVar2 != 2)) &&
            ((iVar3 = iVar3 + (uint)*(ushort *)
                                     (&DAT_000938e0 + (*(int *)data[0xe].opaque + 0x2a) * 2),
             iVar2 != 3 &&
             (((iVar3 = iVar3 + (uint)*(ushort *)
                                       (&DAT_000938e0 + (*(int *)data[0xf].opaque + 0x3b) * 2),
               iVar2 != 4 &&
               (iVar3 = iVar3 + (uint)*(ushort *)
                                       (&DAT_000938e0 + (*(int *)data[0x10].opaque + 0x4c) * 2),
               iVar2 != 5)) &&
              (iVar3 = iVar3 + (uint)*(ushort *)
                                      (&DAT_000938e0 + (*(int *)data[0x11].opaque + 0x5d) * 2),
              iVar2 != 6)))))) &&
           (iVar3 = iVar3 + (uint)*(ushort *)
                                   (&DAT_000938e0 + (*(int *)data[0x12].opaque + 0x6e) * 2),
           iVar2 != 7)) {
          iVar3 = iVar3 + (uint)*(ushort *)(&DAT_000938e0 + (*(int *)data[0x13].opaque + 0x7f) * 2);
        }
        iVar2 = iVar3 + 0x7ff >> 0xb;
      }
      iVar1 = iVar1 + iVar2;
    }
    return iVar1;
  }
  return 0;
}


