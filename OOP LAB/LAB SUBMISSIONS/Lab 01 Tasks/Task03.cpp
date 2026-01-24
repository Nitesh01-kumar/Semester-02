#include <iostream>
using namespace std;

struct Student{
	string roll_num;
	string name;
	int marks[3];
	float cgpa;
};

void input(Student* s, int n){
	
	for(int i=0;i<n;i++){
	
		cout << "Enter the details for student " << i+1 << ": " << endl;
		cout << "Roll num: " <<endl;
		cin >> s[i].roll_num;
		
		cin.ignore();
		cout << "Name: ";
		getline(cin, s[i].name);
		
		for(int j=0;j<3;j++){
			cout << "Marks of subject " << j+1 <<endl;
			cin >> s[i].marks[j]; 
		}
	}
}

void CGPA(Student* s, int n){

	for(int i=0;i<n;i++){
		float total = 0;
		for(int j=0;j<3;j++){
			total = total + s[i].marks[j]; 
		}
		s[i].cgpa = total/30.0;
	}
}

void Display(Student* s, int n){
	int found=0;
	for(int i = 0; i < n; i++){
	    if(s[i].cgpa >= 3.0){
	    	cout << "\nStudent over 3 CGPA\n"<<endl;
	        cout << "Name: " << s[i].name << endl;
	        cout << "CGPA: " << s[i].cgpa << endl;
	        found = 1;
	    }
	}
	if(found == 0){
    	cout << "No student has CGPA above 3.0" << endl;
	}
}

void Top(Student* s, int n){
	int top = 0;
	for(int i=1;i<n;i++){
		if(s[i].cgpa > s[top].cgpa){
			top = i;
		}
	}
	cout << "\nTop Performer: " << endl;
	cout << "Name: " << s[top].name << endl;
	cout << "Roll No: " << s[top].roll_num << endl;
	cout << "CGPA: " << s[top].cgpa << endl;
}


int main(){
	int n;
	
	cout << "Enter the number of students: " << endl;
	cin >> n;
	cin.ignore();	
	
	Student* s = new Student[n];
	input(s,n);
	CGPA(s,n);
	Display(s,n);
	Top(s,n);
	delete[] s;
	return 0;
}
