##
## EPITECH PROJECT, 2019
## kbenchmark
## File description:
## Makefile
##

BIN		=	kbench

TEST	=	unit_tests

INCLUDE 	=	kbenchmark/include/								\

SRC			=	kbenchmark/src/odd/odd.cpp						\
				kbenchmark/src/my_chrono.cpp					\

SRC_MAIN	=	$(SRC)											\
				kbenchmark/src/main.cpp

SRC_TEST	=	$(SRC)											\

OBJ			=	$(SRC_MAIN:%.cpp=%.o)

OBJ_TEST	=	$(SRC_TEST:%.cpp=%.o)

GCDAS		=	$(SRC:%.cpp=%.gcda) $(SRC_TEST:%.cpp=%.gcda)
GCNOS		=	$(SRC:%.cpp=%.gcno)  $(SRC_TEST:%.cpp=%.gcno)

CXX			=	g++

CPPFLAGS	=	-W -Wall -Wpedantic -Wextra -Wshadow -Wstrict-overflow=5 -Wmissing-declarations -Wundef	\
				-Wstack-protector -Wconversion -Wno-unused-parameter -march=native -pipe -std=c++14		\
				-lpthread -I $(INCLUDE)
# -Werror  -Wno-unused-result -Wold-style-cast	

RM			=	rm -f

GCOVR		=	gcovr -r . --exclude tests/


all: CPPFLAGS += -O3
all:$(BIN)

$(BIN): $(OBJ) 
	$(CXX) $(OBJ) $(LDFLAGS) -o $(BIN)

tests_run: CPPFLAGS += -g -O0 -lcriterion
tests_run: $(TEST)
	./$(TEST)

$(TEST): $(OBJ_TEST) 
	$(CXX) $(OBJ_TEST) $(LDFLAGS) --coverage -lcriterion -o $(TEST)

coverage_run: CPPFLAGS += --coverage
coverage_run: tests_run
	$(GCOVR)

branches_run: CPPFLAGS += --coverage
branches_run: tests_run
	$(GCOVR) --branches 

coverage_html_run: CPPFLAGS += --coverage
coverage_html_run: tests_run
	$(GCOVR) --html --html-details -o coverage.html

gdb: CPPFLAGS += -O0 -g3 -ggdb3
gdb:$(BIN)
	gdb ./$(BIN)

valgrind: CPPFLAGS += -g3 -O0
valgrind:$(BIN)
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all -v ./$(BIN)

re:	fclean all

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_TEST)
	$(RM) $(GCDAS)
	$(RM) $(GCNOS)

fclean: clean
	$(RM) $(BIN)
	$(RM) $(TEST)

.PHNOY: clean fclean re all tests_run $(BIN) $(TEST) coverage_run
