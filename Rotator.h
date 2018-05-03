#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector<string> explode(string del, string str) {
	int slen = str.length();
	int dlen = del.length();
	int found_a;
	string before;
	vector<string> final;
	vector<string> fail (0);
	if(dlen == 0) return fail;
	if(slen == 0) return fail;
	for(int counter = 0; counter < slen; counter ++)
	{
		found_a = str.find(del);
		if(found_a != string::npos)
		{
			before = str.substr(0, found_a + dlen);
			final.push_back(before);
			str.replace(0, found_a + dlen, "");
		}
		else
		{
			if(str.length() > 0)
			{
				final.push_back(str);
				str.replace(0, str.length(), "");
			}
			else
			{
				break;
			}
		}
	}
	return final;
}

void rtrim(string& s, char c) {
	if (s.empty())
		return;
	std::string::iterator p;
	for (p = s.end(); p != s.begin() && *--p == c;);
		if (*p != c)
			p++;
	s.erase(p, s.end());
}

string list_to_str(list<string> &l) {
	list<string>::iterator iter;
	string s = "";
	for(iter = l.begin(); iter != l.end(); iter++) {
		s = s + *iter + " ";
	}
	return s;
}

class Rotator {
	private:
		vector<string> phrase;
	public:
		vector<string> getRotations(vector<string> &phrase);
		Rotator(vector<string> &phrase);
};

Rotator::Rotator(vector<string> &phrase) {
}

vector<string> Rotator::getRotations(vector<string> &phrase) {
	vector<string> rotations;
	vector<string>::iterator phrase_iter;
	for(phrase_iter = phrase.begin(); phrase_iter != phrase.end(); phrase_iter++) {
		vector<string> words_vector = explode(" ", *phrase_iter);
		vector<string>::iterator words_iter;
		list<string> words_list;
		for (words_iter = words_vector.begin(); words_iter != words_vector.end(); words_iter++) {
			rtrim(*words_iter, ' ');
			words_list.push_back(*words_iter);
		}

		string rotation;
		do {
			string first_word = words_list.front();
			words_list.push_back(first_word);
			words_list.pop_front();
			rotation = list_to_str(words_list);
			rtrim(rotation, ' ');
			if(rotation != *phrase_iter) {
				rotations.push_back(rotation);
			}
		} while(rotation != *phrase_iter);
	}
	
	return rotations;
}


