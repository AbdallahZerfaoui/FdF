
int count_char_occurrences(const char *str, char c) 
{
    int count = 0;
    while (*str) 
    {
        if (*str == c)
            count++;
        str++;
    }
    return count;
}