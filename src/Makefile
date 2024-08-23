CC = gcc
FLAGS = -Wall -Wextra -Werror -std=c11
SANITIZE=-fsanitize=address -g
TST_LIBS = -lcheck
ifeq ($(shell uname), Linux)
	TST_LIBS += -lpthread -lrt 
endif
LIB_NAME = s21_decimal

SRCS=$(wildcard s21_*.c)

OBJS=$(SRCS:.c=.o)

all: clean test

clean:
	rm -rf *.o test *.a *.gcno *.gcda *.gcov *.html *.css Main SANITIZE *.dSYM

clang-format:
	clang-format -i *.c *.h tests/*.c tests/*.h

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIB_NAME).a: $(OBJS)
	ar rc $(LIB_NAME).a $^
	ranlib $(LIB_NAME).a
	rm -rf *.o

# check - либа для работы тестов, $(LIB_NAME) - наша либа
test: clean $(LIB_NAME).a
	$(CC) $(FLAGS) check.c tests/*.c $(LIB_NAME).a $(TST_LIBS) -o test

sanitize: clean $(LIB_NAME).a
	$(CC) $(FLAGS) $(SANITIZE) check.c tests/*.c $(LIB_NAME).a $(TST_LIBS) -o SANITIZE

main: $(LIB_NAME).a
	$(CC) $(FLAGS) main.c $(LIB_NAME).a -o Main

add_coverage_flag:
	$(eval FLAGS += --coverage)

gcov_report: add_coverage_flag test 
# 	mi-g6 || mi-j6 || at-h6
	./test
	rm -rf check*.gcda check*.gcno
	gcov -b -l -p -c s21_*.gcno
	gcovr -o gcov_report.html --html --html-details

#cppcheck --enable=all --suppress=missingIncludeSystem src/