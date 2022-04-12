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
    int Leng = Vec.size();

    if (Vec.size() == Place)
    {
        for (int INewNodeex = Leng - 1; INewNodeex >= Place - 1; INewNodeex--)
        {
            Vec[INewNodeex + 1] = Vec[INewNodeex];
        }
    }

    Vec[Place - 1] = Input;

    return Vec;
}

vector<int> DelValueSmezh(vector<int> Vec)
{
    int Place;
    cout << "\nВведите номер элемента на исключение из списка:\n";
    cin >> Place;


    Vec.push_back(0);
    int Leng = Vec.size();

    for (int INewNodeex = Place + 1; INewNodeex <= Leng - 1; INewNodeex++)
    {
        Vec[INewNodeex] = Vec[INewNodeex - 1];
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

template <typename T>
class SvyazContainer {
public:
    SvyazContainer() {
        m_start = m_end = nullptr;
        m_size = 0;
    }
    ~SvyazContainer() { Clear(); }
    void Push_Front(const T& data) {
        if (m_start) {
            Node* new_node = new Node();
            new_node->data = data;
            new_node->next = m_start;
            m_start->prev = new_node;
            m_start = new_node;
        }
        else {
            Initialize(data);
        }
        m_size++;
    }
    void Pop_Front() {
        if (!m_start) return;
        if (m_start->next) {
            Node* next = m_start->next;
            next->prev = nullptr;
            delete m_start;
            m_start = next;
        }
        else {
            delete m_start;
            m_start = m_end = nullptr;
        }
        m_size--;
    }
    void Push_Back(const T& data) {
        if (m_end) {
            Node* new_node = new Node();
            new_node->data = data;
            new_node->prev = m_end;
            m_end->next = new_node;
            m_end = new_node;
        }
        else {
            Initialize(data);
        }
        m_size++;
    }
    void Pop_Back() {
        if (!m_end) return;
        if (m_end->prev) {
            Node* prev = m_end->prev;
            prev->next = nullptr;
            delete m_end;
            m_end = prev;
        }
        else {
            delete m_end;
            m_start = m_end = nullptr;
        }
        m_size--;
    }
    void Sort(function<bool(const T&, const T&)> cmp) {
        if (!m_start) return;
        Node* tmp = m_start;
        while (tmp) {
            Node* tmp_next = tmp->next;
            while (tmp_next) {
                if (cmp(tmp->data, tmp_next->data))
                    swap(tmp->data, tmp_next->data);
                tmp_next = tmp_next->next;
            }
            tmp = tmp->next;
        }
    }
    void Remove_One(function<bool(const T&)> cnd) {
        Node* tmp = m_start;
        while (tmp) {
            if (cnd(tmp->data)) {
                Remove_Node(tmp);
                return;
            }
            tmp = tmp->next;
        }
    }
    void Remove_All(function<bool(const T&)> cnd) {
        Node* tmp = m_start;
        while (tmp) {
            if (cnd(tmp->data)) {
                Node* bck = nullptr;
                if (tmp->prev)
                    bck = tmp->prev;
                else if (tmp->next)
                    bck = tmp->next;
                Remove_Node(tmp);
                if (!bck) return;
                tmp = bck;
            }
            else {
                tmp = tmp->next;
            }
        }
    }
    void Clear() {
        if (!m_start) return;
        if (m_start == m_end) {
            delete m_start;
        }
        else {
            Node* tmp = m_start;
            while (tmp != m_end) {
                Node* next = tmp->next;
                delete tmp;
                tmp = next;
            }
        }
        m_size = 0;
        m_start = m_end = nullptr;
    }
    void For_Each(function<void(T&)> fun) {
        Node* tmp = m_start;
        while (tmp) {
            fun(tmp->data);
            tmp = tmp->next;
        }
    }
    inline size_t Size() const noexcept { return m_size; }
    SvyazContainer<T>& operator=(SvyazContainer<T>&& other) noexcept {
        Clear();
        Node* tmp = other.m_start;
        while (tmp) {
            Push_Back(tmp->data);
            tmp = tmp->next;
        }
        other.Clear();
        return *this;
    }
private:
    struct Node {
        Node() {
            next = nullptr;
            prev = nullptr;
        }
        ~Node() = default;
        T data;
        Node* next;
        Node* prev;
    };
    void Initialize(const T& data) {
        m_start = new Node();
        m_start->data = data;
        m_end = m_start;
    }
    void Remove_Node(Node* node) {
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
            InputValueSmezh(Vec);
            break;

        case 2:
            DelValueSmezh(Vec);
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