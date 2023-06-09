﻿//у меня уже домашние китайцы заканчиваются столько дз делать...
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Device {
protected:
    string manufacturerName;
    string model;
    int quantity;
    double price;
    string color;

public:
    Device(string manufacturerName, string model, int quantity, double price, string color) {
        this->manufacturerName = manufacturerName;
        this->model = model;
        this->quantity = quantity;
        this->price = price;
        this->color = color;
    }

    virtual void printDeviceInfo() = 0;
    string getManufacturerName() const {
        return manufacturerName;
    }

    string getModel() const {
        return model;
    }

    int getQuantity() const {
        return quantity;
    }

    double getPrice() const {
        return price;
    }

    string getColor() const {
        return color;
    }
};

class MobilePhone : public Device {
private:
    string networkType;

public:
    MobilePhone(string manufacturerName, string model, int quantity, double price, string color, string networkType)
        : Device(manufacturerName, model, quantity, price, color) {
        this->networkType = networkType;
    }

    void printDeviceInfo() {
        cout << "Mobile Phone: " << getManufacturerName() << ", " << getModel() << ", " << getQuantity() << ", " << getPrice() << ", " << getColor() << ", " << networkType << endl;
    }

    string getNetworkType() const {
        return networkType;
    }
};

class Laptop : public Device {
private:
    string processorType;

public:
    Laptop(string manufacturerName, string model, int quantity, double price, string color, string processorType)
        : Device(manufacturerName, model, quantity, price, color) {
        this->processorType = processorType;
    }

    void printDeviceInfo() {
        cout << "Laptop: " << getManufacturerName() << ", " << getModel() << ", " << getQuantity() << ", " << getPrice() << ", " << getColor() << ", " << processorType << endl;
    }

    string getProcessorType() const {
        return processorType;
    }
};

class Tablet : public Device {
private:
    string screenSize;

public:
    Tablet(string manufacturerName, string model, int quantity, double price, string color, string screenSize)
        : Device(manufacturerName, model, quantity, price, color) {
        this->screenSize = screenSize;
    }

    void printDeviceInfo() {
        cout << "Tablet: " << getManufacturerName() << ", " << getModel() << ", " << getQuantity() << ", " << getPrice() << ", " << getColor() << ", " << screenSize << endl;
    }

    string getScreenSize() const {
        return screenSize;
    }
};

class Shop {
private:
    vector<Device*> devices;

public:
    void addDevice(Device* device) {
        devices.push_back(device);
    }

    void deleteDeviceByManufacturerName(string manufacturerName) {
        devices.erase(remove_if(devices.begin(), devices.end(), [&](Device* device) {
            return device->getManufacturerName() == manufacturerName;
            }), devices.end());
    }

    void printDevices() {
        for (auto device : devices) {
            device->printDeviceInfo();
        }
    }