# Лабораторная работа №2: UML Диаграммы взаимодействия

## Платежная система (Вариант №2)

## Диаграмма взаимодействия (Диаграмма последовательности)

```uml
@startuml PaymentSystem_SequenceDiagram

title Система платежей - Диаграмма последовательности

participant "Client" as Client
participant "BankAccount" as BankAccount
participant "CreditCard" as CreditCard
participant "Order" as Order
participant "Administrator" as Administrator

Client ->> BankAccount: "1: BankAccount(id, balance, currency)"
activate BankAccount
Client ->> CreditCard: "2: CreditCard(number, limit)"
activate CreditCard
Client ->> Order: "3: Order(id, amount, description)"
activate Order

Client ->> Order: "4: payOrder(amount)"
Order ->> BankAccount: "5: PayOrder(amount)"
activate BankAccount
BankAccount ->> Order: "6: return result"
deactivate BankAccount

Client ->> BankAccount: "7: transferTo(target, amount)"
activate BankAccount
BankAccount ->> BankAccount: "8: TransferTo(target, amount)"
BankAccount ->> Client: "9: return result"
deactivate BankAccount

Client ->> CreditCard: "10: blockCard()"
activate CreditCard
CreditCard ->> CreditCard: "11: BlockCard()"
CreditCard ->> Client: "12: return result"
deactivate CreditCard

Client ->> BankAccount: "13: closeAccount()"
activate BankAccount
BankAccount ->> BankAccount: "14: CloseAccount()"
BankAccount ->> Client: "15: return result"
deactivate BankAccount

Administrator ->> CreditCard: "16: BlockCardForOverlimit(card)"
activate CreditCard
CreditCard ->> CreditCard: "17: BlockCard()"
CreditCard ->> Administrator: "18: return result"
deactivate CreditCard

deactivate Client
deactivate Order
deactivate Administrator

@enduml
```

## Онлайн версия диаграммы

Диаграмму можно посмотреть онлайн по ссылке: [PlantUML Online](https://www.planttext.com?text=dLLBRjim4DqRy1q6Nhc00rHfyoaNGH87sQP0iWzeQXeGaIY7eW9ursJTPI_G6nZvmK4-lG9reuu-JabLSHClP766Cu-FRsRaxTHmRR8uWgzy4gCoXvFKO7nyY6SPAe5xafze7dSxtOwH9aAml-milyWlxQrzj5Eml-s3dPRc7Jtti0BsfvtPgRtElzFluppgER-Wo5jxOv_jLPtnaF-mJyKEMRFYY35naKAEkJBG6qQI-FI0fr0j6_kxN9tk295aTP1ZDv4qXj8CkGuhj1Up4NUWGzHbIBbgxEw4iLGoDPgRf8hoF0N_YYUiR6svR1Zq0kOw-Z8Sm8X7d0GUWCYq9gad7thT3XT6ddE3_cKSsB_S2NMLENPVPV48zG0Y6KlZWRaNTh3AInBC9rOjIreyBiuSG8Yfq79iPA8yh5gPLg3F3CPyKc5LE4LgQRTeiiQAdcj6jolW6Dw9wmmqcamhUgLPP0WWn7Q81TNPO40rLEatr4T9dmRY1CrSYRTpyZ4t6HmjmcncL-GeySkIL_8w8_Z8O1GbuhJiZDURuMNT0b7qh0VHZ9up3bONKdOFN3GYr8OYIbAS3ycooWVKXiCcqAjo1sllqTkR-1RDrXtDzXDzS8ww7CU-8CToPTZuJnayIaN2vZkguMxKtrZ7LS-wu_ddYxUDAgH_Zpy0)

## Описание системы

Система реализует платежную функциональность согласно варианту №2:

- **Клиент** имеет банковский счет и кредитную карту
- **Клиент** может оплатить Заказ, сделать платеж на другой Счет, заблокировать КК и аннулировать Счет
- **Администратор** может заблокировать КК за превышение кредита

## Контрольные вопросы и ответы

### 1. Для чего предназначена диаграмма взаимодействия?

Диаграмма взаимодействия предназначена для описания динамики системы, показывая взаимодействие между различными объектами в определенной последовательности. Она отображает:
- Порядок вызовов методов между объектами
- Временные зависимости между сообщениями
- Поток выполнения операций в системе
- Взаимодействие компонентов системы во времени

### 2. Объясните последовательность построения диаграммы взаимодействия объектов программной системы.

Построение диаграммы взаимодействия включает следующие шаги:
1. Определение участников взаимодействия (объектов, акторов)
2. Определение начальной точки взаимодействия
3. Определение последовательности вызовов между участниками
4. Указание типов сообщений (синхронные, асинхронные, возвратные)
5. Добавление условий и альтернативных путей при необходимости
6. Указание активации и деактивации объектов во время взаимодействия
7. Добавление заметок и пояснений для лучшего понимания

### 3. На примере построенной диаграммы последовательностей, расскажите порядок объектов программы.

На диаграмме последовательности объекты представлены в следующем порядке:
1. Клиент - инициирует взаимодействие и координирует действия
2. Банковский счет - хранит и обрабатывает денежные средства
3. Кредитная карта - используется для оплаты и может быть заблокирована
4. Заказ - объект, который оплачивается и содержит информацию о покупке
5. Администратор - контролирует систему и может блокировать карты при нарушениях

Порядок взаимодействия начинается с клиента, который создает необходимые объекты, затем взаимодействует с ними для выполнения различных операций, таких как оплата, перевод, блокировка. Администратор взаимодействует с кредитной картой для контроля лимитов.
