/*The edit distance between two strings is the minimum number of operations (insertions, deletions, and
substitutions of symbols) to transform one string into another. It is a measure of similarity of two strings.
Edit distance has applications, for example, in computational biology, natural language processing, and spell
checking. Your goal in this problem is to compute the edit distance between two strings.*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

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
int Edit_distance(const string s1, const string s2)
{
	int size1 = s1.length()+1, size2 = s2.length()+1,ins,rem,rep;
	 vector<vector<int> > editDist(size1,vector<int>(size2,0));

	for(int i = 0; i<size1; i++)
	  editDist[i][0] = i;

	for(int i = 0; i<size2; i++)
		  editDist[0][i] = i;

	for(int i = 1; i<size1; i++)
	{
		for(int j = 1; j<size2; j++)
		{
		     ins = 1 + editDist[i-1][j];
			 rem = editDist[i][j-1] +1;
			 rep = editDist[i-1][j-1] ;

			if(s1[i-1] != s2[j-1])
				++rep;
		    editDist[i][j] = minimum(ins,rem,rep);
		}
	}

   return editDist[size1-1][size2-1];
}

int main()
{
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	cout<<Edit_distance(s1,s2);

}

