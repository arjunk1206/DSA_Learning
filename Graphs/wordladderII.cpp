#include<bits/stdc++.h>
using namespace std;

class Solution {
    //timelimit is very strict, works for interviews.
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;
        vector<vector<string>>ans;

        if(st.find(endWord) != st.end())
        {
        while(!q.empty())
        {
            vector<string> vec = q.front();
            q.pop();
            //all words been used on every level, bfs traversal permutations done
            if(vec.size() > level)
            {
                level++;
                for(auto it: usedOnLevel)
                {
                    st.erase(it);
                }
            }

            string word = vec.back();
            for(int i = 0; i < word.size();i++)
            {
                char og = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if(st.find(word) != st.end())
                    {
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }

                word[i] = og;
            }

            if(word == endWord)
            {
                if(ans.size() == 0)
                {
                    ans.push_back(vec);
                }

                else if(ans[0].size() == vec.size())
                {
                    ans.push_back(vec);
                }
                
            }

            
        }
        }

        return ans;
    }
};