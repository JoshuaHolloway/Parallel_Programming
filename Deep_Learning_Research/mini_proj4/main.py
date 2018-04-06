from __future__ import absolute_import
from __future__ import division
from __future__ import print_function
import argparse
import sys
from tensorflow.examples.tutorials.mnist import input_data
import tensorflow as tf
import numpy as np
import matplotlib.pyplot as plt
FLAGS = None
# Build session
sess = tf.InteractiveSession()
#===============================================================================
def layer1(input, num_inputs, num_neurons, activation):
    initializer = tf.variance_scaling_initializer()
    W = tf.Variable(initializer([num_inputs, num_neurons]),name='W1') # Num Inputs x Num Neurons
    b = tf.Variable(tf.zeros([num_neurons]),name='b1')
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
def layer2(input, num_inputs, num_neurons, activation):
    initializer = tf.variance_scaling_initializer()
    W = tf.Variable(initializer([num_inputs, num_neurons]),name='W2') # Num Inputs x Num Neurons
    b = tf.Variable(tf.zeros([num_neurons]),name='b2')
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
def leaky_relu(Z, beta):
    return tf.maximum(Z, beta * Z)
#===============================================================================
def mse(Y, A):
    return tf.reduce_mean(tf.square(A - Y))
#===============================================================================
def shape(X):
    print(type(X))
    return X.get_shape()
#===============================================================================
def main(_):
    # Import data
    mnist = input_data.read_data_sets(FLAGS.data_dir, one_hot=True)

    # Create the model
    x = tf.placeholder(tf.float32, [None, 784])
    y = tf.placeholder(tf.float32, [None, 10])

    #===========================================================================
    #===NETWORK 1=AUTO-ENCODER + CLASSIFIER 784-200-784=========================
    #===========================================================================

    # Network 1: Auto-Encoder: 784 -> 200 -> 784, Classifier: 784 -> 200 -> 10
    A1, Z1, W1, b1 = layer1(input=x,  num_inputs=784, num_neurons=200, activation='sigmoid') #Layer 1-encoder
    y2, W2, b2 = layer2(input=A1, num_inputs=200, num_neurons=784, activation='linear') #Layer 2-decoder

    # Dims:
    # y1 is ?x200 -> ? corresponds to M
    # x is ?x784
    # W1 is 784x200 => x * W1  is [?x784]*[784x200] = [?x200]

    p = np.array([0.01,0.1,0.5,0.8])
    beta = 3
    loss = mse(y2, x) + beta * sparsity_constraint(p[0], p_hat(A1)) # NEED TO ADD FROBENIUS NORM OF W1 and W2 sill

    alpha = 0.001
    var_list_1 = [W1,b1,W2,b2]
    step = tf.train.GradientDescentOptimizer(alpha).minimize(loss, var_list=var_list_1)

    #train_a = tf.train.GradientDescentOptimizer(0.1).minimize(loss_a, var_list=[A])
    #train_b = tf.train.GradientDescentOptimizer(0.1).minimize(loss_b, var_list=[B])

    ## Saver object
    #saver = tf.train.Saver()

    # Train the net - auto-encoder:
    tf.global_variables_initializer().run() # Initialize variables
    for _ in range(1000):
        batch_xs, batch_ys = mnist.train.next_batch(100)#Grab batch
        #mosiac(batch_xs)
        sess.run(step, feed_dict={x: batch_xs})#Execute y2 = W2 *(W1*x + b1) + b2

    ## Save graph and parameters
    #saver.save(sess,'my_test_model')

    # Test trained model
    correct_prediction = tf.reduce_mean(tf.square(y2 - x)) # change this for classification to: correct_prediction = tf.equal(tf.argmax(y, 1), tf.argmax(y_, 1))
    accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32)) # Cast to float and sum them
    print(sess.run(accuracy, feed_dict={x: mnist.test.images})) # Evaluate accuracy on test set

    #Extract the encoder
    #Add new layer to encoder with softmax classifier => arch: 784-200-10
    #Train while holding W1,b1 constant.
    tf.stop_gradient(W1)
    tf.stop_gradient(b1)

    # Draw the mosiac of encoder weights
    print('shape of A1 and W1:')
    print(shape(A1))
    print(shape(W1))
    mosiac(tensor_2_nparray(W1).T)

    #===========================================================================
    #===NETWORK 2=ENCODER + CLASSIFIER 784-200-10===============================
    #===========================================================================
    y2_softmax, W2_softmax, b2_softmax = layer2(input=A1, num_inputs=200, num_neurons=10, activation='linear') #Layer 2-classifier
    var_list_2 = [W2_softmax,b2_softmax]
    cross_entropy_net1 = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(labels=y, logits=y2_softmax))
    train_step_Xentropy_net1 = tf.train.GradientDescentOptimizer(0.5).minimize(cross_entropy_net1, var_list=var_list_2)

    # Train the net - classifier:
    tf.global_variables_initializer().run() # Initialize variables
    for _ in range(1000):
        batch_xs, batch_ys = mnist.train.next_batch(100)#Grab batch
        sess.run(train_step_Xentropy_net1, feed_dict={x: batch_xs, y: batch_ys})

    # Test trained model
    correct_prediction = tf.equal(tf.argmax(y2_softmax, 1), tf.argmax(y, 1))
    accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32)) # Cast to float and sum them

    # Evaluate accuracy on test set
    print(sess.run(accuracy, feed_dict={x: mnist.test.images,
                                      y: mnist.test.labels}))

    #===========================================================================
    #===NETWORK 3=FRESH CLASSIFIER 784-200-10===================================
    #===========================================================================
    # Create brand new network and train it:
    A1, y1, W1, b1 = layer1(input=x,  num_inputs=784, num_neurons=200, activation='sigmoid') #Layer 1-encoder
    y2_softmax, W2_softmax, b2_softmax = layer2(input=A1, num_inputs=200, num_neurons=10, activation='linear') #Layer 2-classifier
    cross_entropy_net1 = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(labels=y, logits=y2_softmax))
    train_step_Xentropy_net1 = tf.train.GradientDescentOptimizer(0.5).minimize(cross_entropy_net1)

    # Train the net - classifier:
    tf.global_variables_initializer().run() # Initialize variables
    for _ in range(1000):
        batch_xs, batch_ys = mnist.train.next_batch(100)#Grab batch
        sess.run(train_step_Xentropy_net1, feed_dict={x: batch_xs, y: batch_ys})

    # Test trained model
    correct_prediction = tf.equal(tf.argmax(y2_softmax, 1), tf.argmax(y, 1))
    accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32)) # Cast to float and sum them

    # Evaluate accuracy on test set
    print(sess.run(accuracy, feed_dict={x: mnist.test.images,
                                      y: mnist.test.labels}))
#===============================================================================
if __name__ == '__main__':
  parser = argparse.ArgumentParser()
  parser.add_argument('--data_dir', type=str, default='/tmp/tensorflow/mnist/input_data',
                      help='Directory for storing input data')
  FLAGS, unparsed = parser.parse_known_args()
  tf.app.run(main=main, argv=[sys.argv[0]] + unparsed)
