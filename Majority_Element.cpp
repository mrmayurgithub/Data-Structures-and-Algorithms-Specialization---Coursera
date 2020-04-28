#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

 int count(const vector<int> &a, int left, int right, int element)
{
	 int count = 0;
	for (unsigned int i = left; i <= right; i++)
	{
		if (a[i] == element)
		{
			count++;
		}
	}
	return count;
}

int majority_element(vector<int> &a, int l, int r) {


	if (l > r) return -1;
	if (l == r) return a[l];
	int mid = l + (r - l) / 2;
	int l_Count = majority_element(a, l, mid);
	int r_Count = majority_element(a, mid + 1, r);

	if (l_Count == -1 && r_Count != -1)
	{
		int num = count(a, l, r, r_Count);
		if (num > (r - l + 1) / 2)
		return r_Count;

		else
		return -1;
    }

	else if (r_Count == -1 && l_Count != -1)
	{
		unsigned int num = count(a, l, r, l_Count);
		if (num > (r - l + 1) / 2)
		return l_Count;

		else
		return -1;
   }

	else if (l_Count != -1 && r_Count != -1)
	{
		unsigned int leftNum = count(a, l, r, l_Count);
		unsigned int rightNum = count(a, l, r, r_Count);

		if (leftNum > (r - l + 1) / 2)
		return l_Count;

		else if (rightNum > (r - l + 1) / 2)
		return r_Count;

		else
		return -1;
	}
	else
	return -1;

}


int main() {
	int n;
	  cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); ++i) {
		  cin >> a[i];
	}
	  cout << majority_element(a, 0, a.size() - 1)  << '\n';
}

