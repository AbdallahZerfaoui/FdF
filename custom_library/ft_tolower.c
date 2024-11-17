
// The value of c must be between 0 and 255
// The function ft_tolower() converts an upper-case letter to the corresponding lower-case letter.
int ft_tolower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return (c + 32);
    if (c < -1)
        return (c + 256);
    return (c);
}

// Test ft_tolower
// #include <stdio.h>
// #include <ctype.h>
// int main()
// {
//     char test_cases_tolower[] = {'A', 'z', 'm', '1', '#', ' ', 0, -1, 'a', 'Z', -127, -128};
//     int num_tests_tolower = sizeof(test_cases_tolower) / sizeof(test_cases_tolower[0]);

//     for (int i = 0; i < num_tests_tolower; i++) {
//         int c = test_cases_tolower[i];
//         int actual = ft_tolower(c);
//         int expected = tolower(c);
        
//         printf("Test %d: ft_tolower(%d) = %d\n", i + 1, c, actual);
//     }
// }