#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
	srand(time(NULL));
	int n, i, l, h;
	scanf("%d%d%d", &n, &l, &h);
	printf("%d\n", n);
	for (i=1; i<=n; i++)
		printf("%d ", rand() % (h - l) + l);
	return 0;
}
