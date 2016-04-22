#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include "omp.h"
using namespace std;
int n = 1000;
double points[1000][3];
double dist(double a[3], double b[3])
{
	return sqrt((b[0] - a[0])*(b[0] - a[0]) + (b[1] - a[1])*(b[1] - a[1]) + (b[2] - a[2])*(b[2] - a[2]));
}
int main()
{
	srand(time(NULL));
	for (int i = 0; i < n; ++i)
	{
		points[i][0] = rand() % 1000;
		points[i][1] = rand() % 1000;
		points[i][2] = rand() % 1000;
	}
	/*double max = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			double dist = sqrt((points[j][0] - points[i][0])*(points[j][0] - points[i][0]) + (points[j][1] - points[i][1])*(points[j][1] - points[i][1]) + (points[j][2] - points[i][2])*(points[j][2] - points[i][2]));
			if (dist > max)
				max = dist;
		}
	}
	cout << max << endl;*/
	/*int n1 = n / 2;
	double result = 0, max1 = 0, max2 = 0;
#pragma omp parallel sections

	{
#pragma omp section
		{
			for (int i = 0; i < n1; ++i)
			{
				for (int j = i + 1; j < n - i; ++j)
				{
					double d = dist(points[i], points[j]);
					if (d > max1)
						max1 = d;
				}
			}
		}
#pragma omp section
		{
			for (int i = 0; i < (n - 1); ++i)
			{
				for (int j = n - i; j < n; ++j)
				{
					double d = dist(points[i], points[j]);
					if (d > max2)
						max2 = d;
				}
			}
		}
	}
	result = max(max1, max2);
	cout << "max = " << result << endl;*/
	int n1 = n / 2;
	double result = 0, max1 = 0, max2 = 0, max3 = 0, max4 = 0;
#pragma omp parallel sections
	{
#pragma omp section
		{
			for (int i = 0; i < n1; ++i)
				for (int j = i + 1; j < n1; ++j)
				{
					double d = dist(points[i], points[j]);
					if (d > max1)
						max1 = d;
				}
		}
#pragma omp section
		{
			for (int i = 0; i < n1; ++i)
				for (int j = n1; j < n - i; ++j)
				{
					double d = dist(points[i], points[j]);
					if (d > max2)
						max2 = d;
				}
		}
#pragma omp section
		{
			for (int i = 0; i < n1; ++i)
				for (int j = n - i; j < n; ++j)
				{
					double d = dist(points[i], points[j]);
					if (d > max3)
						max3 = d;
				}
		}
#pragma omp section
		{
			for (int i = n1; i < n; ++i)
				for (int j = i + 1; j < n; ++j)
				{
					double d = dist(points[i], points[j]);
					if (d > max4)
						max4 = d;
				}
		}
	}
	result = max(max1, max2);
	result = max(result, max3);
	result = max(result, max4);
	cout << "max = " << result << endl;
	/*int n1 = n*0.577350;
	int n2 = n*0.816497;
	int result = 0, max1 = 0, max2 = 0, max3 = 0;
#pragma omp parallel sections
	{
#pragma omp section
		{
			for (int i = 0; i < n1; ++i)
				for (int j = 0; j < i; ++j)
				{
					double d = dist(points[i], points[j]);
					if (d > max1)
						max1 = d;
				}
		}
#pragma omp section
		{
			for (int i = n1; i < n2; ++i)
				for (int j = 0; j < i; ++j)
				{
					double d = dist(points[i], points[j]);
					if (d > max2)
						max2 = d;
				}
		}
#pragma omp section
		{
			for (int i = n2; i < n; ++i)
				for (int j = 0; j < i; ++j)
				{
					double d = dist(points[i], points[j]);
					if (d > max3)
						max3 = d;
				}
		}
	}
	result = max(max1, max2);
	result = max(max2, max3);
	cout << "max = " << result << endl;*/
}