#include<stdio.h>
int main()
{
    int a =10;//在内存中开辟一块空间
    int *p= &a;//4个字节的空间，这里将a的4个字节的第一个字节的地址存放在p变量中，
    //p就是一个指针变量。
    return 0;
}


//如何遍址
//4字节


//一个指针变量的大小就应该是4个字节。
//64位的机器上，指针变量就是8个字节，才能存放一个地址。
00000000 00000000 00000000 00000000 
00000000 00000000 00000000 00000001




11111111 11111111 11111111 11111111

2^32== 2^32/1024kb==4GB




2.指针和指针类型


int num = 10;
p= &num;

2.1 指针+-整数

int main()
{

    int n=10;
    char *pc=&n;
    int *pi=&n;

    print("%p/n",&n);
    prtin("%p/n",pc);
    print("%p/n",pc+1);  //往后走了一个字节的内容
    print("%p/n",pi);
    print("%p/n",pi+1);   //往后走了4个字节的 内容

    return 0;
}





#include<stdio.h>
int main()
{
    int n= 0x11223344;
    char *pc = (char *)&n;
    int *pi = &n;

    *pc = 0;
    *pi= 0;
    return 0;
}

//3.野指针     指针指向的位置是不可知的（随机的，不正确）


#include<stdio.h>
int main(){

    int *p;
    *p = 20;
    return 0;
}
//1,指针未初始化



int main(){
    int arr[10] = {0};
    int *p = arr;
    int i=0;
    for(i=0;i<=11;i++)
    {
        *(p++) = i;
        //当指针指向的范围超出数组arr的范围时，p就是野指针。
    }
    return 0;
}
//2.当指针指向的范围超出数组arr的范围时，p就是野指针。

//3.指针指向的空间释放，*p就找不到所要指向的地址空间，就指剩下它自己。
//动态内存开辟的时候，
int *p = arr;



//指针初始化
//小心指针越界
//指针指向空间释放 置为NULL。
//指针使用之前检查有效性

int main()
{
    int *p =NULL;

    int a = 10;
    p = &a;

    if (p!= NULL)
    {
        *p=20;
    }
    return 0;
}

//4.指针运算

//4.1.指针+- 整数
//4.2.指针 和 指针
//4.3.指针的 关系运算


//4.1.指针+- 整数
#define N 5
float values[N];
float *vp;  
//vp < & values[N]   指针的关系运算
//vp = &values[0]; 指针+-整数
// *vp++ = 0; 指针+-整数
for (vp = &values[0]; vp < & values[N];)
{
    *vp++ = 0;
}

//4.2 指针 和 指针
int arr[10] = [0,1,2,3,4,5,6,7,8,9]
int *p = arr;
char *mid = NULL;
mid = arr;
int *pend = arr +9;
while (p<=pend)
{
    printf("%d/n",*p);
    p++;
}
return 0;



//4.2.指针 和 指针       类型  进行运算


int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    char c[5];
    //int c[5];
    //printf("d/n",&arr[9]-&arr[0]);
    printf("d/n",&arr[9]-&c[0]);

}



//5.指针和数组

int main(){
    int arr[10]= { 1,2,3,4,5,6,7,8,9,0};
    printf("%p/n",arr);
    printf("%p/n",&arr[0]);
}
//运行结果：
arr = 012FFB90;   //数组名
&arr[0] = 012FFB90;//数组首元素的地址

//结论：数组名表示的是数组首元素的地址


int arr[10]= { 1,2,3,4,5,6,7,8,9,0};
int *p = arr;//p存放的是数组首元素的地址。   p------数组名------数组首元素的地址。

//6.二级指针

//指针变量也是变量，是变量那么就有地址，指针变量的地址存放在哪里？

//*ppa其实访问的就上pa（不带星号）
int b=20;
*ppa = & b; //等价于 pa = & b;

//**ppa 先通过*ppa找到pa，然后再对pa进行引用操作 ：*pa 找到的是a
//**ppa =30 ;               **ppa -----  *pa -----a
//等价于*pa =30;
//等价于a =30;


//7.指针数组
//指针数组是指针还是数组
//是数组，是存放指针的数组

int* arr3[5];





//结构体  java 
//结构体就是一些值的集合，这些值称为成员变量。每个成员都可以是不同类型的变量

struct tag
{
    member-list;
}tag;

typedef struct stu
{
    char name[20];
    int age;
    char sex[5];
}p1; //声明类型的同时定义变量p1
struct stu p2;

struct stu p3 = {"zhang",20,"man" };


struct Node
{
    int data;
    struct stu p;
    struct Node* next;
}n1 = {10,{"zhang",20,"man"}, NULL};



//2.结构体成员的访问

typedef struct stu
{
    char name[20];
    int age;
}; 
struct stu s;


struct S s;
strcpy(s.name, "zhang");
s.age =20;

//3.结构体传参

struct S
{
    int data[1000];
    int num;
}
struct S s= {{1,2,3,4},1000};
//结构体传参
void print1(struct S s)
{
    print(  s.num)
}
//结构体地址传参
void print2(struct S* ps)
{
    print(  ps->num);
}

int main(){
    print1(s); //传结构体,,传值调用
    print2(&s);//传地址，，传址调用
}





//栈的内容
//栈是一种数据结构。
//先进后出，后进先出
//压栈
//出栈
int Add(int x, int y)
{
    int z=0;
    z = x+y;
    return z;
}
int main(){
    int a =3;
    int b= 5;
    int c= 0;
    c = Add(a,b);
    return 0;
}



//指针进阶

//1.字符指针 char*
int main(){
    char ch = 'w';
    char *pc = &ch;
    *pc = 'w';
    return 0;
}

int main(){
    const char* pstr = "hello";  //这里是把一个字符串放到pstr指针变量里吗？ //不是一个字符串
    printf("%s/n",pstr);
    return 0;
}
//本质上是把字符串hello，（首字符） 第一个字符的地址存放到了pstr；


#include<stdio.h>
int main(){

    char str1[] = "hello";
    char str2[] = "hello";
    const char * str3 = "hello";
    const char * str4 = "hello";

    if (str1==str2)
        printf("str1 and str2 are same");
    else 
        printf("str1 and str2 are not same");

    if(str3==str4)
        printf("str3 and str4 are same");
    else
        printf("str3 and str4 are not same");

    return 0;
}

//str1 and str2 are not same
//str3 and str4 are same
//如果指针指向的是一个相同的常量字符串的时候，C/C++就会把常量字符串存储到单独的一个内存空间。
//当几个指针。指向同一个字符串的时候，他们实际会指向同一块内存。结果是相同的
//数组来说，如果用相同的常量字符串区初始化不同的数组的时候，数组会开辟出不同的内存块，导致他们不相同
//剑指offer


//2.指针数组
//是一个存放指针的数组
int *arr1[10];  //整形指针的数组
char * arr2[4]; //一级字符指针的数组    
char **arr3[5];  // 二级字符指针的数组

//3.数组指针
//指针
//整形指针：int *p；能够指向整形数据的指针。
//浮点型指针：float *pf；能够指向浮点型数据的指针
//数组指针，能够指向数组的指针。

int *p1[10];    
//*p1 代表p1是一个的指针变量----》int *p1代表是一个整形的指针变量----》 int *p1[10] 代表是一个整形的指针数组

int (*p2)[10];
//p2先和*结合，*p2是一个指针变量-----》（*p2)[10]， 指向的是一个大小为10个数组----》
//int (*p2)[10] 代表的是指向一个大小为10的整形数组
//所以这个p2代表是一个指针，指向的是一个数组，叫作数组指针。

//【】的优先级要高于*号的， 
//p1,p2分别是什么？

int arr[10]={1,2,3,4,4,5}
int *parr = &arr;

//parr指向的int，arr指的是数组的地址，指向的是数组。


//3.2 &数组名 vs 数组名
int arr[10];

//arr和&arr 分别是什么？
//arr 数组名，数组名表示数组首元素的地址
// &arr 数组名到底是什么？

int main()
{
    int arr[10] ={0};
    printf("%p/n",arr);
    printf("%p/n",&arr);
}
//arr = 00EFF920;
//arr =00EFF920;

int main(){
    
    int arr[10]={0};
    printf("arr =%p/n",arr);
    printf("&arr =%p/n",&arr);

    printf("arr +1 =%p/n",arr+1);
    printf("&arr +1 =%p/n",&arr +1);
}


//arr = 0133FBB0;
//&arr = 0133FBB0;
//arr+1 = 0133FBB4;     //4字节
//&arr+1 = 0133FBD8;   //40字节

//&arr 的类型：int(*)[10],数组指针类型
//数组的地址+1，跳过整个数组的大小，所以&arr+1 相当于&arr的差值40.

//3.3 数组指针的使用


//第一个用法
int main(){
    int arr[10]= {0};
    int (*p)[10] = &arr;//把这个数组arr的地址赋值给数组指针变量p
    return 0;
}

//第二个用法

void print_arr1(int arr[3][5],int row, int col)
{
    int i,j=0;
    for(i=0; i< row; i++)
    {
        for(j= 0;j<col;j++)
        {
            printf("%d", arr[i][j]);
        }
    }
}
void print_arr2(int (*arr)[5],int row, int col)
{
    int j,i=0;
    for (i= 0; i< row; i++)
    {
        for(j= 0;j<col;j++)
        {
            printf("%d", arr[i][j]);
            printf("%d",*(*(arr+i)+j));
        }
    }
}



int main()
{
    int arr[3][5] = {{1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7}};
    print_arr1(arr,3,5);
    //数组名arr，表示首元素的地址
    //二维数组的首元素 是 二维数组的第一行
    //所以在这传递的arr，其实相当于第一行的地址，是一维数组的地址
    //可以数组指针来进行接收
    print_arr2(arr,3,5);
    return 0;
}


//arr[3][5]   vs    (*arr)[5]

//4.函数指针


void test()
{
    printf("hehe");

}
int main(){
    printf("%p",test);
    printf("%p",&test);
}

//013211DB   test函数的地址
//013211DB

void test()
{
    printf("hehe");

}

//下面哪一个有能力存放test函数的地址？
void (*pfun1)();
void *pfun2();

//pfun1可以存放，pfun1先和*结合，(*pfun1)说明pfun1它是一个指针。(*pfun1)()代表指针指向的是一个函数。
//void (*pfun1)()指向的是函数无参数，并且返回值类为void。

//5.函数指针数组
int *arr[10];//数组的每个元素是int
//函数的地址存到一个数组当中，那么这个就叫函数指针数组。


int (*parr1[10])();
//parr1[10] 说明是一个数组
//int (*)()类型的一个函数指针。




//1.动态内存分配
//int val =20;   在栈空间上占4个字节
//char arr[10] = {0}; 栈空间上开辟10个字节的连续空间

//2.动态内存函数的介绍
//malloc和free
void * malloc (size_t size);

void free(void * ptr);


//3.calloc
void * calloc ( size_t num, size_t size);
//区别：只在于calloc会在返回地址之前把申请的空间的每个字节初始化为全0

//4.realloc
void * realloc(void * ptr,size_t size);


// 树的结构

// 图论
// 贪心算法
// 动态规划
// 栈
// 队列


//数组下标都是从0开始
//数组内存空间的地址是连续的

//所以我们在删除或者增添元素，就难免要移动其他元素的地址。
//C++， vector 和 array的区别，vector的底层实现其实就是array， 严格来讲vector是容器，不是数组。
//数组的元素是不能删除的，只能进行覆盖。

//二维数组的内存空间是如何？
//是连续的
//int array[2][3]
//java 
//[I@782e4545354
//

//java
//int [][]arr = new int [3][]{{1,2,3},{4,5}{6,7,8,9}};

//python
//arraylist 容器类的数据机构，列表，
//arr =['python','java',['asp','php'],'c']
//append insert








void print2(int n){
    static int i = 0;
    while(i<= n){
        i= i*2;  //i= i+1; i++;
    }
}
//1-2-4-8-16-32-64-128-256-512-1024------n;
//2^x = n;  
//x的数值为多少？也就是我们要循环多少次，循环的次数。
//x = log2(n); 2在这里是底数，n是真数。
//O(log2n)  时间复杂度

void print2(int n){
    static int i = 0;
    while(i<= n){
        i= i*3;  //i= i+1; i++;
    }
}
//1-3-9-27-81-243-729-2187-6561-19683-59049------n;
//O(log3n)  时间复杂度
//O（logn）对数阶


//log3n= log32*log2n //log32是一个常数，所以可以省略掉
//O(log3n) = O(log2n) 
//无论底数是多少，最终都可以转化为O(log2n)的时间复杂度。
//底数相关的时间复杂度。
//O(logn)//O（logn）对数阶
//简易判断方法：当循环中下标以指定倍数递增或者递减时，时间复杂度为O(logn)。对数阶。

for(i=0;i<n;i=i*2)
{
    printf("hehe");
    
}

//O(nlogn)  时间复杂度

for(j=1;j<n;j++){
    static int i = 0;
    while(i<= n){
        i= i*3;  //i= i+1; i++
    }
}
//线性对数阶




//空间复杂度

void fun2(int n){
    int a=0; ////O(1) 空间复杂度
    int arr[n] = {0};
    for (int i = 0; i < n; i++)
    {
    arr[i] = n;
    }
}

//O(n) 空间复杂度

//二维数组。 二维数组的空间复杂度是多少？
//O(n^2) 空间复杂度
//一维数组，队列，链表，空间复杂度是O(n)
//二维数组，矩阵。空间复杂度是O(n^2)


int age =0;
//实例化；具体化。虚类，实类。
//抽象类。具体类。
struct Stu s1 = {"张三" ， 20， "男" ， "20180"}
struct Stu a2 = {"张四" ， 20， "男" ， "20180"}




char name[20] = "张三
int age = 18;


//update
//new
//delete
//new
//new word
//new word
//new word
// new word
//new word