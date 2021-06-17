#include "ft_printf.h"

int main()
{
	char *p;
	char *c = "tekim";
	int n = 10;

	ft_printf("========without_prec_width========\n\n");
	ft_printf("c===%c\n", 'a');
	printf("pc===%c\n", 'a');
	ft_printf("s===%s\n", "tekim");
	printf("ps===%s\n", "tekim");
	ft_printf("d===%d\n", 42);
	printf("pd===%d\n", 42);
	ft_printf("u===%u\n", 42);
	printf("pu===%u\n", 42);
	ft_printf("p===%p\n", p);
	printf("pp===%p\n", p);
	ft_printf("x===%x\n", 42);
	printf("px===%x\n", 42);
	ft_printf("X===%X\n", 42);
	printf("pX===%X\n", 42);
	ft_printf("%%===%%\n");
	printf("p%%===%%\n");
	/*ft_printf("\nft_printf========문자_with_prec_and_width========\n\n");
	ft_printf("%*c\n", n, 'a');
	ft_printf("%-*c\n", n, 'a');
	ft_printf("%*.c\n", n, 'a');
	ft_printf("%-c\n",'a');
	ft_printf("%-.c\n",'a');
	ft_printf("%.c\n",'a');
	ft_printf("%10.4c\n",'a');   // .뒤에 숫자 warning
	ft_printf("%.4c\n",'a');     // .뒤에 숫자, warning
	ft_printf("%.c\n",'a');
	ft_printf("%0.0c\n", 'a');    // warning
	ft_printf("%0.c\n",'a');     // warning
	ft_printf("%0c\n", 'a');      // warning
	ft_printf("\nprintf========문자_with_prec_and_width========\n\n");
	printf("%*c\n", n, 'a');
	printf("%-*c\n", n, 'a');
	printf("%*.c\n", n, 'a');
	printf("%-c\n", 'a');
	printf("%-.c\n", 'a');
	printf("%.c\n", 'a');
	printf("%10.4c\n", 'a');   // .뒤에 숫자 warning
	printf("%.4c\n", 'a');     // .뒤에 숫자, warning
	printf("%.c\n", 'a');
	printf("%0.0c\n", 'a');    // warning
	printf("%0.c\n", 'a');     // warning
	printf("%0c\n", 'a');      // warning*/
	ft_printf("\nft_printf========문자열_with_prec_and_width========\n\n");
	ft_printf("%*s\n", n, c);
	ft_printf("%-*s\n", n, c);
	ft_printf("%*.s\n", n, c);
	ft_printf("%-s\n", c);
	ft_printf("%-.s\n", c);
	ft_printf("%.s\n", c);
	ft_printf("%10.4s\n", c);
	ft_printf("%.4s\n", c);
	ft_printf("%.1s\n", c);
	ft_printf("%.s\n", c);
	ft_printf("\nprintf========문자열_with_prec_and_width========\n\n");
	printf("%*s\n", n, c);
	printf("%-*s\n", n, c);
	printf("%*.s\n", n, c);
	printf("%-s\n", c);
	printf("%-.s\n", c);
	printf("%.s\n", c);
	printf("%10.4s\n", c);
	printf("%.4s\n", c);
	printf("%.1s\n", c);
	printf("%.s\n", c);
	ft_printf("\nft_printf========주소값_with_prec_and_width========\n\n");
	ft_printf("%*p\n", n, c);
    ft_printf("%-*p\n", n, c);
    ft_printf("%*.*p\n", n, n, c);	//warning
    ft_printf("%-p\n", c);
    ft_printf("%-.p\n", c);
    ft_printf("%.p\n", c);
    ft_printf("%10.4p\n", c);	//warning
    ft_printf("%.4p\n", c);	//warning
    ft_printf("%.1p\n", c);	//warning
    ft_printf("%.p\n", c);
	ft_printf("\nprintf========주소값_with_prec_and_width========\n\n");
	printf("%*p\n", n, c);
    printf("%-*p\n", n, c);
    printf("%*.*p\n", n, n, c);	//warning
    printf("%-p\n", c);
    printf("%-.p\n", c);
    printf("%.p\n", c);
    printf("%10.4p\n", c);	//warning
    printf("%.4p\n", c);	//warning
    printf("%.1p\n", c);	//warning
    printf("%.p\n", c);
	ft_printf("\nprintf========정수_with_prec_and_width========\n\n");
	printf("%*d\n", n, n);
    printf("%-*d\n", n, n);
    printf("%*.*d\n", n, n, n);	//warning
    printf("%-d\n", n);
    printf("%-.d\n", n);
    printf("%.d\n", n);
    printf("%10.4d\n", n);	//warning
    printf("%.4d\n", n);	//warning
    printf("%.1d\n", n);	//warning
    printf("%.d\n", n);
	ft_printf("\nft_printf========정수_with_prec_and_width========\n\n");
	ft_printf("%*d\n", n, n);
    ft_printf("%-*d\n", n, n);
    //ft_printf("%*.*d\n", n, n, n);	//warning
    ft_printf("%-d\n", n);
    ft_printf("%-.d\n", n);
    ft_printf("%.d\n", n);
    //ft_printf("%10.4d\n", n);	//warning
    //ft_printf("%.4d\n", n);	//warning 정수부분은 주석 처리 된 부분이 문제임
    ft_printf("%.1d\n", n);	//warning
    ft_printf("%.d\n", n);
	return (0);
}
