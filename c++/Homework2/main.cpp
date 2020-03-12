#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <fstream>

int width;
int height;
double x_0;
double x_1;
char tensor[100][100];


std::vector<double> linspace() {
    std::vector<double> linsp;

    double delta = (x_1 - x_0) / (width - 1);
    linsp.reserve(width);
    for (int i = 0; i < width; ++i) {
        linsp.push_back(x_0 + delta * i);
    }
    return linsp;
}

std::vector<double> compute_function_1(const std::vector<double> &linsp) {
    std::vector<double> vec_fun;
    vec_fun.reserve(linsp.size());
    for (double el: linsp) {
        vec_fun.push_back(-el * log(el));
    }
    return vec_fun;
}

std::vector<double> compute_function_2(const std::vector<double> &linsp) {
    std::vector<double> vec_fun;
    vec_fun.reserve(linsp.size());
    for (double el: linsp)
        vec_fun.push_back(sqrt(el));
    return vec_fun;
}

std::vector<double> compute_function_3(const std::vector<double> &linsp) {
    std::vector<double> vec_fun;
    vec_fun.reserve(linsp.size());
    for (double el: linsp) {
        vec_fun.push_back(-(el * el) - 0.5);
    }
    return vec_fun;
}

/*По фану*/
std::vector<double> compute_sinus(const std::vector<double> &linsp) {
    std::vector<double> vec_fun;
    vec_fun.reserve(linsp.size());
    for (double el: linsp) {
        vec_fun.push_back(sin(el));
    }
    return vec_fun;
}

double find_delta(const std::vector<double> &vec_fun) {
    auto minmax = std::minmax_element(vec_fun.begin(), vec_fun.end());
    double max = 0.0;
    std::abs(*minmax.first) > *minmax.second ? max = std::abs(*minmax.first) : max = *minmax.second;
    double delta = double(height) / double(max);
    return delta;
}


/*Теоретически, выведет любую  функцию при правильной настройке парраметров (но не факт, что красиво)*/
void fill(std::vector<double> &vec_fun, double &delta, int height_above_zero) {
    std::ofstream st;
    st.open("file.txt",std::ios::app);
    double delta_1 = delta * double(height_above_zero) / height;
    double delta_2 = delta * (1.01 - double(height_above_zero) / height);
    if (delta_1 < delta * 0.5) {        /*Чтобы первый график выглядел красиво*/
        delta_1 = delta;
    }
    for (int i = height_above_zero-1 /*Высота над нулем*/; i > -1; i--) {
        if (i == 0) {
            for (int j = 0; j < width; j++) {
                tensor[i][j] = '-';
            }
        }
        for (int j = 0; j < width; j++) {
            if (int(vec_fun[j] * delta_1) >= i) {
                for (int k = height; k > 0; k--) {
                    tensor[k][j] = '#';
                }
            } else if (i != 0) { tensor[i][j] = ' '; }
            st << std::setw(1) << tensor[i][j];
        }
        st << std::endl;
    }
    for (int i = 0; i < height - height_above_zero+1/*Высота под нулем*/; i++) {
        for (int j = 0; j < width; j++) {
            if ((int(vec_fun[j] * delta) < 0) and (abs(int(vec_fun[j] * delta_2)) >= i)) {
                for (int k = 0; k < height; k++) {
                    tensor[k][j] = '#';
                }
            } else {
                tensor[i][j] = ' ';
            }
            st << std::setw(1) << tensor[i][j];
        }
        st << std::endl;
    }
    st << "\n\n";
    st.close();
}


int main() {
    /**первая функция**/
    std::cin >> width >> height >> x_0 >> x_1;
    std::vector<double> linsp_1 = linspace();
    std::vector<double> vec_fun_1 = compute_function_1(linsp_1);
    double delta_1 = find_delta(vec_fun_1);
    fill(vec_fun_1, delta_1, 10 /*Высота оси OX относительно заданной высоты*/);

    /**Вторая функция**/
    std::cin >> width >> height >> x_0 >> x_1;
    std::vector<double> linsp_2 = linspace();
    std::vector<double> vec_fun_2 = compute_function_2(linsp_2);
    double delta_2 = find_delta(vec_fun_2);
    fill(vec_fun_2, delta_2, 41);

    /** Третья функция**/
    std::cin >> width >> height >> x_0 >> x_1;
    std::vector<double> linsp_3 = linspace();
    std::vector<double> vec_fun_3 = compute_function_3(linsp_3);
    double delta_3 = find_delta(vec_fun_3);
    fill(vec_fun_3, delta_3, 1);

    /** Синус **/
    std::cin >> width >> height >> x_0 >> x_1;
    std::vector<double> linsp_4 = linspace();
    std::vector<double> vec_fun_4 = compute_sinus(linsp_4);
    double delta_4 = find_delta(vec_fun_4);
    fill(vec_fun_4, delta_4, 7 /*учитывая, что высота = 14*/);

    return 0;
}