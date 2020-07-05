#include<bits/stdc++.h> 
#include "utils.h"
using namespace std;

multimap <string, string> model;

void create_map_model(){
	fstream file;
	string word,tmp;
	string filename="words_alpha.txt";
	file.open(filename.c_str());
	while(file>>word){
		tmp=soundex(word);
		model.insert(pair <string, string> (tmp,word));
	}
	file.close();
}

vector<string>  final_set_with_soundex(string a){
	transform(a.begin(), a.end(), a.begin(), ::tolower);
	multimap<string, string> :: iterator itr;
	multimap<int, string> :: iterator itr2;
	multimap <string, string> near_words;
	vector <string> final,nil;
	string b;
	//cout<<"Enter string:";
	//cin>>a;
	b=soundex(a);
	for(itr=model.begin(); itr!=model.end(); itr++){
		if(b==itr->first)
			near_words.insert(pair<string, string> (itr->first, itr->second));
	}
	for(itr=near_words.begin(); itr!=near_words.end();itr++){
		if(edit(a,a.length(),itr->second,itr->second.length())<2){
			if(edit(a,a.length(),itr->second,itr->second.length())==0){
				//cout<<"Word is valid/";
				return nil;
			}
			final.push_back(itr->second);
		}
	}
	return final;
}

/*int main(){
	multimap<int, string> final;
    string a;
    cout<<"Enter string:";
	cin>>a;
	final = final_set_with_soundex(a);
	if(final.size()!=0){
		for(auto itr=final.begin(); itr!=final.end();itr++){
			cout<<itr->second<<",";
		}
	}
	else{
		cout<<"No Suggestions ";
	}
	return 0;
}*/