#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

class Neuron {
private:
  int numInputs;
  std::vector<double>* weights;

public:
  Neuron() {}

  Neuron(int inputs) {
    numInputs = inputs;
    weights = new std::vector<double>(numInputs);

    // Setup weights with an initial random value between -1 and 1. There is
    // one weight for each input and an additional bias weight.
    for (int i = 0; i < numInputs; i++) {
      (*weights)[i] = ((double)rand() / (double)RAND_MAX) * 2 - 1;
    }
  }

  ~Neuron() {
    delete weights;
  }

  // Get the number of inputs to this neuron.
  int getInputs() const {
    return numInputs;
  }

  // Get the corresponding weight.
  double getWeight(int n) const {
    return (*weights)[n];
  }

  double printWeights() {
    for (int i = 0; i < numInputs; i++) {
      std::cout << (*weights)[i] << " ";
    }
    std::cout << "\n";
  }
};

class Layer {
private:
  int numNeurons;
  std::vector<Neuron*>* neurons;

public:
  Layer() {}

  // Create the vector of neurons for this layer.
  Layer(int neuronCount, int inputsPerNeuron) {
    numNeurons = neuronCount;
    neurons = new std::vector<Neuron*>(numNeurons);

    for (int i = 0; i < neuronCount; i++) {
      (*neurons)[i] = new Neuron(inputsPerNeuron);
    }
  }

  ~Layer() {
    for (int i = 0; i < neurons->size(); i++) {
      delete (*neurons)[i];
    }
    delete neurons;
  }

  // Get the number of neurons in this layer.
  int neuronCount() const {
    return numNeurons;
  }

  // Get the neuron at the given position.
  Neuron *getNeuron(int n) const {
    return (*neurons)[n];
  }

  void printNeurons() {
    for (int i = 0; i < numNeurons; i++) {
      std::cout << "Neuron #" << i << "\n";
      (*neurons)[i]->printWeights();
    }
    std::cout << "\n\n";
  }
};
