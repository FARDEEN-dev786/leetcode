class Solution {
public:
    bool checkInclusion(string s1, string s2)
{
    unordered_map<char, int> mainmpp;
    unordered_map<char, int> tempmpp;
    int low = 0;
    int k = s1.size();
    int high = k - 1;
    int n = s2.size();
    if (s1.size() > s2.size())
    {
        return false;
    }
    for (int i = 0; i < k; i++)
    {
        mainmpp[s1[i]]++;
        tempmpp[s2[i]]++;
    }
    while (high < s2.size())
    {
        if (mainmpp == tempmpp)
        {
            return true;
        }
        else
        {
            tempmpp[s2[low]]--;
            if(tempmpp[s2[low]]==0){
                tempmpp.erase(s2[low]);
            }
            low++;
            high++;
            if (high < n)
            {
                tempmpp[s2[high]]++;
            }
        }
    }
    return false;
}
};