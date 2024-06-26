/*
      File: Project.c

      Created: 24-03-06
      Author: �����
*/

#include <iostream>
#include <string>
#include <vector>
#include "header.h"

using namespace std;

// ���� �Լ�
int main() {
    vector<Product*> products;  // ��ǰ���� �����ϴ� ����

    int choice;
    while (true) {
        cout << "��ǰ���� ���α׷�" << endl;
        cout << "1. ��ǰ�߰� 2. ��ǰ��� 3. ��ǰ�˻� 0. ����" << endl;
        cout << "����: ";
        cin >> choice;

        switch (choice) {
        case 0:
            // ���� �Ҵ��� ��ü�� ����
            for (auto& product : products) {
                delete product;
            }
            return 0;
        case 1:
            addProduct(products);       // ��ǰ �߰� �Լ� ȣ��
            break;
        case 2:
            printProducts(products);    // ��ǰ ��� �Լ� ȣ��
            break;
        case 3:
            searchProduct(products);    // ��ǰ �˻� �Լ� ȣ��
            break;
        default:
            cout << "�߸��� �����Դϴ�. �ٽ� �������ּ���." << endl;
            break;
        }
    }

    return 0;
}