//
//  Folder.h
//
//  Created by Tang Chengming on 2021/8/3.
//
//  @Brief
//          ex13.49 添加 move ctor, move op=
//

#ifndef CPP_PRIMER5_FOLDER_H
#define CPP_PRIMER5_FOLDER_H

#include <string>
#include <set>

class Message;

class Folder {
    friend class Message;
public:
    // ------------------- 构造函数 -------------------
    // ctor
    explicit Folder(std::string const &name) : name_(name), pMsgSet_(std::set<Message *>()) {}

    // ------------------- 拷贝控制 -------------------

    // copy ctor
    Folder(Folder const &rhs) : name_(rhs.name_), pMsgSet_(rhs.pMsgSet_) {
        // rhs 记录的 Message 添加 this 文件夹
        addToMessages();
    }

    // copy op=
    Folder &operator=(Folder const &);

    // dtor
    ~Folder() {
        // 所有对应的 Message 删除 this 文件夹
        removeFromMessages();
    }

    // move ctor
    Folder(Folder &&) noexcept;

    // move op=
    Folder &operator=(Folder &&) noexcept;

    // swap
    void swap(Folder &);

    // ------------------- Debug -------------------

    // 输出目录名以及所有的消息内容
    void printDebug();
private:
    std::string name_;              // 目录名
    std::set<Message *> pMsgSet_;   // Message 指针列表

    // ------------------- 工具函数 -------------------

    // 所有的 Message 单方面添加 this
    void addToMessages();

    // 所有的 Message 单方面移除 this
    void removeFromMessages();

    // 移动 pMsgSet_ 到 this
    void moveMsg(Folder *);

    // ------------------------- Message 调用 -------------------------

    // this 单方面添加 Msg
    void addMsg(Message &);

    // this 单方面移除 Msg
    void removeMsg(Message &);
};

#endif //CPP_PRIMER5_FOLDER_H
