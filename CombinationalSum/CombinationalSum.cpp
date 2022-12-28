#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void findNumbers(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int> r, int i)
    {
        if (target == 0) {
            res.push_back(r);
            return;
        }

        // Recur for all remaining elements that
        // have value smaller than sum.
        while (i < candidates.size() && target - candidates[i] >= 0) {

            // Till every element in the array starting
            // from i which can contribute to the sum
            int checkorig = std::count(candidates.begin(), candidates.end(), candidates[i]);
            int checkins{};
            if (r.size() > 0)
                checkins = std::count(r.begin(), r.end(), r[i]);
            else
                checkins = 0;

            if(checkins<checkorig)
                r.push_back(candidates[i]); // add them to list

            // recursive call for next numbers
            findNumbers(candidates, target - candidates[i], res, r, i);
            i++;

            // Remove number from list (backtracking)
            r.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> r{};
        vector<vector<int>> result{};
        sort(candidates.begin(), candidates.end());
        // candidates.erase(std::unique(candidates.begin(), candidates.end()), candidates.end());      
        findNumbers(candidates, target, result, r, 0);
        return result;
    }
};

int main()
{
    Solution s;
    vector <int> v {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    s.combinationSum2(v, target);
    return 0;

}