## A- SETUP

# To support both python 2 and python 3
from __future__ import division, print_function, unicode_literals

# Common imports
import tensorflow as tf
import numpy as np
import matplotlib
import matplotlib.pyplot as plt
import numpy.random as rnd
import os
import sys

# to make this notebook's output stable across runs
def reset_graph(seed=42):
    tf.reset_default_graph()
    tf.set_random_seed(seed)
    np.random.seed(seed)



def plot_image(image, shape=[28, 28]):
    plt.imshow(image.reshape(shape), cmap="Greys", interpolation="nearest")
    plt.axis("off")
    plt.show()
#===============================================================================
#===============================================================================
#===============================================================================
# Global
p = np.array([0.01,0.1,0.5,0.8])
alpha = 0.01
lambd= 0.0001
beta = 0

n_epochs = 4
batch_sizes = 150
from tensorflow.examples.tutorials.mnist import input_data
dataset = input_data.read_data_sets("/tmp/data/")
n_batches = dataset.train.num_examples // batch_sizes

n_labeled_instances = 1000
#n_batches = n_labeled_instances // batch_sizes
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
def sparsity_constraint(p, y):
    return tf.reduce_sum(KL(p, p_hat(y))) # Penalize neuron's too active
#===============================================================================
def tensor_board():
    writer = tf.summary.FileWriter("./output",sess.graph)
    writer.close()
#===============================================================================
def tensor_2_nparray(tensor):
    sess.run(tensor)
    return tensor.eval(sess)
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
    plt.matshow(mat)
    plt.show()
#===============================================================================
def reg(W, lambd, type):
    if type == 'L1':
        return (1 / lambd) * tf.reduce_sum(tf.abs(W))
    elif type == 'L2':
        return (1 / lambd) * tf.reduce_sum(tf.square(W))
#===============================================================================
def mse(Y, A):
    return tf.reduce_mean(tf.square(A - Y))
def mean(X):
    return tf.reduce_mean(tf.square(X))
#===============================================================================
def shape(X):
    print(type(X))
    return X.get_shape()
#===============================================================================
def init_encoder():

    n_inputs = 28 * 28
    n_A1 = 200

    X = tf.placeholder(tf.float32, shape=[None, n_inputs])

    weights1_init = initializer([n_inputs, n_A1])

    weights1 = tf.Variable(weights1_init, dtype=tf.float32, name="weights1")

    biases1 = tf.Variable(tf.zeros(n_A1), name="biases1")

    A1 = tf.nn.sigmoid(tf.matmul(X, weights1) + biases1)

    return X, weights1, biases1, A1
#===============================================================================
def init():

    n_inputs = 28 * 28
    n_A1 = 200
    n_outputs = n_inputs

    X, weights1, biases1, A1  = init_encoder()
    weights4_init = initializer([n_A1, n_outputs])
    weights4 = tf.Variable(weights4_init, dtype=tf.float32, name="weights4")
    biases4 = tf.Variable(tf.zeros(n_outputs), name="biases4")
    Y2 = tf.matmul(A1, weights4) + biases4

    return X, weights1, weights4, biases1, biases4, A1, Y2
#===============================================================================
def init2():

    n_inputs = 28 * 28
    n_A1 = 200
    n_outputs = 10


    activation = tf.nn.elu
    regularizer = tf.contrib.layers.l2_regularizer(lambd)
    initializer = tf.contrib.layers.variance_scaling_initializer()

    y = tf.placeholder(tf.int32, shape=[None])

    X, weights1, biases1, A1  = init_encoder()
    weights3_init = initializer([n_A1, n_outputs])
    weights3 = tf.Variable(weights3_init, dtype=tf.float32, name="weights3")
    biases3 = tf.Variable(tf.zeros(n_outputs), name="biases3")
    Z = tf.matmul(A1, weights3) + biases3

    return X, y, weights1, weights3, biases1, weights3, Z

#===============================================================================
# Train auto-encoder
tf.reset_default_graph()





activation = tf.nn.elu

initializer = tf.contrib.layers.variance_scaling_initializer()

X, weights1, weights4, biases1, biases4, A1, Y2 = init()


reconstruction_loss = tf.reduce_mean(tf.square(Y2 - X))


Y2 = Y2



decay = tf.contrib.layers.l2_regularizer(lambd)
loss = mse(Y2, X) + beta * sparsity_constraint(p[0], p_hat(A1)) + decay(weights1) + decay(weights4)

step = tf.train.AdamOptimizer(alpha).minimize(loss)



init = tf.global_variables_initializer()
saver = tf.train.Saver()




with tf.Session() as sess:
    init.run()
    for epoch in range(n_epochs):

        for iteration in range(n_batches):

            x, y = dataset.train.next_batch(batch_sizes)
            sess.run(step, feed_dict={X: x})
        print("\r{}".format(epoch), "Train MSE:", mse(X, Y2).eval(feed_dict={X: x}))
        saver.save(sess, "./params.ckpt")
    print("Test MSE:", reconstruction_loss.eval(feed_dict={X: dataset.test.images}))

    # Display weight matrix
    saver.restore(sess, "./params.ckpt")
    mosiac(tensor_2_nparray(weights1).T)

#===============================================================================
# F-Unsupervised pre-training
# Small neural net for  MNIST training
reset_graph()


# Get weights
X, Y, weights1, weights3, biases1, weights3, Z = init2()

cross_entropy = tf.nn.sparse_softmax_cross_entropy_with_logits(labels=Y, logits=Z)
loss = cross_entropy + decay(weights1) + decay(weights3)
optimizer = tf.train.AdamOptimizer(alpha)
training_op = optimizer.minimize(loss)


accuracy = mean(tf.cast(tf.nn.in_top_k(Z, Y, 1), tf.float32))


init = tf.global_variables_initializer()
pretrain_saver = tf.train.Saver([weights1, biases1])
saver = tf.train.Saver()

## Regular training (without pre-training):

print('n_batches = '+str(n_batches))
print('n_batches = '+str(n_batches))
print('n_batches = '+str(n_batches))
print('n_batches = '+str(n_batches))
print('n_batches = '+str(n_batches))

with tf.Session() as sess:
    init.run()
    for epoch in range(n_epochs):
        for iteration in range(n_batches):
            print("\r{}%".format(100 * iteration // n_batches), end="")
            sys.stdout.flush()
            indices = rnd.permutation(1000)[:batch_sizes]
            x, y_batch = dataset.train.images[indices], dataset.train.labels[indices]
            sess.run(training_op, feed_dict={X: x, Y: y_batch})
        accuracy_val = accuracy.eval(feed_dict={X: x, Y: y_batch})
        print("\r{}".format(epoch), "Train accuracy:", accuracy_val, end=" ")
        accuracy_val = accuracy.eval(feed_dict={X: dataset.test.images, Y: dataset.test.labels})
        print("Regular training (without pre-training):")
        print("Test accuracy:", accuracy_val)

# Now, reusing the first two layers of the auto-encoder we pretrained:
with tf.Session() as sess:
    init.run()
    pretrain_saver.restore(sess, "./params.ckpt")
    for epoch in range(n_epochs):
        for iteration in range(n_batches):
            print("\r{}%".format(100 * iteration // n_batches), end="")
            sys.stdout.flush()
            indices = rnd.permutation(n_labeled_instances)[:batch_sizes]
            x, y_batch = dataset.train.images[indices], dataset.train.labels[indices]
            sess.run(training_op, feed_dict={X: x, Y: y_batch})
        accuracy_val = accuracy.eval(feed_dict={X: x, Y: y_batch})
        print("\r{}".format(epoch), "Train accuracy:", accuracy_val, end="\t")

        accuracy_val = accuracy.eval(feed_dict={X: dataset.test.images, Y: dataset.test.labels})
        print("Reusing the first two layers of auto-encoder:")
        print("Test accuracy:", accuracy_val)
