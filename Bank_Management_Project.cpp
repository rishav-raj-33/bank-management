#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<fstream>
#include<vector>
using namespace std;
void login_screenb();
void open_account(ofstream &write,ifstream &read);
void account_holder_list(ifstream &read);
void existing_holder(ifstream &read);
 void search(ifstream &read,string accno);
 void Balance_Enquiry(ifstream &read);
 void deposite(ifstream &read,ofstream &write);
 void close_account(ifstream &read,ofstream &write);
 void WithDrawal(ifstream &read,ofstream &write);  
 void Modify_an_account(ifstream &read,ofstream &write);
 void Name(ifstream &read,ofstream &write,int line_no_name);
 void Address(ifstream &read,ofstream &write,int line_no_name);
string name, address,accno;
    int bb,flag=0;
    char type;
int main(){
    system("cls");
 login_screenb();
 ofstream w;
 ifstream r;
  int k = 0;
    while (k <= 9)
    {
        system("cls");

        cout << "Main Menu" << endl;
        cout << "\t1.New Account" << endl;
        cout << "\t2.Deposit Amount" << endl;
        cout << "\t3.WithDraw Amount" << endl;
        cout << "\t4.Indiviual Details of existing card Holder" << endl;
        cout << "\t5.All Account Holder List" << endl;
        cout << "\t6.Close An Account" << endl;
        cout << "\t7.Modify An Account" << endl;
        cout << "\t8.Balance Enquiry" << endl;
        cout << "\t9.Exit" << endl;
        cout << "Enter your work(1 to 9)" << endl;
       cin >> k;
        switch(k){
            case 1: 
            system("cls");
            open_account(w,r);
            break;
            case 2:
                   system("cls");
                   deposite(r,w);
                   break;
             case 3: system("cls");
                    WithDrawal(r,w);
                     break;      
            case 4: system("cls");
            existing_holder(r);
                    break;
            case 5:
            system("cls");
            account_holder_list(r);
                      break;
            case 6: 
                   system("cls");
                   close_account(r,w);
                    break;
             case 7:
                    system("cls");
                           
                     Modify_an_account(r,w);
                     break;
            case 8: system("cls");
                  Balance_Enquiry(r);
                  break;
            case 9: return 0;
            default:
            cout<<"Invalid Code"<<endl;
            getch();
         }

    }
    main();

}
//========================================================
void login_screenb()
{
    string realid = "Rudra";
    string pass = "Ansh";
    string user_id, password;
    while (1)
    {
        cout << "\n";
        cout << "\t \t \t  \t \t --------x-x------x-x-----------" << endl;
        cout << "\n";
        cout << "\t  \t \t \t \t    Login for RudrAnsh Bank" << endl;
        cout << "\n";
        cout << "\t \t \t \t \t  --------x-x------x-x-----------" << endl;
        cout << "\n \n \n \n";
        cout << "\t \t \t \t USER ID:->";
        cin >> user_id;
        cout << "\t \t \t \t Password:->";
        cin >> password;
        if (user_id.compare(realid) == 0 && password.compare(pass) == 0)
        {
            cout << "\n \n "
                 << "Login SUCCESSFUL...." << endl;
            cout << "\n Press Enter...";
            getch();
            return;
        }
        else
        {
            cout << "User Id or Password is Incorrect.Please try again" << endl;
            cout << "\n Press Enter";
            getch();
            system("cls");
        }
    }
}
//=============================================================
void open_account(ofstream &write,ifstream &read){
    cout << "Fill the form of the customer below:-" << endl;
    cout << "\n";
    cout << "Enter the Account Number of the Customer" << endl;
    cin >> accno;
    search(read,accno);
    if(flag==0){
        write.open("Bank.txt",ios::app);
    write<<"Account No:-"<<accno<<"\n";
    cout << "Enter the Name of Customer" << endl;
    cin.ignore();
    getline(cin, name,'\n');
    write<<"Name:-"<<name<<"\n";
    cout << "Enter address of Customer" << endl;
    getline(cin, address,'\n');
    write<<"Address:-"<<address<<"\n";
    cout << "Enter the type of account (s or c)" << endl;
    cin >> type;
    write<<"Account Type:-"<<"\t"<<type<<"\n";
    cout << "Enter the Amount of deposite" << endl;
    cin >> bb;
    write<<"Bank Balance:-"<<bb<<"\n";
    write<<"==============================================================="<<endl;
    write.close();
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "Account Created....." << endl;
    getch();
    }
     else{
      system("cls");
        cout<<"Account Existed"<<endl;
        getch();
    }
    flag=0;
}
void account_holder_list(ifstream &read){
    string st;
  read.open("Bank.txt");
  if(read.fail()){
    system("cls");
    cout<<"Error Occured"<<endl;
    getch();
    return;
  }
    while(!read.eof()){
        getline(read,st);
      cout<<st<<endl;
     
    }
     getch();
    read.close();

}
//=======================================================
void existing_holder(ifstream &read){
    string acc;
    string line;
 cout<<"Enter Account No."<<endl;
 cin>>acc;
 system("cls");
   string check="Account No:-"+acc;
 read.open("Bank.txt",ios::in);
 if(read.fail()){
  system("cls");
    cout<<"Error Occured"<<endl;
    getch();
    return;
  }
 while(!read.eof()){
    getline(read,line);
    if(line==check){
        cout<<line<<endl;
        for(int i=0;i<=3;i++){
            getline(read,line);
            cout<<line<<endl;
        }
        getch();
        read.close();
        return;
    }
 }
    cout<<"Not Found"<<endl;
 read.close();
 getch();
 

}
//========================================================
void Balance_Enquiry(ifstream &read){
    string a;
    cout<<"Enter Account no."<<endl;
    cin>>a;
    string check="Account No:-"+a;
    string line;
     read.open("Bank.txt");
     if(read.fail()){
      system("cls");
    cout<<"Error Occured"<<endl;
    getch();
    return;
  }
    while(!read.eof()){
    getline(read,line);
    if(line==check){
    for(int i=0;i<=3;i++){
        getline(read,line);
        if(i==3){
            system("cls");
            cout<<line<<endl;
            getch();
            read.close();
            return;
        }
    }
    getch();
    
     }
    }
    system("cls");
      cout<<"Not Found"<<endl;
     getch();
      read.close();
}
//========================================================
void deposite(ifstream &read,ofstream &write){
  string acd;
  int a,b,sum,line=0;
  string substring;
  vector<string> g;
 cout<<"Enter Account No."<<endl;
 cin>>acd;
 string check="Account No:-"+acd;
 string j;
 read.open("Bank.txt");
 if(read.fail()){
  system("cls");
  cout<<"Error Occured"<<endl;
  getch();
  return;
 }
  while(!read.eof()){
   line++;
 getline(read,j);
 if(check==j){
  for(int i=0;i<=3;i++){
    getline(read,j);
    if(i==3){
     read.close();
     substring=j.substr(14,j.length());
     a=stoi(substring);
     cout<<"Enter Amount you want to deposite"<<endl;
     cin>>b;
     sum=b+a;
     substring=to_string(sum);
     string text="Bank Balance:-"+substring;
     read.open("Bank.txt");
     if(read.fail()){
      system("cls");
  cout<<"Error Occured"<<endl;
  getch();
  return;
 }
   while(getline(read,j))
   g.push_back(j);
   read.close();
  write.open("Bank.txt");
  line=line+3;
 for(int j=0;j < g.size(); j++){
 if(j!=line){
  write<<g[j]<<endl;
   } else{
  write<<text<<endl;
  }
 }
 write.close();
 cout<<".";
 cout<<"..";
 cout<<"...";
 cout<<"....";
  cout<<"Deposite Successful"<<endl;
  getch();
 return;

 }   
    }

  }
 }
 system("cls");
   cout<<"Not Found"<<endl;
   read.close();
   getch();
}
void close_account(ifstream &read,ofstream &write){
 string account_number;
 int line_no=0;
  int a=0;
  vector<string> k;
  cout<<"Enter Account Number to close"<<endl;
  cin>>account_number;
  string check="Account No:-"+account_number;
  string l;
  read.open("Bank.txt");
  if(read.fail()){
    system("cls");
   cout<<"Error Occured"<<endl;
   getch();
   return;
   }
   while(!read.eof()){
   line_no++;
   getline(read,l);
   if(check==l){
    a=1;
   break; 
  }
  }
   read.close();
   if(a==0){
   system("cls");
   cout<<"Not Found"<<endl;
   getch();
   return;
   }
   read.open("Bank.txt");
   while(getline(read,l)){
      k.push_back(l);
    }
    read.close();
    
    write.open("Bank.txt");
    line_no=line_no-1;
    int n=line_no+5;
     for(int i=0;i<k.size();i++){
      if(i>=line_no&&i<=n){
        continue;
       }

      write<<k[i]<<endl;
       }
       system("cls");
      cout<<"."<<endl;
      cout<<".."<<endl;
      cout<<"..."<<endl;
      cout<<"Closed Successful"<<endl;
      write.close();
      getch();
}
//=======================================================
void WithDrawal(ifstream &read,ofstream &write){
 string acw;
  int a,b,difference,line=0;
  string substring;
  vector<string> g;
 cout<<"Enter Account No."<<endl;
 cin>>acw;
 string check="Account No:-"+acw;
 string j;
 read.open("Bank.txt");
 if(read.fail()){
  system("cls");
  cout<<"Error Occured"<<endl;
  getch();
  return;
 }
  while(!read.eof()){
   line++;
 getline(read,j);
 if(check==j){
  for(int i=0;i<=3;i++){
    getline(read,j);
    if(i==3){
     read.close();
     substring=j.substr(14,j.length());
     a=stoi(substring);
     cout<<"Enter Amount you want to Withdraw"<<endl;
     cin>>b;
     if(b>a||a==0){
      system("cls");
      cout<<"Insufficient Balance"<<endl;
      getch();
      return;
     }
     difference=a-b;
     substring=to_string(difference);
     string text="Bank Balance:-"+substring;
     read.open("Bank.txt");
     if(read.fail()){
      system("cls");
  cout<<"Error Occured"<<endl;
  getch();
  return;
 }
   while(getline(read,j))
   g.push_back(j);
   read.close();
  write.open("Bank.txt");
  line=line+3;
 for(int j=0;j < g.size(); j++){
 if(j!=line){
  write<<g[j]<<endl;
   } else{
  write<<text<<endl;
  }
 }
 cout<<"."<<endl;
 cout<<".."<<endl;
 cout<<"..."<<endl;
 cout<<"Withdraw Successful"<<endl;
 write.close();
 getch();
 return;
    }
  }
 }
  }
  system("cls");
   cout<<"Not Found"<<endl;
   read.close();
   getch();
}
void Modify_an_account(ifstream &read,ofstream &write){
  int k,a=0,line_no_name=0;
  string bac;
  cout<<"Enter Account No"<<endl;
  cin>>bac;
  string check="Account No:-"+bac;
  string search;
  read.open("Bank.txt");
  if(read.fail()){
  system("cls");
  cout<<"Error Occured"<<endl;
  getch();
  return;
 }

 while(!read.eof()){
  line_no_name++;
  getline(read,search);
  if(search==check){
    a=1;
    break;
  }
 }
 if(a==0){
   read.close();
 system("cls");
   cout<<"Not Found"<<endl;
   getch();
   return;
 }
 read.close();
 cout<<"Update  Account"<<endl;
 cout<<"\t1.Update Name"<<endl;
 cout<<"\t2.Update Address"<<endl;
 cout<<"\t3.Exit"<<endl;
 cout<<"Enter Your Option"<<endl;
 cin>>k;
 switch(k){
  case 1: system("cls");
            Name(read,write,line_no_name);
            break;
  case 2: system("cls");
          Address(read,write,line_no_name);          
  case 3:  return;
           break;
   default: 
           cout<<"Invalid code"<<endl;
           getch();

 }
}



//======================================================================
void search(ifstream &read,string accno){
    string check="Account No:-"+accno;
    string line;
  read.open("Bank.txt");
  if(read.fail()){
    system("cls");
    cout<<"Error Occured"<<endl;
    getch();
    return;
  }
  while(!read.eof()){
    getline(read,line);
    if(line==check){
    flag=1;
  }
  }
    read.close();
}
void Name(ifstream &read,ofstream &write,int line_no_name){
 
 vector<string> name;
 string text;
 string search;

 cout<<"Enter New Name"<<endl;
 cin.ignore();
 getline(cin,text);
 string replace="Name:-"+text;
 read.open("Bank.txt");
 if(read.fail()){
  system("cls");
  cout<<"Error Occured"<<endl;
  getch();
  return;
 }
 while(getline(read,search))
 name.push_back(search);
 read.close();
 write.open("Bank.txt");
  for(int i=0;i<name.size();i++){
  if(i!=line_no_name){
    write<<name[i]<<endl;
  }else{
    write<<replace<<endl;
  }
  }
  cout<<"Updated........."<<endl;
 getch();
 write.close();
 return;


 
}
//=============================================================

void Address(ifstream &read,ofstream &write,int line_no_name){
  vector<string> Address;
 string text;
 string search;

 cout<<"Enter New Address"<<endl;
 getline(cin,text);
 string replace="Address:-"+text;
 read.open("Bank.txt");
 if(read.fail()){
  system("cls");
  cout<<"Error Occured"<<endl;
  getch();
  return;
 }
 while(getline(read,search))
 Address.push_back(search);
 read.close();
 write.open("Bank.txt");
 int line_no_address=line_no_name+1;
  for(int i=0;i<Address.size();i++){
  if(i!=line_no_address){
    write<<Address[i]<<endl;
  }else{
    write<<replace<<endl;
  }
  }
  cout<<"Updated........."<<endl;
 getch();
 write.close();
 return;

}

      
 




    

       
