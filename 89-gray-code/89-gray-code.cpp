class Solution {
public:
    vector<string> solve(int n)
    {
        //Base case when n=1
        if(n==1)
        {
            vector<string> basecaseVect;
            basecaseVect.push_back("0");
            basecaseVect.push_back("1");
            return basecaseVect;
        }
        
          vector<string>ans=solve(n-1);
    
        vector<string> mainAns;
    
        //Adding 0s
       for(int i=0;i<ans.size();i++){
        string s=ans[i];
          mainAns.push_back("0"+s);
      }
        //Adding 1s in reverse order
      for(int i=ans.size()-1;i>=0;i--){
          string s=ans[i];
          mainAns.push_back("1"+s);
      }
        
        return mainAns;
    }
    vector<int> grayCode(int n) {
        vector<string> strRes=solve(n);
        vector<int> result;
        //Converting binary to decimal
 for(int i=0;i<strRes.size();i++)
           {
          int val = stoi(strRes[i], 0, 2);
             result.push_back(val);
         }
        return result;
    }
};