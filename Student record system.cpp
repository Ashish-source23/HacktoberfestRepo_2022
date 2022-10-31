#include <iostream>
#include<fstream>
#include<windows.h>
using namespace std;
struct student
{
char name[90];
char id[90];
int roll_no;
float prog_m,arch_m,writing_sk,alg_m,sum,average;
};
void intro();
void mainmenu();
void acceptdata();
void view_Specific(int);
void viewall();
void result(int);
void deleterecord(int);
void modify(int);

int main()
{
    system("color a");
    char c;
    system("cls");
    intro();

    do{
   system("cls");
   system("color e");
   cout<<"\n\n";
   cout<<"\t====================STUDENT REPORT CARD MANEGEMENT SYSTEM===================="<<endl;
   cout<<endl;
   cout<<"\t\t\t\t1. MAIN MENU\n\n";
   cout<<"\t\t\t\t2. EXIT\n\n";
   cout<<"ENTER YOUR CHOICE :";
   cin>>c;
   system("cls");
   switch(c)
   {
   case '1':
    {
        mainmenu();
        break;
    }
   
   }
    }while(c!='2');
    return 0;
}
void acceptdata()
{
    system("cls");
    student s;
    ofstream outfile;
    outfile.open("Report.txt",ios::app|ios::binary);
    if(outfile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPEN...press enter key";
        cin.ignore();
        cin.get();
    }
    cout<<"\n\n";
    cout<<"\t\t\t\t=======CREATE A REPORT CARD========\n\n";
    cout<<"ENTER YOUR FULL NAME :";
    cin.ignore();
    cin.getline(s.name,80);
    cout<<"ENTER YOUR ID NUMBER : ";
    cin.ignore();
    cin.get(s.id,80);
    cout<<"ENTER YOUR ROLL NUMBER :";
    cin>>s.roll_no;
    cout<<"ENTER YOUR PROGRAMMING MARK :";
    cin>>s.prog_m;
    cout<<"ENTER YOUR COMPUTER ARCITECTURE MARK :";
    cin>>s.arch_m;
    cout<<"ENTER YOUR WRITING SKILL MARK :";
    cin>>s.writing_sk;
    cout<<"ENTER YOUR ALGEBRA MARK :";
    cin>>s.alg_m;
    s.sum=s.prog_m+s.arch_m+s.writing_sk+s.alg_m;
    s.average=(s.sum/4);
    outfile.write(reinterpret_cast<char *> (&s), sizeof(student));
    outfile.close();
    cout<<endl;
    cout<<"\t\t\t\tTHE FILE IS SUCCESSFULLY SAVED"<<endl;
    cout<<endl;
    cout<<"press any key to continue...";
    cin.ignore();
    cin.get();
}

void intro()

{

    cout << "\n\n\n";
    Sleep(300);
    cout << "\t\t\t\t * * *  **** *      ****  ***   ***   ****   " << endl;
    Sleep(300);
    cout << "\t\t\t\t * * * *     *     *     *   * * * * *        "<< endl;
    Sleep(300);
    cout << "\t\t\t\t * * * ***** *     *     *   * * * * *****    " << endl;
    Sleep(300);
    cout << "\t\t\t\t * * * *     *     *     *   * * * * *         " << endl;
    Sleep(300);
    cout << "\t\t\t\t  ***   **** *****  ****  ***  * * *  ****     " << endl;
    Sleep(300);
    cout<<endl;
    cout<<"\t\t\t\t============================================="<<endl;
    Sleep(500);
    cout<<"\t\t\t\tTHIS IS STUDENT REPORT CARD MANEGEMENT SYSTEM"<<endl;
    Sleep(500);
    cout<<"\t\t\t\t============================================="<<endl;
    Sleep(500);
    cout<<"press any key to continue...";
    cin.ignore();
    cin.get();
}

void mainmenu()

{
    system("color c");
    char cc;
    cout<<"\t\t\t\t=================MAIN MENU================\n\n"<<endl;
    Sleep(300);
    cout<<"\t\t\t\t1. CREATE STUDENT REPORT CARD\n\n"<<endl;
     Sleep(300);
    cout<<"\t\t\t\t2. VIEW ALL STUDENTS REPORT CARD\n\n"<<endl;
     Sleep(300);
    cout<<"\t\t\t\t3. VIEW A SINGLE STUDENT REPORT CARD\n\n"<<endl;
     Sleep(300);
    cout<<"\t\t\t\t4. MODIFY REPORT CARD\n\n"<<endl;
     Sleep(300);
    cout<<"\t\t\t\t5. RESULT\n\n"<<endl;
     Sleep(300);
     cout<<"\t\t\t\t6. DELETE RECORD\n\n"<<endl;
     Sleep(300);
    cout<<"\t\t\t\t=============================="<<endl;
     Sleep(300);
    cout<<"\t\t\t\tENTER YOUR CHOICE...:) <1-6> :";
     Sleep(300);
    cin>>cc;
    cout<<endl;
    switch(cc)
    {
    case '1':
        {
            acceptdata();
            break;
        }
    case '2':
        {
            viewall();
            break;
        }
    case '3':
          {
              int n;
              cout<<"ENTER YOUR ROLL NUMBER :";
              cin>>n;
              view_Specific(n);
              break;
          }
    case '4':
        {
            int n;
            cout<<"ENTER YOUR ROLL NUMBER :";
            cin>>n;
            modify(n);
            break;
        }

    case '5':
        {
            int n;
            cout<<"ENTER YOUR ROLL NUMBER :";
            cin>>n;
            cout<<endl;
            result(n);
            break;
        }
    case '6':
        {
            int n;
            cout<<"ENTER YOUR ROLL NUMBER :";
            cin>>n;
            cout<<endl;
            deleterecord(n);
            break;
        }
    }
}

void viewall()

{
    system("cls");
    student s;
    ifstream infile;
    bool check=false;
    infile.open("Report.txt",ios::app|ios::binary);
    if(infile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED.....press enter key...";
        cin.ignore();
        cin.get();
    }
     cout<<"\n\n";
     cout<<"\t\t\t\tALL STUDENTS REPORT CARDS"<<endl;
     cout<<"=================================================================================="<<endl;
    while(infile.read(reinterpret_cast<char*>(&s),sizeof(student)))
    {
        cout<<"\t\t\t\tSTUDENT NAME :"<<s.name<<endl<<endl;
        cout<<"\t\t\t\tSTUDENT ID NUMBER :"<<s.id<<endl<<endl;
        cout<<"\t\t\t\tSTUDENT ROLL NUMBER :"<<s.roll_no<<endl<<endl;
        cout<<"\t\t\t\tPROGRAMMING MARK :"<<s.prog_m<<endl<<endl;
        cout<<"\t\t\t\tCOMPUTER ARCITECTURE MARK :"<<s.arch_m<<endl<<endl;
        cout<<"\t\t\t\tWRITING SKILL MARK :"<<s.writing_sk<<endl<<endl;
        cout<<"\t\t\t\tALGEBRA MARK :"<<s.alg_m<<endl<<endl;
        cout<<"\t\t\t\tSUM :"<<s.sum<<endl<<endl;
        cout<<"\t\t\t\tAVERAGE :"<<s.average<<endl<<endl;
        cout<<"=================================================================================="<<endl;
        check=true;
    }
    infile.close();
    if(check==false)
    cout<<"\t\t\t\tNO RECORD FOUND..."<<endl<<endl;
    cout<<"press any key to continue....";
    cin.ignore();
    cin.get();
}

void view_Specific(int n)

{
    system("cls");
    student s;
    ifstream infile;
    infile.open("Report.txt",ios::app|ios::binary);
    if(infile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED...";

        cin.ignore();
        cin.get();
    }
    bool equality=false;
    cout<<"\t\t\t\t==========VIEW A SINGLE STUDENT REPORT==========\n\n";
    while(infile.read(reinterpret_cast<char*>(&s),sizeof(student)))
    {
        if(s.roll_no==n)
        {
        cout<<"\t\t\t\tSTUDENT NAME :"<<s.name<<endl;
        cout<<"\t\t\t\tSTUDENT ID NUMBER :"<<s.id<<endl;
        cout<<"\t\t\t\tSTUDENT ROLL NUMBER :"<<s.roll_no<<endl;
        cout<<"\t\t\t\tPROGRAMMING MARK :"<<s.prog_m<<endl;
        cout<<"\t\t\t\tCOMPUTER ARCITECTURE MARK :"<<s.arch_m<<endl;
        cout<<"\t\t\t\tWRITING SKILL MARK :"<<s.writing_sk<<endl;
        cout<<"\t\t\t\tALGEBRA MARK :"<<s.alg_m<<endl;
        cout<<"\t\t\t\tSUM :"<<s.sum<<endl;
        cout<<"\t\t\t\tAVERAGE :"<<s.average<<endl;
        cout<<"\t\t\t\t================================================"<<endl;
        equality=true;
        }
    }
        infile.close();
        if(equality==false)
            cout<<"\t\t\t\tRECORD NOT FOUND..."<<endl;
            cout<<endl;
            cout<<"press any key to continue...";
            cin.ignore();
            cin.get();
}

void result(int n)

{
    system("cls");
    student s;
    ifstream infile;
    infile.open("Report.txt",ios::app|ios::binary);
    if(infile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED..."<<endl;
        cin.ignore();
        cin.get();
    }
    bool eq=false;
    cout<<"\t\t\t\t===========VIEW A SINGLE STUDENT RESULT==========\n\n";
    while(infile.read(reinterpret_cast<char*>(&s),sizeof(student)))
    {
        if(s.roll_no==n)
        {
        cout<<"\t\t\t\tSTUDENT NAME :"<<s.name<<endl<<endl;
        cout<<"\t\t\t\tPROGRAMMING MARK :"<<s.prog_m<<endl<<endl;
        cout<<"\t\t\t\tCOMPUTER ARCITECTURE MARK :"<<s.arch_m<<endl<<endl;
        cout<<"\t\t\t\tWRITING SKILL MARK :"<<s.writing_sk<<endl<<endl;
        cout<<"\t\t\t\tALGEBRA MARK :"<<s.alg_m<<endl<<endl;
        cout<<"\t\t\t\tSUM :"<<s.sum<<endl<<endl;
        cout<<"\t\t\t\tAVERAGE :"<<s.average<<endl<<endl;
        cout<<"\t\t\t\t=================================================="<<endl;
        eq=true;
        }
    }
        infile.close();
        if(eq==false)
            cout<<"\t\t\t\tRECORD NOT FOUND..."<<endl;
            cout<<endl;
            cout<<"press any key to continue...";
            cin.ignore();
            cin.get();
}

void modify(int n)

{
    system("cls");
    student s;
    fstream infile;
    infile.open("Report.txt",ios::binary|ios::in|ios::out);
    if(infile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED..."<<endl;
        cin.ignore();
        cin.get();
    }
     bool checker=false;
     cout<<"\t\t\t\t==========MODIFY A REPORT CARD==========\n\n";
     while(!infile.eof() && checker==false)
     {
     infile.read(reinterpret_cast<char*>(&s),sizeof(student));
     {
         if(s.roll_no==n)
         {
        cout<<"\t\t\t\tSTUDENT NAME :"<<s.name<<endl<<endl;
        cout<<"\t\t\t\tSTUDENT ID NUMBER :"<<s.id<<endl<<endl;
        cout<<"\t\t\t\tSTUDENT ROLL NUMBER :"<<s.roll_no<<endl<<endl;
        cout<<"\t\t\t\tPROGRAMMING MARK :"<<s.prog_m<<endl<<endl;
        cout<<"\t\t\t\tCOMPUTER ARCHITECTURE MARK :"<<s.arch_m<<endl<<endl;
        cout<<"\t\t\t\tWRITING SKILL MARK :"<<s.writing_sk<<endl<<endl;
        cout<<"\t\t\t\tALGEBRA MARK :"<<s.alg_m<<endl<<endl;
        cout<<"============================================="<<endl;
        cout<<"\t\tENTER THE NEW INFORMATION"<<endl;
        cout<<"============================================="<<endl;
        cout<<"ENTER YOUR FULL NAME :";
    cin.ignore();
    cin.getline(s.name,80);
    cout<<"ENTER YOUR ID NUMBER : ";
    cin.ignore();
    cin.get(s.id,80);
    cout<<"ENTER YOUR ROLL NUMBER :";
    cin>>s.roll_no;
    cout<<"ENTER YOUR PROGRAMMING MARK :";
    cin>>s.prog_m;
    cout<<"ENTER YOUR COMPUTER ARCITECTURE MARK :";
    cin>>s.arch_m;
    cout<<"ENTER YOUR WRITING SKILL MARK :";
    cin>>s.writing_sk;
    cout<<"ENTER YOUR ALGEBRA MARK :";
    cin>>s.alg_m;
    s.sum=s.prog_m+s.arch_m+s.writing_sk+s.alg_m;
    s.average=(s.sum/4);
    int pos=(-1)*static_cast<int>(sizeof(student));
    infile.seekp(pos,ios::cur);
    infile.write(reinterpret_cast<char *> (&s), sizeof(student));
    cout<<endl;
    cout<<"\t\t\t\tTHE FILE IS SUCCESSFULLY updated"<<endl;
    checker=true;
         }
     }
     }
     infile.close();
         if(checker==false)
            cout<<"\t\t\t\tRECORD NOT FOUND"<<endl;
            cout<<endl;
            cout<<"press any key to continue...";
            cin.ignore();
            cin.get();
  }

  void deleterecord(int n)

  {
     system("cls");
     student s;
     ifstream infile;
     infile.open("Report.txt",ios::binary);
     if(!infile)
     {
         cout<<"THE FILE COULD NOT BE OPENED..."<<endl;
         cin.ignore();
         cin.get();
     }
     ofstream outfile;
     outfile.open("Record2.txt",ios::binary);
     infile.seekg(0,ios::beg);
     cout<<"\t\t\t\t===========DELETE A REPORT CARD==========\n\n";
     while(infile.read(reinterpret_cast<char*>(&s),sizeof(student)))
     {
         if(s.roll_no!=n)
         {
             outfile.write(reinterpret_cast<char*>(&s),sizeof(student));
         }
     }
     infile.close();
     outfile.close();
     remove("Report.txt");
     rename("Record2.txt","Report.txt");
     cout<<endl;
     cout<<"\t\t\t\tRECORD SUCCESSFULLY DELETED"<<endl;
     cout<<"press any key to continue...";
     cin.ignore();
     cin.get();
  }



