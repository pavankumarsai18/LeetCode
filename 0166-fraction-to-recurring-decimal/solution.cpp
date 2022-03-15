class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) 
    {

        long long Numerator = numerator;
        long long Denominator = denominator;
        
        if(numerator == 0)
            return "0";
        bool isNegative = false;
        if( (numerator > 0 && denominator > 0) || (numerator < 0 && denominator < 0))
            isNegative = false;
        else
            isNegative = true;
        
        if(numerator < 0)
            Numerator *= -1;
        if(denominator < 0)
            Denominator *= -1;
        
        
        string result = "";
        if(isNegative)
            result += "-";
        
        long long remainder = Numerator%Denominator;
        // cout<<"remainder "<<remainder<<endl;
        long long quotient = Numerator/Denominator;
        result += to_string(quotient);
        if(remainder == 0)
        {
            return result;
        }
        else
        {
            
            result += ".";
            Numerator = remainder*10;
            unordered_set<string> used;
            string fractionalPart = "";
            vector<int> remainders;
            auto itr = used.end();
            do
            {
                remainder = Numerator%Denominator;
                quotient = Numerator/Denominator;
                Numerator = remainder*10;
                remainders.push_back(remainder);
                
                string key = to_string(quotient) + "," + to_string(remainder);
                itr = used.find(key);
                if(itr == used.end())
                {
                    used.insert(key);
                    fractionalPart += to_string(quotient);
                }
                else
                {
                    string copy = "";
                    for(int i = 0; i < fractionalPart.size();i++)
                    {
                        if(fractionalPart[i]-48 == quotient && remainders[i] == remainder)
                        {
                            copy += "(";
                        }
                        copy += fractionalPart[i];
                    }
                    copy += ")";
                    
                    fractionalPart = copy;
                    break;
                }
                // cout<<"fractionalPart "<<fractionalPart<<endl;

                if(remainder == 0) break;

            }while(remainder != 0 || itr != used.end());
            
            result += fractionalPart;
        }
        
        
        return result;
        
    }
};
