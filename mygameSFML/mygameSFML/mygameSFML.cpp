#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <random>


using namespace sf;
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Автозмейка версия: EA251020281120 (Ранняя альфа). Написано на C++/SFML" << endl;
    random_device rd; 
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 150);

    float Height = 300.0f;
    float Widht = 300.0f;
    double Pi = 3.1415926535;
    int apples = 0;

    Texture CARtex;

    RenderWindow window(sf::VideoMode(Widht, Height), "mgSFML");

    RectangleShape player1;
    player1.setSize(Vector2f(50, 25));
    player1.setFillColor(Color::Green);
    player1.setPosition(150, 150);
    player1.setRotation(0);

    RectangleShape kaktus;
    kaktus.setSize(Vector2f(25, 25));
    kaktus.setFillColor(Color::Red);
    kaktus.setPosition(Vector2f(dist(gen), dist(gen)));
    kaktus.setRotation(0);

    CircleShape oblast(150.f);
    oblast.setPosition(0, 0);
    oblast.setFillColor(Color::White);
    oblast.setRotation(0);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
                cout << "Вы получили " << apples << " яблок" << endl;
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Left)) { player1.rotate(-0.1); }
        if (Keyboard::isKeyPressed(Keyboard::Right)) { player1.rotate(0.1); }
        player1.move(0.1 * cos(player1.getRotation() * (Pi / 180)), 0.1 * sin(player1.getRotation() * (Pi / 180)));

        if ((player1.getPosition().x - 150) * (player1.getPosition().x - 150) + (player1.getPosition().y - 150) * (player1.getPosition().y - 150) > 22500)
        {
            if (player1.getPosition().x >= 150 and player1.getPosition().y < 150)
            {
                player1.setPosition(player1.getPosition().x - 0.1, player1.getPosition().y + 0.1);
            }
            else if (player1.getPosition().x < 150 and player1.getPosition().y < 150)
            {
                player1.setPosition(player1.getPosition().x + 0.1, player1.getPosition().y + 0.1);
            }
            else if (player1.getPosition().x < 150 and player1.getPosition().y >= 150)
            {
                player1.setPosition(player1.getPosition().x + 0.1, player1.getPosition().y - 0.1);
            }
            else
            {
                player1.setPosition(player1.getPosition().x - 0.1, player1.getPosition().y - 0.1);
            }
        }

        if ((kaktus.getPosition().x - 150) * (kaktus.getPosition().x - 150) + (kaktus.getPosition().y - 150) * (kaktus.getPosition().y - 150) > 22500)
        {
            if (kaktus.getPosition().x >= 150 and kaktus.getPosition().y < 150)
            {
                kaktus.setPosition(kaktus.getPosition().x - 0.1, kaktus.getPosition().y + 0.1);
            }
            else if (kaktus.getPosition().x < 150 and kaktus.getPosition().y < 150)
            {
                kaktus.setPosition(kaktus.getPosition().x + 0.1, kaktus.getPosition().y + 0.1);
            }
            else if (kaktus.getPosition().x < 150 and kaktus.getPosition().y >= 150)
            {
                kaktus.setPosition(kaktus.getPosition().x + 0.1, kaktus.getPosition().y - 0.1);
            }
            else
            {
                kaktus.setPosition(kaktus.getPosition().x - 0.1, kaktus.getPosition().y - 0.1);
            }
        }

        if ((player1.getPosition().x < kaktus.getPosition().x + 25) && (player1.getPosition().y < kaktus.getPosition().y + 25) && (player1.getPosition().x > kaktus.getPosition().x) && (player1.getPosition().y > kaktus.getPosition().y)
            or (player1.getPosition().x < kaktus.getPosition().x + 25) && (player1.getPosition().y < kaktus.getPosition().y) && (player1.getPosition().x > kaktus.getPosition().x) && (player1.getPosition().y + 25 > kaktus.getPosition().y))
        {
            kaktus.setPosition(Vector2f(dist(gen), dist(gen)));
            apples++;
            cout << "Осталось " << 100-apples << " до победы" << endl;
        }

        if (apples >= 100) {
            cout << "Победа!" << endl;
            break;
        }
        window.clear(Color(255, 158, 255, 255));
        window.draw(oblast);
        window.draw(player1);
        window.draw(kaktus);
        window.display();
    }

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
