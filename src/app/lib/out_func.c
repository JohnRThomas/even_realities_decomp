/*
 * Function: out_func
 * Entry:    00050d4c
 * Prototype: int __stdcall out_func(int c, void * ctx)
 */


/* exclude_from_export */

int out_func(int c,void *ctx)

{
  int iVar1;
  
  if (**(int **)((int)ctx + 4) == *(int *)((int)ctx + 0xc)) {
    log_output_flush(ctx);
  }
  iVar1 = **(int **)((int)ctx + 4);
  **(int **)((int)ctx + 4) = iVar1 + 1;
  *(char *)(*(int *)((int)ctx + 8) + iVar1) = (char)c;
  if (**(uint **)((int)ctx + 4) <= *(uint *)((int)ctx + 0xc)) {
    return 0;
  }
  _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","out_ctx->control_block->offset <= out_ctx->size",
          "WEST_TOPDIR/zephyr/subsys/logging/log_output.c",122);
                    /* WARNING: Subroutine does not return */
  k_panic();
}


