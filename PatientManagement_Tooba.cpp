#include <iostream>
#include <string>

using namespace std;

// Maximum number of patients and appointments (for simplicity)
const int MAX_PATIENTS = 100;
const int MAX_APPOINTMENTS = 10;

// Structure to hold appointment details
struct Appointment {
    string doctorName;
    string appointmentDate;
    string appointmentTime;
};

// Structure to hold patient details
struct Patient {
    int id; // Unique Patient ID
    string name;
    int age;
    string gender;
    string contact;
    string medicalHistory;
    Appointment appointments[MAX_APPOINTMENTS];  // List of appointments for this patient
    int appointmentCount;  // Count of appointments for this patient
};

// Array of patients (up to MAX_PATIENTS)
Patient patients[MAX_PATIENTS];
int currentPatientCount = 0;  // Track the number of patients

// Function to register a new patient
void registerPatient() {
    if (currentPatientCount >= MAX_PATIENTS) {
        cout << "Patient list is full." << endl;
        return;
    }

    Patient newPatient;

    cout << "Enter unique Patient ID: ";
    cin >> newPatient.id;
    cin.ignore(); // Clear input buffer
    for (int i = 0; i < currentPatientCount; i++) {
        if (patients[i].id == newPatient.id) {
            cout << "Patient ID already exists. Please enter a unique ID.\n";
            return;
        }
    }

    cout << "Enter patient's name: ";
    getline(cin, newPatient.name);
    cout << "Enter patient's age: ";
    cin >> newPatient.age;
    cout << "Enter patient's gender: ";
    cin >> newPatient.gender;
    cout << "Enter patient's contact info: ";
    cin >> newPatient.contact;
    cin.ignore(); // Clear input buffer
    cout << "Enter patient's medical history: ";
    getline(cin, newPatient.medicalHistory);

    newPatient.appointmentCount = 0;  // No appointments yet

    patients[currentPatientCount] = newPatient;
    currentPatientCount++;

    cout << "Patient registered successfully.\n";
}

// Function to schedule an appointment for a patient
void scheduleAppointment() {
    if (currentPatientCount == 0) {
        cout << "No patients registered yet.\n";
        return;
    }

    int patientId;
    cout << "Enter Patient ID: ";
    cin >> patientId;

    int index = -1;
    for (int i = 0; i < currentPatientCount; i++) {
        if (patients[i].id == patientId) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Patient ID not found.\n";
        return;
    }

    if (patients[index].appointmentCount >= MAX_APPOINTMENTS) {
        cout << "This patient has reached the maximum number of appointments.\n";
        return;
    }

    Appointment newAppointment;

    cout << "Enter doctor's name: ";
    cin >> newAppointment.doctorName;
    cout << "Enter appointment date (DD/MM/YYYY): ";
    cin >> newAppointment.appointmentDate;
    cout << "Enter appointment time (HH:MM): ";
    cin >> newAppointment.appointmentTime;

    // Add the new appointment to the patient's list
    patients[index].appointments[patients[index].appointmentCount++] = newAppointment;

    cout << "Appointment scheduled successfully.\n";
}

// Function to display medical history and treatment records for a patient
void viewMedicalHistory() {
    if (currentPatientCount == 0) {
        cout << "No patients registered yet.\n";
        return;
    }

    int patientId;
    cout << "Enter Patient ID: ";
    cin >> patientId;

    int index = -1;
    for (int i = 0; i < currentPatientCount; i++) {
        if (patients[i].id == patientId) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Patient ID not found.\n";
        return;
    }

    Patient patient = patients[index];

    cout << "\nPatient ID: " << patient.id << endl;
    cout << "Name: " << patient.name << endl;
    cout << "Age: " << patient.age << endl;
    cout << "Gender: " << patient.gender << endl;
    cout << "Contact: " << patient.contact << endl;
    cout << "Medical History: " << patient.medicalHistory << endl;

    // Display patient's appointments
    cout << "\nAppointments:\n";
    for (int i = 0; i < patient.appointmentCount; ++i) {
        cout << "Doctor: " << patient.appointments[i].doctorName << endl;
        cout << "Date: " << patient.appointments[i].appointmentDate << endl;
        cout << "Time: " << patient.appointments[i].appointmentTime << endl;
        cout << "---------------------------\n";
    }
}

// Function to search for a patient by name
void searchPatientByName() {
    string name;
    cout << "Enter the name of the patient you want to search: ";
    cin.ignore();
    getline(cin, name);

    bool found = false;
    for (int i = 0; i < currentPatientCount; i++) {
        if (patients[i].name == name) {
            cout << "\nPatient ID: " << patients[i].id << endl;
            cout << "Name: " << patients[i].name << endl;
            cout << "Age: " << patients[i].age << endl;
            cout << "Gender: " << patients[i].gender << endl;
            cout << "Contact: " << patients[i].contact << endl;
            cout << "Medical History: " << patients[i].medicalHistory << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Patient not found.\n";
    }
}

// Main menu function
void displayMenu() {
    int choice;
    do {
        cout << "\nHospital Management System - Patient Management\n";
        cout << "1. Register new patient\n";
        cout << "2. Schedule appointment\n";
        cout << "3. View medical history and treatment records\n";
        cout << "4. Search patient by name\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerPatient();
                break;
            case 2:
                scheduleAppointment();
                break;
            case 3:
                viewMedicalHistory();
                break;
            case 4:
                searchPatientByName();
                break;
            case 5:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 5);
}

int main() {
    displayMenu();
    return 0;
}
