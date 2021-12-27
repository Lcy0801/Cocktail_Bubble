#include <iostream>
#include <ctime>
using namespace std;
// 一般的冒泡排序算法
void bubbleSort(double s[], const int n)
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
void bubbleSortPlus(double s[], const int n)
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
        int index = 0;
        for (int j = 0; j < lastindex; j++)
        {
            if (s[j] > s[j + 1])
            {
                double temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
                index = j;
                flag = false;
            }
        }
        if (flag)
        {
            break;
        }
        else
        {
            lastindex = index;
        }
    }
    return;
}

//基于冒泡排序改进的鸡尾酒排序算法
void cocktailSort(double s[], const int n)
{
    if (n <= 1)
    {
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = true;
        if (i % 2 == 0)
        {
            // 从左向右循环 将最大值放在右侧有序序列中
            // i=0 0 n-2-0
            // i=2 1 n-2-1
            // i=4 2 n-2-2
            // i=6 3 n-2-3
            // 依次类推
            for (int j = i / 2; j < n - i / 2 - 1; j++)
            {
                if (s[j] > s[j + 1])
                {
                    int temp = s[j];
                    s[j] = s[j + 1];
                    s[j + 1] = temp;
                    flag = false;
                }
            }
        }
        else
        {
            // 从右向左循环 将最小值放在左侧有序序列中
            // i=1 n-1-1 1
            // i=3 n-1-2 2
            // i=5 n-1-3 3
            // i=7 n-1-4 4
            // 依次类推
            for (int j = n - 1 - (i + 1) / 2; j > i / 2; j--)
            {
                if (s[j - 1] > s[j])
                {
                    double temp = s[j];
                    s[j] = s[j - 1];
                    s[j - 1] = temp;
                    flag = false;
                }
            }
        }
        if (flag)
        {
            break;
        }
    }
    return;
}

// 鸡尾酒排序算法改进,记录下每一轮循环中最后交换元素的位置
void cocktailSortPlus(double s[], const int n)
{
    if(n<=1)
    {
        return;
    }
    int rightIndex=n-1;
    int leftIndex=0;
    for(int i=0;i<n-1;i++)
    {
        bool flag=true;
        int index;
        if(i%2==0)
        {
            // 奇数次,从左向右循环
            for(int j=leftIndex;j<rightIndex;j++)
            {
                if(s[j]>s[j+1])
                {
                    double temp=s[j];
                    s[j]=s[j+1];
                    s[j+1]=temp;
                    flag=false;
                    index=j;
                }
            }
        }
        else
        {
            // 偶数次,从右向左循环
            for(int j=rightIndex;j>leftIndex;j--)
            {
                if(s[j]<s[j-1])
                {
                    double temp=s[j];
                    s[j]=s[j-1];
                    s[j-1]=temp;
                    index=j;
                    flag=false;
                }
            }
        }
        if(flag)
        {
            break;
        }
        else if(i%2==0)
        {
            rightIndex=index;
        }
        else
        {
            leftIndex=index;
        }
    }
    return;
}

int main()
{
    double s[10];
    srand((int)time(NULL));
    cout << "排序前" << endl;
    for (int i = 0; i < 10; i++)
    {
        s[i] = rand() % 100;
        cout << s[i] << endl;
    }
    cout << "排序后" << endl;
    // bubbleSort(s,10);
    // bubbleSortPlus(s,10);
    // cocktailSort(s,10);
    cocktailSortPlus(s, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << s[i] << endl;
    }
    system("pause");
    return 0;
}