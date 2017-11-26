#include<cstdio>
#include<ctime>
#include<cstdlib>
using namespace std;

struct node{
	int v;
	node *next;
	node(int v){
		this -> v = v;
		this -> next = NULL;
	}
	node* connect(node* next){
		this -> next = next;
		return this;
	}
};

node* merge(node* lhs, node* rhs){
	if (!lhs) return rhs;
	if (!rhs) return lhs;
	return lhs -> v < rhs -> v ? lhs -> connect(merge(lhs -> next, rhs)) : rhs -> connect(merge(lhs, rhs -> next));
}

node* sorted(int *data, int l, int r){
	int mid = (l + r) >> 1;
	return l == r ? new node(data[l]) : merge(sorted(data, l, mid) , sorted(data, mid+1, r));
}

void sort(int *data, int l, int r){
	node* list = sorted(data, l, r), *last = NULL;
	while (l <= r){
		data[l++] = list -> v;
		last = list;
		list = list -> next;
		delete last;
	}
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
