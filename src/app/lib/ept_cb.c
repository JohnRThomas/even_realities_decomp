/*
 * Function: ept_cb
 * Entry:    0008245c
 * Prototype: int __stdcall ept_cb(rpmsg_endpoint * ep, void * data, size_t len, uint32_t src, void * priv)
 */


/* exclude_from_export_ai */

int ept_cb(rpmsg_endpoint *ep,void *data,size_t len,uint32_t src,void *priv)

{
  code *pcVar1;
  
  if (len == 0) {
    if (*(char *)((int)priv + 100) == '\0') {
      *(undefined1 *)((int)priv + 100) = 1;
      bound_cb(priv);
    }
  }
  else {
    pcVar1 = *(code **)(*(int *)((int)priv + 0x68) + 4);
    if (pcVar1 != (code *)0x0) {
      (*pcVar1)(data,len,*(undefined4 *)((int)priv + 0x6c));
    }
  }
  return 0;
}


