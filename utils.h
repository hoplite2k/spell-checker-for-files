#ifndef UTILS_H 
#define UTILS_H

using namespace std;

//edit.cpp
int edit(string s1, int m, string s2, int n);

//soundex.cpp
char convert(char x);
string ConvertToUpperCase(string s);
string soundex(string s);

//spell_check_without_soundex.cpp
vector<string> final_set_without_soundex(string a);

//spell_check_with_soundex.cpp
vector<string> final_set_with_soundex(string a);
void create_map_model();

#endif