#include<iostream>
#include<vector>
using namespace std;

vector<int> v;

int minimum(int d1,int d2,int d3)
{
	if(d1<=d2 && d1<=d3)
		return d1;

	if(d2<=d1 && d2<=d3)
			return d2;

	if(d3<=d1 && d3<=d2)
			return d3;

	return 0;

}

int moneychange(int n)
{      
        //If minimum number of coins needed to exchange n is already    
       //stored in the vector      
	if(n<v.size())
	 return v[n];

	int x,d1,d2,d3;

	d1 = moneychange((n -1)) +1;
	if(n-3>=0)
	d2 = moneychange((n-3)) +1;
	else d2 = n+1;
	if(n-4>=0)
	d3 = moneychange((n-4)) +1;
	else d3 = n+1;

	x = minimum(d1,d2,d3);
	v.push_back(x);
	return x;

}

int main()
{
	int n;
	cin>>n;

        //Number of coins needed to give an exchange of 0, 1 and 2. 
	v.push_back(0);
        v.push_back(1);
        v.push_back(2);
	
        int x = moneychange(n);
	cout<<endl;
	cout<<endl<<<<"Number of coins - "<<x;
	return 0;
}

