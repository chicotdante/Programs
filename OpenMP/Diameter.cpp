//#include <iostream>
//#include <cstdlib>
//#include <omp.h>
//#include <time.h>
//#include <cmath>
//#include <algorithm>
//using namespace std;
//const int n = 10000;
//float arr[n][3];
//int main(){ 
//	double maxDist = 0, dist = 0;
//	cout.precision(4);
//	cout.setf(ostream::fixed);
//
//	srand(time(NULL));
//	for (int i = 0; i < n; ++i){
//		arr[i][0] = rand() % 100;
//		arr[i][1] = rand() % 100;
//		arr[i][2] = rand() % 100;
//	}
//
//	//double t = omp_get_wtime();
//
//	/*Sequential*/
//	/*for (int i = 0; i < n - 1; ++i){
//		for (int j = i + 1; j < n; ++j){
//			dist = sqrt((arr[i][0] - arr[j][0])*(arr[i][0] - arr[j][0]) + (arr[i][1] - arr[j][1])*(arr[i][1] - arr[j][1]) + (arr[i][2] - arr[j][2])*(arr[i][2] - arr[j][2]));
//			if (dist > maxDist)
//				maxDist = dist;
//		}
//	}*/
//
//	/*Parallel (2 sections)*/
///*#pragma omp parallel sections
//		{
//	#pragma omp section
//	{
//		for (int i = 0; i < n; i = i + 2){
//			for (int j = i + 1; j < n - i; j++){
//				dist = sqrt((arr[i][0] - arr[j][0])*(arr[i][0] - arr[j][0]) + (arr[i][1] - arr[j][1])*(arr[i][1] - arr[j][1]) + (arr[i][2] - arr[j][2])*(arr[i][2] - arr[j][2]));
//				if (dist > maxDist)
//					maxDist = dist;
//			}
//		}
//	}
//	#pragma omp section
//	{
//		for(int i = 1; i < n; i = i + 2){
//			for (int j = i + 1; j < n; j++){
//				dist = sqrt((arr[i][0] - arr[j][0])*(arr[i][0] - arr[j][0]) + (arr[i][1] - arr[j][1])*(arr[i][1] - arr[j][1]) + (arr[i][2] - arr[j][2])*(arr[i][2] - arr[j][2]));
//				if (dist > maxDist)
//					maxDist = dist;
//			}
//		}
//	}
//		}*/
//
//	/*Parallel (4 sections)*/
///*#pragma omp parallel sections
//		{
//#pragma omp section
//	{
//		for (int i = 0; i < n; i = i + 4){
//			for (int j = i + 1; j < n - i; j++){
//				dist = sqrt((arr[i][0] - arr[j][0])*(arr[i][0] - arr[j][0]) + (arr[i][1] - arr[j][1])*(arr[i][1] - arr[j][1]) + (arr[i][2] - arr[j][2])*(arr[i][2] - arr[j][2]));
//				if (dist > maxDist)
//					maxDist = dist;
//			}
//		}
//	}
//#pragma omp section
//	{
//		for (int i = 1; i < n; i = i + 4){
//			for (int j = i + 1; j < n; j++){
//				dist = sqrt((arr[i][0] - arr[j][0])*(arr[i][0] - arr[j][0]) + (arr[i][1] - arr[j][1])*(arr[i][1] - arr[j][1]) + (arr[i][2] - arr[j][2])*(arr[i][2] - arr[j][2]));
//				if (dist > maxDist)
//					maxDist = dist;
//			}
//		}
//	}
//#pragma omp section
//	{
//		for (int i = 2; i < n; i = i + 4){
//			for (int j = i + 1; j < n; j++){
//				dist = sqrt((arr[i][0] - arr[j][0])*(arr[i][0] - arr[j][0]) + (arr[i][1] - arr[j][1])*(arr[i][1] - arr[j][1]) + (arr[i][2] - arr[j][2])*(arr[i][2] - arr[j][2]));
//				if (dist > maxDist)
//					maxDist = dist;
//			}
//		}
//	}
//#pragma omp section
//	{
//		for (int i = 3; i < n; i = i + 4){
//			for (int j = i + 1; j < n; j++){
//				dist = sqrt((arr[i][0] - arr[j][0])*(arr[i][0] - arr[j][0]) + (arr[i][1] - arr[j][1])*(arr[i][1] - arr[j][1]) + (arr[i][2] - arr[j][2])*(arr[i][2] - arr[j][2]));
//				if (dist > maxDist)
//					maxDist = dist;
//			}
//		}
//	}
//		}*/
//
//	/*int a = (int)(2.0 / 3.0 * n);
//	int b = (int)(a / (1 + sqrt(2)));*/
//	//int c = n - a - b;
//
//	int a = n*0.577350;
//	int b = n*0.816497;
//
//	double maxDist1 = 0, maxDist2 = 0, maxDist3 = 0;
//
//	double t = omp_get_wtime();
//
//	/*Parallel (3 sections)*/
//#pragma omp parallel sections
//		{
//#pragma omp section
//	{
//		for (int i = 0; i < a; i++){
//			for (int j = 0; j < i; j++){
//				dist = sqrt((arr[i][0] - arr[j][0])*(arr[i][0] - arr[j][0]) + (arr[i][1] - arr[j][1])*(arr[i][1] - arr[j][1]) + (arr[i][2] - arr[j][2])*(arr[i][2] - arr[j][2]));
//				if (dist > maxDist1)
//					maxDist1 = dist;
//			}
//		}
//	}
//#pragma omp section
//	{
//		for (int i = a; i < b; i++){
//			for (int j = 0; j < i; j++){
//				dist = sqrt((arr[i][0] - arr[j][0])*(arr[i][0] - arr[j][0]) + (arr[i][1] - arr[j][1])*(arr[i][1] - arr[j][1]) + (arr[i][2] - arr[j][2])*(arr[i][2] - arr[j][2]));
//				if (dist > maxDist2)
//					maxDist2 = dist;
//			}
//		}
//	}
//#pragma omp section
//	{
//		for (int i = b; i < n; i++){
//			for (int j = 0; j < i; j++){
//				dist = sqrt((arr[i][0] - arr[j][0])*(arr[i][0] - arr[j][0]) + (arr[i][1] - arr[j][1])*(arr[i][1] - arr[j][1]) + (arr[i][2] - arr[j][2])*(arr[i][2] - arr[j][2]));
//				if (dist > maxDist3)
//					maxDist3 = dist;
//			}
//		}
//	}
//
//		}
//	
//	maxDist = max(maxDist1, maxDist2);
//	maxDist = max(maxDist, maxDist3);
//
//	cout << "Diameter: " << maxDist << endl;
//	cout << "Time: " << omp_get_wtime() - t << endl;
//
//	return EXIT_SUCCESS;
//}