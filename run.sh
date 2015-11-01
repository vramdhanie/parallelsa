echo "Compiling sa.cu..."
nvcc -x cu -arch=sm_20 -I. -dc sa.cu
echo "Compiling main.cpp..."
nvcc -x cu -arch=sm_20 -I. -dc main.cpp
echo "linking..."
nvcc -arch=sm_20 main.o sa.o -o app
echo "Running..."
./app
