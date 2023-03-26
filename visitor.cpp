#include "visitor.h"
#include <cmath>

ElectronicAppliance::ElectronicAppliance(double n_price, double n_weight) : weight{ n_weight }, price{ n_price } { }

double ElectronicAppliance::getPrice() {
	return price * 1.23;
}

double ElectronicAppliance::getWeight() {
	return weight;
}

double ElectronicAppliance::accept(Visitor& visitor) {
	return visitor.getDeliveryPriceForElectronics(this);
}

Food::Food(double n_price, double n_weight) : weight{ n_weight }, price{ n_price } { }

double Food::getPrice() {
	return price * 1.05;
}

double Food::getWeight() {
	return weight;
}

double Food::accept(Visitor& visitor) {
	return visitor.getDeliveryPriceForFood(this);
}

int QuickDeliveryCompany::getDeliveryPriceForFood(Food* food) {
	return ceil(food->getPrice() + food->getWeight() * 0.2 + 12);
}

int QuickDeliveryCompany::getDeliveryPriceForElectronics(ElectronicAppliance* appliance) {
	return ceil(appliance->getPrice() + appliance->getWeight() * 0.4 + 5);
}

int HappyDeliveryCompany::getDeliveryPriceForFood(Food* food) {
	return ceil(food->getPrice() + food->getWeight() * 0.15 + 10);
}

int HappyDeliveryCompany::getDeliveryPriceForElectronics(ElectronicAppliance* appliance) {
	return ceil(appliance->getPrice() + appliance->getWeight() * 0.3 + 15);
}