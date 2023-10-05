int binarysearch(int x,int *a,int left,int right)
{
	if(left>right) return -1;
	int mid=(left + right)/2;
	if(x==a[mid]) return mid;
	if (x<a[mid]) return binarysearch(x,a,left,mid-1);
	else return binarysearch(x,a,mid+1,right);
}