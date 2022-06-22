#include<iostream>
#include<conio.h>
#include<bits/stdc++.h>
using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;
duration<double, std::milli> TotalTime;


long int p, q, n, z, j, i, flag;
// p and q are two large prime numbers used to generate public-private key...
// n is the RSA modulus ... n = p*q...
// z is the derived number ... z>1 and z<(p-1)(q-1) .... 
// z and (p-1)(q-1) should be co-prime


vector<long int> e, d;
// e and d are the possible public and private key respectively...
// e is used for encryption and d is used for decryption...

int prime(long int pr) {
   int i;
   j = sqrt(pr);
   for (i = 2; i <= j; i++)
   {
      if (pr % i == 0)
         return 0;
   }
   return 1;
}

long int find_d(long int x) {
   long int k = 1;
   while (1)
   {
      k = k + z;
      if (k % x == 0)
         return (k / x);
   }
}

void get_ce() {
   int k;
   k = 0;
   for (i = 2; i < z; i++)
   {
      if (z % i == 0)
         continue;
      flag = prime(i);
      if (flag == 1 && i != p && i != q)
      {
         e.push_back(i);
         flag = find_d(e[k]);
         k++;
         if (flag > 0)
         {
            d.push_back(flag);
         }
      }
   }
}


int main()
{
   
    cout << "ENTER THE VALUE OF P (PRIME1): " << endl;
   cin >> p;
   flag = prime(p);
   while (flag == 0)
   {
      cout << "P IS NOT PRIME...";
      cout << "ENTER THE VALUE OF P (PRIME1): " << endl;
      cin >> p;
   }
   cout << "ENTER THE VALUE OF Q (PRIME2): " << endl;
   cin >> q;
   flag = prime(q);
   while (flag == 0 || p == q)
   {
      cout << "Q IS NOT PRIME OR YOU HAVE ENTERED THE SAME VALUE AS P..." << endl;
      cout << "ENTER THE VALUE OF Q (PRIME2): " << endl;
      cin >> q;
    }  
   auto start=high_resolution_clock::now();
    n = p * q;
    z = (p - 1) * (q - 1);
    get_ce();
    cout << endl;
    cout << "POSSIBLE VALUES OF e AND d ARE" << endl;
    for (i = 0; i < j - 1; i++)
      cout << e[i] << "\t" << d[i] << "\n";
   auto end=high_resolution_clock::now();
    TotalTime = end - start;
   cout<<"Time taken To generate Public Private Key pair: "<<TotalTime.count()<<" SEC"<<endl;


    return 0;
}