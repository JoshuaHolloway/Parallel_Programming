from __future__ import absolute_import
from __future__ import division
from __future__ import print_function
import argparse
import sys
from tensorflow.examples.tutorials.mnist import input_data
import tensorflow as tf
FLAGS = None
#===============================================================================
def layer(input, num_inputs, num_neurons):
  initializer = tf.variance_scaling_initializer()
  W = tf.Variable(initializer([num_inputs, num_neurons])) # Num Inputs x Num Neurons
  b = tf.Variable(tf.zeros([num_neurons]))

  layer_name = tf.matmul(input, W) + b
  return layer_name, W, b
#===============================================================================
def main(_):
  # Import data
  mnist = input_data.read_data_sets(FLAGS.data_dir, one_hot=True)

  # Create the model
  x = tf.placeholder(tf.float32, [None, 784])
  y1, W1, b1 = layer(input=x,  num_inputs=784, num_neurons=200) #Layer 1-encoder
  y, W2, b2 = layer(input=y1, num_inputs=200, num_neurons=10) #Layer 2-decoder

  # Define loss and optimizer
  y_ = tf.placeholder(tf.float32, [None, 10])

  # Use tf.nn.softmax_cross_entropy_with_logits on the raw outputs of 'y', and then average across the batch.
  cross_entropy = tf.reduce_mean( # specify comparing y_ and y
      tf.nn.softmax_cross_entropy_with_logits(labels=y_, logits=y))

  # Specify how one step of training looks with specified loss function
  # Under the hood: add new op to computational graph including
  # -ops to compute grads
  # -ops to compute parameter update steps
  # -ops to apply update steps to the parameters
  train_step = tf.train.GradientDescentOptimizer(0.5).minimize(cross_entropy)

  # Build session:
  sess = tf.InteractiveSession()

  # Initialize variables
  tf.global_variables_initializer().run()

  # Train the net
  for _ in range(1000):
    batch_xs, batch_ys = mnist.train.next_batch(100) # Grab batch
    sess.run(train_step, feed_dict={x: batch_xs, y_: batch_ys}) # Execute y = Wx + b

  correct_prediction = tf.equal(tf.argmax(y, 1), tf.argmax(y_, 1))# Test trained model
                                                                  # y  is computed label (Vector of probs from soft-max)
                                                                  # y_ is true label     (One-hot encoded)
                                                                  # correct_prediction is a set of bool's
  accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32)) # Cast to float and sum them
  print(sess.run(accuracy, feed_dict={x: mnist.test.images, y_: mnist.test.labels})) # Evaluate accuracy on test set
#===============================================================================
if __name__ == '__main__':
  parser = argparse.ArgumentParser()
  parser.add_argument('--data_dir', type=str, default='/tmp/tensorflow/mnist/input_data',
                      help='Directory for storing input data')
  FLAGS, unparsed = parser.parse_known_args()
#===============================================================================
tf.app.run(main=main, argv=[sys.argv[0]] + unparsed)
