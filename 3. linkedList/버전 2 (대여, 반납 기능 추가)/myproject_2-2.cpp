/*
   File: myproject_2-2.c

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
    char renter[MAX_LEN];      // ���� �뿩��
    struct Book* next;         // ���� ������ ����Ű�� ������
};

struct Book* head = NULL;      // ���� ����Ʈ�� ���� ����

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
