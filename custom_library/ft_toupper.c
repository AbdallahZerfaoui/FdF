
// The value of c must be between -128 and 127
// The function ft_toupper() converts a lower-case letter to 
// the corresponding upper-case letter.
int ft_toupper(int c)
{
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    if (c < -1)
        return (c + 256);
    return (c);
}