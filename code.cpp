#include<iostream>
#include<malloc.h>
#include<conio.h>
#include<string.h>
using namespace std;
struct student
{
    string name;
    char regno[9];          //details of the students to be included
    char DOB[10];           // into the database
    float gpa[8];
    int credpersem[8];
    string programtype;
    int semester;
    int credcomp;
    int curcred;
    float cgpa;
    char residence[7];
    struct courses *h,*t;
    struct student *nt;
}*head=NULL,*tail=NULL;
struct courses
{
    char code[8];
    char components[12];
    int cred;               //details of the courses being
    int sem;                //taken up by the students
    char grade;
    struct courses *next;
};
void updatedetails();                                                   // --
struct student* addstudent();                                           // |       list of related functions required to
struct student* searchbyname(struct student*);                          // |        implement the database and perform several
struct student* searchbyregno(struct student *h);                       // |        functions
void deleterec(struct student*);                                        // --
struct courses* courselist(struct courses*,struct student*);
void insertstudent(struct student*);
void displaydetails(struct student*);
void addcourse(struct student*);
void updatecourselist(struct student*);
void computeother(struct student*);
void checkroll(char [],struct student *);
void check(char[]);
 void checkcourse(char r[],struct courses *h,struct courses *H,int co=1);
int main()
{
        //Please view the console output in full screen

    // PlaySound(TEXT("mbgm.wav"),GetModuleHandle(NULL),SND_FILENAME|SND_ASYNC|SND_LOOP); //  background music
            //INTRODUCTION OF THE DATABASE PROJECT AND THE STUDENTS
    cout<<"                                         **************************************************************************************\n";
    cout<<"                                         **************************************************************************************\n";
    cout<<"                                         **************************************************************************************\n";
    cout<<"                                                          ----  -----  |   |  --*      -----  |\\      |  -----\n";
    cout<<"                                                         |        |    |   |  |   \\    |      | \\     |    |\n";
    cout<<"                                                         |        |    |   |  |    |   |      |  \\    |    |\n";
    cout<<"                                                          ---     |    |   |  |    |   |--    |   \\   |    |\n";
    cout<<"                                                             |    |    |   |  |    |   |      |    \\  |    |\n";
    cout<<"                                                             |    |    |   |  |   /    |      |     \\ |    |\n";
    cout<<"                                                         ----     |     ---   --*      -----  |      \\|    |\n";
    cout<<endl;
    cout<<"                                            --*         /\\       -----      /\\        --          /\\          ----  -----\n";
    cout<<"                                            |   \\      /  \\        |       /  \\       |  \\       /  \\        |      |\n";
    cout<<"                                            |    |    /    \\       |      /    \\      |   |     /    \\       |      |\n";
    cout<<"                                            |    |   /      \\      |     /      \\     |--/     /      \\        ---  |--\n";
    cout<<"                                            |    |  / ------ \\     |    / ------ \\    |  \\    / ------ \\          | |\n";
    cout<<"                                            |   /  /          \\    |   /          \\   |   |  /          \\         | |\n";
    cout<<"                                            --*   /            \\   |  /            \\  -- /  /            \\   ----   -----\n";
    cout<<endl;
    cout<<"                            |\\       /|       /\\       |\\      |       /\\        -----      ----- |\\      /|  ----- |\\      | -----\n";
    cout<<"                            | \\     / |      /  \\      | \\     |      /  \\      /          |      | \\    / | |      | \\     |   |\n";
    cout<<"                            |  \\   /  |     /    \\     |  \\    |     /    \\     |          |      |  \\  /  | |      |  \\    |   |\n";
    cout<<"                            |   \\ /   |    /      \\    |   \\   |    /      \\    |      --  |--    |   \\/   | |--    |   \\   |   |\n";
    cout<<"                            |         |   / ------ \\   |    \\  |   / ------ \\   |     |  | |      |        | |      |    \\  |   |\n";
    cout<<"                            |         |  /          \\  |     \\ |  /          \\  \\     |    |      |        | |      |     \\ |   |\n";
    cout<<"                            |         | /            \\ |      \\| /            \\  -----      ----- |        |  ----- |      \\|   |\n";
    cout<<endl;
    cout<<"                                                         ----  \\       /   ----  -----  -----  |\\      /|\n";
    cout<<"                                                        |       \\     /   |        |    |      | \\    / |\n";
    cout<<"                                                        |        \\   /    |        |    |      |  \\  /  |\n";
    cout<<"                                                         ---      \\ /      ---     |    |--    |   \\/   |\n";
    cout<<"                                                            |      |          |    |    |      |        |\n";
    cout<<"                                                            |      |          |    |    |      |        |\n";
    cout<<"                                                        ----       |      ----     |    -----  |        |\n";
    cout<<endl;
    cout<<"                                         **************************************************************************************\n";
    cout<<"                                         **************************************************************************************\n";
    cout<<"                                         **************************************************************************************\n\n\n";

   getch();
   int i=0;
   system("pause");
   cout<<"Please Wait ";
while(i<4)
{
    i++;
    cout<<". ";

}
   int ask=1,choice;
while(ask)
{
    system("CLS"); //Primary menu options to perform several functions
cout<<"Enter 1 to Insert Student"<<endl<<"Enter 2 to Delete Student"<<endl<<"Enter 3 to Search Student"<<endl<<"Enter 4 to Update Student Record"<<endl;
cout<<"Enter 5 to Display Student"<<endl<<"Enter -1 to exit: ";
cin>>choice;
 if(choice==1)
    insertstudent(addstudent());
else if(choice==2)
    deleterec(head);
else if(choice==3)
{
    system("CLS");
    int n;
    cout<<"Enter 1 to search by name\n"<<"Enter 2 to search by Registration Number: ";
    cin>>n;
    if(n==1)
        searchbyname(head);
    else
    {
        struct student *s=searchbyregno(head);
        if(s!=NULL)
        {   char c;
            cout<<"Do you want the details? :Y/N ";
            cin>>c;
            if(c=='Y')
                displaydetails(s);}
    }
}
else if(choice==4)
{
   updatedetails();
}
else if(choice==5)
{
    system("CLS");
    struct student *s=searchbyregno(head);
    if(s!=NULL)
        displaydetails(s);
}
else if(choice==-1)
    ask=0;
else
{
     cout<<endl<<"Please enter a valid choice!\n ";
            system("pause");
}
}


}
struct student* addstudent()  // to add the a new student into the database
{
    system("CLS");
    struct student *n=new struct student,*t;
    struct courses *temp;
    cout<<"Welcome to Vellore Institute Of Technology\n";
    cout<<"Please Enter your name: ";
    cin.ignore();
    getline(cin,n->name);
    cout<<"Enter the date of birth in DD-MM-YYYY Format: ";
    cin>>n->DOB;
    cout<<"Enter your 9-Digit Registration Number in format 15XYZ0001: ";
    cin>>n->regno;
    checkroll(n->regno,n);
    n->semester=1;
    n->credcomp=0;
    cout<<"Enter Programme Type (for instance B.Tech.): ";
    cin>>n->programtype;
    cout<<"Enter residence in Block-room format: ";
    cin>>n->residence;
    n->h=NULL;
    n->t=NULL;
    n->nt=NULL;
    n->h=courselist(n->h,n);
    temp=n->h;
    while(temp->next!=NULL)
    temp=temp->next;
    n->t=temp;
    system("pause");
    return n;
}
struct courses* courselist(struct courses *h,struct student* H) //function to add courses for the students when the are added to the
{                                                               //database and returns the pointer to the student.
    system("CLS");
    int num;
    cout<<"How many courses have you registered for in this semester ?: ";
    cin>>num;
    cout<<"NOTE:"<<endl;
    cout<<""<<"Use enter in the Standard format\n";
    H->curcred=0;
    for(int i=0;i<num;i++)
    {
        struct courses *nw=new struct courses,*t;
        cout<<"Enter the course code for course "<<i+1<<" : "; //course code
        cin>>nw->code;
        checkcourse(nw->code,nw,h);
        cout<<"Components: \n";
        cout<<"For LO Enter 1\nFor ETH Enter 2\nFor ETH+ELA Enter 3\nFor ETH+ELA+EPJ Enter 4: "; //course components
        int j;
        cin>>j;
        int flag=1;
        while(1)
        {
            switch(j)
        {
        case 1:
            {
                strcpy(nw->components,"LO");
                flag=0;
                break;
            }
        case 2:
            {
                strcpy(nw->components,"ETH");
                flag=0;
                break;
            }
        case 3:
            {
                strcpy(nw->components,"ETH+ELA");
                flag=0;
                break;
            }
        case 4:
            {
                strcpy(nw->components,"ETH+ELA+EPJ");
                flag=0;
                break;
            }
        default:
            {
                cout<<"Enter a valid choice!\nEnter again: ";
                cin>>j;
                break;
            }
            }
            if(flag==0)
                break;
        }
        cout<<"Enter credits: ";  //credits
        cin>>nw->cred;
        H->curcred=H->curcred+nw->cred;
        cout<<"Semester: "<<H->semester<<endl<<endl;
        nw->sem=H->semester;
        nw->grade='\0';
        nw->next=NULL;
        if(h==NULL)
            h=nw;
        else
        {
            struct courses *temp=h;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=nw;
        }

    }
    return h;

}
struct student* searchbyregno(struct student *h)  // this function plays a major role to identify student records
{                                                 //using their registration numbers
    system("CLS");
    char rno[10];
    cout<<"Enter the registration number: ";
    cin>>rno;
    check(rno);
    struct student* temp=h;
    while(temp!=NULL){
        if(strcmp(temp->regno,rno)==0)
            {cout<<"record found"<<endl;
            return temp;}
            temp=temp->nt;
        }
        cout<<"Record Not Found\n";
        system("pause");
        return NULL;
};
struct student* searchbyname(struct student *h)
{
    system("CLS"); //identifies student based on their names,
    string n;      // can handle situation when multiple students with same name are encountered
    int c=0,ask;
    cout<<"Enter the name: ";
    cin.ignore();
    getline(cin,n);
    struct student* temp=h,*f=NULL,*l=NULL;
    while(temp!=NULL){
        if(temp->name==n)
        {
        c++;
        if(c==1)
            f=l=temp;
        l=temp;
        }
        temp=temp->nt;
        }
        if(c==0)
        {cout<<"NO record found!!\n";
        system("pause");}
        else if(c==1)
            displaydetails(f);
        else
        {                                                                      //when multiple students with same name are encountered
            cout<<"More than one records are found !\n";                       //following options can be used by the user
            cout<<"Enter 1 to print them all\n";
            cout<<"Enter 2 to try searching by registration number instead: ";
            cin>>ask;
            if(ask==1)
            {
            temp=f;
            while(temp!=l->nt){
           if(temp->name==n)
            displaydetails(temp);
            temp=temp->nt;}
            }
            else
                {temp=searchbyregno(h);
                displaydetails(temp);
                }
        }
};
void displaydetails(struct student *s)
{                                                           //this function is used to display the details of the
system("CLS");                                              //identified student
    cout<<"Name: "<<s->name<<endl;
    cout<<"Registration Number: "<<s->regno<<endl;
    cout<<"Date Of Birth: "<<s->DOB<<endl;
    cout<<"Program Type: "<<s->programtype<<endl;
    cout<<"Semester: "<<s->semester<<endl;
    cout<<"Credits Completed: "<<s->credcomp<<endl;
    cout<<"Credits In this Semester: "<<s->curcred<<endl;
    if(s->semester==1&&(s->h->grade=='\0'))
        cout<<"CGPA will be calculated after first semester\n";
    else
        cout<<"CGPA: "<<s->cgpa<<endl;                      //displays the details of courses taken up by the time of call by
    cout<<"Current residence: "<<s->residence<<endl;        //the student.
    cout<<"Courses opted:           Components:            Semester:            Credits:"<<endl;
    struct courses *temp;
    temp=s->h;
    while(temp!=NULL)
    {
        cout<<temp->code<<"                    "<<temp->components<<"                    "<<temp->sem<<"                   "<<temp->cred<<endl;
        temp=temp->next;
    }
    system("pause");
}
void insertstudent(struct student *nw) //receives the pointer returned by the addstudent() and
{                                     //adds  the pointer into the list students in the database.
    if(head==NULL)
        {head=nw;
        tail=nw;}
    else
    {
        tail->nt=nw;
        tail=nw;
    }
};
void deleterec(struct student *h) // seraches the student using their registration number and
{                                 // deletes them if found , else returns back
    if(head!=NULL)
    {
    struct student *rec=searchbyregno(h);
    if(rec!=NULL)
    {
        struct student *temp=h;
        if(temp==rec)
        {
            head=head->nt;
            delete temp;
            cout<<endl<<"Record Deleted !\n";
        system("pause");
        }
        else{
        while(temp->nt!=rec)
            temp=temp->nt;
        temp->nt=rec->nt;
        delete (rec);
        cout<<endl<<"Record Deleted !\n";
        system("pause");}
    }
}
else
{
    cout<<endl<<"No records now!!\n";
    system("pause");
    return;
}
}
void updatedetails() //this is a rather important function the complete database is dependent on it to
{                    //update the student record in the database
    system("CLS");
    struct student *s=searchbyregno(head);
    if(s!=NULL)
    {cout<<"Name: "<<s->name<<endl;
    int choice;
    cout<<"Enter 1 to Update Semester\nEnter 2 to Update residence\nEnter 3 to save grades for current semester\nEnter 4 to update course list for current semester: ";
    cin>>choice;
    switch (choice)
    {
    case 1 :  //to update the semester of a student
        {
            struct courses* t=s->h;
            while(t!=NULL)
            {
                if(t->sem==s->semester)
                    break;
                else
                    t=t->next;
            }
            if(t!=NULL)
            {
            if(t->grade=='\0')
            {
            cout<<endl<<"Please update grades of current courses before updating the semester?\n";
            while(t!=NULL&&(t->sem==s->semester))
            {
                cout<<endl<<"Enter grade for course code "<<t->code<<" : ";
                cin>>t->grade;
                s->credcomp=s->credcomp+t->cred;
                t=t->next;
            }
            computeother(s);}
            cout<<endl<<"Semester Updated !\n";
            s->semester++ ;
            cout<<"Would you like to add courses for the new semester ? (y/n) : ";
            char i;
            cin>>i;
            if(i=='y')
                addcourse(s);}

            else
            {   cout<<endl;
                cout<<"Since no courses for Semester "<<s->semester<<" have been entered , Semester cannot be updated!\n\n";
                cout<<"Would you like to add courses for the semester "<<s->semester<<" ? (y/n) : ";
            char i;
            cin>>i;
            if(i=='y')
                addcourse(s);
            }
            break;
        }
    case 2: //To update the residence of the student in the college
        {
        cout<<endl<<"Enter residence in Block-room format: ";
        cin>>s->residence;
        break;
        }
    case 3:  //To enter grades of the courses registered by the student in the current semester
        {
            struct courses* t=s->h;
            while(t!=NULL)
            {
                if(t->sem==s->semester)
                    break;
                else
                    t=t->next;
            }
            char c='y';
                if(t!=NULL&&t->grade!='\0')
                {cout<<endl<<"The Grades have already been awarded, Do you want to overwrite the Grades? (y/n): ";
                cin>>c;}
                if(t==NULL)
            {
                cout<<"No Courses Registered for semester "<<s->semester<<endl;
                system("pause");
            }
            while(t!=NULL&&t->sem==s->semester)
            {
                if(c=='y')
                {cout<<endl<<"Enter grade for course code "<<t->code<<" : ";
                if(t->grade=='\0')
                s->credcomp=s->credcomp+t->cred;
                cin>>t->grade;

                t=t->next;}
                else
                    break;
            }
            if(c=='y')
            computeother(s);
            break;
        }
    case 4: //to add or delete courses registered by the student;
        {
            updatecourselist(s);
            break;
        }
    default:
        {
            cout<<endl<<"Please enter a valid choice!\n ";
            system("pause");
            break;

        }

    }
}
}
void updatecourselist(struct student *s) //this function is essential to add or delete courses
{
    system("CLS");
cout<<"Enter 1 to add courses for the current semester\nEnter 2 to delete course in the current semester: ";
int c;
cin>>c;
switch(c)
    {
case 1:// new courses can be added only if the courses already present are not graded
    {  //or the courses are being registered for the new semester itself
        if((s->t->grade=='\0')||((s->t->grade!='\0')&&(s->t->sem!=s->semester)))
    {system("CLS");
    int num;
    cout<<"How many courses would you like to add?: ";
    cin>>num;
    cout<<"NOTE:"<<endl;
    if(s->t->grade!='\0')
        s->curcred=0;
    cout<<""<<"For example, if it has theory and lab , enter ELA+ETH\n"<<"If it has only labs, enter LO\n";
    for(int i=0;i<num;i++)
    {
        struct courses *nw=new struct courses,*t;
        cout<<"Enter the course code for course "<<i+1<<" : ";
        cin>>nw->code;
        int f;
        checkcourse(nw->code,nw,s->h);
        cout<<"Components: \n";
        cout<<"For LO Enter 1\nFor ETH Enter 2\nFor ETH+ELA Enter 3\nFor ETH+ELA+EPJ Enter 4: ";
        int j;
        cin>>j;
        int flag=1;
        while(1)
        {
            switch(j)
        {
        case 1:
            {
                strcpy(nw->components,"LO");
                flag=0;
                break;
            }
        case 2:
            {
                strcpy(nw->components,"ETH");
                flag=0;
                break;
            }
        case 3:
            {
                strcpy(nw->components,"ETH+ELA");
                flag=0;
                break;
            }
        case 4:
            {
                strcpy(nw->components,"ETH+ELA+EPJ");
                break;
            }
        default:
            {
                cout<<"Enter a valid choice!\nEnter again: ";
                cin>>j;
                break;
            }
            }
            if(flag==0)
                break;
        }
        cout<<"Enter credits: ";
        cin>>nw->cred;
        s->curcred=s->curcred+nw->cred;
        nw->sem=s->semester;
        cout<<"Semester: "<<s->semester<<endl<<endl;
        nw->grade='\0';
        nw->next=NULL;
        if(s->h==NULL)
            s->h=s->t=nw;
        else
        {s->t->next=nw;
         s->t=nw;
        }
    }
    cout<<endl<<endl<<"Courses added Successfully!\n";
    system("pause");
    }
    else
    {
        cout<<endl;
        cout<<"Please Update the semester as the grades of the courses of the  previous semester have already been evaluated\n ";
        system("pause");
    }
    break;
    }
case 2:
        {//deletes the courses that have not been graded yet ,by taking the course code , if found.
            system("CLS");
            char cc[7];
            cout<<"Enter the course code: ";
            cin>>cc;
            struct courses *p=NULL;
            checkcourse(cc,p,p,0);
            cout<<cc;
            struct courses *t=s->h;
            if(t!=NULL&&t->grade=='\0')
                {struct courses *p;
                if(strcmp(s->h->code,cc)==0)
                {
                    p=s->h;
                    s->h=s->h->next;
                    s->curcred=s->curcred-p->cred;
                    delete(p);
                    cout<<"Course Deleted Succesfully!\n";
                    system("pause");
                    return;
                }
                }
                else if(t==NULL)
                {
                cout<<"Oops! The courselist is Empty!\n ";
                system("pause");
                return;
                }
                else if(t->grade!='\0'&&strcmp(s->h->code,cc)==0)
                {
                    cout<<"Sorry,the course has already been graded and cannot be deleted\n";
                    system("pause");
                    return;
                }
            while(t!=NULL)
            {
                if((t->next!=NULL&&strcmp(t->next->code,cc)==0))
                    break;
                else
                    t=t->next;
            }
            cout<<endl;
            if(t==NULL)
                {cout<<"Course not found !\n";
                system("pause");}
            else
            {
                if(t->next->grade=='\0')
                {struct courses *p;
                    p=t->next;
                    t->next=p->next;
                    if(p==s->t)
                        s->t=t;
                    s->curcred=s->curcred-p->cred;
                    delete(p);
                    cout<<"Course Deleted Succesfully!\n";
                    system("pause");
                }
                else
                {
                    cout<<"Sorry,the course has already been graded and cannot be deleted\n";
                    system("pause");
                }
                }

            break;}

default:
    {
      cout<<endl<<"Please enter a valid choice!\n "<<endl;
            system("pause");
            break;
    }
}
}
void addcourse(struct student *s) //this function adds course to the student's course list if the semester is updated
{
    system("CLS");
    int num;
    cout<<"How many courses would you like to add?: ";
    cin>>num;
    cout<<"NOTE:"<<endl;
    cout<<"For example, if it has theory and lab , enter ELA+ETH\n"<<"If it has only labs, enter LO\n";
    s->curcred=0;
    for(int i=0;i<num;i++)
    {
        struct courses *nw=new struct courses,*t;
        cout<<"Enter the course code for course "<<i+1<<" : ";
        cin>>nw->code;
        checkcourse(nw->code,nw,s->h);
        cout<<"Components: \n";
        cout<<"For LO Enter 1\nFor ETH Enter 2\nFor ETH+ELA Enter 3\nFor ETH+ELA+EPJ Enter 4: ";
        int j;
        cin>>j;
        int flag=1;
        while(1)
        {
            switch(j)
        {
        case 1:
            {
                strcpy(nw->components,"LO");
                flag=0;
                break;
            }
        case 2:
            {
                strcpy(nw->components,"ETH");
                flag=0;
                break;
            }
        case 3:
            {
                strcpy(nw->components,"ETH+ELA");
                flag=0;
                break;
            }
        case 4:
            {
                strcpy(nw->components,"ETH+ELA+EPJ");
                flag=0;
                break;
            }
        default:
            {
                cout<<"Enter a valid choice!\nEnter again: ";
                cin>>j;
                break;
            }
            }
            if(flag==0)
                break;
        }
        cout<<"Enter credits: ";
        cin>>nw->cred;
        s->curcred=s->curcred+nw->cred;
        cout<<"Semester: "<<s->semester<<endl<<endl;
        nw->sem=s->semester;
        nw->grade='\0';
        nw->next=NULL;
        if(s->h==NULL)
            s->h=s->t=nw;
        else
        {s->t->next=nw;
         s->t=nw;
        }
    }
    system("pause");
}
void computeother(struct student *s) //based on the information given about the courses this function calculates the CGPA
{                                    //of each student
int st=s->semester;
struct courses *temp=s->h;
float g=0;
while(temp!=NULL&&temp->sem<=st)
{
    if(temp->sem==st)
    {
        switch(temp->grade)
        {
        case 'S':
            {g=g+temp->cred*10;
                break;}
        case 'A':
            {g=g+temp->cred*9;
                break;}
        case 'B':
            {g=g+temp->cred*8;
                break;}
        case 'C':
            {g=g+temp->cred*7;
                break;}
        case 'D':
            {g=g+temp->cred*6;
                break;}
        case 'E':
            {g=g+temp->cred*5;
                break;}
        case 'F':
            {break;}
        case 'N':
            {
                cout<<s->name<<" failed to appear for the examination for course "<<temp->code<<" and hence cannot be evaluated!\n";
                break;
            }
        }
    }
    temp=temp->next;
}
g=g/s->curcred;
s->credpersem[st-1]=s->curcred;
s->gpa[st-1]=g;
s->cgpa=0;
for(int i=0;i<st;i++)
    s->cgpa=s->cgpa+(s->gpa[i])*(s->credpersem[i]);
s->cgpa=s->cgpa/s->credcomp;
}
void checkroll(char r[],struct student *n) //checks the validity of the registration number entered by the user
{
    int f;
    struct student *t;
    while(1)
    {
    f=1;
    t=head;
    if(strlen(n->regno)!=9)
        {
        cout<<endl<<"Incorrect Length!\nEnter again: ";
            cin>>n->regno;
            f=0;
        }

    while(t!=NULL)
    {
        if(strcmp(t->regno,n->regno)==0)
        {
            cout<<endl<<"This Registeration number is already Present\nEnter again: ";
            cin>>n->regno;
            f=0;
            break;
        }
        t=t->nt;
    }
    if(f==1)
    {
        int c=1;
    for(int i=0;i<8;i++)
    {
     if(i==2||i==3||i==4)
     {
         if(isalpha(char(r[i])))
            continue;
         else
         {
             c=0;
             break;
         }
     }
     else
     {
         if(isdigit(int(r[i])))
            continue;
         else
         {
             c=0;
             break;
         }
     }
    }
    if(c==1)
        {
            r[2]=toupper(char(r[2]));
            r[3]=toupper(char(r[3]));
            r[4]=toupper(char(r[4]));
            break;
        }
    else
        {
            cout<<"Incorrect Format!\nEnter Again: ";
            cin>>r;
        }

    }
    }

}
void check(char r[])
  {
    int c=1;
    while(1)
    {
    c=1;
    for(int i=0;i<8;i++)
    {
     if(i==2||i==3||i==4)
     {
         if(isalpha(char(r[i])))
            continue;
         else
         {
             c=0;
             break;
         }
     }
     else
     {
         if(isdigit(int(r[i])))
            continue;
         else
         {
             c=0;
             break;
         }
     }
    }
    if(c==1)
        {
            r[2]=toupper(char(r[2]));
            r[3]=toupper(char(r[3]));
            r[4]=toupper(char(r[4]));
            break;
        }
    else
        {
            cout<<"Incorrect Format!\nEnter Again: ";
            cin>>r;
        }
  }
  }
  void checkcourse(char r[],struct courses *h,struct courses *H,int co) //checks the validity of course code entered by the user
{
    int f;
    struct courses *t;
    while(1)
    {
    f=1;
    if(strlen(r)!=7)
        {
        cout<<endl<<"Incorrect Length!\nEnter again: ";
            cin>>r;
            f=0;
        }
    if(f==1)
    {
        int c=1;
    for(int i=0;i<7;i++)
    {
     if(i<3)
     {
         if(isalpha(char(r[i])))
            continue;
         else
         {
             c=0;
             break;
         }
     }
     else
     {
         if(isdigit(int(r[i])))
            continue;
         else
         {
             c=0;
             break;
         }
     }
    }
    if(c==1)
        {
            r[0]=toupper(char(r[0]));
            r[1]=toupper(char(r[1]));
            r[2]=toupper(char(r[2]));
            c=2;
        }
    else
        {
            cout<<"Incorrect Format!\nEnter Again: ";
            cin>>r;
        }

        if(co)
        {t=H;
         while(t!=NULL)
    {
        if(strcmp(t->code,h->code)==0)
        {
            cout<<endl<<"This Course has already been taken!\nEnter again: ";
            cin>>h->code;
            f=0;
            break;
        }
        t=t->next;
    }
        }
    if(f==1&&c==2)
    break;
    }
    }
}

