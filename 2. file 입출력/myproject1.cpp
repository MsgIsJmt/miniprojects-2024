/*
   File: myproject_1.c

   Created: 24-03-13
   Author: �����
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 64

// �ؽ� �Լ�: �Էµ� ���ڿ��� �ؽ��Ͽ� ���������� ��ȯ
unsigned int hash(const char* str) {
    unsigned int hash = 5381; // �ʱ� �ؽð� ����
    int c;

    // �Էµ� ���ڿ��� �� ���ڿ� ���� �ؽ� ����
    while ((c = *str++)) // ���ڿ��� ���� ������ ������ �ݺ�
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash; // �ؽ̵� �� ��ȯ
}

// �α��� �Լ�
void login() {
    char id[MAX_LEN];               // �Է� ���� ���̵� ������ ����
    char password[MAX_LEN];         // �Է� ���� ��й�ȣ�� ������ ����
    char file_name[] = "myinfo.txt";  // ����� ������ ����� ���� �̸�
    char correct_id[MAX_LEN];       // ���Ͽ��� ���� ��Ȯ�� ���̵�
    char correct_password[MAX_LEN]; // ���Ͽ��� ���� ��Ȯ�� ��й�ȣ (�ؽ̵� ��)
    char file_content[MAX_LEN];     // ���� ������ ������ ����

    // ����ڷκ��� ���̵�� ��й�ȣ �Է� �ޱ�
    printf("���̵� �Է��ϼ���: ");
    scanf("%s", id);
    printf("��й�ȣ�� �Է��ϼ���: ");
    scanf("%s", password);

    // �Էµ� ���̵� "tnwls4388"�̰� ��й�ȣ�� "aud5024!"���� Ȯ��
    if (strcmp(id, "tnwls4388") == 0 && strcmp(password, "aud5024!") == 0) {
        printf("�α��� ����! ���� ���� �õ� ��...\n");

        // ���� ���� �õ�
        FILE* file = fopen(file_name, "r");
        if (file == NULL) {
            printf("������ �� �� �����ϴ�.\n");
            return;
        }
        else {
            printf("������ �������ϴ�!\n"); // ���� ���� ���� ��
            printf("���� ����:\n"); // ���� ������ �о ���
            while (fgets(file_content, MAX_LEN, file) != NULL) {
                printf("%s", file_content);
            }
        }

        fclose(file); // ���� �ݱ�
    }
    else {
        printf("���̵� �Ǵ� ��й�ȣ�� �߸��Ǿ����ϴ�.\n");
    }
}

int main() {
    login();
    return 0;
}
