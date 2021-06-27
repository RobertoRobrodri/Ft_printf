
#include "ft_printf.h"
#include <limits.h>

static int	ft_check_args(const char **str, va_list VaList, int n_bytes, t_flag *flag)
{
/*	if (**str == 's')
		return (ft_print_string(VaList, n_bytes));
	else if (**str == 'c')
		return (ft_print_char(VaList, n_bytes));*/
	if (**str == 'i' || **str == 'd')
		return (ft_print_int(VaList, n_bytes, flag));
/*	else if (**str == 'x')
		return (ft_print_hex(VaList, n_bytes));
	else if (**str == 'p')
		return (ft_print_address(VaList, n_bytes));
	else if (**str == 'X')
		return (ft_print_unsigned_hexa(VaList, n_bytes));*/
	else if (**str == '%')
		return (ft_print_percent(n_bytes));
	return (0);
}

static const char	*ft_is_flag(const char *str, t_flag *flag, va_list VaList)
{
	while (!ft_isalpha(*str))
		str = ft_check_flags(str, flag, VaList);
	return (str);
}

int	ft_printf(const char *str, ...)
{
	int			n_bytes;
	va_list		VaList;
	t_flag		flag;

	n_bytes = 0;
	va_start(VaList, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_init_flags(&flag);
			str = ft_is_flag(str, &flag, VaList);
			n_bytes = ft_check_args(&str, VaList, n_bytes, &flag);
		}
		else
		{
			ft_putchar(*str);
			n_bytes++;
		}
		str++;
	}
	va_end(VaList);
	return(n_bytes);
}

int main()
{
	int i;
	int d;
/*	i = ft_printf(" %5d ", 22220);
	printf("\n%i\n", i);
	d = printf(" %5d ", 22220);				// CASO 1: WIDTH = LEN
	printf("\n%d\n", d);*/
/*	i = ft_printf(" %100d ", 22220);
    printf("\n%i\n", i);
    d = printf(" %100d ", 22220);			// CASO 2: WIDTH > LEN
    printf("\n%d\n", d);*/
/*	i = ft_printf(" %4d ", 11110);
    printf("\n%i\n", i);				// CASO 3: WIDTH < LEN
    d = printf(" %4d ", 11110);
    printf("\n%d\n", d);*/
/*	i = ft_printf(" %.3d ", 220);
	printf("\n%i\n", i);
	d = printf(" %.3d ", 220);			//	CASO 1: PREC = LEN
	printf("\n%d\n", d);*/
/*	i = ft_printf(" %.100d ", 10000);
    printf("\n%i\n", i);
    d = printf(" %.100d ", 10000);			// CASO 2: PREC > LEN
    printf("\n%d\n", d);*/
/*	i = ft_printf(" %.4d ", 11110);
    printf("\n%i\n", i);				// CASO 3: PREC < LEN
    d = printf(" %.4d ", 11110);
    printf("\n%d\n", d);*/
/*	i = ft_printf(" %8.8d ", 22220000);
	printf("\n%i\n", i);
	d = printf(" %8.8d ", 22220000);				// CASO 1: WIDTH = LEN && WIDTH = PREC
	printf("\n%d\n", d);*/
/*	i = ft_printf(" %100.100d ", 22);
    printf("\n%i\n", i);
    d = printf(" %100.100d ", 22);			// CASO 2: WIDTH > LEN && WIDTH = PREC
    printf("\n%d\n", d);*/
/*	i = ft_printf(" %6.6d ", 1111000);
    printf("\n%i\n", i);				// CASO 3: WIDTH < LEN && WIDTH = PREC
    d = printf(" %6.6d ", 1111000);
    printf("\n%d\n", d);*/
/*	i = ft_printf(" %8.7d ", 22220000);
	printf("\n%i\n", i);
	d = printf(" %8.7d ", 22220000);				// CASO 4: WIDTH = LEN && WIDTH > PREC
	printf("\n%d\n", d);*/
/*	i = ft_printf(" %100.10d ", 22);
    printf("\n%i\n", i);
    d = printf(" %100.10d ", 22);			// CASO 5: WIDTH > LEN && WIDTH > PREC
    printf("\n%d\n", d);*/
/*	i = ft_printf(" %6.3d ", 12345678);
    printf("\n%i\n", i);				// CASO 6: WIDTH < LEN && WIDTH > PREC
    d = printf(" %6.3d ", 12345678);
    printf("\n%d\n", d);*/
/*	i = ft_printf(" %8.20d ", 12345678);
	printf("\n%i\n", i);
	d = printf(" %8.20d ", 12345678);				// CASO 7: WIDTH = LEN && WIDTH < PREC
	printf("\n%d\n", d);*/
/*	i = ft_printf(" %6.20d ", 12345678);
    printf("\n%i\n", i);				// CASO 8: WIDTH < LEN && WIDTH < PREC
    d = printf(" %6.20d ", 12345678);
    printf("\n%d\n", d);*/
/*	i = ft_printf(" %10.6d ", 12345678);
    printf("\n%i\n", i);				// CASO 9: WIDTH > LEN && WIDTH < PREC
    d = printf(" %10.6d ", 12345678);
    printf("\n%d\n", d);*/
/*	i = ft_printf(" %8.8d ", 22222);
	printf("\n%i\n", i);
	d = printf(" %8.8d ", 22222);				// CASO 10: PREC > LEN && PREC = WIDTH
	printf("\n%d\n", d);*/
/*	i = ft_printf(" %2.2d ", 22222);
	printf("\n%i\n", i);
	d = printf(" %2.2d ", 22222);				// CASO 11: PREC < LEN && PREC = WIDTH
	printf("\n%d\n", d);*/
/*	i = ft_printf(" %9.10d ", 1234567890);
	printf("\n%i\n", i);
	d = printf(" %9.10d ", 1234567890);				// CASO 12: PREC = LEN && PREC > WIDTH
	printf("\n%d\n", d);*/
/*	i = ft_printf(" %7.8d ", 1234567890);
	printf("\n%i\n", i);
	d = printf(" %7.8d ", 1234567890);				// CASO 13: PREC < LEN && PREC > WIDTH
	printf("\n%d\n", d);*/
/*	i = ft_printf(" %9.30d ", 1234567890);
	printf("\n%i\n", i);
	d = printf(" %9.30d ", 1234567890);				// CASO 14: PREC > LEN && PREC > WIDTH
	printf("\n%d\n", d);*/
/*	i = ft_printf(" %*.*d ", 20, 10, 1234567890);
	printf("\n%i\n", i);
	d = printf(" %*.*d ",20, 10, 1234567890);				// CASO 15: PREC = LEN && PREC < WIDTH
	printf("\n%d\n", d);*/
/*	i = ft_printf(" %20.15d ", 1234567890);
	printf("\n%i\n", i);
	d = printf(" %20.15d ", 1234567890);				// CASO 16: PREC > LEN && PREC < WIDTH
	printf("\n%d\n", d);*/
/*	i = ft_printf(" %20.5d ", 1234567890);
	printf("\n%i\n", i);
	d = printf(" %20.5d ", 1234567890);				// CASO 17: PREC < LEN && PREC < WIDTH
	printf("\n%d\n", d);*/
/*	i = ft_printf(" %20.30d ", 1234567890);
	printf("\n%i\n", i);
	d = printf(" %20.30d ", 1234567890);				// CASO 18: PREC > LEN && PREC > WIDTH && WIDTH > LEN
	printf("\n%d\n", d);*/
}