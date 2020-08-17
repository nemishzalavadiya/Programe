/*
Valid Palindrome

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
 

Constraints:

s consists only of printable ASCII characters.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool isPalindrome(string s) {
        if(s.size()==0||s.size()==1) return true;
        int last=s.size()-1,i=0;
        while(i<last){
            while(i<s.size() && !isalnum(s[i])){
                i++;
            }
            while(last>=0 && !isalnum(s[last])){
                last--;
            }
            if(last==-1 || i==s.size())break;
            if(tolower(s[i])!=tolower(s[last])) return false;
            i++;last--;
        }
        return true;
    }
};
int main(int argc, char *argv[]) {

return 0;
}