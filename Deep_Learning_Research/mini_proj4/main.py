from __future__ import absolute_import
from __future__ import division
from __future__ import print_function
import argparse
import sys
from tensorflow.examples.tutorials.mnist import input_data
import tensorflow as tf
FLAGS = None
sess = tf.InteractiveSession() # Build session
#===============================================================================
def layer(input, num_inputs, num_neurons):
  initializer = tf.variance_scaling_initializer()
  W = tf.Variable(initializer([num_inputs, num_neurons])) # Num Inputs x Num Neurons
  b = tf.Variable(tf.zeros([num_neurons]))
  layer_name = tf.matmul(input, W) + b
  return layer_name, W, b
#===============================================================================
def arch(type, input, labels):
  if type == 'autoencoder' or type == 'classifier-1':
    y1, W1, b1 = layer(input=input,  num_inputs=784, num_neurons=200) #Layer 1-encoder
    if type == 'autoencoder':
      y2, W2, b2 = layer(input=y1, num_inputs=200, num_neurons=784) #Layer 2-decoder
      mse_net1 = tf.reduce_mean(tf.square(y2 - input))
      return y2, W1, b1, mse_net1
    elif type == 'classifier-1':
      y2_softmax, W2_softmax, b2_softmax = layer(input=y1, num_inputs=200, num_neurons=10) #Layer 2-classifier
      #cross_entropy_net1 = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(labels=y, logits=y2_softmax))
      return y2_softmax
  elif type == 'classifier-2':
    yy1, WW1, bb1 = layer(input=input,  num_inputs=784, num_neurons=200) #Layer 1
    yy2_softmax, WW2_softmax, bb2_softmax = layer(input=yy1, num_inputs=200, num_neurons=10) #Layer 2
    return yy2_softmax
#===============================================================================
def main(_):
  # Import data
  mnist = input_data.read_data_sets(FLAGS.data_dir, one_hot=True)

  # Create the model
  x = tf.placeholder(tf.float32, [None, 784])
  y = tf.placeholder(tf.float32, [None, 10])

  # Define architecture
  y2, W1, b1, mse_net1  = arch(type='autoencoder', input=x, labels=x)   #Net-1: Autoencoder: 784->200->784
  y2_softmax = arch(type='classifier-1',  input=x, labels=y)  #Net-1: Classifier:  784->200->10
  yy2_softmax = arch(type='classifier-2', input=x, labels=y) #Net-2: 784->200->10

  # Loss:
  #mse_net1 = tf.reduce_mean(tf.square(y2 - x))
  cross_entropy_net1 = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(labels=y, logits=y2_softmax))
  cross_entropy_net2 = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(labels=y, logits=yy2_softmax))

  train_step__MSE_net1 = tf.train.GradientDescentOptimizer(0.5).minimize(mse_net1)
  train_step_Xentropy_net1 = tf.train.GradientDescentOptimizer(0.5).minimize(cross_entropy_net1)
  train_step_Xentropy_net2 = tf.train.GradientDescentOptimizer(0.5).minimize(cross_entropy_net2)

  # Train the net - auto-encoder:
  tf.global_variables_initializer().run() # Initialize variables
  for _ in range(1000):
    batch_xs, batch_ys = mnist.train.next_batch(100)#Grab batch
    sess.run(train_step__MSE_net1, feed_dict={x: batch_xs})#Execute y2 = W2 *(W1*x + b1) + b2

  # Test trained model
  correct_prediction = tf.reduce_mean(tf.square(y2 - x)) # change this for classification to: correct_prediction = tf.equal(tf.argmax(y, 1), tf.argmax(y_, 1))
  accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32)) # Cast to float and sum them
  print(sess.run(accuracy, feed_dict={x: mnist.test.images})) # Evaluate accuracy on test set

  print('done training autoencoder')
  print('beginning to train classifier with learned encoder')

  #Extract the encoder
  #Add new layer to encoder with softmax classifier => arch: 784-200-10
  #Train while holding W1,b1 constant.
  tf.stop_gradient(W1)
  tf.stop_gradient(b1)

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


  # Train net 2:
  tf.global_variables_initializer().run() # Initialize variables
  for _ in range(1000):
    batch_xs, batch_ys = mnist.train.next_batch(100)#Grab batch
    sess.run(train_step_Xentropy_net2, feed_dict={x: batch_xs, y: batch_ys})

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
