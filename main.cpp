#include <iostream>
#include <fstream>

using namespace std;
const int MAX = 100;
const int PI = 3;

void readFile(string propertiesOfShapes[], int &mountOfShape) {
    ifstream inFile("input.txt");
    inFile >> mountOfShape;
    inFile.ignore();
    for (int i = 0; i < mountOfShape; i++) {
        getline(inFile, propertiesOfShapes[i]);
    }
    inFile.close();
}

int caculatorAreaOfSquare(int a) {
    return a * a;
}

int caculatorPerimeterOfSquare(int a) {
    return a * 4;
}

int caculatorAreaOfCircle(int r) {
    return (r * r) * PI;
}

int caculatorPerimeterOfCircle(int r) {
    return (r + r) * PI;
}

int caculatorAreaOfRectangle(int w, int h) {
    return w * h;
}

int caculatorPerimeterOfRectangle(int w, int h) {
    return (w + h) * 2;
}

void process(string propertiesOfShapes[], int &mountOfShape,
             string &shapeOfSmallestPerimeter,
             string &shapeOfLargestPerimeter,
             string &shapeOfSmallestArea,
             string &shapeOfLargestArea,
             int &countSquare,
             int &countCircle,
             int &countRectangle) {
    int minArea = INT_MAX, maxArea = 0, minP = INT_MAX, maxP = 0;

    int indexOfSmallestPerimeter = 0;
    int indexOfLargestPerimeter = 0;
    int indexOfSmallestArea = 0;
    int indexOfLargestArea = 0;

    for (int i = 0; i < mountOfShape; i++) {
        int area = 0, perimeter = 0;

        if (propertiesOfShapes[i][0] == 'S') {
            countSquare++;
            int a = std::stoi(propertiesOfShapes[i].substr(10)); // index of a number

            area = caculatorAreaOfSquare(a);
            perimeter = caculatorPerimeterOfSquare(a);

            propertiesOfShapes[i] = "Square " + propertiesOfShapes[i].substr(8);
        } else if (propertiesOfShapes[i][0] == 'C') {
            countCircle++;
            int r = std::stoi(propertiesOfShapes[i].substr(10)); // index of r number

            area = caculatorAreaOfCircle(r);
            perimeter = caculatorPerimeterOfCircle(r);

            propertiesOfShapes[i] = "Circle " + propertiesOfShapes[i].substr(8);
        } else if (propertiesOfShapes[i][0] == 'R') {
            countRectangle++;
            int positionEndWitdh = propertiesOfShapes[i].find(",");

            int w = std::stoi(propertiesOfShapes[i].substr(13, positionEndWitdh - 13));  // index of w number to subsring
            int h = std::stoi(propertiesOfShapes[i].substr(positionEndWitdh + 4));

            area = caculatorAreaOfRectangle(w, h);
            perimeter = caculatorPerimeterOfRectangle(w,h);
            propertiesOfShapes[i] = "Rectangle " + propertiesOfShapes[i].substr(11);
        }
        propertiesOfShapes[i] += " => area=" + to_string(area) + ", perimeter=" + to_string(perimeter);
        if (minArea > area) {
            indexOfSmallestArea = i;
            minArea = area;
        }
        if (maxArea < area) {
            indexOfLargestArea = i;
            maxArea = area;
        }
        if (minP > perimeter) {
            indexOfSmallestPerimeter = i;
            minP = perimeter;
        }
        if (maxP < perimeter) {
            indexOfLargestPerimeter = i;
            maxP = perimeter;
        }
        shapeOfLargestPerimeter = "Hinh co chu vi lon nhat: " + propertiesOfShapes[indexOfLargestPerimeter].substr(0, propertiesOfShapes[indexOfLargestPerimeter].find("area"))
        + "perimeter=" + to_string(maxP);
        shapeOfLargestArea = "Hinh co dien tich lon nhat: " + propertiesOfShapes[indexOfLargestArea].substr(0, propertiesOfShapes[indexOfLargestArea].find("area"))
        + "area=" + to_string(maxArea);
        shapeOfSmallestPerimeter = "Hinh co chu vi nho nhat: " + propertiesOfShapes[indexOfSmallestPerimeter].substr(0, propertiesOfShapes[indexOfSmallestPerimeter].find("area"))
        + "perimeter=" + to_string(minP);
        shapeOfSmallestArea = "Hinh co dien tich nho nhat: " + propertiesOfShapes[indexOfSmallestArea].substr(0, propertiesOfShapes[indexOfSmallestArea].find("area"))
        + "area=" + to_string(minArea);
    }
}

void showResult(string propertiesOfShapes[], int mountOfShape,
                string shapeOfSmallestPerimeter,
                string shapeOfLargestPerimeter,
                string shapeOfSmallestArea,
                string shapeOfLargestArea,
                int countSquare,
                int countCircle,
                int countRectangle) {


    for (int i = 0; i < mountOfShape; i++) {
        cout << propertiesOfShapes[i] << endl;
    }
    cout << endl;
    cout << shapeOfLargestPerimeter << endl;
    cout << shapeOfLargestArea << endl;
    cout << shapeOfSmallestPerimeter << endl;
    cout << shapeOfSmallestArea << endl;
    cout << endl << "Thong ke cac hinh da doc" << endl;
    cout << "+ Square: " << countSquare << endl;
    cout << "+ Circle: " << countCircle << endl;
    cout << "+ Retangle: " << countRectangle << endl;

}

int main() {
    string propertiesOfShapes[MAX];
    int amountOfShape;
    string shapeOfSmallestPerimeter;
    string shapeOfLargestPerimeter;
    string shapeOfSmallestArea;
    string shapeOfLargestArea;
    int countSquare = 0;
    int countCircle = 0;
    int countRectangle = 0;

    readFile(propertiesOfShapes, amountOfShape);
    process(propertiesOfShapes, amountOfShape,
            shapeOfSmallestPerimeter,
            shapeOfLargestPerimeter,
            shapeOfSmallestArea,
            shapeOfLargestArea,
            countSquare,
            countCircle,
            countRectangle);
    showResult(propertiesOfShapes, amountOfShape,
               shapeOfSmallestPerimeter,
               shapeOfLargestPerimeter,
               shapeOfSmallestArea,
               shapeOfLargestArea,
               countSquare,
               countCircle,
               countRectangle);
}
