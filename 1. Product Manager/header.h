#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ��ǰ�� �⺻ Ŭ���� ����
class Product {
protected:
    int id;
    double price;
    string producer;
public:
    // ������
    Product(int _id, double _price, string _producer);

    // ���� �Լ��� ���� �������� �����Ͽ� �Ļ� Ŭ�������� ������ ������ ��� �Լ�
    virtual void printInfo() const;

    // ID ��ȯ �Լ�
    int getID() const;

    // ���� �Ҹ���
    virtual ~Product(); // ���� �Ҹ��� �߰�
};

// å Ŭ���� ���� - ��ǰ Ŭ������ ��ӹ���
class Book : public Product {
private:
    string ISBN;
    string author;
    string title;
public:
    // ������
    Book(int _id, double _price, string _producer, string _ISBN, string _author, string _title);


    // �����ǵ� ��� �Լ�
    void printInfo() const override;
};

// �ڵ��� Ŭ���� ���� - ��ǰ Ŭ������ ��ӹ���
class Handphone : public Product {
private:
    string model;
    int ram;
public:
    // ������
    Handphone(int _id, double _price, string _producer, string _model, int _ram);

    // �����ǵ� ��� �Լ�
    void printInfo() const override;
};

class Computer : public Product {
private:
    string model;
    string cpu;
    int ram;
public:

    // ������
    Computer(int _id, double _price, string _producer, string _model, string _cpu, int _ram);

    // �����ǵ� ��� �Լ�
    void printInfo() const override;
};


void addProduct(vector<Product*>& products);
void printProducts(const vector<Product*>& products);
void searchProduct(const vector<Product*>& products);