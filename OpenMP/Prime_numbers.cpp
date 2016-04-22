//#include <iostream>
//#include <cstdlib>
//#include <omp.h>
//#include <time.h>
//#include <cmath>
//using namespace std;
//
//int main(){
//	int n = 1000000, m1, m2, cnt1 = 1, cnt2 = 0;
//	long long div1, div2;
//	bool flag1, flag2;
//	int x = n / (sqrt(4)*sqrt(4)*sqrt(4));
//	if (x % 2 == 0)
//		x++;
//
//	
//
//	/*Consequtive*/
//	/*for (m1 = 3; m1 < n; m1 = m1 + 2){
//		flag1 = false;
//		for (div1 = 3; div1*div1 <= m1; div1 = div1 + 2){
//			if (m1 % div1 == 0){
//				flag1 = true;
//				break;
//			}
//		}
//		if (!flag1)
//			cnt++;
//	}*/
//
//	double t = omp_get_wtime();
//	
//#pragma omp parallel sections
//	{
//#pragma omp section
//	{
//		for (m1 = 3; m1 < x; m1 = m1 + 2){
//			flag1 = true;
//			for (div1 = 3; div1*div1 <= m1; div1 = div1 + 2){
//				if (m1 % div1 == 0){
//					flag1 = false;
//					break;
//				}
//			}
//			if (flag1 == true)
//				cnt1++;
//		}
//	}
//#pragma omp section
//	{
//		for (m2 = x; m2 < n; m2 = m2 + 2){
//			flag2 = true;
//			for (div2 = 3; div2*div2 < m2; div2 = div2 + 2){
//				if (m2 % div2 == 0){
//					flag2 = false;
//					break;
//				}
//			}
//			if (flag2 == true)
//				cnt2++;
//		}
//	}
//	}
//
//	cout << "Prime number count: " << cnt1 + cnt2 << endl;
//	cout << "Time: " << omp_get_wtime() - t << endl;
//	return EXIT_SUCCESS;
//}