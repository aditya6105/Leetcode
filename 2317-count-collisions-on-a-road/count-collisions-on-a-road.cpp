class Solution {
public:
    int countCollisions(string dir) {
        int i = 0;
        int j = dir.size() - 1;
        while(i < dir.size() && dir[i] == 'L') i++;
        while(j < dir.size() && dir[j] == 'R') j--;
        int cntL = 0;
        while(i < dir.size()){
            if(dir[i] == 'L') cntL++;
            i++;
        }
        int cntR = 0;
        while(j >= 0){
            if(dir[j] == 'R') cntR++;
            j--;
        }
        return cntL + cntR;
    }
};