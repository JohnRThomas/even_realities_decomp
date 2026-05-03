/*
 * Function: $_?_z_impl_z_log_msg
 * Entry:    00084122
 * Prototype: undefined __stdcall $_?_z_impl_z_log_msg(void * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, uint param_5, uint8_t * param_6, void * param_7)
 */


void ____z_impl_z_log_msg
               (void *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,uint param_5,
               uint8_t *param_6,void *param_7)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)param_5;
  param_5 = (int)((uVar1 << 0x20) >> 0x20);
  z_impl_z_log_msg_static_create
            (param_1,(log_msg_desc)
                     CONCAT88(CONCAT44(param_5,(int)(uVar1 << 0x20)),CONCAT44(param_3,param_2)),
             param_6,param_7);
  return;
}


