#include <unistd.h>

char	get_choice(void)
{
	char c;
	char trash;


	read(0, &c, 1);

	while (read(0, &trash, 1) > 0 && trash != '\n');

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

void	ft_readline(char *buffer, int size)
{
	int		i;
	char	c;

	i = 0;
	while (i < size - 1)
	{
		if (read(0, &c, 1) <= 0)
			break ;
		if (c == '\n')
			break ;
		buffer[i] = c;
		i++;
	}
	buffer[i] = '\0';
}


void	ft_putchar(char c)
{
	write(1, &c, 1);
}


void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);

	ft_putchar((n % 10) + '0');
}


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
		{
			if (count >= 10)
			{
				ft_putstr("PhoneBook is full!\n\n");
				continue ;
			}

			ft_putstr("Enter name: ");
			ft_readline(names[count], 50);

			ft_putstr("Enter phone: ");
			ft_readline(phones[count], 15);

			count++;

			ft_putstr("Contact added!\n\n");
		}	
		else if (choice == '2')
		{
			int i;

			i = 0;

			if (count == 0)
			{
				ft_putstr("No contacts.\n\n");
				continue ;
			}

			while (i < count)
			{
				ft_putnbr(i + 1);
				ft_putstr(" - ");
				ft_putstr(names[i]);
				ft_putstr(" : ");
				ft_putstr(phones[i]);
				ft_putstr("\n");

				i++;
			}

			ft_putstr("\n");
		}
		else if (choice == '3')
		{
			ft_putstr("Bye!\n");
			break;
		}
	}
    return (0);


}
