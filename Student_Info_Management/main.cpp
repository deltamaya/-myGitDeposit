#include "STUDENT.h"

using namespace std;
int main() {
	stu* head =fread();
	stu* p = head;
	for (p = head; p->next != NULL; p = p->next);
	int choice=0;
again:
	menu();
	cin >> choice;
	switch (choice)
	{
		case 0:
			save(head);
			exit(0);
			cout << "Quit" << endl;
			break;
		case 1:
			p=In(p);
			save(head);
			goto again;
			break;
		case 2:
			Modify(head);
			goto again;
			break;
		case 3:
			head=Del(head);
			goto again;
			break;
		case 4:
			print_all(head);
			goto again;
			break;
		case 5:
			head=sortList(head);
			save(head);
			goto again;
			break;
		case 6:
			print_stu(head);
			goto again;
			break;
	default:
		cout << "Invalid! " << endl;
		goto again;
		break;
	}
	return 0;
}