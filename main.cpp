#include <iostream>

#include "visitor.h"

using namespace std;

int main() {

	{
		auto f = make_unique<Food>(10, 10);
		auto e = make_unique<ElectronicAppliance>(20, 20);

		auto q = make_shared<QuickDeliveryCompany>();
		auto h = make_shared<HappyDeliveryCompany>();

		cout << "Original food state:\nprice: " << f->getPrice() << "\nweight: " << f->getWeight() << "\n";
		cout << "Food price being selled by QuickCompany: " << f->accept(*q) << "\n";
		cout << "Food price being selled by HappyCompany: " << f->accept(*h) << "\n\n";

		cout << "Original electronic appliance state:\nprice: " << e->getPrice() << "\nweight: " << e->getWeight() << "\n";
		cout << "Electronic appliance price being selled by QuickCompany: " << e->accept(*q) << "\n";
		cout << "Electronic appliance price being selled by HappyCompany: " << e->accept(*h) << "\n";
	}

}