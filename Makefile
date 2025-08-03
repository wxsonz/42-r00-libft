CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
       ft_toupper.c ft_tolower.c ft_atoi.c ft_itoa.c\
       ft_bzero.c ft_memset.c ft_memcpy.c ft_memmove.c ft_calloc.c ft_memcmp.c ft_memchr.c\
       ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strdup.c\
       ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c\
       ft_strmapi.c ft_striteri.c\
       ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c\
	ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
SRCS_O = $(SRCS:.c=.o)
BONUS_O = $(BONUS:.c=.o)

all: $(NAME)

%.o: %.c Makefile libft.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(SRCS_O)
	ar rc $(NAME) $(SRCS_O)

so:
	$(CC) -fPIC -nostartfiles $(CFLAGS) $(SRCS)
	$(CC) -nostartfiles -shared -o libft.so $(SRCS_O)

bonus: $(SRCS_O) $(BONUS_O)
	ar rc $(NAME) $(BONUS_O) $(SRCS_O)

clean:
	rm -rf $(SRCS_O) $(BONUS_O)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re so

