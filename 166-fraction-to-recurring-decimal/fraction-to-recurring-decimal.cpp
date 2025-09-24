class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";
        string s = "";
        if((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)) s += "-"; 

        long long n = abs(1ll * numerator);
        long long d = abs(1ll * denominator);
        s += to_string(n / d);
        
        long long r = n % d;
        if(r == 0) return s;

        s += ".";
        unordered_map<long long, int> m;
        while(r){
            if(m.count(r)){
                s.insert(m[r], "(");
                s.push_back(')');
                break;
            }
            m[r] = s.size();
            r *= 10;
            s += to_string(r/d);
            r %= d;
        }
        return s;
    }
};