#ifndef TEXTQUERY_HPP
#define TEXTQUERY_HPP

#include <fstream>
#include <string>
#include <memory>
#include <vector>
#include <map>
#include <set>

class QueryResult;

class TextQuery {
 public:
  using lineNo = std::vector<std::string>::size_type;

  explicit TextQuery(std::ifstream&);
  TextQuery(const TextQuery&) = default;
  TextQuery& operator=(const TextQuery&) = default;
  ~TextQuery() = default;

  QueryResult m_query(const std::string&) const;

 private:
  std::shared_ptr<std::vector<std::string>> m_fileContentsVecPtr;
  std::map<std::string, std::shared_ptr<std::set<lineNo>>> m_wordLinesSetPtrMap;
};

#endif
