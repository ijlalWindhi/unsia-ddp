#include <iostream>
#include <limits>
#include <array>
using namespace std;

// Struktur untuk menyimpan informasi operasi
struct Operation
{
    string name;
    string symbol;
};

// Array konstanta untuk menyimpan informasi operasi
const array<Operation, 4> operations = {{{"Penjumlahan", "+"},
                                         {"Pengurangan", "-"},
                                         {"Pembagian", "/"},
                                         {"Perkalian", "*"}}};

// Fungsi untuk menampilkan header program
void displayHeader()
{
    cout << "======================" << endl;
    cout << "Kalkulator Sederhana" << endl;
    cout << "======================" << endl;
}

// Fungsi untuk menampilkan menu matematika
void displayMenu()
{
    cout << "Menu Matematika :" << endl;
    for (size_t i = 0; i < operations.size(); i++)
    {
        cout << (i + 1) << ". " << operations[i].name << endl;
    }
}

// Fungsi untuk mendapatkan input dari user
double getNumber(const string &prompt)
{
    double number;
    cout << prompt;
    cin >> number;
    return number;
}

// Fungsi untuk melakukan operasi matematika
double calculate(double num1, double num2, int choice)
{
    switch (choice)
    {
    case 1:
        return num1 + num2;
    case 2:
        return num1 - num2;
    case 3:
        return num1 / num2;
    case 4:
        return num1 * num2;
    default:
        return 0;
    }
}

// Fungsi untuk mendapatkan nama operasi
string getOperationName(int choice)
{
    return (choice >= 1 && choice <= 4) ? operations[choice - 1].name : "";
}

// Fungsi untuk mendapatkan simbol operasi
string getOperationSymbol(int choice)
{
    return (choice >= 1 && choice <= 4) ? operations[choice - 1].symbol : "";
}

int main()
{
    while (true)
    {
        system("clear"); // Clear terminal
        displayHeader();

        // Input bilangan
        double num1 = getNumber("Masukkan Bilangan Pertama = ");
        double num2 = getNumber("Masukkan Bilangan Kedua   = ");

        displayMenu();

        // Input pilihan menu
        int choice;
        cout << "Menu Pilihanmu : ";
        cin >> choice;

        // Validasi pilihan menu
        if (choice < 1 || choice > 4)
        {
            cout << "Pilihan tidak valid!" << endl;
            continue;
        }

        // Validasi pembagian dengan nol
        if (choice == 3 && num2 == 0)
        {
            cout << "Error: Pembagian dengan nol tidak diperbolehkan!" << endl;
            cout << "Press any key to continue...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            continue;
        }

        // Menghitung dan menampilkan hasil
        double result = calculate(num1, num2, choice);
        cout << "Hasil " << getOperationName(choice) << " "
             << num1 << " " << getOperationSymbol(choice) << " "
             << num2 << " = " << result << endl;

        // Menunggu input sebelum melanjutkan
        cout << "Press any key to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }

    return 0;
}