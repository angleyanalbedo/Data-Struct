#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 10000
typedef struct SORTTYPE
{
    char name[30]; //��������
    int num_compare;       //�ȽϵĴ���
    int num_move;       //�ƶ��Ĵ���
} ST;        //�洢����Ч�ʵ�����
int num_compare = 0, num_move = 0; //�ؼ��ֱȽϺ��ƶ��Ĵ���
ST st[9];                 //�����㷨�ķ�������
//ֱ�Ӳ��������㷨
void InsertSort(int a[], int n);
//ֱ��ѡ����������
void SelectSort(int a[], int n);
//������
void heapsort(int a[], int n);
//�鲢����
void MergeSort(int a[], int n);
//�۰��������
void BinInsertSort(int a[], int n);
//ϣ�������㷨
void ShellSort(int a[], int n);
//ð�������㷨
void BubbleSort(int a[], int n);
/*���������㷨*/
int partition(int a[], int s, int t); //һ�˻���
//��a[s..t]��Ԫ�ؽ��п�������
void QuickSort(int a[], int s, int t);
void swap(int* a, int* b);
void max_heapify(int arr[], int start, int end);
void heap_sort(int arr[], int len);
//�˵�
void menu();
//����ֱ�Ӳ��������ʵ�ֺ��������˵�1
void op1(int a[]);
void op2(int a[]);
void op3(int a[]);
void op4(int a[]);
void op5(int a[]);
void op6(int a[]);
void op7(int a[]);
void op8(int a[]);
void op9(int a[]);

//��ӡ��������
void printArray(int a[]);
//���������������
void GetaandArray(int a[]);

//ֱ�Ӳ��������㷨
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
//ѡ������
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


//�۰��������
//�����������뵽�����������ǰ��Ĳ�������ʵ������������ֱ����
//�����������۰������Ѱ�ҵĸĽ��㷨
void BinInsertSort(int a[], int n)
{
    int i, j, low, high, mid;
    int tmp;
    for (i = 1; i < n; i++) //�Ѿ��Ƚ���n-1��
    {
        if (a[i] < a[i - 1])
        {
            tmp = a[i];
            low = 0;
            high = i - 1;
            num_compare++;
            while (low <= high)
            {
                num_compare++; //while����Ƚ�
                mid = (low + high) / 2;
                if (tmp < a[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            for (j = i - 1; j >= high + 1; j--)
            {
                a[j + 1] = a[j];
                num_move++; //�ƶ�������һ
            }
            a[high + 1] = tmp;
            num_move += 2; //tmp����
        }
    }
}

//ϣ�������㷨
void ShellSort(int arr[], int n)
{
    int i, j, inc,key;
    //c��ʼ������n/2��ÿһ�˹������2
    for (inc = n / 2; inc > 0; inc /= 2) {
        //ÿһ�˲��ò�������
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
//ð�������㷨
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

/*���������㷨*/
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
   
    if (low < high) //���������ٴ�������Ԫ�ص����
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
    int i;//����
    //��ʼ����i������һ�����ڵ㿪ʼ����
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr,n,i);
    //�Ƚ���һ��Ԫ�غ����ź�Ԫ��ǰһλ�������������µ�����ֱ���������
    for (i = n - 1; i > 0; i--)
    {
        swap(&arr[i], &arr[0]);
        heapify(arr, i,0);
    }
}

void Merge(int arr[], int tmp[], int start, int mid, int end)//�ϲ�С�鲢����
{
    int i = start;//i��ʶ//��С��ĵ�һ��Ԫ��λ��
    int j = mid + 1;//j��ʶ//��С��ĵ�һ��Ԫ��λ��
    int k = start;//tmp��ǰС���ŵ���ʼλ��
    while (i < mid + 1 && j < end + 1)//��С��Խ�����С��Խ������˳�
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

    while (j < end + 1)//����ұ�С��û��Խ��
    {
        tmp[k++] = arr[j++];
    }

    while (i < mid + 1)//������С��û��Խ��
    {
        num_move += 5;
        tmp[k++] = arr[i++];
    }//ŶŶ���ǲ����ˣ�������ŵ��µ��Ǹ���ʱ������ȥ��

    for (i = start; i <= end; i++)
    {
        arr[i] = tmp[i];
    }//���ˣ�ԭ���������Ѿ��������
}

void MergeS(int arr[], int tmp[], int start, int end)//����С�飬����û��end.
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        MergeS(arr, tmp, start, mid);
        MergeS(arr, tmp, mid + 1, end);//���ҵݹ����
        Merge(arr, tmp, start, mid, end);//���ھ�ȫ���ź�
    }
}//���ǵݹ������

void MergeSort(int arr[], int len)
{
    int* tmp = (int*)malloc(sizeof(int) * len);//����һ����������������ʱ����
    MergeS(arr, tmp, 0, len - 1);//Ƕ�׵���
    free(tmp);
}


void menu()
{
    printf("***************************************************\n");
    printf("\t\t1.ֱ�Ӳ�������\n");
    printf("\t\t2.�۰��������\n");
    printf("\t\t3.ϣ������\n");
    printf("\t\t4.ð������\n");
    printf("\t\t5.��������\n");
    printf("\t\t6.ѡ������\n");
    printf("\t\t7.������\n");
    printf("\t\t8.�鲢����\n");
    printf("\t\t9.Ч�ʱȽ�\n");
    printf("\t\t10.�˳�\n");
    printf("***************************************************\n");
    printf("��ѡ�������");
}
void printArray(int a[]) //��ӡ��������
{
    int i;
    for (i = 0; i < MAX; i++)
        printf("%2d%c", a[i], (i + 1) % 40 ? ' ' : '\n');
    putchar(10);
}

//����ֱ�Ӳ��������ʵ�ֺ��������˵�1
void op1(int a[])
{
    GetaandArray(a);
    printf("α������Ѿ����ɵ�10000���µ������\n");
    //��ӡ����ǰ������
    // printArray(a);
    InsertSort(a, MAX);
    // printf("\n����ֱ�Ӳ����������������£�\n");
    //��ӡ����������
    // printArray(a);
    printf("\n\nֱ�Ӳ������򷨣�\nһ���Ƚ���%d�Σ��ƶ���%d��\n", num_compare, num_move);
    st[0].num_compare = num_compare;
    st[0].num_move = num_move;
    strcpy(st[0].name, "ֱ�Ӳ�������");
}
void op2(int a[])
{
    GetaandArray(a);
    printf("�Ѿ�����10000���µ������\n");
    //��ӡ����ǰ������
    //  printArray(a);
    num_compare = 0;
    num_move = 0;
    BinInsertSort(a, MAX);
    printf("\n�����۰�����������������£�\n");
    //��ӡ����������
    // printArray(a);
    printf("\n\n�۰��������\nһ���Ƚ���%d�Σ��ƶ���%d��\n", num_compare, num_move);
    st[1].num_compare = num_compare;
    st[1].num_move = num_move;
    strcpy(st[1].name, "�۰��������");
}

void GetaandArray(int a[]) //Ϊ�����������
{
    int i;
    for (i = 0; i < MAX; i++)
        a[i] = rand() % 100;
}
void op3(int a[])
{
    GetaandArray(a);
    printf("�Ѿ�����10000���µ������\n");
    //��ӡ����ǰ������
    //printArray(a);
    num_compare = 0;
    num_move = 0;
    ShellSort(a, MAX);
    //printf("\n����ϣ�������㷨����������£�\n");
    //��ӡ����������
    //printArray(a);


    printf("\n\nϣ�������㷨��\nһ���Ƚ���%d�Σ��ƶ���%d��\n", num_compare, num_move);
    st[2].num_compare = num_compare;
    st[2].num_move = num_move;
    strcpy(st[2].name, "ϣ�������㷨");
}
void op4(int a[])
{
    GetaandArray(a);
    printf("�Ѿ�����10000���µ������\n");

    //��ӡ����ǰ������
    // printArray(a);

    num_compare = 0;
    num_move = 0;
    BubbleSort(a, MAX);

    //  printf("\n����ð�����򷨺���������£�\n");
    //��ӡ����������

    //  printArray(a);

    printf("\n\nð�������㷨��\nһ���Ƚ���%d�Σ��ƶ���%d��\n", num_compare, num_move);
    st[3].num_compare = num_compare;
    st[3].num_move = num_move;
    strcpy(st[3].name, "ð�������㷨");
}
void op5(int a[])
{
    GetaandArray(a);
    printf("�Ѿ�����10000���µ������\n");

    //��ӡ����ǰ������
    //printArray(a);
    num_compare = 0;
    num_move = 0;
    QuickSort(a, 0, MAX);
    //  printf("\n���ÿ��������㷨����������£�\n");
    //��ӡ����������
    // printArray(a);
    printf("\n\n���������㷨��\nһ���Ƚ���%d�Σ��ƶ���%d��\n", num_compare, num_move);
    st[4].num_compare = num_compare;
    st[4].num_move = num_move;
    strcpy(st[4].name, "���������㷨");
}
void op6(int a[])
{
    GetaandArray(a);
    printf("�Ѿ�����10000���µ������\n");

    //��ӡ����ǰ������
    // printArray(a);

    num_compare = 0;
    num_move = 0;
    SelectSort(a, MAX);

    //  printf("\n����ѡ�����򷨺���������£�\n");
    //��ӡ����������

    //  printArray(a);

    printf("\n\nѡ�������㷨��\nһ���Ƚ���%d�Σ��ƶ���%d��\n", num_compare, num_move);
    st[5].num_compare = num_compare;
    st[5].num_move = num_move;
    strcpy(st[5].name, "ѡ�������㷨");

}
void op7(int a[])
{
    GetaandArray(a);
    printf("�Ѿ�����10000���µ������\n");

    //��ӡ����ǰ������
    // printArray(a);

    num_compare = 0;
    num_move = 0;
    heap_sort(a, MAX);

    //  printf("\n����ð�����򷨺���������£�\n");
    //��ӡ����������

    //  printArray(a);

    printf("\n\n�������㷨��\nһ���Ƚ���%d�Σ��ƶ���%d��\n", num_compare, num_move);
    st[6].num_compare = num_compare;
    st[6].num_move = num_move;
    strcpy(st[6].name, "�������㷨");


}
void op8(int a[])
{
    GetaandArray(a);
    printf("�Ѿ�����10000���µ������\n");
    //��ӡ����ǰ������
    //  printArray(a);
    num_compare = 0;
    num_move = 0;
    MergeSort(a, MAX);
    //  printf("\n�����۰�����������������£�\n");
    //��ӡ����������
    // printArray(a);
    printf("\n\n�鲢����\nһ���Ƚ���%d�Σ��ƶ���%d��\n", num_compare, num_move);
    st[7].num_compare = num_compare;
    st[7].num_move = num_move;
    strcpy(st[7].name, "�鲢����");
}
void op9(int a[])
{
    int i;
    printf("���������㷨�ıȽ����ƶ������ĶԱȣ�\n\n");
    printf("   ����          �Ƚϴ���          �ƶ�����\n");

    for (i = 0; i < 6; i++)
    {
        printf("%-18s%-18d %d\n", st[i].name, st[i].num_compare, st[i].num_move);
    }
}
int main()
{
    int a[MAX]; //�б�����
    int op;
    srand((unsigned)time(NULL)); //�������
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

