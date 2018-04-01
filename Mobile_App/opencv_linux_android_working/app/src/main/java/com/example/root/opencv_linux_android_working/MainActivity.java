package com.example.root.opencv_linux_android_working;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import org.opencv.android.OpenCVLoader;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView textView = (TextView) findViewById(R.id.sample_text);
        textView.setText(stringFromJNI());

        if (!OpenCVLoader.initDebug()) {
            textView.setText(textView.getText() + "\n OpenCVLoader.initDebug() is NOT working.");
        } else {
            textView.setText(textView.getText() + "\n OpenCVLoader.initDebug() IS working.");
            textView.setText(textView.getText() + "\n" + validate(0L, 0L));
        }
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    // Added - JOSH:
    public native String validate(long matAddrGr, long matAddrRgba);

    // Remember that you set the environment variable also
}