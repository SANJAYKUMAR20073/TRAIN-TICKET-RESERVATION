#include<iostream>
#include<string.h>
using namespace std;
static int T=0;
class TRAIN
{
 char T_No[5], Arrival[5], Depart[5], From[10], To[10], seat[16][2][10];
 public:
 void Upload();
 void Booking();
 void Train_Availability();
 void Empty();
 void Allotment();
 void position(int i);
}
train[10];
void TRAIN::Upload()
{
 cout<<"\nEnter Train Number: ";
 cin>>train[T].T_No;
 cout<<"Arrival time : ";
 cin>>train[T].Arrival;
 cout<<"Departure time : ";
 cin>>train[T].Depart;
 cout<<"From : ";
 cin>>train[T].From;
 cout<<"To : ";
 cin>>train[T].To;
 train[T].Empty();
 T++;
}
void TRAIN::Train_Availability()
{
 for(int n=0;n<T;n++)
 {
 cout<<".........................................................\n";
 cout<<"\nTrain Number: "<<train[n].T_No
 <<"\nArrival time: "<<train[n].Arrival
 <<"\t\tDeparture Time: "<<train[n].Depart
 <<"\nFrom : "<<train[n].From
 <<"\t\tTo : "<<train[n].To<<"\n";
 cout<<".........................................................\n";
 }
}
void TRAIN::Booking()
{
 int seat,n,age;
 char num[10];
 Top:
 cout<<"Train Number: ";
 cin>>num;
 for(n=0;n<=T;n++)
 {
 if(strcmp(train[n].T_No, num)==0)
 break;
 }
 while(n<=T)
 {
 cout<<"Number of the seat: ";
 cin>>seat;
 if(seat>32)
 {
 cout<<"\nThere are only 32 seats Available in this train.\n";
 }
 else
 {
 if (strcmp(train[n].seat[seat/2][(seat%2)-1], "Empty")==0)
 {
 cout<<"Enter passenger's name: ";
 cin>>train[n].seat[seat/2][(seat%2)-1];
 cout<<"Enter the Age :";
 cin>>age;
 break;
 }
 else
 {
 cout<<"The seat Number is already reserved.\n";
 }
 }
 }
 if(n>T)
 {
 cout<<"Enter correct Train Number.\n";
 goto Top;
 }
}
void TRAIN::Empty()
{
 for(int i=0; i<16;i++)
 {
 for(int j=0;j<2;j++)
 {
 strcpy(train[T].seat[i][j], "Empty");
 }
 }
}
void TRAIN::Allotment()
{
 int n,i,j;
 char number[5];
 top:
 cout<<"Enter Train Number: ";
 cin>>number;
 for(n=0;n<=T;n++)
 {
 if(strcmp(train[n].T_No, number)==0)
 break;
 }
 while(n<=T)
 {
 cout<<".........................................................\n";
 cout<<"\nTrain Number: "<<train[n].T_No
 <<"\nArrival time: "<<train[n].Arrival
 <<"\t\tDeparture Time: "<<train[n].Depart
 <<"\nFrom : "<<train[n].From
 <<"\t\tTo : "<<train[n].To<<"\n";
 cout<<".........................................................\n";
 train[T].position(n);
 int a=1;
 for (int i=0; i<16; i++)
 {
 for(int j=0;j<2;j++)
 a++;
 if(strcmp(train[n].seat[i][j],"Empty")!=0)
 cout<<"\nThe seat number "<<(a-1)<<" is reserved for "<<train[n].seat[i][j]<<".";
 }
 }
 if(n>T)
 {
 cout<<"\nEnter correct Train Number: ";
 goto top;
 }
}
void TRAIN::position(int l)
{
 int s=0;T=0;
 for (int i =0; i<16;i++)
 {
 cout<<"\n";
 for (int j = 0;j<2; j++)
 {
 s++;
 if(strcmp(train[l].seat[i][j], "Empty")==0) {
 cout.width(5);
 cout<<s<<".";
 cout.width(10);
 cout<<train[l].seat[i][j];
 T++;
 }
 else{
 cout.width(5);
 cout<<s<<".";
 cout.width(10);
 cout<<train[l].seat[i][j];
 }
 }
 }
 cout<<"\n\nThere are "<<T<<" seats empty in Train Number: "<<train[l].T_No;
}
int main()
{
 int ch;
 cout<<"\t..........................................................................\n";
 cout<<"\t\t\t\tRAILWAY MANAGEMENT\n";
 cout<<"\t..........................................................................\n";
 while(1)
 {
 cout<<"\n";
 cout<<"1.Load the Details \n"
 <<"2.Reservation\n"
 <<"3.Trains Available\n"
 <<"4.Allotment\n"
 <<"5.Exit\n";
 cout<<"\nEnter your choice:-> ";
 cin>>ch;
 switch(ch)
 {
 case 1 :
 train[T].Upload();
 break;
 case 2 :
 train[T].Booking();
 break;
 case 3 :
 train[T].Train_Availability();
 break;
 case 4 :
 train[T].Allotment();
 break;
 case 5 :
 return 0;
 default :
 cout<<"\t\t........................";
 cout<<"\n\t\t| Enter Correct Choice |\n";
 cout<<"\t\t........................";
 }
}
 return 0;
}