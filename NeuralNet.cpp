#include <cmath>

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

  // Initialize each hidden layer.
  for (int i = 0; i < numHiddenLayers; i++) {
    Layer l(neuronsPerLayer, inputs);
    layers.push_back(l);
  }
}

// Compute the outputs from a given set of inputs.
vector<double> NeuralNet::update(vector<double> &inputs,
                                 const double bias,
                                 const double responseThreshold) {
  vector<double> outputs;

  for (int i = 0; i < numHiddenLayers + 1; i++) {
    // We implement back-propagation by recursively updating the inputs and
    // computing the outputs at the current layer in turn.
    if (i != 0) {
      inputs = outputs;
    }

    outputs.clear();

    // Compute the weighted input for each neuron and pass to the sigmoid
    // function to get the output.
    for (int j = 0; j < layers[i].neuronCount(); j++) {
      double sum = 0;
      Neuron n = layers[i].getNeuron(j);
      for (int k = 0; k < n.getInputs() - 1; k++) {
        sum += inputs[k] * n.getWeight(k);
      }

      // Add in the bias weight.
      sum += n.getWeight(n.getInputs() - 1) * bias;

      outputs.push_back(sigmoid(sum, responseThreshold));
    }
  }

  return outputs;
}

// Compute the sigmoid function.
inline double NeuralNet::sigmoid(double activation,
                                 double threshold) {
  return 1.0 / (1.0 + exp(-activation / threshold));
}



