//#include <iostream>
//#include <cstdlib>
//#include <omp.h>
//#include <time.h>
//#include <cmath>
//using namespace std;
//
//const int n = 2, m = 2, q = 1000000;
//float matrix1[m][n], matrix2[n][q], result[m][q] = { 0 };
//
//int main(){
//	srand(time(NULL));
//	for (int i = 0; i < m; i++){
//		for (int j = 0; j < 2; j++){
//			matrix2[i][j] = rand() % 200 + 1.0 / (rand() % 200);
//		}
//	}
//	matrix1[0][0] = cos(3.1415 / 3.0);
//	matrix1[0][1] = -sin(3.1415 / 3.0);
//	matrix1[1][0] = sin(3.1415 / 3.0);
//	matrix1[1][1] = cos(3.1415 / 3.0);
//	
//	double t = omp_get_wtime();
//
//#pragma omp parallel sections
//	{
//#pragma omp section
//	{
//		for (int i = 0; i < m / 2; i++){
//			for (int j = 0; j < q / 2; j++){
//				for (int r = 0; r < n; r++){
//					result[i][j] += matrix1[i][r] * matrix2[r][j];
//				}
//			}
//		}
//	}
//#pragma omp section
//	{
//		for (int i = m / 2; i < m; i++){
//			for (int j = 0; j < q / 2; j++){
//				for (int r = 0; r < n; r++){
//					result[i][j] += matrix1[i][r] * matrix2[r][j];
//				}
//			}
//		}
//	}
//#pragma omp section
//	{
//		for (int i = 0; i < m / 2; i++){
//			for (int j = q / 2; j < q; j++){
//				for (int r = 0; r < n; r++){
//					result[i][j] += matrix1[i][r] * matrix2[r][j];
//				}
//			}
//		}
//	}
//#pragma omp section
//	{
//		for (int i = m / 2; i < m; i++){
//			for (int j = q / 2; j < q; j++){
//				for (int r = 0; r < n; r++){
//					result[i][j] += matrix1[i][r] * matrix2[r][j];
//				}
//			}
//		}
//	}
//	}
//
//	cout << "Time: " << omp_get_wtime() - t << endl;
//
//	return EXIT_SUCCESS;
//}