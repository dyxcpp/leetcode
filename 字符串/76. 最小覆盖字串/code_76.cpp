
// // dyx题解一：先对t的所有字符计数，然后遍历s进行匹配(滑动窗口法！！！)
// class Solution {
// public:
//     string minWindow(string s, string t) {
//         unordered_map<char, int> umap1;
//         int count1 = 0;
//         for(char c : t) {
//             if(umap1[c] == 0) ++count1;
//             ++umap1[c];
//         }
//         // cout << "cnt1 = " << count1 << endl;
//         int count2 = 0;
//         unordered_map<char, int> umap2;
//         int left = 0;
//         int minLen = s.size() + 1;
//         int minLeft = 0;
//         for(int right = 0; right < s.size(); ++right) {
//             // cout << "cnt2 = " << count2 << endl;    
//             // cout << "sub = " << string(s.begin() + left, s.begin() + right + 1) << endl;
//             char charR = s[right];
//             ++umap2[charR];
//             if(umap1[charR] && umap1[charR] == umap2[charR]) {
//                 ++count2;
//             }
            
            
//             if(count2 == count1) {
//                 while(left <= right) {
//                     char charL = s[left];
//                     if(umap1[charL]) {
                        
//                         if((umap2[charL]-1) >= umap1[charL]) {
//                             --umap2[charL];
//                             ++left;
//                         }
//                         else break;
//                     }
//                     else ++left;
//                 }
//                 if(right - left + 1 < minLen) {
//                     minLen = right - left + 1;
//                     minLeft = left;
//                 }
                
//             }
//         }
        
//         if(minLen != s.size() + 1) return string(s.begin() + minLeft, s.begin() + minLeft + minLen);
//         return string();
        
//     }
// };


// dyx题解一：先对t的所有字符计数，然后遍历s进行匹配(滑动窗口法！！！)
class Solution {
public:
    string minWindow(string s, string t) {
        int cnt[128] = {0};
        int count1 = 0;
        for(char c : t) {
            if(cnt[c] == 0) ++count1;
            ++cnt[c];
        }
        if(count1 == 0) return t;
        int left = 0;
        int minLen = s.size() + 1;
        int minLeft = 0;
        for(int right = 0; right < s.size(); ++right) {
            --cnt[s[right]];
            if(cnt[s[right]] == 0) count1--;
            while(count1 == 0) {
                if(right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minLeft = left;
                }
                ++cnt[s[left]];
                if(cnt[s[left]] > 0) count1++;
                ++left;
            }
        }
        
        if(minLen != s.size() + 1) return string(s.begin() + minLeft, s.begin() + minLeft + minLen);
        return string();
        
    }
};
