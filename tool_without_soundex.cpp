#include<bits/stdc++.h>
#include "utils.h"
using namespace std;

string getfile(ifstream& is) {
  string contents;
  for (char ch; is.get(ch); contents.push_back(ch)) {}
  return contents;
}

string find_and_replace(string file_contents,const string word, const string rep, int i) {
	auto pos = file_contents.find(word,i);
	if(pos != string::npos){
		file_contents.replace(pos, word.length(), rep);
	}
	return file_contents;
}

int main(int argc,char* argv[]){
	if(argc!=3){
		cout<<"Command Error";
		return 1;
	}
	ifstream filein(argv[1]);
  	ofstream fileout(argv[2]);
	string contents = getfile(filein);
	string word,filename,rep;
	stringstream ss(contents);
	int i = 0;
	/*if(filein || fileout){
        cout<<"Error opening file";
        return 1;
    }*/
	vector<string> final;
	while(ss>>word){		
		final = final_set_without_soundex(word);
		if(final.size() == 0){
			i = i+word.length()+1;
			continue;
		}
		else{
			rep=word;
			rep+="(";
			for(auto itr=final.begin(); itr!=final.end();itr++){
				rep+=(*itr+"/");
			}
			rep+=")";
			contents = find_and_replace(contents, word, rep, i);
			i = i+rep.length()+1;
		}
	}
	fileout<<contents;
	cout<<"Rectified file is saved";
	return 0;
}