package com.example.mCameraSlider;

import android.app.Activity;
import android.os.Bundle;
import android.widget.Toast;
import android.util.Log;
import android.content.res.Configuration;
import android.app.AlertDialog;
import android.content.DialogInterface;
import org.opencv.android.BaseLoaderCallback;
import org.opencv.android.LoaderCallbackInterface;
import org.opencv.android.OpenCVLoader;
import org.opencv.android.CameraBridgeViewBase.CvCameraViewFrame;
import org.opencv.android.CameraBridgeViewBase.CvCameraViewListener2;
import org.opencv.core.CvType;
import org.opencv.core.Mat;
import android.view.SurfaceView;

import android.widget.TextView;
import android.widget.SeekBar;
import android.widget.SeekBar.OnSeekBarChangeListener;
import java.util.Hashtable;

public class mCameraSlider extends Activity implements CvCameraViewListener2
{
    Hashtable<Integer,Float> sliderValues = new Hashtable<Integer,Float>();
	private CameraView mCameraView;
    private int mDisplayWidth;
    private int mDisplayHeight;
	Mat mCameraBufInput;
	Mat mCameraBufOutput;

	private BaseLoaderCallback mLoaderCallback = new BaseLoaderCallback(this) {
	    @Override
	    public void onManagerConnected(int status) {
	        switch (status) {
	            case LoaderCallbackInterface.SUCCESS:
	            {
	            	flashMessage("OpenCV loaded successfully");
	                mCameraView.enableView();
	                System.loadLibrary("mCameraSlider");
	                if (!BgThread.isAlive())
	                	BgThread.start();
	            } break;
	            default:
	            {
	                super.onManagerConnected(status);
	            } break;
	        }
	    }
	};

    private void registerCamera()
    {   
	    mCameraView = (CameraView) findViewById(R.id.surface_view);
	    mCameraView.setVisibility(SurfaceView.VISIBLE);
	    mCameraView.setCvCameraViewListener(this);
    }

    private void resumeCamera()
    {
        OpenCVLoader.initAsync(OpenCVLoader.OPENCV_VERSION_2_4_3, this, mLoaderCallback);
    }

    private void pauseCamera()
    {
        if (mCameraView != null)
            mCameraView.disableView();        
		}

    public void onCameraViewStarted(int width, int height) {
        mCameraBufInput = new Mat(height, width, CvType.CV_8UC4);
        mCameraBufOutput = new Mat(height, width, CvType.CV_8UC4);
		}        

    public void onCameraViewStopped() {
    	mCameraBufInput.release();
    	mCameraBufOutput.release();
    }

    public Mat onCameraFrame(CvCameraViewFrame inputFrame) {
    	mCameraBufInput = inputFrame.rgba();
    	return mCameraBufOutput;
	}


    public int initCamera(double sampleTime, int location, int width, int height)
    {
      	try
    	{
    		mCameraView.check(location, width, height);
            return 1;
    	}
    	catch (CameraView.SetupException ex)
    	{
      		showAlert(ex.mDescription);
            return 0;
    	}
	}

    public int initDisplay(int width, int height)
    {
        mDisplayWidth = width;
        mDisplayHeight = height;
        return 1;
    }
    
    public long getCameraInputBuffer()
    {
    	if (mCameraBufInput != null)
        {
            //byte data[] = new byte[4];
            //int ret = mCameraBufInput.get(0,0,data); //get the first pixel
            //String logMessage = String.format("%d: %d, %d, %d, %d", ret, data[0], data[1], data[2], data[3]);
            //Log.d("Camera", logMessage);
    		return mCameraBufInput.getNativeObjAddr();
        }
    	else
    		return 0;
    }

	public long getCameraOutputBuffer() {
		if (mCameraBufOutput != null)
		{
			return mCameraBufOutput.getNativeObjAddr();
		}
		else
			return 0;
	}

   public void showAlert(final String inMessage)
    {
  		runOnUiThread( new Runnable() {
				public void run() {
		            AlertDialog.Builder ad = new AlertDialog.Builder(thisClass);
		            ad.setCancelable(false); 
		            ad.setMessage(inMessage);
		            ad.setPositiveButton("OK", new DialogInterface.OnClickListener() {
		                public void onClick(DialogInterface dialog, int which) {
		                    dialog.dismiss();
		                    ((Activity)thisClass).finish();
		                }
		            });
		            ad.create();
		            ad.show();
					}
		});    	
    }


    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        // flashMessage("Started");
        registerCamera();

        /* Start the background thread */
        thisClass = this;
    }

    mCameraSlider thisClass;
    Thread BgThread = new Thread()
    {
        @Override
        public void run()
        {
            String argv[] = new String[] {"MainActivity","mCameraSlider"};
            // flashMessage("Started the background thread");
            naMain(argv, thisClass);
        }
    };

    public void flashMessage(final String inMessage)
    {
        Log.d("mCameraSlider", inMessage);
        runOnUiThread(new Runnable() {
              public void run() {
                    Toast.makeText(getBaseContext(), inMessage, Toast.LENGTH_SHORT).show();
              }
            });
    }


    @Override
    protected void onDestroy()
    {
         super.onDestroy();
         System.exit(0); //to kill all our threads.
    }

    @Override
    protected void onResume()
    {
         super.onResume();
         resumeCamera();
    }

    @Override
    protected void onPause() {
        pauseCamera();
        super.onPause();
    };

    @Override
    public void onConfigurationChanged(Configuration newConfig) {
        super.onConfigurationChanged(newConfig);
    }

    public void registerSlider(int id) {
        String sliderid = "slider"+id;
        SeekBar seekBar = (SeekBar)findViewById(getResources().getIdentifier(sliderid, "id", getPackageName()));
        seekBar.setOnSeekBarChangeListener(new OnSeekBarChangeListener() {
        			
        			@Override
        			public void onStopTrackingTouch(SeekBar seekBar) {        				
        			}
        			
        			@Override
        			public void onStartTrackingTouch(SeekBar seekBar) {        				
        			}
        			
        			@Override
        			public void onProgressChanged(SeekBar seekBar, int progress,
        					boolean fromUser) {
        				/* Update the hash table with slider id and value */
        				sliderValues.put(seekBar.getId(), (float)seekBar.getProgress());
        			}
        		});
    }

    public void setSliderValue(int id, float value,int points) {       
        String sliderid = "slider"+id;
        SeekBar seekBar = (SeekBar)findViewById(getResources().getIdentifier(sliderid, "id", getPackageName()));
        seekBar.setMax(points);
        seekBar.setProgress((int)value);
		sliderValues.put(seekBar.getId(), value);
    }

    public float getSliderValue(int id) {
        String sliderid = "slider"+id;
        SeekBar seekBar = (SeekBar)findViewById(getResources().getIdentifier(sliderid, "id", getPackageName()));
        return sliderValues.get(seekBar.getId());
    }

    public void dispSliderValue(int id,float value) {
        final String tid  = "textview"+id;
        final TextView tv = (TextView)findViewById(getResources().getIdentifier(tid, "id", getPackageName()));
        final String text = String.format("%s : %.3f",tv.getTag().toString(),value);

        runOnUiThread(new Runnable() {
            public void run() {
            	tv.setText(text);
            }
          });
    }



    private native int naMain(String[] argv, mCameraSlider pThis);

}
