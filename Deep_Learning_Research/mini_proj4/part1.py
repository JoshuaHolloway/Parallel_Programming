## A- SETUP

# To support both python 2 and python 3
from __future__ import division, print_function, unicode_literals

# Common imports
import tensorflow as tf
import numpy as np
import numpy.random as rnd
import matplotlib.pyplot as plt
import os
import sys

# to make this notebook's output stable across runs
def reset_graph(seed=42):
    tf.reset_default_graph()
    tf.set_random_seed(seed)
    np.random.seed(seed)

# To plot pretty figures
#import matplotlib
#import matplotlib.pyplot as plt
plt.rcParams['axes.labelsize'] = 14
plt.rcParams['xtick.labelsize'] = 12
plt.rcParams['ytick.labelsize'] = 12

# Datset
from tensorflow.examples.tutorials.mnist import input_data
mnist = input_data.read_data_sets("/tmp/data/")
#===============================================================================
#=JOSH==========================================================================
#===============================================================================
def layer(input, num_inputs, num_neurons, activation):
    initializer = tf.variance_scaling_initializer()
    W = tf.Variable(initializer([num_inputs, num_neurons])) # Num Inputs x Num Neurons
    b = tf.Variable(tf.zeros([num_neurons]))
    Z = tf.matmul(input, W) + b
    if activation == 'sigmoid':
        A = tf.nn.sigmoid(Z)
        return A, Z, W, b
    elif activation == 'relu':
        A = tf.nn.relu(Z)
        return A, Z, W, b
    elif activation == 'tanh':
        A = tf.nn.tanh(Z)
        return A, Z, W, b
    elif activation == 'linear':
        return Z, W, b
#===============================================================================
def tensor_2_nparray(tensor):
    sess.run(tensor)
    return tensor.eval(sess)
#===============================================================================
def shape(X):
    print(type(X))
    return X.get_shape()
#===============================================================================
def mosiac(array):
    # Convert the rows of array into matrices of dimension sqrt(cols)xsqrt(cols)
    print('Inside mosiac()')
    print('array.shape[0] = ' + str(array.shape[0]))
    print('array.shape[1] = ' + str(array.shape[1]))
    square = int(np.sqrt(array.shape[1]))
    row_elems = 10
    col_elems = row_elems
    mat = np.zeros([row_elems * square, col_elems * square])
    for i in range(row_elems):
        for j in range(col_elems):
            lower_i = i*square
            upper_i = i*square+square
            lower_j = j*square
            upper_j = j*square+square
            mat[lower_i : upper_i, lower_j : upper_j] = array[i*row_elems+j,:].reshape(square,square)
    plt.imshow(mat, cmap='gray')
    plt.show()
#===============================================================================
def KL(p, q):
    # KL-Divergence between PMF's P and Q
    # p is scalar
    # q is
    return p * tf.log(p/q) + (1-p) * tf.log((1-p) / (1-q))
#===============================================================================
def p_hat(a):
    # Averate activation of each neuron in encoder for all M examples
    # Input is [? x 200]
    # Output is (200,)
    return tf.reduce_mean(a, axis=0) # Sum across rows - each row is an example
#===============================================================================
def MSE(Y, A):
    return tf.reduce_mean(tf.square(A - Y))
#===============================================================================
def sparsity_constraint(p, p_hat):
    return tf.reduce_sum(KL(p, p_hat)) # Penalize neuron's too active
#===============================================================================
#===============================================================================
#===============================================================================
#A couple utility functions to plot grayscale 28x28 image:
def save_fig(fig_id, tight_layout=True):

    str1 = '/home/josh/Desktop/Parallel_Vision_Research/Deep_Learning_Research/mini_proj4'
    path = os.path.join(str1, fig_id + ".png")

    print(path)
    print(type(path))
    print("Saving figure", fig_id)
    if tight_layout:
        plt.tight_layout()
    plt.savefig(path, format='png', dpi=300)
    plt.show()
#===============================================================================
def itterate_over_examples(dataset, step, loss):
    for iteration in range(n_batches):
        x, y = dataset
        sess.run(step, feed_dict={X: x})
    sess.run(loss, feed_dict={X: x})
    saver.save(sess, "./my_model_sparse.ckpt")
#===============================================================================
#===============================================================================
# G-Sparse Autoencoder
reset_graph()

alpha = 0.01
p = np.array([0.01,0.1,0.5,0.8])
beta = 0.001

X = tf.placeholder(tf.float32, shape=[None, 784])

# REPLACED:
A1, Z1, W1, b1 = layer(input=X,  num_inputs=784, num_neurons=200, activation='sigmoid') #Layer 1-encoder
A2, W2, b2 = layer(input=A1, num_inputs=200, num_neurons=784, activation='linear') #Layer 2-decoder

## Replacing:@
## Replacing:@
## Replacing:@
loss = MSE(A2, X) + beta * sparsity_constraint(p[3], p_hat(A1))
step = tf.train.AdamOptimizer(alpha).minimize(loss)
init = tf.global_variables_initializer()
saver = tf.train.Saver()

n_epochs = 20
batch_size = 1000


tensor = np.zeros([7840,7840,n_epochs])
with tf.Session() as sess:
    init.run()
    for epoch in range(n_epochs):

        # Itterate over batches
        n_batches = mnist.train.num_examples // batch_size

        # Itterate over examples in each batch
        itterate_over_examples(mnist.train.next_batch(batch_size), step, loss)
        #for iteration in range(n_batches):
    #        #print("\r{}%".format(100 * iteration // n_batches), end="")
    #        #sys.stdout.flush()
    #        X_batch, y_batch = mnist.train.next_batch(batch_size)
    #        sess.run(step, feed_dict={X: X_batch})
        #reconstruction_loss_val, sparsity_loss_val, loss_val = sess.run([reconstruction_loss, sparsity_loss, loss], feed_dict={X: X_batch})
        #print("\r{}".format(epoch), "Train MSE:", reconstruction_loss_val, "\tSparsity loss:", sparsity_loss_val, "\tTotal loss:", loss_val)
        #saver.save(sess, "./my_model_sparse.ckpt")

        # JOSH - Drop in function to display the weights
        # Draw the mosiac of encoder weights
        w1 = tensor_2_nparray(W1)
        print('w1.shape = ' + str(w1.shape))

        # print the mosiac every epoch -Store to array!
        #mosiac(tensor_2_nparray(W1).T)



        # INSTEAD OF SAVING HERE SIMPLY PLOT FROM THIS LOCATION.

#show_reconstructed_digits(X, A2, "./my_model_sparse.ckpt")
#===============================================================================
# D-Visualizing the reconstruction
n_test_digits = 2
X_test = mnist.test.images[:n_test_digits]

with tf.Session() as sess:
    saver.restore(sess, "./my_model_sparse.ckpt") # not shown in the book
    outputs_val = A2.eval(feed_dict={X: X_test})

def plot_image(image, shape=[28, 28]):
    plt.imshow(image.reshape(shape), cmap="Greys", interpolation="nearest")
    plt.axis("off")

for digit_index in range(n_test_digits):
    plt.subplot(n_test_digits, 2, digit_index * 2 + 1)
    plot_image(X_test[digit_index])
    plt.subplot(n_test_digits, 2, digit_index * 2 + 2)
    plot_image(outputs_val[digit_index])
    plt.show()
#===============================================================================
# E-Visualizing the extracted features
with tf.Session() as sess:
    saver.restore(sess, "./my_model_sparse.ckpt") # not shown in the book
    #weights1_val = W1.eval()
    w1 = tensor_2_nparray(W1)
    print('w1.shape = ' + str(w1.shape))

    #print('shape of W1:')
    #print(shape(W1))
    mosiac(tensor_2_nparray(W1).T)


for i in range(10):
    plt.subplot(1, 5, i + 1)
    plot_image(w1.T[i])

save_fig("extracted_features_plot") # not shown
plt.show()                          # not shown

# Move in cache code to properly pass data to part3.
