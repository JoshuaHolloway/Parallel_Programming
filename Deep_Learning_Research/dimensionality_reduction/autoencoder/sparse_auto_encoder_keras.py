from keras.layers import Input, Dense
from keras.models import Model
from keras import regularizers

## Single fc-layer as encoder and decoder

encoding_dim = 32

input_img = Input(shape=(784,))

# add a Dense layer with a L1 activity regularizer
encoded = Dense(encoding_dim, activation='relu',
                activity_regularizer=regularizers.l1(10e-5))(input_img)

decoded = Dense(784, activation='sigmoid')(encoded)

autoencoder = Model(input_img, decoded)

## Decoder model
# create a placeholder for an encoded (32-D) input
encoded_input = Input(shape=(encoding_dim,))

# retrieve the last layer of the autoencoder model
decoder_layer = autoencoder.layers[-1]

# create the decoder model
decoder = Model(encoded_input, decoder_layer(encoded_input))

# Configure model to use a per-pixel binary cross-entropy loss, and the Adadelta optimizer
autoencoder.compile(optimizer='adadelta', loss='binary_crossentropy')


# Prepare input data (MNIST without labels)
from keras.datasets import mnist
import numpy as np
(x_train, _), (x_test, _) = mnist.load_data()

# x_train is 60k x 28 x 28
# x_test is 10k x 28 x 28



# Normalize all values between 0 and 1 and flatten the 28x28 image into 784-D vectors
x_train = x_train.astype('float32') / 255.
x_test = x_test.astype('float32') / 255.
x_train = x_train.reshape((len(x_train), np.prod(x_train.shape[1:])))
x_test = x_test.reshape((len(x_test), np.prod(x_test.shape[1:])))
print('x_train.shape = '+ str(x_train.shape))
print('x_test.shape = ' + str(x_test.shape))

# Train autoencoder for 50 epochs
autoencoder.fit(x_train, x_train,
                epochs=100, # Increased epochs to 100 from the non-sparse version
                batch_size=256,
                shuffle=True,
                validation_data=(x_test, x_test))

## After 50 epochs, the autoencoder seems to reach a stable train/test loss value of about 0.11
# We can try to visualize the reconstructed inputs and the encoded representations.
# Encode and decode some digits.
# note Nthat we take them from the *test* set.
encoded_imgs = encoder.predict(x_test)
decoded_imgs = decoder.predict(encoded_imgs)

# use Matplotlib (don't ask)
import matplotlib.pyplot as plt

n = 10  # how many digits we will display
plt.figure(figsize=(20, 4))
for i in range(n):
    # display original
    ax = plt.subplot(2, n, i + 1)
    plt.imshow(x_test[i].reshape(28, 28))
    plt.gray()
    ax.get_xaxis().set_visible(False)
    ax.get_yaxis().set_visible(False)

    # display reconstruction
    ax = plt.subplot(2, n, i + 1 + n)
    plt.imshow(decoded_imgs[i].reshape(28, 28))
    plt.gray()
    ax.get_xaxis().set_visible(False)
    ax.get_yaxis().set_visible(False)
plt.show()
