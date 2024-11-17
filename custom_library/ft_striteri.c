
// ft_striteri takes a string and a function as arguments. 
// The function iterates over the string and applies the function to each character in the string. 
// The function takes the index of the character and a pointer to the character as arguments.
void ft_striteri(char *s, void (*func)(unsigned int, char*))
{
    unsigned int i;

    i = 0;
    while (s[i])
    {
        func(i, &s[i]);
        i++;
    }
}