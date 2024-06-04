#include<iostream>
#include<string>
#include<cstring>
using namespace std ;

class Profile 
{
    private:
        string userID;
        string userName;
        int numOfPost;
        string email;
        int followers;
        int likes;
        int comments;
        string password;
        string profilePic;
        int num;
    public:
    //--------------------------------------------------------------------------------------------------------
        static Profile UserProfile[10];
        static string UserID[10];
    //--------------------------------------------------------------------------------------------------------
        Profile(string id, string name, string Email, string pass, int Followers, int Post, int Comments, int Likes) 
        {
            userID = id;
            userName = name;
            numOfPost = Post;
            email = Email;
            followers = Followers;
            likes = Likes;
            comments = Comments;
            password = pass;
            profilePic = "default.jpg";
        }
        Profile(){}
    //--------------------------------------------------------------------------------------------------------
    ~Profile(){cout << "Profile object with userName " << userName << " is destroyed." << endl;}
    //--------------------------------------------------------------------------------------------------------
    void GetUserDetail(string id, string name, string Email, string pass, int Followers, int Post, int Comments, int Likes);
    string SetUserName(){return userName;}
    void SetUserProfileDetail(int n);
    void userProfile(string userid);
    void DisplayUserProfiledetail(int n);
    bool CheckPassword( string password);
    bool validateEmail(string email);

    int SetNum();
};
//------------------------------------------------------------------------------------------------------------
void Profile::GetUserDetail(string id, string name, string Email, string pass, int Followers, int Post, int Comments, int Likes)
{
            userID = id;
            userName = name;
            numOfPost = Post;
            email = Email;
            followers = Followers;
            likes = Likes;
            comments = Comments;
            password = pass;
            profilePic = "default.jpg";
}
//------------------------------------------------------------------------------------------------------------
    Profile Profile::UserProfile[10]={};
    string Profile::UserID[10]={};
//------------------------------------------------------------------------------------------------------------
    void Profile::SetUserProfileDetail(int n)
    {   
        UserID[n] = userID;
        UserProfile[n].userID=userID;
        UserProfile[n].userName=userName;
        UserProfile[n].password=password;
        UserProfile[n].email=email;
        UserProfile[n].comments=comments;
        UserProfile[n].followers=followers;
        UserProfile[n].numOfPost=numOfPost;
        UserProfile[n].likes=likes;
        UserProfile[n].profilePic=profilePic;
    }
//-------------------------------------------------------------------------------------------------------------
    void Profile::userProfile(string userid)
    {for(int i=0; i<10;i++)
        {if(UserID[i]==userid)
            {num=i;
                DisplayUserProfiledetail(i);}}
    }
//-------------------------------------------------------------------------------------------------------------
    int Profile::SetNum(){return num;}
//-------------------------------------------------------------------------------------------------------------
    void Profile::DisplayUserProfiledetail(int n)
    {
cout<<"                     |==================================================================================|\n";
cout<<"                     |                                   PROFILE DETAILS                                |\n";
cout<<"                     |----------------------------------------------------------------------------------|\n";
cout<<"                     |                             |                                                    |\n";
cout<<"                     |   The user ID is            |    "<<UserProfile[n].userID<<endl;
cout<<"                     |-----------------------------|----------------------------------------------------|\n";
cout<<"                     |   The user name is          |    "<<UserProfile[n].userName<<endl;
cout<<"                     |-----------------------------|----------------------------------------------------|\n";
cout<<"                     |   The user password         |    "<<UserProfile[n].password<<endl;
cout<<"                     |-----------------------------|----------------------------------------------------|\n";
cout<<"                     |   The user email            |    "<<UserProfile[n].email<<endl;
cout<<"                     |-----------------------------|----------------------------------------------------|\n";
cout<<"                     |   The comments are          |    "<<UserProfile[n].comments<<endl;
cout<<"                     |-----------------------------|----------------------------------------------------|\n";
cout<<"                     |   The number of followers   |    "<<UserProfile[n].followers<<endl;
cout<<"                     |-----------------------------|----------------------------------------------------|\n";
cout<<"                     |   The numbers of posts      |    "<<UserProfile[n].numOfPost<<endl;
cout<<"                     |-----------------------------|----------------------------------------------------|\n";
cout<<"                     |   The numbers of post       |    "<<UserProfile[n].profilePic<<endl;
cout<<"                     |-----------------------------|----------------------------------------------------|\n";
    }
//------------------------------------------------------------------------------------------------------------
bool Profile::CheckPassword(string password)
{
    bool flag_4 = false; 
    bool flag_1 = false;
    bool flag_2 = false;
    bool flag_3 = false;
    int i=0;
    for( i=0;password[i]!='\0';i++){}
    if(i<8){
cout<<"                     |  VERY SHORT PASSWORD                                                             |\n";}


    for(int  j=0;password[j]!='\0';j++)
    {
        if(password[j]>=65&&password[j]<=90){flag_1 = true;}
        else if(password[j]>=97&&password[j]<=122){flag_2 = true;}
        else if(password[j]>='0' && password[j]<='9'){flag_3 = true;}
    }

    if(flag_1 == true && flag_2 == true && flag_3 == true)
    {
cout<<"                     |  PASSWORD VERIFIED                                                               |\n";
    flag_4=true;
    }
    else
    {
cout<<"                     |  VERY WEAK PASSWORD                                                              |\n";
    }
    if(flag_1 != true )
    {
cout<<"                     |  NO UPPERCASE LETTER                                                             |\n";
    }
    if(flag_2 != true)
    {
cout<<"                     |  NO LOWERCASE LETTER                                                             |\n";
    }
    if(flag_3 != true)
    {
cout<<"                     |  DIGIT MISSING                                                                   |\n";
    }
  
return flag_4;
}
//---------------------------------------------------------------------------------------------------
bool Profile::validateEmail(string email)
{
if (email.empty()) {return false;}
        bool flag1 = false;
            bool flag2 = false;
                bool flag3 = false;
                    for (size_t i = 0; i < email.size(); i++) 
{char c = email[i];
    if (c == '@') 
        {if (flag1 || i == 0 || i == email.size() - 1 || flag2)
            {flag3 = true;break;}
                flag1 = true;}
    else if (c == '.') 
        {if (flag2 || i == 0 || i == email.size() - 1 || !flag1) {
            flag3 = true;break;}
                flag2 = true;}
    else if (!isalnum(c) && c != '_' && c != '-') 
        {flag3 = true;
            break;}}
    if (!flag1 || !flag2 || flag3) 
        {return false;}
return true;
}
//---------------------------------------------------------------------------------------------------
int main() 
{
        string userID;
        string userName;
        int numOfPost;
        string email;
        int followers;
        int likes;
        int comments;
        string password;
        int num=0;
        int num1=0;
        Profile C1[10];
cout<<"                     |==================================================================================|\n";
cout<<"                     |                         WELCOME TO OUR SOCIALMEDIA PLATFORM                      |\n";
cout<<"                     |----------------------------------------------------------------------------------|\n\n";
    for(int i=0;i<10;i++)
    {
cout<<"                     |  If you want to make new profile then PRESS 1 and if you want to edit your older \n                     |  profile then PRESS 2  and if quit then PRESS 3 ::  ";
        cin>>num;cout<<endl;
        if(num==1)
        {
cout<<"                     |  Enter the username : ";cin>>userName;
cout<<"                     |  Enter the userID : ";cin>>userID;
cout<<"                     |  Enter your Email : ";cin>>email;
if(C1[i].validateEmail(email)!=1){
while(C1[i].validateEmail(email)!=1)
{
cout<<"                     |  EMAIL NOT IN CORRECT FORMAT PLZ CHOOSE ANOTHER  : ";cin>>email;}}
else if(C1[i].validateEmail(email)==1)
{cout<<"                     |   EMAIL VERIFIED                                                                 |\n";}
cout<<"                     |  Use UPPER and LOWER CASE LETTER , SPECIAL CHARACTER and NUMBERS and length      |\n";
cout<<"                     |  Should be GREATER then 8                                                        |\n";
cout<<"                     |  Enter the PASSWORD as strong as you can : ";cin>>password;
while(C1[i].CheckPassword(password)!=1)
{
cout<<"                     |  If you want to change the password then PRESS 1 ELSE 2 : ";cin>>num;
    if(num==1)
    {
cout<<"                     |  Enter the PASSWORD as strong as you can : ";cin>>password;
    }
    else if(num==2){break;}
}
cout<<"                     |  Enter the number of posts : ";cin>>numOfPost;
cout<<"                     |  Enter your followers : ";cin>>followers;
cout<<"                     |  Enter your comments : ";cin>>comments;
cout<<"                     |  Enter the numbers of likes : ";cin>>likes;
cout<<"                     |==================================================================================|\n";
cout<<"                     |                        CONGRAJULATIONS! YOUR PROFILE IS READY                    |\n";
cout<<"                     |----------------------------------------------------------------------------------|\n\n";
            C1[i].GetUserDetail(userID,userName,email,password,followers,numOfPost,comments,likes);
            C1[i].SetUserProfileDetail(i);
        }
        else if(num==2)
        {
cout<<"                     |  Enter userID which you want to edit :  ";cin>>userID;
            C1[i].userProfile(userID);
cout<<"I                    |  If you want to edit it then PRESS 1 ELSE 2 : ";cin>>num;
            if(num==1)
            {
                num1=C1[i].SetNum();
cout<<"                     |  Enter the username : ";cin>>userName;
cout<<"                     |  Enter the userID : ";cin>>userID;
cout<<"                     |  Enter your Email : ";cin>>email;
if(C1[i].validateEmail(email)!=1){
while(C1[i].validateEmail(email)!=1)
{
cout<<"                     |  EMAIL NOT IN CORRECT FORMAT PLZ CHOOSE ANOTHER  : ";cin>>email;}}
else if(C1[i].validateEmail(email)==1)
{cout<<"                     |   EMAIL VERIFIED                                                                 |\n";}
cout<<"                     |  Use UPPER and LOWER CASE LETTER , SPECIAL CHARACTER and NUMBERS and length      |\n";
cout<<"                     |  Should be GREATER then 8                                                        |\n";
cout<<"                     |  Enter the PASSWORD as strong as you can : ";cin>>password;
while(C1[i].CheckPassword(password)!=1)
{
cout<<"                     |  If you want to change the password then PRESS 1 ELSE 2 : ";cin>>num;
    if(num==1)
    {
cout<<"                     |  Enter the PASSWORD as strong as you can : ";cin>>password;
    }
    else if(num==2){break;}
}
cout<<"                     |  Enter the number of posts : ";cin>>numOfPost;
cout<<"                     |  Enter your followers : ";cin>>followers;
cout<<"                     |  Enter your comments : ";cin>>comments;
cout<<"                     |  Enter the numbers of likes : ";cin>>likes;
cout<<"                     |==================================================================================|\n";
cout<<"                     |                      CONGRAJULATIONS! YOUR PROFILE IS UPDATED                    |\n";
cout<<"                     |----------------------------------------------------------------------------------|\n\n";
                C1[num1].GetUserDetail(userID,userName,email,password,followers,numOfPost,comments,likes);
                C1[num1].SetUserProfileDetail(num1);

        }i--;}
        else if(num==3)
        {break;}
    }
    
    return 0;
}
