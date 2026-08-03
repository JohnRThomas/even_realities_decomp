/*
 * Function: nrfx_twim_disable
 * Entry:    0006ab78
 * Prototype: void __stdcall nrfx_twim_disable(nrfx_twim_t * p_instance)
 */


/* exclude_from_export */

void nrfx_twim_disable(nrfx_twim_t *p_instance)

{
  int iVar1;
  nrfx_twim_t nVar2;
  
  iVar1 = (uint)(byte)p_instance[1] * 0x28;
  if ((&DAT_2000bdd6)[iVar1] == '\0') {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","p_cb->state != NRFX_DRV_STATE_UNINITIALIZED",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_twim.c",374);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  *(undefined4 *)(&DAT_2000bdbc + iVar1) = 0;
  nVar2 = *p_instance;
  *(undefined4 *)(nVar2 + 0x308) = 0x19c0202;
  *(uint *)(nVar2 + 0x200) = *(uint *)(nVar2 + 0x200) & 0xffffe87f;
  *(undefined4 *)(nVar2 + 0x500) = 0;
  (&DAT_2000bdd8)[iVar1] = 0;
  (&DAT_2000bdd6)[iVar1] = 1;
  return;
}


