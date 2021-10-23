class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        
        int minSum = INT_MAX;
        vector<string> ans;
        for(int i=0;i<list1.size();i++)
            for(int j=0;j<list2.size();j++)
                if(list1[i]==list2[j]) {
                    if(i+j < minSum) {
                        ans.clear();
                        ans.push_back(list1[i]);
                        minSum = i+j;
                    }
                    else if(i+j==minSum)
                        ans.push_back(list1[i]);
                }
        
        
        return ans;
    }
};