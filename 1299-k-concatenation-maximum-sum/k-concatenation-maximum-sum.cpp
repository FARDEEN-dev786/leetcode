class Solution {
public:
    int kConcatenationMaxSum(vector<int> &arr, int k)
{
    int n = arr.size();
    int bestend = arr[0];
    int maxsum_in_arr = arr[0];
    for (int i = 1; i < n; i++)
    {
        int v1 = bestend + arr[i];
        int v2 = arr[i];
        bestend = max(v1, v2);
        maxsum_in_arr = max(maxsum_in_arr, bestend);
    }
    bestend = arr[0];
    int maxsum_from_front = arr[0];
    for (int i = 1; i < n; i++)
    {
        bestend = bestend + arr[i];
        maxsum_from_front = max(maxsum_from_front, bestend);
    }
    bestend = arr[n - 1];
    int maxsum_from_back = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        bestend = bestend + arr[i];
        maxsum_from_back = max(maxsum_from_back, bestend);
    }

    long long arraysum = 0;

    for (int i = 0; i < n; i++)
    {
        arraysum += arr[i];
    }

    if (k == 0)
        return 0;

    if (k == 1)
        return max(0, maxsum_in_arr);

    long long final_ans = max(
        (long long)maxsum_in_arr,
        (long long)maxsum_from_back + maxsum_from_front);

    if (k > 2 && arraysum > 0)
        final_ans += (long long)(k - 2) * arraysum;

    return max(0LL, final_ans) % 1000000007;
}
};