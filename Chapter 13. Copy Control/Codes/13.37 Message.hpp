#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <string>
#include <set>

// Forward declaration.
class Folder;

class Message {
    friend class Folder;
    friend void swap(Message&, Message&);

 public:
  explicit Message(const std::string& str = std::string()) : mContent(str) {}
  Message(const Message&);
  Message& operator=(const Message&);
  ~Message();

  void m_save(Folder&);
  void m_remove(Folder&);

  void m_printContent();

 private:
  std::string mContent;
  std::set<Folder*> mFolders;

  void m_add_folder(Folder*);
  void m_remove_folder(Folder*);

  // Helper functions for copy control members.
  void m_add_to_folders(const Message&);
  void m_remove_from_folders();
};

#endif
