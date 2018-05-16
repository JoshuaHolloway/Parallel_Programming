#include "header.h"
#include <vector>
using std::vector;
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
class Layer
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

public:
	cudnnTensorDescriptor_t input_descriptor;
	cudnnTensorDescriptor_t output_descriptor;
	cudnnFilterDescriptor_t kernel_descriptor;
	cudnnConvolutionDescriptor_t convolution_descriptor;
	cudnnConvolutionFwdAlgo_t convolution_algorithm;

};
//--------------------------------------
class Network
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

private:
	cv::Mat image;
	cudnnHandle_t cudnn;

	vector<Layer> layers;

	//vector<cudnnTensorDescriptor_t> input_descriptor_vect;
	//vector<cudnnTensorDescriptor_t> output_descriptor_vect;
	//vector<cudnnFilterDescriptor_t> kernel_descriptor_vect;
	//vector<cudnnConvolutionDescriptor_t> convolution_descriptor_vect;
	//vector<cudnnConvolutionFwdAlgo_t> convolution_algorithm_vect;
		 
public:
	Network(const cv::Mat& image)
	{
		this->image = image;

		/// cuDNN Step 1: Create context object

		// Create context object

		checkCUDNN(cudnnCreate(&cudnn));
	}
	~Network()
	{
	}

	void do_stuff()
	{
		/// cuDNN Step 2: Create objects to store input tensor, output tensor, and output tensor

		// Input tensor - 1
		layers.push_back(Layer{});

		// input_descriptor_vect.push_back(cudnnTensorDescriptor_t{}); // place new one in vector
		//checkCUDNN(cudnnCreateTensorDescriptor(&input_descriptor_vect[0]));
		checkCUDNN(cudnnCreateTensorDescriptor(&layers[0].input_descriptor));

		checkCUDNN(cudnnSetTensor4dDescriptor(layers[0].input_descriptor, //input_descriptor_1,
			/*format=*/CUDNN_TENSOR_NHWC,
			/*dataType=*/CUDNN_DATA_FLOAT,
			/*batch_size=*/1,
			/*channels=*/3,
			/*image_height=*/image.rows,
			/*image_width=*/image.cols));

		// Output tensor - 1
		//output_descriptor_vect.push_back(cudnnTensorDescriptor_t{}); // place new one in vector
		
		checkCUDNN(cudnnCreateTensorDescriptor(&layers[0].output_descriptor));//output_descriptor_vect[0]));// output_descriptor_1));
		checkCUDNN(cudnnSetTensor4dDescriptor(layers[0].output_descriptor, // output_descriptor_vect[0],//output_descriptor_1,
			/*format=*/CUDNN_TENSOR_NHWC,
			/*dataType=*/CUDNN_DATA_FLOAT,
			/*batch_size=*/1,
			/*channels=*/3,
			/*image_height=*/image.rows,
			/*image_width=*/image.cols));

		// Input tensor - 2
		//cudnnTensorDescriptor_t input_descriptor_2;
		//input_descriptor_vect.push_back(cudnnTensorDescriptor_t{}); // place new one in vector
		layers.push_back(Layer{});

		checkCUDNN(cudnnCreateTensorDescriptor(&layers[1].input_descriptor));//input_descriptor_vect[1]));
		checkCUDNN(cudnnSetTensor4dDescriptor(layers[1].input_descriptor, //input_descriptor_vect[1],
			/*format=*/CUDNN_TENSOR_NHWC,
			/*dataType=*/CUDNN_DATA_FLOAT,
			/*batch_size=*/1,
			/*channels=*/3,
			/*image_height=*/image.rows,
			/*image_width=*/image.cols));

		// Copy output of 1 descriptor into input of 2 descriptor:
		//input_descriptor_vect[1] = input_descriptor_vect[0];
		layers[1].input_descriptor = layers[0].input_descriptor;

		// Filter tensor
		//cudnnFilterDescriptor_t kernel_descriptor_1;
		//kernel_descriptor_vect.push_back(cudnnFilterDescriptor_t{});


		checkCUDNN(cudnnCreateFilterDescriptor(&layers[0].kernel_descriptor));//kernel_descriptor_vect[0]));//kernel_descriptor_1));
		checkCUDNN(cudnnSetFilter4dDescriptor(layers[0].kernel_descriptor,//kernel_descriptor_vect[0],
			/*dataType=*/CUDNN_DATA_FLOAT,
			/*format=*/CUDNN_TENSOR_NCHW,
			/*out_channels=*/3,
			/*in_channels=*/3,
			/*kernel_height=*/3,
			/*kernel_width=*/3));

		// Describe the conv kernel
		//cudnnConvolutionDescriptor_t convolution_descriptor_1;
		//convolution_descriptor_vect.push_back(cudnnConvolutionDescriptor_t{});
		checkCUDNN(cudnnCreateConvolutionDescriptor(&layers[0].convolution_descriptor));//convolution_descriptor_vect[0]));//convolution_descriptor_1));
		checkCUDNN(cudnnSetConvolution2dDescriptor(layers[0].convolution_descriptor, //convolution_descriptor_vect[0],//convolution_descriptor_1,
			/*pad_height=*/1,
			/*pad_width=*/1,
			/*vertical_stride=*/1,
			/*horizontal_stride=*/1,
			/*dilation_height=*/1,
			/*dilation_width=*/1,
			/*mode=*/CUDNN_CROSS_CORRELATION,
			/*computeType=*/CUDNN_DATA_FLOAT));

		// More detailed description of the convolution algorithm we want to use:
		//cudnnConvolutionFwdAlgo_t convolution_algorithm_1;
		//convolution_algorithm_vect.push_back(cudnnConvolutionFwdAlgo_t{});
		checkCUDNN(
			cudnnGetConvolutionForwardAlgorithm(cudnn,
				layers[0].input_descriptor,//input_descriptor_vect[0], //input_descriptor_1,
				layers[0].kernel_descriptor,//kernel_descriptor_vect[0],//kernel_descriptor_1,			
				layers[0].convolution_descriptor,//convolution_descriptor_vect[0], //convolution_descriptor_1,
				layers[0].output_descriptor, //output_descriptor_vect[0], //output_descriptor_1,
				CUDNN_CONVOLUTION_FWD_PREFER_FASTEST,
				/*memoryLimitInBytes=*/0,
				&layers[0].convolution_algorithm));//convolution_algorithm_vect[0]));// convolution_algorithm_1));

		// Physical memory to operate on
		size_t workspace_bytes = 0;
		checkCUDNN(cudnnGetConvolutionForwardWorkspaceSize(cudnn,
			layers[0].input_descriptor,//input_descriptor_vect[0], //input_descriptor_1,
			layers[0].kernel_descriptor,//kernel_descriptor_vect[0],// kernel_descriptor_1,
			layers[0].convolution_descriptor,//convolution_descriptor_vect[0], //convolution_descriptor_1,
			layers[0].output_descriptor,//output_descriptor_vect[0], //output_descriptor_1,
			layers[0].convolution_algorithm,//convolution_algorithm_vect[0], // convolution_algorithm_1,
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
			layers[0].convolution_descriptor,//convolution_descriptor_vect[0], //convolution_descriptor_1,
			layers[0].input_descriptor, //input_descriptor_vect[0], //input_descriptor_1,
			layers[0].kernel_descriptor,//kernel_descriptor_vect[0],//kernel_descriptor_1,
			&batch_size,
			&channels,
			&height,
			&width);
		cout << "\n batch_size = " << batch_size << " channels = " << channels << " rows = " << height << " cols = " << width << "\n";


		// Allocate device memory
		void* d_workspace{ nullptr };
		cudaMalloc(&d_workspace, workspace_bytes);

		int image_bytes = batch_size * channels * height * width * sizeof(float);

		float* d_input_1{ nullptr };
		cudaMalloc(&d_input_1, image_bytes);
		cudaMemcpy(d_input_1, image.ptr<float>(0), image_bytes, cudaMemcpyHostToDevice);

		float* d_input_2{ nullptr };
		cudaMalloc(&d_input_2, image_bytes);
		cudaMemcpy(d_input_2, image.ptr<float>(0), image_bytes, cudaMemcpyHostToDevice);

		
		
		float* d_output_1{ nullptr };
		cudaMalloc(&d_output_1, image_bytes);
		cudaMemset(d_output_1, 0, image_bytes);



		float* d_output_2{ nullptr };
		cudaMalloc(&d_output_2, image_bytes);
		cudaMemset(d_output_2, 0, image_bytes);




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

		float* d_kernel_1{ nullptr };
		cudaMalloc(&d_kernel_1, sizeof(h_kernel));
		cudaMemcpy(d_kernel_1, h_kernel, sizeof(h_kernel), cudaMemcpyHostToDevice);

		// Do conv
		const float alpha = 1, beta = 0;
		checkCUDNN(cudnnConvolutionForward(cudnn,
			&alpha,
			layers[0].input_descriptor,//input_descriptor_vect[0], //input_descriptor_1,
			d_input_1,
			layers[0].kernel_descriptor, //kernel_descriptor_vect[0],//kernel_descriptor_1,
			d_kernel_1,
			layers[0].convolution_descriptor, //convolution_descriptor_vect[0],//convolution_descriptor_1,
			layers[0].convolution_algorithm, //convolution_algorithm_vect[0], //convolution_algorithm_1,
			d_workspace,
			workspace_bytes,
			&beta,
			layers[0].output_descriptor, //output_descriptor_vect[0], //output_descriptor_1,
			d_output_1));


		// Copy output of first layer into input of second layer
		cudaMemcpy(d_input_2, d_output_1, image_bytes, cudaMemcpyDeviceToDevice);


		// Copy DEVICE -> HOST
		float* h_output = new float[image_bytes];
		cudaMemcpy(h_output, d_output_1, image_bytes, cudaMemcpyDeviceToHost);

		// Do something with h_output ...
		save_image("convolved_img.jpg",
			h_output,
			height,
			width);

		cv::imshow("After first conv", cv::imread("convolved_img.jpg"));


		
		checkCUDNN(cudnnConvolutionForward(cudnn,
			&alpha,
			layers[1].input_descriptor,//input_descriptor_vect[1], //input_descriptor_2,
			d_input_2,
			layers[0].kernel_descriptor, //kernel_descriptor_vect[0], //kernel_descriptor_1, // change to 2
			d_kernel_1,
			layers[0].convolution_descriptor, //convolution_descriptor_vect[0], //convolution_descriptor_1,
			layers[0].convolution_algorithm,// convolution_algorithm_vect[0], //convolution_algorithm_1,
			d_workspace,
			workspace_bytes,
			&beta,
			layers[0].output_descriptor, //output_descriptor_vect[0], //output_descriptor_1, // change to 2
			d_output_2));




		// Copy DEVICE -> HOST
		//float* h_output = new float[image_bytes];
		cudaMemcpy(h_output, d_output_2, image_bytes, cudaMemcpyDeviceToHost);

		// Do something with h_output ...
		save_image("convolved_img.jpg",
			h_output,
			height,
			width);

		cv::imshow("After second conv", cv::imread("convolved_img.jpg"));
		cv::waitKey(0);

		// Free memory
		delete[] h_output;
		cudaFree(d_kernel_1);
		cudaFree(d_input_1);
		cudaFree(d_output_1);
		cudaFree(d_workspace);

		//cudnnDestroyTensorDescriptor(input_descriptor_vect[0]); //input_descriptor_1);
		//cudnnDestroyTensorDescriptor(input_descriptor_vect[1]); //input_descriptor_1);
		//cudnnDestroyTensorDescriptor(output_descriptor_1);
		//cudnnDestroyFilterDescriptor(kernel_descriptor_1);
		//cudnnDestroyConvolutionDescriptor(convolution_descriptor_1);

		cudnnDestroy(cudnn);
	}
};
//--------------------------------------
int kernel_wrapper(const cv::Mat& image)
{

	Network net(image);
	net.do_stuff();

	return 0;
}
