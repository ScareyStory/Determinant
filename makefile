CXX = g++
CXXFLAGS = -std=c++0x -Wall -pedantic-errors -g

SRCS = matrixMain.cpp readMatrix.cpp determinant.cpp
OBJS = ${SRCS: .cpp = .o}
HEADERS = readMatrix.hpp determinant.hpp

MAIN = matrix

all: ${MAIN}
	@echo sucessfully compiled!

${MAIN}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${MAIN}

.cpp.o:
	${CXX} ${CXXFLAGS} -c $< -o $@

clean:
	${RM} ${PROGS} ${OBJS} *.0 *~.
