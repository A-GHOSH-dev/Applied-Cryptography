#include<iostream>
#include<math.h>
using namespace std;
/////////////gcd//////////////////
int gcd(int a, int b) {
   int t;
   while(1) {
      t= a%b;
      if(t==0)
      return b;
      a = b;
      b= t;
   }
}
/////////driver////////////
int main() {
/////////2 random prime numbers p and q ////////////////
///////////p/////////////////
   double p;
   cout<<"Enter p: ";
   cin>>p;
///////////////q///////////////////
   double q;
   cout<<"Enter q: ";
   cin>>q;
/////////////n////////////////////
   double n=p*q;//calculate n
   double track;
/////////////////////////phi(n)////////////////////
   double phi= (p-1)*(q-1);//calculate phi
   //public key
///////////////e//////////////////
   double e;
   cout<<"Enter e: ";
   cin>>e;

//////////check 1 < e < phi(n) and gcd(e, phi(n)) = 1
   while(e<phi) {
      track = gcd(e,phi);
      if(track==1)
         break;
      else
         e++;
   }
/////////////private key////////////
/////////////choosing d such that it satisfies d*e = 1 mod phi////////////
   double d1=1/e;
   double d=fmod(d1,phi);
//////////////plaintext///////////
   double message;
   cout<<"Enter message: ";
   cin>>message;
//////////encryption////////////////
///////////c////////////////
   double c = pow(message,e);
   double m = pow(c,d);
   c=fmod(c,n);
   m=fmod(m,n);
   cout<<"Original Message = "<<message;
   cout<<"\n"<<"p = "<<p;
   cout<<"\n"<<"q = "<<q;
   cout<<"\n"<<"n = pq = "<<n;
   cout<<"\n"<<"phi = "<<phi;
   cout<<"\n"<<"e = "<<e;
   cout<<"\n"<<"d = "<<d;
   cout<<"\n"<<"Encrypted message = "<<c;
   cout<<"\n"<<"Decrypted message = "<<m;
   return 0;
}
