/*
 * Function: bt_ancs_client_init
 * Entry:    00082e3a
 * Prototype: int __stdcall bt_ancs_client_init(bt_ancs_client * ancs_c)
 */


/* exclude_from_export_ai */

int bt_ancs_client_init(bt_ancs_client *ancs_c)

{
  int iVar1;
  
  if (ancs_c == (bt_ancs_client *)0x0) {
    iVar1 = -0x16;
  }
  else {
    memset(ancs_c,0,0x122c);
    iVar1 = 0;
  }
  return iVar1;
}


