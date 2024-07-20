ENTRY(_reset);

MEMORY
{
	FLASH(rx):ORIGIN = 0x08000000, LENGTH = 512K
	SRAM(rwx):ORIGIN = 0x20000000, LENGTH = 96K
}
_stack = ORIGIN(SRAM) + LENGTH(SRAM);

SECTIONS
{
	.ivt : { 
		KEEP(*(.ivt)) 
	}	> FLASH
	
	.text : {
		*(.text)
		. = ALIGN(4);
	} > FLASH
	
	.rodata : {
		*(.rodata)
		. = ALIGN(4);
	} > FLASH
	
	.data : {
		_sdata = .;
		*(.data)
		. = ALIGN(4);
		_edata = .;
	} > SRAM AT > FLASH
	
	_lmadata = LOADADDR(.data);
	
	.bss : {
		_sbss = .;
		*(.bss)
		*(COMMON)
		. = ALIGN(4);
		_ebss = .;
	} > SRAM
}
