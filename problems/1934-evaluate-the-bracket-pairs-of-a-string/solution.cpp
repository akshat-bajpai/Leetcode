class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> values;
        values.reserve(knowledge.size());

        for (const auto& entry : knowledge) {
            values[entry[0]] = entry[1];
        }

        string answer;
        int n = static_cast<int>(s.size());
        int i = 0;

        while (i < n) {
            if (s[i] != '(') {
                answer.push_back(s[i]);
                ++i;
                continue;
            }

            ++i;  // Skip '('.
            int start = i;

            while (s[i] != ')') {
                ++i;
            }

            string key = s.substr(start, i - start);
            auto it = values.find(key);

            if (it != values.end()) {
                answer += it->second;
            } else {
                answer.push_back('?');
            }

            ++i;  // Skip ')'.
        }

        return answer;
    }
};
