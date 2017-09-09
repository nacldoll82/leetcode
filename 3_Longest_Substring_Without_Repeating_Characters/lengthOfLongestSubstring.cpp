class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int maxLen = 0;
		int begin, cur;
		vector<int> charPos(256, -1);

		begin = 0;
		cur = 1;

		while (begin < s.size()) {
			charPos[s[begin]] = begin;
			for (; cur < s.size(); ++cur) {
				if (charPos[s[cur]] != -1)
					break;
				charPos[s[cur]] = cur;
			}

			maxLen = max(maxLen, cur - begin);
			if (cur == s.size())
				break;

			while (begin < s.size() && begin <= charPos[s[cur]]) {
				charPos[s[begin]] = -1;
				begin++;
			}
			charPos[s[cur]] = cur;
			cur++;            
		}

		return maxLen;
	}
};
