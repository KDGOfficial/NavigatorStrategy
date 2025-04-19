#include <iostream>
#include <string>
#include <clocale> // ��� ������� setlocale

using namespace std;

// ����������� ��������� ��������� ��� ���������� ��������
class RouteStrategy {
public:
    virtual string buildRoute(const string& A, const string& B) = 0; // ����� ����������� ����� ��� ���������� ��������
    virtual ~RouteStrategy() = default; // ����������� ���������� ��� ����������� ������������
};

// ���������� ���������: ������ (��� ����������)
class RoadStrategy : public RouteStrategy {
public:
    string buildRoute(const string& A, const string& B) override {
        return "���������� �������� �� " + A + " �� " + B + " �� ������� (�� ����������).";
    }
};

// ���������� ���������: ������������ ���������
class PublicTransportStrategy : public RouteStrategy {
public:
    string buildRoute(const string& A, const string& B) override {
        return "���������� �������� �� " + A + " �� " + B + " �� ������������ ����������.";
    }
};

// ���������� ���������: ������
class WalkingStrategy : public RouteStrategy {
public:
    string buildRoute(const string& A, const string& B) override {
        return "���������� �������� �� " + A + " �� " + B + " ������.";
    }
};

// ��������: ���������, ������� ���������� ��������� ���������
class Navigator {
private:
    RouteStrategy* routeStrategy; // ��������� �� ������� ���������

public:
    Navigator() : routeStrategy(nullptr) {} // �����������, �������������� ��������� ��� nullptr

    // ����� ��� ��������� ���������
    void setStrategy(RouteStrategy* strategy) {
        routeStrategy = strategy;
    }

    // ����� ��� ���������� �������� � �������������� ������� ���������
    string buildRoute(const string& A, const string& B) {
        if (routeStrategy == nullptr) {
            return "��������� �� �����������!";
        }
        return routeStrategy->buildRoute(A, B);
    }

    ~Navigator() {
        // ����������: � �������� ���������� ����� ��������� �������� ����� routeStrategy,
        // ���� Navigator ������� ��. ����� �������������� ������� ����������.
    }
};

// ���������� ��� ��� ������������ ������
int main() {
    setlocale(LC_ALL, "Russian"); // ������������� ����������� �� ������� ���� ��� ����������� ����������� ������

    Navigator navigator; // ������ ������ ����������

    // ������ ������� ���������
    RoadStrategy roadStrategy;
    PublicTransportStrategy publicTransportStrategy;
    WalkingStrategy walkingStrategy;

    // ��������� ��������� ��� �����
    navigator.setStrategy(&roadStrategy);
    cout << navigator.buildRoute("����� �", "����� �") << endl;

    // ��������� ��������� ��� ������������� ����������
    navigator.setStrategy(&publicTransportStrategy);
    cout << navigator.buildRoute("����� �", "����� �") << endl;

    // ��������� ��������� ��� ������ ������
    navigator.setStrategy(&walkingStrategy);
    cout << navigator.buildRoute("����� �", "����� �") << endl;

    return 0;
}