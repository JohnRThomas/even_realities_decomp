/*
 * Function: settings_call_set_handler
 * Entry:    000518a4
 * Prototype: int __stdcall settings_call_set_handler(char * name, size_t len, settings_read_cb read_cb, void * read_cb_arg, settings_load_arg * load_arg)
 */


/* exclude_from_export */

int settings_call_set_handler
              (char *name,size_t len,settings_read_cb read_cb,void *read_cb_arg,
              settings_load_arg *load_arg)

{
  log_msg_desc desc;
  settings_handler_static *psVar1;
  int iVar2;
  dword in_stack_ffffffa8;
  uint8_t *in_stack_ffffffac;
  void *in_stack_ffffffb0;
  undefined1 *local_40;
  char *local_3c;
  char *pcStack_38;
  int local_34;
  settings_load_arg local_30;
  char *local_24;
  
  local_24 = name;
  if (load_arg != (settings_load_arg *)0x0) {
    if (((char *)*load_arg != (char *)0x0) &&
       (iVar2 = settings_name_steq(name,(char *)*load_arg,&local_24), iVar2 == 0)) {
      return 0;
    }
    if ((code *)load_arg[1] != (code *)0x0) {
      local_30 = load_arg[2];
      iVar2 = (*(code *)load_arg[1])(local_24,len,read_cb,read_cb_arg);
      return iVar2;
    }
  }
  psVar1 = settings_parse_and_lookup(name,&local_24);
  if ((psVar1 != (settings_handler_static *)0x0) &&
     (local_34 = (*(code *)psVar1[2])(local_24,len,read_cb,read_cb_arg), local_34 != 0)) {
    local_3c = "set-value failure. key: %s error(%d)";
    local_30 = CONCAT22(local_30._2_2_,0x200);
    local_40 = &DAT_01000004;
    desc.level = (dword)&local_40;
    desc.domain = 0x2440;
    desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
    desc.data_len = in_stack_ffffffa8;
    pcStack_38 = name;
    z_impl_z_log_msg_static_create
              (&PTR_s_settings_000a2953_0x12_0008ba28,desc,in_stack_ffffffac,in_stack_ffffffb0);
  }
  return 0;
}


