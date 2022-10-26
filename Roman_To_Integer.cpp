#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int r =0;
        for(int i=0;i<s.size();i++)
        {
         if(s[i]=='V')
         r += 5;
          else if(s[i]=='L')
              r += 50;
          else if(s[i]=='D')
              r += 500;
          else if(s[i]=='M')
              r += 1000;
          else if(s[i]=='C')
          {
              if(s[i+1]=='D')
              {
                r += 400;
                  i++;
              } 
              else if(s[i+1]=='M')
              {
                  r += 900;
                  i++;
              }
              else 
                  r += 100;
          }
           else if(s[i]=='X') 
           {
               if(s[i+1]=='L')
               {
                   r +=40;
                   i++;
               }
               else if(s[i+1]=='C')
               {
                   r += 90;
                   i++;
               }
               else
                   r +=10 ;
           }
            
            else if(s[i]=='I')
            {
                if(s[i+1]=='V')
                {
                    r += 4;
                    i++;
                }
                else if(s[i+1]=='X')
                {
                    r += 9;
                    i++;
                }
                else
                     r += 1;
            }
            
        }
    
        return r;
    }
    
};

int main(){
    Solution s ;
    int result= s.romanToInt("III");
     cout<<result ;
     return 0;
}