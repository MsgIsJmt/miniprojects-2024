#include <stdio.h>
#include <stdlib.h>
#include "book_management.h"

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
