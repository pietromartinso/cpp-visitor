#ifndef VISITOR_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define VISITOR_H

class Food;
class ElectronicAppliance;

class Visitor {
public:
    virtual int getDeliveryPriceForFood(Food*) = 0;
    virtual int getDeliveryPriceForElectronics(ElectronicAppliance*) = 0;
};

class Visitable {
public:
    double price;
    double weight;
    virtual double getPrice() = 0;
    virtual double getWeight() = 0;
    virtual double accept(Visitor&) = 0;
};

class Food : public Visitable {
public:
    double weight;
    double price;
    Food() = default;
    Food(double, double);
    double getWeight();
    double getPrice();
    double accept(Visitor&);
};

class ElectronicAppliance : public Visitable {
public:
    double weight;
    double price;
    ElectronicAppliance() = default;
    ElectronicAppliance(double, double);
    double getWeight();
    double getPrice();
    double accept(Visitor&);
};

class QuickDeliveryCompany : public Visitor {
public:
    QuickDeliveryCompany() = default;
    int getDeliveryPriceForFood(Food*);
    int getDeliveryPriceForElectronics(ElectronicAppliance*);
};

class HappyDeliveryCompany : public Visitor {
public:
    HappyDeliveryCompany() = default;
    int getDeliveryPriceForFood(Food*);
    int getDeliveryPriceForElectronics(ElectronicAppliance*);
};

#endif