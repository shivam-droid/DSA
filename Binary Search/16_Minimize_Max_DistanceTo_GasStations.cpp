class Solution {
  public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        int n = stations.size();
        vector<int> howmany(n-1,0);
        priority_queue<pair<double,int>> pq;
        for(int i=0;i<n-1;i++)
        {
            pq.push({(double)(stations[i+1]-stations[i]),i});
        }
        for(int i=1;i<=k;i++)
        {
            auto it = pq.top();
            pq.pop();
            howmany[it.second]++;
            double totald = (stations[it.second+1]-stations[it.second]);
            double newd = (totald/(double)(howmany[it.second]+1));
            pq.push({newd,it.second});
        }
        return (pq.top().first + 1e-4);
    }
};