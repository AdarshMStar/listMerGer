// io/read-file-sum.cpp - Read integers from file and print sum.
// Fred Swartz 2003-08-20

#include <iostream>
#include <iomanip>
#include <fstream>
#include<cstring>
#include<list>
//#include <bits/stdc++.h> 
using namespace std;

int main() {
    int count = 0,count1=0;
    string x,y;
    list<string> output1,output2;
    ifstream inFile,inFile2;
    ofstream outFile;
    
    string inputFile1,inputFile2,outputFilename;
    cout<<"enter 1st input file:";
    cin>>inputFile1;
    cout<<"enter 2st input file:";
    cin>>inputFile2;
    cout<<"enter output file name:";
    cin>>outputFilename;

    cout<<"1st input file: "<<inputFile1<<endl;
    cout<<"2nd input file: "<<inputFile2<<endl;
    
    inFile.open(inputFile1);
    inFile2.open(inputFile2);
    outFile.open(outputFilename);
    if (!inFile) {
        cout << "Unable to open file1";
        exit(1); // terminate with error
    }
    else{
    while (inFile >> x) {
	inFile>>x;    
	count++;
    output1.push_back(x);
    
    }}


     if (!inFile2) {
        cout << "Unable to open file2";
        exit(1); // terminate with error
    }
    else{
    while (inFile2 >> y) { 
    inFile2>>y;   
    //cout<<x<<" "<<y<<endl;   
	count1++;
    output2.push_back(y);
    }}



    inFile.close();
    inFile2.close();
    output1.sort();
    output2.sort();
    output1.merge(output2);
    cout<<endl<<endl;
    cout<<"file1 Count_c: "<<count<<endl;
    cout<<"file2 Count_c: "<<count1<<endl;
    cout<<"file1 Count: "<<output1.size()<<endl;
    cout<<"file2 Count: "<<output2.size()<<endl;
//     cout<<count;
//    cout<<"size : "<<output1.size()<<endl;
    //cout<<output<<endl;
    
    // for(auto j=output1.begin();j!=output1.end();++j)
    // {
    //     cout<<"output :"<<*j<<endl;
    // }
    
    output1.unique();
     for(auto j=output1.begin();j!=output1.end();++j)
    {
        //cout<<"output :"<<*j<<endl;
        outFile<<*j<<endl;
    }
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"Output Size: "<<output1.size()<<endl;
    cout<<"Output Saved in file : "<<outputFilename<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    outFile.close();
    
    return 0;
}	
