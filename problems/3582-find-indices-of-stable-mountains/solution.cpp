class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        int n=height.size();
        vector<int> stable;
        for (int i=1;i<n;i++){
            if (height[i-1]>threshold) stable.push_back(i);
        }
        return stable;
    }
};
