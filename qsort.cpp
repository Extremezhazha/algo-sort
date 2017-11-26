#include<cstdio>
#include<ctime>
#include<cstdlib>
using namespace std;

void sort(int *data, int l, int r){
	int v = data[rand() % (r - l) + l], i = l, j = r , t;
	while (i <= j){
		for (; data[i] < v; i++);
		for (; v < data[j]; j--);
		if (i <= j){
			t = data[i]; data[i] = data[j]; data[j] = t;
			i++; j--;
		}
	}
	if (l < j) sort(data, l, j);
	if (i < r) sort(data, i, r);
}

int n, data[1000001];

int main(){
	srand(time(NULL));
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", data + i);
	sort(data, 1, n);
	for (int i=1; i<=n; i++)
		printf("%d ", data[i]);
	printf("\n");
	return 0;
}
