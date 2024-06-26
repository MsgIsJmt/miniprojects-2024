/*
   File: myproject_2-2.c

   Created: 24-03-27
   Author: 명수진
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

// 도서 정보를 저장하는 구조체
struct Book {
    char title[MAX_LEN];       // 도서 제목
    char author[MAX_LEN];      // 작가 이름
    char publisher[MAX_LEN];   // 출판사
    int id;                    // 도서 ID
    char renter[MAX_LEN];      // 도서 대여자
    struct Book* next;         // 다음 도서를 가리키는 포인터
};

struct Book* head = NULL;      // 연결 리스트의 시작 지점

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

// 메뉴 출력 함수
void printMenu() {
    printf("**** 메뉴 ****\n");
    printf("1. 도서 등록\n");
    printf("2. 도서 대여\n");
    printf("3. 도서 반납\n");
    printf("4. 도서 검색\n");
    printf("5. 도서 삭제\n");
    printf("6. 도서 출력\n");
    printf("0. 종료\n");
}

int main() {
    //    int choice, id;
    int id;
    char input[MAX_LEN];
    char title[MAX_LEN], author[MAX_LEN], publisher[MAX_LEN], renter[MAX_LEN], keyword[MAX_LEN];

    // 메뉴를 반복하여 출력하고 사용자의 선택에 따라 동작 수행
    while (1) {
        int choice = -1;
        printMenu(); // 메뉴 출력
        printf("메뉴를 선택하세요: ");
        scanf(" %d", &choice);
        getchar(); // 입력 버퍼 비우기

        // 숫자가 아닌 경우 처리
        if (choice < 0 || choice > 6) { // 메뉴 선택 범위 확인
            printf("잘못된 입력입니다. 0부터 6까지의 숫자를 입력하세요.\n");
            continue; // 다시 메뉴로 이동
        }


        switch (choice) {
        case 1:// 도서 등록
            printf("도서 제목을 입력하세요: ");
            scanf("%s", title);
            printf("작가를 입력하세요: ");
            scanf("%s", author);
            printf("출판사를 입력하세요: ");
            scanf("%s", publisher);
            printf("도서 ID를 입력하세요: ");
            scanf("%d", &id);
            addBook(title, author, publisher, id);
            printf("도서 등록이 완료되었습니다.\n");
            printf("\n");
            break;

        case 2:// 도서 대여
            printf("대여할 도서의 ID를 입력하세요: ");
            scanf("%d", &id);
            printf("대여자 이름을 입력하세요: ");
            scanf("%s", renter);
            rentBook(id, renter);
            break;

        case 3:// 도서 반납
            printf("반납할 도서의 ID를 입력하세요: ");
            scanf("%d", &id);
            returnBook(id, renter);
            break;
        case 4:// 도서 검색
            printf("검색 옵션을 선택하세요:\n");
            printf("1. 제목으로 검색\n");
            printf("2. 출판사로 검색\n");
            printf("3. 도서 ID로 검색\n");
            scanf("%d", &choice);
            printf("검색어를 입력하세요: ");
            scanf("%s", keyword);
            searchBook(choice, keyword);
            break;
        case 5:// 도서 삭제
            printf("삭제할 도서의 ID를 입력하세요: ");
            scanf("%d", &id);
            deleteBook(id);
            break;
        case 6:// 도서 출력
            printBooks();
            break;
        case 0:// 프로그램 종료
            printf("프로그램을 종료하시겠습니까? (Y/N)or(1/2): \n");
            char answer;
            scanf(" %c", &answer); // 공백을 포함하여 문자 입력 받기
            if (answer == 'Y' || answer == 'y' || answer == '1') {
                printf("프로그램을 종료합니다.\n");
                exit(0);
            }
            else if (answer == 'N' || answer == 'n' || answer == '2') {
                printf("다시 메뉴로 돌아갑니다.\n");
            }
            else {
                printf("잘못된 입력입니다. 다시 선택해주세요.\n");
            }
            break;
        default:
            printf("메뉴에 있는 숫자만 누르세요..\n");
            break;
        }
    }
    atexit(freeMemory); // 프로그램이 종료될 때 동적으로 할당된 메모리 해제
    while (1) {// 메뉴를 반복하여 출력하고 사용자의 선택에 따라 동작 수행
        // 이전의 코드들
    }

    return 0;
}
