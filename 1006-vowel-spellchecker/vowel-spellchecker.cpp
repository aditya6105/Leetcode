class Solution {
public:
    string toLower(string s){
        string result = s;
        for(char& c : result){
            c = tolower(c);
        }
        return result;
    }

    string replaceVowel(string s){
        string result = s;
        for(char& c : result){
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                c = '*';
            }
        }
        return result;
    }

    string checkForMatch(string& q, unordered_set<string>& exactSet, unordered_map<string, string>& caseMap, unordered_map<string, string>& vowelMap){
        if(exactSet.count(q)){
            return q;
        }
        string lowerCase = toLower(q);
        if(caseMap.count(lowerCase)){
            return caseMap[lowerCase];
        }
        string vowelcase = replaceVowel(lowerCase);
        if(vowelMap.count(vowelcase)){
            return vowelMap[vowelcase];
        }
        return "";
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exactSet;
        unordered_map<string, string> caseMap;
        unordered_map<string, string> vowelMap;
        for(string word : wordlist){
            exactSet.insert(word);
            string lowerCase = toLower(word);
            if(caseMap.find(lowerCase) == caseMap.end()){
                caseMap[lowerCase] = word;
            }
            string vowelCase = replaceVowel(lowerCase);
            if(vowelMap.find(vowelCase) == vowelMap.end()){
                vowelMap[vowelCase] = word;
            }
        }
        vector<string> result;
        for(string q : queries){
            result.push_back(checkForMatch(q, exactSet, caseMap, vowelMap));
        }
        return result;
    }
};
