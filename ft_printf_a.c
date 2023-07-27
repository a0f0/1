#include <unistd.h>//a
#include <stdarg.h>

void	if_D(long long int num, int b, int *len)
{
	char	*B16 = "0123456789ABCDEF";

	if (num < 0)
	{
		num *= -1;
		*len += write(1, "-", 1);
	}
	if (num >= b)
    {
        if_D((num / b), b, len);
    }
	*len += write(1, &B16[num % b], 1);
}

void	if_D(char *s, int *len)
{
	if (!s)
    {
        s = "(Null)";
    }
	while (*s)
    {
        *len += write(1, s++, 1);
    }
}

int	ft_printf(const char *f, ...)
{
	int len = 0;

	va_list	ptr;
	va_start(ptr, f);

	while (*f)
	{
		if ((*f == '%') && ((*(f + 1) == 's') || (*(f + 1) == 'd') || (*(f + 1) == 'x')))
		{
			f++;
			if (*f == 's')
				if_s(va_arg(ptr, char *), &len);
			else if (*f == 'x')
				if_D((long long int)va_arg(ptr, unsigned int), 16, &len);
            else if (*f == 'd')
				if_D((long long int)va_arg(ptr, int), 10, &len);
		}
		else
			len += write(1, f, 1);
		f++;
	}
	return (va_end(ptr), len);
}
