#include "include/Product.h"
#include "include/Customer.h"
#include "include/EMI.h"
#include "include/Finance.h"
#include "include/Transaction.h"

int main() {
    Product p(1, "Laptop", "Electronics", 1200.50, 10);
    p.print();

    Customer c(1, "Alice", "alice@example.com");
    c.print();

    EMI e(1, 1, 300.0, "2025-12-15");
    e.print();

    Transaction t(1, "sale", 1200.50, "2025-11-11");
    Finance f;
    f.addTransaction(t);
    f.printAll();

    return 0;
}
