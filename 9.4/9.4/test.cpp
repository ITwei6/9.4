//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target)
//    {
//        //使用双指针算法
//        int left = 0, right = nums.size() - 1;
//        while (left < right)
//        {
//            if (nums[left] + nums[right] > target)
//                --right;
//            else if (nums[left] + nums[right] < target)
//                ++left;
//            else
//                return { nums[left],nums[right] };
//            //大括号，这样写会发生隐射类型转化，调用vector的构造函数来构造
//        }
//        return { -1,-1 };
//    }
//};
//class Solution {
//public:
//    int lower(int x, int y)
//    {
//        if (x < y)
//            return x;
//        else
//            return y;
//    }
//    int maxArea(vector<int>& height)
//    {
//        vector<int> vt;
//        int left = 0, right = height.size() - 1, V = 0;
//        while (left < right)
//        {
//            V = (right - left) * (lower(height[left], height[right]));
//            vt.push_back(V);
//            if (height[left] < height[right])
//                ++left;
//            else
//                --right;
//        }
//
//        sort(vt.begin(), vt.end());
//        return vt[vt.size() - 1];
//    }
//};
//class Solution
//{
//public:
//
//    int work(int n)
//    {
//        int ret = 0;
//        while (n)
//        {
//            ret += (n % 10) * (n % 10);
//            n = n / 10;
//        }
//        return ret;
//    }
//    bool isHappy(int n)
//    {
//
//        int slow = n, fast = n;
//        //判断快慢指针相遇
//        while (slow && fast)
//        {
//            slow = work(slow);
//            //慢指针每次走1次操作
//            fast = work(work(fast));
//            //快指针每次走2次操作
//            if (fast == slow)
//            {
//                if (fast == 1)
//                    return true;
//                else
//                    return false;
//            }
//        }
//        return false;
//    }
//};
//class Solution {
//public:
//
//
//    //双指针：本质就是划分数组，数组分块
//    //cur:用来遍历数组，将数组分成两个部分，[o,cur-1]已经处理的部分[cur,n-1]待处理的部分
//    //已经处理的部分要求是什么呢？非0元素在前面，0元素在后面，那么我们利用dest指针来作为它们的分割线
//    //dest:已经处理的部分又被dest分割成两部分，[0,dest]是非0部分，而[dest+1,cur-1]就是0部分
//    //所以数组总体被分成三部分
//    void moveZeroes(vector<int>& nums) {
//
//        int cur = 0;
//        int dest = cur - 1;
//
//        while (cur < nums.size())
//        {
//            if (nums[cur] == 0)
//            {
//                //当遇到0时不需要放入des区间，因为des区间里都是非0的
//                cur++;
//            }
//            else
//            {
//                //当遇到非0时，就需要放入des区间，放进一个元素dest就要往后挪动一下，流出位置
//                //但不能覆盖要交换
//                dest++;
//                swap(nums[dest], nums[cur]);
//                cur++;
//            }
//        }
//
//    }
//};
//class Solution {
//public:
//    void duplicateZeros(vector<int>& arr)
//    {
//        //首先找到可以复写的最后一个数据
//        int cur = 0;
//        int dest = cur - 1;
//        //首先判断cur上的数据是什么
//        //while (dest < (int)arr.size() - 1)
//        //{
//        //    if (arr[cur])
//        //    {
//        //        //cur位置上的数据不等于0，那么dest就走1步
//        //        ++dest;
//        //        //每次dest走完后都要判断一下，走没走到尽头,如果走到尽头了就停止
//        //    }
//        //    else
//        //    {
//        //        //cur位置上的数据等于0，那么dest就要走2步
//        //        dest += 2;
//        //    }
//        //    if (dest <(int)arr.size() - 1)
//        //        cur++;
//        //}
//        while (cur < arr.size())
//        {
//            if (arr[cur])
//            {
//                //cur位置上的数据不等于0，那么dest就走1步
//                ++dest;
//                //每次dest走完后都要判断一下，走没走到尽头,如果走到尽头了就停止
//            }
//            else
//            {
//                //cur位置上的数据等于0，那么dest就要走2步
//                dest += 2;
//            }
//            if (dest >= arr.size() - 1)
//                break;
//            cur++;
//        }
//        //找到后，cur和dest的位置都不需要改变，因为我们就是从后往前覆盖，而且cur而dest的位置正好
//        //不过要注意dest可能会越界的情况，需要特性处理
//        if (dest == arr.size())//这个就是越界情况了
//        {
//            arr[arr.size() - 1] = 0;
//            dest -= 2;
//            cur--;
//        }
//        while (dest > 0)
//        {
//            if (arr[cur])//如果cur位置上是非0，那么就将该位置覆盖到dest位置上
//            {
//                arr[dest] = arr[cur];
//                cur--;
//                dest--;
//            }
//            else
//            {
//                arr[dest--] = 0;
//                arr[dest--] = 0;
//                cur--;
//            }
//        }
//
//    }
//
//};
#include <vector>
using namespace std;
#include <algorithm>

int main()
{
         vector<int> nums = { -2,0,1,1,2 };
        //首先优化数组，对数组排序
        sort(nums.begin(), nums.end());
        //首先固定一个元素a，对后面的区间使用双指针算法，筛选
        //筛选的过程中要注意去重

        int ti = 0;
        vector<vector<int>> vv;
        while (ti < nums.size()-1)
        {
            //对后面的区间使用双指针算法
            int left = ti + 1, right = nums.size() - 1, target = -nums[ti];
            while (left < right)
            {
                if (nums[left] + nums[right] > target)
                {
                    right--;
                }
                else if (nums[left] + nums[right] < target)
                {
                    left++;
                }
                else//说明找到这个三元组了
                {
                    vv.push_back({ nums[ti],nums[left],nums[right] });
                    //当找到一对满足条件的元素时，left和right要同时挪动,接下剩下的区间继续寻找
                    //但要根据要去重，我们得注意下次如果再遇到上次的元素还是直接跳过去
                    left++;
                    right--;
                    while (nums[left] == nums[left-1]&&nums[right]==nums[right+1] && left<right)
                    {
                        left++;
                        right--;
                    }
                }
            }
            //最后还要注意对固定的元素进行去重，因为当固定相同的元素时，也会出现重复的
            int later = ti;
            ++ti;
            while (nums[later] == nums[ti]&&ti<nums.size()-1)
                ++ti;
        }
    
    
}
