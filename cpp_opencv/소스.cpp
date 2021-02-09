#include <iostream>
#include <opencv2\opencv.hpp>

#include <stdlib.h>
#include <stdio.h>

using namespace std;
using namespace cv;

int func_a(int& a)
{
	a = 30;
	return a;
}

//int main()
//{
//	int idx = 3;
//	func_a(idx);
//	printf("number : %d. \n", idx);
//}