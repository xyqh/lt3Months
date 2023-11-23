#include "LeetCodeBase.h"

int calcDistance(int a, int b, int c){
    return abs(a-b) + abs(a-c) + abs(b-c);
}

/**
 * 求最小值需要三个点尽量近
 * 已知s1中任意一个点a，找到s2中任意点b∈(-∞, a)的上确界点supb，以及任意点b∈(a,+∞)的下确界infb
 * 二分找最接近s3中[a,b]的点c
 * 
 * 对2的补充说明，假设b1<=a，且b2<b1，对任意点c有abs(b1-c)+abs(b1-a)+abs(a-c)与abs(b2-c)+abs(b2-a)+abs(a-c)的比较
 * 其中abs(b2-a)=abs(b2-b1)+abs(b1-a)
 * 即只需要考虑abs(b1-c)和abs(b2-c)+abs(b1-b2)的大小
 * 对于任意c∈(-∞, b2]，abs(b1-c)==abs(b2-c)+abs(b1-b2)
 * 对于任意c∈[b2,b1]，abs(b1-c)<abs(b2-c)+abs(b1-b2)
 * 对于任意c∈[b1,+∞)，abs(b1-c)<abs(b2-c)+abs(b1-b2)
 * 同理证得b1>=a，且b2>b1的合理性
*/
vector<int> GetCloseToNum(int num, vector<int> nums){
    int n = nums.size();
    int l = 0, r = n - 1, infIdx = -1, supIdx = -1;
    // 上确界
    while(l <= r){
        int m = l + (r - l >> 1);
        if(nums[m] <= num){
            supIdx = m;
            l = m + 1;
        }else{
            r = m - 1;
        }
    }
    l = 0, r = n - 1;
    // 下确界
    while(l <= r){
        int m = l + (r - l >> 1);
        if(nums[m] >= num){
            infIdx = m;
            r = m - 1;
        }else{
            l = m + 1;
        }
    }

    vector<int> ans;
    if(supIdx != -1){
        ans.push_back(nums[supIdx]);
    }
    if(infIdx != -1){
        ans.push_back(nums[infIdx]);
    }
    return ans;
}

int minDistance(vector<int>& s1, vector<int>& s2, vector<int>& s3){
    vector<vector<int>> s;
    s.push_back(move(s1));
    s.push_back(move(s2));
    s.push_back(move(s3));
    sort(s.begin(), s.end(), [](const vector<int>& sa, const vector<int>& sb){
        return sa.size() < sb.size();
    });

    int minD = INT_MAX, l = 0, r = s[2].size() - 1, m = 0;
    for(int i = 0; i < s[0].size(); ++i){
        vector<int> closes = GetCloseToNum(s[0][i], s[1]);
        for(int j = 0; j < closes.size(); ++j){
            // 找最接近的数，二分
            int a = s[0][i], b = closes[j];
            if(a > b){
                swap(a, b);
            }

            l = 0, r = s[2].size() - 1;
            while(l <= r){
                m = l + (r - l >> 1);
                minD = min(minD, calcDistance(a, b, s[2][m]));
                if(s[2][m] < a){
                    l = m + 1;
                }else if(s[2][m] > b){
                    r = m - 1;
                }else{
                    break;
                }
            }
            if(minD == 0){
                return minD;
            }
        }
    }

    return minD;
}

int main(){
    vector<int> s1 = {-1,0,9}, s2 = {-25,-10,10,11}, s3 = {2,9,17,30,41};
    int minD = minDistance(s1, s2, s3);
    cout << minD << endl;
    return 0;
}