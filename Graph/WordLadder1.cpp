class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);

        while(!q.empty()) {
            auto u = q.front();
            q.pop(); 
            string word = u.first;
            int place = u.second;
            if(word==endWord) return place;
            for(int i=0; i<word.size(); i++) {
                char original = word[i];
                for(char c = 'a'; c<='z'; c++) {
                    if(c!=original) {
                        string testWord = word;
                        testWord[i] =c;
                        if(st.find(testWord)!=st.end()) {
                            q.push({testWord, place+1});
                            st.erase(testWord);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
