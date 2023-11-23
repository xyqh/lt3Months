#include<vector>
#include<algorithm>

using namespace std;

int calcDistance(int a, int b, int c){
    return abs(a-b) + abs(a-c) + abs(b-c);
}

/**
 * 对于 D=abs(a-b)+abs(a-c)+abs(b-c)
 * 当ab确定时，不妨假设a<b，在数轴上标识出ab两点，对任意c∈(-∞,a)∪(b,+∞)，有D=abs(a-b)+abs(c-a)+abs(c-b)>abs(a-b)+abs(a-b)。（不清楚的可以把并集拿掉，对两个区间分类讨论）
 * 当且仅当c∈[a,b]时，D取得最小值即D=2abs(a-b)。
 * 
 * 对于在排序数组中寻找是否存在区间[a,b]的值，显然二分最合适。
 * 时间复杂度为：i*j*log(k)，i,j,k为三个数组的长度，显然k越大，时间复杂度越低。
 * 空间复杂度：
*/
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
        for(int j = 0; j < s[1].size(); ++j){
            // 找最接近的数，二分
            int a = s[0][i], b = s[1][j];
            if(a > b){
                swap(a, b);
            }

            l = 0, r = s[2].size() - 1;
            while(l <= r){
                m = l + (r - l >> 1);
                if(s[2][m] < a){
                    l = m + 1;
                }else if(s[2][m] > b){
                    r = m - 1;
                }else{
                    break;
                }
            }
            int c = s[2][m];
            minD = min(minD, calcDistance(a, b, c));
            if(minD == 0){
                return minD;
            }
        }
    }

    return minD;
}