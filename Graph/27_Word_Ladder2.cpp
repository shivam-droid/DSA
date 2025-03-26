class Solution {
    public:
        vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
            unordered_set<string> st(wordList.begin(),wordList.end());
            queue<vector<string>> q;
            q.push({beginWord});
            vector<vector<string>> ans;
            while(!q.empty())
            {
                vector<string> vec = q.front();
                if(ans.size()!=0)
                {
                    if(vec.size()>ans[0].size())
                    {
                        break;
                    }
                }
                q.pop();
                string word = vec.back();
                if(word==endWord)
                {
                    if(ans.size()==0)
                    {
                        ans.push_back(vec);
                    }
                    else if(ans[0].size()>=vec.size())
                    {
                        ans.push_back(vec);
                    }
                }
                st.erase(word);
                for(int i=0;i<word.size();i++)
                {
                    char origin = word[i];
                    for(char c='a';c<='z';c++)
                    {
                        word[i]=c;
                        if(st.find(word)!=st.end())
                        {
                            vec.push_back(word);
                            q.push(vec);
                            vec.pop_back();
                        }
                        word[i]=origin;
                    }
                }
            }
            return ans;
        }
    };