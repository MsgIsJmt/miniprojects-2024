#include <stdio.h>
#include <stdlib.h>
#include "book_management.h"

// �޴� ��� �Լ�
void printMenu() {
    printf("**** �޴� ****\n");
    printf("1. ���� ���\n");
    printf("2. ���� �뿩\n");
    printf("3. ���� �ݳ�\n");
    printf("4. ���� �˻�\n");
    printf("5. ���� ����\n");
    printf("6. ���� ���\n");
    printf("0. ����\n");
}


int main() {
    //    int choice, id;
    int id;
    char input[MAX_LEN];
    char title[MAX_LEN], author[MAX_LEN], publisher[MAX_LEN], renter[MAX_LEN], keyword[MAX_LEN];

    // �޴��� �ݺ��Ͽ� ����ϰ� ������� ���ÿ� ���� ���� ����
    while (1) {
        int choice = -1;
        printMenu(); // �޴� ���
        printf("�޴��� �����ϼ���: ");
        scanf(" %d", &choice);
        getchar(); // �Է� ���� ����

        // ���ڰ� �ƴ� ��� ó��
        if (choice < 0 || choice > 6) { // �޴� ���� ���� Ȯ��
            printf("�߸��� �Է��Դϴ�. 0���� 6������ ���ڸ� �Է��ϼ���.\n");
            continue; // �ٽ� �޴��� �̵�
        }


        switch (choice) {
        case 1:// ���� ���
            printf("���� ������ �Է��ϼ���: ");
            scanf("%s", title);
            printf("�۰��� �Է��ϼ���: ");
            scanf("%s", author);
            printf("���ǻ縦 �Է��ϼ���: ");
            scanf("%s", publisher);
            printf("���� ID�� �Է��ϼ���: ");
            scanf("%d", &id);
            addBook(title, author, publisher, id);
            printf("���� ����� �Ϸ�Ǿ����ϴ�.\n");
            printf("\n");
            break;

        case 2:// ���� �뿩
            printf("�뿩�� ������ ID�� �Է��ϼ���: ");
            scanf("%d", &id);
            printf("�뿩�� �̸��� �Է��ϼ���: ");
            scanf("%s", renter);
            rentBook(id, renter);
            break;

        case 3:// ���� �ݳ�
            printf("�ݳ��� ������ ID�� �Է��ϼ���: ");
            scanf("%d", &id);
            returnBook(id, renter);
            break;
        case 4:// ���� �˻�
            printf("�˻� �ɼ��� �����ϼ���:\n");
            printf("1. �������� �˻�\n");
            printf("2. ���ǻ�� �˻�\n");
            printf("3. ���� ID�� �˻�\n");
            scanf("%d", &choice);
            printf("�˻�� �Է��ϼ���: ");
            scanf("%s", keyword);
            searchBook(choice, keyword);
            break;
        case 5:// ���� ����
            printf("������ ������ ID�� �Է��ϼ���: ");
            scanf("%d", &id);
            deleteBook(id);
            break;
        case 6:// ���� ���
            printBooks();
            break;
        case 0:// ���α׷� ����
            printf("���α׷��� �����Ͻðڽ��ϱ�? (Y/N)or(1/2): \n");
            char answer;
            scanf(" %c", &answer); // ������ �����Ͽ� ���� �Է� �ޱ�
            if (answer == 'Y' || answer == 'y' || answer == '1') {
                printf("���α׷��� �����մϴ�.\n");
                exit(0);
            }
            else if (answer == 'N' || answer == 'n' || answer == '2') {
                printf("�ٽ� �޴��� ���ư��ϴ�.\n");
            }
            else {
                printf("�߸��� �Է��Դϴ�. �ٽ� �������ּ���.\n");
            }
            break;
        default:
            printf("�޴��� �ִ� ���ڸ� ��������..\n");
            break;
        }
    }
    atexit(freeMemory); // ���α׷��� ����� �� �������� �Ҵ�� �޸� ����
    while (1) {// �޴��� �ݺ��Ͽ� ����ϰ� ������� ���ÿ� ���� ���� ����
        // ������ �ڵ��
    }

    return 0;
}
