#imort "vector.h"

vector::vector(int size) : sz{size}, elem{new double[sz]} {
	for(int i = 0; i < size; ++i) {
		elem[i] = 0.0;
	}
}

vector::vector(std::initializer_list<double>lst) : sz{lst.size()}, elem{new double[sz]} {
	copy(lst.begin(), lst.end(), elem);
}

vector::~vector() {
	delete[] elem;
}