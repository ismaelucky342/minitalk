#ifndef MINITALK_H
# define MINITALK_H

# define BUFFERSIZE 1024

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

typedef struct	s_stack
{
	char		message[BUFFERSIZE];
	int			top_bit;
	int			top_byte;
	_Bool		all_receive;
	_Bool		buff_overflow;
}				t_stack;

t_stack			g_print = {{0}, 1 << 6, 0, FALSE, FALSE};

#endif