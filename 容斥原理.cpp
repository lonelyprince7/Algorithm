#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define LL long long
int n, m[130], a, b;
LL ans;
LL gcd (LL a, LL b){//最大公因数
    if (! b)
        return a;
    return gcd (b, a % b);
}
LL lcm (LL a, LL b){//最小公倍数
    return a * b / gcd (a, b);
}
void dfs (int k, int Index, LL v){//k代表第几次并集，Index代表到了第几个集合，v代表这个集合，如v=8，就代表8的倍数这个集合
    if (v > b)//超出范围就没有意义
        return ;
    if (k % 2 == 0)//第偶数次加，第基数次减
        ans += b / v - a / v;
    else
        ans -= b / v - a / v;
    for (int i = Index + 1; i <= n; i ++){
        LL t = lcm (v, m[i]);//求着两个集合的并集
        dfs (k + 1, i, t);//递归求解
    }
}
int main (){
    scanf ("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf ("%d", &m[i]);
    scanf ("%d %d", &a, &b);
    dfs (0, 0, 8);//从第0次开始
    printf ("%lld\n", ans);
    return 0;
}


// 二.例题：组合数学
// 1.题目
// 1.1.题目描述
// 八是个很有趣的数字啊。八=发，八八=爸爸，88=拜拜。当然最有趣的还是8用二进制表示是1000。怎么样，有趣吧。当然题目和这些都没有关系。 某个人很无聊，他想找出[a,b]中能被8整除却不能被其他一些数整除的数。

// 1.2.输入
// 第一行一个数n，代表不能被整除的数的个数。 第二行n个数，中间用空格隔开。 第三行两个数a，b，中间一个空格。 a < =b < =1000000000

// 1.3.输出
// 一个整数，为[a,b]间能被8整除却不能被那n个数整除的数的个数。

// 1.4.样例输入
// 3

// 7764 6082 462

// 2166 53442

// 1.5.样例输出
// 6378
