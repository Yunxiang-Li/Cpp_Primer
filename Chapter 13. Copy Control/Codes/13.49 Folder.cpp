#include "Folder.hpp"
#include "Message.hpp"
#include <iostream>

Folder::Folder(const Folder& folder) : m_msgs(folder.m_msgs){
    m_add_to_Messages(*this);
}

Folder& Folder::operator=(const Folder& folder) {
    m_remove_from_Messages();
    m_msgs = folder.m_msgs;
    m_add_to_Messages(*this);

    return *this;
}

Folder::Folder(Folder&& folder) {
    m_move_Messages(&folder);
}

Folder& Folder::operator=(Folder&& folder) {
    if (this != &folder) {
        m_remove_from_Messages();
        m_move_Messages(&folder);
    }
    return *this;
}

Folder::~Folder() {
    m_remove_from_Messages();
}

void Folder::m_add_to_Messages(const Folder& folder) {
    for (auto msgPtr : folder.m_msgs)
        msgPtr -> m_add_folder(this);
}

void Folder::m_remove_from_Messages() {
    for (auto msgPtr : m_msgs)
        msgPtr -> m_remove_folder(this);
}

void Folder::addMsg(Message* msgPtr) {
    m_msgs.insert(msgPtr);
}

void Folder::remMsg(Message* msgPtr) {
    m_msgs.erase(msgPtr);
}

void Folder::m_printContent() {
    std::cout << '\n' << '\n' << "Folder content start: " << '\n';
    for (auto msgPtr : m_msgs)
        msgPtr -> m_printContent();
    std::cout << '\n' << "Folder content end!" << '\n' << '\n';
}

void swap(Folder& folderOne, Folder& folderTwo) {
    folderOne.m_remove_from_Messages();
    folderTwo.m_remove_from_Messages();

    std::swap(folderOne.m_msgs, folderTwo.m_msgs);

    folderOne.m_add_to_Messages(folderOne);
    folderTwo.m_add_to_Messages(folderTwo);
}

void Folder::m_move_Messages(Folder* folderPtr) {
    m_msgs = std::move(folderPtr -> m_msgs);
    for (Message* msgPtr : m_msgs) {
        msgPtr -> m_remove_folder(folderPtr);
        msgPtr -> m_add_folder(this);
    }
    folderPtr -> m_msgs.clear();
}
