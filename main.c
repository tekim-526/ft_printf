#include "ft_printf.h"

int main()
{
	int d = -123;
	printf("-->|%-4.d|<--\n", d);
	ft_printf("ft-->|%-4.d|<--\n", d);

	return (0);
}
