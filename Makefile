# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/16 20:06:05 by gboudrie          #+#    #+#              #
#    Updated: 2018/11/13 16:56:23 by gboudrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ansi chars
LOG = 	\033[2K
BLUE = 	\033[1;34m
YELLOW =\033[1;33m
GREEN =	\033[1;32m
RED =	\033[1;31m
CLEAR =	\033[0m
BOLD =	\033[1m
UNDERL =\033[4m
SHI =	\xF0\x9F\x9B\xA1
TRA =	\xF0\x9F\x97\x91
LIG =	\xE2\x9A\xA1
BR_V =	\xe2\x95\x91
BR_H =	\xe2\x95\x90
CR_UR =	\xe2\x95\x97
CR_UL =	\xe2\x95\x94
CR_DR =	\xe2\x95\x9d
CR_DL =	\xe2\x95\x9a

# comp
CC =		clang++
CFLAGS =	-Wall -Wextra -Werror

# binaries
EXE =       AbstractVM
LIB_A =

# dir
SRC_DIR =	    sources
OBJ_DIR =	    objs
OBJXCP_DIR =    objsxcp
XCP_DIR =       exceptions
INC_DIR =	    includes

# libs

# sources
SRC_NAME =	Operand.cpp\
			OperandFactory.cpp\
			AbstractStack.cpp\
			Lexer.cpp\
			Parser.cpp\
			Token.cpp\
			FileHandler.cpp\
			AbstractStackExceptions.cpp\
            LexerParserExceptions.cpp\
            OperandExceptions.cpp\
			main.cpp



# objects
OBJ_NAME =		$(SRC_NAME:.cpp=.o)


#paths
SRC =		$(addprefix $(SRC_DIR)/, $(SRC_NAME))
OBJ =		$(addprefix $(OBJ_DIR)/, $(OBJ_NAME))

all :		$(EXE)
$(EXE) :    $(SRC) $(OBJ)
	@$(CC) $(OBJ) -o $@
	@echo "$(CLEAR)$(LIG)$(BLUE) Compiling "$(EXE) "$(CLEAR)$(LIG)"
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR) 2> /dev/null || true
	@$(CC) $(CFLAGS) -o $@ -c $<
meteo :
	@curl http://wttr.in/Paris
clean :
	@echo "$(CLEAR)$(TRA)$(RED)  Cleaning Object $(CLEAR)$(TRA)"
	@$(RM) $(OBJ)
	@rmdir $(OBJ_DIR) 2> /dev/null || true
fclean :	clean
	@echo "$(CLEAR)$(TRA)$(RED)  Removing Binary $(CLEAR)$(TRA)"
	@$(RM) $(EXE)
re :		fclean all
.PHONY :	all, clean, fclean, re
.SILENT :