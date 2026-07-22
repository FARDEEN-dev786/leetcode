class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(),g.end());    
    sort(s.begin(),s.end());    
    int g_pointer = 0;
    int s_pointer = 0;
    while (g_pointer<g.size() && s_pointer<s.size())
    {
        if(s[s_pointer]>=g[g_pointer]){
            g_pointer++;
            s_pointer++;
        }
        else{
            s_pointer++;
        }
    }
    return g_pointer;
    
}
};