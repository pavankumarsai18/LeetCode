class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) 
    {
        // vector<vector<int>> boxes;
        // for(int i = 0; i < boxTypes.size();i++)
        // {
        //     boxes.push_back({boxTypes[i][0]*boxTypes[i][1], boxTypes[i][0], boxTypes[i][1]});
        // }
        
        auto custom = [](vector<int>& a, vector<int>&b){return a[1] < b[1];};
        priority_queue<
                vector<int>,
                std::vector<vector<int>>,
                decltype(custom)
            
            > pq(custom);
        
        for(int i = 0; i < boxTypes.size(); i++)
        {
            pq.push(boxTypes[i]);
        }
        
        int curSize = 0;
        int result = 0;
        while(pq.size() && curSize <= truckSize)
        {
            do
            {
                vector<int> box = pq.top();
                int addEl = box[0];
                if(curSize + box[0] > truckSize)
                {
                    addEl = truckSize - curSize;
                }
                pq.pop();
                
                if(curSize + addEl <= truckSize)
                {
                    curSize += addEl;
                    result  += addEl*box[1];
                    // cout<<"["<<box[0]<<","<<box[1]<<"] ("<<addEl<<","<<addEl*box[1]<<") size="<< curSize<<" ";
                    break;
                }
                curSize -= addEl;
                result -= addEl*box[1];
                
    
            }while(pq.size() && curSize > truckSize);

        }
        // cout<<endl;
        return result;
        
    }
};
