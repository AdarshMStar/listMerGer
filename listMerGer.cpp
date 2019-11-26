#include <iostream>
#include <iomanip>
#include <fstream>
#include<cstring>
#include<list>
using namespace std;

int main() {
    int count = 0,count1=0;
    string x,y;
    list<string> output1,output2;
    ifstream inFile,inFile2;
    ofstream outFile;
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"----------------------listMerGer------------------------"<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    string inputFile1,inputFile2,outputFilename;
    cout<<"enter 1st input file:";
    cin>>inputFile1;
    cout<<"enter 2st input file:";
    cin>>inputFile2;
    cout<<endl;
    cout<<"enter output file name:";
    cin>>outputFilename;

    cout<<endl;
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
    while(!inFile.eof() && inFile.good()) {
	inFile>>x;   
    count++;    
    output1.push_back(x);    
    }}
    inFile.close();

     if (!inFile2) {
        cout << "Unable to open file2";
        exit(1); // terminate with error
    }
    else{
    while (!inFile2.eof() && inFile2.good()) { 
    inFile2>>y;     
	count1++;
    output2.push_back(y);
    }}
    inFile2.close();
    output1.sort();
    output2.sort();
    cout<<endl<<endl<<endl;
    cout<<"file1 Count: "<<output1.size()<<endl;
    cout<<"file2 Count: "<<output2.size()<<endl<<endl;
    cout<<"total number of rows : "<<output2.size()+output1.size()<<endl;
    output1.merge(output2);
    cout<<endl<<endl;
    

    
    output1.unique();
     for(auto j=output1.begin();j!=output1.end();++j)
    {
        //cout<<"output :"<<*j<<endl;
        outFile<<*j<<endl;
    }
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"Number of Unique rows: "<<output1.size()<<endl;
    cout<<"Output Saved in file : "<<outputFilename<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    outFile.close();
    
    return 0;
}	
