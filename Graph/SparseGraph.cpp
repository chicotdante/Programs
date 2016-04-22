#include "SparseGraph.h"

SparseGraph::SparseGraph(int v){
	V = v;
	Vect.resize(v);
}
SparseGraph::~SparseGraph(){
	for (int i = 0; i < V; i++){
		Vect[i].clear();
	}
	Vect.clear();
	V = 0;
}
int SparseGraph::numV(){
	return V;
}
void SparseGraph::addV(){
	V++;
	Vect.resize(V);
}
void SparseGraph::delV(int num){
	Vect.erase(Vect.begin() + num-1);
	for (int i = 0; i < V-1; i++){   //deleting value from each set
		Vect[i].erase(num-1);
		set<int>::iterator it = Vect[i].begin();
		while (it != Vect[i].end()){
			if (*it > num){
				Vect[i].erase(it);
				Vect[i].insert(*it-1);
			}
			it++;
		}
	}
	V--;
}
int SparseGraph::numE(int n){
	int cnt = 0;
	for (set<int>::iterator it = Vect[n-1].begin(); it != Vect[n-1].end(); it++){
		cnt++;
	}
	return cnt;
}
void SparseGraph::addE(int m, int n){
	Vect[m-1].insert(n-1);
	Vect[n-1].insert(m-1);
}
void SparseGraph::delE(int n, int m){
	Vect[m-1].erase(n-1);
	Vect[n-1].erase(m-1);
}
bool SparseGraph::chE(int m, int n){
	set<int>::iterator it = Vect[m - 1].find(n - 1);
	if (it != Vect[m-1].end())
		return true;
	return false;
}
int SparseGraph::first(int n){
	int num = *Vect[n - 1].begin();
	if (num > V || num < 0)
		return -1;
	return num;
}
int SparseGraph::next(int n, int m){
	set<int>::iterator it = Vect[n-1].find(m-1);
	if (it != Vect[n-1].end()){
		it++;
		return *it;
	}
	else
		return -1;
}
bool SparseGraph::last(int n, int m){
	bool flag = true;
	set<int>::iterator it = Vect[n-1].find(m-1);
	if (it != Vect[n-1].end())
		flag = false;
	return flag;
}

/*int main(){
	SparseGraph G(5);
	cout << "Number of Vertexes:" << endl;

	cout << G.numV() << endl;
	G.addV();
	cout << G.numV() << endl;
	G.delV(3);
	cout << G.numV() << endl << endl;

	cout << "Number of Edges:" << endl;

	G.addE(1, 2);
	G.addE(2, 3);
	G.addE(4, 2);
	G.addE(1, 3);

	cout << "1: " << G.numE(1) << endl;
	cout << "4: " << G.numE(4) << endl;
	cout << "2: " << G.numE(2) << endl;

	cout << endl << "Graph before deleting 3 vertex:" << endl;
	for (int i = 1; i <= 4; i++){
		cout << i << ": ";
		for (int j = 1; j <= 4; j++){
			if (G.chE(i, j)){
				cout << j << ' ';
			}
		}
		cout << endl;
	}
	cout << endl;

	G.delV(3);

	cout << endl << "Graph after deleting 3 vertex:" << endl;
	for (int i = 1; i <= 3; i++){
		cout << i << ": ";
		for (int j = 1; j <= 3; j++){
			if (G.chE(i, j)){
				cout << j << ' ';
			}
		}
		cout << endl;
	}
	cout << endl;

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
	cout << "2-3: " << G.last(2, 3) << endl << endl;

	return 0;
}*/