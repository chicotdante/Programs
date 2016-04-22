#include <cstdlib>
#include <iostream>

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
		case '1': state = 0;
		}
				break;
		case 1: switch (s[i])
		{
		case '0': state = 2; break;
		case '1': state = 0;
		}
				break;
		case 2: switch (s[i])
		{
		case '0': state = 3; break;
		case '1': state = 0;
		}
				break;
		case 3: switch (s[i])
		{
		case '0': state = 3; break;
		case '1': state = 3;
		}
		}
	}

	return state == 3;
}

bool f2(char *s){
	int state = 0;
	char i = -1;

	while (s[++i] != '\0'){
		switch (state)
		{
		case 0: switch (s[i])
		{
		case '0': state = 1; break;
		case '1': state = 0;
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
		case '0': state = 1; break;
		case '1': state = 3;
		}
				break;
		case 3: switch (s[i])
		{
		case '0': state = 3; break;
		case '1': state = 3;
		}
		}
	}

	return state == 3;
}

bool f3(char *s){
	int state = 0;
	char i = -1;

	while (s[++i] != '\0'){
		switch (state)
		{
		case 0: switch (s[i])
		{
		case '0': state = 1; break;
		case '1': state = 0;
		}
				break;
		case 1: switch (s[i])
		{
		case '0': state = 2; break;
		case '1': state = 0;
		}
				break;
		case 2: switch (s[i])
		{
		case '0': state = 2; break;
		case '1': state = 0;
		}
		}
	}

	return state == 2;
}

bool f4(char *s){
	int state = 0;
	char i = -1;

	while (s[++i] != '\0'){
		static char cnt = 0;
		char cnt2 = 1;
		for (int j = 0; j < cnt; cnt++)
			cnt2 *= 2;
		if (s[i] == '1'){
			state = state + cnt2;
		}
		
		if (cnt > 9){
			state /= 2;
			cnt--;
		}
		
		cnt++;
	}
	if (i < 10)
		return false;
	return state % 2;
}

bool f5(char *s){
	int state1 = 0, state2 = 0;
	char i = -1;
	while (s[++i] != '\0'){
		switch (state1)
		{
			case 0: switch (s[i])
			{
			case '0': state1 = 1; break;
			case '1': state1 = 3;
			}
			break;

			case 1: switch (s[i])
			{
			case '0': state1 = 3; break;
			case '1': state1 = 2;
			}
			break;

			case 2: switch (s[i])
			{
			case '0': state1 = 2; break;
			case '1': state1 = 2;
			}
			break;

			case 3: switch (s[i])
			{
			case '0': state1 = 3; break;
			case '1': state1 = 3;
			}		
		}

		switch (state2)
		{
			case 0: switch (s[i])
			{
			case '0': state2 = 1; break;
			case '1': state2 = 0;
			}
			break;

			case 1: switch (s[i])
			{
			case '0': state2 = 1; break;
			case '1': state2 = 2;
			}
			break;

			case 2: switch (s[i])
			{
			case '0': state2 = 1; break;
			case '1': state2 = 0;
			}		
		}
	}

	return state1 == 2 || state2 == 2;
}

bool f6(char *s){
	int state1 = 0, state2 = 0;
	char i = -1;
	while (s[++i] != '\0'){
		switch (state1)
		{
			case 0: switch (s[i])
			{
			case '0': state1 = 1;
			}
			break;

			case 1: switch (s[i])
			{
			case '0': state1 = 2;
			}
			break;

			case 2: switch (s[i])
			{
			case '0': state1 = 3;
			}
			break;

			case 3: switch (s[i])
			{
			case '0': state1 = 4;
			}
			break;

			case 4: switch (s[i])
			{
			case '0': state1 = 5;
			}
			break;

			case 5: switch (s[i])
			{
			case '0': state1 = 0;
			}
		}

		switch (state2)
		{
			case 0: switch (s[i])
			{
			case '1': state2 = 1;
			}
			break;

			case 1: switch (s[i])
			{
			case '1': state2 = 2;
			}
			break;

			case 2: switch (s[i])
			{
			case '1': state2 = 3;
			}
			break;

			case 3: switch (s[i])
			{
			case '1': state2 = 0;
			}		
		}
	}

	return state1 == 5 && state2 == 3;
}

bool f7(char *s){
	int state = 0;
	char i = -1;

	while (s[++i] != '\0'){
		if (s[i] == '1')
		  state = 2 * state + 1;
		if (s[i] == '0')
			state = 2 * state;
		
		if (state > 31){
			state /= 2;
		}

		if (state > 28 || state == 15 || state == 23 || state == 27)
		{
			state = -1;
			break;
		}
	}

	if (state == -1)
		return 0;
	return 1;
}

bool f8a(char *s){
	int state = 0;
	char i = -1;

	while (s[++i] != '\0'){
		if (s[i] == '1')
			state = 2 * state + 1;
		if (s[i] == '0')
			state = 2 * state;

		while (state >= 5){
			state -= 5;
		}
	}

	return !(state % 5);
}

bool f8b(char *s){
	int state1 = 0, state2 = 1;
	char i = -1;

	while (s[++i] != '\0'){
		if (s[i] == '1')
			state1 = (state1 + state2) % 5;
		if (s[i] == '0')
			state1 = state1 % 5;
		state2 = (state2 * 2) % 5;
	}

	return !(state1);
}

bool f9(char *s){
	int state = 0;
	char i = -1;

	while (s[++i] != '\0'){
		if (s[i] == '(')
			++state;
		else if (s[i] == ')' && --state < 0)
			break;
	}

	return state == 0;
}

void main(){
	char s[100];
	cin >> s;
	cout << f8b(s) << endl;
}