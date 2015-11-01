objects = main.out

all: $(objects)
	nvcc -arch=sm_20 $(objects) -o app

%.out: %.cpp
	nvcc -x cu -arch=sm_20 -I. -dc $< -o $@

clean:
	rm -f *.out app
