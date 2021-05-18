compiler = gcc
outfileName = out

build:
	$(compiler) src/*.c -o $(outfileName) -lraylib -lm
run:
	./$(outfileName)
start:
	make build
	make run