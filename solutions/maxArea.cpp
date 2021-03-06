/*
Given n non-negative integers a1, a2, ..., an ,
where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two
endpoints of line i is at (i, ai) and (i, 0).
Find two lines, which together with x-axis forms a
container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

Example:
Input: [1,8,6,2,5,4,8,3,7]
Output: 49
*/

#include "comm_header.h"

class Solution
{
  public:
    int maxArea(vector<int> &height)
    {
        /*
        int* *area = new int*[height.size()];
        for (int i = 0; i < height.size(); i++)
            area[i] = new int[height.size()]();
        */

        int maxArea = 0;

        int left = 0;
        int right = height.size() - 1;

        /*
        if height[left] < height[right], no need to compute (height[left], height[right-1]),
        because maxarea(left, [right-1,right-2,...]) must be smaller than maxarea(left, right)
        */
        while (left < right)
        {
            maxArea = max(maxArea, (right - left) * min(height[left], height[right]));
            if (height[left] > height[right])
                right--;
            else
                left++;
        }

        return maxArea;
    }
};

void trimLeftTrailingSpaces(string &input)
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
                    return !isspace(ch);
                }));
}

void trimRightTrailingSpaces(string &input)
{
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
                    return !isspace(ch);
                })
                    .base(),
                input.end());
}

vector<int> stringToIntegerVector(string input)
{
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim))
    {
        output.push_back(stoi(item));
    }
    return output;
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        vector<int> height = stringToIntegerVector(line);

        int ret = Solution().maxArea(height);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}