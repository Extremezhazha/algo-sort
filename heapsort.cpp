#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<climits>
using namespace std;
struct Heap{
	int n, data[1000001], top;
	inline int l(int x){return x << 1;}
	inline int r(int x){return x << 1 | 1;}
	inline int f(int x){return x >> 1;}
	void init(){
		top = n;
	}
	void pushdown(int x){
		if (x > top) return;
		int lv = l(x) > top ? INT_MAX: data[l(x)] , rv = r(x) > top ? INT_MAX : data[r(x)];
		int s = lv < rv ? l(x) : r(x);
		if ((lv < rv ? lv : rv) < data[x]){
			int t = data[x];
			data[x] = data[s];
			data[s] = t;
			pushdown(s);
		}
	}
	void up(int x){
		if (!x) return;
		if (data[f(x)] < data[x]){
			int t = data[f(x)];
			data[f(x)] = data[x];
			data[x] = t;
			up(f(x));
		}
	}
	void build(){
		for (int i=n; i; i--) pushdown(i);
	}
	int pop(){
		int v = data[1];
		data[1] = data[top--];
		pushdown(1);
		return v;
	}
} heap;
int main(){
	srand(time(NULL));
	scanf("%d", &heap.n);
	for (int i=1; i<=heap.n; i++)
		scanf("%d", &heap.data[i]);
	heap.init();
	heap.build();
	for (int i=1; i<=heap.n; i++)
		printf("%d ", heap.pop());
	printf("\n");
	return 0;
}
