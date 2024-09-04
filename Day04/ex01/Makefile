NAME = ex01
SRCS = ./main.cpp ./person.cpp ./studentList.cpp ./staffList.cpp ./room.cpp ./roomList.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98
OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	clang++ $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	clang++ $(FLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all