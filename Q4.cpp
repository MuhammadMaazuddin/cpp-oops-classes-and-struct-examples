#include<iostream>
using namespace std;
class Matrix
{
    private:
        int **matrix;
        int row;
        int column;
    public:
        Matrix(){};
        Matrix(int n1, int n2, int n3, int n4, int row = 2, int col = 2)
        {
            this->row = row;
            this->column = col;
            matrix = new int*[row];
            for (int i = 0; i < row; i++) 
            {
                matrix[i] = new int[col];
            }
            matrix[0][0] = n1;
            matrix[0][1] = n2;
            matrix[1][0] = n3;
            matrix[1][1] = n4;
        }
        Matrix (int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int row = 3, int col = 3)
        {
            this->row = row;
            this->column = col;
                matrix = new int*[row];
            for (int i = 0; i < row; i++) 
            {
                matrix[i] = new int[col];
            }
            matrix[0][0] = n1;
            matrix[0][1] = n2;
            matrix[0][2] = n3;
            matrix[1][0] = n4;
            matrix[1][1] = n5;
            matrix[1][2] = n6;
            matrix[2][0] = n7;
            matrix[2][1] = n8;
            matrix[2][2] = n9;
        }
        Matrix (int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int n10, int n11,int n12, int n13, int n14, int n15, int n16, int row = 4, int col = 4)
        {
            this->row = row;
            this->column = col;
                matrix = new int*[row];
            for (int i = 0; i < row; i++) 
            {
                matrix[i] = new int[col];
            }
            matrix[0][0] = n1;
            matrix[0][1] = n2;
            matrix[0][2] = n3;
            matrix[0][3] = n4;
            matrix[1][0] = n5;
            matrix[1][1] = n6;
            matrix[1][2] = n7;
            matrix[1][3] = n8;
            matrix[2][0] = n9;
            matrix[2][1] = n10;
            matrix[2][2] = n11;
            matrix[2][3] = n12;
            matrix[3][0] = n13;
            matrix[3][1] = n14;
            matrix[3][2] = n15;
            matrix[3][3] = n16;
        }
        Matrix(const Matrix &m)
        {

            row = m.row;
            column = m.column;
                matrix = new int*[row];
            for (int i = 0; i < row; i++) 
            {
                matrix[i] = new int[column];
                for (int j = 0; j < column; j++) 
                {
                    matrix[i][j] = m.matrix[i][j];
                }
            }
        }
        ~Matrix()
        {
		
        }
        void display(); //to display matrix
        int getRow(); // a getter for rows
        int getCol(); // a getter for columns
        int getValue(int row, int col); // a function to get the value at the given row and column of a matrix
        void setValue(int row, int col, int value); // a function to set the value at a given row andcolumn index of a matrix.
        int Total(); // Calculate the total/sum of all the values in the matrix.
        double Average(); //Calculates average of all the values in the array.
        int RowTotal(int row); //Calculates total/sum of the values in the specified row.
        int ColumnTotal(int col);  //Calculates total/sum of the values in the specified column.
        int HighestInRow(int row); //Finds highest value in the specified row of the array.
        int LowestInRow(int row);  //Finds lowest value in the specified row of the array.
        Matrix Transpose();        //Find Transpose of array.
        int LeftDiagonalTotal();   //Calculates total/sum of the values in the leftDiagonal of array.
        int RightDiagonalTotal();  //Calculates total/sum of the values in the right Diagonal ofarray.
        Matrix Add(Matrix m);      //adds the calling object matrix with the one passed as anargument and returns a resultant matrix
        Matrix Subtract(Matrix m); //subtracts the calling object matrix with the one passed as anargument and returns a resultant matrix
        Matrix Multiply(Matrix m); //multiplies the calling object matrix with the one passed as an argument and returns a resultant matrix
        int FindkSmallest(int k);  //a function that finds the kth smallest element in the matrix. If k is1, return the smallest element. If k is 2 return the second smallest element andso on.
        int FindkLargest(int k);   //a function that finds the kth largest element in the matrix. Ifk is1, return the largest element. If k is 2 return the second largest element and so on.
        Matrix merge(Matrix m);    //a function to merge two matrices. E.g.
        void displayMerge();
};
int Matrix::getRow()
{ return row; }
//-------------------------------------------------------------
int Matrix::getCol()
{ return column; }
//-------------------------------------------------------------
int Matrix::getValue(int row, int col)
{ return matrix[row][col]; }
//-------------------------------------------------------------
void Matrix::setValue(int row, int col, int value)
{matrix[row][col] = value; }
//-------------------------------------------------------------
int Matrix::Total()
{   int sum = 0;
        for(int i=0 ; i<row; i++)
            {for(int j=0 ; j<column ; j++)
                { sum = sum + matrix[i][j]; } }
return sum;
}
//--------------------------------------------------------------
double Matrix::Average()
{   int sum = Total(); float average = 0;
        average = sum/(row*column);
return average;
}
//---------------------------------------------------------------
int Matrix::RowTotal(int row)
{   int sum = 0;
        for(int i=0 ; i<column; i++)
            {for(int j=0 ; j<column; j++)
                {if(i == row){sum+=matrix[i][j];}}}
return sum;
}
//----------------------------------------------------------------
int Matrix::ColumnTotal(int col)
{   int sum = 0;
        for(int i=0 ; i<row; i++)
            {for(int j=0 ; j<row; j++)
                {if(j == col){sum+=matrix[i][j];}}}
return sum;
}
//----------------------------------------------------------------
int Matrix::HighestInRow(int row)
{
    int HighestInRow = matrix[row][0];
    for(int i=0 ; i<column; i++)
        {for(int j=0 ; j<column; j++)
            {if(i == row)
                {if(matrix[i][j]>HighestInRow)
                    {HighestInRow = matrix[i][j];}}}}
return HighestInRow;
}
//----------------------------------------------------------------
int Matrix::LowestInRow(int row)
{   int LowestInRow = matrix[row][0];
        for(int i=0 ; i<column; i++)
            {for(int j=0 ; j<column; j++)
                {if(i == row)
                    {if(matrix[i][j]<LowestInRow)
                        {LowestInRow = matrix[i][j];}}}}
return LowestInRow;
}
//------------------------------------------------------------------
Matrix Matrix::Transpose()
{   Matrix temp;
        for(int i=0;i<row;i++)
            {for(int j=0;j<row;j++)
                {temp.matrix[i][j]=matrix[j][i];}}
return temp;
}
//------------------------------------------------------------------
int Matrix::LeftDiagonalTotal()
{   int sum = 0;
        for(int i=0 ; i<column; i++)
            {for(int j=0 ; j<column; j++)
                {if(i  == j)
                    {sum+=matrix[i][j];}}}
return sum;
}
//-----------------------------------------------------------------
int Matrix::RightDiagonalTotal()
{   int num = row;int sum = 0;
        for(int i=0 ; i<column; i++)
            {sum += matrix[i][row - i - 1];}
return sum;
}
//-----------------------------------------------------------------
Matrix Matrix::Add(Matrix m)
{   Matrix temp(m);
        for(int i = 0; i<row; i++)
            {for(int j=0; j<row;j++)
                {temp.matrix[i][j] = matrix[i][j] + m.matrix[i][j];}}
return temp;  
}
//------------------------------------------------------------------
Matrix Matrix::Subtract(Matrix m)
{   Matrix temp(m);
        for(int i = 0; i<row; i++)
            {for(int j=0; j<row;j++)
                {temp.matrix[i][j] = matrix[i][j] - m.matrix[i][j];}}
return temp;  
}
//-------------------------------------------------------------------
Matrix Matrix::Multiply(Matrix m)
{   int sum;
        Matrix temp(m);
            for(int i = 0; i<row; i++)
                {for(int j=0; j<row;j++)
                    {sum=0;for(int k=0; k<row;k++)
                        {sum += matrix[i][k] * m.matrix[k][j];}
                            temp.matrix[i][j] = sum;}}
return temp;  
}
//--------------------------------------------------------------------
int Matrix::FindkSmallest(int k)
{   int flat[row * row];int num = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < row; j++) 
                {flat[num++] = matrix[i][j];}}
                    for (int i = 0; i < row * row; i++) 
                        {int minIndex = i;
                            for (int j = i + 1; j < row * row; j++) 
                                {if (flat[j] < flat[minIndex]) 
                                    {minIndex = j;}}
                                        swap(flat[i], flat[minIndex]);
                                            if (i == k - 1) 
                                                {return flat[i];}}
return -1;
}
//---------------------------------------------------------------------
int Matrix::FindkLargest(int k)
{   int flat[row * row];int num = 0;
        for (int i = 0; i < row; i++) 
            {for (int j = 0; j < row; j++) 
                {flat[num++] = matrix[i][j];}}
                    for (int i = 0; i < row * row; i++)
                        {int maxIndex = i;
                            for (int j = i + 1; j < row * row; j++) 
                                {if (flat[j] > flat[maxIndex]) 
                                    {maxIndex = j;}}
                                        swap(flat[i], flat[maxIndex]);
                                            if (i == k - 1) 
                                                {return flat[i];}}
return -1;
}
//---------------------------------------------------------------------
Matrix Matrix::merge(Matrix m)
{   Matrix temp;int k=0;
        for(int i=0;i<row;i++)
            {k=0;for(int j=0;j<row;j++)
                {temp.matrix[i][j]=matrix[i][j];}
                    for(int j=row;j<2*row;j++)
                        {temp.matrix[i][j]=m.matrix[i][k];k++;}}
return temp;
}
void Matrix::displayMerge()
{   for(int i=0;i<row;i++)
        {cout<<"|                                        ";
            for(int j=0;j<row;j++)
                {cout<<matrix[i][j]<<" ";}
                    for(int j=row;j<2*row;j++)
                        {cout<<matrix[i][j]<<" ";}cout<<endl;}cout<<endl;
}
//----------------------------------------------------------------------
void Matrix::display()
{   for(int i=0;i<row;i++)
        {cout<<"|                                        ";
            for(int j=0;j<row;j++)
                {cout<<matrix[i][j]<<"  ";}cout<<endl;}cout<<endl;
}
//----------------------------------------------------------------------
int main()
{
    Matrix M1(1,2,3,4,2,2);
    Matrix M2(2,3,1,4,2,2);
    Matrix M5,M6,M7,MB,MC;
    cout<<"|=====================================================================================|\n";
    cout<<"|                                      2X2  MATRIX                                    |\n";
    cout<<"|_____________________________________________________________________________________|\n";
    cout<<"|                                       MATRIX M1                                     |"<<endl;
    cout<<"|                                                                                     |\n";
    M1.display();
    cout<<"|=====================================================================================|\n";
    cout<<"|                                       MATRIX M2                                     |"<<endl;
    cout<<"|                                                                                     |\n";
    M2.display();
    M1.setValue(0,1,4);
    cout<<"|=====================================================================================|\n";
    cout<<"|                                   CHANGED MATRIX M1                                 |"<<endl;
    cout<<"|                                                                                     |\n";
    M1.display();
    cout<<"|-------------------------------------------|-----------------------------------------|\n";
    cout<<"|              VALUE AT INDEX               |                    "<<M1.getValue(1,1)<<"                    |\n";
    cout<<"|-------------------------------------------|-----------------------------------------|\n";
    cout<<"|             ELEMENT SUM OF M1             |                    "<<M1.Total()<<"                   |\n";
    cout<<"|-------------------------------------------|-----------------------------------------|\n";
    cout<<"|           ELEMENT AVERAGE OF M1           |                    "<<M1.Average()<<"                    |\n";
    cout<<"|-------------------------------------------|-----------------------------------------|\n";
    cout<<"|           ELEMENT SUM ROW OF M1           |                    "<<M1.RowTotal(1)<<"                    |\n";
    cout<<"|-------------------------------------------|-----------------------------------------|\n";
    cout<<"|           ELEMENT SUM COL OF M1           |                    "<<M1.ColumnTotal(1)<<"                    |\n";
    cout<<"|-------------------------------------------|-----------------------------------------|\n";
    cout<<"|        HIGHEST ELEMENT IN ROW OF M1       |                    "<<M1.HighestInRow(1)<<"                    |\n";
    cout<<"|-------------------------------------------|-----------------------------------------|\n";
    cout<<"|        LOWEST ELEMENT  IN ROW OF M1       |                    "<<M1.LowestInRow(1)<<"                    |\n";
    cout<<"|-------------------------------------------|-----------------------------------------|\n";
    cout<<"|      ELEMENT SUM RIGHTDIAGONAL OF M1      |                    "<<M1.RightDiagonalTotal()<<"                    |\n";
    cout<<"|-------------------------------------------|-----------------------------------------|\n";
    cout<<"|       ELEMENT SUM LEFTDIAGONAL OF M1      |                    "<<M1.LeftDiagonalTotal()<<"                    |\n";
    cout<<"|-------------------------------------------|-----------------------------------------|\n";
    cout<<"|=====================================================================================|\n";
    cout<<"|                                    SUM OF M1 & M2                                   |\n";
    cout<<"|_____________________________________________________________________________________|\n";
    cout<<"|                                                                                     |\n";
    M5 = M1.Add(M2);
    M5.display();
    cout<<"|_____________________________________________________________________________________|\n";
    cout<<"|=====================================================================================|\n";
    cout<<"|                                SUBTRACTION OF M1 & M2                               |\n";
    cout<<"|_____________________________________________________________________________________|\n";
    cout<<"|                                                                                     |\n";
    M6 = M1.Subtract(M2);
    M6.display();
    cout<<"|_____________________________________________________________________________________|\n";
    M7 = M1.Multiply(M2);
    cout<<"|=====================================================================================|\n";
    cout<<"|                               MULTIPLICATION OF M1 & M2                             |\n";
    cout<<"|_____________________________________________________________________________________|\n";
    cout<<"|                                                                                     |\n";
    M7.display();
    cout<<"|_____________________________________________________________________________________|\n";
    cout<<"|=====================================================================================|\n";
    cout<<"|                                   MERGING OF M1 & M2                                |\n";
    cout<<"|_____________________________________________________________________________________|\n";
    cout<<"|                                                                                     |\n";
    MB = M1.merge(M2);
    MB.displayMerge();
    cout<<"|=====================================================================================|\n";
    cout<<"|                                    TRANSPOSE OF M1                                  |\n";
    cout<<"|                                                                                     |\n";
    MC=M1.Transpose();
    MC.display();
    cout<<"|_____________________________________________________________________________________|\n";
    
    Matrix M3(1,2,3,4,5,2,4,3,2,3,3);
    Matrix M4(2,3,1,4,2,2,3,2,6,3,3);
    Matrix M8,M9,MA,MD,ME;
    cout<<"|=====================================================================================|\n";
    cout<<"|                                      3X3  MATRIX                                    |\n";
    cout<<"|_____________________________________________________________________________________|\n";
    cout<<"|                                       MATRIX M3                                     |"<<endl;
    cout<<"|                                                                                     |\n";   
    M3.display();
    cout<<"|=====================================================================================|\n";
    cout<<"|                                       MATRIX M4                                     |"<<endl;
    cout<<"|                                                                                     |\n";  
    M4.display();
    M3.setValue(0,1,4);
    cout<<"The matrix M3 after changing is :: "<<endl; 
    cout<<"|=====================================================================================|\n";
    cout<<"|                                   CHANGED MATRIX M3                                 |"<<endl;
    cout<<"|                                                                                     |\n";
    M3.display();
    cout<<"|-------------------------------------------|-----------------------------------------|\n";
    cout<<"|              VALUE AT INDEX               |                    "<<M3.getValue(1,1)<<"                    |\n";
    cout<<"|-------------------------------------------|-----------------------------------------|\n";
    cout<<"|             ELEMENT SUM OF M1             |                    "<<M3.Total()<<"                   |\n";
    cout<<"|-------------------------------------------|-----------------------------------------|\n";
    cout<<"|           ELEMENT AVERAGE OF M1           |                    "<<M3.Average()<<"                    |\n";
    cout<<"|-------------------------------------------|-----------------------------------------|\n";
    cout<<"|           ELEMENT SUM ROW OF M1           |                    "<<M3.RowTotal(1)<<"                   |\n";
    cout<<"|-------------------------------------------|-----------------------------------------|\n";
    cout<<"|           ELEMENT SUM COL OF M1           |                    "<<M3.ColumnTotal(1)<<"                   |\n";
    cout<<"|-------------------------------------------|-----------------------------------------|\n";
    cout<<"|        HIGHEST ELEMENT IN ROW OF M1       |                    "<<M3.HighestInRow(1)<<"                    |\n";
    cout<<"|-------------------------------------------|-----------------------------------------|\n";
    cout<<"|        LOWEST ELEMENT  IN ROW OF M1       |                    "<<M3.LowestInRow(1)<<"                    |\n";
    cout<<"|-------------------------------------------|-----------------------------------------|\n";
    cout<<"|      ELEMENT SUM RIGHTDIAGONAL OF M1      |                    "<<M3.RightDiagonalTotal()<<"                   |\n";
    cout<<"|-------------------------------------------|-----------------------------------------|\n";
    cout<<"|       ELEMENT SUM LEFTDIAGONAL OF M1      |                    "<<M3.LeftDiagonalTotal()<<"                    |\n";
    cout<<"|-------------------------------------------|-----------------------------------------|\n";
     cout<<"|=====================================================================================|\n";
    cout<<"|                                    SUM OF M3 & M4                                   |\n";
    cout<<"|_____________________________________________________________________________________|\n";
    cout<<"|                                                                                     |\n";
    M8 = M3.Add(M4);
    M8.display();
    cout<<"|_____________________________________________________________________________________|\n";
    cout<<"|=====================================================================================|\n";
    cout<<"|                                SUBTRACTION OF M1 & M2                               |\n";
    cout<<"|_____________________________________________________________________________________|\n";
    cout<<"|                                                                                     |\n";
    M9 = M3.Subtract(M4);
    M9.display();
    cout<<"|_____________________________________________________________________________________|\n";
    MA = M3.Multiply(M4);
    cout<<"|=====================================================================================|\n";
    cout<<"|                               MULTIPLICATION OF M1 & M2                             |\n";
    cout<<"|_____________________________________________________________________________________|\n";
    cout<<"|                                                                                     |\n";
    MA.display();
    cout<<"|_____________________________________________________________________________________|\n";
    cout<<"|=====================================================================================|\n";
    cout<<"|                                   MERGING OF M1 & M2                                |\n";
    cout<<"|_____________________________________________________________________________________|\n";
    cout<<"|                                                                                     |\n";
    MD = M3.merge(M4);
    MD.displayMerge();
    cout<<"|=====================================================================================|\n";
    cout<<"|                                    TRANSPOSE OF M3                                  |\n";
    cout<<"|                                                                                     |\n";
    ME=M3.Transpose();
    ME.display();
    cout<<"|_____________________________________________________________________________________|\n";    
    Matrix N1(1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,4,4);
    Matrix N2(2,2,2,2,1,1,1,1,4,4,4,4,3,3,3,3,4,4);
    Matrix N3,N4,N5,N6,N7;
    cout<<"|=====================================================================================|\n";
    cout<<"|                                      4X4  MATRIX                                    |\n";
    cout<<"|_____________________________________________________________________________________|\n";
    cout<<"|                                       MATRIX M1                                     |"<<endl;
    cout<<"|                                                                                     |\n";   
    N1.display();
    cout<<"|=====================================================================================|\n";
    cout<<"|                                       MATRIX N2                                     |"<<endl;
    cout<<"|                                                                                     |\n";  
    N2.display();
    N1.setValue(0,1,4);
    cout<<"The matrix M3 after changing is :: "<<endl; 
    cout<<"|=====================================================================================|\n";
    cout<<"|                                   CHANGED MATRIX N1                                 |"<<endl;
    cout<<"|                                                                                     |\n";
    N1.display();
    cout<<"|-------------------------------------------|-----------------------------------------|\n";
    cout<<"|              VALUE AT INDEX               |                    "<<N1.getValue(1,1)<<"                    |\n";
    cout<<"|-------------------------------------------|-----------------------------------------|\n";
    cout<<"|             ELEMENT SUM OF M1             |                    "<<N1.Total()<<"                   |\n";
    cout<<"|-------------------------------------------|-----------------------------------------|\n";
    cout<<"|           ELEMENT AVERAGE OF M1           |                    "<<N1.Average()<<"                    |\n";
    cout<<"|-------------------------------------------|-----------------------------------------|\n";
    cout<<"|           ELEMENT SUM ROW OF M1           |                    "<<N1.RowTotal(1)<<"                    |\n";
    cout<<"|-------------------------------------------|-----------------------------------------|\n";
    cout<<"|           ELEMENT SUM COL OF M1           |                    "<<N1.ColumnTotal(1)<<"                   |\n";
    cout<<"|-------------------------------------------|-----------------------------------------|\n";
    cout<<"|        HIGHEST ELEMENT IN ROW OF M1       |                    "<<N1.HighestInRow(1)<<"                    |\n";
    cout<<"|-------------------------------------------|-----------------------------------------|\n";
    cout<<"|        LOWEST ELEMENT  IN ROW OF M1       |                    "<<N1.LowestInRow(1)<<"                    |\n";
    cout<<"|-------------------------------------------|-----------------------------------------|\n";
    cout<<"|      ELEMENT SUM RIGHTDIAGONAL OF M1      |                    "<<N1.RightDiagonalTotal()<<"                   |\n";
    cout<<"|-------------------------------------------|-----------------------------------------|\n";
    cout<<"|       ELEMENT SUM LEFTDIAGONAL OF M1      |                    "<<N1.LeftDiagonalTotal()<<"                   |\n";
    cout<<"|-------------------------------------------|-----------------------------------------|\n";
     cout<<"|=====================================================================================|\n";
    cout<<"|                                    SUM OF N1 & N2                                   |\n";
    cout<<"|_____________________________________________________________________________________|\n";
    cout<<"|                                                                                     |\n";
    N3 = N1.Add(N2);
    N3.display();
    cout<<"|_____________________________________________________________________________________|\n";
    cout<<"|=====================================================================================|\n";
    cout<<"|                                SUBTRACTION OF N1 & N2                               |\n";
    cout<<"|_____________________________________________________________________________________|\n";
    cout<<"|                                                                                     |\n";
    N4 = N1.Subtract(N2);
    N4.display();
    cout<<"|_____________________________________________________________________________________|\n";
    N5 = N1.Multiply(N2);
    cout<<"|=====================================================================================|\n";
    cout<<"|                               MULTIPLICATION OF N1 & N2                             |\n";
    cout<<"|_____________________________________________________________________________________|\n";
    cout<<"|                                                                                     |\n";
    N5.display();
    cout<<"|_____________________________________________________________________________________|\n";
    cout<<"|=====================================================================================|\n";
    cout<<"|                                   MERGING OF N1 & N2                                |\n";
    cout<<"|_____________________________________________________________________________________|\n";
    cout<<"|                                                                                     |\n";
    N6 = N1.merge(N2);
    N6.displayMerge();
    cout<<"|=====================================================================================|\n";
    cout<<"|                                    TRANSPOSE OF N1                                  |\n";
    cout<<"|                                                                                     |\n";
    N7=N1.Transpose();
    N7.display();
    cout<<"|_____________________________________________________________________________________|\n";
    return 0;
}