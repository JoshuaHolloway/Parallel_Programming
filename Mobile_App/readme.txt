SVM in Android

Step 1: Pass data from Java to C++ in android.

Step 2: Do step 1 with code generated from MATLAB:
        2.a) Arrays   -Done
        2.b) Matrices -Done with matrix addition, now doing mat-mult naive with nested for-loops
                      -Done with matrix multiplication.

Step 3: Repeat step 2 with C++ code generated from MATLAB using the SVM model trained in MATLAB.
https://www.mathworks.com/matlabcentral/fileexchange/50232-machine-learning-made-easy?focused=6801923&tab=example
-modified code here:
/Parallel_Vision_Research/Mobile_App/matlab

Note: At the line with the following code there is an error thrown in the file plotActivityResults:
activity = predict(mdl,humanActivityTest{ii,1:end-1});

Step 4: Pass in data matrix from accelerometer readings from Android app into function from step 3.


Data from step 3 is in this form:
rawSensorDataTest is a 2947 x 6 matrix.
Each row is a training example, and each column corresponds to:
accelerometer (x,y,z) gyroscope (x,y,z)

Description of generating C-code from model from here:
https://www.mathworks.com/help/stats/c-generate-code-and-classification-learner.html

0. Use the link in step 3 to train an SVM model. Run the classificationLearner app.

1. In the Export section, click Export Model, and then select Export Compact Model. Click OK in the dialog box.

2. The structure trainedModel appears in the MATLAB Workspace. The field ClassificationSVM of trainedModel contains the compact model.

3. At the command line, save the compact model to a file called ClassificationLearnerModel.mat in your current folder.
saveCompactModel(trainedModel.ClassificationSVM,'ClassificationLearnerModel');
4. 


