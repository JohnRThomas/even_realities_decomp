/*
 * Function: process
 * Entry:    000511e0
 * Prototype: void __stdcall process(void)
 */


/* exclude_from_export_ai */

void process(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = log_format_func_t_get(DAT_2000aadc);
                    /* WARNING: Could not recover jumptable at 0x000511f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(&PTR_char_out_1_0008e898);
  return;
}


