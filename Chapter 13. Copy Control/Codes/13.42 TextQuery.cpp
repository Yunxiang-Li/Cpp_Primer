#include "TextQuery.hpp"
#include "QueryResult.hpp"
#include <sstream>
#include <algorithm>

TextQuery::TextQuery(std::ifstream& file) : m_fileContentsVecPtr(new StrBlob) {
    StrBlob::dataSize fileLinesNumber{0};

    for (std::string eachLine; std::getline(file, eachLine); ++fileLinesNumber) {
        m_fileContentsVecPtr -> push_back(eachLine);

        std::istringstream eachLineStrStream(eachLine);
        for (std::string eachWord; eachLineStrStream >> eachWord; eachWord.clear()) {
            // Remove punctuation.
            std::remove_copy_if(eachWord.begin(), eachWord.end(), std::back_inserter(eachWord), ispunct);
            // Use reference to avoid count adding.
            std::shared_ptr<std::set<StrBlob::dataSize>>& res = m_wordLinesSetPtrMap[eachWord];

            // If this word's mapping relationship is still not set
            if (!res)
                res.reset(new std::set<StrBlob::dataSize>());
            // Then insert the word's existing lines.
            res -> insert(fileLinesNumber);
        }
    }
}

QueryResult TextQuery::m_query(const std::string& str) const {

    // Initialize only once to improve efficiency.
    static std::shared_ptr<std::set<StrBlob::dataSize>> emptyWordLinesSetPtr(new std::set<StrBlob::dataSize>);

    std::map<std::string, std::shared_ptr<std::set<StrBlob::dataSize>>>::const_iterator iter =
        m_wordLinesSetPtrMap.find(str);

    // If this word exists at least once.
    if (iter != m_wordLinesSetPtrMap.cend())
        return QueryResult(str, iter -> second, m_fileContentsVecPtr);
    // If this word does not exist at all.
    return QueryResult(str, emptyWordLinesSetPtr, m_fileContentsVecPtr);
}
