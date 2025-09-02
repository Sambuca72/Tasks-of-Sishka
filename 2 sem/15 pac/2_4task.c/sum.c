typedef long long int int64_t;
static int64_t *pref_sum; 
static int size; 

extern void *malloc(unsigned long size);

void Init(const int *arr, int n) 
{
    size = n; 
    pref_sum = (int64_t *)malloc((n + 1) * sizeof(int64_t));
    pref_sum[0] = 0;

    for (int i = 0; i < n; i++) 
    {
        pref_sum[i + 1] = pref_sum[i] + arr[i]; 
    }
}

int64_t Sum(int l, int r)
{
    return pref_sum[r] - pref_sum[l]; 
}

int GetArrSize() 
{
    return size;
}
