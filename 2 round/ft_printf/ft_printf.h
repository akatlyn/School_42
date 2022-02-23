#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_flag
{
	char	type;
	int		width;
	int		precision;
	int		minus;
	int		null;
}		t_flag;

int		ft_printf(const char *s1, ...);
int		ft_parser(va_list vl, const char *s1);
t_flag	ft_init(void);
int		ft_p_flag(const char *s1, va_list vl, int	*i, t_flag *flags);
int		ft_min(const char *s1, t_flag *flags, int *i);
int		ft_width(const char	*s1, t_flag	*flags, va_list vl, int *i);
int		ft_precision(const char	*s1, t_flag	*flags, va_list vl, int *i);
int		ft_prec_sec(const char *s1, t_flag *flags, int *i);
int		ft_print(va_list vl, t_flag	*flags);
int		ft_print_c(t_flag *flags, char c);
int		ft_print_width(int	width, int null);
int		ft_isdigit(int c);
int		ft_strlen(const char *s);
void	ft_putchar(char c);
int		ft_print_s(t_flag *flags, char *s);
void	ft_putnstr(char *s, int len);
int		ft_print_digit(t_flag *flags, int di);
int		ft_digit_plus(t_flag *flags, int di);
char	*ft_itoa_d(unsigned int di);
int		ft_digit_minus(t_flag *flags, int di);
int		ft_print_digit_u(t_flag *flag, unsigned int u);
int		ft_print_x(t_flag *flags, unsigned int x);
int		ft_print_xx(t_flag *flags, unsigned int x);
int		ft_print_p(t_flag *flags, unsigned long p);
int		ft_print_pp(char *s, t_flag *flags, unsigned long p, int len);

#endif