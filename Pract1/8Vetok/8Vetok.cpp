#include <iostream>
#include <vector>

using namespace std;

int Fact(int Input)
{
    int Result = 1;
    for (int Index = 2; Index <= Input; Index++)
    {
        Result *= Index;
    }

    return Result;
}

int FactSpec(int InputCh, int InputZn)
{
    int Result = 1;
    for (int Index = InputZn + 1; Index <= InputCh; Index++)
    {
        Result *= Index;
    }

    return Result;
}

int RuleSum()
{
    //vvod kolva
    int Count = 0;
    cout << "\nВведите количество множеств для суммы.\n";
    cin >> Count;
    int SumElements = 0;

    for (int Index = 0; Index < Count; Index++)
    {
        //vivod vvedite elem nomer
        int Temp;
        cout << "\nВведите количество элементов множества номер " << Index + 1 << ".\n";
        cin >> Temp;
        SumElements += Temp;
    }

    return SumElements;
}

int RuleMultiply()
{
    //vvod kolva
    int Count = 0;
    cout << "\nВведите количество множеств.\n";
    cin >> Count;
    int Solutions = 1;

    for (int Index = 0; Index < Count; Index++)
    {
        //vivod vvedite elem nomer
        int Temp;
        cout << "\nВведите количество элементов множества номер "<< Index + 1 << ".\n";
        cin >> Temp;
        Solutions *= Temp;
    }

    return Solutions;
}

int RazmeshPovt()
{
    //vvod kolva elem 
    int Count = 0;
    cout << "\nВведите количество элементов множества.\n";
    cin >> Count;
    //vvod sposobov
    int Poss = 0;
    cout << "\nВведите количество способов для этого множества.\n";
    cin >> Poss;

    int Result = Count;

    for (int Index = 1; Index < Poss; Index++)
    {
        Result *= Count;
    }

    return Result;
}

int RazmeshBezPovt()
{
    //vvod kolva elem
    int Count = 0;
    cout << "\nВведите количество элементов множества.\n";
    cin >> Count;
    //vvod sposobov
    int Poss = 0;
    cout << "\nВведите количество способов для этого множества.\n";
    cin >> Poss;

    int Result = Fact(Count)/Fact(Count-Poss);

    return Result;
}

int SochetPovt()
{
    //vvod kolva elem
    int Count = 0;
    cout << "\nВведите количество элементов множества.\n";
    cin >> Count;
    //vvod sposobov
    int Poss = 0;
    cout << "\nВведите количество способов для этого множества.\n";
    cin >> Poss;

    int Result = FactSpec(Count + Poss - 1, Poss);
    //int debugdelit = Fact(Count - 1) * Fact(Poss);
    //Result /= Fact(Count - 1) * Fact(Poss);
    //Result /= debugdelit;
    Result /= Fact(Count - 1);
    return Result;
}

int SochetBezPovt()
{
    //vvod kolva elem
    int Count = 0;
    cout << "\nВведите количество элементов множества.\n";
    cin >> Count;
    //vvod sposobov
    int Poss = 0;
    cout << "\nВведите количество способов для этого множества.\n";
    cin >> Poss;

    int Result = Fact(Count) / (Fact(Count - Poss) * Fact(Poss));

    return Result;
}

int PerestanovPovt()
{
    //vvod kolva elem
    int Count = 0;
    cout << "\nВведите количество элементов множества.\n";
    cin >> Count;

    int Chisl = 0;
    int Znamen = 1;

    for (int Index = 0; Index < Count; Index++)
    {
        //vvod kolva povtor elem
        int TempPovt = 0;
        cout << "\nВведите количество повторов элемента номер " << Index + 1 << ".\n";
        cin >> TempPovt;
        Chisl += TempPovt;
        Znamen *= Fact(TempPovt);
    }

    int Result = Fact(Chisl) / Znamen;

    return Result;
}

int PerestanovBezPovt()
{
    //vvod kolva elem
    int Count = 0;
    cout << "\nВведите количество элементов множества.\n";
    cin >> Count;

    return Fact(Count);
}

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "\nДобро пожаловать в калькулятор некоторых комбинаторных схем!\n\n";

    bool Bool = true;

    while (Bool)
    {
        cout << "\nВыберите операцию (введите номер операции):\n";
        cout << "1) правило суммы;\n";
        cout << "2) правило прямого произведения;\n";
        cout << "3) размещение с повторением;\n";
        cout << "4) размещение без повторения;\n";
        cout << "5) сочетание с повторением;\n";
        cout << "6) сочетание без повторения;\n";
        cout << "7) перестановка с повторением;\n";
        cout << "8) перестановка без повторения;\n";
        cout << "0) выход из программы.\n";

        int Choice = 0;
        int Result;
        cin >> Choice;

        switch (Choice)
        {
        case 1:
            Result = RuleSum();
            cout << "\nРезультат суммы = " << Result << ".\n";
            break;

        case 2:
            Result = RuleMultiply();
            cout << "\nРезультат прямого произведения = " << Result << ".\n";
            break;

        case 3:
            Result = RazmeshPovt();
            cout << "\nРезультат размещения с повторением = " << Result << ".\n";
            break;

        case 4:
            Result = RazmeshBezPovt();
            cout << "\nРезультат размещения без повторения = " << Result << ".\n";
            break;

        case 5:
            Result = SochetPovt();
            cout << "\nРезультат сочетания с повторением = " << Result << ".\n";
            break;

        case 6:
            Result = SochetBezPovt();
            cout << "\nРезультат сочетание без повторения = " << Result << ".\n";
            break;

        case 7:
            Result = PerestanovPovt();
            cout << "\nРезультат перестановка с повторением = " << Result << ".\n";
            break;

        case 8:
            Result = PerestanovBezPovt();
            cout << "\nРезультат перестановка без повторения = " << Result << ".\n";
            break;

        case 0:
            Bool = !Bool;
            break;

        default:
            break;
        }
    }
}

//https://math1.ru/education/raznoe/combinatorics.html#ch5