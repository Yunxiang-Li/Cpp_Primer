#include "Message.hpp"
#include "Folder.hpp"
#include <iostream>

Message::Message(const Message& msg) : mContent(msg.mContent), mFolders(msg.mFolders) {
    m_add_to_folders(msg);
}

Message& Message::operator=(const Message& msg) {
    m_remove_from_folders();
    mContent = msg.mContent;
    mFolders = msg.mFolders;
    m_add_to_folders(msg);
    return *this;
}

Message::Message(Message&& msg) : mContent(std::move(msg.mContent)) {
    m_move_folders(&msg);
}

Message& Message::operator=(Message&& msg) {
    if (this != &msg) {
        m_remove_from_folders();
        mContent = std::move(msg.mContent);
        m_move_folders(&msg);
    }

    return *this;
}

Message::~Message() {
    m_remove_from_folders();
    mFolders.clear();
}

void Message::m_add_folder(Folder* folderPtr) {
    mFolders.insert(folderPtr);
}

void Message::m_remove_folder(Folder* folderPtr) {
    mFolders.erase(folderPtr);
}

void Message::m_add_to_folders(const Message& msg) {
    for (auto f : msg.mFolders)
        f -> addMsg(this);
}

void Message::m_remove_from_folders() {
    for (auto f : mFolders)
        f -> remMsg(this);
}

void Message::m_save(Folder& folder) {
    m_add_folder(&folder);
    folder.addMsg(this);
}

void Message::m_remove(Folder& folder) {
    m_remove_folder(&folder);
    folder.remMsg(this);
}

void swap(Message& msgOne, Message& msgTwo) {
    msgOne.m_remove_from_folders();
    msgTwo.m_remove_from_folders();

    std::swap(msgOne.mContent, msgTwo.mContent);
    std::swap(msgOne.mFolders, msgTwo.mFolders);

    msgOne.m_add_to_folders(msgOne);
    msgTwo.m_add_to_folders(msgTwo);
}

void Message::m_printContent() {
    std::cout << "Message content is: " << mContent;
}

void Message::m_move_folders(Message* msg) {
    mFolders = std::move(msg -> mFolders);
    for (Folder* folderPtr : mFolders) {
        folderPtr -> remMsg(msg);
        folderPtr -> addMsg(this);
    }
    msg -> mFolders.clear();
}

