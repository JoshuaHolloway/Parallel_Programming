from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

import argparse
import sys

from tensorflow.examples.tutorials.mnist import input_data

import tensorflow as tf

FLAGS = None
#===============================================================================
def main(_):
  # Import data
  mnist = input_data.read_data_sets(FLAGS.data_dir, one_hot=True)

  # Create the model
  x = tf.placeholder(tf.float32, [None, 784])

  # Auto-encoder network architecture:
  # 784 -> 200 -> 784

  # After training use encoder in a classification scheme
  # by adding a softmax layer:
  # 784 -> 200 -> 10

  # Layer 1:
  W1 = tf.Variable(tf.zeros([784, 200]))
  b1 = tf.Variable(tf.zeros([200]))
  y1 = tf.matmul(x, W1) + b1

  # Layer 2:
  W2 = tf.Variable(tf.zeros([200, 784]))
  b2 = tf.Variable(tf.zeros([784]))
  y = tf.matmul(y1, W2) + b2

  # Layer 3: to be added to autoencoder
  W3 = tf.Variable(tf.zeros([200, 10]))
  b3 = tf.Variable(tf.zeros([10]))
  y3 = tf.matmul(y1, W3) + b3

  # Loss:
  mse = tf.reduce_mean(tf.square(y - x))
  # drop a softmax here for y3 vs. y_

  # Specify how one step of training looks with specified loss function
  # Under the hood: add new op to computational graph including
  # -ops to compute grads
  # -ops to compute parameter update steps
  # -ops to apply update steps to the parameters
  #train_step = tf.train.GradientDescentOptimizer(0.5).minimize(cross_entropy)
  train_step = tf.train.GradientDescentOptimizer(0.5).minimize(mse)
  # train_step3 for classifier network

  # Build session:
  sess = tf.InteractiveSession()

  # Initialize variables
  tf.global_variables_initializer().run()

  # REPEAT THIS LOOP AFTER LEARNED ENCODER
  # Train the net
  for _ in range(1000):

    # Grab batch
    batch_xs, batch_ys = mnist.train.next_batch(100)

    # Execute y = Wx + b
    #sess.run(train_step, feed_dict={x: batch_xs, y_: batch_ys})
    sess.run(train_step, feed_dict={x: batch_xs}) # should not need the labels
    # The error is zero. Either the network is not working or it did lossles compression

  # Test trained model
  #correct_prediction = tf.equal(tf.argmax(y, 1), tf.argmax(X, 1))
  correct_prediction = tf.reduce_mean(tf.square(y - x))


  # Cast to float and sum them
  accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32))

  # Evaluate accuracy on test set
  print(sess.run(accuracy, feed_dict={x: mnist.test.images}))
  print('done training autoencoder')
  print('beginning to train classifier with learned encoder')


  #Extract the encoder
  #Add new layer to encoder with softmax classifier => arch: 784-200-10
  #Train while holding W1,b1 constant.
  tf.stop_gradient(W1)
  tf.stop_gradient(b1)
  print('W1.shape =' + str(W1.shape))


if __name__ == '__main__':
  parser = argparse.ArgumentParser()
  parser.add_argument('--data_dir', type=str, default='/tmp/tensorflow/mnist/input_data',
                      help='Directory for storing input data')
  FLAGS, unparsed = parser.parse_known_args()
tf.app.run(main=main, argv=[sys.argv[0]] + unparsed)
