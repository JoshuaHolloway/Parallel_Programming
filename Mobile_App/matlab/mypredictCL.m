function label = mypredictCL(X) %#codegen
%MYPREDICTCL Classify credit rating using model exported from
%Classification Learner
%   MYPREDICTCL loads trained classification model (SVM) and model
%   parameters (removeVars, pcaCenters, and pcaCoefficients), removes the
%   columns of the raw matrix of predictor data in X corresponding to the
%   indices in removeVars, transforms the resulting matrix using the PCA
%   centers in pcaCenters and PCA coefficients in pcaCoefficients, and then
%   uses the transformed data to classify credit ratings. X is a numeric
%   matrix with n rows and 7 columns. label is an n-by-1 cell array of
%   predicted labels.

% Load trained classification model and model parameters
SVM = loadCompactModel('ClassificationLearnerModel');
data = coder.load('ModelParameters');
removeVars = data.removeVars;
pcaCenters = data.pcaCenters;
pcaCoefficients = data.pcaCoefficients;
SVM = loadCompactModel('ClassificationLearnerModel');

% Remove unused predictor variables
keepvars = 1:size(X,2);
idx = ~ismember(keepvars,removeVars);
keepvars = keepvars(idx);
XwoID = X(:,keepvars);

% Transform predictors via PCA
Xpca = bsxfun(@minus,XwoID,pcaCenters)*pcaCoefficients;

% Generate label from SVM
label = predict(SVM,Xpca);
end