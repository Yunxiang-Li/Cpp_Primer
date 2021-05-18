#ifndef QUERYRESULT_HPP
#define QUERYRESULT_HPP

#include "TextQuery.hpp"

class QueryResult {
  friend std::ostream& print(std::ostream&, const QueryResult&);

 public:
  QueryResult(const std::string& word, std::shared_ptr<std::set<StrBlob::dataSize>> wordLinesSetPtr,
              std::shared_ptr<StrBlob> fileContentVecPtr) : m_word(word),
              m_wordLinesSetPtr(wordLinesSetPtr), m_fileContentVecPtr(fileContentVecPtr) {}

  std::set<StrBlob::dataSize>::iterator begin() const;
  std::set<StrBlob::dataSize>::iterator end() const;
  std::shared_ptr<StrBlob> get_file();

 private:
  std::string m_word;

  std::shared_ptr<std::set<StrBlob::dataSize>> m_wordLinesSetPtr;
  std::shared_ptr<StrBlob> m_fileContentVecPtr;

};

#endif
