
/* VINEETH KUMAR KORI
   1RN18EC173 - RNSIT
   Electronics and communication department
   1rn18ec173.vineethkumarkori@gmail.com
   Contact number:9742126300*/


// I have choosen question number 2: Reminder Application / Task Manager

#include<bits/stdc++.h>
using namespace std;

class TaskManager           //created a class Task manager
{
  int  current_date=6;
    int* time; // all the data is completely private,{keeping data privacy in mind}
   int top;
    int MAX;
    string* ts;


    public:
     TaskManager(int size){
        top = -1;
        MAX = size;
        time = new int [MAX];
        ts   = new string [MAX];
    }

    bool InsertTask(string s,int x);                //function declarations
    void display();
   void ModifyTask(int task_no,string s,int date);
   void reminder();



};


void TaskManager:: reminder()
{

 int i=0;
    if(top==-1){
        printf("NO tasks at present.So, no reminder\n");
        return;
    }

    for(i = top ; i >=0 ; i--)
    {
      cout<<"Task number:"<<i<<":"<<ts[i]<<"----"<<"reminder:"<<abs(time[i]-current_date)<<endl;
        if(time[i]-current_date>0){
                cout<<abs(time[i]-current_date)<<" days left to finish the task"<<endl;
                cout<<"....Iniating the call (via kaleyra)"<<endl;
                cout<<"call says: Some of your tasks are due.It's not good to procastinate\n\n"<<endl;


        }

         if(time[i]-current_date<0){
                cout<<"This tasks due date is already completed\n\n"<<endl;


        }
    }
}

 void TaskManager:: ModifyTask(int task_no,string s,int date)       //modify Task function definition
 {
      if(top==-1){
        printf("NO Tasks present in the Task Manager to Modify\n");
        return;
    }
    else
    {
        time[task_no]=date;
        ts[task_no]=s;
    }
 }


void TaskManager::display(){                           //display function definition

    int i=0;
    if(top==-1){
        printf("NO tasks at present  .\n");
        return;
    }

    for(i = top ; i >=0 ; i--)
    {
      cout<<"Task number:"<<i<<":"<<ts[i]<<"----"<<"date:"<<time[i]<<endl;

    }


}



bool TaskManager::InsertTask(string s,int x)            //Insert function definition
{
    if (top >= (MAX - 1)) {
        cout << "NO more size in the application to hold task";
        return false;
    }
    else {
        time[++top] = x;
        ts[top]=s;
        cout<<"Task no "<<top<<":"<<ts[top]<<"<----- This task has been added successfully"<<endl;

        return true;
    }
}





                            //main function
int main()
{

int t_n;
int choice=1;
string s;
cout << R"(

 __        __   _                            _          _  __     _                        ____                _           _                _                _ _           _   _
 \ \      / /__| | ___ ___  _ __ ___   ___  | |_ ___   | |/ /__ _| | ___ _   _ _ __ __ _  |  _ \ ___ _ __ ___ (_)_ __   __| | ___ _ __     / \   _ __  _ __ | (_) ___ __ _| |_(_) ___  _ __
  \ \ /\ / / _ \ |/ __/ _ \| '_ ` _ \ / _ \ | __/ _ \  | ' // _` | |/ _ \ | | | '__/ _` | | |_) / _ \ '_ ` _ \| | '_ \ / _` |/ _ \ '__|   / _ \ | '_ \| '_ \| | |/ __/ _` | __| |/ _ \| '_ \
   \ V  V /  __/ | (_| (_) | | | | | |  __/ | || (_) | | . \ (_| | |  __/ |_| | | | (_| | |  _ <  __/ | | | | | | | | | (_| |  __/ |     / ___ \| |_) | |_) | | | (_| (_| | |_| | (_) | | | |
    \_/\_/ \___|_|\___\___/|_| |_| |_|\___|  \__\___/  |_|\_\__,_|_|\___|\__, |_|  \__,_| |_| \_\___|_| |_| |_|_|_| |_|\__,_|\___|_|    /_/   \_\ .__/| .__/|_|_|\___\__,_|\__|_|\___/|_| |_|
                                                                         |___/                                                                  |_|   |_|

)" << '\n';

int size;
int m_t;
int t_d;
cout<<"Enter the number of tasks ,the Kaleyra Reminder Application can hold"<<endl;
cin>>size;
TaskManager t(size);



while(choice)//while loop to keep the interaction with the user alive
{
cout<<"\nEnter your choice:"<<endl;
cout << R"(
            SELECT 0: To close the Application
            SELECT 1: To Add a TASK(Note: Please mention date)
            SELECT 2: To modify the TASK
            SELECT 3: To display the  TASK
            SELECT 4: To display the  Reminders

)" << '\n';
cin>>choice;

switch(choice)                          //using a switch case to find the choice
{



    case 0: cout<<"End of the application"<<endl;
            break;
    case 1: {
                cout<<"Enter the date"<<endl;
                cin>>t_d;
               cout<<"Enter the task to be added"<<endl;
               cin.ignore();
               getline(cin,s);

                t.InsertTask(s,t_d);
            break;}
    case 2:{
                cout<<"you can display all the tasks once to find the task number:(Enter 1 to display the tasks along with the task number and Enter 0 to continue"<<endl;
                cin>>m_t;
                if(m_t)
                    t.display();
                cout<<"Enter the task number"<<endl;
                cin>>t_n;
                cout<<"Enter the date"<<endl;
                cin>>t_d;
               cout<<"Enter the task to be added"<<endl;
               cin.ignore();
               getline(cin,s);

                t.ModifyTask(t_n,s,t_d);
            break;}
    case 3: t.display();
            break;
    case 4:t.reminder();
            break;
    default:cout<<"You have not selected any of the options mentioned above,\n Thank You for using Kaleyra Task manager"<<endl;
            choice=0;
}

}




return 0;
}
