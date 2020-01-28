# include <stdio.h>
# include <algorithm>
using namespace std;
//二进制法求子集 
void print_subset(int n,int s){
	for(int i=0;i<n;i++){
		if(s & (1<<i)) //1左移i位，监测s的哪一位为1，为1的话输出 
			printf("%d ",i);
	} 
	printf("\n");
} 
int main() {
	int n=3;
	for(int i=0;i<(1<<n);i++){//1左移n位等价于2^n-1.因为子集个数2^n-1 
		print_subset(n,i);
	}
	return 0;
}
