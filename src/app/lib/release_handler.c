/*
 * Function: release_handler
 * Entry:    000687ac
 * Prototype: lv_res_t __stdcall release_handler(lv_obj_t * obj)
 */


/* exclude_from_export */

lv_res_t release_handler(lv_obj_t *obj)

{
  ushort uVar1;
  byte bVar2;
  nrfx_err_t nVar3;
  undefined1 *puVar4;
  uint uVar5;
  uint uVar6;
  ushort *puVar7;
  
  bVar2 = get_pin_idx((nrfx_gpiote_pin_t)obj);
  puVar4 = (undefined1 *)(bVar2 + 8);
  uVar1 = *(ushort *)((int)&DAT_20002be0 + (int)puVar4 * 2);
  uVar6 = (uint)uVar1;
  if ((int)(uVar6 << 0x17) < 0) {
    uVar5 = (uVar6 & 0x1fff) >> 9;
    *(ushort *)((int)&DAT_20002be0 + (int)puVar4 * 2) = uVar1 & 0xe0ff;
    puVar4 = (undefined1 *)0x0;
    puVar7 = (ushort *)((int)&DAT_20002bec + 2);
    do {
      puVar7 = puVar7 + 1;
      if (((*puVar7 & 0x100) != 0) && (uVar5 == (*puVar7 & 0x1fff) >> 9)) goto LAB_000687fa;
      puVar4 = puVar4 + 1;
    } while (puVar4 != (undefined1 *)0x30);
    (&DAT_20002be0)[uVar5 * 2] = 0;
    nVar3 = nrfx_flag32_free(&DAT_20002c54,(byte)((uVar6 << 0x13) >> 0x1c));
    puVar4 = (undefined1 *)(uint)nVar3;
    if (puVar4 != &DAT_0bad0000) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","err == NRFX_SUCCESS",
              "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_gpiote.c",351);
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
  }
LAB_000687fa:
  return (lv_res_t)puVar4;
}


