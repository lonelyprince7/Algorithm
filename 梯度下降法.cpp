/*
需要参数为theta：theta0，theta1
目标函数:y=theta0*x0+theta1*x1;
*/
#include <iostream>
using namespace std;
 
int main()
{
	float matrix[4][2] = { { 1, 1 }, { 2, 1 }, { 2, 2 }, { 3, 4 } };
	float result[4] = {5,6.99,12.02,18};
	float theta[2] = {0,0};
	float loss = 10.0;
	for (int i = 0; i < 10000 && loss>0.0000001; ++i)
	{
		float ErrorSum = 0.0;
		float cost[2] = { 0.0, 0.0 };
		for (int j = 0; j <4; ++j)
		{
			float h = 0.0;
			for (int k = 0; k < 2; ++k)
			{
				h += matrix[j][k] * theta[k];
			}
			
			ErrorSum = result[j] - h;
 
			for (int k = 0; k < 2; ++k)
			{
				cost[k] = ErrorSum*matrix[j][k];
			}
		}
		for (int k = 0; k < 2; ++k)
		{
			theta[k] = theta[k] + 0.01*cost[k] / 4;
		}
 
		cout << "theta[0]=" << theta[0] << "\n" << "theta[1]=" << theta[1] << endl;
		loss = 0.0;
		for (int j = 0; j < 4; ++j)
		{
			float h2 = 0.0;
			for (int k = 0; k < 2; ++k)
			{
				h2 += matrix[j][k] * theta[k];
			}
			loss += (h2 - result[j])*(h2 - result[j]);
		}
		cout << "loss=" << loss << endl;
	}
	return 0;
}