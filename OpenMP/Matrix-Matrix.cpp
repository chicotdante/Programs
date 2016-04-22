//#include <iostream>
//#include <cstdlib>
//#include <omp.h>
//#include <time.h>
//#include <cmath>
//using namespace std;
//
//const int n = 1000, m = 1000, q = 1000;
//float matrix1[m][n], matrix2[n][q], result[m][q] = { 0 };
//
//int main(){
//	srand(time(NULL));
//	for (int i = 0; i < m; i++){
//		for (int j = 0; j < n; j++){
//			matrix1[i][j] = rand() % 200;
//		}
//	}
//	for (int i = 0; i < n; i++){
//		for (int j = 0; j < q; j++){
//			matrix2[i][j] = rand() % 200;
//		}
//	}
//
//	/*Sequential*/
//	/*for (int i = 0; i < m; i++){
//		for (int j = 0; j < q; j++){
//			for (int r = 0; r < n; r++){
//				result[i][j] += matrix1[i][r] * matrix2[r][j];
//			}
//		}
//	}*/
//	
//
//	double t = omp_get_wtime();
//
//	/*Cash*/
//	for (int i = 0; i < m; i++){
//		for (int r = 0; r < n; r++){
//			for (int j = 0; j < q; j++){			
//				result[i][j] += matrix1[i][r] * matrix2[r][j];
//			}
//		}
//	}
//
//	/*Parallel*/
////#pragma omp parallel sections
////	{
////#pragma omp section
////	{
////		for (int i = 0; i < m / 2; i++){
////			for (int j = 0; j < q / 2; j++){
////				for (int r = 0; r < n; r++){
////					result[i][j] += matrix1[i][r] * matrix2[r][j];
////				}
////			}
////		}
////	}
////#pragma omp section
////	{
////		for (int i = m / 2; i < m; i++){
////			for (int j = 0; j < q / 2; j++){
////				for (int r = 0; r < n; r++){
////					result[i][j] += matrix1[i][r] * matrix2[r][j];
////				}
////			}
////		}
////	}
////#pragma omp section
////	{
////		for (int i = 0; i < m / 2; i++){
////			for (int j = q / 2; j < q; j++){
////				for (int r = 0; r < n; r++){
////					result[i][j] += matrix1[i][r] * matrix2[r][j];
////				}
////			}
////		}
////	}
////#pragma omp section
////	{
////		for (int i = m / 2; i < m; i++){
////			for (int j = q / 2; j < q; j++){
////				for (int r = 0; r < n; r++){
////					result[i][j] += matrix1[i][r] * matrix2[r][j];
////				}
////			}
////		}
////	}
////	}
//
//	cout << "Time: " << omp_get_wtime() - t << endl;
//
//	return EXIT_SUCCESS;
//}