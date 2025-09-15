class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int c = 0, r = 0, o = 0, a = 0;
        int maxFrogs = 0;
        for(char ch : croakOfFrogs){
            if(ch == 'c'){
                c++;
                maxFrogs = max(maxFrogs, c + r + o + a);
            }
            else if(ch == 'r'){
                if(c == 0) return -1;
                c--; 
                r++;
            }
            else if(ch == 'o'){
                if(r == 0) return -1;
                r--;
                o++;
            }
            else if(ch == 'a'){
                if(o == 0) return -1;
                o--;
                a++;
            }
            else if(ch == 'k'){
                if(a == 0) return -1;
                a--;
            }
            else return -1;
        }
        if(c == 0 && r == 0 && o == 0 && a == 0) return maxFrogs;
        return -1;
    }
};