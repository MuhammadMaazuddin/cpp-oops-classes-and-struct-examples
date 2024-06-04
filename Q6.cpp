#include<iostream>
using namespace std;
class RentalReservation
{
    private:
        string reservationID;
        string customerName;
        string carMakeAndModel;
        int pickupDate;
        int returnDate;
        int rentalDuration;
        double rentalRate;
        double rentalTotal;
    public: 


        //PARAMETERIZED CONSTRUCTOR TO INITALIZE VALUES
        RentalReservation(string ReservationID, string CustomerName, string CarMakeModel, int PickUpDate, int ReturnDate )
        {
            reservationID = ReservationID;
            customerName = CustomerName;
            carMakeAndModel = CarMakeModel;
            pickupDate = PickUpDate;
            returnDate = ReturnDate;
        }

        //CLASS MEMBER DATA TYPES THAT WILL KEEP CHANGES IN EACH OBJECT;
        static bool check[6];
        string CarOption[6];

        
        //DEFAULT CONSTRUCTOR --> CAN BE USE AT THE TIME OF MAKING OBJECT AND ALSO TO KEEP CAR STORAGE
        RentalReservation()
        {
            CarOption[0] = "SuzukiMehran";
            CarOption[1] = "SuzukiAlto";
            CarOption[2] = "HondaCity";
            CarOption[3] = "ToyotaCorolla";
            CarOption[4] = "ToyotaLandCruiser";
            CarOption[5] = "AudiI6";
        }

        void SetRentalresevationdetail(string ReservationID, string CustomerName, string CarMakeModel, int PickUpDate, int ReturnDate );//to take details
        bool ValidateReservationID(); //TO CHECK WHEATHER THE RESERVATION ID IS VALID OR NOT
        void DisplayDate(); //To check wheather the date is between the two dates or not
        bool CarCheck();  //A const member function that validates if the private variable “Car Make and Model” is an existing option.
        double CalculateRentalDuration(); // that will calculate the days 
        double CalculateRentalRate(); //A const member function named calculateRentalRate that calculates and returns the rental rate for a specific car based on its make and model.
        double CalculateRentalTotal(); //A const member function named calculateRentalTotal that calculates and returns the total cost .
        RentalReservation GetRentalReservationDetail();  // that will return details
        void display(); // to display rental detail 
        bool carReturn();
        void carAvailible();
        void CarModelsAvailible();
        ~RentalReservation(){cout<<"The object you created is now destroyed"<<endl;}//destructor
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool RentalReservation::check[6]={false};


//--------------------------------------------------------------------------------------------------------
RentalReservation RentalReservation::GetRentalReservationDetail()
{
    RentalReservation temp;
    temp.reservationID = reservationID;
    temp.customerName = customerName;
    temp.carMakeAndModel = carMakeAndModel;
    temp.pickupDate = pickupDate;
    temp.returnDate = returnDate;
    temp.rentalDuration = rentalDuration;
    temp.rentalRate = rentalRate;
    temp.rentalTotal = rentalTotal;
return temp;
}
//---------------------------------------------------------------------------------------------------------
void RentalReservation::SetRentalresevationdetail(string ReservationID, string CustomerName, string CarMakeModel, int PickUpDate, int ReturnDate )//to take details
{
            reservationID = ReservationID;
            customerName = CustomerName;
            carMakeAndModel = CarMakeModel;
            pickupDate = PickUpDate;
            returnDate = ReturnDate;
}
//---------------------------------------------------------------------------------------------------------
void RentalReservation::display()
{
    cout<<"                     |==================================================================================|\n";
    cout<<"                     |                                    RENTAl DETAIL                                 |\n";
    cout<<"                     |----------------------------------------------------------------------------------|\n\n";
    //displaying reservation ID
    bool flag = false; flag = ValidateReservationID();
        CalculateRentalDuration();
    cout<<"                     ___________________________________________________________________________________|   \n";
    cout<<"                     | Resevation ID           |  ";
                                    if(flag == true){cout<<reservationID<<endl;}else{cout<<"INVALID"<<endl;}
    cout<<"                     |-------------------------|--------------------------------------------------------|\n";
    cout<<"                     | Customer name           |  "<<customerName<<endl;
    cout<<"                     |-------------------------|--------------------------------------------------------|\n";
    cout<<"                     | Car Make and Model      |  "<<carMakeAndModel<<endl;
    cout<<"                     |-------------------------|--------------------------------------------------------|\n";
    cout<<"                     | Car Rate                |  "<<CalculateRentalRate()<<endl;
    cout<<"                     |-------------------------|--------------------------------------------------------|\n";
    cout<<"                     | Total Rent              |  "<<CalculateRentalTotal()<<"$"<<endl;
    cout<<"                     |-------------------------|--------------------------------------------------------|\n";
    DisplayDate();

}
//------------------------------------------------------------------------------------------------------------
bool RentalReservation::ValidateReservationID()
{
    bool flag_1 = false;
    bool flag_2 = false;
    bool flag_3 = false;
    bool flag_4 = false;
    int i = 0, k = 0;
    for (i=0; reservationID[i] != '\0';i++){}//to check the leghnt of reservartionId that must be8
    if(i == 8){flag_1=true;}else{}
    if(flag_1==true){for(int j =0; reservationID[j] !='\0';j++)//to check that in reservationiD there is at least 2 special character
    {if((reservationID[j]>=65&&reservationID[j]<=90)||(reservationID[j]>=97&&reservationID[j]<=122)||(reservationID[j]>='0'&&reservationID[j]<='9'))
    {continue;}else{i++;}}}
    if((i-8)<2){}else{flag_2=true;}
    if(flag_2==true){for(i=4;reservationID[i] != '\0';i++)//to check wheather the sum is less then or not then 18
    {if(reservationID[i]>='0'&&reservationID[i]<='9'){flag_3=true;}else{break;}}}
    if(flag_3==true){for(int i = 4; reservationID[i] != '\0';i++)
    {k+=reservationID[i]-'0';}if(k<18){flag_4=true;}}
    
return flag_4;
}


//------------------------------------------------------------------------------------------------------------
bool RentalReservation::CarCheck()
{
    
    for(int i=0;i<6;i++)
        {if(CarOption[i]==carMakeAndModel)
            {check[i]=true;}}
return 0;
}
bool RentalReservation::carReturn()
{   for(int i=0;i<6;i++)
        {if(CarOption[i]==carMakeAndModel)
            {check[i]=false;}}
return 0;
}
void RentalReservation::carAvailible()
{           
cout<<"                     |==================================================================================|\n";
cout<<"                     |                                   CAR AVAILIBILIY                                |\n";
cout<<"                     |----------------------------------------------------------------------------------|\n\n";
    for(int i=0;i<6;i++)
        {if(CarOption[i]==carMakeAndModel)
            {if(check[i]==true){
cout<<"                     |----------------------------------CAR NOT AVAILIBLE-------------------------------|\n";}
                else{
cout<<"                     |------------------------------------CAR AVIALIBLE---------------------------------|\n";}}}

}
//--------------------------------------------------------------------------------------------------------
void RentalReservation::CarModelsAvailible()
{
cout<<"                      |==================================================================================|\n";
cout<<"                      |                                     CAR OPTIONS                                  |\n";
cout<<"                      |----------------------------------------------------------------------------------|\n\n";
    for(int i=0;i<6;i++)
    {
        if(check[i]==false)
        {
cout<<"                      |     "<<CarOption[i]<<" --- --- --- --- >>> CAR AVAILIBLE \n";
        }
        else
        {
cout<<"                      |     "<<CarOption[i]<<" --- --- --- --- >>> CAR UNAVAILIBLE \n";
        }
    }
}
//--------------------------------------------------------------------------------------------------------
double RentalReservation::CalculateRentalRate()
{
        if(carMakeAndModel == "SuzukiMehran"){rentalRate = 500;}
        else if(carMakeAndModel == "SuzukiAlto"){rentalRate = 550;}
        else if(carMakeAndModel == "HondaCity"){rentalRate = 700;}
        else if(carMakeAndModel == "ToyotaCorolla"){rentalRate = 800;}
        else if(carMakeAndModel == "ToyotaLandCruiser"){rentalRate = 900;}
        else if(carMakeAndModel == "AudiI6"){rentalRate = 1000;}
        return rentalRate;

}
//---------------------------------------------------------------------------------------------------------
double RentalReservation::CalculateRentalDuration()
{
    int a=0, b=0; a=pickupDate%100000000; b=a/1000000; //cout<<b<<endl; //pickup Day
    int c=0, d=0; c=returnDate%100000000; d=c/1000000; //cout<<d<<endl; //return day
    int e=0, f=0; e=pickupDate%1000000; f=e/10000; //cout<<f<<endl; // pickup month
    int g=0, h=0; g=returnDate%1000000; h=g/10000; //cout<<h<<endl; // return month
    int i=0, j=0; i=pickupDate%10000; j=i/1; //cout<<j<<endl; //pickup year
    int k=0, l=0; k=returnDate%10000; l=k/1; //cout<<l<<endl;// return year
    int m=0; if(f%2==0){m=(30-b)+d;}else if(f==2){m=(29-b)+d;}else{m=(31-b)+d;}
    int n=0; n=((12-f)+h)-1;
    while(m>30){n++;m=m-30;}
    int o=0; if(n<=12){o=(l-j)-1;}else{o=(l-j)-1;}
    while(n>=12){o++;n=n-12;}
    
   
    rentalDuration=(365*o)+((30*n)+(n/2))+m;//cout<<p<<endl;
return 0;

}
//-------------------------------------------------------------------------------------------------------------
void RentalReservation::DisplayDate()
{
    string M[13]; M[0]=""; M[1]="JAN";M[2]="FEB";M[3]="MAR";M[4]="APR";M[5]="MAY";M[6]="JUN";M[7]="JUL";M[8]="AUG";
    M[9]="SEP";M[10]="OCT";M[11]="NOV";M[12]="DEC";
    int a=0, b=0; a=pickupDate%100000000; b=a/1000000; //cout<<b<<endl; //pickup Day
    int c=0, d=0; c=returnDate%100000000; d=c/1000000; //cout<<d<<endl; //return day
    int e=0, f=0; e=pickupDate%1000000; f=e/10000; //cout<<f<<endl; // pickup month
    int g=0, h=0; g=returnDate%1000000; h=g/10000; //cout<<h<<endl; // return month
    int i=0, j=0; i=pickupDate%10000; j=i/1; //cout<<j<<endl; //pickup year
    int k=0, l=0; k=returnDate%10000; l=k/1; //cout<<l<<endl;// return year
    int m=0; if(f%2==0){m=(30-b)+d;}else if(f==2){m=(29-b)+d;}else{m=(31-b)+d;}
    int n=0; n=((12-f)+h)-1;
    while(m>30){n++;m=m-30;}
    int o=0; if(n<=12){o=(l-j)-1;}else{o=(l-j)-1;}
    while(n>=12){o++;n=n-12;}
    cout<<"                     | Pickup Date             |  "<<b<<"/"<<M[f]<<"/"<<j<<endl;
    cout<<"                     |-------------------------|--------------------------------------------------------|\n";
    cout<<"                     | Return Date             |  "<<d<<"/"<<M[h]<<"/"<<l<<endl;
    cout<<"                     |-------------------------|--------------------------------------------------------|\n";
    cout<<"                     | Rental Duration         |  "<<o<<" year "<<n<<" month "<<m<<" days "<<endl;
    cout<<"                     |_________________________|________________________________________________________|\n\n\n";
    
}
//------------------------------------------------------------------------------------------------------------
double RentalReservation::CalculateRentalTotal()
{
    
    rentalTotal = rentalRate * rentalDuration;//cout<<rentalTotal<<endl;
    return rentalTotal;
}
//----------------------------------------------------------------------------------------------------------
int main()
{
cout<<"                      |==================================================================================|\n";
cout<<"                      |                                     CAR RENT SERVICE                             |\n";
cout<<"                      |----------------------------------------------------------------------------------|\n\n";

    // RentalReservation C1("MM##1234", "Maaz", "SuzukiMehran",12032023,12052023,14072024);
    // C1.display();
    // RentalReservation C2("MM##1234", "sammar", "ToyotaCorolla",12032023,12052023,14072024);
    // C2.display();

        string reservationID;
        string customerName;
        string carMakeAndModel;
        int pickupDate;
        int returnDate;
        int num;
    RentalReservation C1[10];
    for(int i=0;i<10;i++)
    {
        cout<<"if you want to return a car then press 2 and if renting a car the press 1  =  ";cin>>num;cout<<endl;
        if(num==1)
        {
            C1[i].CarModelsAvailible();
        cout<<"Enter your name : ";cin>>customerName;
        cout<<"Enter car make and model : ";cin>>carMakeAndModel;
        cout<<"Enter resevation ID : ";cin>>reservationID;
        cout<<"Enter the pickup date in the format DDMMYYYY : ";cin>>pickupDate;
        cout<<"Enter the return date date in the format DDMMYYYY : ";cin>>returnDate;
        C1[i].SetRentalresevationdetail(reservationID,customerName,carMakeAndModel,pickupDate,returnDate);
        C1[i].carAvailible();
        C1[i].CarCheck();
        C1[i].display();
        cout<<"==================================================================================================================\n";
        }
        else if(num==2)
        {
        cout<<"Enter your name : ";cin>>customerName;
        cout<<"Enter car make and model you want to return : ";cin>>carMakeAndModel;
        cout<<"Enter resevation ID : ";cin>>reservationID;
        cout<<"Enter the pickup date in the format DDMMYYYY : ";cin>>pickupDate;
        cout<<"Enter the return date date in the format DDMMYYYY : ";cin>>returnDate;
        C1[i].SetRentalresevationdetail(reservationID,customerName,carMakeAndModel,pickupDate,returnDate);
        C1[i].carReturn();
        C1[i].carAvailible();
        C1[i].display();
        }}

        
        

    
    

    

    return 0;
}