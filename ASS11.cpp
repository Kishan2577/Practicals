#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void add()
{
    int id;
    string name,phone, address;
    cout<<"ENTER THE ID"<<endl;
    cin>>id;
    cout<<"ENTER THE NAME"<<endl;
    cin.ignore();
    getline(cin,name);
    cout<<"ENTER THE PHONE"<<endl;
    getline(cin,phone);
    cout<<"ENTER THE ADDRESS"<<endl;
    getline(cin,address);
    
    ofstream f1("members.txt",ios::app);
    if(f1.is_open())
    {
        cout<<" "<<name<<endl;
        f1 << id <<" "<< name <<" "<< phone <<" "<<address<<endl;
        cout<<"MEMBER ADDED SUCCESSFULLY"<<endl;
        f1.close();
    }
    else{
        cout<<"UNABLE TO ADD MEMBER"<<endl;
    }

}                                           

void search()
{
    int searchID,ID;
    string name,phone,address;
    cout << "Enter Member ID to search: ";
    cin >> searchID;

    ifstream inFile("members.txt");
    if (inFile.is_open()) {
        bool found = false;
        while (inFile >> ID >> name >> phone >> address) {
            if (ID == searchID) {
                cout << "Member found:\n";
                cout << "ID: " << ID << ", Name: " << name << ", Phone: " << phone << ", Email: " << address << '\n';
                found = true;
                break;
            }
        }
        if (!found)
            cout << "Member not found.\n";
        inFile.close();
    } else {
        cout << "Error: Unable to open file.\n";
    }
    // int id1,id2;
    // bool flag=false;
    // string name,phone, address;
    // cout<<"ENTER THE ID TO SEARCH"<<endl;
    // cin>>id1;
    // ifstream f2("members.txt");
    // if(f2.is_open())
    // {
    // while(f2 >> id2 >> name >> phone >> address)
    // {
    //     if(id1 == id2)
    //     {
    //         cout<<"DATA =  "<<id1<<name<<phone<<address<<endl;
    //         flag = true;
    //     }
    // }
    // if(!flag)
    // {
    //     cout<<"DATA NOT FOUND"<<endl;
    // }
    // f2.close();
    // }
}

void deleteData()
{
    int searchID,ID;
    string name,phone,address;
    cout << "Enter Member ID to search: ";
    cin >> searchID;

    ifstream inFile("members.txt");
    ofstream outFile("temp.txt",ios::app);
    if (inFile.is_open()) {
        
        while (inFile >> ID >> name >> phone >> address) {
            if (ID != searchID) 
            {
                outFile << ID <<" "<< name <<" "<< phone <<" "<<address<<endl;
            }
        }
    } else {
        cout << "Error: Unable to open file.\n";
    }
    inFile.close();
    outFile.close();
    remove("members.txt");
    rename("temp.txt","members.txt");
}

int main()
{
    int choose,i=0;
    while(i==0)
    {
        cout<<"1) ADD MEMBER"<<endl;
        cout<<"2) SEARCH MEMBER"<<endl;
        cout<<"3) DELETE MEMBER"<<endl;
        cout<<"4) UPDATE MEMBER"<<endl;
        cout<<"5) EXIT"<<endl;
        cin>>choose;
        switch(choose)
        {
            case 1:
                    add();
                    break;

            case 2:
                    search();
                    break;

            case 3:
                    deleteData();
                    break;

            case 4:
                    break;

            case 5: i=1;
                    break;                                
        }
    }
}