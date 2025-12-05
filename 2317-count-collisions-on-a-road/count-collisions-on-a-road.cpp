class Solution {
public:
    int countCollisions(string d) {
        int n = d.size();
        int c = 0;

        for (int i = 1; i < n; i++) {
            while (i > 0) {
                // Case 1: R meets L => +2, both stop
                if (d[i - 1] == 'R' && d[i] == 'L') {
                    c += 2;
                    d[i - 1] = 'S';
                    d[i] = 'S';
                    i--; // re-check with earlier cars
                }
                // Case 2: R meets S => +1, R becomes S
                else if (d[i - 1] == 'R' && d[i] == 'S') {
                    c += 1;
                    d[i - 1] = 'S';
                    i--;
                }
                // Case 3: S meets L => +1, L becomes S
                else if (d[i - 1] == 'S' && d[i] == 'L') {
                    c += 1;
                    d[i] = 'S';
                    break;
                } 
                else {
                    break; // no collision
                }
            }
        }

        return c;
    }
};
