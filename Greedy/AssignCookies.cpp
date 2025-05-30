class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int result = 0;
	    sort(g.begin(), g.end());
	    sort(s.begin(), s.end());
	    int gS=0, sS=0;
	    while(gS<g.size() && sS<s.size()) {
	    	if(g[gS]<=s[sS]) {
                gS++; sS++; result++;
            }
	    	else sS++;
	    }
	    return result;
    }
};
