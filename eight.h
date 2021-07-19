#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

istream &myPrint(istream &is)
{
    string word;
    while (is >> word)
    {
        cout << word << endl;
    }
    is.clear();
    return is;
}

void readFile(const string &filePath, vector<string> &vcs)
{
    ifstream inFile(filePath);
    if (inFile)
    {
        string buf;
        while (getline(inFile,buf))
        {
            vcs.push_back(buf);
        }
        
    }
}

void readFileT(const string &filePath){
	ifstream ifs(filePath);
	if (!ifs)
	{
		cerr << "No data?" << endl;
	}

	vector<string> vecLine;
	string line;
	while (getline(ifs, line))
		vecLine.push_back(line);

	for (auto &s : vecLine)
	{
		istringstream iss(s);
		string word;
		while (iss >> word)
			cout << word << ", ";
		cout << endl;
	}
}
struct PersonTele{
    string name;
    vector<string> teleNo;
};

void telephoneRecord(const string &filePath){
    ifstream ifs(filePath);
    string buf;
    istringstream istream;
    vector<PersonTele> personGroup;
    ostringstream goodOstream,badOstream;

    while (getline(ifs,buf))
    {
        PersonTele personT;
        istream.clear();
        istream.str(buf);
        string sTemp;

        if(!istream){
            cout << "file is not exist!"<<endl;
        }else{
            istream >> personT.name;
            while(istream>>sTemp){
                personT.teleNo.push_back(sTemp);
            }
        }
        personGroup.push_back(personT);
    }

    for(const auto &p:personGroup){
        cout << "name: " << p.name << "  ";
        for(const auto &t : p.teleNo){
            cout << t << " ";
        }
        cout << endl;
    }

    for(const auto &p : personGroup){
        for(const auto& t: p.teleNo){
            if(t.size()<100){
                goodOstream <<" "<< t;
            }
            else{
                badOstream <<" "<< t;
            }
        }
        if(badOstream.str().empty()){
            cout << goodOstream.str() << " name: " << p.name<<endl;
        }else{
            cerr << "bad number is :"<<badOstream.str() << " name : " << p.name << endl;
        }
    }
    
}