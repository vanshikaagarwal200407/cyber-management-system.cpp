#include<iostream>
#include<fstream>
using namespace std;

//global variables
const int MAX=100;
int total_threats=0;
int threat_id[100]; 
string threat_name[100];
string threat_type[100];
string severity[100];
string status[100];


void savethreats(){
    ofstream file("threats.txt");
    file<<total_threats<<endl;
    for(int i=0;i<total_threats;i++){
        file<<threat_id[i]<<endl;
        file<<threat_name[i]<<endl;
        file<<threat_type[i]<<endl;
        file<<severity[i]<<endl; 
        file<<status[i]<<endl;
    }
    file.close();
}

void loadThreats(){
    ifstream file("threats.txt");
    if(!file){
        return;
    }
    file>>total_threats;
    file.ignore();
    
    for(int i=0;i<total_threats;i++){
        file>>threat_id[i];
        file.ignore();
        getline(file,threat_name[i]);
        getline(file,threat_type[i]);
        getline(file,severity[i]);
        getline(file,status[i]);
    }
     file.close();
}

void addThreat(){
int n;
    cout<<"enter the number of threats you want to add: "<<endl;
    cin>>n;
    if(total_threats+n>MAX){
        cout<<"error! maximum limit of threats reached.\n";
    }
    else{
        for(int i=1;i<=n;i++){
            cout<<"enter the threat id "<<threat_id[i]<<endl;
            cin>>threat_id[total_threats];
            cin.ignore();
            cout<<"enter the threat name:"<<threat_name[i]<<endl;
            getline(cin,threat_name[total_threats]);
            cout<<"enter the threat type:"<<threat_type[i]<<endl;
            getline(cin,threat_type[total_threats]);
            cout<<"enter the threat severity:"<<severity[i]<<endl;
            getline(cin,severity[total_threats]);
            cout<<"enter the threat status:"<<status[i]<<endl;
            getline(cin,status[total_threats]);
            total_threats++;
        }
        cout<<"the threat has been added successfully\n";
    }
    
    savethreats();
}


void viewThreat(){
    cout<<"==========View all threats=========="<<endl;
    if(total_threats==0){
        cout<<"no threats found!\n";
    }
    else{
        for(int i=0;i<total_threats;i++){
            cout<<"threat id: "<<threat_id[i]<<endl;
            cout<<"threat name: "<<threat_name[i]<<endl;
            cout<<"threat type: "<<threat_type[i]<<endl;
            cout<<"threat severity: "<<severity[i]<<endl;
            cout<<"threat status: "<<status[i]<<endl;
        }
    }
}


void searchThreat(){
    int id;
    bool found=false;
    cout<<"==========Search Threats=========="<<endl;
    cout<<"enter the threat id to search: "<<endl;
    cin>>id;
    if(total_threats==0){
        cout<<"no threats to search!\n";
    }
    for(int i=0;i<total_threats;i++){
        if(id==threat_id[i]){
            found=true;
            cout<<"the information of the threat is as follows:\n";
            cout<<"threat id: "<<threat_id[i]<<endl;
            cout<<"threat name: "<<threat_name[i]<<endl;
            cout<<"threat type: "<<threat_type[i]<<endl;
            cout<<"threat severity: "<<severity[i]<<endl;
            cout<<"threat status: "<<status[i]<<endl;
        }
    }
        if(!found){
            cout<<"no threat found with the given id\n";
    }
}


void updateThreat(){
    int id;
    bool found=false;
    cout<<"enter the threat id to update: "<<endl;
    cin>>id;
    if(total_threats==0){
        cout<<"no threats to search!\n";
    }
    for(int i=0;i<total_threats;i++){
        if(id==threat_id[i]){
            found=true;
            cin.ignore();
           cout<<"enter the new threat name:"<<threat_name[i]<<endl;
            getline(cin,threat_name[i]);
            cout<<"enter the threat type:"<<threat_type[i]<<endl;
            getline(cin,threat_type[i]);
            cout<<"enter the new threat severity:"<<severity[i]<<endl;
            getline(cin,severity[i]);
            cout<<"enter the new threat status:"<<status[i]<<endl;
            getline(cin,status[i]);
        }
    }
        if(!found){
            cout<<"no id found with the given threats\n";
    }
savethreats();
}


void deleteThreat(){
    int id;
    bool found=false;
    cout<<"enter the threat id to delete: "<<endl;
    cin>>id;
    if(total_threats==0){
        cout<<"no threats to search!\n";
    }
    for(int i=0;i<total_threats;i++){
        if(id==threat_id[i]){
            found=true;
            for(int j=i;j<total_threats-1;j++){
            threat_id[j]=threat_id[j+1];
            threat_name[j]=threat_name[j+1];
            threat_type[j]=threat_type[j+1];
            severity[j]=severity[j+1];
            status[j]=status[j+1];
            }
            break;
            }
    }
    if(!found){
        cout<<"no threat found with the given id\n";
    }
    else{
        total_threats--;
        cout<<"the threat has been deleted successfully!\n";
    }
    savethreats();
}


void generateReport(){
    int high=0,medium=0,low=0; //severity
    int resolved=0,unresolved=0; //status

    if(total_threats==0){
        cout<<"no threats to search!\n";
    }
    for(int i=0;i<total_threats;i++){
        if(severity[i]=="high"||severity[i]=="HIGH"){
           high++;
        }
         else if(severity[i]=="medium"||severity[i]=="MEDIUM"){
           medium++;
        }
         else if(severity[i]=="low"||severity[i]=="LOW"){
           low++;
        }
          if(status[i]=="resolved"){
        resolved++;
        }
           else{
        unresolved++;
        }
    }
    cout << "-- Severity breakdown --\n";
    cout << "High: " << high << endl;
    cout <<"Medium: " << medium ;
    cout << " Low: " << low << endl;
    cout << "-- Status breakdown --\n";
    cout << "Resolved: " << resolved << endl;
    cout << "Unresolved: " << unresolved << endl;
}

int menuDriven(){
    int option;
    cout<<"1. Add threat\n";
    cout<<"2. View all threats\n";
    cout<<"3. search threats\n";
    cout<<"4. update threat status\n";
    cout<<"5. delete threat\n";
    cout<<"6. generate report\n";
    cout<<"7. exit\n";
    cout<<"enter the option to perform the operation: "<<endl;
    cin>>option;
    if(option<1||option>7){
        cout<<"invalid option! please try again\n";
    }
    return option;
}


int main(){
    loadThreats();
    int option,attempt=0;
    string user_name,password;
    bool is_logged_in=false;

   cout<<"=====CYBER MANAGEMENT SYSTEM======"<<endl;
   while(attempt<3){
   cout<<"enter your username: "<<endl;
   cin>>user_name;
   cout<<"enter your password: "<<endl;
   cin>>password;

   if(user_name== "Cyber" && password== "Cyber20"){
    cout<<"login successful\n";
    is_logged_in=true;
       break;
   } 
     else{
    attempt++;
    cout<<"invalid username or password! please try again\n";
   }
   
}
    if(attempt>=3){
        cout<<"maximum number of attempts reached.exiting the programme.\n";
        return 0;
   }
   do{
    option=menuDriven();
    switch(option){
        case 1:
        addThreat();
        break;
        case 2:
        viewThreat();
        break;
        case 3:
        searchThreat();
        break;
        case 4:
        updateThreat();
        break;
        case 5:
        deleteThreat();
        break;
        case 6:
        generateReport();
        break;
        case 7:
        cout<<"thank you for using the cyber management system!\n";
        break;
        default:
        cout<<"invalid option! please try again\n";
    }
   }while(option!=7);

    return 0;
}
