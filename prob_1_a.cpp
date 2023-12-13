/* 1A)
 Create a database of SEIT class (at least 8 records). Database contains different fields of every student like Roll No, Name an SGPA(array of structure).
a) Arrange roll call list of students according to roll numbers in ascending order using Bubble Sort.
b) Search Student according to SGPA.*/


#include<cstring>
#include<iostream>
using namespace std;

struct student
{
    char student_name[20];
    float SGPA;
    int rollno;
};
int n;
class student_data{
    private:
    struct student s1[8];

    public:
    void view_data(){
        cout<<"\n \n   Name       Roll no         SGPA"<<endl;
        for (int i = 0; i < n; i++)
        {
            cout<<i+1<<". "<<s1[i].student_name;
            cout<<"\t\t";
            cout<<s1[i].rollno;
            cout<<"\t\t";
            cout<<s1[i].SGPA<<endl;
        }
        
    }

    void add(){
        cout<<"\n Enter the number of students data to be added (max 8)"<<endl;
        cin>>n;
        cout<<"\n Filling data such as Student name, roll number and SGPA"<<endl;
        for (int i = 0; i < n; i++)
        {
            cout<<"\n Detail of student no."<<i+1<<"-\n \n ENTER THE NAME OF THE STUDENT : "<<endl;
            cin>>s1[i].student_name;
            cout<<"\n ENTER THE ROLL NO OF THE STUDENT"<<endl;
            cin>>s1[i].rollno;
            cout<<"\n ENTER THE SGPA OF THE STUDENT"<<endl;
            cin>>s1[i].SGPA;
        }
        cout<<"Addition carried out successfully"<<endl;
        student_data::view_data();
    }

    void search_sgpa(float r)  //linear search on SGPA
        {
            cout<<"\n\n< Searching in SGPA using Linear Search...>\n-----------------------------------------------";
            int t = 0;
            for (int i = 0; i < n; i++)
            {
                if(s1[i].SGPA == r)
                {
                    cout<<"\n\n#"<<t<<" Details of Student with SGPA "<<s1[i].SGPA;
                    cout<<"\n\n Student     Name           SGPA           Roll_No.\n";  			  		 			    cout<<"    "<<i+1<<".       "<<s1[i].student_name;
                    cout<<"    \t   "<<s1[i].SGPA<<"   \t    "<<s1[i].rollno;
                    cout<<"\n--------------------------------------------------------------";
                    t++;
                    continue;
                }
            }
            if(t == 0)
            {
                cout<<"\n Student '"<<r<<"' not found or Input correct SGPA";
            }
        }

    void sort_rollno()  //sorting roll no. in ascending order using bubble sort
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n-1; j++)
                {
                    if((s1[j].rollno) < (s1[j+1].rollno)) //Swapping
                    {
                        struct student temp;
                        temp = s1[j];
                        s1[j] = s1[j+1];
                        s1[j+1] = temp;
                    }
                }
            }
            student_data :: view_data();
        }
};

int main(){
    student_data std;
    float r;
    cout<<"\t-------- WELCOME TO SE IT STUDENTS DATA BASE -------\n \t "<<endl;
    char stop;
    stop='Y';
    while(stop=='Y'){
        cout<<"\n Select action from the following : \n"<<endl;
        cout<<"1.Add Records \t 2.Sort Roll no \t 3.Search SGPA \t 4.View records"<<endl;
        cout<<"\nEnter choice(1,2,3,4)"<<endl;
        int choice;
        cin>>choice;
        switch(choice){
            case 1:
            std.add();
            break;

            case 2:
            cout<<"Sorting roll call using bubble sort: "<<endl;
            std.sort_rollno();
            break;

            case 3:
            cout<<"Enter the SGPA of the student: "<<endl;
            std.search_sgpa(r);
            break;
            
            case 4:
            cout<<"Record is as follows :"<<endl;
			std.view_data();
            break;

            default:
            cout<<"Invalid Input"<<endl;
        }
        cout<<"Do you want to continue(Y/N)"<<endl;
        cin>>stop;
        if(stop=='N'| 'n'){
            cout<<"----------------Code Ended--------------------"<<endl;
        }
    }
    return 0;
}

/*Algorithm :
Create a structure
Create_database(struct student s[] )

Step 1: Accept how many records user need to add, say, no of records as n
Step 2: For i = 0 to n – 1
i. Accept the record and store it in s[i]
Step 3: End For
Step 4: stop


Display_database(struct student s[] ,int n)

Step 1: For i = 0 to n – 1
i. Display the fields s.roll_no, s.name, s.sgpa
Step 2: End For
Step 3: Stop


Bubble Sort student according to sort to roll numbers
BubbleSort(Student s[], n)

Step 1: For Pass = 1 to n-1
Step 2: For i = 0 to (n – pass – 1)
i. Ifs[i].roll_no < s[i+1].roll_no
a. Swap (s[i]. s[i+1])
iii. End if
Step 3: End for
Step 4: End For
Step 5 :Stop


Search Student by SGPA:
   - Create a function to search for a student based on SGPA.
   - Iterate through the array of students.
   - If the SGPA of the current student matches the target SGPA, return the index.
   - If no match is found, return -1.

Main Program
   - Initialize an array of students with at least 8 records.
   - Display the unsorted list of students.
   - Use the Bubble Sort function to sort the students based on Roll No.
   - Display the sorted list of students.
   - Input a target SGPA.
   - Use the Search function to find a student with the specified SGPA.
   - Display the result - either the student's details and index or a message indicating that the student was not found.
   */