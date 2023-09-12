#include <iostream>

/*
 * 给定整数n，求解1 + 2 + 3 + ... + n的结果
 */

using namespace std;

long sum1(int n)
{
    long ret = 0;
    int* array = new int[n];

    for(int i = 1; i <= n; i++)
    {
        array[i - 1] = i;
    }

    for(int i = 1; i <= n; i++)
    {
        ret += array[i - 1];
    }

    delete [] array;
    return ret;
}

long sum2(int n)
{
    long ret = 0;

    for(int i = 0; i < n; i++)
    {
        ret += n;
    }

    return ret;
}

long sum3(int n)
{
    long ret = 0;

    if(n > 0)
    {
        ret = (1 + n) * n / 2;
    }

    return ret;
}

int main()
{
	std::cout << "sum1(100) = " << sum1(100) << std::endl;
    std::cout << "sum2(100) = " << sum3(100) << std::endl;
    std::cout << "sum3(100) = " << sum3(100) << std::endl;
	return 0;
}
