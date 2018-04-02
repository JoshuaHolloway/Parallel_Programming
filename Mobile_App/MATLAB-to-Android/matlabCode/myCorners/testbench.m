% Copyright 2014 - 2015 The MathWorks, Inc.

%% Clean up the workspace
close all; clear all; clc;

%% Read in an image and scale to VGA;
original = imread('MakeoverHouse.jpg');
scaled = imresize(original,[480 640]);
gray = uint8(rgb2gray(scaled));
imshow(original)

%% Detect Corners

% Classical Harris Corners
harrisPoints = detectHarrisFeatures(gray);
% Rosten and Drummond Corners for higher performance
fastPoints = detectFASTFeatures(gray);
% Shi and Tomasi Minimum Eigenvalue Corners
minEigenPoints = detectMinEigenFeatures(gray);

%% Create a corner detector with scalable threshold
composite = insertMarker(gray, fastPoints.Location,'+', 'Color', 'red');
composite = insertMarker(composite, harrisPoints.Location,'o', 'Color', 'green');
composite = insertMarker(composite, minEigenPoints.Location,'x', 'Color', 'blue');

imshow(composite);

%% Now threshold the results according to Metric

%% FAST
fastLocations = fastPoints.Location;
fastIndex = fastPoints.Metric > 100;
fastLocationsToKeep = fastLocations(fastIndex,:);
fastImage = insertMarker(scaled, fastLocationsToKeep,'+', 'Color', 'red');
imshow(fastImage);
minFast = min(fastPoints.Metric);
maxFast = max(fastPoints.Metric);

%% Harris
harrisLocations = harrisPoints.Location;
harrisIndex = harrisPoints.Metric > 0.001;
harrisLocationsToKeep = harrisLocations(harrisIndex,:);
harrisImage = insertMarker(scaled, harrisLocationsToKeep,'o', 'Color', 'green');
imshow(harrisImage);
minHarris = min(harrisPoints.Metric);
maxHarris = max(harrisPoints.Metric);

%% Shi and Tomasi
minEigenLocations = minEigenPoints.Location;
minEigenIndex = minEigenPoints.Metric > 0.009;
minEigenLocationsToKeep = minEigenLocations(minEigenIndex,:);
minEigenImage = insertMarker(scaled, minEigenLocationsToKeep,'x', 'Color', 'blue');
imshow(minEigenImage);
minMinEigen = min(minEigenPoints.Metric);
maxMinEigen = max(minEigenPoints.Metric);
%% Now, lets create a function that handles this for us and
% returns a composite image that displays 3 sets of corner points, based
% on an input threshold.  This is the code we will use for code generation.

fastThresh = single(1000);
minEigenThresh = single(40000);
harrisThresh = single(100000);
rPlane = scaled(:,:,1);
gPlane = scaled(:,:,2);
bPlane = scaled(:,:,3);
[rPlane, gPlane, bPlane] = myCorners(rPlane,gPlane,bPlane, fastThresh, minEigenThresh, harrisThresh);
imshow(cat(3,rPlane,gPlane,bPlane));

%% Build a mex version
codegen myCorners -args {rPlane, gPlane, bPlane, fastThresh, harrisThresh, minEigenThresh}

%% Test mex version
[rPlane, gPlane, bPlane] = myCorners_mex(rPlane, gPlane, bPlane, fastThresh, minEigenThresh, harrisThresh);
imshow(cat(3,rPlane,gPlane,bPlane));

%% Build Stand-alone
open('myCorners.prj');
