class Solution {
    public:
      string findOrder(vector<string> &words) {
          int m = words.size();
          vector<vector<int>> adjList(26); // Fixed: Initialized size
          
          unordered_set<char> uniqueChars;
          for (string word : words) {
              for (char c : word) {
                  uniqueChars.insert(c); // Track all unique characters
              }
          }
          
          for(int i = 0; i < m - 1; i++) {
              string s1 = words[i];
              string s2 = words[i + 1];
  
              // Edge case: Prefix issue (e.g., "abc" -> "ab" is invalid)
              if (s1.size() > s2.size() && s1.substr(0, s2.size()) == s2) {
                  return "";
              }
  
              int len = min(s1.size(), s2.size());
              for (int k = 0; k < len; k++) {
                  if (s1[k] != s2[k]) {
                      adjList[s1[k] - 'a'].push_back(s2[k] - 'a');
                      break;
                  }
              }
          }
          
          int n = uniqueChars.size(); // Fixed: Use number of unique characters
          vector<int> indegree(26, 0);
          
          for (int i = 0; i < 26; i++) {
              for (int it : adjList[i]) {
                  indegree[it]++;
              }
          }
          
          queue<int> q;
          for (char c : uniqueChars) {
              if (indegree[c - 'a'] == 0) {
                  q.push(c - 'a');
              }
          }
  
          vector<int> topo;
          while (!q.empty()) {
              int node = q.front();
              q.pop();
              topo.push_back(node);
              for (int it : adjList[node]) {
                  indegree[it]--;
                  if (indegree[it] == 0) {
                      q.push(it);
                  }
              }
          }
          
          if (topo.size() != uniqueChars.size()) return ""; // Cycle detected
          
          string ans = "";
          for (int it : topo) {
              ans += char(it + 'a');
          }
          
          return ans;
      }
  };