#include "ft_printf.h"

int main()
{
	//printf("%d\n", printf("%.5d\n", -123));

	printf("%d\n", ft_printf("%.5d\n", -123));
	return (0);
}
