#include <bits/stdc++.h>
using namespace std;
/*
--Two Sum II – Input array is sorted
--3Sum
3Sum Closest
--4Sum
--Subarray Sum Equals K
--Maximum Subarray (Kadane’s Algorithm)
--Maximum Product Subarray
--Find Minimum in Rotated Sorted Array
--Search in Rotated Sorted Array
Search in Rotated Sorted Array II (with duplicates)
Peak Element in Array
Find First and Last Position in Sorted Array
Missing Number
Find the Duplicate Number
Find All Duplicates in an Array
Find Disappeared Numbers
Set Matrix Zeroes
Rotate Image (Matrix)
Spiral Matrix
Spiral Matrix II
Jump Game
Jump Game II (min jumps)
--Merge Intervals
Insert Interval
Interval List Intersections
Non-overlapping Intervals
Minimum Number of Arrows to Burst Balloons
Subsets
Subsets II (with duplicates)
Permutations
Permutations II (with duplicates)
--Combination Sum
Combination Sum II
Combination Sum III
Next Permutation
Previous Permutation with One Swap
Longest Consecutive Sequence
Product of Array Except Self
Majority Element II (appears > n/3 times)
Gas Station (circular array)
Candy Distribution
Trapping Rain Water
Container With Most Water
Largest Rectangle in Histogram
Maximal Rectangle (2D DP on histogram)
--Sort Colors (Dutch National Flag)
--Kth Largest Element in Array (Quickselect/Heap)
Find Median of Two Sorted Arrays
Sliding Window Maximum
Minimum Size Subarray Sum
*/

vector<int> TwoSumII(vector<int>& arr, int target){
    int start=0; int n=arr.size();
    int end=n-1;

    while(start<end){
        int sum=arr[start]+arr[end];

        if(sum==target) return {start,end};
        else if(sum<target) start++;
        else end--;
    }
    return {-1,-1};
}
vector<vector<int>> ThreeSum(vector<int>& arr){
    int i=0; int n=arr.size();
    set<vector<int>> st;

    for(int i=0; i<n; i++){
        int j=i+1; int k=n-1;

        while(j<k){
            int sum=arr[i]+arr[j]+arr[k];

            if(sum==0){
                st.insert({arr[i], arr[j], arr[k]});
                j++; k--;
            }
            else if(sum>k) j++;
            else k--;
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
bool TwoSum_brute(vector<int>& arr, int target){
    // {2,6,5,8,11}
    int n=arr.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]+arr[j]==target) return true;
        }
    }
    return false;
}
bool TwoSum_better(vector<int>& arr, int target){
    int n=arr.size();
    unordered_map<int,int> mpp;
    for(int i=0; i<n; i++){
        int rem=target-arr[i];
        if(mpp.find(rem)!=mpp.end()){
            return true;
        }
        mpp[arr[i]]=i;
    }
    return false;
}
bool TwoSum_optimal(vector<int>& arr,int target){
    int n=arr.size();
    int i=0; int j=n-1;
    sort(arr.begin(), arr.end());
    while(i<j){
        int sum=arr[i]+arr[j];

        if(sum==target) return true;
        else if(sum>target) j--;
        else i++;
    }
    return false;
}

vector<vector<int>> ThreeSum_brute(vector<int>& arr){
    int n=arr.size();
    vector<vector<int>> ans;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(arr[i]+arr[j]+arr[k]==0){
                    vector<int> temp={arr[i], arr[j], arr[k]};
                    ans.push_back(temp);
                }
            }

        }
    }
    return ans;
}
vector<vector<int>> ThreeSum_better(vector<int>& arr){
    int n=arr.size();
    set<vector<int>> hashset;
    for(int i=0; i<n; i++){
        set<int> st;
        for(int j=i+1; j<n; j++){
            int rem=-arr[i]-arr[j];
            if(st.find(rem)!=st.end()){
                vector<int>temp={arr[i],arr[j], rem};
                sort(temp.begin(), temp.end());
                hashset.insert(temp);

            }
            st.insert(arr[j]);
        }
            
    }
    vector<vector<int>> ans(hashset.begin(), hashset.end());
    return ans;
}
vector<vector<int>> ThreeSum_optimal(vector<int>& arr){
    int n=arr.size();
    sort(arr.begin(), arr.end());
    set<vector<int>> st;
    for(int i=0; i<n; i++){
        int j=i+1; int k=n-1;
        while(j<k){
            int sum=arr[i]+arr[j]+arr[k];

            if(sum==0){
                vector<int> temp={arr[i], arr[j], arr[k]};
                sort(temp.begin(), temp.end());
                st.insert(temp);
                j++; k--;
            }
            
            else if(sum>0) k--;
            else j++;
        }
            
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
vector<vector<int>> FourSum(vector<int>& arr){
    int n=arr.size();
    set<vector<int>> st;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int k=j+1; int l=n-1;

            while(k<l){
                int sum=arr[i]+arr[j]+arr[k]+arr[l];

                if(sum==0){
                    st.insert({arr[i], arr[j], arr[k], arr[l]});
                    k++;
                    l--;
                }

                else if(sum<0){
                    k++;
                }
                else l--;
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int SubarraySumEqualsK(vector<int>& arr, int k){
    int count=0; int sum=0; int n=arr.size();
    unordered_map<int,int> mpp;

    for(int i=0; i<n; i++){
        sum+=arr[i];
        if(sum==k) count++;
        int rem=sum-k;
        if(mpp.find(rem)!=mpp.end()) count+=mpp[rem];
        mpp[sum]++;
    }
    return count;
}

int TrappingRainWater(vector<int>& arr){
    int n=arr.size();
    int lmax=0, rmax=0, l=0, r=n-1;;
    int total=0;
    while(l<r){
        if(arr[l]<arr[r]){
            if(lmax>arr[l]){
                total+=lmax-arr[l];
            }
            else lmax=arr[l];
            l=l+1;
        }
        else{
            if(rmax>arr[r]){
                total+=rmax-arr[r];
            }
            else rmax=arr[r];
            r--;
        }
    }
    return total;
}
int findduplicates_brute(vector<int>&arr){
    // {1,3,4,2,2} --> 1,2,2,3,4
    // O(n logn +n)
    int n=arr.size();
    sort(arr.begin(), arr.end());

    for(int i=1; i<n; i++){
        if(arr[i]==arr[i-1]) return arr[i];

    }
    return 0;

}
int findduplicates_optimal(vector<int>& arr){
    int n=arr.size();
    int freq[n-1]={0};

    for(int i=0; i<n; i++){
        if(freq[arr[i]]==0) freq[arr[i]]+=1;
        else return arr[i];
    }
    return 0;
}
// Best Time to Buy and Sell Stock

int BuyAndSellStock_brute(vector<int>& arr){
    // [7,1,5,3,6,4]
    int n=arr.size();
    int maxpro=0;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int pro=arr[j]-arr[i];
            maxpro=max(pro, maxpro);
        }
    }
    return maxpro;

}
int BuyAndSellStock_optimal(vector<int>& arr){
    int maxpro=0;
    int n=arr.size();
    for(int i=0; i<n; i++){
        int buy=min(buy, arr[i]);
        int pro=arr[i]-buy;
        maxpro=max(maxpro, pro);

    }
    return maxpro;
}
 // Search in Rotated Sorted Array
int MinimuminRotatedSortedArray(vector<int>&arr){
    int n=arr.size();
    int low=0; int high=n-1;

    while(low<high){
        if(arr[low]<arr[high]) return arr[low];

        int mid=(low+high)/2;

        if(arr[mid]>arr[high]) low=mid+1;
        else high=mid;
    }
    return arr[low];
}
 int SearchinRotatedArr(vector<int>& arr, int k){
    int n=arr.size();
    int low=0; int high=n-1;

    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid]==k) return mid;
        if(arr[low]<=arr[mid]){
            if(arr[low]<=k && arr[mid]>=k){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{
            if(arr[mid]<=k && arr[high]>=k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    return -1;
 }
 vector<vector<int>> SetMatrixZeros_better(vector<vector<int>> &arr, int n, int m){
    int row[n]={0};
    int col[m]={0};

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j]==0){
                row[i]=1;
                col[j]=1;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(row[i]==1 || col[j]==1) arr[i][j]=0;
        }
    }
    return arr;
 }
 vector<vector<int>> SetMatrixZeros_optimal(vector<vector<int>>& arr, int n, int m){
    int col0=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j]==0){
                arr[i][0]=0;
                if(j!=0){
                    arr[0][j]=0;
                }
                else col0=0;
            }
        }
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(arr[i][j]!=0){
                if(arr[i][0]==0 || arr[0][j]==0) arr[i][j]=0;
            }
        }
    }

    if(arr[0][0]==0){
        for(int j=0; j<m; j++){
            arr[0][j]=0;
        }
    }
    if(col0==0){
        for(int i=0; i<n; i++){
            arr[i][0]=0;
        }
    }
    return arr;
}

vector<vector<int>> MergeIntervals1(vector<vector<int>>& arr){
    //[[1,3],[2,6],[8,10],[15,18]]
    int n=arr.size(); vector<vector<int>> ans;
    int m=arr[0].size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<m; j++){
            if(!ans.empty() && ans.back()[1]> arr[j][0]){
                ans.back()[1]=max(ans.back()[1], arr[j][1]);
            }
            else ans.push_back(arr[i]);

        }
    }
    return ans;
}
vector<vector<int>> MergeIntervals_optimal(vector<vector<int>>& arr){
    //[[1,3],[2,6],[8,10],[15,18]]
    int n=arr.size(); vector<vector<int>> ans;
    for(int i=0; i<n; i++){
        if(ans.empty() || ans.back()[1]<arr[i][0]) ans.push_back(arr[i]);
        else ans.back()[1]=max(ans.back()[1], arr[i][1]);
    }
    return ans;
}

int LongestConsecSeq(vector<int>& arr){
    set<int> st;
    int n=arr.size(); int maxlen=1;

    for(int i=0; i<n; i++){
        st.insert(arr[i]);
    }

    for(auto it: st){
        if(st.find(it-1)==st.end()){
            int x=it;
            int count=1;

            while(st.find(x+1)!=st.end()){
                count++;
                x=x+1;
            }
            maxlen=max(count, maxlen);
        }
    }
    return maxlen;
}
vector<int> NextGreaterElement(vector<int>& arr){
    int n=arr.size();
    vector<int>nge(n,0);
    stack<int> st;

    for(int i=n-1; i>=0; i--){
        while(!st.empty() && st.top()<=arr[i]){
            st.pop();
        }
        if(st.empty()) nge[i]=-1;
        else nge[i]=st.top();
        
        st.push(arr[i]);
    }
    return nge;
}
int SubarraysWithSumK_brute(vector<int>&arr, int k){
    int n=arr.size();
    int count=0;

    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=i; j<n; j++){
            sum+=arr[j];
            if(sum==k){
                count++;
            }

        }
    }
    return count;
}
int SubarraysWithSumK_optimal(vector<int>& arr, int k){
    int count=0;
    unordered_map<int,int> mpp;
    int n=arr.size();
    int sum=0;

    for(int i=0; i<n; i++){
        sum+=arr[i];

        if(sum==k) count++;
        int rem=sum-k;

        if(mpp.find(rem)!=mpp.end()) count+=mpp[rem];
        mpp[sum]++;
    }
    return count;

    // 1,2,3,4
}
// kadane's algo

int MaximumSubarray(vector<int>& arr){
    int n = arr.size();
    int maxsum = arr[0];
    int sum = arr[0];
    
    for(int i = 1; i < n; i++) {
        sum = max(arr[i], sum + arr[i]);  // either extend or start new subarray
        maxsum = max(maxsum, sum);
    }
    return maxsum;
}
vector<int> MaximumSubarray_array(vector<int>& arr){
    int sum=0;
    int n=arr.size();
    int maxi=0; int start=0; int end=0; int tempstart=0;

    for(int i=0; i<n; i++){
        sum+=arr[i];

        if(sum>maxi){
            start=tempstart;
            end=i;
            maxi=sum;
        }
        if(sum<0){
            tempstart=i+1;
            sum=0;
        }

        // [-2,1,-3,4,-1,2,1,-5,4]
    }
    vector<int> temp;
    for(int i=start; i<=end; i++){
        temp.push_back(arr[i]);
    }
    return temp;
}
vector<vector<int>> MergeIntervals(vector<vector<int>>& arr){
    // [[1,3],[2,6],[8,10],[15,18]]
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    int n=arr.size();

    for(int i=0; i<n; i++){
        if(ans.empty() || ans.back()[1]<arr[i][0]){
            ans.push_back(arr[i]);
        }
        else ans.back()[1]=max(ans.back()[1], arr[i][1]);
    }
    return ans;
}
bool SubarrayWithGivenSum_brute(vector<int>& arr, int k){
    int n=arr.size();

    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=i; j<n; j++){
            sum+=arr[j];
            if(sum==k) return true;
        }
    }
    return false;
}
vector<int> SubarrayWithGivenSum_optimal(vector<int>& arr, int k){
    int n=arr.size();
    int l=0;
    int sum=0; 

    for(int r=0; r<n; r++){
        sum+=arr[r];
        while(sum>k && l<=r){
            sum-=arr[l];
            l++;
        }
        if(sum==k){
            return {l,r};
        }
    }
    return {-1,-1};
}
int MaximumProductSubarray(vector<int>& arr){
    int pre=1;
    int suff=1;
    int n=arr.size();
    int maxi=1; 

    for(int i=0; i<n; i++){
        pre*=arr[i];
        suff*=arr[n-i-1];

        if(pre==0) pre=1;
        if(suff==0) suff=1;

        maxi=max(maxi, max(pre, suff));
    }
    return maxi;
}
void sort012(vector<int>& arr){
    // 0000000 ,0,2,1,0,1,2,1,2,0,0 222222
    // dutch national flag

    int low=0; int mid=0;
    int n=arr.size();
    int high=n-1;

    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1) low++;
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
        

    }
}
void MatrixRotation(vector<vector<int>>& mat, int n){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            swap(mat[i][j], mat[j][i]);
        }
    }
    for(int i=0; i<n; i++){
        reverse(mat[i].begin(), mat[i].end());
    }
}
// for rectangular matrix
vector<vector<int> > rotateMatrix_rectangular(vector<vector<int> > &matrix){
	int m=matrix.size();
	int n=matrix[0].size();
	vector<vector<int>> res(n, vector<int> (m));
	for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            res[j][m-i-1]=matrix[i][j];
        }
    }
	return res;
    
}
/*int RepeatingAndMissing(vector<int>& arr){
    int repeating=-1;
    int missing=-1;
    //3,1,2,5,3 14 15
    int n=arr.size();
    for(int i=0; i<n; i++){

    }
}*/
int TrappingRainwater(vector<int>& arr){
    int n=arr.size();

    int l=0; int r=n-1;
    int lmax=0; int rmax=0;
    int res=0;
    while(l<=r){
        if(arr[l]<arr[r]){
            if(arr[l]>lmax){
                lmax=arr[l];
            }
            else{
                res+=lmax-arr[l];
            }
        l++;
        }
        else{
            if(arr[r]>rmax){
                rmax=arr[r];
            } 
            else {
                res+=rmax-arr[r];
            }
        r--;
        }
    }
    return res;
}
int KthLargestElement(vector<int>& arr, int k){
    priority_queue<int> pq;
    int n=arr.size();


    for(int i=0; i<n; i++){
        pq.push(arr[i]);
    }
    int f=k-1;

    while(f>0){
        pq.pop();
        f--;
    }
    return pq.top();
}
int KthSmallestElement(vector<int>& arr, int k){
    priority_queue<int, vector<int>, greater<int>> pq;
    int n=arr.size();


    for(int i=0; i<n; i++){
        pq.push(arr[i]);
    }
    int f=k-1;

    while(f>0){
        pq.pop();
        f--;
    }
    return pq.top();

}
int MinimumInRotated(vector<int>& arr){
    int low=0;
    int n=arr.size();
    int high=n-1;
    int ans=INT_MAX;

    while(low<=high){
        int mid=(low+high)/2;

        if(arr[low]<arr[high]){
            ans=min(ans, arr[low]);
            break;
        }
        if(arr[low]<arr[mid]){
            ans=min(ans, arr[low]);
            low=mid+1;
        }
        else{
            ans=min(ans, arr[mid]);
            high=mid-1;
        }
    }
    return ans;
}
void PrintAllPermutations_util(vector<int>& ds,vector<int>& arr, vector<vector<int>>& ans, int freq[]){
	int n=arr.size();

	if(ds.size()==arr.size()){
		ans.push_back(ds);
		return;
	}

	for(int i=0; i<n; i++){
		if(!freq[i]){
            ds.push_back(arr[i]);
			freq[i]=1;
			PrintAllPermutations_util(ds,arr, ans, freq);
			freq[i]=0;
			ds.pop_back();
		}

	}
	
}
vector<vector<int>> PrintAllPermutations(vector<int>& arr){
	vector<int> ds;
	int freq[arr.size()];
	vector<vector<int>> ans;
    for(int i=0; i<arr.size(); i++){
        freq[i]=0;
    }

	PrintAllPermutations_util(ds,arr,ans,freq);

	return ans;
}
int MissingNumber(vector<int>& arr){
    int res=0;  // 1,2,4,5
    int n=arr.size();
    int N=n+1;
    int sum=0;
    int SUM=(N*(N+1))/2;

    for(int i=0; i<n; i++){
        sum+=arr[i];
    }
    res=SUM-sum;

    return res;
}
vector<int> findRepeatAndMissingNumber_better(vector<int> &nums) {
	unordered_map<int,int> mpp;
	int repeating=0; int missing=0;
	int n=nums.size();
	
	for(int i=0; i<n; i++){
		mpp[nums[i]]++;
	}
	
	for (int i = 1; i <= n; i++) {
        if (mpp[i] == 2) {   // repeating
            repeating=i;
        }
        else if (mpp[i] == 0) { // missing
            missing=i;
        }
    }
	return {repeating, missing};
    
}
vector<int> ProductofArrayExceptSelf(vector<int>& arr){
    // no zeros in array
    // O(2n)
    int n=arr.size();
    int pro=1;

    for(int i=0; i<n; i++){
        pro*=arr[i];
    }
    vector<int> ans;
    for(int i=0; i<n; i++){
        ans.push_back(pro/arr[i]);

    }
    return ans;
}
void SubsetSumHelper(int ind,vector<int>& arr, int n,vector<int>& ds, int sum ){
    if(ind==n){
        ds.push_back(sum);
        return;
    }

    SubsetSumHelper(ind+1, arr,n, ds, sum+arr[ind]);
    SubsetSumHelper(ind+1, arr,n, ds, sum);

}

vector<int> SubsetSum(vector<int>& arr, int n){
    vector<int> ds;
    int sum=0;
    SubsetSumHelper(0,arr,n,ds, sum);
    sort(ds.begin(), ds.end());

    return ds;

}
int CountPlatforms(int n,int arr[], int dep[]){
    sort(arr, arr+n);
    sort(dep, dep+n);

    int count=1;

    int maxi=1;
    int i=1; int j=0;
    
    while(i<n && j<n){
        if(arr[i]<=dep[j]){
            count++;
            i++;
        }
        else{
            count--;
            j++;
        }
        maxi=max(maxi, count);
    }
    return maxi;

}


int main() {
    int n = 6;
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};

    int ans=CountPlatforms(n,arr, dep);
    cout<<ans;
    
    return 0;
}
// Repeating and missing
// quick sort
// sliding win max
// median of two sorted array