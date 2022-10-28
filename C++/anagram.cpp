* Given two strings s and t, return true if t is an anagram of s, and false otherwise.
* An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
  
    public:
   
        static bool isAnagram(string s, string t) {
        if (s==t) return true;
        if (s.size()!=t.size()) return false;
        int umap[26]={};
        for (int i=0; i<s.size(); i++) {
            umap[s[i]-'a']++;
            umap[t[i]-'a']--;
        }
        for (int i=0; i<26; i++) {
            if (umap[i]) return false;
        }
        return true;
       }
};


int main(){
    
    string s="anagram";
    string t ="nagram";
    
    cout<< " String s and t Anagrams : "<<Solution::isAnagram(s,t);
    
     string s2="car";
    string t2 ="rat";
    
    cout<< " String s and t Anagrams : "<<Solution::isAnagram(s2,t2);
    return 0;
    
  }
