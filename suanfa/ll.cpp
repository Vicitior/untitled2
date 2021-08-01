#include<iostream>
#include<cmath>
using namespace std;
class Fraction
{int fenmu,fenzi;
 public:
  Fraction(int x,int y){fenzi=x;fenmu=y;}
  friend Fraction operator +(Fraction data1,Fraction data2);
  friend Fraction operator -(Fraction data1,Fraction data2);
  friend Fraction operator *(Fraction data1,Fraction data2);
  friend Fraction operator /(Fraction data1,Fraction data2);
 void simplify()
    {
 int t,x=fenzi,y=fenmu;
 while(y!=0)
 {t=x%y;
 x=y;
 y=t;}
        fenzi/=x;
        fenmu/=x;
        return;
    }
 void output(int n)
 {
  cout<<"r"<<n<<"="<<fenzi<<"/"<<fenmu;
 }
};
Fraction operator+(Fraction data1,Fraction data2)
  {
   Fraction sum(0,1);
   sum.fenzi=data1.fenzi*data2.fenmu+data1.fenmu*data2.fenzi;
   sum.fenmu=data1.fenmu*data2.fenmu;
   sum.simplify();
   return sum;
  }
Fraction operator-(Fraction data1,Fraction data2)
       {
           Fraction sum(0,1);
     sum.fenzi=data1.fenzi*data2.fenmu-data2.fenmu*data1.fenzi;
     sum.fenmu=data1.fenmu*data2.fenmu;
     sum.simplify();
     return sum;
      }
Fraction operator*(Fraction data1,Fraction data2)
{
  Fraction sum(0,1);
  sum.fenzi=data1.fenzi*data2.fenzi;
  sum.fenmu=data1.fenmu*data2.fenmu;
  sum.simplify();
  return sum;
}
Fraction operator/(Fraction data1,Fraction data2)
 {
  Fraction sum(0,1);
  sum.fenzi=data1.fenzi*data2.fenmu;
  sum.fenmu=data1.fenmu*data2.fenzi;
  sum.simplify();
  return sum;
}
int main()
{
 Fraction r1(2,8),r2(23,45),r3(0,1);
 r1.simplify();
 r1.output(1);
 return 0;
}