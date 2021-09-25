//
//  Folder.cpp
//
//  Created by Tang Chengming on 2021/8/3.
//
//  @Brief  
//

#include "ex13_36_Folder.h"
#include "ex13_34_37_Message.h"

#include <iostream>

// copy op=
Folder &Folder::operator=(Folder const &rhs) {
    // 旧的消息中移除 this 文件夹
    removeFromMessages();

    // 拷贝文件夹名和消息指针列表
    name_ = rhs.name_;
    pMsgSet_ = rhs.pMsgSet_;

    // 新的消息中添加 this 文件夹
    addToMessages();
}

// move ctor
Folder::Folder(Folder &&rhs) noexcept : name_(rhs.name_) {
    // 移动 name_, pMsgSet_
    // rhs 对应的 Message 不再指向 rhs
    // 转而指向 this
    // 保证 rhs 可以安全销毁
    moveMsg(&rhs);
}

// move op=
Folder &Folder::operator=(Folder &&rhs) noexcept {
    // this 对应的 Message 不再指向 this
    removeFromMessages();
    // 移动 rhs 的 name_, pMsgSet_
    name_ = std::move(rhs.name_);
    // rhs 对应的 Message 不再指向 rhs
    // 转而指向 this
    // 保证 rhs 可以安全销毁
    moveMsg(&rhs);
}

// 移动 pMsgSet_ 到 this
void Folder::moveMsg(Folder *rhs) {
    pMsgSet_ = std::move(rhs->pMsgSet_);
    for (auto pMsg : pMsgSet_) {
        pMsg->removeFolder(*rhs);
        pMsg->addFolder(*this);
    }
    rhs->pMsgSet_.clear();
}

// swap
void Folder::swap(Folder &rhs) {
    using std::swap;

    // 从旧的 Message 中移除 this, rhs
    removeFromMessages();
    rhs.removeFromMessages();

    swap(name_, rhs.name_);
    swap(pMsgSet_, rhs.pMsgSet_);

    // 新的 Message 中添加 this, rhs
    addToMessages();
    rhs.addToMessages();

}

// 所有的 Message 单方面添加 this
void Folder::addToMessages() {
    for (auto pMsg : pMsgSet_) {
        pMsg->addFolder(*this);
    }
}

// 所有的 Message 完全移除 this
void Folder::removeFromMessages() {
    for (auto pMsg : pMsgSet_) {
        pMsg->removeFolder(*this);
    }
}

void Folder::addMsg(Message &Msg) {
    pMsgSet_.insert(&Msg);
}

// this 单方面移除 Msg
void Folder::removeMsg(Message &Msg) {
    pMsgSet_.erase(&Msg);
}


void Folder::printDebug() {
    std::cout << "目录名: " << name_ << "\n";
    for (auto pMsg : pMsgSet_) {
        pMsg->printDebug();
    }
}