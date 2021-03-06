#include "comm_header.h"

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (0 == prices.size())
            return 0;
        int maxProfit = 0;

        bool bWantToBuy = true; // false means want to sell

        int buyPrice = 0;

        for (int i = 0; i < prices.size(); i++)
        {
            if (i + 1 < prices.size())
            {
                int nextPrice = prices[i + 1];
                if (bWantToBuy && nextPrice > prices[i])
                {
                    bWantToBuy = false;
                    buyPrice = prices[i];
                }

                if (!bWantToBuy && nextPrice < prices[i])
                {
                    bWantToBuy = true;
                    maxProfit += (prices[i] - buyPrice);
                }
            }
            else //reach the last element
            {
                if (!bWantToBuy && prices[i] > buyPrice)
                {
                    maxProfit += prices[i] - buyPrice;
                    bWantToBuy = true;
                }
            }
        }

        return maxProfit;
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
        vector<int> prices = stringToIntegerVector(line);

        int ret = Solution().maxProfit(prices);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}