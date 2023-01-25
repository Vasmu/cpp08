SRCS= main.cpp \

HEADERS= Span.hpp \
		 MutantStack.hpp \

CXX= c++

CFLAGS= -Wall -Wextra -Werror -std=c++98

OBJS= ${SRCS:.cpp=.o} 

NAME= mutant

%.o: %.cpp ${HEADERS}
	${CXX} ${CFLAGS} -c $< -o ${<:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CXX} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	rm -f ${OBJS}

fclean:
	rm -f ${OBJS}
	rm -f ${NAME}

re: fclean all