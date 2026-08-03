/*
 * Function: buffer_skip_whitespace
 * Entry:    00088688
 * Prototype: parse_buffer * __stdcall buffer_skip_whitespace(parse_buffer * buffer)
 */


/* exclude_from_export */

parse_buffer * buffer_skip_whitespace(parse_buffer *buffer)

{
  uint uVar1;
  uint uVar2;
  
  if (buffer != (parse_buffer *)0x0) {
    if (*(int *)buffer->opaque == 0) {
      buffer = (parse_buffer *)0x0;
    }
    else {
      uVar2 = *(uint *)buffer[1].opaque;
      if (*(uint *)buffer[2].opaque < uVar2) {
        while( true ) {
          uVar1 = *(uint *)buffer[2].opaque;
          if (uVar2 <= uVar1) break;
          if (0x20 < *(byte *)(*(int *)buffer->opaque + uVar1)) {
            return buffer;
          }
          *(uint *)buffer[2].opaque = uVar1 + 1;
        }
        if (uVar2 == uVar1) {
          *(uint *)buffer[2].opaque = uVar2 - 1;
        }
      }
    }
  }
  return buffer;
}


