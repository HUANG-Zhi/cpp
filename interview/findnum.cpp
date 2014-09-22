#include <iostream>

 

using namespace std;

 

unsigned int foo(unsigned int a[], int n)

{

          unsigned int m[4] = {-1, 0, 0, 0}, mb;

          for(int i = 0; i < n; i++)

          {

                   mb= m[3];

                   m[3]= (m[3] & ~a[i]) | (m[2] & a[i]);

                   m[2]= (m[2] & ~a[i]) | (m[1] & a[i]);

                   m[1]= (m[1] & ~a[i]) | (m[0] & a[i]);

                   m[0]= (m[0] & ~a[i]) | (mb & a[i]);

          }

          return m[2];

}

 

int main()

{

          unsigned int test[] = {5,1,2,5,2,2,2,1,1,1,3,3,3,3};

          unsigned int rt;

          rt= foo(test, 14);

          cout<< rt << endl;

          return 0;

}