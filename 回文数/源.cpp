#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node* next;
}node;

typedef struct {
    node* top;
    unsigned int size;
} stack;

typedef struct {
    node* front;
    node* back;
    unsigned int size;
} queue;

char pops(stack* a)
{
    node* tf = NULL;
    char rt = 0;
    if (a->size) {
        tf = a->top;
        a->top = a->top->next;
        --a->size;
        rt = tf->data;
        free(tf);
    }

    return rt;
}

char popq(queue* a)
{
    node* tf = NULL;
    char rt = 0;
    if (a->size) {
        tf = a->front;
        a->front = a->front->next;
        --a->size;
        rt = tf->data;
        free(tf);
    }
    return rt;
}

void push(stack* a, const char c)
{
    node* t = (node*)malloc(sizeof(node));
    if (t) {
        t->data = c;
        t->next = a->top;
        a->top = t;
        ++a->size;
    }
}
void push_back(queue* a, const char c)
{
    node* t = (node*)malloc(sizeof(node));
    if (t) {
        t->data = c;
        t->next = NULL;
        if (!a->size) {
            a->front = a->back = t;
        }
        else
        {
            a->back->next = t;
            a->back = t;
        }

        ++a->size;
    }
}

int isempty(void* a, int tp)
{
    if (tp == 1) return !(((stack*)a)->size);
    else return !(((queue*)a)->size);
}
void initqs(void* a, int tp)
{
    if (tp == 1) {
        ((stack*)a)->top = NULL;
        ((stack*)a)->size = 0;
    }
    else {
        ((queue*)a)->front = ((queue*)a)->back = NULL;
        ((queue*)a)->size = 0;
    }
}

void del(void* a, int tp)
{
    node* t;
    if (tp == 1) {
        while (((stack*)a)->top) {
            t = ((stack*)a)->top;
            ((stack*)a)->top = ((stack*)a)->top->next;
            free(t);
        }
        free(a);
    }
    else {
        while (((queue*)a)->front) {
            t = ((queue*)a)->front;
            ((queue*)a)->front = ((queue*)a)->front->next;
            free(t);
        }
        free(a);
    }
}
int chk(void)
{
    char ch;
    int fg = 1, rt = 0;

    stack* a = (stack*)malloc(sizeof(stack));
    queue* b = (queue*)malloc(sizeof(queue));
    if (!a || !b) {
        fprintf(stderr, "内存分配失败");
        exit(-1);
    }
    initqs(a, 1);
    initqs(b, 0);

    puts("输入字符串以 @结尾 ");
    while ((ch = getchar()) != '@')
    {
        push(a, ch);
        push_back(b, ch);
    }

    while (!isempty(a, 1) && !isempty(b, 0))
    {
        if (pops(a) != popq(b)) {
            fg = 0;
            break;
        }
    }
    if (fg && isempty(a, 1) && isempty(b, 0)) rt = 1;
    del(a, 1);
    del(b, 0);
    return rt;

}
int main(void)
{
    if (chk()) puts("YES");
    else puts("NO");

    return 0;
}