#include <iostream>

using namespace std;

typedef int ElemType;               //����ElemType����Ϊint
# define MAXSIZE 100  // ˳������󳤶�
int i, j;//����ȫ�ֱ���

//�������ѭ������Ľṹ��
typedef struct LNode
{
    ElemType   data;       //������
    struct LNode* next;   //ָ����
} LNode, * LinkList;
//˫������Ľṹ��
typedef struct DuLNode
{
    ElemType data;
    struct DuLNode* prior;
    struct DuLNode* next;
} DuLNode, * DuLinkList;

// ��ʼ�����Ա�
ElemType InitList(LinkList& L)
{
    L = new LNode;
    L->next = NULL;
    return 1;
}

// ���ٵ������ѭ������
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
//����˫������
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

//1 ������Ա�
ElemType ClearList(LinkList L)
{// ��L����Ϊ�ձ�
    LinkList p, q;
    p = L->next;   //pָ���һ�����
    while (p)       //û����β
    {
        q = p->next; delete p; p = q;
    }
    L->next = NULL;   //ͷ���ָ����Ϊ��
    return 1;
}


//2 �����Ա�ĳ���
ElemType  ListLength(LinkList L)
{
    //����L������Ԫ�ظ���
    LinkList p = L->next; //pָ���һ�����
    int count = 0;
    while (p)  //����������,ͳ�ƽ����
    {
        ++count;
        p = p->next;
    }
    return count;
}
//˫������ĳ���
ElemType  DuListLength(DuLinkList L)
{
    //����L������Ԫ�ظ���
    DuLinkList p = L->next; //pָ���һ�����
    int count = 0;
    while (p)  //����������,ͳ�ƽ����
    {
        ++count;
        p = p->next;
    }
    return count;
}

//3 �ж����Ա�L�Ƿ�Ϊ��
ElemType ListEmpty(LinkList L)
{
    LinkList p = L->next;
    if (p)
        return 1;//��Ϊ�շ���1
    else
        return 0;//Ϊ�շ���0

}

//4 ��ȡ���Ա�L�е�ĳ������Ԫ������
ElemType GetElem(LinkList L, int i, ElemType& e)
{
    j = 1;
    LinkList p = L->next;
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i) return 0;//���ݲ�����
    e = p->data;
    return 1;
}

//5 ����ֵΪe������Ԫ��
LNode* LocateElem(LinkList L, ElemType e)
{
    LinkList p = L->next;
    while (p && p->data != e)
        p = p->next;
    return p; 	//����L��ֵΪe������Ԫ�ص�λ�ã�����ʧ�ܷ���NULL
}

//6 �����Ա�L�в���һ������Ԫ��
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

//7 ɾ�����Ա�L�е�i������e
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

//8 ��ʾ���Ա�
void Display(LinkList L)
{
    LinkList p = L->next;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

//9 ǰ�巨����������
void CreateList_H(LinkList& L, int n)
{
    LinkList p;
    L = new LNode;
    L->next = NULL; //�Ƚ���һ����ͷ���ĵ�����
    cout << "��������" << n << "��Ԫ�ص�ֵ";
    for (i = n; i > 0; --i)
    {
        p = new LNode;//�����½��
        cin >> p->data;
        p->next = L->next;
        L->next = p; //���뵽��ͷ
    }
}

//10 ���Ա�Ĺ鲢
void   MergeList_L(LinkList& La, LinkList& Lb, LinkList& Lc)
{
    //��ֵ����ĵ�����LA,LB���鲢ΪLC��Ҳ��ֵ����
    LinkList pa = La->next;
    LinkList pb = Lb->next;
    LinkList pc;
    Lc = pc;
    pc = La;  //��ʼ��
    while (pa && pb) //��pa ��pb��㰴��С���β���C��
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
    pc->next = pa ? pa : pb;     //����ʣ�ಿ��
    delete Lb;                //�ͷ�Lb��ͷ���
}

//11 �������ֱ�Ӻ��
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

//12 ˫������Ĳ���
ElemType DuListInsert(DuLinkList L, int i, ElemType e)
{
    // �ڴ�ͷ����˫��ѭ������ L �е�i-1��λ��֮�����Ԫ��e.
    DuLinkList p = L, s;
    j = 0;
    while (p->next != L && j < i - 1)
    {
        p = p->next;       //��L��ȷ����i��Ԫ�ص�λ��ָ��p
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


//13 ˫�������ɾ��
ElemType DuListDelete(DuLinkList L, int i, ElemType& e)
{
    //ɾ����ͷ����˫��ѭ������L�ĵ�i��Ԫ�ء�
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

//14 ˫�������ֱ��ǰ��
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

//15 ˫�������ֱ�Ӻ��
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

//16 ѭ������Ĵ���,ǰ�巨
ElemType Create_CList(LNode* L, int n)
{
    LinkList p;
    L = new LNode;
    L->next = L; //�Ƚ���һ����ͷ���ĵ�����
    cout << "��������" << n << "��Ԫ�ص�ֵ";
    for (i = n; i > 0; --i)
    {
        p = new LNode;//�����½��
        cin >> p->data;
        p->next = L->next;
        L->next = p; //���뵽��ͷ
    }

}

// ��ʾ���
void show_help()
{
    cout << "******* Data Structure ******" << endl;


    cout << "1.  ������Ա�L" << endl;
    cout << "2.  �����Ա�L�ĳ���" << endl;
    cout << "3.  �ж����Ա�L�Ƿ�Ϊ�� " << endl;
    cout << "4.  ��ȡ���Ա�L�е�ĳ������Ԫ������ " << endl;
    cout << "5.  ����ֵΪe������Ԫ��    " << endl;
    cout << "6.  �����Ա�L�в���һ������Ԫ��  " << endl;
    cout << "7.  ɾ�����Ա�L�е�i������Ԫ��" << endl;
    cout << "8.  ���Ա����ʾ" << endl;
    cout << "9.  ͷ�巨��������" << endl;
    cout << "10. ���Ա�Ĺ鲢" << endl;
    cout << "11. ������ĳ��Ԫ�ص�ֱ�Ӻ��" << endl;
    cout << "12. ˫������Ĳ���" << endl;
    cout << "13. ˫�������ɾ��" << endl;
    cout << "14. ˫�������ֱ��ǰ��" << endl;
    cout << "15. ˫�������ֱ�Ӻ��" << endl;
    cout << "16. ѭ������Ĵ���(ǰ�巨)" << endl;
    cout << "     �˳�������0" << endl;
}
int main()
{
    ElemType e;
    string operate_code;
    show_help();
    //�������Ա��������SqList L;
    LinkList L;
    //���ó�ʼ�����Ա�������Init_List(L);
    InitList(L);
    while (1)
    {
        cout << "������������룺";
        cin >> operate_code;
        if (operate_code == "1")
        {
            //���ò�������1
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
            cout << "��������Ҫ��ȡֵ��λ�ã�";
            cin >> i;
            if (GetElem(L, i, e))
                cout << "ֵΪ��" << e << endl;
            else cout << "ֵ������" << endl;
        }
        else if (operate_code == "5")
        {
            cout << "��Ҫ������Ԫ�أ�";
            cin >> e;
            LocateElem(L, e);
            if (LocateElem(L, e))
            {
                LinkList p;
                e = p->data;
                cout << "ֵ����";
            }
            else cout << "ֵ������";
        }
        else if (operate_code == "6")
        {
            cout << "��Ҫ�����λ�ú�ֵ��";
            cin >> i >> e;
            if (ListInsert(L, i, e)) cout << "����ɹ�" << endl;
            else cout << "����ʧ��" << endl;
        }
        else if (operate_code == "7")
        {
            cout << "��Ҫɾ����λ�ú�ֵ";
            cin >> i >> e;
            if (ListDelete(L, i, e))
                cout << "ɾ���ɹ�";
            else
                cout << "ɾ��ʧ��";
        }
        else if (operate_code == "8")
        {
            Display(L);
            cout << endl;
        }
        else if (operate_code == "9")
        {
            cout << "������Ҫ�����Ľ������(������ͷ���)��";
            int n;
            cin >> n;
            CreateList_H(L, n);
        }
        else if (operate_code == "10")
        {
            LinkList La, Lb, Lc;
            cout << "�ֱ�������Ҫ������һ���͵ڶ�������Ľ������(������ͷ���)��";
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
            cout << "��������Ԫ�أ�" << endl;
            cin >> e;
            int next_e;
            if (NextElem(L, e, next_e)) cout << "ֱ�Ӻ��Ϊ��" << next_e << endl;
            else cout << "��ֱ�Ӻ��" << endl;
        }
        else if (operate_code == "12")
        {
            DuLinkList L;
            cout << "��Ҫ�����λ�ú�ֵ��";
            cin >> i >> e;
            if (DuListInsert(L, i, e)) cout << "����ɹ�" << endl;
            else cout << "����ʧ��" << endl;
        }
        else if (operate_code == "13")
        {
            DuLinkList L;
            cout << "��Ҫɾ����λ�ú�ֵ";
            cin >> i >> e;
            if (DuListDelete(L, i, e))
                cout << "ɾ���ɹ�";
            else
                cout << "ɾ��ʧ��";
        }
        else if (operate_code == "14")
        {
            DuLinkList L;
            cout << "���ĸ�Ԫ�ص�ǰ��������֤��Ԫ�ش��ڣ���";
            cin >> e;
            int a = 0;
            if (!Prior_DU_Elem(L, e, a)) cout << "������Ԫ��" << endl;
            else cout << "��Ԫ��Ϊ��" << a << endl;
        }
        else if (operate_code == "15")
        {
            int a = 0;
            cout << "���ĸ�Ԫ�صĺ�̣�����֤��Ԫ�ش��ڣ���";
            cin >> e;
            if (!NextElem(L, e, a)) cout << "������Ԫ��" << endl;
            else cout << "��Ԫ��Ϊ��" << a << endl;
        }
        else if (operate_code == "16")
        {
            cout << "������Ҫ����ѭ������Ľ��������";
            int n;
            cin >> n;
            Create_CList(L, n);
        }
        else if (operate_code == "0")
        {
            break;
        }
    }

    //�����������Ա�������Destroy_List(L);
    DestroyList(L);//���ٵ������˫������
    Destory_DuList(L);//����˫������
    return 0;
}
