# Game Draw Bus
Консольная игра в который я хотел разобраться с ООП.
В ней реализованы все принципы: Абстракция, полиморфизм, инкапусляция, наследование

Абстракция - основным классом является автобус, который наделён базовым минмум. Методами отрисовки и перемещения

Полиморфизм - в игре представлены несколько видов автобусов, но у всех совпадает название методов. Отличие только в том, как метод реализуется. Например автобус с квардратными колёсами будет ехать медленее, чем автобус с круглыми.

Инкапсуляция - внутренее устройство классов и методов скрыто от пользователя и других разработчиков. Базовый класс обладает полями protected, чтобы классы наследники имели досутп к полям родительского класса.

Наследование - видоизменённые автобусы наследованы от базового, аналогично для объектов-припядствий.

Иерархию классов можно посмотреть в файлах ресурсов - ClassDiagram.cd