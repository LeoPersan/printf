#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int ft_print_char(char c)
{
	write(1, &c, 1);
	return 1;
}

int ft_print_string(char *string)
{
	int	chars;

	chars = 0;
	while (*string)
	{
		write(1, string++, 1);
		chars++;
	}
	return chars;
}

int ft_print_int(int number)
{
	char	c;
	int		chars;

	chars = 0;
	if (number < 0)
	{
		write(1, "-", 1);
		if (number == -2147483648)
		{
			write(1, "2", 1);
			number = -147483648;
		}
		return 2 + ft_print_int(number * -1);
	}
	else if (number > 9)
	{
		ft_print_int((number / 10));
		c = (number % 10) + '0';
		write(1, &c, 1);
	}
	else
	{
		c = number + '0';
		write(1, &c, 1);
	}
	return 1;
}

int ft_print_unsigned_int(unsigned int number)
{
	char	c;
	int		chars;

	if (number > 9)
	{
		chars = ft_print_unsigned_int((number / 10));
		c = (number % 10) + '0';
		write(1, &c, 1);
	}
	else
	{
		chars = 0;
		c = number + '0';
		write(1, &c, 1);
	}
	return 1 + chars;
}

int ft_print_hexadecimal(size_t number, char *base)
{
	char	c;
	int		chars;

	if (number > 15)
	{
		chars = ft_print_hexadecimal(number / 16, base);
		c = base[number % 16];
		write(1, &c, 1);
	}
	else
	{
		chars = 0;
		c = base[number];
		write(1, &c, 1);
	}
	return 1 + chars;
}

int ft_print_pointer(void *pointer)
{
	write(1, "0x", 2);
	return (2 + ft_print_hexadecimal((size_t) pointer, "0123456789abcdef"));
}

int ft_print_percent()
{
	write(1, "%", 1);
	return 1;
}

int	ft_print_vars(char *string, va_list args)
{
	if (*string == 'c')
		return ft_print_char(va_arg(args, int));
	if (*string == 's')
		return ft_print_string(va_arg(args, char*));
	if (*string == 'p')
		return ft_print_pointer(va_arg(args, void*));
	if (*string == 'd' || *string == 'i')
		return ft_print_int(va_arg(args, int));
	if (*string == 'u')
		return ft_print_unsigned_int(va_arg(args, unsigned int));
	if (*string == 'x')
		return ft_print_hexadecimal(va_arg(args, int), "0123456789abcdef");
	if (*string == 'X')
		return ft_print_hexadecimal(va_arg(args, int), "0123456789ABCDEF");
	if (*string == '%')
		return ft_print_percent();
}

int	ft_printf(char *string, ...)
{
	int		chars;
	va_list	args;

	chars = 0;
	va_start(args, string);
	while (*string && chars < 25)
	{
		if (*string == '%')
			chars += ft_print_vars(++string, args);
		else
		{
			write(1, string, 1);
			chars++;
		}
		string++;
	}
	va_end(args);
	return chars;
}

int main(void)
{
	char pointer = 'A';
	   printf("                : %d\n",    printf("             CHAR: %c", 'A'));
	ft_printf("                : %d\n", ft_printf("             CHAR: %c", 'A'));
			printf("           : %d\n",    printf("           STRING: %s", "ABCDEF"));
		 ft_printf("           : %d\n", ft_printf("           STRING: %s", "ABCDEF"));
					printf("   : %d\n",    printf("          POINTER: %p", &pointer));
				 ft_printf("   : %d\n", ft_printf("          POINTER: %p", &pointer));
		 printf("              : %d\n",    printf("          DECIMAL: %d", -42));
	  ft_printf("              : %d\n", ft_printf("          DECIMAL: %d", -42));
		 printf("              : %d\n",    printf("          INTEIRO: %i", -42));
	  ft_printf("              : %d\n", ft_printf("          INTEIRO: %i", -42));
		printf("               : %d\n",    printf("INTEIRO SEM SINAL: %u", 42));
	 ft_printf("               : %d\n", ft_printf("INTEIRO SEM SINAL: %u", 42));
		printf("               : %d\n",    printf("  HEXADECIMAL MIN: %x", 42));
	 ft_printf("               : %d\n", ft_printf("  HEXADECIMAL MIN: %x", 42));
		printf("               : %d\n",    printf("      HEXADECIMAL: %X", 42));
	 ft_printf("               : %d\n", ft_printf("      HEXADECIMAL: %X", 42));
	   printf("                : %d\n",    printf("         PORCENTO: %%"));
	ft_printf("                : %d\n", ft_printf("         PORCENTO: %%"));
}
