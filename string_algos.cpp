#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <cctype>
#include <utility>   
#include <map>
#include <string>  
#include <climits> 
#include <set>
#include <string>    
#include <sstream>
#include <utility>   
#include <ctime>
#include <cassert>
#include <fstream>
#include <iomanip>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> II;
typedef vector<II> VII;
typedef vector<long long> VLL;
typedef vector<bool> VB;

#define SZ(A) ((int)A.size())
#define LEN(A) ((int)A.length())
#define MS(A) memset(A, 0, sizeof(A))
#define MSV(A,a) memset(A, a, sizeof(A))
#define MAX(a,b) ((a >= b) ? (a) : (b))
#define MIN(a,b) ((a >= b) ? (b) : (a))
#define ABS(a) (((a) > 0) ? (a) : (-a))
#define MP make_pair
#define X first
#define Y second
#define PB push_back
#define FOUND(A, x) (A.find(x) != A.end())
#define INF (int(1e9))
#define INFL (LL(1e18))
#define EPS 1e-12

#define chkbit(s, b) (s & (1<<b))
#define setbit(s, b) (s |= (1<<b))
#define clrbit(s, b) (s &= ~(1<<b))

#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REV(i, a, n) for(int i = a; i > n; i--)
#define FORALL(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)
#define ALL(A) A.begin(), A.end()
#define LLA(A) A.rbegin(), A.rend()
#define UNIQUE(A) (A).resize(unique(ALL(A)) - (A).begin())

//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 1, 0, 0, -1, -1, -1}, dy[] = {1, 0, -1, 1, -1, 1, 0, -1};

//General Class for String Algorithms
class StringAlgos {
public:
	//Problem 3: LeetCode
	//Given a string, find the length of the longest substring without repeating characters
	int lengthOfLongestSubstring(string s) {
        map<char,int>num;
        map<char,int>::iterator it;
        
        int len, i, maxlen;
        i = len = maxlen = 0;
        
        while(s[i] != '\0') {
            //cout<< i << ": " << len << endl;
            it = num.find(s[i]); 
            if( it == num.end() ) {
                len++;
                num[s[i]] = i;
                
            } else {
                if(len >= maxlen) {
                    maxlen = len;
                }
                len = 0;
                i = it->second; 
                num.clear();               
            }
            i++;
        }
        if(len >= maxlen)
            maxlen = len;
        return maxlen;
    }

private:
};

int main() {
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//CODE
    return 0;
}