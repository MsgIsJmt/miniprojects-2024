#ifndef BOOK_MANAGEMENT_H
#define BOOK_MANAGEMENT_H

#define MAX_LEN 100

struct Book {
    char title[MAX_LEN];       // 도서 제목
    char author[MAX_LEN];      // 작가 이름
    char publisher[MAX_LEN];   // 출판사
    int id;                    // 도서 ID
    char renter[MAX_LEN];      // 도서 대여자
    struct Book* next;         // 다음 도서를 가리키는 포인터
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
