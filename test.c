#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"
int main()
{
	int select = 0;
	volatile int quit = 0;//保持内存的可见性
	contact_p ct;
	Load(&ct);
	while (!quit){
		menu();
		scanf("%d", &select);
		switch (select){
		case 1:
			ShowContact(ct);
			break;
		case 2:
			AddPerson(&ct);
			break;
		case 3:
			DelPerson(&ct);
			break;
		case 4:
			ModPerson(&ct);
			break;
		case 5:
			SearchPerson(ct);
			break;
		case 6:
			SortContact(ct);
			break;
		case 7:
			ClearPerson(&ct);
			break;
		case 8:
			Save(ct);
			printf("Save!\n");
			quit = 1;
			break;
		default:
			printf("Your Enter Error!\n");
			break;
		}
	}
	system("pause");
	return 0;

}
