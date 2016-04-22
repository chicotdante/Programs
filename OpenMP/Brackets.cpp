//#include <iostream>
//#include <cstdlib>
//#include <omp.h>
//#include <time.h>
//#include <cmath>
//#include <string>
//using namespace std;
//
//int main(){
//	string s;
//	int cnt = 0;
//
//	printf("Input brace-string: ");
//	cin >> s;
//
//	int l = s.length();
//
//	/*Sequential*/
//	/*double t = omp_get_wtime();
//
//	for (int i = 0; i < l; i++){
//	if (s[i] == '(')
//	cnt++;
//	else if (s[i] == ')' && --cnt < 0)
//	break;
//	}
//
//	if (cnt == 0)
//	cout << "Success\n";
//	else
//	cout<< "Fail\n";
//
//	cout << "Time: " << omp_get_wtime() - t << endl;*/
//
//	/*Parallel (2 sections)*/
//	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
//
//	double t = omp_get_wtime();
//
//#pragma omp parallel sections
//	{
//#pragma omp section
//{
//	for (int i = 0; i < l; i++){
//		if (s[i] == '[')
//			cnt1++;
//		else if (s[i] == ']' && --cnt1 < 0)
//			break;
//	}
//}
//#pragma omp section
//{
//	for (int i = 0; i < l; i++){
//		if (s[i] == '(')
//			cnt2++;
//		else if (s[i] == ')' && --cnt2 < 0)
//			break;
//	}
//}
//#pragma omp section
//{
//	for (int i = 0; i < l; i++){
//		if (s[i] == '{')
//			cnt3++;
//		else if (s[i] == '}' && --cnt3 < 0)
//			break;
//	}
//}
//	}
//
//	
//
//	if (cnt1 == 0 && cnt2 == 0 && cnt3 == 0)
//		cout << "Success\n";
//	else
//		cout << "Fail\n";
//
//	cout << "Time: " << omp_get_wtime() - t << endl;
//
//	return EXIT_SUCCESS;
//}