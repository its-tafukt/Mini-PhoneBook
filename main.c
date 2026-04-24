#include <unistd.h>

char	get_choice(void)
{
	char c;
	read(0, &c, 1);
	return (c);
}


void ft_putstr(char *str)
{
    int i = 0;
    while(str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

char names[10][50];
char phones[10][15];
int count = 0;

int main()
{
    char choice;

	while (1)
	{
    ft_putstr("1 - Add Contact\n");
    ft_putstr("2 - Show Contact\n");
    ft_putstr("3 - Exit\n");
    ft_putstr("Choose: \n");

    choice = get_choice();

		if (choice == '1')
			ft_putstr("You chose Add\n\n");
		else if (choice == '2')
			ft_putstr("You chose Show\n\n");
		else if (choice == '3')
		{
			ft_putstr("Bye!\n");
			break;
		}
	}
    return (0);


}
