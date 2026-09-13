/*
 * Retained block shared with the bootloader and the network core
 * (struct ncs_mem, src/main.h), fixed at the top 1 KiB of sram0_shared.
 */
.ncs_mem 0x2007fc00 (NOLOAD) :
{
	KEEP(*(.ncs_mem))
}
