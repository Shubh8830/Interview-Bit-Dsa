#include <bits/stdc++.h>
using namespace std;

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution
{
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval);
};

vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval)
{

    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<Interval> ans;
    int i = 0, left, right, n = intervals.size(), flag = 0;
    if (n > 0)
    {

        if (newInterval.end < intervals[0].start)
        {
            ans.push_back(newInterval);
            flag = 1;
        }
        while (i < n && intervals[i].end < newInterval.start)
        {
            ans.push_back(intervals[i]);
            i++;
        }
        if (i < n && intervals[i].start <= newInterval.end)
        {
            left = min(intervals[i].start, newInterval.start);
            right = max(intervals[i].end, newInterval.end);
            while (i < n && intervals[i].start <= newInterval.end)
            {
                left = min(left, intervals[i].start);
                right = max(right, intervals[i].end);
                i++;
            }

            Interval temp(left, right);
            ans.push_back(temp);
            flag = 1;
        }
        if (flag == 0)
        {
            ans.push_back(newInterval);
            flag = 1;
        }
        while (i < n)
        {
            ans.push_back(intervals[i]);
            i++;
        }
    }
    if (flag == 0)
    {
        ans.push_back(newInterval);
    }
    return ans;
}

int main()
{


    int t;
    cin >> t;
    while (t--)
    {
        Solution s1;
        int n;
        cin >> n;
        vector<Interval> intervals;
        int t1, t2;
        for (int i = 0; i < n; i++)
        {
            cin >> t1 >> t2;
            Interval temp(t1, t2);
            intervals.push_back(temp);
        }
        cin >> t1 >> t2;
        Interval newInterval(t1, t2);
        vector<Interval> ans;
        ans = s1.insert(intervals, newInterval);
        cout << "\nMerged Intervals are: \n";
        for (auto item : ans)
        {

            cout << item.start << " " << item.end << "\n";
        }
        cout << "\n";
    }
    return 0;
}

