/*You are given a primitive calculator that can perform the following three operations with
the current number x: multiply x by 2, multiply x by 3, or add 1 to x. Your goal is given a
positive integer n, find the minimum number of operations needed to obtain the number n
starting from the number 1.*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long> v;

long minimum(long d1,long d2,long d3)
{
	if(d1<=d2 && d1<=d3)
		return d1;

	if(d2<=d1 && d2<=d3)
			return d2;

	if(d3<=d1 && d3<=d2)
			return d3;
}


long primitive_calc(long n)
{  long d1 = 100000000,d2 =100000000,d3 =100000000,min=99999999,p;

    if(n < v.size())
	  return v[n];

    if(n%3==0 && d1!=99999999)
    d1 = primitive_calc(n/3) +1;
    else if(n%3!=0) d1 = 99999999;
    if(d1<min)
    	{
    	 min =d1;
    	 p = n/3;
    	}

    if(n%2 == 0 && d2!=99999999)
    d2 = primitive_calc(n/2) +1;
    else if(n%2!=0) d2 = 99999999;
    if(d2<min)
    	{
    	   min =d2;
    	   p=n/2;
    	}

    if(n - 1 >= 0 && d3!=99999999)
    d3 = primitive_calc(n -1) +1;
    else if(n-1<0) d3 = 99999999;
    if(d3<min)
    	{
    	  min=d3;
    	  p=n-1;
    	}

    if(d1 == 100000000)
    	d1=99999999;
    if(d2==100000000)
    	d2=99999999;
    if(d3==100000000)
    	d3=99999999;


    long x = minimum(d1,d2,d3);
    v.push_back(x);

   return x;

}

int main()
{   long n;
     cin>>n;

     v.push_back(0);
     v.push_back(1);
     v.push_back(1);
     v.push_back(1);

     cout<<primitive_calc(n);
     cout<<endl;


	return 0;
}

