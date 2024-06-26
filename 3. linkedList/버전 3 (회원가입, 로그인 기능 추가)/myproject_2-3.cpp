/*
   File: myproject_2-3.c

   Created: 24-03-27
   Author: �����
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_LEN 100

// ȸ�� ���� ����ü ����
typedef struct {
    char id[MAX_LEN];       // ���̵�
    char password[MAX_LEN]; // ��й�ȣ
    char name[MAX_LEN];     // �̸�
} UserInfo;

// ȸ������ �Լ�
void register_user() {
    char id[MAX_LEN];               // �Է� ���� ���̵� ������ ����
    char password[MAX_LEN];         // �Է� ���� ��й�ȣ�� ������ ����
    char name[MAX_LEN];             // �Է� ���� �̸��� ������ ����
    char file_name[] = "user.txt";  // ����� ������ ����� ���� �̸�

    // ����ڷκ��� ���̵�, ��й�ȣ, �̸� �Է� �ޱ�
    printf("���̵� �Է��ϼ���: ");
    scanf("%s", id);
    printf("��й�ȣ�� �Է��ϼ���: ");
    scanf("%s", password);
    printf("�̸��� �Է��ϼ���: ");
    scanf("%s", name);

    // ���� ����
    FILE* file = fopen(file_name, "a"); // �߰� ���� ���� ����
    if (file == NULL) {
        printf("������ �� �� �����ϴ�.\n");
        return;
    }

    // �Էµ� ������ ���Ͽ� ����
    fprintf(file, "%s %s %s\n", id, password, name);

    fclose(file); // ���� �ݱ�
    printf("ȸ�������� �Ϸ�Ǿ����ϴ�.\n");
}

// �߰� �۾� �Լ�
void additional_task(const char* name) {
    printf("%s��, ȯ���մϴ�!\n", name);

    // ���� ����
    system("./myproject2-2");       // ��������� ���� (gcc -o myproject2-2 myproject2-2.c) �� ����Ͽ� �����Ŵ
}

// �α��� �Լ�
void login() {
    char id[MAX_LEN];               // �Է� ���� ���̵� ������ ����
    char password[MAX_LEN];         // �Է� ���� ��й�ȣ�� ������ ����
    char name[MAX_LEN];             // ������� �̸��� ������ ����
    char file_name[] = "user.txt";  // ����� ������ ����� ���� �̸�
    char correct_id[MAX_LEN];       // ���Ͽ��� ���� ��Ȯ�� ���̵�
    char correct_password[MAX_LEN]; // ���Ͽ��� ���� ��Ȯ�� ��й�ȣ

    // ����ڷκ��� ���̵�� ��й�ȣ �Է� �ޱ�
    printf("���̵� �Է��ϼ���: ");
    scanf("%s", id);
    printf("��й�ȣ�� �Է��ϼ���: ");
    scanf("%s", password);

    // ���� ����
    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        printf("������ �� �� �����ϴ�.\n");
        return;
    }

    // ���Ͽ��� ���̵�� ��й�ȣ �б�
    while (fscanf(file, "%s %s", correct_id, correct_password) != EOF) {
        // ���̵�� ��й�ȣ ��ġ ���� Ȯ��
        if (strcmp(id, correct_id) == 0 && strcmp(password, correct_password) == 0) {
            printf("�α��� ����!\n");
            fclose(file); // ���� �ݱ�
            additional_task(name);
            return;
        }
    }

    fclose(file); // ���� �ݱ�
    printf("�α��� ����!\n");
}

int main() {
    setlocale(LC_ALL, ""); // ���α׷��� ������ ����

    int choice; // ������� ������ ������ ����

    // ����ڰ� ���α׷��� ������ ������ �ݺ��Ͽ� �޴��� ǥ���ϰ� ������ �۾��� ����
    while (1) {
        // �޴� ���
        printf("***** �޴� *****\n");
        printf("1. �α���\n");
        printf("2. ȸ������\n");
        printf("3. ����\n");
        printf("�����ϼ���: ");
        scanf("%d", &choice);
        // ����� ���ÿ� ���� �۾� ����
        switch (choice) {
        case 1:
            login(); // �α��� �Լ� ȣ��
            break;
        case 2:
            register_user(); // ȸ������ �Լ� ȣ��
            break;
        case 3:
            printf("���α׷��� �����մϴ�.\n");
            return 0; // ���α׷� ����
        default:
            printf("�ùٸ� ������ �ƴմϴ�. �ٽ� �����ϼ���.\n");
        }
    }
}
