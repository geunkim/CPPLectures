다음 코드에 알고리즘 추가하기

```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Point {
	int x, y;
public: 
	Point(int a, int b) : x(a), y(b) {}
};

int main(int argc, char const *argv[])
{
	vector<int> v;
	// Point ;
	// vector<Point> vp;

	v.push_back(10);
	v.push_back(2);
	v.push_back(30);
	v.push_back(40);
	v.push_back(5);
	v.push_back(7);

	// cout << v. size() << endl;

	vector<int>::iterator it;
	// for(it = v.begin(); it != v.end(); it++) 
	// 		cout << *it << endl;

	// find 
  it = find(v.begin(), v.end(), 30);
    
  cout << count(v.begin(), v.end(), 30) << endl;

  // sort
  sort(v.begin(), v.end());

  for(auto e : v) 
   	cout << e << endl;

  // max
  int m = max(v[1], v[4]);
  cout << m << endl;

  // max list
  m = max({2, 5, 1, 7, 4});
  cout << m << endl;

  // max_element
  it = max_element(v.begin(), v.end());
  cout << *it << endl;

  // swap_ranges
  // reverse
  // reverse_copy
  // fill
  // fill_n
  // adjacent_find
  // is_sorted
  // find_if
  // remove
  // remove_copy_if
  // unique
  // erase
  // suffle
  // 
 
   
   
  return 0;
}
```
