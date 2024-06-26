#include "book_management.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book* head = NULL;

// 1. 도서 등록 함수
void addBook(char* title, char* author, char* publisher, int id) {
    // 새로운 도서 노드를 동적으로 할당하여 생성
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    // 제목, 작가, 출판사, ID를 설정하고, 다음 노드를 현재의 head로 설정
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    strcpy(newBook->publisher, publisher);
    newBook->id = id;
    strcpy(newBook->renter, "None");  // 초기 대여자는 None으로 설정
    newBook->next = head;
    // head를 새로운 노드로 갱신하여 새로운 도서가 첫 번째에 추가되도록 함
    head = newBook;
}

// 2. 도서 대여 함수
void rentBook(int id, char* renter) {
    struct Book* current = head;

    // 연결 리스트를 순회하며 대여할 도서를 찾음
    while (current != NULL) {
        if (current->id == id) {
            if (strcmp(current->renter, "None") == 0) {
                strcpy(current->renter, renter); // 대여자 정보 업데이트
                printf("%s님이 도서 '%s'(을)를 대여하였습니다.\n", renter, current->title);
            }
            else {
                printf("이 도서는 이미 대여중입니다.\n");
            }
            return;
        }
        current = current->next;
    }
    printf("해당 도서를 찾을 수 없습니다.\n");
}

// 3. 도서 반납 함수
void returnBook(int id, char* renter) {
    struct Book* current = head;
    // 연결 리스트를 순회하며 도서를 검색
    while (current != NULL) {
        if (current->id == id) {
            if (strcmp(current->renter, "None") != 0) {
                strcpy(current->renter, "None"); // 대여자 이름 None으로 변경
                printf("도서 '%s'가 반납되었습니다.\n", current->title);
            }
            else {
                printf("이 도서는 이미 반납되었습니다.\n");
            }
            return;
        }
        current = current->next;
    }
    printf("해당하는 도서를 찾을 수 없습니다.\n");
}

// 4. 도서 검색 함수
void searchBook(int option, char* keyword) {
    struct Book* current = head;
    int found = 0; // 도서가 발견되었는지 여부를 나타내는 플래그

    // 연결 리스트를 순회하며 도서를 검색
    while (current != NULL) {
        // 옵션에 따라 검색 수행
        if ((option == 1 && strcmp(current->title, keyword) == 0) || // 제목으로 검색
            (option == 2 && strcmp(current->author, keyword) == 0) || // 작가 이름으로 검색
            (option == 3 && strcmp(current->publisher, keyword) == 0) || // 출판사로 검색
            (option == 4 && current->id == atoi(keyword)) || // ID로 검색
            (option == 5 && strcmp(current->renter, keyword) == 0)) { // 대여자로 검색
            printf("도서 제목: %s, 작가: %s, 출판사: %s, 도서 ID: %d, 대여자: %s\n",
                current->title, current->author, current->publisher, current->id, current->renter);
            found = 1;

        }
        current = current->next;
    }

    if (!found)
        printf("해당하는 도서를 찾을 수 없습니다.\n");
}
// 5. 도서 삭제 함수
void deleteBook(int id) {
    struct Book* current = head;
    struct Book* prev = NULL;

    // 연결 리스트를 순회하며 삭제할 도서를 찾음
    while (current != NULL) {
        if (current->id == id) {
            if (prev == NULL) {
                // 삭제할 노드가 첫 번째 노드인 경우 head를 다음 노드로 갱신
                head = current->next;
            }
            else {
                // 이전 노드의 next를 삭제할 노드의 next로 연결하여 노드 삭제
                prev->next = current->next;
            }
            free(current);  // 메모리 해제
            printf("도서 삭제 완료.\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("해당 도서를 찾을 수 없습니다.\n");
}

// 6. 도서 목록 출력 함수
void printBooks() {
    struct Book* current = head;
    if (current == NULL) {
        printf("도서가 없습니다.\n");
        return;
    }
    printf("도서 목록:\n");
    while (current != NULL) {
        printf("도서 제목: %s, 작가: %s, 출판사: %s, 도서 ID: %d, 대여자: %s\n",
            current->title, current->author, current->publisher, current->id, current->renter);
        current = current->next;
    }
}

// 7. 메모리 해제 함수: 전역변수 head를 순회하면서 메모리를 해제
void freeMemory() {
    struct Book* current = head;
    while (current != NULL) {
        struct Book* temp = current;
        current = current->next;
        free(temp);
    }
}