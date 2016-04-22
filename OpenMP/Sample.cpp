//#include <iostream>
//#include <cstdlib>
//#include <omp.h>
//using namespace std;
//int main()
//{
	/*double t = omp_get_wtime();
	int sum = 0;
#pragma omp parallel sections reduction(+:sum)
	{
#pragma omp section
{
	for (int i = 0; i<7000000; i++)
		sum++;
}
#pragma omp section
{
	for (int i = 0; i<7000000; i++)
		sum++;
}
#pragma omp section
{
	for (int i = 0; i<7000000; i++)
		sum++;
}
	}
	cout << "Sum: " << sum << endl;
	cout << "Time: " << omp_get_wtime() - t << endl;
	return EXIT_SUCCESS;
}*/