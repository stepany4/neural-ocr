#include <cmath>
#include <cstdio>
#include <iostream>

#include "NeuralNet.h"

using namespace std;

// Initialize the neural network with the given input parameters, in turn
// initializing each layer with neurons of random weight.
NeuralNet::NeuralNet(int inputs,
                     int outputs,
                     int hiddenLayers,
                     int neuronsPerLayer) {
  numInputs = inputs;
  numOutputs = outputs;
  numHiddenLayers = hiddenLayers;
  numNeuronsPerLayer = neuronsPerLayer;
  layers = new vector<Layer*>(hiddenLayers);

  // Initialize each hidden layer.
  for (int i = 0; i < numHiddenLayers; i++) {
    // The first hidden layer has the input set as inputs, whereas
    // subsequent hidden layers have hidden layers as inputs.
    int layerInputs;
    if (i == 0) {
      layerInputs = inputs;
    } else {
      layerInputs = neuronsPerLayer;
    }
    (*layers)[i] = new Layer(neuronsPerLayer, layerInputs);
  }
}

NeuralNet::~NeuralNet() {
  for (int i = 0; i < layers->size(); i++) {
    delete (*layers)[i];
  }
  delete layers;
}

// Compute the outputs from a given set of inputs.
void NeuralNet::feedForward(vector<double>* inputs,
                            vector<double>* outputLayer,
                            const double bias,
                            const double responseThreshold) {
  vector<double>* outputs;

  for (int i = 0; i < numHiddenLayers; i++) {
    // We recursively update the inputs and compute the outputs at the
    // current layer in turn.

    outputs = new vector<double>((*layers)[i]->neuronCount());

    // Compute the weighted input for each neuron and pass to the sigmoid
    // function to get the output.
    for (int j = 0; j < (*layers)[i]->neuronCount(); j++) {
      double sum = 0;
      Neuron *n = (*layers)[i]->getNeuron(j);

      for (int k = 0; k < n->getInputs() - 1; k++) {
        sum += (*inputs)[k] * n->getWeight(k);
      }

      // Add in the bias weight.
      sum += n->getWeight(n->getInputs() - 1) * bias;

      (*outputs)[j] = sigmoid(sum, responseThreshold);
    }

    delete inputs;
    inputs = outputs;
  }

  for (int i = 0; i < numOutputs; i++) {
    (*outputLayer)[i] = (*outputs)[i];
  }
  delete outputs;
}

// Compute the sigmoid function.
inline double NeuralNet::sigmoid(double activation,
                                 double threshold) {
  return 1.0 / (1.0 + exp(-activation / threshold));
}
