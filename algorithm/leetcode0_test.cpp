/**
 * @description: 调试使用
 * @author: michael ming
 * @date: 2019/11/24 22:55
 * @modified by: 
 */
#include <bits/stdc++.h>
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
using namespace std;


struct cmp1
{
    bool operator()(const vector<int>& a, const vector<int>& b)const
    {
        if(a[0]==b[0])
        {
            if(a[1]==b[1])
                return a[2] < b[2];
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
};

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int i, maxlen = 1, n = nums.size(), MAX, MIN;
        vector<vector<int>> dp(n,vector<int>(5,0));
        MAX = MIN = nums[0];
        dp[0] = {1,MAX,MIN,0,0};
        int mi, ma, L, R, idx, maxid, minid;
        for(i = 1; i < n; ++i)
        {
            mi = abs(nums[i]-dp[i-1][2]);
            idx = -1;
            if(mi > limit)
            {
                idx = dp[i-1][4];
            }
            ma = abs(nums[i]-dp[i-1][1]);
            if(ma > limit)
            {
                idx = max(idx, dp[i-1][3]);
            }
            L = max(mi,ma);
            R = min(mi,ma);

            if(L <= limit)
            {
                maxid = dp[i-1][3];
                minid = dp[i-1][4];
                if(nums[i] >= dp[i-1][1])
                {
                    MAX = nums[i];
                    maxid = i;
                }
                if(nums[i] <= dp[i-1][2])
                {
                    MIN = nums[i];
                    minid = i;
                }
                dp[i] = {dp[i-1][0]+1,MAX, MIN,maxid,minid};
                maxlen = max(maxlen, dp[i][0]);
            }
            else
            {
                idx++;
                MIN = MAX = nums[idx];
                minid = maxid = idx;
                int count = 1;
                while(idx < i)
                {
                    mi = abs(nums[i]-nums[idx]);
                    ma = abs(nums[i]-nums[idx]);
                    L = max(mi,ma);
                    R = min(mi,ma);
                    if(nums[idx] >= MAX)
                    {
                        MAX = nums[idx];
                        maxid = idx;
                    }
                    if(nums[i] <= MIN)
                    {
                        MIN = nums[idx];
                        minid = idx;
                    }
                    if(L <= limit)
                    {
                        count++;
                    }
                    else
                    {
                        count = 0;
                        MIN = MAX = nums[idx+1];
                        minid = maxid = idx+1;
                    }
                    idx++;
                }
                dp[i] = {count,MAX,MIN,maxid, minid};
                maxlen = max(maxlen, dp[i][0]);
            }
        }
        return maxlen;
    }
};
//["01","10","0","1","1001010"] 9
//["01","0","0101010"]  6
//["011000","0111010","01101010"] 9
//["011000","0111011","01001010"] 11
//["01","1000000","11111111"] 13
//则当前节点所构成的最大距离即左深度+右深度-2*当前节点深度。

//["...1","..S.","..*.",".0.T"]   9
void printv(vector<int>& v)
{
    for(auto& vi : v)
        cout << vi << " ";
    cout << endl;
}
int main() {
//    vector<vector<int>> v6 = {{-13260,8589},{1350,8721},{-37222,-19547},{-54293,-29302},{-10489,-13241},{-19382,574},{5561,1033},{-22508,-13241},{-1542,20695},{9277,2820},{-32081,16145},{-50902,23701},{-8636,19504},{-17042,-28765},{-27132,-24156},{-48323,-4607},{30279,29922}};
    vector<vector<int>> v6 ={{2,8,4},{2,5,0},{10,9,8}};
    vector<vector<int>> v5 ={{2,11,3},{15,10,7},{9,17,12},{8,1,14}};
    vector<int> v1 = {2,5,1,1,1,1};
    vector<int> v2 = {1,3,5};
    vector<int> v3 = {-1,0};
    vector<int> v4 = {4,8,5,1,7,9};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<string>> st  = {{"David","3","Ceviche"},{"Corina","10","Beef Burrito"},{"David","3","Fried Chicken"},{"Carla","5","Water"},{"Carla","5","Ceviche"},{"Rous","3","Ceviche"}};
    vector<string> st1 = {};
    Solution s;
    s.longestSubarray(v4,6);
    printv(v4);

    string s1 = "1";
    cout << s1[1] << "s[1]" << endl;
    TreeNode *t1 = new TreeNode(0);
    TreeNode *t2 = new TreeNode(1);
    TreeNode *t3 = new TreeNode(2);
    TreeNode *t4 = new TreeNode(3);
    TreeNode *t5 = new TreeNode(4);
    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t2->right = t5;


    ListNode *h1 = new ListNode(3);
    ListNode *h2 = new ListNode(5);
    ListNode *h3 = new ListNode(8);
    ListNode *h4 = new ListNode(5);
    ListNode *h5 = new ListNode(10);
    ListNode *h6 = new ListNode(2);
    ListNode *h7 = new ListNode(1);
    h1->next = h2;
    h2->next = h3;
    h3->next = h4;
    h4->next = h5;
    h5->next = h6;
    h6->next = h7;
    vector<int> a = {1,2,3};
    cout << a.size() << endl;
    a.resize(a.size()+5);
    cout << a.size() << endl;
    for(int i = 0; i < 8; ++i)
        cout << a[i] << endl;
    return 0;
}