#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        vector<int> maxLex(vector<int>& nums, int k) 
        {
            int N = nums.size();
            vector<int> res;
            for (int i=0; i<N; i++) 
            {
                while (!res.empty() && nums[i] > res.back() && k-(int)res.size() <= N-i-1) 
                {
                    res.pop_back();
                }
                if (res.size() < k) res.push_back(nums[i]);
            }
            return res;
        }
        bool greater(vector<int>& nums1, vector<int>& nums2, int a, int b)
        {
            while (a < nums1.size() || b < nums2.size())
            {
                if (a >= nums1.size()) return false;
                else if (b >= nums2.size()) return true;
                else if (nums1[a] < nums2[b]) return false;
                else if (nums1[a] > nums2[b]) return true;
                else a++, b++;
            }
            return true;
        }
        vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
            vector<int> ans;
            for (int i=0; i<=k; i++) 
            {
                int j =k-i;
                if (i > nums1.size() || j > nums2.size()) continue;
                vector<int> max1 = maxLex(nums1, i);
                vector<int> max2 = maxLex(nums2, j);
                vector<int> merged;
                int a=0, b=0;
                while (a < max1.size() || b < max2.size())
                {
                    if (a >= max1.size()) merged.push_back(max2[b++]);
                    else if (b >= max2.size()) merged.push_back(max1[a++]);
                    else if (max1[a] < max2[b]) merged.push_back(max2[b++]);
                    else if (max1[a] > max2[b]) merged.push_back(max1[a++]);
                    else
                    {
                        if (greater(max1, max2, a, b)) merged.push_back(max1[a++]);
                        else merged.push_back(max2[b++]);
                    }
                }
                if (merged > ans) ans = merged;
            }
            return ans;
        }
    };

int main()
{
    
    return 0;
}