#include <iostream>
#include <string>
#include <clocale> // Для функции setlocale

using namespace std;

// Абстрактный интерфейс стратегии для построения маршрута
class RouteStrategy {
public:
    virtual string buildRoute(const string& A, const string& B) = 0; // Чисто виртуальный метод для построения маршрута
    virtual ~RouteStrategy() = default; // Виртуальный деструктор для корректного наследования
};

// Конкретная стратегия: Дороги (для автомобиля)
class RoadStrategy : public RouteStrategy {
public:
    string buildRoute(const string& A, const string& B) override {
        return "Построение маршрута от " + A + " до " + B + " по дорогам (на автомобиле).";
    }
};

// Конкретная стратегия: Общественный транспорт
class PublicTransportStrategy : public RouteStrategy {
public:
    string buildRoute(const string& A, const string& B) override {
        return "Построение маршрута от " + A + " до " + B + " на общественном транспорте.";
    }
};

// Конкретная стратегия: Пешком
class WalkingStrategy : public RouteStrategy {
public:
    string buildRoute(const string& A, const string& B) override {
        return "Построение маршрута от " + A + " до " + B + " пешком.";
    }
};

// Контекст: Навигатор, который использует выбранную стратегию
class Navigator {
private:
    RouteStrategy* routeStrategy; // Указатель на текущую стратегию

public:
    Navigator() : routeStrategy(nullptr) {} // Конструктор, инициализирует стратегию как nullptr

    // Метод для установки стратегии
    void setStrategy(RouteStrategy* strategy) {
        routeStrategy = strategy;
    }

    // Метод для построения маршрута с использованием текущей стратегии
    string buildRoute(const string& A, const string& B) {
        if (routeStrategy == nullptr) {
            return "Стратегия не установлена!";
        }
        return routeStrategy->buildRoute(A, B);
    }

    ~Navigator() {
        // Примечание: В реальном приложении нужно управлять временем жизни routeStrategy,
        // если Navigator владеет им. Здесь предполагается внешнее управление.
    }
};

// Клиентский код для демонстрации работы
int main() {
    setlocale(LC_ALL, "Russian"); // Устанавливаем локализацию на русский язык для корректного отображения текста

    Navigator navigator; // Создаём объект навигатора

    // Создаём объекты стратегий
    RoadStrategy roadStrategy;
    PublicTransportStrategy publicTransportStrategy;
    WalkingStrategy walkingStrategy;

    // Тестируем стратегию для дорог
    navigator.setStrategy(&roadStrategy);
    cout << navigator.buildRoute("Точка А", "Точка Б") << endl;

    // Тестируем стратегию для общественного транспорта
    navigator.setStrategy(&publicTransportStrategy);
    cout << navigator.buildRoute("Точка А", "Точка Б") << endl;

    // Тестируем стратегию для ходьбы пешком
    navigator.setStrategy(&walkingStrategy);
    cout << navigator.buildRoute("Точка А", "Точка Б") << endl;

    return 0;
}