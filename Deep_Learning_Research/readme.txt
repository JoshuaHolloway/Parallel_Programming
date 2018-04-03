In /tensorflow/udemy/udemy_tf01.py linear regression is performed with tensorflow.
In /tensorflow/udemy/udemy_tf01.py linear PCA is performed with an auto-encoder.

Note: The fully_connected tf function makes it difficult to access the paramaters
to use custom loss function with regularization with frobenius norms. I created
a function that replaces the fully_connected function with a standard matrix multiply,
but it only works on the first layer.


Need to fix this second layer, then:
-Introduce sparsity parameter
-Train on MNIST with arch: 784-200-784
-Extract the encoder
-Add new layer to encoder with softmax classifier => arch: 784-200-10
-Train while holding W1,b1 constant.
-Train a new network with random parameters with architecture 784-200-10
-Test each of these networks and compare the network using the encoder with the network that didn't use a pre-trained first layer.

Shoule use the MNIST code and mod it to an auto-encoder
