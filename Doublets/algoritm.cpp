#include <fstream>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <set>
using namespace std;

void getFile(set<string>& fileList);

const string ALPHABET  = "abcdefghijklmnopqrstuvwxyz";

int main() {

    string startStr;
    string endStr;
    int conter = 0;

    set<string> wordlist;

    getFile(wordlist);

    while (cin >> startStr) {
	    cin >> endStr;
	    if (conter != 0) cout << '\n';
	    conter++;

	    queue<stack<string> > wordChains;
	    stack<string> queueTop;
	    set<string> usedList;
	    bool done = false;

    	queueTop.push(startStr);
    	wordChains.push(queueTop);

    	while (wordChains.size() != 0 && !done) {

        	queueTop = wordChains.front();
        	wordChains.pop();

        	if (queueTop.top() == endStr) {
        		stack<string> temp;
            	while (queueTop.size() != 0) {
            		temp.push(queueTop.top());
                	queueTop.pop();
            	}
            	while (temp.size() != 0) {
                	cout << temp.top() << endl;
                	temp.pop();
            	}
            	done = true;
        	} else { // Find neighbor loop
            	int strLen = startStr.length();
            	int althabetLen = ALPHABET.length();
            	for (int w = 0; w < strLen; w++) {
                	for (int n = 0; n < althabetLen; n++ ) {

                	    string replaceString = queueTop.top();;

                	    replaceString[w] = ALPHABET[n];

                	    set<string>::iterator wordIt = wordlist.find(replaceString);
                	    set<string>::iterator usedIt = usedList.find(replaceString);

                    	if (wordIt != wordlist.end() && usedIt == usedList.end()) {
                        	stack<string> tempStak = queueTop;

                    	    tempStak.push(replaceString);
                    	    wordChains.push(tempStak);
                    	    usedList.insert(replaceString);
                    	}

                	}
            	}
        	}

    	}
    	if (wordChains.size() == 0 && !done) cout << "No solution." << endl;
	}
    return 0;
}


void getFile(set<string>& fileList) {

    string line;
    getline(cin,line);

    while (!line.empty()) {
    	
		fileList.insert(line);
		getline(cin,line);
    }
}