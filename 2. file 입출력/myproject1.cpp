/*
   File: myproject_1.c

   Created: 24-03-13
   Author: 명수진
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 64

// 해시 함수: 입력된 문자열을 해싱하여 정수값으로 반환
unsigned int hash(const char* str) {
    unsigned int hash = 5381; // 초기 해시값 설정
    int c;

    // 입력된 문자열의 각 문자에 대해 해시 생성
    while ((c = *str++)) // 문자열의 끝에 도달할 때까지 반복
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash; // 해싱된 값 반환
}

// 로그인 함수
void login() {
    char id[MAX_LEN];               // 입력 받은 아이디를 저장할 변수
    char password[MAX_LEN];         // 입력 받은 비밀번호를 저장할 변수
    char file_name[] = "myinfo.txt";  // 사용자 정보가 저장된 파일 이름
    char correct_id[MAX_LEN];       // 파일에서 읽은 정확한 아이디
    char correct_password[MAX_LEN]; // 파일에서 읽은 정확한 비밀번호 (해싱된 값)
    char file_content[MAX_LEN];     // 파일 내용을 저장할 변수

    // 사용자로부터 아이디와 비밀번호 입력 받기
    printf("아이디를 입력하세요: ");
    scanf("%s", id);
    printf("비밀번호를 입력하세요: ");
    scanf("%s", password);

    // 입력된 아이디가 "tnwls4388"이고 비밀번호가 "aud5024!"인지 확인
    if (strcmp(id, "tnwls4388") == 0 && strcmp(password, "aud5024!") == 0) {
        printf("로그인 성공! 파일 열기 시도 중...\n");

        // 파일 열기 시도
        FILE* file = fopen(file_name, "r");
        if (file == NULL) {
            printf("파일을 열 수 없습니다.\n");
            return;
        }
        else {
            printf("파일을 열었습니다!\n"); // 파일 열기 성공 시
            printf("파일 내용:\n"); // 파일 내용을 읽어서 출력
            while (fgets(file_content, MAX_LEN, file) != NULL) {
                printf("%s", file_content);
            }
        }

        fclose(file); // 파일 닫기
    }
    else {
        printf("아이디 또는 비밀번호가 잘못되었습니다.\n");
    }
}

int main() {
    login();
    return 0;
}
