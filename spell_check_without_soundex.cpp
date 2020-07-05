#include<bits/stdc++.h> 
#include "utils.h"
using namespace std;

vector<string> final_set_without_soundex(string a){
	transform(a.begin(), a.end(), a.begin(), ::tolower);
	vector <string> final,nil;
	fstream file;
	string word,tmp;
	string filename="words_alpha.txt";
	file.open(filename.c_str());
	while(file>>word){
		if(edit(a,a.length(),word,word.length())<2){
			if(edit(a,a.length(),word,word.length())==0){
				//cout<<"Word is valid/";
				return nil;
			}
			final.push_back(word);
		}
	}
	file.close();

	return final;
}

//int main(){
//	vector<string> final;
//  string a;
//  cout<<"Enter string:";
//	cin>>a;
//	final = final_set_without_soundex(a);
//	if(final.size() == 0){
//		cout<<"No Suggestions ";
//	}
//	else{
//		for(auto itr=final.begin(); itr!=final.end();itr++){
//			cout<<*itr<<",";
//		}
//	}
//	return 0;
//}