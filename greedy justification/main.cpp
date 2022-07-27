/*
    Given a string and a line width, split the string into words
    (a maximal run of characters excluding spaces) and write the words
    onto successive lines with spaces added between the words so that
    each line is the requested width. Words should be added to lines
    greedily (as many words as will fit) and extra spaces should be
    assigned to the left of the output string. The last line should
    not have spaces added, so it may be shorter than the other lines.

For example, the string “This is an example of text justification”
is written with a line width of 16 like this:

    ----+----+----+-
    This    is    an
    example  of text
    justification.
    ----+----+----+-

https://programmingpraxis.com/2021/03/30/greedy-text-justification/
*/

#include <iostream>
#include <fstream>
#include <string>

void fillSpaces(std::string &line, size_t lineWidth) {
    size_t spacePos = 0;
    if(line.find(' ') == std::string::npos) return;
    while(line.size() < lineWidth) {
        spacePos = line.find(' ', spacePos) + 1;
        if(spacePos == std::string::npos) {
            spacePos = 0;
            continue;
        } else if(spacePos == 0) continue;
        line.insert(spacePos++, " ");
    }
}

int main(int argc, char** argv) {
    if(argc < 2) return EXIT_FAILURE;
    size_t lineWidth = atoi(argv[1]);

    std::ifstream in;
    std::ofstream out;

    in.open("input.txt");
    if(!in.is_open()) {
        std::cerr << "Unable to open input.txt" << std::endl;
        return EXIT_FAILURE;
    }

    out.open("output.txt");

    std::string word, line;
    while(in >> word) {
        if(line.size() == 0) {
            if(word.size() > lineWidth) {
                line.append(word.substr(0, lineWidth - 1) + "-");
                out << line << '\n';
                line.clear();
                line.append(word.substr(lineWidth - 1, word.size()));
            } else {
                line.append(word);
            }
        } else if(line.size() + word.size() + 1 <= lineWidth) {
            line.append(" " + word);
        } else {
            fillSpaces(line, lineWidth);
            out << line << '\n';
            line.clear();
            if(word.size() > lineWidth) {
                line.append(word.substr(0, lineWidth - 1) + "-");
                out << line << '\n';
                line.clear();
                line.append(word.substr(lineWidth - 1, word.size()));
            } else {
                line.append(word);
            }
        }       
    }
    out << line;
    out.close();
    in.close();
}