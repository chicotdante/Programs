//#include <iostream>
//#include <cstdlib>
//#include <omp.h>
//using namespace std;
//int main(){
//	int n = 10000000, k = n/2;
//	float pi = 0;
//	double t = omp_get_wtime();
//	//cout.width(10);
//	cout.precision(4);
//	cout.setf(ostream::fixed);
//
//	/*Sequental*/
//#pragma omp parallel for schedule(runtime)
//	for (int i = 0; i < n; ++i){
//		pi += 1 / (1 + ((2 * i - 1.) / (2 * n))*((2 * i - 1.) / (2 * n)));
//	}
//	
//
//	/*Parallel (2 sections)*/
///*#pragma omp parallel sections reduction(+:pi)
//	{
//#pragma omp section
//{
//	for (int i = 0; i < k; i++){
//		pi += 1 / (1 + ((2 * i - 1.) / (2 * n))*((2 * i - 1.) / (2 * n)));
//	}
//}
//#pragma omp section
//{
//	for (int i = k; i < n; i++){
//		pi += 1 / (1. + ((2 * i - 1.) / (2 * n))*((2 * i - 1.) / (2 * n)));
//	}
//}
//	}*/
//	pi = pi * 4 / n;
//	cout << "Pi: " << pi << endl;
//	cout << "Time: " << omp_get_wtime() - t << endl;
//
//	return EXIT_SUCCESS;
//}