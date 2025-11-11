#pragma once
#include <vector>
#include "Transaction.h"

class Finance {
private:
    std::vector<Transaction> transactions;

public:
    void addTransaction(const Transaction& t) {
        transactions.push_back(t);
    }

    void printAll() const {
        std::cout << "--- All Transactions ---" << std::endl;
        for (const auto& t : transactions)
            t.print();
    }
};
