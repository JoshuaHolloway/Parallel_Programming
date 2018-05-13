#include "header.h"
//===============
struct FeatureMap
{
	float* val = nullptr;
	size_t rows;
	size_t cols;
	size_t channels;
	size_t num_elems;

	FeatureMap(size_t rows, size_t cols, size_t channels)
	{
		num_elems = rows * cols * channels;
		this->rows = rows;
		this->cols = cols;
		this->channels = channels;
		val = new float[num_elems];
	}


	// Easier indexing is achieved with (channel, row, col)
	void set(size_t i, size_t j, size_t k, float val)
	{
		this->val[i * rows * cols + j * cols + k] = val;
	}

	float at(size_t i, size_t j, size_t k) //(channel, row, col)
	{
		return val[i * rows * cols + j * cols + k];
	}

	void ones()
	{
		for (int i = 0; i < channels; ++i)
		{
			for (int j = 0; j < rows; ++j)
			{
				for (int k = 0; k < cols; ++k)
				{
					this->val[i * rows * cols + j * cols + k] = 1;
				}
			}
		}
	}

	void zeros()
	{
		for (int i = 0; i < channels; ++i)
		{
			for (int j = 0; j < rows; ++j)
			{
				for (int k = 0; k < cols; ++k)
				{
					this->val[i * rows * cols + j * cols + k] = 0;
				}
			}
		}
	}

	void count()
	{
		for (int i = 0; i < channels; ++i)
		{
			for (int j = 0; j < rows; ++j)
			{
				for (int k = 0; k < cols; ++k)
				{
					this->val[i * rows * cols + j * cols + k] = i * rows * cols + j * cols + k;
				}
			}
		}
	}

	void print()
	{
		for (int i = 0; i < channels; ++i)
		{
			cout << "\n ----------------- \n";
			cout << "Slice " << i << " \n";
			for (int j = 0; j < rows; ++j)
			{
				for (int k = 0; k < cols; ++k)
				{
					cout << val[i * rows * cols + j * cols + k] << " ";
				}
				cout << "\n";
			}
		}
	}
};
//---------------
struct Tensor
{

	size_t dim1;
	size_t dim2;
	size_t dim3;
	size_t dim4;

	// pixel data
	float* val = nullptr;

	// (filters, channels, rows, cols)
	size_t filters;		// dim 1
	size_t channels;	// dim 2
	size_t rows;			// dim 3
	size_t cols;			// dim 4

							// total number of pixels
	size_t num_elems;


	// Vector of feature maps - tensor = set of feature maps:
	std::vector<FeatureMap> tensor;

	// Constructor and destructor
	Tensor(size_t filters, size_t channels, size_t rows, size_t cols)
	{
		num_elems = rows * cols * channels * filters;

		val = new float[num_elems];

		this->filters = filters;			this->dim1 = filters;
		this->channels = channels;		this->dim2 = channels;
		this->rows = rows;						this->dim3 = rows;
		this->cols = cols;						this->dim4 = cols;
	}
	~Tensor()
	{
		delete[] val;
	}

	// Easier indexing is achieved with (output_channel, input_channel, row, col)
	void set(size_t i, size_t j, size_t k, size_t l, float val)
	{
		// i: dim1 - filters
		// j: dim2 - channels
		// k: dim3 - rows
		// l: dim4 - cols

		// 3D linear index: i * rows * cols + j * cols + k
		// i * cols * rows + j * cols + k
		// (i * dim3 * dim2) + (j * dim3) + k

		// 4D linear index:
		// (i * dim4 * dim3 * dim2) + (j * dim4 * dim3) + (k * dim4) + l

		this->val[(i * dim4 * dim3 * dim2) + (j * dim4 * dim3) + (k * dim4) + l] = val;
	}

	float at(size_t i, size_t j, size_t k, size_t l) //(filters, channel, row, col)
	{
		return val[(i * dim4 * dim3 * dim2) + (j * dim4 * dim3) + (k * dim4) + l];
	}

	void ones()
	{
		for (int i = 0; i < dim1; ++i)
		{
			for (int j = 0; j < dim2; ++j)
			{
				for (int k = 0; k < dim3; ++k)
				{
					for (int l = 0; l < dim4; ++l)
						this->val[(i * dim4 * dim3 * dim2) + (j * dim4 * dim3) + (k * dim4) + l] = 1;
				}
			}
		}
	}

	void zeros()
	{
		for (int i = 0; i < dim1; ++i)
		{
			for (int j = 0; j < dim2; ++j)
			{
				for (int k = 0; k < dim3; ++k)
				{
					for (int l = 0; l < dim4; ++l)
						this->val[(i * dim4 * dim3 * dim2) + (j * dim4 * dim3) + (k * dim4) + l] = 0;
				}
			}
		}
	}

	void count()
	{
		for (int i = 0; i < dim1; ++i)
		{
			for (int j = 0; j < dim2; ++j)
			{
				for (int k = 0; k < dim3; ++k)
				{
					for (int l = 0; l < dim4; ++l)
					{
						this->val[(i * dim4 * dim3 * dim2) + (j * dim4 * dim3) + (k * dim4) + l]
							= (i * dim4 * dim3 * dim2) + (j * dim4 * dim3) + (k * dim4) + l;

					}
				}
			}
		}
	};

	void print()
	{
		for (int i = 0; i < filters; ++i)
		{
			cout << "\n ----------------- \n";
			cout << "Volume " << i << " \n";
			for (int j = 0; j < channels; ++j)
			{
				cout << "\n ----------------- \n";
				cout << "Slice " << i << " \n";
				for (int k = 0; k < rows; ++k)
				{
					for (int l = 0; l < cols; ++l)
					{
						cout << val[(i * dim4 * dim3 * dim2) + (j * dim4 * dim3) + (k * dim4) + l] << " ";
					}
					cout << "\n";
				}
			}
		}
	}
};
//-------------------------------------
FeatureMap conv(FeatureMap x, Tensor h)
{
	// 'same' 2D conv with 3D feature maps with implicit matrix slice addition
	// Zero-padding is also implicit
	//
	// Input: One 3D feature map and one 4D tensor (set of filters)
	// Output: One 3D feature map
	FeatureMap y(x.rows, x.cols, h.filters);
	for (int idq = 0; idq < h.filters; ++idq) // out_channels
	{
		for (int idy = 0; idy < x.rows; ++idy) // out_rows
		{
			for (int idx = 0; idx < x.cols; ++idx) // out_cols
			{
				float Pvalue = 0.0f;
				for (int idz = 0; idz < x.channels; ++idz) // input_channels
				{

					int M_start_point = idy - h.rows / 2;
					int N_start_point = idx - h.cols / 2;
					for (int i = 0; i < h.rows; ++i) // filter_rows
					{
						for (int j = 0; j < h.cols; ++j) // filter_cols
						{
							if ((M_start_point + i >= 0 && M_start_point + i < x.rows)
								&& (N_start_point + j >= 0 && N_start_point + j < x.cols))
							{
								Pvalue += x.at(idz, M_start_point + i, N_start_point + j) * h.at(idq, idz, i, j);
							}
						}
					}
					y.set(idq, idy, idx, Pvalue);
				}
			}
		}
	}
	return y;
}
//-------------------------------
FeatureMap pool_ave(FeatureMap x)
{
	const size_t H = x.rows;
	const size_t W = x.cols;
	const size_t M = x.channels;
	const size_t K = 2; // downsampling factor

	FeatureMap S(H / K, W / K, x.channels); // rows, cols, channels

	for (int m = 0; m < M; ++m)  // channels
	{
		for (int h = 0; h < H / K; ++h) // rows
		{
			for (int w = 0; w < W / K; ++w)
			{
				float temp = 0.0f;
				for (int p = 0; p < K; ++p)
				{
					for (int q = 0; q < K; ++q)
					{
						temp += x.at(m, K*h + p, K*w + q) / float(K*K);
					}
				}
				S.set(m, h, w, temp);
			}
		}
	}

	return S;
}
//-------------------------------
FeatureMap pool_max(FeatureMap x)
{
	// downsampling factor:
	const size_t K = 2;

	// output downsampled feature map:
	FeatureMap y(x.rows / K, x.cols / K, x.channels); // rows, cols, channels

	for (int i = 0; i < x.channels; ++i)
	{
		for (int j = 0; j < x.rows; j += K)
		{
			for (int k = 0; k < x.cols; k += K)
			{
				// Search inside the KxK block for max value
				int max = 0;
				for (int jj = j; jj < j + K; ++jj)
				{
					for (int kk = k; kk < k + K; ++kk)
					{
						if (jj == j && kk == k)
						{
							max = x.at(i, jj, kk);
						}
						else
						{
							if (x.at(i, jj, kk) > max)
								max = x.at(i, jj, kk);
						} // end if-else
					}// end for over kk
				} // end for over jj
				  //y[i][j / 2][k / 2] = max;
				y.set(i, j / 2, k / 2, max);
			} // end for over k
		} // end for over j
	} // end for over i
	return y;
}
//---------------------------
FeatureMap relu(FeatureMap z)
{
	for (int i = 0; i < z.channels; ++i)
	{
		for (int j = 0; j < z.rows; ++j)
		{
			for (int k = 0; k < z.cols; ++k)
			{
				// Leaky ReLu
				if (z.at(i, j, k) < 0)
					z.set(i, j, k, 0.1*z.at(i, j, k));
			}
		}
	}
	return z;
}
//=============================================================================
__global__ void addKernel(int *c, const int *a, const int *b)
{
	int i = threadIdx.x;
	c[i] = a[i] + b[i];
}
//-----------------------------------------------------------------------------
cudaError_t addWithCuda(int *c, const int *a, const int *b, unsigned int size)
{
	int *dev_a = 0;
	int *dev_b = 0;
	int *dev_c = 0;
	cudaError_t cudaStatus;

	// Choose which GPU to run on, change this on a multi-GPU system.
	cudaStatus = cudaSetDevice(0);
	if (cudaStatus != cudaSuccess) {
		fprintf(stderr, "cudaSetDevice failed!  Do you have a CUDA-capable GPU installed?");
		goto Error;
	}

	// Allocate GPU buffers for three vectors (two input, one output)    .
	cudaStatus = cudaMalloc((void**)&dev_c, size * sizeof(int));
	if (cudaStatus != cudaSuccess) {
		fprintf(stderr, "cudaMalloc failed!");
		goto Error;
	}

	cudaStatus = cudaMalloc((void**)&dev_a, size * sizeof(int));
	if (cudaStatus != cudaSuccess) {
		fprintf(stderr, "cudaMalloc failed!");
		goto Error;
	}

	cudaStatus = cudaMalloc((void**)&dev_b, size * sizeof(int));
	if (cudaStatus != cudaSuccess) {
		fprintf(stderr, "cudaMalloc failed!");
		goto Error;
	}

	// Copy input vectors from host memory to GPU buffers.
	cudaStatus = cudaMemcpy(dev_a, a, size * sizeof(int), cudaMemcpyHostToDevice);
	if (cudaStatus != cudaSuccess) {
		fprintf(stderr, "cudaMemcpy failed!");
		goto Error;
	}

	cudaStatus = cudaMemcpy(dev_b, b, size * sizeof(int), cudaMemcpyHostToDevice);
	if (cudaStatus != cudaSuccess) {
		fprintf(stderr, "cudaMemcpy failed!");
		goto Error;
	}

	// Launch a kernel on the GPU with one thread for each element.
	addKernel << <1, size >> >(dev_c, dev_a, dev_b);

	// Check for any errors launching the kernel
	cudaStatus = cudaGetLastError();
	if (cudaStatus != cudaSuccess) {
		fprintf(stderr, "addKernel launch failed: %s\n", cudaGetErrorString(cudaStatus));
		goto Error;
	}

	// cudaDeviceSynchronize waits for the kernel to finish, and returns
	// any errors encountered during the launch.
	cudaStatus = cudaDeviceSynchronize();
	if (cudaStatus != cudaSuccess) {
		fprintf(stderr, "cudaDeviceSynchronize returned error code %d after launching addKernel!\n", cudaStatus);
		goto Error;
	}

	// Copy output vector from GPU buffer to host memory.
	cudaStatus = cudaMemcpy(c, dev_c, size * sizeof(int), cudaMemcpyDeviceToHost);
	if (cudaStatus != cudaSuccess) {
		fprintf(stderr, "cudaMemcpy failed!");
		goto Error;
	}

Error:
	cudaFree(dev_c);
	cudaFree(dev_a);
	cudaFree(dev_b);

	return cudaStatus;
}
//--------
//--------------------------------------
void save_image(const char* output_filename,
	float* buffer,
	int height,
	int width) {
	cv::Mat output_image(height, width, CV_32FC3, buffer);
	// Make negative values zero.
	cv::threshold(output_image,
		output_image,
		/*threshold=*/0,
		/*maxval=*/0,
		cv::THRESH_TOZERO);
	cv::normalize(output_image, output_image, 0.0, 255.0, cv::NORM_MINMAX);
	output_image.convertTo(output_image, CV_8UC3);
	cv::imwrite(output_filename, output_image);
}
//--------------------------------------
int kernel_wrapper(const cv::Mat& image)
{
#define checkCUDNN(expression)                               \
  {                                                          \
    cudnnStatus_t status = (expression);                     \
    if (status != CUDNN_STATUS_SUCCESS) {                    \
      std::cerr << "Error on line " << __LINE__ << ": "      \
                << cudnnGetErrorString(status) << std::endl; \
      std::exit(EXIT_FAILURE);                               \
    }                                                        \
  }

	// Create context object
	cudnnHandle_t cudnn;
	checkCUDNN(cudnnCreate(&cudnn));

	// Input tensor
	cudnnTensorDescriptor_t input_descriptor;
	checkCUDNN(cudnnCreateTensorDescriptor(&input_descriptor));
	checkCUDNN(cudnnSetTensor4dDescriptor(input_descriptor,
		/*format=*/CUDNN_TENSOR_NHWC,
		/*dataType=*/CUDNN_DATA_FLOAT,
		/*batch_size=*/1,
		/*channels=*/3,
		/*image_height=*/image.rows,
		/*image_width=*/image.cols));

	// Output tensor
	cudnnTensorDescriptor_t output_descriptor;
	checkCUDNN(cudnnCreateTensorDescriptor(&output_descriptor));
	checkCUDNN(cudnnSetTensor4dDescriptor(output_descriptor,
		/*format=*/CUDNN_TENSOR_NHWC,
		/*dataType=*/CUDNN_DATA_FLOAT,
		/*batch_size=*/1,
		/*channels=*/3,
		/*image_height=*/image.rows,
		/*image_width=*/image.cols));

	// Filter tensor
	cudnnFilterDescriptor_t kernel_descriptor;
	checkCUDNN(cudnnCreateFilterDescriptor(&kernel_descriptor));
	checkCUDNN(cudnnSetFilter4dDescriptor(kernel_descriptor,
		/*dataType=*/CUDNN_DATA_FLOAT,
		/*format=*/CUDNN_TENSOR_NCHW,
		/*out_channels=*/3,
		/*in_channels=*/3,
		/*kernel_height=*/3,
		/*kernel_width=*/3));

	// Describe the conv kernel
	cudnnConvolutionDescriptor_t convolution_descriptor;
	checkCUDNN(cudnnCreateConvolutionDescriptor(&convolution_descriptor));
	checkCUDNN(cudnnSetConvolution2dDescriptor(convolution_descriptor,
		/*pad_height=*/1,
		/*pad_width=*/1,
		/*vertical_stride=*/1,
		/*horizontal_stride=*/1,
		/*dilation_height=*/1,
		/*dilation_width=*/1,
		/*mode=*/CUDNN_CROSS_CORRELATION,
		/*computeType=*/CUDNN_DATA_FLOAT));

	// More detailed description of the convolution algorithm we want to use:
	cudnnConvolutionFwdAlgo_t convolution_algorithm;
	checkCUDNN(
		cudnnGetConvolutionForwardAlgorithm(cudnn,
			input_descriptor,
			kernel_descriptor,
			convolution_descriptor,
			output_descriptor,
			CUDNN_CONVOLUTION_FWD_PREFER_FASTEST,
			/*memoryLimitInBytes=*/0,
			&convolution_algorithm));

	// Physical memory to operate on
	size_t workspace_bytes = 0;
	checkCUDNN(cudnnGetConvolutionForwardWorkspaceSize(cudnn,
		input_descriptor,
		kernel_descriptor,
		convolution_descriptor,
		output_descriptor,
		convolution_algorithm,
		&workspace_bytes));
	std::cerr << "Workspace size: " << (workspace_bytes / 1048576.0) << "MB"
		<< std::endl;

	// Dimensions from OpenCV input image
	int batch_size = 1;
	int channels = image.channels();
	int height = image.rows;
	int width = image.cols;
	cout << "\n batch_size = " << batch_size << " channels = " << channels << " rows = " << height << " cols = " << width << "\n";

	// Dimensions from cuDNN for confirmation
	cudnnGetConvolution2dForwardOutputDim(
		convolution_descriptor, 
		input_descriptor,
		kernel_descriptor,
		&batch_size,
		&channels,
		&height,
		&width);
	cout << "\n batch_size = " << batch_size << " channels = " << channels << " rows = " << height << " cols = " << width << "\n";
	

	// Allocate device memory
	void* d_workspace{ nullptr };
	cudaMalloc(&d_workspace, workspace_bytes);

	int image_bytes = batch_size * channels * height * width * sizeof(float);

	float* d_input{ nullptr };
	cudaMalloc(&d_input, image_bytes);
	cudaMemcpy(d_input, image.ptr<float>(0), image_bytes, cudaMemcpyHostToDevice);

	float* d_output{ nullptr };
	cudaMalloc(&d_output, image_bytes);
	cudaMemset(d_output, 0, image_bytes);

	// Mystery kernel
	const float kernel_template[3][3] = {
		{ 1,  1, 1 },
		{ 1, -8, 1 },
		{ 1,  1, 1 }
	};

	float h_kernel[3][3][3][3];
	for (int kernel = 0; kernel < 3; ++kernel) {
		for (int channel = 0; channel < 3; ++channel) {
			for (int row = 0; row < 3; ++row) {
				for (int column = 0; column < 3; ++column) {
					h_kernel[kernel][channel][row][column] = kernel_template[row][column];
				}
			}
		}
	}

	float* d_kernel{ nullptr };
	cudaMalloc(&d_kernel, sizeof(h_kernel));
	cudaMemcpy(d_kernel, h_kernel, sizeof(h_kernel), cudaMemcpyHostToDevice);

	// Do conv
	const float alpha = 1, beta = 0;
	checkCUDNN(cudnnConvolutionForward(cudnn,
		&alpha,
		input_descriptor,
		d_input,
		kernel_descriptor,
		d_kernel,
		convolution_descriptor,
		convolution_algorithm,
		d_workspace,
		workspace_bytes,
		&beta,
		output_descriptor,
		d_output));

	// Copy DEVICE -> HOST
	float* h_output = new float[image_bytes];
	cudaMemcpy(h_output, d_output, image_bytes, cudaMemcpyDeviceToHost);

	// Do something with h_output ...
	save_image("convolved_img.jpg",
		h_output,
		height,
		width);
	//void save_image(const char* output_filename,
	//	float* buffer,
	//	int height,
	//	int width);

	// Free memory
	delete[] h_output;
	cudaFree(d_kernel);
	cudaFree(d_input);
	cudaFree(d_output);
	cudaFree(d_workspace);

	cudnnDestroyTensorDescriptor(input_descriptor);
	cudnnDestroyTensorDescriptor(output_descriptor);
	cudnnDestroyFilterDescriptor(kernel_descriptor);
	cudnnDestroyConvolutionDescriptor(convolution_descriptor);

	cudnnDestroy(cudnn);


	// Custom CNN
	const size_t R[26] = { 416, 416, 208, 208, 104, 104, 104, 104, 52, 52, 52, 52, 26, 26, 26, 26, 26, 26,13,13,13,13,13,13,13,13 }; // Rows    in each 2D matrix slice in each 3D feature map
	const size_t C[26] = { 416, 416, 208, 208, 104, 104, 104, 104, 52, 52, 52, 52, 26, 26, 26, 26, 26, 26,13,13,13,13,13,13,13,13 }; // Columns in each 2D matrix slice in each 3D feature map
	const size_t K = 3; // Filter size

	size_t D[25];
	D[0] = 3;
	D[1] = 32;
	D[2] = 32;
	D[3] = 64;
	D[4] = 64;
	D[5] = 128;
	D[6] = 64;
	D[7] = 128;
	D[8] = 128;
	D[9] = 256;
	D[10] = 128;
	D[11] = 256;
	D[12] = 256;
	D[13] = 512;
	D[14] = 256;
	D[15] = 512;
	D[16] = 256;
	D[17] = 512;
	D[18] = 512;
	D[19] = 1024;
	D[20] = 512;
	D[21] = 1024;
	D[22] = 512;
	D[23] = 1024;
	D[24] = 1024;
	D[25] = 1024;

	/// Section 1 - layers 1,2: conv-pool
	FeatureMap X(R[0], C[0], D[0]);     X.count();
	Tensor H1(D[1], D[0], K, K); /* */ H1.ones(); // Layer 1
	//Tensor H2(D[2], D[1], K, K); /* */ H2.ones(); // Layer 2 - Pool

	/// Section 2 - layers 3,4: conv-pool
	Tensor H3(D[3], D[2], K, K); /* */ H3.ones(); // Layer 3
	//Tensor H4(D[4], D[3], K, K); /* */ H4.ones(); // Layer 4 - Pool

/*
	/// Section 3 - layers 5-8: conv(x3)-pool
	Tensor H5(D[5], D[4], K, K);  H5.ones(); // Layer 5
	Tensor H6(D[6], D[5], K, K);  H6.ones(); // Layer 6
	Tensor H7(D[7], D[6], K, K);  H7.ones(); // Layer 7
	//Tensor H8(D[8], D[7], K, K);  H8.ones(); // Layer 8 - Pool

	/// Section 4 - layers 9-12: conv(x3)-pool
	Tensor H9(D[9], D[8], K, K);     H9.ones(); // Layer 9
	Tensor H10(D[10], D[9], K, K);   H10.ones(); // Layer 10
	Tensor H11(D[11], D[10], K, K);  H11.ones(); // Layer 11
	//Tensor H12(D[12], D[11], K, K);  H12.ones(); // Layer 12 - Pool

	/// Section 5 - layers 13-18: conv(5x)-pool
	Tensor H13(D[13], D[12], K, K);  H13.ones(); // Layer 13
	Tensor H14(D[14], D[13], K, K);  H14.ones(); // Layer 14
	Tensor H15(D[15], D[14], K, K);  H15.ones(); // Layer 15
	Tensor H16(D[16], D[15], K, K);  H16.ones(); // Layer 16
	Tensor H17(D[17], D[16], K, K);  H17.ones(); // Layer 17
	//Tensor H18(D[18], D[17], K, K);  H18.ones(); // Layer 18 - Pool

/// Section 6 - layers 19-23: conv(5x)
	Tensor H19(D[18], D[17], K, K);  H19.ones(); // Layer 19
	Tensor H20(D[19], D[18], K, K);  H20.ones(); // Layer 20
	Tensor H21(D[20], D[19], K, K);  H21.ones(); // Layer 21 
	Tensor H22(D[21], D[20], K, K);  H22.ones(); // Layer 22
	Tensor H23(D[22], D[21], K, K);  H23.ones(); // Layer 23
*/
	// Start CPU Timing
	LARGE_INTEGER start_CPU, end_CPU, frequency_CPU;
	double milliseconds_CPU, seconds_CPU, minutes_CPU;
	QueryPerformanceFrequency(&frequency_CPU);
	QueryPerformanceCounter(&start_CPU);

	// |-----------section 1-----------|--------section 2---------|------------------------section 3------------------------|------------------section 4------------------------|------------------------------section 5------------------------------------|
	// Layer:   1              2              3            4              5              6             7              8             9           10          11            12          13            14           15           16           17           18
	//         conv           max           conv          max           conv           conv          conv            max          conv         conv        conv          max         conv          conv         conv         conv         conv         max 
	// 416x416x3 -> 416x416x32 -> 208x208x32 -> 208x208x64 -> 104x104x64 -> 104x104x128 -> 104x104x64 ->  104x104x128 -> 52x52x128 -> 52x52x256 -> 52x52x128 -> 52x52x256 -> 26x26x256 -> 26x26x512 -> 26x26x256 -> 26x26x512 -> 26x26x256 -> 26x26x512 -> ...
	//  D[0]=3       D[1]=32        D[2]=32       D[3]=64       D[4]=64       D[5]=128       D[6]=64        D[7]=128     D[8]=128      D[9]=256    D[10]=128    D[11]=256    D[12]=256    D[13]=512    D[14]=256    D[15]=512    D[16]=256    D[17]=512
	
	//                                                         FEATURE-EXTRACTION   | DETECTION
	//                conv         conv          conv          conv         conv          conv          conv          route conv reorg route conv conv detection
	// ...-> 13x13x512 -> 13x13x1024 -> 13x13x512 -> 13x13x1024 -> 13x13x512 -> 13x13x1024 -> 13x13x1024 -> 13x13x1024 -> 
	//       D[18]=512    D[19]=1024    D[20]=512    D[21]=1024    D[22]=512    D[23]=1024    D[24]=1024    D[25]=1024
	//  |---------------------------section 6---------------------------------------|------------------------------section 5------------------------------------|

	// -----------
	// Section 1:
	// -----------
	cout << "Section 1: layers 1-2" << R[0] << "x" << C[0] << "x" << D[0] << " -> " << R[1] << "x" << C[1] << "x" << D[1] << " -> " << R[2] << "x" << C[2] << "x" << D[2] << "\n";
	cout << "From Darknet: 416x416x3 -> 416x416x32 -> 208x208x32 \n";
	FeatureMap A1 = pool_max(relu(conv(X, H1)));

	// -----------
	// Section 2:
	// -----------
	cout << "\nSection 2: layers 3-4" << R[2] << "x" << C[2] << "x" << D[2] << " -> " << R[3] << "x" << C[3] << "x" << D[3] << " -> " << R[4] << "x" << C[4] << "x" << D[4] << "\n";
	cout << "From Darknet: 208x208x32 -> 208x208x64 -> 104x104x64 \n";
	FeatureMap A3 = pool_max(relu(conv(A1, H3)));

	/*

	// -----------
	// Section 3:
	// -----------
	cout << "\nSection 3: layers 5-8" << R[4] << "x" << C[4] << "x" << D[4] << " -> " << R[5] << "x" << C[5] << "x" << D[5] << " -> " << R[6] << "x" << C[6] << "x" << D[6]
		<< " -> " << R[7] << "x" << C[7] << "x" << D[7] << " -> " << R[8] << "x" << C[8] << "x" << D[8] << "\n";
	cout << "From Darknet: 104x104x64 -> 104x104x128 -> 104x104x64 ->  104x104x128 -> 52x52x128 \n";
	FeatureMap A5 = relu(conv(A3, H5));
	FeatureMap A6 = relu(conv(A5, H6));
	FeatureMap A7 = relu(conv(A6, H7));
	FeatureMap A8 = pool_max(A7);

	// -----------
	// Section 4:
	// -----------
	cout << "\nSection 4: layers 9-12" << R[8] << "x" << C[8] << "x" << D[8] << " -> " << R[9] << "x" << C[9] << "x" << D[9] << " -> " << R[10] << "x" << C[10] << "x" << D[10]
		<< " -> " << R[11] << "x" << C[11] << "x" << D[11] << " -> " << R[12] << "x" << C[12] << "x" << D[12] << "\n";
	cout << "From Darknet: 52x52x128 -> 52x52x256 -> 52x52x128 -> 52x52x256 -> 26x26x256 \n";
	FeatureMap A9 = relu(conv(A8, H9));
	FeatureMap A10 = relu(conv(A9, H10));
	FeatureMap A11 = relu(conv(A10, H11));
	FeatureMap A12 = pool_max(A11);

	// -----------
	// Section 5:
	// -----------
	cout << "\nSection 5: layers 13-18" << R[12] << "x" << C[12] << "x" << D[12] << " -> " << R[13] << "x" << C[13] << "x" << D[13] << " -> " << R[14] << "x" << C[14] << "x" << D[14]
		<< " -> " << R[15] << "x" << C[15] << "x" << D[15] << " -> " << R[16] << "x" << C[16] << "x" << D[16]
		<< " -> " << R[17] << "x" << C[17] << "x" << D[17] << " -> " << R[18] << "x" << C[18] << "x" << D[18] << "\n";
	cout << "From Darknet: 26x26x256 -> 26x26x512 -> 26x26x256 -> 26x26x512 -> 26x26x256 -> 26x26x512 -> 13x13x512 \n";
	FeatureMap A13 = relu(conv(A12, H13));
	FeatureMap A14 = relu(conv(A13, H14));
	FeatureMap A15 = relu(conv(A14, H15));
	FeatureMap A16 = relu(conv(A15, H16));
	FeatureMap A17 = relu(conv(A16, H17));
	FeatureMap A18 = pool_max(A17);

	// -----------
	// Section 6:
	// -----------
	cout << "\nSection 6: layers 19-23" << R[18] << "x" << C[18] << "x" << D[18] << " -> " << R[19] << "x" << C[19] << "x" << D[19] << " -> "
		<< " -> " << R[20] << "x" << C[20] << "x" << D[20] << " -> " << R[21] << "x" << C[21] << "x" << D[21]
		<< " -> " << R[22] << "x" << C[22] << "x" << D[22] << " -> " << R[23] << "x" << C[23] << "x" << D[23] << "\n";
	cout << "From Darknet: 13x13x512 -> 13x13x1024 -> 13x13x512 -> 13x13x1024 -> 13x13x512 -> 13x13x1024 \n";
	FeatureMap A19 = relu(conv(A18, H19));
	FeatureMap A20 = relu(conv(A19, H20));
	FeatureMap A21 = relu(conv(A20, H21));
	FeatureMap A22 = relu(conv(A21, H22));
	FeatureMap A23 = relu(conv(A22, H23));

	// End CPU Timing
	QueryPerformanceCounter(&end_CPU);
	milliseconds_CPU = (end_CPU.QuadPart - start_CPU.QuadPart) *
		1000.0 / frequency_CPU.QuadPart;
	seconds_CPU = milliseconds_CPU / 1000;
	minutes_CPU = seconds_CPU / 60;
	fprintf(stderr, "\nCPU Time = %.3f milliseconds", milliseconds_CPU);
	fprintf(stderr, "\nCPU Time = %.3f seconds", seconds_CPU);
	fprintf(stderr, "\nCPU Time = %.3f minutes\n\n", minutes_CPU);
	*/
	cout << "\n\nCompleted CNN\n\n";
	getchar();


    const int arraySize = 5;
    const int a[arraySize] = { 1, 2, 3, 4, 5 };
    const int b[arraySize] = { 10, 20, 30, 40, 50 };
    int c[arraySize] = { 0 };

    // Add vectors in parallel.
    cudaError_t cudaStatus = addWithCuda(c, a, b, arraySize);
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "addWithCuda failed!");
        return 1;
    }

    printf("{1,2,3,4,5} + {10,20,30,40,50} = {%d,%d,%d,%d,%d}\n",
        c[0], c[1], c[2], c[3], c[4]);

    // cudaDeviceReset must be called before exiting in order for profiling and
    // tracing tools such as Nsight and Visual Profiler to show complete traces.
    cudaStatus = cudaDeviceReset();
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaDeviceReset failed!");
        return 1;
    }

    return 0;
}
