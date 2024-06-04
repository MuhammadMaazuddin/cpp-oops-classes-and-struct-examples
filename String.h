#include <iostream>
#include<cstring>
using namespace std;

//-----funtions of cstring

// strcpy implementation
// void strcpy(char* dest,const char*  src) {
//   while (*src != '\0') {
//     *dest = *src;
//     src++;
//     dest++;
//   }
//   *dest = '\0';
// }

// // strcmp implementation
// int strcmp(const char*  str1,const char* str2) 
// {
//   for(int i=0; str1[i] != '\0' && str2[i] != '\0';i++) 
//   {
//     if (*str1 != *str2) {
//       return (*str1 - *str2);
//     }
//     // str1++;
//     // str2++;
//   }
//   return (*str1 - *str2);
// }

// // strncpy implementation
// void strncpy(char* dest,const char* src, int n) 
// {
//   int i = 0;
//   while (*src != '\0' && i < n) 
//   {
//     *dest = *src;
//     src++;
//     dest++;
//     i++;
//   }
//   *dest = '\0';
// }

// // strncmp implementation
// int strncmp(const char* str1,const char* str2, int n) {
//   int i = 0;
//   while (*str1 != '\0' && *str2 != '\0' && i < n) {
//     if (*str1 != *str2) {
//       return (*str1 - *str2);
//     }
//     str1++;
//     str2++;
//     i++;
//   }
//   if (i == n) {
//     return 0;
//   }
//   return (*str1 - *str2);
// }
//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
class String 
{
    private:
        char* data;
        int length;
    public:
    // Default constructor
    String() 
    {
        data = nullptr;
        length = 0;
    }
    
    // Alternate constructor 1
    String(int size) 
    {
        data = new char[size];
        length = size;
    }
    
    // Alternate constructor 2
    String(const char* str) 
    {
        int num1=0;
        for(num1=0;num1<str[num1]!='\0';num1++){}
        length = num1;
        data = new char[length];
        //copying content of str into data after making dynamic array of data
        for(int i=0;str[i]!='\0';i++)
        {
            data[i]=str[i];
        }
    }
    
    // Copy constructor
    String(const String& str) 
    {
        length = str.length;
        data = new char[length];
        //copying content of data into member (str) of object of str 
        //strcpy(data, str.data);
        for(int i=0;str.data[i]!='\0';i++)
        {
            data[i]=str.data[i];
        }
    }
    
    // Destructor
    ~String() 
    {
        delete[] data;
    }
    
    // Getters
    int strLength() const 
    {
        return length;
    }
    
    char* getdata() const 
    {
        return data;
    }
    
    // Clear function
    void clear() 
    {
        delete[] data;
        data = nullptr;
        length = 0;
    }
    
    // Empty function
    bool empty() const 
    {
        return (length == 0);
    }
    
    // CharAt function
    int charAt(char c) const 
    {
        for (int i = 0; i < length; i++) 
        {
            if (data[i] == c) 
            {
                return i+1;
            }
        }
        return -1;
    }
    
    // Equals function
    bool equals(const char*  str) const 
    {
        
        bool flag=true;
        int num1=0; int num2=0;
        for(num1=0;num1<data[num1]!='\0';num1++){}
        //cout<<num1<<endl;
        for(num2=0;num2<str[num2]!='\0';num2++){}
        //cout<<num2<<endl;
        if(num1==num2)
        {
            for(int i=0;i<num1;i++)
            {
                if(data[i]!=str[i])
                {
                    flag=false;
                    break;
                }
                else{continue;}
            }
        }
        else{flag=false;}
        return flag;
    }
    
    // EqualsIgnoreCase function
    bool equalsIgnoreCase(const char* str) const 
    {
        bool flag=true;
        int num1=0; int num2=0;
        for(num1=0;num1<data[num1]!='\0';num1++){}
        for(num2=0;num2<str[num2]!='\0';num2++){}
        char*  const str2 = new char;
        if(num1==num2)
        {for(int i=0;i<num1;i++)
            {if(data[i]>=97&&data[i]<=122)
                    {data[i]=data[i]-32;}
                      else if(data[i]>=65&&data[i]<=90)
                        {continue;}}
            for(int i=0;i<num2;i++)
                {if(str[i]>=97&&str[i]<=122)
                    {str2[i]=str[i]-32;}
                        else if(str[i]>=65&&str[i]<=90)
                            {str2[i]=str[i];}}


            for(int i=0;i<num1;i++)
                {if(data[i]!=str2[i])
                    {flag=false;
                        break;}
                            else{continue;}}}
                                else{flag=false;}
        return flag;
    }
    
    // Substring function (1 parameter)
    char* substring(const char*  substr, int startIndex) const 
    {
        
        int num1=0; int num2=0;
        for(num1=0;num1<data[num1]!='\0';num1++){}
        for(num2=0;num2<substr[num2]!='\0';num2++){}
        char*  const str2 = new char;
            for(int i=startIndex;i<num1;i++)
                {if(data[i]==substr[i])
                    {str2[i]=data[i];}}
                        for(int i=startIndex;i<num1;i++)
                            {cout<<str2[i];}cout<<endl;
return str2;
    }
    
    // Substring function (2 parameters)
    char* substring(const char* substr, int startIndex, int endIndex)const 
    {
        int num1=0; int num2=0;
        for(num1=0;num1<data[num1]!='\0';num1++){}
        for(num2=0;num2<substr[num2]!='\0';num2++){}
        char*  const str2 = new char;
            for(int i=startIndex;i<endIndex;i++)
                {if(data[i]==substr[i])
                    {str2[i]=data[i];}}
                        for(int i=startIndex;i<endIndex;i++)
                            {cout<<str2[i];}cout<<endl;
return str2;
    }
    
    // Print function
    void print() const 
    {
        if (data == nullptr || length == 0) 
        {
            cout << "NULL" <<endl;
        }
        else {
            cout << data << endl;
        }
    }
};
