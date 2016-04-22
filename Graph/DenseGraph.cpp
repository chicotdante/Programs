#include "DenseGraph.h"

DenseGraph::DenseGraph(int v){
	V = v;
	Vect.resize(v);
	for (int i = 0; i < v; i++){
		Vect[i].resize(v);
	}
}
DenseGraph::~DenseGraph(){
	Vect.clear();
	V = 0;
}
int DenseGraph::numV(){
	return V;
}
void DenseGraph::addV(){
	V++;
	Vect.resize(V);
	for (int i = 0; i < V; i++){
		Vect[i].resize(V);
	}
}
void DenseGraph::delV(int num){
	for (int i = 0; i < V; i++){
		Vect[i].erase(Vect[i].begin() + num);
	}
	Vect[num].clear();
	V--;
	Vect.resize(V);
}
int DenseGraph::numE(int n){
	int cnt = 0;
	for (int i = 0; i < V; i++){
		if (Vect[n][i])
			cnt++;
	}
	return cnt;
}
void DenseGraph::addE(int m, int n){
	Vect[m][n] = 1;
	Vect[n][m] = 1;
}
void DenseGraph::delE(int n, int m){
	Vect[m][n] = 0;
	Vect[n][m] = 0;
}
bool DenseGraph::chE(int m, int n){
	return Vect[m][n];
}
int DenseGraph::first(int n){
	for (int i = 0; i < V; i++){
		if (Vect[n][i])
			return i;
	}
	return -1;
}
int DenseGraph::next(int n, int m){
	for (int i = m + 1; i < V; i++){
		if (Vect[n][i])
			return i;
	}
	return -1;
}
bool DenseGraph::last(int n, int m){
	bool flag = true;
	for (int i = m + 1; i < V; i++){
		if (Vect[n][i])
			flag = false;
	}
	return flag;
}

/*int main(){
	DenseGraph G(5);
	cout << "Number of Vertexes:" << endl;

	cout << G.numV() << endl;
	G.addV();
	cout << G.numV() << endl;
	G.delV(3);
	cout << G.numV() << endl << endl;

	cout << "Number of Edges:" << endl;

	G.addE(1, 2);
	G.addE(2, 4);
	G.addE(4, 2);
	G.addE(1, 1);

	cout << "1: " << G.numE(1) << endl;
	cout << "4: " << G.numE(4) << endl;
	cout << "0: " << G.numE(0) << endl;

	G.delE(1, 2);
	cout << "After deleting 1 edge for 1st vertex" << endl;
	cout << "1: " << G.numE(1) << endl << endl;

	cout << "Checking edges:" << endl;
	cout << "1-2: " << G.chE(1, 2) << endl;
	cout << "4-2: " << G.chE(4, 2) << endl << endl;

	cout << "First: " << endl;
	G.addE(2, 1);
	cout << "2: " << G.first(2) << endl << endl;

	cout << "Next: " << endl;
	cout << "2: " << G.next(2, 1) << endl << endl;

	cout << "Last: " << endl;
	cout << "2-1: " << G.last(2, 1) << endl;
	cout << "2-5: " << G.last(2, 5) << endl << endl;

	return 0;
}*/