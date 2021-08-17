//
//  Message.cpp
//
//  Created by Tang Chengming on 2021/8/3.
//
//  @Brief  
//

#include "ex13_34_37_Message.h"
#include "ex13_36_Folder.h"

#include <iostream>

// copy op=
Message &Message::operator=(Message const &rhs) {
    // 在之前的 folder 中移除 this 指针
    removeFromFolders();
    contents_ = rhs.contents_;
    pFolderSet_ = rhs.pFolderSet_;
    // 在新的 folder 中添加 this 指针
    addToFolders();
    return *this;
}

// move ctor
Message::Message(Message &&rhs) noexcept : contents_(std::move(rhs.contents_)) {
    // 移动 contents_, pFolderSet_
    // 对应的 folder 不再指向 rhs
    // 对应的 folder 指向 this
    moveFolders(&rhs);
}

// move op=
Message &Message::operator=(Message &&rhs) noexcept {
    // 旧的 folder 不再指向 this
    removeFromFolders();
    // 移动 contents_, pFolderSet_
    contents_ = std::move(rhs.contents_);
    // 新的 folder 不再指向 rhs
    // 新的 folder 指向 this
    moveFolders(&rhs);
}

void Message::swap(Message &rhs) {
    using std::swap;    // 当成员没有定义 swap时，调用 std::swap
    // 将 this 和 rhs 从原来的文件夹中移除
    removeFromFolders();
    rhs.removeFromFolders();
    swap(contents_, rhs.contents_);
    swap(pFolderSet_, rhs.pFolderSet_);
    // 将 this 和 rhs 添加到新的文件夹中
    addToFolders();
    rhs.addToFolders();
}

void Message::save(Folder &folder) {
    pFolderSet_.insert(&folder);
    folder.addMsg(*this);
}

void Message::remove(Folder &folder) {
    pFolderSet_.erase(&folder);
    folder.removeMsg(*this);
}

void Message::addToFolders() {
    for (Folder *pFolder : pFolderSet_) {
        pFolder->addMsg(*this);
    }
}

void Message::removeFromFolders() {
    for (Folder *pFolder : pFolderSet_) {
        pFolder->removeMsg(*this);
    }
}

// Message 单方面添加 Folder
void Message::addFolder(Folder &folder) {
    pFolderSet_.insert(&folder);
}

// Message 单方面移除 Folder
void Message::removeFolder(Folder &folder) {
    pFolderSet_.erase(&folder);
}

void Message::moveFolders(Message *rhs) {
    pFolderSet_ = std::move(rhs->pFolderSet_);
    for (auto pFolder : pFolderSet_) {
        pFolder->removeMsg(*rhs);
        pFolder->addMsg(*this);
    }
    rhs->pFolderSet_.clear();
}

void Message::printDebug() {
    std::cout << contents_ << std::endl;
}





