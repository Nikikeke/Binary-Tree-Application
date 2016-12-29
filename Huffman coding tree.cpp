#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef struct tree{
	int weight;
	int lc, rc, parent;
}HufNode, *HufTree;

int GetMin(HufTree H, int k){
	int i = 0, min, minWeight;
	while (H[i].parent != -1){
		i++;
	}
	min = i;
	minWeight = H[i].weight;

	for (; i<k; i++){
		if (minWeight > H[i].weight && H[i].parent == -1){
			minWeight = H[i].weight;
			min = i;
		}
	}

	H[min].parent = 1;
	return min;
}

HufTree Create(HufTree &H, int *s, int n){
	int total = 2 * n - 1;
	H = (HufTree)malloc(total*sizeof(HufNode));

	for (int i = 0; i < n; i++){
		H[i].weight = *s;
		H[i].lc = -1;
		H[i].rc = -1;
		H[i].parent = -1;
		s++;
	}

	for (int i = n; i < total; i++){
		H[i].weight = 0;
		H[i].lc = -1;
		H[i].rc = -1;
		H[i].parent = -1;
	}

	int min1, min2;
	for (int i = n; i < total; i++){
		min1 = GetMin(H, i);
		min2 = GetMin(H, i);
		H[min1].parent = i;
		H[min2].parent = i;
		H[i].lc = min1;
		H[i].rc = min2;
		H[i].weight = H[min1].weight + H[min2].weight;
	}

	return H;
}

int Trans(HufTree H, int n){
	int ans = 0;

	for (int i = 0; i < n; i++){
		int deepth = 0;
		int temp = i;
		while (H[i].parent != -1){
			deepth++;
			i = H[i].parent;
		}
		i = temp;
		ans += deepth *H[i].weight;
	}
	return ans;
}

int main(){
	int n;
	cin >> n;
	int s[1000];
	for (int i = 0; i < n; i++){
		cin >> s[i];
	}
	HufTree H = Create(H, s, n);
	printf("%d\n", Trans(H, n));
	return 0;
}