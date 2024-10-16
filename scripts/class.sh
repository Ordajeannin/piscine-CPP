#!/bin/bash

# Function to create the makefile
create_makefile() {
    if [ -f makefile ]; then
        echo "makefile already exists. Skipping creation."
        return
    fi

    cat <<EOL > makefile
########### V A R I A B L E S #############

NAME        = $CLASS_NAME
INCLUDES    = -Iincludes
SRC_DIR     = srcs
OBJ_DIR     = obj
CXX         = c++
CTAGS		= ctags
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98
CPPFLAGS    = -MMD

############### S O U R C E S #############

SRC_FILES       := \$(shell find \$(SRC_DIR) -type f -name "*.cpp")
SRCS            := \$(SRC_FILES)
OBJS            := \$(patsubst \$(SRC_DIR)/%.cpp, \$(OBJ_DIR)/%.o, \$(SRCS))
DEPS            = \$(OBJS:.o=.d) 

################ R U L E S ################

all             : \$(NAME)

\$(NAME)        : \$(OBJS)
	@\$(CXX) \$(OBJS) \$(CXXFLAGS) \$(INCLUDES) -o \$(NAME)

\$(OBJ_DIR)/%.o : \$(SRC_DIR)/%.cpp
	@mkdir -p \$(@D)
	@\$(CXX) \$(CPPFLAGS) \$(CXXFLAGS) \$(INCLUDES) -c \$< -o \$@

tags			: \$(SRCS)
	@\$(CTAGS) -R
clean           :
	\$(RM) -r \$(OBJ_DIR) tags

fclean          : clean
	\$(RM) \$(NAME)

re              : fclean all

clear			:
	clear

test            : \$(NAME)
	./\$(NAME)

ctest			: clear test

vtest           : \$(NAME)
	valgrind ./\$(NAME)

cvtest			: clear vtest

-include \$(DEPS)

.PHONY: all clean fclean re test ctest vtest cvtest
EOL
    echo "makefile has been created."
}

# Default values
create_makefile_flag=false

# Parse options
while getopts ":m" opt; do
  case $opt in
    m)
      create_makefile_flag=true
      ;;
    \?)  # Handle invalid options
      echo "Usage: $0 [-m] ClassName"
      exit 1
      ;;
  esac
done

# Shift processed options
shift $((OPTIND - 1))

# Check if class name is provided
if [ -z "$1" ]; then
    echo "Usage: $0 [-m] ClassName"
    exit 1
fi

CLASS_NAME=$1
HEADER_FILE="includes/${CLASS_NAME}.hpp"
SOURCE_FILE="srcs/${CLASS_NAME}.cpp"
MAIN_FILE="srcs/main.cpp"

# Create directories if they don't exist
mkdir -p includes
mkdir -p srcs

# Create header file if it doesn't exist
if [ -f "$HEADER_FILE" ]; then
    echo "Header file $HEADER_FILE already exists. Skipping creation."
else
    cat <<EOL > $HEADER_FILE
#ifndef ${CLASS_NAME^^}_HPP
#define ${CLASS_NAME^^}_HPP

#include <string>
#include <iostream>

class $CLASS_NAME
{
    private:
        std::string _name;
    public:
        $CLASS_NAME();
        $CLASS_NAME(std::string _name);
        $CLASS_NAME(const $CLASS_NAME &c);
        ~$CLASS_NAME();
        $CLASS_NAME &operator=(const $CLASS_NAME &c);
};

#endif
EOL
    echo "Header file $HEADER_FILE has been created."
fi

# Create source file if it doesn't exist
if [ -f "$SOURCE_FILE" ]; then
    echo "Source file $SOURCE_FILE already exists. Skipping creation."
else
    cat <<EOL > $SOURCE_FILE
#include "$CLASS_NAME.hpp"

$CLASS_NAME::$CLASS_NAME() : _name("exemple")
{
    std::cout << "$CLASS_NAME default constructor called" << std::endl;
}

$CLASS_NAME::$CLASS_NAME(std::string name) : _name(name)
{
    std::cout << "$CLASS_NAME constructor called : " << name << std::endl;
}

$CLASS_NAME::$CLASS_NAME(const $CLASS_NAME &c)
{
    std::cout << "$CLASS_NAME copy constructor called : " << c._name << std::endl;
    *this = c;
}

$CLASS_NAME::~$CLASS_NAME()
{
    std::cout << "$CLASS_NAME destructor called" << std::endl;
}

$CLASS_NAME &$CLASS_NAME::operator=(const $CLASS_NAME &c)
{
    std::cout << "$CLASS_NAME copy assignement operator called" << std::endl;
    if (this != &c)
    {
        this->_name = c._name;
    }
    return *this;
}
EOL
    echo "Source file $SOURCE_FILE has been created."
fi

# Create makefile and main.cpp if the -m flag is set
if [ "$create_makefile_flag" = true ]; then
    create_makefile

    # Create main.cpp if it doesn't exist
    if [ -f "$MAIN_FILE" ]; then
        echo "Main file $MAIN_FILE already exists. Skipping creation."
    else
        cat <<EOL > $MAIN_FILE
#include "$CLASS_NAME.hpp"

int main() {
    $CLASS_NAME obj1;
    $CLASS_NAME obj2("example_name");
    $CLASS_NAME obj3(obj2);

    obj1 = obj2;

    return 0;
}
EOL
        echo "Main file $MAIN_FILE has been created."
    fi
fi


