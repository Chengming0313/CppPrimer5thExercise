//
//  ex13_28.cpp
//
//  Created by Tang Chengming on 2021/7/15.
//
//  @Brief  构建二叉树以及二叉树节点类
//

#include <string>

// TreeNode 中的 count_ 为引用计数变量, 在拷贝控制的过程中需要完成子结点引用计数的控制.
class TreeNode {
public:
    // default ctor
    TreeNode() : value_(std::string("NA")), count_(new int(1)), left_(nullptr), right_(nullptr) {}

    // copy ctor
    TreeNode(TreeNode const &rhs) : value_(rhs.value_), count_(rhs.count_), left_(rhs.left_), right_(rhs.right_) {
        // 增加引用计数
        rhs.copy();
    }

    // copy op=
    // 这里的参数应该是 const 吗
    TreeNode &operator=(TreeNode const &rhs) {
        // 增加 rhs 的引用计数
        rhs.copy();
        // 减小当前节点的引用计数
        release();
        value_ = rhs.value_;
        left_ = rhs.left_;
        right_ = rhs.right_;

    }

    ~TreeNode() {
        // 减小引用计数
        release();
    }


private:
    // 增加节点的引用计数
    void copy() const{
        ++(*count_);
        // 增加左子树的引用计数
        if (left_) {
            left_->copy();
        }
        // 增加右子树的引用计数
        if (right_) {
            right_->copy();
        }
    }

    // 减小节点的引用计数
    void release() {
        // 当前节点引用计数减1, 如果为0, 释放资源
        if (--(*count_)) {
            delete count_;
        }
        // 减小左子树的引用计数
        if (left_) {
            left_->release();
        }
        // 减小右子树的引用计数
        if (right_) {
            right_->release();
        }
    }

    std::string value_;     // 字符串指针
    int *count_;             // 引用计数指针
    TreeNode *left_;        // 左结点
    TreeNode *right_;       // 右结点
};


// BinStrTree 中的原始指针 root_ 指向动态分配的内存, 因此需要拷贝控制对 root_ 进行管理.
class BinStrTree {
public:
    // default ctor
    explicit BinStrTree() : root_(new TreeNode()) {}

    // copy ctor
    BinStrTree(BinStrTree const &rhs) : root_(new TreeNode(*rhs.root_)) {}

    // copy op=
    BinStrTree &operator=(BinStrTree const &rhs) {
        auto *newRoot = new TreeNode(*rhs.root_);
        delete root_;
        root_ = newRoot;
        return *this;
    }

    // dtor
    ~BinStrTree() {
        delete root_;
    }

private:
    TreeNode *root_; // 根节点
};

