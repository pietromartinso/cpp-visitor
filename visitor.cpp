#include "visitor.h"
#include <cmath>
#include <cstddef>
#include <iostream>

using namespace std;

ElectronicAppliance::ElectronicAppliance(double n_price, double n_weight) : weight{ n_weight }, price{ n_price } {
	// implement your solution here
}

double ElectronicAppliance::getPrice() {
	return price * 1.23;
}

double ElectronicAppliance::getWeight() {
	// implement your solution here
	return weight;
}

double ElectronicAppliance::accept(Visitor& visitor) {
	// implement your solution here
	visitor.getDeliveryPriceForElectronics(this);
	return 0;
}

Food::Food(double n_price, double n_weight) : weight{ n_weight }, price{ n_price } {
	// implement your solution here
	// use 'cout << "Your output here" << endl;' to debug your solution
}

double Food::getPrice() {
	// implement your solution here
	return price * 1.05;
}

double Food::getWeight() {
	// implement your solution here
	return weight;
}

double Food::accept(Visitor& visitor) {
	// implement your solution here
	visitor.getDeliveryPriceForFood(this);
	return 0;
}

int QuickDeliveryCompany::getDeliveryPriceForFood(Food* food) {
	// implement your solution here
	return ceil(food->getPrice() + food->getWeight() * 0.2 + 12);
}

int QuickDeliveryCompany::getDeliveryPriceForElectronics(ElectronicAppliance* appliance) {
	// implement your solution here
	return ceil(appliance->getPrice() + appliance->getWeight() * 0.4 + 5);
}

int HappyDeliveryCompany::getDeliveryPriceForFood(Food* food) {
	// implement your solution here
	return ceil(food->getPrice() + food->getWeight() * 0.15 + 10);
}

int HappyDeliveryCompany::getDeliveryPriceForElectronics(ElectronicAppliance* appliance) {
	// implement your solution here
	return ceil(appliance->getPrice() + appliance->getWeight() * 0.3 + 15);
}

int main() {

}