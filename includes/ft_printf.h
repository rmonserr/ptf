#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include "../libft/includes/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <float.h>

typedef struct	s_params
{
	va_list		args;
	char		*format;
	long int	precision;
	long int	width;
	int			minus_sign;
	int			plus_sign;
	int			space;
	int			zero;
	int			hash;
	size_t		size;
	int			counter;
	int			total;
	int			negative;
	int			printed;
	int			trigger;
	char		type;
	char		*specifier_mask;
	char		*flag_mask;
	char		*output_str;
}				t_params;

int				ft_printf(char *format, ...);
t_params		*init(t_params *data, char *format);
void			clean_struct(t_params *data);
void			parcer(t_params *data);
void			read_specifier(t_params *data);
void			read_flag(t_params *data);
void			read_width(t_params *data);
void			read_precision(t_params *data);
void			read_precision_2(t_params *data);
void			read_size(t_params *data);
void			sort_flags(t_params *data);
void			type_parsing(t_params *data);
int				check_space(t_params *data);

//int
char			*move_minus(char *str);
int				print_zero(t_params *data);
char			*put_minus(int len, char *str);
char			*print_int_3(t_params *data, int len, char *str);
char			*print_int_2(t_params *data, int len, char *str);
void			print_int(t_params *data);

//char
void			print_char(t_params *data);
void			print_char_with_width(t_params *data);
void			print_string(t_params *data);

//str
void			print_string(t_params *data);
char			*print_string_2(t_params *data, long int len, char *str);
char			*print_string_3(t_params *data, int len, char *str);
char			*check_null(t_params *data, char *str);

//octal
void			print_octal(t_params *data);
char			*octal_calculation(unsigned long long int number, t_params *data);
char			*print_octal_2(t_params *data, char *str, int len);
char			*print_octal_3(t_params *data, char *str, int len);

//unsigned
void			print_unsigned(t_params *data);

//hexadecimal
void			print_hexadecimal(t_params *data);
char			*hex_calculation(unsigned long long int number, t_params *data);
char			*hex_str(int number, char *res, t_params *data);

//pointer
void			print_pointer(t_params *data);

//floats
void			print_f(t_params *data, long double arg);
char			*ft_prec(t_params *data, char *output);
char			*ft_make_output(long double nbr, int arg, t_params *data, int count);
char			*add_one(char *str);
char			*rounding(t_params *data, char *output);
char			*use_zero(t_params *data, char *output, int flag);
char			*use_flag(t_params *data, char *output, int flag);
char			*copy(char *output, char *str);
char			*floatld_inf_or_nan(int mant, int sign);
void			print_start_f(t_params *data);


# endif
