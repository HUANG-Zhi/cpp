#include <iostream>
#include <vector>
using namespace std;
 
//----------------------------
//Returns a vector containing the zero based index of 
//  the start of each match of the string K in S.
//  Matches may overlap
//----------------------------
vector<int> KMP(string S, string K)
{
    vector<int> T(K.size() + 1, -1);
	vector<int> matches;
 
        if(K.size() == 0)
        {
            matches.push_back(0);
            return matches;
        }
	for(int i = 1; i <= K.size(); i++)
	{
		int pos = T[i - 1];
		while(pos != -1 && K[pos] != K[i - 1]) pos = T[pos];
		T[i] = pos + 1;
	}

	for (std::vector<int>::iterator i = T.begin(); i != T.end(); ++i)
	{
		cout << *i << " ";	
	}
	cout << endl;
 
	int sp = 0;
	int kp = 0;
	while(sp < S.size())
	{
		while(kp != -1 && (kp == K.size() || K[kp] != S[sp])) kp = T[kp];
		kp++;
		sp++;
		if(kp == K.size()) matches.push_back(sp - K.size());
	}
 
	return matches;
}
int main(int argc, char const *argv[])
{
	/* code */
	vector<int> matches = KMP("hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh","baaaaabbbbaaahhhhh");
	for(std::vector<int>::iterator i = matches.begin(); i != matches.end() ; ++i){
		cout << *i << " ";
	}
	cout << endl;
	return 0;
}