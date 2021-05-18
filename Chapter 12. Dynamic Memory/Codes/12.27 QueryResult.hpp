#ifndef QUERYRESULT_HPP
#define QUERYRESULT_HPP

#include "TextQuery.hpp"

class QueryResult {
  friend std::ostream& print(std::ostream&, const QueryResult&);

 public:
  QueryResult(const std::string& word, std::shared_ptr<std::set<TextQuery::lineNo>> wordLinesSetPtr,
              std::shared_ptr<std::vector<std::string>> fileContentVecPtr) : m_word(word),
              m_wordLinesSetPtr(wordLinesSetPtr), m_fileContentVecPtr(fileContentVecPtr) {}

 private:
  std::string m_word;

  std::shared_ptr<std::set<TextQuery::lineNo>> m_wordLinesSetPtr;
  std::shared_ptr<std::vector<std::string>> m_fileContentVecPtr;

};

#endif
