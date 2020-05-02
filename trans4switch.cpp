constexpr unsigned int switch_translator(const char* str, int h = 0)
{
    return !str[h] ? 5381 : (switch_translator(str, h+1) * 33) ^ str[h];
}