#include <iostream>
#include <omp.h>
using namespace std;
bool isPrime(int n)
{
	int srt = sqrt(n);
		for (int j = 3; j <= srt; j +=2)
		{
			if (n % j == 0)
				return false;
		}
		return true;
}
int main()
{
	
	/*int n;
	cin >> n;
	double t = omp_get_wtime();
	int count = 0;
	if (n >= 2)
		++count;
	for (int i = 3; i <= n; i += 2)
	{
		if (isPrime(i))
			++count;
	}
	
		cout << "count(" << n << ") = " << count << endl;

	
	cout << "Time = " << omp_get_wtime() - t << endl;*/
	/*int n;
	cin >> n;
	double t = omp_get_wtime();
	int count = 0;
	int m = n*pow(1.0/4.0, 1.0 / 3.0);
	if (n >= 2)
		++count;
#pragma omp parallel sections reduction(+:count)
	{
#pragma omp section
		{
			for (int i = 3; i <= m; i += 2)
			{
				if (isPrime(i))
					++count;
			}
		}
#pragma omp section
		{
			for (int j = m + 1 + (m % 2); j <= n; j += 2)
			{
				if (isPrime(j))
					++count;
			}
		}
	}
	cout << count << endl;
	cout << "Time = " << omp_get_wtime() - t << endl;*/
	int n;
	cin >> n;
	int a = n* pow(1.0 / 16.0, 1.0 / 3.0);
	int b = n*pow(1.0 / 4.0, 1.0 / 3.0);
	int c = (n*(2 * pow(4.0, 1.0 / 3.0) - 1)) / (pow(16.0, 1.0 / 3.0));
	cout << a << ' ' << b << ' ' << c << endl;
	int count = 0;
#pragma omp parallel sections reduction(+:count)
	{
#pragma omp section
		{
			for (int i = 3; i <= a; i += 2)
			{
				if (isPrime(i))
					++count;
			}
		}
#pragma omp section
		{
			//for (int i = a + 1 + (a % 2);)
		}
	}
}