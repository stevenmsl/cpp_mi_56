#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "interval.h"
#include "util.h"

using namespace std;
using namespace sol56;

/* Example 1:
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
*/
tuple<vector<Interval>, vector<Interval>>
testFixture1()
{
  auto input = vector<Interval>{
      {1, 3}, {2, 6}, {8, 10}, {15, 18}};

  auto output = vector<Interval>{
      {1, 6}, {8, 10}, {15, 18}};

  return make_tuple(input, output);
}

/* Example 2:
Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

*/
tuple<vector<Interval>, vector<Interval>>
testFixture2()
{
  auto input = vector<Interval>{
      {1, 4}, {4, 5}};

  auto output = vector<Interval>{
      {1, 5}};

  return make_tuple(input, output);
}
void test1()
{
  auto f = testFixture1();
  auto input = get<1>(f);
  auto iv = vector<vector<int>>();
  for (auto i : input)
    iv.push_back(vector<int>{i.start, i.end});

  cout << "Expect to see: " << Util::toString(iv) << endl;

  Solution sol;
  auto output = sol.merge(input);

  auto ov = vector<vector<int>>();
  for (auto o : output)
    ov.push_back(vector<int>{o.start, o.end});

  cout << Util::toString(ov) << endl;
}

void test2()
{
  auto f = testFixture2();
  auto input = get<1>(f);
  auto iv = vector<vector<int>>();
  for (auto i : input)
    iv.push_back(vector<int>{i.start, i.end});

  cout << "Expect to see: " << Util::toString(iv) << endl;

  Solution sol;
  auto output = sol.merge(input);

  auto ov = vector<vector<int>>();
  for (auto o : output)
    ov.push_back(vector<int>{o.start, o.end});

  cout << Util::toString(ov) << endl;
}

main()
{
  test1();
  test2();

  return 0;
}