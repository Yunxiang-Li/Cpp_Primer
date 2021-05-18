#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

int main() {
    using lineNo = std::vector<std::string>::size_type;
    std::ifstream file("../file.txt");
    std::vector<std::string> fileContent;
    std::map<std::string, std::set<lineNo>> wordSetMap;
    lineNo lineNumber{0};

    for (std::string eachLine; std::getline(file, eachLine); ++lineNumber) {
        fileContent.emplace_back(eachLine);
        std::istringstream line_stream(eachLine);

        for (std::string word; line_stream >> word; word.clear()) {
            std::remove_copy_if(word.begin(), word.end(),
                                std::back_inserter(word), ispunct);
            wordSetMap[word].insert(lineNumber);
        }
    }

    do {
        std::cout << "Enter word to look for, or enter q to quit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q")
            break;

        auto iter = wordSetMap.find(s);
        if (iter != wordSetMap.end()) {
            std::cout << s << " occurs " << iter -> second.size()
                      << (iter -> second.size() > 1 ? " times" : " time")
                      << std::endl;

            for (auto i : iter -> second)
                std::cout << "\t(line " << i + 1 << ") " << fileContent.at(i)
                          << std::endl;
        }
        else
            std::cout << s << " occurs 0 time" << std::endl;
    } while (true);

    return 0;
}




