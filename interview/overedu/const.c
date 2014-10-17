#include <iostream>
using namespace std;
class Obj
{
private:
	int value;
public:
	int f1() const{
		//value = value + 1;
		return value;
	}
	int f2() {
		value = value + 2;
		return value;
	}
	Obj():value(0){};
	~Obj(){};
};

int main(int argc, char const *argv[])
{
	//const Obj o1;
	Obj o1;
	cout << o1.f1() << endl;
	cout << o1.f2() << endl;
	return 0;
}