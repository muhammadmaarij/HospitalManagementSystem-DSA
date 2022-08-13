#include <cstring>
#include <iostream>
using namespace std;

/*
SEMESTER PROJECT
HOSPITAL MANAGEMENT SYSTEM
DSA
SIR INAYAT UR REHMAN

BCS-3B
Muhammad Hassan Munawar  FA20-BCS-056
Muhammad Maarij          FA20-BCS-060
Fatima Mahsud            SP20-BCS-113


USERNAME: Admin
PASSWORD: 123

*/

//patient and emergency patients structs implementing doubly linked list and priority queues respectively
struct patient{
	string patientName;
	string patientID;
	int patientAge;
	int cnic_no;
	string visit_time;
	string departure_time;
	string ward_no;
	string bed_no;
	string pDepartment;
	string gender;
	string labTest;
	patient *p_n=NULL, *prev=NULL;
	patient *e_n = NULL;
};
	patient* p_f=NULL, *p_l=NULL;
	patient *pTop = NULL;
	patient *e_f = NULL, *e_l=NULL;


//doctor struct implementing BST 
struct doc{
	string docName;
	string dDepartment;
	int totalPatients;
	int patientsAttended;
	int patientsLeft;
	bool dAvailability;
	string docId;
	string docCnic;
	doc *dNext = NULL;
	doc *dPrev = NULL;
	doc* dLeft = NULL;
	doc *dRight = NULL;	
};
	doc *dRoot = NULL;
	doc *dLast = NULL;
	doc *dFront = NULL;


//FeedBacks implementing doubly linked list and stcks
struct FeedBack{
	string userName;
	string stars;
	string message;
	int FB_no=0;
	FeedBack *f_n=NULL, *f_p=NULL;
	FeedBack *e_n = NULL;
};
	FeedBack* f_f=NULL, *f_l=NULL;
	
	
void dijkstra();
void addPatientsRecord();
void displayPatient();
void insertDoc();
void deletePatientRecord();
void dequeueDoc();
void AddEmergencyPatients(string, int, string, int , string, string , string, string );
void displayEmergencyPatients();
void deleteDoc();
void displayDoc();
void mainmenu();
void displayLaboratory();
void pushPatientLaboratory();
void popPatientLaboratory();
void displaySkin();
void displayEye();
void displayENT();
void displayCardiac();
void dischargeEmergencyPatients();
void addFeedback();
void displayFeedBack();
void displayDoctor(doc *);
doc* search(string key);


//Admin Log in Details
string adminName = "Admin";
string adminPass = "123";


int main(){	
	cout<<"************************************************************************************\n";
	cout<<"                             Welcome to Our Hospital                               \n";
	cout<<"************************************************************************************\n";
	cout<<"\n\n";
	cout<<"\n-----------------------------------------------------------------------------------\n";
	cout<<"                          --We provide the best services in town---\n";
	cout<<"                              We have specialists for\n";
	cout<<"      ***ENT*** \t ***SKIN** \t ***EYE*** \t ***CARDIAC***\t ";
	cout<<"\n-----------------------------------------------------------------------------------\n";
	cout<<"\n\n";
	mainmenu();
}

	void mainmenu(){
	cout<<"Press \n1-ADMIN \n2-USER";
	cout<<"\n\n";
	int opt;
	cin>>opt;
	if(opt==1){
		cout<<"-----------------------------------------------------\n";
		cout<<"----------------Welcome to Admin Portal--------------\n";
		cout<<"-----------------------------------------------------\n";
				int flag1=0;
				int flag2=0;
				cout<<"Please Enter the log In details\n";
				do{
					cout<<"Enter admin name: \n";
					string guess_admin;
					cin>>guess_admin;
				if(guess_admin==adminName){
					cout<<"Admin name is correct"<<endl;
				flag1=1;
		
				}
				else{
					cout<<"Admin name is incorrect"<<endl;
					
				}
				}while(flag1!=1);
				do{
					string guess_pass;
					cout<<"Enter admin passcode: \n";
					cin>>guess_pass;
				if(guess_pass==adminPass){
					cout<<"-----------------------\n";
					cout<<"LogIn Successful!"<<endl;
					cout<<"------------------------\n";
					cout<<"\n\n";
					flag2 =1;
				}
				else{
					cout<<"Incorrect Password. Kindly try again"<<endl;
				}
				}while(flag2!=1);

				int choice;			
				do{
					cout<<"\n------------------------------------------------------------\n";
					cout<<"Enter any choice to perform any of the below opertion:"<<endl;
					cout<<"1. Add normal Patients Record"<<endl;
					cout<<"2. View all Patients Record"<<endl;
					cout<<"3. View ENT Patients Record"<<endl;
					cout<<"4. View EYE Patients Record"<<endl;
					cout<<"5. View CARDIAC Patients Record"<<endl;
					cout<<"6. View SKIN Patients Record"<<endl;
					cout<<"7. Search for Patient Record "<<endl;
					cout<<"8. Discharge any normal Patient"<<endl;
					cout<<"9. Add Doctors record"<<endl;
					cout<<"10.View Doctors Record"<<endl;
					cout<<"11.Free Doctor"<<endl;	
					cout<<"12.Search for Doctor"<<endl;
					cout<<"13.Add emergency Patients"<<endl;
					cout<<"14.Discharge Emergency Patients "<<endl;
					cout<<"15.Display Emergency Patients"<<endl;
					cout<<"16.Send Patients to Labortary"<<endl;
					cout<<"17.Discharge Labortary Patients Records"<<endl;
					cout<<"18.Display Labortary Patients Reports"<<endl;
					cout<<"19.Ambulance department"<<endl;
					cout<<"20.Generate a Final discharge Report of patient"<<endl;
					cout<<"21.Back to main Page"<<endl;
					cout<<"22.0 to exit"<<endl;
					cout<<"\n------------------------------------------------------------\n";
					cin>>choice;
					switch(choice){
				case 0:{
					cout<<"Loop terminated"<<endl;
					mainmenu();
					break;
					}
				case 1:
					addPatientsRecord();
					break;
				case 2:
					displayPatient();
					break;
				case 3:
					displayENT();
					break;
				case 4:
					displayEye();
					break;
				case 5:
					displayCardiac();
					break;
				case 6:
					displaySkin();
					break;
				case 7:{
					cout<<"Enter the patient ID: ";
					string ID;
					cin>>ID;
					patient *p = p_f;
					do{
					if(p->patientID == ID){
					cout<<"Patient Found!";
					string opt;
					cout<<"Do you want to view the records of this patient? (y/n))";
					cin>>opt;
					if(opt=="y"){
					cout<<"Patient Details"<<endl;
					cout<<"Name: "<<p->patientName<<endl;
					cout<<"Age: "<<p->patientAge<<endl;
					cout<<"Id: "<<p->patientID<<endl;
					cout<<"CNIC: "<<p->cnic_no<<endl;
					cout<<"Arrival Time: "<<p->visit_time<<endl;
					cout<<"Departure Time: "<<p->departure_time<<endl;
					cout<<"Ward no: "<<p->ward_no<<endl;
					cout<<"Department: "<<p->pDepartment<<endl;
					cout<<"Bed no: "<<p->bed_no<<endl<<endl;
					cout<<"\n";		
						}
					else{
					cout<<"You have selected not to view the Record of Patient!";
					main();
					}
					break;	
					}
			
					else{	
					p = p->p_n;	
					} 		
					} while(p!=NULL);
					break;
									}

				case 8:
					deletePatientRecord();	
					break;
				case 9:
					insertDoc();//deleteDoc();
					break;
				case 10:
					cout<<"----Available Doctors---";
					displayDoctor(dRoot);  //deleteDoc(dRoot);
					break;
				case 11:{
					deleteDoc();
					break;
						}
				case 12:{
						cout<<"Enter name or id of Doctor to search: ";
						string x;
						cin>>x;
						search(x);	
					break;
						}				
				case 13:
					{
					string name, patientID, visit_time, departure_time, ward_no, bed_no;
					int patientAge, cnic_no;
					cout<<"Enter the patient name: "<<endl;
					cin>>name;
					cout<<"Enter the patient age: "<<endl;
					cin>>patientAge;
					cout<<"Enter the patient ID: "<<endl;
					cin>>patientID;
					cout<<"Enter the cnic of patient: "<<endl;
					cin>>cnic_no;
					cout<<"Enter the visit time: "<<endl;
					cin>>visit_time;
					cout<<"Enter the departure time: "<<endl;
					cin>>departure_time;
					cout<<"Enter the ward no: "<<endl;
					cin>>ward_no;
					cout<<"Enter the bed no: "<<endl;
					cin>>bed_no;
					AddEmergencyPatients(name, patientAge , patientID, cnic_no, visit_time, departure_time, ward_no, bed_no);
					break;
						}				
				case 14:
					dischargeEmergencyPatients();
					break;
							
				case 15:
					displayEmergencyPatients();
					break;
				case 16:{
	 				pushPatientLaboratory(); 
					break;
						}
				case 17:{
					popPatientLaboratory();
					break;
						}
				case 18:{
					displayLaboratory();
					break;
						}
				case 19:{
					cout<<"\n-------------------------------------\n";
					cout<<"     Welcome to Ambulance Department   ";
					cout<<"\n--------------------------------------\n";
					dijkstra();					
					break;
						}
				case 20:{
						
					cout<<"Enter the patient ID or name: ";
					string ID;
					cin>>ID;
					string doc;
					cout<<"Enter the doctor name who attended the patient: ";
					cin>>doc;
					string lab;
					cout<<"Lab facility(y/n): ";
					cin>>lab;
					string emergency;
					cout<<"Emergency facility(y/n): ";
					cin>>emergency;
					patient *p = p_f;
					do{
					if(p->patientID == ID || p->patientName == ID){
					cout<<"\t\t\t*****************Discharge Report Of Patient**************\t\t\t";
					cout<<"\n\n\n";	
					cout<<"\t\t\t\t\tDetails \n"<<endl;
					cout<<"\t\tName of Patient: \t\t\t"<<p->patientName<<endl;
					cout<<"\t\tDoctor Name: \t\t\t\t"<<doc<<endl;
					cout<<"\t\tAge: \t\t\t\t\t"<<p->patientAge<<endl;
					cout<<"\t\tId: \t\t\t\t\t"<<p->patientID<<endl;
					cout<<"\t\tCNIC: \t\t\t\t\t"<<p->cnic_no<<endl;
					cout<<"\t\tArrival Time: \t\t\t\t"<<p->visit_time<<endl;
					cout<<"\t\tDeparture Time: \t\t\t"<<p->departure_time<<endl;
					cout<<"\t\tWard no: \t\t\t\t"<<p->ward_no<<endl;
					cout<<"\t\tDepartment: \t\t\t\t"<<p->pDepartment<<endl;
					cout<<"\t\tBed no: \t\t\t\t"<<p->bed_no<<endl<<endl;
					cout<<"\n\n\n";	
					break;	
						}		
					else if (!(p->patientID == ID || p->patientName == ID)){	
					p = p->p_n;	
					} 			
					}while(p!=NULL);
					
					int cost = 1000;
					if(lab=="y" || emergency=="n"){
						cost=2*1000;
					}
					else if(lab=="y" && emergency=="n"){
						cost=3*1000;
					}
					else{
						cost =1000;
					}
					cout<<"\t\tTotal Amount: \t\t\t\t\t" << cost;
					
					break;
						}
				case 21:{
					main();
					break;
						}
				default:
					cout<<"Invalid Input!";
					break;
							
					}					
				}while(choice != 0);	
	
				}
	else if(opt==2){
		cout<<"\n\n";
		cout<<"------------------------------------------\n";
		cout<<"          Welcome to User Portal          \n";
		cout<<"------------------------------------------\n";
		cout<<"\n\n";
		int option;
	do{
		cout<<"-----------------------------------------------\n";
		cout<<"Press 1 to search for Patient \nPress 2 for setting an appointment with doctor \n3 for any FeedBacks \n4 to view all FeedBacks \n5 to search for any doctor \n6 Back to main menu \n0 to exit"<<endl;
		cout<<"-----------------------------------------------\n";
		cin>>option;
		switch(option){		
			case 0:{
				cout<<"Loop exited"<<endl;
				mainmenu();
				break;
			}
			case 1:{
				cout<<"Enter the patient ID or Name: ";
				string ID;
				cin>>ID;
				patient *p = p_f;
			do{
				if(p->patientID == ID || p->patientName == ID){
				cout<<"Patient Found!";
				string opt;
				cout<<"Do you want to view the records of this patient? (y/n))";
				cin>>opt;
					if(opt=="y"){
					cout<<"Patient Details"<<endl;
					cout<<"Name: "<<p->patientName<<endl;
					cout<<"Age: "<<p->patientAge<<endl;
					cout<<"Id: "<<p->patientID<<endl;
					cout<<"CNIC: "<<p->cnic_no<<endl;
					cout<<"Arrival Time: "<<p->visit_time<<endl;
					cout<<"Departure Time: "<<p->departure_time<<endl;
					cout<<"Ward no: "<<p->ward_no<<endl;
					cout<<"Department: "<<p->pDepartment<<endl;
					cout<<"Bed no: "<<p->bed_no<<endl<<endl;
					cout<<"\n";		
			}
			else{
				cout<<"You have selected not to view the Record of Patient!";
				main();
			}
			break;	
		}
			
		else{	
			p = p->p_n;	
				
			} 		
		} while(p!=NULL);
			break;
			}				
		case 2:{			
			cout<<"To get an appointment with doctor first we need you to enter the patient record.";
			addPatientsRecord();
			int opt;
			cout<<"\n----Available Doctors---\n";
			displayDoctor(dRoot);
			deleteDoc();
			break;
		}
		
		case 3:{			
			cout<<"******FeedBacks Help Us become Better******"<<endl;
			cout<<"        Kindly leave Your Review           "<<endl;
			addFeedback();
			break;
		}
		
		case 4:{			
			displayFeedBack();
			break;
		}
		
		case 5:{			
			cout<<"Enter name or id of Doctor to search: ";
			string x;
			cin>>x;
			search(x);	
			break;
		}
		
		case 6:{			
			mainmenu();	
			break;
		}
		
		default:{
			cout<<"Wrong Input!"<<endl;
			break;
		}
	}
	}while(opt!=0);
	}
	else {
	cout<<"Kindly choose correct option"<<endl;
	mainmenu();
	}
	}
	


//
void deletePatientRecord(){
	string s = p_f->patientName;
	string id = p_f->patientID;
	
	if(p_f == NULL){
		cout<<"No record available"<<endl;
	}
	
	else if(p_f == p_l){
		cout<<"Now "<<s<<" having ID: "<<id<<" will be discharged"<<endl<<endl;
		delete p_f;
		p_f = p_l =NULL;
	}
	
	else{
		cout<<"Now "<<s<<" having ID: "<<id<<" will be discharged"<<endl<<endl;
		patient *temp = p_f;
		p_f = p_f->p_n;
		delete temp;
	}
	
}
	
	
	
//Add Patients to emergency Ward
void AddEmergencyPatients(string name, int age , string ID, int cnic, string visit_t, string dep_time, string ward_n, string bed_n){
	
	patient *newpat;
	newpat = new patient;
	
		newpat->patientName = name;
		newpat->patientAge = age;
		newpat->patientID = ID;
		newpat->cnic_no = cnic;
		newpat->visit_time = visit_t;
		newpat->departure_time = dep_time;
		newpat->ward_no = ward_n;
		newpat->bed_no = bed_n;
	
	if (e_f == NULL){
		e_f = e_l = newpat;
	}
		else if (age > e_f->patientAge){
		newpat->e_n = e_f;
		e_f = newpat;
	}
	
	else if (age < e_l ->patientAge){
		e_l ->e_n = newpat;
		e_l = newpat;
	}

	
	else {
		patient *node = e_f;
		patient *prev = NULL;
		
		while (age <= node->patientAge){
			prev = node;
			node = node->e_n;
		}
			prev->e_n = newpat;
			newpat->e_n = node;
	}
	newpat->patientAge = age;
}


//Discharge Patients in Emergency 
void dischargeEmergencyPatients(){
	string nam;
	int qtty;
	int ag;
	if (e_f == NULL){
		cout<<"No Emergency Patients have been found."<<endl;
	}
    
	else if(e_f == e_l){
            delete e_f;
            e_f = e_f = NULL;
            cout<<"Patient with maximum age has been sent for checkup"<<endl;
        }
        else{
            patient *temp = e_f;
            e_f = e_f->e_n;
            delete temp;
            cout<<"Patient with maximum age has been sent for checkup"<<endl;
        }
    }



//Display Patients in Emergency 
void displayEmergencyPatients(){
		
	patient *p = e_f;
	if (e_f == NULL){
		cout<<"no data to display."<<endl;
	}
		
	
	else{	
		do{		
		cout<<"Emergency Patients Details"<<endl;
		cout<<"Name: "<<p->patientName<<endl;
		cout<<"Age: "<<p->patientAge<<endl;
		cout<<"Id: "<<p->patientID<<endl;
		cout<<"CNIC: "<<p->cnic_no<<endl;
		cout<<"Arrival Time: "<<p->visit_time<<endl;
		cout<<"Departure Time: "<<p->departure_time<<endl;
		cout<<"Ward no: "<<p->ward_no<<endl;
		cout<<"Bed no: "<<p->bed_no<<endl<<endl;
		p = p->e_n;	
	} while(p!=NULL);
}

}

 
//Enter Patients in Lab Record
void pushPatientLaboratory(){
	patient *curr = new patient;
		cout<<"Enter the patient name: ";
		cin>>curr->patientName;
		cout<<"Enter the patient age: ";
		cin>>curr->patientAge;
		cout<<"Enter the patient ID: ";
		cin>>curr->patientID;
		cout<<"Enter the cnic of patient: ";
		cin>>curr->cnic_no;
		cout<<"Enter sample taking time: ";
		cin>>curr->visit_time;
		cout<<"Enter report returning time: ";
		cin>>curr->departure_time;

	int choice;
	
	do{
		cout<<"Enter gender of patient: \nPress\n1.Male \n2.Female"<<endl;
		cin>>choice;
		
		switch(choice){
			case 1:
				curr->gender = "Male";
				break;
			case 2: 
				curr->gender = "Female";
				break;
			default:
				cout<<"Invalid Gender!!"<<endl;
				break;
		}
		
	}while(choice<1 || choice>2);
		
	int option;
	do{
		cout<<"Select laboratory test: \nPress: \n1.CBC(Complete blood count) \n2.Creatinine \n3.Lipid Panel \n4.X-ray \n5.Ultrasound \0 to exit"<<endl;
	    cin>>option;
	    
	    switch(option){
	    	case 1:
	    		curr->labTest = "CBC";
	    		break;
	    	case 2:
	    		curr->labTest = "Creatinine";
	    		break;
	    	case 3:
	    		curr->labTest = "Lipid Profile";
	    		break;
	    	case 4:
	    		curr->labTest = "X-ray";
	    		break;
	    	case 5:
	    		curr->labTest = "Ultrasound";
	    	default:
	    		cout<<"Invalid Test name!!"<<endl;
	    		break;
		}
	    
	}while(option>5 || option <1);
	
	
    if(pTop == NULL){
        pTop = curr;
    }
    else{
        curr->p_n = pTop;
        pTop = curr;
    }
}

void popPatientLaboratory(){
    if(pTop == NULL){
        cout << "No test pending. " << endl;
    }
    else{
        patient *temp = pTop;
        pTop = pTop->p_n;
        cout<<"Reports of patient "<<temp->patientName<<" submitted"<<endl;
        
        delete temp; 
    }
}


//Display Labortary Details
void displayLaboratory(){	
    if (pTop == NULL){
        cout << "No sample to test!" << endl;
    }
    
    else{
        patient *p = pTop;
        
        while (p != NULL){
            cout<<"Laboratory"<<endl;
			cout<<"Name: "<<p->patientName<<endl;
			cout<<"Age: "<<p->patientAge<<endl;
			cout<<"Id: "<<p->patientID<<endl;
			cout<<"CNIC: "<<p->cnic_no<<endl;
			cout<<"Sample collection time: "<<p->visit_time<<endl;
			cout<<"Report submission time: "<<p->departure_time<<endl;
			cout<<"Gender: "<<p->gender<<endl;
			cout<<"Test: "<<p->labTest<<endl;
			cout<<endl;
			
            p = p->p_n;
        }
    }    
}


//dijkstra Graph Implemented
void dijkstra(){
	
	int n = 7;	
	string hosp[n] = {"PIMS", "RIC", "CMH", "AFIC", "AFID","SHIFA","PAF"};
	
	int graph[n][n] = {
	  {99, 99, 99, 24, 22, 99, 99},
	  {18, 99, 14, 99, 99, 99, 99},
	  {12, 99, 99, 99, 99, 99, 12},
	  {99, 16, 10, 99, 99, 18, 99},
	  {99, 99, 99, 99, 99, 6, 99},
	  {99, 99, 99, 99, 99, 99, 8},
	  {99, 99, 99, 14, 10, 99, 99}
	  };
		
	int src = -1;
	string sourceNode;
	cout<<"Enter source node"<<endl;
	cout<<"PIMS \nRIC \nCMH \nAFIC \nAFID \nSHIFA\nPAF"<<endl<<endl;
	cin>>sourceNode;
	
	for(int i = 0; i<7; i++){
		if(sourceNode== hosp[i]){
			src = i;
			break;
		}
	}
	if(src == -1){
		cout<<"Node doesnot exists"<<endl;
		return;
	}
		int count = 1;
		
		int path[n];
		for(int i=0;i<n;i++)
			path[i] = graph[src][i];
		
		int visited[n] = {0};
		visited[src] = 1;
		
		while(count<n)
		{
			int minNode;
			int minVal = 99;
			
			for(int i=0;i<n;i++)
				if(visited[i] == 0 && path[i]<minVal)
				{
					minVal = path[i];
					minNode = i;
				}
			
			visited[minNode] = 1;
			
			for(int i=0;i<n;i++)
				if(visited[i] == 0)
					path[i] = min(path[i],minVal+graph[minNode][i]);
						
			count++;
		}
		
		path[src] = 0;
		for(int i=0;i<n;i++)
			cout<<"Shortest distance from "<<sourceNode<<" to "<<hosp[i]<<" -> "<<path[i]<<endl;
	
}


//add feedacks method
void addFeedback(){
		cout<<"------------FeedBacks-------------"<<endl;
     	FeedBack *curr = new FeedBack;
		cout<<"Enter the user name: ";
		cin>>curr->userName;
		cout<<"Rate us out of 5 stars(*****) : "<<endl;
		cin>>curr->stars;
		cout<<"Leave your FeedBack: "<<endl;
		cin>>curr->message;
		curr->FB_no=curr->FB_no++;
		
	if(f_f == NULL){
		f_f = f_l = curr;
	}
	else{
		f_l->f_n = curr;
		curr->f_p = f_l;
		f_l = curr;
	}
	cout<<"**New FeedBack Added!\n   THANK YOU!  "<<endl;
}


//display feed backs method
void displayFeedBack(){
FeedBack *p = f_f;
int Fb_no=0;
	if(f_f == NULL){
		cout<<"No record to display"<<endl;
	}
	else
		while(p!=NULL){
		Fb_no++;	
		cout<<"FeedBack Details"<<endl;
		cout<<"Feed Back Number # "<<Fb_no<<"   "<<endl;
		cout<<"User name: "<<p->userName<<endl;
		cout<<"Ratings: "<<p->stars<<endl;
		cout<<"Feed Back: "<<p->message<<endl;
		
		cout<<"\n";
		p = p->f_n;
		}
	cout<<"\n";
	
}



doc* search(string key)
{
	doc *p = dRoot;
	if(dRoot==NULL){
		cout<<"Doctor not found";
	}
	else{
	while((p->docId!=key || p->docName !=key) && p!=NULL)
	{
		if(p->docId<key)
		{
			if(p->docId ==key || p->docName == key){
			cout<<"Doctor Details: "<<endl;
	 		cout<<"Name: "<<p->docName<<endl;
	 		cout<<"Id: "<<p->docId<<endl;
	 		cout<<"CNIC: "<<p->docCnic<<endl;
	 		cout<<"Patient Department: "<<p->dDepartment<<endl;
	 		cout<<"Total Patients: "<<p->totalPatients<<endl;
	 		cout<<"Patients attended: "<<p->patientsAttended<<endl;
	 		cout<<"Patients left to be attended: "<<p->patientsLeft<<endl;
	 		return 0;
			}
			else{
			p = p->dRight;
			}
			
		}
		else
		{
			if(p->docId ==key || p->docName == key){
			cout<<"Doctor Details: "<<endl;
	 		cout<<"Name: "<<p->docName<<endl;
	 		cout<<"Id: "<<p->docId<<endl;
	 		cout<<"CNIC: "<<p->docCnic<<endl;
	 		cout<<"Patient Department: "<<p->dDepartment<<endl;
	 		cout<<"Total Patients: "<<p->totalPatients<<endl;
	 		cout<<"Patients attended: "<<p->patientsAttended<<endl;
	 		cout<<"Patients left to be attended: "<<p->patientsLeft<<endl;
	 		return 0;
			}
			else{
			p = p->dLeft;
			//return p;
		    }
		}
	}
}
    	cout<<"Doctor not found";	
}



//Display Patients Record
void displayPatient(){
patient *p = p_f;
	if(p_f == NULL){
		cout<<"No record to display";
	}
	else
		while(p!=NULL){
		cout<<"Patient Details"<<endl;
		cout<<"Name: "<<p->patientName<<endl;
		cout<<"Age: "<<p->patientAge<<endl;
		cout<<"Id: "<<p->patientID<<endl;
		cout<<"CNIC: "<<p->cnic_no<<endl;
		cout<<"Arrival Time: "<<p->visit_time<<endl;
		cout<<"Departure Time: "<<p->departure_time<<endl;
		cout<<"Ward no: "<<p->ward_no<<endl;
		cout<<"Department: "<<p->pDepartment<<endl;
		cout<<"Bed no: "<<p->bed_no<<endl<<endl;
		cout<<"\n";
		p = p->p_n;
		}
	cout<<"\n";
	
}



//Add Patients Records 
void addPatientsRecord(){
		cout<<"------------Patients Record Entry-------------"<<endl;
     	patient *curr = new patient;
		cout<<"Enter the patient name: ";
		cin>>curr->patientName;
		cout<<"Enter the patient age: ";
		cin>>curr->patientAge;
		cout<<"Enter the patient ID: ";
		cin>>curr->patientID;
		cout<<"Enter the cnic of patient: ";
		cin>>curr->cnic_no;
		cout<<"Enter the visit time: ";
		cin>>curr->visit_time;
		cout<<"Enter the departure time: ";
		cin>>curr->departure_time;
		cout<<"Enter the ward no: ";
		cin>>curr->ward_no;
		cout<<"Enter the bed no: ";
		cin>>curr->bed_no;
	int choice;
	do{
		cout<<"Press 1: ENT\tPress 2: Skin\tPress 3: Cardiac\n";
		cout<<"Enter Patient's Department: ";
		cin>>choice;

		switch(choice){
			case 1: curr->pDepartment="ENT";
			break;
			case 2: curr->pDepartment="Skin";
			break;
			case 3: curr->pDepartment="Cardiac"; 
			break;
			case 4: curr->pDepartment="EYE";
			default: cout<<"\nWrong Department!\n";
		}
		
	}while(!(choice >= 1 && choice <= 3));
	
	if(p_f == NULL){
		p_f = p_l = curr;
	}
	else{
		p_l->p_n = curr;
		curr->prev = p_l;
		p_l = curr;
	}
	cout<<"**New Patient added!\n";
}


//Display Cardiac Patients
void displayCardiac(){
	patient* p = p_f;
	int sNo=0;

	do {
		sNo++;
		if(p->pDepartment =="Cardiac"){
		cout<<"--Record#"<<sNo<<"---";
		cout<<"Cardiac Patients In line Details"<<endl;
		cout<<"Name: "<<p->patientName<<endl;
		cout<<"Age: "<<p->patientAge<<endl;
		cout<<"Id: "<<p->patientID<<endl;
		cout<<"CNIC: "<<p->cnic_no<<endl;
		cout<<"Arrival Time: "<<p->visit_time<<endl;
		cout<<"Departure Time: "<<p->departure_time<<endl;
		cout<<"Ward no: "<<p->ward_no<<endl;
		cout<<"Department: "<<p->pDepartment<<endl;
		cout<<"Bed no: "<<p->bed_no<<endl<<endl;
		cout<<"\n";
		}
		p=p->p_n;	
	} while(p!=NULL);
	
		  if(sNo==0){
			cout<<"**No Patients are in-line!\n";
	}
	}
	
	
//Display ENT patients	
	void displayEye(){
	patient* p = p_f;
	int sNo=0;

	do {
		sNo++;
		if(p->pDepartment =="EYE"){
		cout<<"---Record#"<<sNo<<"---";
		cout<<"EYE Patients In line Details"<<endl;
		cout<<"Name: "<<p->patientName<<endl;
		cout<<"Age: "<<p->patientAge<<endl;
		cout<<"Id: "<<p->patientID<<endl;
		cout<<"CNIC: "<<p->cnic_no<<endl;
		cout<<"Arrival Time: "<<p->visit_time<<endl;
		cout<<"Departure Time: "<<p->departure_time<<endl;
		cout<<"Ward no: "<<p->ward_no<<endl;
		cout<<"Department: "<<p->pDepartment<<endl;
		cout<<"Bed no: "<<p->bed_no<<endl<<endl;
		cout<<"\n";
		}
		p=p->p_n;	
	} while(p!=NULL);
	
		  if(sNo==0){
			cout<<"**No Patients are in-line!\n";
	}
	}



//Display Skin Patients	
	void displaySkin(){
	patient* p = p_f;
	int sNo=0;

	do {
		sNo++;
		if(p->pDepartment =="SKIN"){
		cout<<"---Record#"<<sNo<<"---";
		cout<<"SKIN Patients In line Details"<<endl;
		cout<<"Name: "<<p->patientName<<endl;
		cout<<"Age: "<<p->patientAge<<endl;
		cout<<"Id: "<<p->patientID<<endl;
		cout<<"CNIC: "<<p->cnic_no<<endl;
		cout<<"Arrival Time: "<<p->visit_time<<endl;
		cout<<"Departure Time: "<<p->departure_time<<endl;
		cout<<"Ward no: "<<p->ward_no<<endl;
		cout<<"Department: "<<p->pDepartment<<endl;
		cout<<"Bed no: "<<p->bed_no<<endl<<endl;
		cout<<"\n";
		}
		p=p->p_n;	
	} while(p!=NULL);
	
		  if(sNo==0){
			cout<<"**No Patients are in-line!\n";
	}
	}
	


//Display ENT patients
	void displayENT(){
	patient* p = p_f;
	int sNo=0;

	do {
		sNo++;
		if(p->pDepartment =="ENT"){
		cout<<"---Record#"<<sNo<<"---";
		cout<<"ENT Patients In line Details"<<endl;
		cout<<"Name: "<<p->patientName<<endl;
		cout<<"Age: "<<p->patientAge<<endl;
		cout<<"Id: "<<p->patientID<<endl;
		cout<<"CNIC: "<<p->cnic_no<<endl;
		cout<<"Arrival Time: "<<p->visit_time<<endl;
		cout<<"Departure Time: "<<p->departure_time<<endl;
		cout<<"Ward no: "<<p->ward_no<<endl;
		cout<<"Department: "<<p->pDepartment<<endl;
		cout<<"Bed no: "<<p->bed_no<<endl<<endl;
		cout<<"\n";
		}
		p=p->p_n;	
	} while(p!=NULL);
	
		  if(sNo==0){
			cout<<"**No Patients are in-line!\n";
	}
	}



//doctor insertion in trees if doctor's availability is true
void insertDoc(){
	//Department *d;
	doc *p = new doc;
//	doc *curr = new doc;
	cout<<"Enter name of doctor: "<<endl;
	cin>>p->docName;
	cout<<"Enter department of doctor: "<<endl;
	cin>>p->dDepartment;
	cout<<"Enter id of doctor: "<<endl;
	cin>>p->docId;
	cout<<"Enter CNIC of doctor: "<<endl;
	cin>>p->docCnic;
	cout<<"Total patients doctor can check on daily basis:  ";
	p->totalPatients=45;
	cout<<p->totalPatients<<endl;
	cout<<"Enter total patients attended: ";
	cin>>p->patientsAttended;
	cout<<"Patients left unattended: ";
	p->patientsLeft = p->totalPatients-p->patientsAttended;
	cout<<p->patientsLeft<<endl;
	if(p->totalPatients == p->patientsAttended){
		p->dAvailability = false;
		cout<<"Doctor not available."<<endl;
	}
	else if(p->patientsAttended<p->totalPatients){
		p->dAvailability = true;
		cout<<"Doctor Available, added to BST"<<endl;
	}
	
if(dRoot == NULL){
		dRoot = p;
	}
	else{
		doc *prev = NULL;
		doc *curr = dRoot;
		while(curr != NULL){
			prev = curr;
			if(curr->docId == p->docId){
				cout<<"Duplicates not allowed"<<endl;
				return;
			}
			else if(p->docId > prev->docId){
				curr = curr->dRight;
			}
			else if(p->docId < prev->docId){
				curr = curr->dLeft;
			}
		}
		if(p->docId > prev->docId){
			prev->dRight = p;
		}
		else{
			prev->dLeft = p;
		}
	}	
}



//To display doctors
void displayDoctor(doc *p){
	
	if(p != NULL){
		cout<<endl;
		cout<<"Doctor Details: "<<endl;
	 	cout<<"Name: "<<p->docName<<endl;
	 	cout<<"Id: "<<p->docId<<endl;
		cout<<"CNIC: "<<p->docCnic<<endl;
 		cout<<"Total Patients: "<<p->totalPatients<<endl;
	 	cout<<"Patients attended: "<<p->patientsAttended<<endl;
	 	cout<<"Patients left to be attended: "<<p->patientsLeft<<endl;
		displayDoctor(p->dLeft);
		displayDoctor(p->dRight);
	}
}

//to free or delete doctors from BST
void deleteDoc() {
	string x;
	cout<<"Enter id or name of doctor: "<<endl;
	cin>>x;
	doc *p = dRoot;
	doc *prev;
	
	if(dRoot == NULL){
		cout<<"No doctor is Available. Kindly wait for some time"<<endl;
	}
	
	else{
		
	while (p != NULL && (p->docId != x || p->docName != x)) {
		prev = p;
		if (x > p->docId) {
		    p = p->dRight;
		} 
		else{
			p = p->dLeft;
		}
	}
	if (p->dLeft == NULL && p->dRight == NULL) { // Leaf Node
	
		if(p == dRoot){
			dRoot = NULL;
		}
		else if (p == prev->dRight) {
		    prev->dRight = NULL;
	    } 
		else{
			prev->dLeft = NULL;
		}
		cout<<"Appointment Successful. Kindly contact your doctor."<<endl;
	} 
	else if (p->dRight == NULL || p->dLeft == NULL) { //1 Branch
	    if (p->dRight == NULL) {
		    if (p == prev->dLeft) {
		        prev->dLeft = p->dLeft;
		    }
			else{  
		        prev->dRight=p->dLeft;
		    }
			cout<<"Appointment Successful. Kindly contact your doctor."<<endl;
		}
		else
		{
		    if(p==prev->dRight){
		        prev->dRight=p->dRight;
		    }
			else{
		        prev->dLeft=p->dRight;
		    }
		    cout<<"Appointment Successful. Kindly contact your doctor."<<endl;
		}
		
	}
	else{ //2 branches
		doc* p2 = p->dRight;
		doc* prev2 = p2;
		while(p2->dLeft != NULL){
			prev2 = p2;
			p2 = p2->dLeft;
		}
		if(p2->dLeft == NULL && p2->dRight == NULL){
			p->docId = p2->docId;
			if(prev2 == p2){
				p->dRight = NULL;
			}	
			else{
				prev2->dLeft = NULL;
			} 
		}
		else{
			p->docId = p2->docId;
			if(p2 == prev2){
				p->dRight = prev2->dRight;
			}
			else if(p2->dRight != NULL){
				prev2->dLeft = p2->dRight; 
			}                 
			else{
				prev2->dLeft = NULL;
			}
		}     
	}
	
}
}

//To display All Doctors
void displayDoc(){
 	doc *p = dFront;
 	
 	if(dFront == NULL){
 		cout<<"No doctor available"<<endl;
	}
	 
	else{
	 	while(p != NULL){
	 		cout<<"Doctor Details: "<<endl;
	 		cout<<"Name: "<<p->docName<<endl;
	 		cout<<"Id: "<<p->docId<<endl;
	 		cout<<"CNIC: "<<p->docCnic<<endl;
	 		cout<<"Patient Department: "<<p->dDepartment<<endl;
	 		cout<<"Total Patients: "<<p->totalPatients<<endl;
	 		cout<<"Patients attended: "<<p->patientsAttended<<endl;
	 		cout<<"Patients left to be attended: "<<p->patientsLeft<<endl;
	 		p = p->dNext;
		}
	}
}


