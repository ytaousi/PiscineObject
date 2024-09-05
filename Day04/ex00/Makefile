NAME = ex00
SRCS = ./main.cpp ./course.cpp ./form.cpp ./person.cpp ./room.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98
OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	g++ $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	clang++ $(FLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all