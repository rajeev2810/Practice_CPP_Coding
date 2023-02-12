// Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define SWAP(a,b,c) { c t;t=a;a=b;b=t; }
#define MAXIMUM(a, b) (a > b) ? a : b

#include <iostream>

struct student
{
    const char* name;
    int age;
};

void myfunc()
{
    static int x = 5;
    x++;
    printf("%d ", x);
}


void myfunc(const char* q)
{
    q = (char*)malloc(8);
    memcpy((char*)q, "Welcome to Turing", 8);
}

union test {
    char a;
    char b;
    int c;
}t2;

struct test1 {
    char a;
    char b;
    int c;
}t1;

struct pp
{
    int x;
    int y;
};

struct developer
{
    int age;
    char name[10];
}t3;

int main()
{
    char t[20] = "ABCDEFGHIJK";
    int s = strlen(t);
    t[3] = '\0';
    s = strlen(t);
    int a = 10;
    void *p = (void*)0;
   // std::cout << s;

    FILE* fp = stdout;
    int n;
    fprintf(fp, "%d", 45);
    fflush(stdout);
    fprintf(stderr, "%d\n", 65);
    
    //const char* k = "Turing";
    //char* l = k + 5;
   // printf("%c\t%c", *l, k[1]);

    //struct student m;
   // struct student* b = &m;
    //b->name = "Turing";
    //printf("%s", b->name);

    register int i = 20;
    register int* j = &i;
    //printf("%d", sizeof(void*));
    myfunc();
    myfunc();
    printf("\n");

    //for (int j = 1; j <= 10; j = j - 1)
    printf("%d\n", sizeof(t2));
    printf("%d\n", sizeof(t1));

    const char* c1 = "";
    myfunc(c1);
    printf(c1);

    char ya = 'A';
    char yb = 'B';
    printf("%d\n", ya & yb);
    float yc = 4.5;
    if (yc == 4.5)
        printf("c");

    int arr[3][3] = { {2,3,4}, {5,6,7} };
    printf("%u", sizeof(arr)/sizeof(arr[1][1]));
    //turing();

    //strcpy(t3.name, "Turing");
    //printf(t3.name);

    struct pp p1[] = { 1,2,3,4,5,6 };
    struct pp* ptr1 = p1;
    printf("%d %d\n", ptr1->x, (ptr1 + 2)->x);

    int* aptr = new int;
    *aptr = 100;
    std::cout << *aptr + 2;

    int d = 10, e = 20;
    int f = MAXIMUM(d, e);
    SWAP(e, d, int);
    printf("\n%d %d", d, e);

    return 0;
}

void turing()
{
    printf("Turing");
}
