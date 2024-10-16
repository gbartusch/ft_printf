#include <stdint.h>
#include "ft_printf.h"

int print_address(void* ptr)
{
	int	count;
	write(1, "0x", 2);
	count = 2;
//convert the pointer to an integer type
	uintptr_t int_ptr = (uintptr_t)ptr;
	count += convert_to_hex(int_ptr);
return (count);
}