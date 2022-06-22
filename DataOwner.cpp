#include<iostream>
#include<conio.h>
#include<bits/stdc++.h>
#include <chrono>
using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;


//*****************************************************************************//
//*****************************************************************************//

string file;
vector<char>msg;
vector<long int>m;
vector<long int>encryptedFile;
vector<char>PrintEncrypted;
vector<int>Hashtags;
int PublicKey=7;
int p=11;
int q=17;
int n = p*q;
duration<double, std::milli> timeForReadingFile,timeForEncryption,timeForDividingFileIntoBlocks,timeForHashingBlocks,TotalTime;

//*****************************************************************************//
//*****************************************************************************//

vector<string>DivideInBlock(string &file);
vector<int>GenerateHashtags(vector<string>&Fileblocks);
void PrintEncryptedFile();
void ReadInput();
void Encrypt();
void DivideAndGenHashTags();
void PrintHashtags(int filesize,vector<string>Fileblocks,vector<int>Hashtags);
void print();
void printFiles();
void printTimeTaken();
//*****************************************************************************//
//*****************************************************************************//

int main()
{

    auto startProgram=high_resolution_clock::now();
    ReadInput();
    for(int i=0;i<file.size();i++)
        msg.push_back(file[i]);
        for(int i=0;i<msg.size();i++)
        m.push_back(msg[i]);
    Encrypt(); 
    print();
    PrintEncryptedFile();

    DivideAndGenHashTags();    
    printFiles();
    auto endProgram=high_resolution_clock::now();
    printTimeTaken();

    TotalTime = endProgram - startProgram;
    cout<<"Total Time Taken :"<<TotalTime.count()<<" SEC"<<endl;  

    return 0;
}

//*****************************************************************************//
//*****************************************************************************//

void ReadInput()
{
    auto start=high_resolution_clock::now();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    getline(cin,file);
    auto end=high_resolution_clock::now();
    timeForReadingFile = end - start;
}

//*****************************************************************************//
//*****************************************************************************//

void Encrypt()
{
   auto start=high_resolution_clock::now(); 
   long int pt, ct, key = PublicKey, k, len;
   long int i = 0;
   int size = msg.size();
   while (i != size)
   {
      pt = m[i];
      pt = pt - 96;
      k = 1;
      for (int j = 0; j < key; j++)
      {
         k = k * pt;
         k = k % n;
      }
      
      ct = k + 96;
      encryptedFile.push_back(ct);
      i++;
   }

   for (i = 0; i < encryptedFile.size(); i++)
      PrintEncrypted.push_back(encryptedFile[i]);
    auto end=high_resolution_clock::now();
    timeForEncryption = end - start;
           
}

//*****************************************************************************//
//*****************************************************************************//

void PrintEncryptedFile()
{
    #ifndef ONLINE_JUDGE
    freopen("EncryptedFile.txt", "w", stdout);
    #endif
   for(int i=0;i<encryptedFile.size();i++)
    cout<<encryptedFile[i]<<" ";

    
}

//*****************************************************************************//
//*****************************************************************************//

void DivideAndGenHashTags()
{
    auto start=high_resolution_clock::now();

    // adding extra space if length of file is odd...
    int filesize=file.size();
    if(filesize%2!=0)   file.append(" ");

    // dividing files into blocks...

    vector<string>Fileblocks=DivideInBlock(file);
    auto end=high_resolution_clock::now();
    timeForDividingFileIntoBlocks = end - start;


    // generating hashtag for each block...

    Hashtags=GenerateHashtags(Fileblocks);
    
    PrintHashtags(filesize,Fileblocks,Hashtags);
    
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
    auto start=high_resolution_clock::now();
    vector<int>hashtags;
    for(int i=0;i<Fileblocks.size();i++)
    {
        char x=Fileblocks[i][0];
        int temp=int(x);
        hashtags.push_back(temp%769);
    }
    auto end=high_resolution_clock::now();
    timeForHashingBlocks = end - start;
    return hashtags;
}

//*****************************************************************************//
//*****************************************************************************//

void PrintHashtags(int filesize,vector<string>Fileblocks,vector<int>Hashtags)
{

    #ifndef ONLINE_JUDGE
    freopen("hashtags.txt", "w", stdout);
    #endif
        for(int i=0;i<filesize;i++)
        cout<<Hashtags[i]<<endl;    
}

//*****************************************************************************//
//*****************************************************************************//

void print()
{
    cout << endl << "ENCRYPTED MESSAGE: " << endl;
    for (int i = 0; i < PrintEncrypted.size(); i++)
        cout << PrintEncrypted[i];  
    cout<<"\n";
            
}

void printFiles()
{
    #ifndef ONLINE_JUDGE
    freopen("printhashtags.txt", "w", stdout);
    #endif
    
    for(int i=0;i<file.size();i++)
        cout<<"block no."<<i<<"---->"<<"Hashtag:    "<<Hashtags[i]<<endl;

}
void printTimeTaken()
{
    #ifndef ONLINE_JUDGE
    freopen("TimeTaken.txt", "w", stdout);
    #endif
    cout<<"Time Taken in Reading the File: "<<timeForReadingFile.count()<<" SEC"<<endl;
    cout<<"Time Taken in Encryptiion: "<<timeForEncryption.count()<<" SEC"<<endl;
    cout<<"Time Taken in Dividing file into Blocks: "<<timeForDividingFileIntoBlocks.count()<<" SEC"<<endl;
    cout<<"Time Taken in Hashing the Blocks: "<<timeForHashingBlocks.count()<<" SEC"<<"\n"<<endl;
    
}
//*****************************************************************************//
//*****************************************************************************//
