#include <cstdio>
#include <cstdlib>

typedef struct HTnode{
	int count;
	int num;
	struct HTnode *parent;
	struct HTnode *left;
	struct HTnode *right;
}HTnode;

int ReadInt(int* n){
	static char ch;
	static int neg;
	while (((ch = getchar()) < '0' || ch >'9') && ch != '-') if (ch == EOF) return 0;
	if (ch == '-'){
		neg = -1;
		*n = 0;
	}
	else{
		neg = 1;
		*n = ch - '0';
	}
	while ((ch = getchar()) >= '0' && ch <= '9'){
		*n = (*n << 3) + (*n << 1) + ch - '0';
	}
	*n = neg == -1 ? (-*n) : *n;
	return 1;
}

void insert(int sc, HTnode* HTree, int idx){
	static HTnode* ptr;
	ptr = HTree;
	HTree[idx].num = sc;
	HTree[idx].count = 1;
	HTree[idx].left = NULL;
	HTree[idx].right = NULL;
	while (ptr){
		if (sc == ptr->num){
			ptr->count++;
			while (ptr->parent){
				ptr = ptr->parent;
				ptr->count++;
			}
			ptr = NULL;
		}
		else if (sc < ptr->num){
			if (ptr->left != NULL) ptr = ptr->left;
			else{
				HTree[idx].parent = ptr;	
				ptr->left = &(HTree[idx]);
				ptr->count++;
				while (ptr->parent){
					ptr = ptr->parent;
					ptr->count++;
				}
				ptr = NULL;
			}
		}
		else{
			if (ptr->right != NULL) ptr = ptr->right;
			else{
				HTree[idx].parent = ptr;	
				ptr->right = &(HTree[idx]);
				ptr->count++;
				while (ptr->parent){
					ptr = ptr->parent;
					ptr->count++;
				}
				ptr = NULL;
			}
		}
	}
}


int search(int n, HTnode* HTree){
	static HTnode* ptr;
	static int lc, rc;
	ptr = HTree;
	while (ptr->count >= n){
		if (ptr->left) lc = ptr->left->count;
		else lc = 0;
		if (ptr->right) rc = ptr->right->count;
		else rc = 0;

		if (n <= lc) ptr = ptr->left;
		else if (n <= ptr->count - rc) return ptr->num;
		else{
			n -= ptr->count - rc;
			ptr = ptr->right;
		}
	}
}

int main(){
	int t, n, idx, i, score;
	HTnode* HTree;
	HTree = (HTnode*)malloc(sizeof(HTnode)* 40000);
	ReadInt(&t);
	for (; t; t--){
		ReadInt(&n);
		ReadInt(&score);
		HTree[0].count = 1;
		HTree[0].left = NULL;
		HTree[0].right = NULL;
		HTree[0].parent = NULL;
		HTree[0].num = score;
		idx = 1;
		for (i = 1; i < n; ++i){
			ReadInt(&score);
			insert(score, HTree, idx);
			++idx;
		}
		if (n & 1) n = n / 2 + 1;
		else n = n / 2;
		printf("%d\n", search(n, HTree));
	}

	

	system("pause");
}