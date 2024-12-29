#include <iostream>
#include <cmath>

using namespace std;

// Function prototypes
void arithmeticOperations();
void areaCalculation();
void volumeCalculation();
void solveSimultaneous();

int main() {
    int choice;
    do {
        cout << "\nCalculator Menu:";
        cout << "\n1. Arithmetic Operations";
        cout << "\n2. Area of Figures";
        cout << "\n3. Volume of Figures";
        cout << "\n4. Solve Simultaneous Equations";
        cout << "\n5. Exit";
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
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

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
}

void areaCalculation() {
    int choice;
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
            cout << "Area of Circle: " << M_PI * radius * radius << endl;
            break;
        }
        case 2: {
            double length, width;
            cout << "Enter length and width: ";
            cin >> length >> width;
            cout << "Area of Rectangle: " << length * width << endl;
            break;
        }
        case 3: {
            double base, height;
            cout << "Enter base and height: ";
            cin >> base >> height;
            cout << "Area of Triangle: " << 0.5 * base * height << endl;
            break;
        }
        default:
            cout << "Invalid choice!\n";
    }
}

void volumeCalculation() {
    int choice;
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
            cout << "Volume of Sphere: " << (4.0 / 3.0) * M_PI * pow(radius, 3) << endl;
            break;
        }
        case 2: {
            double side;
            cout << "Enter side length: ";
            cin >> side;
            cout << "Volume of Cube: " << pow(side, 3) << endl;
            break;
        }
        case 3: {
            double radius, height;
            cout << "Enter radius and height: ";
            cin >> radius >> height;
            cout << "Volume of Cylinder: " << M_PI * pow(radius, 2) * height << endl;
            break;
        }
        default:
            cout << "Invalid choice!\n";
    }
}

void solveSimultaneous() {
    double a1, b1, c1, a2, b2, c2;

    cout << "For the first equation (a1*x + b1*y = c1), enter a1, b1, and c1: ";
    cin >> a1 >> b1 >> c1;

    cout << "For the second equation (a2*x + b2*y = c2), enter a2, b2, and c2: ";
    cin >> a2 >> b2 >> c2;

    double determinant = a1 * b2 - a2 * b1;

    if (determinant == 0) {
        cout << "The equations have no unique solution (they are either dependent or inconsistent).\n";
    } else {
        double x = (c1 * b2 - c2 * b1) / determinant;
        double y = (a1 * c2 - a2 * c1) / determinant;
        cout << "The solution is: x = " << x << ", y = " << y << endl;
    }
}
