#include <cstdlib>
#include <iostream>
#include <set>
#include <map>

using namespace std;

bool f1(char *s){
	int state = 0;
	char i = -1;

	while (s[++i] != '\0'){
		switch (state)
		{
		case 0: switch (s[i])
		{
		case '0': state = 1; break;
		case '1': state = 4;
		}
				break;
		case 1: switch (s[i])
		{
		case '0': state = 1; break;
		case '1': state = 2;
		}
				break;
		case 2: switch (s[i])
		{
		case '0': state = 3; break;
		case '1': state = 2;
		}
				break;
		case 3: switch (s[i])
		{
		case '0': state = 3; break;
		case '1': state = 4;
		}
				break;
		case 4: switch (s[i])
		{
		case '0': state = 4; break;
		case '1': state = 4;
		}
		}
	}

	return state == 3;
}

bool f2(char *s){
	set<int> states;
	char i = -1;

	states.insert(0);
	while (s[++i] != '\0'){
		set<int> ns;
		set<int>::iterator j;
		for (j = states.begin(); j != states.end(); ++j)
		{
			switch (*j)
			{
				case 0: switch (s[i])
				{
				case '0': ns.insert(1); break;
				case '1': break;
				}
				break;

				case 1: switch (s[i])
				{
				case '0': ns.insert(2);  break;
				case '1': break;
				}
				break;

				case 2: switch (s[i])
				{
				case '0': ns.insert(3); break;
				case '1': break;
				}
				break;

				case 3: switch (s[i])
				{
				case '0': ns.insert(3); break;
				case '1': ns.insert(4);
				}
				break;

				case 4: switch (s[i])
				{
				case '0': ns.insert(3); break;
				case '1': ns.insert(5);
				}
				break;

				case 5: switch (s[i])
				{
				case '0': ns.insert(3); break;
				case '1': ns.insert(6);
				}
				break;

				case 6: switch (s[i])
				{
				case '0': ns.insert(3); break;
				case '1': ns.insert(6);
				}
			}
		}
		states = ns;
	}
	return states.count(6);
}

void main(){
	char s[100];
	cin >> s;
	//cout << f1(s) << endl;
	cout << f2(s) << endl;
}