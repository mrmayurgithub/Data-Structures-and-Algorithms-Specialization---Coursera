//  PROBLEM-
/*You are responsible for collecting signatures from all tenants of a certain build-
ing. For each tenant, you know a period of time when he or she is at home.
You would like to collect all signatures by visiting the building as few times as
possible.
The mathematical model for this problem is the following. You are given a set
of segments on a line and your goal is to mark as few points on a line as possible
so that each segment contains at least one marked point.*/


#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

using std::vector;

struct Segment {
  int start, end;
};

int min_end(vector<Segment> a)
{
	int min = a[0].end;
	int i;
	for(i = 0; i<a.size(); i++)
	{
		if(a[i].end < min)
			min = a[i].end;
	}
	return min;
}

bool include_min(Segment a,int min)
{
		if(a.start <= min && a.end >= min)
			return true;

	return false;
}
vector<int> optimal_points(vector<Segment> &segments) {
	vector<int> points;
	while(segments.size() > 0)
  {
   	   	 int x = min_end(segments);
   	   	 points.push_back(x);
   	   	 int j = 0;
   	   	 while(j<segments.size())
   	   	    { 	if(include_min(segments[j], x))
   	   	    	{ segments.erase(segments.begin() + j); }

   	   	    	else j++;
   	   	    }
  }

  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}

