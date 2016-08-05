#include <cstdio>

#ifdef _MSC_VER
#define scanf scanf_s
#endif //_MSC_VER

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define INF 0x7fffffff

using namespace std;

typedef struct{
	int minval;
	int maxval;
}MinMaxNode;


void initTrees(MinMaxNode* DT, int* IT, int N){
	int i;
	for (i = (N << 1) - 1; i; i--){
		DT[i].maxval = -INF;
		DT[i].minval = INF;
		if (i >= N){
			IT[i] = 1;
		}
		else IT[i] = IT[i << 1] + IT[i << 1 | 1];
	}
}

void modifyNode(int idx, int mxv, int mnv, MinMaxNode* DT){
	while (idx && (DT[idx].maxval != mxv || DT[idx].minval != mnv)){
		DT[idx].maxval = mxv;
		DT[idx].minval = mnv;
		mxv = max(mxv, DT[idx ^ 1].maxval);
		mnv = min(mnv, DT[idx ^ 1].minval);
		idx >>= 1;
	}
}

void deleteNode(int idx, MinMaxNode* DT, int* IT){
	
	modifyNode(idx, -INF, INF, DT);
	while (idx){
		IT[idx]--;
		idx >>= 1;
	}
}

int getInitIdx(int curIdx, int N, int* IT){
	int idx_;

	idx_ = 1;
	while (idx_ < N){
		if (curIdx <= IT[idx_ << 1]) idx_ = idx_ << 1;
		else{
			curIdx -= IT[idx_ << 1];
			idx_ = idx_ << 1 | 1;
		} 
	}
	return idx_;
}

void findMinMax(MinMaxNode &ans, int qi, int qj, MinMaxNode* DT){
	ans.maxval = max(DT[qi].maxval, DT[qj].maxval);
	ans.minval = min(DT[qi].minval, DT[qj].minval);
	if (qi == qj) return;
	while ((qi ^ qj) != 1){
		if (~qi & 1){
			ans.maxval = max(ans.maxval, DT[qi^1].maxval);
			ans.minval = min(ans.minval, DT[qi^1].minval);
		}
		if (qj & 1){
			ans.maxval = max(ans.maxval, DT[qj ^ 1].maxval);
			ans.minval = min(ans.minval, DT[qj ^ 1].minval);
		}
		qi >>= 1; 
		qj >>= 1;
	}
}

int ReadInt(int *x) {
	static char c, neg;
	while ((c = getchar()) < '-')    { if (c == EOF) return EOF; }
	neg = (c == '-') ? -1 : 1;
	*x = (neg == 1) ? c - '0' : 0;
	while ((c = getchar()) >= '0')
		*x = (*x << 3) + (*x << 1) + c - '0';
	*x *= neg;
	return 1;
}



int main(){
	int n, m, act, qi, qj, data, i;
	int N;
	MinMaxNode *DataTree, ans;
	int *IndexTree;

	while (scanf("%d %d", &n, &m) == 2){
		for (N = 1; N < n; N <<= 1);
		DataTree = new MinMaxNode[N << 1];
		IndexTree = new int[N << 1];

		initTrees(DataTree, IndexTree, N);

		for (i = N; n; n--, i++){
			ReadInt(&data);
			//scanf("%d", &data);
			modifyNode(i, data, data, DataTree);
		}

		while (m--){
			ReadInt(&act);
			ReadInt(&qi);
			//scanf("%d %d", &act, &qi);
			if (act == 1){
				qi = getInitIdx(qi, N, IndexTree);
				deleteNode(qi, DataTree, IndexTree);

			}
			else{
				ReadInt(&qj);
				//scanf("%d", &qj);
				qi = getInitIdx(qi, N, IndexTree);
				qj = getInitIdx(qj, N, IndexTree);
				findMinMax(ans, qi, qj, DataTree);
				printf("%d %d\n", ans.minval, ans.maxval);
			}
		}
	}
}