#include<iostream>
#include<cmath>
using namespace std;
struct Average
{
    private:
        int a;
        int b;
    public:
       
        void setNum(int n1, int n2);
        friend Average sumPoints(Average o1, Average o2);
        int printNum();
};
void Average::setNum(int n1, int n2)
{
        a = n1;
        b = n2;
        
}
int Average::printNum()
{
    int num=0;
    num=sqrt(a+b);
    return num;
}
Average sumPoints(Average o1, Average o2)
{
    Average o3;
    o3.setNum(((o2.a - o1.a)*(o2.a - o1.a)), ((o2.b - o1.b)*(o2.b - o1.b)));
    return o3;
}                                          
int main()
{  
            int MN[8][3];
            int M[8],N[8];
            float A1[10][3],A2[10][3];
            int GR[8];
            M[0] = 2; N[0] = 10;
            M[1] = 2; N[1] = 5;
            M[2] = 8; N[2] = 4;
            M[3] = 5; N[3] = 8;
            M[4] = 7; N[4] = 5;
            M[5] = 6; N[5] = 4;
            M[6] = 1; N[6] = 2;
            M[7] = 4; N[7] = 9;
A1[0][0]=2;
A2[0][0]=10;
A1[0][1]=5;
A2[0][1]=8;
A1[0][2]=1;
A2[0][2]=2;

//int k=0;
    Average c1, c2, sum,c3;
for(int k=0;k<5;k++)
   {
    for(int i=0;i<8;i++)
    {  
        c1.setNum(A1[k][0],A2[k][0]);
        c2.setNum(M[i],N[i]);
        sum=sumPoints(c1,c2);
        MN[i][0]=sum.printNum();
        c1.setNum(A1[k][1],A2[k][1]);
        c2.setNum(M[i],N[i]);
        sum=sumPoints(c1,c2);
        MN[i][1]=sum.printNum();
        c1.setNum(A1[k][2],A2[k][2]);
        c2.setNum(M[i],N[i]);
        sum=sumPoints(c1,c2);
        MN[i][2]=sum.printNum();
    }
    for(int i=0;i<8;i++)
        { int group=MN[i][0];
        for(int j=0;j<3;j++)
        {if(MN[i][j]<group)
        {GR[i]=j+1;group=MN[i][j];}
        else if(MN[i][j]==group)
        {GR[i]=j+1;}}}

cout<<"|==================================================================================|\n";
cout<<"|                                      DATA SET                                    |\n";
cout<<"|----------------------------------------------------------------------------------|\n\n";

    cout<<"          ( "<<A1[k][0]<<","<<A2[k][0]<<" )"<<"   ,   "<<"( "<<A1[k][1]<<","<<A2[k][1]<<" )"<<"   ,   "<<"( "<<A1[k][2]<<","<<A2[k][2]<<" )" <<"    N\n";
    for(int i=0;i<8;i++)
    {   
        cout<<"( "<<M[i]<<","<<N[i]<<" )        ";
        for(int j=0;j<3;j++)
        {
            cout<<MN[i][j]<<"           ";
        }cout<<GR[i]<<"\n";
    }cout<<endl;
cout<<"|==================================================================================|\n";
cout<<"|                                 SPECIFYING GROUP                                 |\n";
cout<<"|----------------------------------------------------------------------------------|\n\n";
cout<<"            FOR GROUP = 1    ";
for(int i=0;i<8;i++)
{if(GR[i]==1){cout<<"( "<<M[i]<<","<<N[i]<<" ) , ";}}cout<<endl;

cout<<"            FOR GROUP = 2    ";
for(int i=0;i<8;i++)
{if(GR[i]==2) {cout<<"( "<<M[i]<<","<<N[i]<<" ) , ";}}cout<<endl;

cout<<"            FOR GROUP = 3    ";
for(int i=0;i<8;i++)
{if(GR[i]==3){cout<<"( "<<M[i]<<","<<N[i]<<" ) , ";}}cout<<"\n\n";

cout<<"|==================================================================================|\n";
cout<<"|                      TAKING AVERAGES OF CORRESRPONDING GROUPS                    |\n";
cout<<"|----------------------------------------------------------------------------------|\n\n";

float n=0,m=0,o=0;
for(int i=0;i<8;i++)
{if(GR[i]==1){n+=N[i];m+=M[i];o++;}};        
A1[k+1][0]=m/o;A2[k+1][0]=n/o;
m=0,n=0,o=0;
for(int i=0;i<8;i++)
{if(GR[i]==2){n+=N[i];m+=M[i];o++;}};
A1[k+1][1]=m/o;A2[k+1][1]=n/o;
m=0,n=0,o=0;
for(int i=0;i<8;i++)
{if(GR[i]==3){n+=N[i];m+=M[i];o++;}};
A1[k+1][2]=m/o;A2[k+1][2]=n/o;
cout<<A1[k+1][0]<<" "<<A2[k+1][0]<<endl;
cout<<A1[k+1][1]<<" "<<A2[k+1][1]<<endl;
cout<<A1[k+1][2]<<" "<<A2[k+1][2]<<endl;


if(((A1[k][0]==A1[k-1][0])&&(A2[k][0]==A2[k-1][0])) && ((A1[k][1]==A1[k-1][1])&&(A2[k][1]==A2[k-1][1])) && ((A1[k][2]==A1[k-1][2])&&(A2[k][2]==A2[k-1][2])))
{
cout<<"|==================================================================================|\n";
cout<<"|                    BECOME SAME AVERAGE VALUES AT ITERATION = "<<k<<"                   |\n";
cout<<"|----------------------------------------------------------------------------------|\n\n";
break;
}
}



    return 0;
}



