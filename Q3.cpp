#include<iostream>
#include"String.h"
using namespace std;
int main() 
{

    String obj1;
    cout << "obj1: ";
    obj1.print();
    
    String obj2(10);
    cout << "obj2: ";
    obj2.print();
    
    String obj3("Hello, world!");
    cout << "obj3: ";
    obj3.print();
    
    String obj4("Hello_world");
    cout<<"obj4: ";
    obj4.print();
    
    String obj5("helloWorld");
    int startIndex=0, endIndex=0;
    char*  const word = new char;
    char*  const str = new char;
    string str1;    
    char c;
    cout<<obj5.getdata()<<endl;

    // cout<<"Enter the character you want to find in  string  = ";cin>>c;
    // cout<<"Index of the character is  "<<obj5.charAt(c)<<endl;
    cout<<"Enter the string to check wheather the strings are equal or not = ";
    cin>>word;
    cout<<"equal case : ";
    if(obj5.equals(word)==1){cout<<"two strings are equal\n";}else{cout<<"two strings are not equal\n";}
    cout<<"equal iqnore case : ";
    if(obj5.equalsIgnoreCase(word)==1){cout<<"two strings are equal\n";}else{cout<<"two strings are not equal\n";}




    String obj6("wellDone");
    obj6.print();
    cout<<"Enter the string to check its substr = ";
    cin>>str;
    cout<<"Enter the start index  :  ";cin>>startIndex;
    cout<<"The substring is : ";

    obj6.substring(str,startIndex);
    

cout<<"Enter the string to check its substr = ";
    cin>>str;
    cout<<"Enter the start index  :  ";cin>>startIndex;

    cout<<"Enter the endindex  :  ";cin>>endIndex;
    cout<<"The substring is  :  "<<obj5.substring(str,startIndex,endIndex)<<endl;



    





    return 0;

}
