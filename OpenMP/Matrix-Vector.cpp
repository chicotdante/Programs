//#include <iostream>
//#include <cstdlib>
//#include <omp.h>
//#include <time.h>
//#include <cmath>
//using namespace std;
//
//const int n = 10000, m = 10000;
//float matrix[m][n];
//float vector1[n], vector2[m] = { 0 };
//
//int main(){
//	srand(time(NULL));
//	for (int i = 0; i < m; i++){
//		for (int j = 0; j < n; j++){
//			matrix[i][j] = rand() % 200;
//		}
//	}
//	for (int j = 0; j < n; j++){
//		vector1[j] = rand() % 200;
//	}
//
//	
//
//	/*for (int i = 0; i < m; i++){
//		for (int j = 0; j < n; j++){
//			vector2[i] += matrix[i][j] * vector1[j];
//		}
//	}*/
//
//double t = omp_get_wtime();
//
//#pragma omp parallel sections
//	{
//#pragma omp section
//	{
//		for (int i = 0; i < n / 4; i++){
//			for (int j = 0; j < m; j++){
//				vector2[i] += matrix[i][j] * vector1[j];
//			}
//		}
//	}
//#pragma omp section
//	{
//		for (int i = n / 4 + 1; i < n / 2; i++){
//			for (int j = 0; j < m; j++){
//				vector2[i] += matrix[i][j] * vector1[j];
//			}
//		}
//	}
//#pragma omp section
//	{
//		for (int i = n / 2 + 1; i < 3 * n / 4; i++){
//			for (int j = 0; j < m; j++){
//				vector2[i] += matrix[i][j] * vector1[j];
//			}
//		}
//	}
//#pragma omp section
//	{
//		for (int i = 3 * n / 4 + 1; i < n; i++){
//			for (int j = 0; j < m; j++){
//				vector2[i] += matrix[i][j] * vector1[j];
//			}
//		}
//	}
//	}
//
//	cout << "Time: " << omp_get_wtime() - t << endl;	
//
//	return EXIT_SUCCESS;
//}