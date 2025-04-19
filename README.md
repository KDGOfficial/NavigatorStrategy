# NavigatorStrategy

## Описание проекта

Этот проект представляет собой реализацию паттерна проектирования "Стратегия" (Strategy) на языке C++. Программа моделирует работу навигатора, который может строить маршруты между двумя точками (A и B) с использованием различных стратегий: на автомобиле, на общественном транспорте или пешком.

Проект был создан в рамках изучения объектно-ориентированного программирования и паттернов проектирования. Код включает поддержку русского языка в консоли с использованием `setlocale`.

### Основные особенности:

- Использование паттерна "Стратегия" для динамической смены алгоритма построения маршрута.
- Поддержка трёх стратегий: `RoadStrategy` (по дорогам), `PublicTransportStrategy` (на общественном транспорте) и `WalkingStrategy` (пешком).
- Корректное отображение русского текста в консоли благодаря `setlocale`.

## Установка и запуск

1. Склонируйте репозиторий:

   ```bash
   git clone https://github.com/KDGOfficial/NavigatorStrategy.git
   ```
2. Перейдите в папку проекта:

   ```bash
   cd NavigatorStrategy
   ```
3. Скомпилируйте код с помощью компилятора C++ (например, g++):

   ```bash
   g++ navigator.cpp -o navigator
   ```
4. Запустите программу:

   ```bash
   ./navigator
   ```

## Пример вывода

После запуска программы вы увидите следующий результат:

```
Построение маршрута от Точка А до Точка Б по дорогам (на автомобиле).
Построение маршрута от Точка А до Точка Б на общественном транспорте.
Построение маршрута от Точка А до Точка Б пешком.
```

## Используемые технологии

- Язык программирования: C++
- Библиотеки: `<iostream>`, `<string>`, `<clocale>`
- Компилятор: Любой совместимый с C++ (например, g++)

## Автор

Проект разработал студент второго курса KDG в рамках учебного задания по ООП

## Лицензия
MIT License

Copyright (c) 2025 KDG

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

---

Если у вас есть идеи или пожелания по улучшению проекта, создавайте issues или присылайте pull requests!


