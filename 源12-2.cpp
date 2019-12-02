
//int getValue(vector<int> gifts, int n) {
//	vector<int> hash;
//	int num = n / 2;
//	for (int i = 0; i<gifts.size(); i++)
//		hash[gifts[i]] = 0;
//	for (int i = 0; i<gifts.size(); i++)
//		hash[gifts[i]]++;
//	for (int i = 0; i<gifts.size(); i++)
//	if (hash[gifts[i]]>num)
//		return gifts[i];
//	return 0;
//}
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int Returnminsize(string s1, string s2)
{
	int n = (int)s1.size(); int m = (int)s2.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); 
	dp[0][0] = 0;
	for (int i = 1; i <= m; ++i) dp[0][i] = i;
	for (int i = 1; i <= n; ++i) dp[i][0] = i;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			int one = dp[i - 1][j] + 1, two = dp[i][j - 1] + 1, three = dp[i - 1][j - 1];
			if (s1[i - 1] != s2[j - 1]) three += 1;
			dp[i][j] = min(min(one, two), three);
		}
	}
	return dp[n][m];
}
int main()
{
	string str1, str2;
	while(cin >> str1 >> str2)
		cout<<Returnminsize(str1,str2)<<endl;
	return 0;
}