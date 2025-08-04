SRC = srcs
INCL = includes
CC = cc
# CFLAGS = -Wall -Wextra -I $(INCL)
# CFLAGS = -Wall -Wextra -Werror -I $(INCL)
CFLAGS = -Wall -Wextra -Werror
MODS = ft_printf \
		conversion
# VPATH = srcs
# NAMEOBJS = ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
# NAMEOBJS = $(addprefix ft_,$(FUNCS))
# vpath %.c $(SRC)
# vpath %.h $(INCL)
# vpath %goal test
# OBJS = $(addprefix $(SRC)/,$(NAMEOBJS))
OBJS = $(addsuffix .o,$(MODS))
TGT = push_swap

.PHONY:	all clean fclean re test
all :	$(TGT)

$(TGT): 
#	$(CC) $(CFLAGS) -c %@.c -o $@ $< -Llibft -lft
	$(CC) $(CFLAGS) %@.c -o $@
	
%.o: %.c *.h 
#	cd libft; make
	$(CC) $(CFLAGS) -c %@.c -o $@ $< -Llibft -lft

# libft.a :	$(OBJS)
#	ar rcs libft.a $(OBJS)

# %.o: %.c $(INCL)/ft.h
#	$(CC) -c $(CFLAGS) -o $@ $<

# ($OBJS) : $(INCL)/ft.h
# $(CC) -c $(CFLAGS) $< -o $@

clean :
	rm -f *.o

fclean : clean
	rm -f a.out

re : fclean all

test: $(TGTLIB)
	$(CC) $(CFLAGS) -o test test.c -L. -lftprintf
	./test
