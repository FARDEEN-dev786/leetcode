class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int n = nums.size();
    vector<int> res(n);
    vector<int> parent(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    int i, j;
    for (i = 0; i < n; i++)
    {
        res[i] = 1;
        for (j = 0; j < i; j++)
        {
            if (nums[i] % nums[j] == 0 && res[j] + 1 > res[i])
            {
                res[i] = res[j] + 1;
                parent[i] = j;
            }
        }
    }
    int ans = 1;
    int index = 0;
    for (i = 0; i < n; i++)
    {
        if (ans < res[i])
        {
            index = i;
            ans = res[i];
        }
    }

    vector<int> uttar;
    uttar.push_back(nums[index]);
    for (int i = 1; i < ans; i++)
    {
        int parent_index = parent[index];
        uttar.push_back(nums[parent_index]);
        index = parent_index;
    }
    reverse(uttar.begin(), uttar.end());
    return uttar;
}
};