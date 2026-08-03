/*
 * Function: z_queue_node_peek
 * Entry:    00089c80
 * Prototype: void * __stdcall z_queue_node_peek(sys_sfnode_t * node, bool needs_free)
 */


/* exclude_from_export */

void * z_queue_node_peek(sys_sfnode_t *node,bool needs_free)

{
  sys_sfnode_t *psVar1;
  
  psVar1 = node;
  if (((node != (sys_sfnode_t *)0x0) && ((*node & 3) != 0)) &&
     (psVar1 = (sys_sfnode_t *)node[1], needs_free)) {
    k_free(node);
  }
  return psVar1;
}


