#include <initializer_list>

class vector {
	int sz;
	double* elem;
public:
	vector(int size);
	vector(std::initializer_list<double> lst);
	~vector();
};