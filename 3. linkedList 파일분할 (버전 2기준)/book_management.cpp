#include "book_management.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book* head = NULL;

// 1. ���� ��� �Լ�
void addBook(char* title, char* author, char* publisher, int id) {
    // ���ο� ���� ��带 �������� �Ҵ��Ͽ� ����
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    // ����, �۰�, ���ǻ�, ID�� �����ϰ�, ���� ��带 ������ head�� ����
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    strcpy(newBook->publisher, publisher);
    newBook->id = id;
    strcpy(newBook->renter, "None");  // �ʱ� �뿩�ڴ� None���� ����
    newBook->next = head;
    // head�� ���ο� ���� �����Ͽ� ���ο� ������ ù ��°�� �߰��ǵ��� ��
    head = newBook;
}

// 2. ���� �뿩 �Լ�
void rentBook(int id, char* renter) {
    struct Book* current = head;

    // ���� ����Ʈ�� ��ȸ�ϸ� �뿩�� ������ ã��
    while (current != NULL) {
        if (current->id == id) {
            if (strcmp(current->renter, "None") == 0) {
                strcpy(current->renter, renter); // �뿩�� ���� ������Ʈ
                printf("%s���� ���� '%s'(��)�� �뿩�Ͽ����ϴ�.\n", renter, current->title);
            }
            else {
                printf("�� ������ �̹� �뿩���Դϴ�.\n");
            }
            return;
        }
        current = current->next;
    }
    printf("�ش� ������ ã�� �� �����ϴ�.\n");
}

// 3. ���� �ݳ� �Լ�
void returnBook(int id, char* renter) {
    struct Book* current = head;
    // ���� ����Ʈ�� ��ȸ�ϸ� ������ �˻�
    while (current != NULL) {
        if (current->id == id) {
            if (strcmp(current->renter, "None") != 0) {
                strcpy(current->renter, "None"); // �뿩�� �̸� None���� ����
                printf("���� '%s'�� �ݳ��Ǿ����ϴ�.\n", current->title);
            }
            else {
                printf("�� ������ �̹� �ݳ��Ǿ����ϴ�.\n");
            }
            return;
        }
        current = current->next;
    }
    printf("�ش��ϴ� ������ ã�� �� �����ϴ�.\n");
}

// 4. ���� �˻� �Լ�
void searchBook(int option, char* keyword) {
    struct Book* current = head;
    int found = 0; // ������ �߰ߵǾ����� ���θ� ��Ÿ���� �÷���

    // ���� ����Ʈ�� ��ȸ�ϸ� ������ �˻�
    while (current != NULL) {
        // �ɼǿ� ���� �˻� ����
        if ((option == 1 && strcmp(current->title, keyword) == 0) || // �������� �˻�
            (option == 2 && strcmp(current->author, keyword) == 0) || // �۰� �̸����� �˻�
            (option == 3 && strcmp(current->publisher, keyword) == 0) || // ���ǻ�� �˻�
            (option == 4 && current->id == atoi(keyword)) || // ID�� �˻�
            (option == 5 && strcmp(current->renter, keyword) == 0)) { // �뿩�ڷ� �˻�
            printf("���� ����: %s, �۰�: %s, ���ǻ�: %s, ���� ID: %d, �뿩��: %s\n",
                current->title, current->author, current->publisher, current->id, current->renter);
            found = 1;

        }
        current = current->next;
    }

    if (!found)
        printf("�ش��ϴ� ������ ã�� �� �����ϴ�.\n");
}
// 5. ���� ���� �Լ�
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

// 6. ���� ��� ��� �Լ�
void printBooks() {
    struct Book* current = head;
    if (current == NULL) {
        printf("������ �����ϴ�.\n");
        return;
    }
    printf("���� ���:\n");
    while (current != NULL) {
        printf("���� ����: %s, �۰�: %s, ���ǻ�: %s, ���� ID: %d, �뿩��: %s\n",
            current->title, current->author, current->publisher, current->id, current->renter);
        current = current->next;
    }
}

// 7. �޸� ���� �Լ�: �������� head�� ��ȸ�ϸ鼭 �޸𸮸� ����
void freeMemory() {
    struct Book* current = head;
    while (current != NULL) {
        struct Book* temp = current;
        current = current->next;
        free(temp);
    }
}