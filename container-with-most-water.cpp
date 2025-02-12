#include<iostream>
#include<vector>
using namespace std;

class Solution { //greedy algoritam, raboti za site test slucai
    public:
        int maxArea(vector<int>& height) {
            int left=0, right=height.size()-1;
            int maxi=0;
            while (left < right)
            {
                int x = min(height[left], height[right]);
                maxi = max(maxi, (right-left)*x);
                if (height[left] > height[right])
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
            return maxi;
        }
    };

    class Solution { //brute force algoritam, rabori za 58/65 test slucai
        public:
            int maxArea(vector<int>& height) {
                int maxSize=1;
                if (height.size()==2)
                {
                    return min(height[0], height[1]);
                }
                for (int i=0; i<height.size(); i++)
                {
                    int curr=0;
                    for (int j=i+1; j<height.size(); j++)
                    {
                        int temp=(j-i)*min(height[i],height[j]);
                        if (curr < temp)
                        {
                            curr = temp;
                        }
                    }
                   if (curr > maxSize)
                   {
                    maxSize = curr;
                   }
                }
                return maxSize;
            }
        };

int main()
{
    return 0;
}