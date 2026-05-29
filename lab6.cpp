// #include <iostream>
// #include <vector>
// #include <chrono>
// #include <cmath>
// #include <iomanip>
// #include <cblas.h>

// using namespace std;

// template <typename T>
// void my_gemm(int n, const T* A, const T* B, T* C) {
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < n; ++j) {
//             T sum = 0;
//             for (int k = 0; k < n; ++k) {
//                 sum += A[i * n + k] * B[k * n + j];
//             }
//             C[i * n + j] = sum;
//         }
//     }
// }

// void openblas_gemm(int n, const float* A, const float* B, float* C) {
//     cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 
//                 n, n, n, 1.0f, A, n, B, n, 0.0f, C, n);
// }

// void openblas_gemm(int n, const double* A, const double* B, double* C) {
//     cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 
//                 n, n, n, 1.0, A, n, B, n, 0.0, C, n);
// }

// template <typename T>
// void run_test(int N, int threads) {
//     openblas_set_num_threads(threads);

//     vector<T> A(N * N, T(1.1)), B(N * N, T(2.2)), C_my(N * N, T(0)), C_bl(N * N, T(0));
//     vector<double> my_times, bl_times;

//     cout << "\n--- Тест: N=" << N << ", Потоков=" << threads << " ---" << endl;

//     for (int r = 0; r < 10; ++r) {
//         auto s1 = chrono::high_resolution_clock::now();
//         my_gemm(N, A.data(), B.data(), C_my.data());
//         auto e1 = chrono::high_resolution_clock::now();
//         my_times.push_back(chrono::duration<double>(e1 - s1).count());

//         auto s2 = chrono::high_resolution_clock::now();
//         openblas_gemm(N, A.data(), B.data(), C_bl.data());
//         auto e2 = chrono::high_resolution_clock::now();
//         bl_times.push_back(chrono::duration<double>(e2 - s2).count());
//     }

//     double sum_log_rel = 0;
//     cout << fixed << setprecision(4);
//     cout << "№ | My Time (s) | BLAS Time (s) | Rel. Performance (%)" << endl;
    
//     for (int i = 0; i < 10; ++i) {
//         double rel = (bl_times[i] / my_times[i]) * 100.0;
//         sum_log_rel += log(rel);
//         cout << i+1 << " | " << my_times[i] << "    | " << bl_times[i] << "      | " << rel << "%" << endl;
//     }

//     double geom_mean = exp(sum_log_rel / 10.0);
//     cout << "Среднее геометрическое производительности: " << geom_mean << "%" << endl;
// }

// int main() {
//     int N = 2000; 
    
//     int thread_counts[] = {1, 2, 4, 8, 16};
    
//     for (int t : thread_counts) {
//         run_test<double>(N, t);
//     }

//     return 0;
// }
