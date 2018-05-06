#include <iostream>
using std::cout;
using std::endl;
//===================
template <typename T>
class FeatureMap {
public:
	FeatureMap() {}
	FeatureMap(size_t rows, size_t cols, size_t chs)
		: rows(rows), cols(cols), chs(chs) {
		fm = new float[rows * cols * chs];
		for (size_t i = 0; i < rows; ++i) {
			for (size_t j = 0; j < cols; ++j) {
				for (size_t k = 0; k < chs; ++k) {
					fm[i * cols * chs + j * chs + k] = i * cols * chs + j * chs + k;
				}
			}
		}
	}
	~FeatureMap() {
		delete[] fm;
	}
	float at(size_t x, size_t y, size_t z) {
		return fm[x * cols * chs + y * chs + z];
	}
	void print() {

	}
	//private:
	size_t rows{ 0 };
	size_t cols{ 0 };
	size_t chs{ 0 };
	float* fm = nullptr;
};
//========
int main()
{
	cout << " DEBUG";

	//     conv      pool
	// 4x4x1 -> 4x4x2 -> 2x2x2
	const size_t R[3] = { 4, 4, 2 };
	const size_t C[3] = { 4, 4, 2 };
	const size_t D[3] = { 1, 2, 2 };

	FeatureMap<float> fm(R[0], C[0], D[0]);
	
	for (size_t i = 0; i < fm.rows; ++i) {
		for (size_t j = 0; j < fm.cols; ++j) {
			for (size_t k = 0; k < fm.chs; ++k) {
				cout << fm.at(i, j, k) << " ";
			}
		}
		cout << endl;
	}


	getchar();
	return 0;
}
