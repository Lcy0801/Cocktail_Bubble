#include <iostream>
#include <ctime>
using namespace std;
// 一般的冒泡排序算法
void bubbleSort(double s[], int n)
{
    if (n <= 1)
    {
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = true;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (s[j] > s[j + 1])
            {
                double temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
                flag = false;
            }
        }
        if (flag)
        {
            break;
        }
    }
    return;
}

//改进的冒泡排序算法 记录下每轮循环中最后交换元素的位置
void bubbleSortPlus(double s[], int n)
{
    if (n <= 1)
    {
        return;
    }
    // 初始化最后交换元素的位置
    int lastindex = n - 1;
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = true;
        int index=0;
        for (int j = 0; j < lastindex; j++)
        {
            if (s[j] > s[j + 1])
            {
                double temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
                index=j;
                flag = false;
            }
        }
        if (flag)
        {
            break;
        }
        else
        {
            lastindex=index;
        }
    }
    return;
}

int main()
{
    double s[10];
    srand((int)time(NULL));
    cout<<"排序前"<<endl;
    for (int i = 0; i < 10; i++)
    {
        s[i] = rand() % 100;
        cout << s[i] << endl;
    }
    cout<<"排序后"<<endl;
    bubbleSortPlus(s,10);
    for (int i = 0; i < 10; i++)
    {
        cout << s[i] << endl;
    }
    system("pause");
    return 0;
}