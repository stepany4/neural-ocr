# Neural Network OCR

We propose the design, implementation, training, and evaluation of a feed-forward neural network adapted to the task of optical character recognition (OCR). We define a precise metric for measuring the success of such a network on real-world data. We experimentally measure the efficacy of the neural network under variation of certain parameters of its construction and seek to maximize a precise quantity expressing the success of the neural network versus the difficulty in constructing and training it.

## Authors
* Bryan Cuccioli (blc72@cornell.edu)
* Renato Amez (ra374@cornell.edu)

## Training

We define the success of the neural network as the square root of the number of correctly recognized characters, so as to more heavily weight improvements to the neural network once the network is already performing well, under the guise that e.g. 70% recognition is not particularly better than 40% recognition. Training of the network will be complete once this success parameter falls above a pre-determined threshold. For the purpose of experimentation, this threshold will be varied and the success of the network will be measured accordingly.

The network will be trained in handwritten digit-recognition with 10,000 images derived from <a href="http://cis.jhu.edu/~sachin/digit/digit.html">the MINST database</a> using a <a href="https://gist.github.com/4056614">simple script</a>.

## Evaluation

Evaluation of the neural network will be performed using data distinct from the training data. Samples rendered by computer and printed out as well as samples handwritten by multiple third parties will be used. We will evaluate the system varying parameters such as

* the training error threshold,
* the number of layers in the neural network,
* the size and variety of the training data.

For experimentation purposes, the success of the neural network in performing OCR will be measured as a function of each of these parameters separately. We will experimentally determine the values of these parameters that maximize the training efficiency, given as the ratio of the square of the success to the product of the above three paramters.

## Building

This program is built using the <a href="http://opencv.willowgarage.com/wiki/">OpenCV</a> library, which is compatible with Windows, OS X, and Linux.

If you are using Linux, you can install OpenCV via most package managers; for example, in Debian/Ubuntu:

    sudo apt-get install libopencv-dev

Or in OSX:

    sudo port install opencv

You may have to change the `INCLUDE` variable in the Makefile to point to the location in which the library is installed.

