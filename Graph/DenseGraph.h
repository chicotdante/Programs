#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <set>

using namespace std;

class DenseGraph{
	int V;
	vector<vector<bool> > Vect;
public:
	DenseGraph(int v = 0);
	~DenseGraph();
	int numV();
	void addV();
	void delV(int num);
	int numE(int n);
	void addE(int m, int n);
	void delE(int n, int m);
	bool chE(int m, int n);
	int first(int n);
	int next(int n, int m);
	bool last(int n, int m);
};