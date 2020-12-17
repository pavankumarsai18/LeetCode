class Solution {
public:
    void duplicateZeros(vector<int>& arr) 
    {
        int size = arr.size() - 1;
        int duplicateZeros = 0;
        
        for(int index = 0; index <= size - duplicateZeros; index++)
        {
            if(arr[index] == 0)
            {
                if(index == size - duplicateZeros){
                    arr[size] = 0;
                    size--;
                    break;
                }
                duplicateZeros++;
            }
        }
        
        int last = size - duplicateZeros;
        
        for(int i = last; i >= 0; i--)
        {
            if(arr[i] == 0)
            {
                arr[i+duplicateZeros] = 0;
                duplicateZeros--;
                arr[i+duplicateZeros] = 0;
            }
            else{
                arr[i+duplicateZeros] = arr[i];
            }
        }
    }
};
