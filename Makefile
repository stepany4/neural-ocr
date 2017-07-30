CC = g++
CLAGS = -Wall
INCLUDE = -I/usr/include/opencv
LDFLAGS = $(INCLUDE) \
-I/usr/include/opencv /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so -lopencv_calib3d /usr/lib/x86_64-linux-gnu/libopencv_contrib.so -lopencv_contrib /usr/lib/x86_64-linux-gnu/libopencv_core.so -lopencv_core /usr/lib/x86_64-linux-gnu/libopencv_features2d.so -lopencv_features2d /usr/lib/x86_64-linux-gnu/libopencv_flann.so -lopencv_flann /usr/lib/x86_64-linux-gnu/libopencv_gpu.so -lopencv_gpu /usr/lib/x86_64-linux-gnu/libopencv_highgui.so -lopencv_highgui /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so -lopencv_imgproc /usr/lib/x86_64-linux-gnu/libopencv_legacy.so -lopencv_legacy /usr/lib/x86_64-linux-gnu/libopencv_ml.so -lopencv_ml /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so -lopencv_objdetect /usr/lib/x86_64-linux-gnu/libopencv_ocl.so -lopencv_ocl /usr/lib/x86_64-linux-gnu/libopencv_photo.so -lopencv_photo /usr/lib/x86_64-linux-gnu/libopencv_stitching.so -lopencv_stitching /usr/lib/x86_64-linux-gnu/libopencv_superres.so -lopencv_superres /usr/lib/x86_64-linux-gnu/libopencv_ts.so -lopencv_ts /usr/lib/x86_64-linux-gnu/libopencv_video.so -lopencv_video /usr/lib/x86_64-linux-gnu/libopencv_videostab.so -lopencv_videostab 
ALL = neural

all: $(ALL)

neural: main.o NeuralNet.o ImageData.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o neural main.o NeuralNet.o ImageData.o

main.o: main.cpp
	$(CC) $(CFLAGS) -Wno-write-strings $(INCLUDE) -c main.cpp

NeuralNet.o: Neuron.h Layer.h NeuralNet.cpp NeuralNet.h
	$(CC) $(CFLAGS) -c Neuron.h NeuralNet.cpp

ImageData.o: ImageData.cpp ImageData.h
	$(CC) $(CFLAGS) $(INCLUDE) -c ImageData.cpp

.PHONY: clean

clean:
	rm -rf *.o *.gch $(ALL)
