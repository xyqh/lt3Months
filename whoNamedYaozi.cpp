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

#include <vector>
#include <algorithm>
#include <iostream>
int anotherMinDistance(const vector<int>& s1, const vector<int>& s2, const vector<int>& s3)
{
    int calc_count = 0;
    auto calc = [&calc_count, s1, s2, s3](int i, int j, int k) {
        ++calc_count;
        return std::abs(s1[i] - s2[j]) + std::abs(s2[j] - s3[k]) + std::abs(s3[k] - s1[i]);
    };

    // 获取a b c的中位数
    auto _mid_of_three = [](int a, int b, int c) {
        std::vector<int> tmp = { a, b, c };
        std::sort(tmp.begin(), tmp.end());
        return tmp[1];
    };

    auto _get_next_baseline = [s1, s2, s3](int i, int j, int k) {
        auto _get_max = [](int a, int b, int c) {
            return std::max(a, std::max(b, c));
        };

        std::vector<int> tmp;
        tmp.push_back(_get_max(s1[i], s2[j], s3[k]));
        if (i + 1 < s1.size()) {
            tmp.push_back(s1[i + 1]);
        }
        if (j + 1 < s2.size()) {
            tmp.push_back(s2[j + 1]);
        }
        if (k + 1 < s3.size()) {
            tmp.push_back(s3[k + 1]);
        }

        std::sort(tmp.begin(), tmp.end());
        return tmp[1];
    };

    int min_D = INT32_MAX;
    int i = 0;
    int j = 0;
    int k = 0;

    int baseline = _mid_of_three(s1[0], s2[0], s3[0]);
    int baseline_end = _mid_of_three(s1.back(), s2.back(), s3.back());

    int len1 = abs(s1[0] - baseline);
    int len2 = abs(s2[0] - baseline);
    int len3 = abs(s3[0] - baseline);

    while (baseline < baseline_end) {

        int calc_D = calc(i, j, k);

        std::cout << "baseline:" << baseline << std::endl;
        std::cout << "D:" << min_D << " trituple:(" << s1[i] << "," << s2[j] << "," << s3[k] << ") " << std::endl;

        if (calc_D < min_D) {
            min_D = calc_D;
            if (min_D == 0) {
                break;
            }
        }

        len1 = abs(s1[i] - baseline);
        len2 = abs(s2[j] - baseline);
        len3 = abs(s3[k] - baseline);

        // 将i, j, k 都逼近baseline
        while (i + 1 < s1.size() && abs(s1[i + 1] - baseline) <= len1) {
            len1 = abs(s1[i + 1] - baseline);
            i = i + 1;
            std::cout << "i++:" << std::endl;
        }
        while (j + 1 < s2.size() && abs(s2[j + 1] - baseline) <= len2) {
            len2 = abs(s2[j + 1] - baseline);
            j = j + 1;
            std::cout << "j++:" << std::endl;
        }
        while (k + 1 < s3.size() && abs(s3[k + 1] - baseline) <= len3) {
            len3 = abs(s3[k + 1] - baseline);
            k = k + 1;
            std::cout << "k++:" << std::endl;
        }

        // 将 baseline 往右移动
        int mid_value = _mid_of_three(s1[i], s2[j], s3[k]);
        if (mid_value == baseline) {
            // 如果当前三点abc中的中位数就是baseline， 那么baseline选取 S1，S2，S3 比 baseline大的下一个数
            baseline = _get_next_baseline(i, j, k);
        } else {
            baseline = mid_value;
        }
    }

    int newcalc_D = calc(i, j, k);

    if (newcalc_D < min_D) {
        min_D = newcalc_D;
    }

    std::cout << "calc_count:" << calc_count << std::endl;
    std::cout << "D:" << min_D << " trituple:(" << s1[i] << "," << s2[j] << "," << s3[k] << ") " << std::endl;

    return min_D;
}


int main(){
    vector<int> s1 = {-1,0,9}, s2 = {-25,-10,10,11}, s3 = {2,9,17,30,41};
    int anotherMinD = anotherMinDistance(s1, s2, s3);
    int minD = minDistance(s1, s2, s3);
    cout << minD << endl;
    return 0;
}
