class Solution {
public:
    int binaryGap(int N) 
    {
        string bin = "";
        
        while(N != 0)
        {
            bin += static_cast<char>((N&1) +48);
            N >>= 1;
        }

        
        for(int i = 0; i < bin.size()/2 ; i++)
        {
            char temp = bin[i];
            bin[i] = bin[bin.size() - 1 - i];
            bin[bin.size() - 1 - i] = temp;
        }
        
        //cout<<bin<<endl;
        
        int start_index = -1, end_index = -1; 
        bool found = false;
        int diff = -1;
        for(int i = 0; i <= bin.size(); i++)
        {
            //cout<<"i: " << i << " "<<start_index<<" "<<end_index<<endl;
            //cout<<bin[i]<<endl;
            if(start_index == -1 && bin[i] == '1' && found == false)
            {
                start_index = i;
            }
            
            else if(start_index  != -1 && bin[i] == '1')
            {
                found = true;
                end_index = i;
            }

            if(diff < end_index - start_index && !(start_index == -1 || end_index == -1) )
            {
                diff = end_index -start_index;
            }
            
            if(found)
            {
                start_index = end_index;
            }
            
        }
        
        
        if(start_index == -1 || end_index == -1)
        {
            return 0;
        }
        
        return diff;
        
        
    }
};
