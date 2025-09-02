typedef long long int int64_t;
extern int64_t Sum(int l, int r);
extern int Size();

int Query(int l, int64_t sum) 
{
    int left = l, right = Size();
    while (left < right) 
    {
        int mid = (left + right + 1) / 2; 

        if (Sum(l, mid) <= sum) 
        { 
            left = mid; 
        } else 
        {
            right = mid - 1;
        }
    }
    return left; 
}
