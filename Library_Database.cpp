#include<bits/stdc++.h>
#include<algorithm>
#define int long long
#define float double
#define pb push_back
#define rep(i,ind,n) for(int i=ind;i<n;i++)
using namespace std;

class Student{
protected:
    vector<string> Name,standard;
    vector<int> Addmission,Books;
    map<int,int> Date;
};

class Book{
protected:
    vector<string> Author,Title,Domain,Edition;
    vector<int> No,Copies;
};

class Admin:public Student,public Book{
public:
    void AddStudentInf(string name,string cl,int a,int b){
        Name.pb(name);
        standard.pb(cl);
        Addmission.pb(a);
        Books.pb(b);
    }
    void AddBookInf(string w,string x,string y,string z,int a,int b){
        Author.pb(w);
        Title.pb(x);
        Domain.pb(y);
        Edition.pb(z);
        No.pb(a);
        Copies.pb(b);
    }
    void modifyStudent(int a,string cl,int b){
        int j=-1;
        rep(i,0,Addmission.size())
        if(Addmission[i]==a){
            j=i;
            break;
        }
        if(j==-1)
        cout<<"No such record exists.\n";
        else{
            standard[j]=cl;
            Books[j]=b;
        }
    }
    void modifyBook(int a,int b){
        int j=-1;
        rep(i,0,No.size())
        if(No[i]==a){
            j=i;
            break;
        }
        if(j==-1)
        cout<<"No such record exists.\n";
        else{
            Copies[j]=b;
        }
    }
    void DeleteStudentRecord(int a){
        int j=-1;
        rep(i,0,Addmission.size())
        if(Addmission[i]==a){
            j=i;
            break;
        }
        if(j==-1)
        cout<<"No such record exists.\n";
        else{
            rep(i,j,Addmission.size()-1){
                Addmission[i]=Addmission[i+1];
                Name[i]=Name[i+1];
                standard[i]=standard[i+1];
                Books[i]=Books[i+1];
            }
            Addmission.pop_back();
            Name.pop_back();
            standard.pop_back();
            Books.pop_back();
        }
    }
    void DeleteBookRecord(int a){
        int j=-1;
        rep(i,0,No.size())
        if(No[i]==a){
            j=i;
            break;
        }
        if(j==-1)
        cout<<"No such record exists.\n";
        else{
            rep(i,j,No.size()-1){
                No[i]=No[i+1];
                Author[i]=Author[i+1];
                Title[i]=Title[i+1];
                Domain[i]=Domain[i+1];
                Edition[i]=Edition[i+1];
                Copies[i]=Copies[i+1];
            }
            No.pop_back();
            Author.pop_back();
            Title.pop_back();
            Domain.pop_back();
            Edition.pop_back();
            Copies.pop_back();
        }
    }
    void viewSingleStudentRecord(int a){
        int j=-1;
        rep(i,0,Addmission.size())
        if(Addmission[i]==a){
            j=i;
            break;
        }
        if(j==-1)
        cout<<"No such record exists.\n";
        else{
            cout<<"Student's Name: "<<Name[j]<<endl;
            cout<<"Student's Admission Number: "<<Addmission[j]<<endl;
            cout<<"Student's Class: "<<standard[j]<<endl;
            cout<<"Student's Books Issued Number: "<<Books[j]<<endl;
        }
    }
    void viewSingleBookRecord(int a){
        int j=-1;
        rep(i,0,No.size())
        if(No[i]==a){
            j=i;
            break;
        }
        if(j==-1)
        cout<<"No such record exists.\n";
        else{
            cout<<"Books's No: "<<No[j]<<endl;
            cout<<"Books's Author Name: "<<Author[j]<<endl;
            cout<<"Books's Title: "<<Title[j]<<endl;
            cout<<"Books's Domain: "<<Domain[j]<<endl;
            cout<<"Books's Edition: "<<Edition[j]<<endl;
            cout<<"Books's Copies: "<<Copies[j]<<endl;
        }
    }
    void viewAllStudentRecord(){
            int tmp=1;
        rep(j,0,Addmission.size()){
            cout<<"Student "<<tmp<<"'s Name: "<<Name[j]<<endl;
            cout<<"Student "<<tmp<<"'s Admission Number: "<<Addmission[j]<<endl;
            cout<<"Student "<<tmp<<"'s Class: "<<standard[j]<<endl;
            cout<<"Student "<<tmp<<"'s Books Issued Number: "<<Books[j]<<endl;
            tmp++;
        }
    }
    void viewAllBooksRecord(){
            int tmp=1;
        rep(i,0,No.size()){
            cout<<"Books: "<<tmp<<"'s No: "<<No[i]<<endl;
            cout<<"Books: "<<tmp<<"'s Author Name: "<<Author[i]<<endl;
            cout<<"Books: "<<tmp<<"'s Title: "<<Title[i]<<endl;
            cout<<"Books: "<<tmp<<"'s Domain: "<<Domain[i]<<endl;
            cout<<"Books: "<<tmp<<"'s Edition: "<<Edition[i]<<endl;
            cout<<"Books: "<<tmp<<"'s Copies: "<<Copies[i]<<endl;
            tmp++;
        }
    }
    void issue(int a,int b,int date){
        int x,y;
        rep(i,0,Addmission.size())
        if(a==Addmission[i]){x=i;break;}
        rep(i,0,No.size())
        if(b==No[i]){y=i;break;}
        if(Copies[y]==0){
            cout<<"This book cannot be issued as no copy is available regarding it.\n";
        }
        else if(Books[x]==3)
        cout<<"Books cannot be issued max no. 3 is reached.\n";
        else{
        Books[x]++;
        Date[b]=date;
        Copies[y]--;}
    }
    void Deposit(int a,int b,int date){
        int x,y,fine;
        rep(i,0,Addmission.size())
        if(a==Addmission[i]){x=i;break;}
        rep(i,0,No.size())
        if(b==No[i]){y=i;break;}
        if(date-Date[b]>15){
            // Fine per day is assumed to be 20 Ruppees
            fine=(date-Date[b]-15)*20;
            cout<<"Submit fine: "<<fine<<"And if need for more days Enter 1 else 0:"<<endl;
            int choice;cin>>choice;
            if(choice==1)
            issue(a,b,date);
        }
        Copies[y]++;
        Books[x]--;
        Date.erase(b);
    }
};


int32_t main()
{
    Admin A;
    string a,b,c,d;
    int x,y,z,choice;
    do{
        cout<<"\n1. Add Student's Info\n2. Add Book's Info\n3. Modify Student's Information\n4. Modify Book's Information\n5. Delete Student's Information\n6. Delete Book's Information\n7. View Single Student's Information\n8. View All Students Information\n9. View Single Books's Information\n10. View All Books Information\n11. Issue The Book\n12. Deposit the book\n";
        cout<<"Enter choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter Name, Class, Admission no and BooksNo: \n";
            cin>>a>>b>>x>>y;
            A.AddStudentInf(a,b,x,y);
            break;
        case 2:
            cout<<"Enter Author's Name,Title,Domain,Edition,No and Copies: \n";
            cin>>a>>b>>c>>d>>x>>y;
            A.AddBookInf(a,b,c,d,x,y);
            break;
        case 3:
            cout<<"Enter Admission No for changes, Standard, BooksNo: \n";
            cin>>x>>a>>y;
            A.modifyStudent(x,a,y);
            break;
        case 4:
            cout<<"Enter Book's No, Copies of that book: ";
            cin>>x>>y;
            A.modifyBook(x,y);
            break;
        case 5:
            cout<<"Enter admission no whose record to be deleted: ";
            cin>>x;
            A.DeleteStudentRecord(x);
            break;
        case 6:
            cout<<"Enter Book no whose record to be deleted: ";
            cin>>x;
            A.DeleteBookRecord(x);
            break;
        case 7:
            cout<<"Enter Admission no of single student: ";
            cin>>x;
            A.viewSingleStudentRecord(x);
            break;
        case 8:
            A.viewAllStudentRecord();
            break;
        case 9:
            cout<<"Enter Admission no of single book: ";
            cin>>x;
            A.viewSingleBookRecord(x);
            break;
        case 10:
            A.viewAllBooksRecord();
            break;
        case 11:
            cout<<"Enter Admission no, Book No, Date: ";
            cin>>x>>y>>z;
            A.issue(x,y,z);
            break;
        case 12:
            cout<<"Enter Admission no, Book No, Current Date: ";
            cin>>x>>y>>z;
            A.Deposit(x,y,z);
            break;

        default:
            exit(0);
        }
    }while(choice<=12);
    return 0;
}