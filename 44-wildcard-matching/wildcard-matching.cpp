class Solution {
public:
    bool isMatch(string s, string p)
{
    int n = s.size();
    int m = p.size();
    vector<int>next(m+1);
    vector<int>curr(m+1);

    next[m] =1;
    for(int j = m-1; j>=0; j--){
        if(p[j]=='*') next[j]= next[j+1];
        else next[j] = 0;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        curr[m] = 0;
        for (int j = m - 1; j >= 0; j--)
        {
            if (s[i] == p[j] || p[j] == '?')
                curr[j] = next[j + 1];

            else if (p[j] == '*')
            {
                curr[j] = curr[j + 1] || next[j];
            }
            else
            {
                curr[j] = 0;
            }
        }
        next = curr;
    }

    return next[0];
}
};