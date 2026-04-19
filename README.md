# Лабораторные работы 11-12

Автор: Aleksey Logvinenko  
Email: amlogvinenko@edu.hse.ru

Проект содержит решения задач по темам:

- лабораторная 11: практическое применение контейнеров и итераторов STL;
- лабораторная 12: разработка и тестирование пользовательских итераторов.

## Структура

- `lab11/task1_prices.cpp` - сортировка цен по убыванию и удаление цен ниже среднего;
- `lab11/task2_inventory.cpp` - управление инвентарем через команды и `back_inserter`;
- `lab11/task3_journal_editor.cpp` - простой редактор журнала на `list<string>`;
- `lab11/task4_data_sync.cpp` - копирование данных между `vector` и `deque`;
- `lab11/task5_reverse_output.cpp` - вывод данных в обратном порядке через reverse iterators;
- `lab12/task1_reverse_history_iterator.cpp` - пользовательский обратный итератор истории;
- `lab12/task2_time_interval_iterator.cpp` - итератор событий в заданном временном интервале;
- `lab12/task3_filter_iterator.cpp` - фильтрующий итератор задач;
- `lab12/task4_transform_iterator.cpp` - трансформирующий итератор валют;
- `lab12/task5_multi_iterator.cpp` - мульти-итератор для двух источников данных.

## Сборка

```bash
cmake -S . -B build
cmake --build build
```

После сборки исполняемые файлы будут находиться в папке `build`.

## Быстрая проверка без CMake

```bash
g++ -std=c++17 lab11/task1_prices.cpp -o task1_prices
g++ -std=c++17 lab12/task5_multi_iterator.cpp -o task5_multi_iterator
```
