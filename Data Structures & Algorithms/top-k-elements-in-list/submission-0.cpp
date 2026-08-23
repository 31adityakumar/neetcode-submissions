class Solution {
public:
    struct compare{
        bool operator()(const pair<int, int>& a, const pair<int, int>& b){
            return a.second<b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for(auto it : nums){
            freq[it]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;

        for(auto f : freq){
            pq.push({f.first,f.second});
        }

        vector<int> res;

        while(k-- > 0){
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};