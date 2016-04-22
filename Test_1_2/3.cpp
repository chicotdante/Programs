#include <iostream>
#include <cstdlib>
#include <omp.h>
#include <string>
#include <time.h>
#include <cmath>
using namespace std;


bool isLetter(char c){
	if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return true;
	return false;
}
int main(){
	char *s = new char [255];
	cout << "Input s: " << endl;
	cin.getline(s, 255);

	int l = strlen(s);

	int cnt = 0;
	double t = omp_get_wtime();

#pragma omp parallel sections reduction (+:cnt)
	{
#pragma omp section
	{
		for (int i = 0; i < l/2; i++){
			if (isLetter(s[i]) && !isLetter(s[i+1]))
			{
					cnt++;
			}
		}
	}
#pragma omp section
	{
		for (int j = l-1; j > l/2-1; j--){
			if (isLetter(s[j]) && !isLetter(s[j-1]))
			{
				cnt++;
			}
		}
	}
	}

	if (isLetter(s[l/2]) && isLetter(s[l/2-1]))	//Если разбили слово пополам, уеличиаем счетчик
		cnt++;
	
	cout << "Number of words: " << cnt << endl;
	cout << "Time: " << omp_get_wtime() - t << endl;

	return EXIT_SUCCESS;
}