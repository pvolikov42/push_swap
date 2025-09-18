SRC = srcs
INCL = includes
CC = cc
# CFLAGS = -Wall -Wextra -I $(INCL)
# CFLAGS = -Wall -Wextra -Werror -I $(INCL)
CFLAGS = -Wall -Wextra -Werror
# MODS = push_swap 
MODS = logic1 logic2 logic3 logic4 logic5 logic6 \
		stacks stacks1 stacks2 \
		histacks histacks1 histacks2 histacks3 histacks4 \
		hiops hiops1 hiops2 hiops3\
		sort sort1 sort2 \
		utils utils1
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

$(TGT): $(OBJS) $(TGT).o
#	$(CC) $(CFLAGS) -c $@.c -o $@ $< -Llibft -lft
	$(CC) $(CFLAGS) -o $@ $(TGT).o $(OBJS) -Llibft -lft
	
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
	rm -f $(TGT)

fclean : clean
	rm -f *.o

re : fclean all

test: $(OBJS)
	$(CC) $(CFLAGS) -o test test.c $(OBJS) -Llibft -lft
	./test
