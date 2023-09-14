//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target)
//    {
//        //ʹ��˫ָ���㷨
//        int left = 0, right = nums.size() - 1;
//        while (left < right)
//        {
//            if (nums[left] + nums[right] > target)
//                --right;
//            else if (nums[left] + nums[right] < target)
//                ++left;
//            else
//                return { nums[left],nums[right] };
//            //�����ţ�����д�ᷢ����������ת��������vector�Ĺ��캯��������
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
//        //�жϿ���ָ������
//        while (slow && fast)
//        {
//            slow = work(slow);
//            //��ָ��ÿ����1�β���
//            fast = work(work(fast));
//            //��ָ��ÿ����2�β���
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
//    //˫ָ�룺���ʾ��ǻ������飬����ֿ�
//    //cur:�����������飬������ֳ��������֣�[o,cur-1]�Ѿ�����Ĳ���[cur,n-1]������Ĳ���
//    //�Ѿ�����Ĳ���Ҫ����ʲô�أ���0Ԫ����ǰ�棬0Ԫ���ں��棬��ô��������destָ������Ϊ���ǵķָ���
//    //dest:�Ѿ�����Ĳ����ֱ�dest�ָ�������֣�[0,dest]�Ƿ�0���֣���[dest+1,cur-1]����0����
//    //�����������屻�ֳ�������
//    void moveZeroes(vector<int>& nums) {
//
//        int cur = 0;
//        int dest = cur - 1;
//
//        while (cur < nums.size())
//        {
//            if (nums[cur] == 0)
//            {
//                //������0ʱ����Ҫ����des���䣬��Ϊdes�����ﶼ�Ƿ�0��
//                cur++;
//            }
//            else
//            {
//                //��������0ʱ������Ҫ����des���䣬�Ž�һ��Ԫ��dest��Ҫ����Ų��һ�£�����λ��
//                //�����ܸ���Ҫ����
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
//        //�����ҵ����Ը�д�����һ������
//        int cur = 0;
//        int dest = cur - 1;
//        //�����ж�cur�ϵ�������ʲô
//        //while (dest < (int)arr.size() - 1)
//        //{
//        //    if (arr[cur])
//        //    {
//        //        //curλ���ϵ����ݲ�����0����ôdest����1��
//        //        ++dest;
//        //        //ÿ��dest�����Ҫ�ж�һ�£���û�ߵ���ͷ,����ߵ���ͷ�˾�ֹͣ
//        //    }
//        //    else
//        //    {
//        //        //curλ���ϵ����ݵ���0����ôdest��Ҫ��2��
//        //        dest += 2;
//        //    }
//        //    if (dest <(int)arr.size() - 1)
//        //        cur++;
//        //}
//        while (cur < arr.size())
//        {
//            if (arr[cur])
//            {
//                //curλ���ϵ����ݲ�����0����ôdest����1��
//                ++dest;
//                //ÿ��dest�����Ҫ�ж�һ�£���û�ߵ���ͷ,����ߵ���ͷ�˾�ֹͣ
//            }
//            else
//            {
//                //curλ���ϵ����ݵ���0����ôdest��Ҫ��2��
//                dest += 2;
//            }
//            if (dest >= arr.size() - 1)
//                break;
//            cur++;
//        }
//        //�ҵ���cur��dest��λ�ö�����Ҫ�ı䣬��Ϊ���Ǿ��ǴӺ���ǰ���ǣ�����cur��dest��λ������
//        //����Ҫע��dest���ܻ�Խ����������Ҫ���Դ���
//        if (dest == arr.size())//�������Խ�������
//        {
//            arr[arr.size() - 1] = 0;
//            dest -= 2;
//            cur--;
//        }
//        while (dest > 0)
//        {
//            if (arr[cur])//���curλ�����Ƿ�0����ô�ͽ���λ�ø��ǵ�destλ����
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
        //�����Ż����飬����������
        sort(nums.begin(), nums.end());
        //���ȹ̶�һ��Ԫ��a���Ժ��������ʹ��˫ָ���㷨��ɸѡ
        //ɸѡ�Ĺ�����Ҫע��ȥ��

        int ti = 0;
        vector<vector<int>> vv;
        while (ti < nums.size()-1)
        {
            //�Ժ��������ʹ��˫ָ���㷨
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
                else//˵���ҵ������Ԫ����
                {
                    vv.push_back({ nums[ti],nums[left],nums[right] });
                    //���ҵ�һ������������Ԫ��ʱ��left��rightҪͬʱŲ��,����ʣ�µ��������Ѱ��
                    //��Ҫ����Ҫȥ�أ����ǵ�ע���´�����������ϴε�Ԫ�ػ���ֱ������ȥ
                    left++;
                    right--;
                    while (nums[left] == nums[left-1]&&nums[right]==nums[right+1] && left<right)
                    {
                        left++;
                        right--;
                    }
                }
            }
            //���Ҫע��Թ̶���Ԫ�ؽ���ȥ�أ���Ϊ���̶���ͬ��Ԫ��ʱ��Ҳ������ظ���
            int later = ti;
            ++ti;
            while (nums[later] == nums[ti]&&ti<nums.size()-1)
                ++ti;
        }
    
    
}
