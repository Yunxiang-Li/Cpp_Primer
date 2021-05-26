#ifndef FOLDER_HPP
#define FOLDER_HPP

#include <set>

// Forward declaration.
class Message;

class Folder {
  friend class Message;
  friend void swap(Folder&, Folder&);

 public:
  Folder() = default;
  Folder(const Folder&);
  Folder& operator=(const Folder&);
  Folder(Folder&&);
  Folder& operator=(Folder&&);
  ~Folder();

  void m_printContent();

 private:
  std::set<Message*> m_msgs;

  void addMsg(Message*);
  void remMsg(Message*);

  void m_add_to_Messages(const Folder&);
  void m_remove_from_Messages();

  void m_move_Messages(Folder*);
};

#endif
