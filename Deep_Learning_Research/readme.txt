The project code is here:
In /Parallel_Vision_Research/Deep_Learning_Research/mini_proj4/main.py

The network does this:
-Train auto-encoder on MNIST with arch: 784-200-784
-Extract the encoder
-Add new layer to encoder with softmax classifier => arch: 784-200-10
-Train while holding W1,b1 constant.
-Train a new network with random parameters with architecture 784-200-10
-Test each of these networks and compare the network using the encoder with the network that didn't use a pre-trained first layer.

Still need to:
-Introduce sparsity constraint

Other I used to get to this point:
In /tensorflow/udemy/udemy_tf01.py linear regression is performed with tensorflow.
In /tensorflow/udemy/udemy_tf01.py linear PCA is performed with an auto-encoder.
