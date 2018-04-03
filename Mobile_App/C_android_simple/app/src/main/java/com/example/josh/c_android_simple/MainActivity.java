package com.example.josh.c_android_simple;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

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
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());

        // Test the C-function:
        float[] array3 = new float[3];
        float[] array1 = new float[3];
        float[] array2 = new float[3];

        array1[0] = 0;
        array1[1] = 1;
        array1[2] = 2;

        array2[0] = 0;
        array2[1] = 1;
        array2[2] = 2;

        array3 = test(array1, array2);


    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
    public native float[] test(float[] array1, float[] array2);
}
