//
//  Message.h
//
//  Created by Tang Chengming on 2021/8/3.
//
//  @Brief
//          ex13.49 添加 move ctor, move op=
//

#ifndef CPP_PRIMER5_Message_H
#define CPP_PRIMER5_Message_H

#include <string>
#include <set>
#include <algorithm>

class Folder;

class Message {
    friend class Folder;
public:
    // ------------------------- 构造函数 -------------------------

    explicit Message(std::string content) : contents_(content), pFolderSet_(std::set<Folder *>()) {}

    // ------------------------- 拷贝控制 -------------------------
    // copy ctor
    Message(Message const &rhs) : contents_(rhs.contents_), pFolderSet_(rhs.pFolderSet_){
        // 在对应的 folder 中添加 this 指针
        addToFolders();
    }

    // copy op=
    Message &operator=(Message const &rhs);

    // dtor
    ~Message() {
        removeFromFolders();
    }

    // move ctor
    Message(Message &&) noexcept;

    // move op=
    Message &operator=(Message &&) noexcept;

    // swap
    void swap(Message &);

    // ------------------------- 功能函数 -------------------------

    // 将 this 消息保存到新的 Folder
    void save(Folder &);

    // 从 Folder 中删除 this 消息
    void remove(Folder &);

    // ------------------- Debug -------------------

    // 输出消息内容
    void printDebug();
private:
    std::string contents_;           // 消息内容
    std::set<Folder *> pFolderSet_;  // 文件夹列表

    // ------------------------- 工具函数 -------------------------

    void addToFolders();

    void removeFromFolders();

    void moveFolders(Message *);

    // ------------------------- Folder 调用 -------------------------

    // Message 单方面添加 Folder
    void addFolder(Folder &);

    // Message 单方面移除 Folder
    void removeFolder(Folder &);


};

#endif //CPP_PRIMER5_Message_H
