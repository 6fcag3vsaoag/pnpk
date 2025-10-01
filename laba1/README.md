# Лабораторная работа №1: UML Диаграммы классов
## Платежная система (Вариант №2)

## UML Диаграмма классов

```uml
@startuml PaymentSystem_ClassDiagram

' Interfaces positioned above their implementing classes with methods
interface IClient {
    +getClientId(): int
    +getName(): string
    +getPhoneNumber(): string
    +payOrder(amount: double): bool
    +transferTo(target: BankAccount, amount: double): bool
    +closeAccount(): void
    +blockCard(): void
}

interface IBankAccount {
    +getAccountId(): int
    +getBalance(): double
    +getCurrency(): string
    +PayOrder(amount: double): bool
    +TransferTo(target: BankAccount, amount: double): bool
    +CloseAccount(): void
}

interface ICreditCard {
    +getCardNumber(): string
    +getCreditLimit(): double
    +getCurrentDebt(): double
    +isCardBlocked(): bool
    +BlockCard(): void
    +AddDebt(amount: double): void
}

interface IAdministrator {
    +getAdminId(): int
    +getName(): string
    +BlockCardForOverlimit(card: CreditCard): void
}

interface IOrder {
    +getOrderId(): int
    +getAmount(): double
    +getDescription(): string
}

class Client
class BankAccount
class CreditCard
class Administrator
class Order

' Interface implementations with dashed arrows
IClient <|.. Client
IBankAccount <|.. BankAccount
ICreditCard <|.. CreditCard
IAdministrator <|.. Administrator
IOrder <|.. Order

' Main classes with attributes and methods
class Client {
    -clientId: int
    -name: string
    -phoneNumber: string
    -account: BankAccount
    -card: CreditCard

    +Client(id: int, name: string, phone: string)
    +getClientId(): int
    +getName(): string
    +getPhoneNumber(): string
    +setBankAccount(account: BankAccount): void
    +setCreditCard(card: CreditCard): void
    +getBankAccount(): BankAccount
    +getCreditCard(): CreditCard
    +payOrder(amount: double): bool
    +transferTo(target: BankAccount, amount: double): bool
    +closeAccount(): void
    +blockCard(): void
}

class BankAccount {
    -accountId: int
    -balance: double
    -currency: string

    +BankAccount(id: int, balance: double, currency: string)
    +getAccountId(): int
    +getBalance(): double
    +getCurrency(): string
    +PayOrder(amount: double): bool
    +TransferTo(target: BankAccount, amount: double): bool
    +CloseAccount(): void
}

class CreditCard {
    -cardNumber: string
    -creditLimit: double
    -currentDebt: double
    -isBlocked: bool

    +CreditCard(number: string, limit: double)
    +getCardNumber(): string
    +getCreditLimit(): double
    +getCurrentDebt(): double
    +isCardBlocked(): bool
    +BlockCard(): void
    +AddDebt(amount: double): void
}

class Administrator {
    -adminId: int
    -name: string

    +Administrator(id: int, name: string)
    +getAdminId(): int
    +getName(): string
    +BlockCardForOverlimit(card: CreditCard): void
}

class Order {
    -orderId: int
    -amount: double
    -description: string

    +Order(id: int, amount: double, description: string)
    +getOrderId(): int
    +getAmount(): double
    +getDescription(): string
}

' All relationships with arrows and numeric notations only
Client "1" --> "1" BankAccount
Client "1" --> "1" CreditCard
Administrator "1" --> "*" CreditCard
Client "1" --> "*" Order

' Layout and styling
title Payment System - Class Diagram (Variant #2)

@enduml
```

## Онлайн версия диаграммы

Диаграмму можно посмотреть онлайн по ссылке: [PlantUML Online](https://www.planttext.com?text=tLTRQzim57uFv3ySkeScMrpO7iCOJL86XQujhFHro9RQYCfIaEGMi-s_JnVBaXod5BR2jhuKdoETotSkNtIgD9AwgHbSexOcN7zjbIRrjmr3IfrHT2zHFPrC9yTmpZMHTwWY2dP2KKq59nXGAHu9w2sX4cYzOyJQeFmUAcl0d7sYUWirqLk1rNH2Wn4utp1gZiBtwGJCtxjxehta7C_cIp07e-8IrSGAbPR6T9HVRqqCbqrT4hcdtg7sIcAZGBLek5u25at9Y3bM2i6wGreYhkw8l14p0uEnk8GruW-hgh9t5l3StOe9HRgJrlkZeBXJbKnK3niaSPJ_j20csITkKWWwqGW6QyGGhnmCFfe4jqPAmgjs3uFhbs1myniOR4On6EQwaGHJRV78gcs-3zJEQjsT2rfJVJXbVKRAVJLLrlJQre0u79E0r_kLSV8LnixMNhBZ6QrmJJarCICjP5O_gtXf1_V1V1Rowf58vhAjZ6094RE3GRZIfiwTOCJvgWxr6S9uHbGbwSxESXgTy-G66FnCXg-aCVe3VQ11ae4JX2wsmIA92mFP2BfTWP7QsiKYfNWo6oFiYOy_JaxwQBBnSPeiihJZ_Bqao47nd7uGSWUjKoM1Vq6KvtiDQODOsMZpZJYEQox5BbIegBhrbbIduAOlygueTd6f3JJ8vxVCa_Ms1qtZnVsKMiSpwZql87Mw0ESlVCvVQHihky3we6TZcUG3gS8ASCDwS2RYTep6voC0nPKIXd-8rLz967jJrpSJ2aIHTbFfEIAVywBgw24lITX12N1zWmpiB61e8ccJ_uUnXlii3cxFL8E1h299ZMBk-6cWeQfZfZIi45piK9xvMm1BdQHJ-g-nw0X7nARsxFdyWknz9HR6TrlQfQ_DomdBzUa8pyTfEZaodH175XvDrKz4ds9kOm4ZrvFC_-oFWcDOCGQICC_OMxeBJEZesh6WQLqYQGLS15uNdBNJIKU7H--Fe2W-kV_PdXxHfqiwRvd-rDlyrD28KISCVe5QqMWNfT8jStbfgXa9hn_mpnyem3s0e7i1mUmMIOgC_is7kJLrIZWsZwRfv1S0)

## Описание системы

Система реализует платежную функциональность согласно варианту №2:

- **Клиент** имеет банковский счет и кредитную карту
- **Клиент** может оплачивать заказы, делать переводы на другие счета, блокировать карту и закрывать счет
- **Администратор** может блокировать кредитные карты при превышении кредитного лимита


## Контрольные вопросы и ответы

### 1. Для чего предназначена диаграмма классов?

Диаграмма классов предназначена для описания структуры системы, отображения классов и отношений между ними. Она показывает:
- Структуру классов в системе
- Атрибуты и методы классов
- Отношения между классами (ассоциации, наследование, реализацию интерфейсов)
- Взаимодействие компонентов системы

### 2. Перечислите основные графические символы, используемые при построении диаграммы классов.

Основные графические символы UML диаграммы классов:
- **Класс**: прямоугольник, разделенный на три секции (имя класса, атрибуты, методы)
- **Интерфейс**: прямоугольник с ключевым словом «interface» или круг с именем интерфейса
- **Ассоциация**: сплошная линия между классами
- **Агрегация**: линия с незакрашенным ромбом
- **Композиция**: линия с закрашенным ромбом
- **Наследование**: сплошная линия с треугольной стрелкой
- **Реализация интерфейса**: пунктирная линия с треугольной стрелкой
- **Зависимость**: пунктирная линия со стрелкой

### 3. Как на диаграмме классов представляются отношения наследования и агрегации?

**Наследование** представляется сплошной линией с треугольной стрелкой, направленной от подкласса к базовому классу. Стрелка указывает на базовый класс.

**Агрегация** представляется сплошной линией с незакрашенным ромбом на конце, указывающем на целое. Агрегация показывает отношение "часть-целое", где части могут существовать независимо от целого.
