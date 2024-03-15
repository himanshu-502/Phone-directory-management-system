#include<iostream>
#include<fstream>
#include <sstream>
#include<conio.h>
#include<unistd.h>
//#include<windows.h>
#include<bits/stdc++.h>
using namespace std;

//if running on codeblocks, please replace   system("clear");   with   system("cls");

struct Node{
	string name;
	string phone_number;
	string address;
	Node *next;
	Node *prev;

	Node(){
	    next=NULL;
	    prev=NULL;
	}
};

struct admin{
    string userid;
    string pwd;
    admin *next;
    admin *prev;

    admin(){
        next=NULL;
        prev=NULL;
    }
};

class ContactBook{
	Node *head;
	string x;
	string y;
	string room;
	int totalcon=0;
	int namelength=4;
    int roomlength=4;
	admin *user;
	string curuserid;
    int useridlen=6;
    int passwordlen=8;
    string us;
	string p;
	public:
		ContactBook() {
			head=NULL;
			x="";
			y="";
			room="";
			user=NULL;
			us="";
			p="";
			curuserid="";
		}


    	void Display(int num) {
	    	Node *temp=head;
	    	int count=0;

	    	if(temp==NULL) {
		    	cout<<"  No Contacts... Please Add Some Contacts"<<endl;
		    	cout<<"  Thanks"<<endl;
	    	}

	    	else {
	    		cout<<"Displaying contacts Information: \n\n";
	    		for(int i=20+roomlength+namelength;i>0;i--) cout<<"*";
	    		cout<<endl;
	    		cout<<"| Name ";
	    		for(int i=namelength-4;i>0;i--) cout<<" ";
	    		cout<<"| Number     | Room ";
	    		for(int i=roomlength-4;i>0;i--) cout<<" ";
	    		cout<<"|"<<endl;
	    		for(int i=20+roomlength+namelength;i>0;i--) cout<<"*";
	    		cout<<endl;
	        	while(temp!=NULL) {
	        	    count++;
	        	    string xx=temp->name;
	        	    for(int i=0;i<xx.size();i++){
                        if(i==0){ if(xx[0]>=97 && xx[0]<=122) xx[0]-=32; }
                        else if(xx[i-1]==' ' && xx[i]>=97 && xx[i]<=122) xx[i]-=32;
                    }
		        	cout<<"| "<<xx;
		        	for(int i=namelength-temp->name.size();i>0;i--) cout<<" ";

		        	cout<<" | "<<temp->phone_number;
		        	cout<<" | "<<temp->address;
		        	for(int i=roomlength-temp->address.size();i>0;i--) cout<<" ";
		        	cout<<" |"<<endl;
		        	for(int i=20+roomlength+namelength;i>0;i--) cout<<"*";
		        	cout<<endl;
    		    	temp=temp->next;
	        	}
	        	//for(int i=20+roomlength+namelength;i>0;i--) cout<<"*";
	        	cout<<endl<<endl<<"  Total contacts: "<<count<<endl<<endl;
	    	}
	    	if(num==0) {
	    	    cout<<endl<<"press enter to continue: ";
	    	    getchar();
	    	    system("clear");
	    	}
	    	else cout<<endl;
    	}

    	void displayuser(){
    	    admin *temp=user;
	    	int count=0;

	    	if(temp==NULL) {
		    	cout<<"  No Users... Please Add Some Users"<<endl;
		    	cout<<"  Thanks"<<endl;
	    	}

	    	else {
	    		cout<<"Displaying Users Information: \n\n";
	    		for(int i=7+useridlen+passwordlen;i>0;i--) cout<<"*";
	    		cout<<endl;
	    		cout<<"| Userid ";
	    		for(int i=useridlen-6;i>0;i--) cout<<" ";
	    		cout<<"| Password ";
	    		for(int i=passwordlen-8;i>0;i--) cout<<" ";
	    		cout<<"|"<<endl;
	    		for(int i=7+useridlen+passwordlen;i>0;i--) cout<<"*";
	    		cout<<endl;
	        	while(temp!=NULL) {
	        	    count++;
	        	    string xx=temp->userid;
		        	cout<<"| "<<xx;
		        	for(int i=useridlen-temp->userid.size();i>0;i--) cout<<" ";
	    		    cout<<" | "<<temp->pwd;
		        	for(int i=passwordlen-temp->pwd.size();i>0;i--) cout<<" ";
		        	cout<<" |"<<endl;
		        	for(int i=7+useridlen+passwordlen;i>0;i--) cout<<"*";
	    		    cout<<endl;
    		    	temp=temp->next;
	        	}
	        	//for(int i=20+roomlength+namelength;i>0;i--) cout<<"*";
	        	cout<<endl<<endl<<"  Total Users: "<<count<<endl<<endl;
	    	}
	    	    cout<<endl<<"press enter to continue: ";
	    	    getchar();
	    	    system("clear");
	    	}

    	string checknumber(string num){
    	    if(num[0]=='0') num.erase(0,1);
    	    else if(num[0]=='+' && num[1]=='9' && num[2]=='1') num.erase(0,3);
    	    if(num[4]==' ' || num[4]=='-') num.erase(4, 1);
    	    else if(num[5]==' ' || num[5]=='-') num.erase(5,1);
    	    if(num.size()!=10) return "no";
    	    for(int i=0;i<10;i++)  if(num[i]<'0' || num[i]>'9') return "no";
    	    return num;
    	}

    	int countdigit(int num){
    	    int temp=0;
    	    while(num!=0){
    	        temp++;
    	        num/=10;
    	    }
    	    return temp;
    	}

    	int Search(string na="", string ph="", string ro="") {
    		bool check=false;
	    	Node *temp=head;
	    	if(temp==NULL) {
		    	cout<<"  No Contacts to search..."<<endl;
		    	sleep(2);
		    	system("clear");
	    	    return 0;
	    	}
	    	int len=0;
	    	len=countdigit(totalcon);
	    	if(len<6) len=6;
	    	string command;
	    	if(na=="" && ph=="" && ro==""){
	    	    cout<<"**************************************************"<<endl;
	    	    cout<<"| Press 1 if you want to Search By Name.         |"<<endl;
	    	    cout<<"| Press 2 if you want to Search By PHone Number. |"<<endl;
	    	    cout<<"| Press 3 if you want to Search By Room Number   |"<<endl;
	    	    cout<<"**************************************************"<<endl<<endl;
	    	    cout<<"  Enter the Command: ";
	    	    getline(cin>>ws, command);
    	    }
    	    else if(na!="") command="1";
    	    else if(ph!="") command="2";
    	    else if(ro!="") command="3";
	    	if(command=="1") {
	    	    int flag=0;
	    		if(na=="") {
	    		    cout<<"  Enter the Name to Search: ";
	    		    getline(cin>>ws, x);
	    	    }
	    		else x=na;
	    		for(int i=0;i<x.size();i++){
	        	   if(x[i]>=65 && x[i]<=90) x[i]+=32;
	        	}
	        	cout.flush();
		    	while(temp!=NULL) {
		        	if(temp->name.find(x) != string::npos)	{

//		        	    for(int i=0;i<x.size();i++){
//	        	            if(x[i]>=65 && x[i]<=90) x[i]+=32;
//	        	        }

		        	    flag++;
		        	    if(flag==1){
		        	        cout<<"Displaying contacts Information: \n\n";
		        	        for(int i=23+len+roomlength+namelength;i>0;i--) cout<<"*";
		        	        cout<<endl;
		        	        cout<<"| Sr.No. ";
		        	        for(int i=len-6;i>0;i--)cout<<" ";
	    		            cout<<"| Name ";
	    		            for(int i=namelength-4;i>0;i--) cout<<" ";
	    		            cout<<"| Number     | Room ";
	    	    	        for(int i=roomlength-4;i>0;i--) cout<<" ";
	    	        	    cout<<"|"<<endl;
	    	        	    for(int i=23+len+roomlength+namelength;i>0;i--) cout<<"*";
		        	        cout<<endl;
	        		    }
	        		    string xx=temp->name;;
	        		    for(int i=0;i<xx.size();i++){
                            if(i==0){ if(xx[0]>=97 && xx[0]<=122) xx[0]-=32; }
                            else if(xx[i-1]==' ' && xx[i]>=97 && xx[i]<=122) xx[i]-=32;
                        }
                        cout<<"| "<<flag;
                        int tlen=countdigit(flag);
                        for(int i=len-tlen+1;i>0;i--) cout<<" ";
		        	    cout<<"| "<<xx;
		        	    for(int i=namelength-temp->name.size();i>0;i--) cout<<" ";
		        	    cout<<" | "<<temp->phone_number;
		        	    cout<<" | "<<temp->address;
		        	    for(int i=roomlength-temp->address.size();i>0;i--) cout<<" ";
		        	    cout<<" |"<<endl;
		        	    for(int i=23+len+roomlength+namelength;i>0;i--) cout<<"*";
		        	    cout<<endl;

		        	    check=true;

		        		//cout<<"*****"<<endl;
		        		//cout<<"  Name: "<<temp->name<<endl;
		        		//cout<<"  Phone Number:"<<temp->phone_number<<endl;
		        		//cout<<"  Room Number: "<<temp->address<<endl;
		        		//cout<<"*****"<<endl;
		        		//check=true;
		        	}
		        	temp=temp->next;

	        	}
	        	if(check==false)  cout<<"  Name Not Found....."<<endl;
	        	if(na!="") { cout<<"\n---------------------------------------\n\n"; return flag; }
	    	}
	    	else if(command=="2")  {
	    	    if(ph=="") {
	    		    cout<<"  Enter the Phone Number to Search: ";
	    		    getline(cin>>ws, y);
	    		}
	    		cout.flush();
	    		int flag=0;
	    		while(temp!=NULL) {
	    	    	if(temp->phone_number==y) {

		        		flag++;
		        	    if(flag==1){
		        	        cout<<"Displaying contacts Information: \n\n";
		        	        for(int i=23+len+roomlength+namelength;i>0;i--) cout<<"*";
		        	        cout<<endl;
		        	        cout<<"| Sr.No. ";
		        	        for(int i=len-6;i>0;i--)cout<<" ";
	    		            cout<<"| Name ";
	    		            for(int i=namelength-4;i>0;i--) cout<<" ";
	    		            cout<<"| Number     | Room ";
	    	    	        for(int i=roomlength-4;i>0;i--) cout<<" ";
	    	        	    cout<<"|"<<endl;
	    	        	    for(int i=23+len+roomlength+namelength;i>0;i--) cout<<"*";
		        	        cout<<endl;
	        		    }
	        		    string xx=temp->name;
	        		    for(int i=0;i<xx.size();i++){
                            if(i==0){ if(xx[0]>=97 && xx[0]<=122) xx[0]-=32; }
                            else if(xx[i-1]==' ' && xx[i]>=97 && xx[i]<=122) xx[i]-=32;
                        }
                        cout<<"| "<<flag;
                        int tlen=countdigit(flag);
                        for(int i=len-tlen+1;i>0;i--) cout<<" ";
		        	    cout<<"| "<<xx;
		        	    for(int i=namelength-temp->name.size();i>0;i--) cout<<" ";
		        	    cout<<" | "<<temp->phone_number;
		        	    cout<<" | "<<temp->address;
		        	    for(int i=roomlength-temp->address.size();i>0;i--) cout<<" ";
		        	    cout<<" |"<<endl;
		        	    for(int i=23+len+roomlength+namelength;i>0;i--) cout<<"*";
		        	    cout<<endl;
		        	    check=true;


		        		//cout<<"*****"<<endl;
		        		//cout<<"  Name: "<<temp->name<<endl;
		        		//cout<<"  Phone Number: "<<temp->phone_number<<endl;
		        		//cout<<"  Room Number: "<<temp->address<<endl;
		        		//cout<<"*****"<<endl;
		        		//check=true;

		        	}
			        temp=temp->next;
	        	}
				if(check==false)	cout<<"  Number Not Found...."<<endl;
				if(ph!="") { cout<<"\n---------------------------------------\n\n"; return flag; }
	    	}
	    	else if(command=="3"){
	    	    if(ph=="") {
	    		    cout<<"  Enter the Room Number to Search: ";
	    	        getline(cin>>ws, room);
	    	    }
	    	    cout.flush();
	    	    int flag=0;
	    	    while(temp!=NULL) {
	    	    	if(temp->address==room) {


		        		flag++;
		        	    if(flag==1){
		        	        cout<<"Displaying contacts Information: \n\n";
		        	        for(int i=23+len+roomlength+namelength;i>0;i--) cout<<"*";
		        	        cout<<endl;
		        	        cout<<"| Sr.No. ";
		        	        for(int i=len-6;i>0;i--)cout<<" ";
	    		            cout<<"| Name ";
	    		            for(int i=namelength-4;i>0;i--) cout<<" ";
	    		            cout<<"| Number     | Room ";
	    	    	        for(int i=roomlength-4;i>0;i--) cout<<" ";
	    	        	    cout<<"|"<<endl;
	    	        	    for(int i=23+len+roomlength+namelength;i>0;i--) cout<<"*";
		        	        cout<<endl;
	        		    }
	        		    string xx=temp->name;
	        		    for(int i=0;i<xx.size();i++){
                            if(i==0){ if(xx[0]>=97 && xx[0]<=122) xx[0]-=32; }
                            else if(xx[i-1]==' ' && xx[i]>=97 && xx[i]<=122) xx[i]-=32;
                        }
                        cout<<"| "<<flag;
                        int tlen=countdigit(flag);
                        for(int i=len-tlen+1;i>0;i--) cout<<" ";
		        	    cout<<"| "<<xx;
		        	    for(int i=namelength-temp->name.size();i>0;i--) cout<<" ";
		        	    cout<<" | "<<temp->phone_number;
		        	    cout<<" | "<<temp->address;
		        	    for(int i=roomlength-temp->address.size();i>0;i--) cout<<" ";
		        	    cout<<" |"<<endl;
		        	    for(int i=23+len+roomlength+namelength;i>0;i--) cout<<"*";
		        	    cout<<endl;
		        	    check=true;


		        		//cout<<"*****"<<endl;
		        		//cout<<"  Name: "<<temp->name<<endl;
		        		//cout<<"  Phone Number: "<<temp->phone_number<<endl;
		        		//cout<<"  Room Number: "<<temp->address<<endl;
		        		//cout<<"*****"<<endl;
		        		//check=true;
		        		//break;
		        	}
			        temp=temp->next;
	        	}
				if(check==false)	cout<<"  Room Number not found"<<endl;
	    	    if(ph!="") { cout<<"\n---------------------------------------\n\n"; return flag; }
	    	}
	    	else cout<<"Invalid choice..."<<endl;
	    	cout<<endl<<"press enter to continue: ";
	    	getchar();
	    	system("clear");
	    	return 0;
	    }

	    void DeleteAllContacts() {
	    	Node *temp=head;
	    	Node *temp2;
	    	if(head==NULL)	{
	    		cout<<"  Already Contact Book is Empty"<<endl;
	    		cout<<"***********************************"<<endl;
			}
			else {
			    string com;
			    Display(1);
			    cout<<"***********************************"<<endl;
			    cout<<"| 1. Delete all Contacts           |"<<endl;
			    cout<<"| 2. Go back                       |"<<endl;
			    cout<<"************************************"<<endl<<endl;
			    cout<<" Enter your choice: ";
			    getline(cin>>ws, com);
			    cout.flush();
			    if(com=="1"){
				    while(temp!=NULL) {
				    	temp2=temp;
				    	temp=temp->next;
				    	delete temp2;
				    }
				    head=NULL;
				    cout<<"  Successfully Deleted All Contacts"<<endl;
	    		    cout<<"*************************************"<<endl;
			    }

			    else if(com=="2")   cout<<" \n";
			    else cout<<" Invalid choice........\n";
			}
			//cout<<endl<<"Please Wait....";
			sleep(2);
			system("clear");
		}

/*...*/		void finaldelete(Node *ptr){
                if(ptr==head && ptr->next){ head=head->next; delete ptr; head->prev=NULL;  return; }
                else if(ptr==head){ head=head->next; delete ptr; return; }
                else if(ptr->next==NULL) { Node*temp=ptr->prev; temp->next=NULL; delete ptr; return; }
                else{
                    ptr->prev->next=ptr->next;
                    ptr->next->prev=ptr->prev;
                    delete ptr;
                    return ;
                }
            }

/*...*/		void deletenode(string n="", string p="", string r="", int num=-1, string *na=NULL, string *ph=NULL, string * ro=NULL){
		    Node *temp=head;
		    int flag;
		    while(temp!=NULL) {
		        	if(n!="") { if(temp->name.find(x) != string::npos)  flag++; }
		        	else if(p!="") { if(temp->phone_number==p) flag++; }
		        	else if(r!="") { if(temp->phone_number==r) flag++; }
		        	if(flag==num) {
		        	    if(na==NULL) { finaldelete(temp); break; }
		        	    else { *na=temp->name; *ph=temp->phone_number; *ro=temp->address; finaldelete(temp); break; }
		        	}
		        	temp=temp->next;
	        	}
		}

/*...*/ void CreateNode1(string n="", string p="", string r="") {
	    	cout<<"\n------Enter u if information is unavailable---------\n\n";
	    	int nou=0;
	    	if(head==NULL)	{
    	    	Node *newer= new Node;
    	    	cout<<"  Name of Contact: ";
		        getline(cin>>ws, x);
		        for(int i=0;i<x.size();i++){
	        	   if(x[i]>=65 && x[i]<=90) x[i]+=32;
	        	}
	        	if(x=="u") { x="unavailable"; nou++; }
		        newer->name=x;
		        cout.flush();
    		    cout<<"  Phone Number: ";
	    	    getline(cin>>ws, y);
	    	    cout.flush();
	    	    if(y!="u") y=checknumber(y);
	    	    else { y="unavailable"; nou++; }
	    	    if(y=="no"){
	    	        cout<<"Invalid Phone Number...\n ";
	    	        delete newer;
	    	        if(n!="" || p!="" || r!="") goto l1;
	    	        //cout<<endl<<"Please Wait....";
	    	        sleep(2);
	    	        system("clear");
	    	        return;
	    	    }
	    	    newer->phone_number=y;
	    	    cout<<" Enter Room number: ";
	    	    getline(cin>>ws, room);
	    	    cout.flush();
	    	    if(room=="u")  { room="unavailable"; nou++; }
		        newer->address=room;
		        newer->next=NULL;
		        newer->prev==NULL;
		        if(nou>1) {
		            cout<<endl<<"Insufficient Data..\n"<<nou<<" fields cannot be unavailable at the same time....\n";
		            delete newer;
		            if(n!="" || p!="" || r=="") goto l1;
		            sleep(2);
		            system("clear");
		            return;
		        }
		        head=newer;
		        if(namelength<x.size()) namelength=x.size();
		        if(roomlength<room.size()) roomlength=room.size();
		        if(n=="" && p=="" && r=="") cout<<"  Contact Added...."<<endl;
		        else { cout<<"Contact Edited Successfully....\n"; return; }
		    }

		    else {
		        Node *newer= new Node;
	    	    cout<<"  Name of Contact: ";
		        getline(cin>>ws, x);
		        for(int i=0;i<x.size();i++){
	        	   if(x[i]>=65 && x[i]<=90) x[i]+=32;
	        	}
	        	if(x=="u") { x="unavailable"; nou++; }
		        cout.flush();
		        newer->name=x;
    		    cout<<"  Phone Number: ";
	    	    getline(cin>>ws, y);
	    	    cout.flush();
	    	    if(y!="u") y=checknumber(y);
	    	    else { nou++; y="unavailable"; }
	    	    Node *temp1=head;
	    	    while(y!="unavailable" && temp1!=NULL){
	    	        if(temp1->phone_number==y){
	    	            cout<<"\nPhone Number already exists.....\n";
	    	            delete newer;
	    	            if(n!="" || p!="" || r!="") goto l1;
	    	            sleep(2);
	    	            system("clear");
	    	            return;
	    	        }
	    	        temp1=temp1->next;
	    	    }
	    	    if(y=="no"){
	    	        cout<<"Invalid Phone Number...\n ";
	    	        delete newer;
	    	        if(n!="" || p!="" || r!="") goto l1;
	    	       // cout<<endl<<"Please Wait....";
	    	        sleep(2);
	    	        system("clear");
	    	        return;
	    	    }
		        newer->phone_number=y;
		        cout<<"  Enter Room Number: ";
		        getline(cin>>ws, room);
		        if(room=="u") { nou++; room="unavailable"; }
		        cout.flush();
		        newer->address=room;
		        newer->next=NULL;
		        if(nou>1) {
		            cout<<endl<<"Insufficient Data..\n"<<nou<<" fields cannot be unavailable at the same time....\n";
		            delete newer;
		            if(n!="" || p!="" || r!="") goto l1;
		            sleep(2);
		            system("clear");
		            return;
		        }
		    	Node *temp=head;
		    	while(temp->next!=NULL)  temp=temp->next;
		    	temp->next=newer;
		    	newer->prev=temp;
		    	if(namelength<x.size()) namelength=x.size();
		        if(roomlength<room.size()) roomlength=room.size();
		    	if(n=="" && p=="" && r=="") cout<<"  Contact Added Successfully...\n   ";
		    	else { cout<<"Contact Edited Successfully....\n"; return; }
			}
			if(0){
			    l1: cout<<"Contact could not be edited...\n";
			    Node* temp1=new Node;
			    temp1->name=n;
			    temp1->phone_number=p;
			    temp1->address=r;
			    temp1->prev=NULL;
			    temp1->next=NULL;
			    if(head==NULL) head=temp1;
			    else{
			        Node* last=head;
			        while(last->next!=NULL) { last=last->next; }
			        last->next=temp1;
			        temp1->prev=last;
			    }
			    return ;
			}
//			cout<<endl<<"Please Wait....";
			sleep(2);
			system("clear");
		}

		int commstr(string s){
		    for(int i=0; s[i]!='\0';i++){
		        if(s[i]<'0' || s[i]>'9') return 0;
		    }
		    return 1;
		}

/*...*/	void DeleteContactBySearch()  	{
	    	Node *temp=head;
	    	if(temp==NULL){
	    	    cout<<"There are no contacts in the Directory......\n";
	    	    sleep(2);
	    	    system("clear");
	    	    return;
	    	}
	    	cout<<"**************************************************"<<endl;
	    	cout<<"| Press 1 if you want to Search By name           |"<<endl;
	    	cout<<"| Press 2 if you want to Search By Phone Number   |"<<endl;
	    	cout<<"| Press 3 if you want to Search by Room Number    |"<<endl;
	    	cout<<"***************************************************"<<endl<<endl;
	    	string command;
	    	cout<<"  Enter the Command: ";
	    	getline(cin>>ws, command);
	    	if(command=="1")	{
	    		bool Dcheck=false;
	    		cout<<"  Enter the Name to Delete: ";
	    		getline(cin>>ws, x);
	    		for(int i=0;i<x.size();i++){
	        	   if(x[i]>=65 && x[i]<=90) x[i]+=32;
	        	}
	    		cout.flush();
	    		int con=Search(x);
	        	if(con!=0)
	        	{
	            	string command;
	            	cout<<"  Enter the serial number of the contact to delete: ";
	            	getline(cin>>ws, command);
	            	int deletecon=0;
	            	if(commstr(command)) deletecon=stoi(command);
	            	if(deletecon==0 || deletecon>con){
	            	    cout<<"Invalid input.....\n";

	            	}
	            	else {  deletenode(x, "", "", deletecon);
    	            	cout<<"Contact deleted Successfully....\n";
	            	}
	            }
	            else if(con==0) 	cout<<"  Contact of This Name Not Found...\n."<<endl;
			}
	    	else if(command=="2")
	    	{
	    		bool Dcheck=false;
	    		cout<<"  Enter the Number to Delete: ";
	    		getline(cin>>ws, y);
	    		int con=Search("", y);
	    		cout.flush();

	        	if(con!=0)
	        	{
	            	string command;
	            	cout<<"  Enter the Serial Number of contact to delete: ";
	        	    getline(cin>>ws, command);
	            	int deletecon=0;
	            	if(commstr(command)) deletecon=stoi(command);
	            	if(deletecon==0 || deletecon>con){
	            	    cout<<"Invalid input.....\n";

	            	}
	            	else { deletenode("", y, "", deletecon);
	            	    cout<<"Contact deleted Successfully....\n";
	            	}
	            }
	            else if(con==0) 	cout<<"  Contact of This Phone Not Found.....\n"<<endl;
			}
	    	else if(command=="3"){
	    	    bool Dcheck=false;
	    		cout<<"  Enter the Room Number to Delete: ";
	    		getline(cin>>ws, room);
	    		int con=Search("", "", room);
	    		cout.flush();
	    		if(con!=0)
	        	{
	            	string command;
	            	cout<<"  Enter the Serial Number of contact to delete: ";
	        	    getline(cin>>ws, command);
	            	int deletecon=0;
	            	if(commstr(command)) deletecon=stoi(command);
	            	if(deletecon==0 || deletecon>con){
	            	    cout<<"Invalid input.....\n";

	            	}
	            	else { deletenode("", "", room, deletecon);
	            	    cout<<"Contact deleted Successfully....\n";
	            	}
	            }
	            else if(con==0) 	cout<<"  Contact of This Phone Not Found.....\n"<<endl;
			}
	    	else cout<<"  You Enter wrong Command\n";
			//cout<<endl<<"Please Wait....";
			sleep(2);
			system("clear");
	    }

	    void BubbleSort(){
        	Node *temp=head;
            Node *i,*j;
            string n;
            string n2;
            string n3;
            if(temp=NULL)
            {
            	cout<<"  Empty contact Book"<<endl;
			}
			else
			{
                for(i=head;i->next!=NULL;i=i->next)
                {
                    for(j=i->next;j!=NULL;j=j->next)
                    {
                        if(i->name>j->name)
		                {
                            n=i->name;
                            i->name=j->name;
                            j->name=n;

                            n2=i->phone_number;
                            i->phone_number=j->phone_number;
                            j->phone_number=n2;

                            n3=i->address;
                            i->address=j->address;
                            j->address=n3;
                        }
                    }
                }
            }
        }


/*...*/ void EditContacts()	{
	    	Node *temp=head;
	    	if(temp==NULL){
	    	    cout<<"There are no contacts in the Directory......\n";
	    	    sleep(2);
	    	    system("clear");
	    	    return;
	    	}
	    	cout<<"**************************************************"<<endl;
	    	cout<<"| Press 1 if you want to Search By Name           |"<<endl;
	    	cout<<"| Press 2 if you want to Search By Phone Number   |"<<endl;
	    	cout<<"| Press 3 if you want to Search By Room Number    |"<<endl;
	    	cout<<"***************************************************"<<endl<<endl;
	    	string Ecommand;
	    	cout<<"  Enter the Command: ";
	    	getline(cin>>ws, Ecommand);

	    	if(Ecommand=="1")
	    	{
	    		bool Echeck=false;
	    		cout<<"  Enter the Name to Edit: ";
	    		getline(cin>>ws, x);
	    		cout.flush();
	    		int con=Search(x);

	        	if(con!=0)
	        	{
	            	string command;
	        	    cout<<"  Press the serial number of the Contact you want to edit: ";
	            	getline(cin>>ws, command);
	            	int tempcon=0;
	            	if(commstr(command)) tempcon=stoi(command);
	        	    if(tempcon>0 && tempcon<=con) {
	        		    string na, ph, ro;

	        		    deletenode(x, "", "", tempcon, &na, &ph, &ro);
	        		    CreateNode1(na, ph, ro);
			    	}
			    	else    cout<<"  You Enter Wrong Command ... "<<endl;
	    	    }
	    	    else if(con==0) cout<<"  Contact Not Found...."<<endl;
			}
	    	else if(Ecommand=="2")
	    	{
	    		bool Echeck=false;
	    		cout<<"  Enter the Phone Number to Search: ";
	    		getline(cin>>ws, y);
	    		cout.flush();
	    		int con=Search("", y);
	    		if(con!=0)
	        	{
	            	string command;
	        	    cout<<"  Press the serial number of the Contact you want to edit: ";
	            	getline(cin>>ws, command);
	            	int tempcon=0;
	            	if(commstr(command)) tempcon=stoi(command);
	        	    if(tempcon>0 && tempcon<=con) {
	        		    string na, ph, ro;

	        		    deletenode("", y, "", tempcon, &na, &ph, &ro);
	        		    CreateNode1(na, ph, ro);
			    	}
			    	else    cout<<"  You Enter Wrong Command ... "<<endl;
	    	    }
	        	else if(Echeck==false) 	    cout<<"  There is No Contact of this Number."<<endl;
	        }
	        else if(Ecommand=="3"){
	            bool Echeck=false;
	    		cout<<"  Enter the Room Number to Edit: ";
	    		getline(cin>>ws, room);
	    		cout.flush();
	    		int con=Search("", "", room);
	        	if(con!=0)
	        	{
	            	string command;
	        	    cout<<"  Press the serial number of the Contact you want to edit: ";
	            	getline(cin>>ws, command);
	            	int tempcon=0;
	            	if(commstr(command)) tempcon=stoi(command);
	        	    if(tempcon>0 && tempcon<=con) {
	        		    string na, ph, ro;

	        		    deletenode("", "", room, tempcon, &na, &ph, &ro);
	        		    CreateNode1(na, ph, ro);
			    	}
			    	else    cout<<"  You Enter Wrong Command ... "<<endl;
	    	    }
	        	else if(con==0) cout<<"  There is No Contact of this Room Number."<<endl;
	        }
	        else cout<<"  You Enter Wrong Command ...\n    ";
	        sleep(2);
	        system("clear");
        }


    	void OflineSave()	{
    		Node *temp=head;
    		ofstream myfile ("contactbook.txt");
            if (myfile.is_open())
            {
            	while(temp!=NULL)
	        	{
	        	    myfile<<temp->name<<endl;
		        	myfile<<temp->phone_number<<endl;
		        	myfile<<temp->address<<endl;
    		    	temp=temp->next;
	        	}
                myfile.close();
            }
            admin *t=user;
            ofstream adm("admin.txt");
            if(adm.is_open()){
                while(t!=NULL){
                    adm<<t->userid<<endl;
                    adm<<t->pwd<<endl;
                    t=t->next;
                }
                adm.close();
            }
		}

		void reopenCB()	{
			bool isEmpty;
			ifstream temp1("admin.txt");
			if(!temp1.is_open()){
			    cout<<"Creating database....\n";
			    sleep(2);
			    ofstream temp2("admin.txt");
			    temp2.close();
			}
			temp1.close();
			ifstream temp3("contactbook.txt");
			if(!temp3){
			    cout<<"Creating database....\n";
			    sleep(2);
			    ofstream temp2("contactbook.txt");
			    temp2.close();
			}
			temp3.close();
			ifstream adm("admin.txt");
			ifstream myfile ("contactbook.txt");
			if(!adm.is_open()) { cout<<"cannot connect to database\nadmin.txt file missing\n"; exit(1);  }
			if(!myfile.is_open()) { cout<<"cannot connect to database\ncontactbook.txt file missing\n"; exit(1); }
            if (myfile.is_open() && myfile.peek() != EOF)
            {
                while(getline(myfile,x))
                {
                    getline(myfile, y);
                    getline(myfile, room);
                    totalcon++;
                    for(int i=0;i<x.size();i++){
                        if(x[i]>=65 && x[i]<=90) x[i]+=32;
                    }
                    if(namelength<x.size()) namelength=x.size();
                    if(roomlength<room.size()) roomlength=room.size();
						if(head==NULL)
	                    {
    	                  Node *newer= new Node;
                          newer->name=x;
		                  newer->phone_number=y;
		                  newer->address=room;
	                      newer->next=NULL;
	                      newer->prev==NULL;
	                      head=newer;
		                }
						else
						{
							Node *newer= new Node;
							newer->name=x;
							newer->phone_number=y;
							newer->address=room;
							newer->next=NULL;

							Node *temp=head;
		                	while(temp->next!=NULL)		temp=temp->next;

		                	temp->next=newer;
		                	newer->prev=temp;
						}


                }
            	myfile.close();
            }
            if(head!=NULL) BubbleSort();


            if (adm.is_open() && adm.peek() != EOF)
            {
                while(getline(adm,us))
                {
                    getline(adm, p);
                    if(useridlen<us.size()) useridlen=us.size();
                    if(passwordlen<p.size()) passwordlen=p.size();
						if(user==NULL)
	                    {
    	                  admin *newer= new admin;
                          newer->userid=us;
		                  newer->pwd=p;
	                      newer->next=NULL;
	                      newer->prev==NULL;
	                      user=newer;
		                }
						else
						{
							admin *newer= new admin;
							newer->userid=us;
							newer->pwd=p;
							newer->next=NULL;

							admin *temp=user;
		                	while(temp->next!=NULL)		temp=temp->next;

		                	temp->next=newer;
		                	newer->prev=temp;
						}


                }
            	adm.close();
            }
            if(user==NULL)
	        {
    	        admin *newer= new admin;
                newer->userid="admin123";
		        newer->pwd="admin123";
	            newer->next=NULL;
	            newer->prev==NULL;
	            user=newer;
		    }


		}

		void createuser(){
		    if(user==NULL)	{
    	    	admin *newer= new admin;
	    	    cout<<"  userid: ";
		        getline(cin>>ws, us);
		        newer->userid=us;
		        cout.flush();
    		    cout<<"  Password: ";
	    	    getline(cin>>ws, p);
	    	    cout.flush();
	    	    newer->pwd=p;
		        newer->next=NULL;
		        newer->prev==NULL;
		        user=newer;
		        if(useridlen<us.size()) useridlen=us.size();
		        if(passwordlen<p.size()) passwordlen=p.size();
		        cout<<"  Userid Added"<<endl;
		    }

		    else {
		        cout<<"  Userid: ";
		        getline(cin>>ws, us);
		        admin *t=user;
		        while(t!=NULL){
		            if(t->userid==us){
		                cout<<"userid already exists....\n";
		                sleep(2);
		                system("clear");
		                return;
		            }
		            t=t->next;
		        }
		        cout.flush();
		        admin *newer= new admin;
	    	    newer->userid=us;
    		    cout<<"  Password: ";
	    	    getline(cin>>ws, p);
	    	    cout.flush();
		        newer->pwd=p;
		        cout.flush();
		        newer->next=NULL;
		    	admin *temp=user;
		    	while(temp->next!=NULL)  temp=temp->next;
		    	temp->next=newer;
		    	newer->prev=temp;
		    	if(useridlen<us.size()) useridlen=us.size();
		        if(passwordlen<p.size()) passwordlen=p.size();
		        cout<<"  Userid Added"<<endl;

			}
//			cout<<endl<<"Please Wait....";
			sleep(2);
			system("clear");
		}

		int deleteuser(){
		    cout<<"Enter userid to delete: ";
		    int flag=0;
		    getline(cin>>ws, us);
		    if(us=="admin123"){
		        cout<<"cannot delete this userid.....\n";
		        sleep(2);
		        system("clear");
		        return 0;
		    }
		    cout<<"Enter Password: ";
		    getline(cin>>ws, p);
		    admin *t=user;
		    while(t!=NULL){
		        if(t->userid==us && t->pwd==p){

		            if(t==user)
	            	{
	            		admin *temp1;
	            		temp1=t;
	        	    	t=t->next;
	        		    delete temp1;

    	        		if(t) t->prev=NULL;
	            		user=t;
	            	}
				    else if( t->next==NULL)
    				{
	    				t->prev->next=NULL;
		    			delete t;
			    	}
				    else
    				{
	    				admin *temp1;
		    			temp1=t;
			    		t->prev->next=temp1->next;
				    	t->next->prev=temp1->prev;
					    delete temp1;
		    		}

		            flag=1;
		            break;
		        }
		        t=t->next;
		    }
		    if(flag){
		        cout<<"userid deleted successfully...\n";
		        if(us==curuserid){ cout<<"Logging out.....\n";  }
		        sleep(2);
		        system("clear");
		        if(us==curuserid) { curuserid=""; return 1; }
		    }
		    else{
		        cout<<"userid does not exist....\n";
		        sleep(2);
		        system("clear");
		    }
		    return 0;
		}

		void Structure() {
		    cout<<endl;
	    	cout<<"*******************************"<<endl;
	    	cout<<"|   1. Add Contact            |"<<endl;
	    	cout<<"|   2. Edit the Contact       |"<<endl;
	    	cout<<"|   3. Delete Contact         |"<<endl;
	    	cout<<"|   4. Search Contact         |"<<endl;
	    	cout<<"|   5. Display All Contacts   |"<<endl;
	    	cout<<"|   6. Delete All Contacts    |"<<endl;
	    	cout<<"|   7. Create New User        |"<<endl;
	    	cout<<"|   8. Delete a User          |"<<endl;
	    	cout<<"|   9. Display all User       |"<<endl;
	    	cout<<"|   10.Logout                 |"<<endl;
	    	cout<<"*******************************"<<endl;

	    	string Scommand;
	    	cout<<"  Enter the Command: ";
	    	getline(cin>>ws, Scommand);
	    	cout<<endl;
	    	cout<<"_________________________________________________________________\n\n";
	    	try
	    	{
	    		if(Scommand=="1")
	            {
	            	CreateNode1();
	            	Structure();
	            }
	            else if(Scommand=="2")
		        {
		        	EditContacts();
		        	Structure();
			       }
	            else if(Scommand=="3")
	            {
	    	      	DeleteContactBySearch();
	    	       	Structure();
	            }
	            else if(Scommand=="4")
	            {
	            	int tt=Search();
	            	Structure();
	            }
	            else if(Scommand=="5")
	            {
	            	Display(0);
	            	Structure();
	            }
	            else if(Scommand=="6")
	            {
	            	DeleteAllContacts();
	            	Structure();
		        }
		        else if(Scommand=="7"){
		            createuser();
		            Structure();
		        }
		        else if(Scommand=="8"){
		            int flag=deleteuser();
		            if(flag) return ;
		            Structure();
		        }
		        else if(Scommand=="9"){
		            displayuser();
		        }
		        else if(Scommand=="10"){
		            OflineSave();
		            cout<<"Logging out.....\n";
		            sleep(2);
		            system("clear");
		        }
				else
				{
				throw(Scommand);
				}
			}
			catch(string Scommand)
			{
				cout<<"  You Enter wrong Command...\n   "<<endl;
				//cout<<"Please Wait....";
				sleep(2);
				system("clear");
				Structure();
			}
	    }

	    int login(){
	        cout<<"Enter userid: ";
	        getline(cin>>ws, us);
	        cout<<"Enter password: ";
	        getline(cin>>ws, p);
	        cout.flush();
	        admin *t=user;
		    while(t!=NULL){
		        if(t->userid==us && t->pwd==p) { cout<<"Welcome....\n"; curuserid=us; sleep(2); system("clear"); return 1; }
		        t=t->next;
		    }
		    cout<<"Invalid Credentials.....\n";
		    sleep(2);
		    system("clear");
		    return 0;
	    }

	    void options(){
	        cout<<endl;
	        cout<<"********************************"<<endl;
	    	cout<<"|   1. Search Contact          |"<<endl;
	    	cout<<"|   2. Display All Contacts    |"<<endl;
	    	cout<<"|   3. Login                   |"<<endl;
	    	cout<<"|   4. Exit                    |"<<endl;
	    	cout<<"*******************************"<<endl;
	    	string Scommand;
	    	cout<<"  Enter the Command: ";
	    	getline(cin>>ws, Scommand);
	    	cout<<endl;
	    	cout<<"_________________________________________________________________\n\n";
	    	try
	    	{
	    		if(Scommand=="1")
	            {
	                int tt=Search();
	            	options();
	            }
	            else if(Scommand=="2"){
	                Display(0);
	                options();
	            }
	            else if(Scommand=="3")
		        {
		        	int flag=login();
		        	if(flag) {
		        	    Structure();
		        	}
		            options();
			    }
				else if(Scommand!="4")
				{
					throw(Scommand);
				}
			}
			catch(string Scommand)
			{
				cout<<"  You Enter wrong Command... \n";
				//cout<<endl<<"Please Wait....";
				sleep(2);
				system("clear");
				options();
			}
	    }

};


int main() {
    ContactBook cb;
    cb.reopenCB();
	cout<<endl<<endl;
    cout<<"***************************************"<<endl;
	cout<<"|         WELCOME TO CONTACTBOOK      |"<<endl;
	cout<<"***************************************"<<endl<<endl;
	cb.options();
	cb.OflineSave();
	return 0;
}


/*
check the redundancy of phone Number while creating new node
if the user directly enter into database, check for suspicious numbers
check for unavailability of data
make the login module
check the redundancy of userid in login module
make constraints in DeleteContactBySearch and EditContacts by asking enough data in case multiple outputs appear
*/
