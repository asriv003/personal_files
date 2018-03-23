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

//General Class for Array Algorithms
class ArrayAlgos {

public:
    //Problem 1: LeetCode
    //Given an array of integers, return indices of the two numbers such that they add up to a specific target
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>::iterator it1,it2;
        vector<int> result;
        for(it1 = nums.begin(); it1 != nums.end(); ++it1)
        {
            it2 = find(it1+1, nums.end(), target-*it1);
            if(it2 != nums.end())
            {
                result.push_back(it1 - nums.begin());
                result.push_back(it2 - nums.begin());
                break;
            }
        }
        return result;
    }

    //Problem 4: LeetCode
    //Find median of given two sorted vector of different size
    //If combined legth is even then return mean of two medians otherwise a single median value
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int nums1_size = nums1.size();
        int nums2_size = nums2.size();
        
        int k = (nums1_size + nums2_size + 1)/2;
        int mid_1 = findKthInTwoArrays(nums1, 0, nums1_size-1, nums2, 0,nums2_size-1, k);
        
        if( (nums1_size + nums2_size)%2 ) {
            return mid_1;
        } else {
            int mid_2 = findKthInTwoArrays(nums1, 0, nums1_size-1, nums2, 0, nums2_size-1, k+1);
            return (mid_1 + mid_2)/2.0;
        }
    }

	//To find kth smallest element in two given sorted vectors
	int findKthInTwoArrays(vector<int>& nums1, int nums1_left, int nums1_right, vector<int>& nums2, int nums2_left, int nums2_right, int k){
        //base cases
        //if nums1 array is empty return the kth element
        if(nums1_left > nums1_right) return nums2[nums2_left + (k-1)];
        //if nums2 array is empty return the kth element
        if(nums2_left > nums2_right) return nums1[nums1_left + (k-1)];
        
        int nums1_mid = nums1_left + (nums1_right - nums1_left)/2;
        int nums2_mid = nums2_left + (nums2_right - nums2_left)/2;
        
        //If median of nums1 is smaller than nums2
        if(nums1[nums1_mid] <= nums2[nums2_mid]) {
        	//if k is smaller than the number of elements smaller than median of nums2
        	//at least (nums1_mid - nums1_l) + 1 + (nums2_mid - nums2_l) are smaller than nums2 median i.e nums2_mid
        	//so we ignore the elements greater than nums_mid
            if(k <= (nums1_mid - nums1_left) + 1 + (nums2_mid - nums2_left) )
                return findKthInTwoArrays(nums1, nums1_left, nums1_right, nums2, nums2_left, nums2_mid-1, k);
            //if k is larger than the number of elements smaller than median of nums2
        	//then we ignore the elments smaller than nums1_mid and modify the 'k' value appropriately
        	//which is (k - numder of elments smaller than nums1_mid )i.e: k - (nums1_mid - nums1_l + 1)
            else
                return findKthInTwoArrays(nums1, nums1_mid+1, nums1_right, nums2, nums2_left, nums2_right, (k - (nums1_mid - nums1_left) - 1));
        }//same logic but reversed if nums2_mid is smaller than nums1_mid 
        else {
            if(k <= (nums2_mid - nums2_l) + 1 + (nums1_mid - nums1_l) )
                return findKthInTwoArrays(nums1, nums1_left, nums1_mid-1, nums2, nums2_left, nums2_right, k);
            else
                return findKthInTwoArrays(nums1, nums1_left, nums1_right, nums2, nums2_mid+1, nums2_right, (k - (nums2_mid - nums2_left) - 1));
        }
	}

};

int main() {
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//CODE
    return 0;
}