/*
 * Function: twim_configure
 * Entry:    0006a868
 * Prototype: void __stdcall twim_configure(nrfx_twim_t * p_instance, nrfx_twim_config_t * p_config)
 */


/* exclude_from_export */

void twim_configure(nrfx_twim_t *p_instance,nrfx_twim_config_t *p_config)

{
  undefined4 uVar1;
  undefined4 uVar2;
  nrfx_twim_t nVar3;
  
  uVar2 = *(undefined4 *)p_config[2].opaque;
  nVar3 = *p_instance;
  if (p_config[3].opaque[3] == 0) {
    uVar1 = *(undefined4 *)p_config[1].opaque;
    *(undefined4 *)(nVar3 + 0x508) = *(undefined4 *)p_config->opaque;
    *(undefined4 *)(nVar3 + 0x50c) = uVar1;
  }
  *(undefined4 *)(nVar3 + 0x524) = uVar2;
  if (*(int *)(&DAT_2000bdb4 + (uint)(byte)p_instance[1] * 0x28) != 0) {
    arch_irq_enable((int)(*p_instance << 0xc) >> 0x18);
    return;
  }
  return;
}


