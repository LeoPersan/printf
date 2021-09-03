#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define FLAGS "# +-0"
#define HAS_HASHTAG_FLAG(f) f&(1<<0)
#define HAS_SPACE_FLAG(f) f&(1<<1)
#define HAS_PLUS_FLAG(f) f&(1<<2)
#define HAS_ZERO_FLAG(f) f&(1<<3)

int ft_print_char(char c, int *formaters)
{
	int	width;

	width = 0;
	while (++width < formaters[1])
		write(1, " ", 1);
	write(1, &c, 1);
	return (width);
}

int ft_print_string(char *string, int *formaters)
{
	int	chars;
	int	width;

	chars = 0;
	while (string[chars])
		chars++;
	width = -1;
	while (++width + chars < formaters[1])
		write(1, " ", 1);
	write(1, string++, chars);
	return (width + chars);
}

int ft_print_int(int number, int *formaters)
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
		return 2 + ft_print_int(number * -1, formaters);
	}
	else if (number > 9)
	{
		ft_print_int(number / 10, formaters);
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

int ft_print_unsigned_int(unsigned int number, int *formaters)
{
	char	c;
	int		chars;

	if (number > 9)
	{
		chars = ft_print_unsigned_int(number / 10, formaters);
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

int ft_print_hexadecimal(size_t number, char *base, int *formaters)
{
	char	c;
	int		chars;

	if (number > 15)
	{
		chars = ft_print_hexadecimal(number / 16, base, formaters);
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

int ft_print_pointer(void *pointer, int *formaters)
{
	write(1, "0x", 2);
	return (2 + ft_print_hexadecimal((size_t) pointer, "0123456789abcdef", formaters));
}

int ft_print_percent()
{
	write(1, "%", 1);
	return 1;
}

int	ft_conversors(char *string, va_list args, int *formaters)
{
	// printf("ft_conversors: %c %d %d %d\n", *string, formaters[0], formaters[1], formaters[2]);
	if (*string == 'c')
		return ft_print_char(va_arg(args, int), formaters);
	if (*string == 's')
		return ft_print_string(va_arg(args, char*), formaters);
	if (*string == 'p')
		return ft_print_pointer(va_arg(args, void*), formaters);
	if (*string == 'd' || *string == 'i')
		return ft_print_int(va_arg(args, int), formaters);
	if (*string == 'u')
		return ft_print_unsigned_int(va_arg(args, unsigned int), formaters);
	if (*string == 'x')
		return ft_print_hexadecimal(va_arg(args, int), "0123456789abcdef", formaters);
	if (*string == 'X')
		return ft_print_hexadecimal(va_arg(args, int), "0123456789ABCDEF", formaters);
	if (*string == '%')
		return ft_print_percent();
}

int	ft_strpos(char *string, char c)
{
	int pos;

	pos = -1;
	while (string[++pos])
		if (string[pos] == c)
			return (pos);
	return (-1);
}

int	ft_formaters_flags(char **string)
{
	int flags;
	int pos;

	flags = 0;
	pos = ft_strpos(FLAGS, **string);
	while (**string && pos > -1)
	{
		if (flags & (1 << pos))
			return (-1);
		flags = flags | (1 << pos);
		pos = ft_strpos(FLAGS, *(*string)++);
	}
	return (flags);
}

int	ft_formaters_width(char **string)
{
	int width;

	width = 0;
	while (**string && **string >= '0' && **string <= '9')
		width = (width *10) + (*(*string)++ - '0');
	return (width);
}

int	ft_formaters_precision(char **string)
{
	int precision;

	precision = 0;
	if (**string == '.')
		(*string)++;
	while (**string && **string >= '0' && **string <= '9')
		precision + (precision *10) + (*(*string)++ - '0');
	return (precision);
}

int *ft_formaters(char **string, int *formaters)
{
	// printf("ft_formaters1: %c %d %d %d\n", **string, formaters[0], formaters[1], formaters[2]);
	formaters[0] = ft_formaters_flags(string);
	// printf("ft_formaters2: %c %d %d %d\n", **string, formaters[0], formaters[1], formaters[2]);
	formaters[1] = ft_formaters_width(string);
	// printf("ft_formaters3: %c %d %d %d\n", **string, formaters[0], formaters[1], formaters[2]);
	formaters[2] = ft_formaters_precision(string);
	// printf("ft_formaters4: %c %d %d %d\n", **string, formaters[0], formaters[1], formaters[2]);
	return formaters;
}

int	ft_print_var(char **string, va_list args)
{
	int	formaters[3];

	return ft_conversors(*string, args, ft_formaters(string, formaters));
}

int	ft_printf(char *string, ...)
{
	int		chars;
	va_list	args;

	chars = 0;
	va_start(args, string);
	while (*string)
	{
		if (*string == '%')
		{
			string++;
			chars += ft_print_var(&string, args);
		}
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
	   printf("                : %d\n",    printf("             CHAR: |%c|", 'A'));
	ft_printf("                : %d\n", ft_printf("             CHAR: |%c|", 'A'));
			printf("           : %d\n",    printf("           STRING: |%s|", "ABCDEF"));
		 ft_printf("           : %d\n", ft_printf("           STRING: |%s|", "ABCDEF"));
					printf("   : %d\n",    printf("          POINTER: |%p|", &pointer));
				 ft_printf("   : %d\n", ft_printf("          POINTER: |%p|", &pointer));
		 printf("              : %d\n",    printf("          DECIMAL: |%d|", -42));
	  ft_printf("              : %d\n", ft_printf("          DECIMAL: |%d|", -42));
		 printf("              : %d\n",    printf("          INTEIRO: |%i|", -42));
	  ft_printf("              : %d\n", ft_printf("          INTEIRO: |%i|", -42));
		printf("               : %d\n",    printf("INTEIRO SEM SINAL: |%u|", 42));
	 ft_printf("               : %d\n", ft_printf("INTEIRO SEM SINAL: |%u|", 42));
		printf("               : %d\n",    printf("  HEXADECIMAL MIN: |%x|", 42));
	 ft_printf("               : %d\n", ft_printf("  HEXADECIMAL MIN: |%x|", 42));
		printf("               : %d\n",    printf("      HEXADECIMAL: |%X|", 42));
	 ft_printf("               : %d\n", ft_printf("      HEXADECIMAL: |%X|", 42));
	   printf("                : %d\n",    printf("         PORCENTO: |%%|"));
	ft_printf("                : %d\n", ft_printf("         PORCENTO: |%%|"));

	   printf("            : %d\n",    printf("             CHAR: |%5c|", 'A'));
	ft_printf("            : %d\n", ft_printf("             CHAR: |%5c|", 'A'));
			printf("           : %d\n",    printf("           STRING: |%5s|", "ABCDEF"));
		 ft_printf("           : %d\n", ft_printf("           STRING: |%5s|", "ABCDEF"));
					printf("   : %d\n",    printf("          POINTER: |%5p|", &pointer));
				 ft_printf("   : %d\n", ft_printf("          POINTER: |%5p|", &pointer));
		 printf("            : %d\n",    printf("          DECIMAL: |%5d|", -42));
	  ft_printf("            : %d\n", ft_printf("          DECIMAL: |%5d|", -42));
		 printf("            : %d\n",    printf("          INTEIRO: |%5i|", -42));
	  ft_printf("            : %d\n", ft_printf("          INTEIRO: |%5i|", -42));
		printf("             : %d\n",    printf("INTEIRO SEM SINAL: |%5u|", 42));
	 ft_printf("             : %d\n", ft_printf("INTEIRO SEM SINAL: |%5u|", 42));
		printf("             : %d\n",    printf("  HEXADECIMAL MIN: |%5x|", 42));
	 ft_printf("             : %d\n", ft_printf("  HEXADECIMAL MIN: |%5x|", 42));
		printf("             : %d\n",    printf("      HEXADECIMAL: |%5X|", 42));
	 ft_printf("             : %d\n", ft_printf("      HEXADECIMAL: |%5X|", 42));
	   printf("                : %d\n",    printf("         PORCENTO: |%5%|"));
	ft_printf("                : %d\n", ft_printf("         PORCENTO: |%5%|"));
}
