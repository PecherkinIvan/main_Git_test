#include <iostream>
#include <fstream> 
#include <math.h>
using namespace std;

void FillMatrix(double**&,double*&,int);       //��������� ���������� �������
void Manual_fill_in(double**&,double*&,int);  // ������ ���������� �������
void Print(double**&,double*&,int);
void PrintFull(double **&,double*&,int);         
void Gauss(double **,double *y, int n);    // ������� ���� ������� �����
void Dete(double **,int);
void PrintFull(double **&,double*&,int);
void Select(double **&,double*&,int);
void Select2(double **&,double*&,int);
void Read(double **&,int);
//double GetDeterminant(double **, int , double);

void DelMatrix(double**&,int&);

/// FABS!!!

int main()
{
   system("chcp 1251");  system("cls");

   int N=3;
   double **Mat= new double*[N];  // ������� ������������
   double *y = new double[N];    // ��������� ��������
   double eps=0.000001; 

   Select(Mat,y,N);
   PrintFull(Mat,y,N);
   Select2(Mat,y,N);

 
  
 
 
   DelMatrix(Mat,N);
   delete [] y;
   y=nullptr;

 return 0;
}

void Select(double **&a,double*&y,int n)
{
    cout<<"\n  ________________________________";
    cout<<"\n |                                ||";
    cout<<"\n |  ** ��� ��������� �������? **  ||";
    cout<<"\n |  1.) ��������������            ||";
    cout<<"\n |  2.) ��������� �������         ||";
    cout<<"\n |  3.) ����� ������ �� �����     ||";
    cout<<"\n |________________________________||";
    cout<<"\n > ";
    int point;
    cin>>point;

    switch(point) {
        case 1:
            Manual_fill_in(a,y,n);
            break;
        case 2:
            FillMatrix(a,y,n);
            break;
        case 3:
            Read(a,n);
            break;

        default:
           exit(EXIT_FAILURE);
        }
}
void Select2(double **&a,double*&y,int n)
{
    cout<<"\n  _______________________________________________";
    cout<<"\n |                                               |";
    cout<<"\n | ** ����� �������� ���������? **               |"; 
    cout<<"\n |  1.) ������ ���� ������� ������               |";
    cout<<"\n |  2.) ��������� ������������                   |";
    cout<<"\n |  3.) ����� �������� �������                   |";
    cout<<"\n |  4.) ���������� �������� ����������� �������  |";
    cout<<"\n |  0.) �����                                    |";
    cout<<"\n |_______________________________________________| \n>";
    int point;
    cin>>point;

    switch(point) {
        case 1:
            Gauss(a,y,n);
            break;
        case 2:
            Dete(a,n);
            break;
        case 3:

            break;
        case 0:
           exit(1);
            break;
        default:
           exit(EXIT_FAILURE);
        }
     Select2(a,y,n);
}

void FillMatrix(double **&a,double*&y,int n)
{
     for (int i = 0; i < n; i++)  // ��������� A
  {
    a[i] = new double[n];
    for (int j = 0; j < n; j++) 
      a[i][j]=rand() % 10;
  }
  for (int i = 0; i < n; i++) // ���������� Y
  {
    y[i]=rand() % 10;
  }
}
void Manual_fill_in(double**&a,double*&y, int n)
{
  for (int i = 0; i < n; i++)  // ��������� A
  {
    a[i] = new double[n];
    for (int j = 0; j < n; j++) 
    {
      cout << "a[" << i << "][" << j << "]= ";
      cin >> a[i][j];
    }
  }
  
  for (int i = 0; i < n; i++) // ���������� Y
  {
    cout << "y[" << i << "]= ";
    cin >> y[i];
  }
}

void Print(double **&a,double*&y, int n)
{
  cout<<endl;
   for (int i = 0; i < n; i++) 
  {
    for (int j = 0; j < n; j++) 
    {
      cout << a[i][j] << " ";
    }
    cout<<endl;
  }

}
void PrintFull(double **&a,double*&y,int n)
{
  cout<<endl;
   for (int i = 0; i < n; i++) 
  {
    for (int j = 0; j < n; j++) 
    {
      cout << a[i][j] << "*x" << j;
      if (j < n - 1)
        cout << " + ";
    }
    cout << " = " << y[i] << endl;
  }
}


void Gauss(double **a, double *y, int n) 
{
  double *x, max;
  int k, index;
  const double eps = 0.00001;  // ��������
  x = new double[n];
  k = 0;
  while (k < n) 
  {
    // ����� ������ � ������������ a[i][k] (��������� �� ������)
    max = abs(a[k][k]);
    index = k;
    for (int i = k + 1; i < n; i++) 
    {
      if (abs(a[i][k]) > max)
      {
        max = abs(a[i][k]);
        index = i;
      }
    }
    // ������������ �����
    if (max < eps) 
    {
      // ��� ��������� ������������ ���������
      cout << "������� �������� ���������� ��-�� �������� ������� ";
      cout << index << " ������� A" << endl;
      system("pause");
      exit(0);
    }
    for (int j = 0; j < n; j++) 
    {
      double temp = a[k][j];
      a[k][j] = a[index][j];
      a[index][j] = temp;
    }
    double temp = y[k];
    y[k] = y[index];
    y[index] = temp;
    // ������������ ���������
    for (int i = k; i < n; i++) 
    {
      double temp = a[i][k];
      if (abs(temp) < eps) continue; // ��� �������� ������������ ����������
      for (int j = 0; j < n; j++) 
        a[i][j] = a[i][j] / temp;
      y[i] = y[i] / temp;
      if (i == k)  continue; // ��������� �� �������� ���� �� ����
      for (int j = 0; j < n; j++)
        a[i][j] = a[i][j] - a[k][j];
      y[i] = y[i] - y[k];
    }
    Print(a,y,n);
    k++;
  }
  // �������� �����������
  for (k = n - 1; k >= 0; k--)
  {
    x[k] = y[k];
    for (int i = 0; i < k; i++)
      y[i] = y[i] - a[i][k] * x[k];
  }
  cout<<endl;  // ������ �������.
  for (int i = 0; i < n; i++) 
    cout << "x[" << i << "]=" << x[i] << endl;
}

void Det(double **a, int n) 
{
  double max, det=1;
  int k, index;
  const double eps = 0.00001;  // ��������
  k = 0;
 
 while (k < n) 
   {
      double zero=0;
     for(int i=0;i<n;i++)  //�������� �� ����������� ���.
       for(int j=0; j<n; j++)
         if(i>j)zero+=fabs(a[i][j]);

    cout<<zero;
    if(zero!=0)
    {
    // ����� ������ � ������������ a[i][k] (��������� �� ������)
    max = abs(a[k][k]);
    index = k;

    for (int i = k + 1; i < n; i++) 
    {
      if (abs(a[i][k]) > max)
      {
        max = abs(a[i][k]);
        index = i;
      }
    }
    // ������������ �����
    if (max < eps) 
    {
      // ��� ��������� ������������ ���������
      cout << "������� �������� ���������� ��-�� �������� ������� ";
      cout << index << " ������� A" << endl;
      system("pause");
      exit(0);
    }
    for (int j = 0; j < n; j++) 
    {
      double temp = a[k][j];
      a[k][j] = a[index][j];
      a[index][j] = temp;
    }
    // ������������ ���������
    for (int i = k; i < n; i++) 
    {
      double temp = a[i][k];
      if (abs(temp) < eps) continue; // ��� �������� ������������ ����������
      for (int j = 0; j < n; j++) 
      {
        a[i][j] = a[i][j] / temp;
        det*=temp;
      }
      if (i == k)  continue; // ��������� �� �������� ���� �� ����
      for (int j = 0; j < n; j++)
        a[i][j] = a[i][j] - a[k][j];
    }
    
   cout<<endl;
   for (int i = 0; i < n; i++) 
   {
    for (int j = 0; j < n; j++) 
      cout << a[i][j] << " ";
    cout<<endl;  
   } 
    cout<<endl;
  }
    k++;
  }
  
  for(int i=0; i<n;i++)
     det*=a[i][i];
  cout<<"Det= "<<det; 
}

void Dete(double **a,int n)
{   
    double det=1;
   
    for(int i=0; i<n; i++)
    {
        bool flag=false;
        if(a[i][i]==0)
        {
            flag=true;
            for(int j=i;j<n;++j)
            {
                if(a[j][i]!=0)
                {
                    det*=-1;
                    for(int k=0;k<n;k++){  //???
                        double temp=a[i][k];
                        a[i][k]=a[j][k];
                        a[j][k]=temp;
                        flag=false;
                    }
                }
             }
        }
    

     if (flag==true){ det=0; break; }
     else{
         
         for(int j=i+1; j<n; j++)
         {
            double store=a[j][i];
            for(int k=i; k<n; k++)
            {
                a[j][k] -= (a[i][k]*store)/a[i][i];
            }
          }
         det*=a[i][i];
         }
    }

    cout<<"Det: "<<det;
}


void Read(double **&a,int n)
{
  for(int i=0; i<n; i++) a[i]=new double[n];
    
    ifstream fin("input1.txt");

	 for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
          fin >> a[i][j];
          
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
          cout<<a[i][j]<<"  ";
     cout<<endl;  
    }
    fin.close();

}

void DelMatrix(double **&mat,int &N)
{
   for(int i=0; i<N; i++)
     delete[]mat[i]; 
   
   delete [] mat;
   mat=nullptr;
}
  

  
  
  
  
  /* ofstream f("fail.txt");
 for(int i=0; i<I; i++){
  for(int j=0; j<J; j++){
   f<<M[i][j]<<" ";
   cout<<M[i][j]<<" ";
  }
  cout<<endl;
  f<<endl;
 }
 f.close(); */