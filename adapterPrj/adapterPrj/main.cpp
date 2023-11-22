#include<iostream>
#include<string>

using namespace std;

//Problem: client want to control the fan and we have 2 ways to access the fan

// The existing class with a compatible interface
class fan {
protected:
	int lv;
	string turn;
public:
	virtual void remote() = 0;
	virtual void chooseLv() = 0;
};

// Interface for the Adapter
class adapterFan : public fan{
public:
	void remote() {
		cout << "Turn on/off: ";
		cin.ignore();
		getline(cin, turn);
		if (turn == "off") {
			lv = 0;
			return;
		}
		else
			chooseLv();
	}
	void chooseLv() {
		cout << "Pick level: ";
		cin >> lv;
		cout << "\n";
	}
	virtual void control() = 0;
	virtual ~adapterFan() = default;
};

// Bluetooth Adapter
class bluetoothAdapter : public adapterFan {
public:
	void control() override {
		cout << "Successful connection by Bluetooth!\n";
		remote();
	}
};

// Wifi Adapter
class wifiAdapter : public adapterFan {
public:
	void control() override {
		cout << "Successful connection by Wifi!\n";
		remote();
	}
};

int main() {
	// Using the Bluetooth adapter
	adapterFan* bluetoothFan = new bluetoothAdapter();
	bluetoothFan->control();
	delete bluetoothFan;

	// Using the Wifi adapter
	adapterFan* wifiFan = new wifiAdapter();
	wifiFan->control();
	delete wifiFan;

	return 0;
}
