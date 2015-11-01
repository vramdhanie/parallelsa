objects = main.o sa.o

all: $(objects)
	nvcc -arch=sm_20 $(objects) -o app

main.o: main.cpp
	nvcc -x cu -arch=sm_20 -I. -dc $< -o $@

sa.o: sa.cu
	nvcc -x cu -arch=sm_20 -I. -dc $< -o $@

clean:
	rm -f *.o app
