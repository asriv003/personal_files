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

//General Class for LinkList Algorithms
class LinkListAlgos {
public:
	//Problem 2: LeetCode
	//given two non-empty linked lists representing two non-negative integers.
	//The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = NULL;
        ListNode* end = NULL;
        int carry = 0;
        
        while(l1 != NULL && l2 != NULL) {
            ListNode* temp = new ListNode( (l1->val + l2-> val + carry)%10 );
            carry = (l1->val + l2-> val + carry)/10;
            if(ans == NULL) {
                ans = temp;
            } else {
                end->next = temp;
            }
            end = temp;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        if(l1 == NULL && l2 != NULL) {
            end->next = l2;   
        }
        else if(l2 == NULL && l1 != NULL){
            end->next = l1;   
        }
        
        while(carry != 0) {
            if(end->next == NULL) {
                end->next = new ListNode(carry);
                carry = 0;
            } else {
                int sum = end->next->val + carry; 
                end->next->val = sum%10;
                carry = sum/10;
                end = end->next;
            }
        }
        return ans;
    }
private:
	//Definition for singly-linked list.
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
	};

};

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);
	//CODE
    return 0;
}