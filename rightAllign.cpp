#include <bits/stdc++.h>
using namespace std;

void rightAllign(int windowWidth, vector <string> words) {
    vector <vector <string> > allLines;
    int wordsSize = words.size();

    for (int i = 0; i < (int)words.size(); i += 0) {
        int usedWidth = 0;
        vector <string> currentLine;

        while (i < wordsSize && usedWidth + (int)words[i].size() + (usedWidth != 0) <= windowWidth) {
            usedWidth += (int)words[i].size() + (usedWidth != 0);
            currentLine.push_back(words[i]);
            i ++;
        }
        allLines.push_back(currentLine);
    }

    for (int i = 0; i < (int)allLines.size(); i++) {
        vector <string> currentLine = allLines[i];
        int usedSpace = 0;

        for (int j = 0; j < (int)currentLine.size(); j++) {
            if (j == (int)currentLine.size() - 1) {
                int remainingSpace = windowWidth - usedSpace;
                int whiteSpace = remainingSpace - (int)currentLine[j].size();
                while (whiteSpace --) cout << " ";
                cout << currentLine[j];
            }
            else {
                cout << (usedSpace == 0? currentLine[j] : (" " + currentLine[j]));
                usedSpace += (int)currentLine[j].size() + (usedSpace != 0);
            }
        }
        cout << "\n";
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int windowWidth;
    cin >> windowWidth;
    cin.ignore();

    string line;
    vector <string> words;

    while (getline(cin, line)) {
        stringstream iss(line);
        string tempWord;

        while (iss >> tempWord) {
            assert(("window can't fit this word", (int)tempWord.size() <= windowWidth));
            words.push_back(tempWord);
        }
    }

    rightAllign(windowWidth, words);
    return 0;
}
