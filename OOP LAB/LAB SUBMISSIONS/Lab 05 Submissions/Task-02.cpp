#include <iostream>
using namespace std;

class MedicationEntry {
public:
    string drugName;
    string dose;
    string timeGiven;

    MedicationEntry(string d, string ds, string t) {
        drugName = d;
        dose = ds;
        timeGiven = t;
    }

    void display() {
        cout << "Drug: " << drugName << endl;
        cout << "Dose: " << dose << endl;
        cout << "Time Given: " << timeGiven << endl;
    }
};

class VitalSignsCheck {
public:
    float temperature;
    int heartRate;
    string timeChecked;

    VitalSignsCheck(float temp, int hr, string time) {
        temperature = temp;
        heartRate = hr;
        timeChecked = time;
    }

    void display() {
        cout << "Temperature: " << temperature << endl;
        cout << "Heart Rate: " << heartRate << endl;
        cout << "Time Checked: " << timeChecked << endl;
    }
};

class DiagnosisNote {
public:
    string noteText;
    string doctorName;
    string date;

    DiagnosisNote(string note, string doctor, string d) {
        noteText = note;
        doctorName = doctor;
        date = d;
    }

    void display() {
        cout << "Diagnosis: " << noteText << endl;
        cout << "Doctor: " << doctorName << endl;
        cout << "Date: " << date << endl;
    }
};

class PatientRecord {
public:
    int patientId;
    string name;
    string dob;

    MedicationEntry* medication;
    VitalSignsCheck* vitals;
    DiagnosisNote* diagnosis;

    PatientRecord(int id, string n, string d) {
        patientId = id;
        name = n;
        dob = d;

        medication = new MedicationEntry("Paracetamol", "500mg", "10:00 AM");
        vitals = new VitalSignsCheck(98.6, 75, "09:30 AM");
        diagnosis = new DiagnosisNote("Viral Fever", "Dr. Ahmed", "26-02-2026");
    }

    ~PatientRecord() {
        delete medication;
        delete vitals;
        delete diagnosis;
    }

    void displayRecord() {
        cout << "Patient ID: " << patientId << endl;
        cout << "Name: " << name << endl;
        cout << "DOB: " << dob << endl;
        cout << endl;

        medication->display();
        cout << endl;

        vitals->display();
        cout << endl;

        diagnosis->display();
    }
};

int main() {
    PatientRecord p1(101, "Lily Smith", "12-05-2000");
    p1.displayRecord();
    return 0;
}