#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>

class Book {
  friend std::istream& operator>>(std::istream&, Book&);
  friend std::ostream& operator<<(std::ostream&, const Book&);
  friend bool operator==(const Book&, const Book&);
  friend bool operator!=(const Book&, const Book&);

 public:
  Book() = default;
  Book(unsigned int no, const std::string& name, const std::string& author, const std::string& pubdate)
      : no_(no), name_(name), author_(author), pubdate_(pubdate)
  {
  }

 private:
  unsigned int no_;
  std::string name_;
  std::string author_;
  std::string pubdate_;
};

#endif // BOOK_HPP
