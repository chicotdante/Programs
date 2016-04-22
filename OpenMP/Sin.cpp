//#include <iostream>
//#include <cstdlib>
//#include <cmath>
//#include <omp.h>
//using namespace std;
//#define pi 3.1415
//double arrSin[500000];
//int main(){
//	double t = omp_get_wtime();
//	int n = 500000;
//	/*for (int i = 0; i < 500000; i++){
//		arrSin[i] = sin(i*pi / 2 / n);
//	}*/
//#pragma omp parallel sections reduction(+:sum)
//	{
//#pragma omp section
//{
//	for (int i = 0; i < 1000000; i++){
//		sum++;
//		cout << sin(sum * pi / 2 / i) << endl;
//	}
//}
//#pragma omp section
//{
//	for (int i = 0; i<1000000; i++)
//		cout << sin(pi / 2 / (i+1000000)) << endl;
//}
//	}
//	cout << "Time: " << omp_get_wtime() - t << endl;
//	return EXIT_SUCCESS;
//}
