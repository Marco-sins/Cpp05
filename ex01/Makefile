CPP := c++
CPPFLAGS := -Wall -Werror -Wextra -std=c++98
RM := rm -fr

SRC :=	main.cpp \
		Bureaucrat.cpp \
		Form.cpp

HEADERS := 	Bureaucrat.hpp \
		Form.hpp

OBJDIR = objs
OBJ = $(SRC:%.cpp=$(OBJDIR)/%.o)

NAME := form

all: $(NAME)

$(OBJDIR)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(dir $@)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo "Compiling"

clean:
	@$(RM) $(OBJDIR)
	@echo "Clean objects"

fclean: clean
	@$(RM) $(NAME)
	@echo "Clean executable"

re: fclean all

.PHONY: all clean fclean re
