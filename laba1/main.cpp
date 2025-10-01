#include <windows.h>
#include <clocale>
#include <iostream>
#include <iomanip>
#include "Client.h"
#include "BankAccount.h"
#include "CreditCard.h"
#include "Administrator.h"
#include "Order.h"


int main() {
    // Настройка кодировки для поддержки русского языка в Windows
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);


    std::cout << "=== Платежная система (Вариант №2) ===" << std::endl;
    std::cout << std::endl;

    // Создаем банковский аккаунт
    BankAccount* account = new BankAccount(1001, 50000.0, "RUB");

    // Создаем кредитную карту
    CreditCard* card = new CreditCard("4532-1234-5678-9012", 100000.0);

    // Создаем клиента
    Client* client = new Client(1, "Иванов Иван Иванович", "+7-999-123-45-67");
    client->setBankAccount(account);
    client->setCreditCard(card);

    // Создаем администратора
    Administrator* admin = new Administrator(1, "Петров Петр Петрович");

    // Создаем заказы
    Order* order1 = new Order(1, 15000.0, "Смартфон");
    Order* order2 = new Order(2, 25000.0, "Ноутбук");
    Order* order3 = new Order(3, 80000.0, "Телевизор");

    client->addOrder(order1);
    client->addOrder(order2);
    client->addOrder(order3);

    std::cout << "Информация о клиенте:" << std::endl;
    std::cout << "ID: " << client->getClientId() << std::endl;
    std::cout << "Имя: " << client->getName() << std::endl;
    std::cout << "Телефон: " << client->getPhoneNumber() << std::endl;
    std::cout << "Баланс счета: " << std::fixed << std::setprecision(2) << account->getBalance() << " " << account->getCurrency() << std::endl;
    std::cout << "Кредитный лимит: " << card->getCreditLimit() << " RUB" << std::endl;
    std::cout << std::endl;

    // Оплачиваем первый заказ
    std::cout << "=== Оплата первого заказа ===" << std::endl;
    if (client->payOrder(order1->getAmount())) {
        std::cout << "Заказ успешно оплачен!" << std::endl;
    }
    std::cout << "Текущий долг по карте: " << card->getCurrentDebt() << " RUB" << std::endl;
    std::cout << "Остаток на счете: " << account->getBalance() << " RUB" << std::endl;
    std::cout << std::endl;

    // Оплачиваем второй заказ
    std::cout << "=== Оплата второго заказа ===" << std::endl;
    if (client->payOrder(order2->getAmount())) {
        std::cout << "Заказ успешно оплачен!" << std::endl;
    }
    std::cout << "Текущий долг по карте: " << card->getCurrentDebt() << " RUB" << std::endl;
    std::cout << "Остаток на счете: " << account->getBalance() << " RUB" << std::endl;
    std::cout << std::endl;

    // Пытаемся оплатить третий заказ (превышение лимита)
    std::cout << "=== Попытка оплаты третьего заказа ===" << std::endl;
    if (!client->payOrder(order3->getAmount())) {
        std::cout << "Не удалось оплатить заказ - превышен кредитный лимит!" << std::endl;
    }
    std::cout << std::endl;

    // Администратор блокирует карту за превышение лимита
    std::cout << "=== Проверка администратором ===" << std::endl;
    admin->BlockCardForOverlimit(*card);
    std::cout << std::endl;

    // Показываем информацию о заказах клиента
    std::cout << "=== Информация о заказах клиента ===" << std::endl;
    const std::vector<Order*>& orders = client->getOrders();
    for (size_t i = 0; i < orders.size(); ++i) {
        Order* order = orders[i];
        std::cout << "Заказ #" << order->getOrderId() << ": " << order->getDescription()
                  << " - " << std::fixed << std::setprecision(2) << order->getAmount() << " RUB" << std::endl;
    }
    std::cout << std::endl;

    // Демонстрация перевода между счетами
    std::cout << "=== Демонстрация перевода ===" << std::endl;
    BankAccount* targetAccount = new BankAccount(2001, 10000.0, "RUB");
    std::cout << "Баланс целевого счета до перевода: " << targetAccount->getBalance() << " RUB" << std::endl;

    if (client->transferTo(*targetAccount, 5000.0)) {
        std::cout << "Перевод выполнен успешно!" << std::endl;
        std::cout << "Баланс целевого счета после перевода: " << targetAccount->getBalance() << " RUB" << std::endl;
        std::cout << "Баланс счета клиента: " << account->getBalance() << " RUB" << std::endl;
    }
    std::cout << std::endl;

    // Освобождаем память
    delete targetAccount;
    delete client; // Это также удалит account, card и orders благодаря деструктору
    delete admin;

    std::cout << "=== Программа завершена ===" << std::endl;
    return 0;
}