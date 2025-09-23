#include <iostream>
#include "Client.h"
#include "BankAccount.h"
#include "CreditCard.h"
#include "Administrator.h"

int main() {
    std::cout << "=== Payment System Simulation (Variant 2) ===\n\n";

    // Создаем объекты
    BankAccount acc1(1001, 1500.0, "USD");
    BankAccount acc2(1002, 500.0, "USD");
    CreditCard card("4111-1111-1111-1111", 2000.0);
    Client client(1, "John Doe", "+123456789");
    Administrator admin(1, "Alice Smith");

    // Связываем клиента с его счетом и картой
    client.setBankAccount(&acc1);
    client.setCreditCard(&card);

    std::cout << "--- Client Operations ---\n";
    client.payOrder(300.0); // Успешная оплата
    client.payOrder(2000.0); // Ошибка: недостаточно средств
    client.transferTo(&acc2, 400.0); // Успешный перевод
    client.transferTo(&acc2, 1500.0); // Ошибка: недостаточно средств

    std::cout << "\n--- Credit Card Operations ---\n";
    card.AddDebt(1800.0); // Добавляем долг
    admin.BlockCardForOverlimit(&card); // Админ проверяет - не блокирует
    card.AddDebt(500.0); // Превышаем лимит
    admin.BlockCardForOverlimit(&card); // Админ блокирует карту

    std::cout << "\n--- Final Actions ---\n";
    client.blockCard(); // Клиент пытается заблокировать уже заблокированную карту
    client.closeAccount(); // Закрываем счет

    std::cout << "\n=== Simulation Complete ===\n";
    return 0;
}