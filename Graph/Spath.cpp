#include "DenseGraph.h"
#include "SparseGraph.h"

template <class T>
class Spath{
	T &cl;
	bool* marked;
public:
	Spath(T &x):cl(x), marked(new bool[x.numV()]){
		for (int i = 0; i < cl.numV(); i++){
			marked[i] = false;
		}
	}

	bool Path(int V1, int V2){
		if (cl.chE(V1, V2)){
			return true;
		}

		if (cl.numV() > 0){
			int VNext = cl.first(V1), i = 0;
			if (VNext == -1){
				return false;
			}

			while (i < cl.numV()){
				if (!marked[VNext]){
					if (Path(VNext, V2)){
						return true;
					}
				}
				marked[VNext] = true;
				VNext = cl.next(V1, VNext);
				i++;
			}
			Path(VNext, V2);
		}

		return false;
	}
};

//int main(){
//	DenseGraph D(5);
//	D.addE(1, 4);
//	D.addE(3, 1);
//
//	Spath<DenseGraph> P(D);
//	cout << "3-4: " << P.Path(3, 4) << endl;
//	cout << "2-3: " << P.Path(2, 3) << endl;
//	return 0;
//}