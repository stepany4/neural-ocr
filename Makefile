CC = g++
CLAGS = -Wall --disable-precomp-headers
INCLUDE = -I/usr/local/include/opencv
LDFLAGS = $(INCLUDE) -L/usr/local/lib \
          -lopencv_core -lopencv_highgui -lopencv_imgproc
ALL = neural

all: $(ALL)

neural: main.o NeuralNet.o ImageData.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o neural main.o NeuralNet.o ImageData.o

main.o: main.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c main.cpp

NeuralNet.o: Neuron.h NeuralNet.cpp NeuralNet.h
	$(CC) $(CFLAGS) -c Neuron.h NeuralNet.cpp

ImageData.o: ImageData.cpp ImageData.h
	$(CC) $(CFLAGS) $(INCLUDE) -c ImageData.cpp

.PHONY: clean

clean:
	rm -rf *.o *.gch $(ALL)
