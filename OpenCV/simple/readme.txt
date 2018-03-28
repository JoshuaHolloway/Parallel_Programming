# Compile opencv from terminal

# To run:
$ ./DisplayImage baboon.png

$ pkg-config --cflags opencv
-I/usr/local/include/opencv -I/usr/local/include

$ pkg-config --libs opencv
<List of libraries>

g++ -I/usr/local/include/opencv -I/usr/local/include -L/usr/local/lib -g -o binary  main.cpp -lopencv_stitching -lopencv_videostab -lopencv_superres -lopencv_xphoto -lopencv_freetype -lopencv_bioinspired -lopencv_xfeatures2d -lopencv_shape -lopencv_dnn_objdetect -lopencv_surface_matching -lopencv_xobjdetect -lopencv_rgbd -lopencv_img_hash -lopencv_hfs -lopencv_aruco -lopencv_ccalib -lopencv_bgsegm -lopencv_face -lopencv_photo -lopencv_dpm -lopencv_objdetect -lopencv_reg -lopencv_line_descriptor -lopencv_structured_light -lopencv_phase_unwrapping -lopencv_optflow -lopencv_ximgproc -lopencv_stereo -lopencv_calib3d -lopencv_saliency -lopencv_fuzzy -lopencv_tracking -lopencv_datasets -lopencv_text -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_dnn -lopencv_video -lopencv_plot -lopencv_ml -lopencv_imgproc -lopencv_flann -lopencv_core








icc -g -O3 -vec-report3 -I/usr/local/include/opencv -I/usr/local/include -L/usr/local/lib -g -o binary  main.cpp -lopencv_stitching -lopencv_videostab -lopencv_superres -lopencv_xphoto -lopencv_freetype -lopencv_bioinspired -lopencv_xfeatures2d -lopencv_shape -lopencv_dnn_objdetect -lopencv_surface_matching -lopencv_xobjdetect -lopencv_rgbd -lopencv_img_hash -lopencv_hfs -lopencv_aruco -lopencv_ccalib -lopencv_bgsegm -lopencv_face -lopencv_photo -lopencv_dpm -lopencv_objdetect -lopencv_reg -lopencv_line_descriptor -lopencv_structured_light -lopencv_phase_unwrapping -lopencv_optflow -lopencv_ximgproc -lopencv_stereo -lopencv_calib3d -lopencv_saliency -lopencv_fuzzy -lopencv_tracking -lopencv_datasets -lopencv_text -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_dnn -lopencv_video -lopencv_plot -lopencv_ml -lopencv_imgproc -lopencv_flann -lopencv_core

