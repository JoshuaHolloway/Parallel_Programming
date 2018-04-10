clc, clear, close all;

% addpath to the libsvm toolbox
addpath('/home/josh/Desktop/libsvm');

% -training_label_vector:
%    An m by 1 vector of training labels (type must be double).
% -training_instance_matrix:
%    An m by n matrix of m training instances with n features.
%    It can be dense or sparse (type must be double).
% -libsvm_options:
%    A string of training options in the same format as that of LIBSVM.


%% Download data from source
%  If you are running this script for the first time, make sure that you
%  execute these functions. 
%%
% * |downloadSensorData| : This function will download the dataset and
% extract its contents to a folder called: UCI HAR Dataset
% This folder must be present before you execute |saveSensorDataAsMATFiles|
if ~exist('UCI_HAR_Dataset','file')
    downloadSensorData;
end

%% Load data from individual files and save as MAT file for reuse
%%
% * |saveSensorDataAsMATFiles| : This function will load the data from the individual
% source files and save the data in a single MAT file for easy accesss 
if ~exist('rawSensorData_train.mat','file') && ~exist('rawSensorData_test.mat','file')
    saveSensorDataAsMATFiles;
end

%% Load Training Data
load rawSensorData_train

%% Display data summary
plotRawSensorData(total_acc_x_train, total_acc_y_train, ...
    total_acc_z_train,trainActivity,1000)

%% Create Table variable
rawSensorDataTrain = table(...
    total_acc_x_train, total_acc_y_train, total_acc_z_train);%, ...
%    body_gyro_x_train, body_gyro_y_train, body_gyro_z_train);

%% Pre-process Training Data: *Feature Extraction*
% Lets start with a simple preprocessing technique. Since the raw sensor 
% data contain fixed-width sliding windows of 2.56sec (128 readings/window) 
% lets start with a simple average feature for every 128 points
humanActivityData = varfun(@Wmean,rawSensorDataTrain);
humanActivityData.activity = trainActivity;

%% Additional Feature Extraction
T_mean = varfun(@Wmean, rawSensorDataTrain);
T_stdv = varfun(@Wstd,rawSensorDataTrain);
T_pca  = varfun(@Wpca1,rawSensorDataTrain);

%humanActivityData = [T_mean, T_stdv, T_pca];
humanActivityData = [T_mean, T_stdv];
humanActivityData.activity = trainActivity;

%% Train a model and assess its performance using Classification Learner
classificationLearner

%% Print the sizes of the arrays:
X = humanActivityData(:,1:6);
Y = humanActivityData(:,7);
size(X)
size(Y)

training_label_vector = Y;
training_instance_matrix = X;
%model = svmtrain(training_label_vector, training_instance_matrix [, 'libsvm_options']);
model = svmtrain(training_label_vector, training_instance_matrix);