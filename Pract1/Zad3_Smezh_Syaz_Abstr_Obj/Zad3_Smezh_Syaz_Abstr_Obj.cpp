#include <iostream>
#include <vector>
#include <string>
#include <functional>

using namespace std;

//Написать программы для смежного и связного представлений абстрактных объектов (последовательностей)

vector<int> InputValueSmezh(vector<int> Vec)
{
    int Input, Place = -1;
    if (Vec.size() != 0)
    {
        cout << "\nВведите номер нового элемента в списке из " << Vec.size() << " элементов:\n";
        cin >> Place;
    }

    cout << "\nВведите значение нового элемента:\n";
    cin >> Input;

    Vec.push_back(0);

    if ((Vec.size() != Place) && (Vec.size() > 1))
    {
        for (int INewNodeex = Vec.size() - 2; INewNodeex >= Place - 1; INewNodeex--)
        {
            Vec[INewNodeex + 1] = Vec[INewNodeex];
        }
    }
    
    if (Vec.size() > 1)
    {
        Vec[Place - 1] = Input;
    }
    else
    {
        Vec[0] = Input;
    }

    return Vec;
}

vector<int> DelValueSmezh(vector<int> Vec)
{
    int Place;
    cout << "\nВведите номер элемента на исключение из списка:\n";
    cin >> Place;

    for (int INewNodeex = Place; INewNodeex <= Vec.size() - 1; INewNodeex++)
    {
        Vec[INewNodeex - 1] = Vec[INewNodeex];
    }

    Vec.pop_back();

    return Vec;
}

void OutputValuesSmezh(vector<int> Vec)
{
    cout << "\nСписок сейчас состоит из данных элементов:\n";
    for(int Value : Vec)
    {
        cout << Value << " ";
    }
    cout << "\n";
}

class SvyazContainer
{
public:
    SvyazContainer() 
    {
        m_start = m_end = nullptr;
        m_size = 0;
    }
    ~SvyazContainer() { Clear(); }
    void Push_Front(int data) 
    {
        if (m_start)
        {
            Node* new_node = new Node();
            new_node->data = data;
            new_node->next = m_start;
            m_start->prev = new_node;
            m_start = new_node;
        }
        else 
        {
            Initialize(data);
        }
        m_size++;
    }
    void Push_Back(int data) 
    {
        if (m_end) 
        {
            Node* new_node = new Node();
            new_node->data = data;
            new_node->prev = m_end;
            m_end->next = new_node;
            m_end = new_node;
        }
        else 
        {
            Initialize(data);
        }
        m_size++;
    }
    void Remove_One(int Index) 
    {
        Index--;
        if ((Index < 0) || (Index >= m_size) || (m_size == 0))
        {
            cout << "Номер элемента не может быть меньше нуля и больше размера списка! Невозможно удаление из пустого списка!";
        }
        else if (Index == 0)
        {
            Node* tmp = m_start;
            cout << endl << tmp->data << endl;
            Remove_Node(tmp);
        }
        else if (Index == m_size - 1)
        {
            Node* tmp = m_end;
            cout << endl << tmp->data << endl;
            Remove_Node(tmp);
        }
        else
        {
            int Jindex = 0;
            Node* tmp = m_start;
            while (Jindex != Index)
            {
                tmp = tmp->next;
                Jindex++;
            }
            cout << endl << tmp->data << endl;
            Remove_Node(tmp);
        }
    }
    void Clear() 
    {
        if (!m_start) return;
        if (m_start == m_end) 
        {
            delete m_start;
        }
        else 
        {
            Node* tmp = m_start;
            while (tmp != m_end) 
            {
                Node* next = tmp->next;
                delete tmp;
                tmp = next;
            }
        }
        m_size = 0;
        m_start = m_end = nullptr;
    }
    inline size_t Size() const noexcept { return m_size; }
    SvyazContainer operator=(SvyazContainer& other) noexcept 
    {
        Clear();
        Node* tmp = other.m_start;
        while (tmp) 
        {
            Push_Back(tmp->data);
            tmp = tmp->next;
        }
        other.Clear();
        return *this;
    }
    void PrintList()
    {
        Node* Current = m_start;
        while (Current)
        {
            cout << Current->data << " ";
            Current = Current->next;
        }
        cout << endl;
    }
private:
    struct Node 
    {
        Node() 
        {
            next = nullptr;
            prev = nullptr;
        }
        ~Node() = default;
        int data;
        Node* next;
        Node* prev;
    };
    void Initialize(const int data) 
    {
        m_start = new Node();
        m_start->data = data;
        m_end = m_start;
    }
    void Remove_Node(Node* node) 
    {
        Node* prev = node->prev;
        Node* next = node->next;
        if (prev != nullptr) prev->next = next;
        if (next != nullptr) next->prev = prev;
        if (node == m_start) m_start = next;
        if (node == m_end) m_end = prev;
        delete node;
        m_size--;
    }
    Node* m_start;
    Node* m_end;
    size_t m_size;
};

void SmezhWhile()
{
    bool ContinuousWhile = true;
    vector<int> Vec;
    cout << "\nСоздан пустой смежный список. \n";
    int Choice = 0;

    while (ContinuousWhile)
    {
        cout << "\nВыберите действие со смежным списком:\n";
        cout << "1)введите <1> для включения нового числа в список;\n";
        cout << "2)введите <2> для исключения числа из списка;\n";
        cout << "3)введите <3> для вывода всего списка;\n";
        cout << "0)введите <0> для выхода в главное меню.\n";
        cin >> Choice;

        switch (Choice)
        {
        case 1:
            Vec = InputValueSmezh(Vec);
            break;

        case 2:
            Vec = DelValueSmezh(Vec);
            break;

        case 3:
            OutputValuesSmezh(Vec);
            break;

        case 0:
            ContinuousWhile = !ContinuousWhile;
            break;

        default:
            break;
        }
    }
}

void SvyazWhile()
{
    bool ContinuousWhile = true;
    SvyazContainer SvyazCont;
    cout << "\nСоздан пустой связанный список. \n";
    int Choice = 0;

    while (ContinuousWhile)
    {
        cout << "\nВыберите действие со смежным списком:\n";
        cout << "1)введите <1> для включения нового числа в начало списка из " << SvyazCont.Size() << " элементов;\n";
        cout << "2)введите <2> для включения нового числа в конец списка из " << SvyazCont.Size() << " элементов;\n";
        cout << "3)введите <3> для исключения числа из списка из " << SvyazCont.Size() << " элементов по номеру;\n";
        cout << "4)введите <4> для вывода всего списка;\n";
        cout << "0)введите <0> для выхода в главное меню.\n";
        cin >> Choice;

        int TmpNum;

        switch (Choice)
        {
        case 1:
            cout << "\nВведите новое число:\n";
            cin >> TmpNum;
            SvyazCont.Push_Front(TmpNum);
            break;

        case 2:
            cout << "\nВведите новое число:\n";
            cin >> TmpNum;
            SvyazCont.Push_Back(TmpNum);
            break;

        case 3:
            cout << "\nВведите номер элемента для удаления:\n";
            cin >> TmpNum;
            SvyazCont.Remove_One(TmpNum);
            break;

        case 4:
            cout << "Вывод всех элементов:";
            SvyazCont.PrintList();
            break;

        case 0:
            ContinuousWhile = !ContinuousWhile;
            break;

        default:
            break;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    bool ContinuousWhile = true;
    int Choice = 0;

    while (ContinuousWhile)
    {
        cout << "\nВыберите действие:\n";
        cout << "1)введите <1> для манипуляций с новым смежным списком;\n";
        cout << "2)введите <2> для манипуляций с новым связанным списком;\n";
        cout << "0)введите <0> для выхода из программы.\n";
        cin >> Choice;

        switch (Choice)
        {
        case 1:
            SmezhWhile();
            break;

        case 2:
            SvyazWhile();
            break;

        case 0:
            ContinuousWhile = !ContinuousWhile;
            break;

        default:
            break;
        }
    }
}