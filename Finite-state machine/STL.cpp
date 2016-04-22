#include <set>
#include <map>

#include <cstdlib>
#include <iostream>

using namespace std;

bool f1(char *s){
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
				case '0': ns.insert(0); ns.insert(1); break;
				case '1': ns.insert(0);
			}
			break;

			case 1: switch (s[i])
			{
				case '0': break;
				case '1': ns.insert(2); 
			}
			break;

			case 2: switch (s[i])
			{
				case '0': break;
				case '1': ns.insert(3);
			}
			break;

			case 3: switch (s[i])
			{
			case '0': ns.insert(3); break;
			case '1': ns.insert(3);
			}
			}	
		}
		states = ns;
	}
	return states.count(3) == 1;
}

bool f2(char *s){
	set<int> states;
	char i = -1;
	char cnt = 0, cnt2;

	states.insert(0);
	while (s[++i] != '\0'){
		set<int> ns;
		set<int>::iterator j = states.begin();
		for (int k = 0; k < 10; ++k)
		{
			cnt2 = 1;
			for (int j = 0; j < cnt; cnt++)
				cnt2 *= 2;
			if (s[i] == '1'){
				ns.insert(*j + cnt2);
			}

			if (cnt > 9){
				ns.insert(*j / 2);
				cnt--;
			}

			cnt++;
		}
		states = ns;
	}
	if (i < 10)
		return false;
	return states.count(1) % 2;
}

/*bool f3(char *s){
	set <int> states;
	char i = -1;

	states.insert(0);
	while (s[++i] != '\0'){
		set<int> ns;
		set<int>::iterator j;

		for (j = states.begin(); j < states.end(); ++j){

		}
	}

	//return states.count
}*/

void main(){
	char s[100];
	cin >> s;
	cout << f2(s) << endl;
}