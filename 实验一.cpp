#include <iostream>

using namespace std;
//.����洢��ʾ
typedef int ElemType;               //����ElemType����Ϊint
# define MAXSIZE 100  // ˳������󳤶�
int i, j;//����ȫ�ֱ���
typedef struct {              //�����治���ã���ʡ�Խṹ��
    ElemType* elem;         //�洢�ռ��ַ
    int length;      //��ǰ������ָԪ�ظ�����
}SqList;
typedef int ElemType; //���Ϊʲô���¶��壿

//.�����������1 ��ʼ������
ElemType InitList(SqList& L)
{ //����һ���յ����Ա�L��
    L.elem = new ElemType[MAXSIZE];
    L.length = 0;  // �ձ���Ϊ0
    return 1;
}

//.�����������2 ��������
void DestroyList(SqList& L)
{
    if (L.elem) delete[] L.elem;    //�ͷŴ洢�ռ�
    L.length = 0;
    L.elem = NULL;
}

//1 ���� ������Ա�
void ClearList(SqList& L)
{
    L.length = 0;                //�����Ա�ĳ�����Ϊ0
}

//2 ���� �ж����Ա��Ƿ�Ϊ��
bool ListEmpty(SqList L)
{
    if (L.length == 0)
        return true;
    else
        return false;
}

//3.�����������3 �����鳤��
int GetLength(SqList L)
{
    return L.length;
}

//4 ���� ȡ���Ա�ָ��λ�õ�ֵ
ElemType GetElem(SqList L, int i, ElemType& e)
{
    //�ж�iֵ�Ƿ����������������ERROR
    if (i<1 || i>L.length) return -1;
    e = L.elem[i - 1];   //��i-1����Ԫ�洢��i������
    return 1;
}

//5 ���� ��ǰ��
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

//6 ����
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

//7 ���� ��ָ��λ�ò���ֵ
ElemType ListInsert(SqList& L, int i, ElemType e) {
    if (i<1 || i>L.length + 1)  return -1;   //iֵ���Ϸ�
    if (L.length == MAXSIZE)  return -1;
    //��ǰ�洢�ռ�����
    for (j = L.length - 1; j >= i - 1; j--)
        L.elem[j + 1] = L.elem[j];   //����λ�ü�֮���Ԫ�غ���
    L.elem[i - 1] = e;                     //����Ԫ��e�����i��λ��
    ++L.length;	//����1
    return 1;
}

//8 ���� ɾ��ָ��λ��Ԫ��
ElemType ListDelete(SqList& L, int i, ElemType& e) {
    if ((i < 1) || (i > L.length)) return -1;	 //iֵ���Ϸ�
    e = L.elem[i - 1];
    for (j = i; j <= L.length - 1; j++)
        L.elem[j - 1] = L.elem[j]; //��ɾ��Ԫ��֮���Ԫ��ǰ��
    --L.length;               	      //����1
    return 1;
}

//9 ���� ��ʾ���Ա�
void Display(SqList L) {
    for (i = 1; i <= L.length; ++i)
        cout << L.elem[i - 1] << " ";
    cout << endl;
}

//10 ������˳���Ĳ���
//�ж�˳������Ƿ��к��ⲿ��ͬ��Ԫ��
ElemType LocateElem(SqList L, ElemType e,int& i) {
    for (i = 0; i <= L.length - 1; ++i) {
        if (e == L.elem[i]) return 1;
        else return 0;
    }
    return 0;
}
//����������
void Union(SqList& La, SqList Lb){
    ElemType e;
    int j;
    for (i = 1; i <= Lb.length; i++) {
        GetElem(Lb, i, e); // ȡLb�е�i������Ԫ�ظ���e
        if (!LocateElem(La, e,j))
            ListInsert(La, ++La.length, e);
        // La�в����ں� e ��ͬ������Ԫ�أ������֮
    }
}

//11 ������˳���Ľ���
void JiaoJi(SqList& La, SqList Lb) {
    SqList Lc;
    ElemType e;
    int j;
    for (i = 1; i <= Lb.length; i++) {
        GetElem(Lb, i, e); // ȡLb�е�i������Ԫ�ظ���e
        if (LocateElem(La, e,j))
            ListInsert(Lc, ++Lc.length, e);
        // La�д��ں� e ��ͬ������Ԫ�أ�����Lc��
    }
}

//12 ������˳���Ĳ�
void Delete(SqList& La, SqList Lb) {
    ElemType e;
    int j;
    for (i = 1; i <= Lb.length; i++) {
        GetElem(Lb, i, e); // ȡLb�е�i������Ԫ�ظ���e
        if (LocateElem(La, e,j))
            ListDelete(La, j, e);
        // La�д��ں� e ��ͬ������Ԫ�أ���ɾ��֮
    }
}

// ��ʾ���
void show_help()
{
    cout << "******* Data Structure ******" << endl;
    cout << "1----������Ա�" << endl;
    cout << "2----�ж����Ա��Ƿ�Ϊ��" << endl;
    cout << "3----�����Ա���" << endl;
    cout << "4----��ȡ���Ա�ָ��λ��Ԫ��" << endl;
    cout << "5----��ǰ��" << endl;
    cout << "6----����" << endl;
    cout << "7----�����Ա�ָ��λ�ò���Ԫ��" << endl;
    cout << "8----ɾ�����Ա�ָ��λ��Ԫ��" << endl;
    cout << "9----��ʽ���Ա�" << endl;
    cout << "10---������˳���Ĳ���" << endl;
    cout << "11---������˳���Ľ���" << endl;
    cout << "12---������˳���Ĳ�" << endl;
    cout << "     �˳�������0" << endl;
}


int main()
{
    ElemType e;
    string operate_code;
    show_help();
    //�������Ա��������SqList L;
    SqList L;
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
            if (ListEmpty(L)) cout << "The list is empty." << endl;
            else cout << "The list is not empty." << endl;
        }
        else if (operate_code == "3")
        {
            cout << "the length of list is:" << GetLength(L) << endl;
        }
        else if (operate_code == "4")
        {
            cout << "��Ҫ��ȡԪ�ص�λ�ã�";
            cin >> i;
            if (GetElem(L, i, e) == -1) cout << "������" << endl;
            else cout << "����Ԫ��Ϊ��" << e << endl;
        }
        else if (operate_code == "5")
        {
            cout << "���ĸ�Ԫ�ص�ǰ��������֤��Ԫ�ش��ڣ���";
            cin >> e;
            int a=0;
            if (!PriorElem(L, e, a)) cout << "������Ԫ��" << endl;
            else cout << "��Ԫ��Ϊ��" << a << endl;
        }
        else if (operate_code == "6")
        {
            int a=0;
            cout << "���ĸ�Ԫ�صĺ�̣�����֤��Ԫ�ش��ڣ���";
            cin >> e;
            if (!NextElem(L, e, a)) cout << "������Ԫ��" << endl;
            else cout << "��Ԫ��Ϊ��" << a << endl;
        }
        else if (operate_code == "7")
        {
            cout << "������Ҫ�����λ�ú�ֵ��";
            cin >> i >> e;
            ListInsert(L, i, e);

        }
        else if (operate_code == "8")
        {
            cout << "������Ҫɾ����λ�ú�ֵ��";
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
            //����������δ��ʼ��������ڴ�����ֵ
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
            cout << "\n��������󣡣���" << endl;
            show_help();
        }
    }
    //�����������Ա�������Destroy_List(L);
    DestroyList(L);
    return 0;
}
