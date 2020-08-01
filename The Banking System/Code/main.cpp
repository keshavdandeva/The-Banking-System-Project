#include <iostream>
#include <string.h>
#include "people.h"
#include "cashier.h"
#include "client.h"
#include "accountant.h"
#include "manager.h"
#include "ceo.h"
#include "president.h"
#include "groups.h"
#include "seniorPartnerGroup.h"
#include "seniorEmployees.h"
#include "juniorPartnerEmployees.h"
#include "juniorEmployeeGroup.h"
#include "bank.h"

int main() {

    cout << "Testing!" << endl;
    int choice = 0;
    cout << "1. Printing employee information." << endl;
    cout << "2. Firing of employees and re-hiring them." << endl;
    cout << "3. Opening and closing of bank accounts." << endl;
    cout << "4. Withdrawing and depositing cash." << endl;
    cout << "5. Conducting inter and outer bank transactions." << endl;
    cout << "6. Requesting loans, repayment and account closure." << endl;
    cout << "Enter choice: ";
    cin >> choice;
    if (choice > 6 || choice < 1) {
        cout << "Choice not in valid range." << endl;
        cout << "Enter a number from 1 to 6 :" << endl;
        cin >> choice;
        }

    cout << "Testing case: " << choice << endl;
    Bank bank1("PEKAO");
    Bank bank2("MILLENIUM");

    Ceo ceo1("Tony", "Stark", 42);
    Ceo ceo2("Steve", "Rogers", 98);

    President pr1("Bruce", "Wayne", 48);
    President pr2("Clark", "Kent", 78);

    Manager m1("Natasha", "Romanoff", 28);
    Manager m2("Diana", "Prince", 29);

    Cashier csh1("Clint", "Barton", 27);
    Cashier csh2("Barry", "Allen", 29);

    Accountant actn1("Bruce", "Banner", 26);
    Accountant actn2("Panther", "Pink", 30);

    bank1.addCeoToBank(ceo1);
    //bank2.addCeoToBank(ceo2);
    bank1.addManagerToBank(m1);
    bank1.addPresidentToBank(pr1);
    bank1.addAccountantToBank(actn1);


    bank1.addCashierToBank(csh1);
    //bank2.addCashierToBank(csh1);
    bank2.addAccountantToBank(actn2);

    Client client1("Ninja");
    Client client2("Lee");

    switch (choice) {
        case 1: {

            bank2.printEmployeeInformation();
            bank1.printEmployeeInformation();
            break;
        }
        case 2: {
            cout << "Before firing!" << endl;
            bank1.printEmployeeInformation();

            //bank1.removeCeo(ceo1);
            //bank1.removePresident(pr1);
            bank1.removeManager(m1);
            bank1.fireCashier(csh1);
            bank1.fireAccountant(actn1);
            cout << "After firing!" << endl;
            bank1.printEmployeeInformation();
            break;
        }

        case 3: {
            bank1.openAccount(client1, 5555, 2000 );
            bank1.openAccount(client1, 5555, 15000);
            bank1.openAccount(client1, 6464, 15000);
            bank2.openAccount(client1, 6999, 10000);
            bank1.openAccount(client2, 4545, 12000);
            bank1.printClientInformation();
            bank2.printClientInformation();

            bank1.closeAccount(client1, 6464);
            bank1.closeAccount(client1, 5555);
            bank1.printClientInformation();
            break;
        }
        case 4: {
            bank1.openAccount(client1, 5555, 15000);
            bank1.openAccount(client1, 6969, 18000);
            bank1.depositCash(client1, 5555, 12000);
            bank1.depositCash(client1, 6969, 2000);
            bank1.getAccountBalance(client1, 5555 );
            bank1.getAccountBalance(client1, 6969);

            bank1.withdrawCash(client1, 5555, 2000);
            bank1.getAccountBalance(client1, 5555);
            break;
        }
        case 5: {
            cout << "!-------Inter Back transfer simulation---------!" << endl;
            bank1.openAccount(client1, 4646, 12000);
            bank1.openAccount(client2, 6565, 12000);

            bank2.openAccount(client1, 5454, 15000);
            bank2.openAccount(client2, 4545, 15000);

            bank1.getAccountBalance(client2, 6565);
            bank1.getAccountBalance(client1, 4646);
            bank1.transferMoney(client1, 4646, 2000, client2, 6565);
            bank1.getAccountBalance(client2, 6565);
            bank1.getAccountBalance(client1, 4646);
            cout << "!------------------------------------------------" << endl;
            cout << "!-------Cross Bank transfer simulation---------!" << endl;
            bank2.getAccountBalance(client2, 4545);
            bank1.crossBankTransfer(client1, 4646, 30000, client2, 4545, bank2);
            bank2.getAccountBalance(client2, 4545);
            cout << "!----------------------------------------------!" << endl;
        break;
        }
        case 6: {
            cout << "!---------Loan request simulation-----------!" << endl;
            bank1.openAccount(client1, 4545, 12000);
            bank1.requestForLoan(client1, 4545, 25000);
            bank1.requestForLoan(client1, 4545, 25000);
            bank1.closeAccount(client1, 4545);
            bank1.repayLoan(client1, 4545, 10000);

            bank1.getAccountBalance(client1, 4545);
            bank1.requestForLoan(client1, 4545, 2500);
            bank1.repayLoan(client1, 4545, 15000);
            bank1.closeAccount(client1, 4545);
            bank1.printClientInformation();
            cout <<"!--------------------------------------------!" << endl;
            break;
        }


    }

}