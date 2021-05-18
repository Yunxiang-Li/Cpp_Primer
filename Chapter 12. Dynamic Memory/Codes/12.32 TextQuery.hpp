#ifndef TEXTQUERY_HPP
#define TEXTQUERY_HPP

#include <fstream>
#include <string>
#include <memory>
#include <vector>
#include <map>
#include <set>
#include "StrBlob.hpp"

class QueryResult;

class TextQuery {
 public:

  explicit TextQuery(std::ifstream&);
  TextQuery(const TextQuery&) = default;
  TextQuery& operator=(const TextQuery&) = default;
  ~TextQuery() = default;

  QueryResult m_query(const std::string&) const;

 private:
  std::shared_ptr<StrBlob> m_fileContentsVecPtr;
  std::map<std::string, std::shared_ptr<std::set<StrBlob::dataSize>>> m_wordLinesSetPtrMap;
};

#endif
