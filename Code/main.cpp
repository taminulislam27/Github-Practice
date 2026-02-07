#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<limits>
using namespace std;

struct Student {
    string roll, name, fname, address;
    string blood, donor, phone, tshirt, active;
};

class temp{
    string rollNum,name,fName,address,search;
    string blood, donor, phone, tshirt, active;
    fstream file;
public:
    void addStu();
    void viewStu();
    void searchStu();
    void deleteStu();
    void editStu();
}obj;

/* ================= MAIN ================= */
int main(){
    while(true){
        char choice;
        cout<<"\n---------------------------\n";
        cout<<"1- Add Student Record\n";
        cout<<"2- Edit Student Record\n";
        cout<<"3- View All Student Record\n";
        cout<<"4- Search Student Record\n";
        cout<<"5- Delete Student Record\n";
        cout<<"6- Exit\n";
        cout<<"---------------------------\n";
        cout<<"Enter choice: ";
        cin>>choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch(choice){
            case '1': obj.addStu(); break;
            case '2': obj.editStu(); break;
            case '3': obj.viewStu(); break;
            case '4': obj.searchStu(); break;
            case '5': obj.deleteStu(); break;
            case '6': cout<<"Exiting...\n"; return 0;
            default: cout<<"Invalid Choice...!\n";
        }
    }
}

/* ================= ADD ================= */
void temp::addStu(){
    cout<<"\n--- Add Student ---\n";
    cout<<"Roll :: "; getline(cin,rollNum);
    cout<<"Name :: "; getline(cin,name);
    cout<<"Father Name :: "; getline(cin,fName);
    cout<<"Address :: "; getline(cin,address);
    cout<<"Blood Group :: "; getline(cin,blood);
    cout<<"Donor (Yes/No) :: "; getline(cin,donor);
    cout<<"Phone :: "; getline(cin,phone);
    cout<<"T-Shirt Size :: "; getline(cin,tshirt);
    cout<<"Active (Yes/No) :: "; getline(cin,active);

    file.open("stuData.txt", ios::out | ios::app);
    file<<rollNum<<"*"<<name<<"*"<<fName<<"*"<<address<<"*"
        <<blood<<"*"<<donor<<"*"<<phone<<"*"
        <<tshirt<<"*"<<active<<endl;
    file.close();

    cout<<"Student Added Successfully!\n";
}

/* ================= VIEW ================= */
void temp::viewStu(){
    vector<Student> students;
    Student s;

    file.open("stuData.txt", ios::in);
    if(!file){
        cout<<"No record found!\n";
        return;
    }

    while(getline(file,s.roll,'*')){
        getline(file,s.name,'*');
        getline(file,s.fname,'*');
        getline(file,s.address,'*');
        getline(file,s.blood,'*');
        getline(file,s.donor,'*');
        getline(file,s.phone,'*');
        getline(file,s.tshirt,'*');
        getline(file,s.active);
        students.push_back(s);
    }
    file.close();

    sort(students.begin(), students.end(),
        [](Student a, Student b){ return a.roll < b.roll; });

    cout<<"\n";
    cout<<left
        <<setw(6)<<"Roll"<<setw(16)<<"Name"<<setw(16)<<"Father"
        <<setw(18)<<"Address"<<setw(8)<<"Blood"
        <<setw(8)<<"Donor"<<setw(15)<<"Phone"
        <<setw(8)<<"TShirt"<<setw(8)<<"Active"<<endl;
    cout<<string(102,'-')<<endl;

    for(auto &st:students){
        cout<<left
            <<setw(6)<<st.roll<<setw(16)<<st.name
            <<setw(16)<<st.fname<<setw(18)<<st.address
            <<setw(8)<<st.blood<<setw(8)<<st.donor
            <<setw(15)<<st.phone<<setw(8)<<st.tshirt
            <<setw(8)<<st.active<<endl;
    }
}

/* ================= SEARCH ================= */
void temp::searchStu(){
    cout<<"\nEnter Roll to Search :: ";
    getline(cin,search);

    file.open("stuData.txt", ios::in);
    bool found=false;

    while(getline(file,rollNum,'*')){
        getline(file,name,'*');
        getline(file,fName,'*');
        getline(file,address,'*');
        getline(file,blood,'*');
        getline(file,donor,'*');
        getline(file,phone,'*');
        getline(file,tshirt,'*');
        getline(file,active);

        if(rollNum==search){
            found=true;
            cout<<"\nStudent Found\n";
            cout<<"Name: "<<name<<"\nFather: "<<fName
                <<"\nAddress: "<<address
                <<"\nBlood: "<<blood
                <<"\nDonor: "<<donor
                <<"\nPhone: "<<phone
                <<"\nTShirt: "<<tshirt
                <<"\nActive: "<<active<<endl;
            break;
        }
    }
    file.close();

    if(!found) cout<<"Record Not Found!\n";
}

/* ================= DELETE ================= */
void temp::deleteStu(){
    string roll;
    cout<<"\nEnter Roll to Delete :: ";
    getline(cin,roll);

    ifstream fin("stuData.txt");
    ofstream fout("temp.txt");
    bool found=false;

    while(getline(fin,rollNum,'*')){
        getline(fin,name,'*');
        getline(fin,fName,'*');
        getline(fin,address,'*');
        getline(fin,blood,'*');
        getline(fin,donor,'*');
        getline(fin,phone,'*');
        getline(fin,tshirt,'*');
        getline(fin,active);

        if(rollNum==roll){
            found=true;
        } else {
            fout<<rollNum<<"*"<<name<<"*"<<fName<<"*"<<address<<"*"
                <<blood<<"*"<<donor<<"*"<<phone<<"*"
                <<tshirt<<"*"<<active<<endl;
        }
    }

    fin.close(); fout.close();
    remove("stuData.txt");
    rename("temp.txt","stuData.txt");

    cout<<(found?"Record Deleted Successfully!\n":"Record Not Found!\n");
}

/* ================= EDIT ================= */
void temp::editStu(){
    string roll;
    cout<<"\nEnter Roll to Edit :: ";
    getline(cin,roll);

    ifstream fin("stuData.txt");
    ofstream fout("temp.txt");
    bool found=false;

    while(getline(fin,rollNum,'*')){
        getline(fin,name,'*');
        getline(fin,fName,'*');
        getline(fin,address,'*');
        getline(fin,blood,'*');
        getline(fin,donor,'*');
        getline(fin,phone,'*');
        getline(fin,tshirt,'*');
        getline(fin,active);

        if(rollNum==roll){
            found=true;
            cout<<"New Name :: "; getline(cin,name);
            cout<<"New Father :: "; getline(cin,fName);
            cout<<"New Address :: "; getline(cin,address);
            cout<<"Blood :: "; getline(cin,blood);
            cout<<"Donor :: "; getline(cin,donor);
            cout<<"Phone :: "; getline(cin,phone);
            cout<<"TShirt :: "; getline(cin,tshirt);
            cout<<"Active :: "; getline(cin,active);
        }

        fout<<rollNum<<"*"<<name<<"*"<<fName<<"*"<<address<<"*"
            <<blood<<"*"<<donor<<"*"<<phone<<"*"
            <<tshirt<<"*"<<active<<endl;
    }

    fin.close(); fout.close();
    remove("stuData.txt");
    rename("temp.txt","stuData.txt");

    cout<<(found?"Record Updated Successfully!\n":"Record Not Found!\n");
}
