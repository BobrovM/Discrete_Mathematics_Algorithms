//Бобров Михаил Алексеевич БПИ-20-2

#include <iostream>
#include <string>

using namespace std;

int DoubleToDecimal(int Input)
{
    int Result = 0, Pow = 1;

    while (Input != 0)
    {
        Result += Input % 10 * Pow;
        Input /= 10;
        Pow *= 2;
    }

    return Result;
}

int DecimalToDouble(int Input)
{
    int Result = 0, Pow = 1;

    while (Input != 0)
    {
        Result += Input % 2 * Pow;
        Input /= 2;
        Pow *= 10;
    }

    return Result;
}

int ProcessInput(int Input)
{
    int NumberInput;

    switch (Input)
    {
    case 1:
        cout << "\nВведите число в двоичном формате:\n";
        scanf_s("%d", &NumberInput);
        return DoubleToDecimal(NumberInput);

    case 2:
        cout << "\nВведите число в восьмиричном формате:\n";
        scanf_s("%o", &NumberInput);
        return NumberInput;
    
    case 3:
        cout << "\nВведите число в десятичном формате:\n";
        scanf_s("%d", &NumberInput);
        return NumberInput;

    case 4:
        cout << "\nВведите число в шестнадцатиричном формате:\n";
        scanf_s("%x", &NumberInput);
        return NumberInput;
    }
}

int ProcessCalc(int FNum, int SNum, int OperChoice)
{
    int Result = 0;

    switch (OperChoice)
    {
        case 1:
            Result = FNum + SNum;
            break;
        case 2:
            if (FNum < SNum)
            {
                int Temp = SNum;
                SNum = FNum;
                FNum = Temp;
            }
            Result = FNum - SNum;
            break;
        case 3:
            Result = FNum * SNum;
            break;
        case 4:
            if (FNum < SNum)
            {
                int Temp = SNum;
                SNum = FNum;
                FNum = Temp;
            }
            Result = FNum / SNum;
            break;
    }

    return Result;
}

void PrintResult(int Result, int Choice)
{
    switch (Choice)
    {
    case 1:
        Result = DecimalToDouble(Result);
        printf_s("%d", Result);
        break;
    case 2:
        printf_s("%o", Result);
        break;
    case 3:
        printf_s("%d", Result);
        break;
    case 4:
        printf_s("%x", Result);
        break;
    }

    cout << " - результат вычислений!\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");

    while (true)
    {
        int ChoiceInput = 0, FirstNum = 0, SecondNum = 0;

        cout << "\nВыберите систему счисления ПЕРВОГО числа.\nВведите 1 для ввода двоичного числа.";
        cout << "\nВведите 2 для ввода восьмиричного числа\nВведите 3 для ввода десятичного числа.\nВведите 4 для ввода шестнадцатиричного числа.\n";
        cout << "Или введите любое значение для выхода из программы.\n";

        cin >> ChoiceInput;

        if (ChoiceInput == 0)
        {
            break;
        }

        FirstNum = ProcessInput(ChoiceInput);

        cout << "\nВыберите систему счисления ВТОРОГО числа.\nВведите 1 для ввода двоичного числа.";
        cout << "\nВведите 2 для ввода восьмиричного числа\nВведите 3 для ввода десятичного числа.\nВведите 4 для ввода шестнадцатиричного числа.\n";
        cout << "Или введите любое значение для выхода из программы.\n";

        cin >> ChoiceInput;

        if (ChoiceInput == 0)
        {
            break;
        }

        SecondNum = ProcessInput(ChoiceInput);

        cout << "Выберите операцию с данными числами.\n Введите:\n1 для сложения;";
        cout << "\n2 для вычитания;\n3 для умножения; \n4 для деления.\n";

        cin >> ChoiceInput;

        int Result = ProcessCalc(FirstNum, SecondNum, ChoiceInput);

        cout << "\nВыберите формат вывода числа.\n Введите:\n1 для двочиного;";
        cout << "\n2 для восьмиричного;\n3 для десятичного; \n4 для шестнадцатиричного.\n";

        cin >> ChoiceInput;

        PrintResult(Result, ChoiceInput);
    }
}