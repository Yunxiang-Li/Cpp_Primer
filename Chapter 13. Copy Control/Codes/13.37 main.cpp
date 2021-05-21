#include "Message.hpp"
#include "Folder.hpp"

int main() {
    Message firstMail("Hello");
    Message secondMail("World!!!");
    Folder mailBox;

    firstMail.m_printContent();
    firstMail.m_save(mailBox);
    mailBox.m_printContent();

    secondMail.m_printContent();
    secondMail.m_save(mailBox); 
    mailBox.m_printContent();

    firstMail = firstMail;
    firstMail.m_printContent();
    mailBox.m_printContent();

    return 0;
}

/*

Output:

Message content is: Hello

Folder content start:
Message content is: Hello
Folder content end!

Message content is: World!!!

Folder content start:
Message content is: World!!!Message content is: Hello
Folder content end!

Message content is: Hello

Folder content start:
Message content is: World!!!Message content is: Hello
Folder content end!

 */



