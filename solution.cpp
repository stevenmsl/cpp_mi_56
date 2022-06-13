#include "solution.h"
#include "util.h"
#include <unordered_map>
#include <algorithm> //lower_bound
#include <string>
#include <queue>
#include <sstream>
#include <functional>
#include <math.h>

#include "Interval.h"
using namespace sol56;
using namespace std;

/*takeaways
  - sort by start time
  - merge the interval
*/
vector<Interval> Solution::merge(vector<Interval> &Intervals)
{
  sort(begin(Intervals), end(Intervals), [](Interval &a, Interval &b)
       { return a.start < b.start; });

  auto result = vector<Interval>();

  for (auto i : Intervals)
  {
    /* no overlapping */
    if (result.empty() || result.back().end < i.start)
      result.push_back(i);
    /* overlapping - we only need to look at the end time
       as we already sort the intervals by the start time
    */
    else
      result.back().end = max(result.back().end, i.end);
  }

  return result;
}