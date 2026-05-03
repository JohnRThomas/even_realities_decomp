/*
 * Function: FUN_00086f30
 * Entry:    00086f30
 * Prototype: undefined __stdcall FUN_00086f30(int param_1)
 */


void FUN_00086f30(int param_1)

{
  adc_context *ctx;
  undefined *puVar1;
  
  ctx = (adc_context *)(param_1 + -8);
  puVar1 = ctx->sampling_requested;
  ctx->sampling_requested = puVar1 + 1;
  if (puVar1 != (undefined *)0x0) {
    *(undefined4 *)(param_1 + 0x68) = 0xfffffff0;
    return;
  }
  adc_context_start_sampling(ctx);
  return;
}


