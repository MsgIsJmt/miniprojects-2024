/*
   File: myproject_2-1.c

   Created: 24-03-27
   Author: �����
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

// ���� ������ �����ϴ� ����ü
struct Book {
    char title[MAX_LEN];       // ���� ����
    char author[MAX_LEN];      // �۰� �̸�
    char publisher[MAX_LEN];   // ���ǻ�
    int id;                    // ���� ID
    struct Book* next;         // ���� ������ ����Ű�� ������
};

struct Book* head = NULL;      // ���� ����Ʈ�� ���� ����

// ���� ��� �Լ�
void addBook(char* title, char* author, char* publisher, int id) {
    // ���ο� ���� ��带 �������� �Ҵ��Ͽ� ����
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    // ����, �۰�, ���ǻ�, ID�� �����ϰ�, ���� ��带 ������ head�� ����
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    strcpy(newBook->publisher, publisher);
    newBook->id = id;
    newBook->next = head;
    // head�� ���ο� ���� �����Ͽ� ���ο� ������ ù ��°�� �߰��ǵ��� ��
    head = newBook;
}

// ���� �˻� �Լ�
void searchBook(int option, char* keyword) {
    struct Book* current = head;
    int found = 0; // ������ �߰ߵǾ����� ���θ� ��Ÿ���� �÷���

    // ���� ����Ʈ�� ��ȸ�ϸ� ������ �˻�
    while (current != NULL) {
        // �ɼǿ� ���� �˻� ����
        if ((option == 1 && strcmp(current->title, keyword) == 0) || // �������� �˻�
            (option == 2 && strcmp(current->author, keyword) == 0) || // �۰� �̸����� �˻�
            (option == 3 && strcmp(current->publisher, keyword) == 0) || // ���ǻ�� �˻�
            (option == 4 && current->id == atoi(keyword))) { // ID�� �˻�
            printf("���� ����: %s, �۰�: %s, ���ǻ�: %s, ���� ID: %d\n",
                current->title, current->author, current->publisher, current->id);
            found = 1;
        }
        current = current->next;
    }

    if (!found)
        printf("�ش��ϴ� ������ ã�� �� �����ϴ�.\n");
}

// ���� ���� �Լ�
void deleteBook(int id) {
    struct Book* current = head;
    struct Book* prev = NULL;

    // ���� ����Ʈ�� ��ȸ�ϸ� ������ ������ ã��
    while (current != NULL) {
        if (current->id == id) {
            if (prev == NULL) {
                // ������ ��尡 ù ��° ����� ��� head�� ���� ���� ����
                head = current->next;
            }
            else {
                // ���� ����� next�� ������ ����� next�� �����Ͽ� ��� ����
                prev->next = current->next;
            }
            free(current);  // �޸� ����
            printf("���� ���� �Ϸ�.\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("�ش� ������ ã�� �� �����ϴ�.\n");
}

// ���� ��� ��� �Լ�
void printBooks() {
    struct Book* current = head;
    if (current == NULL) {
        printf("������ �����ϴ�.\n");
        return;
    }
    printf("���� ���:\n");
    while (current != NULL) {
        printf("���� ����: %s, �۰�: %s, ���ǻ�: %s, ���� ID: %d\n",
            current->title, current->author, current->publisher, current->id);
        current = current->next;
    }
}

// �޴� ��� �Լ�
void printMenu() {
    printf("**** �޴� ****\n");
    printf("1. ���� ���\n");
    printf("2. ���� �˻�\n");
    printf("3. ���� ����\n");
    printf("4. ���� ��� ���\n");
    printf("0. ����\n");
}

int main() {
    int id;
    char title[MAX_LEN], author[MAX_LEN], publisher[MAX_LEN], keyword[MAX_LEN];

    // �޴��� �ݺ��Ͽ� ����ϰ� ������� ���ÿ� ���� ���� ����
    while (1) {
        int choice = -1;
        printMenu(); // �޴� ���
        printf("�޴��� �����ϼ���: ");
        scanf(" %d", &choice);
        getchar(); // �Է� ���� ����

        // ���ڰ� �ƴ� ��� ó��
        if (choice < 0 || choice > 4) { // �޴� ���� ���� Ȯ��
            printf("�߸��� �Է��Դϴ�. 0���� 4������ ���ڸ� �Է��ϼ���.\n");
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

        case 2:// ���� �˻�
            printf("�˻� �ɼ��� �����ϼ���:\n");
            printf("1. �������� �˻�\n");
            printf("2. �۰��� �˻�\n");
            printf("3. ���ǻ�� �˻�\n");
            printf("4. ���� ID�� �˻�\n");
            scanf("%d", &choice);
            printf("�˻�� �Է��ϼ���: ");
            scanf("%s", keyword);
            searchBook(choice, keyword);
            break;

        case 3:// ���� ����
            printf("������ ������ ID�� �Է��ϼ���: ");
            scanf("%d", &id);
            deleteBook(id);
            break;

        case 4:// ���� ��� ���
            printBooks();
            break;

        case 0:// ����
            printf("���α׷��� �����մϴ�.\n");
            exit(0);
            break;

        default:
            printf("�߸��� �޴� �����Դϴ�. �ٽ� �������ּ���.\n");
            break;
        }
    }

    return 0;
}

