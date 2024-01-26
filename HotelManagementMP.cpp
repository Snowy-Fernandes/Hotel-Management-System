/*Micro-project of 1107-1109*/
//Topic-Hotel management//
#include<iostream>
#include<iomanip>
#include<conio.h>
#include<stdlib.h>
using namespace std;

class hotelmanagement
{
    private:
    int room_no;
    string phone_no;
	string guest_name;
    string email_id;
    string checkin_date;
    string checkout_date;
    string room_type;

    public:
    int booking_id;
    int show;
    void defaultdata(int i);
    void dispdata();
    void adddata();
    void roomtype();
    void generate_bookingid();
    void searchdata(int i);
};

void dispdatafield();
//----------------------------ASSIGNING DEFAULT DATA VALUES--------------------------------
    int def_booking_id[5]={1111,1109,1108,1112,1110};
    int def_room_no[5]={704,101,602,303,205};
    int def_show[5]={0,0,0,0,0};
    string def_phone_no[5]={"8169262413","9968423041","7792533540","8449302137","9965532148"};
    string def_guest_name[5]={"Meet Chavan","Kamlesh Ohol","Snowy Fernandes","Sujal Salvi","Mandar Kule"};
    string def_email_id[5]={"meet24@gmail.com","kamlesh11@yahoo.com","snowy08@outlook.com","sujal12@gmail.com","mandar10@live.com"};
    string def_checkin_date[5]={"15/11/2021","14/11/2021","16/11/2021","13/11/2021","12/11/2021"};
    string def_checkout_date[5]={"20/11/2021","18/11/2021","17/11/2021","16/11/2021","15/11/2021"};
    string def_room_type[5]={"Deluxe","Suite","Double","Single","Twin"};

int main()
{
    hotelmanagement x[20];
    int i,choice;
    int totaldata=4;

        for(i=0;i<=totaldata;i++)
        x[i].defaultdata(i);
    
 //----------------------------MENU PROGRAM FOR HOTEL MANAGEMENT--------------------------------
       menu:cout<<"\n Welcome to Hotel Management System \n";
       while(1)
       {   
        cout<<"\n 1 : Display Guest Record";
        cout<<"\n 2 : Search Guest Record ";
        cout<<"\n 3 : Add New Booking";
        cout<<"\n 4 : Delete Guest Record ";
        cout<<"\n 5 : Exit ";

        cout<<"\n Enter your Choice 1 to 5: ";
        cin>>choice;
        switch(choice)
        {
        case 1 : dispdatafield();
                 for(i=0;i<=totaldata;i++)
                 x[i].dispdata();
                 cout<<"\n\n Press any key to continue...";
                 getch();
                 system("cls");
                 goto menu;
                 break;

        case 2 : int searchid;
                 cout<<"\n Enter the Booking ID to Search Record:";
                 cin>>searchid;
                 for(i=0;i<=totaldata;i++)
                 {
                     if(searchid==x[i].booking_id)
                     {
                       x[i].searchdata(i);
                       cout<<"\n\n Press any key to continue...";
                       getch();
                       system("cls");
                       goto menu;
                     }
                 }
                 cout<<"\n Record Not Found!";
                 break;

        case 3 : x[totaldata+1].adddata();
                 totaldata++;
                 cout<<"\n\n Press any key to continue...";
                 getch();
                 system("cls");
                 goto menu;
                 break;

        case 4 : int deleteid;
                 cout<<"\n Enter the Booking ID of the Record to be Deleted:";
                 cin>>deleteid;
                 for(i=0;i<=totaldata;i++)
                 {
                     if(deleteid==x[i].booking_id)
                     {
                       x[i].show=1;
                       /*for(i=deleteid;i<=totaldata;i++)
                       {
                            x[i].booking_id=x[i+1].booking_id;
                            x[i].phone_no=x[i+1].phone_no;
                            x[i].room_no=x[i+1].room_no;
                            x[i].guest_name= x[i+1].guest_name;
                            x[i].email_id=x[i+1].email_id;
                            x[i].checkin_date= x[i+1].checkin_date;
                            x[i].checkout_date= x[i+1].checkout_date;
                            x[i].room_type=x[i+1].room_type;
                            x[i].show= x[i+1].show;
                       }
                       totaldata--;*/
                       cout<<"\n Record Deleted Successfully";
                       cout<<"\n Press any key to continue...";
                       getch();
                       system("cls");
                       goto menu;
                     }
                 }
                 cout<<"\n Record Not Found, Record Not Deleted!";
                 break;

        case 5 : exit(0);
        }
        getch();
        return(0);
     }
   
}

//----------------MEMBER FUNCTION TO ASSIGN DEFAULT DATA VALUES AT START----------------
void hotelmanagement::defaultdata(int i)
{
  booking_id=def_booking_id[i];
  phone_no=def_phone_no[i];
  room_no=def_room_no[i];
  guest_name=def_guest_name[i];
  email_id=def_email_id[i];
  checkin_date=def_checkin_date[i];
  checkout_date=def_checkout_date[i];
  room_type=def_room_type[i];
  show=def_show[i];
}

//----------------MEMBER FUNCTION TO PRINT DATA WHEN SEARCH SUCCESSFUL------------------
void hotelmanagement::searchdata(int i)
{
    cout<<"\n Entry Found at Location: "<<i+1<<endl;
    dispdatafield();
    dispdata();
}   

//----------------MEMBER FUNCTION TO PRINT DATA IN TABULAR FORMAT-----------------------
void hotelmanagement::dispdata()
{
     if(show==0)
    {
    cout<<"\n "<<booking_id<<"\t"<<guest_name<<"\t"<<email_id<<"\t"<<phone_no;
    cout<<"\t"<<room_no<<"\t"<<room_type<<"\t"<<checkin_date<<"\t"<<checkout_date;
    }
}

//-----------------------FUNCTION TO PRINT DATA FIELD HEADINGS--------------------------
void dispdatafield()
{
    cout<<"\n"<<" ID"<<"\t"<<"Guest Name"<<"\t"<<"Email ID"<<"\t\t"<<"Phone No";
    cout<<"\t"<<"Room No"<<"\t"<<"Type"<<"\t"<<"Check In"<<"\t"<<"Check Out";

}

//-------------------------MEMBER FUNCTION TO ADD DATA---------------------------------
void hotelmanagement::adddata()
{
    
    cout<<"\n Enter Guest Name : ";
    //cin>>guest_name;
    cin.ignore();
    getline(cin, guest_name);
    cout<<" Enter Email ID   : ";
    cin>>email_id;
    cout<<" Enter Phone No   : ";
    cin>>phone_no;
    cout<<" Enter Room No    : ";
    cin>>room_no;
    roomtype();
    cout<<" Checkin Date     : ";
    cin>>checkin_date;
    cout<<" Checkout Date    : ";
    cin>>checkout_date;
    rand();
    booking_id=rand() % (1199-1113) + 1113;
    show=0;
    cout<<" Data Added Successfully with ID: "<<booking_id;
}

//-------------------------MEMBER FUNCTION TO ADD ROOM TYPE------------------------------
void hotelmanagement::roomtype()
{
    int room_type_no;
    cout<<" Enter Room Type  : 1:Deluxe 2:Suite 3:Double 4:Single 5:Twin 6:Triple: ";
    cin>>room_type_no;
    switch(room_type_no)
    {
        case 1:
        room_type="Deluxe";
        break;
        case 2:
        room_type="Suite";   
        break;
        case 3:
        room_type="Double";
        break;
        case 4:
        room_type="Single";
        break;
        case 5:
        room_type="Twin";
        break;
        case 6:
        room_type="Triple";
        break;
        default:
        room_type=room_type_no;
    }
}

