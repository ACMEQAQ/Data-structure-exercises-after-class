#include <iostream>

using namespace std;

typedef int ElemType;               //定义ElemType类型为int
# define MAXSIZE 100  // 顺序表的最大长度
int i, j;//定义全局变量

//单链表和循环链表的结构体
typedef struct LNode
{
    ElemType   data;       //数据域
    struct LNode* next;   //指针域
} LNode, * LinkList;
//双向链表的结构体
typedef struct DuLNode
{
    ElemType data;
    struct DuLNode* prior;
    struct DuLNode* next;
} DuLNode, * DuLinkList;

// 初始化线性表
ElemType InitList(LinkList& L)
{
    L = new LNode;
    L->next = NULL;
    return 1;
}

// 销毁单链表和循环链表
ElemType DestroyList(LinkList& L)
{
    LinkList p;
    while (L)
    {
        p = L;
        L = L->next;
        delete p;
    }
    return 1;
}
//销毁双向链表
ElemType Destory_DuList(DuLinkList& L)
{
    DuLinkList p;
    while (L)
    {
        p = L;
        L = L->next;
        delete p;
    }
}

//1 清空线性表
ElemType ClearList(LinkList L)
{// 将L重置为空表
    LinkList p, q;
    p = L->next;   //p指向第一个结点
    while (p)       //没到表尾
    {
        q = p->next; delete p; p = q;
    }
    L->next = NULL;   //头结点指针域为空
    return 1;
}


//2 求线性表的长度
ElemType  ListLength(LinkList L)
{
    //返回L中数据元素个数
    LinkList p = L->next; //p指向第一个结点
    int count = 0;
    while (p)  //遍历单链表,统计结点数
    {
        ++count;
        p = p->next;
    }
    return count;
}
//双向链表的长度
ElemType  DuListLength(DuLinkList L)
{
    //返回L中数据元素个数
    DuLinkList p = L->next; //p指向第一个结点
    int count = 0;
    while (p)  //遍历单链表,统计结点数
    {
        ++count;
        p = p->next;
    }
    return count;
}

//3 判断线性表L是否为空
ElemType ListEmpty(LinkList L)
{
    LinkList p = L->next;
    if (p)
        return 1;//不为空返回1
    else
        return 0;//为空返回0

}

//4 获取线性表L中的某个数据元素内容
ElemType GetElem(LinkList L, int i, ElemType& e)
{
    j = 1;
    LinkList p = L->next;
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i) return 0;//数据不存在
    e = p->data;
    return 1;
}

//5 检索值为e的数据元素
LNode* LocateElem(LinkList L, ElemType e)
{
    LinkList p = L->next;
    while (p && p->data != e)
        p = p->next;
    return p; 	//返回L中值为e的数据元素的位置，查找失败返回NULL
}

//6 在线性表L中插入一个数据元素
ElemType ListInsert(LinkList L, int i, ElemType e)
{
    LinkList p = L, s;
    j = 1;
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i) return 0;
    s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return 1;
}

//7 删除线性表L中第i个数据e
ElemType ListDelete(LinkList L, int i, ElemType& e)
{
    LinkList p = L, r;
    j = 1;
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i) return 0;
    r = p->next;
    p->next = r->next;
    e = r->data;
    delete r;
    return 1;
}

//8 显示线性表
void Display(LinkList L)
{
    LinkList p = L->next;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

//9 前插法创建单链表
void CreateList_H(LinkList& L, int n)
{
    LinkList p;
    L = new LNode;
    L->next = NULL; //先建立一个带头结点的单链表
    cout << "依次输入" << n << "个元素的值";
    for (i = n; i > 0; --i)
    {
        p = new LNode;//生成新结点
        cin >> p->data;
        p->next = L->next;
        L->next = p; //插入到表头
    }
}

//10 线性表的归并
void   MergeList_L(LinkList& La, LinkList& Lb, LinkList& Lc)
{
    //按值排序的单链表LA,LB，归并为LC后也按值排序
    LinkList pa = La->next;
    LinkList pb = Lb->next;
    LinkList pc;
    Lc = pc;
    pc = La;  //初始化
    while (pa && pb) //将pa 、pb结点按大小依次插入C中
    {
        if (pa->data <= pb->data)
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;     //插入剩余部分
    delete Lb;                //释放Lb的头结点
}

//11 求单链表的直接后继
ElemType NextElem(LinkList L, ElemType e, int& next_e)
{
    LinkList p, q;
    p = L->next;
    for (i = 0; i < ListLength(L); p = p->next)
    {
        if (e == p->data)
        {
            if (i == ListLength(L) - 1) return 0;
            else
            {
                q = p->next;
                next_e = q->data;;
                return 1;
            }
        }
    }
    return 0;
}

//12 双向链表的插入
ElemType DuListInsert(DuLinkList L, int i, ElemType e)
{
    // 在带头结点的双向循环链表 L 中第i-1个位置之后插入元素e.
    DuLinkList p = L, s;
    j = 0;
    while (p->next != L && j < i - 1)
    {
        p = p->next;       //在L中确定第i个元素的位置指针p
        j++;
    }
    if ((p->next == L && i - 1 != j) || j > i - 1)   return 0;
    s = new DuLNode;
    s->data = e;
    s->prior = p;
    s->next = p->next;
    p->next->prior = s;
    p->next = s;
    return 1;
}


//13 双向链表的删除
ElemType DuListDelete(DuLinkList L, int i, ElemType& e)
{
    //删除带头结点的双向循环链表L的第i个元素。
    DuLinkList p = L->next;
    j = 1;
    while (p != L && j < i)
    {
        p = p->next;
        j++;
    }
    if (p == L || j > i)	return 0;
    e = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    delete p;
    return 1;
}

//14 双向链表的直接前驱
ElemType Prior_DU_Elem(DuLinkList L, ElemType e, int& prior_e)
{
    DuLinkList p, q;
    p = L->next;
    for (i = 0; i < DuListLength(L); p = p->next)
    {
        if (e == p->data)
        {
            if (i == DuListLength(L) - 1) return 0;
            else
            {
                q = p->prior;
                prior_e = q->data;;
                return 1;
            }
        }
    }
    return 0;
}

//15 双向链表的直接后继
ElemType Next_DU_Elem(DuLinkList L, ElemType e, int& next_e)
{
    DuLinkList p, q;
    p = L->next;
    for (i = 0; i < DuListLength(L); p = p->next)
    {
        if (e == p->data)
        {
            if (i == DuListLength(L) - 1) return 0;
            else
            {
                q = p->next;
                next_e = q->data;;
                return 1;
            }
        }
    }
    return 0;
}

//16 循环链表的创建,前插法
ElemType Create_CList(LNode* L, int n)
{
    LinkList p;
    L = new LNode;
    L->next = L; //先建立一个带头结点的单链表
    cout << "依次输入" << n << "个元素的值";
    for (i = n; i > 0; --i)
    {
        p = new LNode;//生成新结点
        cin >> p->data;
        p->next = L->next;
        L->next = p; //插入到表头
    }

}

// 提示语句
void show_help()
{
    cout << "******* Data Structure ******" << endl;


    cout << "1.  清空线性表L" << endl;
    cout << "2.  求线性表L的长度" << endl;
    cout << "3.  判断线性表L是否为空 " << endl;
    cout << "4.  获取线性表L中的某个数据元素内容 " << endl;
    cout << "5.  检索值为e的数据元素    " << endl;
    cout << "6.  在线性表L中插入一个数据元素  " << endl;
    cout << "7.  删除线性表L中第i个数据元素" << endl;
    cout << "8.  线性表的显示" << endl;
    cout << "9.  头插法建单链表" << endl;
    cout << "10. 线性表的归并" << endl;
    cout << "11. 求单链表某个元素的直接后继" << endl;
    cout << "12. 双向链表的插入" << endl;
    cout << "13. 双向链表的删除" << endl;
    cout << "14. 双向链表的直接前驱" << endl;
    cout << "15. 双向链表的直接后继" << endl;
    cout << "16. 循环链表的创建(前插法)" << endl;
    cout << "     退出，输入0" << endl;
}
int main()
{
    ElemType e;
    string operate_code;
    show_help();
    //定义线性表变量，如SqList L;
    LinkList L;
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
            cout << "the length of list is:" << ListLength(L) << endl;
        }
        else if (operate_code == "3")
        {
            if (ListEmpty(L)) cout << "The list is not empty." << endl;
            else cout << "The list is empty." << endl;
        }
        else if (operate_code == "4")
        {
            cout << "请输入想要获取值的位置：";
            cin >> i;
            if (GetElem(L, i, e))
                cout << "值为：" << e << endl;
            else cout << "值不存在" << endl;
        }
        else if (operate_code == "5")
        {
            cout << "想要检索的元素：";
            cin >> e;
            LocateElem(L, e);
            if (LocateElem(L, e))
            {
                LinkList p;
                e = p->data;
                cout << "值存在";
            }
            else cout << "值不存在";
        }
        else if (operate_code == "6")
        {
            cout << "想要插入的位置和值：";
            cin >> i >> e;
            if (ListInsert(L, i, e)) cout << "插入成功" << endl;
            else cout << "插入失败" << endl;
        }
        else if (operate_code == "7")
        {
            cout << "想要删除的位置和值";
            cin >> i >> e;
            if (ListDelete(L, i, e))
                cout << "删除成功";
            else
                cout << "删除失败";
        }
        else if (operate_code == "8")
        {
            Display(L);
            cout << endl;
        }
        else if (operate_code == "9")
        {
            cout << "输入想要创建的结点数量(不包括头结点)：";
            int n;
            cin >> n;
            CreateList_H(L, n);
        }
        else if (operate_code == "10")
        {
            LinkList La, Lb, Lc;
            cout << "分别输入想要创建第一个和第二个链表的结点数量(不包括头结点)：";
            int n1, n2;
            cin >> n1 >> n2;
            InitList(La);
            CreateList_H(La, n1);
            InitList(Lb);
            CreateList_H(Lb, n2);
            MergeList_L(La, Lb, Lc);
            DestroyList(La);
            DestroyList(Lb);
        }
        else if (operate_code == "11")
        {
            cout << "输入想求元素；" << endl;
            cin >> e;
            int next_e;
            if (NextElem(L, e, next_e)) cout << "直接后继为：" << next_e << endl;
            else cout << "无直接后继" << endl;
        }
        else if (operate_code == "12")
        {
            DuLinkList L;
            cout << "想要插入的位置和值：";
            cin >> i >> e;
            if (DuListInsert(L, i, e)) cout << "插入成功" << endl;
            else cout << "插入失败" << endl;
        }
        else if (operate_code == "13")
        {
            DuLinkList L;
            cout << "想要删除的位置和值";
            cin >> i >> e;
            if (DuListDelete(L, i, e))
                cout << "删除成功";
            else
                cout << "删除失败";
        }
        else if (operate_code == "14")
        {
            DuLinkList L;
            cout << "求哪个元素的前驱（不保证该元素存在）：";
            cin >> e;
            int a = 0;
            if (!Prior_DU_Elem(L, e, a)) cout << "不存在元素" << endl;
            else cout << "该元素为：" << a << endl;
        }
        else if (operate_code == "15")
        {
            int a = 0;
            cout << "求哪个元素的后继（不保证该元素存在）：";
            cin >> e;
            if (!NextElem(L, e, a)) cout << "不存在元素" << endl;
            else cout << "该元素为：" << a << endl;
        }
        else if (operate_code == "16")
        {
            cout << "输入想要创建循环链表的结点数量：";
            int n;
            cin >> n;
            Create_CList(L, n);
        }
        else if (operate_code == "0")
        {
            break;
        }
    }

    //调用销毁线性表函数，如Destroy_List(L);
    DestroyList(L);//销毁单链表和双向链表
    Destory_DuList(L);//销毁双向链表
    return 0;
}
