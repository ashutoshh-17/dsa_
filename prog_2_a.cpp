/*
2)  Create a database of SEIT class (at least 8 records). Database contains different fields of every student like Roll No, 
Name an SGPA.(array of structure).
a) Arrange list of students alphabetically using Insertion Sort. b) Search Student name using Binary search.  */                                                                

#include <cstring>
#include <iostream>
using namespace std;

struct student
{
    char student_name[20];
    float SGPA;
    int Roll_no;
};
int n;
class student_data
{
    private :
          struct student s1[15];        
     public :
         void viewdata()
        {
            cout<<"\n\n   Student Name        SGPA        Roll No.\n-----------------------------------------------------\n";
            for (int i = 0; i < n; i++)
            {
                cout<<"    "<<i+1<<". "<<s1 [i].student_name ;
                cout<<"\t\t";
                cout<<s1[i].SGPA ;
                cout<<"\t\t";
                cout<<s1[i].Roll_no<<endl;
            }
        }

        void add()
        {       cout<<"\n Enter no. of Student details to be added (max 15) : ";
                cin>>n;
 		cout<<"\n Filling data such as Name,    SGPA,    Roll no.\n ------------------------------------------------------";
                for ( int i =0; i <n; i++)
                {
                    cout<<"\n\n# Details of Student no. "<<i+1<<" - \n\n  Enter Name of Student : ";
                    cin>>s1[i].student_name;
                    cout<<"\n  Enter Student SGPA : ";
                    cin>>s1[i].SGPA;
                    cout<<"\n  Enter Student Roll no. : ";
                    cin>>s1[i].Roll_no;
                }
                cout<<"---------------- Addition Done Successfully ! ----------------";
                student_data :: viewdata();
        }
        void sort_names()  //insertion sort for sorting names
        {
            for (int k=n-1; k>0; k--)
            {  
                struct student temp = s1[k];
                int j = k-1;
                while (j >= 0 && strcmp(temp.student_name, s1[j].student_name) < 0)  
                {
                    s1[j+1] = s1[j];
                    j = j-1;
                }
                s1[j+1] = temp;
            }
        }

  void search_name()
        {
            cout<<"\n Enter student name to be searched : ";
            char search[10];
            cin>>search;
            cout<<"\n< Searching name using Binary Search...>";
            int lower = 0, upper, mid;
            upper = n - 1;
            mid = (lower + upper)/2;
            student_data :: sort_names();
            while (lower <= upper)
            {
                if(strcmp(s1[mid].student_name, search)<0)
                {
                    lower = mid + 1;
                }
                else if(strcmp(s1[mid].student_name, search)==0)
                {
                    cout<<"\n\n# Details of Student with name "<<s1[mid].student_name<<" -";
                    cout<<"\n\n Student        Name         SGPA        Roll\n    No.                                           No.\n--------------------------------------------------------------\n";
                    cout<<"    1.        "<<s1[mid].student_name;
                    cout<<"   \t  "<<s1[mid].SGPA<<"   \t  "<<s1[mid].Roll_no;
                    cout<<"\n--------------------------------------------------------------";
                    break;
                }
                else
                {
                    upper = mid - 1;
                    mid = (lower + upper)/2;
                }
            }
            if(lower > upper)
            {
                cout<<"\n Student '"<<search<<"' details not found or Input correct name";
            }
        }
};


int main()
{
    student_data std;
    float r;
    cout<<"--------------------------------------------------------------------\n\t\t----- SE IT Student Database -----\n--------------------------------------------------------------------\n";
    char stopApp;
    stopApp = 'Y';
    while(stopApp == 'Y')
    {
        cout<<"\n\nSelect action from following : \n";
        cout<<"\n1.ADD RECORDS\t2.SORT NAME \t3.SEARCH NAME\t4. EXIT\n";
        cout<<"Enter choice (1/2/3/4): ";
        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1:
                std.add();
                break;
            case 2:
                cout<<"\n< Sorting name alphabetically using Insertion Sort...>";
                std.sort_names();
                std.viewdata();
                break;
            case 3:
                std.search_name();
                break;
            case 4:
                cout<<" >Exited successful<\n --| END OF CODE |--";
                return 0;
            default :
                cout<<"\n Invalid choice !";
        }
        cout<<"\n\nDo you want to continue (Y/N) ? : ";
        cin>>stopApp;
        if (stopApp == 'N' | 'n')
        {
            cout<<" ----------------| END OF CODE |----------------\n";
        }
    }
    return 0;
}

/* Algorithm :
insertion_Sort (Struct student S[], int n)
Step 1: For i = 1 to n-1
i. Set key to s[i]
ii. Set j to i-1
iii. While j>=0 AND strcmp(s[i].name,key.name)>0
a. Assign s[j] to s[j+1]
b. Decrement j
iv. End While
Step 2: Assign key to s[j+1]
Step 3: End for
Step 4: end of insertion sort
*/