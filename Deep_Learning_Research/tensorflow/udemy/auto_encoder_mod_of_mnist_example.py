# Linear Auto-encoder
import numpy as np
import matplotlib.pyplot as plt

from sklearn.datasets import make_blobs

# Create 100 samples (100 rows of data)
# Each example has 3 features (3 columns)
# Two classes
data = make_blobs(n_samples=100, n_features=3, centers=2, random_state=101)
# data is a tuple containing
# data[0] contains the data matrix
# data[1] contains the labels
X = data[0]
Y = data[1]

# pre-process data
from sklearn.preprocessing import MinMaxScaler
scaler = MinMaxScaler()
scaled_data = scaler.fit_transform(data[0]) # normalize dataset

# Plot data
data_x = scaled_data[:,0] # 1st feature
data_y = scaled_data[:,1] # 2nd feature
data_z = scaled_data[:,2] # 3rd feature

# Look at the data
from mpl_toolkits.mplot3d import Axes3D
fig = plt.figure()
ax = fig.add_subplot(111,projection='3d')
ax.scatter(data_x, data_y, data_z,c=data[1])


# Perform PCA with Tensorflow
import tensorflow as tf
from tensorflow.contrib.layers import fully_connected

num_inputs = 3
num_hidden = 2
num_outputs = num_inputs

learning_rate = 0.01


X = tf.placeholder(tf.float32,shape=[None,num_inputs])
#hidden = fully_connected(X,num_hidden,activation_fn=None) # Linear act. func
#outputs = fully_connected(hidden,num_outputs,activation_fn=None) # Linear act. func



#==========
# Layer 1:
W1 = tf.Variable(tf.zeros([num_inputs, num_hidden])) # Num Inputs x Num Neurons
b1 = tf.Variable(tf.zeros([num_hidden]))
y1 = tf.matmul(X, W1) + b1

# Layer 2:
W2 = tf.Variable(tf.zeros([num_hidden, num_outputs])) # Num Inputs x Num Neurons
b2 = tf.Variable(tf.zeros([num_outputs]))
y2 = tf.matmul(y1, W2) + b2
#==========



loss = tf.reduce_mean(tf.square(y2-X))
optimizer = tf.train.AdamOptimizer(learning_rate)
train = optimizer.minimize(loss)

# initialize variables
init = tf.global_variables_initializer()

#num_steps = 1000
#with tf.Session() as sess:
#    sess.run(init)
#    for iteration in range(num_steps):
#        sess.run(train,feed_dict={X:scaled_data}) # the data is automatically vectorized?
#    output_2d = hidden.eval(feed_dict={X:scaled_data})

# Train the net
with tf.Session() as sess:
    sess.run(init)
    for _ in range(1000):
        # Execute y2 = W2*(W1*x + b1) + b2
        sess.run(train, feed_dict={X: scaled_data})
    output_2d = y1.eval(feed_dict={X:scaled_data})

# Loop at the reduced dimensioned data
#plt.scatter(output_2d[:,0],output_2d[:,1])
ax.scatter(output_2d[:,0],output_2d[:,1], np.zeros([100,]), data_z,c=data[1])
plt.show()
