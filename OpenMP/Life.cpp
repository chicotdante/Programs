#include <iostream>
#include <cstdlib>
#include <omp.h>
#include <time.h>
#include <cmath>
using namespace std;

const int m = 1000, n = 1000;
float field[m+2][n+2] = { 0 };

int main(){
	srand(time(NULL));
	for (int i = 1; i < m - 1; i++){
		for (int j = 1; j < n - 1; j++){
			field[i][j] = rand() % 2;
		}
	}
	int sum;
	double t = omp_get_wtime();

#pragma omp parallel for
	for (int r = 0; r < 100; r++){
		for (int i = 1; i < m - 1; i++){
			for (int j = 1; j < n - 1; j++){
				sum = field[i - 1][j - 1] + field[i - 1][j] + field[i - 1][j + 1] + 
					field[i][j - 1] + field[i][j + 1] + 
					field[i + 1][j - 1] + field[i + 1][j] + field[i + 1][j + 1];
				if (sum < 2 || sum > 3){
					field[i][j] = 0;
				}
				if (sum == 3){
					field[i][j] = 0;
				}
			}
		}
	}

	

/*#pragma omp parallel sections
	{
#pragma omp section
	{
		for (int r = 0; r < 25; r++){
			for (int i = 1; i < m - 1; i++){
				for (int j = 1; j < n - 1; j++){
					sum = field[i - 1][j - 1] + field[i - 1][j] + field[i - 1][j + 1] +
						field[i][j - 1] + field[i][j + 1] +
						field[i + 1][j - 1] + field[i + 1][j] + field[i + 1][j + 1];
					if (sum < 2 || sum > 3){
						field[i][j] = 0;
					}
					if (sum == 3){
						field[i][j] = 0;
					}
				}
			}
		}
	}
#pragma omp section
	{
		for (int r = 25; r < 50; r++){
			for (int i = 1; i < m - 1; i++){
				for (int j = 1; j < n - 1; j++){
					sum = field[i - 1][j - 1] + field[i - 1][j] + field[i - 1][j + 1] +
						field[i][j - 1] + field[i][j + 1] +
						field[i + 1][j - 1] + field[i + 1][j] + field[i + 1][j + 1];
					if (sum < 2 || sum > 3){
						field[i][j] = 0;
					}
					if (sum == 3){
						field[i][j] = 0;
					}
				}
			}
		}
	}
#pragma omp section
	{
		for (int r = 50; r < 75; r++){
			for (int i = 1; i < m - 1; i++){
				for (int j = 1; j < n - 1; j++){
					sum = field[i - 1][j - 1] + field[i - 1][j] + field[i - 1][j + 1] +
						field[i][j - 1] + field[i][j + 1] +
						field[i + 1][j - 1] + field[i + 1][j] + field[i + 1][j + 1];
					if (sum < 2 || sum > 3){
						field[i][j] = 0;
					}
					if (sum == 3){
						field[i][j] = 0;
					}
				}
			}
		}
	}
#pragma omp section
	{
		for (int r = 75; r < 100; r++){
			for (int i = 1; i < m - 1; i++){
				for (int j = 1; j < n - 1; j++){
					sum = field[i - 1][j - 1] + field[i - 1][j] + field[i - 1][j + 1] +
						field[i][j - 1] + field[i][j + 1] +
						field[i + 1][j - 1] + field[i + 1][j] + field[i + 1][j + 1];
					if (sum < 2 || sum > 3){
						field[i][j] = 0;
					}
					if (sum == 3){
						field[i][j] = 0;
					}
				}
			}
		}
	}
	}*/

	cout << "Time: " << omp_get_wtime() - t << endl;

	return EXIT_SUCCESS;
}