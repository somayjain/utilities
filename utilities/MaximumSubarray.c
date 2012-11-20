/*
   Problem Statement- Given an array, find the maximum sum subarray in nlogn time.

   Algorithm - Intro to algo ( Divide And Conquer)

   Date - 7-5-12
   Author - Somay Jain

   */

#include<stdio.h>
typedef struct tuple
{
	int low, high, sum;
}tuple;
tuple MaximumSubarray(int a[], int low, int high);
int main()
{
	int n, i;
	scanf("%d", &n);
	int a[n];
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	tuple ans;
	ans=MaximumSubarray(a, 0, n-1);
	printf("low=%d high=%d\n%d\n", ans.low, ans.high, ans.sum);
	
}
tuple MaximumSubarray(int a[], int low, int high)
{
	if(low==high)
	{
		tuple ret;
		ret.low=low; ret.high=high;
		ret.sum=a[low];
		return ret;
	}
	int mid=(low+high)/2, i;
	tuple left, right;
		left=MaximumSubarray(a, low, mid);
		right=MaximumSubarray(a, mid+1, high);

	int leftsum=-999999, rightsum=-999999, sumleft=0, sumright=0, leftindex, rightindex;
	tuple cross;
	for(i=mid; i>=low; i--)
	{
		sumleft+=a[i];
		printf("sumleft=%d\n", sumleft);
		if(sumleft > leftsum)
		{
			leftsum=sumleft;
			printf("leftsum=%d\n", leftsum);
			leftindex=i;
		}
	}
	cross.low=leftindex;
	for(i=mid+1; i<=high; i++)
	{
		printf("in right loop\n");
		sumright+=a[i];
		if(sumright > rightsum)
		{
			rightsum=sumright;
			rightindex=i;
		}
	}
	cross.high=rightindex;
	cross.sum=leftsum+rightsum;
	printf("cross sum=%d\n", cross.sum);
	if(cross.sum > left.sum && cross.sum > right.sum)
	{
		return cross;
	}
	else if( right.sum > left.sum && right.sum > cross.sum)
	{
		return right;
	}
	else
		return left;
	
}

