#include <iostream>
#include <string>
#include <vector>
#include "header.h"

using namespace std;
// ��ǰ �߰� �Լ� ����


Product::Product(int _id, double _price, string _producer) : id(_id), price(_price), producer(_producer) {}

void Product::printInfo() const {
    cout << "ID: " << id << ", Price: " << price << ", Producer: " << producer << endl;
}

int Product::getID() const {
    return id;
}

Product::~Product() {}

Book::Book(int _id, double _price, string _producer, string _ISBN, string _author, string _title)
    : Product(_id, _price, _producer), ISBN(_ISBN), author(_author), title(_title) {}

void Book::printInfo() const {
    Product::printInfo();
    cout << "ISBN: " << ISBN << ", Author: " << author << ", Title: " << title << endl;
}

Handphone::Handphone(int _id, double _price, string _producer, string _model, int _ram)
    : Product(_id, _price, _producer), model(_model), ram(_ram) {}

void Handphone::printInfo() const {
    Product::printInfo();
    cout << "Model: " << model << ", RAM: " << ram << "GB" << endl;
}

Computer::Computer(int _id, double _price, string _producer, string _model, string _cpu, int _ram)
    : Product(_id, _price, _producer), model(_model), cpu(_cpu), ram(_ram) {}

void Computer::printInfo() const {
    Product::printInfo();
    cout << "Model: " << model << ", CPU: " << cpu << "GB" << ", RAM: " << ram << "GB" << endl;
}

void addProduct(vector<Product*>& products) {
    int productType;
    cout << "1. å 2. �ڵ��� 3. ��ǻ��" << endl;
    cout << "��ǰ ���� ����: ";
    cin >> productType;

    int id;
    double price;
    string producer;
    cout << "ID: ";
    cin >> id;
    cout << "Price: ";
    cin >> price;
    cout << "Producer: ";
    cin >> producer;

    if (productType == 1) {
        string ISBN, author, title;
        cout << "ISBN: ";
        cin >> ISBN;
        cout << "Author: ";
        cin >> author;
        cout << "Title: ";
        cin >> title;
        products.push_back(new Book(id, price, producer, ISBN, author, title)); // å ��ü �߰�
    }
    else if (productType == 2) {
        string model;
        int ram;
        cout << "Model: ";
        cin >> model;
        cout << "RAM: ";
        cin >> ram;
        products.push_back(new Handphone(id, price, producer, model, ram));
    }
    else if (productType == 3) {
        string model, cpu;
        int ram;
        cout << "Model: ";
        cin >> model;
        cout << "CPU: ";
        cin >> cpu;
        cout << "RAM: ";
        cin >> ram;
        products.push_back(new Computer(id, price, producer, model, cpu, ram));
    }
}

void printProducts(const vector<Product*>& products) {
    cout << "��ǰ ���" << endl;
    for (const auto& product : products) {
        product->printInfo();
    }
}

void searchProduct(const vector<Product*>& products) {
    cout << "��ǰ �˻�" << endl;
    int searchId;
    cout << "�˻��� ��ǰ�� ID�� �Է��ϼ���: ";
    cin >> searchId;


    bool found = false;
    for (const auto& product : products) {
        if (product->getID() == searchId) {
            product->printInfo();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "�ش� ID�� ��ǰ�� ã�� �� �����ϴ�." << endl;
    }
}