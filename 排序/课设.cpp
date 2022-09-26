#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 10000
typedef struct SORTTYPE
{
    char name[30]; //排序名称
    int num_compare;       //比较的次数
    int num_move;       //移动的次数
} ST;        //存储分析效率的数据
int num_compare = 0, num_move = 0; //关键字比较和移动的次数
ST st[9];                 //六种算法的分析数据
//直接插入排序算法
void InsertSort(int a[], int n);
//直接选择排序排序法
void SelectSort(int a[], int n);
//堆排序法
void heapsort(int a[], int n);
//归并排序
void MergeSort(int a[], int n);
//折半插入排序法
void BinInsertSort(int a[], int n);
//希尔排序算法
void ShellSort(int a[], int n);
//冒泡排序算法
void BubbleSort(int a[], int n);
/*快速排序算法*/
int partition(int a[], int s, int t); //一趟划分
//对a[s..t]的元素进行快速排序
void QuickSort(int a[], int s, int t);
void swap(int* a, int* b);
void max_heapify(int arr[], int start, int end);
void heap_sort(int arr[], int len);
//菜单
void menu();
//调用直接插入排序的实现函数，即菜单1
void op1(int a[]);
void op2(int a[]);
void op3(int a[]);
void op4(int a[]);
void op5(int a[]);
void op6(int a[]);
void op7(int a[]);
void op8(int a[]);
void op9(int a[]);

//打印数组数据
void printArray(int a[]);
//给数组生成随机数
void GetaandArray(int a[]);

//直接插入排序算法
void InsertSort(int a[], int n)
{
    int i = 0;
    for (i = 1; 1; i++)
    {   
        int key = a[i];
        int j = i - 1;

        while (j > 0 && a[j] > key) {
            num_compare++;
            num_move++;
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
        num_move++;
    }

}
//选择排序
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    num_move += 3;
}
void SelectSort(int arr[], int n) {
    int i, j,min;
    for (i = 0; i < n; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            num_compare++;
            if (arr[j] < arr[min])
                min = j;
        }
    }swap(&arr[min], &arr[i]);
}


//折半插入排序法
//把无序区插入到有序区里，由于前面的插入排序法实现了有序，所以直接在
//有序区利用折半查找来寻找的改进算法
void BinInsertSort(int a[], int n)
{
    int i, j, low, high, mid;
    int tmp;
    for (i = 1; i < n; i++) //已经比较了n-1次
    {
        if (a[i] < a[i - 1])
        {
            tmp = a[i];
            low = 0;
            high = i - 1;
            num_compare++;
            while (low <= high)
            {
                num_compare++; //while进入比较
                mid = (low + high) / 2;
                if (tmp < a[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            for (j = i - 1; j >= high + 1; j--)
            {
                a[j + 1] = a[j];
                num_move++; //移动次数加一
            }
            a[high + 1] = tmp;
            num_move += 2; //tmp交换
        }
    }
}

//希尔排序算法
void ShellSort(int arr[], int n)
{
    int i, j, inc,key;
    //c初始增量：n/2，每一趟过后除以2
    for (inc = n / 2; inc > 0; inc /= 2) {
        //每一趟采用插入排序
        for (i = inc; i < n; i++) {
            key = arr[i];
            for (j = i; j >= inc && key < arr[j - inc]; j -= inc) {
                num_compare++;
                num_move++;
                arr[j] = arr[j - inc];

            }
            arr[j] = key;

        }

    }

  
}
//冒泡排序算法
void BubbleSort(int arr[],int Length)
{
    int i, j;
    int tmp;
    for (int i = Length; i > 1; i--){
        int swapped = 0;
        for (int j = 1; j < i; j++) {
            num_compare++;
            if (arr[j - 1] > arr[j]) {
                swap(&arr[j - 1], &arr[j]);
                swapped = 1;
            }
        }
     
           
    }
}

/*快速排序算法*/
int partition(int arr[], int low, int high) 
{
    int pivot = arr[high];
   int i = low;
   for (int j = low; j < high; j++) {
       num_compare++;
       if (arr[j] < pivot)
           swap(&arr[j], &arr[i++]);
   }swap(&arr[high], &arr[i]);
      return i;
}

void QuickSort(int arr[], int low, int high)
{
   
    if (low < high) //区间内至少存在两个元素的情况
    {
      int  mid = partition(arr,low,high);
       QuickSort(arr, low, mid - 1);
       QuickSort(arr, mid + 1, high);
    }
}
void QuickSort(int arr[], int len) {
    QuickSort(arr, 0, len - 1);
}



void heapify(int arr[], int n,int i)
{
   
    int largest = i;
    int lson = 1 * 2 + 1;
    int rson = i * 2 + 2;
    if (lson < n && arr[largest] < arr[lson]) {
        num_compare++;
        largest = lson;
    }
    if (rson < n && arr[largest] < arr[rson]) {
        largest = rson;
        num_compare++;
    }
    
    if (largest != i) {
        swap(&arr[largest], &arr[i]);
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n)
{
    int i;//建堆
    //初始化，i从最後一个父节点开始调整
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr,n,i);
    //先将第一个元素和已排好元素前一位做交换，再重新调整，直到排序完毕
    for (i = n - 1; i > 0; i--)
    {
        swap(&arr[i], &arr[0]);
        heapify(arr, i,0);
    }
}

void Merge(int arr[], int tmp[], int start, int mid, int end)//合并小组并排序
{
    int i = start;//i标识//左小组的第一个元素位置
    int j = mid + 1;//j标识//右小组的第一个元素位置
    int k = start;//tmp当前小组存放的起始位置
    while (i < mid + 1 && j < end + 1)//左小组越界或右小组越界才能退出
    {
        if (arr[i] <= arr[j])
        {
            num_compare += 3;
            tmp[k++] = arr[i++];
        }
        else
        {
            tmp[k++] = arr[j++];
        }
    }

    while (j < end + 1)//如果右边小组没有越界
    {
        tmp[k++] = arr[j++];
    }

    while (i < mid + 1)//如果左边小组没有越界
    {
        num_move += 5;
        tmp[k++] = arr[i++];
    }//哦哦就是补齐了，把数组放到新的那个临时数组中去了

    for (i = start; i <= end; i++)
    {
        arr[i] = tmp[i];
    }//至此，原来的数组已经排序完毕
}

void MergeS(int arr[], int tmp[], int start, int end)//划分小组，现在没有end.
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        MergeS(arr, tmp, start, mid);
        MergeS(arr, tmp, mid + 1, end);//自我递归调用
        Merge(arr, tmp, start, mid, end);//现在就全部排号
    }
}//就是递归调用呗

void MergeSort(int arr[], int len)
{
    int* tmp = (int*)malloc(sizeof(int) * len);//开了一个排序后结果保存的临时数组
    MergeS(arr, tmp, 0, len - 1);//嵌套调用
    free(tmp);
}


void menu()
{
    printf("***************************************************\n");
    printf("\t\t1.直接插入排序法\n");
    printf("\t\t2.折半插入排序法\n");
    printf("\t\t3.希尔排序法\n");
    printf("\t\t4.冒泡排序法\n");
    printf("\t\t5.快速排序法\n");
    printf("\t\t6.选择排序法\n");
    printf("\t\t7.堆排序法\n");
    printf("\t\t8.归并排序法\n");
    printf("\t\t9.效率比较\n");
    printf("\t\t10.退出\n");
    printf("***************************************************\n");
    printf("请选择操作：");
}
void printArray(int a[]) //打印数组数据
{
    int i;
    for (i = 0; i < MAX; i++)
        printf("%2d%c", a[i], (i + 1) % 40 ? ' ' : '\n');
    putchar(10);
}

//调用直接插入排序的实现函数，即菜单1
void op1(int a[])
{
    GetaandArray(a);
    printf("伪随机数已经生成的10000个新的随机数\n");
    //打印排序前的数组
    // printArray(a);
    InsertSort(a, MAX);
    // printf("\n利用直接插入排序后的数列如下：\n");
    //打印排序后的数组
    // printArray(a);
    printf("\n\n直接插入排序法：\n一共比较了%d次，移动了%d次\n", num_compare, num_move);
    st[0].num_compare = num_compare;
    st[0].num_move = num_move;
    strcpy(st[0].name, "直接插入排序");
}
void op2(int a[])
{
    GetaandArray(a);
    printf("已经生成10000个新的随机数\n");
    //打印排序前的数组
    //  printArray(a);
    num_compare = 0;
    num_move = 0;
    BinInsertSort(a, MAX);
    printf("\n利用折半插入排序后的数列如下：\n");
    //打印排序后的数组
    // printArray(a);
    printf("\n\n折半插入排序：\n一共比较了%d次，移动了%d次\n", num_compare, num_move);
    st[1].num_compare = num_compare;
    st[1].num_move = num_move;
    strcpy(st[1].name, "折半插入排序");
}

void GetaandArray(int a[]) //为数组获得随机数
{
    int i;
    for (i = 0; i < MAX; i++)
        a[i] = rand() % 100;
}
void op3(int a[])
{
    GetaandArray(a);
    printf("已经生成10000个新的随机数\n");
    //打印排序前的数组
    //printArray(a);
    num_compare = 0;
    num_move = 0;
    ShellSort(a, MAX);
    //printf("\n利用希尔排序算法后的数列如下：\n");
    //打印排序后的数组
    //printArray(a);


    printf("\n\n希尔排序算法：\n一共比较了%d次，移动了%d次\n", num_compare, num_move);
    st[2].num_compare = num_compare;
    st[2].num_move = num_move;
    strcpy(st[2].name, "希尔排序算法");
}
void op4(int a[])
{
    GetaandArray(a);
    printf("已经生成10000个新的随机数\n");

    //打印排序前的数组
    // printArray(a);

    num_compare = 0;
    num_move = 0;
    BubbleSort(a, MAX);

    //  printf("\n利用冒泡排序法后的数列如下：\n");
    //打印排序后的数组

    //  printArray(a);

    printf("\n\n冒泡排序算法：\n一共比较了%d次，移动了%d次\n", num_compare, num_move);
    st[3].num_compare = num_compare;
    st[3].num_move = num_move;
    strcpy(st[3].name, "冒泡排序算法");
}
void op5(int a[])
{
    GetaandArray(a);
    printf("已经生成10000个新的随机数\n");

    //打印排序前的数组
    //printArray(a);
    num_compare = 0;
    num_move = 0;
    QuickSort(a, 0, MAX);
    //  printf("\n利用快速排序算法后的数列如下：\n");
    //打印排序后的数组
    // printArray(a);
    printf("\n\n快速排序算法：\n一共比较了%d次，移动了%d次\n", num_compare, num_move);
    st[4].num_compare = num_compare;
    st[4].num_move = num_move;
    strcpy(st[4].name, "快速排序算法");
}
void op6(int a[])
{
    GetaandArray(a);
    printf("已经生成10000个新的随机数\n");

    //打印排序前的数组
    // printArray(a);

    num_compare = 0;
    num_move = 0;
    SelectSort(a, MAX);

    //  printf("\n利用选择排序法后的数列如下：\n");
    //打印排序后的数组

    //  printArray(a);

    printf("\n\n选择排序算法：\n一共比较了%d次，移动了%d次\n", num_compare, num_move);
    st[5].num_compare = num_compare;
    st[5].num_move = num_move;
    strcpy(st[5].name, "选择排序算法");

}
void op7(int a[])
{
    GetaandArray(a);
    printf("已经生成10000个新的随机数\n");

    //打印排序前的数组
    // printArray(a);

    num_compare = 0;
    num_move = 0;
    heap_sort(a, MAX);

    //  printf("\n利用冒泡排序法后的数列如下：\n");
    //打印排序后的数组

    //  printArray(a);

    printf("\n\n堆排序算法：\n一共比较了%d次，移动了%d次\n", num_compare, num_move);
    st[6].num_compare = num_compare;
    st[6].num_move = num_move;
    strcpy(st[6].name, "堆排序算法");


}
void op8(int a[])
{
    GetaandArray(a);
    printf("已经生成10000个新的随机数\n");
    //打印排序前的数组
    //  printArray(a);
    num_compare = 0;
    num_move = 0;
    MergeSort(a, MAX);
    //  printf("\n利用折半插入排序后的数列如下：\n");
    //打印排序后的数组
    // printArray(a);
    printf("\n\n归并排序：\n一共比较了%d次，移动了%d次\n", num_compare, num_move);
    st[7].num_compare = num_compare;
    st[7].num_move = num_move;
    strcpy(st[7].name, "归并排序");
}
void op9(int a[])
{
    int i;
    printf("各种排序算法的比较于移动次数的对比：\n\n");
    printf("   名称          比较次数          移动次数\n");

    for (i = 0; i < 6; i++)
    {
        printf("%-18s%-18d %d\n", st[i].name, st[i].num_compare, st[i].num_move);
    }
}
int main()
{
    int a[MAX]; //列表数组
    int op;
    srand((unsigned)time(NULL)); //随机种子
    do
    {
        system("cls");
        menu();
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            op1(a);
            break;
        case 2:
            op2(a);
            break;
        case 3:
            op3(a);
            break;
        case 4:
            op4(a);
            break;
        case 5:
            op5(a);
            break;
        case 6:
            op6(a);
            break;
        case 7:
            op7(a);
            break;
        case 8:
            op8(a);
            break;
        case 9:
            op9(a);
            break;
        default:
            break;
        }
        system("pause");

    } while (op != 9);
    return 0;
}

