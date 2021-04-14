int main()
{
    const int i   = 42;
    auto j        = i;   // int j
    const auto &k = i;   // const int &k
    auto *p       = &i;  // const int **p
    auto p2       = &i;
    const auto j2 = i, &k2 = i;  // const int j2 const int &k2
}