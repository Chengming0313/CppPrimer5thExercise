#include <iostream>

int main()
{
    std::cout << "/*";
    std::cout << "*/";
    // 不合法 std::cout << /* "*/ " */;
    std::cout << /* " */ " /* " /* " */;
    return 0;
}