
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <string>
using namespace std;

double cost0(vector<double> theta,vector<double> Constant, vector<double> X1, vector<double> X2,vector<double> X3,vector<double>Y)
{
   double Cost = 0;
   for(int i=0;i<Constant.size();i++)
   {
       Cost = Cost + (((theta[0]+theta[1]*X1[i]+theta[2]*X2[i]+theta[3]*X3[i])-Y[i]))*Constant[i];
   }
    int Size = Constant.size();
    Cost = Cost*(1.00/(Size));
    return Cost;
}
double cost1(vector<double> theta,vector<double> Constant, vector<double> X1, vector<double> X2,vector<double> X3,vector<double>Y)
{
   double Cost = 0;
   for(int i=0;i<X1.size();i++)
   {
       Cost = Cost + (((theta[0]+theta[1]*X1[i]+theta[2]*X2[i]+theta[3]*X3[i])-Y[i]))*X1[i];
   }
    int Size = X1.size();
    Cost = Cost*(1.00/(Size));
    return Cost;
}
double cost2(vector<double> theta,vector<double> Constant, vector<double> X1, vector<double> X2,vector<double> X3,vector<double>Y)
{
   double Cost = 0;
   for(int i=0;i<X2.size();i++)
   {
       Cost = Cost + ((theta[0]+theta[1]*X1[i]+theta[2]*X2[i]+theta[3]*X3[i])-Y[i])*X2[i];
   }
    int Size = X2.size();
    Cost = Cost*(1.00/(Size));
    return Cost;
}
double cost3(vector<double> theta,vector<double> Constant, vector<double> X1, vector<double> X2,vector<double> X3,vector<double>Y)
{
   double Cost = 0;
   for(int i=0;i<X3.size();i++)
   {
       Cost = Cost + (((theta[0]+theta[1]*X1[i]+theta[2]*X2[i]+theta[3]*X3[i])-Y[i]))*X3[i];
   }
    int Size = X3.size();
    Cost = Cost*(1.00/(Size));
    return Cost;
}
void grad_decent(vector<double>& theta,vector<double> Constant, vector<double> X1, vector<double> X2,vector<double> X3,vector<double> Y)
{
    double Learning_Rate = 0.01;
    double Zero,Previous_Zero=1;
    double One,Previous_One=1;
    double Two,Previous_Two=1;
    double Three,Previous_Three=1;
    int Iteration = 0;
    while(abs(Previous_Zero-theta[0])>0.0 || abs(Previous_One-theta[1])>0.0 || abs(Previous_Two-theta[2])>0.0 || abs(Previous_Three-theta[3])>0.0)
    {
        Previous_Zero = theta[0];
        Previous_One = theta[1];
        Previous_Two = theta[2];
        Previous_Three = theta[3];
        Zero = theta[0] - Learning_Rate*cost0(theta,Constant,X1,X2,X3,Y);
        One = theta[1] - Learning_Rate*cost1(theta,Constant,X1,X2,X3,Y);
        Two = theta[2] - Learning_Rate*cost2(theta,Constant,X1,X2,X3,Y);
        Three = theta[3] - Learning_Rate*cost3(theta,Constant,X1,X2,X3,Y);
        theta[0] = Zero;
        theta[1] = One;
        theta[2] = Two;
        theta[3] = Three;
        Iteration += 1;
        cout << theta[0];
        cout << theta[1];
        cout << theta[2];
        cout << theta[3];
    }
    cout << "Iterations: " << Iteration << endl;

}

int main()
{
    vector<double> Constant;
    vector<double> Birth_Rate;
    vector<double> Per_Capita_Income;
    vector<double> Population_Farms;
    vector<double> Infant_Mortality;
    vector<double> Theta;
        Theta = {0,0,0,0};
        Birth_Rate = {46.4,45.7,45.3,38.6,37.2,35.0,34.0,28.3,24.7,24.7,24.4,22.7,22.3,21.7,21.6,21.3,21.2,20.8,20.3,18.9,18.8,18.6,10.0,17.6,17.0,16.7,15.9,15.3,15.0,14.8};
        Per_Capita_Income =  {392,118,44,158,81,374,187,993,1723,287,970,885,200,575,688,48,572,239,244,472,134,633,295 ,906,1045,775,619,901,910,556};
        Population_Farms = {0.4,0.61,0.53,0.53,0.53,0.37,0.3,0.19,0.12,0.2,0.19,0.12,0.53,0.14,0.34,0.69,0.49,0.42,0.48,0.25,0.52,0.19,0.44,0.24,0.16,0.1,0.15,0.05,0.24,0.22};
        Infant_Mortality = {68.5,87.8,115.8,106.8,71.6,60.2,118.7,33.7,27.2,62,24.9,22.9,65.7,21.6,32.4,108.7,38.6,46.7,56.5,44.4,47.4,21.7,55.7,27.1,28.5,41.6,44.6,26.1,18.7,49.1};
        Constant = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        //Perform Feature Scaling to help the program Converge
        for(int i=0;i<Birth_Rate.size();i++)
        {
            Birth_Rate[i] = Birth_Rate[i];
        }
        for(int i=0;i<Per_Capita_Income.size();i++)
        {
            Per_Capita_Income[i] = Per_Capita_Income[i]*(1/500);
        }
        for(int i=0;i<Birth_Rate.size();i++)
        {
            Population_Farms[i] = Population_Farms[i]*2;
        }
        for(int i=0;i<Birth_Rate.size();i++)
        {
            Infant_Mortality[i] = Infant_Mortality[i]*(1/50);
        }
        grad_decent(Theta,Constant,Per_Capita_Income,Population_Farms,Infant_Mortality,Birth_Rate);
        cout << "y=" << Theta[0] << "+" << Theta[1] << "x+" << Theta[2] << "x+" << Theta[3] <<"x" << endl;

    }

