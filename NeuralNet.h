#include "Neuron.h"

class NeuralNet {
private:
  int numInputs;
  int numOutputs;
  int numHiddenLayers;
  int numNeuronsPerLayer;

  std::vector<Layer*>* layers;
  double* outputLayer;

public:
  NeuralNet(int inputs,
            int outputs,
            int hiddenLayers,
            int neuronsPerLayer);

  ~NeuralNet();

  double* getWeights() const;

  // Compute the outputs from a given set of inputs.
  void feedForward(std::vector<double>* inputs,
                   std::vector<double>* outputLayer,
                   const double bias,
                   const double responseThreshold);

  // Sigmoid response function.
  inline double sigmoid(double activation, double threshold);

  void print() {
    for (int i = 0; i < numHiddenLayers; i++) {
      std::cout << "Layer #" << i << "\n";
      (*layers)[i]->printNeurons();
    }
  }
};
