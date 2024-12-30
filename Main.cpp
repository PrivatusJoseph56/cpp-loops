#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

// Struct to store history records
struct HistoryRecord {
    string operation;
    double result;
};

// Vector to store history
vector<HistoryRecord> history;

// Function prototypes
void arithmeticOperations();
void areaCalculation();
void volumeCalculation();
void solveSimultaneous();
void displayHistory();

int main() {
    int choice;
    do {
        cout << "\nCalculator Menu:";
        cout << "\n1. Arithmetic Operations";
        cout << "\n2. Area of Figures";
        cout << "\n3. Volume of Figures";
        cout << "\n4. Solve Simultaneous Equations";
        cout << "\n5. Display History";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                arithmeticOperations();
                break;
            case 2:
                areaCalculation();
                break;
            case 3:
                volumeCalculation();
                break;
            case 4:
                solveSimultaneous();
                break;
            case 5:
                displayHistory();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}

void arithmeticOperations() {
    char op;
    double num1, num2, result;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter operator (+, -, *, /): ";
    cin >> op;
    cout << "Enter second number: ";
    cin >> num2;

    switch (op) {
        case '+': result = num1 + num2; break;
        case '-': result = num1 - num2; break;
        case '*': result = num1 * num2; break;
        case '/': 
            if (num2 != 0)
                result = num1 / num2;
            else {
                cout << "Error! Division by zero.\n";
                return;
            }
            break;
        default:
            cout << "Invalid operator!\n";
            return;
    }
    cout << "Result: " << result << endl;

    // Store in history
    history.push_back({"Arithmetic Operation: " + to_string(num1) + " " + op + " " + to_string(num2), result});
}

void areaCalculation() {
    int choice;
    double result;
    cout << "\n1. Area of Circle";
    cout << "\n2. Area of Rectangle";
    cout << "\n3. Area of Triangle";
    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            double radius;
            cout << "Enter radius: ";
            cin >> radius;
            result = M_PI * radius * radius;
            cout << "Area of Circle: " << result << endl;

            // Store in history
            history.push_back({"Area of Circle with radius " + to_string(radius), result});
            break;
        }
        case 2: {
            double length, width;
            cout << "Enter length and width: ";
            cin >> length >> width;
            result = length * width;
            cout << "Area of Rectangle: " << result << endl;

            // Store in history
            history.push_back({"Area of Rectangle with length " + to_string(length) + " and width " + to_string(width), result});
            break;
        }
        case 3: {
            double base, height;
            cout << "Enter base and height: ";
            cin >> base >> height;
            result = 0.5 * base * height;
            cout << "Area of Triangle: " << result << endl;

            // Store in history
            history.push_back({"Area of Triangle with base " + to_string(base) + " and height " + to_string(height), result});
            break;
        }
        default:
            cout << "Invalid choice!\n";
    }
}

void volumeCalculation() {
    int choice;
    double result;
    cout << "\n1. Volume of Sphere";
    cout << "\n2. Volume of Cube";
    cout << "\n3. Volume of Cylinder";
    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            double radius;
            cout << "Enter radius: ";
            cin >> radius;
            result = (4.0 / 3.0) * M_PI * pow(radius, 3);
            cout << "Volume of Sphere: " << result << endl;

            // Store in history
            history.push_back({"Volume of Sphere with radius " + to_string(radius), result});
            break;
        }
        case 2: {
            double side;
            cout << "Enter side length: ";
            cin >> side;
            result = pow(side, 3);
            cout << "Volume of Cube: " << result << endl;

            // Store in history
            history.push_back({"Volume of Cube with side " + to_string(side), result});
            break;
        }
        case 3: {
            double radius, height;
            cout << "Enter radius and height: ";
            cin >> radius >> height;
            result = M_PI * pow(radius, 2) * height;
            cout << "Volume of Cylinder: " << result << endl;

            // Store in history
            history.push_back({"Volume of Cylinder with radius " + to_string(radius) + " and height " + to_string(height), result});
            break;
        }
        default:
            cout << "Invalid choice!\n";
    }
}

void solveSimultaneous() {
    double a1, b1, c1, a2, b2, c2;
    double x, y;
    bool hasSolution = true;

    cout << "For the first equation (a1*x + b1*y = c1), enter a1, b1, and c1: ";
    cin >> a1 >> b1 >> c1;

    cout << "For the second equation (a2*x + b2*y = c2), enter a2, b2, and c2: ";
    cin >> a2 >> b2 >> c2;

    double determinant = a1 * b2 - a2 * b1;

    if (determinant == 0) {
        cout << "The equations have no unique solution (they are either dependent or inconsistent).\n";
        hasSolution = false;
    } else {
        x = (c1 * b2 - c2 * b1) / determinant;
        y = (a1 * c2 - a2 * c1) / determinant;
        cout << "The solution is: x = " << x << ", y = " << y << endl;
    }

    if (hasSolution) {
        // Store in history
        history.push_back({"Solve Simultaneous Equations", x});
        history.push_back({"Solve Simultaneous Equations", y});
    }
}

void displayHistory() {
    cout << "\nCalculation History:\n";
    for (const auto& record : history) {
        cout << record.operation << " = " << record.result << endl;
    }
}
