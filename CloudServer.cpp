#include<iostream>
#include<conio.h>
#include<bits/stdc++.h>
using namespace std;

//*****************************************************************************//
//*****************************************************************************//

vector<long int>m;
vector<long int>encryptedFile;
vector<char>PrintDecrypted;
vector<int>Hashtags;
string file="";

//*****************************************************************************//
//*****************************************************************************//

int PrivateKey=23;
int p=11;
int q=17;
int n = p*q;

//*****************************************************************************//
//*****************************************************************************//
void ReadInput();
void Decrypt();
vector<string>DivideInBlock(string &file);
vector<int>GenerateHashtags(vector<string>&Fileblocks);
void DivideAndGenHashTags();
int GenerateProof(vector<int>hash);


//*****************************************************************************//
//*****************************************************************************//

int main()
{

   ReadInput();
   for(int i=0;i<encryptedFile.size();i++)
      m.push_back(encryptedFile[i]);
   Decrypt();
   cout<<"\n";
   DivideAndGenHashTags();
   cout<<"MHT for given hashtags is : "<<GenerateProof(Hashtags)<<endl;
   cout<<"\n...THE END...\n";
    
   return 0;
}

//*****************************************************************************//
//*****************************************************************************//

void ReadInput()
{
   #ifndef ONLINE_JUDGE
    freopen("EncryptedFile.txt", "r", stdin);
   #endif
   for(int i=0;i<8;i++)
   {
      long int x;
      cin>>x;
      encryptedFile.push_back(x);
   }
      
}

//*****************************************************************************//
//*****************************************************************************//

void Decrypt()
{
   long int pt, ct, key = PrivateKey, k;
   int i = 0;
   int size = encryptedFile.size();
   while (size > 0 )
   {
      ct = encryptedFile[i]-96;
      k = 1;
      for (int j = 0; j < key; j++)
      {
         k = k * ct;
         k = k % n;
      }
      pt = k + 96;
      m[i] = pt;
      i++;
      size--;

   }
   for (i = 0; i < m.size(); i++)
      PrintDecrypted.push_back(m[i]);
   for (i = 0; i < m.size(); i++)
      file+=PrintDecrypted[i];
   cout << endl;
   
   cout << "DECRYPTED MESSAGE: " << endl;
   for (i = 0; i < PrintDecrypted.size(); i++)
      cout << PrintDecrypted[i];

}

//*****************************************************************************//
//*****************************************************************************//

void DivideAndGenHashTags()
{
    // adding extra space if length of file is odd...
    int filesize=file.size();
    if(filesize%2!=0)   file.append(" ");

    // dividing files into blocks...

    vector<string>Fileblocks=DivideInBlock(file);

    // generating hashtag for each block...

    Hashtags=GenerateHashtags(Fileblocks);
    
}

//*****************************************************************************//
//*****************************************************************************//

vector<string>DivideInBlock(string &file)
{
    vector<string>Blocks;
    int filesize=file.size();
    for(int i=0;i<filesize;i++)
    {
        string temp="";
        temp+=file[i];
        Blocks.push_back(temp);
    }
    return Blocks;    
         
}

//*****************************************************************************//
//*****************************************************************************//

vector<int>GenerateHashtags(vector<string>&Fileblocks)
{
    vector<int>hashtags;
    for(int i=0;i<Fileblocks.size();i++)
    {
        char x=Fileblocks[i][0];
        int temp=int(x);
        hashtags.push_back(temp%769);
    }
    return hashtags;
}

//*****************************************************************************//
//*****************************************************************************//

int GenerateProof(vector<int>hash)
{
    int n = hash.size();
    if(n==1)    return hash[0];
    
        vector<int>parenthash;
        int j=0;
        for(int i=0;i<n-1 && j<n/2;i=i+2)
        {
            parenthash.push_back(hash[i]+hash[i+1]);
            j++;
        }
        return GenerateProof(parenthash);
    
}

//*****************************************************************************//
//*****************************************************************************//