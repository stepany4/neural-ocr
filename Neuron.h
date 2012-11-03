#include <cstdlib>
#include <ctime>
#include <vector>

class Neuron {
private:
  int numInputs;
  std::vector<double> weights;

public:
  Neuron(int inputs) {
    numInputs = inputs;

    // Setup weights with an initial random value between -1 and 1. There is
    // one weight for each input and an additional bias weight.
    srand(time(NULL));
    for (int i = 0; i < numInputs; i++) {
      weights.push_back(rand() % 2 - 1);
    }
  }

  // Get the number of inputs to this neuron.
  int getInputs() const {
    return numInputs;
  }

  // Get the corresponding weight.
  int getWeight(int n) const {
    return weights[n];
  }
};

class Layer {
private:
  int numNeurons;
  std::vector<Neuron> neurons;

public:
  // Create the vector of neurons for this layer.
  Layer(int neuronCount, int inputsPerNeuron) {
    numNeurons = neuronCount;
    for (int i = 0; i < neuronCount; i++) {
      Neuron n(inputsPerNeuron);
      neurons.push_back(n);
    }
  }

  // Get the number of neurons in this layer.
  int neuronCount() const {
    return numNeurons;
  }

  // Get the neuron at the given position.
  Neuron getNeuron(int n) const {
    return neurons[n];
  }
};

