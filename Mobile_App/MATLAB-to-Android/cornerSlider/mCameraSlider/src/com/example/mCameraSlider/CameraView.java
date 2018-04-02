package com.example.mCameraSlider;

// import java.util.ArrayList;
import java.util.List;
import java.util.ListIterator;

import org.opencv.android.JavaCameraView;

import android.content.Context;
import android.hardware.Camera.Size;
import android.util.AttributeSet;

class CameraView extends JavaCameraView
{
    private int mCameraWidth = 352;
    private int mCameraHeight = 288;
    private int mCameraLocation = org.opencv.android.CameraBridgeViewBase.CAMERA_ID_BACK;

    public class SetupException extends Exception
    {
        private static final long serialVersionUID = 3405052571591189497L;
    	public String mDescription;
    	SetupException(String inDescription)
    	{
    		mDescription = inDescription;
    	}
    }
    public CameraView(Context context, int cameraId) {
        super(context, cameraId);
        setCameraIndex(mCameraLocation);
        setMaxFrameSize(mCameraWidth, mCameraHeight);
    }

    public CameraView(Context context, AttributeSet attrs) {
        super(context, attrs);
        setCameraIndex(mCameraLocation);
        setMaxFrameSize(mCameraWidth, mCameraHeight);
    }

    public void check(int location, int width, int height) throws SetupException
    {
    	if ((mCameraWidth != width) || (mCameraHeight != height))
    	{
    		String message = String.format("Image size in the model doesn't match the view:\nModel: %d x %d\nView: %d x %d", width, height, mCameraWidth, mCameraHeight);
    		throw new SetupException(message);
    	}

    	String strLocation;
    	if (mCameraLocation == org.opencv.android.CameraBridgeViewBase.CAMERA_ID_BACK)
    		strLocation = "Back";
    	else
    		strLocation = "Front";       	

    	if (location > 0)
        {
    		boolean match = false;
    		String mdlLocation;
            if (location == 2) //back
            {
            	mdlLocation = "Back";
            	match = (mCameraLocation == org.opencv.android.CameraBridgeViewBase.CAMERA_ID_BACK);
            }               
            else
            {
            	mdlLocation = "Front";
            	match = (mCameraLocation == org.opencv.android.CameraBridgeViewBase.CAMERA_ID_FRONT);
            }
            if (!match)
            {
            	String message = String.format("Location in model doesn't match the view:\nModel: %s\nView: %s", mdlLocation, strLocation);            	
            	throw new SetupException(message);
            }
        }
    }

    protected boolean initializeCamera(int width, int height)
    {
    	boolean ret = super.initializeCamera(width, height);
    	if (ret)
    	{
            List<Size> resolutions = mCamera.getParameters().getSupportedPreviewSizes();
            ListIterator<Size> resolutionsItr = resolutions.listIterator();
            boolean found = false;
            while (resolutionsItr.hasNext() && !found)
            {
                Size resolution = resolutionsItr.next();
                found = (resolution.height == mCameraHeight) && (resolution.width == mCameraWidth);
            }
            if (found)
                return ret;
            resolutions = mCamera.getParameters().getSupportedPictureSizes();
            resolutionsItr = resolutions.listIterator();
            while (resolutionsItr.hasNext() && !found)
            {
                Size resolution = resolutionsItr.next();
                found = (resolution.height == mCameraHeight) && (resolution.width == mCameraWidth);
            }
            if (!found)
            {
            	String message = String.format("Resolution requested: %d x %d is not supported by the Back Camera.", mCameraWidth, mCameraHeight);
            	mCameraSlider activity = (mCameraSlider)getContext();
            	activity.showAlert(message);
            }    		
    	}
    	return ret;
    }

}
