class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        deque<pair<string,int>> mpp;
        
        mpp.push_back({beginWord,1});

        unordered_set<string> st(wordList.begin(),wordList.end());

        st.erase(beginWord);


        while(!mpp.empty()){

            string word = mpp.front().first;

            int steps = mpp.front().second;

            mpp.pop_front();


            if (word == endWord) return steps;


            for(int i = 0 ; i < word.size(); i++){
                char ch = word[i];
                for(int j = 'a'; j <= 'z'; j++){
                    word[i] = j;

                    if(st.find(word) != st.end()){
                        st.erase(word);
                        mpp.push_back({word,steps+1});
                    }

                }
                word[i] = ch;
            }


        }

        return 0;
        
    }
};




// Time Complexity: O(M^2 * N)
// Space Complexity: O(N)