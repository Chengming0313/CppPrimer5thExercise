
int txt_size();

int main()
{
    unsigned buf_size = 1024;
    /* 非法，数组维度必须是一个常量表达式 */
    int ia[ buf_size ];
    /* 合法 */
    int ib[ 4 * 7 - 14 ];
    /* 非法，不能使用非constexpr函数作为数组维度 */
    int ic[ txt_size() ];
    /* "fundamental"类型为const char[12]，而st小了 */
    char st[ 11 ] = "fundamental";
    return 0;
}