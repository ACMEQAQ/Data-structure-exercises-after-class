#include <iostream>

using namespace std;
//.定义存储表示
typedef int ElemType;               //定义ElemType类型为int
# define MAXSIZE 100  // 顺序表的最大长度
int i, j;//定义全局变量
typedef struct {              //若后面不再用，可省略结构名
    ElemType* elem;         //存储空间基址
    int length;      //当前表长（特指元素个数）
}SqList;
typedef int ElemType; //这个为什么重新定义？

//.定义操作函数1 初始化数组
ElemType InitList(SqList& L)
{ //构造一个空的线性表L。
    L.elem = new ElemType[MAXSIZE];
    L.length = 0;  // 空表长度为0
    return 1;
}

//.定义操作函数2 销毁数组
void DestroyList(SqList& L)
{
    if (L.elem) delete[] L.elem;    //释放存储空间
    L.length = 0;
    L.elem = NULL;
}

//1 函数 清空线性表
void ClearList(SqList& L)
{
    L.length = 0;                //将线性表的长度置为0
}

//2 函数 判断线性表是否为空
bool ListEmpty(SqList L)
{
    if (L.length == 0)
        return true;
    else
        return false;
}

//3.定义操作函数3 求数组长度
int GetLength(SqList L)
{
    return L.length;
}

//4 函数 取线性表指定位置的值
ElemType GetElem(SqList L, int i, ElemType& e)
{
    //判断i值是否合理，若不合理，返回ERROR
    if (i<1 || i>L.length) return -1;
    e = L.elem[i - 1];   //第i-1个单元存储第i个数据
    return 1;
}

//5 函数 求前驱
ElemType PriorElem(SqList L, ElemType e, int& pre_e) {
    for (i = 0; i < L.length; i++) {
        if (e == L.elem[i]) {
            if (i == 0)return 0;
            else {
                pre_e = L.elem[i - 1];
                return 1;
            }
        }
    }
    return 0;
}

//6 求后继
ElemType NextElem(SqList L, ElemType e, int& next_e) {
    for (i = 0; i < L.length; i++) {
        if (e == L.elem[i]) {
            if (i == L.length - 1) return 0;
            else {
                    next_e = L.elem[i + 1];
                    return 1;
            }
        }
    }
    return 0;
}

//7 函数 在指定位置插入值
ElemType ListInsert(SqList& L, int i, ElemType e) {
    if (i<1 || i>L.length + 1)  return -1;   //i值不合法
    if (L.length == MAXSIZE)  return -1;
    //当前存储空间已满
    for (j = L.length - 1; j >= i - 1; j--)
        L.elem[j + 1] = L.elem[j];   //插入位置及之后的元素后移
    L.elem[i - 1] = e;                     //将新元素e放入第i个位置
    ++L.length;	//表长增1
    return 1;
}

//8 函数 删除指定位置元素
ElemType ListDelete(SqList& L, int i, ElemType& e) {
    if ((i < 1) || (i > L.length)) return -1;	 //i值不合法
    e = L.elem[i - 1];
    for (j = i; j <= L.length - 1; j++)
        L.elem[j - 1] = L.elem[j]; //被删除元素之后的元素前移
    --L.length;               	      //表长减1
    return 1;
}

//9 函数 显示线性表
void Display(SqList L) {
    for (i = 1; i <= L.length; ++i)
        cout << L.elem[i - 1] << " ";
    cout << endl;
}

//10 求两个顺序表的并集
//判断顺序表内是否有和外部相同的元素
ElemType LocateElem(SqList L, ElemType e,int& i) {
    for (i = 0; i <= L.length - 1; ++i) {
        if (e == L.elem[i]) return 1;
        else return 0;
    }
    return 0;
}
//并集主函数
void Union(SqList& La, SqList Lb){
    ElemType e;
    int j;
    for (i = 1; i <= Lb.length; i++) {
        GetElem(Lb, i, e); // 取Lb中第i个数据元素赋给e
        if (!LocateElem(La, e,j))
            ListInsert(La, ++La.length, e);
        // La中不存在和 e 相同的数据元素，则插入之
    }
}

//11 求两个顺序表的交集
void JiaoJi(SqList& La, SqList Lb) {
    SqList Lc;
    ElemType e;
    int j;
    for (i = 1; i <= Lb.length; i++) {
        GetElem(Lb, i, e); // 取Lb中第i个数据元素赋给e
        if (LocateElem(La, e,j))
            ListInsert(Lc, ++Lc.length, e);
        // La中存在和 e 相同的数据元素，插入Lc中
    }
}

//12 求两个顺序表的差
void Delete(SqList& La, SqList Lb) {
    ElemType e;
    int j;
    for (i = 1; i <= Lb.length; i++) {
        GetElem(Lb, i, e); // 取Lb中第i个数据元素赋给e
        if (LocateElem(La, e,j))
            ListDelete(La, j, e);
        // La中存在和 e 相同的数据元素，则删除之
    }
}

// 提示语句
void show_help()
{
    cout << "******* Data Structure ******" << endl;
    cout << "1----清空线性表" << endl;
    cout << "2----判断线性表是否为空" << endl;
    cout << "3----求线性表长度" << endl;
    cout << "4----获取线性表指定位置元素" << endl;
    cout << "5----求前驱" << endl;
    cout << "6----求后继" << endl;
    cout << "7----在线性表指定位置插入元素" << endl;
    cout << "8----删除线性表指定位置元素" << endl;
    cout << "9----显式线性表" << endl;
    cout << "10---求两个顺序表的并集" << endl;
    cout << "11---求两个顺序表的交集" << endl;
    cout << "12---求两个顺序表的差" << endl;
    cout << "     退出，输入0" << endl;
}


int main()
{
    ElemType e;
    string operate_code;
    show_help();
    //定义线性表变量，如SqList L;
    SqList L;
    //调用初始化线性表函数，如Init_List(L);
    InitList(L);
    while (1)
    {
        cout << "请输入操作代码：";
        cin >> operate_code;
        if (operate_code == "1")
        {
            //调用操作函数1
            ClearList(L);

        }
        else if (operate_code == "2")
        {
            if (ListEmpty(L)) cout << "The list is empty." << endl;
            else cout << "The list is not empty." << endl;
        }
        else if (operate_code == "3")
        {
            cout << "the length of list is:" << GetLength(L) << endl;
        }
        else if (operate_code == "4")
        {
            cout << "想要获取元素的位置：";
            cin >> i;
            if (GetElem(L, i, e) == -1) cout << "不存在" << endl;
            else cout << "所求元素为：" << e << endl;
        }
        else if (operate_code == "5")
        {
            cout << "求哪个元素的前驱（不保证该元素存在）：";
            cin >> e;
            int a=0;
            if (!PriorElem(L, e, a)) cout << "不存在元素" << endl;
            else cout << "该元素为：" << a << endl;
        }
        else if (operate_code == "6")
        {
            int a=0;
            cout << "求哪个元素的后继（不保证该元素存在）：";
            cin >> e;
            if (!NextElem(L, e, a)) cout << "不存在元素" << endl;
            else cout << "该元素为：" << a << endl;
        }
        else if (operate_code == "7")
        {
            cout << "输入想要插入的位置和值：";
            cin >> i >> e;
            ListInsert(L, i, e);

        }
        else if (operate_code == "8")
        {
            cout << "输入想要删除的位置和值：";
            cin >> i >> e;
            ListDelete(L, i, e);
        }
        else if (operate_code == "9")
        {
            cout << "The element is:";
            Display(L);
        }
        else if (operate_code == "10")
        {
            //后三个操作未初始化，向表内传入数值
            SqList La, Lb;
            Union(La, Lb);
        }
        else if (operate_code == "11")
        {
            SqList La, Lb;
            JiaoJi(La, Lb);
        }
        else if (operate_code == "12")
        {
            SqList La, Lb;
            Delete(La, Lb);
        }
        else if (operate_code == "0")
        {
            break;
        }
        else
        {
            cout << "\n操作码错误！！！" << endl;
            show_help();
        }
    }
    //调用销毁线性表函数，如Destroy_List(L);
    DestroyList(L);
    return 0;
}
