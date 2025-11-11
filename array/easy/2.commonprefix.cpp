#include <iostream>
#include <vector>
#include <string>
using namespace std;


string longestcommonprefix (vector <string>& strs){
          if (strs.empty()) return "" ;

          string prefix = strs[0];

          for (int i=1; i<strs.size(); i++){
           //keep reducing perfix until it get matched
           while (strs[i].find(prefix) !=0){
               prefix = prefix.substr(0, prefix.size()-1);
               if (prefix.empty()) return "";
           }

      }


      return prefix;
}


int main (){
       vector <string> strs = {"flower", "flow", "flight"};
       cout << "Longest common prefix : " << longestcommonprefix(strs)<< endl;
       return 0;
}