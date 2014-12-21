#include<iostream>
#include<string>
#include<sstream>
#include<stack>
#include<thread>
#include<fstream>
#include<vector>
#include<random>
#include<mutex>

using namespace std;

ofstream ofile;
mutex m;

string reverseSentence(const string &strIn,const char chDelim = ' ')
{
	if(strIn.empty())
		return string("");

	stack<string> stRevStrings;
	istringstream ss(strIn);

	string word;
	string strDelim;
	strDelim += chDelim;
	while(getline(ss,word,chDelim))
	{
		stRevStrings.push(word);
		stRevStrings.push(strDelim);
	}
	stRevStrings.pop(); //pop last extra delim
	
	string revString;
	while(!stRevStrings.empty())
	{
		revString += stRevStrings.top();
		stRevStrings.pop();
	}
		
	return revString;
}


void reverseFiles(const char* fileName,const char* ofileName, const char chDelim)
{
	if(!fileName || !ofileName)
	{
		cout<<"Not a valid input filename or output file name";
		return;
	}
	ifstream inFile(fileName, ios::in);
	if(!inFile.is_open())
	{
		cout<<"Could not open file "<<fileName;
		return;
	}

	string line;
	vector<string> revFile;
	while(getline(inFile,line))
		revFile.push_back(reverseSentence(line,' '));	

	vector<string>::iterator itr;
	for(itr = revFile.begin() ; itr != revFile.end() ; ++itr)
	{
			lock_guard<mutex> lock(m);
			if(!ofile.is_open())
			{
				cout<<"Could not open file for writing";
				return;
			}
			ofile<<*itr<<endl;
	}	
	inFile.close();
}


string jumbleUp(const char* line)
{
	if(! line)
		return string();

	string retString;
	vector<string> vecString;
	istringstream ss(line);

	string word;
	while(ss >> word)
		vecString.push_back(word);
	
	vector<string>::iterator itr;
	int n = vecString.size();
	for(itr = vecString.begin(); itr != vecString.end(); ++itr)
	for(auto& itr : vecString)
	{
		random_device rd;
		mt19937 gen(rd());
		
		uniform_int_distribution<> dis(0,n-1);
		int i = dis(gen);
		int j = dis(gen);
		swap(vecString[i],vecString[j]);	
	}	
	
	for(itr = vecString.begin(); itr != vecString.end(); ++itr)
		retString += *itr + " ";

	return retString;
}


int main(int argc, char *argv[])
{
	cout<<reverseSentence("hello world, what's up!")<<endl;
	cout<<reverseSentence("yo man! its working fine!",' ')<<endl;
	cout<<reverseSentence("any;plans;for next weekend?;going;to;pune?;",';')<<endl;
	cout<<reverseSentence("so:what:are::your: ::plans:12345:blah:blah:blah",':')<<endl;
	cout<<reverseSentence("|||This|Is|Cool||||Isn't it?",'|')<<endl;
	cout<<reverseSentence("This is a line",':')<<endl;
	cout<<reverseSentence("",':')<<endl;
	cout<<reverseSentence(" ",':')<<endl; 



	const char* ofileName = "/home/shrikant/GSLabs/out.txt";	
	ofile.open(ofileName,ios::app | ios::out);
	thread t[argc];

	for(int i = 1 ; i < argc; i++)
		t[i] = thread(reverseFiles,argv[i],ofileName,' ');

	
	for(int i = 1 ; i < argc; i++)
		t[i].join();
	
	ofile.close();

	cout<<jumbleUp("This is a line")<<endl;
	cout<<jumbleUp("Is this working for all inputs")<<endl;
	cout<<jumbleUp("Hi This Is India")<<endl;
	cout<<jumbleUp("    ")<<endl;
	return 0;
}


