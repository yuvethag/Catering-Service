#include <fstream>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <cstdio>
#include <string>
#include <iomanip>
#include <process.h>
#include <dos.h>
#include <math.h>
#include <ctype.h>

using namespace std;

//CLASS FOR ADMINISTRATOR
class cat_admin{
    public:
    char name[80];                //TO STORE NAME OF CUSTOMER
    int order_no;                 //TO STORE THE ORDER NUMBER OF CUSTOMER
    struct date{                  //STRUCTURE TO STORE DATE
        int DD1,MM1,YY1;
    }date;
    struct time{                 //STRUCTURE TO STORE TIME
        int mm,hh;
    }time;
    int menuitem[80];            //ARRAY FOR SORTING ITEM NUMBER
    int qty[80];                 //ARRAY FOR SORTING QUANTITY OF ORDER
    int n;                       //TO STORE NUMBER OF ITEMS
    long double tprice;          //TO STORE PRICE OF INDIVIDUAL ITEMS
    long double amount;          //TO STORE TOTAL PRICE
    void printdet();             //TO CALCULATE BILL
    int getcode()                //FUNCTION TO RETURN CUSTOMER ORDER NUMBER
    {
      return order_no;
    }
};
void cat_admin:: printdet() //FUNCTION TO CALCULATE BILL
{
    int L;
    tprice=0;
    amount=0;
    cout<<"NAME:"<<"\t";
    puts(name);
    cout<<"ORDER NUMBER:"<<order_no<<endl;
    for(int j=0;j<n;j++)
    {
        L=menuitem[j];
        switch(L)
        {
            case 1:tprice=qty[j]*700;
                   amount+=tprice;
                   break;
            case 2:tprice=qty[j]*500;
                   amount+=tprice;
                   break;
            case 3:tprice=qty[j]*800;
                   amount+=tprice;
                   break;
            case 4:tprice=qty[j]*650;
                   amount+=tprice;
                   break;
            case 5:tprice=qty[j]*250;
                   amount+=tprice;
                   break;
            default:cout<<"NO ITEM PRESENT";
        }
        cout<<"ITEM NUMBER\t\tQUANTITY ORDER\t\tPRICE"<<endl;
        cout<<menuitem[j]<<"\t\t\t\t"<<qty[j]<<"\t\t"<<tprice<<endl;
    }
    cout<<"\nYOUR TOTAL BILL IS\n";
}

//CLASS FOR USER

class cat_user:public cat_admin
{
    public:
    void getdetails_u(); //FUNCTION TO GET DETAILS OF CUSTOMER AND FOOD ORDERED
};

//FUNCTION TO INPUT DETAILS

void cat_user::getdetails_u(){
    cout<<"PLEASE ENTER THE FOLLOWING DETAILS"<<endl;
    cout<<"NAME:";
    gets(name);
    cout<<"ENTER ORDER NUMBER";
    cin>>order_no;
    cout<<"\n\n";
    cout<<"----------MENU----------"<<endl;
    cout<<"ITEM NO.\tITEM                PRICE"<<endl;
    cout<<"1.\t\tPASTA CARBONARA            Rs700"<<endl;
    cout<<"2.\t\tRATATOUILLE              Rs500"<<endl;
    cout<<"3.\t\tLASAGNA               Rs800"<<endl;
    cout<<"4.\t\tSHEPHERDS PIE           Rs500"<<endl;
    cout<<"5.\t\tTIRAMISU              Rs250"<<endl;
    cout<<"\n\nENTER THE NUMBER OF ITEMS"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"ENTER ITEM NUMBER";
        cin>>menuitem[i];
        cout<<"ENTER QUANTITY";
        cin>>qty[i];
    }
    cout<<"-DELIVERY DATE:DD/MM/YY\n";
    cin>>date.DD1>>date.MM1>>date.YY1;
    cout<<"DELIVERY TIME:mm/hh\n";
    cin>>time.hh>>time.mm;
}


//MAIN FUNCTION

int main()
{
    system("cls");
    char c;
    cout<<"\n";
    cout<<"\t\t\t\t\t\tWELCOME TO CATERING SERVICE\t\t\t\t";
    cout<<"\n\t\t\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\t\t\t\t"<<endl;
    cout<<"\t\t\t\t\t\t\t\tMENU\t\t\t\t\t\t\t\t"<<endl;
    cout<<"\t\t\t\t\tA=ADMINISTRATOR\t\t\t\t\t"<<endl;
    cout<<"\t\t\t\t\tU=USER\t\t\t\t\t"<<endl;
    cout<<"\t\t\t\t\t\tX=EXIT\t\t\t\t\t"<<endl;
    cout<<"\n\n";
    cout<<"\t\t\t\t\tPLEASE ENTER YOUR CHOICE\t\t\t\t\t"<<endl;
    cin>>c;
    switch(c){
        case 'a':
        case 'A': void admen();
                  admen();
                  break;

        case 'u':
        case 'U': void user_u();
                  user_u();
                  break;
        default:cout<<"PLEASE ENTER A VALID OPTION";
    }
    return 0;

}

/*ADMINISTRATOR MENU */
void admen()
{
    int i=0;
    int pass();
    cout<<"\n\n\n";
    cout<<"PASSWORD"<<endl;
    cout<<"********"<<endl;
    I:cout<<"INPUT PASSWORD";
    if(pass())
    {
        char choice;
        void print_bill();
        void delorder();
        void searchrecord();
        void exit_order();
        int b;
        do
        {
            cout<<"\nADMINISTRATOR MENU"<<endl;
            cout<<"$$$$$$$$$$$$$$$$$$$$"<<endl;
            cout<<"\n\n";
            cout<<"1.PRINT BILL"<<endl;
            cout<<"2.DELETE ORDER"<<endl;
            cout<<"3.SEARCH RECORD"<<endl;
            cout<<"4.EXIT"<<endl;
            cout<<"\n\n";
            cout<<"PLEASE ENTER YOUR CHOICE\n";
            cin>>b;
            switch(b)
            {
                case 1:print_bill();
                       break;
                case 2:delorder();
                       break;
                case 3:searchrecord();
                       break;
                case 4: exit_order();
                       break;
                default:cout<<"INVALID CHOICE";
            }
            cout<<"DO YOU WANT TO DO ANYMORE FUNCTIONS (Y/N)"<<endl;
            cin>>choice;
            system("cls");

        } while (choice=='y'|| choice=='Y');

    }
    else
    {
        i++;
        cout<<"\n\nCORRECT PASSWORD"<<endl;
        if(i==1)
        goto I;
        if(i==2){
            cout<<"LAST CHANCE"<<endl;
            goto I;
        }

    if(i==3)
    exit(0);
    }
}
/*USER MENU */
void user_u()
{
    int x=0;
    int pass_u();    //FUNCTION FOR PASSWORD
    cout<<"\n\n\n\n\n\n\n\n";
    cout<<"PASSWORD"<<endl;
    cout<<"********"<<endl;
    K:
    cout<<"INPUT PASSWORD";
    if(pass_u())
    {
        char cho;
        void additem_u();     // TO ADD ITEM
        void ordstatus_u();   //TO VIEW ORDER STATUS
        void delete_order_u();  // TO CANCEL ORDER
        void modify_order_u();  //TO MODIFY ORDER
        void exit_order_u();   //TO EXIT;
        int b_u;
        do
        {
            cout<<"\n\n";
            cout<<"USER MENU"<<endl;
            cout<<"    $$$$$$$$$$$$$$$$$$"<<endl;
            cout<<"\n\n";
            cout<<"1.ADD ITEM"<<endl;
            cout<<"2.CHECK YOUR ORDER STATUS"<<endl;
            cout<<"3.DELETE ORDER"<<endl;
            cout<<"4.MODIFY ORDER"<<endl;
            cout<<"5.EXIT ORDER"<<endl;
            cout<<"\n\n";
            cout<<"PLEASE ENTER YOUR CHOICE:"<<endl;
            cin>>b_u;
            switch(b_u)
            {
                case 1:additem_u();
                       break;
                case 2:ordstatus_u();
                       break;
                case 3:delete_order_u();
                       break;
                case 4:modify_order_u();
                       break;
                case 5: exit_order_u();
                       break;
                default:cout<<"INVALID CHOICE"<<endl;
            }
            cout<<"DO YOU WANT ANY MORE FUNCTIONS(Y/N)";
            cin>>cho;
            system("cls");
        } while (cho=='Y'||cho=='y');

    }
    else{
        x++;
        cout<<"WRONG PASSWORD";
        if(x==1)
        goto K;
        if(x==2){
            cout<<"LAST CHANCE"<<endl;
            goto K;
        }
        if(x==3)
        exit(0);
    }
}

//TAKING ORDER
void additem_u()
{
    system("cls");
    cout<<"--------------"<<endl;
    cout<<"APPENDING NEW RECORDS"<<endl;
    cout<<"---------------"<<endl;
    cat_user A;
    ofstream f1_u("cat_user.dat",ios::binary|ios::app);
    A.getdetails_u();
    f1_u.write((char*)&A,sizeof(A));
    f1_u.close();
}

//CANCEL ORDER BY USER
void delete_order_u()
{
    system("cls");
    int cod_u;
    cat_user B;
    cout<<"---------------"<<endl;
    cout<<"DELETE RECORDS";
    cout<<"---------------"<<endl;
    ofstream f4_u("TEMP.dat",ios::binary);
    ifstream f5_u("cat_user.dat",ios::binary);
    cout<<"ENTER EXISTING ORDER NUMBER TO BE DELETED:";
    cin>>cod_u;
    while(f5_u.read((char*)&B,sizeof(B)))
    {
        if(B.getcode()!=cod_u)
            f4_u.write((char*)&B,sizeof(B));
    }
    f4_u.close();
    f5_u.close();
    remove("cat_user.dat");
    rename("TEMP.dat","cat_user.dat");
    cout<<"ORDER HAS BEEN CANCELLED"<<endl;
}

//DISPLAYING ORDER STATUS
void ordstatus_u()
{
    cat_admin T;
    int G;
    cout<<"ENTER ORDER NUMBER FOR CHECKING STATUS";
    cin>>G;
    int DD,MM,YY;
    ifstream s("cat_user.dat",ios::binary|ios::app);
    cout<<"ENTER TODAY'S DATE(DD/MM/YY)"<<endl;
    cin>>DD>>MM>>YY;
    while(s.read((char*)&T,sizeof(T)))
    {
        if(T.getcode()==G)
        {
            if(T.date.MM1>MM)
               cout<<"ORDER YET TO BE DELIVERED"<<endl;
            else
            {
                if(T.date.MM1==MM)
                {
                    if(T.date.DD1>=DD)
                        cout<<"ORDER YET TO BE DELEVERED"<<endl;
                    else
                        cout<<"ORDER DELEIVERED"<<endl;
                }
                else
                    cout<<"ORDER DELIVERED"<<endl;
            }
        }
    }

}

//MODIFY ORDER BY USER
void modify_order_u()
{
    system("cls");
    cout<<"---------------"<<endl;
    cout<<"MODIFY RECORDS"<<endl;
    cout<<"---------------"<<endl;
    cat_user a3;
    int c,H=0;
    ifstream f3("cat_user.dat",ios::binary);
    ofstream f2("cat_user.dat",ios::ate);
    cout<<"ENTER ORDER NUMBER TO BE MODIFIED:";
    cin>>c;
    while(f3.read((char*)&a3,sizeof(a3)))
    {
        if(a3.getcode()==c)
        {
            int pos=f3.tellg();
            f2.seekp(pos-sizeof(a3));
            cout<<"ENTER ITEM TO BE MODIFIED"<<endl;
            a3.getdetails_u();
            f2.write((char*)&a3,sizeof(a3));
            H=1;
            break;
        }
    }
    f3.close();
    f2.close();
    if(!H)
       cout<<"NO DATA FOUND...";
    else
       cout<<"ORDER HAS BEEN MODIFIED"<<endl;
}

//FUNCTION TO PRINT BILL
void print_bill()
{
    int e;
    system("cls");
    cout<<"-------------"<<endl;
    cout<<"PRINTING BILL"<<endl;
    cout<<"-------------"<<endl;
    cat_user Q;
    ifstream f8("cat_user.dat",ios::binary);
    cout<<"ENTER ORDER NUMBER FOR PRINTING BILL";
    cin>>e;
    while(f8.read((char*)&Q,sizeof(Q)))
    {
        if(Q.getcode()==e)
           Q.printdet();
    }
    f8.close();
}

//SEARCH ORDER BY ADMINISTRATOR
void searchrecord()
{
    system("cls");
    cout<<"------------"<<endl;
    cout<<"SEARCH FOR RECORDS"<<endl;
    cout<<"------------"<<endl;
    int co;
    cat_admin H;
    ifstream iff("cat_user.dat",ios::binary);
    cout<<"ENTER RECORD TO BE SEARCHED:";
    cin>>co;
    int flag=0;
    while(iff.read((char*)&H,sizeof(H)));
    {
        if(H.getcode()==co)
        {
            cout<<"---------RECORD FOUND---------"<<endl;
            H.printdet();
            flag=1;
        }
    }
    iff.close();
    if(flag==0)
       cout<<"---------RECORD NOT FOUND----------"<<endl;

}

//FUNCTION TO CANCEL ORDER
void delorder()
{
    system("cls");
    int cod;
    cat_user G;
    cout<<"----------"<<endl;
    cout<<"DELETE RECORDS"<<endl;
    cout<<"----------"<<endl;
    ofstream f9("TEMP.dat",ios::binary);
    ifstream f12("cat_user.dat",ios::binary);
    cout<<"ENTER ORDER NUMBER TO BE DELETED";
    cin>>cod;
    while(f12.read((char*)&G,sizeof(G)))
    {
        if(G.getcode()!=cod)
           f9.write((char*)&G,sizeof(G));
    }
    f9.close();
    f12.close();
    remove("cat_user.dat");
    rename("TEMP.dat","cat_user.dat");
    cout<<"RECORD HAS BEEN DELETED"<<endl;
}

//TO EXIT FROM PROGRAM FOR ADMIN
void exit_order()
{
    exit(0);
}

//TO EXIT PROGRAM FOR USER
void exit_order_u()
{
    exit(0);
}

//PASSWORD FUNCTION FOR ADMIN

int pass()
{
    char c[10];
    int w=0;
    for(;;)
    {
        c[w]=getch();
        if(c[w]=='\r')
           break;
        w++;
        cout<<"*";
    }
    if((c[0]=='Y') && (c[1]=='K'))
        return 1;
    else
        return 0;
}

//PASSWORD FUNCTION FOR USER

int pass_u()
{
    char c[10];
    for(int w=0;w<6;w++){
        c[w]=getch();
        cout<<"*";
    }
    if((c[0]=='1')&&(c[1]=='2')&&(c[2]=='3')&&((c[3]=='M')||(c[3]=='m'))&&((c[4]=='a')||(c[4]=='A'))&&((c[5]=='t')||(c[5]=='T')))
        return 1;
    else
        return 0;
}


