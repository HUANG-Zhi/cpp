#include <iostream>
#include <cassert>
using namespace std;
class bitmap
{
private:
	int size;
	int ecount;
	static const char bytesmap[8];
	char* mem;
public:
	bitmap(int _size){
		size = _size;
		ecount = (size + 8 - 1) / 8;
		cout << "new bitmap:"<< size << "," << 8 << "," << ecount << endl;
		mem = new char[ecount]();
	}
	~bitmap(){
		delete [] mem;
	}
	bool getbit(int pos){
		assert(pos <= size && pos > 0);
		return mem[(pos - 1) / 8] & bytesmap[pos - 1];
	}
	void setbit(int pos){
		assert(pos <= size && pos > 0);
		mem[(pos - 1) / 8] = mem[(pos - 1) / 8] | bytesmap[pos - 1];
	}
	void unsetbit(int pos){
		assert(pos <= size && pos > 0);
		mem[(pos - 1) / 8] = mem[(pos - 1) / 8] & (~bytesmap[pos - 1]);
	}
};
const char bitmap::bytesmap[8] = {1,2,4,8,16,32,64,128};

int main(int argc, char const *argv[])
{
	//cout << ~2 << "," << ~0;
	const int size = 17;
	bitmap* bm = new bitmap(size);
	int cmd = 0,pos = 0;
	while(cin >> cmd >> pos){
		assert(cmd == 0 || cmd == 1 || cmd == -1);
		assert(pos > 0 && pos <= size);
		switch(cmd){
			case 0:bm->unsetbit(pos);
			break;
			case 1:bm->setbit(pos);
			break;
			case -1:cout << bm->getbit(pos) << endl;
		}
	}
	return 0;
}