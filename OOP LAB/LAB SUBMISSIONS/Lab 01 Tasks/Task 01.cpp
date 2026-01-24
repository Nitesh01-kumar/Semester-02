#include <iostream>
using namespace std;

int main(){
    int marks[5];
    int total=0, average;
    cout << "Enter the marks for 5 subjects (Out of 100): " << endl;
    
    for(int i=0;i<5;i++){
        cout << "Subject " << i+1 << ": ";
        cin >> marks[i];
        total = total+marks[i];
    }

    cout << "Total: " << total << endl;

    average = total/5;
    cout << "Average: " << average << endl;

    if(average >= 50){
        cout << "Result: Pass" << endl;
    }
    else {
        cout << "Result: Fail" << endl;
    }
	
	return 0;
}
