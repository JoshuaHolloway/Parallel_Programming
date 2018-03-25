See pdf in this directory for overall description.

The implementation is as follows:

-Create app that utilizes users camera to record video at a framerate of 1 frame per second to reduce make the size of the overall video managable for cloud usage.

-Upload the recorded video from user to cloud database using firebase.

-Run ORB-SLAM2 on video.

-Send processed data back to user's phone.

-Display data onto visual map in GUI on screen for user to visually see location as determined by SLAM algorithm.
