//#include <iostream>
//#include <cstdlib>
//#include <omp.h>
//#include <time.h>
//#include <cmath>
//using namespace std;
//
//const int n = 1000;
//double arr[n];
//
//int main(){
//	srand(time(NULL));
//	for (int i = 0; i < n; i++){
//		arr[i] = rand() % 200 + 1.0 / (rand() % 200);
//	}
//	
//	double t = omp_get_wtime();
//
//	for (int i = 0; i < 50; i++){
//		int sum = 0;
//		for (int k = 0; k < n; k++){
//			sum += arr[k];
//		}
//#pragma omp parallel sections
//	{
//#pragma omp section
//	{
//		for (int j = 0; j < n/4; j++){
//			arr[j] = sqrt(sum - arr[j]);
//		}
//	}
//#pragma omp section
//	{
//		for (int j = n/4; j < n/2; j++){
//			arr[j] = sqrt(sum - arr[j]);
//		}
//	}
//#pragma omp section
//	{
//		for (int j = n/2; j < 3*n/4; j++){
//			arr[j] = sqrt(sum - arr[j]);
//		}
//	}
//#pragma omp section
//	{
//		for (int j = 3 * n / 4; j < n; j++){
//			arr[j] = sqrt(sum - arr[j]);
//		}
//	}
//	}
//	}
//
//	
//	cout << "Time: " << omp_get_wtime() - t << endl;
//
//	return EXIT_SUCCESS;
//}