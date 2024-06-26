#ifndef BOOK_MANAGEMENT_H
#define BOOK_MANAGEMENT_H

#define MAX_LEN 100

struct Book {
    char title[MAX_LEN];       // ���� ����
    char author[MAX_LEN];      // �۰� �̸�
    char publisher[MAX_LEN];   // ���ǻ�
    int id;                    // ���� ID
    char renter[MAX_LEN];      // ���� �뿩��
    struct Book* next;         // ���� ������ ����Ű�� ������
};

extern struct Book* head;

void addBook(char* title, char* author, char* publisher, int id);
void rentBook(int id, char* renter);
void returnBook(int id, char* renter);
void searchBook(int option, char* keyword);
void deleteBook(int id);
void printBooks();
void freeMemory();

#endif /* BOOK_MANAGEMENT_H */
