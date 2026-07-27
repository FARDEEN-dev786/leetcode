class Solution {
public:
    long long timeu(vector<int>& arr, int n, int speed){
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans + arr[i]/speed ;
        if(arr[i]%speed != 0){
            ans+=1;
        }
    }
    return ans;
    
}
int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());
    int res = -1;
    while (low <= high)
    {
        int guess = (low+high)/2;
        if(timeu(piles,piles.size(),guess) <= h){
            res = guess;
            high = guess-1;
        }
        else{
            low = guess +1;
        }
    }
    return res;
}
};