class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>res;
        string ds;
        if(digits.size()==0)return res;
        string mapping[10] = {"","","abc","def","ghi","jkl",
                                "mno","pqrs","tuv","wxyz"};
        solve(digits, res, ds, mapping, 0);
        return res;
    }

    void solve(string digits, vector<string>&res, string ds, string mapping[], int i) {
        if(i>=digits.size()) {
            res.push_back(ds);
            return;
        }

        int n = digits[i]-'0';
        string val = mapping[n];

        for(int j=0; j<val.size(); j++) {
            ds.push_back(val[j]);
            solve(digits, res, ds, mapping, i+1);
            ds.pop_back();
        }
    }
};
