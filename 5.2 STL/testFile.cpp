#include<cstdlib>
#include<iostream>
#include<fstream>
//#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
    srand(time(NULL));
    ofstream ofile;
    ofile.open("data.txt",ios::out);
    int num=50;
    for(int i=0;i<50;i++)
    {
        ofile<<rand()%2<<endl;
    }
    ofile.close();
    ifstream ifile;
    ifile.open("data.txt",ios::in);
    while(ifile>>num)
    {
        //ifile>>num;
        cout<<num<<endl;
    }
    ifile.close();
    return 0;
}