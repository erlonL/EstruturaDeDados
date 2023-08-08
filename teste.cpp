#include <iostream>
#include <chrono>
#include <thread>

int main() {
    std::cout << "Contagem regressiva: " << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << 5 - i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Espera por 1 segundo
    }

    std::cout << "Fim da contagem." << std::endl;

    return 0;
}
