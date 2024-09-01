NAME = ex00
SRCS = ./main.cpp ./car.cpp ./engine.cpp ./gears.cpp ./brake.cpp ./wheels.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98
OBJS = $(SRCS:.cpp=.o)


%.o: %.c
	@clang++ $(FLAGS) -c $< -o $@

$OBJS: $(SRCS)
	@clang++ $(FLAGS) -c $(SRCS)

all: $(NAME)

$(NAME): $(OBJS)
	@clang++ $(FLAGS) $(SRCS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)


re: fclean all