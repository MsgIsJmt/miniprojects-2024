/*
   File: myproject_2-3.c

   Created: 24-03-27
   Author: 명수진
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_LEN 100

// 회원 정보 구조체 정의
typedef struct {
    char id[MAX_LEN];       // 아이디
    char password[MAX_LEN]; // 비밀번호
    char name[MAX_LEN];     // 이름
} UserInfo;

// 회원가입 함수
void register_user() {
    char id[MAX_LEN];               // 입력 받은 아이디를 저장할 변수
    char password[MAX_LEN];         // 입력 받은 비밀번호를 저장할 변수
    char name[MAX_LEN];             // 입력 받은 이름을 저장할 변수
    char file_name[] = "user.txt";  // 사용자 정보가 저장될 파일 이름

    // 사용자로부터 아이디, 비밀번호, 이름 입력 받기
    printf("아이디를 입력하세요: ");
    scanf("%s", id);
    printf("비밀번호를 입력하세요: ");
    scanf("%s", password);
    printf("이름을 입력하세요: ");
    scanf("%s", name);

    // 파일 열기
    FILE* file = fopen(file_name, "a"); // 추가 모드로 파일 열기
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return;
    }

    // 입력된 정보를 파일에 저장
    fprintf(file, "%s %s %s\n", id, password, name);

    fclose(file); // 파일 닫기
    printf("회원가입이 완료되었습니다.\n");
}

// 추가 작업 함수
void additional_task(const char* name) {
    printf("%s님, 환영합니다!\n", name);

    // 파일 실행
    system("./myproject2-2");       // 라즈베리파이 기준 (gcc -o myproject2-2 myproject2-2.c) 를 사용하여 실행시킴
}

// 로그인 함수
void login() {
    char id[MAX_LEN];               // 입력 받은 아이디를 저장할 변수
    char password[MAX_LEN];         // 입력 받은 비밀번호를 저장할 변수
    char name[MAX_LEN];             // 사용자의 이름을 저장할 변수
    char file_name[] = "user.txt";  // 사용자 정보가 저장된 파일 이름
    char correct_id[MAX_LEN];       // 파일에서 읽은 정확한 아이디
    char correct_password[MAX_LEN]; // 파일에서 읽은 정확한 비밀번호

    // 사용자로부터 아이디와 비밀번호 입력 받기
    printf("아이디를 입력하세요: ");
    scanf("%s", id);
    printf("비밀번호를 입력하세요: ");
    scanf("%s", password);

    // 파일 열기
    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return;
    }

    // 파일에서 아이디와 비밀번호 읽기
    while (fscanf(file, "%s %s", correct_id, correct_password) != EOF) {
        // 아이디와 비밀번호 일치 여부 확인
        if (strcmp(id, correct_id) == 0 && strcmp(password, correct_password) == 0) {
            printf("로그인 성공!\n");
            fclose(file); // 파일 닫기
            additional_task(name);
            return;
        }
    }

    fclose(file); // 파일 닫기
    printf("로그인 실패!\n");
}

int main() {
    setlocale(LC_ALL, ""); // 프로그램의 로케일 설정

    int choice; // 사용자의 선택을 저장할 변수

    // 사용자가 프로그램을 종료할 때까지 반복하여 메뉴를 표시하고 선택한 작업을 수행
    while (1) {
        // 메뉴 출력
        printf("***** 메뉴 *****\n");
        printf("1. 로그인\n");
        printf("2. 회원가입\n");
        printf("3. 종료\n");
        printf("선택하세요: ");
        scanf("%d", &choice);
        // 사용자 선택에 따라 작업 수행
        switch (choice) {
        case 1:
            login(); // 로그인 함수 호출
            break;
        case 2:
            register_user(); // 회원가입 함수 호출
            break;
        case 3:
            printf("프로그램을 종료합니다.\n");
            return 0; // 프로그램 종료
        default:
            printf("올바른 선택이 아닙니다. 다시 선택하세요.\n");
        }
    }
}
