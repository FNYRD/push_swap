/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:41:53 by jericard          #+#    #+#             */
/*   Updated: 2025/11/21 14:41:55 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>

char	*ft_ctos(const char c);
char	*ft_utoa(unsigned int n);
char	ft_datatype(const char *ptr);
char	*ft_hexa(unsigned long long n, char x);
char	*ft_stringer(const char c, va_list *arg, const char *format);

int		ft_flag(const char *str);
int		ft_width(const char *str);
int		ft_skipping(const char c);
int		ft_printf(const char *format, ...);
int		ft_precision(const char *str);
int		ft_signalflag(const char *str);
int		ft_count_0xchar(unsigned long long n);

size_t	ft_manager(const char *data, const char *format);
size_t	ft_onlywods(const char *data, const char *format, char type);
size_t	ft_putminzero(const char *str, size_t positions, size_t flag);
size_t	ft_ph(const char *data, int precision, int flag, long long width);
size_t	ft_dotcase(const char *str, size_t p, size_t precision, size_t flag);

ssize_t	ft_typeverify(char c);
ssize_t	ft_putstr(const char *s);
ssize_t	ft_putchar(const char c);

#endif
