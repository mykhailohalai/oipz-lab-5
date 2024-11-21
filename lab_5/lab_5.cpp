#include <iostream>
#include <fstream>

using namespace std;

void variables(double& start, double& end, double& step, double& n);
void solveEquation(double start, double end, double step, double n);
double y(double x, double n);

int main() {
    double start, end, step, n;

    try {
        variables(start, end, step, n);         
        solveEquation(start, end, step, n); 
    }
    catch (const invalid_argument& e) {
        cout << "Invalid argument error: " << e.what() << endl;
        return -1;
    }

    return 0;
}

void variables(double& start, double& end, double& step, double& n) {
    ofstream outFile("result.txt");
    cout << "Enter start: ";
    cin >> start;
    cout << "Enter end: ";
    cin >> end;
    cout << "Enter step: ";
    cin >> step;
    cout << "Enter n: ";
    cin >> n;


    outFile << "start : " << start << '\t' << "end : " << end << '\t' << "step : " << step << '\t' << "n : " << n << endl;
    outFile.close();
}

void solveEquation(double start, double end, double step, double n) {
    ofstream outFile("results.txt");
    if (step <= 0) {
        throw invalid_argument("step cannot be less 1");
    }
    for (double x = start; x <= end; x += step) {
        double res = y(x, n);
        outFile << "x: " << x << ", y: " << res << "\n";
        cout << "x: " << x << ", y: " << res << endl;
    }

    outFile.close();
}

double y(double x, double n) {
    double res;
    if (x < 0) {
        if (n < 3) {
            throw invalid_argument("n must be at least 3 when x < 0.");
        }

        double y = 1;
        for (int j = 2; j <= n - 2; j++) {
            y *= (j + x);
        }
        res = y;
    }
    else {
        if (n < 2) {
            throw invalid_argument("n must be at least 2 when x >= 0.");
        }
        double y = 0;
        for (int i = 0; i <= n - 1; i++) {
            double product = 1;
            for (int j = 0; j <= n - 1; j++) {
                product *= (x + i + j * j);
            }
            y += product;
        }
        res = y;
    }
    return res;
}
