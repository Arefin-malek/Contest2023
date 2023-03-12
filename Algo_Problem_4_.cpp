#include<bits/stdc++.h>
using namespace std;

void solve(int T) {
	vector<char> operators = {'+', '-', '*', '/', '='};
	string str;
	vector<string> streq;
	vector<string> AlphaNum = {"plus", "substract", "multiple", "division", "equals"};
	
	
	vector<string> Num = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "30", "40", "50", "60", "70", "80", "90", "100"};
	vector<string> AlphaNumS = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninty", "hundred" } ;
	
		while (true) {
			cin >> str;
			if (str == "and" || str == " ") continue;
			if (str == "=" || str == "equals") {
				streq.push_back(str);
				cin >> str;
				streq.push_back(str);
				break;
			}
			streq.push_back(str);
		}

		for (auto& i : streq) {
			int it = find(AlphaNum.begin(), AlphaNum.end(), i) - AlphaNum.begin();
			if (it != (int)AlphaNum.size()) {
				i = operators[it];
			}
			it = find(AlphaNumS.begin(), AlphaNumS.end(), i) - AlphaNumS.begin();
			if (it != (int)AlphaNumS.size()) {
				i = Num[it];
			}
		}

		double LHS = 0, RHS = 0;
		double previous = -1;
		char previousOperation = '#';
		bool Isneg = false;
		for (int i = 0; i < (int)streq.size(); i++) {
			if (('0' <= streq[i][0] && streq[i][0] <= '9') || (previousOperation == '=')) {
				if (streq[i][0] == '-') {
					Isneg = true;
					streq[i] = streq[i].substr(1);
				}
				if (previous == -1) {
					previous = stod(streq[i]);
				} else {
					if (streq[i] == "100") {
						previous *= stod(streq[i]);
					} else {
						previous += stod(streq[i]);
					}
				}
			} else {
				if (previousOperation == '#') {
					LHS = previous;
				} else {
					if (previousOperation == '+') {
						LHS += previous;
					} else if (previousOperation == '-') {
						LHS -= previous;
					} else if (previousOperation == '*') {
						LHS *= previous;
					} else if (previousOperation == '/') {
						LHS /= previous;
					}
				}
				previous = -1;
				previousOperation = streq[i][0];
			}
		}
		RHS = (Isneg ? -previous : previous);
        cout << "Case #" << T << ": ";
		cout << (LHS == RHS ? "True" : "False") << endl;
}


int main()
{
    int t;
    cin>>t;
    int a =1;
    while(t--){

        solve(a);
        a++;
    }
}
