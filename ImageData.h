#include <cv.h>
#include <highgui.h>

class ImageData {
private:
  // Indicates whether there was an error reading the file.
  bool readError;

  // The path to the file that is being read.
  char *filename;

  // The image object as stored by OpenCV.
  IplImage *img;

  // The width, height, and array of pixels of the image.
  int width, height;
  float* pixels;

public:
  // Normalized width and height constants.
  static const int NORMALIZED_WIDTH = 30;
  static const int NORMALIZED_HEIGHT = 30;

  // Read the image file and store its data, after converting the image to
  // binary and normalizing it for size.
  ImageData(char *file);

  // Free the image object.
  ~ImageData();

  // Get the pixel corresponding to position (x,y).
  float pixel(int x, int y) const;

  // Get the width and height of the image.
  int getWidth() const;
  int getHeight() const;

  // Render a brief summary of the image object.
  void summary(char *buffer) const;
  bool error() const;
};
