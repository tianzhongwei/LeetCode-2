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
    int findBestValue(vector<int>& arr, int target) {
        int i, l, r, mid, idx, diff, mindiff = INT_MAX, n = arr.size(), ans;
        sort(arr.begin(),arr.end());
        vector<int> presum(arr);
        for(i = 1; i < n; ++i)
            presum[i] += presum[i-1];
        l = 1, r = arr[n-1];
        while(l <= r)
        {
            mid = l+((r-l)>>1);
            idx = binsearch(arr, mid);
            diff = idx>0? presum[idx-1] : 0 +(n-idx)*mid-target;
            if(abs(diff) < mindiff)
            {
                mindiff = abs(diff);
                ans = mid;
            }
            if(diff < 0)
                l = mid+1;
            else if(diff > 0)
                r = mid-1;
            else
                return ans;
        }
        return ans;
    }

    int binsearch(vector<int>& arr, int val)
    {	//找第一个大于val的数的下标
        int l = 0, r = arr.size()-1, mid;
        while(l <= r)
        {
            mid = l+((r-l)>>1);
            if(arr[mid] > val)
            {
                if(mid==0 || arr[mid-1] <= val)
                    return mid;
                else
                    r = mid-1;
            }
            else
                l = mid+1;
        }
        return arr.size();//没找到，全部小于val
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
    vector<int> v4 = {2,3,5};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<string>> st  = {{"David","3","Ceviche"},{"Corina","10","Beef Burrito"},{"David","3","Fried Chicken"},{"Carla","5","Water"},{"Carla","5","Ceviche"},{"Rous","3","Ceviche"}};
    vector<string> st1 = {};
    Solution s;
    s.findBestValue(v4,10);
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