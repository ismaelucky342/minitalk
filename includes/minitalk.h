/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:18:07 by ismherna          #+#    #+#             */
/*   Updated: 2024/07/03 20:47:39 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h> // Encabezado estándar para señales
# include <stdio.h> // Para printf
# include <stdlib.h>
# include <string.h> // Para manejo de cadenas
# include <unistd.h>

void			ft_printf(const char *format, ...);
int				ft_atoi(const char *str);
char			*ft_string2bin(const char *str, int a, int b);
char			*ft_strdup(const char *s);
char			*ft_add_fs(char *s, char c);
void			ft_bin2ascii(char *bin);

#endif
