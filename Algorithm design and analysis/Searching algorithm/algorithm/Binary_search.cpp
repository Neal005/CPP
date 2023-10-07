int BinarySearch(int x,int *a,int left,int right)
{
	if(left>right) return -1;
	int mid=(left+right)/2;
	if(x==a[mid]) return mid;
	if (x<a[mid]) return BinarySearch(x,a,left,mid-1);
	else return BinarySearch(x,a,mid+1,right);
}