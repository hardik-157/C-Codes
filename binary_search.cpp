//returns '0' base indexing output
// And a.size() if it is Greatest element
//No other element which is Greater then it, is present.
// n = a.size()
int upper_bound(int a[], int n, int x) {
    int l = 0;
    int h = n;
    while (l < h)
    {
        int mid = l + (h - l) / 2;

        if (x >= a[mid])
            l = mid + 1;
        else
            h = mid;

    }
    return l;
}

//returns '0' base indexing output
// And a.size() Otherwise
// n = a.size()
int lower_bound(int a[], int n, int x) {
    int l = 0;
    int h = n; // Not n - 1
    while (l < h)
    {
        int mid = l + (h - l) / 2;

        if (x <= a[mid])
            h = mid;
        else
            l = mid + 1;

    }
    return l;
}

//returns '0' base index
// l = 0 and r = n-1 for n size array
int binarySearch(int arr[], int l, int r, int x) 
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;

        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1; 
    }
    return -1; 
}
