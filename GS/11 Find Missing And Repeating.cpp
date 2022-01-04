
 /*
        APPROACH 1 : sorting O(nlong)/O(1)
        APPROACH 2 : mapping O(n)/O(n)
        APPROACH 3 : negative indexing O(n)/O(1)
        APPROACH 4 : using swap sort technique O(n)/O(1)
        APPROACH 5 : summation & square equations O(n)/O(1) (interger overflow for larger values)
        APPROACH 6 : using XOR technique O(n)/O(1)

    */
    int *findTwoElement(int *arr, int n) {
        // code here
        int* ans = new int[2];
        
        for(int i=0;i<n;i++)
        {
            arr[abs(arr[i])-1] = -1*abs(arr[abs(arr[i])-1]);
        }
        for(int i=0;i<n;i++)
            if(arr[i]>0){
                ans[1] = i+1,
                ans[0] = arr[i];
                break;
            }
        return ans;
    }

