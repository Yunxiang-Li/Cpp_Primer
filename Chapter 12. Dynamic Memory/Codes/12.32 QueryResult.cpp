#include "QueryResult.hpp"

std::ostream& print(std::ostream& ostream, const QueryResult& query_result) {
    ostream << query_result.m_word << " occurs " << query_result.m_wordLinesSetPtr -> size()
        << (query_result.m_wordLinesSetPtr -> size() > 1 ? " times" : " time") << std::endl;

    // Remember our line number starts from 0 thus we need to increment by one.
    for (auto i : *(query_result.m_wordLinesSetPtr)) {
        ConstStrBlobPtr p(*query_result.m_fileContentVecPtr, i);
        ostream << "\t(line " << i + 1 << ") " << p.deref() << std::endl;
    }

    return ostream;
}
