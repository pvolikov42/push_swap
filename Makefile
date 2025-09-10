SRC = srcs
INCL = includes
CC = cc
# CFLAGS = -Wall -Wextra -I $(INCL)
# CFLAGS = -Wall -Wextra -Werror -I $(INCL)
CFLAGS = -Wall -Wextra -Werror
MODS = push_swap \
		stacks	\
		histacks	\
		hiops	\
		sort \
		utils
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

$(TGT): $(OBJS)
#	$(CC) $(CFLAGS) -c $@.c -o $@ $< -Llibft -lft
	$(CC) $(CFLAGS) -o $@ $(OBJS) -Llibft -lft
	
%.o: %.c *.h 
#	cd libft; make
#	$(CC) $(CFLAGS) -c $@.c -o $@ $< -Llibft -lft
	$(CC) $(CFLAGS) -c $< -Llibft -lft

# libft.a :	$(OBJS)
#	ar rcs libft.a $(OBJS)

# %.o: %.c $(INCL)/ft.h
#	$(CC) -c $(CFLAGS) -o $@ $<

# ($OBJS) : $(INCL)/ft.h
#	$(CC) -c $(CFLAGS) $< -o $@

clean :
	rm -f *.o

fclean : clean
	rm -f a.out

re : fclean all

test: $(TGTLIB)
	$(CC) $(CFLAGS) -o test test.c -Llibft -lft
	./test
