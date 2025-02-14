#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

// Struktur untuk menyimpan data mahasiswa
struct Student
{
    string name;
    string nim;
    string prodi;
    string className;
    double attendance;
    double assignment;
    double midExam;
    double finalExam;
};

// Struktur untuk menyimpan hasil perhitungan
struct Result
{
    double finalScore;
    char grade;
    string status;
};

// Konstanta bobot penilaian
const double ATTENDANCE_WEIGHT = 0.10; // 10%
const double ASSIGNMENT_WEIGHT = 0.20; // 20%
const double MIDEXAM_WEIGHT = 0.30;    // 30%
const double FINALEXAM_WEIGHT = 0.40;  // 40%

// Fungsi untuk membersihkan buffer input
void clearInputBuffer()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Fungsi untuk validasi input nilai
double getValidScore(const string &prompt)
{
    double score;
    bool isValid = false;

    do
    {
        cout << prompt;

        // Cek apakah input adalah angka
        if (cin >> score)
        {
            // Cek apakah nilai berada dalam range 0-100
            if (score >= 0 && score <= 100)
            {
                isValid = true;
            }
            else
            {
                cout << "Error: Nilai harus berada dalam rentang 0-100!\n";
            }
        }
        else
        {
            cout << "Error: Input harus berupa angka!\n";
            clearInputBuffer();
        }
    } while (!isValid);

    return score;
}

// Fungsi untuk input data mahasiswa
Student inputStudentData()
{
    Student student;

    cout << "Masukkan Nama        : ";
    getline(cin >> ws, student.name);
    cout << "Masukkan NIM         : ";
    getline(cin, student.nim);
    cout << "Masukkan Prodi       : ";
    getline(cin, student.prodi);
    cout << "Masukkan Kelas       : ";
    getline(cin, student.className);

    // Input nilai dengan validasi
    student.attendance = getValidScore("Masukkan Nilai Absen : ");
    student.assignment = getValidScore("Masukkan Nilai Tugas : ");
    student.midExam = getValidScore("Masukkan Nilai UTS   : ");
    student.finalExam = getValidScore("Masukkan Nilai UAS   : ");

    return student;
}

// Fungsi untuk menghitung nilai akhir
double calculateFinalScore(const Student &student)
{
    return (student.attendance * ATTENDANCE_WEIGHT) +
           (student.assignment * ASSIGNMENT_WEIGHT) +
           (student.midExam * MIDEXAM_WEIGHT) +
           (student.finalExam * FINALEXAM_WEIGHT);
}

// Fungsi untuk menentukan nilai huruf
char determineGrade(double finalScore)
{
    if (finalScore >= 80)
        return 'A';
    if (finalScore >= 70)
        return 'B';
    if (finalScore >= 55)
        return 'C';
    if (finalScore >= 40)
        return 'D';
    return 'E';
}

// Fungsi untuk menentukan status kelulusan
string determineStatus(double finalScore)
{
    return (finalScore >= 55) ? "LULUS" : "TIDAK LULUS";
}

// Fungsi untuk menghitung semua hasil
Result calculateResults(const Student &student)
{
    Result result;
    result.finalScore = calculateFinalScore(student);
    result.grade = determineGrade(result.finalScore);
    result.status = determineStatus(result.finalScore);
    return result;
}

// Fungsi untuk menampilkan hasil
void displayResults(const Student &student, const Result &result)
{
    cout << "\n====================\n";
    cout << "Hasil Perhitungan\n";
    cout << "====================\n";
    cout << "Nama        : " << student.name << endl;
    cout << "NIM         : " << student.nim << endl;
    cout << "Prodi       : " << student.prodi << endl;
    cout << "Kelas       : " << student.className << endl;
    cout << fixed << setprecision(2);
    cout << "Nilai Akhir : " << result.finalScore << endl;
    cout << "Nilai Huruf : " << result.grade << endl;
    cout << "Status      : " << result.status << endl;
}

int main()
{
    cout << "=====================================\n";
    cout << "Program Penghitung Nilai Mahasiswa\n";
    cout << "=====================================\n";

    // Input data mahasiswa
    Student student = inputStudentData();

    // Hitung hasil
    Result result = calculateResults(student);

    // Tampilkan hasil
    displayResults(student, result);

    return 0;
}