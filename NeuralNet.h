#include "Neuron.h"

class NeuralNet {
private:
  int numInputs;
  int numOutputs;
  int numHiddenLayers;
  int numNeuronsPerLayer;

  std::vector<Layer> layers;

public:
  NeuralNet(int inputs,
            int outputs,
            int hiddenLayers,
            int neuronsPerLayer);

  std::vector<double> getWeights() const;

  // Compute the outputs from a given set of inputs.
  std::vector<double> update(std::vector<double> &inputs,
                             const double bias,
                             const double responseThreshold);

  // Sigmoid response function.
  inline double sigmoid(double activation, double threshold);
};

