########### V A R I A B L E S #############

NAME        = Array
INCLUDES    = -Iincludes
SRC_DIR     = srcs
OBJ_DIR     = obj
CXX         = c++
CTAGS       = ctags
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98
CPPFLAGS    = -MMD

############### S O U R C E S #############

SRC_FILES       := $(shell find $(SRC_DIR) -type f -name "*.cpp")
SRCS            := $(SRC_FILES)
OBJS            := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
DEPS            = $(OBJS:.o=.d) 

################ R U L E S ################

all             : $(NAME)

$(NAME)         : $(OBJS)
	@$(CXX) $(OBJS) $(CXXFLAGS) $(INCLUDES) -o $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

tags            : $(SRCS)
	@$(CTAGS) -R

clean           :
	$(RM) -r $(OBJ_DIR) tags

fclean          : clean
	$(RM) $(NAME)

re              : fclean all

clear           :
	clear

test            : $(NAME)
	./$(NAME)

ctest           : clear test

vtest           : $(NAME)
	valgrind ./$(NAME)

cvtest          : clear vtest

-include $(DEPS)

.PHONY: all clean fclean re test ctest vtest cvtest

